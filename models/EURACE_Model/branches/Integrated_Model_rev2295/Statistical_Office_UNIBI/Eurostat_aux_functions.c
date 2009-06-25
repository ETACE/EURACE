/*********************************
 * Eurostat_aux_functions.c 
 * Eurostat auxiliary functions.
 * *********************************
 * History:
 * 16/09/08 Sander 
 *********************************/
#include <limits.h> //required to test for max. double: LONG_MAX
#include "../header.h"
#include "../my_library_header.h"
#include "../Eurostat_agent_header.h"
#include "Eurostat_aux_header.h"

#define MAX_SURVIVAL_PERIODS 12 //length of the array to store the survival rate distribution, nr of bins
#define MAX_FIRM_AGE 60         //length of the array to store the firm age distribution, nr of bins


/* \fn: void Eurostat_reset_data(void)
 * \brief: Function to reset the region data strucures for firms and households.
 */
void Eurostat_reset_data(void)
{
    int i;

    /*delete the content of the data arrays in order to store the data for the new month*/
    //free(REGION_HOUSEHOLD_DATA);
    //free(REGION_FIRM_DATA);
    
    //Remove all data arrays
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
        remove_firm_data(&REGION_FIRM_DATA, i);
        i--;
    }
    
    for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
    {
        remove_household_data(&REGION_HOUSEHOLD_DATA, i);
        i--;
    }

    //Reconstruct empty data arrays
    for(i = 1; i <= NO_REGIONS; i++)
    {
        add_firm_data(&REGION_FIRM_DATA,
                i,0,0,                   //region_id -> vacancies
                0,0,0,0,0,0,             //employees_skill
                0.0,0.0,0.0,0.0,0.0,0.0, //average_wage_skill
                0.0,0.0,0.0,0.0,0.0,0.0, //average_s_skill
                0.0,0.0,0.0,0.0,0.0,     //total_earnings -> average_debt_earnings_ratio
                0.0,0.0,0.0,0.0,0.0,0.0, //average_debt_equity_ratio -> monthly_planned_output
                0.0,1.0,1.0,             //gdp, cpi, cpi_last_month 
                0,0,                     //no_firm_births, no_firm_deaths
                0,0);                    //productivity_progress, productivity
        
        add_household_data(&REGION_HOUSEHOLD_DATA,
                i,
                0,0,0,0,0,0,
                0,0,0,0,0,0,
                0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0);
    }
    
}

/* \fn: void Eurostat_compute_mean_price(void)
 * \brief: Function to compute a mean price.
 */
void Eurostat_compute_mean_price(void)
{
    double sum_consumption_good_supply = 0.0;
    PRICE_INDEX = 0.0;

    /*Compute a weighted mean price*/
            
    START_FIRM_SEND_DATA_MESSAGE_LOOP
        sum_consumption_good_supply+= firm_send_data_message->total_supply;
    FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
            
    START_FIRM_SEND_DATA_MESSAGE_LOOP
        PRICE_INDEX += (firm_send_data_message->price*firm_send_data_message->total_supply)/ sum_consumption_good_supply;
    FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
}

/* \fn: void Eurostat_read_firm_data(void)
 * \brief: Function to read and store the region data of the firms.
 */
void Eurostat_read_firm_data(void)
{
    int i;

    NO_VACANCIES = 0.0;
    NO_EMPLOYEES = 0.0;
    NO_EMPLOYEES_SKILL_1 = 0.0;
    NO_EMPLOYEES_SKILL_2 = 0.0;
    NO_EMPLOYEES_SKILL_3 = 0.0;
    NO_EMPLOYEES_SKILL_4 = 0.0;
    NO_EMPLOYEES_SKILL_5 = 0.0;

    FIRM_AVERAGE_WAGE = 0.0;

    FIRM_AVERAGE_S_SKILL = 0.0;
    FIRM_AVERAGE_S_SKILL_1 = 0.0;
    FIRM_AVERAGE_S_SKILL_2 = 0.0;
    FIRM_AVERAGE_S_SKILL_3 = 0.0;
    FIRM_AVERAGE_S_SKILL_4 = 0.0;
    FIRM_AVERAGE_S_SKILL_5 = 0.0;
    
    FIRM_AVERAGE_PRODUCTIVITY_PROGRESS = 0.0;
    FIRM_AVERAGE_PRODUCTIVITY = 0.0;
    
    NO_FIRMS =0;

    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
        REGION_FIRM_DATA.array[i].no_firms = 0;
                    
        START_FIRM_SEND_DATA_MESSAGE_LOOP
        
        if(firm_send_data_message->region_id == 
        REGION_FIRM_DATA.array[i].region_id)
        {
            REGION_FIRM_DATA.array[i].no_firms += 1;
            NO_FIRMS++;
            
            REGION_FIRM_DATA.array[i].vacancies += 
                firm_send_data_message->vacancies;
            NO_VACANCIES += firm_send_data_message->vacancies;
    
            REGION_FIRM_DATA.array[i].employees += 
                firm_send_data_message->employees;
            NO_EMPLOYEES += firm_send_data_message->employees;
    
            REGION_FIRM_DATA.array[i].employees_skill_1 += 
                firm_send_data_message->employees_skill_1;
            NO_EMPLOYEES_SKILL_1 += 
                firm_send_data_message->employees_skill_1;
    
            REGION_FIRM_DATA.array[i].employees_skill_2 += 
                firm_send_data_message->employees_skill_2;
            NO_EMPLOYEES_SKILL_2 += 
                firm_send_data_message->employees_skill_2;
    
            REGION_FIRM_DATA.array[i].employees_skill_3 += 
                firm_send_data_message->employees_skill_3;
            NO_EMPLOYEES_SKILL_3 += 
                firm_send_data_message->employees_skill_3;
    
            REGION_FIRM_DATA.array[i].employees_skill_4 += 
                firm_send_data_message->employees_skill_4;
            NO_EMPLOYEES_SKILL_4 += 
                firm_send_data_message->employees_skill_4;
    
            REGION_FIRM_DATA.array[i].employees_skill_5 += 
                firm_send_data_message->employees_skill_5;
            NO_EMPLOYEES_SKILL_5 += 
                firm_send_data_message->employees_skill_5;
    
    
            /********sum of wages of the firms++++++++*/
            REGION_FIRM_DATA.array[i].average_wage += 
                firm_send_data_message->average_wage*
                firm_send_data_message->employees;
            FIRM_AVERAGE_WAGE += firm_send_data_message->average_wage*
                firm_send_data_message->employees;
    
    
            /********sum of specific skills of the firms++++++++*/
            REGION_FIRM_DATA.array[i].average_s_skill += 
                firm_send_data_message->average_s_skill *
                firm_send_data_message->employees;
            FIRM_AVERAGE_S_SKILL += 
                firm_send_data_message->average_s_skill *
                firm_send_data_message->employees;
    
    
            REGION_FIRM_DATA.array[i].average_s_skill_1 +=
                firm_send_data_message->average_s_skill_1*
                firm_send_data_message->employees_skill_1;
            FIRM_AVERAGE_S_SKILL_1 +=
                firm_send_data_message->average_s_skill_1*
                firm_send_data_message->employees_skill_1;
    
    
            REGION_FIRM_DATA.array[i].average_s_skill_2 +=
                firm_send_data_message->average_s_skill_2*
                firm_send_data_message->employees_skill_2;
            FIRM_AVERAGE_S_SKILL_2 +=
                firm_send_data_message->average_s_skill_2*
                firm_send_data_message->employees_skill_2;
    
    
            REGION_FIRM_DATA.array[i].average_s_skill_3 +=
                firm_send_data_message->average_s_skill_3*
                firm_send_data_message->employees_skill_3;
            FIRM_AVERAGE_S_SKILL_3 +=
                firm_send_data_message->average_s_skill_3*
                firm_send_data_message->employees_skill_3;
    
    
            REGION_FIRM_DATA.array[i].average_s_skill_4 +=
                firm_send_data_message->average_s_skill_4*
                firm_send_data_message->employees_skill_4;
            FIRM_AVERAGE_S_SKILL_4 +=
                firm_send_data_message->average_s_skill_4*
                firm_send_data_message->employees_skill_4;
    
            
            REGION_FIRM_DATA.array[i].average_s_skill_5 +=
                firm_send_data_message->average_s_skill_5*
                firm_send_data_message->employees_skill_5;
            FIRM_AVERAGE_S_SKILL_5 +=
                firm_send_data_message->average_s_skill_5*
                firm_send_data_message->employees_skill_5;
            
            REGION_FIRM_DATA.array[i].productivity_progress +=
                firm_send_data_message->firm_productivity_progress;
            FIRM_AVERAGE_PRODUCTIVITY_PROGRESS +=
                firm_send_data_message->firm_productivity_progress;
            
            REGION_FIRM_DATA.array[i].productivity +=
                firm_send_data_message->firm_productivity;
            FIRM_AVERAGE_PRODUCTIVITY +=
                firm_send_data_message->firm_productivity;
   
        }
        FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
        
    }
}
    
