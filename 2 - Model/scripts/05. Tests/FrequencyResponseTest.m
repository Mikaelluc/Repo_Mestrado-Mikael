%% Frequency Response

% Run Frequency Response Test
%run('Load_Parameters')
model_name = 'RudderActuatorChannel_control';
StiffnessTest_Enable = 3; %1 - Stiffness test, 2 - Regular Load, 3 - No load
Load_cmd = 0;
warning('off','all');
warning;

% Run Frequency Response Test
switch FreqResp_type 
    case 0 % Run Complete Frequency Response Test
        Input.Control = 2; %Sine Wave surface command
        Input.Sine.Amplitude = .5; %Surface command input(deg)
        Input.Sine.Bias = 0;
        Input.Sine.Phase = 0;
        EHSVTest.Enable = 1; %1- Normal Operation, 2 - Frequency Test, 3 Step Test
        ControlTopology = 2; % 1- Closed Loop (Kp), 2- Open Loop
        getControllerParameters
        
        % Frequencies for Frequency Response Test(Hz)
        test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
        
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
        
        %[GM,GF,PM,PF] = imargin(mag_vec,phase_vec,test_freq)
        
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

        
    case 1
        Input.Control = 4; % No surface command input
        EHSVFreqTest.Enable = 2;
        %EHSVFreqTest.Sine.Amplitude = .1; %.1 ma
        EHSVFreqTest.Sine.Amplitude = 5; %.1 ma
        EHSVTest.Enable = 2; %1- Normal Operation, 2 - Frequency Test, 3 Step Test
        
        % Frequencies for Frequency Response Test(Hz)
        test_freq=[0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40,45,50,55,60,65,70,75,80,85,90,100,200,300,400,500,600,700,800,900];
        
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
            EHSVFreqTest.Sine.Frequency  = 2*pi*freq;
            
            % Simulation time (s)
            Time = num2str(max(t));
            simOut = sim(model_name,'StopTime',Time);
            
%             Loadp = -simOut.get('logsout').('Load_(lbf.in)').Data;
%             Xpp = simOut.get('logsout').('Actuation System').Xp.Data; %SurfacePositionCmd_(deg)
%             timet = simOut.get('yout').time;
            
            %indx=find(timet >= Tp*num_settle_cycles);
            EHSV_curr_cmd = simOut.get('logsout').getElement('EHSV_current_cmd').Values.Data;
            EHSV_Xv = simOut.get('logsout').getElement('Xv').Values.Data;
            timet = simOut.get('logsout').getElement('Xv').Values.Time;
            [Hjw,mag,phase]=FFT_Analysis(timet,EHSV_curr_cmd ,EHSV_Xv,freq);
            
            % Store H(jw),mag,phase in vectors
            Hjw_vec(i)=Hjw;
            mag_vec(i)=mag;
            phase_vec(i)=phase;
        end
        
%         indexPhase180 = find(phase_vec < -180,1);
%         if isempty(indexPhase180)
%             NotFound3db180deg = 0;
%         else
%             phase180freq = interp1([phase_vec(indexPhase180-1) phase_vec(indexPhase180)],...
%                 [test_freq(indexPhase180-1) test_freq(indexPhase180)],-180);
%         end
%         
%         indexGain3db = find(20*log10(mag_vec) < -3,1);
%         if isempty(indexGain3db)
%             NotFound3db180deg = 0;
%         elseif indexGain3db == 1
%             gain3dbfreq = interp1([20*log10(mag_vec(indexGain3db)) 20*log10(mag_vec(indexGain3db+1))],...
%                 [test_freq(indexGain3db) test_freq(indexGain3db+1)],-3);
%         else
%             gain3dbfreq = interp1([20*log10(mag_vec(indexGain3db-1)) 20*log10(mag_vec(indexGain3db))],...
%                 [test_freq(indexGain3db-1) test_freq(indexGain3db)],-3);
%         end
%         
%         GainMargin =  0 - 20*log10(interp1(test_freq,mag_vec,phase180freq));
%         
%         PhaseMargin = abs(-180 - interp1(test_freq,phase_vec,gain3dbfreq));
 [GM,GF,PM,PF,Bw] = findmargin2(mag_vec,phase_vec,test_freq);
        
        %[GM,GF,PM,PF] = imargin(mag_vec,phase_vec,test_freq)
        
        figure('Name','Frequency Response');
 
        subplot(2,1,1),semilogx(test_freq,20*log10(mag_vec),'b-*');
        gain_str = strcat('Gain Margin:',{' '},num2str(GM),{' '},'dB',' @ ',{' '},num2str(GF),{' '},'Hz');
        phase_str = strcat('Phase Margin:',{' '},num2str(PM),{' '},'dB',' @ ',{' '},num2str(PF),{' '},'Hz');
        band_str = strcat('Bandwidth:',{' '},num2str(Bw),{' '},'Hz');
        title({'EHSV Frequency Response';gain_str{1} ;phase_str{1};band_str{1}})
        
