
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Resposta ao Degrau do Controlador Original
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% model_filename = 'RudderActuatorChannel_control';

PH_StepInput_CLLoad;
simOut = sim(model_filename,'StopTime',num2str(Time));
% set_param(bdroot,'SimulationCommand','start')

% Initial Variables

SurfaceCmd.Values.Time  = simOut.get('yout').time;
SurfacePos.Values.Time  = simOut.get('yout').time;
SurfaceRate.Values.Time = simOut.get('yout').time;
Load.Values.Time        = simOut.get('yout').time;
HornArm.Values.Time     = simOut.get('yout').time;

SurfaceCmd.Values.Data  = simOut.get('yout').signals(1,1).values;
SurfacePos.Values.Data  = simOut.get('yout').signals(1,2).values;
SurfaceRate.Values.Data = simOut.get('yout').signals(1,3).values;
Load.Values.Data        = simOut.get('yout').signals(1,4).values;
HornArm.Values.Data     = simOut.get('yout').signals(1,5).values;

% BulkModulusC1.Values    = simOut.get('logsout').getElement('BulkModulusC1').Values;
% BulkModulusC2.Values    = simOut.get('logsout').getElement('BulkModulusC2').Values;
% P1.Values               = simOut.get('logsout').getElement('P1').Values;
% P2.Values               = simOut.get('logsout').getElement('P2').Values;
% FrictionForce.Values    = simOut.get('logsout').getElement('FrictionForce').Values;
% Xpiston.Values          = simOut.get('logsout').getElement('Xp').Values;
% 
% Xv_EHSV.Values          = simOut.get('logsout').getElement('Xv').Values;
% Q_EHSV.Values           = simOut.get('logsout').getElement('EHSV_Q').Values;
% i_EHSV.Values           = simOut.get('logsout').getElement('EHSV_current_cmd').Values;
% 
% Koil.Values.Time        = simOut.get('yout').time;
% Koil.Values.Data        = Ap^2.*(BulkModulusC1.Values.Data ./ (V011.*ones(length(simOut.get('yout').time),1) + Ap.*Xpiston.Values.Data)...
%                             + BulkModulusC2.Values.Data ./ (V021.*ones(length(simOut.get('yout').time),1)-Ap.*Xpiston.Values.Data)).*6894.75729;

n=length(SurfacePos.Values.Time);
final = SurfacePos.Values.Data(n);

FullStroke_deg = 2*33.3;

StepResponse = stepinfo(SurfacePos.Values.Data,SurfacePos.Values.Time,SurfaceCmd.Values.Data(n),'RiseTimeLimits',[0.15,0.85],'SettlingTimeThreshold',0.02);

Td = 0;
Tr1 = 0;
Tr2 = 0;

for i=1:n
    if abs(SurfacePos.Values.Data(i))> abs(SurfacePos.Values.Data(1)) && Td == 0
        Td = SurfacePos.Values.Time(i);
    end

end

Ts = StepResponse.SettlingTime - Input.Step.Time;
Tp = StepResponse.PeakTime - Input.Step.Time;
Tr = StepResponse.RiseTime - Input.Step.Time;
Mp = StepResponse.Overshoot;
yss =  SurfaceCmd.Values.Data(n);
StepResponse.av_rate = (0.85*Input.Step.FinalValue - 0.15*Input.Step.FinalValue)/StepResponse.RiseTime;
StepResponse.ess = (final - SurfaceCmd.Values.Data(n))/FullStroke_deg;