/* \fn: void Eurostat_compute_region_firm_data(void)
 * \brief: Function to compute regional data related to firms.
 */
void Eurostat_compute_region_firm_data(void)
{
    int i;

    /*Create the REGIONAL data which feed backs to firms*/
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
        /*********************WAGES************************/
        if(REGION_FIRM_DATA.array[i].employees > 0)
        {
            REGION_FIRM_DATA.array[i].average_wage = 
            REGION_FIRM_DATA.array[i].average_wage/
            REGION_FIRM_DATA.array[i].employees;
        }
    
    
        /*****************SPECIFIC SKILLS*********************/
        if(REGION_FIRM_DATA.array[i].employees > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill =
            REGION_FIRM_DATA.array[i].average_s_skill/
            REGION_FIRM_DATA.array[i].employees;
        }
    
        if(REGION_FIRM_DATA.array[i].employees_skill_1 > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill_1 =
            REGION_FIRM_DATA.array[i].average_s_skill_1/
            REGION_FIRM_DATA.array[i].employees_skill_1;
        }
    
        if(REGION_FIRM_DATA.array[i].employees_skill_2 > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill_2 =
            REGION_FIRM_DATA.array[i].average_s_skill_2/
            REGION_FIRM_DATA.array[i].employees_skill_2;
        }
    
    
        if(REGION_FIRM_DATA.array[i].employees_skill_3 > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill_3 =
            REGION_FIRM_DATA.array[i].average_s_skill_3/
            REGION_FIRM_DATA.array[i].employees_skill_3;
        }
    
    
        if(REGION_FIRM_DATA.array[i].employees_skill_4 > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill_4 =
            REGION_FIRM_DATA.array[i].average_s_skill_4/
            REGION_FIRM_DATA.array[i].employees_skill_4;
        }
    
        if(REGION_FIRM_DATA.array[i].employees_skill_5 > 0)
        {
            REGION_FIRM_DATA.array[i].average_s_skill_5 =
            REGION_FIRM_DATA.array[i].average_s_skill_5/
            REGION_FIRM_DATA.array[i].employees_skill_5;
        }  
        
        if(REGION_FIRM_DATA.array[i].no_firms > 0)
        {
            REGION_FIRM_DATA.array[i].productivity_progress =
            REGION_FIRM_DATA.array[i].productivity_progress/
            REGION_FIRM_DATA.array[i].no_firms;
            
            REGION_FIRM_DATA.array[i].productivity =
            REGION_FIRM_DATA.array[i].productivity/
            REGION_FIRM_DATA.array[i].no_firms;
     
        }
    }
}

/* \fn: void Eurostat_compute_global_firm_data(void)
 * \brief: Function to compute global data that is related to firms.
 */
void Eurostat_compute_global_firm_data(void)
{   
    /*Create the GLOBAL data which is needed for controlling the results or sending 
     *         back to the Households*/
    
    /*********************WAGES****************/
    if(NO_EMPLOYEES > 0)
    {
        FIRM_AVERAGE_WAGE = FIRM_AVERAGE_WAGE/(double)NO_EMPLOYEES;
    }
    
    
    /*****************SPECIFIC_SKILLS******************/
    if(NO_EMPLOYEES > 0)
    {
        FIRM_AVERAGE_S_SKILL = FIRM_AVERAGE_S_SKILL/(double)NO_EMPLOYEES;
    }
    
    if(NO_EMPLOYEES_SKILL_1 > 0)
    {
        FIRM_AVERAGE_S_SKILL_1 = FIRM_AVERAGE_S_SKILL_1/
                    (double)NO_EMPLOYEES_SKILL_1;
    }
    
    if(NO_EMPLOYEES_SKILL_2 > 0)
    {
        FIRM_AVERAGE_S_SKILL_2 = FIRM_AVERAGE_S_SKILL_2/
                    (double)NO_EMPLOYEES_SKILL_2;
    }
    
    if(NO_EMPLOYEES_SKILL_3 > 0)
    {
        FIRM_AVERAGE_S_SKILL_3 = FIRM_AVERAGE_S_SKILL_3/
                    (double)NO_EMPLOYEES_SKILL_3;
    }
    
    if(NO_EMPLOYEES_SKILL_4 > 0)
    {
        FIRM_AVERAGE_S_SKILL_4 = FIRM_AVERAGE_S_SKILL_4/
                    (double)NO_EMPLOYEES_SKILL_4;
    }
    
    if(NO_EMPLOYEES_SKILL_5 > 0)
    {
        FIRM_AVERAGE_S_SKILL_5 = FIRM_AVERAGE_S_SKILL_5/
                    (double)NO_EMPLOYEES_SKILL_5;
    }
    
    if(NO_FIRMS > 0)
    {
        FIRM_AVERAGE_PRODUCTIVITY_PROGRESS = FIRM_AVERAGE_PRODUCTIVITY_PROGRESS/
        NO_FIRMS;
        
        FIRM_AVERAGE_PRODUCTIVITY = FIRM_AVERAGE_PRODUCTIVITY/NO_FIRMS;
        
    }
}


