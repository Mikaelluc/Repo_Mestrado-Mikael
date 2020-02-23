
% Plot and Save Optimization Results

% Save workspace, results and finish command history recording
% save([ folder workspace_filename '.mat' ]);
save([ folder currentDate ' - ' workspace_filename ' - Initial Design.mat' ],'InitialDesign');
save([ folder currentDate ' - ' workspace_filename ' - Optimized Design.mat' ],'OptimizedDesign');
diary off

% Name of figure files
figure_ds = 'Dynamic Stiffness Comparison';
figure_tr = 'Time Response Comparison';
figure_fr = 'Frequency Response Comparison';

% Properties of saved figures
resolution = '-r300';
unit = 'centimeters';
size = [10 5 20 15];

% Figure handles and configuration
h1 = figure; h1.Units = unit; h1.Position =  size;
h2 = figure; h2.Units = unit; h2.Position =  size;
h3 = figure; h3.Units = unit; h3.Position =  size;

% Plot for each response the comparison between initial and optimized
% design in both evaluated temperatures
plotDynamicStiffnessComparisonTemp(h1,InitialDesign,OptimizedDesign);
plotTimeResponseComparisonTemp(h2,InitialDesign,OptimizedDesign);
plotFrequencyResponseComparisonTemp(h3,InitialDesign,OptimizedDesign);

% Save figures in MATLAB format to allow later customization
saveas(h1,[ folder currentDate ' - ' figure_ds ],'fig');
saveas(h2,[ folder currentDate ' - ' figure_tr ],'fig');
saveas(h3,[ folder currentDate ' - ' figure_fr ],'fig');

% Save figures in jpeg format for use in documents
print(h1,[ folder currentDate ' - ' figure_ds ],'-djpeg',resolution);
print(h2,[ folder currentDate ' - ' figure_tr ],'-djpeg',resolution);
print(h3,[ folder currentDate ' - ' figure_fr ],'-djpeg',resolution);



