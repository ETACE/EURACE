clc
clear all
close all

Pat = '..\';

font_sz = 14;

%agent_id = 110;

Data = load([Pat, 'banks_daily_balance_sheet.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
%agent_id_data_ids = find(Data(:,2)==agent_id);



FIRM_LOAN_ISSUES = Data(:,3);
FIRM_LOAN_INSTALLMENTS = Data(:,4);
TOTAL_CREDIT = Data(:,5);
CASH = Data(:,6);
DEPOSITS = Data(:,7);
ECB_DEBT = Data(:,8);
EQUITY = Data(:,9);

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    FIRM_LOAN_ISSUES_sum(i) = sum(FIRM_LOAN_ISSUES(days_idx));
    FIRM_LOAN_INSTALLMENTS_sum(i) = sum(FIRM_LOAN_INSTALLMENTS(days_idx));
    TOTAL_CREDIT_sum(i) = sum(TOTAL_CREDIT(days_idx));
    CASH_sum(i) = sum(CASH(days_idx));
    DEPOSITS_sum(i) = sum(DEPOSITS(days_idx));
    ECB_DEBT_sum(i) = sum(ECB_DEBT(days_idx));
    EQUITY_sum(i) = sum(EQUITY(days_idx));
    
    clear days_idx
    
end

clear Data

Data = load([Pat, 'CentralBank_balance_sheet.txt']);


break

figure(1); hold on; grid on
title('Households aggregate data','fontsize',font_sz)

plot(days(find(received_dividends_sum)),received_dividends_sum(find(received_dividends_sum)),'o')
plot(days(find(monthly_bond_interest_sum)),monthly_bond_interest_sum(find(monthly_bond_interest_sum)),'rv')
plot(days(find(labor_income_sum)),labor_income_sum(find(labor_income_sum)),'sk')
plot(days(find(tax_payments_sum)),tax_payments_sum(find(tax_payments_sum)),'gx')
plot(days,expenditures_sum,'r')
xlabel('days','fontsize',font_sz)
legend('received dividends','monthly bond interest','labor income','tax payments','expenditures',0)

figure(2); hold on; grid on
title('Households aggregate data','fontsize',font_sz)
saving_sum = received_dividends_sum+monthly_bond_interest_sum+labor_income_sum-expenditures_sum-tax_payments_sum;
plot(days,saving_sum)
plot(days,payment_account_sum,'ok')
xlabel('days','fontsize',font_sz)
legend('savings','payment account')


figure(3); hold on; grid on
title('Households aggregate data','fontsize',font_sz)
saving_sum = received_dividends_sum+monthly_bond_interest_sum+labor_income_sum-expenditures_sum-tax_payments_sum;
plot(days,saving_sum)
plot(days(2:end),diff(payment_account_sum),'ok')
xlabel('days','fontsize',font_sz)
legend('savings','\Delta payment account')


received_dividends_agent_id = received_dividends(agent_id_data_ids);
monthly_bond_interest_agent_id = monthly_bond_interest(agent_id_data_ids);
labor_income_agent_id = labor_income(agent_id_data_ids);
tax_payments_agent_id = tax_payments(agent_id_data_ids);
expenditures_agent_id = expenditures(agent_id_data_ids);
payment_account_agent_id = payment_account(agent_id_data_ids);
days_agent_id = Data(agent_id_data_ids,1);

figure(4); hold on; grid on
title(['Household ID = ',num2str(agent_id)],'fontsize',font_sz)
plot(days_agent_id(find(received_dividends_agent_id)),received_dividends_agent_id(find(received_dividends_agent_id)),'o')
plot(days_agent_id(find(monthly_bond_interest_agent_id)),monthly_bond_interest_agent_id(find(monthly_bond_interest_agent_id)),'rv')
plot(days_agent_id(find(labor_income_agent_id)),labor_income_agent_id(find(labor_income_agent_id)),'sk')
plot(days_agent_id(find(tax_payments_agent_id)),tax_payments_agent_id(find(tax_payments_agent_id)),'gx')
plot(days_agent_id(find(expenditures_agent_id)),expenditures_agent_id(find(expenditures_agent_id)),'or')
xlabel('days','fontsize',font_sz)
legend('received dividends','monthly bond interest','labor income','tax payments','expenditures',0)


saving_agent_id = received_dividends_agent_id + monthly_bond_interest_agent_id + ...
    labor_income_agent_id - expenditures_agent_id - tax_payments_agent_id;

figure(5); hold on; grid on
plot(days,saving_agent_id)
plot(days(2:end),diff(payment_account_agent_id),'ok')
xlabel('days','fontsize',font_sz)
legend('savings','\Delta payment account',0)


%break

clear Data
Data = load([Pat, 'households_transactions.txt']);
days = unique(Data(:,1));
trades = Data(:,3);

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    trades_sum(i) = sum(trades(days_idx));
    
    clear days_idx
    
end


figure(11); hold on; grid on
title('Households aggregate net transactions','fontsize',font_sz)
plot(trades_sum)
xlabel('days','fontsize',font_sz)
