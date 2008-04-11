#include "header.h"
#include "Firm_agent_header.h"
#include "my_library_header.h"



/************************************ Firm agent functions ************************************/

/* Function condition functions */

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


int Firm_idle()
{
	return 0;
}







/********************************Firm Role Consumption Goods marke*******************************/


/** \fn Firm_calc_production_quantity()
 * \brief Firm calculate the intended production volume depending on the current stocks in the malls*/
int Firm_calc_production_quantity()
{
	double production_volume = 0;
	double prod_vol;

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		/*reading current mall stocks   */
		START_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP

			if(current_mall_stock_info_message->firm_id == ID)
			{
				for(int j=0; j< CURRENT_MALL_STOCKS.size;j++)
				{
					if(current_mall_stock_info_message->mall_id==
					CURRENT_MALL_STOCKS.array[j].mall_id)
					{
						/*Firms update the stock level in one mall*/
						CURRENT_MALL_STOCKS.array[j].current_stock= 							current_mall_stock_info_message->stock;
					}		
				}
			}
	
		FINISH_CURRENT_MALL_STOCK_INFO_MESSAGE_LOOP

		/*Computing of mean critical stock levels*/
		double mean_critical_stocks=0;
		for (int j = 0; j < CURRENT_MALL_STOCKS.size;j++)
		{
			mean_critical_stocks += CURRENT_MALL_STOCKS.array[j].critical_stock;
		}

		mean_critical_stocks = mean_critical_stocks/CURRENT_MALL_STOCKS.size;

		/*Computing of out-of-stock costs*/
		OUT_OF_STOCK_COSTS = (PRICE - DISCONT_RATE*UNIT_COSTS)/
		(PRICE+INVENTORY_COSTS_PER_UNIT);

		/*Creating a temporary array of the last X sales per mall*/
		for(int i = 0; i < CURRENT_MALL_STOCKS.size;i++)
		{
			sales_statistics_array sales_mall;
			init_sales_statistics_array(&sales_mall);

			for(int j = 0; j < MALLS_SALES_STATISTICS.size;j++)
			{
				if(CURRENT_MALL_STOCKS.array[i].mall_id==
				MALLS_SALES_STATISTICS.array[j].mall_id)
				{
					add_sales_statistics(&sales_mall,
					MALLS_SALES_STATISTICS.array[j].mall_id,
					MALLS_SALES_STATISTICS.array[j].period,
					MALLS_SALES_STATISTICS.array[j].sales);
				}
			}
			
			/*Lowest number (sales) first*/	
			//sort_mall_sales_list(&sales_mall);
			/* Sorting the sales lists   */
			qsort(sales_mall.array, sales_mall.size, sizeof(sales_statistics),
			 sales_statistics_list_rank_sales_function);

		

			/*Setting the critical values*/
			for(int k = 0; k < FIRM_PLANNING_HORIZON; k++)
			{
				double prob = (1 + k)/FIRM_PLANNING_HORIZON;

				if(prob < OUT_OF_STOCK_COSTS)
				{
					CURRENT_MALL_STOCKS.array[i].critical_stock = 
					sales_mall.array[k].sales;
				}
			}

			/*If the critical level for a mall is zero then the firm sets (with a 				certain prob )the critical level equal the average CL in order to keep 				this mall on the delivery list */
			if(CURRENT_MALL_STOCKS.array[i].critical_stock==0)
			{
				int random_nummer = random_int(0,100);
				if(random_nummer < DELIVERY_PROB_IF_CRITICAL_STOCK_0)
				{
					CURRENT_MALL_STOCKS.array[i].critical_stock=
 					mean_critical_stocks;
				}

			}
	
			free_sales_statistics_array(&sales_mall);
		}


		/*checking whether or not the current mall stocks are below the critical values 		(sS-Rule) If this is the case refill the stock up to the max stock */
		for(int i = 0; i < CURRENT_MALL_STOCKS.size; i++)
		{
			
			if(CURRENT_MALL_STOCKS.array[i].current_stock <= 
			CURRENT_MALL_STOCKS.array[i].critical_stock)	
			{
				/*If stocks are left at the beginning of a new production cycle
				then firms produce the difference between these stocks and the
				critical stock for this mall*/
				if(CURRENT_MALL_STOCKS.array[i].current_stock > 0)
				{
					prod_vol = CURRENT_MALL_STOCKS.array[i].critical_stock - 						CURRENT_MALL_STOCKS.array[i].current_stock;
	
					PLANNED_DELIVERY_VOLUME.array[i].mall_id = 
					CURRENT_MALL_STOCKS.array[i].mall_id;

					PLANNED_DELIVERY_VOLUME.array[i].quantity  = prod_vol;
					production_volume = production_volume + prod_vol;
				}
				else/*If no stocks are left then the firms want to produce more
				    units than the period before. They increase the production 					    volume for one mall by a certain fraction of the last delivery 					    volume*/
				{
					for(int j = 0; j < DELIVERY_VOLUME.size; j++)
					{
						if(PLANNED_DELIVERY_VOLUME.array[i].mall_id==
						DELIVERY_VOLUME.array[j].mall_id)
						{
							prod_vol = DELIVERY_VOLUME.array[j].
							quantity*(1 + ADAPTION_DELIVERY_VOLUME);

							PLANNED_DELIVERY_VOLUME.
							array[i].quantity = prod_vol;

							printf("Prod-Vol %f\n",prod_vol);
						}
					}
				}
				
				production_volume = production_volume + prod_vol;
				
			}
			else/*If  stocks are higher than the critical value no production takes 			    place for this mall*/
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
	
		PLANNED_PRODUCTION_QUANTITY = LAMBDA*production_volume + 
		(1-LAMBDA)*mean_production_quantity;

	}
	else 
	{
		PLANNED_PRODUCTION_QUANTITY = 0;
	}

	return 0;

}

