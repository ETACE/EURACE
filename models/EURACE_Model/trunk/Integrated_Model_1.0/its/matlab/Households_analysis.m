clc
clear all
close all

Pat = '..\';

font_sz = 14;

agent_id = 104;



Data = load([Pat, 'households_daily_income_statement.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
agent_id_data_ids = find(Data(:,2)==agent_id);
labor_income = Data(:,3);
monthly_bond_interest = Data(:,4);
received_dividends = Data(:,5);
expenditures = Data(:,6);
payment_account = Data(:,7);
tax_payments = Data(:,8);


for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    received_dividends_sum(i) = sum(received_dividends(days_idx));
    labor_income_sum(i) = sum(labor_income(days_idx));
    monthly_bond_interest_sum(i) = sum(monthly_bond_interest(days_idx));
    expenditures_sum(i) = sum(expenditures(days_idx));
    tax_payments_sum(i) = sum(tax_payments(days_idx));
    payment_account_sum(i) = sum(payment_account(days_idx));
    
    clear days_idx
    
end



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
