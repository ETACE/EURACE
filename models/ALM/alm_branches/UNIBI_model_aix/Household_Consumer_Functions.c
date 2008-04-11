#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"


/********************************* Household agent functions *************************************/

int is_employed()
{
	if(EMPLOYEE_FIRM_ID > -1) return 1;
	else return 0;
}

int is_unemployed()
{
	if(EMPLOYEE_FIRM_ID == -1) return 1;
	else return 0;
}

int on_the_job_search_no()
{
	if(ON_THE_JOB_SEARCH == 0) return 1;
	else return 0;
}

int on_the_job_search_yes()
{
	if(ON_THE_JOB_SEARCH == 1) return 1;
	else return 0;
}

int is_employed_and_on_the_job_search_no()
{
	if(EMPLOYEE_FIRM_ID > -1 && ON_THE_JOB_SEARCH == 0) return 1;
	else return 0;
}

int is_unemployed_or_on_the_job_search_yes()
{
	if(EMPLOYEE_FIRM_ID == -1 || ON_THE_JOB_SEARCH == 1) return 1;
	else return 0;
}




int Household_finish_labour_market()
{
	return 0;
}

int Household_on_the_job_search_yes()
{
	return 0;
}

int Household_idle()
{
	return 0;
}

int Household_on_the_job_search_no()
{
	return 0;
}

int Household_made_unemployed()
{
	return 0;
}


/**********************************Household Role: Consumption Goods Market*********************/


/** \fn Household_receive_wage()
 * \brief Household receives wage, additionally the specific skills are updated, if the household is employed 
 */

int Household_receive_wage()
{
	double mean_income = 0;
	
	/*Household reads the wage messages if employed*/
	START_WAGE_PAYMENT_MESSAGE_LOOP

		if(wage_payment_message->worker_id==ID)
		{
			WAGE = wage_payment_message->payment;
			remove_double(&LAST_INCOME,0);
			add_double(&LAST_INCOME,wage_payment_message->payment);
			
			/*Compute a mean income of the last four month*/
			for(int i = 0; i < 4;i++)
			{
				mean_income += LAST_INCOME.array[i];
			}

			mean_income = mean_income/4;
			
			/*Add wage on account   */
			SAVINGS += wage_payment_message->payment;
			


			/*Determing the consumption budget of the month*/
			if(SAVINGS > (INITIAL_CONSUMPTION_PROPENSITY*mean_income))
			{
				
				BUDGET=CONSUMPTION_PROPENSITY*SAVINGS+(1-CONSUMPTION_PROPENSITY)
				*INITIAL_CONSUMPTION_PROPENSITY*mean_income;
			}
			else
			{
				BUDGET = SAVINGS;
			}

			WEEKLY_BUDGET = BUDGET/4;
			WEEK_OF_MONTH = 4;
			
			/*Update of specific skills   */ 
			
		
			if(SPECIFIC_SKILL < wage_payment_message->productivity)
			{
				
				SPECIFIC_SKILL = SPECIFIC_SKILL + (wage_payment_message-> 					productivity- SPECIFIC_SKILL)*
				((1-pow(0.5,1/(20+0.25*(GENERAL_SKILL-1)*(4-20))))+ 
				0*wage_payment_message->average_specific_skills);


				add_specific_skill_update_message(ID,
				EMPLOYEE_FIRM_ID,SPECIFIC_SKILL,MSGDATA);	
			}
		}	
	
	FINISH_WAGE_PAYMENT_MESSAGE_LOOP

	/*If the worker is unemployed then he consumes his savings */
	if(DAY%WEEK==DAY_OF_WEEK_TO_ACT && EMPLOYEE_FIRM_ID == -1 && WEEK_OF_MONTH == 0)
	{
		remove_double(&LAST_INCOME,0);
		add_double(&LAST_INCOME,0);
			
		for(int i = 0; i < 4; i++)
		{
			mean_income+= LAST_INCOME.array[i];

		}

		mean_income = mean_income/4;	
		BUDGET = CONSUMPTION_PROPENSITY*SAVINGS;
		WEEKLY_BUDGET = BUDGET/4;
		WEEK_OF_MONTH =4;		
	}

	return 0;

}


/** \fn Household_rank_and_buy_goods_1()
 * \brief Household receives information about the offered range of goods in the malls.
	Depending on these infos the household sends its good request		
 */

