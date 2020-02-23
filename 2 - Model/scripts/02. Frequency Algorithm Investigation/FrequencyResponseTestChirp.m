
%
%       Chirp Frequency Response Test
%
% This function will calculate the frequency response of the model 
% response for a chirp signal input
%

function response = FrequencyResponseTestChirp(model_name)

global Input

warning('off','all');
warning;

Input.Control = 2; % Sine Wave surface command
Input.Chirp.Enable = 1; % Chirp input
Input.Chirp.InitialFrequency = 0.1;
Input.Chirp.TargetFrequency = 35;
Input.Chirp.TargetTime = 20;
        
% Simulation time (s)
Time = num2str(Input.Chirp.TargetTime);
simOut = sim(model_name,'StopTime',Time);
          
Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;
Ts = timet(20)-timet(19);

% The data must be presented to the spafdr function as an object assembled 
% by the iddata function. More information check the MATLAB help.
data = iddata(Surf_fbk,Surf_cmd,Ts);

% The frequency resolution, i.e., the interval at which the frequency
% response will be evaluated will be equal to 0.1 Hz.

FrequencyResolution = 0.2;                     % Use between 0.1 and 1.0 Hz.

% Let us create the frequency vector and transform it from Hz to radians
% per second (as required by the spafdr function).

f                   = Input.Chirp.InitialFrequency:FrequencyResolution:Input.Chirp.TargetFrequency;
% f                   = [0.1,0.5,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,25,30,35];
w                   = 2 * pi * f;

% Now that we have the object data, the resolution and the frequency vector
% the spectral decomposition can be evaluated.
g                   = spafdr(data, FrequencyResolution, w);

% The output of the spafdr function returns the object "g".
% This object contains the frequency response and its associated
% uncertainty as an idfrd object that can be used by the MATLAB "bode"
% function.

% bode(g,w);
[magnitude, phase]  = bode(g,w);

% The bode function receives the idfrd object and the frequency vector in
% radians per second and provides the frequency response magnitude and the
% system phase in degrees.
% In order to obtain a classical bode diagram a conversion to dB must be
% made.

magnitudeDb         = 20 * log10(magnitude);

% Both magnitude and phase are originally assembled as 3D line vectors.
% The next step is to find the gain and phase margins of the system.
% Before proceeding let us extract and transpose the magnitude and phase
% information.

magnitude           = magnitude(:,:)';
magnitudeDb         = magnitudeDb(:,:)';
phase               = phase(:,:)';

% The MATLAB function "MARGIN()" derives the gain and phase margins from
% the Bode magnitude, phase, and frequency vectors produced by the BODE()
% function.

[GM,PM,GF,PF]       = margin(magnitude,phase,w);
 
% In order to obtain a classical bode diagram a conversion to dB must be
% made.

Gm_dB               = 20*log10(GM)

% Another performance criteria that needs to be evaluated is the system
% bandwidth. This parameter will be equal to the frequency in which the
% -3dB point is achieved for the first time compared to the average value
% of the frequency response magnitude between 0.1 and 1 Hz.

% Fb = bandwidth2(f, magnitudeDb);
Bw = 0;

% [GM,GF,PM,PF,Bw] = findmargin2(mag_vec,phase_vec,test_freq);

response = {f,magnitude,phase,GM,GF,PM,PF,Bw};
