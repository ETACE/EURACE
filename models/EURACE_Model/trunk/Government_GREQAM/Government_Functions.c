#include "../header.h"
#include "../Government_agent_header.h"
//#include "header.h"
//#include "Government_agent_header.h"
#include "../my_library_header.h"

#define REGIONS_PER_GOV 1 //number of regions per gov

/************Government Role: Finance********************************/
int Government_idle()
{
	return 0;
}

int Government_send_policy_announcements()
{	
	//add announcements
	add_policy_announcement_message(ID, TAX_RATE_CORPORATE, TAX_RATE_HH_LABOUR, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT, UNEMPLOYMENT_BENEFIT_PCT, TRANSFER_PAYMENT, SUBSIDY_PAYMENT);
	
	return 0;	
}

int Government_read_tax_payments()
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

/* \fn: int Government_read_unemployment_benefit_notifications()
 * \brief Monthly counter of total unemployment benefit payments.
 */
int Government_read_unemployment_benefit_notifications()
{
	
	double sum, unemployment_payment;
	NUM_UNEMPLOYED = 0;
	
	MONTHLY_UNEMPLOYMENT_BENEFIT_PAYMENT=0.0;

	//Start message loop
	sum=0.0;
	START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
		
		NUM_UNEMPLOYED++;
		
		//Compute the individual unemployment benefit payment as a fraction of the last labour income		
		//if unemployment benefit is larger than the mean wage:
		if(unemployment_notification_message->last_labour_income*UNEMPLOYMENT_BENEFIT_PCT > COUNTRY_WIDE_MEAN_WAGE*0.5 )
		{		
			unemployment_payment = unemployment_notification_message->last_labour_income*UNEMPLOYMENT_BENEFIT_PCT;	
			//unemployment_payment = 0.8;
		}
		else	
		{
			//if unemployment benefit is below the mean wage: pay 0.5 * MEAN_WAGE
			unemployment_payment =  COUNTRY_WIDE_MEAN_WAGE*0.5;	
			//unemployment_payment = 0.8;
		}
		sum += unemployment_payment;
		
	FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP

	MONTHLY_UNEMPLOYMENT_BENEFIT_PAYMENT += sum; 	
	YEARLY_UNEMPLOYMENT_BENEFIT_PAYMENT += sum; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= sum;
	
	return 0;
}

/* \fn: int Government_read_transfer_notifications()
 * \brief Daily counter
 */
int Government_read_transfer_notifications()
{
	int sum;
		
	//Start message loop 
	sum=0;
	START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
	//Filter: m.gov_id==a.id
		//if(transfer_notification_message->gov_id==ID) sum++;
		sum++;
	FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
	
	MONTHLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT;
	YEARLY_TRANSFER_PAYMENT += sum*HH_TRANSFER_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= sum*HH_TRANSFER_PAYMENT;

	//Start message loop 
	sum=0;
	START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
	//Filter: m.gov_id==a.id
		//if(transfer_notification_message->gov_id==ID) sum++;
		sum++;
	FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
	
	MONTHLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;
	YEARLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= sum*FIRM_TRANSFER_PAYMENT;
	
	
	return 0;
}
	
/* \fn: int Government_read_subsidy_notifications()
 * \brief Daily counter
 */
int Government_read_subsidy_notifications()
{
	int sum;
		
	//Start message loop 
	sum=0;
	START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
	//Filter: m.gov_id==a.id
		//if(subsidy_payment_notification_message->gov_id==ID) sum++;
		sum++;
	FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
	
	MONTHLY_SUBSIDY_PAYMENT += sum*HH_SUBSIDY_PAYMENT;
	YEARLY_SUBSIDY_PAYMENT += sum*HH_SUBSIDY_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= sum*HH_SUBSIDY_PAYMENT;

	//Start message loop 
	sum=0;
	START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
	//Filter: m.gov_id==a.id
		//if(subsidy_payment_notification_message->gov_id==ID) sum++;
		sum++;
	FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
	
	MONTHLY_SUBSIDY_PAYMENT += sum*FIRM_SUBSIDY_PAYMENT;
	YEARLY_SUBSIDY_PAYMENT += sum*FIRM_SUBSIDY_PAYMENT; 	

	// Update the payment account
	PAYMENT_ACCOUNT -= sum*FIRM_SUBSIDY_PAYMENT;

	return 0;
}

int Government_budget_accounting()
{
	double in, out;

	//Compute the following:
	YEARLY_UNEMPLOYMENT_BENEFIT_PAYMENT =0.0;
	YEARLY_TRANSFER_PAYMENT =0.0;
	YEARLY_SUBSIDY_PAYMENT =0.0;
	YEARLY_BOND_COUPON_PAYMENT =0.0;
	YEARLY_GOV_INVESTMENT =0.0;
	YEARLY_GOV_CONSUMPTION =0.0;
	GOV_INTEREST_RATE = 0.05;
	
	
	//Interest on debt
		YEARLY_INTEREST_PAYMENT = (1+GOV_INTEREST_RATE)*TOTAL_DEBT;
	
	//Items that have already been added to the payment_account
		in = YEARLY_TAX_REVENUES;

	//Items that have already been subtracted from the payment_account
		out = YEARLY_UNEMPLOYMENT_BENEFIT_PAYMENT +
		YEARLY_TRANSFER_PAYMENT +
		YEARLY_BOND_COUPON_PAYMENT +
		YEARLY_INTEREST_PAYMENT +
		YEARLY_GOV_INVESTMENT +
		YEARLY_GOV_CONSUMPTION;
		
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
	int i;
	
	//Read mean wage
	START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
		COUNTRY_WIDE_MEAN_WAGE = data_for_government_message->mean_wage;
	FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP

	//Read national GDP
	START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
	for (i=0; i<REGIONS_PER_GOV; i++)
	{
		//region_gdp_for_government_message(region_id, gdp);
		if(data_for_government_message->region_id==LIST_OF_REGIONS[i])
		{
			GDP += data_for_government_message->gdp;
		}
	}
	FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
	
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
	GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT = 0.70;

	//Determine new transfer payment
	TRANSFER_PAYMENT =1000;

	
	//Determine new transfer payment
	SUBSIDY_PAYMENT =1000;


	//Determine new government investment
	// YEARLY_GOV_INVESTMENT
	
	//Distribute total per firm investment
	// GOV_INVESTMENT


	//Determine new government consumption
	// YEARLY_GOV_CONSUMPTION
	
	//Distribute total per firm consumption
	// GOV_CONSUMPTION
	
	return 0;
}

int Government_yearly_resetting()
{
	//Reset the yearly counters:
	YEARLY_TAX_REVENUES =0.0;
	YEARLY_UNEMPLOYMENT_BENEFIT_PAYMENT =0.0;
	YEARLY_TRANSFER_PAYMENT =0.0;
	YEARLY_SUBSIDY_PAYMENT =0.0;
	YEARLY_BOND_COUPON_PAYMENT =0.0;
	YEARLY_GOV_INVESTMENT =0.0;
	YEARLY_GOV_CONSUMPTION =0.0;
	
	return 0;
}

