#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"
//#include "../Household_Library_Functions.h"


/**********************************Household Role: Labour Market**********************************/

/** \fn Household_receive_wage()
 * \brief Household receives wage if the household is employed 
 */

int Household_receive_wage()
{
	
	double mean_income = 0;
	
	/*Household reads the wage messages if employed*/
	START_WAGE_PAYMENT_MESSAGE_LOOP

	
		WAGE = wage_payment_message->payment;
		remove_double(&LAST_INCOME,0);
		add_double(&LAST_INCOME,wage_payment_message->payment);
		
		/*Compute a mean income of the last four month*/
		for(int i = 0; i < 4;i++)
		{
			mean_income += LAST_INCOME.array[i];
		}

		MEAN_INCOME= mean_income/4;
		
		/*Add wage on account   */
		PAYMENT_ACCOUNT += wage_payment_message->payment;
		
	CURRENT_PRODUCTIVITY_EMPLOYER = wage_payment_message-> productivity;
	CURRENT_MEAN_SPECIFIC_SKILLS_EMPLOYER =wage_payment_message->average_specific_skills;
	FINISH_WAGE_PAYMENT_MESSAGE_LOOP
	
	
	return 0;
	
}

/** \fn Household_update_specific_skills()
 * \brief Household's specific skills are updated if the household is employed 
 */

int Household_update_specific_skills()
{
	

	if(SPECIFIC_SKILL < CURRENT_PRODUCTIVITY_EMPLOYER)
	{
		
		
		
		SPECIFIC_SKILL = SPECIFIC_SKILL + (CURRENT_PRODUCTIVITY_EMPLOYER - SPECIFIC_SKILL)*((1-pow(0.5,1/(20+0.25*(GENERAL_SKILL-1)*(4-20))))+ 0*CURRENT_MEAN_SPECIFIC_SKILLS_EMPLOYER);


		add_specific_skill_update_message(ID,EMPLOYEE_FIRM_ID,SPECIFIC_SKILL);
			
	}
	
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
    	TRANSFER_PAYMENT = policy_announcement_message->transfer_payment;
    	SUBSIDY_PAYMENT = policy_announcement_message->subsidy_payment;
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

