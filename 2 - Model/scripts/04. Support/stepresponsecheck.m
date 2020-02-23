clear all;
clc;

run('PH_Load_Parameters');


% P Controller

Kp = 40; Ki = 0; Kd = 0;

PController.Kp = Kp;
PController.Ki = Ki;
PController.Kd = Kd;

PH_StepPerformanceTest_100;

PController.StepResponse.CommandTime = SurfaceCmd.Values.Time;
PController.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
PController.StepResponse.ResponseTime = SurfacePos.Values.Time;
PController.StepResponse.ResponsePosition = SurfacePos.Values.Data;
PController.StepResponse.Ts = Ts;
PController.StepResponse.Tp = Tp;
PController.StepResponse.Tr = Tr;
PController.StepResponse.Mp = Mp;
PController.StepResponse.ess = StepResponse.ess;
PController.StepResponse.av_rate = StepResponse.av_rate;

% PI Controller

Kp = 40; Ki = 1E-6; Kd = 0;

PIController.Kp = Kp;
PIController.Ki = Ki;
PIController.Kd = Kd;

PH_StepPerformanceTest_100;

PIController.StepResponse.CommandTime = SurfaceCmd.Values.Time;
PIController.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
PIController.StepResponse.ResponseTime = SurfacePos.Values.Time;
PIController.StepResponse.ResponsePosition = SurfacePos.Values.Data;
PIController.StepResponse.Ts = Ts;
PIController.StepResponse.Tp = Tp;
PIController.StepResponse.Tr = Tr;
PIController.StepResponse.Mp = Mp;
PIController.StepResponse.ess = StepResponse.ess;
PIController.StepResponse.av_rate = StepResponse.av_rate;

% PD Controller

Kp = 40; Ki = 0; Kd = 0.7;

PDController.Kp = Kp;
PDController.Ki = Ki;
PDController.Kd = Kd;

PH_StepPerformanceTest_100;

PDController.StepResponse.CommandTime = SurfaceCmd.Values.Time;
PDController.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
PDController.StepResponse.ResponseTime = SurfacePos.Values.Time;
PDController.StepResponse.ResponsePosition = SurfacePos.Values.Data;
PDController.StepResponse.Ts = Ts;
PDController.StepResponse.Tp = Tp;
PDController.StepResponse.Tr = Tr;
PDController.StepResponse.Mp = Mp;
PDController.StepResponse.ess = StepResponse.ess;
PDController.StepResponse.av_rate = StepResponse.av_rate;

% PID Controller

Kp = 40; Ki = 1E-6; Kd = 0.7;

PIDController.Kp = Kp;
PIDController.Ki = Ki;
PIDController.Kd = Kd;

PH_StepPerformanceTest_100;

PIDController.StepResponse.CommandTime = SurfaceCmd.Values.Time;
PIDController.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
PIDController.StepResponse.ResponseTime = SurfacePos.Values.Time;
PIDController.StepResponse.ResponsePosition = SurfacePos.Values.Data;
PIDController.StepResponse.Ts = Ts;
PIDController.StepResponse.Tp = Tp;
PIDController.StepResponse.Tr = Tr;
PIDController.StepResponse.Mp = Mp;
PIDController.StepResponse.ess = StepResponse.ess;
PIDController.StepResponse.av_rate = StepResponse.av_rate;


(PController.StepResponse.Ts-0.25)*1000
(PIController.StepResponse.Ts-0.25)*1000
(PDController.StepResponse.Ts-0.25)*1000 
(PIDController.StepResponse.Ts-0.25)*1000 

%% PD Controller 2

Kp = 40; Ki = 0; Kd = 0.5;

PD2Controller.Kp = Kp;
PD2Controller.Ki = Ki;
PD2Controller.Kd = Kd;

PH_StepPerformanceTest_m15;

PD2Controller.StepResponse.CommandTime = SurfaceCmd.Values.Time;
PD2Controller.StepResponse.CommandPosition = SurfaceCmd.Values.Data;
PD2Controller.StepResponse.ResponseTime = SurfacePos.Values.Time;
PD2Controller.StepResponse.ResponsePosition = SurfacePos.Values.Data;
PD2Controller.StepResponse.Ts = Ts;
PD2Controller.StepResponse.Tp = Tp;
PD2Controller.StepResponse.Tr = Tr;
PD2Controller.StepResponse.Mp = Mp;
PD2Controller.StepResponse.ess = StepResponse.ess;
PD2Controller.StepResponse.av_rate = StepResponse.av_rate;
