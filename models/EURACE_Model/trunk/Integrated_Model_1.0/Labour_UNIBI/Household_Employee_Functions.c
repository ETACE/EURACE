#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"
#include "Labour_aux_headers.h"


/**********************************Household Role: Labour Market*********************************.*/
/** \fn Household_receive_wage()
 * \brief: 
    - Household receives wage if the household is employed.
    - Sets reservation wage equal to the new wage.
    - Calculates the income in this period add to last_income_array.
*/
int Household_receive_wage()
{

    /*Household reads the wage messages if employed.*/
    START_WAGE_PAYMENT_MESSAGE_LOOP

        /*Set wage and reservation wage.*/
        WAGE = wage_payment_message->payment;
        WAGE_RESERVATION = WAGE;
    

        /*Calculate the total income.*/
        TOTAL_INCOME= wage_payment_message->payment +  CUM_TOTAL_DIVIDENDS +
        MONTHLY_BOND_INTEREST_INCOME;

        /*Add wage to payment account.*/
        PAYMENT_ACCOUNT += wage_payment_message->payment;

        /*Store the productivity and the average specific skills 
        of the employer in order to update the specific skills later.*/
        CURRENT_PRODUCTIVITY_EMPLOYER = wage_payment_message-> productivity;
        CURRENT_MEAN_SPECIFIC_SKILLS_EMPLOYER =wage_payment_message->average_specific_skills;
    
    FINISH_WAGE_PAYMENT_MESSAGE_LOOP

    return 0;
}


/** \fn Household_update_specific_skills()
 * \brief:
    - Household updates specific skills if the household is employed
    - Household sends the new specific skill to the employer
*/
int Household_update_specific_skills()
{
    /*If the specific skill of household is lower than the productivity of the employer
    - no negative effect: no forgetting.*/
    if(SPECIFIC_SKILL < CURRENT_PRODUCTIVITY_EMPLOYER)
    {
        /*Update the specific skill: depends on the actual specific skill, 
        the gap between the actual specific skills and the actual productivity of the employer,
        and the general skill which determines the speed of closing the this gap.*/
        
    	if(SKILL_UPGRADE_PREDETERMINED==0)
    	{
    	SPECIFIC_SKILL = SPECIFIC_SKILL + 
        (CURRENT_PRODUCTIVITY_EMPLOYER - SPECIFIC_SKILL)*((1-pow(0.5,1/(20+0.25*(GENERAL_SKILL-1)*(4-20))))
        + 0*CURRENT_MEAN_SPECIFIC_SKILLS_EMPLOYER);
    	}else
    	{
    		if(GENERAL_SKILL == 1)
    		{
    			SPECIFIC_SKILL = SPECIFIC_SKILL + 
    			        (CURRENT_PRODUCTIVITY_EMPLOYER - SPECIFIC_SKILL)*LOW_SKILL_UPGRADE;
    		}else
    		{
    			SPECIFIC_SKILL = SPECIFIC_SKILL + 
    			    			        (CURRENT_PRODUCTIVITY_EMPLOYER - SPECIFIC_SKILL)*HIGH_SKILL_UPGRADE;
    		}
    	}
        /*Send specific skill to employer.*/
        add_specific_skill_update_message(ID,EMPLOYEE_FIRM_ID,SPECIFIC_SKILL);
    }

    return 0;
}



/** \fn Household_read_firing_messages()
 * \brief 
    - Household reads firing messages if the household is employed
    - Household becomes unemployed: no employer and no wage
    - Stores the last_labor_income for the benefit notification
*/
int Household_read_firing_messages()
{

    char * filename;
    FILE * file1;
    /* Check for firing message*/
    START_FIRING_MESSAGE_LOOP

        /*If employee is fired.*/
        if(firing_message->worker_id == ID)
        {
            /*No employer.*/
            EMPLOYEE_FIRM_ID = -1;
            
                        if (PRINT_DEBUG_FILE_EXP1)
       {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_read_firing.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %d",DAY,firing_message->firm_id,ID);
        fclose(file1);
        free(filename);
       }
            
            
            /*Information for unemployment benefit notification.*/
            LAST_LABOUR_INCOME = WAGE;
            WAGE = 0;
        }

    FINISH_FIRING_MESSAGE_LOOP
    
    return 0;
}



