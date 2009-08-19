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
/** \fn IGFirm_update_productivity()
 * \brief IGFirm inceases productivity via a stochastic process and the according price */
int IGFirm_update_productivity_price()
{
printf("IN FUNCTION: IGFirm_calc_research_employees\n");
	printf("*****************************************************************************\n");
	 if(DAY >= TRANSITION_PHASE)
	 {}

	int i,j;
	int influence_the_variance = 75; 
	/*increase this variable to get a lower variance of the normal distribution/the random
	progress*/

	double k,random_progress,innovation_probability;
	i = random_int( 0 ,100);
	
	/*Create normal distributed random number: mean~0, standard deviation ~ 0.01*/
	for(j = 0; j < 12; j++)
	{
		k = (double)(random_int(0, 1000))/1000;
		random_progress += ((k - 0.5)/influence_the_variance);	
	}
//printf("1: DURATION_UNTIL_NEXT_INNOVATION: %d\n",DURATION_UNTIL_NEXT_INNOVATION);
//printf("1: INNOVATION_SUCCESS: %d\n",INNOVATION_SUCCESS);
	
	DURATION_UNTIL_NEXT_INNOVATION += 12;
	INNOVATION_SUCCESS = 0;	
	
	/*Calculate the probability of completing the innovation project: The probability can not 
	be larger than 1*/
	if((NO_RESEARCH_EMPLOYEES*EFFICIENCY_INNOVATION) < 1)
	{
		/**Project completed with probability = innovation_probability*/
		innovation_probability = NO_RESEARCH_EMPLOYEES*EFFICIENCY_INNOVATION;	
	}
	else //if NO_RESEARCH_EMPLOYEES*EFFICIENCY_INNOVATION >= 1
	{
		/*Project completed*/
		innovation_probability = 1;	
	}
//printf("Innovation_probability: %f\n",innovation_probability);
	/*If project is completed calculate the productivity progress*/
	if((innovation_probability * 100) >= i)
	{
		//if progress is larger than zero/positiv
		if((random_progress + PRODUCTIVITY_PROGRESS) > 0)
		{
			INNOVATION_SUCCESS = 1;
			ADDITIONAL_PRODUCTIVITY =  (PRODUCTIVITY_PROGRESS + random_progress);
			PRODUCTIVITY = PRODUCTIVITY*(1 + ADDITIONAL_PRODUCTIVITY);
			//CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE*(1 +0.5* ADDITIONAL_PRODUCTIVITY);
//printf("PRODUCTIVITY %f\n",PRODUCTIVITY);
//printf("ADDITIONAL_PRODUCTIVITY %f\n",ADDITIONAL_PRODUCTIVITY);
		}
	}
//printf("2: DURATION_UNTIL_NEXT_INNOVATION: %d\n",DURATION_UNTIL_NEXT_INNOVATION);
//printf("2: INNOVATION_SUCCESS: %d\n",INNOVATION_SUCCESS);
/**********************TEST: NORMAL DISTRIBUTION************************************************/
	/*int l,m,counter;
	counter = 1000000;
	double one,two,three,four,five,six,seven,eight,nine,ten,small,big;
	double diff[counter];
	double  sum,variance,deviation;
	sum=0.0;
	for( l = 0 ; l < counter; l++)
	{ 
		random_progress = 0.0;
		for(j = 0; j < 12; j++)
		{
			k = (double)(random_int(0, 1000))/1000;
			random_progress += ((k - 0.5)/75);	
		}

		diff[l]= random_progress;
		random_progress = random_progress/1; //printf("PROGRESS  %f\n",random_progress);
		//printf("sum %f\n",sum);
		sum += random_progress;

		if(-0.05 < random_progress && random_progress <= -0.04)
		{
			one++;//printf(" 1 \n");
		}
		if(-0.04 < random_progress && random_progress <= -0.03)
		{
			two++; //printf(" 2 \n");
		}
		if(-0.03 < random_progress && random_progress <= -0.02)
		{
			three++;//printf(" 3 \n");
		}
		if(-0.02 < random_progress  && random_progress <= -0.01)
		{
			four++;//printf(" 4 \n");
		}
		if(-0.01 < random_progress  && random_progress <= 0)
		{
			five++;//printf(" 5 \n");
		}
		if(0 < random_progress  && random_progress <= 0.01)
		{
			six++;//printf(" 6 \n");
		}
		if(0.01 < random_progress  && random_progress <= 0.02)
		{
			seven++;//printf(" 7 \n");
		}
		if(0.02 < random_progress  && random_progress <= 0.03)
		{
			eight++;//printf(" 8 \n");
		}
		if(0.03 < random_progress  && random_progress <=0.04)
		{
			nine++;//printf(" 9 \n");
		}
		if(0.04 < random_progress  && random_progress <=0.05)
		{
			ten++;//printf(" 10 \n");
		}
		if(-0.05 >= random_progress)
		{
			small++;//printf(" small \n");
		}
		if(0.05 < random_progress)
		{
			big++;//printf(" big \n");
		}

		
	}

	sum= sum/counter;
	printf("sum %f\n",sum);

	for(m=0; m < counter; m++)
	{	
		//printf("DIFF %f\n",pow((diff[m] - sum),2));
		variance += pow((diff[m] - sum),2);
	}

	variance = variance/counter;
	printf("VARIANCE  %f\n",variance);
	deviation = pow(variance,0.5);
	printf("deviation  %f\n",deviation);

	printf("%f  %f  %f  %f  %f  %f  %f  %f  %f  %f	%f  %f\n" ,one,two,three,four,five, 	
	six,seven,eight,nine,ten,small, big);*/
printf("*****************************************************************************\n");
	return 0;
}