/** \fn Firm_calc_input_demands()
 * \brief Firms calculate the labor demand and the demand for capital goods*/
int Firm_calc_input_demands()
{
	double temp_labour_demand;
	double temp_capital_demand;
	
	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		
		START_PRODUCTIVITY_MESSAGE_LOOP
			/*Update of the actual capital good information*/
			TECHNOLOGICAL_FRONTIER = productivity_message->cap_productivity;
			ACTUAL_CAP_PRICE = productivity_message->cap_good_price;
		
		FINISH_PRODUCTIVITY_MESSAGE_LOOP
		
		/*Calculate labor demand and needed capital goods.
		Complementarity between specific skills and productivity*/
		


		/*Specific skills are limiting factor*/
		if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
		{
	
			temp_capital_demand = PLANNED_PRODUCTION_QUANTITY * 
			(pow((BETA*MEAN_WAGE)/(DEPRICIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
			MEAN_SPECIFIC_SKILLS);
			

			/*Smoothing of capital good demand*/
			if(temp_capital_demand > 
			(1+(INV_INERTIA-1)*DEPRICIATION_RATE)*CAPITAL_STOCK)
			{
				NEEDED_CAPITAL_STOCK = 
				(1+(INV_INERTIA-1)*DEPRICIATION_RATE)*CAPITAL_STOCK;

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
			(pow((BETA*MEAN_WAGE)/	(DEPRICIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
			TECHNOLOGY);
			
			/*Smoothing of capital good demand*/
			if(temp_capital_demand > 
			(1+(INV_INERTIA-1)*DEPRICIATION_RATE)*CAPITAL_STOCK)
			{
				NEEDED_CAPITAL_STOCK = 
				(1+(INV_INERTIA-1)*DEPRICIATION_RATE)*CAPITAL_STOCK;

			}else
			{
				NEEDED_CAPITAL_STOCK=temp_capital_demand;

			}

		temp_labour_demand = pow(PLANNED_PRODUCTION_QUANTITY /
		(pow(NEEDED_CAPITAL_STOCK,BETA)*TECHNOLOGY),1/ALPHA);
		}
		
		/*Depriciation of the old capital stock.
		If additional capital goods are needed...*/
		if(NEEDED_CAPITAL_STOCK > (1-DEPRICIATION_RATE)*CAPITAL_STOCK)
		{
				
			CAPITAL_STOCK = (1-DEPRICIATION_RATE)*CAPITAL_STOCK;
			
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

			CAPITAL_STOCK = (1-DEPRICIATION_RATE)*CAPITAL_STOCK;
			
			/*Recalculation of the labor demand*/
			if(MEAN_SPECIFIC_SKILLS > TECHNOLOGY)
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
				(TECHNOLOGY*pow(CAPITAL_STOCK,BETA)),1/ALPHA));
			}
			else
			{
				EMPLOYEES_NEEDED = (int) (pow(PLANNED_PRODUCTION_QUANTITY/
 				(MEAN_SPECIFIC_SKILLS*pow(CAPITAL_STOCK,BETA)),1/ALPHA));
			}
		}
	}

	return 0;

}



/** \fn Firm_recalc_capital_demand()
 * \brief Depending on LM rationing firms substitute labor with capital */
int Firm_recalc_capital_demand()
{
	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		double optimal_capital_input;
		/*If rationed on the LM*/
		if(NO_EMPLOYEES < EMPLOYEES_NEEDED)
		{
			if(NO_EMPLOYEES > 0 )
			{
		 		optimal_capital_input = pow(PLANNED_PRODUCTION_QUANTITY/
				(TECHNOLOGY* pow(NO_EMPLOYEES,ALPHA)),1/BETA) ; 
	
				NEEDED_CAPITAL_STOCK = (1-TETA)*NEEDED_CAPITAL_STOCK +
				 TETA*optimal_capital_input;	
			}
			else
			{
				NEEDED_CAPITAL_STOCK = 0;
			}
		}
	
		if(NEEDED_CAPITAL_STOCK > 0 && NEEDED_CAPITAL_STOCK > CAPITAL_STOCK)
		{		
			double investments = NEEDED_CAPITAL_STOCK -CAPITAL_STOCK;
			double net_investments;




			if(investments - CAPITAL_STOCK*DEPRICIATION_RATE > 0)
 			{/*Calculation of net investments*/
				net_investments = investments - CAPITAL_STOCK*DEPRICIATION_RATE;
			}
			else
			{
 				net_investments= 0;
			}
		
			/*Calculate the share of net investments*/	
			SHARE_NET_INVESTMENTS = net_investments/investments;

			add_capital_good_request_message(ID,investments,MSGDATA);		
		}
		else
		{
			SHARE_NET_INVESTMENTS=0;
		}
	}
	return 0;
}