/** \fn Household_UNEMPLOYED_read_job_vacancies_and_send_applications()
 * \brief: 
    - Household reads vacancy messages. 
    - Selects vacancies regarding the posted wage offer: 
        1: Household and firm are in the same region: wage offer has to be higher than reservation wage
        2: Household and firm are not in the same region: wage offer - commuting costs has to be higher than the res-wage
    - Sends application. 
*/
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications()
{
    int i=0;
    int j=0;
    double wage_offer=0.0;
    char * filename;
    FILE * file1;
    
    if (DAY>20)
    {
    if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_unemployed.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d",DAY,ID);
        fclose(file1);
        free(filename);
    }
    }

    
    

    /* Create a vacancy dynamic array to store vacancies.*/
    vacancy_array  vacancy_list;
    init_vacancy_array(&vacancy_list);
    
    /*Searchs for vacancies.*/
    START_VACANCIES_MESSAGE_LOOP
 
        /*Unemployed take only the wage offer for the correspondent general skill level into account.*/
        if(GENERAL_SKILL == 1)
        {
            wage_offer = vacancies_message->firm_wage_offer_for_skill_1;
        }

        if(GENERAL_SKILL == 2)
        {
            wage_offer = vacancies_message->firm_wage_offer_for_skill_2;
        }

        if(GENERAL_SKILL == 3)
        {
            wage_offer =  vacancies_message->firm_wage_offer_for_skill_3;
        }

        if(GENERAL_SKILL == 4)
        {
            wage_offer =  vacancies_message->firm_wage_offer_for_skill_4;
        }

        if(GENERAL_SKILL == 5)
        {
            wage_offer =  vacancies_message->firm_wage_offer_for_skill_5;
        }

        /*Wage offer has to be equal or higher than the reservation wage.*/
        if(wage_offer >= WAGE_RESERVATION)
        {
            /*Firm and Household are in the same region: no commuting costs.*/
            if(REGION_ID == vacancies_message->region_id)
            {
                /*Add vacancy to vacancy list (possible job candidates).*/
                add_vacancy(&vacancy_list,
                vacancies_message->firm_id, 
                vacancies_message->region_id,
                wage_offer);
            }
            /*Firm and Household are not in the same region: Household has to bear commuting costs.*/
            else 
            {
                /*For every neighboring region.*/
                for(i = 0;i < NEIGHBORING_REGION_IDS.size; i++)
                {
                    /*If vacancy is in a neighboring region.*/
                    if(vacancies_message->region_id == NEIGHBORING_REGION_IDS.array[i])
                    {
                        /*Wage offer minus commuting costs has to be higher than the reservation wage.*/
                        //if((wage_offer -REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT) >= WAGE_RESERVATION)
                        if((wage_offer - REGION_COST) >= WAGE_RESERVATION)
                        {
                            /*Add vacancy to vacancy list (possible job candidates).*/
                            add_vacancy(&vacancy_list, 
                            vacancies_message->firm_id, 
                            vacancies_message->region_id,
                            (wage_offer - REGION_COST));

                            /*add_vacancy(&vacancy_list, 
                            vacancies_message->firm_id, 
                            vacancies_message->region_id,
                            (wage_offer - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT));.*/
                        }
                        break;
                    }
                }
            }
        }

    FINISH_VACANCIES_MESSAGE_LOOP


    /*If there are more vacancies on the list than the maximum number of applications the household can send.*/
    if(vacancy_list.size > NUMBER_APPLICATIONS)
    {
        /*Remove vacancies from the list randomly until the list contains as many
        vacancies as a household can send applications.
        ->imperfect information.*/
        while(vacancy_list.size > NUMBER_APPLICATIONS)
        {
            j = random_int(0, (vacancy_list.size-1));
            remove_vacancy(&vacancy_list, j);
        }
    }

    /*Sorting vacancies regarding their posted wage offer.*/
    //qsort(vacancy_list.array, vacancy_list.size, sizeof(vacancy),vacancy_list_rank_wage_offer_function);

    /* Sends applications to all vacancies which are still on the list.*/
    for(i = 0; i < (vacancy_list.size); i++)
    {
        add_job_application_message(ID, 
        vacancy_list.array[i].firm_id,  
        REGION_ID, 
        GENERAL_SKILL, 
        SPECIFIC_SKILL);
    }

    /*Free the vacancy dynamic array.*/
    free_vacancy_array(&vacancy_list);

    return 0;
}

