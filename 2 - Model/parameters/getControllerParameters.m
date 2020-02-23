% Controller
switch ControlTopology
    
    case 1 % ClOSED LOOP, ON-OFF
        Rate_Limit = 37; % Rate Limit, deg/s
        Max_Cmd = 30; % Maximum command allowable, deg
        Min_Cmd = -30; % Minimum command allowable, deg
        Kp = 0; % Proportional gain in PID Controller
        Ki = 0; % Integral gain in PID Controller
        Kd = 0; % Derivative gain in PID Controller
        Limit_Int = .5; % Integral Limit, mA
        Imax = 10; % Maximum EHSV Current, mA
           
    case 2 % CLOSED LOOP, Kp
        
        Rate_Limit = 38; % Rate Limit, deg/s
        Max_Cmd = 30; % Maximum command allowable, deg
        Min_Cmd = -30; % Minimum command allowable, deg
        Kp = 40; % Proportional gain in PID Controller
%         Kp = 53.1633; % Proportional gain in PID Controller
%         Ki = 0; % Integral gain in PID Controller
%         Kd = 0; % Derivative gain in PID Controller
        Ki = 0; % [1E-1,5E-2,1E-2,5E-3,1E-3,.1E-4,1E-5];
        Kd = 0.7;
        Limit_Int = .5; % Integral Limit, mA
        Imax = 10; % Maximum EHSV Current, mA
          
        
    otherwise % OPEN LOOP
        Rate_Limit = 1e10; % Rate Limit, deg/s
        Max_Cmd = 30; % Maximum command allowable, deg
        Min_Cmd = -30; % Minimum command allowable, deg
        Kp = 0; % Proportional gain in PID Controller
        Ki = 0; % Integral gain in PID Controller
        Kd = 0; % Derivative gain in PID Controller
        Limit_Int = .5; % Integral Limit, mA
        Imax = 10; % Maximum EHSV Current, mA
        
end