int Household_rank_and_buy_goods_1()
{

	//Logit model parameter:
	double sum_weighted_qual_pric_ratios = 0; 
	int j=0;
	int i=0;
	double logit;

	logit_firm_id_array  logit_firm_id_list;
	init_logit_firm_id_array(&logit_firm_id_list);

	mall_quality_price_info_array mall_quality_price_info_list;
 	init_mall_quality_price_info_array(&mall_quality_price_info_list);

	if(DAY%WEEK==DAY_OF_WEEK_TO_ACT)
	{

		/*Household reads quality price info mesasges sent by malls   */
		START_QUALITY_PRICE_INFO_1_MESSAGE_LOOP

			if(quality_price_info_1_message->mall_region_id == REGION_ID)  
			{	
		
				
				add_mall_quality_price_info(&mall_quality_price_info_list,  					quality_price_info_1_message->mall_id,  				quality_price_info_1_message->firm_id,  				quality_price_info_1_message->mall_region_id,  					quality_price_info_1_message->quality,  				quality_price_info_1_message->price, 
				quality_price_info_1_message->available);
				
			}

		FINISH_QUALITY_PRICE_INFO_1_MESSAGE_LOOP

		
		//+++++ Logit Model +++++++++:

		
		/*Sum of weighted exponents of quality price ratios*/
		for(i = 0; i < mall_quality_price_info_list.size;i++) 
		{
			sum_weighted_qual_pric_ratios += (mall_quality_price_info_list.array[i]
			.available) * exp(log(mall_quality_price_info_list.array[i].price)*GAMMA); 
		}



		/* Compute logits and add on temporary logit array   */
		for(i = 0; i < mall_quality_price_info_list.size;i++) 
		{
			logit = (mall_quality_price_info_list.array[i].available) * 
			exp(log(mall_quality_price_info_list.array[i].price)*GAMMA) / 
			sum_weighted_qual_pric_ratios;
			
			logit = logit * 100;

			if(logit > 0)
			{
				add_logit_firm_id(&logit_firm_id_list, logit, 
				mall_quality_price_info_list.array[i].firm_id);
			}

		}


		if(sum_weighted_qual_pric_ratios > 0)
		{
			MALL_COMPLETELY_SOLD_OUT = 0;
			int random_number = random_int(0,100);
			j=0;
			int x =0, index_selected_good=j;

			for(j = 0; j < logit_firm_id_list.size;j++)
			{
			
				/*if randum number <= logit then select the corresponding good  */ 
				if((random_number < logit_firm_id_list.array[j].logit) && (x != 1))
				{
					ORDER_QUANTITY[0].firm_id = logit_firm_id_list.
					array[j].firm_id;
				
					x = 1;
					index_selected_good= j;
				}
				/*else sum logits and go to the next iteration step  */
				else
				{
					if((j < logit_firm_id_list.size-1) )
					{	
						logit_firm_id_list.array[j+1].logit =
						logit_firm_id_list.array[j+1].logit+
						logit_firm_id_list.array[j].logit;
					}
				}
			}

			/*This computes and stores the order quantity of the selected good and 				saves the price in memory */
			ORDER_QUANTITY[0].quantity = WEEKLY_BUDGET/ mall_quality_price_info_list
			.array[index_selected_good].price;
		
			ORDER_QUANTITY[0].price = mall_quality_price_info_list.
			array[index_selected_good].price;

			/*The consumption request message is sent  */ 
			add_consumption_request_1_message(
			mall_quality_price_info_list.array[index_selected_good].mall_id,ID,
			ORDER_QUANTITY[0].firm_id,
			ORDER_QUANTITY[0].quantity,MSGDATA);

		}
		else
		{
			EXPENDITURES=0;
			MALL_COMPLETELY_SOLD_OUT =1;
			ORDER_QUANTITY[0].quantity=0;
			ORDER_QUANTITY[0].price=0;
			ORDER_QUANTITY[0].firm_id=0;
		}
	}	

	free_mall_quality_price_info_array(&mall_quality_price_info_list);
	free_logit_firm_id_array(&logit_firm_id_list);

	return 0;

}

/** \fn Household_rank_and_buy_goods_2()
 * \brief If the household was rationed in the first consumption step, this process is repeated once again 
			
 */