/** \fn Household_read_job_offers_send_response()
 * \brief: 
    - Household reads job offer(s) and accepts the offer with the highest wage offer net of commuting costs.
*/
int Household_read_job_offers_send_response()
{
    /* Create a job offer dynamic array*/
    job_offer_array job_offer_list;
    init_job_offer_array(&job_offer_list);

    START_JOB_OFFER_MESSAGE_LOOP

        /*Read job offer messages for this Household.*/
        if(job_offer_message->worker_id == ID)
        {
            /*Job offers of firms in the same region: no commuting costs.*/
            if(REGION_ID == job_offer_message->region_id)
            {
                /*Add job offer to the job offer list.*/
                add_job_offer(&job_offer_list,
                job_offer_message->firm_id, 
                job_offer_message->region_id,
                job_offer_message->wage_offer);
            }
            /*Job offers of firms in different regions: Household has to bear commuting costs.*/
            else
            {
                add_job_offer(&job_offer_list,
                job_offer_message->firm_id, 
                job_offer_message->region_id,
                (job_offer_message->wage_offer - REGION_COST));

                /*add_job_offer(&job_offer_list,
                job_offer_message->firm_id, 
                job_offer_message->region_id,
                (job_offer_message->wage_offer - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT));.*/
            }
        }

    FINISH_JOB_OFFER_MESSAGE_LOOP


    /*Ranks job offers regarding the posted wage offer net of commuting costs.*/
    qsort(job_offer_list.array, job_offer_list.size, sizeof(job_offer),job_offer_list_rank_wage_offer_function);

    /* Accept  job with highest net wage offer: first on the list (array[0]).*/
    if(job_offer_list.size > 0)
    {
        add_job_acceptance_message(ID, 
        job_offer_list.array[0].firm_id, 
        REGION_ID, 
        GENERAL_SKILL, 
        SPECIFIC_SKILL);

        /*Sets employer_id, employer_region_id and the day when the household will receive the wage.*/
        EMPLOYEE_FIRM_ID = job_offer_list.array[0].firm_id;
        EMPLOYER_REGION_ID = job_offer_list.array[0].region_id;
        DAY_OF_MONTH_RECEIVE_INCOME = DAY%MONTH;

        /*If household and firm are in the same region.*/
        if(REGION_ID == job_offer_list.array[0].region_id)
        {
            /*Add the new wage and sets the reservation wage to the new wage.*/
            WAGE = job_offer_list.array[0].wage_offer;
            WAGE_RESERVATION = WAGE;
        }
        /*If household and firm are not in the same region.*/
        else
        {   
            //WAGE = (job_offer_list.array[0].wage_offer + REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT);
            //WAGE_RESERVATION = WAGE - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT;
            
            /*Add the new wage minus commuting costs and 
            sets the reservation wage to the new wage minus commuting costs.*/
            WAGE = (job_offer_list.array[0].wage_offer + REGION_COST);
            WAGE_RESERVATION = WAGE - REGION_COST;
        }
    }

    /*Free the job offer dynamic array.*/
    free_job_offer_array(&job_offer_list);

    return 0;
}



