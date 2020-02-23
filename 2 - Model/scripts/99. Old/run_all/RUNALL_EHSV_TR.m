% Run Time Response Test
clear all
clc

run('Load_Parameters')
model_name = 'RudderActuatorChannel';
Load_cmd = 0;
Input.Control = 3; % Command step
Input.Custom = 1;
warning('off','all');
warning;

        
StiffnessTest_Enable = 2;
Input.Step.Time = 0.25;
Input.Step.InitialValue = 0;
Input.Step.Amplitude = 30;
Input.Step.FinalValue = Input.Step.InitialValue + Input.Step.Amplitude;
EHSVTest.Enable = 1;

ControlTopology = 2; % 2Closed Loop (Kp)
figure('Name','Time Response')

Xwidth_vec = [.10,.15,.20,.25,.30,.35,.40,.45,.50,.55,.60];
ColorVec = {'y','m','c','r','g','b','k','-.k','-.g','-.b','-.r'};

for ind=1:length(Xwidth_vec)
    
    Xwidth = Xwidth_vec(ind);    
    simOut = sim(model_name,'StopTime',num2str(Time));

    Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
    timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
    Q1 = simOut.get('logsout').getElement('EHSV_Q').Values.Q1.Data;
    Q1_vector(ind) = max(Q1*0.25974);
    
    plot(timet,Surf_fbk,ColorVec{ind})
    hold on
    
end

Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
plot(timet,Surf_cmd,'-.r')
grid on
axis tight

legend(sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(1)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(2)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(3)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(4)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(5)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(6)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(7)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(8)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(9)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(10)),...
sprintf('EHSV Xwidth = %.2f in',Xwidth_vec(11)),...
'Surface Command')
xlabel('Time (s)')
ylabel('Surface Position (deg)')
title('Step Response - EHSV')
hold off