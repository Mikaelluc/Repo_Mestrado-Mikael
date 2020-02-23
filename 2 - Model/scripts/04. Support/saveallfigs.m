% figures = []; 
% Generate figures
%[your code]
% Resize and output figures
figSize = [21, 29];            % [width, height]
figUnits = 'Centimeters';
for f = 1:60
      fig = figure(f);
      % Resize the figure
      set(fig, 'Units', figUnits);
      pos = get(fig, 'Position');
      pos = [pos(1), pos(4)+figSize(2), pos(3)+figSize(1), pos(4)];
      set(fig, 'Position', pos);
      % Output the figure
      filename = sprintf('Figure%02d.pdf', f);
      print( fig, '-dpdf', filename );
end