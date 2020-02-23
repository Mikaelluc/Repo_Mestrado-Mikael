%Get root project directory
ProjectDir = fileparts(mfilename('fullpath'));

rmpath(fullfile(ProjectDir,'Library'),'-end');
rmpath(fullfile(ProjectDir,'scripts'),'-end');
rmpath(fullfile(ProjectDir,'scripts\linearization'),'-end');
rmpath(fullfile(ProjectDir,'scripts\run_all'),'-end');
rmpath(fullfile(ProjectDir,'scripts\plot'),'-end');
rmpath(fullfile(ProjectDir,'models'),'-end');
rmpath(fullfile(ProjectDir,'parameters'),'-end');

rmpath(fullfile(ProjectDir,'scripts\00. Model'),'-end');
rmpath(fullfile(ProjectDir,'scripts\01. Optimization'),'-end');
rmpath(fullfile(ProjectDir,'scripts\02. Frequency Algorithm Investigation'),'-end');
rmpath(fullfile(ProjectDir,'scripts\03. Dynamic Stiffness Algorithm Investigation'),'-end');
rmpath(fullfile(ProjectDir,'scripts\04. Support'),'-end');
rmpath(fullfile(ProjectDir,'scripts\05. Tests'),'-end');
rmpath(fullfile(ProjectDir,'results/1. Optimization'),'-end');
rmpath(fullfile(ProjectDir,'results/4. Support'),'-end');

Simulink.fileGenControl('reset');

%Clear workspace
clear;
clc;


