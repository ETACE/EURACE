clc
clear all
close all

Pat = 'E:\research\Conferences\Artificial Economics 2011 - The Hague\data\seed_';

seeds_grid = [1236:1237];
qe = 0;
alfa = 10;

fprintf('\n\n qe: %d \t alfa: %1.1f',qe,alfa)

s = 0;

for seme = seeds_grid
    s = s + 1;
    FileName = [Pat, num2str(seme), '\qe', num2str(qe), '_alfa', num2str(alfa), '\its\'];
      
    Data = load([FileName, 'eurostat2.txt']);
    NrRows = size(Data,1);
    
    fprintf('\n seed: %d NrRows: %d',seme,NrRows)
    
end