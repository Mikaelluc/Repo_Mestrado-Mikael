

%load resultsFR.mat

% load('results/3. Dynamic Stiffness Algorithm/Time Evaluation/baselineResponse.mat');
% load('results/3. Dynamic Stiffness Algorithm/Time Evaluation/modifiedResponse.mat');

resultsDS.frequencies       = baselineResponse.fr;
resultsDS.timeBaseline      = baselineResponse.time_freq;
resultsDS.timeBaselineMod   = modifiedResponse.time_freq;
resultsDS.deltaTime         = modifiedResponse.time_freq - baselineResponse.time_freq;
resultsDS.deltaPerc         = (modifiedResponse.time_freq - baselineResponse.time_freq)./baselineResponse.time_freq;

Frequencies             = resultsDS.frequencies';
BaselineAlgTime         = resultsDS.timeBaseline';
ModifiedBaselineAlgTime = resultsDS.timeBaselineMod';
TimeDifference          = resultsDS.deltaTime';
Percentage              = resultsDS.deltaPerc';

T1 = table(Frequencies,BaselineAlgTime,ModifiedBaselineAlgTime,TimeDifference,Percentage);

resultsDS.sumBaselineMin    = sum(baselineResponse.time_freq)/60;
resultsDS.sumBaselineModMin = sum(modifiedResponse.time_freq)/60;
resultsDS.deltaTimeSumMin   = sum(modifiedResponse.time_freq)/60 - sum(baselineResponse.time_freq)/60;
resultsDS.deltaPercSum      = (sum(modifiedResponse.time_freq) - sum(baselineResponse.time_freq))./sum(baselineResponse.time_freq);

TimeSumBaseline         = resultsDS.sumBaselineMin';
TimeSumBaselineMod      = resultsDS.sumBaselineModMin';
TimeDifference          = resultsDS.deltaTimeSumMin';
Percentage              = resultsDS.deltaPercSum';

T2 = table(TimeSumBaseline,TimeSumBaselineMod,TimeDifference,Percentage);

T1
T2