/* \fn: void Eurostat_read_household_data(void)
 * \brief: Function to read household_send_data_messages and store the global/region data of the households.
 */
void Eurostat_read_household_data(void)
{   
    int i;
    NUM_HOUSEHOLDS=0;
    
    EMPLOYED = 0;
    EMPLOYED_SKILL_1 = 0;
    EMPLOYED_SKILL_2 = 0;
    EMPLOYED_SKILL_3 = 0;
    EMPLOYED_SKILL_4 = 0;
    EMPLOYED_SKILL_5 = 0;
    UNEMPLOYED = 0;  
    
    AVERAGE_WAGE = 0.0;
    AVERAGE_WAGE_SKILL_1 = 0.0;
    AVERAGE_WAGE_SKILL_2 = 0.0;
    AVERAGE_WAGE_SKILL_3 = 0.0;
    AVERAGE_WAGE_SKILL_4 = 0.0;
    AVERAGE_WAGE_SKILL_5 = 0.0;

    AVERAGE_S_SKILL = 0.0;
    AVERAGE_S_SKILL_1 = 0.0;
    AVERAGE_S_SKILL_2 = 0.0;
    AVERAGE_S_SKILL_3 = 0.0;
    AVERAGE_S_SKILL_4 = 0.0;
    AVERAGE_S_SKILL_5 = 0.0;

    START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
    
        /*Store the global/region data of the households*/
        for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
        {
            if(household_send_data_message->region_id == 
            REGION_HOUSEHOLD_DATA.array[i].region_id)
            {
    
                //if(DAY == 20)
                //{
                    NUM_HOUSEHOLDS++;
                //}
                
    
                REGION_HOUSEHOLD_DATA.array[i].no_households++;
    
                REGION_HOUSEHOLD_DATA.array[i].average_wage +=
                household_send_data_message->wage;
                AVERAGE_WAGE = AVERAGE_WAGE + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill +=
                household_send_data_message->specific_skill;
                AVERAGE_S_SKILL = AVERAGE_S_SKILL + 
                household_send_data_message->specific_skill;
    
                /*(Region) data is subdivided by general skill level*/
                switch(household_send_data_message->general_skill)
                {  
                case 1:/*General skill level 1*/
                if(household_send_data_message->employment_status != -1)
                {
                    REGION_HOUSEHOLD_DATA.array[i].employed++;
                    REGION_HOUSEHOLD_DATA.array[i].employed_skill_1++;
                    EMPLOYED_SKILL_1++;
                    EMPLOYED++;
                }
                else
                {
                    REGION_HOUSEHOLD_DATA.array[i].unemployed++;
                    UNEMPLOYED++;
                }
    
                if(DAY == 20)
                {   
                    NO_HOUSEHOLDS_SKILL_1++;
                }
    
                REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1++;
    
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 =
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 +
                household_send_data_message->wage;
    
                AVERAGE_WAGE_SKILL_1 = AVERAGE_WAGE_SKILL_1 + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 =
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 +
                household_send_data_message->specific_skill;
    
                AVERAGE_S_SKILL_1 = AVERAGE_S_SKILL_1 + 
                household_send_data_message->specific_skill;
                break;
    
                case 2:/*General skill level 2*/
                if(household_send_data_message->employment_status != -1)
                {
                    REGION_HOUSEHOLD_DATA.array[i].employed++;
                    REGION_HOUSEHOLD_DATA.array[i].employed_skill_2++;
                    EMPLOYED_SKILL_2++;
                    EMPLOYED++;
                }
                else
                {
                    REGION_HOUSEHOLD_DATA.array[i].unemployed++;
                    UNEMPLOYED++;
                }       
        
                if(DAY == 20)
                {   
                    NO_HOUSEHOLDS_SKILL_2++;
                }
                
                REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2++;
                
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 =
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 +
                household_send_data_message->wage;
    
                AVERAGE_WAGE_SKILL_2 = AVERAGE_WAGE_SKILL_2 + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 =
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 +
                household_send_data_message->specific_skill;
    
                AVERAGE_S_SKILL_2 = AVERAGE_S_SKILL_2 + 
                household_send_data_message->specific_skill;
                break;
    
                case 3:/*General skill level 3*/
                if(household_send_data_message->employment_status != -1)
                {
                    REGION_HOUSEHOLD_DATA.array[i].employed++;
                    REGION_HOUSEHOLD_DATA.array[i].employed_skill_3++;
                    EMPLOYED_SKILL_3++;
                    EMPLOYED++;
                }
                else
                {
                    REGION_HOUSEHOLD_DATA.array[i].unemployed++;
                    UNEMPLOYED++;
                }
        
                if(DAY == 20)
                {
                    NO_HOUSEHOLDS_SKILL_3++;
                }
    
                REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3++;
    
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 =
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 +
                household_send_data_message->wage;
    
                AVERAGE_WAGE_SKILL_3 = AVERAGE_WAGE_SKILL_3 + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 =
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 +
                household_send_data_message->specific_skill;
    
                AVERAGE_S_SKILL_3 = AVERAGE_S_SKILL_3 + 
                household_send_data_message->specific_skill;
                break;
    
                case 4:/*General skill level 4*/
                if(household_send_data_message->employment_status != -1)
                {
                    REGION_HOUSEHOLD_DATA.array[i].employed++;
                    REGION_HOUSEHOLD_DATA.array[i].employed_skill_4++;
                    EMPLOYED_SKILL_4++;
                    EMPLOYED++;
                }
                else
                {
                    REGION_HOUSEHOLD_DATA.array[i].unemployed++;
                    UNEMPLOYED++;
                }
                
                if(DAY == 20)
                {
                    NO_HOUSEHOLDS_SKILL_4++;
                }
    
                REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4++;
    
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 =
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 +
                household_send_data_message->wage;
    
                AVERAGE_WAGE_SKILL_4 = AVERAGE_WAGE_SKILL_4 + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 =
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 +
                household_send_data_message->specific_skill;
    
                AVERAGE_S_SKILL_4 = AVERAGE_S_SKILL_4 + 
                household_send_data_message->specific_skill;
                break;
            
                case 5:/*General skill level 5*/
                if(household_send_data_message->employment_status != -1)
                {
                    REGION_HOUSEHOLD_DATA.array[i].employed++;
                    REGION_HOUSEHOLD_DATA.array[i].employed_skill_5++;
                    EMPLOYED_SKILL_5++;
                    EMPLOYED++;
                }
                else
                {
                    REGION_HOUSEHOLD_DATA.array[i].unemployed++;
                    UNEMPLOYED++;
                }
    
                if(DAY == 20)
                {
                    NO_HOUSEHOLDS_SKILL_5++;
                }
    
                REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5++;
    
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 =
                REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 +
                household_send_data_message->wage;
    
                AVERAGE_WAGE_SKILL_5 = AVERAGE_WAGE_SKILL_5 + 
                household_send_data_message->wage;
    
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 =
                REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 +
                household_send_data_message->specific_skill;
    
                AVERAGE_S_SKILL_5 = AVERAGE_S_SKILL_5 + 
                household_send_data_message->specific_skill;
                break;
                }
            }
        }
    FINISH_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP
}

