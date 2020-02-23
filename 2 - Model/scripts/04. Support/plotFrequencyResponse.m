

%
%
%

function plotFrequencyResponse(handle,response,curve)

colors = {'b-*','g-*','r-*','y-*'};

figure(handle);
handle.Name = 'Frequency Response Algorithms Graphic Comparison'; 
subplot(2,1,1),semilogx(response{1},20*log10(response{2}),colors{curve}); 
hold on;
grid on;
ylabel('mag (dB)');
xlabel('Frequency (Hz)');
title('Frequency Response Algorithms Comparison');

subplot(2,1,2),semilogx(response{1},response{3},colors{curve}); 
hold on;
grid on;
ylabel('phase (deg)'),
xlabel('Frequency (Hz)')




