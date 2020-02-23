function [Gm,Wcg,Pm,Wcp,Bw] = findmargin2(mag,phase,w)
%ALLMARGIN  All stability margins and crossover frequencies.
%
%   S = ALLMARGIN(SYS) provides detailed information about the gain, phase,
%   and delay margins and the corresponding crossover frequencies of the
%   SISO open-loop model SYS.
%
%   The output S is a structure with the following fields:
%     * GMFrequency: all -180 deg crossover frequencies in rad/TimeUnit
%       (relative to the time units specified in SYS.TimeUnit, the default
%       being seconds)
%     * GainMargin: corresponding gain margins (g.m. = 1/G where G is the
%       gain at crossover)
%     * PMFrequency: all 0 dB crossover frequencies (in rad/TimeUnit)
%     * PhaseMargin: corresponding  phase margins (in degrees)
%     * DelayMargin, DMFrequency: delay margins (in the units specified
%       in SYS.TimeUnit for continuous-time systems, and in multiples of
%       the sample time for discrete-time systems) and corresponding
%       critical frequencies
%     * Stable: 1 if nominal closed loop is stable, 0 if unstable, and NaN
%       if stability cannot be assessed (as in the case of most FRD systems)
%
%   S = ALLMARGIN(MAG,PHASE,W,TS) computes the stability margins from the
%   frequency response data W, MAG, PHASE and the sampling time TS. ALLMARGIN
%   expects gain values MAG in absolute units and phase values PHASE in 
%   degrees. Interpolation is used between frequency points to approximate
%   the true stability margins.
%
%   See also MARGIN, BODE, NYQUIST, NICHOLS, LTIVIEW, DYNAMICSYSTEM.

%   Author(s): P.Gahinet
%   Copyright 1986-2011 The MathWorks, Inc.
%   $Revision: 1.1.8.7 $  $Date: 2011/08/02 14:25:00 $
narginchk(3,5);
nf = numel(w);  
w = reshape(w,[1 nf]);
if ~(isnumeric(mag) && isnumeric(phase) && isnumeric(w) && ...
      isreal(w) && isreal(mag) && isreal(phase) && ...
      numel(mag)==nf && numel(phase)==nf)
   error(message('Control:analysis:margin2','allmargin'))
elseif any(w<0) || any(diff(w)<=0)
   error(message('Control:analysis:margin3','allmargin'))
end
mag = reshape(mag,[1 nf]);
phase = reshape(phase,[1 nf]);
if any(mag<0)
   error(message('Control:analysis:margin4','allmargin'))
end

% Prep work
logmag = zeros(1,nf);
isZero = (mag==0);
logmag(:,isZero) = -Inf;
logmag(:,~isZero) = 20*log10(mag(~isZero)); % log magnitude
phase = unwrap((pi/180)*phase); % unwrap phase values in rad
if nf>2 && w(1)==0
   w(1) = eps * w(2);  % g335997   
end
logw  = log10(w);                        % log frequency
twopi = 2*pi;

%------------------------------------
% Gain margins (-180 phase crossings)
%------------------------------------

% Find points where phase crosses -180 degrees modulo 360
% NOTE: phase is in radians
k = floor((phase+pi)/twopi);      % -pi+2*k*pi <= phase < pi+2*k*pi
lowcross = (2*k(:,1:nf-1)-1)*pi;  % nearest -pi crossing below phase
ic = find(phase(:,2:nf)<lowcross | phase(:,2:nf)>=lowcross+twopi);  % phase crossing locations
% Keep max of 50 crossings for system with delay oscillations
% h = feedback(ss(tf([.8 0],[1 1],'inputdelay',1)),1);
ic = ic(1:min(50,end));  
Pc = lowcross(:,ic) + twopi*(phase(:,ic+1)>phase(:,ic)); % phase at crossings
% Pc = (1-t) P(ic) + t P(ic+1)
t = (Pc - phase(:,ic)) ./ (phase(:,ic+1) - phase(:,ic));

% Get gain margin values for -180 phase crossings
Wcg = logw(:,ic) + t .* (logw(:,ic+1)-logw(:,ic));
Gm = logmag(:,ic) + t .* (logmag(:,ic+1)-logmag(:,ic));  % -G.M. in dB

