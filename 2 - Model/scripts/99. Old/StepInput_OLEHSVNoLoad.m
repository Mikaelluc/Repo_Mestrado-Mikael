% Step Response - Onpen Loop UnLoaded

% Actuator Control Loop Requirements
SP.tss= 0.85; % Desired Settling time
SP.ess = 0.01; % Actuator steady state error 0.01 of actuator full stroke
SP.mp = 0.1; % Overshoot < 0.1 of actuator full stroke
SP.avrate = 32; % Average rate > 32 deg/s
SP.maxrate = 36; % Maximum rate < 36 deg/s
SP.td = 0.5;
SP.tr = 1;

%%% For Step Input
Cmd = 0;
Input.Step.Time = 0.25;
Input.Step.InitialValue = 0;
Input.Step.Amplitude = Cmd;
Input.Step.FinalValue = Input.Step.InitialValue + Input.Step.Amplitude;

% % EHSV Step Input
Input.Control = 4; % 1 - Repeating sequence Input, 2 - Sine Input, 3 -
%Step Input, 4- No Input
Input.Custom = 1; % 1- Zero, 2- Square , 3 - Sine, 4- Square Sine
StiffnessTest_Enable = 3; 
Load_cmd = 0;
ControlTopology = 3; % Open Loop
getControllerParameters
EHSVTest.Enable = 3; %1- Normal Operation, 2 - Frequency Test, 3 Step Test
EHSV.Step.Time = 0.5;
EHSV.Step.Value = 10;


% Simulation
Time = 3*SP.tss; % Simulation time (s)