/** \fn int IGFirm_calc_research_employees()
 * \brief IGFirm determines the number of research_employees */
int IGFirm_calc_research_employees()
{

	printf("IN FUNCTION: IGFirm_calc_research_employees\n");
	printf("******************************************************************************\n");
	

	//int m;
	if(INNOVATION_SUCCESS == 1)
	{	
		//double demand_change;
			
		/*store information about the innovation period: capital good demand after last 		innovation, additional productivity of the new innovation, number of months after 			last innovation, percent change of capital good demand*/
		/*add_innovation_period_info(&INNOVATION_PERIOD_INFO_LIST,
		(REVENUE_FOR_INNOVATION/DURATION_UNTIL_NEXT_INNOVATION),
		CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION,
		ADDITIONAL_PRODUCTIVITY,
		DURATION_UNTIL_NEXT_INNOVATION,
		0);*/
		
		
		//m = INNOVATION_PERIOD_INFO_LIST.size;
		
		/*Ignore the starting values*/	
		/*if(m > 1)
		{
			//calculate the demand change per month
			demand_change= ((INNOVATION_PERIOD_INFO_LIST.array[m-1].capital_good_demand
			/INNOVATION_PERIOD_INFO_LIST.array[m-1].duration_until_next_innovation)/
			(INNOVATION_PERIOD_INFO_LIST.array[m-2].capital_good_demand
			/INNOVATION_PERIOD_INFO_LIST.array[m-2].duration_until_next_innovation))-1;
			
	
			INNOVATION_PERIOD_INFO_LIST.array[m-1].demand_change= demand_change;
		}*/
		
		/*"start" of new innovation period*/
		DURATION_UNTIL_NEXT_INNOVATION = 0;
		CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION = 0;
		
	}
//printf("DURATION_UNTIL_NEXT_INNOVATION: %d\n",DURATION_UNTIL_NEXT_INNOVATION);
//printf("CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION: %f\n",CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION);

	//ESTIMATED_RESEARCHER_WAGE = WAGE_OFFER_FOR_SKILL_6;


	/*1. option: The number Research employees is determined when there is a successful 	
	Innovation*/
	
	/*if(INNOVATION_SUCCESS == 1 )
	{
		RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
		INNOVATION_PERIOD_INFO_LIST.array[INNOVATION_PERIOD_INFO_LIST.size-1].
		revenue_for_innovation/WAGE_OFFER_FOR_SKILL_6);

		REVENUE_FOR_INNOVATION = 0;

	}*/

	/*To be sure to have at least some R&D*/
	/*if(NO_RESEARCH_EMPLOYEES == 0 && INNOVATION_SUCCESS == 0)
	{
		RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
		(REVENUE_FOR_INNOVATION/DURATION_UNTIL_NEXT_INNOVATION)
		/WAGE_OFFER_FOR_SKILL_6);

		if(RESEARCH_EMPLOYEES_NEEDED > 25)
		{
			RESEARCH_EMPLOYEES_NEEDED = 25;
		}
		
	}*/

printf("REVENUE_FOR_INNOVATION: %f\n",REVENUE_FOR_INNOVATION/12);
//printf("WAGE_OFFER_FOR_SKILL_6: %f\n",WAGE_OFFER_FOR_SKILL_6);

	/*2. option: The number Research employees is determined every year*/

	RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
	(REVENUE_FOR_INNOVATION/12))/WAGE_OFFER_FOR_SKILL_6;

		/*if(RESEARCH_EMPLOYEES_NEEDED > 50)
		{
			RESEARCH_EMPLOYEES_NEEDED = 50;
		}*/

	REVENUE_FOR_INNOVATION = 0;

	printf("RESEARCH_EMPLOYEES_NEEDED %d \n",RESEARCH_EMPLOYEES_NEEDED);	
	//printf("CUM_REVENUES %f \n",CUM_REVENUES);
	
	printf("***************************************************************************\n");
	return 0;
}


