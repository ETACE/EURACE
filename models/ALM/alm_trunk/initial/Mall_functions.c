#include "header.h"
#include "Mall_agent_header.h"
#include "my_library_header.h"



/********************Mall agent functions*****************/

int Mall_send_current_stocks()
{
	for(int i=0; i< CURRENT_STOCK->size;i++)
	{
	add_current_mall_stock_info_message(ID, CURRENT_STOCK->array[i]->firm_id, CURRENT_STOCK->array[i]->stock,MSGDATA );

	}

return 0;
}


int Mall_update_mall_stock()
{
	//printf("Mall_update_mall_stock() von Firm %d\n",ID);
	START_UPDATE_MALL_STOCK_MESSAGE_LOOP
		//printf("Messageinhalt: %d", update_mall_stock_message->mall_id);
		if(ID==update_mall_stock_message->mall_id)
		{
			//printf("Messageinhalt: %f", update_mall_stock_message->quantity);

			for(int j=0; j < CURRENT_STOCK->size; j++)
			{	
				if(update_mall_stock_message->firm_id==CURRENT_STOCK->array[j]->firm_id)
				{
					CURRENT_STOCK->array[j]->stock=CURRENT_STOCK->array[j]->stock + update_mall_stock_message->quantity;
					//printf("Current Stock aus message: %f\n", update_mall_stock_message->quantity);
					CURRENT_STOCK->array[j]->firm_id=update_mall_stock_message->firm_id;

					CURRENT_STOCK->array[j]->quality=update_mall_stock_message->quality;

					CURRENT_STOCK->array[j]->price=update_mall_stock_message->price;


					//printf("Current Stock: %f\n", CURRENT_STOCK->array[j]->stock);
				}
			}

		}
	FINISH_UPDATE_MALL_STOCK_MESSAGE_LOOP




return 0;

}


int Mall_send_quality_price_info_1()
{
	int i;
	int available;

	for(i=0;i<CURRENT_STOCK->size;i++)
	{
	if(CURRENT_STOCK->array[i]->stock > 0)
		{
		available= 1;
		}else
		{
		available= 0;
		}	
		//printf("Mall %d:  Gut %d:  Menge %f   available %d \n",ID,CURRENT_STOCK->array[i]->firm_id,CURRENT_STOCK->array[i]->stock,available);
		add_quality_price_info_1_message(ID,REGION_ID,CURRENT_STOCK->array[i]->firm_id, 		CURRENT_STOCK->array[i]->quality, CURRENT_STOCK->array[i]->price,available,MSGDATA);

	}
	return 0;
}



int Mall_update_mall_stocks_sales_rationing_1()
{
	double aggregated_demand;
	double rationing_rate;

	consumption_request_array * consumption_request_list = init_consumption_request_array();

	START_CONSUMPTION_REQUEST_1_MESSAGE_LOOP
	
		if(ID == consumption_request_1_message->mall_id)
		{
			add_consumption_request(consumption_request_list, 				consumption_request_1_message->worker_id, 
			consumption_request_1_message->firm_id, 
			consumption_request_1_message->quantity );

		}

	FINISH_CONSUMPTION_REQUEST_1_MESSAGE_LOOP

	for(int i = 0; i < CURRENT_STOCK->size;i++)
	{
		aggregated_demand=0;
		for(int j = 0; j < consumption_request_list->size; j++)	
		{
			if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[j]->firm_id)
			{
				aggregated_demand+= consumption_request_list->array[j]->quantity;
		
			}
		
	
		}
		
		//printf("Agg Demand: %f \n", aggregated_demand);
	
		if(aggregated_demand> CURRENT_STOCK->array[i]->stock)
		{
		//Rationing

			rationing_rate= CURRENT_STOCK->array[i]->stock/ aggregated_demand;
			
			for(int k=0; k<consumption_request_list->size;k++)
			{
				if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[k]->firm_id)		{
					add_accepted_consumption_1_message(ID,consumption_request_list->array[k]->worker_id, consumption_request_list->array[k]->quantity* rationing_rate, 1, MSGDATA);
				}
			}

			for(int k=0; k< CURRENT_STOCK->size;k++)
			{
					
				if(CURRENT_STOCK->array[i]->firm_id==FIRM_REVENUES->array[k]->firm_id)
				{
					FIRM_REVENUES->array[k]->sales = CURRENT_STOCK->array[i]->stock*CURRENT_STOCK->array[i]->price;
				
					CURRENT_STOCK->array[i]->stock=0;
				
				}
			}
		}
		else
		{
			
			for(int k=0; k<consumption_request_list->size;k++)
			{
				if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[k]->firm_id)
				{	
					//printf("Quantity: %f\n",consumption_request_list->array[k]->quantity);
					add_accepted_consumption_1_message(ID,consumption_request_list->array[k]->worker_id,consumption_request_list->array[k]->quantity, 0,MSGDATA);
	
				}	
			}
	
			for(int l=0; l< CURRENT_STOCK->size;l++)
			{
		
				if(CURRENT_STOCK->array[i]->firm_id==FIRM_REVENUES->array[l]->firm_id)
				{
	
					FIRM_REVENUES->array[l]->sales = aggregated_demand *CURRENT_STOCK->array[i]->price ;
					CURRENT_STOCK->array[i]->stock-=aggregated_demand;
			
				}
			}
		
		}
		
	
	}

	free_consumption_request_array(consumption_request_list);


	int i;
	int available;
	for(i=0;i<CURRENT_STOCK->size;i++)
	{

	if(CURRENT_STOCK->array[i]->stock > 0)
		{
		available= 1;
		}else
		{
		available= 0;
		
		
		
		
		}	
		add_quality_price_info_2_message(ID,REGION_ID,CURRENT_STOCK->array[i]->firm_id, 		CURRENT_STOCK->array[i]->quality, CURRENT_STOCK->array[i]->price,available,MSGDATA);

	}




