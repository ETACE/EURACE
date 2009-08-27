//For trunk model
#include <math.h>
#include "../header.h"
#include "../Government_agent_header.h"

//For Isolated model
//#include <math.h>
//#include "header.h"
//#include "Government_agent_header.h"
//#include "../my_library_header.h"

//#define NO_REGIONS_PER_GOV 2 //number of regions per gov

/************Government Role: Finance********************************/
int Government_idle()
{
    return 0;
}

/* \fn: int Government_send_policy_announcements()
 * \brief Function to send yearly policy announcement message.
 */
int Government_send_policy_announcements()
{   
    //add announcements
    add_policy_announcement_message(ID, TAX_RATE_CORPORATE, TAX_RATE_HH_LABOUR, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT, UNEMPLOYMENT_BENEFIT_PCT, HH_SUBSIDY_PAYMENT, FIRM_SUBSIDY_PAYMENT, HH_TRANSFER_PAYMENT, FIRM_TRANSFER_PAYMENT);
    
    return 0;   
}

/* \fn: int Government_read_tax_payments()
 * \brief Function to read the tax revenues and store the monthly and yearly totals.
 */
int Government_read_tax_payments()
{   
    double sum =0;
    START_TAX_PAYMENT_MESSAGE_LOOP
        
        MONTHLY_TAX_REVENUES += tax_payment_message->tax_payment;
        sum+= tax_payment_message->tax_payment;
    FINISH_TAX_PAYMENT_MESSAGE_LOOP 

   PAYMENT_ACCOUNT += sum;
    
    
    return 0;
}

/* \fn: int Government_read_unemployment_benefit_notifications()
 * \brief Counter of the unemployment benefit messages, monthly and yearly totals of the unemployment benefit payments.
 */
int Government_read_unemployment_benefit_notifications()
{
    double sum, unemployment_payment, rationing_rate;
    /*
    NUM_UNEMPLOYED = 0;
    
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

    MONTHLY_BENEFIT_PAYMENT += sum;    
    YEARLY_BENEFIT_PAYMENT += sum;     

    // Update the payment account
    
    PAYMENT_ACCOUNT -= sum;
    */
	
	
	
	NUM_UNEMPLOYED = 0;
	    
	    //Start message loop
	    sum=0.0;
	    START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
	        
	        NUM_UNEMPLOYED++;
	        
	    unemployment_payment = unemployment_notification_message->last_labour_income*UNEMPLOYMENT_BENEFIT_PCT
	    sum += unemployment_payment;
	    
	        
	    FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
	    
	    
	    if(sum<=PAYMENT_ACCOUNT)
	    {
	    
	    	 UNEMPLOYMENT_BENEFIT_RATIONING_PERCENTAGE = 0.0;
	    }else
	    {
	    	UNEMPLOYMENT_BENEFIT_RATIONING_PERCENTAGE = 1 - PAYMENT_ACCOUNT/sum;	
	     }
	    
		sum = (1- UNEMPLOYMENT_BENEFIT_RATIONING_PERCENTAGE)*sum;
		MONTHLY_BENEFIT_PAYMENT += sum;    
		YEARLY_BENEFIT_PAYMENT += sum;

	    // Update the payment account
	    
	    PAYMENT_ACCOUNT -= sum;
	    
	    //Send message to household
	    
	    add_hh_unemployment_benefit_pay_out_message(ID,UNEMPLOYMENT_BENEFIT_RATIONING_PERCENTAGE);
	
    return 0;
}

/* \fn: int Government_read_transfer_notifications()
 * \brief Counter of the transfer notification messages, monthly and yearly totals of the transfer payments.
 */
int Government_read_transfer_notifications()
{
    int sum;
        
    //Start message loop 
    sum=0;
    START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_transfer_notification_message->gov_id==ID)
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
        if(firm_transfer_notification_message->gov_id==ID)
            sum++;
    FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;
    YEARLY_TRANSFER_PAYMENT += sum*FIRM_TRANSFER_PAYMENT;   

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*FIRM_TRANSFER_PAYMENT;
    
    
    return 0;
}
    
/* \fn: int Government_read_subsidy_notifications()
 * \brief Counter of the subsidy notification messages, monthly and yearly totals of the subsidy payments.
 */
int Government_read_subsidy_notifications()
{
    int sum;
        
    //Start message loop 
    sum=0;
    START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    //Filter: m.gov_id==a.id
        if(hh_subsidy_notification_message->gov_id==ID)
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
        if(firm_subsidy_notification_message->gov_id==ID)
            sum++;
    FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
    
    MONTHLY_SUBSIDY_PAYMENT += sum*FIRM_SUBSIDY_PAYMENT;
    YEARLY_SUBSIDY_PAYMENT += sum*FIRM_SUBSIDY_PAYMENT;     

    // Update the payment account
    PAYMENT_ACCOUNT -= sum*FIRM_SUBSIDY_PAYMENT;

    return 0;
}