int IGFirm_set_quantities_zero()
{

	//PRODUCTION_QUANTITY = 0;
	return 0;
}




/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm send quality and price information */
int IGFirm_send_quality_price_info()
{
	printf("IN FUNCTION: IGFirm_send_quality_price_info\n");
	printf("************************************************************************\n");
	add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE);

	printf("PRODUCTIVITY %f \n",PRODUCTIVITY);
	printf("CAPITAL_GOOD_PRICE %f \n",CAPITAL_GOOD_PRICE);
	printf("************************************************************************\n");	
	return 0;
}


/** \fn IGFirm_calc_production_quantity()
 * \brief IGFirm calculate the intended production volume depending on the current stocks in the malls*/
int IGFirm_calc_production_quantity()
{

	printf("IN FUNCTION: IGFirm_calc_production_quantity()\n");
	printf("***************************************************************************\n");

	/*Remove the oldest capital good demand and add the capital good demand of the last 	
	period*/
	remove_double(&LAST_CAPITAL_GOOD_DEMAND,0);
	add_double(&LAST_CAPITAL_GOOD_DEMAND, CAPITAL_GOOD_DEMAND);
	
	if(CAPITAL_GOOD_DEMAND > 0)
	{
		NO_ZERO_DEMAND = 0;
	}
	else
	{
		NO_ZERO_DEMAND++;
	}

	remove_double(&LAST_CAPITAL_GOOD_SALES,0);
	add_double(&LAST_CAPITAL_GOOD_SALES, SALES);


	printf("CAPITAL_GOOD_DEMAND %f \n",CAPITAL_GOOD_DEMAND);
	printf("SALES %f \n",SALES);
	printf("CAPITAL_GOOD_STORE %f \n",CAPITAL_GOOD_STORE);

	

	/*Computing of out-of-stock costs*/
	/*OUT_OF_STOCK_COSTS = (CAPITAL_GOOD_PRICE - DISCOUNT_RATE*UNIT_COSTS)/
	(CAPITAL_GOOD_PRICE+IG_INVENTORY_COSTS_PER_UNIT);

	printf("OUT_OF_STOCK_COSTS %f \n",OUT_OF_STOCK_COSTS);
	printf("CAPITAL_GOOD_PRICE %f \n",CAPITAL_GOOD_PRICE);
	printf("UNIT_COSTS %f \n",UNIT_COSTS);*/

	

	double sales[FIRM_PLANNING_HORIZON];
	double mean_of_last_sales;
	int i;
	for(i = 0; i < 10; i++)
	{
		sales[i] = LAST_CAPITAL_GOOD_SALES.array[i];
		mean_of_last_sales += LAST_CAPITAL_GOOD_SALES.array[i];
	}

	mean_of_last_sales = mean_of_last_sales/FIRM_PLANNING_HORIZON;	
	//printf("mean_of_last_sales %f\n",mean_of_last_sales);

	/*printf("********SALES BEFORE ********\n");
	for(int y = 0; y<10;y++)
	{
		printf("%f \n", sales[y]);
	}*/

	double temp1;
	double temp2;

	
	for(i = 0; i < 10; i++)
	{
		int j;
		for(j = (i+1); j < 10;j++)
		{
			temp1 = sales[i];
			temp2 = sales[j];

			if(temp2 < temp1)
			{
				sales[i] = temp2;
				sales[j] = temp1;
			}
		}
	}

	/*printf("********SALES after ********\n");
	for(int z = 0; z<10;z++)
	{
		printf("%f \n", sales[z]);
	}*/

	/*Setting the critical values*/
	//for(int k = 0; k < FIRM_PLANNING_HORIZON; k++)
	//{
	//	double prob = (1 + k)/(double)FIRM_PLANNING_HORIZON;
	//	if(prob < OUT_OF_STOCK_COSTS)
	//	{
			CRITICAL_STOCK = sales[8];
			
			
	//	}
		/*if(OUT_OF_STOCK_COSTS < 1/(double)FIRM_PLANNING_HORIZON)
		{
			CRITICAL_STOCK = 0.0;
		}*/
		
	//}
	
	if(CRITICAL_STOCK == 0)
	{
		int random_nummer = random_int(0,100);
		if(random_nummer < DELIVERY_PROB_IF_CRITICAL_STOCK_0)
		{
			CRITICAL_STOCK = mean_of_last_sales;
			//printf("CRITICAL_STOCK DETERMINED BY MEAN \n");
		}

	}
//printf("CRITICAL_STOCK: %f \n",CRITICAL_STOCK);	
//printf("CAPITAL_GOOD_STORE: %f \n",CAPITAL_GOOD_STORE);

	if(CAPITAL_GOOD_STORE <= CRITICAL_STOCK)
	{
		if(CAPITAL_GOOD_STORE > 0)
		{
			PLANNED_PRODUCTION_QUANTITY = CRITICAL_STOCK - CAPITAL_GOOD_STORE;
		}
		else
		{
			PLANNED_PRODUCTION_QUANTITY = CRITICAL_STOCK*
			(1 + ADDITIONAL_CAPITAL_GOOD_PRODUCTION);
		}
	}
	else
	{
		PLANNED_PRODUCTION_QUANTITY = 0.0;	
	}

//printf("1: PLANNED_PRODUCTION_QUANTITY OF SALES ARRAY %f \n",PLANNED_PRODUCTION_QUANTITY);

	double mean_last_demand = 0.0;
	
	for(i = 0; i < LAST_CAPITAL_GOOD_DEMAND.size; i++)
	{
		mean_last_demand += LAST_CAPITAL_GOOD_DEMAND.array[i];
		
	}

	
	mean_last_demand = mean_last_demand/(double)LAST_CAPITAL_GOOD_DEMAND.size;
	//printf("mean_last_demand %f \n",mean_last_demand);
	
	/*if(mean_last_demand < CAPITAL_GOOD_DEMAND)
	{
		mean_last_demand = mean_last_demand*(1+ADDITIONAL_CAPITAL_GOOD_PRODUCTION);
	}*/
		

	PLANNED_PRODUCTION_QUANTITY = IG_LAMBDA*PLANNED_PRODUCTION_QUANTITY +
	(1-IG_LAMBDA)*mean_last_demand;

	if(NO_ZERO_DEMAND > 0)
	{
		PLANNED_PRODUCTION_QUANTITY = 0.0;	
	}

	if(CAPITAL_GOOD_STORE > CRITICAL_STOCK)
	{
		PLANNED_PRODUCTION_QUANTITY = 0.0;
	}

	
	/*only for getdata: every 20 iteration*/
	

	printf("CAPITAL_GOOD_STORE %f \n",CAPITAL_GOOD_STORE);
	printf("2: PLANNED_PRODUCTION_QUANTITY AS AVERAGE %f \n",PLANNED_PRODUCTION_QUANTITY);
	printf("CAPITAL_GOOD_DEMAND_LAST_MONTH %f \n",CAPITAL_GOOD_DEMAND_LAST_MONTH);
	
	printf("********************************************************************************\n");
	return 0;
}

