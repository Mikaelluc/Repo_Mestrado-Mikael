
% Run step response, frequency response and dynamic stiffness test for the
% optimized design in two temperatures: -15ºC and 100ºC.
global DynStiffOptController

% Create fmincon paramteters: initial solution, lower solution boundary and
% upper solution boundary
switch DynStiffOptController
    case 0
        OptimizedDesign.Controller.Kp = xopt(1);
        OptimizedDesign.Controller.Ki = 0;
        OptimizedDesign.Controller.Kd = 0;
        OptimizedDesign.Controller.Kfsfc = 0;
        OptimizedDesign.Controller.Kpsfc = 0;
    case 1
        OptimizedDesign.Controller.Kp = xopt(1);
        OptimizedDesign.Controller.Ki = xopt(2);
        OptimizedDesign.Controller.Kd = 0;
        OptimizedDesign.Controller.Kfsfc = 0;
        OptimizedDesign.Controller.Kpsfc = 0;
    case 2
        OptimizedDesign.Controller.Kp = xopt(1);
        OptimizedDesign.Controller.Ki = 0;
        OptimizedDesign.Controller.Kd = xopt(2);
        OptimizedDesign.Controller.Kfsfc = 0;
        OptimizedDesign.Controller.Kpsfc = 0;
    case 3
        OptimizedDesign.Controller.Kp = xopt(1);
        OptimizedDesign.Controller.Ki = xopt(2);
        OptimizedDesign.Controller.Kd = xopt(3);
        OptimizedDesign.Controller.Kfsfc = 0;
        OptimizedDesign.Controller.Kpsfc = 0;
    case 4
        OptimizedDesign.Controller.Kp = 0;
        OptimizedDesign.Controller.Ki = 0;
        OptimizedDesign.Controller.Kd = 0;
        OptimizedDesign.Controller.Kfsfc = xopt;
        OptimizedDesign.Controller.Kpsfc = 0;
    case 5
        OptimizedDesign.Controller.Kp = 0;
        OptimizedDesign.Controller.Ki = 0;
        OptimizedDesign.Controller.Kd = 0;
        OptimizedDesign.Controller.Kfsfc = 0;
        OptimizedDesign.Controller.Kpsfc = xopt;
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

OptimizedDesign.Temp100.temperature = 100;
OptimizedDesign.Tempm15.temperature = -15;

% Obtain dynamic stiffness response of the initial design

PH_DynamicStiffnessTest_100;

OptimizedDesign.Temp100.StiffnessResponse.spec_fr = spec_fr;
OptimizedDesign.Temp100.StiffnessResponse.spec_mag = spec_mag;
OptimizedDesign.Temp100.StiffnessResponse.fr = test_freq;
OptimizedDesign.Temp100.StiffnessResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;
OptimizedDesign.Temp100.StiffnessResponse.Jf = (OptimizedDesign.Temp100.StiffnessResponse.mag - 1.79e7);
OptimizedDesign.Temp100.StiffnessResponse.Jf_WeightedCF = (OptimizedDesign.Temp100.StiffnessResponse.mag - 1.79e7).*(test_freq.^2);

PH_DynamicStiffnessTest_m15;

OptimizedDesign.Tempm15.StiffnessResponse.spec_fr = spec_fr;
OptimizedDesign.Tempm15.StiffnessResponse.spec_mag = spec_mag;
OptimizedDesign.Tempm15.StiffnessResponse.fr = test_freq;
OptimizedDesign.Tempm15.StiffnessResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;

% Obtain Step Response

PH_StepPerformanceTest_100;

OptimizedDesign.Temp100.StepResponse.CommandTime = SurfaceCmd.Values.Time;
OptimizedDesign.Temp100.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
OptimizedDesign.Temp100.StepResponse.ResponseTime = SurfacePos.Values.Time;
OptimizedDesign.Temp100.StepResponse.ResponsePosition = SurfacePos.Values.Data;
OptimizedDesign.Temp100.StepResponse.Ts = Ts;
OptimizedDesign.Temp100.StepResponse.Tp = Tp;
OptimizedDesign.Temp100.StepResponse.Tr = Tr;
OptimizedDesign.Temp100.StepResponse.Mp = Mp;
OptimizedDesign.Temp100.StepResponse.ess = StepResponse.ess;
OptimizedDesign.Temp100.StepResponse.av_rate = StepResponse.av_rate;

