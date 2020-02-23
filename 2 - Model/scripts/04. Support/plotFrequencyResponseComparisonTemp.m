

%
%
%

function plotFrequencyResponseComparisonTemp(handle,initDesign,optDesign)

global DynStiffOptController

init_colors = {[0,0,0.2],[0,0,0.4],[0,0,0.6],[0.4,0.3,0.9]};
opt_colors  = {[0,0.2,0],[0,0.4,0],[0,0.6,0],[0.5,0.9,0]};

figure(handle);

subplot(2,1,1),semilogx(initDesign.Temp100.FrequencyResponse.Frequency,20*log10(initDesign.Temp100.FrequencyResponse.Magnitude),'--','Color',init_colors{4}); hold on;
subplot(2,1,1),semilogx(initDesign.Tempm15.FrequencyResponse.Frequency,20*log10(initDesign.Tempm15.FrequencyResponse.Magnitude),'--','Color',opt_colors{4});
subplot(2,1,1),semilogx(optDesign.Temp100.FrequencyResponse.Frequency,20*log10(optDesign.Temp100.FrequencyResponse.Magnitude),'Color',init_colors{3});
subplot(2,1,1),semilogx(optDesign.Tempm15.FrequencyResponse.Frequency,20*log10(optDesign.Tempm15.FrequencyResponse.Magnitude),'Color',opt_colors{3});
grid on; box on;
ylabel('mag (dB)');
xlabel('Frequency (Hz)');
axis([0.1 35 -35 3]);
% title('Frequency Response Comparison');

% textG1 = ['\color{blue}G(0.1) = ',num2str(20*log10(initDesign.Temp100.FrequencyResponse.Magnitude(1)),'%1.1f')];
% textG2 = ['\color{green}G(0.1) = ',num2str(20*log10(optDesign.Temp100.FrequencyResponse.Magnitude(1)),'%1.1f')];

% text(initDesign.Temp100.FrequencyResponse.Frequency(1)+0.01,initDesign.Temp100.FrequencyResponse.Magnitude(1)-5,...
%     [textG1,sprintf('\n'),textG2],...
%     'FontSize',8,'VerticalAlignment','middle','HorizontalAlignment','left','BackgroundColor',[1 1 1],'EdgeColor','black');

subplot(2,1,2),semilogx(initDesign.Temp100.FrequencyResponse.Frequency,initDesign.Temp100.FrequencyResponse.Phase,'--','Color',init_colors{4}); hold on;
subplot(2,1,2),semilogx(initDesign.Tempm15.FrequencyResponse.Frequency,initDesign.Tempm15.FrequencyResponse.Phase,'--','Color',opt_colors{4});
subplot(2,1,2),semilogx(optDesign.Temp100.FrequencyResponse.Frequency,optDesign.Temp100.FrequencyResponse.Phase,'Color',init_colors{3});
subplot(2,1,2),semilogx(optDesign.Tempm15.FrequencyResponse.Frequency,optDesign.Tempm15.FrequencyResponse.Phase,'Color',opt_colors{3});
grid on;
ylabel('phase (deg)'),
xlabel('Frequency (Hz)')
axis([0.1 35 -250 0]);

switch DynStiffOptController
    case 0
        freq_legend = legend(strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southwest');
    case 1
        freq_legend = legend(strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southwest');               
    case 2
        freq_legend = legend(strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southwest');
    case 3
        freq_legend = legend(strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'),'Location','southwest');
    case 4
        error('Full State Feedback Controller Optimization not implemented.');
    case 5
        error('Partial State Feedback Controller Optimization not implemented.');
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

freq_legend.FontSize = 8;
leg_pos = get(freq_legend,'position') ;
aux = leg_pos(3)*1.3;
set(freq_legend,'position',[leg_pos(1),leg_pos(2),aux,leg_pos(4)]);