/* \fn IGFirm_calc_input_demands()
 * \brief IGFirms calculate the labor demand and the demand for energy*/
int IGFirm_calc_input_demands()
{
	printf("IN FUNCTION: IGFirm_calc_input_demands \n");
	printf("******************************************\n");

	EMPLOYEES_NEEDED = (int)(PLANNED_PRODUCTION_QUANTITY
	/(PRODUCTION_PRODUCTIVITY*MEAN_SPECIFIC_SKILLS));

	
	/*Planned production costs for the next period: for the calculation of
	 PRODUCTION_LIQUIDITY_NEEDS in IGFirm_compute_total_liquidity_needs() (Fin-Man)*/
	PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE +
 	RESEARCH_EMPLOYEES_NEEDED*MEAN_RESEARCH_WAGE;

	//printf("MEAN_SPECIFIC_SKILLS %f \n",MEAN_SPECIFIC_SKILLS);
	//printf("PRODUCTION_PRODUCTIVITY %f \n",PRODUCTION_PRODUCTIVITY);	
	printf("PLANNED_PRODUCTION_QUANTITY %f \n",PLANNED_PRODUCTION_QUANTITY);	
	printf("EMPLOYEES_NEEDED %d \n",EMPLOYEES_NEEDED);
	//printf("RESEARCH_EMPLOYEES_NEEDED %d \n",RESEARCH_EMPLOYEES_NEEDED);
	
	printf("******************************************\n");

    return 0;	
}



