clc
clear all
%close all

%Pat = '..\qe1_d0.6_es0_r10\its\';
Pat = 'E:\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\seed_1234\qe1_d0.9\its\';
%Pat = '..\';

font_sz = 11;
colore = 'k';

mf = 120;
af = ceil(mf/12);
tf = 20*mf;
daily_month_index = (1:tf)/20;
monthly_month_index = 1:mf;
yearly_month_index = (1:af)*12;
monthly_index = 0:12:mf; 
monthly_index2 = 0:36:mf; 
yearly_index  = 0:af

%%% BANKS

Data = load([Pat, 'banks_daily_balance_sheet.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
%agent_id_data_ids = find(Data(:,2)==agent_id);

print_flag = 1;

FIRM_LOAN_ISSUES = Data(:,3);
FIRM_LOAN_INSTALLMENTS = Data(:,4);
TOTAL_CREDIT = Data(:,5);
PAYMENT_ACCOUNT_BANKS = Data(:,6);
DEPOSITS = Data(:,7);
ECB_DEBT = Data(:,8);
EQUITY = Data(:,9);

%PROFITS = Data(:,10);

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    FIRM_LOAN_ISSUES_sum(i) = sum(FIRM_LOAN_ISSUES(days_idx));
    FIRM_LOAN_INSTALLMENTS_sum(i) = sum(FIRM_LOAN_INSTALLMENTS(days_idx));
    TOTAL_CREDIT_sum(i) = sum(TOTAL_CREDIT(days_idx));
    PAYMENT_ACCOUNT_BANKS_sum(i) = sum(PAYMENT_ACCOUNT_BANKS(days_idx));
    DEPOSITS_sum(i) = sum(DEPOSITS(days_idx));
    ECB_DEBT_sum(i) = sum(ECB_DEBT(days_idx));
    EQUITY_sum(i) = sum(EQUITY(days_idx));
 %   PROFITS_sum(i) = sum(PROFITS(days_idx));
    
    clear days_idx
    
end

%h_Bank_aggregate_data =  figure('Name','Bank aggregate data'); 

%%% FIGURE: Bank aggregate data %%%
figure(1)
set(gcf,'Name','Bank aggregate data')
subplot(2,2,1); grid on; hold on; box
plot(daily_month_index,TOTAL_CREDIT_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('loans to firms','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,2); grid on; hold on; box
plot(daily_month_index,PAYMENT_ACCOUNT_BANKS_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('reserves at the CB','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,3); grid on; hold on; box
plot(daily_month_index,DEPOSITS_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('private sector deposits','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,4); grid on; hold on; box
plot(daily_month_index,ECB_DEBT_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('loans from the the CB','fontsize',font_sz)
xlabel('months','fontsize',font_sz)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% FIGURE: Bank aggregate equity %%%
figure(2); grid on; hold on; box
set(gcf,'Name','Bank aggregate equity')
plot(daily_month_index,EQUITY_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
xlabel('months','fontsize',font_sz)
title('Bank aggregate equity','fontsize',font_sz)

clear Data
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


%%% Central Bank
Data = load([Pat, 'CentralBank_daily_balance_sheet.txt']);

FIAT_MONEY_GOVS = Data(:,2);
FIAT_MONEY_BANKS = Data(:,3);
FIAT_MONEY = Data(:,4);
PAYMENT_ACCOUNT_CB = Data(:,5);
ECB_DEPOSITS = Data(:,6);

%%% FIGURE: Central bank data %%%
figure(11); 
set(gcf,'Name','Central bank data')
subplot(2,2,1); grid on; hold on; box
plot(daily_month_index,FIAT_MONEY_GOVS(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('Fiat money to the government','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,2); grid on; hold on; box
plot(daily_month_index,FIAT_MONEY_BANKS(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('Fiat money to banks','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,3); grid on; hold on; box
plot(daily_month_index,PAYMENT_ACCOUNT_CB(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('CB reserves','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,4); grid on; hold on; box
plot(daily_month_index,ECB_DEPOSITS(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('banks + gov deposits at CB','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

clear Data
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%% Government
Data = load([Pat, 'Governments_daily_balance_sheet.txt']);

days = unique(Data(:,1));

PAYMENT_ACCOUNT_GOVS = Data(:,3);
BONDS_NR_OUTSTANDING = Data(:,4);
BOND_QUANTITY = Data(:,5);
BOND_PRICE = Data(:,6);

for i=1:numel(days)
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_GOVS_sum(i) = sum(PAYMENT_ACCOUNT_GOVS(days_idx));
    BONDS_NR_OUTSTANDING_sum(i) = sum(BONDS_NR_OUTSTANDING(days_idx));
end

%%% FIGURE: Government data %%%
figure(31); 
set(gcf,'Name','Government data')
subplot(2,2,1); grid on; hold on; box
plot(daily_month_index,PAYMENT_ACCOUNT_GOVS_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('Government liquidity','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,2); grid on; hold on; box
plot(daily_month_index,BONDS_NR_OUTSTANDING_sum(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('Nr bonds outstanding','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,3); grid on; hold on; box
plot(daily_month_index,BOND_QUANTITY(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('Bonds new issues','fontsize',font_sz)
xlabel('months','fontsize',font_sz)

subplot(2,2,4); grid on; hold on; box
plot(daily_month_index,BOND_PRICE(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
set(gca,'xlim',[0, mf])
title('bond price','fontsize',font_sz)
xlabel('months','fontsize',font_sz)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Firm bankruptcies

if exist([Pat, '\firms_bankruptcies.txt'])==2
    
    Data = load([Pat, 'firms_bankruptcies.txt']);
    Bankruptcies_nr = zeros(size(Data,1),1);
    Bankruptcies_nr_tmp = 0;

    for i=1:size(Data,1)
        if Data(i,6)<0
            Bankruptcies_nr_tmp = Bankruptcies_nr_tmp + 1;
        else
            Bankruptcies_nr_tmp = Bankruptcies_nr_tmp - 1;
        end
        Bankruptcies_nr(i) = Bankruptcies_nr_tmp;
        Bankruptcies_times(i) = Data(i,1);
    end

    figure(41); hold on; grid; box on
    set(gcf,'Name','Bankruptcies')
    stairs(Bankruptcies_times/20,Bankruptcies_nr,colore)
    set(gca,'xtick',monthly_index,'fontsize',font_sz)
    xlabel('months','fontsize',font_sz)
    ylabel('Nr firms in bankruptcy','fontsize',font_sz)
    set(gca,'xlim',[0, mf]) 
    clear Data
else
    fprintf('\r\r No bankruptcy file found')
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% figure(1000); hold on; grid on; box on
% plot(ECB_DEPOSITS(i:tf)'-(PAYMENT_ACCOUNT_GOVS_sum(i:tf)+PAYMENT_ACCOUNT_BANKS_sum(i:tf)))
% legend('ECB DEPOSITS - Aggregate PAYMENT ACCOUNT GOVS - PAYMENT ACCOUNT BANKS',0)

clear Data


%%% Households

% Data = load([Pat, 'households_daily_income_statement.txt']);
% 
% PAYMENT_ACCOUNT_HOUSEHOLDS = Data(:,7);
% 
% days = unique(Data(:,1));
% agents_ids = unique(Data(:,2));
% 
% for i=1:numel(days)
%     
%     days_idx = find(Data(:,1)==i);
%     PAYMENT_ACCOUNT_HOUSEHOLDS_sum(i) = sum(PAYMENT_ACCOUNT_HOUSEHOLDS(days_idx));
%     
%     clear days_idx
%     
% end
% 
% clear Data

%%% IGFirm
Data = load([Pat, 'IGFirm_daily_balance_sheet.txt']);
set(gcf,'Name','Central bank data')

PAYMENT_ACCOUNT_IGFIRMS = Data(:,3);
CUM_ENERGY_COSTS = Data(:,4);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_IGFIRMS_sum(i) = sum(PAYMENT_ACCOUNT_IGFIRMS(days_idx));
    CUM_ENERGY_COSTS_sum(i) = sum(CUM_ENERGY_COSTS(days_idx));
    
    clear days_idx
    
end

clear Data

% figure(51); 
% subplot(2,1,1); hold on; grid on; box on
% plot(PAYMENT_ACCOUNT_IGFIRMS_sum(1:tf),colore)
% 
% xlabel('months','fontsize',font_sz)
% ylabel('arbitrary monetary units','fontsize',font_sz)
% title('PAYMENT ACCOUNT IGFIRM')
% 
% subplot(2,1,2); hold on; grid on; box on
% plot(CUM_ENERGY_COSTS_sum(1:tf),colore)
% xlabel('days','fontsize',font_sz)
% title('CUMULATED ENERGY COST')
% 
% break 
%%% Stock prices
Data = load([Pat, 'stock_prices.txt']);
firms_id = Data(:,2);
firms_nr = numel(unique(firms_id));
days = unique(Data(:,1));
%prices = zeros(numel(days),firms_nr);


figure(62); hold on; grid on
set(gcf,'Name','Stock prices')
for i=1:firms_nr
    Idx_id = find(firms_id==i);
    
    stock_prices_values{i} = Data(Idx_id,3);
    stock_prices_days{i} = Data(Idx_id,1);
   plot(stock_prices_days{i},stock_prices_values{i},'color',[rand rand rand])
    clear Idx_id
end

for d=1:numel(days) 
    Idx_days = find(Data(:,1)==d);
    stock_index(d) = mean(Data(Idx_days,3));
    clear Idx_days
end

figure(61); hold on; grid on; box on
set(gcf,'Name','Stock price index')
plot(daily_month_index,stock_index(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('stock price index','fontsize',font_sz)
set(gca,'xlim',[0, mf])

clear Data



%%% Credit rationing
 Data = load([Pat, 'credit_rationing.txt']);
 Credit_requested = Data(:,3);
 Credit_allowed = Data(:,4);
% 
 days = unique(Data(:,1));
% 

credit_rationing_time = [];
credit_rationing_qty = [];
j = 0;
for i=1:numel(days)
    
    d = days(i);
    
    days_idx = find(Data(:,1)==d);
    Credit_requested_sum(i) = sum(Credit_requested(days_idx));
    Credit_allowed_sum(i) = sum(Credit_allowed(days_idx));
    
    if Credit_requested_sum(i)>Credit_allowed_sum(i)
        j = j + 1;
        credit_rationing_time(j) = d;
        credit_rationing_qty(j) = Credit_requested_sum(i)-Credit_allowed_sum(i);
    end
   
    clear days_idx
    
end
% 
% 
if j>0
figure(71); hold on; grid on
set(gcf,'Name','credit rationing')
bar(credit_rationing_time/20,credit_rationing_qty,colore)

set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('credit rationing','fontsize',font_sz)
set(gca,'xlim',[0, mf])
end

clear Data

% %%% Firm stock transaction
% Data = load([Pat, 'firms_stock_transactions.txt']);
% firms_id = Data(:,2);
% firms_nr = numel(unique(firms_id));
% 
% days = unique(Data(:,1));
% 
% figure(81); hold on; grid on
% 
% testo = [];
% 
% for i=1:firms_nr
% 
%     Idx_id = find(firms_id==i);
%     Shares_outstanding_nr{i} = Data(Idx_id,4);   
%     Shares_outstanding_days{i} = Data(Idx_id,1);   
%     new_capital_raised{i} = Data(Idx_id,5);
%     stairs(Shares_outstanding_days{i},Shares_outstanding_nr{i},colore{i})
%     clear Idx_id      
%     
%     testo{i} = ['firm ', num2str(i)];
%   
% end
% 
% legend(testo,0)
% 
% clear Data

%%% Eurostat
Data = load([Pat, 'eurostat.txt']);
Data2 = load([Pat, 'eurostat2.txt']);

figure(91); hold on; grid on
GDP = Data(:,2);
CPI = Data(:,3);
OUTPUT = Data(:,4);
UNEMPLOYMENT = Data(:,6);
AVERAGE_WAGE = Data(:,7);
NrFailures = Data(:,8);

SOLD_QUANTITY = Data2(:,2);
MONTHLY_OUTPUT = Data2(:,3);
MONTHLY_REVENUES = Data2(:,4);
MONTHLY_INVESTMENT = Data2(:,5);

% figure(91); 
% subplot(2,1,1); hold on; grid on
% plot(Data(1:mf,1),GDP(1:mf),colore)
% legend('monthly GDP',0)
% 
% subplot(2,1,2); hold on; grid on
% plot(Data(1:mf,1),UNEMPLOYMENT(1:mf),colore)
% legend('monthly unemployment rate (%)',0)
% 
% figure(92); 
% subplot(2,1,1); hold on; grid on
% plot(Data(1:mf,1),CPI(1:mf),colore)
% legend('monthly CPI',0)
% 
% subplot(2,1,2); hold on; grid on
% plot(Data(1:mf,1),AVERAGE_WAGE(1:mf),colore)
% legend('monthly average wage',0)

figure(91); grid on; hold on; box on
set(gcf,'Name','Production & Sales')
plot(monthly_month_index,SOLD_QUANTITY(monthly_month_index),colore)
plot(monthly_month_index,MONTHLY_OUTPUT(monthly_month_index),[colore, ':'])
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
set(gca,'xlim',[0, mf])
ylabel('real values','fontsize',font_sz)
legend('sales','production',0)

clear Data Data2

%%%%%%  Good market statistics
Data = load([Pat, 'firms_goods_market.txt']);
days = unique(Data(:,1));

k = 0;
for d=1:20:(numel(days)-19)
    Idx = find((Data(:,1)>=d)&(Data(:,1)<(d+20)));
    Idx_q_sold = find(Data(Idx,3));
    q_sold = Data(Idx(Idx_q_sold),3);
    p_sold = Data(Idx(Idx_q_sold),4);
    k = k + 1;
    
    q_sold_tot(k) = sum(q_sold);
    Revenues(k) = sum(q_sold.*p_sold);
    p_index(k,1) = sum(q_sold.*p_sold)/q_sold_tot(k);
    
    clear Idx q_sold p_sold
end


figure(92);
set(gcf,'Name','Price & Wage Level')
subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,p_index(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('consumption goods price level','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,AVERAGE_WAGE(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('wage level','fontsize',font_sz)
set(gca,'xlim',[0, mf])

clear Data

%%%%  Capital goods and GDP components
Data = load([Pat, 'firms_capital_goods.txt']);

k = 1;
for d=1:20:(numel(days)-19)
    Idx = find((Data(:,1)>=d)&(Data(:,1)<(d+20)));

    tota_units_capital_stock(k,1) = sum(Data(Idx,3));
    capital_goods_investment(k,1) = sum(Data(Idx,4));
    capital_goods_price(k,1) = sum(Data(Idx,5))/numel(find(Data(Idx,5)>0));
    k = k + 1;
       
    clear Idx 
end

nominal_investment = capital_goods_investment(1:mf).*capital_goods_price(1:mf);

figure(93);
set(gcf,'Name','Nominal GDP components')

subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,Revenues(monthly_month_index),colore)
%plot(MONTHLY_REVENUES(1:mf),colore,'linewidth',2)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('nominal consumption (firm revenues)','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,nominal_investment(monthly_month_index),colore)
%plot(MONTHLY_REVENUES(1:mf),colore,'linewidth',2)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('nominal investment','fontsize',font_sz)
set(gca,'xlim',[0, mf])


figure(94);
set(gcf,'Name','Real GDP components')

subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,SOLD_QUANTITY(monthly_month_index),colore)
plot(monthly_month_index,MONTHLY_OUTPUT(monthly_month_index),[colore, ':'])
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
set(gca,'xlim',[0, mf])
ylabel('real consumption','fontsize',font_sz)
legend('sales','production',0)

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,capital_goods_investment(monthly_month_index),colore)
%plot(MONTHLY_REVENUES(1:mf),colore,'linewidth',2)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('real investment','fontsize',font_sz)
set(gca,'xlim',[0, mf])


figure(95);
set(gcf,'Name','Consumption and capital goods prices')
subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,p_index(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('consumption goods price level','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,capital_goods_price(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('capital goods price level','fontsize',font_sz)
set(gca,'xlim',[0, mf])


%%% INVARIANTS

MONEY_PRIVATE_SECTOR = DEPOSITS_sum(1:tf) + EQUITY_sum(1:tf) + FIAT_MONEY_BANKS(1:tf)';

MONEY_PRIVATE_SECTOR_counterpart = TOTAL_CREDIT_sum(1:tf) + ...
    FIAT_MONEY(1:tf)' - PAYMENT_ACCOUNT_CB(1:tf)' - CUM_ENERGY_COSTS_sum(1:tf) - PAYMENT_ACCOUNT_GOVS_sum(1:tf);


figure(101); 
set(gcf,'Name','Invariants')
subplot(2,1,1); hold on; grid on; box on
plot(daily_month_index,MONEY_PRIVATE_SECTOR(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('private sector deposits + banks equity','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,MONEY_PRIVATE_SECTOR_counterpart(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('total loans + fiat money - public sectors deposits','fontsize',font_sz)
set(gca,'xlim',[0, mf])




% figure(102);  hold on; grid on
% plot(MONEY_PRIVATE_SECTOR(1:tf)-MONEY_PRIVATE_SECTOR_counterpart(1:tf),colore)




% figure(96);
% subplot(2,1,2); hold on; grid on; box on
% plot(Revenues(1:mf),colore)
% plot(MONTHLY_REVENUES(1:mf),colore,'linewidth',2)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('arbitrary monetary units','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('Firms revenues (Matlab)','Firms revenues (Eurostat)','Location','Best')
% 
% subplot(2,1,1); hold on; grid on; box on
% plot(q_sold_tot(1:mf),colore)
% plot(SOLD_QUANTITY(1:mf),'-o')
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('units','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('Sold quantity (Matlab)','Sold quantity (Eurostat)','Location','Best')
% 
% if print_flag
%     print('-dpsc2','figure06.eps')
% end


figure(111);
set(gcf,'Name','Output and unemployment')
subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,MONTHLY_OUTPUT(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Production of consumptio goods','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,UNEMPLOYMENT(1:mf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Unemployment rate (%)','fontsize',font_sz)
set(gca,'xlim',[0, mf])



%%% Firm monthly balance sheet
Data = load([Pat, 'firms_balance_sheet.txt']);



days = unique(Data(:,1));
TOTAL_UNITS_CAPITAL_STOCK_FIRMS = Data(:,3);
TOTAL_VALUE_CAPITAL_STOCK_FIRMS = Data(:,4);
TOTAL_UNITS_LOCAL_INVENTORY_FIRMS = Data(:,5);
TOTAL_VALUE_LOCAL_INVENTORY_FIRMS = Data(:,6);
PAYMENT_ACCOUNT_FIRMS = Data(:,7);
TOTAL_ASSETS_FIRMS = Data(:,8);
TOTAL_DEBT_FIRMS = Data(:,9);
EQUITY_FIRMS = Data(:,10);


for i=1:numel(days)
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_FIRMS_sum(i) = sum(PAYMENT_ACCOUNT_FIRMS(days_idx));
    TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum(i) = sum(TOTAL_UNITS_CAPITAL_STOCK_FIRMS(days_idx));
    TOTAL_VALUE_CAPITAL_STOCK_FIRMS_sum(i) = sum(TOTAL_VALUE_CAPITAL_STOCK_FIRMS(days_idx));
    TOTAL_UNITS_LOCAL_INVENTORY_FIRMS(i) = sum(TOTAL_UNITS_LOCAL_INVENTORY_FIRMS(days_idx));
     TOTAL_VALUE_LOCAL_INVENTORY_FIRMS_sum(i) = sum(TOTAL_VALUE_LOCAL_INVENTORY_FIRMS(days_idx));
      PAYMENT_ACCOUNT_FIRMS_sum(i) = sum(PAYMENT_ACCOUNT_FIRMS(days_idx));
    TOTAL_ASSETS_FIRMS_sum(i) = sum(TOTAL_ASSETS_FIRMS(days_idx));
    TOTAL_DEBT_FIRMS_sum(i) = sum(TOTAL_DEBT_FIRMS(days_idx));
    EQUITY_FIRMS_sum(i) = sum(EQUITY_FIRMS(days_idx));
    LEVERAGE_FIRMS(i,:) = TOTAL_DEBT_FIRMS(days_idx)./EQUITY_FIRMS(days_idx);
    clear days_idx
end    

% FIRMS CAPITAL STRENGTH
figure(121); 
set(gcf,'Name','Aggregate capital stock')
subplot(2,1,1); hold on; grid on; box on
plot(daily_month_index,TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('total units of capital stock','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,TOTAL_VALUE_CAPITAL_STOCK_FIRMS_sum(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('total value of capital stock','fontsize',font_sz)
set(gca,'xlim',[0, mf])





figure(122); 
set(gcf,'Name','Firms Debt and Equity')
subplot(2,1,1); hold on; grid on; box on
plot(daily_month_index,TOTAL_DEBT_FIRMS_sum(1:tf),colore)
legend('firms total debt','Location','Best')
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('firms debt','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,EQUITY_FIRMS_sum(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('firms equity','fontsize',font_sz)
legend('firms equity','Location','Best')
set(gca,'xlim',[0, mf])



clear Data

%%% VALUE AT RISK
Data = load([Pat, 'banks_value_at_risk.txt']);
Value_at_Risk = Data(:,3);
Banks_ids = unique(Data(:,2));

figure(123);
set(gcf,'Name','Firms value at risk')
for i= 1:numel(Banks_ids)
    Idx = find(Data(:,2)==Banks_ids(i));
    subplot(2,1,1); hold on; grid on; box on
    if i==1
        plot(daily_month_index,Value_at_Risk(Idx(1:tf)),colore)
    else
        plot(daily_month_index,Value_at_Risk(Idx(1:tf)),colore,'linewidth',2)
    end
    clear Idx
end
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Value at risk','fontsize',font_sz)
legend('Bank 1','Bank 2','Location','Best')
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,TOTAL_CREDIT_sum(1:tf),colore)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Total loans to firms','fontsize',font_sz)
set(gca,'xlim',[0, mf])

clear Data

GDP_real = capital_goods_investment + MONTHLY_OUTPUT;
GDP_fluctuations = diff(log(GDP_real));

m1 = floor(numel(GDP_fluctuations)/2);

fprintf('\n\n GDP fluctuations statistics')
fprintf('\n 12:end. m: %f s: %f',mean(GDP_fluctuations(12:end)),std(GDP_fluctuations(12:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(GDP_fluctuations(12:m1)),std(GDP_fluctuations(12:m1)))
fprintf('\n m1:end. m: %f s: %f',mean(GDP_fluctuations(m1:end)),std(GDP_fluctuations(m1:end)))

price_inflation = diff(log(p_index));

fprintf('\n\n Inflation statistics')
fprintf('\n 12:end. m: %f s: %f',mean(price_inflation(12:end)),std(price_inflation(12:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(price_inflation(12:m1)),std(price_inflation(12:m1)))
fprintf('\n m1:end. m: %f s: %f',mean(price_inflation(m1:end)),std(price_inflation(m1:end)))

wage_inflation = diff(log(AVERAGE_WAGE));

fprintf('\n\n wage statistics')
fprintf('\n 12:end. m: %f s: %f',mean(wage_inflation(12:end)),std(wage_inflation(12:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(wage_inflation(12:m1)),std(wage_inflation(12:m1)))
fprintf('\n m1:end. m: %f s: %f',mean(wage_inflation(m1:end)),std(wage_inflation(m1:end)))

fprintf('\n\n Unemployment statistics')
fprintf('\n 12:end. m: %f s: %f',mean(UNEMPLOYMENT(12:end)),std(UNEMPLOYMENT(12:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(UNEMPLOYMENT(12:m1)),std(UNEMPLOYMENT(12:m1)))
fprintf('\n m1:end. m: %f s: %f',mean(UNEMPLOYMENT(m1:end)),std(UNEMPLOYMENT(m1:end)))

fprintf('\n\n Money private sector statistics (I)')
fprintf('\n 12:end. m: %f s: %f',mean(MONEY_PRIVATE_SECTOR(12*20:end)),std(MONEY_PRIVATE_SECTOR(12*20:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(MONEY_PRIVATE_SECTOR(12*20:m1*20)),std(MONEY_PRIVATE_SECTOR(12*20:m1*20)))
fprintf('\n m1:end. m: %f s: %f',mean(MONEY_PRIVATE_SECTOR(m1*20:end)),std(MONEY_PRIVATE_SECTOR(m1*20:end)))

Kapital_growth = diff(log(TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum));

fprintf('\n\n kapital stock growth statistics')
fprintf('\n 12:end. m: %f s: %f',mean(Kapital_growth(12*20:end)),std(Kapital_growth(12*20:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(Kapital_growth(12*20:m1*20)),std(Kapital_growth(12*20:m1*20)))
fprintf('\n m1:end. m: %f s: %f',mean(Kapital_growth(m1*20:end)),std(Kapital_growth(m1*20:end)))


fprintf('\n\n Leverage firms statistics')
fprintf('\n 12:end. m: %f',max(max(LEVERAGE_FIRMS(12*20:end,:))))
fprintf('\n 12:m1. m: %f',max(max(LEVERAGE_FIRMS(12*20:m1*20,:))))
fprintf('\n m1:end. m: %f',max(max(LEVERAGE_FIRMS(m1*20:end,:))))


stock_index_returns = diff(log(stock_index));
fprintf('\n\n Stock index returns statistics')
fprintf('\n 12:end. m: %f s: %f',mean(stock_index_returns(12*20:end)),std(stock_index_returns(12*20:end)))
fprintf('\n 12:m1. m: %f s: %f',mean(stock_index_returns(12*20:m1*20)),std(stock_index_returns(12*20:m1*20)))
fprintf('\n m1:end. m: %f s: %f',mean(stock_index_returns(m1*20:end)),std(stock_index_returns(m1*20:end)))

k = 0;
for d=1:20:tf
    k = k + 1;
    TOTAL_CREDIT_sum_monthly(k,1) = sum(TOTAL_CREDIT_sum(d:d+19));
    MONEY_PRIVATE_SECTOR_monthly(k,1) = sum(MONEY_PRIVATE_SECTOR(d:d+19));
end

fprintf('\n\n Money private sector statistics (II)')
fprintf('\n 12:end. m: %f s: %f',mean(diff(log(MONEY_PRIVATE_SECTOR_monthly))),std(diff(log(MONEY_PRIVATE_SECTOR_monthly))))
fprintf('\n 12:m1. m: %f s: %f',mean(diff(log(MONEY_PRIVATE_SECTOR_monthly))),std(diff(log(MONEY_PRIVATE_SECTOR_monthly))))
fprintf('\n m1:end. m: %f s: %f',mean(diff(log(MONEY_PRIVATE_SECTOR_monthly))),std(diff(log(MONEY_PRIVATE_SECTOR_monthly))))


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
w = 60; k = 0;
for d = 1:(numel(GDP_real)-w)
    k = k + 1;
    massimo(k,1) = max(GDP_real(d:d+w));
    minimo(k,1) = min(GDP_real(d:d+w));
end
   
GDP_drop = (massimo-minimo)./massimo;



fprintf('\n\n GDP drop statistics')
fprintf('\n Mean 12:end %f 12:%d: %f %d:end: %f',...
    mean(GDP_drop(12:end)),m1,mean(GDP_drop(12:m1)),m1,mean(GDP_drop(m1:end)))
fprintf('\n Max 12:end %f 12:%d: %f %d:end: %f',...
    max(GDP_drop(12:end)),m1,max(GDP_drop(12:m1)),m1,max(GDP_drop(m1:end)))
fprintf('\n Min 12:end %f 12:%d: %f %d:end: %f',...
    min(GDP_drop(12:end)),m1,min(GDP_drop(12:m1)),m1,min(GDP_drop(m1:end)))
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

fprintf('\n\n Cross correlations')
c = corrcoef(diff(log(TOTAL_CREDIT_sum_monthly)),UNEMPLOYMENT(2:mf));
fprintf('\n TOTAL_CREDIT_sum_monthly fluctuations vs UNEMPLOYMENT: %f',c(1,2))
c = corrcoef(diff(log(MONEY_PRIVATE_SECTOR_monthly)),UNEMPLOYMENT(2:mf));
fprintf('\n MONEY_PRIVATE_SECTOR_monthly fluctuations vs UNEMPLOYMENT: %f',c(1,2))
c = corrcoef(diff(log(TOTAL_CREDIT_sum_monthly)),diff(log(MONTHLY_OUTPUT)));
fprintf('\n TOTAL_CREDIT_sum_monthly fluctuations vs Monthly output: %f',c(1,2))
c = corrcoef(diff(log(MONEY_PRIVATE_SECTOR_monthly)),diff(log(MONTHLY_OUTPUT)));
fprintf('\n MONEY_PRIVATE_SECTOR_monthly fluctuations vs Monthly output: %f',c(1,2))
c = corrcoef(diff(log(TOTAL_CREDIT_sum_monthly)),capital_goods_investment(2:end));
fprintf('\n TOTAL_CREDIT_sum_monthly fluctuations vs Investments: %f',c(1,2))
c = corrcoef(diff(log(MONEY_PRIVATE_SECTOR_monthly)),capital_goods_investment(2:end));
fprintf('\n MONEY_PRIVATE_SECTOR_monthly fluctuations vs Investments: %f',c(1,2))
c = corrcoef(diff(log(TOTAL_CREDIT_sum_monthly)),GDP_fluctuations);
fprintf('\n TOTAL_CREDIT_sum_monthly fluctuations vs GDP fluctuations: %f',c(1,2))
c = corrcoef(diff(log(MONEY_PRIVATE_SECTOR_monthly)),GDP_fluctuations);
fprintf('\n MONEY_PRIVATE_SECTOR_monthly fluctuations vs GDP fluctuations: %f',c(1,2))

   
    
    
%%% FIGURE DEFINITIVE %%%%%%%%%%%%%%%%%%%%

font_sz = 16;

figure(201);
set(gcf,'Name','GDP and unemployment')
subplot(2,1,1); hold on; grid on; box on
plot(monthly_month_index,GDP_real(1:mf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('real GDP','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,UNEMPLOYMENT(1:mf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Unemployment rate (%)','fontsize',font_sz)
set(gca,'xlim',[0, mf])


figure(202);
subplot(2,1,1); hold on; grid on; box on
plot(daily_month_index,MONEY_PRIVATE_SECTOR(1:tf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Private sector money endowment','fontsize',font_sz)
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(monthly_month_index,p_index(1:mf),colore)
set(gca,'xtick',monthly_index2,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Price level','fontsize',font_sz)
set(gca,'xlim',[0, mf])

