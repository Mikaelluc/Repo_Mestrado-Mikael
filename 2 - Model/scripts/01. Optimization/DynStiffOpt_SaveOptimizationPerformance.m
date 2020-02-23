
% Save Optimization Performance Results

OptimizationResults.xopt = xopt;
OptimizationResults.fopt = fopt;
OptimizationResults.flag = flag;
OptimizationResults.iter = iter;
OptimizationResults.ExecutionTime = optimizationExecutionTime;
OptimizationResults.Jf = OptimizedDesign.Temp100.StiffnessResponse.Jf;
OptimizationResults.Jf_WeightedCF = OptimizedDesign.Temp100.StiffnessResponse.Jf_WeightedCF;

save([ folder currentDate ' - ' workspace_filename ' - OptimizationResults.mat' ],'OptimizationResults');

diary([ folder currentDate ' - ' 'Partial Cost Function Table.txt' ]);
diary on
%
OptimizedDesign.Temp100.StiffnessResponse.fr(18) = 0;
OptimizedDesign.Temp100.StiffnessResponse.Jf(18) = 0;

for i=1:6    
    disp([ '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.fr(i),3) '$ & '...
           '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.Jf(i),3) '$ & '...
           '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.fr(6+i),3) '$ & '...
           '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.Jf(6+i),3) '$ & '...
           '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.fr(12+i),3) '$ & '...
           '$' num2str(OptimizedDesign.Temp100.StiffnessResponse.Jf(12+i),3) '$ \\ \hline']);
end

disp(' '); disp(' '); disp(' ');

disp([ 'Optimization Execution Time (h) & ' num2str(optimizationExecutionTime/3600) ' \\ \hline' ]);
disp([ 'Number of Iterations & ' num2str(iter.iterations) ' \\ \hline' ]);
disp([ 'Number of Obj. Function Evaluations & ' num2str(iter.funcCount) ' \\ \hline' ]);

disp(' '); disp(' '); disp(' ');

plotTable;

diary off