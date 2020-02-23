% Run Dynamic Stiffness Test
clear all
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

figure('name','Dynamic Stiffness')

switch ControlTopology
    
    case 1

        test_freq=[0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,30,40];
        ON_OFF_hyst_vec = [0.0005 0.001 0.005 0.01 0.05];

       for ind=1:length(ON_OFF_hyst_vec)
           
        ON_OFF_hyst = ON_OFF_hyst_vec(ind);
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
        plot(test_freq(3:end),real(Hjw_vector(3:end))*175.126835)
        hold all
       
end
        spec_fr  = [2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20]'; %Hz
        spec_mag = [1.81E+05 4.11E+05 7.41E+05 1.18E+06 1.74E+06 2.43E+06 3.28E+06 ...
        4.31E+06 5.56E+06 7.09E+06 8.96E+06 1.13E+07 1.42E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07...
        1.79E+07 1.79E+07]';%N/m
        new_spec_mag = 1.79E+07*ones(size(spec_mag),1);
        plot(spec_fr,spec_mag,'-.r')
        grid on
        title('Dynamic Stiffness Test Analysis')
        xlabel('Frequency (Hz)')
        ylabel('Dynamic Stiffness (N/m)')
        hold off
        
        legend(sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(1)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(2)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(3)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(4)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(5)*100),...
        'Requirement')%,'New Requirement')
        
    case 2
        
%         ColorVec = {'y','m','c','r','g','b','k','--k','--r','--g','--b'};
%         ind = 1;
%         Kp_matrix = [10,20,40,60,80,100,120,140,160,180,200];
%         Ki_matrix = [.01,.05,.1,.25,.5,.75,1,1.25,1.5,1.75,2]; Kp = 40;
% %         Ki_matrix = [.1,.5,1,2,5,8,10,20,50,100,200];
%         Ki_matrix = [1E-1,5E-2,1E-2,5E-3,1E-3,.1E-4,1E-5];
%         Kd_matrix = [.01,.1,.5,1,1.5,2,2.5,4,5,10,20];
%         Aleakint_matrix = [.1*pi*.005^2,pi*.005^2,4*pi*.005^2,8*pi*.005^2,10*pi*.005^2];
% %         
        ColorVec = {'b','g','k','r'};
%         Kp_matrix = [40,60,40,40];
%         Ki_matrix = [1e-6,1e-6,1e-6,.1]; 
%         Kd_matrix = [.5,.5,.8,.5];
        Kp_matrix = [40,40,40,40];
        Ki_matrix = [0,1E-6,0,1e-6]; 
        Kd_matrix = [.0,.0,.7,.7];
        T_ES_matrix = [1/100,1/500,1/1000,1/2000];
        for ind=1:length(ColorVec)
            % Frequencies of Stiffness Test Input(Hz)

            test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35,40];

%             Kp = Kp_matrix(ind);
%             Ki = Ki_matrix(ind);
%             Kd = Kd_matrix(ind);
            Kp =40;Ki =0; Kd =0;
%             Aleakint = Aleakint_matrix(ind);
            T_ES = T_ES_matrix(ind);
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
            plot(test_freq(3:end),real(Hjw_vector(3:end))*175.126835,ColorVec{ind})
            hold on

        end
        spec_fr  = [1 2 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 20 30]'; %Hz
        spec_mag = [0 0 1.81E+05 4.11E+05 7.41E+05 1.18E+06 1.74E+06 2.43E+06 3.28E+06 ...
        4.31E+06 5.56E+06 7.09E+06 8.96E+06 1.13E+07 1.42E+07 1.79E+07 1.79E+07 1.79E+07 1.79E+07...
        1.79E+07 1.79E+07 0 0]';%N/m
        new_spec_mag = 1.79E+07*ones(size(spec_mag),1);
        plot(spec_fr,spec_mag,'-.r')%,spec_fr,new_spec_mag,'-.g');
        grid on
        title('Dynamic Stiffness Test Analysis')
        xlabel('Frequency (Hz)')
        ylabel('Dynamic Stiffness (N/m)')
        hold off
%         legend(sprintf('Kp = %d',Kp_matrix(1)),...
%         sprintf('Kp = %d',Kp_matrix(2)),...
%         sprintf('Kp = %d',Kp_matrix(3)),...
%         sprintf('Kp = %d',Kp_matrix(4)),...
%         sprintf('Kp = %d',Kp_matrix(5)),...
%         sprintf('Kp = %d',Kp_matrix(6)),...
%         sprintf('Kp = %d',Kp_matrix(7)),...
%         sprintf('Kp = %d',Kp_matrix(8)),...
%         sprintf('Kp = %d',Kp_matrix(9)),...
%         sprintf('Kp = %d',Kp_matrix(10)),...
%         sprintf('Kp = %d',Kp_matrix(11)),...
%         'Requirement','New Requirement')
%     
%         legend(sprintf('Ki = %.2f',Ki_matrix(1)),...
%         sprintf('Ki = %.2f',Ki_matrix(2)),...
%         sprintf('Ki = %.2f',Ki_matrix(3)),...
%         sprintf('Ki = %.2f',Ki_matrix(4)),...
%         sprintf('Ki = %.2f',Ki_matrix(5)),...
%         sprintf('Ki = %.2f',Ki_matrix(6)),...
%         sprintf('Ki = %.2f',Ki_matrix(7)),...
%         sprintf('Ki = %.2f',Ki_matrix(8)),...
%         sprintf('Ki = %.2f',Ki_matrix(9)),...
%         sprintf('Ki = %.2f',Ki_matrix(10)),...
%         sprintf('Ki = %.2f',Ki_matrix(11)),...
%         'Requirement')%,'New Requirement')
% % 
%         legend(sprintf('Kd = %.2f',Kd_matrix(1)),...
%         sprintf('Kd = %.2f',Kd_matrix(2)),...
%         sprintf('Kd = %.2f',Kd_matrix(3)),...
%         sprintf('Kd = %.2f',Kd_matrix(4)),...
%         sprintf('Kd = %.2f',Kd_matrix(5)),...
%         sprintf('Kd = %.2f',Kd_matrix(6)),...
%         sprintf('Kd = %.2f',Kd_matrix(7)),...
%         sprintf('Kd = %.2f',Kd_matrix(8)),...
%         sprintf('Kd = %.2f',Kd_matrix(9)),...
%         sprintf('Kd = %.2f',Kd_matrix(10)),...
%         sprintf('Kd = %.2f',Kd_matrix(11)),...
%         'Requirement')%,'New Requirement')
    
%         legend(sprintf('Aleak_{int} = %.2E',Aleakint_matrix(1)),...
%         sprintf('Aleak_{int} = %.2E',Aleakint_matrix(2)),...
%         sprintf('Aleak_{int} = %.2E',Aleakint_matrix(3)),...
%         sprintf('Aleak_{int} = %.2E',Aleakint_matrix(4)),...
% %         sprintf('Aleak_{int} = %.2E',Aleakint_matrix(5)),...
%         'Requirement')
%     
    otherwise
        
end