int IGFirm_calc_production_quantity_2()
{

printf("IN FUNCTION: IGFirm_calc_production_quantity_2()\n");
printf("********************************************************************************\n");

printf("FINANCIAL_RESOURCES_FOR_PRODUCTION %f\n",FINANCIAL_RESOURCES_FOR_PRODUCTION);
printf("PLANNED_PRODUCTION_COSTS %f\n",PLANNED_PRODUCTION_COSTS);
printf("EMPLOYEES_NEEDED %d\n",EMPLOYEES_NEEDED);
printf("RESEARCH_EMPLOYEES_NEEDED %d\n",RESEARCH_EMPLOYEES_NEEDED);

	FINANCIAL_RESOURCES_FOR_PRODUCTION = PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS;
	
	if( FINANCIAL_RESOURCES_FOR_PRODUCTION > 0.0)
	{
		while (PLANNED_PRODUCTION_COSTS > FINANCIAL_RESOURCES_FOR_PRODUCTION)
		{
			if(EMPLOYEES_NEEDED >0)
			{
				EMPLOYEES_NEEDED -= 1;

				PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE +
 				RESEARCH_EMPLOYEES_NEEDED*MEAN_RESEARCH_WAGE;
			}

			
			if(PLANNED_PRODUCTION_COSTS > FINANCIAL_RESOURCES_FOR_PRODUCTION && 
			RESEARCH_EMPLOYEES_NEEDED > 0)
			{
				RESEARCH_EMPLOYEES_NEEDED -= 1;

				PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE +
 				RESEARCH_EMPLOYEES_NEEDED*MEAN_RESEARCH_WAGE;
			}
			printf("PLANNED_PRODUCTION_COSTS %f\n",PLANNED_PRODUCTION_COSTS);

			//PLANNED_PRODUCTION_QUANTITY =
			//EMPLOYEES_NEEDED*PRODUCTION_PRODUCTIVITY*MEAN_SPECIFIC_SKILLS;
			
		}
	}
	else
	{
		EMPLOYEES_NEEDED = 0;
		RESEARCH_EMPLOYEES_NEEDED = 0;
	}

	
	
	printf("EMPLOYEES_NEEDED %d\n",EMPLOYEES_NEEDED);
	printf("RESEARCH_EMPLOYEES_NEEDED %d\n",RESEARCH_EMPLOYEES_NEEDED);
	printf("PLANNED_PRODUCTION_QUANTITY %f \n",PLANNED_PRODUCTION_QUANTITY);

	printf("**************************************************************************************\n");

	return 0;
}



