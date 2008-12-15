#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
//#include "Firm_Library_Functions.h"


/* Library functions */

/** \fn Firm_calc_input_demands_2(), auxiliary function
 * \brief Firms recalculate the labor demand and the demand for capital goods
 * such that these can be financed with the external finances obtained.
 * This function is iterated multiple times by the function Firm_calc_production_quantity_2
 * in order to find the maximal possible production_quantity that can be financed.
 */
int Firm_calc_input_demands_2()
{

	
	double temp_labour_demand;
	double temp_capital_demand;
	

		
		
		/*Calculate labor demand and needed capital goods.
		Complementarity between specific skills and productivity*/
		
		
		/*Specific skills are limiting factor*/
		if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
		{
	
			temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
			(pow((BETA*MEAN_WAGE*(1.04))/((DEPRECIATION_RATE*ACTUAL_CAP_PRICE)*ALPHA),ALPHA)/
			MEAN_SPECIFIC_SKILLS);
			
			/*Smoothing of capital good demand*/
			if(temp_capital_demand > TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS)
			{
				NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS;
			}else
			{
				NEEDED_CAPITAL_STOCK = temp_capital_demand;
			}
			
			
				
		temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
		(pow(NEEDED_CAPITAL_STOCK,BETA)*MEAN_SPECIFIC_SKILLS),1/ALPHA);
 
		}
		/*Technological productivity is limiting factor*/
		else
		{
			temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
			(pow((BETA*MEAN_WAGE*(1.04))/	((DEPRECIATION_RATE*ACTUAL_CAP_PRICE)*ALPHA),ALPHA)/
			TECHNOLOGY);

			/*Smoothing of capital good demand*/
			if(temp_capital_demand > TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS)
			{
				NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS;
			}else
			{
				NEEDED_CAPITAL_STOCK = temp_capital_demand;
			}
		

		temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
		(pow(NEEDED_CAPITAL_STOCK,BETA)*TECHNOLOGY),1/ALPHA);
		}
   
		

		if(NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK)
		{		
			if(temp_labour_demand < 1 && temp_labour_demand > 0)
			{
				EMPLOYEES_NEEDED = 1;
			}else
			{
				EMPLOYEES_NEEDED = (int) temp_labour_demand;
			}
		}
		else/*... if capital stock is higher than the needed one..*/
		{
			/*Recalculation of the labor demand*/
			if(MEAN_SPECIFIC_SKILLS > TECHNOLOGY)
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
				(TECHNOLOGY*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA));
			}
			else
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
 				(MEAN_SPECIFIC_SKILLS*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA));
			}
		}
		/*This calculates the needed capital investments*/
		DEMAND_CAPITAL_STOCK=  NEEDED_CAPITAL_STOCK - TOTAL_UNITS_CAPITAL_STOCK;
		if(DEMAND_CAPITAL_STOCK< 0)
			DEMAND_CAPITAL_STOCK=0;		
		
		/*This computes the financial needings for production*/
		PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE*(1.04) + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;
	
	
	return 0;
}	


/************************************ Firm agent functions ************************************/


int Firm_set_quantities_zero()
{
	
	PLANNED_PRODUCTION_QUANTITY = 0;
	PRODUCTION_QUANTITY = 0;

	return 0;
}


/********************************Firm Role Consumption Goods marke*******************************/


/** \fn Firm_calc_production_quantity()
 * \brief Firm calculate the intended production volume depending on the current stocks in the malls*/
