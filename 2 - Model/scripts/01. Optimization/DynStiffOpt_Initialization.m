

clear all;
clc;

% Load the parameters of the rudder actuation system simulink model
run('PH_Load_Parameters');

global DynStiffOptController DynStiffOptCostFunction operationCancelled

window_title = 'Controller Selection';
prompt = sprintf(['Enter desired controller to be optimized according to the following code.\n\n',...
                  '0 - Proportional Controller (P)\n',...
                  '1 - Proportional Integrative Controller (PI)\n',...
                  '2 - Proportional Derivative Controller (PD)\n',...
                  '3 - Proportional Integrative Derivative Controller (PID)\n',...
                  '4 - Full State Feedback Controller (FSFC)\n',...
                  '5 - Partial State Feedback Controller (PSFC)\n']);
% DynStiffOptController = 2;
DynStiffOptController = inputdlg(prompt,window_title);
if isempty(DynStiffOptController)
    operationCancelled = 1;
    return;
end
DynStiffOptController = str2double(DynStiffOptController{1});

prompt = sprintf(['Enter desired cost function.\n\n',...
                  '0 - Simple Cost Function \n',...
                  '1 - Weighted Cost Function \n',...
                  '2 - Second Weighted Cost Function \n']);
DynStiffOptCostFunction = inputdlg(prompt,window_title);
if isempty(DynStiffOptCostFunction)
    operationCancelled = 1;
    return;
end
DynStiffOptCostFunction = str2double(DynStiffOptCostFunction{1});

switch DynStiffOptCostFunction
    case 0
        root = 'results/1. Optimization/1. Simple Cost Function/';
    case 1
        root = 'results/1. Optimization/2. Weighted Cost Function/';
    case 2
        root = 'results/1. Optimization/3. Second Weighted Cost Function/';
    otherwise
        error('DynStiffOptCostFunction is not a valid cost function code.');  
end

% Specify folder address to save files
switch DynStiffOptController
    case 0
        folder = [ root '1. P/'];
        workspace_filename = 'P Controller Optimization';        
    case 1
        folder = [ root '2. PI/'];
        workspace_filename = 'PI Controller Optimization';
    case 2
        folder = [ root '3. PD/'];
        workspace_filename = 'PD Controller Optimization';
    case 3
        folder = [ root '4. PID/'];
        workspace_filename = 'PID Controller Optimization';
    case 4
        folder = [ root '5. FSFC/'];
        workspace_filename = 'Full State Feedback Controller Optimization';
    case 5
        folder = [ root '6. PSFC/'];
        workspace_filename = 'Partial State Feedback Controller Optimization';
    otherwise
        error('DynStiffOptController is not a valid controller code.');        
end

% Start recording of MATLAB command history

currentDate = datestr(date,29);
diary([ folder currentDate ' - Diary - ' workspace_filename '.txt' ]);
diary on

disp(['Algoritmo de maximização de rigidez dinâmica através da otimização dos ganhos de um controlador. Workspace após simulação salvo como ' workspace_filename '.']);
