%% Configuração do modelo para os testes de resposta em frequência

clear all;
close all;
clc;

run('PH_Load_Parameters');

%% Obtenção e plot da resposta do algoritmo baseline

h1 = figure(1);

baselineResponse.Kp = Kp;
baselineResponse.Ki = Ki;
baselineResponse.Kd = Kd;

tic;
% PH_DynamicStiffnessTest;
% baselineResponse.time = toc;
PH_DynamicStiffnessTest_Time;
baselineResponse.time_freq = time_freq;

baselineResponse.spec_fr = spec_fr;
baselineResponse.spec_mag = spec_mag;
baselineResponse.fr = test_freq;
baselineResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;

plotDynamicStiffness(h1,baselineResponse,1);

%% Obtenção e plot da resposta do algoritmo baseline modificado

h2 = figure(2);

modifiedResponse.Kp = Kp;
modifiedResponse.Ki = Ki;
modifiedResponse.Kd = Kd;

tic;
% % PH_ModifiedDynamicStiffnessTest;
% % modifiedResponse.time = toc;
PH_ModifiedDynamicStiffnessTest_Time;
modifiedResponse.time_freq = time_freq;

modifiedResponse.spec_fr = spec_fr;
modifiedResponse.spec_mag = spec_mag;
modifiedResponse.fr = test_freq;
modifiedResponse.mag = real(Hjw_vector(1:length(test_freq)))*175.126835;

plotDynamicStiffness(h2,modifiedResponse,2);


