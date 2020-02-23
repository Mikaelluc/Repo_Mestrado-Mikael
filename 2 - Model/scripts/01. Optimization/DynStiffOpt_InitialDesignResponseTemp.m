
global Kp Ki Kd Kfsfc Kpsfc

% Run step response, frequency response and dynamic stiffness test for the
% initial design in two temperatures: -15ºC and 100ºC.

InitialDesign.Controller.Kp = Kp;
InitialDesign.Controller.Ki = Ki;
InitialDesign.Controller.Kd = Kd;
InitialDesign.Controller.Kfsfc = Kfsfc;
InitialDesign.Controller.Kpsfc = Kpsfc;
InitialDesign.Temp100.temperature = 100;
InitialDesign.Tempm15.temperature = -15;

% Obtain dynamic stiffness response of the initial design

PH_DynamicStiffnessTest_100;

InitialDesign.Temp100.StiffnessResponse.spec_fr = spec_fr;
InitialDesign.Temp100.StiffnessResponse.spec_mag = spec_mag;
InitialDesign.Temp100.StiffnessResponse.fr = test_freq;
InitialDesign.Temp100.StiffnessResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;

PH_DynamicStiffnessTest_m15;

InitialDesign.Tempm15.StiffnessResponse.spec_fr = spec_fr;
InitialDesign.Tempm15.StiffnessResponse.spec_mag = spec_mag;
InitialDesign.Tempm15.StiffnessResponse.fr = test_freq;
InitialDesign.Tempm15.StiffnessResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;

% Obtain Step Response

PH_StepPerformanceTest_100;

InitialDesign.Temp100.StepResponse.CommandTime = SurfaceCmd.Values.Time;
InitialDesign.Temp100.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
InitialDesign.Temp100.StepResponse.ResponseTime = SurfacePos.Values.Time;
InitialDesign.Temp100.StepResponse.ResponsePosition = SurfacePos.Values.Data;
InitialDesign.Temp100.StepResponse.Ts = Ts;
InitialDesign.Temp100.StepResponse.Tp = Tp;
InitialDesign.Temp100.StepResponse.Tr = Tr;
InitialDesign.Temp100.StepResponse.Mp = Mp;
InitialDesign.Temp100.StepResponse.ess = StepResponse.ess;
InitialDesign.Temp100.StepResponse.av_rate = StepResponse.av_rate;

PH_StepPerformanceTest_m15;

InitialDesign.Tempm15.StepResponse.CommandTime = SurfaceCmd.Values.Time;
InitialDesign.Tempm15.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
InitialDesign.Tempm15.StepResponse.ResponseTime = SurfacePos.Values.Time;
InitialDesign.Tempm15.StepResponse.ResponsePosition = SurfacePos.Values.Data;
InitialDesign.Tempm15.StepResponse.Ts = Ts;
InitialDesign.Tempm15.StepResponse.Tp = Tp;
InitialDesign.Tempm15.StepResponse.Tr = Tr;
InitialDesign.Tempm15.StepResponse.Mp = Mp;
InitialDesign.Tempm15.StepResponse.ess = StepResponse.ess;
InitialDesign.Tempm15.StepResponse.av_rate = StepResponse.av_rate;

% Obtain Frequency Response

PH_FrequencyResponseTest_100;

InitialDesign.Temp100.FrequencyResponse.Frequency = test_freq;
InitialDesign.Temp100.FrequencyResponse.Magnitude = mag_vec;
InitialDesign.Temp100.FrequencyResponse.Phase = phase_vec;

if strcmp(GM,'Not found')
    InitialDesign.Temp100.FrequencyResponse.GM = 100;
    InitialDesign.Temp100.FrequencyResponse.GF = 0;
else
    InitialDesign.Temp100.FrequencyResponse.GM = GM;
    InitialDesign.Temp100.FrequencyResponse.GF = GF;
end

if strcmp(PM,'Not found')
    InitialDesign.Temp100.FrequencyResponse.PM = 180;
    InitialDesign.Temp100.FrequencyResponse.PF = 0;
else
    InitialDesign.Temp100.FrequencyResponse.PM = PM;
    InitialDesign.Temp100.FrequencyResponse.PF = PF;
    
end

if strcmp(Bw,'Not found')
    InitialDesign.Temp100.FrequencyResponse.Bw = 0;
else
    InitialDesign.Temp100.FrequencyResponse.Bw = Bw;
end
if strcmp(Bc,'Not found')
    InitialDesign.Temp100.FrequencyResponse.Bc = 0;
else
    InitialDesign.Temp100.FrequencyResponse.Bc = Bc;
end

PH_FrequencyResponseTest_m15;

InitialDesign.Tempm15.FrequencyResponse.Frequency = test_freq;
InitialDesign.Tempm15.FrequencyResponse.Magnitude = mag_vec;
InitialDesign.Tempm15.FrequencyResponse.Phase = phase_vec;

if strcmp(GM,'Not found')
    InitialDesign.Tempm15.FrequencyResponse.GM = 100;
    InitialDesign.Tempm15.FrequencyResponse.GF = 0;
else
    InitialDesign.Tempm15.FrequencyResponse.GM = GM;
    InitialDesign.Tempm15.FrequencyResponse.GF = GF;
end

if strcmp(PM,'Not found')
    InitialDesign.Tempm15.FrequencyResponse.PM = 180;
    InitialDesign.Tempm15.FrequencyResponse.PF = 0;
else
    InitialDesign.Tempm15.FrequencyResponse.PM = PM;
    InitialDesign.Tempm15.FrequencyResponse.PF = PF;
    
end

if strcmp(Bw,'Not found')
    InitialDesign.Tempm15.FrequencyResponse.Bw = 0;
else
    InitialDesign.Tempm15.FrequencyResponse.Bw = Bw;
end
if strcmp(Bc,'Not found')
    InitialDesign.Tempm15.FrequencyResponse.Bc = 0;
else
    InitialDesign.Tempm15.FrequencyResponse.Bc = Bc;
end