%         hx = graph2d.constantline(FreqAnalysis.GMFreq(end), 'LineStyle','--', 'Color','r');
%         changedependvar(hx,'x');
%         hhx = graph2d.constantline(FreqAnalysis.PMFreq(end), 'LineStyle','--', 'Color','g');
%         changedependvar(hhx,'x');
%         text(FreqAnalysis.GMFreq + 1,-FreqAnalysis.GainMargin + 4,['\color{blue}Gain Margin: ' ,num2str(FreqAnalysis.GainMargin,'%1.3f'), '\color{blue}dB'],...
%         'FontSize',8,...
%         'VerticalAlignment','middle',...
%         'HorizontalAlignment','left',...
%         'BackgroundColor',[1 1 1],...
%         'EdgeColor','black');
        grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)')
        
        subplot(2,1,2),semilogx(test_freq,phase_vec,'b-*')
%         hx = graph2d.constantline(FreqAnalysis.GMFreq(end), 'LineStyle','--', 'Color','r');
%         changedependvar(hx,'x');
%         hhx = graph2d.constantline(FreqAnalysis.PMFreq(end), 'LineStyle','--', 'Color','g');
%         changedependvar(hhx,'x');
        grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')
%         
%         text(FreqAnalysis.PMFreq(end) + 1,-180+FreqAnalysis.PhaseMargin(end) + 10,['\color{blue}Phase Margin: ' ,num2str(FreqAnalysis.PhaseMargin(end),'%1.3f'), '\color{blue} deg'],...
%         'FontSize',8,...
%         'VerticalAlignment','middle',...
%         'HorizontalAlignment','left',...
%         'BackgroundColor',[1 1 1],...
%         'EdgeColor','black');

        
% %         figure('Name','Frequency Response');
% %  
% %         subplot(2,1,1),semilogx(test_freq,20*log10(mag_vec),'b-*');
% %         title('EHSV Frequency Response')
% %         hx = graph2d.constantline(gain3dbfreq, 'LineStyle','--', 'Color','r');
% %         changedependvar(hx,'x');
% %         hhx = graph2d.constantline(phase180freq, 'LineStyle','--', 'Color','g');
% %         changedependvar(hhx,'x');
% %         text(phase180freq,-GainMargin,['\color{blue}Gain Margin: ' ,num2str(GainMargin,'%1.3f')],...
% %         'FontSize',8,...
% %         'VerticalAlignment','middle',...
% %         'HorizontalAlignment','left',...
% %         'BackgroundColor',[1 1 1],...
% %         'EdgeColor','black');
% %         text(gain3dbfreq,0,['\color{blue}Bandwidth: ' ,num2str(gain3dbfreq,'%1.3f')],...
% %         'FontSize',8,...
% %         'VerticalAlignment','middle',...
% %         'HorizontalAlignment','left',...
% %         'BackgroundColor',[1 1 1],...
% %         'EdgeColor','black');
% %         grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)')
% %         
% %         subplot(2,1,2),semilogx(test_freq,phase_vec,'b-*')
% %         hx1 = graph2d.constantline(gain3dbfreq, 'LineStyle','--', 'Color','r');
% %         changedependvar(hx1,'x');
% %         hhx1 = graph2d.constantline(phase180freq, 'LineStyle','--', 'Color','g');
% %         changedependvar(hhx1,'x');
% %         text(gain3dbfreq,-180+PhaseMargin,['\color{blue}Phase Margin: ' ,num2str(PhaseMargin,'%1.3f')],...
% %         'FontSize',8,...
% %         'VerticalAlignment','middle',...
% %         'HorizontalAlignment','left',...
% %         'BackgroundColor',[1 1 1],...
% %         'EdgeColor','black');
% %         grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')
% %         
    otherwise
        Time = 0;
        fprintf('No frequency response simulation running');
end
%