int Household_rank_and_buy_goods_2()
{
	//Logit parameters
	
	int j = 0;
	int i = 0;
	double logit;
	double sum_weighted_qual_pric_ratios = 0; 

	//Temporary arrays
	logit_firm_id_array logit_firm_id_list;
	init_logit_firm_id_array(&logit_firm_id_list);

	mall_quality_price_info_array mall_quality_price_info_list;
	init_mall_quality_price_info_array(&mall_quality_price_info_list);

	if(DAY%WEEK == DAY_OF_WEEK_TO_ACT && MALL_COMPLETELY_SOLD_OUT == 0)
	{
		EXPENDITURES = 0;

		/*Household reads messages containing the realized consumption of the first round*/
		START_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP

			if(accepted_consumption_1_message->worker_id == ID)
			{
				RATIONED = accepted_consumption_1_message->rationed;

				/*Update of Budget  */
				WEEKLY_BUDGET = WEEKLY_BUDGET - accepted_consumption_1_message
				->offered_consumption_volume * ORDER_QUANTITY[0].price;
			
				EXPENDITURES =accepted_consumption_1_message
				->offered_consumption_volume * ORDER_QUANTITY[0].price;
			 
				RECEIVED_QUANTITY[0].quantity = accepted_consumption_1_message
				->offered_consumption_volume;

				RECEIVED_QUANTITY[0].firm_id = ORDER_QUANTITY[0].firm_id;
			}

		FINISH_ACCEPTED_CONSUMPTION_1_MESSAGE_LOOP


		/*If rationed repeat ranking and request of goods: */
		if(RATIONED == 1)
		{

			/*The updated quality price message is read  */
			START_QUALITY_PRICE_INFO_2_MESSAGE_LOOP

				if(quality_price_info_2_message->mall_region_id == REGION_ID)  
				{

					
					add_mall_quality_price_info(&mall_quality_price_info_list, 						quality_price_info_2_message->mall_id, 
					quality_price_info_2_message->firm_id, 
					quality_price_info_2_message->mall_region_id, 
					quality_price_info_2_message->quality, 
					quality_price_info_2_message->price, 
					quality_price_info_2_message->available);
					
				}

			FINISH_QUALITY_PRICE_INFO_2_MESSAGE_LOOP



			//+++++ Logit Model +++++++++:

			/*Sum of weighted exponents of quality price ratios   */
			for(i = 0;i < mall_quality_price_info_list.size; i++) 
			{
				sum_weighted_qual_pric_ratios +=(mall_quality_price_info_list
				.array[i].available) * 
				exp(log(mall_quality_price_info_list.array[i].price)*GAMMA); 
			}

			/*This computes the logits  */
			for(i = 0; i < mall_quality_price_info_list.size; i++) 
			{
				logit = (mall_quality_price_info_list.array[i].available) * 
				exp(log(mall_quality_price_info_list.array[i].price)*GAMMA) / 
				sum_weighted_qual_pric_ratios;

				logit = logit*100;

				add_logit_firm_id(&logit_firm_id_list, logit,
 				mall_quality_price_info_list.array[i].firm_id);
			}

			if(sum_weighted_qual_pric_ratios>0)
			{
				int random_number = random_int(0,100);
				j = 0;
				int x = 0, index_selected_good=j;

				for(j = 0; j < logit_firm_id_list.size;j++)
				{
					/*if randum number <= logit then select the corresponding 						good  */ 
					if((random_number < logit_firm_id_list.array[j].logit)
					&& (x!=1))
					{
						ORDER_QUANTITY[1].firm_id = logit_firm_id_list
						.array[j].firm_id; //Seleced Good
					
						x =1;
						index_selected_good= j;
					}
					/*else sum logits and go to next iteration step */
					else
					{
						if((j < logit_firm_id_list.size-1) )
						{
							logit_firm_id_list.array[j+1].logit = 								logit_firm_id_list.array[j+1].logit+ 
							logit_firm_id_list.array[j].logit;
						}
					}
				}
			
				/*This computes the order quantity  and store the price */
				ORDER_QUANTITY[1].quantity = WEEKLY_BUDGET/
				mall_quality_price_info_list.array[index_selected_good].price;

				ORDER_QUANTITY[1].price = mall_quality_price_info_list
				.array[index_selected_good].price;

				/*Sending the second consumption request message  */
				add_consumption_request_2_message(
				mall_quality_price_info_list.array[index_selected_good].mall_id,
				ID,ORDER_QUANTITY[1].firm_id,
				ORDER_QUANTITY[1].quantity,MSGDATA);
			

			

			
			}
			else
			{		
				ORDER_QUANTITY[1].quantity = 0;
				ORDER_QUANTITY[1].firm_id= 0;
				ORDER_QUANTITY[1].price= 0;
			}
		}
		else
		{
			ORDER_QUANTITY[1].quantity = 0.0;
			ORDER_QUANTITY[1].firm_id = 0;
			ORDER_QUANTITY[1].price = 0.0;
		}

	}else 
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT && MALL_COMPLETELY_SOLD_OUT == 1)
	{
		EXPENDITURES= 0;
		RECEIVED_QUANTITY[0].quantity = 0;
		RECEIVED_QUANTITY[0].firm_id = 0;
		ORDER_QUANTITY[1].quantity = 0;
		ORDER_QUANTITY[1].firm_id = 0;
		ORDER_QUANTITY[1].price = 0;
	}

	free_mall_quality_price_info_array(&mall_quality_price_info_list);
	free_logit_firm_id_array(&logit_firm_id_list);

	return 0;
}