/* \fn: void Eurostat_compute_region_household_data(void)
 * \brief: Function to create the region data related to Households.
 */
void Eurostat_compute_region_household_data(void)
{
    int i;
    
    /*Create the REGIONAL data which is needed for controlling the results or sending
     *            back to the Households*/
    for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
    {

        /**************UNEMPLOYMENT-RATE******************/
        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate = 
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households);

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_1 =
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_1/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1);

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_2 =
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_2/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2);

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_3 =
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_3/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3);

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_4 =
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_4/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4);

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_5 =
            100*(1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_5/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5);
    

    
        /*******************WAGES*************************/
        if(REGION_HOUSEHOLD_DATA.array[i].employed > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage/
            REGION_HOUSEHOLD_DATA.array[i].employed;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage = 0;
        }

        if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_1 > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1/
            REGION_HOUSEHOLD_DATA.array[i].employed_skill_1;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_1 = 0;
        }   

        if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_2 > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2/
            REGION_HOUSEHOLD_DATA.array[i].employed_skill_2;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_2 = 0;
        }

        if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_3 > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3/
            REGION_HOUSEHOLD_DATA.array[i].employed_skill_3;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_3 = 0;
        }

        if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_4 > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4/
            REGION_HOUSEHOLD_DATA.array[i].employed_skill_4;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_4 = 0;
        }

        if(REGION_HOUSEHOLD_DATA.array[i].employed_skill_5 > 0)
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 = 
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5/
            REGION_HOUSEHOLD_DATA.array[i].employed_skill_5;
        }
        else
        {
            REGION_HOUSEHOLD_DATA.array[i].average_wage_skill_5 = 0;
        }

        /*******************SPECIFIC SKILLS**********************/
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill = 
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill/
        REGION_HOUSEHOLD_DATA.array[i].no_households;

        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1 =
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1/
        REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1;

        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2 =
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2/
        REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2;

        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3 =
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3/
        REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3;

        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4 =
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4/
        REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4;
    
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5 =
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5/
        REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5;   
    }
}
    
/* \fn: void Eurostat_compute_global_household_data(void)
 * \brief: Function to compute the global macro data related to households.
 */
void Eurostat_compute_global_household_data(void)
{

    /*Create the GLOBAL data which is needed for controlling the results or sending         back to the Households*/
    
    /*******************UNEMPLOYMENT RATE**********************/
    UNEMPLOYMENT_RATE = 100*(1 - (double)EMPLOYED/(double)NUM_HOUSEHOLDS);
    UNEMPLOYMENT_RATE_SKILL_1 = 100*(1 - (double)EMPLOYED_SKILL_1/
                    (double)NO_HOUSEHOLDS_SKILL_1);
    UNEMPLOYMENT_RATE_SKILL_2 = 100*(1 - (double)EMPLOYED_SKILL_2/
                    (double)NO_HOUSEHOLDS_SKILL_2);
    UNEMPLOYMENT_RATE_SKILL_3 = 100*(1 - (double)EMPLOYED_SKILL_3/
                    (double)NO_HOUSEHOLDS_SKILL_3);
    UNEMPLOYMENT_RATE_SKILL_4 = 100*(1 - (double)EMPLOYED_SKILL_4/
                    (double)NO_HOUSEHOLDS_SKILL_4);
    UNEMPLOYMENT_RATE_SKILL_5 = 100*(1 - (double)EMPLOYED_SKILL_5/
                    (double)NO_HOUSEHOLDS_SKILL_5);
    
    
    /*******************WAGES**********************/
    
    if(EMPLOYED > 0)
    {
        AVERAGE_WAGE = AVERAGE_WAGE/(double)EMPLOYED;
    }
    else
    {
        AVERAGE_WAGE = 0;
    }
    
    if(EMPLOYED_SKILL_1 > 0)
    {
        AVERAGE_WAGE_SKILL_1 = AVERAGE_WAGE_SKILL_1/(double)EMPLOYED_SKILL_1;
    }
    else
    {
        AVERAGE_WAGE_SKILL_1 = 0;
    }
    
    if(EMPLOYED_SKILL_2 > 0)
    {
        AVERAGE_WAGE_SKILL_2 = AVERAGE_WAGE_SKILL_2/(double)EMPLOYED_SKILL_2;
    }
    else
    {
        AVERAGE_WAGE_SKILL_2 = 0;
    }
    
    if(EMPLOYED_SKILL_3 > 0)
    {
        AVERAGE_WAGE_SKILL_3 = AVERAGE_WAGE_SKILL_3/(double)EMPLOYED_SKILL_3;
    }
    else
    {
        AVERAGE_WAGE_SKILL_3 = 0;
    }
    
    if(EMPLOYED_SKILL_4 > 0)
    {
        AVERAGE_WAGE_SKILL_4 = AVERAGE_WAGE_SKILL_4/(double)EMPLOYED_SKILL_4;
    }
    else
    {
        AVERAGE_WAGE_SKILL_4 = 0;
    }
    
    if(EMPLOYED_SKILL_5 > 0)
    {
        AVERAGE_WAGE_SKILL_5 = AVERAGE_WAGE_SKILL_5/(double)EMPLOYED_SKILL_5;
    }
    else
    {
        AVERAGE_WAGE_SKILL_5 = 0;
    }
    
    
    /*******************SPECIFIC SKILLS**********************/
    AVERAGE_S_SKILL = AVERAGE_S_SKILL/(double)NUM_HOUSEHOLDS;
    AVERAGE_S_SKILL_1 = AVERAGE_S_SKILL_1/(double)NO_HOUSEHOLDS_SKILL_1;
    AVERAGE_S_SKILL_2 = AVERAGE_S_SKILL_2/(double)NO_HOUSEHOLDS_SKILL_2;
    AVERAGE_S_SKILL_3 = AVERAGE_S_SKILL_3/(double)NO_HOUSEHOLDS_SKILL_3;
    AVERAGE_S_SKILL_4 = AVERAGE_S_SKILL_4/(double)NO_HOUSEHOLDS_SKILL_4;
    AVERAGE_S_SKILL_5 = AVERAGE_S_SKILL_5/(double)NO_HOUSEHOLDS_SKILL_5;
}
    
