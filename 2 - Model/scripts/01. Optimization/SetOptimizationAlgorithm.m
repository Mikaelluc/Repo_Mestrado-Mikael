function opt = SetOptimizationAlgorithm(option,debug)
%This function generates a structre variable containing the settings for
%a chosen optimization algorithm. 
%
%Options may assume the following values:
%
% option = 'active-set' -> Select Active-Set algorithm for fmincon.
% Active-Set Algorithm does not respect linear and non-linear restrictions
% during intermediate steps, moreover if the user does not provide an
% initial guess that respects one of the boundary conditions, it is very
% likely that the algorithm may try solutions outside of the boundary
% conditions scope, possibly leading to a failure in the program.
%
% option = 'interior-point' -> Select Interior-Point Algorithm for fmincon.
% Interior Point Algorithm has a slower convergence when compared to the
% Active-Set but it does respect the problem restrictions at each
% intermediate step of the optimization algorithm.
%
% option = 'Global' -> Will make use of the Global Optimization ToolBox.
% The algorithm chosen here is PatternSearch, since is the fastests among
% every Global Optimization Algorithms.
%
%Troubleshoot information is also made available by assigning the variable
%debug as follows:
%
% Debug = 1 -> Provide complete information about the optimization routine
% being executed.
% Debug = 2 -> Turn off diagonostics and provide limited information about the
% optimization routine being executed.
% Debug = 3 -> Disables the display of any information.

% delete(gcp)
% parpool('local')

opt.FunValCheck = 'on';
opt.DiffMinChange = 1e-3;
opt.DiffMaxChange = 2;
opt.Hessian = [];
opt.MaxFunEvals = 10000;
opt.MaxIter = 5*opt.MaxFunEvals;
opt.AlwaysHonorConstraints = 'bounds';
opt.RelLineSrchBnd = 10;
opt.RelLineSrchBndDuration = 100;
opt.InitTrustRegionRadius = 40;
% opt.UseParallel = true;
%opt.PlotFcns = 'optimplotfval';
%opt.PlotFcns = 'PlotCost';
%opt.PlotFcns = {'PlotCost', 'PlotX1','PlotX2','PlotX4'};
% opt.PlotFcns = {'PlotCost', 'PlotX1','PlotX2'};

if debug==1
    opt.Diagnostics = 'on';
    opt.Display = 'iter-detailed';
elseif debug==2
    opt.Diagnostics = 'off';
    opt.Display = 'iter';
else
    opt.Diagnostics = 'off';
    opt.Display = 'final';
end

if strcmp(option,'active-set')
    opt.Algorithm = 'active-set';
    opt.LargeScale = 'on';
    opt.TolFun = 1e-5;
    opt.TolX = 1e-4;
    opt.TolCon = 5e-5;
elseif strcmp(option,'interior-point')
    opt.Algorithm = 'interior-point';
%     opt.TolFun = 1e-4;
%     opt.TolX = 1e-4;
%     opt.TolCon = 5e-5;
    opt.TolFun = 1-6;
    opt.TolX = 1e-4;
    opt.TolCon = 1e-4;
elseif strcmp(option,'Global')
    opt.CompletePoll = 'on';
    opt.PollingOrder = 'Random';
    opt.CompleteSearch = 'on';
    opt.Display = 'iter';
    opt.TolMesh = 1e-3;
    opt.TolX = 1e-3;
    opt.TolCon = 5e-4;
    opt.SearchMethod = @searchga;
    opt.MaxFunEvals = 100000;
    opt.ScaleMesh = 'off';
    opt.InitialMeshSize = 1;
    opt.MaxMeshSize=3;
    opt.MeshExpansion = 1.5;
    opt.MeshContraction = 0.9;
    opt.PlotFcns = @psplotbestf;
else
    disp('Ivalid solver option, check your code')
end



