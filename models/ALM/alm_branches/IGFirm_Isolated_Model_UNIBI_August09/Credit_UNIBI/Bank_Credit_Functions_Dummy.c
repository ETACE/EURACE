
#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"



/************Bank Role: Credit market********************************/

int Bank_read_loan_request_send_acceptance()
{
	
// Computes the total deposits



// Set the total loan supply
if(TOTAL_DEPOSITS+PAYMENT_ACCOUNT>0)
{
TOTAL_LOAN_SUPPLY= 0.90*(TOTAL_DEPOSITS+PAYMENT_ACCOUNT);
}else
TOTAL_LOAN_SUPPLY=0;

	
credit_request_array  credit_requests;
	init_credit_request_array (&credit_requests);

	START_LOAN_REQUEST_MESSAGE_LOOP
	
	//Compute the ratio of debt and assets

	double ratio_debt_assets = loan_request_message->total_debt/loan_request_message->total_assets;

	
	//printf("ID: %d Risk TA:%f,   TD%f  CA:%f +++ Prof %f\n",loan_request_message->firm_id,loan_request_message->total_assets,loan_request_message->total_debt,loan_request_message->credit_amount,ratio_debt_assets);
	

	//Add credit request on a temporary array	
	add_credit_request(&credit_requests,loan_request_message->firm_id,loan_request_message->credit_amount , loan_request_message->total_assets,loan_request_message->total_debt,ratio_debt_assets);
	
	FINISH_LOAN_REQUEST_MESSAGE_LOOP




	//This sorts the credit requests depending on the debt assets ratio
	qsort(credit_requests.array, credit_requests.size, 
	sizeof(credit_request), credit_request_function);

	TOTAL_LOAN_DEMAND = 0;

	

	//this computes the total loan demand
	for(int i=0;i<credit_requests.size;i++)
	{
	
	TOTAL_LOAN_DEMAND+=credit_requests.array[i].credit_amount;
	
	}

	
	// credit requrest is accepted if both the debt assets ratio < a threshold and if the 		requested amount is covered by the total supply
 
	for(int i=0;i<credit_requests.size;i++)
	{

	if((credit_requests.array[i].prob_of_failure<DEBT_ASSETS_RATIO_THRESHOLD &&credit_requests.array[i].prob_of_failure>=0)&&TOTAL_LOAN_SUPPLY-credit_requests.array[i].credit_amount>0)
	{
	double accepted_credit_volume = credit_requests.array[i].credit_amount;

	LAST_CREDIT_ID++;
		
	add_loan_acceptance_message(credit_requests.array[i].firm_id,ID,LAST_CREDIT_ID,accepted_credit_volume,INTEREST_RATE);
	
	
	add_outstanding_loans(&LOANS_OUTSTANDING,credit_requests.array[i].firm_id,credit_requests.array[i].credit_amount,INTEREST_RATE,LAST_CREDIT_ID);
	

	TOTAL_LOAN_SUPPLY -= credit_requests.array[i].credit_amount;

	}else//Send no acceptance if either constraint of the bank is binding or the firm doesn't 		fullfill the credit conditions 
	{
	
	add_loan_acceptance_message(credit_requests.array[i].firm_id,ID,0,0.0,0.0);

	}
	
		/*for(int j=0; j<LOANS_OUTSTANDING.size;j++)
		{
		if(LOANS_OUTSTANDING.array[j].firm_id==credit_requests.array[i].firm_id)
		{
			LOANS_OUTSTANDING.array[j].total_amount += credit_requests.array[i].credit_amount;

		}
		}*/

	
	}

	free_credit_request_array(&credit_requests);

	return 0;
}


int Bank_read_interest_payments()
{
	
	//int firm_id;

		DAILY_INTEREST_REVENUE =0.0;
	
	START_INTEREST_PAYMENT_MESSAGE_LOOP
		if(interest_payment_message->bank_id==ID)
		{
					

			PAYMENT_ACCOUNT+=interest_payment_message->interest_payment;

			DAILY_INTEREST_REVENUE += interest_payment_message->interest_payment;

			MONTHLY_INTEREST_REVENUE+= interest_payment_message->interest_payment;


			//Update the firm's bank account: the interest is NOT an amount that is added or subtracted
			//firm_id = interest_payment_message->firm_id;
			//interest_payment_message->interest_payment;
		}
	FINISH_INTEREST_PAYMENT_MESSAGE_LOOP
	
	return 0;
}

int Bank_read_debt_installment_payments()
{	

	START_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
		if(debt_installment_payment_message->bank_id==ID)
		{
			//update the firm's bank account: the debt_installment_payment is added to the bank account of the firm
			for(int i=0; i<LOANS_OUTSTANDING.size;i++)
			{
			if(  LOANS_OUTSTANDING.array[i].credit_id==debt_installment_payment_message->credit_id)
			{

			//printf("\n debt_installment_payment_message->credit_id %d debt_installment_payment_message->debt_installment_payment%f \n",debt_installment_payment_message->credit_id,debt_installment_payment_message->debt_installment_payment);

		/*if(LOANS_OUTSTANDING.array[i].credit_id==100)

		{
		printf("\n LOANS_OUTSTANDING.array[i].total_amount %f debt_installment_payment_message->debt_installment_payment%f \n",LOANS_OUTSTANDING.array[i].total_amount,debt_installment_payment_message->debt_installment_payment);

		}*/
			
LOANS_OUTSTANDING.array[i].total_amount-=debt_installment_payment_message->debt_installment_payment;



			//printf("LOANS_OUTSTANDING.array[i].total_amount %f \n",LOANS_OUTSTANDING.array[i].total_amount);
		
			if(LOANS_OUTSTANDING.array[i].total_amount<=0.0)
				{	
				remove_outstanding_loans(&LOANS_OUTSTANDING,i);
		
				}
			break;

			}

			}
}
	FINISH_DEBT_INSTALLMENT_PAYMENT_MESSAGE_LOOP
	
	return 0;
}


int Bank_account_update_deposits()
{
TOTAL_DEPOSITS=0;	
START_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
if(ID == bank_account_update_message->bank_id)
{



TOTAL_DEPOSITS+=bank_account_update_message->payment_account;



}

FINISH_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP

return 0;
}




int Bank_pays_dividends_taxes()
{

	
	//Compute the monthy earnings
	EARNINGS = MONTHLY_INTEREST_REVENUE;
	MONTHLY_INTEREST_REVENUE =0;

	//Compute and pay taxes
	TAX_PAYMENT = TAX_RATE_COPORATE * EARNINGS;
	NET_EARNINGS = EARNINGS - TAX_PAYMENT;
	PAYMENT_ACCOUNT -= TAX_PAYMENT;
	add_tax_payment_message(GOV_ID,TAX_PAYMENT) ;

	//Compute and pay dividends
	DIVIDEND_PAYMENT = NET_EARNINGS;
	CURRENT_DIVIDEND_PER_SHARE= DIVIDEND_PAYMENT/OUTSTANDING_SHARES;
	PAYMENT_ACCOUNT -= DIVIDEND_PAYMENT;
	add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);

return 0;
}


int Bank_idle()
{


return 0;
}





