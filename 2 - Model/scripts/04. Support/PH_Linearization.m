


kv1 = -K2*Kw*(wne^2)/(As*Kr);
kv2 = -(wne^2);
kv3 = -2*ksie*wne;
gv = 
gdP = 
gp = 
gpd = 
adP = Ap/mp;
apd = -Bp/mp;
kvi = Ki*K2*(wne^2)/(As*Kr);





LinActModel.Xo = [0 0 0 0 0 0]; % xv xvd xvdd dP xp xpd
LinActModel.U = 0; % i
LinActModel.Y = [0 0 0]; % xv dP xp

LinActModel.A = [0   1   0   0   0  0;
                 0   0   1   0   0  0;
                 kv1 kv2 kv3 0   0  0;
                 gv  0   0   gdP gp gpd;
                 0   0   0   0   0  1;
                 0   0   0   adP 0  apd];
LinActModel.B = [0; 
                 0; 
                 kvi; 
                 0; 
                 0; 
                 0];
LinActModel.C = [1   0   0   0   0  0;
                 0   0   0   1   0  0;
                 0   0   0   0   1  0];
LinActModel.D = 0;





















%% 

% EHSV 1st Stage - Moog model
% i_ehsv = 10; %ma Torque motor current
% xf_ehsv = 0.0012; %in Flapper displacement at nozzles
% xs_ehsv = 1; %in Spool displacement
% DeltaQ_ehsv = 0.18;%in3/s Hydraulic amplifier differential flow
% Ql_ehsv = 4; %gpm Servovalve control flow
% Ki_ehsv = 0.025; %in lbs/ma Torque motor gain
% K2_ehsv = 150; %in3/s/in Hydraulic amplifier flow gain
% K3_ehsv = 1030; %in3/s/in Flow gain of spool/bushing
% As_ehsv = 0.026; % in2 Spool end area
% Kf_ehsv = 93; %in lbs/in Net stiffness on armature/flapper
% Kw_ehsv = 13.5; % in lbs/in feedback wire stiffness
% bf_ehsv = 0.016; % in lbs/ in/sec net damping on armature/flapper
% lf_ehsv = 4.4e-6; %in lbs/ in/sec2 rotational mass of armature/flapper
% w_n_ehsv = sqrt(Kf_ehsv/lf_ehsv); %730 Hz natural frequency of first stage
% Kv = K2_ehsv*Kw_ehsv/(Kf_ehsv*As_ehsv);%840; %serovalve loop gain 1/s
% Kr_ehsv = K2_ehsv*Kw_ehsv/(Kv*As_ehsv);%w_n_ehsv^2/Kf_ehsv; % Armature flapper
% ksi_ehsv = w_n_ehsv*bf_ehsv/(2*Kf_ehsv);%0.4; % damping ratio of first stage

% Ka1 = 2.05E+05; % 329-326
% Mp1 = 2.14; % Piston mass for Act1, lb
% Bp1 = 1; % Damping coefficient for Act1, lbf.s/in


Control.X0 = [0 0 1600 1600 0 0 0]'; %xp xpdot P1 P2 xv xvdot xvddot
xp_0 = Control.X0(1); xpd_0 = Control.X0(2); P1_0 = Control.X0(3); P2_0 = Control.X0(4); xv_0 = Control.X0(5);
Ps = Supply_Pressure;
Pt = Return_Pressure;
Aleak = Aleak1;
xw = Xwidth;
V0 = V011;
Betac = 2.425e5 - 603.4*Temp;
Betaa = 5.971;
mp = Mp1;
Bp = Bp1;
Kpp = Ka1;
kd = Cd*sqrt(2/Rho);

c1 = (-Ap/(V0+Ap*xp_0)^2)*(Betac + Betaa*P1_0)*( kd*sqrt(Ps-P1_0)*(xv_0*xw+Aleak) -kd*sqrt(P1_0 - Pt)*Aleak - Ap*xpd_0 - kd*Ap*sqrt(P1_0));
c2 = -Ap *((Betac + Betaa*P1_0)/(V0+Ap*xp_0));
c3 = (Betaa/(V0+Ap*xp_0))*(kd*sqrt(Ps-P1_0)*(xv_0*xw+Aleak) - kd*sqrt(P1_0-Pt)*Aleak - Ap*xpd_0 - kd*Ap*sqrt(P1_0)) + ...
    ((Betac + Betaa*P1_0)/(V0+Ap*xp_0))*(kd/2)*(-(xv_0*xw+Aleak)/sqrt(Ps - P1_0) - Aleak/sqrt(P1_0-Pt) - Ap/sqrt(P1_0));
c4 = 0;
c5 = ((Betac + Betaa*P1_0)/(V0+Ap*xp_0))*kd*sqrt(Ps - P1_0)*xw;
c6 = (Ap/(V0-Ap*xp_0)^2)*(Betac + Betaa*P2_0)*(Ap*xpd_0  - kd*Ap*sqrt(P2_0) - kd*sqrt(P2_0-Pt)*(xv_0*xw+Aleak) +kd*sqrt(Ps - P2_0)*Aleak);
c7 = Ap *((Betac + Betaa*P2_0)/(V0-Ap*xp_0));
c8 = 0;
c9 = (Betaa/(V0 - Ap*xp_0))*(Ap*xpd_0  - kd*Ap*sqrt(P2_0) - kd*sqrt(P2_0-Pt)*(xv_0*xw+Aleak) +kd*sqrt(Ps - P2_0)*Aleak) + ...
    ((Betac + Betaa*P2_0)/(V0-Ap*xp_0))*(kd/2)*(-Ap/sqrt(P2_0) -(xv_0*xw+Aleak)/sqrt(P2_0-Pt) + Aleak/sqrt(Ps - P2_0));
c10 = ((Betac + Betaa*P2_0)/(V0-Ap*xp_0))*-kd*sqrt(P2_0-Pt)*xw;


Control.A = [0 1 0 0 0 0 0;
             -Kpp/mp -Bp/mp Ap/mp -Ap/mp 0 0 0;
             c1 c2 c3 c4 c5 0 0;
             c6 c7 c8 c9 c10 0 0;
             0 0 0 0 0 1 0;
             0 0 0 0 0 0 1;
             0 0 0 0 -(K2_ehsv*Kw_ehsv*w_n_ehsv^2)/(As_ehsv*Kr_ehsv) -w_n_ehsv^2 -2*ksi_ehsv*w_n_ehsv];

Control.B = [0 0; -1/mp 0; 0 0; 0 0; 0 0;0 0; 0 (Ki_ehsv*K2_ehsv*w_n_ehsv^2)/(As_ehsv*Kr_ehsv)];
Control.B = Control.B(:,2);

Control.C = [1 0 0 0 0 0 0;
             0 0 1 -1 0 0 0;
             0 0 0 0 1 0 0];


modern = ss(Control.A,Control.B,Control.C,0);


%%
StateControl.C = [1 0 0 0 0 0;
                  0 0 0 1 0 0;
                  0 0 0 0 1 0];

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
%  Control.K = place(Control.A,Control.B,Control.p);