/** \fn Firm_calc_pay_costs()
 * \brief In this function the firm receives the purchased investment goods and pays the goods and 	the wage bill. Additionally, the new mean wage and tthe new average specific skill level is 	computed. */
int Firm_calc_pay_costs()
{
	
	double capital_costs;
	double labour_costs;

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		/*Calculate mean wage and mean specific skills:*/
		double ave_wage =0.0;
		double ave_spec_skills =0.0;
		
		for(int i=0;i<EMPLOYEES.size;i++)
		{
			ave_wage+=EMPLOYEES.array[i].wage;
			ave_spec_skills += EMPLOYEES.array[i].specific_skill;
		}
		
		double no_employees = (double) NO_EMPLOYEES;
		if(no_employees==0)
		{
			MEAN_WAGE = WAGE_OFFER;
			MEAN_SPECIFIC_SKILLS = 1;
		}
		else
		{
			MEAN_WAGE = ave_wage /( no_employees);
			MEAN_SPECIFIC_SKILLS =ave_spec_skills/no_employees;
		}
		
		/*Firm receives the investment goods*/
		
		START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
		
			TECHNOLOGICAL_FRONTIER = capital_good_delivery_message->productivity;

			if(ID == capital_good_delivery_message->firm_id)
			{

				/*Update of productivity*/
				TECHNOLOGY = CAPITAL_STOCK / (CAPITAL_STOCK +
 				capital_good_delivery_message->capital_good_delivery_volume)
				*TECHNOLOGY + 
				capital_good_delivery_message->capital_good_delivery_volume/
				(CAPITAL_STOCK + 
				capital_good_delivery_message->capital_good_delivery_volume)
				*capital_good_delivery_message->productivity;

				/*Update of the capital stock*/
				CAPITAL_STOCK += capital_good_delivery_message
				->capital_good_delivery_volume;
				
				/*Computing the capital bill*/
				capital_costs = capital_good_delivery_message
				->capital_good_delivery_volume* capital_good_delivery_message
				->capital_good_price;
				
				/*This is to keep the current price and best pratice technology in 					memory*/
				ACTUAL_CAP_PRICE =capital_good_delivery_message
				->capital_good_price;

				TECHNOLOGICAL_FRONTIER = capital_good_delivery_message
				->productivity;
			}

		FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP



		/* This determines the realized production volume*/
		if(PLANNED_PRODUCTION_QUANTITY != 0)
		{
		
			if(MEAN_SPECIFIC_SKILLS < TECHNOLOGY)
			{	
			
				PRODUCTION_QUANTITY = MEAN_SPECIFIC_SKILLS * 
				pow(NO_EMPLOYEES,ALPHA)*pow(CAPITAL_STOCK,BETA); 
			}
			else 
			{
				PRODUCTION_QUANTITY = TECHNOLOGY * 
				pow(NO_EMPLOYEES,ALPHA)*pow(CAPITAL_STOCK,BETA); 
			}

			/*Pay the costs*/

			add_pay_capital_goods_message(ID,capital_costs,
			SHARE_NET_INVESTMENTS,MSGDATA );

			labour_costs=0;

			for(int i=0; i<EMPLOYEES.size;i++)
			{
				labour_costs += EMPLOYEES.array[i].wage;

				add_wage_payment_message(ID,
				EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
				TECHNOLOGY,MEAN_SPECIFIC_SKILLS,MSGDATA);
			}
		/*Calculate the unit costs and total costs*/
			if(PRODUCTION_QUANTITY!=0 )
			{
				UNIT_COSTS=(labour_costs+CAPITAL_STOCK*DEPRICIATION_RATE
				*ACTUAL_CAP_PRICE) / PRODUCTION_QUANTITY;
		
				PRICE_LAST_MONTH=PRICE;
				PRICE = UNIT_COSTS*(1 + MARK_UP);
			}

			COSTS = capital_costs + labour_costs;
		

		}

		printf("Production Quantity : %f\n",PRODUCTION_QUANTITY);

		remove_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,0);
		add_double(&LAST_PLANNED_PRODUCTION_QUANTITIES,PLANNED_PRODUCTION_QUANTITY);

	}
	else 
	{
		PRODUCTION_QUANTITY =0;
	}

	return 0;
}


