

%load resultsFR.mat


Frequencies             = resultsFR.frequencies';
BaselineAlgTime         = resultsFR.timeBaseline';
ModifiedBaselineAlgTime = resultsFR.timeBaselineMod';
TimeDifference          = resultsFR.deltaTime';
Percentage              = resultsFR.deltaPerc';

T1 = table(Frequencies,BaselineAlgTime,ModifiedBaselineAlgTime,TimeDifference,Percentage);

TimeSumBaseline         = resultsFR.sumBaselineMin';
TimeSumBaselineMod      = resultsFR.sumBaselineModMin';
TimeDifference          = resultsFR.deltaTimeSumMin';
Percentage              = resultsFR.deltaPercSum';

T2 = table(TimeSumBaseline,TimeSumBaselineMod,TimeDifference,Percentage);
