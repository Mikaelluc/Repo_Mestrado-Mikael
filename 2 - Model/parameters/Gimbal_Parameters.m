%Gimbal Parameters
%Tabela 4.1 Espinosa Ramirez
% Azimuth
Jaz = 1.78e-4;         % Rotational Intertia [kg·m²]
Baz = 5.2e-3;          % Viscous friction coefficient [N·m·s/rad]

% Elevation
Jel = 4.66e-4;        % Rotational Inertia [kg·m²]
Bel = 5.2e-3;         % Viscous friction coefficient [N·m·s/rad]


%------------------------------------------------------------------------------------------------------------

% Motor parameters for FAULHABER 1524T012SR

V_nominal     = 12;              % Nominal voltage [V]
R             = 19.8;            % Thermal resistance [Ohms]
P_out         = 1.75;            % Output power [W]
efficiency    = 0.76;            % Max efficiency [unitless]
no_load_rpm   = 9900;            % No-load speed [rpm]
omega_no_load = 9900 * 2*pi/60;  % No-load speed [rad/s]
no_load_I     = 0.011;           % No-load current [A]
tau_friction  = 0.13e-3;         % Friction torque [Nm]
Kv_rpm_per_V  = 840;             % Speed constant [rpm/V]
Kt_mNm_per_A  = 11.4;            % Torque constant [mNm/A]
Ki_A_per_mNm  = 0.088;           % Current per torque [A/mNm]
tau_mech      = 10e-3;           % Mechanical time constant [s]
J_cm2         = 0.65;            % Rotor inertia [g·cm²]
alpha_max     = 100e3;           % Angular acceleration [rad/s²]
mass          = 21e-3;           % Mass [kg]
Tstall        = 6.92e-3;          % Torque [Nm] 

% Encoder parameters for FAULHABER IE2-512

encoder_resolution     = 512;             % Pulses per revolution [PPR]
encoder_max_freq       = 160e3;           % Max frequency [Hz]
encoder_voltage_range  = [4.5, 5.5];      % Supply voltage range [V]
encoder_current_max    = 13e-3;           % Max current [A]
encoder_phase_shift_AB = 90;              % Phase shift between channels A and B [degrees]
J_encoder_gcm2         = 0.09;            % Disk inertia [g·cm²]

%Modeled Motor Parameters
Jm            = J_cm2 * 1e-7 + J_encoder_gcm2 * 1e-7;   % Motor inertia [kg·m²]
J_encoder     = J_encoder_gcm2 * 1e-7;                  % Encoder inertia [kg·m²]
Km            = Kt_mNm_per_A * 1e-3;                    % Torque constant [Nm/A]
Ke            = 1 / (Kv_rpm_per_V * (2*pi/60));         % Back EMF constant [V·s/rad]
L             = 250e-6;                                 % Inductance [H]
Bm            = tau_friction/omega_no_load;             % Viscous friction coefficient [N·m·s/rad]
R             = 0.674;                                   % Armature resistance [Ohms]

%------------------------------------------------------------------------------------------------------------

%Camera Parameters
W_original = 1280;          %Pixels
H_original = 720;           %Pixels
W_YOLO = 600;               %Pixels
H_YOLO = 440;               %Pixels
s_x = W_YOLO/W_original;
s_y = H_YOLO/H_original;
f_x = 1109;                 %Pixels
f_y = 1109;                 %Pixels
c_x = 640;                  %Pixels
c_y = 360;                  %Pixels
K_camera = [f_x 0 c_x
            0 f_y c_y
            0 0 1] ;        %Scaled Intrinsic Matrix
K_camera_inv = inv(K_camera);

%------------------------------------------------------------------------------------------------------------
%Ripple Parameters
A_ripple        = 0.04 * Tstall;
N_cycles_ripple = 91;

%Coulomb Friction
K_cf = 3.6e-4; %[]

%------------------------------------------------------------------------------------------------------------
%Atraso
Tpade = 0.04; %[s], ou 40[ms]
Tpade2 = 0.08

%System
DC_motor_IN = tf([Km*(Jm+Jel) Km*(Bel+Bm)], [L*(Jm+Jel) R*(Jm+Jel)+L*(Bm+Bel) R*(Bm+Bel)+Km*Ke])
Inner_gimbal = feedback(tf([1],[(Jel+Jm) (Bel+Bm)]),-K_cf)
elevation_axis = tf([Tpade^2 -6*Tpade 12], [Tpade^2 6*Tpade 12])*DC_motor_IN*Inner_gimbal*tf([1],[1 0])
[Csel, info_el] = pidtune(elevation_axis,'PID')

Outer_gimbal = feedback(tf([1],[(Jaz+Jm) (Baz+Bm)]),-K_cf)
DC_motor_OUT = tf([Km*(Jm+Jaz) Km*(Baz+Bm)], [L*(Jm+Jaz) R*(Jm+Jaz)+L*(Bm+Baz) R*(Bm+Baz)+Km*Ke])
azimuth_axis = feedback(tf([Tpade^2 -6*Tpade 12], [Tpade^2 6*Tpade 12])*DC_motor_OUT*Outer_gimbal*tf([1],[1 0]),tf([Tpade2^2 -6*Tpade2 12], [Tpade2^2 6*Tpade2 12]))
%Gsaz = tf([Km], [((Jaz+Jm)*L) ((Jaz+Jm)*R+(Baz+Bm)*L) ((Baz+Bm)*R+Km*Ke) 0])
[Csaz, info_az] = pidtune(azimuth_axis,'PID')

s = tf('s')
