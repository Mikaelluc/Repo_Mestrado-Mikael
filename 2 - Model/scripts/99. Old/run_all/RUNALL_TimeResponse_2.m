% Run Time Response Test
clear all
clc

run('Load_Parameters')
model_name = 'RudderActuatorChannel_control';
Input.Control = 3; % Command step
Input.Custom = 1;
warning('off','all');
warning;

        
StiffnessTest_Enable = 3; Load_cmd = 0;
SealType = 3; SealConstValue = 0;
% Sel_bulk = 1; Sel_ent_air = 1;
Input.Step.Time = 0.25;
Input.Step.InitialValue = 0;
Input.Step.Amplitude = 30;
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
        Time = 2;
        ColorVec = {'y','m','r','c','g','b','k','--k','--r','--g','--b'};
        Kp_matrix = [10,20,40,60,80,100,120,140,160];
        Kp_matrix = [10,10];
%         Ki_matrix = [.01,.05,.1,.25,.5,.75,1,1.25,1.5,1.75,2]; Kp = 40;
        Ki_matrix = [1E-1,1,10,20,30,40,50];
        Kd_matrix = [.01,.1,.5,1,1.5,2,2.5];
      ControlTop = [5, 6];
      Xov_matrix = [5e-4, 0];
%         ColorVec = {'b','g'};
%         Kp_matrix = [40];
%         Ki_matrix = [.0001]; 
%         Kd_matrix = [0];

        for ind=1:length(Xov_matrix)


%             Kp =40;
            Ki = 0;
            Kd = 0;
            Kp = Kp_matrix(ind);
            Xov = Xov_matrix(ind);
%             Ki = Ki_matrix(ind);
%             Kd = Kd_matrix(ind);
%             ControlTopology = ControlTop(ind);
            Rate_Limit = 100;

            simOut = sim(model_name,'StopTime',num2str(Time));

            Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
            EHSV_pos = simOut.get('logsout').getElement('Xv').Values.Data;
            timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
            subplot(2,1,1)
            plot(timet,Surf_fbk,ColorVec{ind})
            ylabel('Surface position (deg)')
            grid on
            hold on
            
            subplot(2,1,2)
            plot(timet,100*EHSV_pos/0.01852,ColorVec{ind})
            ylabel('EHSV open/close (%)')
            hold on


        end

        Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
%         plot(timet,Surf_cmd,'-.r')
        grid on
        axis tight
        xlabel('Time (s)')

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
% 
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

%  subplot(2,1,1)
%             plot(surf.time,surf.signals.values,'r')
%             ylabel('Surface position (deg)')
%             grid on
%          
%             subplot(2,1,2)
%             plot(ehsv.time,ehsv.signals.values,'r')
%             ylabel('EHSV open/close (%)')
%             grid on


    otherwise
        
end
