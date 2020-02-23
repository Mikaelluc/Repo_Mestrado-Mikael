% Step Response - Closed Loop Loaded

% Surface Input Command
Input.Control = 2; % 1 - Repeating sequence Input, 2 - Sine Input, 3 - Step Input
Input.Custom = 1; % 1- Zero, 2- Square , 3 - Sine, 4- Square Sine

Input.Sine.Frequency = 5;
Input.Sine.Amplitude = 5;
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

% Actuator Control Loop Requirements
SP.tss= 0.85; % Desired Settling time
SP.ess = 0.01; % Actuator steady state error 0.01 of actuator full stroke
SP.mp = 0.1; % Overshoot < 0.1 of actuator full stroke
SP.avrate = 32; % Average rate > 32 deg/s
SP.maxrate = 36; % Maximum rate < 36 deg/s
SP.td = 0.5;
SP.tr = 1;

% Actuator Position Control Loop
ControlTopology = 1; % Closed Loop, Kp
getControllerParameters
StiffnessTest_Enable = 2;
EHSVTest.Enable = 1;%1- Normal Operation, 2 - Frequency Test, 3 Step Test

% Simulation
Time = 3*SP.tss; % Simulation time (s)

