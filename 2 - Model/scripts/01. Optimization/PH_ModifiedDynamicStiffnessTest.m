% Run Dynamic Stiffness Test
% run('PH_Load_Parameters')

global Supply_Pressure Return_Pressure ActStallLoad Ap StiffnessTest_Enable
global Input Kst_Enable StiffTest simOut TempC Temp Rho
global mag_vector phase_vector Hjw_vector result_mag spec_mag spec_fr test_freq

model_filename = 'RudderActuatorChannel_control';
lbfpin2Npm = 175.126835; % Unit conversion from lbf/in to N/m

warning('off','all');
warning;

StiffnessTest_Enable = 1;   %1 - Stiffness test, 2 - Normal operation, 3 - No load
Input.Control = 4;          % Custom input
Input.Custom = 1;           % Command to zero
Kst_Enable = 0;             % 0-Stiffness Test

% Frequencies of Stiffness Test Input(Hz)
% test_freq=[14,15];
% test_freq=[10,11,12,13,14,15];
test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15];
% test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40];

% Number of Integration Cycles for EACH frequency
int_cycles = zeros(1,length(test_freq));
Hjw_vector = zeros(1,length(test_freq));
mag_vector = zeros(1,length(test_freq));
phase_vector = zeros(1,length(test_freq));
for i=1:length(test_freq)
    if test_freq(i) <=0.1
        int_cycles(i)=1;
    elseif test_freq(i) <=3
        int_cycles(i)=3;
    else
        int_cycles(i)=9;
    end
end

ActStallLoad = (Supply_Pressure - Return_Pressure)*Ap;
StiffTest.Sine_Amplitude = 0.20*ActStallLoad;
StiffTest.Sine_Bias = 0.30*ActStallLoad;
StiffTest.Sine_Frequency =  2*pi*1.0; %rad/sec
TempC = 100;
[Temp,Rho] = setHydraulicProperties(TempC);


for i=1:length(test_freq)
    
    % Dynamics settling time
    Tdyn = 0.5; % 0.5s
    
    % Frequency
    freq=test_freq(i);
    
    % Period (seconds) of ith frequency
    Tp = 1/freq;
        
    % Time vector (seconds) for ith frequency
    t =[0:0.001:(Tdyn+int_cycles(i)*Tp) - 0.001]';
    
    % Sine Force Frequency
    StiffTest.Sine_Frequency = 2*pi*freq;      %rad/sec
     
    % Simulation time (seconds)
    Time = num2str(max(t));   
    simOut = sim(model_filename,'StopTime',Time);
    
    Loadp = -simOut.get('logsout').getElement('Load_(lbf)').Values.Data;
    Xpp = simOut.get('logsout').getElement('Xp').Values.Data;
    timet = simOut.get('yout').time;
    
    %indx=find(timet >= T*num_settle_cycles);
         
    [Hjw,mag,phase]=FFT_Analysis3(timet,Xpp,Loadp,freq,int_cycles(i));
       
    % Store H(jw),mag,phase in vectors before running next point
    Hjw_vector(i)=Hjw;
    mag_vector(i)=mag;
    phase_vector(i)=phase;
    
    result_mag = real(Hjw_vector)*lbfpin2Npm;
end

% Single PCU - Re [Impedance] Requirement (Rudder)
% spec_fr  = [14 15]'; %Hz
% spec_mag = [1.79E+07 1.79E+07]';%N/m
% spec_fr  = [10 11 12 13 14 15]'; %Hz
% spec_mag = [1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07]';%N/m
spec_fr  = [0.1 0.5,1 2 3 4 5 6 7 8 9 10 11 12 13 14 15]'; %Hz
spec_mag = [1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07]';%N/m
%new_spec_mag = 1.79E+07*ones(size(spec_mag),1);