/* \fn IGFirm_produce_capital_good()
 * \brief IGFirms produce the capital good*/
int IGFirm_produce_capital_good()
{
	printf("IN FUNCTION: IGFirm_produce_capital_good()\n");
	printf("********************************************************************************\n");

	OUTPUT = 0;
	PLANNED_OUTPUT = 0;

	PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY;

	/*Minimum of the capital good store: directly before production*/
	CAPITAL_GOOD_STORE_BEFORE_PRODUCTION = CAPITAL_GOOD_STORE;
	
	PRODUCTION_QUANTITY = NO_EMPLOYEES*PRODUCTION_PRODUCTIVITY*MEAN_SPECIFIC_SKILLS;
	OUTPUT = PRODUCTION_QUANTITY;

	/*Add the production quantity to the capital good store*/
	CAPITAL_GOOD_STORE += PRODUCTION_QUANTITY;

	/*Maximum of the capital good store: directly after production*/
	CAPITAL_GOOD_STORE_AFTER_PRODUCTION = CAPITAL_GOOD_STORE;

	remove_double(&LAST_PRODUCTION_QUANTITIES,0);
	add_double(&LAST_PRODUCTION_QUANTITIES, PRODUCTION_QUANTITY);

	printf("PRODUCTION_QUANTITY %f \n",PRODUCTION_QUANTITY);
	printf("CAPITAL_GOOD_STORE %f \n",CAPITAL_GOOD_STORE);
	printf("*********************************************************************************\n");

	

	return 0;
}




int IGFirm_calc_pay_costs()
{
	printf("IN FUNCTION: IGFirm_calc_pay_costs\n");
	printf("***************************************************************************************\n");
	
	double average_production_quantity = 0.0;
	LABOUR_COSTS = 0.0;
	int i;

	for(i=0; i<EMPLOYEES.size;i++)
	{
		LABOUR_COSTS += EMPLOYEES.array[i].wage;

		add_wage_payment_message(ID,
		EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
		TECHNOLOGY,MEAN_SPECIFIC_SKILLS,1);	
	}

	for(i=0; i<RESEARCH_EMPLOYEES.size;i++)
	{
		LABOUR_COSTS += RESEARCH_EMPLOYEES.array[i].wage;
		add_wage_payment_message(ID,
		RESEARCH_EMPLOYEES.array[i].id,RESEARCH_EMPLOYEES.array[i].wage,
		TECHNOLOGY,MEAN_SPECIFIC_SKILLS,1);
		
	}

	PAYMENT_ACCOUNT -= LABOUR_COSTS;

	PRODUCTION_COSTS = LABOUR_COSTS;

	double old_capital_good_price = 0.0;
	old_capital_good_price = CAPITAL_GOOD_PRICE;
	int m;
	for(m = 0; m < LAST_PRODUCTION_QUANTITIES.size; m++)
	{
		average_production_quantity += LAST_PRODUCTION_QUANTITIES.array[m];
	}
	average_production_quantity = 
	average_production_quantity/(double)LAST_PRODUCTION_QUANTITIES.size;


	if(PRODUCTION_QUANTITY > 0)
	{
		UNIT_COSTS = LABOUR_COSTS/average_production_quantity;
		CAPITAL_GOOD_PRICE = UNIT_COSTS*(1+IG_MARK_UP);
	}
	else
	{
		UNIT_COSTS = UNIT_COSTS;
		CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE;
	}

	if(UNIT_COSTS == 0)
	{
		CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE;
	}

	/*if(UNIT_COSTS > 0)
	{
		CAPITAL_GOOD_PRICE = UNIT_COSTS*(1+IG_MARK_UP);
	}
	else
	{
		CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE;
	}*/

	if(CAPITAL_GOOD_PRICE > old_capital_good_price*(1 + MAX_CAPITAL_GOOD_PRICE_INCREASE))
	{
		CAPITAL_GOOD_PRICE = old_capital_good_price*(1 + MAX_CAPITAL_GOOD_PRICE_INCREASE);
	}


	printf("NO_EMPLOYEES %d \n",NO_EMPLOYEES);
	printf("NO_RESEARCH_EMPLOYEES %d \n",NO_RESEARCH_EMPLOYEES);
	printf("LABOUR_COSTS %f \n",LABOUR_COSTS);
	printf("UNIT_COSTS %f \n",UNIT_COSTS);
	printf("CAPITAL_GOOD_PRICE %f \n",CAPITAL_GOOD_PRICE);
	printf("***************************************************************************************\n");

	return 0;
}




