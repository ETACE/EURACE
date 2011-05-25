clc
clear all
%close all

Pat = 'E:\research\X-EURACE\models\EURACE_Model\trunk\Integrated_Model_1.0\its\seed_1234\qe1_alpha5\its\';

BanksBalanceSheet = load([Pat, 'banks_daily_balance_sheet.txt']);
FirmsBalanceSheet = load([Pat, 'firms_balance_sheet.txt']);

T = 3800;

for d=1:T
    Idx = find(BanksBalanceSheet(:,1)==d);
    TOTAL_LOANS(d,1) = sum(BanksBalanceSheet(Idx,5));
    clear Idx
end

for d=1:T
    Idx = find(FirmsBalanceSheet(:,1)==d);
    TOTAL_DEBT(d,1) = sum(FirmsBalanceSheet(Idx,9));
end

figure(1); hold on; grid on
plot(TOTAL_LOANS,'g')
plot(TOTAL_DEBT,'--k')

figure(2); hold on; grid on
Difference = TOTAL_LOANS - TOTAL_DEBT;
plot(Difference)