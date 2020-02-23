close all
clc
clear all

format shortEng
format compact

sampleTime=1e-5;

Load_Parameters
ControlTopology = 4;
EHSV_Step.final = 1; %mA
EHSV_Step.time = 0.5;
TotalTime = 2;
StiffnessTest_Enable = 3;

linearization_type = input('Linearizaton Method : \n 1 - Numerical \n 2 - trim/linmod Matlab \n')

switch linearization_type 
    case 1
        
        run_linearizemodel
        rlocus(ss(sys_act.A,sys_act.B,[0 0 0 0 0 1 0],0))
        StateControl.A = sys_act.A;
        StateControl.B = sys_act.B;
        StateControl.C = sys_act.C;
        StateControl.Kr = 1;
        StateControl.X0 = [0 0 0 1500 1500 0 0]';
        StateControl.Xest0 = X0;
        StateControl.K = place(sys_act.A,sys_act.B,[-1000 -1005 -1010 -45 -50 -40.5 -35]);
        % rlocus(ss(sys_act.A-sys_act.B*K_fb,sys_act.B,[0 0 0 0 1 0],0))
        R =4e5;
        Q = eye(7);
        StateControl.K = lqr(sys_act.A,sys_act.B,Q,R);
        
        % K_fb = place(sys_act.A,sys_act.B,[-80 -84 -40 -45 -50 -40.5 -35]);
        StateControl.L = place(sys_act.A',sys_act.C',[-190 -110 -200 -170 -160 -180 -250])';
        save('StateControl.mat','StateControl')
        
    case 2
%         xp0 = 0.01; xpdot0 = 0; xv0 = 0; P10 = 1500; P20 = 1500;
%         xw = Xwidth; Ps = 3000; Pt = 150; Aleak = Aleak1; Ri = 237674.269; %psi s/in3 - material adade
%         dp1_dp1 = (Be/(V011+Ap*xp0))*((Cd*sqrt(2/Rho)/2)*( (xv0*xw+Aleak)/sqrt(Ps-P10) + Aleak/sqrt(P10-Pt) ) - 1/Ri);
%         dp1_dp2 = (Be/(V011+Ap*xp0))/Ri;
%         dp1_xp = (-1*Be/((V011+Ap*xp0)^2))*Ap*((Cd*sqrt(2/Rho)/2)*((xv0*xw+Aleak)*sqrt(Ps-P10)-Aleak*sqrt(P10-Pt))-Ap*xpdot0 - (P10-P20)/Ri);
%         dp1_xv = (Be/(V011+Ap*xp0))*Cd*sqrt(2/Rho)*xw*sqrt(Ps-P10);
% 
%         dp2_dp2 = (Be/(V011-Ap*xp0))*((Cd*sqrt(2/Rho)/2)*( Aleak/sqrt(Ps-P20) + (Aleak+xw*xv0)/sqrt(P20-Pt) )+ 1/Ri);
%         dp2_dp1 = (Be/(V011-Ap*xp0))/Ri;
%         dp2_xp = (Be/((V011-Ap*xp0)^2))*Ap*((Cd*sqrt(2/Rho)/2)*(-(xv0*xw+Aleak)*sqrt(P20-Pt)+Aleak*sqrt(Ps-P20))+Ap*xpdot0 + (P10-P20)/Ri);
%         dp2_xv = (Be/(V011-Ap*xp0))*(-1)*Cd*sqrt(2/Rho)*xw*sqrt(P20-Pt);

%         StateControl.A = [0 1 0 0 0 0 0;...
%                   0 0 1 0 0 0 0;...
%                   -1.77e10 -2.114e7 -3636 0 0 0 0;...
% 
% % %                    14.3567e+003*751.6064 0 0  -37.8646e+003    37.8644e+003  -50.9113e-009   -33.4228e+003;...
% % %                    -14.3567e+003*713.0365 0 0  37.8636e+003   -37.8638e+003  -51.5435e-009    33.4221e+003;...
% 
% % % 22.5923e+006 0 0 -37.6696e+003-32.8930e-003  0 1.3060e-006   -33.2502e+003;...
% % %  -22.8276e+006  0 0 0 -38.0620e+003-33.2356e-003     1.3333e-006    33.5966e+003;...
% 
% % %                    17.5156e+006 0 0 -37.8643e+003-152.8527e-003 37.8641e+003 85.0918e-009   -33.4226e+003;...
% % %                    -17.5154e+006 0 0 37.8637e+003 -37.8639e+003-152.8511e-003 85.0899e-009    33.4223e+003;...
% % 
%                   dp1_xv 0 0  dp1_dp1  dp1_dp2 dp1_xp -Ap*Be/(V011+Ap*xp0);...
%                   dp2_xv 0 0  dp2_dp1  dp2_dp2  dp2_xp  Ap*Be/(V011-Ap*xp0);...
%                   0 0 0 0 0 0 1;...
%                   0 0 0 1.0879 -1.0879 -9.579e4 -467.2897e-003];

