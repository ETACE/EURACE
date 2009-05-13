#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"


/************Government Role: Finance********************************/




int Government_read_data_from_Eurostat()
{
START_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP

COUNTRY_WIDE_MEAN_WAGE = mean_wage_for_government_message->mean_wage;


FINISH_MEAN_WAGE_FOR_GOVERNMENT_MESSAGE_LOOP

return 0;	
}


int Government_read_tax_payment()
{
	

	NUM_UNEMPLOYED = 0;
	
	TAX_REVENUES =0.0;

	START_TAX_PAYMENT_MESSAGE_LOOP
		
		TAX_REVENUES += tax_payment_message->tax_payment;

		
	FINISH_TAX_PAYMENT_MESSAGE_LOOP	

	PAYMENT_ACCOUNT += TAX_REVENUES;
	
	return 0;
}

int Government_send_unemployment_benefit_payment()
{
	
	double unemployment_payment;
	NUM_UNEMPLOYED = 0;
	
	TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT=0.0;

	//Start message loop 
	START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
	
	
	NUM_UNEMPLOYED++;
	//Compute the individual unemployment benefit payment as a fraction of the last labour income
	
	
	if(unemployment_notification_message->last_labour_income*UNEMPLOYMENT_BENEFIT_PAYMENT > COUNTRY_WIDE_MEAN_WAGE*0.5 )
	{
	unemployment_payment = unemployment_notification_message->last_labour_income*UNEMPLOYMENT_BENEFIT_PAYMENT;
		//Send message to household
	}else
		
	{
		
		unemployment_payment =  COUNTRY_WIDE_MEAN_WAGE*0.5;	
		
	}
		//add_unemployment_benefit_message(ID,unemployment_notification_message->id,unemployment_payment);
		
	TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT+=unemployment_payment; 	
		
	FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
	// Update the paymment account
	PAYMENT_ACCOUNT -= TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT;
	
	return 0;
}

int Government_send_account_update()
{
	// Update of payment account due to the realized unemployment benefits
	


	// At the very end of agent government: update the bank account

	// If bank account has a negative balance: pay interests
	if(PAYMENT_ACCOUNT <0)
	{
	TOTAL_INTEREST_PAYMENT=(-1)*PAYMENT_ACCOUNT*INTEREST_RATE;
	PAYMENT_ACCOUNT-=TOTAL_INTEREST_PAYMENT;
	TOTAL_DEBT= -PAYMENT_ACCOUNT; 
	}else
	{
	TOTAL_DEBT=0;
	}	
	add_bank_account_update_message(ID, BANK_ID, PAYMENT_ACCOUNT);
	
	return 0;
}



int Government_send_tax_rates()
{
	
	if(PAYMENT_ACCOUNT<0)
	{
	TAX_RATE_CORPORATE+=0.01;
	TAX_RATE_HH_LABOUR+=0.01; 
	TAX_RATE_HH_CAPITAL+=0.01;
	}else if(PAYMENT_ACCOUNT>1000)
	{
	TAX_RATE_CORPORATE-=0.01;
	TAX_RATE_HH_LABOUR-=0.01; 
	TAX_RATE_HH_CAPITAL-=0.01;

	}
	
	
	add_government_tax_rates_message(ID, TAX_RATE_CORPORATE, TAX_RATE_HH_LABOUR, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
	
	return 0;	
}

int Government_idle()
{
	
	return 0;
}
