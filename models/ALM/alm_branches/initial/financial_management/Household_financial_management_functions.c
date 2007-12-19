#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"
#include "math.h"

/************Household Role: Financial Management********************************/
/*
 * TODO:
 * 1. update code using capitalized variable names
 * 2. function names at bottom: change CamelCaps into camel_caps names.
 */


//Household_calc_financial_management()
int Household_compute_income_and_financial_needs()
{

	double income_account=get_income_account();   //the running income account
	double payment_account=get_payment_account(); //the payment account
	double wage_income=get_wage_income();         // the wage payment from the firm
	double capital_income= get_capital_income();  // the capital gain on the asset portfolio
	double gross_income=0.0;                      //Total gross income: labour income, capital income
	double tax_provision=0.0;
	double leftover_consumption_budget=get_leftover_consumption_budget(); //Left-over budget from previous month (read from memory)
	double net_income=0.0;                        //Total net income for this month
	
	double savings_account_diff=0.0;              //Savings Account differential: addition
	double savings_account=get_savings_account();
	
	double total_budget=0.0;
	double asset_wealth=0.0;                //Total asset value evaluated at current market prices
	double cash_on_hands=0.0;                //Value of all liquid assets: payment_account, savings_account, asset_portfolio
	
	double consumption_ratio=get_consumption_ratio();
	double total_consumption_budget=0.0;    //Total fraction of cash_on_hands that is allocated to consumption expenditure this month
	double weekly_consumption_budget=0.0;   //Transformation of the total_consumption_budget to weekly budget
	double financial_needs=0.0;             //Total financial needs that are not covered by the cash_on_hands: 
	double financial_surplus=0.0;           //Financial surplus
	double add_financial_needs=0.0;
	
	double current_debt=get_current_debt();
	double target_debt=0.0;
	double interest_payment=0.0;            //Interest payments on outstanding debts
	double debt_repayment=0.0;              //Value of debt repayments (equal to current_debts?)
	double loan_application=0.0;            //Value of new loans to obtain with the bank
	
	double asset_ratio=get_asset_ratio();
	double asset_budget=0.0;                //Budget allocation for expenditure on the asset market
	
	
	//Total gross income: labour income and capital income
	gross_income = wage_income + capital_income;
	
	//Compute taxes
	tax_provision = income_tax_rate*gross_income;
	
	//Compute net income
	net_income = (1-income_tax_rate)*gross_income+leftover_consumption_budget;
	
	//Additional savings from net income
	savings_account_diff=0; //if no savings
	/* C-CODE */
	// savings_account_diff= ; //if some savings
	
	
	savings_account += savings; 
	
	//Total budget
	total_budget=net_income-savings;
	
	//Current asset wealth, evaluated at current market prices
	/* C-CODE */
	// asset_wealth =
	
	//Cash-on-hands
	cash_on_hands = total_budget + asset_wealth;
	
	//Consumption budget
	total_consumption_budget=consumption_ratio*total_budget;
	weekly_consumption_budget=total_consumption_budget/4;
	
	//Financial needs/surplusses
	financial_needs = max(0, total_consumption_budget-cash_on_hands)
	financial_surplus = max(0, cash_on_hands-total_consumption_budget);
	
	/******************************* NO HOUSEHOLD CREDIT YET ************************************/
	//Interest payments on outstanding debts
	//interest_payments=interest*current_debt;
	
	//Interest payment message to bank
	//add_interest_payment_message(household_id, bank_id, interest_payments, range, x, y, z);
	//payment_account -= interest_payments;
	
	//Debt repayments
	//debt_repayments=current_debt;
	
	//Debt repayment message to bank:
	//add_debt_repayment_message(household_id, bank_id, debt_repayments, range, x, y, z);
	//payment_account -= debt_repayments;
	
	//New loans
	//loan_application=min(financial_needs, max_debt);
	
	//Additional financial needs
	//add_financial_needs = max(0,financial_needs-loan_application);
	
	/********************************************************************************************/
	
	
	//Allocation of funds to the asset market
	asset_budget=asset_ratio*total_budget;
	
	
	set_income_account(income_account);
	set_payment_account(payment_account);
	set_gross_income(gross_income);
	set_tax_payment(tax_payment);
	set_net_income(net_income);
	set_savings_account(savings_account);
	set_total_budget(total_budget);
	set_asset_wealth(asset_wealth);
	set_cash_on_hands(cash_on_hands);
	set_total_consumption_budget(total_consumption_budget);
	set_weekly_consumption_budget(weekly_consumption_budget);
	set_financial_needs(financial_needs);
	
	set_asset_budget(asset_budget);
	set_target_asset_portfolio(target_asset_portfolio);
/*
	set_target_debt(target_debt);
	set_interest_payment(interest_payment);
	set_debt_repayment(debt_repayment);
	set_loan_application(loan_application);
*/
    return 0;
}


int HouseholdCalculateMonthlyTaxes()
{
    return 0;
}

int HouseholdCalculateNetIncome()
{
    return 0;
}


int HouseholdCalculateTotalBudget()
{
    return 0;
}

int HouseholdCalculateAssetWealth()
{
    return 0;
}


int HouseholdCalculateCashOnHands()
{
    return 0;
}


int HouseholdCalculateConsumptionBudget()
{
    return 0;
}

int HouseholdCalculateFinancialNeedsMonthly()
{
    return 0;
}

/// ConsumptionMarket role
///asset market role

int HouseholdUpdateAssetPortfolio()
{
    return 0;
}


int HouseholdCalculateFinancialNeedsDaily()
{
    return 0;
}


int HouseholdEntryDecision()
{
    return 0;
}

int HouseholdCalculateAssetBudget()
{
    return 0;
}


int HouseholdCalculateFirmBondOrders()
{
    return 0;
}

int HouseholdCalculateGovernmentBondOrders()
{
    return 0;
}

int HouseholdCalculateFirmStockOrders()
{
    return 0;
}
