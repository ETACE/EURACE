#include "header.h"
#include "IGFirm_agent_header.h"
#include "my_library_header.h"


/* I love SVN */

/**************** Investment Goods producer function************/

int IGFirm_update_productivity_price()
{

	//printf("Funktion IGFirm_update_productivity_price() wird ausgeführt\n");
	int i;

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{	
		i = random_int( 0 ,100);
		//printf("Randomnumber: %d\n",i);


		if(i<INNOVATION_PROBABILITY)
		{
			PRODUCTIVITY = PRODUCTIVITY*(1 + PRODUCTIVITY_PROGRESS);
			CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE*(1 +.5* PRODUCTIVITY_PROGRESS);	
			
			
		}



	//printf("message: %d,%f,%f\n",ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE);
		

	}
	add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE,MSGDATA);



return 0;
}

int IGFirm_send_capital_good()
{
	START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

		add_capital_good_delivery_message(capital_good_request_message->firm_id, 			capital_good_request_message->capital_good_demand, PRODUCTIVITY, 			CAPITAL_GOOD_PRICE, MSGDATA );

	FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

return 0;
}

int IGFirm_receive_payment()
{
	
	REVENUE_PER_DAY =0;

	START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

	REVENUE_PER_DAY +=pay_capital_goods_message->capital_bill;


	FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP  

	double distributed_payment = REVENUE_PER_DAY/NO_HOUSEHOLDS; 
	
	
	add_capital_good_profit_distribution_message(distributed_payment,MSGDATA);

	

return 0;
}
