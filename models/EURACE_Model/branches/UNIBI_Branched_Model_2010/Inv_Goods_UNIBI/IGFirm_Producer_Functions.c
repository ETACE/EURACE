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
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif

	 if(DAY >= TRANSITION_PHASE)
	 {}

	int i,j;
	int influence_the_variance = 75; 
	/*increase this variable to get a lower variance of the normal distribution/the random
	progress*/

	double k,random_progress,innovation_probability;
	
	
	/*Create normal distributed random number: mean~0, standard deviation ~ 0.01*/
	for(j = 0; j < 12; j++)
	{
		k = (double)(random_int(0, 1000))/1000;
		random_progress += ((k - 0.5)/influence_the_variance);	
	}


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


	i = random_int( 0 ,100);
	/*If project is completed calculate the productivity progress*/
	if((innovation_probability * 100) >= i)
	{
		//if progress is larger than zero/positiv
		if((random_progress + PRODUCTIVITY_PROGRESS) > 0)
		{
			INNOVATION_SUCCESS = 1;
			ADDITIONAL_PRODUCTIVITY =  (PRODUCTIVITY_PROGRESS + random_progress);
			NEW_PRODUCTIVITY = PRODUCTIVITY*(1 + ADDITIONAL_PRODUCTIVITY);
		}
	}

	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_update_productivity()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," Innovation_probability: %f\n",innovation_probability);
        fprintf(file1," PRODUCTIVITY %f\n",PRODUCTIVITY);
		fprintf(file1," NEW_PRODUCTIVITY %f\n",NEW_PRODUCTIVITY);
		fprintf(file1," ADDITIONAL_PRODUCTIVITY %f\n",ADDITIONAL_PRODUCTIVITY);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    }
	

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
			two++;//printf(" 2 \n");
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

	return 0;
}


/** \fn int IGFirm_calc_research_employees()
 * \brief IGFirm determines the number of research_employees */
int IGFirm_calc_research_employees()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif
	
	if(INNOVATION_SUCCESS == 1)
	{	
		/*"start" of new innovation period*/
		DURATION_UNTIL_NEXT_INNOVATION = 0;
		CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION = 0;	
	}

	/*1. option: The number Research employees is determined when there is a successful 	
	Innovation*/
	
	/*if(INNOVATION_SUCCESS == 1 )
	{
		RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
		(REVENUE_FOR_INNOVATION/DURATION_UNTIL_NEXT_INNOVATION)
		/WAGE_OFFER_FOR_SKILL_6);

		REVENUE_FOR_INNOVATION = 0;

	}*/

	/*To be sure to have at least some R&D*/
	/*if(NO_RESEARCH_EMPLOYEES == 0 && INNOVATION_SUCCESS == 0)
	{
		RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
		(REVENUE_FOR_INNOVATION/DURATION_UNTIL_NEXT_INNOVATION)
		/WAGE_OFFER_FOR_RD);

		if(RESEARCH_EMPLOYEES_NEEDED > 10)
		{
			RESEARCH_EMPLOYEES_NEEDED = 10;
		}
		
	}*/

	/*2. option: The number Research employees is determined every year*/

	RESEARCH_EMPLOYEES_NEEDED = (int) (PERCENT_REVENUE_FOR_INNOVATION*
	(REVENUE_FOR_INNOVATION/12))/WAGE_OFFER_FOR_RD;

	REVENUE_FOR_INNOVATION = 0;

	/*1: complete functionality of the IGFirm -- 0: Exogenous stochastic innovation process  */
	if(IGFIRM_SWITCH_ON == 0)
	{
		RESEARCH_EMPLOYEES_NEEDED = 0;
	}

	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_research_employees()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," REVENUE_FOR_INNOVATION = %f\n",REVENUE_FOR_INNOVATION/12);
		fprintf(file1," WAGE_OFFER_FOR_RD = %f\n",WAGE_OFFER_FOR_RD);
		fprintf(file1," RESEARCH_EMPLOYEES_NEEDED = %d \n",RESEARCH_EMPLOYEES_NEEDED);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    }

	return 0;
}


int IGFirm_set_quantities_zero()
{

	return 0;
}




/** \fn IGFirm_update_productivity_price()
 * \brief IGFirm send quality and price information */