%          StateControl.A = [0 1 0 0 0 0 0;...
%                   0 0 1 0 0 0 0;...
%                   -1.77e10 -2.114e7 -3636 0 0 0 0;...
%                   1.436e4*751.6064 0 0 -0.05558 0 -1.094e-10 -3.342e4;...
%                   -1.436e4*713.0365 0 0 0 -0.05558 1.095e-10 3.342e4;...
%                   0 0 0 0 0 0 1;...
%                   0 0 0 1.088 -1.088 -9.579e4 -0.4673];

        StateControl.A = [0 1 0 0 0 0;
                          0 0 1 0 0 0;
                          -1.77e10 -2.114e7 -3636 0 0 0;
                          2.30e7 0 0 -9.36e-2 8.16e1 -9.63e4;
                          0 0 0 0 0 1;
                          0 0 0 2.18 0 -46.73];


        StateControl.B = [0 0 3.278e7 0 0 0]';
        StateControl.C = [0 0 0 0 1 0];
        StateControl.D = 0;
        % StateControl.Kr =
        StateControl.X0 = [0 0 0 0 0 0]';
        StateControl.Xest0 = [0 0 0 0 0 0]';

%         StateControl.K = place(StateControl.A,StateControl.B,[-1000 -1005 -1010 -45 -50 -40.5 -35]);
%         rlocus(ss(sys_act.A-sys_act.B*K_fb,sys_act.B,[0 0 0 0 1 0],0))
        
        % LQR Control
        Rq = 4e4;
        Q = eye(6);
        Q(1,1) = 0.5*(1/1e-2)^2; Q(2,2) = 1; Q(3,3) = 1e4; Q(4,4) = (1/25)^2; Q(5,5)=(1/1e-4)^2 ;Q(6,6)=1;
        
        StateControl.K = lqr(StateControl.A,StateControl.B,Q,Rq);
%         poles = [-13.5694e+003, -1.0401e+003+471.6984e+000i, -1.0401e+003-471.6984e+000i,...
%             -25.0220e+000+457.3409e+000i,-25.0220e+000-457.3409e+000i,-19.7705e+000];
%         poles = [-1.3227e+003+4.0924e+003i,-1.3227e+003-4.0924e+003i,-968.7266e+000,...
%             -24.6221e+000+457.7413e+000i,-24.6221e+000-457.7413e+000i,-10];
%         poles = [-1.3227e+003+4.0924e+003i,-1.3227e+003-4.0924e+003i,-968.7266e+000,...
%             -24.6221e+000+457.7413e+000i,-24.6221e+000-457.7413e+000i,-25];
        
%         StateControl.K = place(StateControl.A,StateControl.B,poles)
        
        save('StateControl.mat','StateControl')
    otherwise
        StateControl = 0;
        
end

fprintf('Matrix A EIGENVALUES \n')
eig(StateControl.A)
rlocus(ss(StateControl.A,StateControl.B,[0 0 0 0 1 0],StateControl.D))

fprintf('Matrix A-Bk EIGENVALUES \n')
eig(StateControl.A - StateControl.B*StateControl.K)
figure
rlocus(ss(StateControl.A-StateControl.B*StateControl.K,StateControl.B,[0 0 0 0 1 0],0))
       


% Reduced order observer
% A_11 = [0 0 0 0;1.436e4*751.6064 -0.0558 0 -1.094e-10; -1.436e4*713.0365 0 -0.0558 1.095e-10; 0 0 0 0];
% A_12 = [1 0 0; 0 0 -3.342e4; 0 0 -3.342e4; 0 0 1];
% A_21 = [0 0 0 0; -1.77e10 0 0 0; 0 1.088 -1.088 -9.579e4];
% A_22 = [0 1 0; -2.114e7 -3636 0; 0 0 -0.4673];
A_11 = [0 0 0;StateControl.A(4,1) StateControl.A(4,4) StateControl.A(4,5); 0 0 0];
A_12 = [1 0 0; 0 0 StateControl.A(4,6); 0 0 1];
A_21 = [0 0 0; StateControl.A(3,1) 0 0; 0 StateControl.A(6,4) 0];
A_22 = [0 1 0; StateControl.A(3,2) StateControl.A(3,3) 0; 0 0 StateControl.A(6,6)];
StateControl.Obs.K = place(A_22',A_12',[-1000 -1100, -200])';
StateControl.Obs.A = A_22 - StateControl.Obs.K*A_12;
StateControl.Obs.L = A_21 - StateControl.Obs.K*A_11 + StateControl.Obs.A*StateControl.Obs.K;
StateControl.Obs.H = [0 3.278e7 0]' - StateControl.Obs.K*[0 0 0]';
save('StateControl.mat','StateControl')