/** \fn Firm_send_goods_to_mall()
 * \brief Here the firms send the produced goods to the malls. If the realized output is less than 	the intended one, then the malls are only delivered with a proportional share of their 		plannded delivery volumes. */

int Firm_send_goods_to_mall()
{ 

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
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
					/*If planned prod vol > realized prod vol -> curtain the 						delivery vol*/
					if(delivery_volume>PRODUCTION_QUANTITY)
					{
						DELIVERY_VOLUME.array[j].quantity =
 						PRODUCTION_QUANTITY / delivery_volume * 						PLANNED_DELIVERY_VOLUME.array[i].quantity;
					
					}else /*otherwise planned = realized del vol*/
					
					if(PRODUCTION_QUANTITY > delivery_volume &&
 					delivery_volume !=0)
					{
						DELIVERY_VOLUME.array[j].quantity = 							PRODUCTION_QUANTITY / delivery_volume*
						PLANNED_DELIVERY_VOLUME.array[i].quantity;

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
					DELIVERY_VOLUME.array[j].quantity,QUALITY,PRICE,MSGDATA);
			
				}
			}
		}
	}

	return 0;
}

/** \fn Firm_calc_revenue()
 * \brief Here the firms calc the revenues and profits and then distribute the dividends to 	    households 
 */
