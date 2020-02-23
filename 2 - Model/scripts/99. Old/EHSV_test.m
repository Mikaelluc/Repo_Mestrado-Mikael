% EHSV 1st Stage Moog model
i_ehsv = 10; %ma Torque motor current
xf_ehsv = 0.0012*8; %in Flapper displacement at nozzles
xs_ehsv = 1; %in Spool displacement
DeltaQ_ehsv = 0.18*10;%in3/s Hydraulic amplifier differential flow
Ql_ehsv = 4; %gpm Servovalve control flow
Ki_ehsv = 0.025*10; %in lbs/ma Torque motor gain
K2_ehsv = 150; %in3/s/in Hydraulic amplifier flow gain
K3_ehsv = 1030; %in3/s/in Flow gain of spool/bushing
As_ehsv = 0.026*.5; % in2 Spool end area
Kf_ehsv = 93; %in lbs/in Net stiffness on armature/flapper
Kw_ehsv = 13.5; % in lbs/in feedback wire stiffness
bf_ehsv = 0.016; % in lbs/ in/sec net damping on armature/flapper
lf_ehsv = 4.4e-6; %in lbs/ in/sec2 rotational mass of armature/flapper
w_n_ehsv = sqrt(Kf_ehsv/lf_ehsv); %730 Hz natural frequency of first stage
Kv = 840; %serovalve loop gain 1/s
Kr_ehsv = K2_ehsv*Kw_ehsv/(Kv*As_ehsv);%w_n_ehsv^2/Kf_ehsv; % Armature flapper
ksi_ehsv = w_n_ehsv*bf_ehsv/(2*Kf_ehsv);%0.4; % damping ratio of first stage


% EHSV 2nd Stage
Xlength = .25; % EHSV slot lenght, in
Xwidth = .15 +.65; % EHSV slot width, in
Xov = 5e-4*0; % EHSV slot overlap, in
Aleak1 = pi*.001^2/4; % Equivalent orifice area for path 1 leakage, in²
Aleak2 = pi*.001^2/4; % Equivalent orifice area for path 2 leakage, in²
Aleak3 = pi*.001^2/4; % Equivalent orifice area for path 3 leakage, in²
Aleak4 = pi*.001^2/4; % Equivalent orifice area for path 4 leakage, in²
Aleak5 = pi*.01^2/4; % Equivalent orifice area for path 5 leakage, in²
Cd = 0.67; % Discharge Coefficient
TempC = 100;
Temp = TempC*9/5 +32; % Fuid Temperature, ºF

% According to SAE AIR1362 Rev. B
Rho = (1.08-0.95)/(-70-90)*(Temp-90)+0.95; % Fluid density, N.s²/m?
Rho = 0.00009357268*Rho; % Fluid density, lbf.s²/in?
