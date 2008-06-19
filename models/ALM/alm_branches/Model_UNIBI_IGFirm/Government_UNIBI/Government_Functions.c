#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"


/************Government Role: Finance********************************/




int Government_read_tax_payment()
{
	

	NUM_UNEMPLOYED = 0;
	int num_employed=0;
	TAX_REVENUES =0.0;

	START_TAX_PAYMENT_MESSAGE_LOOP
		
		TAX_REVENUES += tax_payment_message->tax_payment;

		if(tax_payment_message->agent_status==0)
		{		
		NUM_UNEMPLOYED++; 
		}else if(tax_payment_message->agent_status==1)
		{
		num_employed++;
		}
	FINISH_TAX_PAYMENT_MESSAGE_LOOP	

	PAYMENT_ACCOUNT += TAX_REVENUES;
	
	return 0;
}

int Government_send_unemployment_benefit_payment()
{
	
	

	//Compute UNEMPLOYMENT_BENEFIT_PAYMENT
	//Compute TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT
	
	add_unemployment_benefit_message(ID,UNEMPLOYMENT_BENEFIT_PAYMENT);
	
	//Update of payment account follows when the current num of unemploymed households is known
	return 0;
}

int Government_send_account_update()
{
	// Update of payment account due to the realized unemployment benefits
	TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT = NUM_UNEMPLOYED*UNEMPLOYMENT_BENEFIT_PAYMENT;
	PAYMENT_ACCOUNT -= TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT;


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
	add_bank_account_update_message(ID, BANK_ID, 0);
	
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
