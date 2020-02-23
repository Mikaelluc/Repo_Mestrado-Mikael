% Load_Parameters
% Script created to run Electro Hydraulic Actuator model
% Modified by Pedro Paula, created by Heric Ballesteros, based on the model by Carlos A Constantino
clear all


global Time Cmd K_Supply1 Supply_Pressure Return_Pressure Input Max_Load_TED Max_Load_TEU StiffnessTest_Enable Load_cmd StiffTest 
global ControlTopology ON_OFF_hyst SP EHSV_Step T_ES Tol_SA1 ramLVDT dpLVDT xvLVDT L0 C R Theta0 Acv Pcvi Vcv Ps0 Pcvr Pt0
global EHSVFreqTest EHSV EHSVTest i_ehsv xf_ehsv xs_ehsv DeltaQ_ehsv Ql_ehsv Ki_ehsv K2_ehsv K3_ehsv As_ehsv Kf_ehsv Kw_ehsv
global bf_ehsv lf_ehsv w_n_ehsv Kv Kr_ehsv ksi_ehsv Xlength Xwidth Xov Aleak1 Aleak2 Aleak3 Aleak4 Aleak5 Cd 
global Piston_OD Ap Aleakext Aleakint Pcvac Xpmax Xpmin Xp_init FullStroke V011 V021 Ffric1 Ka1 Kst Kst_Enable Mp1 Bp1 P10 P20 
global ent_air Sel_ent_air gamma_air Be Sel_bulk TempC Temp Rho seal_param SealType SealConstValue 
global Ap_seal Ar_seal Lp_seal Lr_seal Bkp_seal seal_hardness seal_compression frictionstribeck_velocity 

%% SIMULATION PARAMETERS
Time = 2.0; % Simulation time (s)
Cmd = 30;
sampleTime = 1e-5;
Kd_N = 100;

%% HYDRAULIC SYSTEM
K_Supply1 = 125; %psi/gpm 75; % Pressure loss gain, 
Supply_Pressure = 3000;
Return_Pressure = 150;


%% SURFACE INPUT COMMAND
Input.Control = 3; % 1 - Repeating sequence Input, 2 - Sine Input, 3 - Step Input, 4- Custom Input
Input.Custom = 1; % 1- Zero, 2- Square , 3 - Sine, 4- Square Sine

% Repeating Sequence Input
Input.Sequence.Time = [0 1];
Input.Sequence.Output = [0 1];

% Step Input
Input.Step.Time = 0.25;
Input.Step.InitialValue = 0;
Input.Step.Amplitude = 30;
Input.Step.FinalValue = Input.Step.InitialValue + Input.Step.Amplitude;

% Sine Input
Input.Sine.Frequency = 0;
Input.Sine.Amplitude = 0;
Input.Sine.Bias = 0;
Input.Sine.Phase = 0;

% Chirp Input
Input.Chirp.Enable              = 0;
Input.Chirp.InitialFrequency    = 0;
Input.Chirp.TargetFrequency     = 0;
Input.Chirp.TargetTime          = 0;

%% HINGE MOMENT LOAD
Max_Load_TED = 3050*8.85074579; %lbf 3815Nm@30deg % Aerodynamic actuator load max)
Max_Load_TEU = 3050*8.85074579; %lbf 3815Nm@30deg % Aerodynamic actuator load max)

StiffnessTest_Enable = 2; %1 - Stiffness test, 2 - Normal operation, 3 - No load
Load_cmd = 0;
StiffTest.Sine_Amplitude = 0;
StiffTest.Sine_Bias = 0;
StiffTest.Sine_Frequency = 0; %rad/sec

%% POSITION CONTROL LOOP
ControlTopology = 2; % 1- On-Off Controller, 2- Closed Loop PID, 3- Constant Input Current, 4- Step Input Current, 5- Closed Loop State Feedback
OpenLoop = 0; % 0- Closed Loop, 1- Open Loop
PH_getControllerParameters
ON_OFF_hyst = .01;
%Actuator Control Loop Requirements
SP.tss= 0.85; % Desired Settling time
SP.ess = 0.01; % Actuator steady state error 0.01 of actuator full stroke
SP.mp = 0.1; % Overshoot < 0.1 of actuator full stroke
SP.avrate = 32; % Average rate > 32 deg/s
SP.maxrate = 36; % Maximum rate < 36 deg/s
SP.td = 0.5;
SP.tr = 1;
EHSV_Step.time = 1;
EHSV_Step.initial = 0;
EHSV_Step.final = 1;

% Hardware_in
T_ES = 1/500; % Electronic System running at 500Hz