int Firm_calc_revenue()
{
	REVENUE_PER_DAY=0.0;
	TOTAL_SOLD_QUANTITY=0.0;
	double dividend_per_household;


	/*calc the daily revenue and sum up the monthly revenue*/
	START_SALES_MESSAGE_LOOP
	
		if(sales_message->firm_id==ID)
		{
		
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
		}

	FINISH_SALES_MESSAGE_LOOP

	/*The onthly sales statistics*/
	CUM_TOTAL_SOLD_QUANTITY+=TOTAL_SOLD_QUANTITY;	
	
	/*On a monthly base the earnings are computed and dividends distributed*/
	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		EARNINGS= CUM_TOTAL_SOLD_QUANTITY*PRICE - COSTS;
		
		if(EARNINGS >0)
		{

			if((ACCOUNT <0 &&(-1)*ACCOUNT<=CUM_TOTAL_SOLD_QUANTITY*PRICE)||
			(ACCOUNT>0&&ACCOUNT <=CUM_TOTAL_SOLD_QUANTITY*PRICE))
			{
				NET_PROFIT = EARNINGS - DIVIDEND_RATE * EARNINGS;
				dividend_per_household =DIVIDEND_RATE * EARNINGS / NO_HOUSEHOLDS ;

				add_dividend_message(dividend_per_household,MSGDATA);
			}
			else
			{
				NET_PROFIT =0;
				dividend_per_household =  EARNINGS / NO_HOUSEHOLDS ;

				add_dividend_message(dividend_per_household,MSGDATA);
			}
		}
		else
		{
			NET_PROFIT= EARNINGS;
		}
		 
		ACCOUNT = ACCOUNT + NET_PROFIT;
		CUM_TOTAL_SOLD_QUANTITY=0.0;
		CUM_REVENUE =0.0;
		
		
		/*The sales per mall must be stored for the inventory rule*/
			
		int remove_index;
				
		for(int j=0; j < MALLS_SALES_STATISTICS.size;j++)
		{
					 
			if(MALLS_SALES_STATISTICS.array[j].period== FIRM_PLANNING_HORIZON)
			{		
				remove_index = j;
				remove_sales_statistics(&MALLS_SALES_STATISTICS, remove_index);
				j--;
			}	
		}
										
		for(int j=0; j < MALLS_SALES_STATISTICS.size;j++)
		{
			MALLS_SALES_STATISTICS.array[j].period++;	
		}
				
				
		for(int i=0; i< SOLD_QUANTITIES.size;i++)
		{
			
			add_sales_statistics(&MALLS_SALES_STATISTICS,
			SOLD_QUANTITIES.array[i].mall_id, 1 , 
			SOLD_QUANTITIES.array[i].sold_quantity);
		
			SOLD_QUANTITIES.array[i].sold_quantity=0;
			SOLD_QUANTITIES.array[i].stock_empty=0;	
		}
		/*Calculate the mean wage*/
		if(PLANNED_PRODUCTION_QUANTITY>PRODUCTION_QUANTITY  && DAY>20)
		{
			double mean_wage =0.0;
				
			for( int i=0; i < EMPLOYEES.size; i++)
			{
				mean_wage+= EMPLOYEES.array[i].wage;
			}

			double no_employees = (int) NO_EMPLOYEES;
			MEAN_WAGE = mean_wage/no_employees; 
		
	
		}		
					
	}
		
	return 0;
}






/** \fn Firm_update_specific_skills_of_workers()()
 * \brief 	Because the specific skills of workers have changed the firms update the specific 			skill levels of the workers.
 */
int Firm_update_specific_skills_of_workers()
{

	START_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP

		if(specific_skill_update_message->firm_id==ID)
		{
			for(int i=0; i<EMPLOYEES.size;i++)
			{
				if(specific_skill_update_message->id==EMPLOYEES.array[i].id)
				{
					EMPLOYEES.array[i].specific_skill=
					specific_skill_update_message->specific_skills;
				}
			}
		}

	FINISH_SPECIFIC_SKILL_UPDATE_MESSAGE_LOOP

	return 0;
}


/** \fn Firm_send_data_to_Market_Research()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Firm_send_data_to_Market_Research()
{
	if(DAY%MONTH == 0)
	{
		add_firm_send_data_message(ID, REGION_ID, VACANCIES, 
		NO_EMPLOYEES, NO_EMPLOYEES_SKILL_1, 
		NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4,
 		NO_EMPLOYEES_SKILL_5, 
		MEAN_WAGE, MEAN_SPECIFIC_SKILLS, AVERAGE_S_SKILL_OF_1, 
		AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3,
		AVERAGE_S_SKILL_OF_4, AVERAGE_S_SKILL_OF_5, 
		MSGDATA);
	}	

	return 0;
}

