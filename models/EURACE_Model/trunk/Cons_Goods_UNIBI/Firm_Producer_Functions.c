#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "../Firm_Library_Functions.h"

/* Library functions */

int sales_statistics_list_rank_sales_function(const void *x, const void *y)
{
	if( ((sales_statistics *)x)->sales < ((sales_statistics *)y)->sales) return -1;
	else if( ((sales_statistics *)x)->sales > ((sales_statistics *)y)->sales) return 1;
	else return 0;
}

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
			(pow((BETA*MEAN_WAGE)/(DEPRECIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
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
			(pow((BETA*MEAN_WAGE)/	(DEPRECIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
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
   
		/*Depriciation of the old capital stock.
		If additional capital goods are needed...*/

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
		
		/*This computes the financial needings for production*/
		PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;
	

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
	
			free_sales_statistics_array(&sales_mall);
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
							prod_vol = DELIVERY_VOLUME.array[j].
							quantity*(1 + ADAPTION_DELIVERY_VOLUME);

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

	
	

	return 0;

}

	
/** \fn Firm_calc_input_demands()
 * \brief Firms calculate the labor demand and the demand for capital goods*/
int Firm_calc_input_demands()
{
	int i,imax;
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
			(pow((BETA*MEAN_WAGE)/(DEPRECIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
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
			(pow((BETA*MEAN_WAGE)/	(DEPRECIATION_RATE*ACTUAL_CAP_PRICE*ALPHA),ALPHA)/
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
		
        //The capital stock is heterogeneous.
        //struct CAPITAL_STOCK               		: dynamic array of capital_stock_item; each item is a struct of a certain purchased quantity of capital stock
        //double units                      		: current units of capital in the item
		//double purchase_price                     : purchase_price of the units of capital in the item
        //double depreciation_units_per_period      : the capital stock depreciates with a fixed value in each period (inn units of capital)
        
        //We loop over all capital stock items and update the current_value
        imax = CAPITAL_STOCK.size;
        TOTAL_VALUE_CAPITAL_STOCK=0;
        TOTAL_UNITS_CAPITAL_STOCK=0;
        for (i=0;i<imax;i++)
        {
            //decrease the value of each installment of capital by its own depreciation value
            CAPITAL_STOCK.array[i].units -= CAPITAL_STOCK.array[i].depreciation_units_per_period;
            
            //update the current units of capital stock:
            TOTAL_UNITS_CAPITAL_STOCK += CAPITAL_STOCK.array[i].units;

            //update the current value of the capital stock:
            TOTAL_VALUE_CAPITAL_STOCK += CAPITAL_STOCK.array[i].units*CAPITAL_STOCK.array[i].purchase_price;

            //if the period of full depreciation has been reached: remove the capital_stock_item
            if (CAPITAL_STOCK.array[i].units==0)
            {
                remove_capital_stock_item(&CAPITAL_STOCK, i);
            }
        }       
        
		/*Depriciation of the old capital stock.
		If additional capital goods are needed...*/

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
		
		/*This computes the financial needings for production*/
		PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE + DEMAND_CAPITAL_STOCK*ACTUAL_CAP_PRICE;

	return 0;
}


/* GENUA NOTE: This needs to be updated with the new style of checking FINANCIAL_NEEDS
 * See file: Firm_Financial_Management
 */

/** \fn Firm_calc_production_quantity_2()
 * \brief Firms iterate over the planned production quantity decreasing it incrementally,
 * such that the corresponding labor demand and capital demand can be financed by the actually obtained financial resources.*/
int Firm_calc_production_quantity_2()
{
	//Here we set a fraction of the planned production quantity
	double decrement;
	decrement = ADAPTION_PRODUCTION_VOLUME_DUE_TO_INSUFFICIENT_FINANCES*PLANNED_PRODUCTION_QUANTITY;
	
	//Only direct payments need to be financed
	if (DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING==1 && DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING==0)
	{
		while (PLANNED_PRODUCTION_COSTS > PAYMENT_ACCOUNT)
		{
			PLANNED_PRODUCTION_QUANTITY -= decrement;
			Firm_calc_input_demands_2();
		}
	}

	//Direct and delayed payments need to be financed
	if (DIRECT_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING==1 && DELAYED_FINANCIAL_NEEDS_REQUIRE_EXTERNAL_FINANCING==1)
	{
		while (PLANNED_PRODUCTION_COSTS > PAYMENT_ACCOUNT - FRACTION_RESERVED_FOR_DELAYED_PAYMENTS*TOTAL_EXTERNAL_FINANCING_OBTAINED)
		{
			PLANNED_PRODUCTION_QUANTITY -= decrement;
			Firm_calc_input_demands_2();
		}
	}

	return 0;
}

/** \fn Firm_send_capital_demand()
 * \brief Firm sends demand for capital to the capital goods market. */
int Firm_send_capital_demand()
{
	int i;
	
		TOTAL_CAPITAL_DEPRECIATION_VALUE=0;
		TOTAL_CAPITAL_DEPRECIATION_UNITS=0;
		
        for (i=0;i<CAPITAL_STOCK.size;i++)
        {
            //sum the depreciation values of each item in the capital stock 
        	TOTAL_CAPITAL_DEPRECIATION_VALUE += CAPITAL_STOCK.array[i].depreciation_units_per_period*CAPITAL_STOCK.array[i].purchase_price;
        	TOTAL_CAPITAL_DEPRECIATION_UNITS += CAPITAL_STOCK.array[i].depreciation_units_per_period;
        }
        
		if ( (NEEDED_CAPITAL_STOCK > 0) && (NEEDED_CAPITAL_STOCK > TOTAL_UNITS_CAPITAL_STOCK))
		{					
			double net_investments;

			if(DEMAND_CAPITAL_STOCK - TOTAL_CAPITAL_DEPRECIATION_UNITS > 0)
 			{/*Calculation of net investments*/
				net_investments = DEMAND_CAPITAL_STOCK - TOTAL_CAPITAL_DEPRECIATION_UNITS;
			}
			else
			{
 				net_investments= 0;
			}
		
			/*Calculate the share of net investments*/	
			SHARE_NET_INVESTMENTS = net_investments/DEMAND_CAPITAL_STOCK;

			add_capital_good_request_message(ID,DEMAND_CAPITAL_STOCK);		
		}
		else
		{
			SHARE_NET_INVESTMENTS=0;
		}

	return 0;
}

/** \fn Firm_calc_pay_costs()
 * \brief In this function the firm receives the purchased investment goods and pays the goods and 	the wage bill. Additionally, the new mean wage and tthe new average specific skill level is 	computed. */
int Firm_calc_pay_costs()
{
	int i,imax;
	double capital_costs;
	double labour_costs;
    
	double units;
	double purchase_price;
	double productivity;
	double depreciation_units_per_period;
		
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
	capital_costs=0;
	
	START_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP
		

		/*Adding a new capital stock item*/
		units			= capital_good_delivery_message->capital_good_delivery_volume;
		purchase_price	= capital_good_delivery_message->capital_good_price;
		productivity	= capital_good_delivery_message->productivity;
		depreciation_units_per_period = DEPRECIATION_RATE*units;
		
		add_capital_stock_item(&CAPITAL_STOCK, units, purchase_price, productivity, depreciation_units_per_period);
		
		/*Update the total units of capital*/
		TOTAL_UNITS_CAPITAL_STOCK += units;
		
		/*Determine the weighted average productivity of the total capital stock*/
		imax = CAPITAL_STOCK.size;
		TECHNOLOGY=0;
		for (i=0;i<imax;i++)
		{
			TECHNOLOGY += CAPITAL_STOCK.array[i].productivity*CAPITAL_STOCK.array[i].units/TOTAL_UNITS_CAPITAL_STOCK;
		}
 
		/*Computing the capital bill*/
		capital_costs += capital_good_delivery_message
		->capital_good_delivery_volume* capital_good_delivery_message
		->capital_good_price;
		
	FINISH_CAPITAL_GOOD_DELIVERY_MESSAGE_LOOP


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

		/*Pay the costs*/

		add_pay_capital_goods_message(ID,capital_costs,
		SHARE_NET_INVESTMENTS);

		labour_costs=0;

		for(int i=0; i<EMPLOYEES.size;i++)
		{
			labour_costs += EMPLOYEES.array[i].wage;

			add_wage_payment_message(ID,
			EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
			TECHNOLOGY,MEAN_SPECIFIC_SKILLS);
		}
	/*Calculate the unit costs and total costs*/
		if(PRODUCTION_QUANTITY!=0 )
		{	        
			UNIT_COSTS=(labour_costs + TOTAL_CAPITAL_DEPRECIATION_VALUE) / PRODUCTION_QUANTITY;
	
			PRICE_LAST_MONTH=PRICE;
			PRICE = UNIT_COSTS*(1 + MARK_UP);
		}

		PRODUCTION_COSTS = capital_costs + labour_costs;
	}

	/*printf("Production Quantity : %f\n",PRODUCTION_QUANTITY);*/

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
					DELIVERY_VOLUME.array[j].quantity,QUALITY,PRICE);
			
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
	double mean_wage;
	double no_employees;
	
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
	
	FINISH_SALES_MESSAGE_LOOP
	
	/*GENUA*/
	/*add_bank_account_update_message(BANK_ID, PAYMENT_ACCOUNT);*/
	//Not needed here: there is a function after this called Firm_send_payments_to_bank
	
	PAYMENT_ACCOUNT += REVENUE_PER_DAY;
	
	/*The monthly sales statistics*/
	CUM_TOTAL_SOLD_QUANTITY+=TOTAL_SOLD_QUANTITY;	
	
	/*On a monthly base the earnings are computed and dividends distributed*/
	//See the functions for financial management
		
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
			mean_wage =0.0;
				
			for( int i=0; i < EMPLOYEES.size; i++)
			{
				mean_wage+= EMPLOYEES.array[i].wage;
			}

			no_employees = (int) NO_EMPLOYEES;
			MEAN_WAGE = mean_wage/no_employees; 
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


