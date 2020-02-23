%Clear workspace
clear;
clc;

%Get root project directory
ProjectDir = fileparts(mfilename('fullpath'));

addpath(fullfile(ProjectDir,'Library'),'-end');
addpath(fullfile(ProjectDir,'scripts'),'-end');
addpath(fullfile(ProjectDir,'scripts\00. Model'),'-end');
addpath(fullfile(ProjectDir,'scripts\01. Optimization'),'-end');
addpath(fullfile(ProjectDir,'scripts\02. Frequency Algorithm Investigation'),'-end');
addpath(fullfile(ProjectDir,'scripts\03. Dynamic Stiffness Algorithm Investigation'),'-end');
addpath(fullfile(ProjectDir,'scripts\04. Support'),'-end');
addpath(fullfile(ProjectDir,'scripts\05. Tests'),'-end');
% addpath(fullfile(ProjectDir,'scripts\99. Old'),'-end');
% addpath(fullfile(ProjectDir,'scripts\99. Old\linearization'),'-end');
% addpath(fullfile(ProjectDir,'scripts\99. Old\run_all'),'-end');
% addpath(fullfile(ProjectDir,'scripts\99. Old\plot'),'-end');
addpath(fullfile(ProjectDir,'models'),'-end');
addpath(fullfile(ProjectDir,'parameters'),'-end');
addpath(fullfile(ProjectDir,'results/1. Optimization'),'-end');
addpath(fullfile(ProjectDir,'results/4. Support'),'-end');
% addpath(fullfile(ProjectDir,'data'),'-end');

Simulink.fileGenControl('set', 'CacheFolder', fullfile(ProjectDir,'simul'), ...
    'CodeGenFolder', fullfile(ProjectDir,'simul'));
