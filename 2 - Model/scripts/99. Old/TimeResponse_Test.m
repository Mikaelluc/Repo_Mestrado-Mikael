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

ControlTopology = 2; % 2 Closed Loop
figure('Name','Time Response')

simOut = sim(model_name,'StopTime',num2str(Time));
Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;


Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
SurfaceCmd.Values.Data = Surf_cmd;


SurfacePos.Values.Data = Surf_fbk;
SurfacePos.Values.Time = timet;
n=length(SurfacePos.Values.Time);

final = SurfacePos.Values.Data(n);

FullStroke_deg = 2*33.3;

StepResponse = stepinfo(SurfacePos.Values.Data,SurfacePos.Values.Time,SurfaceCmd.Values.Data(n),'RiseTimeLimits',[0.15,0.85],'SettlingTimeThreshold',0.02);

    Td = 0;
    Tr1 = 0;
    Tr2 = 0;

    for i=1:n
        if abs(SurfacePos.Values.Data(i))> abs(SurfacePos.Values.Data(1)) && Td == 0
            Td = SurfacePos.Values.Time(i);
        end

    end

    Ts = StepResponse.SettlingTime - Input.Step.Time;
    Tp = StepResponse.PeakTime - Input.Step.Time;
    Tr = StepResponse.RiseTime - Input.Step.Time;
    Mp = StepResponse.Overshoot;
    yss =  SurfaceCmd.Values.Data(n);
    StepResponse.av_rate = (0.85*Input.Step.FinalValue - 0.15*Input.Step.FinalValue)/StepResponse.RiseTime;
    StepResponse.ess = (final - SurfaceCmd.Values.Data(n))/FullStroke_deg;

     %% Plot Results
    figure(1)

    plot(SurfacePos.Values.Time,SurfaceCmd.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(SurfacePos.Values.Time,SurfacePos.Values.Data,'b','LineWidth',2);

    plot(Ts*ones(n,1),linspace(0,1.02*final,n),'k--');
    plot(SurfacePos.Values.Time,.98*final*ones(n,1),'k--');
    plot(SurfacePos.Values.Time,1.02*final*ones(n,1),'k--');

    plot(Tp*ones(n,1),linspace(0,StepResponse.Peak*final,n),'k--');
    plot(linspace(0,Tp,n),StepResponse.Peak*final*ones(n,1),'k--');

    text(Td+0.02,0,...
        ['\color{blue}Td ' ,num2str(Td-Input.Step.Time,'%1.3f'),sprintf('\n'), '\color{red}Td_e ',num2str(SP.td)],...
        'FontSize',8,...
        'VerticalAlignment','bottom',...
        'HorizontalAlignment','right',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');

    text(Tr+0.1,final/2,...
        ['\color{blue}Tr ' ,num2str(StepResponse.RiseTime-Input.Step.Time,'%1.3f'),sprintf('\n'), '\color{red}Tr_e ',num2str(SP.tr)],...
        'FontSize',8,...
        'VerticalAlignment','bottom',...
        'HorizontalAlignment','right',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');


    text(Ts-0.5,0.7*final+0.7*sign(final),['\color{blue}Ts ' ,num2str(Ts-Input.Step.Time,'%1.3f'),sprintf('\n'),'\color{red}Ts_e ',num2str(SP.tss)],...
        'FontSize',8,...
        'VerticalAlignment','middle',...
        'HorizontalAlignment','left',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');

    text(Tp-0.01,StepResponse.Peak+1.5*sign(final),...
        ['\color{blue}Mp ' num2str(Mp,'%3.1f') '%',...
        sprintf('\n'),'\color{blue}Tp ' num2str(Tp-Input.Step.Time,'%1.3f'),sprintf('\n'),'\color{red}Mp_e ' num2str((SP.mp)*100,'%3.1f') '%'],...
         'FontSize',8,...
        'VerticalAlignment','middle',...
        'HorizontalAlignment','right',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');

    text(SurfacePos.Values.Time(n),0.5,['\color{blue}AvgRate ' num2str(StepResponse.av_rate,'%1.2f'),' \color{red}AvgRate_e >' num2str(SP.avrate,'%1.2f'),...
        sprintf('\n'),'\color{blue}SSe ' num2str(abs(StepResponse.ess*100),'%1.2f') '%',' \color{red}SSe_e <' num2str(SP.ess*100,'%1.2f') '%'],...
        'FontSize',8,...
        'VerticalAlignment','bottom',...
        'HorizontalAlignment','right',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');

    xlabel('Time (s)','FontSize',12), ylabel('\Theta (deg)','FontSize',12),
    title('Step Input Response Analysis','FontWeight','bold','FontSize',12) 
    legend({'Command';'System Response'},...
        'FontSize',8,...
        'Position',[0.7 0.5 0.2 0]);
    if final>0
        axis([0 SurfacePos.Values.Time(n) min(SurfacePos.Values.Data) final+3])
    else
        axis([0 SurfacePos.Values.Time(n) final-4 max(SurfacePos.Values.Data)])
    end