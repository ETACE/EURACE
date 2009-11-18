clc
clear all
%close all

Pat = 'E:\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\qe1_d0.5\';
%Pat = '..\qe1_d0.5_es0\';

font_sz = 14;
colore = 'r';
marker = 'o';

mf = 120;
af = ceil(mf/12);
tf = 20*mf;
daily_month_index = (1:tf)/20;
yearly_month_index = (1:af)*12;
monthly_index = 0:6:mf; 
yearly_index  = 0:af

line_width = 1;

%%% BANKS

Data = load([Pat, 'banks_daily_balance_sheet.txt']);

days = unique(Data(:,1));
agents_ids = unique(Data(:,2));
%agent_id_data_ids = find(Data(:,2)==agent_id);

print_flag = 0;

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

% figure(11); grid on; hold on; box
% plot(daily_month_index,TOTAL_CREDIT_sum(1:tf),colore)
% plot(daily_month_index,PAYMENT_ACCOUNT_BANKS_sum(1:tf),[colore, '--'])
% plot(daily_month_index,DEPOSITS_sum(1:tf),colore,'linewidth',2)
% plot(daily_month_index,ECB_DEBT_sum(1:tf),colore,'linewidth',2)
% plot(daily_month_index,EQUITY_sum(1:tf),[colore,':'])
% legend('loans to firms','liquidity','private sector deposits','equity','Location','Best')
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% %title('Banking sector aggregate data','fontsize',font_sz)

%set(gca,'xlim',[0, mf])

clear Data
monthly_index12 = 0:12:mf; 

