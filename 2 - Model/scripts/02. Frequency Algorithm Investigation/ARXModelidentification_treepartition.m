



function rudder_act_arx = ARXModelidentification_treepartition(model_name)


% Simulation time (s)
Time = num2str(15);
simOut = sim(model_name,'StopTime',Time);
          
Surf_cmd = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Data;
Surf_fbk = simOut.get('logsout').getElement('SurfacePosition_(deg)').Values.Data;
timet = simOut.get('logsout').getElement('SurfacePositionCmd_(deg)').Values.Time;


% Reducing data resolution
Surf_cmd_new = zeros((length(Surf_cmd)-1)/100,1);
Surf_fbk_new = zeros((length(Surf_fbk)-1)/100,1);
timet_new = zeros((length(timet)-1)/100,1);
j=1;
for i = 1:100:length(Surf_cmd)
    Surf_cmd_new(j) = Surf_cmd(i);
    Surf_fbk_new(j) = Surf_fbk(i);
    timet_new(j) = timet(i);
    j = j + 1;
end
Ts = timet_new(20)-timet_new(19);

data = iddata(Surf_fbk_new,Surf_cmd_new,Ts);

% nlarxopt = nlarxOptions('Focus','simulation');
% rudder_act_arx = nlarx(data,[21 21 1],'wavenet');
% rudder_act_arx = nlarx(data,[15 15 1],'sigmoidnet');
rudder_act_arx = nlarx(data,[19 19 1],'treepartition');

% opt = armaxOptions;
% opt.Focus = 'simulation';
% opt.SearchOption.MaxIter = 50;
% opt.SearchOption.Tolerance = 1e-5;
% na = 4;
% nb = 4;
% nc = 4;
% nk = 0;
% 
% sys_act = armax(data,[na nb nc nk], opt);

end