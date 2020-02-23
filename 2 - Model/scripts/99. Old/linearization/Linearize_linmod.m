    Load_Parameters
SealType = 3; % 1 - Parker O-ring, 2 - Parker O-ring +Stribeck , 3 - Constant value
SealConstValue = 0;
Sel_ent_air = 1;
Sel_bulk = 1;% 1- Constant, 2- Adiabatic Tangent, 3 - Isothermal Secant, 4 - Isothermal Tangent

options(14)=70000; [piston_x0,piston_u0,y,dx,options]=trim('PistonDynamics',[0 0]',[1500 1500]',[0 0]',[],[],[],[],[],options)
sys_piston = linmod('PistonDynamics',piston_x0,piston_u0)
sys_piston.x0 = piston_x0;

options(14)=70000; [valve1_x0,valve1_u0,y,dx,options]=trim('EHSV_1st_stage',[0 0 0]',[0]',[0]',[1],[1],[1],[],[],options)
sys_valve1 = linmod('EHSV_1st_stage',valve1_x0,valve1_u0)
sys_valve1.x0 = valve1_x0;

options(14)=70000; [valve_x0,valve_u0,y,dx,options]=trim('EHSV2',[0 0 0]',[0]',[0 0]',[1],[1],[1],[],[],options)
sys_valve = linmod('EHSV2',valve_x0,valve_u0)
sys_valve.x0 = valve_x0;

options(14)=70000; [fluid1_x0,fluid1_u0,y,dx,options]=trim('FluidDynamics',[2850/2 2850/2]',[0]',[2850/2 2850/2]',[1,2],[1],[1,2],[],[],options)
sys_fluid1 = linmod('FluidDynamics',fluid1_x0,fluid1_u0)
sys_fluid1.x0 = fluid1_x0;

% options(14)=70000; [fluid_x,fluid_u,y,dx,options]=trim('FluidDynamics2',[1600 1600]',[0 0]',[1600 1600]',[1,2],[1 2],[1,2],[],[],options)
% sys_fluid = linmod('FluidDynamics2',fluid_x,fluid_u)
% sys_fluid.x0 = fluid_x;


% sys_fluid.a = [-0.08369         0;  0  -0.08369];
% sys_fluid.b = [2.103e+07      -0.02899             0; -2.103e+07             0      -0.02899];
% sys_fluid.c = [1    0;0    1];
% sys_fluid.d = [ 0             1             0; 0             0             1];

StateControl.A = [0 1 0 0 0 0 0;...
                  0 0 1 0 0 0 0;...
                  -1.77e10 -2.114e7 -3636 0 0 0 0;...
                  1.436e4*751.6064 0 0 -0.05558 0 -1.094e-10 -3.342e4;...
                  -1.436e4*713.0365 0 0 0 -0.05558 1.095e-10 3.342e4;...
                  0 0 0 0 0 0 1;...
                  0 0 0 1.088 -1.088 -9.579e4 -0.4673];
StateControl.B = [0 0 3.278e7 0 0 0 0]';
StateControl.C = [0 0 0 0 0 1 0];
StateControl.D = 0;
% StateControl.Kr =
StateControl.X0 = [0 0 0 1500 1500 0 0]';
StateControl.Xest0 = [0 0 0 1500 1500 0 0]';
eig(StateControl.A)
rlocus(ss(StateControl.A,StateControl.B,StateControl.C,StateControl.D))
StateControl.K = place(StateControl.A,StateControl.B,[-1000 -1005 -1010 -45 -50 -40.5 -35]);
% % rlocus(ss(sys_act.A-sys_act.B*K_fb,sys_act.B,[0 0 0 0 1 0],0))

R =2e5;
Q = eye(7);
StateControl.K = lqr(StateControl.A,StateControl.B,Q,R);
% figure
% rlocus(ss(StateControl.A-StateControl.B*StateControl.K,StateControl.B,[0 0 0 0 0 1 0],0))
StateControl.K
% 
% % K_fb = place(sys_act.A,sys_act.B,[-80 -84 -40 -45 -50 -40.5 -35]);
% StateControl.L = place(StateControl.A',StateControl.C',[-190 -110 -200 -170 -160 -180 -250])';

save('StateControl.mat','StateControl')

