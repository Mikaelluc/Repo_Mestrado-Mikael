clear all
clc

run('Load_Parameters')
Time = 10.0;
dpres = Supply_Pressure -Return_Pressure;
SLd = Ap*dpres;

EHSV_steps = [10, 8, 6 ,4 ,2 , 1];
load_cmd_matrix = [SLd,6500:-500:-SLd/2];
rate_high = 25.5;
rate_low = 4.49;

t  = [0:0.001:Time]';

rate = zeros(length(EHSV_steps),length(load_cmd_matrix));

%% Run Simulation

for j = 1: length(EHSV_steps)
    
    EHSV_step.final = EHSV_steps(j);
 
for i = 1:length(load_cmd_matrix)
    
    load_cmd = load_cmd_matrix(i);

    sim_parameters.StopTime = num2str(max(t));
    
    tout = t;

    DataLog = sim('Load_Rate_Actuator',sim_parameters);
    
    load('rate_out.mat')
    
    rate(j,i) = rate_out(2,end);
end

end

for ind = 1:(length(EHSV_steps)) 
plot(rate(ind,:),load_cmd_matrix);
hold all
end
grid on
axis tight
ylabel('Load (lbf)')
xlabel('Rate (deg/s)')