int IGFirm_send_quality_price_info()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif
	
	
	/*1: complete functionality of the IGFirm -- 0: Exogenous stochastic innovation process  */
	if(IGFIRM_SWITCH_ON == 0)
	{

		RESEARCH_EMPLOYEES_NEEDED = 0;

		if(DAY >= TRANSITION_PHASE)
	 	{

			if(DAY%MONTH == DAY_OF_MONTH_TO_ACT)
			{
				int i;	
				i = random_int( 0 ,100);
		
				if(i < IGFIRM_EXOGENOUS_INNOVATION_PROBABILITY)
				{
					PRODUCTIVITY = PRODUCTIVITY*(1 + IGFIRM_EXOGENOUS_PRODUCTIVITY_PROGRESS);
					CAPITAL_GOOD_PRICE = 
					CAPITAL_GOOD_PRICE*(1 +IGFIRM_EXOGENOUS_PRODUCTIVITY_PROGRESS);	
				}
	 		}
		}
	}

	add_productivity_message(ID,PRODUCTIVITY,CAPITAL_GOOD_PRICE);

if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
		{
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_send_quality_price_info()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," PRODUCTIVITY = %f \n",PRODUCTIVITY);
		fprintf(file1," CAPITAL_GOOD_PRICE = %f \n",CAPITAL_GOOD_PRICE);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    }
    }
	return 0;
}


/** \fn IGFirm_calc_production_quantity()
 * \brief IGFirm calculate the intended production volume depending on the current stocks in the malls*/
int IGFirm_calc_production_quantity()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif


	double sales[FIRM_PLANNING_HORIZON];
	double mean_of_last_sales;
	double mean_last_demand = 0.0;
	int i;
	double temp_planned_production_quantity =0.0;

	/*Remove the oldest capital good demand and add the capital good demand of the last 	
	period*/
	remove_double(&LAST_CAPITAL_GOOD_DEMAND,0);
	add_double(&LAST_CAPITAL_GOOD_DEMAND, CAPITAL_GOOD_DEMAND);
	
	/*Count the number of zero demands: faster adaption of the 
	production when there is no demand for capital goods*/
	if(CAPITAL_GOOD_DEMAND > 0)
	{
		NO_ZERO_DEMAND = 0;
	}
	else
	{
		NO_ZERO_DEMAND++;
	}


	/*Remove the oldest capital good sales and add the capital good salesof the last 	
	period*/
	remove_double(&LAST_CAPITAL_GOOD_SALES,0);
	add_double(&LAST_CAPITAL_GOOD_SALES, SALES);


	

	
	/*Calculate the average of the last sales*/
	for(i = 0; i < FIRM_PLANNING_HORIZON; i++)
	{
		sales[i] = LAST_CAPITAL_GOOD_SALES.array[i];
		mean_of_last_sales += LAST_CAPITAL_GOOD_SALES.array[i];
	}

	mean_of_last_sales = mean_of_last_sales/FIRM_PLANNING_HORIZON;	

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

	/*Setting the critical values: determined to 8*/
	CRITICAL_STOCK = sales[8];
			
		
	if(CRITICAL_STOCK == 0)
	{
		int random_num = random_int(0,100);
		if(random_num < DELIVERY_PROB_IF_CRITICAL_STOCK_0)
		{
			CRITICAL_STOCK = mean_of_last_sales;		
		}

	}

	/*If capital good store is too small, plan the production the IGFirm has to produce*/
	if(CAPITAL_GOOD_STORE <= CRITICAL_STOCK)
	{

		/*If capital goods are left produce the difference between the critical stock and the actual store*/
		if(CAPITAL_GOOD_STORE > 0)
		{
			PLANNED_PRODUCTION_QUANTITY = CRITICAL_STOCK - CAPITAL_GOOD_STORE;
		}
		/*If no stocks are left produce the critical stock plus an additional 
		fraction because the IGFirm could have sold more goods in the last period*/
		else
		{
			PLANNED_PRODUCTION_QUANTITY = CRITICAL_STOCK*
			(1 + ADDITIONAL_CAPITAL_GOOD_PRODUCTION);
		}


		/*Calculate the average of the last capital goods demand*/
		for(i = 0; i < LAST_CAPITAL_GOOD_DEMAND.size; i++)
		{
			mean_last_demand += LAST_CAPITAL_GOOD_DEMAND.array[i];	
		}

		mean_last_demand = mean_last_demand/(double)LAST_CAPITAL_GOOD_DEMAND.size;
		
		/*Smooth the production quantity by taking also the average of the last demands into account*/
		temp_planned_production_quantity = PLANNED_PRODUCTION_QUANTITY;
		PLANNED_PRODUCTION_QUANTITY = IG_LAMBDA*PLANNED_PRODUCTION_QUANTITY +
		(1-IG_LAMBDA)*mean_last_demand;

		if(NO_ZERO_DEMAND > 0)
		{
			PLANNED_PRODUCTION_QUANTITY = 0.0;	
		}

		
	}
	/*If capital good store is greater than the critical stock*/
	else
	{
		PLANNED_PRODUCTION_QUANTITY = 0.0;
	}


	

	
	/*1: complete functionality of the IGFirm  0: ISOLATED MODEL UNIBI MAY 09 */
	if(IGFIRM_SWITCH_ON == 0)
	{
		PLANNED_PRODUCTION_QUANTITY = 0.0;
	}
	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_production_quantity()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," CAPITAL_GOOD_DEMAND = %f \n",CAPITAL_GOOD_DEMAND);
		fprintf(file1," SALES = %f  \n",SALES);
		fprintf(file1,"\n");
		fprintf(file1," CAPITAL_GOOD_STORE = %f \n",CAPITAL_GOOD_STORE);
		fprintf(file1," CRITICAL_STOCK = %f \n",CRITICAL_STOCK);
		fprintf(file1," temp_planned_production_quantity = %f \n",temp_planned_production_quantity);
		fprintf(file1," mean_last_demand = %f \n",mean_last_demand);
		fprintf(file1," IG_LAMBDA = %f \n",IG_LAMBDA);
		fprintf(file1," PLANNED_PRODUCTION_QUANTITY = %f  \n",PLANNED_PRODUCTION_QUANTITY);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 

	return 0;
}


