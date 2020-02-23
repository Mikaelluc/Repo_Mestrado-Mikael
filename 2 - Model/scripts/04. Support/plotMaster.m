% Initial Variables

SurfaceCmd.Values.Time = yout.time;
SurfacePos.Values.Time = yout.time;
SurfaceRate.Values.Time = yout.time;
Load.Values.Time = yout.time;
HornArm.Values.Time = yout.time;

SurfaceCmd.Values.Data = yout.signals(1,1).values;
SurfacePos.Values.Data = yout.signals(1,2).values;
SurfaceRate.Values.Data = yout.signals(1,3).values;
Load.Values.Data = yout.signals(1,4).values;
HornArm.Values.Data = yout.signals(1,5).values;

BulkModulusC1.Values = logsout.getElement('BulkModulusC1').Values;
BulkModulusC2.Values = logsout.getElement('BulkModulusC2').Values;
P1.Values = logsout.getElement('P1').Values;
P2.Values = logsout.getElement('P2').Values;
FrictionForce.Values = logsout.getElement('FrictionForce').Values;
Xpiston.Values = logsout.getElement('Xp').Values;

Xv_EHSV.Values = logsout.getElement('Xv').Values;
Q_EHSV.Values = logsout.getElement('EHSV_Q').Values;
i_EHSV.Values = logsout.getElement('EHSV_current_cmd').Values;

Koil.Values.Time = yout.time;
Koil.Values.Data = Ap^2.*(BulkModulusC1.Values.Data ./ (V011.*ones(length(yout.time),1) + Ap.*Xpiston.Values.Data)...
    + BulkModulusC2.Values.Data ./ (V021.*ones(length(yout.time),1)-Ap.*Xpiston.Values.Data)).*6894.75729;

n=length(SurfacePos.Values.Time);
final = SurfacePos.Values.Data(n);

FullStroke_deg = 2*33.3;

