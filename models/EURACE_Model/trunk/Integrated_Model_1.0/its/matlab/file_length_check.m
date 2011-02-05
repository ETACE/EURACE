clc
clear all
close all

Pat = 'C:\DATA\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\seed_';

seeds_grid = [1231:1235, 1237:1241];
qe = 1;
div = 0.6;

mf = 240;
m0 = 12;
nrdays = 20*mf;

fprintf('\n\n qe: %d \t div: %1.1f',qe,div)

s = 0;

for seme = seeds_grid
    s = s + 1;
    FileName = [Pat, num2str(seme), '\qe', num2str(qe), '_d', num2str(div), '\its\'];
      
    Data = load([FileName, 'eurostat2.txt']);
    NrRows = size(Data,1);
    
    fprintf('\n NrRows: %d',NrRows)
    
end