/* \fn: void Eurostat_calc_macro_data(void)
 * \brief: Function to compute macro data from firm micro data.
 */
void Eurostat_calc_macro_data(void)
{
    int i;

    //Auxiliary sums:
    double sum_total_debt_earnings_ratios;
    double sum_total_debt_equity_ratios;
    double sum_total_labour_share_ratios;

    double sum_total_sold_quantity;
    double sum_total_output;
    double sum_total_cum_revenue;
    double sum_total_planned_output;
    
    double sum_region_debt_earnings_ratios;
    double sum_region_debt_equity_ratios;
    double sum_region_labour_share_ratios;
    
    double sum_region_sold_quantity;
    double sum_region_output;
    double sum_region_cum_revenue;
    double sum_region_planned_output;
        
    int counter_firms_in_region;
    
    GDP = 0.0;
    TOTAL_EARNINGS = 0.0;
    TOTAL_DEBT = 0.0;
    TOTAL_ASSETS = 0.0;
    TOTAL_EQUITY = 0.0;
    AVERAGE_DEBT_EARNINGS_RATIO = 0.0;
    AVERAGE_DEBT_EQUITY_RATIO = 0.0;
    LABOUR_SHARE_RATIO = 0.0;

    MONTHLY_SOLD_QUANTITY = 0.0;
    MONTHLY_OUTPUT = 0.0;
    MONTHLY_REVENUE = 0.0;
    MONTHLY_PLANNED_OUTPUT = 0.0;
    
    //Reset total economy sums: these are updated inside the message loop to sum across all firms
    sum_total_debt_earnings_ratios = 0.0;
    sum_total_debt_equity_ratios   = 0.0;
    sum_total_labour_share_ratios  = 0.0;
    sum_total_sold_quantity        = 0.0;
    sum_total_output               = 0.0;
    sum_total_cum_revenue          = 0.0;
    sum_total_planned_output       = 0.0;

    /*Store the region data of the firms*/
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
//      printf("\n Entering region %d", i+1);
        
        counter_firms_in_region =0;
        
        //Reset region sums: these are updated to sum across all firms in the region
        sum_region_debt_earnings_ratios = 0.0;
        sum_region_debt_equity_ratios   = 0.0;
        sum_region_labour_share_ratios  = 0.0;
        sum_region_sold_quantity        = 0.0;
        sum_region_output               = 0.0;
        sum_region_cum_revenue          = 0.0;
        sum_region_planned_output       = 0.0;

        //Reading loop
        START_FIRM_SEND_DATA_MESSAGE_LOOP
        if(firm_send_data_message->region_id == REGION_FIRM_DATA.array[i].region_id)
        {
            counter_firms_in_region++;

            /********sum of GDP: total consumption and investment costs++++++++*/
            REGION_FIRM_DATA.array[i].gdp += firm_send_data_message->cum_revenue + firm_send_data_message->capital_costs;
            GDP += firm_send_data_message->cum_revenue + firm_send_data_message->capital_costs;

            /********sum of net earnings of the firms++++++++*/
            REGION_FIRM_DATA.array[i].total_earnings += firm_send_data_message->net_earnings;
            TOTAL_EARNINGS += firm_send_data_message->net_earnings;
            
            
            /********sum of total debt of the firms++++++++*/
            REGION_FIRM_DATA.array[i].total_debt += firm_send_data_message->total_debt;
            TOTAL_DEBT += firm_send_data_message->total_debt;
            
            
            /********sum of total assets of the firms++++++++*/
            REGION_FIRM_DATA.array[i].total_assets += firm_send_data_message->total_assets;
            TOTAL_ASSETS += firm_send_data_message->total_assets;
            
            
            /********sum of total equity of the firms++++++++*/
            REGION_FIRM_DATA.array[i].total_equity += firm_send_data_message->equity;
            TOTAL_EQUITY += firm_send_data_message->equity;
            
            /***************** average debt/earnings ratio *********************/
            if (firm_send_data_message->net_earnings>0.0)
            {
                sum_region_debt_earnings_ratios += firm_send_data_message->total_debt/firm_send_data_message->net_earnings;
                sum_total_debt_earnings_ratios += firm_send_data_message->total_debt/firm_send_data_message->net_earnings;
            }
            
            /***************** average debt/equity ratio *********************/
            if (firm_send_data_message->equity>0.0)
            {
                sum_region_debt_equity_ratios += firm_send_data_message->total_debt/firm_send_data_message->equity;
                sum_total_debt_equity_ratios += firm_send_data_message->total_debt/firm_send_data_message->equity;
            }
            
            /***************** average labour share *********************/
            if (firm_send_data_message->net_earnings>0.0)
            {               
                sum_region_labour_share_ratios += firm_send_data_message->average_wage*firm_send_data_message->employees/firm_send_data_message->net_earnings;
                sum_total_labour_share_ratios += firm_send_data_message->average_wage*firm_send_data_message->employees/firm_send_data_message->net_earnings;
            }
            
            /***************** Sum of: total_sold_quantity *********************/
            sum_region_sold_quantity += firm_send_data_message->cum_total_sold_quantity;
            sum_total_sold_quantity  += firm_send_data_message->cum_total_sold_quantity;
    
            /***************** Sum of: output *********************/
            //printf("Eurostat reads output: %.2f", firm_send_data_message->output);
            sum_region_output += firm_send_data_message->output;
            sum_total_output  += firm_send_data_message->output;
            
            /***************** Sum of: cum_revenue *********************/                                 
            sum_region_cum_revenue += firm_send_data_message->cum_revenue;
            sum_total_cum_revenue  += firm_send_data_message->cum_revenue;
            
            /***************** Sum of: planned_output *********************/
            //printf("Eurostat reads planned_output: %.2f\n", firm_send_data_message->planned_output);
            sum_region_planned_output += firm_send_data_message->planned_output;
            sum_total_planned_output  += firm_send_data_message->planned_output;
            
        }
        FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
        
        //Compute regional averages after the regional-specific message loop
        REGION_FIRM_DATA.array[i].average_debt_earnings_ratio = sum_region_debt_earnings_ratios/counter_firms_in_region;
        REGION_FIRM_DATA.array[i].average_debt_equity_ratio = sum_region_debt_equity_ratios/counter_firms_in_region;
        REGION_FIRM_DATA.array[i].labour_share_ratio = sum_region_labour_share_ratios/counter_firms_in_region;
        
        REGION_FIRM_DATA.array[i].monthly_sold_quantity = sum_region_sold_quantity;
        REGION_FIRM_DATA.array[i].monthly_output = sum_region_output;
        REGION_FIRM_DATA.array[i].monthly_revenue = sum_region_cum_revenue;
        REGION_FIRM_DATA.array[i].monthly_planned_output = sum_region_planned_output;
    }
    
    //Compute total averages after the region for-loop
    AVERAGE_DEBT_EARNINGS_RATIO = sum_total_debt_earnings_ratios/NO_FIRMS;
    AVERAGE_DEBT_EQUITY_RATIO = sum_total_debt_equity_ratios/NO_FIRMS;
    LABOUR_SHARE_RATIO  = sum_total_labour_share_ratios/NO_FIRMS;

    MONTHLY_SOLD_QUANTITY = sum_total_sold_quantity;
    MONTHLY_OUTPUT = sum_total_output;
    MONTHLY_REVENUE = sum_total_cum_revenue;
    MONTHLY_PLANNED_OUTPUT = sum_total_planned_output;
}
    