% Look for asymptotic behavior near -180 degrees.  (30 degree tolerance).
% Linearly extrapolate gain and frequency based on first 2 or last 2 points.
tol = pi/6;
if nf>=2,
   % Extrapolation toward w=0
   pcs = (2*round((phase(1)+pi)/twopi)-1)*pi;  % -180 crossing nearest to P(1)
   if abs(phase(1)-pcs)<tol && abs(phase(2)-phase(1))~=0,       % Starts near -180 degrees (mod 360)
      t = (pcs-phase(1)) / (phase(2)-phase(1));
      if t<0,  % Extrapolation toward 0
         Wcg = [Wcg , logw(1) + t * (logw(2)-logw(1))];
         Gm = [Gm , logmag(1) + t * (logmag(2)-logmag(1))];
      end
   end
   % Extrapolation toward w=Inf
   pce = (2*round((phase(nf)+pi)/twopi)-1)*pi;  % -180 crossing nearest to P(end)
   if abs(phase(nf)-pce)<tol && abs(phase(nf)-phase(nf-1))~=0,  % Ends near -180 degrees.
      t = (pcs-phase(nf-1)) / (phase(nf)-phase(nf-1));
      if t>0,  % Extrapolation toward +Inf
         Wcg = [Wcg , logw(nf-1) + t * (logw(nf)-logw(nf-1))];
         Gm = [Gm , logmag(nf-1) + t * (logmag(nf)-logmag(nf-1))];
      end
   end
end

% Return sorted list of crossings and associated margins
if isempty(Gm)
   Gm = 'Not found';   Wcg = 'Not found';
else
   [Wcg,is] = sort(Wcg);
   Gm = (-Gm(is));
   Wcg = 10.^Wcg;
end

%------------------------------------
% Phase margins (0dB gain crossings)
%------------------------------------

% Find points where magnitude crosses 0 db
ic = find(logmag(:,1:nf-1) .* logmag(:,2:nf) <= 0 & logmag(:,1:nf-1)~=logmag(:,2:nf));
% Keep max of 50 crossings for system with delay oscillations
ic = ic(1:min(50,end));  
t = -logmag(:,ic) ./ (logmag(:,ic+1) - logmag(:,ic));

% Get interpolated frequency and phase margin values for 0 dB crossings
Wcp = logw(:,ic) + t .* (logw(:,ic+1)-logw(:,ic));
Pm = phase(:,ic) + t .* (phase(:,ic+1)-phase(:,ic)); % in radians

% Compute phase margins
if isempty(Pm)
   Pm = 'Not found';  Wcp = 'Not found';
else
   [Wcp,is] = sort(Wcp);
   Pm = mod(Pm(is),twopi)-pi;
   Wcp = 10.^Wcp;
   Pm = (180/pi) * Pm; % in deg
end


%------------------------------------
% Bandwidth (DC - 3dB gain crossing)
%------------------------------------

% Find points where magnitude crosses 0 db

GainDC = 20*log10(mag(1));
ic = find(20*log10(mag) < GainDC-3,1);
if isempty(ic)
    Bw = 'Not found';
elseif ic == 1
    Bw = interp1([20*log10(mag(ic)) 20*log10(mag(ic+1))],[w(ic) w(ic+1)],GainDC-3);
else
    Bw = interp1([20*log10(mag(ic-1)) 20*log10(mag(ic))],[w(ic-1) w(ic)],GainDC-3);
end


% Keep max of 50 crossings for system with delay oscillations
%ic = ic(1:min(50,end));
% Gain at crossings
%t = -3 -logmag(:,ic) ./ (logmag(:,ic+1) - logmag(:,ic));

% Get interpolated frequency and phase margin values for 0 dB crossings
%Wcp = logw(:,ic) + t .* (logw(:,ic+1)-logw(:,ic));
%Pm = phase(:,ic) + t .* (phase(:,ic+1)-phase(:,ic)); % in radians
%Pm = abs(-180 - interp1(w,phase*180/pi,Wcp));



% Construct output
% s = struct(...
%    'GainMargin',Gm,...
%    'GMFreq',Wcg,...
%    'PhaseMargin',Pm,...
%    'PMFreq',Wcp,...
%    'Bandwidth',Bw);
