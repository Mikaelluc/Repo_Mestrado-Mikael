
%%%%%%%%%%%%%%%%%%%%%%%%    Controller Selection   %%%%%%%%%%%%%%%%%%%%%%%%
 
% 0 - Proportional Controller (P)
% 1 - Proportional Integrative Controller (PI)
% 2 - Proportional Derivative Controller (PD)
% 3 - Proportional Integrative Derivative Controller (PID)
% 4 - Full State Feedback Controller
% 5 - Partial State Feedback Controller

global Kp Ki Kd Kfsfc Kpsfc DynStiffOptController ControlTopology

% Create fmincon paramteters: initial solution, lower solution boundary and
% upper solution boundary
switch DynStiffOptController
    case 0
        ControlTopology = 2;
        Kp = 40; Ki = 0; Kd = 0; 
        Kfsfc = 0; Kpsfc = 0;
        x0 = Kp;
        lb = 10;
        ub = 100;  
    case 1
        ControlTopology = 2;
        Kp = 40; Ki = 1e-6; Kd = 0;
        Kfsfc = 0; Kpsfc = 0;
        x0 = [ Kp Ki];
        lb = [  10 0];
        ub = [ 100 5];                  
    case 2
        ControlTopology = 2;
        Kp = 40; Ki = 0; Kd = 0.7;
        Kfsfc = 0; Kpsfc = 0;
        x0 = [ Kp Kd];
        lb = [  10 0];
        ub = [ 100 5];
    case 3
        ControlTopology = 2;
        Kp = 40; Ki = 1e-6; Kd = 0.7;
        Kfsfc = 0; Kpsfc = 0;
        x0 = [ Kp Ki Kd];
        lb = [  10 0 0];
        ub = [ 100 5 5];  
    case 4
        ControlTopology = 6;
        Kp = 0; Ki = 0; Kd = 0; Kpsfc = 0;
        Kfsfc = [14.6507   -0.0011   -0.0000    0.0003   22.9112   -0.0053];
        x0   = Kfsfc;
        lb   = [];
        ub   = [];
    case 5
        ControlTopology = 5;
        Kp = 0; Ki = 0; Kd = 0; Kfsfc = 0;
        Kpsfc = [14.6507 0.0003   22.9112];
        x0   = Kpsfc;
        lb   = [0 0 0];
        ub   = [100 1 100];
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

