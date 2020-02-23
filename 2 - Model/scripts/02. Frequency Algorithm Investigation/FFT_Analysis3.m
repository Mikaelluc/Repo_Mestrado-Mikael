
function [Hjw,mag,phase]=FFT_Analysis3(t_dyn,input_dyn,output_dyn,f,cycles)

% Time step
tstep=t_dyn(2)-t_dyn(1);

% Removing dynamics settling time end-(cycles*(1/f)/tstep)
t_offset = t_dyn(end-(cycles*(1/f)/tstep):end);
input_offset = input_dyn(end-(cycles*(1/f)/tstep):end);
output_offset = output_dyn(end-(cycles*(1/f)/tstep):end);

% Removing signal offset
t = t_offset - mean(t_offset);
input = input_offset - mean(input_offset);
output = output_offset - mean(output_offset);

% Number of Samples
N=length(input);

% Duration of data sample
duration=(N-1)*tstep;

% Sampling frequency
fs=1/tstep;

% Max frequency
fmax=fs;

% Find adjusted length of fft input signals
nfft = 2^nextpow2(length(t));

% New uration of data sample
duration2=nfft*tstep;

% Step frequency
fstep=1/duration2;

% Compute DFT (DTFT approximation of input and output)
inputfft=fft(input,nfft);
outputfft=fft(output,nfft);

% Complex transfer function
H=outputfft./inputfft;

% Compute magnitude
magH=abs(H);

% Compute phase in degrees
phaseinput=atan2(imag(inputfft),real(inputfft));
phaseoutput=atan2(imag(outputfft),real(outputfft));
phaseinminusout = phaseinput-phaseoutput;
phaseH = phaseinminusout;
phaseH=180*phaseH/pi;

% Find Gain and Phase at test frequency
freq_index=round(f/fstep)+1;
Hjw=H(freq_index);
mag=magH(freq_index);
if phaseH(freq_index) < 0
    phaseH = phaseH + 360;
    else 
end

phase = - phaseH(freq_index);

