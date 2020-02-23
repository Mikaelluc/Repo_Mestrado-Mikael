% Run Time Response Test
clear all
clc

run('Load_Parameters')
model_name = 'RudderActuatorChannel_control';
Load_cmd = 0;
Input.Control = 3; % Command step
Input.Custom = 1;
warning('off','all');
warning;

        
StiffnessTest_Enable = 2;
Input.Step.Time = 0.25;
Input.Step.InitialValue = 0;
Input.Step.Amplitude = 10;
Input.Step.FinalValue = Input.Step.InitialValue + Input.Step.Amplitude;
EHSVTest.Enable = 1;

ControlTopology = 2; % 2Closed Loop (Kp)
figure('Name','Time Response')

switch ControlTopology
    case 1
        
        %ON_OFF_hyst_vec = [0.0005 0.001 0.005 0.01 0.05];
        ON_OFF_hyst_vec = [0.001];
        
        for ind = 1:length(ON_OFF_hyst_vec)
            ON_OFF_hyst = ON_OFF_hyst_vec(ind);
        getControllerParameters
        Time = 2.5;
        Rate_Limit = 100;
        simOut = sim(model_name,'StopTime',num2str(Time));
        Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
        timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;

        plot(timet,Surf_fbk)
        title('ON-OFF controller Step Response')
        hold all
        
        end

        Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
        plot(timet,Surf_cmd,'-.r')
        grid on
        axis tight
        legend(sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(1)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(2)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(3)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(4)*100),...
        sprintf('Hysteresis error = %.2f %%',ON_OFF_hyst_vec(5)*100),'Surface Command')
    
        
    case 2
        getControllerParameters
        Time = 1.0;
        ColorVec = {'y','m','k','r','g','b','c','--k','--b','--g'};
        Kp_matrix = [10,20,40,60,80,100,120,140,160];
%         Ki_matrix = [.01,.05,.1,.25,.5,.75,1,1.25,1.5,1.75,2]; Kp = 40;
        Ki_matrix = [10,1,1E-1,5E-2,1E-2,5E-3,1E-3,.1E-4,1E-5];
        Kd_matrix = [.01,.1,.5,1,1.5,2,2.5,4,5,10];
        Kcontrol = [2.430e1 5.853e-4 1.692e-4 6.532e-4 5.728e1 -4.902e-3];
%         
%         ColorVec = {'b','g'};
%         Kp_matrix = [40];
%         Ki_matrix = [.0001]; 
%         Kd_matrix = [0];

        for ind=1:length(1)


            Kp = 40;
            Ki = 0;
%             Kd = 0 ;
%             Kp = Kp_matrix(ind);
%             Ki = Ki_matrix(ind);
            Kd = Kd_matrix(ind);
            
            Rate_Limit = 100;

            simOut = sim(model_name,'StopTime',num2str(Time));

            Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
            EHSV_pos = simOut.get('logsout').getElement('Xv').Values.Data;
            timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
            subplot(2,1,1)
            plot(timet,Surf_fbk,ColorVec{ind})
            hold on
            
            subplot(2,1,2)
            plot(timet,100*EHSV_pos/0.01852,ColorVec{ind})
            hold on


        end

        Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
%         plot(timet,Surf_cmd,'-.r')
        grid on
        axis tight
        ylabel('Time (s)')

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
%         'Suface Command');
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
    
%         legend(sprintf('Ki = %.2E',Ki_matrix(1)),...
%         sprintf('Ki = %.2E',Ki_matrix(2)),...
%         sprintf('Ki = %.2E',Ki_matrix(3)),...
%         sprintf('Ki = %.2E',Ki_matrix(4)),...
%         sprintf('Ki = %.2E',Ki_matrix(5)),...
%         sprintf('Ki = %.2E',Ki_matrix(6)),...
%         sprintf('Ki = %.2E',Ki_matrix(7)),...
%         'Command')%,'New Requirement')

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
    
%          legend('P','PID optimal',...
%         'Requirement')%,'New Requirement')

    otherwise
        
end
