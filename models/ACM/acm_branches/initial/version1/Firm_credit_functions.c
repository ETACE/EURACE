#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"


int Firm_ask_loan()
{
	int bank_name[2];
	bank_name[0] = rand()%NUMBER_OF_BANKS;
	do 
	{
		bank_name[1] = rand()%NUMBER_OF_BANKS;
	} while ( bank_name[1] == bank_name[0] );
	
	/*WARNING: CREDIT_DEMAND is also an agent memory variable*/
	double credit_demand = rand()/((double)RAND_MAX+1);  /* generate random credit demand */
	add_loan_request_message(CURRENT_EQUITY, CURRENT_DEBT, credit_demand, bank_name[0], ID);
	add_loan_request_message(CURRENT_EQUITY, CURRENT_DEBT, credit_demand, bank_name[1], ID);
	return 0;
}

int Firm_get_loan()
{
	int n = 0;
	double interest;
	double tempi;
	int tempn; /*WARNING : All declarations should be done on top of function*/

	START_LOAN_CONDITIONS_MESSAGE_LOOP
	if (ID == loan_conditions_message->firm_id) 
	{
		INTEREST.array[n] = loan_conditions_message->proposed_interest_rate;
		CREDIT_OFFER.array[n] = loan_conditions_message->amount_offered_credit;
		CONTACTED_BANK.array[n] = loan_conditions_message->bank_id;
		VALUE_AT_RISK.array[n] = loan_conditions_message->var;
		n += 1;
	}
	FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
	//double tempi;
//	int tempn; /*WARNING : All declarations should be done on top of function*/
	if (INTEREST.array[0] > INTEREST.array[1] ) 
	{
		tempi = INTEREST.array[0];
		INTEREST.array[0] = INTEREST.array[1];
		INTEREST.array[1] = tempi;
		tempi = CREDIT_OFFER.array[0];
		CREDIT_OFFER.array[0] = CREDIT_OFFER.array[1];
		CREDIT_OFFER.array[1] = tempi;
		tempi = VALUE_AT_RISK.array[0];
		VALUE_AT_RISK.array[0] = VALUE_AT_RISK.array[1];
		VALUE_AT_RISK.array[1] = tempi;
		tempn = CONTACTED_BANK.array[0];
		CONTACTED_BANK.array[0] = CONTACTED_BANK.array[1];
		CONTACTED_BANK.array[1] = tempn;
	}
	if ( CREDIT_OFFER.array[0] > 0 ) 
	{
		interest = CREDIT_OFFER.array[0]*INTEREST.array[0];
		OUTSTANDING_DEBT.array[LOANS_NUMBER] = CREDIT_OFFER.array[0]+interest;
		INSTALLMENT_AMOUNT.array[LOANS_NUMBER] = (CREDIT_OFFER.array[0]+interest)/INSTALLMENT_NUMBER;
		INTEREST_AMOUNT.array[LOANS_NUMBER] = interest/INSTALLMENT_NUMBER;
		RESIDUAL_VAR.array[LOANS_NUMBER] = VALUE_AT_RISK.array[0];
		VAR_PER_INSTALLMENT.array[LOANS_NUMBER] = VALUE_AT_RISK.array[0]/INSTALLMENT_NUMBER;
		INTEREST_LEFT.array[LOANS_NUMBER] = interest;
		LENDING_BANK_ID.array[LOANS_NUMBER] = CONTACTED_BANK.array[0];
		add_loan_acceptance_message(CREDIT_OFFER.array[0], CONTACTED_BANK.array[0]);
		LOANS_NUMBER += 1;
	}
	if ( CREDIT_OFFER.array[0] < CREDIT_DEMAND && CREDIT_OFFER.array[1] > 0) 
	{
		double residual_credit_demand = CREDIT_DEMAND-CREDIT_OFFER.array[0];
		if ( residual_credit_demand < CREDIT_OFFER.array[1] ) 
		{
			interest = residual_credit_demand*INTEREST.array[1];
			OUTSTANDING_DEBT.array[LOANS_NUMBER] = residual_credit_demand+interest;
			INSTALLMENT_AMOUNT.array[LOANS_NUMBER] = (residual_credit_demand+interest)/INSTALLMENT_NUMBER;
			INTEREST_AMOUNT.array[LOANS_NUMBER] = interest/INSTALLMENT_NUMBER;
			RESIDUAL_VAR.array[LOANS_NUMBER] = VALUE_AT_RISK.array[1]*(residual_credit_demand/CREDIT_DEMAND);
			VAR_PER_INSTALLMENT.array[LOANS_NUMBER] = RESIDUAL_VAR.array[LOANS_NUMBER]/INSTALLMENT_NUMBER;
			INTEREST_LEFT.array[LOANS_NUMBER] = interest;
			LENDING_BANK_ID.array[LOANS_NUMBER] = CONTACTED_BANK.array[1];
			add_loan_acceptance_message(residual_credit_demand, CONTACTED_BANK.array[1]);
			LOANS_NUMBER += 1;
		}
		else 
		{
			interest = CREDIT_OFFER.array[1]*INTEREST.array[1];
			OUTSTANDING_DEBT.array[LOANS_NUMBER] = CREDIT_OFFER.array[1]+interest;
			INSTALLMENT_AMOUNT.array[LOANS_NUMBER] = (CREDIT_OFFER.array[1]+interest)/INSTALLMENT_NUMBER;
			INTEREST_AMOUNT.array[LOANS_NUMBER] = interest/INSTALLMENT_NUMBER;
			RESIDUAL_VAR.array[LOANS_NUMBER] = VALUE_AT_RISK.array[1];
			VAR_PER_INSTALLMENT.array[LOANS_NUMBER] = VALUE_AT_RISK.array[1]/INSTALLMENT_NUMBER;
			INTEREST_LEFT.array[LOANS_NUMBER] = interest;
			LENDING_BANK_ID.array[LOANS_NUMBER] = CONTACTED_BANK.array[1];
			add_loan_acceptance_message(CREDIT_OFFER.array[1], CONTACTED_BANK.array[1]);
			LOANS_NUMBER += 1;
			/*WARNING: Not a correct was to add to a dynamic array. Refer to manual or wiki notes*/
		}
	}
	
	return 0;
}