/* \fn: int Government_send_account_update()
 * \brief Function to send the payment_account value to the Central Bank.
 */
int Government_send_account_update()
{
        // At the very end of agent government: update the bank account
        add_central_bank_account_update_message(ID, PAYMENT_ACCOUNT);
        
        

    return 0;
}

/* \fn: int Government_monthly_budget_accounting()
 * \brief Function to perform accounting at the end of each month.
 */
int Government_monthly_budget_accounting()
{
    double in, out;
    

    //Compute the following: the interest rate is the base rate of the Central Bank
    //GOV_INTEREST_RATE = (double) 0.05/12.0;
    //GOV_INTEREST_RATE = CB_BASE_RATE/12.0;
    
    YEARLY_TAX_REVENUES += MONTHLY_TAX_REVENUES;
    
    //Items that have already been added to the payment_account
        in = MONTHLY_TAX_REVENUES;
        MONTHLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account
        out = MONTHLY_BENEFIT_PAYMENT +
        MONTHLY_TRANSFER_PAYMENT +
        MONTHLY_BOND_INTEREST_PAYMENT +
        MONTHLY_INVESTMENT_EXPENDITURE +
        MONTHLY_CONSUMPTION_EXPENDITURE;
        
        MONTHLY_EXPENDITURE = out;
        
    //Compute budget deficit
        MONTHLY_BUDGET_BALANCE = in - out;
        
    //Debt accounting: if the balance>0 debt decreases, if balance<0, debt increases.
        //Debt>0 means a debt, Debt<0 means a surplus.
        TOTAL_DEBT -= MONTHLY_BUDGET_BALANCE;
       // PAYMENT_ACCOUNT += MONTHLY_BUDGET_BALANCE;
        
        //Check: value of payment account should be equal to total_debt:
        //if (abs(TOTAL_DEBT + PAYMENT_ACCOUNT))> 0.001)

        if (PRINT_DEBUG && ((TOTAL_DEBT + PAYMENT_ACCOUNT) != 0.0))
            fprintf(stdout,"\n ERROR in Government: Total debt %2.5f is not equal to payment account %2.5f\n\n", TOTAL_DEBT, PAYMENT_ACCOUNT);
        
    //Monetary policy rule
        TOTAL_MONEY_FINANCING=0;
        TOTAL_BOND_FINANCING=0;
        if (MONTHLY_BUDGET_BALANCE<0.0)
        {
            TOTAL_MONEY_FINANCING = GOV_POLICY_MONEY_FINANCING_FRACTION*abs(MONTHLY_BUDGET_BALANCE);
            TOTAL_BOND_FINANCING = (1-GOV_POLICY_MONEY_FINANCING_FRACTION)*abs(MONTHLY_BUDGET_BALANCE);
        }
    return 0;
}



/* \fn: int Government_monthly_resetting()
 * \brief Monthly resetting of counters.
 */
int Government_monthly_resetting()
{
    //Reset the yearly counters:
    MONTHLY_TAX_REVENUES =0.0;
    MONTHLY_BENEFIT_PAYMENT =0.0;
    MONTHLY_TRANSFER_PAYMENT =0.0;
    MONTHLY_SUBSIDY_PAYMENT =0.0;
    MONTHLY_BOND_INTEREST_PAYMENT =0.0;
    MONTHLY_INVESTMENT_EXPENDITURE =0.0;
    MONTHLY_CONSUMPTION_EXPENDITURE =0.0;
    
    return 0;
}

/* \fn: int Government_yearly_budget_accounting()
 * \brief Function to perform accounting at the end of each year.
 */
int Government_yearly_budget_accounting()
{
    double in, out;

    //Compute the following:
   // GOV_INTEREST_RATE = 0.05;
    //GOV_INTEREST_RATE = CB_BASE_RATE;

    //Items that have already been added to the payment_account
        in = YEARLY_TAX_REVENUES;
        YEARLY_INCOME = in;
        
    //Items that have already been subtracted from the payment_account
        out = YEARLY_BENEFIT_PAYMENT +
        YEARLY_TRANSFER_PAYMENT +
        YEARLY_BOND_INTEREST_PAYMENT +
        YEARLY_INVESTMENT_EXPENDITURE +
        YEARLY_CONSUMPTION_EXPENDITURE;
        
        YEARLY_EXPENDITURE = out;
        
    //Compute budget deficit
        YEARLY_BUDGET_BALANCE = in - out;
                
    return 0;
}

