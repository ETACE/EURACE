clc
clear all
%close all

Pat = 'E:\research\Conferences\Artificial Economics 2011 - The Hague\data\seed';

seeds_grid = [1234:1237];
nrseeds = numel(seeds_grid);
qe = 0;
alfa = 5;

m0 = 1;  %181
mf = 180;  % 360

day_0 = 1+20*(m0-1);
day_f = 20*mf;

fprintf('\n\n qe: %d \t alfa: %1.1f TIME AVERAGES',qe,alfa)

s = 0;
for seme = seeds_grid
    s = s + 1;
    FileName = [Pat, num2str(seme), 'bis\alfa_', num2str(alfa), '\its\'];
      
    Data1 = load([FileName, 'eurostat2.txt']);
    Data2 = load([FileName, 'firms_capital_goods.txt']);
    Data3 = load([FileName, 'eurostat.txt']);
    Data4 = load([FileName, 'firms_pricing.txt']);
    Data41 = load([FileName, 'firms_goods_market.txt']);
   
    k = 0;
    for d=day_0:20:day_f
        k = k + 1;
        Idx2 = find((Data2(:,1)>=d)&(Data2(:,1)<(d+20)));
        Idx4 = find((Data4(:,1)>=d)&(Data4(:,1)<(d+20)));

        total_units_capital_stock(k,s) = sum(Data2(Idx2,3));
        capital_goods_investment(k,s) = sum(Data2(Idx2,4));
        CGPs_production(k,s) = sum(Data4(Idx4,6));
        
        Idx41 = find((Data41(:,1)>=d)&(Data41(:,1)<(d+20)));
        Idx_q_sold = find(Data41(Idx41,3));
        q_sold = Data41(Idx41(Idx_q_sold),3);
        p_sold = Data41(Idx41(Idx_q_sold),4);
   
        q_sold_tot(k) = sum(q_sold);
        p_index(k,s) = sum(q_sold.*p_sold)/q_sold_tot(k);
    
        clear Idx2 Idx4 Idx41 q_sold p_sold
        
    end
    
    fprintf('\n\t seed: %d day_0: %d day_f: %d',seme,day_0,day_f);
    
    output(:,s) = CGPs_production(:,s) + capital_goods_investment(:,s);
 
    
    K_mt(s) = mean(total_units_capital_stock(:,s));
    GDP_mt(s) = mean(output(:,s));

        
    unemployment_mt(s) = mean(Data3(m0:mf,6)); 
    fprintf('\n\t\t K_mt: %f GDP_mt: %f U: %f',K_mt(s),GDP_mt(s),unemployment_mt(s))


    %%%%%%%%%%%% Wage and price level
    wage(:,s) = Data3(m0:mf,7);
    wage_mt(s) = mean(wage(:,s));
    p_index_mt(s) = mean(p_index(:,s));
    
    fprintf('\n\t\t wage_mt: %f p_index_mt: %f',wage_mt(s),p_index_mt(s))
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    
    %%%%%%%%%%% Bank equity and total credit
    Data5 = load([FileName, 'banks_daily_balance_sheet.txt']);
    
    for i=day_0:day_f
         
         days_idx = find(Data5(:,1)==i);
         TOTAL_CREDIT(i,s) = sum(Data5(days_idx,5));
         EQUITY(i,s) = sum(Data5(days_idx,9));
 
         clear days_idx
         
    end
    
    TOTAL_CREDIT_mt(s,1) = mean(TOTAL_CREDIT(:,s));
    EQUITY_mt(s,1) = mean(EQUITY(:,s));
    
    fprintf('\n\t\t TOTAL_CREDIT_mt: %f EQUITY_mt: %f',TOTAL_CREDIT_mt(s),EQUITY_mt(s))
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
end


fprintf('\n\n qe: %d \t alfa: %1.1f ENSEMBLE AVERAGES',qe,alfa)

K_me = mean(K_mt);  K_se = std(K_mt)/sqrt(nrseeds);
GDP_me = mean(GDP_mt); GDP_se = std(GDP_mt)/sqrt(nrseeds);
unemployment_me = mean(unemployment_mt);   unemployment_se = std(unemployment_mt)/sqrt(nrseeds);
p_index_me = mean(p_index_mt);  p_index_se = std(p_index_mt)/sqrt(nrseeds);
wage_me = mean(wage_mt);  wage_se = std(wage_mt)/sqrt(nrseeds);
TOTAL_CREDIT_me = mean(TOTAL_CREDIT_mt);  TOTAL_CREDIT_se = std(TOTAL_CREDIT_mt)/sqrt(nrseeds);
EQUITY_me = mean(EQUITY_mt);  EQUITY_se = std(EQUITY_mt)/sqrt(nrseeds);

fprintf('\n\t K_me: %f (%f) GDP_me: %f (%f) unemployment_me: %f (%f)',K_me,K_se,GDP_me,GDP_se,unemployment_me,unemployment_se)
fprintf('\n\t wage_me: %f (%f) p_index_me: %f (%f)',wage_me,wage_se,p_index_me,p_index_se)
fprintf('\n\t TOTAL_CREDIT_me: %f (%f) EQUITY_me: %f (%f)',TOTAL_CREDIT_me,TOTAL_CREDIT_se,EQUITY_me,EQUITY_se)