% Hardware_out
Tol_SA1 = 1; % Servo Amplifier error gain for ES1

%% SENSORS
ramLVDT.Error = 0.02; % in
ramLVDT.Range = [-5 0 5];
ramLVDT.Hysteresis = 0.01;
ramLVDT.Bandwidth = 250; % Hz

dpLVDT.Error = 3300*2*.25/100; % in
dpLVDT.Range = [-3300 0 3300];
dpLVDT.Hysteresis = 0.01;
dpLVDT.Bandwidth = 250; % Hz

xvLVDT.Error = 0.00025; % in
xvLVDT.Range = [-0.050 0 0.050];
xvLVDT.Hysteresis = 0.01;
xvLVDT.Bandwidth = 250; % Hz
% Tol_LVDT1 = 1; % LVDT error gain for Act1
% NB_LVDT1 = 0; % LVDT null bias error for Act1

%% KINEMATICS Act Nominal
L0 = 19.88; % Neutral length of the Act, in
C = 20.85;  % Hinges distances, in
R = 6.81; % Actuation Radius, in
Theta0 = acos((C^2+R^2-L0^2)/(2*C*R)); % Theta angle at neutral, rad


%% VALVES PARAMETERS

% Inlet Check Valve
Acv = (pi/4)*0.500^2;%0.003*5; % Check Valve Area, in²
Pcvi = 5; % Inlet cracking pressure, psi
Vcv = 1; % Check valve volume, in³
Ps0 = 3000; % Initial inlet pressure, psi

% Return Check Valve
Pcvr = 100; % Return cracking pressure, psi
Pt0 = 200; % Initial return pressure, psi


%%% EHSV TEST %%%%%
EHSVFreqTest.Sine.Amplitude = 0;
EHSVFreqTest.Sine.Bias = 0;
EHSVFreqTest.Sine.Frequency = 0;
EHSV.Step.Time = 0;
EHSV.Step.Value = 0;
EHSVTest.Enable = 1; %1- Normal Operation, 2 - Frequency Test, 3 Step Test

% EHSV 1st Stage - Moog model
i_ehsv = 10; %ma Torque motor current
xf_ehsv = 0.0012; %in Flapper displacement at nozzles
xs_ehsv = 1; %in Spool displacement
DeltaQ_ehsv = 0.18;%in3/s Hydraulic amplifier differential flow
Ql_ehsv = 4; %gpm Servovalve control flow
Ki_ehsv = 0.025; %in lbs/ma Torque motor gain
K2_ehsv = 150; %in3/s/in Hydraulic amplifier flow gain
K3_ehsv = 1030; %in3/s/in Flow gain of spool/bushing
As_ehsv = 0.026; % in2 Spool end area
Kf_ehsv = 93; %in lbs/in Net stiffness on armature/flapper
Kw_ehsv = 13.5; % in lbs/in feedback wire stiffness
bf_ehsv = 0.016; % in lbs/ in/sec net damping on armature/flapper
lf_ehsv = 4.4e-6; %in lbs/ in/sec2 rotational mass of armature/flapper
w_n_ehsv = sqrt(Kf_ehsv/lf_ehsv); %730 Hz natural frequency of first stage
Kv = K2_ehsv*Kw_ehsv/(Kf_ehsv*As_ehsv);%840; %serovalve loop gain 1/s
Kr_ehsv = K2_ehsv*Kw_ehsv/(Kv*As_ehsv);%w_n_ehsv^2/Kf_ehsv; % Armature flapper
ksi_ehsv = w_n_ehsv*bf_ehsv/(2*Kf_ehsv);%0.4; % damping ratio of first stage

% EHSV 2nd Stage
Xlength = .25; % EHSV slot lenght, in
Xwidth = .20;%.15 + .05;%+.015; % EHSV slot width, in
Xov = 5e-4; % EHSV slot overlap, in
Aleak1 = pi*.001^2/4; % Equivalent orifice area for path 1 leakage, in²
Aleak2 = pi*.001^2/4; % Equivalent orifice area for path 2 leakage, in²
Aleak3 = pi*.001^2/4; % Equivalent orifice area for path 3 leakage, in²
Aleak4 = pi*.001^2/4; % Equivalent orifice area for path 4 leakage, in²
Aleak5 = pi*.01^2/4; % Equivalent orifice area for path 5 leakage, in²
Cd = 0.67; % Discharge Coefficient


%% CYLINDER DYNAMICS
%Piston_OD = 3.865; Rod_OD =  1.746;
%Piston_OD = 3.490; Rod_OD =  3.120;
%Piston_OD = 2.865; Rod_OD =  1.433; % seal 333-221
 Piston_OD = 2.240; Rod_OD =  1.433; % seal 328-221

