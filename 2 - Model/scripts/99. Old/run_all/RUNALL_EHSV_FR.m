run('Load_Parameters')
Input.Control = 2; %Sine Wave surface command
Input.Sine.Amplitude = .5; %Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;
EHSVTest.Enable = 1; %1- Normal Operation, 2 - Frequency Test, 3 Step Test

model_name = 'RudderActuatorChannel';
StiffnessTest_Enable = 3; %1 - Stiffness test, 2 - Regular Load, 3 - No load
Load_cmd = 0;
warning('off','all');
warning;


ControlTopology = 2; % 1- Closed Loop (Kp), 2- Open Loop
getControllerParameters
figure('Name','Frequency Response')

Xwidth_vec = [.10,.15,.20,.25,.30,.35,.40,.45,.50,.55,.60];
ColorVec = {'y','m','c','r','g','b','k','-.k','-.g','-.b','-.r'};
test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40];

FR_RES =cell(1,size(test_freq,2));

for ind = 1:length(Xwidth_vec)
    

     Xwidth = Xwidth_vec(ind);
     Rate_Limit = 100;
        % Input Number of Settling Cycles (at each frequency)
        % Purpose is to allow the system to reach steady-state at a specific operating point (e.g., non-zero bias load or non-zero position) before integration.
        for i=1:length(test_freq)
            if test_freq(i) < 1
                settle_cycles(i)=1;
            else
                settle_cycles(i)=test_freq(i);
            end
        end

        % Input Number of Integration Cycles (at each frequency)
        int_cycles=2*settle_cycles;

        % Surface Position Amplitude for Frequency Response Test (deg)
        for i=1:length(test_freq)

            % Frequency (Hz)
            freq=test_freq(i);

            % Period of ith frequency (s)
            Tp = 1/freq;

            % Number of Settling Cycles for ith frequency
            num_settle_cycles = settle_cycles(i);

            % Number of Integration Cycles for ith frequency
            num_int_cycles = int_cycles(i);

            % Time vector for ith frequency (s)
            t =[0:0.001:Tp*(num_settle_cycles + num_int_cycles) - 0.001]';

            % Input Suface command Frequency (rad/sec)
            Input.Sine.Frequency  = 2*pi*freq;

            % Simulation time (s)
            Time = num2str(max(t));
            simOut = sim(model_name,'StopTime',Time);


            %indx=find(timet >= Tp*num_settle_cycles);
            Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
            Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
            timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
            [Hjw,mag,phase]=FFT_Analysis(timet,Surf_cmd,Surf_fbk,freq);

            % Store H(jw),mag,phase in vectors
            Hjw_vec(i)=Hjw;
            mag_vec(i)=mag;
            phase_vec(i)=phase;
        end

        %FreqAnalysis = findmargin(mag_vec,phase_vec,test_freq);

        [GM,GF,PM,PF,Bw] = findmargin2(mag_vec,phase_vec,test_freq);
        FR_RES{1,ind} = [GM,GF,PM,PF,Bw];
        %[GM,GF,PM,PF] = imargin(mag_vec,phase_vec,test_freq)

        %figure('Name','Frequency Response');

        subplot(2,1,1),semilogx(test_freq,20*log10(mag_vec),ColorVec{ind});
%         gain_str = strcat('Gain Margin:',{' '},num2str(GM(end)),{' '},'dB',' @ ',{' '},num2str(GF(end)),{' '},'Hz');
%         phase_str = strcat('Phase Margin:',{' '},num2str(PM(end)),{' '},'deg',' @ ',{' '},num2str(PF(end)),{' '},'Hz');
%         band_str = strcat('Bandwidth:',{' '},num2str(Bw),{' '},'Hz');
%         title({'Rudder Actuator Frequency Response';gain_str{1} ;phase_str{1};band_str{1}})
        hold on
        grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)')

        subplot(2,1,2),semilogx(test_freq,phase_vec,ColorVec{ind})
        hold on    
        grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')
                
end
title('Frequency Response - EHSV parameter')
legend(sprintf('EHSV Xwidth = %.2f',Xwidth_vec(1)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(2)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(3)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(4)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(5)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(6)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(7)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(8)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(9)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(10)),...
sprintf('EHSV Xwidth = %.2f',Xwidth_vec(11)))
hold off