/** \fn Household_read_application_rejection_update_wage_reservation()
 * \brief: 
    - If the household is still unemployed it updates (decreases) its wage reservation.
*/
int Household_read_application_rejection_update_wage_reservation()
{
    /*Updates the reservation wage by a certain fraction according to the parameter WAGE_RESERVATION_UPDATE.*/
    WAGE_RESERVATION = WAGE_RESERVATION - WAGE_RESERVATION*WAGE_RESERVATION_UPDATE;

    /* Don't let wage reservation be below the current unemplyoment benefit pct.*/
    if(WAGE_RESERVATION < LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT)
    {
        WAGE_RESERVATION = LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT;
    }
    
    return 0;
}


/** \fn Household_UNEMPLOYED_read_job_vacancies_and_send_applications2()
 * \brief: 
    - Household reads vacancy messages. 
    - Selects vacancies regarding the posted wage offer: 
        1: Household and firm are in the same region: wage offer has to be higher than reservation wage
        2: Household and firm are not in the same region: wage offer - commuting costs has to be higher than the res-wage
    - Sends application. 
*/
int Household_UNEMPLOYED_read_job_vacancies_and_send_applications_2()
{
    int i=0;
    int j=0;
    double wage_offer=0.0;

    /* Create a vacancy dynamic array*/
    vacancy_array  vacancy_list;
    init_vacancy_array(&vacancy_list);

    /*Searchs for vacancies.*/
    START_VACANCIES2_MESSAGE_LOOP
    
        /*Unemployed take only the wage offer for the correspondent general skill level into account.*/
        if(GENERAL_SKILL == 1)
        {
            wage_offer = vacancies2_message->firm_wage_offer_for_skill_1;
        }

        if(GENERAL_SKILL == 2)
        {
            wage_offer = vacancies2_message->firm_wage_offer_for_skill_2;
        }

        if(GENERAL_SKILL == 3)
        {
            wage_offer =  vacancies2_message->firm_wage_offer_for_skill_3;
        }

        if(GENERAL_SKILL == 4)
        {
            wage_offer =  vacancies2_message->firm_wage_offer_for_skill_4;
        }

        if(GENERAL_SKILL == 5)
        {
            wage_offer =  vacancies2_message->firm_wage_offer_for_skill_5;
        }

        /*Wage offer has to be equal or higher than the reservation wage.*/
        if(wage_offer >= WAGE_RESERVATION)
        {
            /*Firm and Household are in the same region: no commuting costs.*/
            if(REGION_ID == vacancies2_message->region_id)
            {
                /*Add vacancy to vacancy list (possible job candidates).*/
                add_vacancy(&vacancy_list, 
                vacancies2_message->firm_id, 
                vacancies2_message->region_id,
                wage_offer);
            }
            /*Firm and Household are not in the same region: Household has to bear commuting costs.*/
            else
            {
                /*For every neighboring region.*/
                for(i = 0; i < NEIGHBORING_REGION_IDS.size;i++)
                {
                    /*If vacancy is in a neighboring region.*/
                    if(vacancies2_message->region_id == NEIGHBORING_REGION_IDS.array[i])
                    {
                        /*Wage offer minus commuting costs has to be higher than the reservation wage.*/
                        //if((wage_offer - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT) >=WAGE_RESERVATION)
                        if((wage_offer - REGION_COST) >= WAGE_RESERVATION)
                        {
                            /*Add vacancy to vacancy list (possible job candidates).*/
                            add_vacancy(&vacancy_list,
                            vacancies2_message->firm_id, 
                            vacancies2_message->region_id,
                            (wage_offer - REGION_COST));

                            /*add_vacancy(&vacancy_list,
                            vacancies2_message->firm_id, 
                            vacancies2_message->region_id,
                            (wage_offer - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT));.*/
                        }
                    
                        break;

                    }
                }
            }
        }

    FINISH_VACANCIES2_MESSAGE_LOOP

    /*If there are more vacancies on the list than the maximum number of applications the household can send.*/
    if(vacancy_list.size > NUMBER_APPLICATIONS)
    {
        /*Remove vacancies from the list randomly until the list contains as many
        vacancies as a household can send applications.
        ->imperfect information.*/
        while(vacancy_list.size > NUMBER_APPLICATIONS)
        {
            j = random_int(0, (vacancy_list.size-1));
            remove_vacancy(&vacancy_list, j);
        }
    }

    /*Sorting vacancies regarding their posted wage offer.*/
    //qsort(vacancy_list.array, vacancy_list.size, sizeof(vacancy),vacancy_list_rank_wage_offer_function);

    /* Sends applications to all vacancies which are still on the list.*/
    for(i = 0; i < (vacancy_list.size); i++)
    {
        add_job_application2_message(ID, 
        vacancy_list.array[i].firm_id, 
        REGION_ID, 
        GENERAL_SKILL, 
        SPECIFIC_SKILL);
    }

    /* Free the vacancy dynamic array*/
    free_vacancy_array(&vacancy_list);

    return 0;
}