/* \fn IGFirm_calc_input_demands()
 * \brief IGFirms calculate the labor demand and the demand for energy*/
int IGFirm_calc_input_demands()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif

	/*Calculated the number of production employees*/
	EMPLOYEES_NEEDED = (int)(PLANNED_PRODUCTION_QUANTITY
	/PRODUCTION_PRODUCTIVITY);

	
	/*Planned production costs for the next period: for the calculation of
	 PRODUCTION_LIQUIDITY_NEEDS in IGFirm_compute_total_liquidity_needs() (Fin-Man)*/
	PLANNED_PRODUCTION_COSTS = EMPLOYEES_NEEDED*MEAN_WAGE +
 	RESEARCH_EMPLOYEES_NEEDED*MEAN_RESEARCH_WAGE;

	
	/*1: complete functionality of the IGFirm  0: ISOLATED MODEL UNIBI MAY 09 */
	if(IGFIRM_SWITCH_ON == 0)
	{
		PLANNED_PRODUCTION_COSTS = 0;
		EMPLOYEES_NEEDED = 0;
	}

	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_input_demands()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," PRODUCTION_PRODUCTIVITY = %f \n",PRODUCTION_PRODUCTIVITY);	
		fprintf(file1," PLANNED_PRODUCTION_QUANTITY = %f \n",PLANNED_PRODUCTION_QUANTITY);
		fprintf(file1," EMPLOYEES_NEEDED %d \n",EMPLOYEES_NEEDED);
		fprintf(file1,"\n");
		fprintf(file1," EMPLOYEES_NEEDED %d \n",EMPLOYEES_NEEDED);
		fprintf(file1," MEAN_WAGE = %f \n",MEAN_WAGE);
		fprintf(file1," RESEARCH_EMPLOYEES_NEEDED = %d \n",RESEARCH_EMPLOYEES_NEEDED);
		fprintf(file1," MEAN_RESEARCH_WAGE = %f \n",MEAN_RESEARCH_WAGE);
		fprintf(file1," PLANNED_PRODUCTION_COSTS = %f \n",PLANNED_PRODUCTION_COSTS);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 
	

    return 0;	
}