PH_StepPerformanceTest_m15;

OptimizedDesign.Tempm15.StepResponse.CommandTime = SurfaceCmd.Values.Time;
OptimizedDesign.Tempm15.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
OptimizedDesign.Tempm15.StepResponse.ResponseTime = SurfacePos.Values.Time;
OptimizedDesign.Tempm15.StepResponse.ResponsePosition = SurfacePos.Values.Data;
OptimizedDesign.Tempm15.StepResponse.Ts = Ts;
OptimizedDesign.Tempm15.StepResponse.Tp = Tp;
OptimizedDesign.Tempm15.StepResponse.Tr = Tr;
OptimizedDesign.Tempm15.StepResponse.Mp = Mp;
OptimizedDesign.Tempm15.StepResponse.ess = StepResponse.ess;
OptimizedDesign.Tempm15.StepResponse.av_rate = StepResponse.av_rate;

% Obtain Frequency Response

PH_FrequencyResponseTest_100;

OptimizedDesign.Temp100.FrequencyResponse.Frequency = test_freq;
OptimizedDesign.Temp100.FrequencyResponse.Magnitude = mag_vec;
OptimizedDesign.Temp100.FrequencyResponse.Phase = phase_vec;

if strcmp(GM,'Not found')
    OptimizedDesign.Temp100.FrequencyResponse.GM = 100;
    OptimizedDesign.Temp100.FrequencyResponse.GF = 0;
else
    OptimizedDesign.Temp100.FrequencyResponse.GM = GM;
    OptimizedDesign.Temp100.FrequencyResponse.GF = GF;
end

if strcmp(PM,'Not found')
    OptimizedDesign.Temp100.FrequencyResponse.PM = 180;
    OptimizedDesign.Temp100.FrequencyResponse.PF = 0;
else
    OptimizedDesign.Temp100.FrequencyResponse.PM = PM;
    OptimizedDesign.Temp100.FrequencyResponse.PF = PF;
    
end

if strcmp(Bw,'Not found')
    OptimizedDesign.Temp100.FrequencyResponse.Bw = 0;
else
    OptimizedDesign.Temp100.FrequencyResponse.Bw = Bw;
end
if strcmp(Bc,'Not found')
    OptimizedDesign.Temp100.FrequencyResponse.Bc = 0;
else
    OptimizedDesign.Temp100.FrequencyResponse.Bc = Bc;
end

PH_FrequencyResponseTest_m15;

OptimizedDesign.Tempm15.FrequencyResponse.Frequency = test_freq;
OptimizedDesign.Tempm15.FrequencyResponse.Magnitude = mag_vec;
OptimizedDesign.Tempm15.FrequencyResponse.Phase = phase_vec;

if strcmp(GM,'Not found')
    OptimizedDesign.Tempm15.FrequencyResponse.GM = 100;
    OptimizedDesign.Tempm15.FrequencyResponse.GF = 0;
else
    OptimizedDesign.Tempm15.FrequencyResponse.GM = GM;
    OptimizedDesign.Tempm15.FrequencyResponse.GF = GF;
end

if strcmp(PM,'Not found')
    OptimizedDesign.Tempm15.FrequencyResponse.PM = 180;
    OptimizedDesign.Tempm15.FrequencyResponse.PF = 0;
else
    OptimizedDesign.Tempm15.FrequencyResponse.PM = PM;
    OptimizedDesign.Tempm15.FrequencyResponse.PF = PF;
    
end

if strcmp(Bw,'Not found')
    OptimizedDesign.Tempm15.FrequencyResponse.Bw = 0;
else
    OptimizedDesign.Tempm15.FrequencyResponse.Bw = Bw;
end
if strcmp(Bc,'Not found')
    OptimizedDesign.Tempm15.FrequencyResponse.Bc = 0;
else
    OptimizedDesign.Tempm15.FrequencyResponse.Bc = Bc;
end
