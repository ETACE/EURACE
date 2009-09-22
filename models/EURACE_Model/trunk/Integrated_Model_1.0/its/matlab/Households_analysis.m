clc
clear all
close all

Pat = '..\';

font_sz = 14;

Data = load([Pat, 'households_daily_income_statement.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
labor_income = Data(:,3);
received_dividends = Data(:,4);
monthly_bond_interest = Data(:,5);
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
plot(days,payment_account_sum,'k')
xlabel('days','fontsize',font_sz)
legend('savings','payment account')


figure(3); hold on; grid on
title('Households aggregate data','fontsize',font_sz)
saving_sum = received_dividends_sum+monthly_bond_interest_sum+labor_income_sum-expenditures_sum-tax_payments_sum;
plot(days,saving_sum)
plot(days(2:end),diff(payment_account_sum),'k')
xlabel('days','fontsize',font_sz)
legend('savings','\Delta payment account')

break

clear Data
Data = load([Pat, 'households_transactions.txt']);
days = unique(Data(:,1));
trades = Data(:,3);

for i=1:numel(days)
    
    days_idx = find(Data(:,1)==i);
    trades_sum(i) = sum(trades(days_idx));
    
    clear days_idx
    
end


figure(4); hold on; grid on
title('Households aggregate net transactions','fontsize',font_sz)
plot(trades_sum)
xlabel('days','fontsize',font_sz)
