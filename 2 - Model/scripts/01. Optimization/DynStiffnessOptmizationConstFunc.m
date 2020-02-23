
function [c,ceq] = DynStiffnessOptmizationConstFunc(x)

global simOut Time Input StepResponse Kp Kd Ki Kfsfc Kpsfc DynStiffOptController
global Ts Tp Tr Mp yss av_rate ess
global GM PM MagPk

% Refresh controller gains with current fmincon evaluation
switch DynStiffOptController
    case 0
        Kp = x(1);
        Ki = 0; 
        Kd = 0; 
        Kfsfc = 0; Kpsfc = 0;
    case 1
        Kp = x(1);
        Ki = x(2);
        Kd = 0;  
        Kfsfc = 0; Kpsfc = 0;
    case 2
        Kp = x(1);
        Ki = 0;
        Kd = x(2);
        Kfsfc = 0; Kpsfc = 0;
    case 3
        Kp = x(1);
        Ki = x(2);
        Kd = x(3);
        Kfsfc = 0; Kpsfc = 0;
    case 4
        Kp = 0; Ki = 0; Kd = 0;
        Kfsfc = x; 
        Kpsfc = 0;
    case 5
        Kp = 0; Ki = 0; Kd = 0;
        Kfsfc = 0; 
        Kpsfc = x;
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

FullStroke_deg = 2*33.3;
model_filename = 'RudderActuatorChannel_control';

%%%%%%%%%%%%%%%%%%%%%%%% Time Response Performance %%%%%%%%%%%%%%%%%%%%%%%%

% Load simulink model parameters for a closed loop step response with aerodynamic load
PH_StepInput_CLLoad

% Run step response simulation @ -15ºC
simOut = sim(model_filename,'StopTime',num2str(Time));

% Extract data from simulation
surfPos = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
surfPosCmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
time = simOut.get('yout').time;

% Obtain information about the step response
StepResponse = stepinfo(surfPos,time,surfPosCmd(end),'RiseTimeLimits',[0.15,0.85],'SettlingTimeThreshold',0.02);

% Calculate step response performance parameters
Ts = StepResponse.SettlingTime - Input.Step.Time;
Tp = StepResponse.PeakTime - Input.Step.Time;
Tr = StepResponse.RiseTime - Input.Step.Time;
Mp = StepResponse.Overshoot;
yss =  surfPos(end);
av_rate = (0.85*yss - 0.15*yss)/StepResponse.RiseTime;
ess = abs((yss - surfPosCmd(end))/FullStroke_deg);

% Calculate optimization time performance constraints
ConstSettlingTime = Ts-1.1;
ConstSteadyStateError = ess-0.01;
ConstOvershoot = Mp-0.1;
ConstLowestAverageRate = -(av_rate-32);
ConstHighestAverageRate = av_rate-36;

if isnan(ConstSettlingTime)
    ConstSettlingTime = 10;
end
if isnan(ConstLowestAverageRate)
    ConstLowestAverageRate = 10;
end
if isnan(ConstHighestAverageRate)
    ConstHighestAverageRate = 0;
end

%%%%%%%%%%%%%%%%%%%%% Frequency Response Performance %%%%%%%%%%%%%%%%%%%%%%

% Run modified frequency response test @ 100ºC
PH_ModifiedFrequencyResponseTest

% Calculate max magnitude 
MagPk = max(20*log10(mag_vec));

% Assign 180 degrees of phase margin if it is not found
if strcmp(PM,'Not found')
    PM = 180;
end

% Calculate optimization frequency performance constraints
ConstGainMargin = -(min(GM)-10);
ConstPhaseMargin = -(min(PM)-45);
ConstHighestMagnitude = MagPk-0.5;

% Assign constraint vectors
c = [ConstSettlingTime ConstSteadyStateError ConstOvershoot ConstLowestAverageRate ConstHighestAverageRate ConstGainMargin ConstPhaseMargin ConstHighestMagnitude ]
ceq = [];