int IGFirm_calc_production_quantity_2()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif

	double temp_planned_production_costs = 0.0;

	temp_planned_production_costs = PLANNED_PRODUCTION_COSTS;

	FINANCIAL_RESOURCES_FOR_PRODUCTION = PAYMENT_ACCOUNT - FINANCIAL_LIQUIDITY_NEEDS;

	if(FINANCIAL_RESOURCES_FOR_PRODUCTION < PLANNED_PRODUCTION_COSTS)
	{


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
	
			}
		}
		else
		{	
			EMPLOYEES_NEEDED = 0;
			RESEARCH_EMPLOYEES_NEEDED = 0;


		}
	}


	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_production_quantity_2()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," RESOURCES_FOR_PRODUCTION = %f \n",FINANCIAL_RESOURCES_FOR_PRODUCTION);	
		fprintf(file1," temp_planned_production_costs = %f\n",temp_planned_production_costs);
		fprintf(file1,"\n");
		fprintf(file1," EMPLOYEES_NEEDED %d \n",EMPLOYEES_NEEDED);
		fprintf(file1," MEAN_WAGE = %f \n",MEAN_WAGE);
		fprintf(file1," RESEARCH_EMPLOYEES_NEEDED = %d \n",RESEARCH_EMPLOYEES_NEEDED);
		fprintf(file1," MEAN_RESEARCH_WAGE = %f \n",MEAN_RESEARCH_WAGE);
		fprintf(file1," PLANNED_PRODUCTION_COSTS = %f \n",PLANNED_PRODUCTION_COSTS);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 

	return 0;
}



/* \fn IGFirm_produce_capital_good()
 * \brief IGFirms produce the capital good*/
int IGFirm_produce_capital_good()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif

	
	
	if(IGFIRM_SWITCH_ON == 1)
	{
		/*Variables for getdata*/
		OUTPUT = 0;
		PLANNED_OUTPUT = 0;
	
		PLANNED_OUTPUT = PLANNED_PRODUCTION_QUANTITY;
	
		/*Minimum of the capital good store: directly before production*/
		CAPITAL_GOOD_STORE_BEFORE_PRODUCTION = CAPITAL_GOOD_STORE;
		
		PRODUCTION_QUANTITY = NO_EMPLOYEES*PRODUCTION_PRODUCTIVITY;
		OUTPUT = PRODUCTION_QUANTITY;
	
		/*Add the production quantity to the capital good store*/
		CAPITAL_GOOD_STORE += PRODUCTION_QUANTITY;
	
		/*Maximum of the capital good store: directly after production*/
		CAPITAL_GOOD_STORE_AFTER_PRODUCTION = CAPITAL_GOOD_STORE;
	
		remove_double(&LAST_PRODUCTION_QUANTITIES,0);
		add_double(&LAST_PRODUCTION_QUANTITIES, PRODUCTION_QUANTITY);
	}

	
	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_produce_capital_good()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," CAP_STORE_BEFORE_PRODUCTION = %f \n",CAPITAL_GOOD_STORE_BEFORE_PRODUCTION);
        fprintf(file1,"\n");
        fprintf(file1," PLANNED_PRODUCTION_QUANTITY = %f\n",PLANNED_PRODUCTION_QUANTITY);
        fprintf(file1," NO_EMPLOYEES = %d \n",NO_EMPLOYEES);
        fprintf(file1," PRODUCTION_PRODUCTIVITY  = %f \n",PRODUCTION_PRODUCTIVITY);	
		fprintf(file1," PRODUCTION_QUANTITY = %f\n",PRODUCTION_QUANTITY);
		fprintf(file1,"\n");
		fprintf(file1," CAP_STORE_AFTER_PRODUCTION = %f \n",CAPITAL_GOOD_STORE_AFTER_PRODUCTION);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 

	return 0;
}