int Firm_calc_production_quantity()
{

	double production_volume = 0;
	double prod_vol;

    //Reset the counters at the start of month
    CUM_TOTAL_SOLD_QUANTITY = 0.0;
    CUM_REVENUE = 0.0;        

	
		/*Computing of mean critical stock levels*/
		double mean_critical_stocks=0;
		for (int j = 0; j < CURRENT_MALL_STOCKS.size;j++)
		{
			mean_critical_stocks += CURRENT_MALL_STOCKS.array[j].critical_stock;
		}

		mean_critical_stocks = mean_critical_stocks/CURRENT_MALL_STOCKS.size;

		/*Computing of out-of-stock costs*/
		OUT_OF_STOCK_COSTS = (PRICE - DISCOUNT_RATE*UNIT_COSTS)/
		(PRICE+INVENTORY_COSTS_PER_UNIT);

		/*Creating a temporary array of the last X sales per mall*/
		for(int i = 0; i < CURRENT_MALL_STOCKS.size;i++)
		{
			tempory_sales_statistics_array sales_mall;
			init_tempory_sales_statistics_array(&sales_mall);

			for(int j = 0; j < MALLS_SALES_STATISTICS.size;j++)
			{
				if(CURRENT_MALL_STOCKS.array[i].mall_id==
				MALLS_SALES_STATISTICS.array[j].mall_id)
				{
					for(int k = 0; k < FIRM_PLANNING_HORIZON; k++)
					{
					add_tempory_sales_statistics(&sales_mall,
					MALLS_SALES_STATISTICS.array[j].mall_id,
					MALLS_SALES_STATISTICS.array[j].sales.array[k].period,
					MALLS_SALES_STATISTICS.array[j].sales.array[k].sales);
					}
				}
			}
			
			/*Lowest number (sales) first*/	
			//sort_mall_sales_list(&sales_mall);
			/* Sorting the sales lists   */
			qsort(sales_mall.array, sales_mall.size, sizeof(temporary_sales_statistics),
			 sales_statistics_list_rank_sales_function);

		

			/*Setting the critical values*/
			for(int k = 0; k < FIRM_PLANNING_HORIZON; k++)
			{
				double prob = (1 + k)/(double)FIRM_PLANNING_HORIZON;

				if(prob < OUT_OF_STOCK_COSTS)
				{
					CURRENT_MALL_STOCKS.array[i].critical_stock = 
					sales_mall.array[k].sales;
				}
			}

			/*If the critical level for a mall is zero then the firm sets (with a certain prob )the 
			 * critical level equal the average CL in order to keep this mall on the delivery list */
			if(CURRENT_MALL_STOCKS.array[i].critical_stock==0)
			{
				int random_nummer = random_int(0,100);
				if(random_nummer < DELIVERY_PROB_IF_CRITICAL_STOCK_0)
				{
					CURRENT_MALL_STOCKS.array[i].critical_stock=
 					mean_critical_stocks;
				}

			}
	
			free_temporary_sales_statistics_array(&sales_mall);
		}


		/*checking whether or not the current mall stocks are below the critical values 		
		 * (sS-Rule) If this is the case refill the stock up to the max stock */
		for(int i = 0; i < CURRENT_MALL_STOCKS.size; i++)
		{
			
			if(CURRENT_MALL_STOCKS.array[i].current_stock <= 
			CURRENT_MALL_STOCKS.array[i].critical_stock)	
			{
				/*If stocks are left at the beginning of a new production cycle 
				 * then firms produce the difference between these stocks and the 
				 * critical stock for this mall*/
				if(CURRENT_MALL_STOCKS.array[i].current_stock > 0)
				{
					prod_vol = CURRENT_MALL_STOCKS.array[i].critical_stock - CURRENT_MALL_STOCKS.array[i].current_stock;
	
					PLANNED_DELIVERY_VOLUME.array[i].mall_id = 
					CURRENT_MALL_STOCKS.array[i].mall_id;

					PLANNED_DELIVERY_VOLUME.array[i].quantity  = prod_vol;
					production_volume = production_volume + prod_vol;
				}
				else
				/*If no stocks are left then the firms want to produce more 
				 * units than the period before. They increase the production 
				 * volume for one mall by a certain fraction of the last delivery volume*/
				{
					for(int j = 0; j < DELIVERY_VOLUME.size; j++)
					{
						if(PLANNED_DELIVERY_VOLUME.array[i].mall_id==
						DELIVERY_VOLUME.array[j].mall_id)
						{
							prod_vol = CURRENT_MALL_STOCKS.array[i].critical_stock*(1 + ADAPTION_DELIVERY_VOLUME);

							PLANNED_DELIVERY_VOLUME.
							array[i].quantity = prod_vol;

							/*printf("Prod-Vol %f\n",prod_vol);*/
						}
					}
				}
				
				production_volume = production_volume + prod_vol;
				
			}
			else/*If  stocks are higher than the critical value no production takes place for this mall*/
			{
				PLANNED_DELIVERY_VOLUME.array[i].mall_id= 
				CURRENT_MALL_STOCKS.array[i].mall_id;

				PLANNED_DELIVERY_VOLUME.array[i].quantity= 0;
			}
		}

		/*Smoothing of production quantity in order to avoid high fluctuations*/
		double mean_production_quantity=0;
		for(int i = 0; i < LAST_PLANNED_PRODUCTION_QUANTITIES.size; i++)
		{
			mean_production_quantity += LAST_PLANNED_PRODUCTION_QUANTITIES.array[i];
		}

		mean_production_quantity = mean_production_quantity/
		LAST_PLANNED_PRODUCTION_QUANTITIES.size;
	
		PLANNED_PRODUCTION_QUANTITY = LAMBDA*production_volume + (1-LAMBDA)*mean_production_quantity;
		
		//Set planned production value that is retained in memory during the month:
		PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY; 
	    
	    //printf("In calculate production: Firm %d PLANNED_PRODUCTION_QUANTITY %f\n", ID, PLANNED_PRODUCTION_QUANTITY);
	    //printf("In calculate production: Firm %d PLANNED_OUTPUT %f\n", ID, PLANNED_OUTPUT);
	    
	return 0;

}

	
/** \fn Firm_calc_input_demands()
 * \brief Firms calculate the labor demand and the demand for capital goods*/
