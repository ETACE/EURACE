#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"


/************Government Role: Finance********************************/
int Government_idle()
{
	return 0;
}

int Government_send_policy_announcements()
{	
	//add announcements
	add_government_tax_rates_message(ID, TAX_RATE_CORPORATE, TAX_RATE_HH_LABOUR, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
	add_unemployment_benefit_announcement(ID, UNEMPLOYMENT_BENEFIT_PCT);
	add_transfer_payment_announcement(ID, TRANSFER_PAYMENT);
	add_subsidy_payment_announcement(ID, SUBSIDY_PAYMENT);
	
	return 0;	
}

int Government_read_tax_payment()
{	
	//Reset the monthly tax counter
	MONTHLY_TAX_REVENUES =0.0;

	START_TAX_PAYMENT_MESSAGE_LOOP
		
		MONTHLY_TAX_REVENUES += tax_payment_message->tax_payment;
		
	FINISH_TAX_PAYMENT_MESSAGE_LOOP	

	PAYMENT_ACCOUNT += MONTHLY_TAX_REVENUES;
	YEARLY_TAX_REVENUES += MONTHLY_TAX_REVENUES;
	
	return 0;
}

/* \fn: int Government_calc_unemployment_benefit_payment()
 * \brief Monthly counter of total unemployment benefit payments.
 * TODO:
 * In household UNEMPLOYMENT_NOTIFICATION_MESSAGE
 * Instead of reading the msg from gov:
 * - read general GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT
 * - let HH compute its own unemployment benefit payment
 */
int Government_read_unemployment_benefit_applications()
{
	
	double unemployment_payment;
	NUM_UNEMPLOYED = 0;
	
	MONTHLY_UNEMPLOYMENT_BENEFIT_PAYMENT=0.0;

	//Start message loop 
	START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
		
		NUM_UNEMPLOYED++;
		
		//Compute the individual unemployment benefit payment as a fraction of the last labour income		
		//if unemployment benefit is larger than the mean wage:
		if(unemployment_notification_message->last_labour_income*GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT > COUNTRY_WIDE_MEAN_WAGE*0.5 )
		{		
			unemployment_payment = unemployment_notification_message->last_labour_income*GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT;	
			//unemployment_payment = 0.8;
		}
		else	
		{
			//if unemployment benefit is below the mean wage: pay 0.5 * MEAN_WAGE
			unemployment_payment =  COUNTRY_WIDE_MEAN_WAGE*0.5;	
			//unemployment_payment = 0.8;
		}
		MONTHLY_UNEMPLOYMENT_BENEFIT_PAYMENT += unemployment_payment; 	
		TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT += unemployment_payment; 	
		
	FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
	
	// Update the payment account
	PAYMENT_ACCOUNT -= TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT;
	
	return 0;
}

/* \fn: int Government_calc_transfer_payment()
 * \brief Yearly counter
 */
int Government_read_transfer_applications()
{
	int sum;
	
	TOTAL_TRANSFER_PAYMENT =0.0;
	
	//Start message loop 
	sum=0;
	START_TRANSFER_PAYMENT_NOTIFICATION_MESSAGE_LOOP
		if(transfer_payment_notification_message->gov_id==ID) sum++;		
	FINISH_TRANSFER_PAYMENT_NOTIFICATION_MESSAGE_LOOP
	
	TOTAL_TRANSFER_PAYMENT =sum*TRANSFER_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= TOTAL_TRANSFER_PAYMENT;

	return 0;
}
	
/* \fn: int Government_calc_subsidy_payment()
 * \brief Yearly counter
 */
int Government_read_subsidy_applications()
{
	int sum;
	
	TOTAL_SUBSIDY_PAYMENT =0.0;
	
	//Start message loop 
	sum=0;
	START_SUBSIDY_PAYMENT_NOTIFICATION_MESSAGE_LOOP
		if(subsidy_payment_notification_message->gov_id==ID) sum++;		
	FINISH_SUBSIDY_PAYMENT_NOTIFICATION_MESSAGE_LOOP
	
	TOTAL_SUBSIDY_PAYMENT =sum*SUBSIDY_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= TOTAL_SUBSIDY_PAYMENT;

	return 0;
}

int Government_budget_accounting()
{
	double in, out;

	//Compute the following:
	TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT =0.0;
	TOTAL_TRANSFER_PAYMENT =0.0;
	TOTAL_SUBSIDY_PAYMENT =0.0;
	TOTAL_BOND_COUPON_PAYMENT =0.0;
	TOTAL_GOV_INVESTMENT =0.0;
	TOTAL_GOV_CONSUMPTION =0.0;
	GOV_INTEREST_RATE = 1.0;
	
	
	//Interest on debt
		TOTAL_INTEREST_PAYMENT = GOV_INTEREST_RATE*TOTAL_DEBT;
	
	//Items that have already been added to the payment_account
		in = YEARLY_TAX_REVENUES;

	//Items that have already been subtracted from the payment_account
		out = TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT +
		TOTAL_TRANSFER_PAYMENT +
		TOTAL_BOND_COUPON_PAYMENT +
		TOTAL_INTEREST_PAYMENT +
		TOTAL_GOV_INVESTMENT +
		TOTAL_GOV_CONSUMPTION;
		
	//Compute budget deficit
		BUDGET_DEFICIT = in - out;
		
	//Debt accounting
		TOTAL_DEBT += BUDGET_DEFICIT;
		
	//Monetary policy rule
		TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*BUDGET_DEFICIT;
		TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*BUDGET_DEFICIT;
		
	//Fiscal policy rule
		if(PAYMENT_ACCOUNT<0)
		{
			TAX_RATE_CORPORATE  += 0.01;
			TAX_RATE_HH_LABOUR  += 0.01; 
			TAX_RATE_HH_CAPITAL += 0.01;
		}else if(PAYMENT_ACCOUNT>1000)
		{
			TAX_RATE_CORPORATE  -= 0.01;
			TAX_RATE_HH_LABOUR  -= 0.01; 
			TAX_RATE_HH_CAPITAL -= 0.01;
		}

	return 0;
}

int Government_read_data_from_Eurostat()
{
	//Read mean wage
	START_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP
		COUNTRY_WIDE_MEAN_WAGE = mean_wage_for_government_message->mean_wage;
	FINISH_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP

	//Read national GDP
	START_REGION_GDP_FOR_GOVERNMENT_MESSAGE_LOOP
	for (i=0; i<LIST_OF_REGIONS->size; i++)
	{
		//region_gdp_for_government_message(region_id, gdp);
		if(region_gdp_for_government_message->region_id==LIST_OF_REGIONS.array[i].region_id)
		{
			GDP += region_gdp_for_government_message->gdp;
		}
	}
	FINISH_REGION_GDP_FOR_GOVERNMENT_MESSAGE_LOOP
	
	return 0;	
}


int Government_send_account_update()
{
		// At the very end of agent government: update the bank account
		add_central_bank_account_update_message(ID, PAYMENT_ACCOUNT);
		
	return 0;
}


int Government_set_policy()
{
		
	BUDGET_FORECAST = GOV_POLICY_BUDGET_PCT*GDP;
	
	//Set the following policies:
	
	//Determine new unemployment benefit percentage
	//GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT
	//Send message to all
	//add_unemployment_benefit_announcement_message(ID, GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT);

	//Determine new transfer payment
	//TRANSFER_PAYMENT
	//Send message to all
	//add_transfer_payment_announcement_message(ID, TRANSFER_PAYMENT);
	
	//Determine new transfer payment
	//SUBSIDY_PAYMENT
	//Send message to all
	//add_subsidy_payment_announcement_message(ID, SUBSIDY_PAYMENT);

	//Determine new government investment
	// TOTAL_GOV_INVESTMENT
	
	//Distribute total per firm investment
	// GOV_INVESTMENT
	//Send message to all
	//add_gov_investment_announcement_message(ID, GOV_INVESTMENT);

	//Determine new government consumption
	// TOTAL_GOV_CONSUMPTION
	//Distribute total per firm consumption
	// GOV_CONSUMPTION
	//Send message to all
	//add_gov_consumption_announcement_message(ID, GOV_CONSUMPTION);

	return 0;
}

int Government_yearly_resetting()
{
	//Reset the yearly counters:
	YEARLY_TAX_REVENUES =0.0;
	TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT =0.0;
	TOTAL_TRANSFER_PAYMENT =0.0;
	TOTAL_SUBSIDY_PAYMENT =0.0;
	TOTAL_BOND_COUPON_PAYMENT =0.0;
	TOTAL_GOV_INVESTMENT =0.0;
	TOTAL_GOV_CONSUMPTION =0.0;
	
	return 0;
}