int IGFirm_calc_pay_costs()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif


	double average_production_quantity = 0.0;
	//double old_capital_good_price = 0.0;
	int i,m;
	double temp_payment_account= 0.0;
	
	LABOUR_COSTS = 0.0;
	CALC_PRODUCTION_COSTS=0.0;

	/*Sum up the wages for production workers*/
	for(i=0; i<EMPLOYEES.size;i++)
	{
		LABOUR_COSTS += EMPLOYEES.array[i].wage;

		add_wage_payment_message(ID,
		EMPLOYEES.array[i].id,EMPLOYEES.array[i].wage,
		TECHNOLOGY,MEAN_SPECIFIC_SKILLS,1);	
	}
	
	/*Sum up the wages for researchers*/
	for(i=0; i<RESEARCH_EMPLOYEES.size;i++)
	{
		LABOUR_COSTS += RESEARCH_EMPLOYEES.array[i].wage;

		add_wage_payment_message(ID,
		RESEARCH_EMPLOYEES.array[i].id,RESEARCH_EMPLOYEES.array[i].wage,
		TECHNOLOGY,MEAN_SPECIFIC_SKILLS,1);	
	}

	temp_payment_account =PAYMENT_ACCOUNT;
	PAYMENT_ACCOUNT -= LABOUR_COSTS;

	/*Store the production costs for getdata*/
	PRODUCTION_COSTS_LAST_MONTH = PRODUCTION_COSTS;

	/*Production costs are only labor costs*/
	PRODUCTION_COSTS = LABOUR_COSTS;
	CALC_PRODUCTION_COSTS= LABOUR_COSTS;

	
	//old_capital_good_price = CAPITAL_GOOD_PRICE;
	
	/*Calculate the average of the last production quantities*/
	for(m = 0; m < LAST_PRODUCTION_QUANTITIES.size; m++)
	{
		average_production_quantity += LAST_PRODUCTION_QUANTITIES.array[m];
	}

	average_production_quantity = 
	average_production_quantity/(double)LAST_PRODUCTION_QUANTITIES.size;

	
	/*1: complete functionality of the IGFirm  0: ISOLATED MODEL UNIBI MAY 09 */
	if(IGFIRM_SWITCH_ON == 1)
	{
		/*If the IGFirm has produced capital goods*/	
		if(PRODUCTION_QUANTITY > 0)
		{
			/*The average of the last production quantities is used to smooth the capital good price*/
			UNIT_COSTS = LABOUR_COSTS/average_production_quantity;
			NEW_CAPITAL_GOOD_PRICE = UNIT_COSTS*(1+IG_MARK_UP);
		}
		/*If there was no production*/
		else
		{	/*Take the unit costs of the last period and also the price*/
			UNIT_COSTS = UNIT_COSTS;
			NEW_CAPITAL_GOOD_PRICE = CAPITAL_GOOD_PRICE;
		}
	}
	
	
	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_pay_costs()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," LABOUR_COSTS = %f  \n",LABOUR_COSTS);
		fprintf(file1," AVERAGE PRODUCTION QUANTITY = %f  \n",average_production_quantity);
		fprintf(file1," UNIT_COSTS = %f \n",UNIT_COSTS);
		fprintf(file1," NEW_CAPITAL_GOOD_PRICE = %f \n",NEW_CAPITAL_GOOD_PRICE);
		fprintf(file1," CAPITAL_GOOD_PRICE = %f \n",CAPITAL_GOOD_PRICE);
		fprintf(file1,"\n");
		fprintf(file1," temp_payment_account = %f \n",temp_payment_account);
		fprintf(file1," PAYMENT_ACCOUNT = %f \n",PAYMENT_ACCOUNT);
        fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 

	return 0;
}




/** \fn IGFirm_send_capital_good()
 * \brief IGFirm sends capital goods to firms_payment

 */
