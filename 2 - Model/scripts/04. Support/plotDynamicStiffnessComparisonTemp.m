

%
%
%

function plotDynamicStiffnessComparisonTemp(handle,initDesign,optDesign)

global DynStiffOptController

init_colors = {[0,0,0.2],[0,0,0.4],[0,0,0.6],[0.4,0.3,0.9]};
opt_colors  = {[0,0.2,0],[0,0.4,0],[0,0.6,0],[0.5,0.9,0]};

figure(handle); hold on;

plot(initDesign.Temp100.StiffnessResponse.spec_fr,initDesign.Temp100.StiffnessResponse.spec_mag,'r--');
p1 = plot(initDesign.Temp100.StiffnessResponse.fr,initDesign.Temp100.StiffnessResponse.mag,'--','Color',init_colors{4});
p2 = plot(initDesign.Tempm15.StiffnessResponse.fr,initDesign.Tempm15.StiffnessResponse.mag,'--','Color',opt_colors{4});
p3 = plot(optDesign.Temp100.StiffnessResponse.fr,optDesign.Temp100.StiffnessResponse.mag,'Color',init_colors{3});
p4 = plot(optDesign.Tempm15.StiffnessResponse.fr,optDesign.Tempm15.StiffnessResponse.mag,'Color',opt_colors{3});
plot((15)*ones(1000,1),linspace(0,1.79E+07,1000),'r--');
plot(initDesign.Temp100.StiffnessResponse.spec_fr,initDesign.Temp100.StiffnessResponse.spec_mag,'r--');

p1.Marker = 'o'; p2.Marker = 'o'; p3.Marker = '*'; p4.Marker = '*';
p1.MarkerSize = 4; p2.MarkerSize = 4; p3.MarkerSize = 4; p4.MarkerSize = 4;

grid on; box on;
% axis([0.1 15 0 10e7]);
axis([0.1 20 0 19e7]);
xlabel('Frequency (Hz)');
ylabel('Dynamic Stiffness (N/m)');
title('Dynamic Stiffness Response Comparison');

switch DynStiffOptController
    case 0
        dyns_legend = legend('Requirement',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'));
    case 1
        dyns_legend = legend('Requirement',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'));               
    case 2
        dyns_legend = legend('Requirement',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'));
    case 3
        dyns_legend = legend('Requirement',...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Temp100.temperature),'ºC)'),...
            strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,4),';Ki=',num2str(initDesign.Controller.Ki,4),';Kd=',num2str(initDesign.Controller.Kd,4),';T=',num2str(initDesign.Tempm15.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Temp100.temperature),'ºC)'),...
            strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,4),';Ki=',num2str(optDesign.Controller.Ki,4),';Kd=',num2str(optDesign.Controller.Kd,4),';T=',num2str(optDesign.Tempm15.temperature),'ºC)'));
    case 4
        error('Full State Feedback Controller Optimization not implemented.');
    case 5
        error('Partial State Feedback Controller Optimization not implemented.');
    otherwise
        error('DynStiffOptController is not a valid controller code.');
end

dyns_legend.FontSize = 8;
leg_pos = get(dyns_legend,'position');
aux1 = leg_pos(1)*0.8;
aux2 = leg_pos(3)*1.3;
set(dyns_legend,'position',[aux1,leg_pos(2),aux2,leg_pos(4)]);


