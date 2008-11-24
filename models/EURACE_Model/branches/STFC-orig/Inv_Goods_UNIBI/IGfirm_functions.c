#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"


int day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 1;
	else return 0;
}

int not_day_of_month_to_act()
{
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT) return 0;
	else return 1;
}


int IGFirm_idle()
{
	return 0;
}


/***************************** Investment Goods producer function********************************/
/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm inceases productivity via a stochastic process and the according price */
int IGFirm_update_productivity_price()
{
	
	int i;

	
		i = random_int( 0 ,100);
		
		if(i < INNOVATION_PROBABILITY)
		{
			PRODUCTIVITY = PRODUCTIVITY*(1 + PRODUCTIVITY_PROGRESS);
			CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE*(1 +.5* PRODUCTIVITY_PROGRESS);	
		}

	
	



	return 0;
}

/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm send quality and price information */
int IGFirm_send_quality_price_info()
{
	add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE);
	return 0;
}

/** \fn IGFirm_send_capital_good()
 * \brief IGFirm sends capital goods to firms
 */
int IGFirm_send_capital_good()
{
	START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

		add_capital_good_delivery_message(capital_good_request_message->firm_id,
				capital_good_request_message->capital_good_demand, PRODUCTIVITY, CAPITAL_GOOD_PRICE);

	FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

	return 0;
}



/** \fn IGFirm_receive_payment()
 * \brief IGFirm calculates revenues and distributes the revenue to the households
 */

int IGFirm_receive_payment()
{

	
	REVENUE_PER_DAY = 0;

	START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

		REVENUE_PER_DAY += pay_capital_goods_message->capital_bill;

		

	FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP  

	CUM_REVENUES += REVENUE_PER_DAY; 
	PAYMENT_ACCOUNT += REVENUE_PER_DAY;
	return 0;
}

/** \fn IGFirm_dividend_payment()
 * \brief IGFirm distributes dividends to the households, and sends total_dividend payment to the bank
 */



int IGFirm_pay_taxes()
{
	
	//TAX_PAYMENT = CUM_REVENUES*TAX_RATE_CORPORATE;
	TAX_PAYMENT = CUM_REVENUES*1;	
	
	PAYMENT_ACCOUNT -= TAX_PAYMENT;

	NET_PROFIT = CUM_REVENUES - TAX_PAYMENT;
	CUM_REVENUES=0.0;
	add_tax_payment_message(ID,GOV_ID,TAX_PAYMENT);
	
	return 0;
}



int IGFirm_dividend_payment()
{
	CURRENT_DIVIDEND_PER_SHARE = NET_PROFIT / OUTSTANDING_SHARES;

	
	//add dividend_per_share_msg(firm_id, current_dividend_per_share) to shareholders (dividend per share)     
	add_dividend_per_share_message(ID, CURRENT_DIVIDEND_PER_SHARE);


	
	//decrease payment_account with the total_dividend_payment
	//PAYMENT_ACCOUNT -= TOTAL_DIVIDEND_PAYMENT;
	
	return 0;
}



