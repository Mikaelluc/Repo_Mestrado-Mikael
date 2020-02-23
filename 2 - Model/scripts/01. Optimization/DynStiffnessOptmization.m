    
%
%                       Dynamic Stiffness Optimization
%
% Use variable DynStiffOptController in DynStiffOptInitialization.m to
% select the controller type.
% Use variable DynStiffOptCostFunction in DynStiffOptInitialization.m to
% select the cost function type.
%
% By Pedro Paula, November 2017.
%
global DynStiffOptCostFunction operationCancelled
%%%%%%%%%%%%%%%%%%%%%%%%%%    Initialization    %%%%%%%%%%%%%%%%%%%%%%%%%%%

DynStiffOpt_Initialization;

if operationCancelled == 1
    errordlg('Operation cancelled by the user.','Program aborted');
    clear all;
    return;
end

%%%%%%%%%%%%%%%%%%%%%%%%    Controller Selection    %%%%%%%%%%%%%%%%%%%%%%%

DynStiffOpt_ControllerSelection;

%%%%%%%%%%%%%%%%%%%%%%%%%%    InitialResults    %%%%%%%%%%%%%%%%%%%%%%%%%%%

DynStiffOpt_InitialDesignResponseTemp;

%%%%%%%%%%%%%%%%%%%%%%%%%%%    Optimization    %%%%%%%%%%%%%%%%%%%%%%%%%%%%

tic;
opt = SetOptimizationAlgorithm('interior-point',1);
switch DynStiffOptCostFunction
    case 0
        [xopt,fopt,flag,iter] = fmincon(@DynStiffnessOptmizationFunc,x0,[],[],[],[],lb,ub,@DynStiffnessOptmizationConstFunc,opt);
    case 1
        [xopt,fopt,flag,iter] = fmincon(@DynStiffnessOptmizationFunc,x0,[],[],[],[],lb,ub,[],opt);
    case 2
        [xopt,fopt,flag,iter] = fmincon(@DynStiffnessOptmizationFunc,x0,[],[],[],[],lb,ub,[],opt);
    otherwise
        error('DynStiffOptCostFunction is not a valid cost function code.');  
end
optimizationExecutionTime = toc;

%%%%%%%%%%%%%%%%%%%%%%%%%%%    Final Results    %%%%%%%%%%%%%%%%%%%%%%%%%%%

DynStiffOpt_FinalDesignResponseTemp;

%%%%%%%%%%%%%%%%%%%%%%%%%    Plot/Save Results    %%%%%%%%%%%%%%%%%%%%%%%%%

DynStiffOpt_PlotSaveResultsTemp;
DynStiffOpt_SaveOptimizationPerformance;

% %%
% close all;
% global DynStiffOptController
% DynStiffOptController = 0; %(P)
% load 'P Controller Optimization - Initial Design.mat'
% load 'P Controller Optimization - Optimized Design.mat'
% folder = 'results/1. Optimization/1. P/';
% 
% DynStiffOpt_PlotSaveResultsTemp;