int Firm_calc_input_demands()
{


	double temp_labour_demand;
	double temp_capital_demand;
	
		START_PRODUCTIVITY_MESSAGE_LOOP
			/*Update of the actual capital good information*/
			TECHNOLOGICAL_FRONTIER = productivity_message->cap_productivity;
			ACTUAL_CAP_PRICE = productivity_message->cap_good_price;
		
		FINISH_PRODUCTIVITY_MESSAGE_LOOP
		
		/*Calculate labor demand and needed capital goods. 
		 * Complementarity between specific skills and productivity*/
		


		/*Specific skills are limiting factor*/
		if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
		{
	
			temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
			(pow((BETA*MEAN_WAGE*(1.04))/((DEPRECIATION_RATE*ACTUAL_CAP_PRICE)*ALPHA),ALPHA)/
			MEAN_SPECIFIC_SKILLS);
			
			/*Smoothing of capital good demand*/
			if(temp_capital_demand > TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS)
			{
				NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS;
			}else
			{
				NEEDED_CAPITAL_STOCK = temp_capital_demand;
			}
			
				
			
				
		temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
		(pow(NEEDED_CAPITAL_STOCK,BETA)*MEAN_SPECIFIC_SKILLS),1/ALPHA);
 
		}
		/*Technological productivity is limiting factor*/
		else
		{
			temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
			(pow((BETA*MEAN_WAGE*(1.04))/	((DEPRECIATION_RATE*ACTUAL_CAP_PRICE)*ALPHA),ALPHA)/
			TECHNOLOGY);
			
				/*Smoothing of capital good demand*/
			if(temp_capital_demand > TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS)
			{
				NEEDED_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK + (INV_INERTIA-1)*TOTAL_CAPITAL_DEPRECIATION_UNITS;
			}else
			{
				NEEDED_CAPITAL_STOCK = temp_capital_demand;
			}
			
			
		
				
			
			
		temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
		(pow(NEEDED_CAPITAL_STOCK,BETA)*TECHNOLOGY),1/ALPHA);
		}
		
		
		/*Compute new capital stock, in units and in value*/
		
    
	
        
		/*Depriciation of the old capital stock.
		If additional capital goods are needed...*/
			
		
		
        	
		TOTAL_CAPITAL_DEPRECIATION_UNITS = TOTAL_UNITS_CAPITAL_STOCK*DEPRECIATION_RATE;
		TOTAL_CAPITAL_DEPRECIATION_VALUE= TOTAL_VALUE_CAPITAL_STOCK*DEPRECIATION_RATE;
		TOTAL_VALUE_CAPITAL_STOCK *=(1-DEPRECIATION_RATE);
		TOTAL_UNITS_CAPITAL_STOCK -= TOTAL_CAPITAL_DEPRECIATION_UNITS;
	

		if(NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK)
		{		
			if(temp_labour_demand < 1 && temp_labour_demand > 0)
			{
				EMPLOYEES_NEEDED = 1;
			}else
			{
				EMPLOYEES_NEEDED = (int) temp_labour_demand;
			}
		}
		else/*... if capital stock is higher than the needed one..*/
		{
			/*Recalculation of the labor demand*/
			if(MEAN_SPECIFIC_SKILLS > TECHNOLOGY)
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
				(TECHNOLOGY*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA));
			}
			else
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
 				(MEAN_SPECIFIC_SKILLS*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA)),1/ALPHA));
			}
		}
		/*This calculates the needed capital investments*/
	
		DEMAND_CAPITAL_STOCK = NEEDED_CAPITAL_STOCK - TOTAL_UNITS_CAPITAL_STOCK;
		if(DEMAND_CAPITAL_STOCK<0)
			DEMAND_CAPITAL_STOCK=0;	
		/*This computes the financial needings for production*/

		
		PLANNED_VALUE_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK /max(NEEDED_CAPITAL_STOCK,TOTAL_UNITS_CAPITAL_STOCK)*TOTAL_VALUE_CAPITAL_STOCK + DEMAND_CAPITAL_STOCK/max(NEEDED_CAPITAL_STOCK,TOTAL_UNITS_CAPITAL_STOCK)*ACTUAL_CAP_PRICE;
		
		PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*(1.04)*MEAN_WAGE + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;

		//printf("Firm: %d  Labour: %d  Capital: %f  PLANNED_PROD_COSTS: %f\n", ID,EMPLOYEES_NEEDED,NEEDED_CAPITAL_STOCK,PLANNED_PRODUCTION_COSTS);
	
	return 0;
}


