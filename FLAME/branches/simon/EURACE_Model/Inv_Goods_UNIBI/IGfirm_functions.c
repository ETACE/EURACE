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
	add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE,MSGDATA);
	return 0;
}

/** \fn IGFirm_send_capital_good()
 * \brief IGFirm sends capital goods to firms
 */
int IGFirm_send_capital_good()
{
	START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

		add_capital_good_delivery_message(capital_good_request_message->firm_id, 			capital_good_request_message->capital_good_demand, PRODUCTIVITY, 			CAPITAL_GOOD_PRICE, MSGDATA );

	FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

	return 0;
}



/** \fn IGFirm_receive_payment()
 * \brief IGFirm calculates revenues and distributes the revenue to the households
 */

int IGFirm_receive_payment()
{

	double distributed_revenue = 0;
	
	REVENUE_PER_DAY = 0;

	START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

		REVENUE_PER_DAY += pay_capital_goods_message->capital_bill;

		distributed_revenue += (1-0.65*pay_capital_goods_message->share_net_investments)
		*pay_capital_goods_message->capital_bill;

	FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP  

	double distributed_payment = distributed_revenue/NO_HOUSEHOLDS; 
	//double distributed_payment = REVENUE_PER_DAY/NO_HOUSEHOLDS; 
	
	add_capital_good_profit_distribution_message(distributed_payment,MSGDATA);

	
	return 0;
}
