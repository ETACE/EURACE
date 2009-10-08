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

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    FIRM_LOAN_ISSUES_sum(i) = sum(FIRM_LOAN_ISSUES(days_idx));
    FIRM_LOAN_INSTALLMENTS_sum(i) = sum(FIRM_LOAN_INSTALLMENTS(days_idx));
    TOTAL_CREDIT_sum(i) = sum(TOTAL_CREDIT(days_idx));
    PAYMENT_ACCOUNT_BANKS_sum(i) = sum(PAYMENT_ACCOUNT_BANKS(days_idx));
    DEPOSITS_sum(i) = sum(DEPOSITS(days_idx));
    ECB_DEBT_sum(i) = sum(ECB_DEBT(days_idx));
    EQUITY_sum(i) = sum(EQUITY(days_idx));
    
    clear days_idx
    
end

clear Data

%%% Central Bank
Data = load([Pat, 'CentralBank_daily_balance_sheet.txt']);

FIAT_MONEY_GOVS = Data(:,2);
FIAT_MONEY_BANKS = Data(:,3);
PAYMENT_ACCOUNT_CB = Data(:,4);
ECB_DEPOSITS = Data(:,5);


clear Data

%%% Government
Data = load([Pat, 'Governments_daily_balance_sheet.txt']);

days = unique(Data(:,1));

PAYMENT_ACCOUNT_GOVS = Data(:,3);

for i=1:numel(days)
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_GOVS_sum(i) = sum(PAYMENT_ACCOUNT_GOVS(days_idx));
end

figure(1); hold on; grid on; box on
plot(ECB_DEPOSITS)
plot(PAYMENT_ACCOUNT_GOVS_sum+PAYMENT_ACCOUNT_BANKS_sum,'ko')
legend('ECB DEPOSITS','Aggregate PAYMENT ACCOUNT GOVS + PAYMENT ACCOUNT BANKS',0)

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

%%% Households

Data = load([Pat, 'households_daily_income_statement.txt']);

PAYMENT_ACCOUNT_HOUSEHOLDS = Data(:,7);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    PAYMENT_ACCOUNT_HOUSEHOLDS_sum(i) = sum(PAYMENT_ACCOUNT_HOUSEHOLDS(days_idx));
    
    clear days_idx
    
end

figure(2); hold on; grid on; box on
plot(DEPOSITS_sum)
plot(PAYMENT_ACCOUNT_HOUSEHOLDS_sum+PAYMENT_ACCOUNT_FIRMS_sum,'ko')
legend('aggregate BANK DEPOSITS','Aggregate PAYMENT ACCOUNT HOUSEHOLDS + PAYMENT ACCOUNT FIRMS',0)

clear Data

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

figure(2); hold on; grid on; box on
plot(DEPOSITS_sum)
plot(PAYMENT_ACCOUNT_HOUSEHOLDS_sum+PAYMENT_ACCOUNT_FIRMS_sum,'ko')
legend('aggregate BANK DEPOSITS','Aggregate PAYMENT ACCOUNT HOUSEHOLDS + PAYMENT ACCOUNT FIRMS',0)

clear Data

figure(3); hold on; grid on; plot(DEPOSITS_sum'+ECB_DEPOSITS+PAYMENT_ACCOUNT_IGFIRMS_sum'-TOTAL_CREDIT_sum')

legend('aggregate BANK DEPOSITS + ECB DEPOSITS + PAY ACC IGFIRM - TOTAL CREDIT')