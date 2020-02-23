% Run Dynamic Stiffness Test
run('Load_Parameters')
model_filename = 'RudderActuatorChannel_control';
StiffnessTest_Enable = 1; %1 - Stiffness test, 2 - No test
Input.Control = 4; % Command to zero
Input.Custom = 1;
Kst_Enable = 0; % 0 - Stiffness Test
warning('off','all');
warning;

% Frequencies of Stiffness Test Input(Hz)
test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40];

% Number of Settling Cycles for EACH frequency
for i=1:length(test_freq)
    if test_freq(i) < 1
        settle_cycles(i)=1;
    else
        settle_cycles(i)=test_freq(i);
    end
end

% Number of Integration Cycles for EACH frequency
int_cycles=2*settle_cycles;

ActStallLoad = (Supply_Pressure - Return_Pressure)*Ap;
StiffTest.Sine_Amplitude = 0.20*ActStallLoad;
StiffTest.Sine_Bias = 0.30*ActStallLoad;
StiffTest.Sine_Frequency =  2*pi*1.0; %rad/sec


for i=1:length(test_freq)
    
    % Frequency
    freq=test_freq(i);
    
    % Period (seconds) of ith frequency
    T = 1/freq;
    
    % Number of Settling Cycles for ith frequency
    num_settle_cycles = settle_cycles(i);
    
    % Number of Integration Cycles for ith frequency
    num_int_cycles = int_cycles(i);
    
    % Time vector (seconds) for ith frequency
    t =[0:0.001:T*(num_settle_cycles + num_int_cycles) - 0.001]';
    
    % Sine Force Frequency
    StiffTest.Sine_Frequency = 2*pi*freq;      %rad/sec
     
    % Simulation time (seconds)
    Time = num2str(max(t));   
    simOut = sim(model_filename,'StopTime',Time);
    
    Loadp = -simOut.get('logsout').getElement('Load_(lbf)').Values.Data;
    Xpp = simOut.get('logsout').getElement('Xp').Values.Data;
    timet = simOut.get('yout').time;
    
    indx=find(timet >= T*num_settle_cycles);
         
    [Hjw,mag,phase]=FFT_Analysis(timet,Xpp,Loadp,freq);
       
    % Store H(jw),mag,phase in vectors before running next point
    Hjw_vector(i)=Hjw;
    mag_vector(i)=mag;
    phase_vector(i)=phase;
end

%% Single PCU - Re [Impedance] Requirement (Rudder)
spec_fr  = [2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20]'; %Hz
spec_mag = [1.81E+05 4.11E+05 7.41E+05 1.18E+06 1.74E+06 2.43E+06 3.28E+06 ...
4.31E+06 5.56E+06 7.09E+06 8.96E+06 1.13E+07 1.42E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07...
1.79E+07 1.79E+07]';%N/m
%new_spec_mag = 1.79E+07*ones(size(spec_mag),1);
        
plot(test_freq(3:end),real(Hjw_vector(3:end))*175.126835,'b*-',spec_fr,spec_mag,'r--')%,spec_fr)%,new_spec_mag,'g--');
grid on
title('Dynamic Stiffness Test Analysis')
xlabel('Frequency (Hz)')
ylabel('Dynamic Stiffness (N/m)')
legend('Design','Requirement')%,'New Requirement')