/** \fn Household_read_rationing()
 * \brief This function stores in memory the realized consumption if HH was rationed in first round. 
			
 */
int Household_read_rationing()
{

	if(DAY%WEEK==DAY_OF_WEEK_TO_ACT)
	{

		if(RATIONED ==1)
		{
			/*Read the message about accepted consumption */
			START_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP

				if(accepted_consumption_2_message->worker_id == ID)
				{
					RATIONED = accepted_consumption_2_message->rationed;

					RECEIVED_QUANTITY[1].quantity=
					accepted_consumption_2_message->offered_consumption_volume;
					
					RECEIVED_QUANTITY[1].firm_id = 
					ORDER_QUANTITY[1].firm_id; 
				}

			FINISH_ACCEPTED_CONSUMPTION_2_MESSAGE_LOOP

		}
		else
		{
			RECEIVED_QUANTITY[1].quantity=0.0;
			RECEIVED_QUANTITY[1].firm_id =0; 
		}

		WEEKLY_BUDGET = WEEKLY_BUDGET - RECEIVED_QUANTITY[1].quantity 
		*ORDER_QUANTITY[1].price ;
		
		EXPENDITURES += RECEIVED_QUANTITY[1].quantity * ORDER_QUANTITY[1].price ;
	}

	return 0;
}

/** \fn Household_rank_and_buy_goods_2()
 * \brief This function convert the remaining budget, that is not spent in both consumtion steps, into the savings 
			
 */
int Household_handle_leftover_budget()
{

	RECEIVED_DIVIDEND_CONS = 0;
	RECEIVED_DIVIDEND_CAP = 0;
	
	/*Receive the dividens*/
	
	START_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP

		RECEIVED_DIVIDEND_CAP += capital_good_profit_distribution_message
		->capital_good_profit_shares;

	FINISH_CAPITAL_GOOD_PROFIT_DISTRIBUTION_MESSAGE_LOOP


	START_DIVIDEND_MESSAGE_LOOP

		RECEIVED_DIVIDEND_CONS += dividend_message->dividend;

	FINISH_DIVIDEND_MESSAGE_LOOP
	

	SAVINGS += RECEIVED_DIVIDEND_CONS+RECEIVED_DIVIDEND_CAP;

	if(DAY%WEEK == DAY_OF_WEEK_TO_ACT )
	{
		
		BUDGET = BUDGET - EXPENDITURES;


		if(WEEK_OF_MONTH !=1)
		{	
			
			SAVINGS -= EXPENDITURES;
			WEEKLY_BUDGET = BUDGET / WEEK_OF_MONTH;
			
			WEEK_OF_MONTH--; 
		}
		else
		{
			SAVINGS =SAVINGS - EXPENDITURES;
			//WEEK_OF_MONTH =4;
			WEEK_OF_MONTH--;
		}
		//set rationed back to zero:
		RATIONED = 0;
	}

	return 0;
}

/** \fn Household_send_data_to_Market_Research()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Household_send_data_to_Market_Research()
{
	if(DAY%MONTH == 0)
	{
		add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
		WAGE, SPECIFIC_SKILL,MSGDATA);
	}	



	return 0;
}