switch Input.Control
    case 1 %ToDO
        fprintf('ToDo');
        
    case 2 %Sine Input Response
    figure(1)

    plot(SurfacePos.Values.Time,SurfaceCmd.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(SurfacePos.Values.Time,SurfacePos.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',12), ylabel('\Theta (deg)','FontSize',12),
    title('Sine Input Response Analysis','FontWeight','bold','FontSize',12) 
    legend({'Command';'System Response'},...
        'FontSize',8,...
        'Position',[0.7 0.5 0.2 0]);

    figure(2)
       
    subplot(2,2,1)
    plot(SurfaceRate.Values.Time,SurfaceRate.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Surface Rate (deg/s)','FontSize',7),
    title('Surface Rate','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,2)
    plot(Xpiston.Values.Time,Xpiston.Values.Data,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Xp (in)','FontSize',7),
    title('Piston position','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,3)
    plot(Load.Values.Time,(Load.Values.Data.*HornArm.Values.Data)*0.11298483,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Horn Arm (in)','FontSize',7),
    title('Aerodynamic Hinge Momment Load','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,4)
    plot(FrictionForce.Values.Time,FrictionForce.Values.Data*4.44822,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Friction Force (N)','FontSize',7),
    title('Friction force','FontWeight','bold','FontSize',7)
    axis tight
    
    figure(3)
    subplot(3,1,1)
    plot(Koil.Values.Time,Koil.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Oil Stiffness (N/m2)','FontSize',7)
    title('Stiffness Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(BulkModulusC1.Values.Time,BulkModulusC1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(BulkModulusC2.Values.Time,BulkModulusC2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Bulk Modulus (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    subplot(3,1,3)
    plot(P1.Values.Time,P1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(P2.Values.Time,P2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Chamber pressures (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    figure(4)
    subplot(3,1,1)
    plot(Xv_EHSV.Values.Time,Xv_EHSV.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV Spool Position (in)','FontSize',7)
    title('EHSV Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(i_EHSV.Values.Time,i_EHSV.Values.Data,'r','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV current (mA)','FontSize',7),
    axis tight
    
    subplot(3,1,3)
    plot(Q_EHSV.Values.Q1.Time,Q_EHSV.Values.Q1.Data.*0.25974 ,'r','LineWidth',2); grid on, hold on,
    plot(Q_EHSV.Values.Q2.Time,Q_EHSV.Values.Q2.Data.*0.25974 ,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('EHSV flow (gpm)','FontSize',7),
    legend({'Extension chamber','Retraction chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    case 3 % Step Input Response
        %% Step Response Performance
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


    text(Ts+0.08,1.02*final+0.7*sign(final),['\color{blue}Ts ' ,num2str(Ts-Input.Step.Time,'%1.3f'),sprintf('\n'),'\color{red}Ts_e ',num2str(SP.tss)],...
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

    figure(2)
       
    subplot(2,2,1)
    plot(SurfaceRate.Values.Time,SurfaceRate.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Surface Rate (deg/s)','FontSize',7),
    title('Surface Rate','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,2)
    plot(Xpiston.Values.Time,Xpiston.Values.Data,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Xp (in)','FontSize',7),
    title('Piston position','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,3)
    plot(Load.Values.Time,(Load.Values.Data.*HornArm.Values.Data)*0.11298483,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Horn Arm (in)','FontSize',7),
    title('Aerodynamic Hinge Momment Load','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,4)
    plot(FrictionForce.Values.Time,FrictionForce.Values.Data*4.44822,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Friction Force (N)','FontSize',7),
    title('Friction force','FontWeight','bold','FontSize',7)
    axis tight
    
    figure(3)
    subplot(3,1,1)
    plot(Koil.Values.Time,Koil.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Oil Stiffness (N/m2)','FontSize',7)
    title('Stiffness Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(BulkModulusC1.Values.Time,BulkModulusC1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(BulkModulusC2.Values.Time,BulkModulusC2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Bulk Modulus (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    subplot(3,1,3)
    plot(P1.Values.Time,P1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(P2.Values.Time,P2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Chamber pressures (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    figure(4)
    subplot(3,1,1)
    plot(Xv_EHSV.Values.Time,Xv_EHSV.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV Spool Position (in)','FontSize',7)
    title('EHSV Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(i_EHSV.Values.Time,i_EHSV.Values.Data,'r','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV current (mA)','FontSize',7),
    axis tight
    
    subplot(3,1,3)
    plot(Q_EHSV.Values.Q1.Time,Q_EHSV.Values.Q1.Data.*0.25974 ,'r','LineWidth',2); grid on, hold on,
    plot(Q_EHSV.Values.Q2.Time,Q_EHSV.Values.Q2.Data.*0.25974 ,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('EHSV flow (gpm)','FontSize',7),
    legend({'Extension chamber','Retraction chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    case 4 % EHSV Step Response
    
    SurfaceEHSVCmd = 3.*logsout.getElement('EHSV_current_cmd').Values.Data;
    
    StepResponse = stepinfo(SurfacePos.Values.Data,SurfacePos.Values.Time,SurfaceEHSVCmd(n),'RiseTimeLimits',[0.15,0.85],'SettlingTimeThreshold',0.02);

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
    yss = SurfaceEHSVCmd(n);
    StepResponse.av_rate = (0.85*SurfaceEHSVCmd(n) - 0.15*SurfaceEHSVCmd(n))/StepResponse.RiseTime;
    StepResponse.ess = (final - SurfaceEHSVCmd(n))/(FullStroke_deg);

     %% Plot Results
    figure(1)

    plot(SurfacePos.Values.Time,SurfaceEHSVCmd,'r','LineWidth',2); grid on, hold on,
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


    text(Ts+0.08,1.02*final+0.7*sign(final),['\color{blue}Ts ' ,num2str(Ts-Input.Step.Time,'%1.3f'),sprintf('\n'),'\color{red}Ts_e ',num2str(SP.tss)],...
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

    figure(2)
       
    subplot(2,2,1)
    plot(SurfaceRate.Values.Time,SurfaceRate.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Surface Rate (deg/s)','FontSize',7),
    title('Surface Rate','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,2)
    plot(Xpiston.Values.Time,Xpiston.Values.Data,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Xp (in)','FontSize',7),
    title('Piston position','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,3)
    plot(Load.Values.Time,(Load.Values.Data.*HornArm.Values.Data)*0.11298483,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Horn Arm (in)','FontSize',7),
    title('Aerodynamic Hinge Momment Load','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(2,2,4)
    plot(FrictionForce.Values.Time,FrictionForce.Values.Data*4.44822,'b','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Friction Force (N)','FontSize',7),
    title('Friction force','FontWeight','bold','FontSize',7)
    axis tight
    
    figure(3)
    subplot(3,1,1)
    plot(Koil.Values.Time,Koil.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('Oil Stiffness (N/m2)','FontSize',7)
    title('Stiffness Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(BulkModulusC1.Values.Time,BulkModulusC1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(BulkModulusC2.Values.Time,BulkModulusC2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Bulk Modulus (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    subplot(3,1,3)
    plot(P1.Values.Time,P1.Values.Data,'r','LineWidth',2); grid on, hold on,
    plot(P2.Values.Time,P2.Values.Data,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('Chamber pressures (psi)','FontSize',7),
    legend({'Extension Chamber','Retraction Chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
    
    figure(4)
    subplot(3,1,1)
    plot(Xv_EHSV.Values.Time,Xv_EHSV.Values.Data,'g','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV Spool Position (in)','FontSize',7)
    title('EHSV Analysis','FontWeight','bold','FontSize',7)
    axis tight
    
    subplot(3,1,2)
    plot(i_EHSV.Values.Time,i_EHSV.Values.Data,'r','LineWidth',2); grid on
    xlabel('Time (s)','FontSize',7), ylabel('EHSV current (mA)','FontSize',7),
    axis tight
    
    subplot(3,1,3)
    plot(Q_EHSV.Values.Q1.Time,Q_EHSV.Values.Q1.Data.*0.25974 ,'r','LineWidth',2); grid on, hold on,
    plot(Q_EHSV.Values.Q2.Time,Q_EHSV.Values.Q2.Data.*0.25974 ,'b','LineWidth',2);
    xlabel('Time (s)','FontSize',7), ylabel('EHSV flow (gpm)','FontSize',7),
    legend({'Extension chamber','Retraction chamber'},'FontSize',6,'Location','northoutside','Orientation','horizontal')
    axis tight
        
    otherwise
        fprintf('Error while plot results displayed');
end


