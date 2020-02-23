clc 
clear all
PH_Load_Parameters
model_name = 'RudderActuatorChannel_control';

Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 0  ; % Sine input
Input.Sine.Amplitude = .5; % Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

test_freq = [0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
freq = test_freq(1);

Input.Sine.Frequency  = 2*pi*freq;

simOut = sim(model_name,'StopTime','60.5');

Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
% [Hjw,mag,phase]=FFT_Analysis3(timet,Surf_cmd,Surf_fbk,freq);

% Store H(jw),mag,phase in vectors
% Hjw_vec(i)=Hjw;
% mag_vec(i)=mag;
% phase_vec(i)=phase;

nharm = 10;
[thd_db,harmpow,harmfreq] = thd(Surf_fbk(end-(6*(1/freq)/0.00001):end),100000,nharm)
percent_thd = 100*(10^(thd_db/20))

% Kd = 40
% Kd = 0.7
% THD = 61.3695   61.5442   61.3675    4.8961    2.9799    2.8271    2.7593    2.7569    2.8853    3.1781    3.5108    2.7189    2.3830    2.5772    3.6256    6.0915    7.8315    6.8173    5.2923    4.1105    3.1512    2.4612    0.9943    0.4236    0.2022
% THD =  6.2069    4.6059   4.0483(-27.8545)    4.8961    2.9799    2.8271    2.7593    2.7569    2.8853    3.1781    3.5108    2.7189    2.3830    2.5772    3.6256    6.0915    7.8315    6.8173    5.2923    4.1105    3.1512    2.4612    0.9943    0.4236    0.2022