int IGFirm_send_capital_good()
{
	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif


	double daily_capital_good_demand = 0.0;
	double daily_sales = 0.0;	

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{	
		/*Store the demand for and sales of the capital good of the last twenty days in order to have the monthly
	 	demand and monthly sales for getdata_region*/
		CAPITAL_GOOD_DEMAND_LAST_MONTH = CAPITAL_GOOD_DEMAND;
		CAPITAL_GOOD_DEMAND = 0.0;
		SALES_LAST_MONTH = SALES;
		SALES = 0.0;
	}

	

	capital_good_request_array capital_good_request_list;
	init_capital_good_request_array(&capital_good_request_list); 

	

	START_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP

		add_capital_good_request(&capital_good_request_list,
		capital_good_request_message->firm_id,
		capital_good_request_message->capital_good_demand);

		daily_capital_good_demand += capital_good_request_message->capital_good_demand;

	FINISH_CAPITAL_GOOD_REQUEST_MESSAGE_LOOP


	CAPITAL_GOOD_DEMAND += daily_capital_good_demand;

	CAPITAL_GOOD_DEMAND_AFTER_LAST_INNOVATION += daily_capital_good_demand;


	/*1: complete functionality of the IGFirm  0: ISOLATED MODEL UNIBI MAY 09 */
	if(IGFIRM_SWITCH_ON == 1)
	{
	
		/*Capital good store is bigger than capital good demand: demand can be satisfied*/
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
	
				CAPITAL_GOOD_STORE -= capital_good_request_list.
				array[v].capital_good_order;
	
				SALES += capital_good_request_list.
				array[v].capital_good_order;
	
				daily_sales += capital_good_request_list.
				array[v].capital_good_order;
			}
		}
		else
		{	/*Capital good demand is higher than capital good store and 
			the store is positive: every firm gets a fration of their order*/
			if(CAPITAL_GOOD_STORE > 0)
			{
				double fraction_order;
				fraction_order = CAPITAL_GOOD_STORE/daily_capital_good_demand;

				
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
			/*Capital goods store is empty: no delivery*/
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

	}
	/*If IGFIRM_SWITCH_ON is zero: demand of the firms is satisfied*/
	else
	{
		int v;
		for(v = 0; v < capital_good_request_list.size; v++)
		{
			add_capital_good_delivery_message(
			capital_good_request_list.array[v].firm_id,
			capital_good_request_list.array[v].capital_good_order, 	
			PRODUCTIVITY, 
			CAPITAL_GOOD_PRICE);
		
			CAPITAL_GOOD_STORE -= capital_good_request_list.
			array[v].capital_good_order;
	
			SALES += capital_good_request_list.
			array[v].capital_good_order;
	
			daily_sales += capital_good_request_list.
			array[v].capital_good_order;
		}
	}

	free_capital_good_request_array(&capital_good_request_list);

	
	
	if(IGFIRM_SWITCH_ON == 1)
	{	
		if(DAY%240 == DAY_OF_MONTH_TO_ACT)
		{
			/*The new productivity is set here to make sure that the new productivity together with the new price is 				sent 	on the first day after the production. Hence it is avoided that the IGFIRM sent the new productivity 				with the old price. */
			PRODUCTIVITY = NEW_PRODUCTIVITY;

		}



		if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
		{
			/*Firms which buy goods on the day_of_month_to_act of the IGFIRM should pay the price which 
			was announced in IGFirm_send_quality_price_info_message. Hence the new price after the 
			last production is set here for the next 20 days.*/
			CAPITAL_GOOD_PRICE = NEW_CAPITAL_GOOD_PRICE;

		}

	}
	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_send_capital_good()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," CAPITAL_GOOD_DEMAND = %f\n",CAPITAL_GOOD_DEMAND);
        fprintf(file1," daily_capital_good_demand = %f\n",daily_capital_good_demand);
        fprintf(file1," daily_sales = %f\n",daily_sales);
		fprintf(file1," SALES = %f\n",SALES);
		fprintf(file1," CAPITAL_GOOD_STORE = %f \n",CAPITAL_GOOD_STORE);
		fprintf(file1,"\n");
		fprintf(file1," CAPITAL_GOOD_PRICE = %f \n",CAPITAL_GOOD_PRICE);
		fprintf(file1," PRODUCTIVITY = %f \n",PRODUCTIVITY);
		fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 

	return 0;
}




/** \fn IGFirm_calc_revenue()
 * \brief IGFirm calculates revenues and distributes the revenue to the households
 */

int IGFirm_calc_revenue()
{

	//  #ifdef _DEBUG_MODE        
        FILE *file1;
        char *filename;
   // #endif

	if(DAY%MONTH==DAY_OF_MONTH_TO_ACT)
	{
		
		/*Store the revenue for getdata*/
		CUM_REVENUE_LAST_MONTH = CUM_REVENUE;
		CUM_REVENUE = 0.0;
	}

	REVENUE_PER_DAY = 0;
	

	START_PAY_CAPITAL_GOODS_MESSAGE_LOOP

		REVENUE_PER_DAY += pay_capital_goods_message->capital_bill;

	FINISH_PAY_CAPITAL_GOODS_MESSAGE_LOOP  

	CUM_REVENUE += REVENUE_PER_DAY; 
	PAYMENT_ACCOUNT += REVENUE_PER_DAY;
	/*Sum up revenues for the R&D budget: not necessary if research employees are 
	calculated every year -> then: CUM_REVENUES = REVENUE FOR INNOVATION*/
	REVENUE_FOR_INNOVATION += REVENUE_PER_DAY;

	
	if (IGFIRM_PRODUCER_DEBUG)
    {
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/IGFirm_producer.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"IGFirm_calc_revenue()\n");
        fprintf(file1,"---------------------------------------------------------------------------------\n");
        fprintf(file1," DAY %d \t ID %d \n",DAY,ID);
        fprintf(file1," CUM_REVENUE = %f\n",CUM_REVENUE);
        fprintf(file1," PAYMENT_ACCOUNT = %f\n",PAYMENT_ACCOUNT);
		fprintf(file1,"\n");
        fprintf(file1,"\n");
        fclose(file1);
        free(filename);
    } 
	
	return 0;
}