/* GENUA NOTE: This needs to be updated with the new style of checking FINANCIAL_NEEDS
 * See file: Firm_Financial_Management
 */

/** \fn Firm_calc_production_quantity_2()
 * \brief Firms iterate over the planned production quantity decreasing it incrementally,
 * such that the corresponding labor demand and capital demand can be financed by the actually obtained financial resources.
 * If PLANNED_PRODUCTION_COSTS <= PAYMENT_ACCOUNT this function does nothing.
 */
int Firm_calc_production_quantity_2()
{
	//printf("Firm_calc_production_quantity_2() ID: %d\n",ID);

	double decrement;
	double diff;
	diff = PLANNED_PRODUCTION_QUANTITY;

	//Here we set a fraction of the planned production quantity
	decrement = ADAPTION_PRODUCTION_VOLUME_DUE_TO_INSUFFICIENT_FINANCES*PLANNED_PRODUCTION_QUANTITY;
	
		
		//if( FINANCIAL_RESOURCES_FOR_PRODUCTION>0.0)
		if( PAYMENT_ACCOUNT>0.0)
		{
			//while (PLANNED_PRODUCTION_COSTS > FINANCIAL_RESOURCES_FOR_PRODUCTION)
			while (PLANNED_PRODUCTION_COSTS > PAYMENT_ACCOUNT)
			{
				PLANNED_PRODUCTION_QUANTITY -= decrement;
				Firm_calc_input_demands_2();
			}
		}else
		{
			PLANNED_PRODUCTION_QUANTITY=0.0;
			Firm_calc_input_demands_2();
		}
	
	//printf("Labour: %d  Capital: %f  PLANNED_PROD_COSTS: %f\n", EMPLOYEES_NEEDED,NEEDED_CAPITAL_STOCK,PLANNED_PRODUCTION_COSTS);
	
		//Compute the diff
		diff -= PLANNED_PRODUCTION_QUANTITY;
		
		//Set planned production value that is retained in memory during the month:
		PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY;

	    //printf("In calculate production 2: Firm %d PLANNED_PRODUCTION_QUANTITY %.2f (-%.2f)\n", ID, PLANNED_PRODUCTION_QUANTITY, diff);
	    //printf("In calculate production 2: Firm %d PLANNED_OUTPUT %.2f (-%.2f)\n", ID, PLANNED_OUTPUT, diff);

	return 0;
}