figure(12); 
subplot(3,1,1); grid on; hold on; box
plot(daily_month_index,TOTAL_CREDIT_sum(1:tf),colore,'linewidth',1)
set(gca,'xtick',monthly_index12,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Loans to firms (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

subplot(3,1,2); grid on; hold on; box
plot(daily_month_index,DEPOSITS_sum(1:tf),colore,'linewidth',1)
set(gca,'xtick',monthly_index12,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Private sector deposits (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

subplot(3,1,3); grid on; hold on; box
plot(daily_month_index,PAYMENT_ACCOUNT_BANKS_sum(1:tf),colore,'linewidth',1)
set(gca,'xtick',monthly_index12,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Reserves (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

% subplot(2,2,4); grid on; hold on; box
% plot(daily_month_index,ECB_DEBT_sum(1:tf),colore,'linewidth',1)
% set(gca,'xtick',monthly_index12,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('Standing facitility at the CB (€)','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('FT','QE','Location','Best')
% % if print_flag
% %     print('-dpsc2','figure01.eps')
% % end



%%% Central Bank
Data = load([Pat, 'CentralBank_daily_balance_sheet.txt']);

FIAT_MONEY_GOVS = Data(:,2);
FIAT_MONEY_BANKS = Data(:,3);
FIAT_MONEY = Data(:,4);
PAYMENT_ACCOUNT_CB = Data(:,5);
ECB_DEPOSITS = Data(:,6);



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


figure(32); 
% subplot(3,1,1); hold on; grid on; box on
% plot(daily_month_index,PAYMENT_ACCOUNT_GOVS_sum(1:tf),colore,'linewidth',line_width)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('government liquidity (€)','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('FT','QE','Location','Best')
% 
% subplot(3,1,2); hold on; grid on; box on
% plot(daily_month_index,BONDS_NR_OUTSTANDING_sum(1:tf),colore,'linewidth',line_width)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('# outstanding bonds','fontsize',font_sz)
% set(gca,'xlim',[0, mf])

% legend('FT','QE','Location','Best')


subplot(3,1,3); hold on; grid on; box on
plot(daily_month_index,BOND_PRICE(1:tf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('bond price (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

% if print_flag
%     print('-dpsc2','figure02.eps')
% end
% 

clear Data

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

% figure(61); hold on; grid on; box on
% plot(daily_month_index,stock_index(1:tf),colore)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('stock price index','Location','Best')

if print_flag
    print('-dpsc2','figure03.eps')
end

%set(gca,'ylim',[0.07, 0.11])

clear Data



%%% Eurostat
Data = load([Pat, 'eurostat.txt']);
Data2 = load([Pat, 'eurostat2.txt']);

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



%%% INVARIANTS

MONEY_PRIVATE_SECTOR = DEPOSITS_sum+ EQUITY_sum;

% MONEY_PRIVATE_SECTOR_counterpart = TOTAL_CREDIT_sum + ...
%     FIAT_MONEY' - PAYMENT_ACCOUNT_CB' - CUM_ENERGY_COSTS_sum - PAYMENT_ACCOUNT_GOVS_sum;

MONEY_PRIVATE_SECTOR_counterpart = TOTAL_CREDIT_sum + ...
    FIAT_MONEY' - PAYMENT_ACCOUNT_CB'  - PAYMENT_ACCOUNT_GOVS_sum;

figure(101); hold on; grid on; box on
subplot(2,1,1); hold on; grid on; box on
plot(daily_month_index,MONEY_PRIVATE_SECTOR(1:tf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('private sector deposits + bank equity (€)','fontsize',font_sz)
%legend('private sectors deposits','Location','Best')
set(gca,'xlim',[0, mf])

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,MONEY_PRIVATE_SECTOR_counterpart(1:tf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('total loans + fiat money - public sector deposits (€)','fontsize',font_sz)
%legend('total loans + fiat money - public sector deposits','Location','Best')
set(gca,'xlim',[0, mf])



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
% 
% 
% 
figure(95);
subplot(2,1,1); hold on; grid on; box on
plot(p_index(1:mf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('average price level (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

subplot(2,1,2); hold on; grid on; box on
plot(AVERAGE_WAGE(1:mf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('average wage level (€)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')


% figure(96);
% subplot(2,1,2); hold on; grid on; box on
% plot(Revenues(1:mf),colore)
% plot(MONTHLY_REVENUES(1:mf),colore,'linewidth',2)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('arbitrary monetary units','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('Firms revenues (Matlab)','Firms revenues (Eurostat)','Location','Best')


% subplot(2,1,1); hold on; grid on; box on
% plot(q_sold_tot(1:mf),colore)
% plot(SOLD_QUANTITY(1:mf),'-o')
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('units','fontsize',font_sz)
% set(gca,'xlim',[0, mf])
% legend('Sold quantity (Matlab)','Sold quantity (Eurostat)','Location','Best')


figure(97);
hold on; grid on; box on
plot(MONTHLY_OUTPUT(1:mf),[colore, ':'],'linewidth',1)
plot(q_sold_tot(1:mf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('# (units)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('Production of consumption goods (FT)','Final consumption (FT)',...
    'Production of consumption goods (QE)','Final consumption (QE)','Location','Best')


clear Data

%break

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
    clear days_idx
end    

% 
figure(111); 
subplot(2,1,1); hold on; grid on; box on
plot(UNEMPLOYMENT(1:mf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Unemployment rate (%)','fontsize',font_sz)
set(gca,'xlim',[0, mf])
legend('FT','QE','Location','Best')

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,TOTAL_UNITS_CAPITAL_STOCK_FIRMS_sum(1:tf),colore,'linewidth',line_width)
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Total units capital stock','fontsize',font_sz)
legend('FT','QE','Location','Best')
set(gca,'xlim',[0, mf])






% figure(112); 
% subplot(2,1,1); hold on; grid on; box on
% plot(daily_month_index,TOTAL_DEBT_FIRMS_sum(1:tf),colore)
% legend('firms total debt',0)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% %title('Central Bank aggregate data','fontsize',font_sz)
% legend('firms debt','Best')
% set(gca,'xlim',[0, mf])
% 
% subplot(2,1,2); hold on; grid on; box on
% plot(daily_month_index,EQUITY_FIRMS_sum(1:tf),colore)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% %title('Central Bank aggregate data','fontsize',font_sz)
% legend('firms equity','Best')
% set(gca,'xlim',[0, mf])
% print('-dpsc2','figure10.eps')




% figure(113); hold on; grid on
% plot(PAYMENT_ACCOUNT_FIRMS_sum(1:tf),colore)
% title('Firms aggregate data','fontsize',font_sz)
% xlabel('days','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% legend('Payment account','Location','Best')



clear Data

%%% VALUE AT RISK
% Data = load([Pat, 'banks_value_at_risk.txt']);
% Value_at_Risk = Data(:,3);
% Banks_ids = unique(Data(:,2));
% 
% figure(121);
% for i= 1:numel(Banks_ids)
%     Idx = find(Data(:,2)==Banks_ids(i));
%     subplot(2,1,1); hold on; grid on; box on
%     if i==1
%         plot(daily_month_index,Value_at_Risk(Idx(1:tf)),colore)
%     else
%         plot(daily_month_index,Value_at_Risk(Idx(1:tf)),colore,'linewidth',2)
%     end
%     clear Idx
% end
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% legend('Value at risk Bank 1','Value at risk Bank 2','Location','Best')
% set(gca,'xlim',[0, mf])
% 
% subplot(2,1,2); hold on; grid on; box on
% plot(daily_month_index,TOTAL_CREDIT_sum(1:tf),colore)
% set(gca,'xtick',monthly_index,'fontsize',font_sz)
% xlabel('months','fontsize',font_sz)
% ylabel('aribitrary monetary units','fontsize',font_sz)
% %title('Central Bank aggregate data','fontsize',font_sz)
% legend('Total loans to firms','Location','Best')
% set(gca,'xlim',[0, mf])
% 
% if print_flag
%     print('-dpsc2','figure11.eps')
% end

clear Data



Data = load([Pat, 'Government_policies.txt']);

figure(131); 

TaxRates = Data(:,3);
subplot(2,1,1); hold on; grid on; box on
%plot(yearly_month_index,TaxRates(1:af),'kx')
plot(yearly_month_index,TaxRates(1:af),[marker, colore])
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('tax rates (%)','fontsize',font_sz)
%title('Central Bank aggregate data','fontsize',font_sz)
legend('FT','QE','location','Best')
set(gca,'xlim',[0, 12*af])
set(gca,'ylim',[0.04, 0.11])

clear Data

Data = load([Pat, 'CentralBank_daily_balance_sheet.txt']);
FIAT_MONEY_GOVS = Data(:,2);
FIAT_MONEY_BANKS = Data(:,3);

subplot(2,1,2); hold on; grid on; box on
plot(daily_month_index,FIAT_MONEY_GOVS(1:tf),colore,'linewidth',line_width)
%plot(daily_month_index,FIAT_MONEY_BANKS(1:tf),[colore, '-.'])
legend('FT','QE','location','Best')
set(gca,'xtick',monthly_index,'fontsize',font_sz)
xlabel('months','fontsize',font_sz)
ylabel('Central Bank fiat money to Gov (€)','fontsize',font_sz)
%title('Central Bank aggregate data','fontsize',font_sz)
set(gca,'xlim',[0, mf])

clear Data

if print_flag
    print('-dpsc2','figure12.eps')
end

figure(132); hold on; grid on; box on
plot(FIAT_MONEY_GOVS+FIAT_MONEY_BANKS,colore)

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
