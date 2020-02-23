
%
%       Baseline Frequency Response Test 3
%
% This function will calculate the frequency response for each frequency in
% the test vector separately and return the magnitude, phase and frequency
% vector
%
% Changes implemented to simulate each frequency for a fixed time to
% dissipate the model dynamics plus one period of the frequency.
%

function response = FrequencyResponseTestBaselineModified(model_name)

global Input

warning('off','all');
warning;

Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 0  ; % Sine input
Input.Sine.Amplitude = .5; % Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

% Frequencies for Frequency Response Test (Hz)
test_freq=[0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
time_freq = zeros(1,length(test_freq));

% Number of cycles of respective frequency
int_cycles = zeros(1,length(test_freq));
for i=1:length(test_freq)
    if test_freq(i) <=1
        int_cycles(i)=1;
    elseif test_freq(i) <=3
        int_cycles(i)=3;
    else
        int_cycles(i)=9;
    end
end

    
% Surface Position Amplitude for Frequency Response Test (deg)
for i=1:length(test_freq)
    
%     tic;
    
    % Dynamics settling time
    Tdyn = 0.5; % 0.5s
        
    % Frequency (Hz)
    freq=test_freq(i);

    % Period of ith frequency (s)
    Tp = 1/freq;

    % Time vector for ith frequency (s)
    t =[0:0.001:(Tdyn+int_cycles(i)*Tp) - 0.001]';

    % Input Suface command Frequency (rad/sec)
    Input.Sine.Frequency  = 2*pi*freq;
    
    % Simulation time (s)
    Time = num2str(max(t));
    simOut = sim(model_name,'StopTime',Time);
        
    %indx=find(timet >= Tp*num_settle_cycles);
    Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
    Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
    timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
    [Hjw,mag,phase]=FFT_Analysis3(timet,Surf_cmd,Surf_fbk,freq,int_cycles(i));

    % Store H(jw),mag,phase in vectors
    Hjw_vec(i)=Hjw;
    mag_vec(i)=mag;
    phase_vec(i)=phase;
    
%     time_freq(i) = toc;
    
    nharm = 6;
    [thd_db,harmpow,harmfreq] = thd(Surf_fbk,100000,nharm);
    percent_thd(i) = 100*(10^(thd_db/20));
end

[GM,GF,PM,PF,Bw,Bc] = findmargin3(mag_vec,phase_vec,test_freq);

response = {test_freq,mag_vec,phase_vec,GM,GF,PM,PF,Bw,Bc,percent_thd};
% response = {test_freq,mag_vec,phase_vec,GM,GF,PM,PF,Bw,Bc,time_freq};

end




