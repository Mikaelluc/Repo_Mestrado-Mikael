

%
%
%

function plotDynamicStiffness(handle,response,curve)

colors = {'b-*','g-*','r-*','y-*'};

figure(handle);
handle.Name = 'Dynamic Stiffness Algorithms Graphic Comparison'; 

plot(response.fr,response.mag,colors{curve}); hold on;
plot(response.spec_fr,response.spec_mag,'r--');
grid on;
title('Dynamic Stiffness Test Analysis')
xlabel('Frequency (Hz)')
ylabel('Dynamic Stiffness (N/m)')
legend('Design','Requirement')%,'New Requirement')
title('Dynamic Stiffness Algorithms Graphic Comparison');
end