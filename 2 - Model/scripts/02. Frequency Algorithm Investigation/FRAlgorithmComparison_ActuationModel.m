
clear all;
close all;
clc;

%% Configuração do modelo para os testes de resposta em frequência

global Input sampleTime

run('PH_Load_Parameters')
model_name = 'RudderActuatorChannel_control';
% model_name = 'RudderActuatorChannel_control_linear';
% model_name = 'pid_nonlinear_example2';
h = figure(5);

StiffnessTest_Enable = 3; % 1 - Stiffness test, 2 - Regular Load, 3 - No load
EHSVTest.Enable = 1; % 1 - Normal Operation, 2 - Frequency Test, 3 Step Test
ControlTopology = 2; % 2 - PID Controller     
OpenLoop = 0; % 1 - Open-Loop Frequency Response
Rate_Limit = 38; % Rate Limit, deg/s
Max_Cmd = 30; % Maximum command allowable, deg
Min_Cmd = -30; % Minimum command allowable, deg
Limit_Int = .5; % Integral Limit, mA
Imax = 10; % Maximum EHSV Current, mA
Load_cmd = 0;

% Kp = 38.7453; Kd = 0.4333;
Kp = 40; Kd = 0.7;
% Kp = 40.5481; Kd = 0.4926;

sampleTime = 1e-5;
Kd_N = 100;

Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 0  ; % Sine input
Input.Sine.Amplitude = .5; % Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

%% Plot da resposta do algoritmo baseline

test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\magnitudeBaselineFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\phaseBaselineFRAlgorithm.mat')

plotFrequencyResponse(h,{test_freq,magnitudeBaselineFRAlgorithm,phaseBaselineFRAlgorithm,0,0,0,0,0},1);

%% Plot da resposta do algoritmo chirp + spafdr

load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\freqChirp100.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\magChirp100.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\phaseChirp100.mat')

plotFrequencyResponse(h,{freqChirp100,10.^(magChirp100/20),phaseChirp100,0,0,0,0,0},3);

%% Obtenção e plot da resposta do algoritmo baseline

tic;
responseBaseline = FrequencyResponseTestBaseline(model_name);
timeBaseline = toc;

plotFrequencyResponse(h,responseBaseline,1);

%% Obtenção e plot da resposta do algoritmo baseline modificado

tic;
responseBaselineMod = FrequencyResponseTestBaselineModified(model_name);
timeBaselineMod = toc;

plotFrequencyResponse(h,responseBaselineMod,2);

%% Obtenção e plot da resposta do algoritmo chirp + spafdr

tic;
responseChirp = FrequencyResponseTestChirp(model_name);
timeChirp = toc;

plotFrequencyResponse(h,responseChirp,4);

%% Obtenção e plot da resposta do algoritmo armax + baseline

model_name = 'RudderActuatorChannel_control_arx';
model_name_fr = 'pid_nonlinear_example2';

tic;
rudder_act_arx = ARXModelidentification_wavenet(model_name);
% rudder_act_arx = ARXModelidentification_sigmoidnet(model_name);
% rudder_act_arx = ARXModelidentification_treepartition(model_name);
responseArmax = FrequencyResponseTestBaseline(model_name_fr);
timeARX = toc;

plotFrequencyResponse(h,responseArmax,1);

%% Seção utilizada para plotar gráfico de bode e tabela comparativa. Alguns resultado estão armazenados em ..\Matlab\results\Frequency Response Algorithm e podem ser carregados para comparação.

test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\timeBaselineFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\magnitudeBaselineFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\phaseBaselineFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\timeChirpFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\magnitudeChirpFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\phaseChirpFRAlgorithm.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\freqChirp100.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\freqpChirp100.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\magChirp100.mat')
load('C:\Users\Pedro H\Documents\GitHub\MestradoHeric\Matlab\results\Frequency Response Algorithm\phaseChirp100.mat')

figure('Name','Frequency Response Algorithms Graphic Comparison'); 
subplot(2,1,1),semilogx(test_freq,20*log10(magnitudeBaselineFRAlgorithm),'b-*'); hold on;
subplot(2,1,1),semilogx(test_freq,magnitudeChirpFRAlgorithm,'g-*');
subplot(2,1,1),semilogx(freqChirp100,magChirp100,'r-*');
grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)');
legend('Baseline Algorithm: 12.6 min','Chirp Algorithm 20: 2.3 min','Chirp Algorithm 100: 60+ min');
title('Frequency Response Algorithms Comparison');
subplot(2,1,2),semilogx(test_freq,phaseBaselineFRAlgorithm,'b-*'); hold on;
subplot(2,1,2),semilogx(test_freq,phaseChirpFRAlgorithm,'g-*');
subplot(2,1,2),semilogx(freqpChirp100,phaseChirp100,'r-*');
grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')

[baseGM,baseGF,basePM,basePF,baseBw] = findmargin2(magnitudeBaselineFRAlgorithm,phaseBaselineFRAlgorithm,test_freq);
[ch80GM,ch80GF,ch80PM,ch80PF,ch80Bw] = findmargin2(10.^(magnitudeChirpFRAlgorithm'/20),phaseChirpFRAlgorithm',freqpChirp100);
[ch100GM,ch100GF,ch100PM,ch100PF,ch100Bw] = findmargin2(10.^(magChirp100'/20),phaseChirp100,freqpChirp100);

figure('Name','Frequency Response Algorithms Numerical Comparison'); 
parameters = {'Gain Margin (dB)';'Gain Frequency (Hz)';'Phase Margin (deg)';'Phase Frequency (Hz)';'Bandwidth (Hz)';'Computation Time (min)'};
baselineFRA = {baseGM;baseGF;basePM;basePF;baseBw;timeBaselineFRAlgorithm/60};
chirp20FRA = {ch80GM(1);ch80GF(1);ch80PM;ch80PF;ch80Bw;timeChirpFRAlgorithm/60};
chirp100FRA = {ch100GM;ch100GF;ch100PM;ch100PF;ch100Bw;'60+'};
T = table(baselineFRA,chirp20FRA,chirp100FRA,'RowNames',parameters);

uitable('Data',T{:,:},'ColumnName',T.Properties.VariableNames,'RowName',T.Properties.RowNames,'Units', 'Normalized', 'Position',[0, 0, 1, 1]);


%%
text(0.1,0,'teste','FontSize',8,'VerticalAlignment','bottom','HorizontalAlignment','right','BackgroundColor',[1 1 1],'EdgeColor','black');
text(Td+0.02,0,...
        ['\color{blue}Td ' ,num2str(Td-Input.Step.Time,'%1.3f'),sprintf('\n'), '\color{red}Td_e ',num2str(SP.td)],...
        'FontSize',8,...
        'VerticalAlignment','bottom',...
        'HorizontalAlignment','right',...
        'BackgroundColor',[1 1 1],...
        'EdgeColor','black');
test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
figure('Name','Frequency Response Algorithms Graphic Comparison'); 
subplot(2,1,1),semilogx(test_freq,magnitudeChirpFRAlgorithm,'g-*');
grid on;ylabel('mag (dB)');xlabel('Frequency (Hz)');
title('Frequency Response Algorithms Comparison');
subplot(2,1,2),semilogx(test_freq,phaseChirpFRAlgorithm,'g-*');
grid on;ylabel('phase (deg)'),xlabel('Frequency (Hz)')