%Piston_OD = 2.490; Rod_OD =  1.746; % seal 330 - 327
%Piston_OD = 2.365; Rod_OD =  1.498; % seal 329-325
%Piston_OD = 2.365; Rod_OD =  1.621; % seal 329-326
Ap = (Piston_OD^2-Rod_OD^2)*pi/4;% Piston area Act1, in²
Aleakext = pi*.001^2; % Equivalent orifice area for external leakage, in²
Aleakint = pi*.005^2; % Equivalent orifice area for internal leakage, in²
Pcvac = 5; % Anti-Cavitation Valve cracking pressure, psi
Xpmax = 3.4*1.1; % Maximum Xp value (extension), in % 10% of margin included in Act Stroke
Xpmin = -3.4*1.1; % Minimum Xp value (retraction), in
Xp_init = 0;
FullStroke = 3.4*2;
V011 = 1.2*Ap*abs(Xpmax);
V021 = 1.2*Ap*abs(Xpmin);
Ffric1 = 150; % Piston Friction for Act1, lbf

%Ka1 = 1.79e7; % Stiffness for Act1, lbf/in
%Ka1 = 6.25E+05; % Stiffness for Act1, lbf/in
%Ka1 = 9.04E+05; % Stiffness for Act1, lbf/in
%Ka1 = 4.26E+05; % Stiffness for Act1, lbf/in
% Ka1 = 3*2.18E+05; % 330-327
% Ka1 = 3*2.32E+05; % 329-325
Ka1 = 2.05E+05; % 329-326

Kst = 1e9/175; % Stiffness of the end stop for both Act, lbf/in
Kst_Enable = 1; %1- Enable, 0 - Disable for Dynamic Stiffness Test
Mp1 = 2.14; % Piston mass for Act1, lb
Bp1 = 1; % Damping coefficient for Act1, lbf.s/in
P10 = 1600; % Initial pressure on extension chamber, psi
P20 = 1600; % Initial pressure on retraction chamber, psi

%% FLUID DEFINITIONS - BULK MODULUS, TEMPERATURE, DENSITY
ent_air = 0.005; %Percentage of entrapped air in actuator chambers
Sel_ent_air = 2; % 1- Constant, 2- Adiabatic Tangent, 3 - Isothermal Secant, 4 - Isothermal Tangent
gamma_air = 1.4;

Be = 150000; % Bulk Modulus, psi
Sel_bulk = 2;% 1- Constant, 2- Adiabatic Tangent, 3 - Isothermal Secant, 4 - Isothermal Tangent


TempC = 100;
[Temp,Rho] = setHydraulicProperties(TempC);

%% SEAL PARAMETERS - O-ring - Parker Handbook

% Seal Parameters A, B-1, A-1, B %AIR code A F E B
% seal_param = [3.868 3.870; 3.494 3.496; 1.615 1.617; 1.433 1.435]; % seal 341-220
% seal_param = [2.863 2.865; 2.494 2.496; 1.615 1.617; 1.433 1.435]; % seal 333-221
 seal_param = [2.243 2.245; 2.869 2.471; 1.615 1.617; 1.433 1.435]; % seal 328-221
%seal_param = [3.493 3.495; 3.119 3.121; 3.494 3.496; 3.120 3.122]; % Seal 338
SealType = 2; % 1 - Parker O-ring, 2 - Parker O-ring +Stribeck , 3 - Constant value
SealConstValue = 150;

%seal_param =[2.493 2.495; 2.121 2.123; 2.120 2.122; 1.746 1.748];%%330-327
%al_param = [2.368 2.370; 1.994 1.996; 1.870 1.872; 1.486 1.498]; % seal 329-325
%seal_param = [2.368 2.370; 1.994 1.996; 1.995 1.997; 1.621 1.623]; % seal 329-326

Ap_seal = (max(seal_param(1,:))^2 - min(seal_param(2,:))^2)*pi/4;
Ar_seal = (max(seal_param(3,:))^2 - min(seal_param(4,:))^2)*pi/4;
Lp_seal = pi*max(seal_param(1,:));
Lr_seal = pi*max(seal_param(4,:));

Bkp_seal = 3; % Number of Backup seals
seal_hardness= 90; % Seal hardness
seal_compression=10;% Seal compression
frictionstribeck_velocity = 10;