/* \fn: void Eurostat_calc_firm_population(void)
 * \brief: Function to compute the firm population, number of new firm births and firm deaths.
 */
void Eurostat_calc_firm_population(void)
{
    int i;

    /* Reset the content of the memory variables*/
   // NO_FIRMS =0;
    NO_FIRM_BIRTHS=0;
    NO_FIRM_DEATHS=0;

    //Reset the age distribution, and store the previous distribution (needed to compute the 1-period survival rates)
    for (i=0;i<MAX_FIRM_AGE;i++)
    {
        FIRM_AGE_DISTRIBUTION_2_PERIOD_LAG[i]=FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i];
        FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i]=FIRM_AGE_DISTRIBUTION[i];
        FIRM_AGE_DISTRIBUTION[i]=0;
        SURVIVAL_RATE[i]=0.0;
    }
    
    /*Start reading loop*/
    START_FIRM_SEND_DATA_MESSAGE_LOOP
        /***************** Sum of: no_firm_births *********************/
        if (firm_send_data_message->age==1)
        {
            NO_FIRM_BIRTHS++;
            for(i = 0; i < REGION_FIRM_DATA.size; i++)
            {
                REGION_FIRM_DATA.array[i].no_firm_births++;
            }
        }
        
        /***************** Firm age distribution *********************/
        //add the firm's age to correct bin (we assume max. age is 60 months, all firms older than 60 are in the last bin)
        if (firm_send_data_message->age<MAX_FIRM_AGE)
        {
            FIRM_AGE_DISTRIBUTION[firm_send_data_message->age -1]++;
        }
        else
        {
            FIRM_AGE_DISTRIBUTION[MAX_FIRM_AGE-1]++;
        }
    FINISH_FIRM_SEND_DATA_MESSAGE_LOOP

    /***************** Sum of: no_firm_deaths *********************/
    //NO_FIRM_DEATHS = -1*(NO_FIRMS - HISTORY_MONTHLY[0].no_firms - NO_FIRM_BIRTHS);
    
    START_BANKRUPTCY_MESSAGE_LOOP
        NO_FIRM_DEATHS++;
    FINISH_BANKRUPTCY_MESSAGE_LOOP    
    
    //Compute firm demises in a region as follows:
    //F_t = F_{t-1} + B_t - D_t this gives the nr of firms alive in t, thus
    //D_t = F_{t-1} + B_t - F_t gives nr of firm deaths
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
        REGION_FIRM_DATA.array[i].no_firm_deaths = 
            HISTORY_MONTHLY[0].region_data.array[i].no_firms + REGION_FIRM_DATA.array[i].no_firm_births - REGION_FIRM_DATA.array[i].no_firms; 
    }
    
    /***************** Firm birth rate *********************/
    //Def: nr of newborn firms in period x / nr of firms in period x
    if(NO_FIRMS == 0) FIRM_BIRTH_RATE = 0.0;
    else FIRM_BIRTH_RATE = NO_FIRM_BIRTHS / NO_FIRMS;
        
    /***************** Firm death rate *********************/
    //Def: nr of firm demises in period x / nr of firms in period x
    if(NO_FIRMS == 0) 
        FIRM_DEATH_RATE = 0.0;
    else
        FIRM_DEATH_RATE = NO_FIRM_DEATHS / NO_FIRMS;
}

/* \fn: void Eurostat_calc_firm_survival_rates(void)
 * \brief: Function to compute the (monthly) survival rates.
 */
