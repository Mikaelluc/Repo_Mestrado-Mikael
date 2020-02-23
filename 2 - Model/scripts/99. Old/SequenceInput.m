%RunSineInput

% Surface Input Command
Input.Control = 2; % 1 - Repeating sequence Input, 2 - Sine Input, 3 - Step Input

% Actuator Control Loop Requirements
SP.tss= 0.85; % Desired Settling time
SP.ess = 0.01; % Actuator steady state error 0.01 of actuator full stroke
SP.mp = 0.1; % Overshoot < 0.1 of actuator full stroke
SP.avrate = 32; % Average rate > 32 deg/s
SP.maxrate = 36; % Maximum rate < 36 deg/s
SP.td = 0.5;
SP.tr = 1;

%%% For Sequence Input
Input.Sequence.Time = [0 1];
Input.Sequence.Output = [0 30];


% Simulation
Time = 3*SP.tss; % Simulation time (s)