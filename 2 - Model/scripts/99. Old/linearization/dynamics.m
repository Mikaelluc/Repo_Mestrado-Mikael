function din = dynamics(t,X,control,dt,parameters)

%tem que passar o aeronave.S pra dentro da funcao

if dt >= 0
    waitbar(t/dt);
end

% xv     = X(1);
% xv_dot = X(2);
% P1     = X(3);
% P2     = X(4);
% xp     = X(5);
% xp_dot = X(6);

xv     = X(1);
xv_dot = X(2);
xv_dot_dot = X(3);
P1     = X(4);
P2     = X(5);
xp     = X(6);
xp_dot = X(7);

cd = parameters.cd;

wv = parameters.wv;
ksiv = parameters.ksiv;
kv = parameters.kv;
Asv = parameters.Asv;
Kiv = parameters.Kiv;
Krv = parameters.Krv;
K2v = parameters.K2v;
Kwv = parameters.Kwv;

Beta = parameters.Beta;
xw = parameters.xw;
Ap = parameters.Ap;
V01 = parameters.V01;
rho = parameters.rho;
Ps = parameters.Ps;
V02 = parameters.V02;
Pt = parameters.Pt;
Bp = parameters.Bp;
Kp = parameters.Kp;
Fl = parameters.Fl;
mp = parameters.mp;
Aleak = parameters.Aleak;
Aleakint = parameters.Aleakint;


u = control;
% 
% Q1 = cd*(xw*xv+Aleak)*sqrt(2*(abs(Ps-P1))/rho) - cd*(Aleak)*sqrt(2*(abs(P1-Pt))/rho);
Q1_s1 = cd*(xw*xv+Aleak)*sqrt(2*(abs(Ps-P1))/rho);
Q1_1t = cd*(Aleak)*sqrt(2*(abs(P1-Pt))/rho);
% Q2 = cd*(xw*xv+Aleak)*sqrt(2*(abs(P2-Pt))/rho) - cd*(Aleak)*sqrt(2*(abs(Ps-P2))/rho);
Q2_2t = cd*(xw*xv+Aleak)*sqrt(2*(abs(P2-Pt))/rho);
Q2_s2 = cd*(Aleak)*sqrt(2*(abs(Ps-P2))/rho);
% Q1 = cd*(xw*xv+Aleak)*sqrt(2*(Ps-P1)/rho) - cd*(Aleak)*sqrt(2*(P1-Pt)/rho);
% Q2 = cd*(xw*xv+Aleak)*sqrt(2*(P2-Pt)/rho) - cd*(Aleak)*sqrt(2*(Ps-P2)/rho);
Qint = cd*Aleakint*sqrt(2*(abs(P1-P2))/rho);

% Qint = cd*Aleakint*sqrt(2*(P1-P2)/rho);

Qep1 = cd*Aleak*sqrt(2*(abs(P1))/rho);
Qep2 = cd*Aleak*sqrt(2*(abs(P2))/rho);
% Qep1 = cd*Aleak*sqrt(2*(P1)/rho);
% Qep2 = cd*Aleak*sqrt(2*(P2)/rho);

% Qep1 = 0; Qep2 = 0;
% Qint = 0;

V1 = V01+Ap*xp;
V2 = V02-Ap*xp;

vetor_de_estados2.xv_dot       = xv_dot;
vetor_de_estados2.xv_dot_dot   = xv_dot_dot;
vetor_de_estados2.xv_dot_3     = ((Kiv*K2v*wv^2)*u - (2*ksiv*wv*Asv*Krv)*xv_dot_dot - (Asv*Krv*wv^2)*xv_dot - (K2v*Kwv*wv^2)*xv)/(Asv*Krv);

vetor_de_estados2.P1_dot       = (Beta/V1)*(Q1_s1 - Q1_1t - Ap*xp_dot - Qint - Qep1);
vetor_de_estados2.P2_dot       = (Beta/V2)*(Ap*xp_dot + Q2_s2 - Q2_2t + Qint - Qep2);

vetor_de_estados2.xp_dot       = xp_dot;
vetor_de_estados2.xp_dot_dot   = (Ap*(P1-P2) - Bp*xp_dot - Kp*xp - Fl)/mp;


din = struct2vect(vetor_de_estados2);

% To DO´s
% 1- Adicionar vazamento interno da EHSV (A_leak) = amortecimento - ok
% 2 - Vazamento entre câmaras - ok
% 3 - Modelagem deltaP
% 4 - Investigar queda de 300 psi para atuador parado - 
% 5 - Equações auxiliares fora - ok



