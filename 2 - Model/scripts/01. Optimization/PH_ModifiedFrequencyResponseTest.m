%% Frequency Response

% Run Frequency Response Test
%run('Load_Parameters')

global StiffnessTest_Enable Load_cmd FreqResp_type TempC Temp Rho
global Input EHSVTest  
global test_freq Hjw_vec mag_vec phase_vec
global GM GF PM PF Bw Bc

model_name = 'RudderActuatorChannel_control';
StiffnessTest_Enable = 3; %1 - Stiffness test, 2 - Regular Load, 3 - No load
Load_cmd = 0;
TempC = 100;
[Temp,Rho] = setHydraulicProperties(TempC);

warning('off','all');
warning;

FreqResp_type = 0;
plot = 0;

% Run Frequency Response Test
switch FreqResp_type 
    case 0 % Run Complete Frequency Response Test
        Input.Control = 2; %Sine Wave surface command
        Input.Sine.Amplitude = .5; %Surface command input(deg)
        Input.Sine.Bias = 0;
        Input.Sine.Phase = 0;
        Input.Chirp.Enable = 0; % 1 - Chirp Signal Enabled 
        EHSVTest.Enable = 1; %1- Normal Operation, 2 - Frequency Test, 3 Step Test
        
        % Frequencies for Frequency Response Test(Hz)
        test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
        time_freq = zeros(1,length(test_freq));

        % Number of cycles of respective frequency
        int_cycles = zeros(1,length(test_freq));
        for i=1:length(test_freq)
            if test_freq(i) <=1
                int_cycles(i)=1;
            elseif test_freq(i) <=3
                int_cycles(i)=3;
            else
                int_cycles(i)=9;
            end
        end
        
        % Surface Position Amplitude for Frequency Response Test (deg)
        for i=1:length(test_freq)
            
            % Dynamics settling time
            Tdyn = 0.5; % 0.5s

            % Frequency (Hz)
            freq=test_freq(i);

            % Period of ith frequency (s)
            Tp = 1/freq;

            % Time vector for ith frequency (s)
            t =[0:0.001:(Tdyn+int_cycles(i)*Tp) - 0.001]';

            % Input Suface command Frequency (rad/sec)
            Input.Sine.Frequency  = 2*pi*freq;

            % Simulation time (s)
            Time = num2str(max(t));
            simOut = sim(model_name,'StopTime',Time);           
          
            %indx=find(timet >= Tp*num_settle_cycles);
            Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
            Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
            timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
            [Hjw,mag,phase]=FFT_Analysis3(timet,Surf_cmd,Surf_fbk,freq,int_cycles(i));
            
            % Store H(jw),mag,phase in vectors
            Hjw_vec(i)=Hjw;
            mag_vec(i)=mag;
            phase_vec(i)=phase;
        end
        
        %FreqAnalysis = findmargin(mag_vec,phase_vec,test_freq);
        [GM,GF,PM,PF,Bw,Bc] = findmargin3(mag_vec,phase_vec,test_freq);   
        %[GM,GF,PM,PF] = imargin(mag_vec,phase_vec,test_freq)
        
        if plot == 1
            figure('Name','Frequency Response'); 
            subplot(2,1,1),semilogx(test_freq,20*log10(mag_vec),'b-*');
            gain_str = strcat('Gain Margin:',{' '},num2str(GM(end)),{' '},'dB',' @ ',{' '},num2str(GF(end)),{' '},'Hz');
            %phase_str = strcat('Phase Margin:',{' '},num2str(PM(end)),{' '},'deg',' @ ',{' '},num2str(PF(end)),{' '},'Hz');
            phase_str = strcat('Phase Margin:',{' '},PM,{' '},'deg',' @ ',{' '},PF,{' '},'Hz');
            band_str = strcat('Bandwidth:',{' '},num2str(Bw),{' '},'Hz');
            title({'Rudder Actuator Frequency Response';gain_str{1} ;phase_str{1};band_str{1}})

            grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)')

            subplot(2,1,2),semilogx(test_freq,phase_vec,'b-*')
            grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')
        end
            
    otherwise
        Time = 0;
        fprintf('No frequency response simulation running');
end
