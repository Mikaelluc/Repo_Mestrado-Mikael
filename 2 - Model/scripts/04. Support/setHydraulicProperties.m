
function [FluidTemperatureFahrenheit,FluidDensity,FluidViscosity] = setHydraulicProperties(FluidTempCelsius)


% Temperature
FluidTemperatureFahrenheit = FluidTempCelsius*9/5 + 32;

% Density - according to SAE AIR1362 Rev. B
FluidDensity = (1.08-0.95)/(-70-90)*(FluidTemperatureFahrenheit-90)+0.95; % Fluid density, N.s²/m4
FluidDensity = 0.00009357268*FluidDensity; % Fluid density, lbf.s²/in4

% Viscosity - future implementation

FluidViscosity = 0;