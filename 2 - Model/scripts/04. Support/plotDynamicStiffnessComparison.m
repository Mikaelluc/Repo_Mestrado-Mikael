

%
%
%

function plotDynamicStiffnessComparison(handle,initDesign,optDesign)

colors = {'b-*','g-*','r-*','y-*'};

figure(handle);
hold on;
plot(initDesign.StiffnessResponse.spec_fr,initDesign.StiffnessResponse.spec_mag,'r--');
plot(initDesign.StiffnessResponse.fr,initDesign.StiffnessResponse.mag,colors{1});
plot(optDesign.StiffnessResponse.fr,optDesign.StiffnessResponse.mag,colors{2});
grid on;
axis([0.1 15 0 10e7]);
xlabel('Frequency (Hz)')
ylabel('Dynamic Stiffness (N/m)')
title('Dynamic Stiffness Response Comparison');
legend('Requirement',...
    strcat('Initial Design (Kp=',num2str(initDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(initDesign.Controller.Kd,'%1.4f'),')'),...
    strcat('Optimized Design (Kp=',num2str(optDesign.Controller.Kp,'%1.4f'),';Kd=',num2str(optDesign.Controller.Kd,'%1.4f'),')'));



