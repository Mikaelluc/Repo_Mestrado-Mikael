

%
%
%

function plotTimeResponseComparisonTemp(handle,initDesign,optDesign)

global DynStiffOptController

init_colors = {[0,0,0.2],[0,0,0.4],[0,0,0.6],[0.4,0.3,0.9]};
opt_colors  = {[0,0.2,0],[0,0.4,0],[0,0.6,0],[0.5,0.9,0]};

figure(handle);

plot(initDesign.Temp100.StepResponse.CommandTime,initDesign.Temp100.StepResponse.CommandPosition,'r'); grid on; hold on; box on;
plot(initDesign.Temp100.StepResponse.ResponseTime,initDesign.Temp100.StepResponse.ResponsePosition,'--','Color',init_colors{4});
plot(initDesign.Tempm15.StepResponse.ResponseTime,initDesign.Tempm15.StepResponse.ResponsePosition,'--','Color',opt_colors{4});
plot(optDesign.Temp100.StepResponse.ResponseTime,optDesign.Temp100.StepResponse.ResponsePosition,'Color',init_colors{3});
plot(optDesign.Tempm15.StepResponse.ResponseTime,optDesign.Tempm15.StepResponse.ResponsePosition,'Color',opt_colors{3});

n = length(optDesign.Temp100.StepResponse.ResponseTime);
final = optDesign.Temp100.StepResponse.ResponsePosition(end);
% plot((0.9515+0.25)*ones(n,1),linspace(0,0.98*final,n),'k--'); %optDesign.Temp100.StepResponse.Ts
% plot(optDesign.Temp100.StepResponse.ResponseTime,.98*final*ones(n,1),'k--');
% plot(optDesign.Temp100.StepResponse.ResponseTime,1.02*final*ones(n,1),'k--');

% text((optDesign.Temp100.StepResponse.Ts+0.25)+0.08,1.02*final-0.7*sign(final),...
%     ['\color{blue}Ts: ' ,num2str(initDesign.Temp100.StepResponse.Ts,'%1.3f'),sprintf('\n'),...
%     '\color{green}Ts: ' ,num2str(optDesign.Temp100.StepResponse.Ts,'%1.3f'),sprintf('\n'),...
%     '\color{red}Ts_e: ',num2str(0.950)],...
%     'VerticalAlignment','middle','HorizontalAlignment','left',...
%     'BackgroundColor',[1 1 1],'EdgeColor','black');
% 
% text(optDesign.Temp100.StepResponse.Ts+0.25,0.5,...
%     ['\color{blue}AvgRate ' num2str(initDesign.Temp100.StepResponse.av_rate,'%1.2f'),' \color{green}AvgRate ' num2str(optDesign.Temp100.StepResponse.av_rate,'%1.2f'),' \color{red}AvgRate_e >' num2str(34,'%1.2f'),sprintf('\n'),...
%     '\color{blue}SSe ' num2str(abs(initDesign.Temp100.StepResponse.ess*100),'%1.2f') '%',' \color{green}SSe ' num2str(abs(optDesign.Temp100.StepResponse.ess*100),'%1.2f') '%',' \color{red}SSe_e <' num2str(1,'%1.2f') '%'],...
%     'VerticalAlignment','middle','HorizontalAlignment','left',...
%     'BackgroundColor',[1 1 1],'EdgeColor','black');

xlabel('Time (s)');
ylabel('\Theta (deg)');
% title('Step Input Response Comparison');

switch DynStiffOptController
    case 0
        time_legend = legend('Step Command',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southeast');
    case 1
        time_legend = legend('Step Command',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southeast');               
    case 2
        time_legend = legend('Step Command',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southeast');
    case 3
        time_legend = legend('Step Command',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southeast');
    case 4
        error('Full State Feedback Controller Optimization not implemented.');
    case 5
        error('Partial State Feedback Controller Optimization not implemented.');
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

time_legend.FontSize = 8;
leg_pos = get(time_legend,'position');
aux1 = leg_pos(1)*0.8;
aux2 = leg_pos(3)*1.3;
set(time_legend,'position',[aux1,leg_pos(2),aux2,leg_pos(4)]);

if final>0
    axis([0 optDesign.Temp100.StepResponse.ResponseTime(n) min(optDesign.Temp100.StepResponse.ResponsePosition) final+3])
else
    axis([0 optDesign.Temp100.StepResponse.ResponseTime(n) final-4 max(optDesign.Temp100.StepResponse.ResponsePosition)])
end