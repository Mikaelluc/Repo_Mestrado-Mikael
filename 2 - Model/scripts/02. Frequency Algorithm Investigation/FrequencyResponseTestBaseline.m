
%
%       Baseline Frequency Response Test
%
% This function will calculate the frequency response for each frequency in
% the test vector separately and return the magnitude, phase and frequency
% vector
%

function response = FrequencyResponseTestBaseline(model_name)

global Input sampleTime

warning('off','all');
warning;

Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 0  ; % Sine input
Input.Sine.Amplitude = .5; % Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

% Frequencies for Frequency Response Test (Hz)
test_freq = [0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
% time_freq = zeros(1,length(test_freq));

% Input Number of Settling Cycles (at each frequency)
% Purpose is to allow the system to reach steady-state at a specific operating point (e.g., non-zero bias load or non-zero position) before integration.
for i=1:length(test_freq)
    if test_freq(i) < 1
        settle_cycles(i)=1;
    else
        settle_cycles(i)=test_freq(i);
    end
end

% Input Number of Integration Cycles (at each frequency)
int_cycles=2*settle_cycles;

% Surface Position Amplitude for Frequency Response Test (deg)
for i=1:length(test_freq)
    
%     tic;
    
    % Frequency (Hz)
    freq=test_freq(i);

    % Period of ith frequency (s)
    Tp = 1/freq;

    % Number of Settling Cycles for ith frequency
    num_settle_cycles = settle_cycles(i);

    % Number of Integration Cycles for ith frequency
    num_int_cycles = int_cycles(i);

    % Time vector for ith frequency (s)
%     t =[0:0.001:Tp*(3) - 0.001]';
    t =[0:0.001:Tp*(num_settle_cycles+num_int_cycles) - 0.001]';

    % Input Suface command Frequency (rad/sec)
    Input.Sine.Frequency  = 2*pi*freq;
    
    % Simulation time (s)
    Time = num2str(max(t));
    simOut = sim(model_name,'StopTime',Time);
    
    %indx=find(timet >= Tp*num_settle_cycles);
    Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
    Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
    timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
    [Hjw,mag,phase]=FFT_Analysis(timet,Surf_cmd,Surf_fbk,freq);

    % Store H(jw),mag,phase in vectors
    Hjw_vec(i)=Hjw;
    mag_vec(i)=mag;
    phase_vec(i)=phase;
    
    nharm = 6;
    [thd_db,harmpow,harmfreq] = thd(Surf_fbk,100000,nharm);
    percent_thd(i) = 100*(10^(thd_db/20));
    
%     time_freq(i) = toc;
    
%     figure(i);
%     plot(timet,Surf_cmd,'b',timet,Surf_fbk,'r');
%     axis([0 1 -0.5 0.5]);
%     ylabel('Surface Position (deg)');
%     xlabel('Time (s)');
%     title(strcat('Actuation System ',num2str(freq),'Hz Time Response'));
end

[GM,GF,PM,PF,Bw] = findmargin2(mag_vec,phase_vec,test_freq);

response = {test_freq,mag_vec,phase_vec,GM,GF,PM,PF,Bw,percent_thd};
% response = {test_freq,mag_vec,phase_vec,GM,GF,PM,PF,Bw,time_freq};

end




