


Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 0  ; % Sine input
Input.Sine.Amplitude = .5; % Surface command input(deg)
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

% Frequencies for Frequency Response Test (Hz)
test_freq = 18;


% Period of ith frequency (s)
Tp = 1/test_freq;

% Time vector for ith frequency (s)
%     t =[0:0.001:Tp*(3) - 0.001]';
t =[0:0.001:Tp*(3*test_freq) - 0.001]';

% Input Suface command Frequency (rad/sec)
Input.Sine.Frequency  = 2*pi*test_freq;

% Simulation time (s)
Time = num2str(max(t));
simOut = sim(model_name,'StopTime',Time);

%indx=find(timet >= Tp*num_settle_cycles);
Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
%%
figure(2)
plot(timet,Surf_cmd,'b',timet,Surf_fbk,'r');
axis([0 1 -0.5 0.5]);
ylabel('Surface Position (deg)');
xlabel('Time (s)');
title('Actuation System 18Hz Response');
%%

% Time step
tstep=timet(2)-timet(1);

% Number of Samples
N=length(Surf_fbk);

% Duration of data sample
duration=(N-1)*tstep;

% Sampling frequency
fs=1/tstep;

% Max frequency
fmax=fs;

% Step frequency
% fstep=1/duration;
nfft = 2^nextpow2(length(timet));
fstep=fs/nfft;
Surf_fbk_fft = fft(Surf_fbk,nfft);
Surf_fbk_mag = abs(Surf_fbk_fft);
Surf_fbk_mag_dB = 20*log10(Surf_fbk_mag);
Surf_fbk_pow = Surf_fbk_fft(1:nfft/2+1).*conj(Surf_fbk_fft(1:nfft/2+1))/length(timet);
freq = (0:nfft-1)*(fs/nfft); 
freq_index=round(test_freq/fstep)+1;
% freq=0:fstep:(length(Surf_fbk_mag)-1)*(fstep);
% freq=0:fstep:(nfft-1)*(fstep);
%%
figure(1);
% plot(freq(1:nfft/2+1),Surf_fbk_mag_dB(1:nfft/2+1));
% plot(freq(1:nfft/2+1),2*abs(Surf_fbk_fft(1:nfft/2+1)));
plot(freq(1:nfft/2+1),Surf_fbk_pow(1:nfft/2+1)); 
% axis([0 2000 0 90]);
% axis([0 100 0 100]);
axis([0 100 0 2200]);
grid on;
ylabel('Surface Position Power Spectrum');
% ylabel('Surface Position Spectrum (dBm)');
xlabel('Frequency (Hz)');
title('Actuation System 18Hz Frequency Response');
%% Find Gain and Phase at test frequency


freq_index=round(test_freq/fstep)+1;