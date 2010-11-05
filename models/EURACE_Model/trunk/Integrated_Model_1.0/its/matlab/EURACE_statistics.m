clc
clear all
close all

Pat = 'C:\DATA\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\seed_';

seeds_grid = [1231:1235, 1237:1241];
qe = 0;
div = 0.9;

mf = 240;
m0 = 12;
nrdays = 20*mf;

fprintf('\n\n qe: %d \t div: %1.1f',qe,div)

s = 0;
for seme = seeds_grid
    s = s + 1;
    FileName = [Pat, num2str(seme), '\qe', num2str(qe), '_d', num2str(div), '\its\'];
      
    Data1 = load([FileName, 'eurostat2.txt']);
    Data2 = load([FileName, 'firms_capital_goods.txt']);
    Data3 = load([FileName, 'eurostat.txt']);
    Data4 = load([FileName, 'firms_pricing.txt']);
    Data41 = load([FileName, 'firms_goods_market.txt']);
   
    k = 0;
    for d=1:20:nrdays
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
    
    fprintf('\n seed: %d nr_days: %d',seme,max(Data1(:,1)));
    
    output(:,s) = CGPs_production(:,s) + capital_goods_investment(:,s);
    
    % Output variation
    tt1 = 0;
    for t01=12:61
        tt1 = tt1 + 1;
        output_tmp1 = output(t01:t01+59,s);
        output_tmp1_max(tt1) = max(output_tmp1);
        output_tmp1_min(tt1) = min(output_tmp1);
        output_tmp1_variation(tt1) = (output_tmp1_max(tt1)-output_tmp1_min(tt1))./(output_tmp1_min(tt1)+output_tmp1_max(tt1));
        clear output_tmp1
    end
    output_tmp1_variation_max(s) = mean(output_tmp1_variation);

    tt1 = 0;
    % Output drop
    for t01=12:61
        tt1 = tt1 + 1;
        output_drop1 = (output(t01,s) - output(t01+1:t01+59,s))./output(t01,s);
        output_drop1_max_tmp(tt1) = min(output_drop1);
        clear output_drop1
    end
    output_drop1_max(s) = mean(output_drop1_max_tmp);

    
    tt2 = 0;
    for t02=121:181
        tt2 = tt2 + 1;
        output_tmp2 = output(t02:t02+59,s);
        output_tmp2_max(tt2) = max(output_tmp2);
        output_tmp2_min(tt2) = min(output_tmp2);
        output_tmp2_variation(tt2) = (output_tmp2_max(tt2)-output_tmp2_min(tt2))./(output_tmp2_min(tt2)+output_tmp2_max(tt2));
        clear output_tmp2
    end
    output_tmp2_variation_max(s) = mean(output_tmp2_variation);
    
    tt2 = 0;
    % Output drop
    for t02=121:181
        tt2 = tt2 + 1;
        output_drop2 = (output(t02,s) - output(t02+1:t02+59,s))./output(t02,s);
        output_drop2_max_tmp(tt2) = min(output_drop2);
        clear output_drop2
    end
    output_drop2_max(s) = mean(output_drop2_max_tmp);
    
    tt3 = 0;
    for t03=1:181
        tt3 = tt3 + 1;
        output_tmp3 = output(t03:t03+59,s);
        output_tmp3_max(tt3) = max(output_tmp3);
        output_tmp3_min(tt3) = min(output_tmp3);
        output_tmp3_variation(tt3) = (output_tmp3_max(tt3)-output_tmp3_min(tt3))./(output_tmp3_min(tt3)+output_tmp3_max(tt3));
        clear output_tmp3
    end
    output_tmp3_variation_max(s) = mean(output_tmp3_variation);
    
    tt3 = 0;
    % Output drop
    for t03=1:181
        tt3 = tt3 + 1;
        output_drop3 = (output(t03,s) - output(t03+1:t03+59,s))./output(t03,s);
        output_drop3_max_tmp(tt3) = min(output_drop3);
        clear output_drop3
    end
    output_drop3_max(s) = mean(output_drop3_max_tmp);

    
    K_gwt(s) = mean(diff(log(total_units_capital_stock(m0:mf,s))));
    I(s) = mean(capital_goods_investment(m0:mf,s));
    GDP_ret = diff(log(output(m0:mf,s)));
    GDP_gwt(s) = mean(GDP_ret);
    
    wage(:,s) = Data3(12:mf,7);
    wage_inflation(s) = mean(diff(log(wage(:,s))));
    
    
    unemployment(s) = mean(Data3(12:mf,6)); 
    
    fprintf('K_gwt: %f I: %f GDP_gwt: %f U: %f',100*K_gwt(s),I(s),100*GDP_gwt(s),unemployment(s))
    
    Data5 = load([FileName, 'banks_daily_balance_sheet.txt']);
    Data6 = load([FileName, 'CentralBank_daily_balance_sheet.txt']);
    FIAT_MONEY_BANKS(1:nrdays,s) = Data6(1:nrdays,3);

    days = unique(Data5(:,1));

    for i=1:numel(days)
        
        days_idx = find(Data5(:,1)==i);
        DEPOSITS_sum(i,s) = sum(Data5(days_idx,7));
        EQUITY_sum(i,s) = sum(Data5(days_idx,9));

        clear days_idx
        
    end
    
    MONEY_PRIVATE_SECTOR(1:nrdays,s) = DEPOSITS_sum(1:nrdays,s) + EQUITY_sum(1:nrdays,s) + FIAT_MONEY_BANKS(1:nrdays,s);
    
    k = 0;
    for d=1:20:nrdays
        k = k + 1;
        MONEY_PRIVATE_SECTOR_monthly(k,s) = sum(MONEY_PRIVATE_SECTOR(d:d+19,s));
    end
 
    MONEY_PRIVATE_SECTOR_monthly_ret = diff(log(MONEY_PRIVATE_SECTOR_monthly(m0:mf,s)));
    M_gwt(s) = mean(MONEY_PRIVATE_SECTOR_monthly_ret);
    
    p_index_ret = diff(log(p_index(m0:mf,s)));
    CPI(s)  = mean(p_index_ret); 
    
    fprintf('\n\t M_gwt: %f CPI: %f wage inf: %f',100*M_gwt(s),100*CPI(s),100*wage_inflation(s))
    
    X_tmp = crosscorr(MONEY_PRIVATE_SECTOR_monthly_ret,p_index_ret);
    X_M_p(:,s) = X_tmp(20:22);
    clear X_tmp
    
    X_tmp = crosscorr(MONEY_PRIVATE_SECTOR_monthly_ret,GDP_ret);
    X_M_GDP(:,s) = X_tmp(20:22);
    clear X_tmp
    
    fprintf('\n\t GDP variation. 1st Period: %f 2nd Period: %f total: %f',...
        100*output_tmp1_variation_max(s),100*output_tmp2_variation_max(s),100*output_tmp3_variation_max(s))
    fprintf('\n\t GDP drop. 1st Period: %f 2nd Period: %f total: %f',...
        100*output_drop1_max(s),100*output_drop2_max(s),100*output_drop3_max(s))
    fprintf('\n\t X_M_p: %f %f %f',X_M_p(1,s),X_M_p(2,s),X_M_p(3,s))
    fprintf('\n\t X_M_GDP: %f %f %f',X_M_GDP(1,s),X_M_GDP(2,s),X_M_GDP(3,s))

    clear Data1 Data2 Data3 Data4 Data5 Data6
    clear GDP_ret p_index_ret MONEY_PRIVATE_SECTOR_monthly_ret
end

K_gwt_m = mean(K_gwt);
I_m = mean(I);
GDP_gwt_m = mean(GDP_gwt);
unemployment_m = mean(unemployment);
M_gwt_m = mean(M_gwt);
CPI_m = mean(CPI);
wage_inflation_m = mean(wage_inflation);
GDP_max_variation1_mean = mean(output_tmp1_variation_max);
GDP_max_variation2_mean = mean(output_tmp2_variation_max);
GDP_max_variation3_mean = mean(output_tmp3_variation_max);
output_drop1_max_mean = mean(output_drop1_max);
output_drop2_max_mean = mean(output_drop2_max);
output_drop3_max_mean = mean(output_drop3_max);
X_M_p_mean = mean(X_M_p,2);
X_M_GDP_mean = mean(X_M_GDP,2);

K_gwt_se = std(K_gwt)/sqrt(s);
I_se = std(I)/sqrt(s);
GDP_gwt_se = std(GDP_gwt)/sqrt(s);
unemployment_se= std(unemployment)/sqrt(s);
M_gwt_se = std(M_gwt)/sqrt(s);
CPI_se = std(CPI)/sqrt(s);
wage_inflation_se = std(wage_inflation)/sqrt(s);
GDP_max_variation1_se = std(output_tmp1_variation_max)/sqrt(s);
GDP_max_variation2_se = std(output_tmp2_variation_max)/sqrt(s);
GDP_max_variation3_se = std(output_tmp3_variation_max)/sqrt(s);
output_drop1_max_se = std(output_drop1_max)/sqrt(s);
output_drop2_max_se = std(output_drop2_max)/sqrt(s);
output_drop3_max_se = std(output_drop3_max)/sqrt(s);
X_M_p_se = std(X_M_p,[],2)/sqrt(s);
X_M_GDP_se = std(X_M_GDP,[],2)/sqrt(s);


fprintf('\n\n qe: %d \t div: %1.1f averages:',qe,div)
fprintf('\n\t K_gwt: %f (%f) I: %f (%f) GDP_gwt: %f (%f) U: %f (%f)',100*K_gwt_m,100*K_gwt_se,I_m,I_se,100*GDP_gwt_m,100*GDP_gwt_se,unemployment_m,unemployment_se)
fprintf('\n\t M_gwt: %f (%f) CPI: %f (%f) wage inf: %f (%f)',100*M_gwt_m,100*M_gwt_se,100*CPI_m,100*CPI_se,...
    100*wage_inflation_m,100*wage_inflation_se)    
fprintf('\n GDP max variation. 1st Period: %f (%f) 2nd Period: %f (%f) total: %f (%f)',...
    GDP_max_variation1_mean,GDP_max_variation1_se,GDP_max_variation2_mean,GDP_max_variation2_se,GDP_max_variation3_mean,GDP_max_variation3_se) 
fprintf('\n GDP max drop. 1st Period: %f (%f) 2nd Period: %f (%f) total: %f (%f)',...
    100*output_drop1_max_mean,100*output_drop1_max_se,100*output_drop2_max_mean,100*output_drop2_max_se,...
    100*output_drop3_max_mean,100*output_drop3_max_se) 
fprintf('\n (Lag -1) X_M_p: %f (%f) X_M_GDP: %f (%f)',X_M_p_mean(1),X_M_p_se(1),X_M_GDP_mean(1),X_M_GDP_se(1)) 
fprintf('\n (Lag 0) X_M_p: %f (%f) X_M_GDP: %f (%f)',X_M_p_mean(2),X_M_p_se(2),X_M_GDP_mean(2),X_M_GDP_se(2)) 
fprintf('\n (Lag 1) X_M_p: %f (%f) X_M_GDP: %f (%f)',X_M_p_mean(3),X_M_p_se(3),X_M_GDP_mean(3),X_M_GDP_se(3)) 

% x1(1) = 0;
% for t=2:1000
%     x1(t) = 0.5*x1(t-1) + randn;
% end
% 
% x2(1) = 0;
% for t=3:1000
%     x2(t) = 0.5*x1(t-2) - 0.3*x1(t-1)+ randn;
% end
% 
% figure(11); crosscorr(x1,x2)
