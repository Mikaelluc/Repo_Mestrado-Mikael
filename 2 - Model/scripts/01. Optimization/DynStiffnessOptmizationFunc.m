
function f = DynStiffnessOptmizationFunc(x)

global Hjw_vector Kp Kd Ki Kfsfc Kpsfc DynStiffOptController DynStiffOptCostFunction

% Refresh controller gains with current fmincon evaluation
switch DynStiffOptController 
    case 0
        Kp = x(1)
        Ki = 0; 
        Kd = 0; 
        Kfsfc = 0; Kpsfc = 0;
    case 1
        Kp = x(1)
        Ki = x(2)
        Kd = 0;  
        Kfsfc = 0; Kpsfc = 0;
    case 2
        Kp = x(1)
        Ki = 0;
        Kd = x(2)
        Kfsfc = 0; Kpsfc = 0;
    case 3
        Kp = x(1)
        Ki = x(2)
        Kd = x(3)
        Kfsfc = 0; Kpsfc = 0;
    case 4
        Kp = 0; Ki = 0; Kd = 0;
        Kfsfc = x
        Kpsfc = 0;
    case 5
        Kp = 0; Ki = 0; Kd = 0;
        Kfsfc = 0; 
        Kpsfc = x
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

% Run dynamic stiffness test @ 100ºC
PH_ModifiedDynamicStiffnessTest

% Obtain dynamic stiffness response in correct unit
DynStiffResponse = real(Hjw_vector(1:17))*175.126835;
disp(DynStiffResponse);

% Calculate cost function
switch DynStiffOptCostFunction
    case 0
        Jobjective = sum(DynStiffResponse - 1.79e7);
        Jp = 0;
        Jconstraint = 0;
    case 1
        % w_i=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]/3;
        % gamma_i = 1 + (w_i + 1)./2;
        gamma_i = [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 5];
        J_i = DynStiffResponse - 1.79e7;
        J_io = 0.1e7;
        J_vector = (J_i/J_io).^gamma_i;
        Jobjective = sum(J_vector);
        Jp = 0;
        
        % Calculate constraint cost function
        [c,~] = DynStiffnessOptmizationConstFunc(x);
        c(c<0) = 0;
        alfa = [5 5 5 5 5 5 5 5];
        Jconstraint = sum( (1+1e3*c).^alfa);
    case 2
%         gamma_i = [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 7];
        gamma_i = [1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 7];
        J_i = DynStiffResponse - 1.79e7;
        J_io = 0.1e7;
        J_vector = (J_i/J_io).^gamma_i;
        Jobjective = sum(J_vector);
        Jp = 0;
        
        % Calculate constraint cost function
        [c,~] = DynStiffnessOptmizationConstFunc(x);
        c(c<0) = 0;
        alfa = [5 5 5 5 5 5 5 5];
        Jconstraint = sum( (1+1e3*c).^alfa);
    otherwise
        error('DynStiffOptCostFunction is not a valid cost function code.');  
end

% Evaluate if the stiffness requirement was met in all frequencies and if not penalize the cost function
belowSpecVectorIndex = DynStiffResponse(1:17) < spec_mag(1:17)';
if min(find(belowSpecVectorIndex)) > 0
    belowSpecDifference = exp( (spec_mag(belowSpecVectorIndex == 1)' - DynStiffResponse(belowSpecVectorIndex == 1)) );
    Jp = prod(belowSpecDifference);
end

if Jp == Inf
    Jp = 1e90;
end

% Calculate penalized cost function
f = -Jobjective + Jconstraint + Jp