return 0;
}



int Mall_update_mall_stocks_sales_rationing_2()
{

	double aggregated_demand;
	double rationing_rate;

	consumption_request_array * consumption_request_list = init_consumption_request_array();


	START_CONSUMPTION_REQUEST_2_MESSAGE_LOOP

		if(ID == consumption_request_2_message->mall_id)
		{
			add_consumption_request(consumption_request_list, 				consumption_request_2_message->worker_id, 
			consumption_request_2_message->firm_id, consumption_request_2_message->quantity );

		}

	FINISH_CONSUMPTION_REQUEST_2_MESSAGE_LOOP

	for(int i = 0; i < CURRENT_STOCK->size;i++)
	{
		aggregated_demand=0;
		for(int j = 0; j < consumption_request_list->size; j++)
		{
			if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[j]->firm_id)
			{
				aggregated_demand+= consumption_request_list->array[j]->quantity;
		
			}
		
	
		}
	
		if(aggregated_demand> CURRENT_STOCK->array[i]->stock)
		{
			//Rationing

			rationing_rate= CURRENT_STOCK->array[i]->stock/ aggregated_demand;
	
			for(int k=0; k<consumption_request_list->size;k++)
			{
				if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[k]->firm_id)
				{
					add_accepted_consumption_2_message(ID,consumption_request_list->array[k]->worker_id,consumption_request_list->array[k]->quantity* rationing_rate, 1,MSGDATA);
				}
			}
			for(int k=0; k< CURRENT_STOCK->size;k++)
			{
				if(CURRENT_STOCK->array[i]->firm_id==FIRM_REVENUES->array[k]->firm_id)
				{
					FIRM_REVENUES->array[k]->sales += CURRENT_STOCK->array[i]->stock*CURRENT_STOCK->array[i]->price;

					
					CURRENT_STOCK->array[i]->stock=0;
					
				}
			}
		}
		else
		{

			for(int k=0; k<consumption_request_list->size;k++)
			{
				if(CURRENT_STOCK->array[i]->firm_id == consumption_request_list->array[k]->firm_id)
				{
					add_accepted_consumption_2_message(ID,consumption_request_list->array[k]->worker_id, consumption_request_list->array[k]->quantity, 0,MSGDATA);
	
				}	
			}
	
			for(int l=0; l< CURRENT_STOCK->size;l++)
			{
		
				if(CURRENT_STOCK->array[i]->firm_id==FIRM_REVENUES->array[l]->firm_id)
				{
	
					FIRM_REVENUES->array[l]->sales += aggregated_demand *CURRENT_STOCK->array[i]->price ;
					
					CURRENT_STOCK->array[i]->stock-=aggregated_demand;
				
				}
			}
		
		}

	}
	free_consumption_request_array(consumption_request_list);

return 0;
}


int Mall_pay_firm()
{
	TOTAL_SUPPLY=0;
	int stock_empty;
	for(int i=0; i< FIRM_REVENUES->size;i++)
	{
		
		
		for(int j=0; j<CURRENT_STOCK->size;j++)
		{
		
		if(FIRM_REVENUES->array[i]->firm_id == CURRENT_STOCK->array[j]->firm_id)
		{

			TOTAL_SUPPLY += CURRENT_STOCK->array[j]->stock;

			if(CURRENT_STOCK->array[j]->stock ==0)
			{
			stock_empty =1;
			}else
			{
			stock_empty =0;
			}
		add_sales_message(ID, FIRM_REVENUES->array[i]->firm_id, 			FIRM_REVENUES->array[i]->sales,stock_empty,MSGDATA );
		}
		}
	}

return 0;
}