/** \fn IGFirm_send_capital_good()
 * \brief IGFirm sends capital goods to firms_payment

 */
int IGFirm_send_capital_good()
{

if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
{
	printf("IN FUNCTION: IGFirm_send_capital_good\n");
	printf("***************************************************************************************\n");
}

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{	
		/*Store the demand for and sales of the capital good of the last twenty days in order to have the monthly
	 	demand and monthly sales for getdata_region*/
		CAPITAL_GOOD_DEMAND_LAST_MONTH = CAPITAL_GOOD_DEMAND;
		CAPITAL_GOOD_DEMAND = 0.0;
		SALES_LAST_MONTH = SALES;
		SALES = 0.0;
	}

	double daily_capital_good_demand = 0.0;
	double daily_sales = 0.0;

	capital_good_request_array capital_good_request_list;
	init_capital_good_request_array(&capital_good_request_list); 
	//printf("DAILY CAPITAL_GOOD_STORE: %f\n",CAPITAL_GOOD_STORE);
	START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

		add_capital_good_request(&capital_good_request_list,
		capital_good_request_message->firm_id,
		capital_good_request_message->capital_good_demand);

		daily_capital_good_demand += capital_good_request_message->capital_good_demand;

	FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP
//	printf("DAILY CAPITAL_GOOD_DEMAND %f\n",daily_capital_good_demand);

	CAPITAL_GOOD_DEMAND += daily_capital_good_demand;
//printf("CAPITAL_GOOD_DEMAND %f\n",CAPITAL_GOOD_DEMAND);

	CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION += daily_capital_good_demand;

/*printf("CAPITAL_GOOD_DEMAND: %f\n",CAPITAL_GOOD_DEMAND);
printf("CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION: %f\n",CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION);*/

	/*for(int j = 0; j < capital_good_request_list.size; j++)
	{
		printf(" ID %i; Request %f\n",capital_good_request_list.array[j].firm_id,
		capital_good_request_list.array[j].capital_good_order);
	}*/

	/*Capital good store is bigger than capital good demand*/
	if(daily_capital_good_demand <= CAPITAL_GOOD_STORE)
	{
		int v;
		for(v = 0; v < capital_good_request_list.size; v++)
		{
			add_capital_good_delivery_message(
			capital_good_request_list.array[v].firm_id,
			capital_good_request_list.array[v].capital_good_order, 	
			PRODUCTIVITY, 
			CAPITAL_GOOD_PRICE);
//printf("capital_good_request_list.array[v].capital_good_order %f\n",capital_good_request_list.array//[v].capital_good_order);
			CAPITAL_GOOD_STORE -= capital_good_request_list.
			array[v].capital_good_order;

			SALES += capital_good_request_list.
			array[v].capital_good_order;

			daily_sales += capital_good_request_list.
			array[v].capital_good_order;
		}
		
		

	}
	else
	{	/*Capital good demand is higher than capital good store and the store is positive*/
		if(CAPITAL_GOOD_STORE > 0)
		{
			double fraction_order;
			fraction_order = CAPITAL_GOOD_STORE/daily_capital_good_demand;
//printf("DAILY fraction_order %f\n",fraction_order);
			int v;
			for(v = 0; v < capital_good_request_list.size; v++)
			{
				add_capital_good_delivery_message(
				capital_good_request_list.array[v].firm_id,
				capital_good_request_list.array[v].capital_good_order*fraction_order, 
				PRODUCTIVITY, 	
				CAPITAL_GOOD_PRICE);

				CAPITAL_GOOD_STORE -= capital_good_request_list.
				array[v].capital_good_order *fraction_order;

				SALES += capital_good_request_list.
				array[v].capital_good_order*fraction_order;
			
				daily_sales += capital_good_request_list.
				array[v].capital_good_order*fraction_order;
		
			}

			
		}
		else
		{
			int v;
			for(v = 0; v < capital_good_request_list.size; v++)
			{
				add_capital_good_delivery_message(
				capital_good_request_list.array[v].firm_id,
				0, 
				PRODUCTIVITY, 	
				CAPITAL_GOOD_PRICE);

				SALES += 0.0;
			}
		}
	}

	

	/*Remove the oldest capital good demand and add the capital good demand of the last 	
	period*/
	/*if(DAY%20 == DAY_OF_MONTH_TO_ACT)
	{
		remove_double(&LAST_CAPITAL_GOOD_SALES,0);
		add_double(&LAST_CAPITAL_GOOD_SALES, SALES);
		
	}*/
	/*if(CAPITAL_GOOD_DEMAND > CAPITAL_GOOD_STORE && CAPITAL_GOOD_STORE = 0)
	{
		for(int v = 0; v < capital_good_request_list.size; v++)
		{
			add_capital_good_delivery_message(
			capital_good_request_list.array[v].firm_id,
			0, 
			PRODUCTIVITY, 	
			CAPITAL_GOOD_PRICE);
		}
	}*/

	free_capital_good_request_array(&capital_good_request_list);
//printf("DAILY CAPITAL_GOOD_STORE %f\n",CAPITAL_GOOD_STORE);
//printf("DAILY SALES %f\n",daily_sales);
//printf("SALES %f\n",SALES);
if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
{
	//printf("CAPITAL_GOOD_STORE %f\n",CAPITAL_GOOD_STORE);
	//printf("CAPITAL_GOOD_DEMAND %f\n",CAPITAL_GOOD_DEMAND);
	//printf("SALES %f\n",SALES);
	//printf("CALC REVENUE %f\n",(SALES*CAPITAL_GOOD_PRICE));
	printf("******************************************************************************************\n");

}
	return 0;
}




/** \fn IGFirm_receive_payment()
 * \brief IGFirm calculates revenues and distributes the revenue to the households
 */

int IGFirm_calc_revenue()
{
if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
{
	printf("IN FUNCTION: IGFirm_calc_revenue\n");
	printf("**************************************************************************\n");
	CUM_REVENUES = 0.0;
}
	REVENUE_PER_DAY = 0;
	

	START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

		REVENUE_PER_DAY += pay_capital_goods_message->capital_bill;

	FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP  

	CUM_REVENUES += REVENUE_PER_DAY; 
	PAYMENT_ACCOUNT += REVENUE_PER_DAY;
	REVENUE_FOR_INNOVATION += REVENUE_PER_DAY;

if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
{
	printf("CUM_REVENUES %f\n",CUM_REVENUES);
	printf("PAYMENT_ACCOUNT %f\n",PAYMENT_ACCOUNT);
	printf("*****************************************\n");
}
	return 0;
}

/** \fn IGFirm_dividend_payment()
 * \brief IGFirm distributes dividends to the households, and sends total_dividend payment to the bank
 */