/** \fn Firm_send_capital_demand()
 * \brief Firm sends demand for capital to the capital goods market. */
int Firm_send_capital_demand()
{
	
	if ( (NEEDED_CAPITAL_STOCK > 0) && (NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK))
		{					
			
			add_capital_good_request_message(ID,DEMAND_CAPITAL_STOCK);		
		}
	
	return 0;
}


int Firm_receive_capital_goods()
{
		
		
		CAPITAL_COSTS = 0.0;
		START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
		
		/*Adding the new capital*/

		TOTAL_UNITS_CAPITAL_STOCK += capital_good_delivery_message
		->capital_good_delivery_volume;
		
		/*Determine the weighted average productivity of the total capital stock*/
	
		/*Update of productivity*/
				TECHNOLOGY = TOTAL_UNITS_CAPITAL_STOCK / 	(TOTAL_UNITS_CAPITAL_STOCK +capital_good_delivery_message->capital_good_delivery_volume)
				*TECHNOLOGY + 
				capital_good_delivery_message->capital_good_delivery_volume/
				(TOTAL_UNITS_CAPITAL_STOCK + 
				capital_good_delivery_message->capital_good_delivery_volume)
				*capital_good_delivery_message->productivity;
 		/*Update of current value of capital stock*/

				TOTAL_VALUE_CAPITAL_STOCK = TOTAL_UNITS_CAPITAL_STOCK / 	(TOTAL_UNITS_CAPITAL_STOCK +capital_good_delivery_message->capital_good_delivery_volume)
				*TOTAL_VALUE_CAPITAL_STOCK + 
				capital_good_delivery_message->capital_good_delivery_volume/
				(TOTAL_UNITS_CAPITAL_STOCK + 
				capital_good_delivery_message->capital_good_delivery_volume)
				*capital_good_delivery_message->capital_good_price;		



		/*Computing the capital bill*/
		CAPITAL_COSTS += capital_good_delivery_message
		->capital_good_delivery_volume* capital_good_delivery_message
		->capital_good_price;

		
		
	FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
		if(CAPITAL_COSTS>0.0)
		{
		add_financing_capital(&CAPITAL_FINANCING,CAPITAL_COSTS/PERIODS_TO_REPAY_LOANS,PERIODS_TO_REPAY_LOANS);
		}
return 0;
}





int Firm_execute_production()
{
	double diff;
	
	/* This determines the realized production volume*/
	if(PLANNED_PRODUCTION_QUANTITY != 0)
	{
	
		if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
		{	
		
			PRODUCTION_QUANTITY = MEAN_SPECIFIC_SKILLS * 
			pow(NO_EMPLOYEES,ALPHA)*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA); 
		}
		else 
		{
			PRODUCTION_QUANTITY = TECHNOLOGY * 
			pow(NO_EMPLOYEES,ALPHA)*pow(TOTAL_UNITS_CAPITAL_STOCK,BETA); 
		}

	}
	else
	{
		PRODUCTION_QUANTITY=0.0;
	}
	
	//compute diff between actual and planned
	diff = PRODUCTION_QUANTITY - PLANNED_PRODUCTION_QUANTITY;
	
	//Set actual production value that is retained  in memory during the month:
	OUTPUT = PRODUCTION_QUANTITY;
	
	TOTAL_SUPPLY = TOTAL_UNITS_LOCAL_INVENTORY + OUTPUT;
	
	//printf("In Execute production: Firm %d PRODUCTION_QUANTITY: %.2f (%.2f) \n", ID, PRODUCTION_QUANTITY, diff);
	//printf("In Execute production: Firm %d OUTPUT: %.2f (%.2f)\n", ID, OUTPUT, diff);

return 0;
}



/** \fn Firm_calc_pay_costs()
 * \brief In this function the firm receives the purchased investment goods and pays the goods and 	the wage bill. Additionally, the new mean wage and tthe new average specific skill level is 	computed. */
