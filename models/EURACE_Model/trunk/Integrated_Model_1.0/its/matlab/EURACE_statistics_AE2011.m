clc
clear all
close all

Pat = 'E:\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\seed_';

seeds_grid = [1228:1230, 1250:1254];
nrseeds = numel(seeds_grid);
qe = 0;
alfa = 8;

m0 = 241;  %181
mf = 480;  % 360

day_0 = 1+20*(m0-1);
day_f = 20*mf;

fprintf('\n\n qe: %d \t alfa: %1.1f TIME AVERAGES',qe,alfa)

s = 0;
for seme = seeds_grid
    s = s + 1;
    FileName = [Pat, num2str(seme), '\qe0_alfa', num2str(alfa), '\its\'];
      
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
    
    output_PV(:,s) = diff(output(:,s))./output(1:end-1,s);
    GDP_PV_mt(s) = mean(output_PV(:,s));
    
    fprintf('\n\t\t K_mt: %f GDP_mt: %f U: %f',K_mt(s),GDP_mt(s),unemployment_mt(s))
    fprintf(' GDP_PV_mt: %f',GDP_PV_mt(s))


    %%%%%%%%%%%% Wage and price level
    wage(:,s) = Data3(m0:mf,7);
    wage_mt(s) = mean(wage(:,s));
    p_index_mt(s) = mean(p_index(:,s));

    inflation(:,s) = diff(p_index(:,s))./p_index(1:end-1,s);
    
    fprintf('\n\t\t wage_mt: %f p_index_mt: %f',wage_mt(s),p_index_mt(s))
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
    
    %%%%%%%%%%% Bank equity and total credit
    Data5 = load([FileName, 'banks_daily_balance_sheet.txt']);
    
    for i=day_0:day_f
         
         days_idx = find(Data5(:,1)==i);
         TOTAL_CREDIT(i-day_0+1,s) = sum(Data5(days_idx,5));
         EQUITY(i-day_0+1,s) = sum(Data5(days_idx,9));
 
         clear days_idx
         
    end

    m_index = 0;
    for mm=m0:mf
        m_index = m_index + 1;
        m_index0 = 20*(mm-m0)+1;
        m_indexf = 20*(mm-m0)+20;
        TOTAL_CREDIT_MONTHLY(m_index,s) = mean(TOTAL_CREDIT(m_index0:m_indexf,s));
    end
    
    TOTAL_CREDIT_mt(s,1) = mean(TOTAL_CREDIT(:,s));
    EQUITY_mt(s,1) = mean(EQUITY(:,s));
    
    
    TOTAL_CREDIT_MONTHLY_PV(:,s) = diff(TOTAL_CREDIT_MONTHLY(:,s))./TOTAL_CREDIT_MONTHLY(1:end-1,s);
    TOTAL_CREDIT_MONTHLY_PV_mt(s) = mean(TOTAL_CREDIT_MONTHLY_PV(:,s));
    
    fprintf('\n\t\t TOTAL_CREDIT_mt: %f EQUITY_mt: %f',TOTAL_CREDIT_mt(s),EQUITY_mt(s))
    fprintf(' TOTAL_CREDIT_MONTHLY_PV_mt: %f',TOTAL_CREDIT_MONTHLY_PV_mt(s))
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    
end


fprintf('\n\n qe: %d \t alfa: %1.1f ENSEMBLE AVERAGES',qe,alfa)

fprintf('\n\t day_0: %d day_f: %d',day_0,day_f);
   
K_me = mean(K_mt);  K_std = std(K_mt);
GDP_me = mean(GDP_mt); GDP_std = std(GDP_mt);
unemployment_me = mean(unemployment_mt);   unemployment_std = std(unemployment_mt);
p_index_me = mean(p_index_mt);  p_index_std = std(p_index_mt);
wage_me = mean(wage_mt);  wage_std = std(wage_mt);
TOTAL_CREDIT_me = mean(TOTAL_CREDIT_mt);  TOTAL_CREDIT_std = std(TOTAL_CREDIT_mt);
EQUITY_me = mean(EQUITY_mt);  EQUITY_std = std(EQUITY_mt);

fprintf('\n\t K_me: %f (%f) GDP_me: %f (%f) unemployment_me: %f (%f)',K_me,K_std,GDP_me,GDP_std,unemployment_me,unemployment_std)
fprintf('\n\t wage_me: %f (%f) p_index_me: %f (%f)',wage_me,wage_std,p_index_me,p_index_std)
fprintf('\n\t TOTAL_CREDIT_me: %f (%f) EQUITY_me: %f (%f)',TOTAL_CREDIT_me,TOTAL_CREDIT_std,EQUITY_me,EQUITY_std)


