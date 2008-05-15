#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"


/************Government Role: Finance********************************/

int Government_read_tax_payment()
{
	TAX_REVENUES =0.0;

	START_TAX_PAYMENT_MESSAGE_LOOP
		TAX_REVENUES += tax_payment_message->tax_payment;
	FINISH_TAX_PAYMENT_MESSAGE_LOOP
	
	START_HOUSEHOLD_TAX_PAYMENT_MESSAGE_LOOP
		if(ID == household_tax_payment_messag->gov_id)
		{
			TAX_REVENUES += household_tax_payment_message->tax_payment;
		}
	FINISH_HOUSEHOLD_TAX_PAYMENT_MESSAGE_LOOP
	

	PAYMENT_ACCOUNT += TAX_REVENUES;
	
	return 0;
}

int Government_send_unemployment_benefit_payment()
{
	//Compute UNEMPLOYMENT_BENEFIT_PAYMENT
	//Compute TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT
	PAYMENT_ACCOUNT -= TOTAL_UNEMPLOYMENT_BENEFIT_PAYMENT;
	
	add_unemployment_benefit_message(ID,UNEMPLOYMENT_BENEFIT_PAYMENT);
	
	return 0;
}

int Government_send_account_update()
{
	
	add_central_bank_account_update_message(ID, PAYMENT_ACCOUNT);
	
	return 0;
}



int Government_send_tax_rates()
{

	add_government_tax_rates_message(ID, TAX_RATE_CORPORATE, TAX_RATE_HH_LABOUR, TAX_RATE_HH_CAPITAL, TAX_RATE_VAT);
	
	return 0;	
}
