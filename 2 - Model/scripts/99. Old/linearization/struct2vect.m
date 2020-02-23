function x = struct2vect(structure)

names = fieldnames(structure);
x = [];
for i = 1:length(names)
    temp = ['structure.' char(names(i))];
    x =[x; eval(temp)];
end