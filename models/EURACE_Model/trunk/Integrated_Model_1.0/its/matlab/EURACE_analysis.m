clc
clear all
close all

Pat = '..\';

font_sz = 14;

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
plot(TOTAL_CREDIT_sum)
plot(PAYMENT_ACCOUNT_BANKS_sum,'g')
plot(DEPOSITS_sum,'m')
plot(ECB_DEBT_sum,'k')
plot(EQUITY_sum,'r')
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
plot(FIAT_MONEY_GOVS)
plot(FIAT_MONEY_BANKS,'g')
plot(FIAT_MONEY,'m')
plot(PAYMENT_ACCOUNT_CB,'k')
plot(ECB_DEPOSITS,'r')
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
plot(PAYMENT_ACCOUNT_GOVS_sum)
title('payment account government')

subplot(2,2,2)
plot(BONDS_NR_OUTSTANDING_sum)
title('Nr Outstanding bonds')

subplot(2,2,3)
plot(BOND_QUANTITY)
title('Bond quantity')

subplot(2,2,4)
plot(BOND_PRICE)
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
plot(PAYMENT_ACCOUNT_FIRMS_sum)
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
plot(PAYMENT_ACCOUNT_IGFIRMS_sum)
title('PAYMENT ACCOUNT IGFIRM')
subplot(2,1,2)
plot(CUM_ENERGY_COSTS_sum)
title('CUMULATED ENERGY COST')


%%% Stock prices
Data = load([Pat, 'stock_prices.txt']);
firms_id = Data(:,2);
firms_nr = numel(unique(firms_id));
days = unique(Data(:,1));
%prices = zeros(numel(days),firms_nr);

colore = {'r';'k';'g';'b';'y'};


for i=1:firms_nr
    Idx_id = find(firms_id==i);
    stock_prices_values{i} = Data(Idx_id,3);
    stock_prices_days{i} = Data(Idx_id,1);
    figure(61); hold on; grid on
    plot(stock_prices_days{i},stock_prices_values{i},colore{i})
    clear Idx_id
end



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
plot(days,Credit_requested_sum)
plot(days,Credit_allowed_sum,'r')
legend('Credit requested','Credit allowed',0)

clear Data

%%% Firm stock transaction
Data = load([Pat, 'firms_stock_transactions.txt']);
firms_id = Data(:,2);
firms_nr = numel(unique(firms_id));

days = unique(Data(:,1));

figure(81); hold on; grid on

testo = [];

for i=1:firms_nr

    Idx_id = find(firms_id==i);
    Shares_outstanding_nr{i} = Data(Idx_id,4);   
    Shares_outstanding_days{i} = Data(Idx_id,1);   
    new_capital_raised{i} = Data(Idx_id,5);
    stairs(Shares_outstanding_days{i},Shares_outstanding_nr{i},colore{i})
    clear Idx_id      
    
    testo{i} = ['firm ', num2str(i)];
  
end

legend(testo,0)

clear Data

%%% Eurostat
Data = load([Pat, 'eurostat.txt']);

figure(91); hold on; grid on
GDP = Data(:,2);
CPI = Data(:,3);
OUTPUT = Data(:,4);
UNEMPLOYMENT = Data(:,6);
AVERAGE_WAGE = Data(:,7);

colore = 'b';
figure(91); 
subplot(2,1,1); hold on; grid on
plot(Data(:,1),GDP,colore)
plot(Data(:,1),OUTPUT,[colore, ':'])
legend('GDP','OUTPUT')

subplot(2,1,2); hold on; grid on
plot(Data(:,1),UNEMPLOYMENT,colore)
legend('unemployment')

figure(92); 
subplot(2,1,1); hold on; grid on
plot(Data(:,1),CPI,colore)
legend('CPI')

subplot(2,1,2); hold on; grid on
plot(Data(:,1),AVERAGE_WAGE,colore)
legend('AVERAGE_WAGE')



%%% INVARIANTS

MONEY_PRIVATE_SECTOR = DEPOSITS_sum+ EQUITY_sum;

MONEY_PRIVATE_SECTOR_counterpart = TOTAL_CREDIT_sum + ...
    FIAT_MONEY' - PAYMENT_ACCOUNT_CB' - CUM_ENERGY_COSTS_sum - PAYMENT_ACCOUNT_GOVS_sum;

figure(101); 
subplot(2,1,1); hold on; grid on
plot(MONEY_PRIVATE_SECTOR)

subplot(2,1,2); hold on; grid on
plot(MONEY_PRIVATE_SECTOR_counterpart)

%%%%%%%%%%%%%%%

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
