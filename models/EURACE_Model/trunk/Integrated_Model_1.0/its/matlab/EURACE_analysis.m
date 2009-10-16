clc
clear all
close all

Pat = '..\qe1\';
Pat = '..\';

font_sz = 14;
colore = 'b';

%%% BANKS

Data = load([Pat, 'banks_daily_balance_sheet.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
%agent_id_data_ids = find(Data(:,2)==agent_id);


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

figure(11); grid on; hold on
plot(TOTAL_CREDIT_sum,colore)
plot(PAYMENT_ACCOUNT_BANKS_sum,[colore, '--'])
plot(DEPOSITS_sum,[colore, '-.'])
plot(ECB_DEBT_sum,[colore, '-o'])
plot(EQUITY_sum,[colore,':'])
legend('TOTAL CREDIT','PAYMENT ACCOUNT BANKS','DEPOSITS','ECB DEBT','EQUITY',0)
xlabel('days','fontsize',font_sz)
ylabel('aribitrary monetary units','fontsize',font_sz)
title('Banks aggregate data','fontsize',font_sz)

clear Data

%%% Central Bank
Data = load([Pat, 'CentralBank_daily_balance_sheet.txt']);

FIAT_MONEY_GOVS = Data(:,2);
FIAT_MONEY_BANKS = Data(:,3);
FIAT_MONEY = Data(:,4);
PAYMENT_ACCOUNT_CB = Data(:,5);
ECB_DEPOSITS = Data(:,6);

figure(21); grid on; hold on
plot(FIAT_MONEY_GOVS,[colore, ':'])
plot(FIAT_MONEY_BANKS,[colore, '-.'])
plot(FIAT_MONEY,colore)
plot(PAYMENT_ACCOUNT_CB,[colore,'--'])
plot(ECB_DEPOSITS,[colore,'-o'])
legend('FIAT MONEY GOVS','FIAT MONEY BANKS','FIAT MONEY','PAYMENT ACCOUNT CB','ECB DEPOSITS',0)
xlabel('days','fontsize',font_sz)
ylabel('aribitrary monetary units','fontsize',font_sz)
title('Central Bank aggregate data','fontsize',font_sz)

clear Data

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

figure(31); 
title('Goverments aggregate data','fontsize',font_sz)
grid on; hold on

subplot(2,2,1)
plot(PAYMENT_ACCOUNT_GOVS_sum,colore)
title('payment account government')

subplot(2,2,2)
plot(BONDS_NR_OUTSTANDING_sum,colore)
title('Nr Outstanding bonds')

subplot(2,2,3)
plot(BOND_QUANTITY,colore)
title('Bond quantity')

subplot(2,2,4)
plot(BOND_PRICE,colore)
title('Bond price')


figure(1); hold on; grid on; box on
plot(ECB_DEPOSITS'-(PAYMENT_ACCOUNT_GOVS_sum+PAYMENT_ACCOUNT_BANKS_sum))
legend('ECB DEPOSITS - Aggregate PAYMENT ACCOUNT GOVS - PAYMENT ACCOUNT BANKS',0)

clear Data

%%% CGP FIRMS
Data = load([Pat, 'firms_daily_payment_account.txt']);

days = unique(Data(:,1));

PAYMENT_ACCOUNT_FIRMS = Data(:,3);

for i=1:numel(days)
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_FIRMS_sum(i) = sum(PAYMENT_ACCOUNT_FIRMS(days_idx));
end

clear Data

figure(41); hold on; grid on
plot(PAYMENT_ACCOUNT_FIRMS_sum,colore)
title('Firms aggregate data','fontsize',font_sz)
xlabel('days','fontsize',font_sz)
ylabel('aribitrary monetary units','fontsize',font_sz)

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

figure(51); hold on; grid on
subplot(2,1,1)
plot(PAYMENT_ACCOUNT_IGFIRMS_sum,colore)
title('PAYMENT ACCOUNT IGFIRM')
subplot(2,1,2)
plot(CUM_ENERGY_COSTS_sum,colore)
title('CUMULATED ENERGY COST')


%%% Stock prices
Data = load([Pat, 'stock_prices.txt']);
firms_id = Data(:,2);
firms_nr = numel(unique(firms_id));
days = unique(Data(:,1));
%prices = zeros(numel(days),firms_nr);




for i=1:firms_nr
    Idx_id = find(firms_id==i);
    
    stock_prices_values{i} = Data(Idx_id,3);
    stock_prices_days{i} = Data(Idx_id,1);
%    figure(61); hold on; grid on
 %   plot(stock_prices_days{i},stock_prices_values{i},colore{i})
    clear Idx_id
end

for d=1:numel(days) 
    Idx_days = find(Data(:,1)==d);
    stock_index(d) = mean(Data(Idx_days,3));
    clear Idx_days
end

    figure(61); hold on; grid on
   plot(stock_index,colore)
clear Data

%%% Credit market
Data = load([Pat, 'credit_rationing.txt']);
Credit_requested = Data(:,3);
Credit_allowed = Data(:,4);

days = unique(Data(:,1));

for i=1:numel(days)
    
    d = days(i);
    
    days_idx = find(Data(:,1)==d);
    Credit_requested_sum(i) = sum(Credit_requested(days_idx));
    Credit_allowed_sum(i) = sum(Credit_allowed(days_idx));
    
    clear days_idx
    
end


figure(71); hold on; grid on
plot(days,Credit_requested_sum,[':',colore])
plot(days,Credit_allowed_sum,colore)
legend('Credit requested','Credit allowed',0)

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
MONTHLY_INVESTMENT = Data2(:,end);
SOLD_QUANTITY = Data2(:,2);
MONTHLY_OUTPUT = Data2(:,3);

figure(91); 
subplot(2,1,1); hold on; grid on
plot(Data(:,1),GDP,colore)
legend('monthly GDP',0)

subplot(2,1,2); hold on; grid on
plot(Data(:,1),UNEMPLOYMENT,colore)
legend('monthly unemployment rate (%)',0)

figure(92); 
subplot(2,1,1); hold on; grid on
plot(Data(:,1),CPI,colore)
legend('monthly CPI',0)

subplot(2,1,2); hold on; grid on
plot(Data(:,1),AVERAGE_WAGE,colore)
legend('monthly average wage',0)

figure(93); hold on; grid on
plot(Data(:,1),SOLD_QUANTITY,colore)
plot(Data(:,1),MONTHLY_OUTPUT,[colore, ':'])
legend('sold quantity','output',0)

%%% INVARIANTS

MONEY_PRIVATE_SECTOR = DEPOSITS_sum+ EQUITY_sum;

MONEY_PRIVATE_SECTOR_counterpart = TOTAL_CREDIT_sum + ...
    FIAT_MONEY' - PAYMENT_ACCOUNT_CB' - CUM_ENERGY_COSTS_sum - PAYMENT_ACCOUNT_GOVS_sum;

figure(101); 
subplot(2,1,1); hold on; grid on
plot(MONEY_PRIVATE_SECTOR,colore)

subplot(2,1,2); hold on; grid on
plot(MONEY_PRIVATE_SECTOR_counterpart,colore)

figure(102);  hold on; grid on
plot(MONEY_PRIVATE_SECTOR-MONEY_PRIVATE_SECTOR_counterpart,colore)

clear Data Data2

%%% Firm monthly balance sheet
Data = load([Pat, 'firms_balance_sheet.txt']);

TOTAL_UNITS_CAPITAL_STOCK_FIRMS = Data(:,3);
TOTAL_VALUE_CAPITAL_STOCK_FIRMS = Data(:,4);
TOTAL_VALUE_LOCAL_INVENTORY_FIRMS = Data(:,5);
PAYMENT_ACCOUNT_FIRMS = Data(:,6);
TOTAL_ASSETS_FIRMS = Data(:,7);
TOTAL_DEBT_FIRMS = Data(:,8);
EQUITY_FIRMS = Data(:,9);
days = unique(Data(:,1));

k = 0;
for d=1:21:days(end)
    Idx_days = find((Data(:,1)>=d)&(Data(:,1)<(d+20)));
    k = k + 1;
    TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum(k) = sum(TOTAL_UNITS_CAPITAL_STOCK_FIRMS(Idx_days));
    TOTAL_VALUE_CAPITAL_STOCK_FIRMS_sum(k) = sum(TOTAL_VALUE_CAPITAL_STOCK_FIRMS(Idx_days));
    TOTAL_VALUE_LOCAL_INVENTORY_FIRMS_sum(k) = sum(TOTAL_VALUE_LOCAL_INVENTORY_FIRMS(Idx_days));
    TOTAL_ASSETS_FIRMS_sum(k) = sum(TOTAL_ASSETS_FIRMS(Idx_days));
    TOTAL_DEBT_FIRMS_sum(k) = sum(TOTAL_DEBT_FIRMS(Idx_days));
    EQUITY_FIRMS_sum(k) = sum(EQUITY_FIRMS(Idx_days));
    clear Idx_days
end    

figure(111); 
subplot(2,1,1); hold on; grid on
plot(1:21:days(end),TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum,colore)
legend('firms total units capital stock',0)

subplot(2,1,2); hold on; grid on
plot(1:21:days(end),TOTAL_VALUE_CAPITAL_STOCK_FIRMS_sum,colore)
legend('firms total value capital stock',0)

figure(112); 
subplot(2,1,1); hold on; grid on
plot(1:21:days(end),TOTAL_DEBT_FIRMS_sum,colore)
legend('firms total debt',0)

subplot(2,1,2); hold on; grid on
plot(1:21:days(end),EQUITY_FIRMS_sum,colore)
legend('firms total equity',0)

clear Data

%%% VALUE AT RISK
Data = load([Pat, 'banks_value_at_risk.txt']);
Value_at_Risk = Data(:,3);
Banks_ids = unique(Data(:,2));

figure(121);
for i= 1:numel(Banks_ids)
    Idx = find(Data(:,2)==Banks_ids(i));
    subplot(2,1,1); hold on; grid on
    plot(Value_at_Risk(Idx),colore)
    clear Idx
end
legend('Value at risk',0)

subplot(2,1,2); hold on; grid
plot(TOTAL_CREDIT_sum,colore)
legend('Total Credit',0)

break

figure(2); hold on; grid on; box on
plot(DEPOSITS_sum)
plot(PAYMENT_ACCOUNT_HOUSEHOLDS_sum+PAYMENT_ACCOUNT_FIRMS_sum+PAYMENT_ACCOUNT_IGFIRMS_sum,'ko')
legend('aggregate BANK DEPOSITS','Aggregate PAYMENT ACCOUNT HOUSEHOLDS + PAYMENT ACCOUNT FIRMS',0)

clear Data

figure(3); hold on; grid on; plot(DEPOSITS_sum'+ECB_DEPOSITS+PAYMENT_ACCOUNT_IGFIRMS_sum'-TOTAL_CREDIT_sum')

legend('aggregate BANK DEPOSITS + ECB DEPOSITS + PAY ACC IGFIRM - TOTAL CREDIT')


figure(4); hold on; grid on; box on
plot(PAYMENT_ACCOUNT_IGFIRMS)
legend('PAYMENT ACCOUNT IGFIRM',0)
