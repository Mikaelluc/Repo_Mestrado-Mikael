

%
%
%

function plotFrequencyResponseComparison(handle,initDesign,optDesign)

colors = {'b-*','g-*','r-*','y-*'};

figure(handle);
handle.Name = 'Frequency Response Comparison'; 
subplot(2,1,1),semilogx(initDesign.FrequencyResponse.Frequency,20*log10(initDesign.FrequencyResponse.Magnitude),colors{1}); hold on;
subplot(2,1,1),semilogx(optDesign.FrequencyResponse.Frequency,20*log10(optDesign.FrequencyResponse.Magnitude),colors{2});
grid on;
ylabel('mag (dB)');
xlabel('Frequency (Hz)');
title('Frequency Response Comparison');
legend(strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(initDesign.Controller.Kd,'%1.4f'),')'),...
    strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(optDesign.Controller.Kd,'%1.4f'),')'));

text(initDesign.FrequencyResponse.Frequency(1)+0.01,initDesign.FrequencyResponse.Magnitude(1)-4,...
    ['\color{blue}G(0.1) = ' ,num2str(20*log10(initDesign.FrequencyResponse.Magnitude(1)),'%1.1f'),sprintf('\n'),'\color{green}G(0.1) = ' ,num2str(20*log10(optDesign.FrequencyResponse.Magnitude(1)),'%1.1f')],...
    'FontSize',8,'VerticalAlignment','middle','HorizontalAlignment','left','BackgroundColor',[1 1 1],'EdgeColor','black');

subplot(2,1,2),semilogx(initDesign.FrequencyResponse.Frequency,initDesign.FrequencyResponse.Phase,colors{1}); hold on;
subplot(2,1,2),semilogx(optDesign.FrequencyResponse.Frequency,optDesign.FrequencyResponse.Phase,colors{2});
grid on;
ylabel('phase (deg)'),
xlabel('Frequency (Hz)')