/** \fn Household_read_job_offers_send_response2()
 * \brief: 
    - Household reads job offer(s) and accepts the offer with the highest wage offer net of commuting costs.
*/
int Household_read_job_offers_send_response_2()
{
    /* Create a job offer dynamic array*/
    job_offer_array  job_offer_list;
    init_job_offer_array(&job_offer_list);

    START_JOB_OFFER2_MESSAGE_LOOP
    
        /* Read job offer messages for this Household*/
        if(job_offer2_message->worker_id == ID)
        {
            /*Job offers of firms in the same region: no commuting costs.*/
            if(REGION_ID == job_offer2_message->region_id)
            {
                /*Add job offer to the job offer list.*/
                add_job_offer(&job_offer_list,
                job_offer2_message->firm_id,
                job_offer2_message->region_id,
                job_offer2_message->wage_offer);
            }
            /*Job offers of firms in different regions: Household has to bear commuting costs.*/
            else
            {
                /*add_job_offer(&job_offer_list,
                job_offer2_message->firm_id,
                job_offer2_message->region_id,
                (job_offer2_message->wage_offer - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT));.*/

                /*Add job offer to the job offer list.*/
                add_job_offer(&job_offer_list,
                job_offer2_message->firm_id,
                job_offer2_message->region_id,
                (job_offer2_message->wage_offer - REGION_COST));
            }
        }

    FINISH_JOB_OFFER2_MESSAGE_LOOP

    /*Ranks job offers regarding the posted wage offer net of commuting costs.*/
    qsort(job_offer_list.array, job_offer_list.size, sizeof(job_offer),job_offer_list_rank_wage_offer_function);

    /* Accept  job with highest net wage offer: first on the list (array[0]).*/
    if(job_offer_list.size > 0)
    {
        add_job_acceptance2_message(ID, 
        job_offer_list.array[0].firm_id,
        REGION_ID, 
        GENERAL_SKILL, 
        SPECIFIC_SKILL);

        /*Sets employer_id, employer_region_id and the day when the household will receive the wage.*/
        EMPLOYEE_FIRM_ID = job_offer_list.array[0].firm_id;
        EMPLOYER_REGION_ID = job_offer_list.array[0].region_id;
        DAY_OF_MONTH_RECEIVE_INCOME = DAY%MONTH;

        /*If household and firm are in the same region.*/
        if(REGION_ID == job_offer_list.array[0].region_id)
        {
            /*Add the new wage and sets the reservation wage to the new wage.*/
            WAGE = job_offer_list.array[0].wage_offer;
            WAGE_RESERVATION = WAGE;    
        }
         /*If household and firm are not in the same region.*/
        else
        {  
            //WAGE = (job_offer_list.array[0].wage_offer + REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT);
            //WAGE_RESERVATION = WAGE - REGION_COST*COMMUTING_COSTS_PRICE_LEVEL_WEIGHT;
            
            /*Add the new wage minus commuting costs and 
            sets the reservation wage to the new wage minus commuting costs.*/
            WAGE = (job_offer_list.array[0].wage_offer + REGION_COST);
            WAGE_RESERVATION = WAGE - REGION_COST;
        }
    }

    /* Free the job offer dynamic array*/
    free_job_offer_array(&job_offer_list);

    return 0;
}