% K_obs = place(sys_act.A',[0 0 0 0 0 1 0]',[-10 -11 -20 -15 -16 -18 -25])';

%
% SealType =3; SealConstValue = 0; Sel_ent_air = 1; Sel_bulk =3;P10 = 1500; P20 = 1500;
% options(14)=70000; [x,u,y,dx,options]=trim('Actuator_linear',[0 1500 1500 0 0 0 0]',0,0,[1;2;3;4;5],[1],[1],[],[],options);
% sys_struct = linmod('Actuator_linear',[0 1500 1500 0 0 0 0]',0);
% % sys_struct = linmod('Actuator_linear',x,u);
% % rlocus(ss(sys_struc.a,sys_struc.b,sys_struc.c,sys_struc.d))
% StateControl.A = sys_struct.a;
% StateControl.B = sys_struct.b;
% StateControl.C = sys_struct.c;
% StateControl.X0 = [0 1500 1500 0 0 0 0]';

% K_fb = place(sys_act.A,sys_act.B,[-200 -240 -220 -100 -120 -50 -40.5]);
% rlocus(ss(sys_act.A-sys_act.B*K_fb,sys_act.B,[0 0 0 0 0 1 0],0))
sampleTime=1e-5;
load('StateControl.mat')
simOut1 = sim('LinearModel_RudderActuator2','StopTime',num2str(TotalTime));

sampleTime=1e-5;
Sel_bulk = 2; SealType = 2; Sel_ent_air = 2; P10 = 1500; P20 = 1500;
simOut = sim('RudderActuatorChannel_check2','StopTime',num2str(TotalTime),'SimulationMode','normal');


Xv_EHSV.Values = simOut.get('logsout').getElement('Xv').Values;
Xv_dot_EHSV.Values =  simOut.get('logsout').getElement('Xv_dot').Values;
Xv_dot2_EHSV.Values =  simOut.get('logsout').getElement('Xv_dot2').Values;
P1.Values =  simOut.get('logsout').getElement('P1').Values;
P2.Values =  simOut.get('logsout').getElement('P2').Values;
Xpiston.Values =  simOut.get('logsout').getElement('Xp').Values;
Xpiston_dot.Values =  simOut.get('logsout').getElement('Xpdot').Values;
% Current.Values = simOut.get('logsout').getElement('Current_Cmd_CL').Values;
Q1_nonlin.Values = simOut.get('logsout').getElement('EHSV_Q').Values.Q1;
Q2_nonlin.Values = simOut.get('logsout').getElement('EHSV_Q').Values.Q2;

load('lin_model.mat')

Xv_lin = states_lin.Data(:,1);
Xv_dot_lin = states_lin.Data(:,2);
Xv_dot2_lin = states_lin.Data(:,3);
dP_lin = states_lin.Data(:,4);
% P2_lin = states_lin.Data(:,5);
Xp_lin = states_lin.Data(:,5);
Xp_dot_lin = states_lin.Data(:,6);

% Xv_lin = states_lin.Data(:,4);
% Xv_dot_lin = states_lin.Data(:,7);
% Xv_dot2_lin = states_lin.Data(:,6);
% P1_lin = states_lin.Data(:,2);
% P2_lin = states_lin.Data(:,3);
% Xp_lin = states_lin.Data(:,1);
% Xp_dot_lin = states_lin.Data(:,4);

% subplot(7,1,1)
% plot(Xv_EHSV.Values.Time,Xv_EHSV.Values.Data)
% subplot(7,1,2)
% plot(Xv_dot_EHSV.Values.Time,Xv_dot_EHSV.Values.Data)
% subplot(7,1,3)
% plot(P1.Values.Time,P1.Values.Data)
% subplot(7,1,4)
% plot(P2.Values.Time,P2.Values.Data)
% subplot(7,1,5)
% plot(Xpiston.Values.Time,Xpiston.Values.Data)
% subplot(7,1,6)
% plot(Xpiston_dot.Values.Time,Xpiston_dot.Values.Data)
% subplot(7,1,7)
% plot(Current.Values.Time,Current.Values.Data)
%%
figure
subplot(2,1,1)
plot(Xv_EHSV.Values.Time,Xv_EHSV.Values.Data,'b')
ylabel('Xv (in)')
title('EHSV')
hold on
plot(states_lin.Time,Xv_lin,'g--')
axis tight
legend('Nonlinear','Linear')

subplot(2,1,2)
plot(Xv_dot_EHSV.Values.Time,Xv_dot_EHSV.Values.Data,'b')
ylabel('Xv dot (in/s)')
hold on
plot(states_lin.Time,Xv_dot_lin,'g--')
axis tight
% 
% subplot(3,1,3)
% plot(Xv_dot_EHSV.Values.Time,Xv_dot2_EHSV.Values.Data,'b')
% ylabel('Xv dot (in/s)')
% hold on
% plot(states_lin.Time,Xv_dot2_lin,'g--')
% axis tight


% figure
% subplot(3,1,1)
% title('Pressure')
% plot(P1.Values.Time,P1.Values.Data)
% ylabel('P1 (psi)')
% hold on
% plot(states_lin.Time,P1_lin,'g')
% axis tight
% legend('Nonlinear','Linear')
% 
% subplot(3,1,2)
% plot(P2.Values.Time,P2.Values.Data)
% ylabel('P2 (psi)')
% hold on
% plot(states_lin.Time,P2_lin,'g')
% axis tight

% subplot(3,1,3)
figure
plot(P2.Values.Time,P1.Values.Data - P2.Values.Data)
ylabel('dP (psi)')
hold on
plot(states_lin.Time,dP_lin,'g--')
axis tight
grid on
legend('Nonlinear','Linear')

figure
subplot(2,1,1)
title('Piston')
plot(Xpiston.Values.Time,Xpiston.Values.Data)
ylabel('Xpiston (in)')
grid on
hold on
plot(states_lin.Time,Xp_lin,'g--')
axis tight
legend('Nonlinear','Linear')
grid on

subplot(2,1,2)
plot(Xpiston_dot.Values.Time,Xpiston_dot.Values.Data)
ylabel('Xpiston dot (in/s)')
grid on
hold on
plot(states_lin.Time,Xp_dot_lin,'g--')
xlabel('Time (s)')
grid on
axis tight

% subplot(3,1,3)
% plot(Current.Values.Time,Current.Values.Data)
% ylabel('Current (mA)')
% axis tight
%% 
% aa= states_lin.Data(:,1);
% Ps = 3000; Pt = 150;
% PsP1 = abs(Ps*ones(length(aa),1)-P1_lin);
% P1Pt = abs(P1_lin-Pt*ones(length(aa),1));
% P2Ps = abs(Ps*ones(length(aa),1)-P2_lin);
% P2Pt = abs(P2_lin-Pt*ones(length(aa),1));
% Q1 = Cd*(Xwidth*Xv_lin + Aleak1*ones(length(aa),1)).*sqrt(2*(PsP1)./Rho) - Cd*(Aleak1*ones(length(aa),1)).*sqrt(2*(P1Pt)./Rho);
% Q2 = Cd*(Xwidth*Xv_lin + Aleak1*ones(length(aa),1)).*sqrt(2*(P2Pt)./Rho) - Cd*(Aleak1*ones(length(aa),1)).*sqrt(2*(P2Ps)./Rho);
% Qint = Cd*Aleakint*sqrt(2*(abs(P1_lin-P2_lin))./Rho);
% Qep1 = Cd*Aleak1*sqrt(2.*(abs(P1_lin))./Rho);
% Qep2 = Cd*Aleak1*sqrt(2.*(abs(P2_lin))./Rho);
% 
% b_V1 = 320000*ones(length(aa),1)./(V011*ones(length(aa),1)+Ap*states_lin.Data(:,6));
% b_V2 = 320000*ones(length(aa),1)./(V011*ones(length(aa),1)-Ap*states_lin.Data(:,6));
% 
% figure
% subplot(3,1,1)
% plot(states_lin.Time,Q1,'g')
% hold on
% plot(Q1_nonlin.Values.Time, Q1_nonlin.Values.Data)
% 
% subplot(3,1,2)
% plot(states_lin.Time,Q2,'g')
% hold on
% plot(Q2_nonlin.Values.Time, Q2_nonlin.Values.Data)
% 
% subplot(3,1,3)
% plot(states_lin.Time,Qint,'g')

% subplot(6,1,4)
% plot(states_lin.Time,Qep1,'g')
% 
% subplot(6,1,5)
% plot(states_lin.Time,Qep1,'g')

% subplot(6,1,6)
% figure
% plot(states_lin.Time,b_V1)
% hold on
% plot(states_lin.Time,b_V2,'g')

