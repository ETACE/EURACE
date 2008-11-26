#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/


int Household_receive_data()
{

return 0;

}

/**********************************Household Role: Public Sector *********************/

/** \fn Household_read_policy_announcements()
 * \brief This function reads messages send by the government announcing tax rates, benefits, transfer payments and subsidies.
 */
int Household_read_policy_announcements()
{
	/*Read tax announcement*/
	/*Read unemployment benefit announcement*/
	/*Read transfer announcement*/
	/*Read subsidy announcement*/
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    if(policy_announcement_message->gov_id == GOV_ID)
    {
    	TAX_RATE_HH_LABOUR  = policy_announcement_message->tax_rate_hh_labour;
	    TAX_RATE_HH_CAPITAL = policy_announcement_message->tax_rate_hh_capital;

	    /*This is the endogeneous unemployment percentage (the global parameter is: GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT)*/
    	UNEMPLOYMENT_BENEFIT_PCT = policy_announcement_message->unemployment_benefit_pct; 
    	TRANSFER_PAYMENT = policy_announcement_message->hh_transfer_payment;
    	SUBSIDY_PAYMENT = policy_announcement_message->hh_subsidy_payment;
    }
	FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP

	return 0;		
}

/** \fn Household_send_unemployment_benefit_notification()
 * \brief This function sends a message to the government in case of being unemployed that contains the last earned labour income
 * The government then can calculate the unemployment benefit payment based on the last labour income and subtract the amount from its payment account.
 * The household uses the environment parameter GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT to calculate its own unemployment benefit as well (there is no need for a message from government). 
 */
int Household_send_unemployment_benefit_notification()
{
	double mean_income = 0.0;
	
	/*Add unemployment_benefit message */
	add_unemployment_notification_message(GOV_ID,LAST_LABOUR_INCOME);

	/*Add unemployment_benefit to account */		
	PAYMENT_ACCOUNT +=  UNEMPLOYMENT_BENEFIT_PCT * LAST_LABOUR_INCOME;
	remove_double(&LAST_INCOME,0);	
	add_double(&LAST_INCOME, UNEMPLOYMENT_BENEFIT_PCT * LAST_LABOUR_INCOME);
	
		
	/*Compute a mean income of the last four month*/
	for(int i = 0; i < 4;i++)
	{
		mean_income += LAST_INCOME.array[i];
	}

	MEAN_INCOME = mean_income/4;
	
	//Set the benefit reception day
	DAY_OF_MONTH_RECEIVE_BENEFIT = DAY_OF_MONTH_RECEIVE_INCOME; 
	
	return 0;	
	
}

/** \fn Household_send_subsidy_notification()
 * \brief This function sends a message to the government in case the household applies for a subsidy. 
 */
int Household_send_subsidy_notification()
{
	/*Add subsidy message */
	add_hh_subsidy_notification_message(GOV_ID);
	PAYMENT_ACCOUNT += HH_SUBSIDY_PAYMENT;
		
	return 0;		
}

/** \fn Household_send_transfer_notification()
 * \brief This function sends a message to the government in case the household applies for a transfer. 
 */
int Household_send_transfer_notification()
{
	/*Add transfer message */
	add_hh_transfer_notification_message(GOV_ID);
	PAYMENT_ACCOUNT += TRANSFER_PAYMENT;
		
	return 0;		
}

/** \fn Household_send_tax_payment()
 * \brief Household pays the income taxes 
 */
int Household_send_tax_payment()
{
	double additional_tax;
	additional_tax =0.0;
	
	//Additional tax: repayment of the already received monthly unemployment benefits if recently re-employed
	if (DAY_OF_MONTH_RECEIVE_BENEFIT != DAY_OF_MONTH_RECEIVE_INCOME )
	{ 
		additional_tax = ((DAY_OF_MONTH_RECEIVE_BENEFIT + (20-DAY_OF_MONTH_RECEIVE_INCOME)%20)/20)
		 					* LAST_INCOME.array[3];
	}	
		
	
	/*Compute the total taxes*/
	TOTAL_TAXES = additional_tax + CUM_TOTAL_DIVIDENDS*TAX_RATE_HH_CAPITAL + WAGE*TAX_RATE_HH_LABOUR;

	/*Send a message to the government*/
	add_tax_payment_message(ID, GOV_ID,TOTAL_TAXES);
	
	/*Reduce the payment account*/
	PAYMENT_ACCOUNT-=TOTAL_TAXES;
	
	/*Setting the counter of monthly dividends = 0*/
	CUM_TOTAL_DIVIDENDS=0;
	
	
	return 0;

}

/** \fn Household_send_data_to_Eurostat()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Household_send_data_to_Eurostat()
{	
	add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
	WAGE, SPECIFIC_SKILL);
		
	return 0;
}