/* \fn: int Government_yearly_resetting()
 * \brief Yearly resetting of counters.
 */
int Government_yearly_resetting()
{
    //Reset the yearly counters:
    YEARLY_TAX_REVENUES =0.0;
    YEARLY_BENEFIT_PAYMENT =0.0;
    YEARLY_TRANSFER_PAYMENT =0.0;
    YEARLY_SUBSIDY_PAYMENT =0.0;
    YEARLY_BOND_INTEREST_PAYMENT =0.0;
    YEARLY_INVESTMENT_EXPENDITURE =0.0;
    YEARLY_CONSUMPTION_EXPENDITURE =0.0;
    
    return 0;
}

/* \fn: int Government_read_data_from_Eurostat()
 * \brief Function to read data from Eurostat.
 */
int Government_read_data_from_Eurostat()
{
    int i;
    double old_gdp;
    
    old_gdp=GDP;
    GDP=0.0;
    COUNTRY_WIDE_MEAN_WAGE=0.0;
    
    START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
        for (i=0; i<NO_REGIONS_PER_GOV; i++)
        {
            if(data_for_government_message->region_id==LIST_OF_REGIONS.array[i])
            {
                //Read region mean wage
                COUNTRY_WIDE_MEAN_WAGE += data_for_government_message->mean_wage;
                //Read region GDP
                GDP += data_for_government_message->gdp;
            }
        }
    FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
    
    //Set country-wide mean wage as avg of region's mean wages
    COUNTRY_WIDE_MEAN_WAGE = COUNTRY_WIDE_MEAN_WAGE/NO_REGIONS_PER_GOV;
    
    //Set GDP growth rate
    if (old_gdp > 0.0)
        GDP_GROWTH = GDP/old_gdp;
    else GDP_GROWTH = 1.0; 
        
    return 0;   
}

/* \fn: int Government_set_policy()
 * \brief Function to set policy rules: income forecast and expenditure budget.
 */
int Government_set_policy()
{   
/*      
    //Fiscal policy rule 1

        //increase tax rates when in debt
        if(PAYMENT_ACCOUNT<0)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(PAYMENT_ACCOUNT>1000)
        {
            //decrease tax rates when in surplus
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }
*/
        //Fiscal policy rule 2
/*
        //increase tax rates when GDP growth > 1.05
        if(GDP_GROWTH>1.05)
        {
            TAX_RATE_CORPORATE  += 0.01;
            TAX_RATE_HH_LABOUR  += 0.01; 
            TAX_RATE_HH_CAPITAL += 0.01;
        }
        else if(GDP_GROWTH<1.01)
        {
            //decrease tax rates when GDP growth < 1.01
            TAX_RATE_CORPORATE  -= 0.01;
            TAX_RATE_HH_LABOUR  -= 0.01; 
            TAX_RATE_HH_CAPITAL -= 0.01;
        }
*/
    
    //Set GDP forecast equal to extrapolation of previous growth rate*GDP
    GDP_FORECAST = GDP_GROWTH*GDP;
    
    //Set income forecast
    YEARLY_INCOME_FORECAST = GDP_GROWTH*YEARLY_INCOME;

    //Set expenditure forecast: counter-cyclical to gdp growth
    YEARLY_EXPENDITURE_BUDGET = GDP_GROWTH*YEARLY_EXPENDITURE;
    
    BUDGET_BALANCE_FORECAST = YEARLY_INCOME_FORECAST - YEARLY_EXPENDITURE_BUDGET;
    
    //Set the following policies:

    //Determine new government consumption
     YEARLY_CONSUMPTION_BUDGET = GOV_POLICY_GDP_FRACTION_CONSUMPTION * GDP_FORECAST;    
     MONTHLY_CONSUMPTION_BUDGET = YEARLY_CONSUMPTION_BUDGET/12;
     
    //Determine new government investment
     YEARLY_INVESTMENT_BUDGET = GOV_POLICY_GDP_FRACTION_INVESTMENT * GDP_FORECAST;
     MONTHLY_INVESTMENT_BUDGET = YEARLY_INVESTMENT_BUDGET/12;
     
    //Determine new transfer payment
    HH_TRANSFER_PAYMENT =0.0;
    FIRM_TRANSFER_PAYMENT =0.0;
    
    //Determine new subsidy payment
    HH_SUBSIDY_PAYMENT =0.0;
    FIRM_SUBSIDY_PAYMENT =0.0;
    
    return 0;
}