%% CONTROL PARAMETERS
load('StateControl.mat')
load('StateControlLinear.mat')
% Control.X0 = [0 0 1500 1500 0 0 0]'; %xp xpdot P1 P2 xv xvdot xvddot
% xp_0 = Control.X0(1); xpd_0 = Control.X0(2); P1_0 = Control.X0(3); P2_0 = Control.X0(4); xv_0 = Control.X0(5);
% Ps = Supply_Pressure;
% Pt = Return_Pressure;
% Aleak = Aleak1;
% xw = Xwidth;
% V0 = V011;
% Betac = 2.425e5 - 603.4*Temp;
% Betaa = 5.971;
% mp = Mp1;
% Bp = Bp1;
% Kpp = Ka1;
% kd = Cd*sqrt(2/Rho);
% 
% c1 = (-Ap/(V0+Ap*xp_0)^2)*(Betac + Betaa*P1_0)*( kd*sqrt(Ps-P1_0)*(xv_0*xw+Aleak) -kd*sqrt(P1_0 - Pt)*Aleak - Ap*xpd_0 - kd*Ap*sqrt(P1_0));
% c2 = -Ap *((Betac + Betaa*P1_0)/(V0+Ap*xp_0));
% c3 = (Betaa/(V0+Ap*xp_0))*(kd*sqrt(Ps-P1_0)*(xv_0*xw+Aleak) - kd*sqrt(P1_0-Pt)*Aleak - Ap*xpd_0 - kd*Ap*sqrt(P1_0)) + ...
%     ((Betac + Betaa*P1_0)/(V0+Ap*xp_0))*(kd/2)*(-(xv_0*xw+Aleak)/sqrt(Ps - P1_0) - Aleak/sqrt(P1_0-Pt) - Ap/sqrt(P1_0));
% c4 = 0;
% c5 = ((Betac + Betaa*P1_0)/(V0+Ap*xp_0))*kd*sqrt(Ps - P1_0)*xw;
% c6 = (Ap/(V0-Ap*xp_0)^2)*(Betac + Betaa*P2_0)*(Ap*xpd_0  - kd*Ap*sqrt(P2_0) - kd*sqrt(P2_0-Pt)*(xv_0*xw+Aleak) +kd*sqrt(Ps - P2_0)*Aleak);
% c7 = Ap *((Betac + Betaa*P2_0)/(V0-Ap*xp_0));
% c8 = 0;
% c9 = (Betaa/(V0 - Ap*xp_0))*(Ap*xpd_0  - kd*Ap*sqrt(P2_0) - kd*sqrt(P2_0-Pt)*(xv_0*xw+Aleak) +kd*sqrt(Ps - P2_0)*Aleak) + ...
%     ((Betac + Betaa*P2_0)/(V0-Ap*xp_0))*(kd/2)*(-Ap/sqrt(P2_0) -(xv_0*xw+Aleak)/sqrt(P2_0-Pt) + Aleak/sqrt(Ps - P2_0));
% c10 = ((Betac + Betaa*P2_0)/(V0-Ap*xp_0))*-kd*sqrt(P2_0-Pt)*xw;
% 
% 
% Control.A = [0 1 0 0 0 0 0;
%              -Kpp/mp -Bp/mp Ap/mp -Ap/mp 0 0 0;
%              c1 c2 c3 c4 c5 0 0;
%              c6 c7 c8 c9 c10 0 0;
%              0 0 0 0 0 1 0;
%              0 0 0 0 0 0 1;
%              0 0 0 0 -(K2_ehsv*Kw_ehsv*w_n_ehsv^2)/(As_ehsv*Kr_ehsv) -w_n_ehsv^2 -2*ksi_ehsv*w_n_ehsv];
% 
% Control.B = [0 0; -1/mp 0; 0 0; 0 0; 0 0;0 0; 0 (Ki_ehsv*K2_ehsv*w_n_ehsv^2)/(As_ehsv*Kr_ehsv)];
% Control.B = Control.B(:,2);
% 
% Control.C = [1 0 0 0 0 0 0;
%              0 0 1 -1 0 0 0;
%              0 0 0 0 1 0 0];
% 
%  Co = ctrb(Control.A,Control.B);
%  unco=length(Control.A)-rank(Co);
%  Ob = obsv(Control.A,Control.C);
%  unob = length(Control.A)-rank(Ob);
%  
%  [Control.WA,Control.DAA] = eig(Control.A.'); 
%  Control.WA = (Control.WA).';
%  Control.SS.ctr = Control.WA*Control.B;
%  
%  [Control.VA,Control.DA] = eig(Control.A);
%  Control.SS.obs = Control.C*Control.VA;
%   
 %Control.K = place(Control.A,Control.B,Control.p);