/** \fn Household_read_application_rejection_update_wage_reservation2()
 * \brief: 
    - If the household is still unemployed it updates (decreases) its wage reservation.
*/
int Household_read_application_rejection_update_wage_reservation_2()
{
    /*Updates the reservation wage by a certain fraction according to the parameter WAGE_RESERVATION_UPDATE.*/
    WAGE_RESERVATION = WAGE_RESERVATION-WAGE_RESERVATION*WAGE_RESERVATION_UPDATE;

    /* Don't let wage reservation be below the current unemplyoment benefit pct.*/
    if(WAGE_RESERVATION < LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT)
    {
        WAGE_RESERVATION = LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT;
    }

    return 0;
}

int Household_idle()
{
    return 0;
}

int Household_finish_labour_market()
{
    return 0;
}

/**********************************Household Role: Public Sector *********************/

/** \fn Household_send_unemployment_benefit_notification()
 * \brief This function sends a message to the government in case of being unemployed that contains the unemployment benefit.
 * The government aggregates the unemployment benefit payments and subtract the amount from its payment account.
 * The household uses the own memory variable UNEMPLOYMENT_BENEFIT_PCT to calculate its own unemployment benefit.
 */
int Household_send_unemployment_benefit_notification()
{
    
    /*Compute unemployment_benefit*/
    //Sander, 23.10.09: Transferred this code from the government to the household
    //Now the household does the complete computation and only sends the outcome to government
            
    //Compute the individual unemployment benefit payment as a fraction of the last labour income       
    //if unemployment benefit is larger than the mean wage:
        if(LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT > REGION_WIDE_MEAN_WAGE*0.5 )
        {       
            UNEMPLOYMENT_PAYMENT = LAST_LABOUR_INCOME*UNEMPLOYMENT_BENEFIT_PCT;  
        }
        else    
        {
            //if unemployment benefit is below the mean wage: pay 0.5 * MEAN_WAGE
            UNEMPLOYMENT_PAYMENT =  REGION_WIDE_MEAN_WAGE*0.5; 
        }
    
    /*Add unemployment_benefit message */
    add_unemployment_notification_message(GOV_ID, UNEMPLOYMENT_PAYMENT );
    
    /*Add unemployment_benefit to account */
    PAYMENT_ACCOUNT +=  UNEMPLOYMENT_PAYMENT;

    
  //  if (DAY>238)
   // printf("\n LAST_LABOUR_INCOME: %f",LAST_LABOUR_INCOME);        
    //printf("\n PAYMENT_ACCOUNT before: %f",PAYMENT_ACCOUNT);
    //PAYMENT_ACCOUNT +=  UNEMPLOYMENT_BENEFIT_PCT * LAST_LABOUR_INCOME;
   //  printf("\n PAYMENT_ACCOUNT after: %f",PAYMENT_ACCOUNT);
  //  printf("\n UNEMPLOYMENT_BENEFIT_PCT: %f LAST_LABOUR_INCOME: %f",UNEMPLOYMENT_BENEFIT_PCT,LAST_LABOUR_INCOME);

    TOTAL_INCOME=  UNEMPLOYMENT_PAYMENT + CUM_TOTAL_DIVIDENDS + MONTHLY_BOND_INTEREST_INCOME;


    //Set the benefit reception day
    DAY_OF_MONTH_RECEIVE_BENEFIT = DAY_OF_MONTH_RECEIVE_INCOME;

    return 0;

}


