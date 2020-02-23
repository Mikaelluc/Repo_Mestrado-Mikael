

%
%
%

function plotFrequencyResponseAlgComparison(handle,response1,response2)

colors = {'b-*','g-*','r-*','y-*'};

figure(handle);
handle.Name = 'Frequency Response Algorithms Graphic Comparison'; 
subplot(2,1,1),semilogx(response1{1},20*log10(response1{2}),colors{1},response2{1},20*log10(response2{2}),colors{2}); 
hold on;
grid on;
ylabel('mag (dB)');
xlabel('Frequency (Hz)');
title('Frequency Response Algorithms Comparison');
legend('Baseline Algorithm','Modified Baseline Algorithm');

text(response1{1}(1)+0.01,response1{2}(1)-4,...
    ['\color{blue}G(0.1) = ' ,num2str(20*log10(response1{2}(1)),'%1.1f'),sprintf('\n'),'\color{green}G(0.1) = ' ,num2str(20*log10(response2{2}(1)),'%1.1f')],...
    'FontSize',8,'VerticalAlignment','middle','HorizontalAlignment','left','BackgroundColor',[1 1 1],'EdgeColor','black');

subplot(2,1,2),semilogx(response1{1},response1{3},colors{1},response2{1},response2{3},colors{2}); 
hold on;
grid on;
ylabel('phase (deg)'),
xlabel('Frequency (Hz)')