void Eurostat_calc_firm_survival_rates(void)
{
    int i,x,index, index2;
    

    /***************** Firm survival rate *********************/
    //Def: The survival rate after x years (or months) is the percentage of all enterprise births of year n which are still active in year n+x.
    //This is related to the age. We measure the age in months.
    //We need information on: the age distribution in the current period, and the age distribution in the previous period
    //Then we take into account that the demographics moves along the distribution from left to right.
    //For each age, we then define the survival rate as the percentage.

    //1-month survival rate
    //The survival rate for firms that in the previous period had an age in the range [0,59] months:
    for (i=0; i<MAX_FIRM_AGE; i++)
    {
        if(FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i]>0)
        {
            SURVIVAL_RATE[i]=
                FIRM_AGE_DISTRIBUTION[i+1]/FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i];
        }
        else
        {
            SURVIVAL_RATE[i]=0.0;
        }
    }
    

        /*********************************************
         * NEW FEATURE: Multi-period survival rates
         *********************************************/
        
        //Temporary code: should be double-indexed array
        //SURVIVAL_RATE_MULTIPERIOD_1[60]: 1-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD_2[60]: 2-period survival rate
    
        /******************************* 1-period survival rate code *******************************/
        if (PRINT_DEBUG)
        {
            fprintf(stdout,"Entering 1-period ahead survival rate: SURVIVAL_RATE_MULTIPERIOD_1\n");
        }
        x=0;
        for (i=0; i<60-x-1; i++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering element %d, using element %d of FIRM_AGE_DISTRIBUTION[%d] and comparing it to FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[%d]\n", i, i+x+1, i+x+1, i);}
            
            if(FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i]>0)
            {
                SURVIVAL_RATE_MULTIPERIOD_1[i]=
                    FIRM_AGE_DISTRIBUTION[i+x+1]/FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i];
            }
            else
            {
                SURVIVAL_RATE_MULTIPERIOD_1[i]=0.0;
            }
        }
        for (i=60-x-1; i<60; i++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering element %d, padding element %d of SURVIVAL_RATE_MULTIPERIOD with 0.0\n", i, i);}
            //padding
            SURVIVAL_RATE_MULTIPERIOD_1[i]=0.0;
        }

        /******************************* 2-period survival rate code *******************************/
        if (PRINT_DEBUG){fprintf(stdout,"Entering 2-period ahead survival rate: SURVIVAL_RATE_MULTIPERIOD_2\n");}
        x=1;
        for (i=0; i<60-x-1; i++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering element %d, using element %d of FIRM_AGE_DISTRIBUTION[%d] and comparing it to FIRM_AGE_DISTRIBUTION_2_PERIOD_LAG[%d]\n", i, i+x+1, i+x+1, i);}
            
            if(FIRM_AGE_DISTRIBUTION_2_PERIOD_LAG[i]>0)
            {
                SURVIVAL_RATE_MULTIPERIOD_2[i]=
                    FIRM_AGE_DISTRIBUTION[i+x+1]/FIRM_AGE_DISTRIBUTION_2_PERIOD_LAG[i];
            }
            else
            {
                SURVIVAL_RATE_MULTIPERIOD_2[i]=0.0;
            }
        }
        for (i=60-x-1; i<60; i++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering element %d, padding element %d of SURVIVAL_RATE_MULTIPERIOD with 0.0\n", i, i);}
            //padding
            SURVIVAL_RATE_MULTIPERIOD_2[i]=0.0;
        }

        /******************************* General survival rate code *******************************/
        //Generalized code for any x-period survival rate: we can set MAX_SURVIVAL_PERIODS (12)
        //For each period x, we need bins i = 0...59 FOR THE FIRM AGE: we can set MAX_FIRM_AGE (60)
        //SURVIVAL_RATE_MULTIPERIOD[0][]: 1-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[1][]: 2-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[x][]: x+1-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[11][]: 11+1=12-period survival rate

        //In model.xml we need to add these variables:
        // <variable><type>int</type><name>firm_age_distribution_multiperiod[12][60]</name><description>Multi-period firm_age_distributions.</description></variable>
        // <variable><type>double</type><name>survival_rate_multiperiod[12][60]</name><description>Multi-period survival rates. Definition: "The survival rate after x years is the percentage of all enterprise births of year n which are still active in year n+x." The 1st row survival_rate_multiperiod[0][.] equals survival_rate[], and contains the 1-period survival rates (for all age bins 0-59). The 2nd row survival_rate_multiperiod[1][.] contains the 2-period survival rates (for all age bins 0-59), etc.</description></variable>
        //Using matrix-to-array translation:
        // <variable><type>int</type><name>firm_age_distribution_multiperiod[MAX_SURVIVAL_PERIODS*MAX_FIRM_AGE]</name><description>Multi-period firm_age_distributions.</description></variable>
        // <variable><type>double</type><name>survival_rate_multiperiod[MAX_SURVIVAL_PERIODS*MAX_FIRM_AGE]</name><description>Multi-period survival rates. Definition: "The survival rate after x years is the percentage of all enterprise births of year n which are still active in year n+x." The 1st row survival_rate_multiperiod[0][.] equals survival_rate[], and contains the 1-period survival rates (for all age bins 0-59). The 2nd row survival_rate_multiperiod[1][.] contains the 2-period survival rates (for all age bins 0-59), etc.</description></variable>        
        
        /* SURVIVAL_RATE |  AGE_DISTRIBUTION    | Compare to old AGE_DISTRIBUTION
         *      [x][i]   | [x+1][i+x+1]         | [0][i]
         * ----------------------------------------------------------------------
         * x=0: [0][i]   |   [1][i+1]           | [0][i]  | 1-period
         * x=1: [1][i]   |   [2][i+2]           | [0][i]  | 2-period
         * x=2: [2][i]   |   [3][i+3]           | [0][i]  | 3-period
         * x=3: [3][i]   |   [4][i+4]           | [0][i]  | 4-period
         */
        
        for (x=0; x<MAX_SURVIVAL_PERIODS; x++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering row %d: %d-period ahead survival rate\n", x, x+1);}
            
            for (i=0; i<MAX_FIRM_AGE-x-1; i++)
            {
                if (PRINT_DEBUG){fprintf(stdout,"Entering element [%d][%d], using element %d of FIRM_AGE_DISTRIBUTION_MULTIPERIOD[%d][%d] and comparing it to FIRM_AGE_DISTRIBUTION_MULTIPERIOD[0][%d]\n", x, i, i+x+1, x+1, i+x+1, i);}
/*              
                if(FIRM_AGE_DISTRIBUTION_MULTIPERIOD[0][i]>0)
                {
                    SURVIVAL_RATE_MULTIPERIOD[x][i]=
                        FIRM_AGE_DISTRIBUTION_MULTIPERIOD[x+1][i+x+1]/FIRM_AGE_DISTRIBUTION_MULTIPERIOD[0][i];
                }
                else
                {
                    SURVIVAL_RATE_MULTIPERIOD[x][i]=0.0;
                }
*/
//Translation:                
                index = x*MAX_SURVIVAL_PERIODS+i;
                index2 =(x+1)*MAX_SURVIVAL_PERIODS+(i+x+1);
 
                if(FIRM_AGE_DISTRIBUTION_MULTIPERIOD[i]>0)
                {
                    SURVIVAL_RATE_MULTIPERIOD[index]=
                        FIRM_AGE_DISTRIBUTION_MULTIPERIOD[index2]/FIRM_AGE_DISTRIBUTION_MULTIPERIOD[i];
                }
                else
                {
                    SURVIVAL_RATE_MULTIPERIOD[index]=0.0;
                }            
            }
            
            for (i=MAX_FIRM_AGE-x-1; i<MAX_FIRM_AGE; i++)
            {
                if (PRINT_DEBUG){fprintf(stdout,"Entering element [%d][%d], padding element %d of SURVIVAL_RATE_MULTIPERIOD[%d][%d] with 0.0\n", x, i, i, x, i);}
                //padding
                //SURVIVAL_RATE_MULTIPERIOD[index]=0.0;

                //Translation:                
                index = x*MAX_SURVIVAL_PERIODS+i;
                SURVIVAL_RATE_MULTIPERIOD[index]=0.0;
            }
        }
        /******************************* end of general survival rate code *******************************/
        
}