int Firm_calc_pay_costs()
{
		/*Pay capital costs*/

		add_pay_capital_goods_message(ID,CAPITAL_COSTS);

		LABOUR_COSTS=0.0;

		for(int i=0; i<EMPLOYEES.size;i++)
		{
			LABOUR_COSTS += EMPLOYEES.array[i].wage;

			add_wage_payment_message(ID,
			EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
			TECHNOLOGY,MEAN_SPECIFIC_SKILLS);

			
		}
	/*Calculate the unit costs and total costs*/
		if(PRODUCTION_QUANTITY!=0 )
		{
			
			double calc_capital_costs = 0;
		for(int i = 0; i<CAPITAL_FINANCING.size;i++) 
			{
				if(CAPITAL_FINANCING.array[i].nr_periods_before_repayment==0)
				{
					remove_financing_capital(&CAPITAL_FINANCING,i);
					i--;
				}else
				{
				CAPITAL_FINANCING.array[i].nr_periods_before_repayment--;
				calc_capital_costs+= CAPITAL_FINANCING.array[i].financing_per_month;
				}
				

			} 
     			
			UNIT_COSTS=(LABOUR_COSTS + calc_capital_costs + TOTAL_INTEREST_PAYMENT) / PRODUCTION_QUANTITY;
	
			

			PRICE = UNIT_COSTS*(1 + MARK_UP);
			

			
		}

		
		PRODUCTION_COSTS = CAPITAL_COSTS + LABOUR_COSTS;

	PAYMENT_ACCOUNT -= PRODUCTION_COSTS;

	//if(PLANNED_PRODUCTION_COSTS<PRODUCTION_COSTS)
		//printf("XXXX PLANNED_PRODUCTION_COSTS: %f  PRODUCTION_COSTS %f XXXXX\n",PLANNED_PRODUCTION_COSTS,PRODUCTION_COSTS);

	remove_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,0);
	add_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,PLANNED_PRODUCTION_QUANTITY);	
	
	return 0;
}


/** \fn Firm_send_goods_to_mall()
 * \brief Here the firms send the produced goods to the malls. If the realized output is less than 	the intended one, then the malls are only delivered with a proportional share of their 		plannded delivery volumes. */

int Firm_send_goods_to_mall()
{ 	
	
		double delivery_volume=0;

		for(int i=0; i<PLANNED_DELIVERY_VOLUME.size; i++)
		{
			delivery_volume+=PLANNED_DELIVERY_VOLUME.array[i].quantity;

		}


		for(int i = 0; i < PLANNED_DELIVERY_VOLUME.size; i++)
		{

			for(int j = 0; j < DELIVERY_VOLUME.size; j++)
			{
				if(DELIVERY_VOLUME.array[j].mall_id == 
				PLANNED_DELIVERY_VOLUME.array[i].mall_id)
				{
					/*If planned prod vol > realized prod vol -> curtain the delivery vol*/
					if(delivery_volume>PRODUCTION_QUANTITY)
					{
						DELIVERY_VOLUME.array[j].quantity =
 						PRODUCTION_QUANTITY / delivery_volume * PLANNED_DELIVERY_VOLUME.array[i].quantity;
					
					}else /*otherwise planned = realized del vol*/
					
					if(PRODUCTION_QUANTITY > delivery_volume &&
 					delivery_volume !=0)
					{
						DELIVERY_VOLUME.array[j].quantity = PRODUCTION_QUANTITY / delivery_volume*PLANNED_DELIVERY_VOLUME.array[i].quantity;

					}else 
					if(PRODUCTION_QUANTITY > delivery_volume &&
 					delivery_volume ==0)
					{	

						DELIVERY_VOLUME.array[j].quantity = 
						PRODUCTION_QUANTITY/(DELIVERY_VOLUME.size);
					}
					else
					{
						DELIVERY_VOLUME.array[j].quantity = 
						PLANNED_DELIVERY_VOLUME.array[i].quantity;
					}
		
					DELIVERY_VOLUME.array[j].quality=
					PLANNED_DELIVERY_VOLUME.array[j].quality;

					DELIVERY_VOLUME.array[j].price=
					PLANNED_DELIVERY_VOLUME.array[j].price;
			
			
					add_update_mall_stock_message(
					DELIVERY_VOLUME.array[j].mall_id,ID,
					DELIVERY_VOLUME.array[j].quantity,QUALITY,PRICE,PRICE_LAST_MONTH);
			
				}
			}
		}
	
	
	return 0;
}

