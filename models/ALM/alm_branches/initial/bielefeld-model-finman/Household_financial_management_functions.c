#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"

/************Household Role: Financial Management********************************/

//int Household_financial_planning()
int Household_financial_planning()
{
	//Total gross income: labour income and capital income
//	GROSS_INCOME = WAGE_INCOME + CAPITAL_INCOME;
	
	//Compute taxes
//	TAX_PAYMENT = INCOME_TAX_RATE*GROSS_INCOME;
	
	//Send tax to goverment
//	add_tax_payment_message(ID, gov_id, TAX_PAYMENT, MSGDATA);
	
	//Compute net income
//	INCOME_ACCOUNT = (1-INCOME_TAX_RATE)*GROSS_INCOME + LEFTOVER_CONSUMPTION_BUDGET;
	
	//If no savings
//	SAVINGS_PROPENSITY =0;
	
	//Savings from net income
//	SAVINGS = SAVINGS_PROPENSITY * INCOME_ACCOUNT;	
	
//	SAVINGS_ACCOUNT += SAVINGS; 
	
	//Total budget: transfer funds from income account to payment account, minus savings
//	PAYMENT_ACCOUNT = INCOME_ACCOUNT - SAVINGS;
	
	//Reset the income account
//	INCOME_ACCOUNT = 0;
	
	//Current asset wealth, evaluated at current market prices
	/* C-CODE */
	// ASSET_WEALTH =
	
	//Cash-on-hands
//	CASH_ON_HANDS = PAYMENT_ACCOUNT + ASSET_WEALTH;
	
	//Consumption budget
//	if(CASH_ON_HANDS > MEAN_INCOME)
//	{
//		TOTAL_CONSUMPTION_BUDGET = CASH_ON_HANDS + EXCESS_CONSUMPTION_PROPENSITY*(CASH_ON_HANDS - MEAN_INCOME);
//	}
//	else
//	{
//		TOTAL_CONSUMPTION_BUDGET = CASH_ON_HANDS;
//	}
	
	//Weekly consumption budget
//	WEEKLY_CONSUMPTION_BUDGET = TOTAL_CONSUMPTION_BUDGET/4;
	
	//Financial needs and asset_budget
//	FINANCIAL_NEEDS = 0; FINANCIAL_SURPLUS=0;
//	if (TOTAL_CONSUMPTION_BUDGET > CASH_ON_HANDS)
//	{
		//planned consumption superceeds cash_on_hands: sell assets
//		FINANCIAL_NEEDS = TOTAL_CONSUMPTION_BUDGET - CASH_ON_HANDS;
//		ASSET_BUDGET = -FINANCIAL_NEEDS;
//	}
//	else
//	{
		//planned consumption is less than cash_on_hands: use the excess to buy assets
//		FINANCIAL_SURPLUS = max(0, CASH_ON_HANDS-TOTAL_CONSUMPTION_BUDGET);
//		ASSET_BUDGET = FINANCIAL_SURPLUS;
//	}

	
	
	/******************************* NO HOUSEHOLD CREDIT YET ************************************/
	//Interest payments on outstanding debts
	//INTEREST_PAYMENTS=INTEREST*CURRENT_DEBT;
	
	//Interest payment message to bank
	//add_interest_payment_message(household_id, bank_id, INTEREST_PAYMENTS, MSGDATA);
	//PAYMENT_ACCOUNT -= INTEREST_PAYMENTS;
	
	//Debt repayments
	//DEBT_REPAYMENTS=CURRENT_DEBT;
	
	//Debt repayment message to bank:
	//add_debt_repayment_message(household_id, bank_id, DEBT_REPAYMENTS, MSGDATA);
	//PAYMENT_ACCOUNT -= DEBT_REPAYMENTS;
	
	//New loans
	//loan_application=min(FINANCIAL_NEEDS, MAX_DEBT);
	
	//Financial needs
	//EXTERNAL_FINANCIAL_NEEDS = max(0,FINANCIAL_NEEDS-LOAN_APPLICATION);
	
	/********************************************************************************************/
	
    return 0;
}

int Household_compute_gross_income()
{
	return 0;
}

int Household_compute_monthly_taxes()
{
	return 0;
}

int Household_compute_net_income()
{
	return 0;
}

int Household_compute_asset_wealth()
{
	return 0;
}

int Household_compute_total_budget()
{
	return 0;
}

int Household_compute_cash_on_hand()
{
	return 0;
}

int Household_update_asset_portfolio()
{
	return 0;
}

int Household_compute_cash_on_hands()
{
	return 0;
}

int Household_compute_consumption_budget()
{
	return 0;
}

int Household_compute_financial_needs_daily()
{
	return 0;
}

int Household_compute_financial_needs_monthly()
{
	return 0;
}

int Household_entry_decision()
{
	return 0;
}

int Household_compute_asset_budget()
{
	return 0;
}

int Household_compute_and_send_stock_orders()
{
	return 0;
}

int Household_read_stock_transactions()
{
	return 0;
}

int Household_compute_and_send_bond_orders()
{
	return 0;
}

int Household_read_bond_transactions()
{
	return 0;
}

int Household_compute_and_send_gov_bond_orders()
{
	return 0;
}

int Household_read_gov_bond_transactions()
{
	return 0;
}