/** \fn Household_send_subsidy_notification()
 * \brief This function sends a message to the government in case the household applies for a subsidy.
 */
int Household_send_subsidy_notification()
{
    if (POLICY_EXP_STABILIZATION_SUBSIDY==1)
    {
        SUBSIDY_PAYMENT = SUBSIDY_PCT*MONTHLY_CONSUMPTION_EXPENDITURE;
    
        /*Add subsidy message */
        add_hh_subsidy_notification_message(GOV_ID, SUBSIDY_PAYMENT);
        PAYMENT_ACCOUNT += SUBSIDY_PAYMENT;
    }
    return 0;
}

/** \fn Household_send_transfer_notification()
 * \brief This function sends a message to the government in case the household applies for a transfer.
 */
int Household_send_transfer_notification()
{
    /*Add transfer message */
    add_hh_transfer_notification_message(GOV_ID);
    PAYMENT_ACCOUNT += TRANSFER_PAYMENT;

    return 0;
}

/** \fn Household_send_tax_payment()
 * \brief Household pays the income taxes
 */
int Household_send_tax_payment()
{
    // #ifdef _DEBUG_MODE  
  //      FILE *file1=NULL;
  //      char *filename="";
   // #endif
    double restitution_payment=0.0;
    int i;
   
    //Benefit restitution: repayment of the already received monthly unemployment benefits if recently re-employed
    if (DAY_OF_MONTH_RECEIVE_BENEFIT != DAY_OF_MONTH_RECEIVE_INCOME )
    {
        //printf("\n DAY: %d DAY_OF_MONTH_RECEIVE_INCOME: %d DAY_OF_MONTH_RECEIVE_BENEFIT: %d",DAY,DAY_OF_MONTH_RECEIVE_INCOME,DAY_OF_MONTH_RECEIVE_BENEFIT);
        restitution_payment = ((DAY_OF_MONTH_RECEIVE_BENEFIT + (20-DAY_OF_MONTH_RECEIVE_INCOME)%20)/20.0)
                            * UNEMPLOYMENT_PAYMENT;
        //Reset
        DAY_OF_MONTH_RECEIVE_BENEFIT = DAY_OF_MONTH_RECEIVE_INCOME;
        
       //  printf("\n DAY: %d restitution_payment: %f UNEMPLOYMENT_PAYMENT: %f",DAY,restitution_payment,UNEMPLOYMENT_PAYMENT);
            

    }
    
     
    
    
    /*Send a message to the government*/
    add_unemployment_benefit_restitution_message(GOV_ID, restitution_payment);

    /*Compute the total taxes*/
    TAX_PAYMENT = CUM_TOTAL_DIVIDENDS*TAX_RATE_HH_CAPITAL + WAGE*TAX_RATE_HH_LABOUR;
    
    
    //Store the net income in an array
    remove_double(&LAST_NET_INCOME,0);
         add_double(&LAST_NET_INCOME,TOTAL_INCOME-TAX_PAYMENT);
         
    //Compute the mean net income:
         
         double net_inc = 0;
         for(i=0;i<LAST_NET_INCOME.size;i++)
         {
        	 net_inc+=LAST_NET_INCOME.array[i];
         }
         MEAN_NET_INCOME = net_inc/LAST_NET_INCOME.size;

    /*Send a message to the government*/
    add_tax_payment_message(GOV_ID, TAX_PAYMENT);

    /*Reduce the payment account*/
    PAYMENT_ACCOUNT -= restitution_payment + TAX_PAYMENT;

    /*Setting the counter of monthly dividends = 0*/
    CUM_TOTAL_DIVIDENDS=0;
    
  /*  if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/households_tax_payments.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f %f",DAY,ID,restitution_payment,TAX_PAYMENT);
            fclose(file1);
            free(filename);
        }  */


    return 0;

}