/* \fn: void Eurostat_firm_creation(void)
 * \brief: The firm creation process
 */
void Eurostat_firm_creation(void)
{
    int i;
    double sum;
    int nr_new_firms;
    
    //The average 1-period survival rate of firms age 0-12 months: 
    sum=0.0;
    for (i=0; i<12; i++)
    {
        //sum += SURVIVAL_RATE_MULTIPERIOD[0][i];
        sum += SURVIVAL_RATE[i];
    }
    
    //Total number of new firms created is between 0 and MAX_FIRM_CREATION
    nr_new_firms = (int)MAX_FIRM_CREATION*sum/12;
    
    //add new firms
    printf("Adding new firms: %d", nr_new_firms);
    for (i=0; i<nr_new_firms; i++)
    {
        //new unique id
        //random activation day
        //some payment account?
        //some capital?
        
        //add_firm_agent();
    }

}

/* \fn: void Eurostat_measure_export(void)
 * \brief: Function to measure exports between regions.
 */
void Eurostat_measure_export(void)
{
    int i,j,index;
    
    //reset export matrix
    for (i=0; i<NO_REGIONS; i++)
    {
        REGION_EXPORT_VOLUME[i]=0.0;
        REGION_IMPORT_VOLUME[i]=0.0;
        REGION_EXPORT_VALUE[i]=0.0;
        REGION_IMPORT_VALUE[i]=0.0;
        REGION_IMPORT_PREVIOUS_VALUE[i]=0.0;
        
        for (j=0; j<NO_REGIONS; j++)
        {
            index=i*NO_REGIONS+j;
            EXPORT_VOLUME_MATRIX[index]=0.0;
            EXPORT_VALUE_MATRIX[index]=0.0;
            EXPORT_PREVIOUS_VALUE_MATRIX[index]=0.0;
        }
    }
    
    //read in all data from the malls
    START_MALL_DATA_MESSAGE_LOOP
        index = (mall_data_message->firm_region-1)*NO_REGIONS + (mall_data_message->household_region-1);        
        EXPORT_VOLUME_MATRIX[index] += mall_data_message->export_volume;
        EXPORT_VALUE_MATRIX[index] += mall_data_message->export_value;
        EXPORT_PREVIOUS_VALUE_MATRIX[index] += mall_data_message->export_previous_value;
    FINISH_MALL_DATA_MESSAGE_LOOP
    
    //sum total exports (row sum) and imports (column sum)
    for (i=0; i<NO_REGIONS; i++)
    {
        for (j=0; j<NO_REGIONS; j++)
        {
            if(i!=j)
            {
                index=i*NO_REGIONS+j;
                REGION_EXPORT_VOLUME[i] += EXPORT_VOLUME_MATRIX[index];
                REGION_IMPORT_VOLUME[j] += EXPORT_VOLUME_MATRIX[index];
                REGION_EXPORT_VALUE[i] += EXPORT_VALUE_MATRIX[index];
                REGION_IMPORT_VALUE[j] += EXPORT_VALUE_MATRIX[index];
                REGION_IMPORT_PREVIOUS_VALUE[j] += EXPORT_PREVIOUS_VALUE_MATRIX[index];
            }
        }
    }
                           
}


/*\fn: void Eurostat_calc_price_index(void)
 * \brief: Compute the regional CPI and the economy-wide CPI.
 * Q: MONTHLY_SOLD_QUANTITY: total quantity sold in economy
 * q: REGION_FIRM_DATA.array[i].monthly_sold_quantity: total quantity sold in region             
 * weight=q/Q
 * p: REGION_FIRM_DATA.array[i].cpi
 * p_previous = REGION_FIRM_DATA.array[i].cpi_last_month
 * sum_1= sum_regions(weight * p * q)
 * sum_2= sum_regions(weight * p_previous * q)
 * PRICE_INDEX =sum_1/sum2;
*/
void Eurostat_calc_price_index(void)
{
    int j, index;
    double weight, price, price_last_month, quantity, sum_1, sum_2;
    
    //Compute the regional CPI as the ratio between sum(p_t*q_t)/sum(p_t-1*q_t)
    //NOTE: we also need to include the diagonal value of the original export_value_matrix, which was excluded from the import/export sums.
    for (j=0; j<NO_REGIONS; j++)
    {    
        index=j*NO_REGIONS+j;
        REGION_FIRM_DATA.array[j].cpi_last_month = HISTORY_MONTHLY[0].region_data.array[j].cpi;
        REGION_FIRM_DATA.array[j].cpi = (REGION_IMPORT_VALUE[j]+EXPORT_VALUE_MATRIX[index])/(REGION_IMPORT_PREVIOUS_VALUE[j]+EXPORT_PREVIOUS_VALUE_MATRIX[index]);

        //printf("\n HISTORY_MONTHLY[0].region_data.array[%d].cpi = %f\n", j, HISTORY_MONTHLY[0].region_data.array[j].cpi);
        //printf("\n REGION_FIRM_DATA.array[%d].cpi = %f\n", j, REGION_FIRM_DATA.array[j].cpi);
        //printf("\n REGION_FIRM_DATA.array[%d].cpi_last_month = %f\n", j, REGION_FIRM_DATA.array[j].cpi_last_month);
    }                

    //Compute overall economy-wide price index: loop over regions
    sum_1 = 0.0;
    sum_2 = 0.0;
    for(j=0; j<REGION_FIRM_DATA.size; j++)
    {
        quantity = REGION_FIRM_DATA.array[j].monthly_sold_quantity;
        weight = quantity/MONTHLY_SOLD_QUANTITY;
        price = REGION_FIRM_DATA.array[j].cpi;
        price_last_month = REGION_FIRM_DATA.array[j].cpi_last_month;
        sum_1 += weight * price * quantity;
        sum_2 += weight * price_last_month * quantity;
    }
    
    CPI = sum_1/sum_2;
    
    if (PRINT_DEBUG)
    {
        fprintf(stdout,"\n Economy-wide CPI = %f\n", CPI);
    }
}