/** \fn Firm_calc_revenue()
 * \brief Here the firms calc the revenues and profits and then distribute the dividends to households 
 */
int Firm_calc_revenue()
{
	
	REVENUE_PER_DAY=0.0;
	TOTAL_SOLD_QUANTITY=0.0;

	/*calc the daily revenue and sum up the monthly revenue*/
	START_SALES_MESSAGE_LOOP
	
		for(int i=0; i< SOLD_QUANTITIES.size; i++)
		{
			if(sales_message->mall_id ==  SOLD_QUANTITIES.array[i].mall_id)
			{
				SOLD_QUANTITIES.array[i].sold_quantity += 
				sales_message->revenue/PRICE;
			
				REVENUE_PER_DAY += sales_message->revenue;
		
				CUM_REVENUE += sales_message->revenue;
	
				TOTAL_SOLD_QUANTITY+=sales_message->revenue/PRICE;
			}	
		}
		

		//Update mall stocks
		for(int i=0; i< CURRENT_MALL_STOCKS.size; i++)
		{
			if(sales_message->mall_id ==  CURRENT_MALL_STOCKS.array[i].mall_id)
			{
				CURRENT_MALL_STOCKS.array[i].current_stock= sales_message->current_stock;
			}
		}
	
	FINISH_SALES_MESSAGE_LOOP
	
	/*GENUA*/
	/*add_bank_account_update_message(BANK_ID, PAYMENT_ACCOUNT);*/
	//Not needed here: there is a function after this called Firm_send_payments_to_bank
	
	PAYMENT_ACCOUNT += REVENUE_PER_DAY;
	
	/*The monthly sales statistics*/
	CUM_TOTAL_SOLD_QUANTITY += TOTAL_SOLD_QUANTITY;	
		
	/*On a monthly base the earnings are computed and dividends distributed*/
	//See the functions for financial management
	return 0;		
	
}
int Firm_compute_sales_statistics()
{


	/*The sales per mall must be stored for the inventory rule*/
			
		int remove_index;
				
		for(int j=0; j < MALLS_SALES_STATISTICS.size;j++)
		{
			for(int k = 0; k < MALLS_SALES_STATISTICS.array[j].sales.size; k++)
			{
				if(MALLS_SALES_STATISTICS.array[j].sales.array[k].period== FIRM_PLANNING_HORIZON)
				{		
				remove_index = k;
				remove_sales_statistics(&MALLS_SALES_STATISTICS.array[j].sales, remove_index);
				k--;
				}else
				{
					MALLS_SALES_STATISTICS.array[j].sales.array[k].period++;
					
				}
			}
		}
											
				
		for(int i=0; i< SOLD_QUANTITIES.size;i++)
		{
			for(int j=0; j<MALLS_SALES_STATISTICS.size; j++)
			{
			if(MALLS_SALES_STATISTICS.array[j].mall_id == SOLD_QUANTITIES.array[i].mall_id)
				{
				add_sales_statistics(&MALLS_SALES_STATISTICS.array[j].sales, 1 , 
					SOLD_QUANTITIES.array[i].sold_quantity);
		
				SOLD_QUANTITIES.array[i].sold_quantity=0;
				SOLD_QUANTITIES.array[i].stock_empty=0;
				}
			}
		}


		

	
	return 0;
}


/** \fn Firm_update_specific_skills_of_workers()()
 * \brief 	Because the specific skills of workers have changed the firms update the specific skill levels of the workers.
 */
int Firm_update_specific_skills_of_workers()
{

	START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
		
		for(int i=0; i<EMPLOYEES.size;i++)
		{
			if(specific_skill_update_message->id==EMPLOYEES.array[i].id)
			{
				EMPLOYEES.array[i].specific_skill=
				specific_skill_update_message->specific_skills;
				
			}
		}
		
	FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP
	
	return 0;
}


