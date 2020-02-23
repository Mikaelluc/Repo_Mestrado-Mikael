

%
%
%

function plotTimeResponseComparisonTemp(handle,initDesign,optDesign)

figure(handle);

plot(initDesign.StepResponse.CommandTime,initDesign.StepResponse.CommandPosition,'r'); grid on; hold on;
plot(initDesign.StepResponse.ResponseTime,initDesign.StepResponse.ResponsePosition,'b');
plot(optDesign.StepResponse.ResponseTime,optDesign.StepResponse.ResponsePosition,'g');

n = length(optDesign.StepResponse.ResponseTime);
final = optDesign.StepResponse.ResponsePosition(end);
plot((optDesign.StepResponse.Ts+0.25)*ones(n,1),linspace(0,0.99*final,n),'k--');
plot(optDesign.StepResponse.ResponseTime,.99*final*ones(n,1),'k--');
plot(optDesign.StepResponse.ResponseTime,1.01*final*ones(n,1),'k--');

text((optDesign.StepResponse.Ts+0.25)+0.08,1.02*final+0.7*sign(final),...
    ['\color{blue}Ts: ' ,num2str(initDesign.StepResponse.Ts,'%1.3f'),sprintf('\n'),...
    '\color{green}Ts: ' ,num2str(optDesign.StepResponse.Ts,'%1.3f'),sprintf('\n'),...
    '\color{red}Ts_e: ',num2str(0.950)],...
    'VerticalAlignment','middle','HorizontalAlignment','left',...
    'BackgroundColor',[1 1 1],'EdgeColor','black');

text(optDesign.StepResponse.ResponseTime(n),0.5,...
    ['\color{blue}AvgRate ' num2str(initDesign.StepResponse.av_rate,'%1.2f'),' \color{green}AvgRate ' num2str(optDesign.StepResponse.av_rate,'%1.2f'),' \color{red}AvgRate_e >' num2str(34,'%1.2f'),sprintf('\n'),...
    '\color{blue}SSe ' num2str(abs(initDesign.StepResponse.ess*100),'%1.2f') '%',' \color{green}SSe ' num2str(abs(optDesign.StepResponse.ess*100),'%1.2f') '%',' \color{red}SSe_e <' num2str(1,'%1.2f') '%'],...
    'VerticalAlignment','middle','HorizontalAlignment','left',...
    'BackgroundColor',[1 1 1],'EdgeColor','black');

xlabel('Time (s)');
ylabel('\Theta (deg)');
title('Step Input Response Comparison');

legend('Step Command',...
    strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(initDesign.Controller.Kd,'%1.4f'),')'),...
    strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(optDesign.Controller.Kd,'%1.4f'),')'));

if final>0
    axis([0 optDesign.StepResponse.ResponseTime(n) min(optDesign.StepResponse.ResponsePosition) final+3])
else
    axis([0 optDesign.StepResponse.ResponseTime(n) final-4 max(optDesign.StepResponse.ResponsePosition)])
end