int Firm_pay_interest_installment()
{
	double c, r, v;
	int a;
	int i;
	double total_debt = 0;
	double total_installments = 0;
	double debt_share;
	double refunded_debt;
	double bad_debt;
	for ( i = 0; i < LOANS_NUMBER; i++ ) 
	{
		total_debt += OUTSTANDING_DEBT.array[i];
		total_installments += INSTALLMENT_AMOUNT.array[i];
	}
	if ( TOTAL_RESOURCES >= total_installments ) 
	{
		for ( i = 0; i < LOANS_NUMBER; i++ ) 
		{
			c = INSTALLMENT_AMOUNT.array[i];
			r = INTEREST_AMOUNT.array[i];
			a = LENDING_BANK_ID.array[i];
			v = VAR_PER_INSTALLMENT.array[i];
			TOTAL_RESOURCES -= c;
			OUTSTANDING_DEBT.array[i] -= c;
			INTEREST_LEFT.array[i] -= r;
			RESIDUAL_VAR.array[i] -= v;
			if ( OUTSTANDING_DEBT.array[i] <= 0 ) 
			{
				for ( int j = i; j<LOANS_NUMBER-1; j++ ) 
				{
					OUTSTANDING_DEBT.array[j] = OUTSTANDING_DEBT.array[j+1];
					INSTALLMENT_AMOUNT.array[j] = INSTALLMENT_AMOUNT.array[j+1];
					INTEREST_AMOUNT.array[j] = INTEREST_AMOUNT.array[j+1];
					INTEREST_LEFT.array[j] = INTEREST_LEFT.array[j+1];
					LENDING_BANK_ID.array[j] = LENDING_BANK_ID.array[j+1];
					RESIDUAL_VAR.array[j] = RESIDUAL_VAR.array[j+1];
					VAR_PER_INSTALLMENT.array[j] = VAR_PER_INSTALLMENT.array[j+1];
				}
				LOANS_NUMBER -= 1;
			}
			add_installment_message(c, r, a, v);
		}
	}
	else 
	{
		BANKRUPTCY_STATE = 1;
		for ( i = 0; i < LOANS_NUMBER; i++ ) 
		{
			a = LENDING_BANK_ID.array[i];
			debt_share = OUTSTANDING_DEBT.array[i]/total_debt;
			refunded_debt = TOTAL_RESOURCES*debt_share;
			bad_debt = (OUTSTANDING_DEBT.array[i]-INTEREST_LEFT.array[i]) - refunded_debt;
			add_bankruptcy_message(a, bad_debt, refunded_debt, RESIDUAL_VAR.array[i]);
		}
		LOANS_NUMBER = 0;
	}
	return 0;
}


