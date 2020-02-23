% Run Dynamic Stiffness Test
run('Load_Parameters')
model_filename = 'RudderActuatorChannel';
StiffnessTest_Enable = 1; %1 - Stiffness test, 2 - No test
Input.Control = 4; % Command to zero
Input.Custom = 1;
Kst_Enable = 0; % 0 - Stiffness Test
warning('off','all');
warning;

ControlTopology = 2; % 2Closed Loop (Kp)
getControllerParameters

figure
spec_fr  = [2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20]'; %Hz
spec_mag = [1.81E+05 4.11E+05 7.41E+05 1.18E+06 1.74E+06 2.43E+06 3.28E+06 ...
4.31E+06 5.56E+06 7.09E+06 8.96E+06 1.13E+07 1.42E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07...
1.79E+07 1.79E+07]';%N/m
new_spec_mag = 1.79E+07*ones(size(spec_mag),1);
plot(spec_fr,spec_mag,'r--',spec_fr,new_spec_mag,'g--');
hold all
grid on
Xwidth_vec = [.10,.15,.20,.25,.30,.35,.40,.45,.50,.55,.60];
ColorVec = {'y','m','c','r','g','b','k','-.k','-.g','-.b','-.r'};

for ind = 1:length(Xwidth_vec)
    
    % Frequencies of Stiffness Test Input(Hz)
    test_freq=[0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20];
    Xwidth = Xwidth_vec(ind);
    
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
        Q1 = simOut.get('logsout').getElement('EHSV_Q').Values.Q1.Data;
        
        indx=find(timet >= T*num_settle_cycles);

        [Hjw,mag,phase]=FFT_Analysis(timet,Xpp,Loadp,freq);

        % Store H(jw),mag,phase in vectors before running next point
        Hjw_vector(i)=Hjw;
        mag_vector(i)=mag;
        phase_vector(i)=phase;
        Q1_vector(ind) = max(Q1*0.25974); 
    end

    %% Single PCU - Re [Impedance] Requirement (Rudder)


    plot(test_freq(3:end),real(Hjw_vector(3:end))*175.126835,ColorVec{ind})
    hold all

end


title('Dynamic Stiffness Test Analysis')
xlabel('Frequency (Hz)')
ylabel('Dynamic Stiffness (N/m)')
%legend('Requirement','New Requirement',sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(1)),...
legend('Requirement',sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(1)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(2)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(3)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(4)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(5)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(6)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(7)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(8)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(9)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(10)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(11)))    
hold off

