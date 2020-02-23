% clear all
% clc

parameters.cd   = 0.67; %adm

parameters.wv   = 4.5974e+03; %Hz
parameters.ksiv = 0.4; %adm
parameters.kv   = 0.001852; %in/mA

parameters.Asv  = 0.026; % in2
parameters.Kiv  = 0.025; %in lbs/ma
parameters.Krv  = 93;
parameters.K2v  = 150; %in3/s/in
parameters.Kwv  = 13.5; %in lbs/in

parameters.Beta = 150000; %psi
parameters.xw   = 0.20; %in
parameters.Ap   = 2.328; %in^2
parameters.V01  = 10.4481; %in3
parameters.rho  = 9.5356e-05; %lbf.s²/in?
parameters.Ps   = 3000; %psi
parameters.V02  = 10.4481; %in3
parameters.Pt   = 150; %psi
parameters.Bp   = 1; %lbf.s/in
parameters.Kp   = 2.05E+05; %lbf/in
parameters.Fl   = 0;%.30*2850*parameters.Ap;
parameters.mp   = 2.14;% lb
parameters.Aleak = pi*.001^2/4;
parameters.Aleakint = pi*.005^2/4;

% parameters.cd   = 0.67;
% parameters.wv   = 730; %Hz
% parameters.ksiv = 0.4; %adm
% parameters.kv   = 0.001852*0.0254; %m/mA
% parameters.Beta = 150000*6894.75729; %Pa
% parameters.xw   = 0.20*0.0254; %m
% parameters.Ap   = 2.328*0.00064516; %m^2
% parameters.V01  = 10.4481*1.6387064*10^(-5); %m3
% parameters.rho  = 9.5356e-05*10686895.2 ; %Kg/m3
% parameters.Ps   = 3000*6894.75729; %Pa
% parameters.V02  = 10.4481*1.6387064*10^(-5); %m3
% parameters.Pt   = 150*6894.75729; %Pa
% parameters.Bp   = 1*175.126835; %N/(m.s)
% parameters.Kp   = 2.05E+05*175.126835; %N/m
% parameters.Fl   = 0;%.30*2850*6894.75729*parameters.Ap;
% parameters.mp   = 2.14*0.45359237;% Kg

control = 0;

% X0 = [1E-3 0 1500*6894.75729 1500*6894.75729 parameters.Fl/parameters.Kp 0];

X0 = [0 0 0 150 150 parameters.Fl/parameters.Kp 0];

sys_act = linearize_model(parameters,X0,control)

eig(sys_act.A)

Co = ctrb(sys_act.A,sys_act.B);
unco = length(sys_act.A)-rank(Co)

Ob = obsv(sys_act.A,sys_act.C);
unob = length(sys_act.A)-rank(Ob)
 