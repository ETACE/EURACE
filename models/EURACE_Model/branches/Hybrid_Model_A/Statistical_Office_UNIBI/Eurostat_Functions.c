//#include <assert.h>
#include "../header.h"
#include "../Eurostat_agent_header.h"
#include "../my_library_header.h"
#include "Eurostat_aux_header.h"

/** \Eurostat_idle()
  */
int Eurostat_idle()
{
    return 0;   
}

/** \Eurostat_send_data_to_government()
 * \brief Eurostat send data: mean wage  ...
 */   
int Eurostat_send_data_to_government()
{
    int i, region;
    double gdp;
    
    //add message for each region
    for (i=0; i<NO_REGIONS; i++)
    {
        region = i+1;
        
        gdp = REGION_FIRM_DATA.array[region].gdp;
        
        printf("\n Region %d GDP=%2.2f\n", region, gdp);
        add_data_for_government_message(region, gdp, AVERAGE_WAGE);
    }
    
    return 0;
}

/** \Eurostat_send_data()
 * \brief Eurostat send data: specific skills ...
 */
int Eurostat_send_data()
{
    int i;   
    
    /*First of every month*/
    /*Send the data*/
    for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
    {
        add_eurostat_send_specific_skills_message(
        REGION_HOUSEHOLD_DATA.array[i].region_id,   
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_1, 
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_2,
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_3, 
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_4, 
        REGION_HOUSEHOLD_DATA.array[i].average_s_skill_5);
    }
    return 0;
}


/** \Eurostat_calculate_data
 * \brief Eurostat receive micro data and calculates macro data
 */
int Eurostat_calculate_data_old_version()
{
    int i,j,m;
        
    double sum_consumption_good_supply;

    EMPLOYED = 0;
    EMPLOYED_SKILL_1 = 0;
    EMPLOYED_SKILL_2 = 0;
    EMPLOYED_SKILL_3 = 0;
    EMPLOYED_SKILL_4 = 0;
    EMPLOYED_SKILL_5 = 0;
    UNEMPLOYED = 0;     

    UNEMPLOYMENT_RATE = 0.0;
    UNEMPLOYMENT_RATE_SKILL_1 = 0.0;
    UNEMPLOYMENT_RATE_SKILL_2 = 0.0;
    UNEMPLOYMENT_RATE_SKILL_3 = 0.0;
    UNEMPLOYMENT_RATE_SKILL_4 = 0.0;
    UNEMPLOYMENT_RATE_SKILL_5 = 0.0;

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
    
    PRICE_INDEX = 0.0;

    sum_consumption_good_supply    = 0.0;

    
    /*delete the content of the data arrays in order to store the data for the new month*/
    //free(REGION_HOUSEHOLD_DATA);
    //free(REGION_FIRM_DATA);
    
    //Remove all data arrays
    for(j = 0; j < REGION_FIRM_DATA.size; j++)
    {
        remove_firm_data(&REGION_FIRM_DATA, j);
        j--;
    }
    
    for(m = 0; m < REGION_HOUSEHOLD_DATA.size; m++)
    {
        remove_household_data(&REGION_HOUSEHOLD_DATA, m);
        m--;
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
                0.0,0.0,0.0,             //gdp, cpi, cpi_last_month 
                0,0);                    //no_firm_births, no_firm_deaths
        
        add_household_data(&REGION_HOUSEHOLD_DATA,
                i,
                0,0,0,0,0,0,
                0,0,0,0,0,0,
                0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,1.0,1.0,1.0,1.0,1.0);
    }
    
        /*Compute a weighted mean price*/
                
        START_FIRM_SEND_DATA_MESSAGE_LOOP
            sum_consumption_good_supply+= firm_send_data_message->total_supply;
        FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
                
        START_FIRM_SEND_DATA_MESSAGE_LOOP
            PRICE_INDEX += (firm_send_data_message->price*firm_send_data_message->total_supply)/ sum_consumption_good_supply;
        FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
        
        /*Store the region data of the firms*/
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
            }
            
            FINISH_FIRM_SEND_DATA_MESSAGE_LOOP

        }

    /*Create the REGIONAL data which is needed for controlling the results or sending
     *            back to the Firms*/
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

    }

    
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

    
    

    NUM_HOUSEHOLDS=0;

    START_HOUSEHOLD_SEND_DATA_MESSAGE_LOOP

        /*Store the global/region data of the households*/
        for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
        {
            if(household_send_data_message->region_id == 
            REGION_HOUSEHOLD_DATA.array[i].region_id)
            {

                //if(DAY == 19)
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

                if(DAY == 19)
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
        
                if(DAY == 19)
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
        
                if(DAY == 19)
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
                
                if(DAY == 19)
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
    
                if(DAY == 19)
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

    //printf("Eurostat_Functions: NUM_HOUSEHOLDS %d\n",NUM_HOUSEHOLDS);
    /*Create the REGIONAL data which is needed for controlling the results or sending           back to the Households*/
    for(i = 0; i < REGION_HOUSEHOLD_DATA.size; i++)
    {

        /**************UNEMPLOYMENT-RATE******************/
        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate = 
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households;

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_1 =
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_1/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_1;

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_2 =
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_2/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_2;

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_3 =
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_3/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_3;

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_4 =
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_4/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_4;

        REGION_HOUSEHOLD_DATA.array[i].unemployment_rate_skill_5 =
        1 - (double)REGION_HOUSEHOLD_DATA.array[i].employed_skill_5/
        (double)REGION_HOUSEHOLD_DATA.array[i].no_households_skill_5;
    

    
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



    /*Create the GLOBAL data which is needed for controlling the results or sending         back to the Households*/

    /*******************UNEMPLOYMENT RATE**********************/
    UNEMPLOYMENT_RATE = 1 - (double)EMPLOYED/(double)NUM_HOUSEHOLDS;
    UNEMPLOYMENT_RATE_SKILL_1 = 1 - (double)EMPLOYED_SKILL_1/
                    (double)NO_HOUSEHOLDS_SKILL_1;
    UNEMPLOYMENT_RATE_SKILL_2 = 1 - (double)EMPLOYED_SKILL_2/
                    (double)NO_HOUSEHOLDS_SKILL_2;
    UNEMPLOYMENT_RATE_SKILL_3 = 1 - (double)EMPLOYED_SKILL_3/
                    (double)NO_HOUSEHOLDS_SKILL_3;
    UNEMPLOYMENT_RATE_SKILL_4 = 1 - (double)EMPLOYED_SKILL_4/
                    (double)NO_HOUSEHOLDS_SKILL_4;
    UNEMPLOYMENT_RATE_SKILL_5 = 1 - (double)EMPLOYED_SKILL_5/
                    (double)NO_HOUSEHOLDS_SKILL_5;


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

    
    /*Execute auxiliary functions*/
    Eurostat_calc_macro_data();
    //Eurostat_calc_firm_population();
    //Eurostat_calc_firm_survival_rates();
    Eurostat_measure_export();
    Eurostat_calc_price_index();    
    
    return 0;
}

/** \fn Eurostat_calculate_data
 * \brief Eurostat receive micro data and calculates macro data
 */
int Eurostat_calculate_data()
{
    /* Eurostat auxiliary functions */
     Eurostat_reset_data();
     Eurostat_compute_mean_price();

     Eurostat_read_firm_data();
     Eurostat_compute_region_firm_data();
     Eurostat_compute_global_firm_data();

     Eurostat_read_household_data();
     Eurostat_compute_region_household_data();
     Eurostat_compute_global_household_data();

     Eurostat_calc_macro_data();
     Eurostat_calc_firm_population();
     Eurostat_calc_firm_survival_rates();
     Eurostat_measure_export();
     Eurostat_calc_price_index();    
    
    return 0;
}

/** \fn Eurostat_read_policy_announcements
 * \brief Eurostat receive micro data and calculates macro data
 */
int Eurostat_read_policy_announcements()
{
    int i;
    
    //Messages send by Government:
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP          
    for (i=0; i<27; i++)
    {
        if(policy_announcement_message->gov_id == GOVERNMENT_TAX_RATES[i].gov_id)
        {
            GOVERNMENT_TAX_RATES[i].tax_rate_corporate = policy_announcement_message->tax_rate_corporate;
            GOVERNMENT_TAX_RATES[i].tax_rate_hh_labour = policy_announcement_message->tax_rate_hh_labour;
            GOVERNMENT_TAX_RATES[i].tax_rate_hh_capital = policy_announcement_message->tax_rate_hh_capital;
            GOVERNMENT_TAX_RATES[i].tax_rate_vat = policy_announcement_message->tax_rate_vat;
            break;
        }
    }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    
    return 0;
}




/******************************* STORING MONTHLY DATA **************************************/
/* Datatype:

      struct history_item
      {
            double cpi;
            double gdp;
            double output;
            double employment;
            double unemployment_rate;
            double average_wage;    
       }

    //Static array of history items:
     history_item history_monthly[13];
     history_item history_quarterly[5];
    
    //Single history_items for storing the growth rates: 
    history_item monthly_growth_rates: month to month growth rate statistics
    history_item quarterly__growth_rates: quarter to quarter growth rate statistics
    history_item annual_growth_rates_monthly: annual growth rates (per month), measured as the percentage change over the same month in the previous year.
    history_item annual_growth_rates_quarterly: annual growth rates (per quarter), measured as the percentage change over the same quarter in the previous year.
*/

/* \fn: int Eurostat_store_history_monthly()
 * \brief: Central_Eurostat agent stores statistics to monthly history structure. 
 */
int Eurostat_store_history_monthly()
{   
    int i, region;
    region=0;
    
    //Shift history backwards
    /*
     * history_monthly[4].GDP = history_monthly[3].GDP;     //t-4 gets filled with value from t-3
     * history_monthly[3].GDP = history_monthly[2].GDP;     //t-3 gets filled with value from t-3
     * history_monthly[2].GDP = history_monthly[1].GDP;     //t-2 gets filled with value from t-2
     * history_monthly[1].GDP = history_monthly[0].GDP;     //t-1 gets filled with value from t-1
     * history_monthly[0].GDP = GDP;                        //t gets filled with value from t
     */

    //*********************************** Economy-wide data
    for (i=12; i>0; i--)
    {
      //t-i-1 gets filled with value from t-i
      HISTORY_MONTHLY[i].cpi = HISTORY_MONTHLY[i-1].cpi;
      HISTORY_MONTHLY[i].gdp = HISTORY_MONTHLY[i-1].gdp;
      HISTORY_MONTHLY[i].output = HISTORY_MONTHLY[i-1].output;
      HISTORY_MONTHLY[i].employment = HISTORY_MONTHLY[i-1].employment;
      HISTORY_MONTHLY[i].unemployment_rate = HISTORY_MONTHLY[i-1].unemployment_rate;
      HISTORY_MONTHLY[i].unemployment_rate_skill_1 = HISTORY_MONTHLY[i-1].unemployment_rate_skill_1;
      HISTORY_MONTHLY[i].unemployment_rate_skill_2 = HISTORY_MONTHLY[i-1].unemployment_rate_skill_2;
      HISTORY_MONTHLY[i].unemployment_rate_skill_3 = HISTORY_MONTHLY[i-1].unemployment_rate_skill_3;
      HISTORY_MONTHLY[i].unemployment_rate_skill_4 = HISTORY_MONTHLY[i-1].unemployment_rate_skill_4;
      HISTORY_MONTHLY[i].unemployment_rate_skill_5 = HISTORY_MONTHLY[i-1].unemployment_rate_skill_5;
      HISTORY_MONTHLY[i].average_wage = HISTORY_MONTHLY[i-1].average_wage;
      HISTORY_MONTHLY[i].no_firms = HISTORY_MONTHLY[i-1].no_firms;
      HISTORY_MONTHLY[i].no_firm_births = HISTORY_MONTHLY[i-1].no_firm_births;
      HISTORY_MONTHLY[i].no_firm_deaths = HISTORY_MONTHLY[i-1].no_firm_deaths;
    }
    
    //Store current value of history: [0] gets filled with current value
    HISTORY_MONTHLY[0].cpi = CPI;
    HISTORY_MONTHLY[0].gdp = GDP;                   
    HISTORY_MONTHLY[0].output = MONTHLY_OUTPUT;     
    HISTORY_MONTHLY[0].employment = EMPLOYED;       
    HISTORY_MONTHLY[0].unemployment_rate = UNEMPLOYMENT_RATE;
    HISTORY_MONTHLY[0].unemployment_rate_skill_1 = UNEMPLOYMENT_RATE_SKILL_1;
    HISTORY_MONTHLY[0].unemployment_rate_skill_2 = UNEMPLOYMENT_RATE_SKILL_2;
    HISTORY_MONTHLY[0].unemployment_rate_skill_3 = UNEMPLOYMENT_RATE_SKILL_3;
    HISTORY_MONTHLY[0].unemployment_rate_skill_4 = UNEMPLOYMENT_RATE_SKILL_4;
    HISTORY_MONTHLY[0].unemployment_rate_skill_5 = UNEMPLOYMENT_RATE_SKILL_5;
    HISTORY_MONTHLY[0].average_wage = FIRM_AVERAGE_WAGE;        
    HISTORY_MONTHLY[0].no_firms = NO_FIRMS;         
    HISTORY_MONTHLY[0].no_firm_births = NO_FIRM_BIRTHS; 
    HISTORY_MONTHLY[0].no_firm_deaths = NO_FIRM_DEATHS; 

    //*********************************** Code to be tested: region data

    for ( region=0; region<REGION_FIRM_DATA.size; region++)
    {
        //Shift history backwards
        for (i=12; i>0; i--)
        {
            HISTORY_MONTHLY[i].region_data.array[region].cpi = HISTORY_MONTHLY[i-1].region_data.array[region].cpi;
            HISTORY_MONTHLY[i].region_data.array[region].gdp = HISTORY_MONTHLY[i-1].region_data.array[region].gdp;
            HISTORY_MONTHLY[i].region_data.array[region].output = HISTORY_MONTHLY[i-1].region_data.array[region].output;
            HISTORY_MONTHLY[i].region_data.array[region].employment = HISTORY_MONTHLY[i-1].region_data.array[region].employment;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_1 = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate_skill_1;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_2 = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate_skill_2;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_3 = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate_skill_3;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_4 = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate_skill_4;
            HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_5 = HISTORY_MONTHLY[i-1].region_data.array[region].unemployment_rate_skill_5;
            HISTORY_MONTHLY[i].region_data.array[region].average_wage = HISTORY_MONTHLY[i-1].region_data.array[region].average_wage;
            HISTORY_MONTHLY[i].region_data.array[region].no_firms = HISTORY_MONTHLY[i-1].region_data.array[region].no_firms;
            HISTORY_MONTHLY[i].region_data.array[region].no_firm_births = HISTORY_MONTHLY[i-1].region_data.array[region].no_firm_births;
            HISTORY_MONTHLY[i].region_data.array[region].no_firm_deaths = HISTORY_MONTHLY[i-1].region_data.array[region].no_firm_deaths;
        }
        
        //Store current value of history
        HISTORY_MONTHLY[0].region_data.array[region].cpi = REGION_FIRM_DATA.array[region].cpi;
        HISTORY_MONTHLY[0].region_data.array[region].gdp = REGION_FIRM_DATA.array[region].gdp;                   
        HISTORY_MONTHLY[0].region_data.array[region].output = REGION_FIRM_DATA.array[region].monthly_output;
        HISTORY_MONTHLY[0].region_data.array[region].employment = REGION_FIRM_DATA.array[region].employees;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_1 = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate_skill_1;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_2 = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate_skill_2;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_3 = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate_skill_3;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_4 = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate_skill_4;
        HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_5 = REGION_HOUSEHOLD_DATA.array[region].unemployment_rate_skill_5;
        HISTORY_MONTHLY[0].region_data.array[region].average_wage = REGION_HOUSEHOLD_DATA.array[region].average_wage;
        HISTORY_MONTHLY[0].region_data.array[region].no_firms = REGION_FIRM_DATA.array[region].no_firms;
        HISTORY_MONTHLY[0].region_data.array[region].no_firm_births = REGION_FIRM_DATA.array[region].no_firm_births; 
        HISTORY_MONTHLY[0].region_data.array[region].no_firm_deaths = REGION_FIRM_DATA.array[region].no_firm_deaths;   
    }

    if (PRINT_LOG)
    {
        printf("Monthly data recorded by Eurostat:\n");
        printf(" - monthly CPI: %f\n", HISTORY_MONTHLY[0].cpi);
        printf(" - monthly GDP: %f\n", HISTORY_MONTHLY[0].gdp);
        printf(" - monthly output: %f\n", HISTORY_MONTHLY[0].output);
        printf(" - monthly average employment: %d\n", HISTORY_MONTHLY[0].employment);
        printf(" - monthly average unemployment rate: %f\n", HISTORY_MONTHLY[0].unemployment_rate);
        printf(" - monthly average unemployment rate_skill_1: %f\n", HISTORY_MONTHLY[0].unemployment_rate_skill_1);
        printf(" - monthly average unemployment rate_skill_2: %f\n", HISTORY_MONTHLY[0].unemployment_rate_skill_2);
        printf(" - monthly average unemployment rate_skill_3: %f\n", HISTORY_MONTHLY[0].unemployment_rate_skill_3);
        printf(" - monthly average unemployment rate_skill_4: %f\n", HISTORY_MONTHLY[0].unemployment_rate_skill_4);
        printf(" - monthly average unemployment rate_skill_5: %f\n", HISTORY_MONTHLY[0].unemployment_rate_skill_5);        
        printf(" - monthly average wage: %f\n", HISTORY_MONTHLY[0].average_wage);
        printf(" - monthly average number of firms: %d\n", HISTORY_MONTHLY[0].no_firms);
        printf(" - monthly total number of firm births: %d\n", HISTORY_MONTHLY[0].no_firm_births);
        printf(" - monthly total number of firm deaths: %d\n", HISTORY_MONTHLY[0].no_firm_deaths);
    }    
    
    return 0;
}

/******************************* STORING QUARTERLY DATA **************************************/
/* \fn: int Eurostat_store_history_quarterly()
 * \brief: Central_Eurostat agent stores statistics to quarterly history structure. 
 */
int Eurostat_store_history_quarterly()
{
    int i, region;
    region=0;
    
    //*********************************** Economy-wide data
    //Shift history backwards
    for (i=4; i>0; i--)
    {
      //t-i-1 gets filled with value from t-i
      HISTORY_QUARTERLY[i].cpi = HISTORY_QUARTERLY[i-1].cpi;
      HISTORY_QUARTERLY[i].gdp = HISTORY_QUARTERLY[i-1].gdp;
      HISTORY_QUARTERLY[i].output = HISTORY_QUARTERLY[i-1].output;
      HISTORY_QUARTERLY[i].employment = HISTORY_QUARTERLY[i-1].employment;      
      HISTORY_QUARTERLY[i].unemployment_rate = HISTORY_QUARTERLY[i-1].unemployment_rate;
      HISTORY_QUARTERLY[i].unemployment_rate_skill_1 = HISTORY_QUARTERLY[i-1].unemployment_rate_skill_1;
      HISTORY_QUARTERLY[i].unemployment_rate_skill_2 = HISTORY_QUARTERLY[i-1].unemployment_rate_skill_2;
      HISTORY_QUARTERLY[i].unemployment_rate_skill_3 = HISTORY_QUARTERLY[i-1].unemployment_rate_skill_3;
      HISTORY_QUARTERLY[i].unemployment_rate_skill_4 = HISTORY_QUARTERLY[i-1].unemployment_rate_skill_4;
      HISTORY_QUARTERLY[i].unemployment_rate_skill_5 = HISTORY_QUARTERLY[i-1].unemployment_rate_skill_5;
      HISTORY_QUARTERLY[i].average_wage = HISTORY_QUARTERLY[i-1].average_wage;
      HISTORY_QUARTERLY[i].no_firms = HISTORY_QUARTERLY[i-1].no_firms;
      HISTORY_QUARTERLY[i].no_firm_births = HISTORY_QUARTERLY[i-1].no_firm_births;
      HISTORY_QUARTERLY[i].no_firm_deaths = HISTORY_QUARTERLY[i-1].no_firm_deaths;
    }
        
    //Reset first elements for sum
    HISTORY_QUARTERLY[0].cpi=1.0;
    HISTORY_QUARTERLY[0].gdp=0.0;
    HISTORY_QUARTERLY[0].output=0.0;
    HISTORY_QUARTERLY[0].employment=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_1=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_2=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_3=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_4=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_5=0.0;    
    HISTORY_QUARTERLY[0].average_wage=0.0;
    HISTORY_QUARTERLY[0].no_firms=0;
    HISTORY_QUARTERLY[0].no_firm_births=0;
    HISTORY_QUARTERLY[0].no_firm_deaths=0;
    
    //Store first value: construct quarterly sums from monthly history
    for (i=0; i<3; i++)
    {
        HISTORY_QUARTERLY[0].cpi                *= HISTORY_MONTHLY[i].cpi;
        HISTORY_QUARTERLY[0].gdp                += HISTORY_MONTHLY[i].gdp;
        HISTORY_QUARTERLY[0].output             += HISTORY_MONTHLY[i].output;
        HISTORY_QUARTERLY[0].employment         += HISTORY_MONTHLY[i].employment;        
        HISTORY_QUARTERLY[0].unemployment_rate  += HISTORY_MONTHLY[i].unemployment_rate;
        HISTORY_QUARTERLY[0].unemployment_rate_skill_1  += HISTORY_MONTHLY[i].unemployment_rate_skill_1;
        HISTORY_QUARTERLY[0].unemployment_rate_skill_2  += HISTORY_MONTHLY[i].unemployment_rate_skill_2;
        HISTORY_QUARTERLY[0].unemployment_rate_skill_3  += HISTORY_MONTHLY[i].unemployment_rate_skill_3;
        HISTORY_QUARTERLY[0].unemployment_rate_skill_4  += HISTORY_MONTHLY[i].unemployment_rate_skill_4;
        HISTORY_QUARTERLY[0].unemployment_rate_skill_5  += HISTORY_MONTHLY[i].unemployment_rate_skill_5;
        HISTORY_QUARTERLY[0].average_wage       += HISTORY_MONTHLY[i].average_wage;
        HISTORY_QUARTERLY[0].no_firms           += HISTORY_MONTHLY[i].no_firms;
        HISTORY_QUARTERLY[0].no_firm_births     += HISTORY_MONTHLY[i].no_firm_births;
        HISTORY_QUARTERLY[0].no_firm_deaths     += HISTORY_MONTHLY[i].no_firm_deaths;
    }
    //The following quarterly statistics are averages of monthly statistics
    //HISTORY_QUARTERLY[0].cpi                    = HISTORY_QUARTERLY[0].cpi/3;
    HISTORY_QUARTERLY[0].gdp                    = HISTORY_QUARTERLY[0].gdp;
    HISTORY_QUARTERLY[0].output                 = HISTORY_QUARTERLY[0].output;
    HISTORY_QUARTERLY[0].employment             = HISTORY_QUARTERLY[0].employment/3;
    HISTORY_QUARTERLY[0].unemployment_rate      = HISTORY_QUARTERLY[0].unemployment_rate/3;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_1 = HISTORY_QUARTERLY[0].unemployment_rate_skill_1/3;    
    HISTORY_QUARTERLY[0].unemployment_rate_skill_2 = HISTORY_QUARTERLY[0].unemployment_rate_skill_2/3;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_3 = HISTORY_QUARTERLY[0].unemployment_rate_skill_3/3;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_4 = HISTORY_QUARTERLY[0].unemployment_rate_skill_4/3;
    HISTORY_QUARTERLY[0].unemployment_rate_skill_5 = HISTORY_QUARTERLY[0].unemployment_rate_skill_5/3;
    HISTORY_QUARTERLY[0].average_wage           = HISTORY_QUARTERLY[0].average_wage/3;
    HISTORY_QUARTERLY[0].no_firms               = HISTORY_QUARTERLY[0].no_firms/3;
    HISTORY_QUARTERLY[0].no_firm_births         = HISTORY_QUARTERLY[0].no_firm_births;
    HISTORY_QUARTERLY[0].no_firm_deaths         = HISTORY_QUARTERLY[0].no_firm_deaths;
    
    //*********************************** Code to be tested: region data

    for ( region=0; region<REGION_FIRM_DATA.size; region++)
    {
        //Shift history backwards
        for (i=4; i>0; i--)
        {
            HISTORY_QUARTERLY[i].region_data.array[region].cpi = HISTORY_QUARTERLY[i-1].region_data.array[region].cpi;
            HISTORY_QUARTERLY[i].region_data.array[region].gdp = HISTORY_QUARTERLY[i-1].region_data.array[region].gdp;
            HISTORY_QUARTERLY[i].region_data.array[region].output = HISTORY_QUARTERLY[i-1].region_data.array[region].output;
            HISTORY_QUARTERLY[i].region_data.array[region].employment = HISTORY_QUARTERLY[i-1].region_data.array[region].employment;      
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate;
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate_skill_1 = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate_skill_1;
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate_skill_2 = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate_skill_2;
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate_skill_3 = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate_skill_3;
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate_skill_4 = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate_skill_4;
            HISTORY_QUARTERLY[i].region_data.array[region].unemployment_rate_skill_5 = HISTORY_QUARTERLY[i-1].region_data.array[region].unemployment_rate_skill_5;
            HISTORY_QUARTERLY[i].region_data.array[region].average_wage = HISTORY_QUARTERLY[i-1].region_data.array[region].average_wage;
            HISTORY_QUARTERLY[i].region_data.array[region].no_firms = HISTORY_QUARTERLY[i-1].region_data.array[region].no_firms;
            HISTORY_QUARTERLY[i].region_data.array[region].no_firm_births = HISTORY_QUARTERLY[i-1].region_data.array[region].no_firm_births;
            HISTORY_QUARTERLY[i].region_data.array[region].no_firm_deaths = HISTORY_QUARTERLY[i-1].region_data.array[region].no_firm_deaths;
        }

        //Reset first elements for sum
        HISTORY_QUARTERLY[0].region_data.array[region].cpi=1.0;
        HISTORY_QUARTERLY[0].region_data.array[region].gdp=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].output=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].employment=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5=0.0;    
        HISTORY_QUARTERLY[0].region_data.array[region].average_wage=0.0;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firms=0;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births=0;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths=0;

        //Store first value: construct quarterly sums from monthly history
        for (i=0; i<3; i++)
        {
            HISTORY_QUARTERLY[0].region_data.array[region].cpi                *= HISTORY_MONTHLY[i].region_data.array[region].cpi;
            HISTORY_QUARTERLY[0].region_data.array[region].gdp                += HISTORY_MONTHLY[i].region_data.array[region].gdp;
            HISTORY_QUARTERLY[0].region_data.array[region].output             += HISTORY_MONTHLY[i].region_data.array[region].output;
            HISTORY_QUARTERLY[0].region_data.array[region].employment         += HISTORY_MONTHLY[i].region_data.array[region].employment;        
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate;
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_1;
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_2;
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_3;
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_4;
            HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5  += HISTORY_MONTHLY[i].region_data.array[region].unemployment_rate_skill_5;
            HISTORY_QUARTERLY[0].region_data.array[region].average_wage       += HISTORY_MONTHLY[i].region_data.array[region].average_wage;
            HISTORY_QUARTERLY[0].region_data.array[region].no_firms           += HISTORY_MONTHLY[i].region_data.array[region].no_firms;
            HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births     += HISTORY_MONTHLY[i].region_data.array[region].no_firm_births;
            HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths     += HISTORY_MONTHLY[i].region_data.array[region].no_firm_deaths;           
        }
        
        //The following quarterly statistics are averages of monthly statistics
        //HISTORY_QUARTERLY[0].region_data.array[region].cpi                    = HISTORY_QUARTERLY[0].region_data.array[region].cpi/3;
        HISTORY_QUARTERLY[0].region_data.array[region].gdp                    = HISTORY_QUARTERLY[0].region_data.array[region].gdp;
        HISTORY_QUARTERLY[0].region_data.array[region].output                 = HISTORY_QUARTERLY[0].region_data.array[region].output;        
        HISTORY_QUARTERLY[0].region_data.array[region].employment             = HISTORY_QUARTERLY[0].region_data.array[region].employment/3;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate      = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate/3;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1 = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1/3;    
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2 = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2/3;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3 = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3/3;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4 = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4/3;
        HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5 = HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5/3;
        HISTORY_QUARTERLY[0].region_data.array[region].average_wage           = HISTORY_QUARTERLY[0].region_data.array[region].average_wage/3;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firms               = HISTORY_QUARTERLY[0].region_data.array[region].no_firms/3;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births         = HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births;
        HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths         = HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths;    
    }

    if (PRINT_LOG)
    {
        printf("Quarterly data recorded by Eurostat:\n");
        printf(" - quarterly CPI: %f\n", HISTORY_QUARTERLY[0].cpi);
        printf(" - quarterly GDP: %f\n", HISTORY_QUARTERLY[0].gdp);
        printf(" - quarterly output: %f\n", HISTORY_QUARTERLY[0].output);
        printf(" - quarterly average employment: %d\n", HISTORY_QUARTERLY[0].employment);
        printf(" - quarterly average unemployment rate: %f\n", HISTORY_QUARTERLY[0].unemployment_rate);
        printf(" - quarterly average wage: %f\n", HISTORY_QUARTERLY[0].average_wage);
        printf(" - quarterly average number of firms: %d\n", HISTORY_QUARTERLY[0].no_firms);
        printf(" - quarterly total number of firm births: %d\n", HISTORY_QUARTERLY[0].no_firm_births);
        printf(" - quarterly total number of firm deaths: %d\n", HISTORY_QUARTERLY[0].no_firm_deaths);
    }
    
    return 0;
}


/************ Computation ********************************/
/* \fn: int Eurostat_compute_growth_rates_monthly()
 * \brief: Computes rates of change from the current history at the end of every month.
 */
int Eurostat_compute_growth_rates_monthly()
{
    int i,region;
    region=0;

    //*********************************** Economy-wide data
    MONTHLY_GROWTH_RATES.cpi                       = 1.0;
    MONTHLY_GROWTH_RATES.gdp                       = 0.0; 
    MONTHLY_GROWTH_RATES.output                    = 0.0;
    MONTHLY_GROWTH_RATES.employment                = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate         = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate_skill_1         = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate_skill_2         = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate_skill_3         = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate_skill_4         = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate_skill_5         = 0.0;
    MONTHLY_GROWTH_RATES.average_wage                      = 0.0;
    MONTHLY_GROWTH_RATES.no_firms                  = 0.0;
    MONTHLY_GROWTH_RATES.no_firm_births            = 0.0;
    MONTHLY_GROWTH_RATES.no_firm_deaths            = 0.0;
    
    ANNUAL_GROWTH_RATES_MONTHLY.cpi                = 1.0;           //CPI: compounded inflation rate in pct over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.gdp                = 0.0;           //GDP: percentage change in GDP over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.output             = 0.0;           //percentage change in output over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.employment         = 0.0;           //percentage change in total employment over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate  = 0.0;           //percentage change in unemployment_rate over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_1  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_2  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_3  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_4  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_5  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.average_wage               = 0.0;   //percentage change in average_wage over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.no_firms           = 0.0;           //percentage change in no_firms over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.no_firm_births     = 0.0;           //percentage change in no_firm_births over last 12 months
    ANNUAL_GROWTH_RATES_MONTHLY.no_firm_deaths     = 0.0;           //percentage change in no_firm_deaths over last 12 months
    
    //compute monthly rates of change: change over the previous month
    if(HISTORY_MONTHLY[1].cpi>0.0)              {MONTHLY_GROWTH_RATES.cpi                       = (HISTORY_MONTHLY[0].cpi-1)*100;}
    if(HISTORY_MONTHLY[1].gdp>0.0)              {MONTHLY_GROWTH_RATES.gdp                       = (HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[1].gdp -1)*100;}
    if(HISTORY_MONTHLY[1].output>0.0)           {MONTHLY_GROWTH_RATES.output                    = (HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[1].output  -1)*100;}
    if(HISTORY_MONTHLY[1].employment>0)         {MONTHLY_GROWTH_RATES.employment                = (HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[1].employment  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate>0.0){MONTHLY_GROWTH_RATES.unemployment_rate         = (HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[1].unemployment_rate  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate_skill_1>0.0){MONTHLY_GROWTH_RATES.unemployment_rate_skill_1         = (HISTORY_MONTHLY[0].unemployment_rate_skill_1 / HISTORY_MONTHLY[1].unemployment_rate_skill_1  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate_skill_2>0.0){MONTHLY_GROWTH_RATES.unemployment_rate_skill_2         = (HISTORY_MONTHLY[0].unemployment_rate_skill_2 / HISTORY_MONTHLY[1].unemployment_rate_skill_2  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate_skill_3>0.0){MONTHLY_GROWTH_RATES.unemployment_rate_skill_3         = (HISTORY_MONTHLY[0].unemployment_rate_skill_3 / HISTORY_MONTHLY[1].unemployment_rate_skill_3  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate_skill_4>0.0){MONTHLY_GROWTH_RATES.unemployment_rate_skill_4         = (HISTORY_MONTHLY[0].unemployment_rate_skill_4 / HISTORY_MONTHLY[1].unemployment_rate_skill_4  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate_skill_5>0.0){MONTHLY_GROWTH_RATES.unemployment_rate_skill_5         = (HISTORY_MONTHLY[0].unemployment_rate_skill_5 / HISTORY_MONTHLY[1].unemployment_rate_skill_5  -1)*100;}
    if(HISTORY_MONTHLY[1].average_wage>0.0)     {MONTHLY_GROWTH_RATES.average_wage              = (HISTORY_MONTHLY[0].average_wage / HISTORY_MONTHLY[1].average_wage  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firms>0)           {MONTHLY_GROWTH_RATES.no_firms                  = (HISTORY_MONTHLY[0].no_firms / HISTORY_MONTHLY[1].no_firms  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firm_births>0)     {MONTHLY_GROWTH_RATES.no_firm_births            = (HISTORY_MONTHLY[0].no_firm_births / HISTORY_MONTHLY[1].no_firm_births  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firm_deaths>0)     {MONTHLY_GROWTH_RATES.no_firm_deaths            = (HISTORY_MONTHLY[0].no_firm_deaths / HISTORY_MONTHLY[1].no_firm_deaths  -1)*100;}   

    //compute annual rate of change of CPI: compounded inflation rate over the previous 12 months
    for (i=0; i<12; i++)
    {
        ANNUAL_GROWTH_RATES_MONTHLY.cpi *= HISTORY_MONTHLY[i].cpi;
    }
    ANNUAL_GROWTH_RATES_MONTHLY.cpi = (ANNUAL_GROWTH_RATES_MONTHLY.cpi-1)*100;
    
    //compute annual rates of change over the previous 12 months: respective to same month in previous year
    if(HISTORY_MONTHLY[12].gdp>0.0)             {ANNUAL_GROWTH_RATES_MONTHLY.gdp                = (HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[12].gdp  -1)*100;}
    if(HISTORY_MONTHLY[12].output>0.0)          {ANNUAL_GROWTH_RATES_MONTHLY.output             = (HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[12].output  -1)*100;}
    if(HISTORY_MONTHLY[12].employment>0)        {ANNUAL_GROWTH_RATES_MONTHLY.employment         = (HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[12].employment  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate  = (HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[12].unemployment_rate  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate_skill_1>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_1  = (HISTORY_MONTHLY[0].unemployment_rate_skill_1 / HISTORY_MONTHLY[12].unemployment_rate_skill_1  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate_skill_2>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_2  = (HISTORY_MONTHLY[0].unemployment_rate_skill_2 / HISTORY_MONTHLY[12].unemployment_rate_skill_2  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate_skill_3>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_3  = (HISTORY_MONTHLY[0].unemployment_rate_skill_3 / HISTORY_MONTHLY[12].unemployment_rate_skill_3  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate_skill_4>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_4  = (HISTORY_MONTHLY[0].unemployment_rate_skill_4 / HISTORY_MONTHLY[12].unemployment_rate_skill_4  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate_skill_5>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate_skill_5  = (HISTORY_MONTHLY[0].unemployment_rate_skill_5 / HISTORY_MONTHLY[12].unemployment_rate_skill_5  -1)*100;}
    if(HISTORY_MONTHLY[12].average_wage>0)      {ANNUAL_GROWTH_RATES_MONTHLY.average_wage       = (HISTORY_MONTHLY[0].average_wage / HISTORY_MONTHLY[12].average_wage  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firms>0)          {ANNUAL_GROWTH_RATES_MONTHLY.no_firms           = (HISTORY_MONTHLY[0].no_firms / HISTORY_MONTHLY[12].no_firms  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firm_births>0)    {ANNUAL_GROWTH_RATES_MONTHLY.no_firm_births     = (HISTORY_MONTHLY[0].no_firm_births / HISTORY_MONTHLY[12].no_firm_births  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firm_deaths>0)    {ANNUAL_GROWTH_RATES_MONTHLY.no_firm_deaths     = (HISTORY_MONTHLY[0].no_firm_deaths / HISTORY_MONTHLY[12].no_firm_deaths  -1)*100;}

    
    //*********************************** Code to be tested: region data
    
    for ( region=0; region<REGION_FIRM_DATA.size; region++)
    {
        MONTHLY_GROWTH_RATES.region_data.array[region].cpi                       = 1.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].gdp                       = 0.0; 
        MONTHLY_GROWTH_RATES.region_data.array[region].output                    = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].employment                = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate         = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_1 = 0.0;        
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_2 = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_3 = 0.0;        
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_4 = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_5 = 0.0;        
        MONTHLY_GROWTH_RATES.region_data.array[region].average_wage              = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].no_firms                  = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].no_firm_births            = 0.0;
        MONTHLY_GROWTH_RATES.region_data.array[region].no_firm_deaths            = 0.0;
        
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].cpi                = 1.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].gdp                = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].output             = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].employment         = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_1  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_2  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_3  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_4  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_5  = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].average_wage       = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firms           = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firm_births     = 0.0;
        ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firm_deaths     = 0.0;
        
        //compute monthly rates of change: change over the previous month
        if(HISTORY_MONTHLY[1].region_data.array[region].cpi>0.0)              {MONTHLY_GROWTH_RATES.region_data.array[region].cpi                       = (HISTORY_MONTHLY[0].region_data.array[region].cpi-1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].gdp>0.0)              {MONTHLY_GROWTH_RATES.region_data.array[region].gdp                       = (HISTORY_MONTHLY[0].region_data.array[region].gdp / HISTORY_MONTHLY[1].region_data.array[region].gdp -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].output>0.0)           {MONTHLY_GROWTH_RATES.region_data.array[region].output                    = (HISTORY_MONTHLY[0].region_data.array[region].output / HISTORY_MONTHLY[1].region_data.array[region].output  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].employment>0)         {MONTHLY_GROWTH_RATES.region_data.array[region].employment                = (HISTORY_MONTHLY[0].region_data.array[region].employment / HISTORY_MONTHLY[1].region_data.array[region].employment  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate         = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_1>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_1 = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_1 / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_1  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_2>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_2 = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_2 / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_2  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_3>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_3 = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_3 / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_3  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_4>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_4 = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_4 / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_4  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_5>0.0){MONTHLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_5 = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_5 / HISTORY_MONTHLY[1].region_data.array[region].unemployment_rate_skill_5  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].average_wage>0.0)     {MONTHLY_GROWTH_RATES.region_data.array[region].average_wage              = (HISTORY_MONTHLY[0].region_data.array[region].average_wage / HISTORY_MONTHLY[1].region_data.array[region].average_wage  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].no_firms>0)           {MONTHLY_GROWTH_RATES.region_data.array[region].no_firms                  = (HISTORY_MONTHLY[0].region_data.array[region].no_firms / HISTORY_MONTHLY[1].region_data.array[region].no_firms  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].no_firm_births>0)     {MONTHLY_GROWTH_RATES.region_data.array[region].no_firm_births            = (HISTORY_MONTHLY[0].region_data.array[region].no_firm_births / HISTORY_MONTHLY[1].region_data.array[region].no_firm_births  -1)*100;}
        if(HISTORY_MONTHLY[1].region_data.array[region].no_firm_deaths>0)     {MONTHLY_GROWTH_RATES.region_data.array[region].no_firm_deaths            = (HISTORY_MONTHLY[0].region_data.array[region].no_firm_deaths / HISTORY_MONTHLY[1].region_data.array[region].no_firm_deaths  -1)*100;}   
        
        //compute annual rate of change of CPI: compounded inflation rate over the previous 12 months
         for (i=0; i<12; i++)
         {
            ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].cpi *= HISTORY_MONTHLY[i].region_data.array[region].cpi;
         }
         ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].cpi = (ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].cpi-1)*100;

        //compute annual rates of change over the previous 12 months: respective to same month in previous year
        if(HISTORY_MONTHLY[12].region_data.array[region].gdp>0.0)             {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].gdp                = (HISTORY_MONTHLY[0].region_data.array[region].gdp / HISTORY_MONTHLY[12].region_data.array[region].gdp  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].output>0.0)          {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].output             = (HISTORY_MONTHLY[0].region_data.array[region].output / HISTORY_MONTHLY[12].region_data.array[region].output  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].employment>0)        {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].employment         = (HISTORY_MONTHLY[0].region_data.array[region].employment / HISTORY_MONTHLY[12].region_data.array[region].employment  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_1>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_1  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_1 / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_1  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_2>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_2  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_2 / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_2  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_3>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_3  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_3 / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_3  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_4>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_4  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_4 / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_4  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_5>0) {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].unemployment_rate_skill_5  = (HISTORY_MONTHLY[0].region_data.array[region].unemployment_rate_skill_5 / HISTORY_MONTHLY[12].region_data.array[region].unemployment_rate_skill_5  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].average_wage>0)      {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].average_wage       = (HISTORY_MONTHLY[0].region_data.array[region].average_wage / HISTORY_MONTHLY[12].region_data.array[region].average_wage  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].no_firms>0)          {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firms           = (HISTORY_MONTHLY[0].region_data.array[region].no_firms / HISTORY_MONTHLY[12].region_data.array[region].no_firms  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].no_firm_births>0)    {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firm_births     = (HISTORY_MONTHLY[0].region_data.array[region].no_firm_births / HISTORY_MONTHLY[12].region_data.array[region].no_firm_births  -1)*100;}
        if(HISTORY_MONTHLY[12].region_data.array[region].no_firm_deaths>0)    {ANNUAL_GROWTH_RATES_MONTHLY.region_data.array[region].no_firm_deaths     = (HISTORY_MONTHLY[0].region_data.array[region].no_firm_deaths / HISTORY_MONTHLY[12].region_data.array[region].no_firm_deaths  -1)*100;}
    }

    
    return 0;
}

/* \fn: int Eurostat_compute_growth_rates_quarterly()
 * \brief: Computes rates of change from the current history at the end of every quarterly.
 */
int Eurostat_compute_growth_rates_quarterly()
{
    int i,region;
    region=0;
    
    //*********************************** Economy-wide data
    QUARTERLY_GROWTH_RATES.cpi                         = 1.0;
    QUARTERLY_GROWTH_RATES.gdp                         = 0.0;
    QUARTERLY_GROWTH_RATES.output                      = 0.0;
    QUARTERLY_GROWTH_RATES.employment                  = 0.0;
    QUARTERLY_GROWTH_RATES.unemployment_rate           = 0.0;
    QUARTERLY_GROWTH_RATES.unemployment_rate_skill_1   = 0.0;    
    QUARTERLY_GROWTH_RATES.unemployment_rate_skill_2   = 0.0;
    QUARTERLY_GROWTH_RATES.unemployment_rate_skill_3   = 0.0;    
    QUARTERLY_GROWTH_RATES.unemployment_rate_skill_4   = 0.0;
    QUARTERLY_GROWTH_RATES.unemployment_rate_skill_5   = 0.0;    
    QUARTERLY_GROWTH_RATES.average_wage                = 0.0;
    QUARTERLY_GROWTH_RATES.no_firms                    = 0.0;
    QUARTERLY_GROWTH_RATES.no_firm_births              = 0.0;
    QUARTERLY_GROWTH_RATES.no_firm_deaths              = 0.0;
    
    ANNUAL_GROWTH_RATES_QUARTERLY.cpi                  = 1.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.gdp                  = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.output               = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.employment           = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_1    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_2    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_3    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_4    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_5    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.average_wage         = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firms             = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_births       = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_deaths       = 0.0;

    //compute quarterly rate of change of CPI: compounded inflation rate over the previous 3 months
    for (i=0; i<3; i++)
    {
        QUARTERLY_GROWTH_RATES.cpi *= HISTORY_MONTHLY[0].cpi;           
    }
    QUARTERLY_GROWTH_RATES.cpi = (QUARTERLY_GROWTH_RATES.cpi-1)*100;
    
    //compute quarterly rates of change: change over the previous 3 months
    if(HISTORY_QUARTERLY[1].gdp>0.0)                {QUARTERLY_GROWTH_RATES.gdp                         = (HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[1].gdp  -1)*100;}
    if(HISTORY_QUARTERLY[1].output>0.0)             {QUARTERLY_GROWTH_RATES.output                      = (HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[1].output  -1)*100;}
    if(HISTORY_QUARTERLY[1].employment>0)           {QUARTERLY_GROWTH_RATES.employment                  = (HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[1].employment  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate           = (HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[1].unemployment_rate  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate_skill_1>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate_skill_1   = (HISTORY_QUARTERLY[0].unemployment_rate_skill_1 / HISTORY_QUARTERLY[1].unemployment_rate_skill_1  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate_skill_2>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate_skill_2   = (HISTORY_QUARTERLY[0].unemployment_rate_skill_2 / HISTORY_QUARTERLY[1].unemployment_rate_skill_2  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate_skill_3>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate_skill_3   = (HISTORY_QUARTERLY[0].unemployment_rate_skill_3 / HISTORY_QUARTERLY[1].unemployment_rate_skill_3  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate_skill_4>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate_skill_4   = (HISTORY_QUARTERLY[0].unemployment_rate_skill_4 / HISTORY_QUARTERLY[1].unemployment_rate_skill_4  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate_skill_5>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate_skill_5   = (HISTORY_QUARTERLY[0].unemployment_rate_skill_5 / HISTORY_QUARTERLY[1].unemployment_rate_skill_5  -1)*100;}
    if(HISTORY_QUARTERLY[1].average_wage>0.0)       {QUARTERLY_GROWTH_RATES.average_wage                = (HISTORY_QUARTERLY[0].average_wage / HISTORY_QUARTERLY[1].average_wage  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firms>0)             {QUARTERLY_GROWTH_RATES.no_firms                    = (HISTORY_QUARTERLY[0].no_firms / HISTORY_QUARTERLY[1].no_firms  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firm_births>0)       {QUARTERLY_GROWTH_RATES.no_firm_births              = (HISTORY_QUARTERLY[0].no_firm_births / HISTORY_QUARTERLY[1].no_firm_births  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firm_deaths>0)       {QUARTERLY_GROWTH_RATES.no_firm_deaths              = (HISTORY_QUARTERLY[0].no_firm_deaths / HISTORY_QUARTERLY[1].no_firm_deaths  -1)*100;}
    
    //compute annual rate of change of CPI: compounded inflation rate over the last 4 quarters (should equal the inflation rate measured over last 12 months)
     for (i=0; i<4; i++)
     {
        ANNUAL_GROWTH_RATES_QUARTERLY.cpi *= HISTORY_QUARTERLY[i].cpi;
     }
     ANNUAL_GROWTH_RATES_QUARTERLY.cpi = (ANNUAL_GROWTH_RATES_QUARTERLY.cpi-1)*100;

    //compute annual rates of change over the previous 4 quarters: respective to same quarter in previous year    
    if(HISTORY_QUARTERLY[4].gdp>0.0)                {ANNUAL_GROWTH_RATES_QUARTERLY.gdp                  = (HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[4].gdp  -1)*100;}
    if(HISTORY_QUARTERLY[4].output>0.0)             {ANNUAL_GROWTH_RATES_QUARTERLY.output               = (HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[4].output  -1)*100;}
    if(HISTORY_QUARTERLY[4].employment>0)           {ANNUAL_GROWTH_RATES_QUARTERLY.employment           = (HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[4].employment  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate    = (HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[4].unemployment_rate  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate_skill_1>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_1    = (HISTORY_QUARTERLY[0].unemployment_rate_skill_1 / HISTORY_QUARTERLY[4].unemployment_rate_skill_1  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate_skill_2>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_2    = (HISTORY_QUARTERLY[0].unemployment_rate_skill_2 / HISTORY_QUARTERLY[4].unemployment_rate_skill_2  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate_skill_3>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_3    = (HISTORY_QUARTERLY[0].unemployment_rate_skill_3 / HISTORY_QUARTERLY[4].unemployment_rate_skill_3  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate_skill_4>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_4    = (HISTORY_QUARTERLY[0].unemployment_rate_skill_4 / HISTORY_QUARTERLY[4].unemployment_rate_skill_4  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate_skill_5>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate_skill_5    = (HISTORY_QUARTERLY[0].unemployment_rate_skill_5 / HISTORY_QUARTERLY[4].unemployment_rate_skill_5  -1)*100;}
    if(HISTORY_QUARTERLY[4].average_wage>0.0)       {ANNUAL_GROWTH_RATES_QUARTERLY.average_wage         = (HISTORY_QUARTERLY[0].average_wage / HISTORY_QUARTERLY[4].average_wage  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firms>0)             {ANNUAL_GROWTH_RATES_QUARTERLY.no_firms             = (HISTORY_QUARTERLY[0].no_firms / HISTORY_QUARTERLY[4].no_firms  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firm_births>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_births       = (HISTORY_QUARTERLY[0].no_firm_births / HISTORY_QUARTERLY[4].no_firm_births  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firm_deaths>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_deaths       = (HISTORY_QUARTERLY[0].no_firm_deaths / HISTORY_QUARTERLY[4].no_firm_deaths  -1)*100;}
    
    //*********************************** Code to be tested: region data
    
    for ( region=0; region<REGION_FIRM_DATA.size; region++)
    {
        QUARTERLY_GROWTH_RATES.region_data.array[region].cpi                         = 1.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].gdp                         = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].output                      = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].employment                  = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate           = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_1   = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_2   = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_3   = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_4   = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_5   = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].average_wage                = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].no_firms                    = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].no_firm_births              = 0.0;
        QUARTERLY_GROWTH_RATES.region_data.array[region].no_firm_deaths              = 0.0;
        
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].cpi                  = 1.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].gdp                  = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].output               = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].employment           = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_1    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_2    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_3    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_4    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_5    = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].average_wage         = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firms             = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firm_births       = 0.0;
        ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firm_deaths       = 0.0;
    
        //compute quarterly rates of change of CPI: compounded inflation rate over the previous 3 months
        for (i=0; i<3; i++)
        {
            QUARTERLY_GROWTH_RATES.region_data.array[region].cpi *= HISTORY_MONTHLY[0].region_data.array[region].cpi;           
        }
        QUARTERLY_GROWTH_RATES.region_data.array[region].cpi = (QUARTERLY_GROWTH_RATES.region_data.array[region].cpi-1)*100;
        
        //compute quarterly rates of change:
        if(HISTORY_QUARTERLY[1].region_data.array[region].gdp>0.0)                {QUARTERLY_GROWTH_RATES.region_data.array[region].gdp                         = (HISTORY_QUARTERLY[0].region_data.array[region].gdp / HISTORY_QUARTERLY[1].region_data.array[region].gdp  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].output>0.0)             {QUARTERLY_GROWTH_RATES.region_data.array[region].output                      = (HISTORY_QUARTERLY[0].region_data.array[region].output / HISTORY_QUARTERLY[1].region_data.array[region].output  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].employment>0)           {QUARTERLY_GROWTH_RATES.region_data.array[region].employment                  = (HISTORY_QUARTERLY[0].region_data.array[region].employment / HISTORY_QUARTERLY[1].region_data.array[region].employment  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate           = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_1>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_1   = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1 / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_1  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_2>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_2   = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2 / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_2  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_3>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_3   = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3 / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_3  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_4>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_4   = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4 / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_4  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_5>0.0)  {QUARTERLY_GROWTH_RATES.region_data.array[region].unemployment_rate_skill_5   = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5 / HISTORY_QUARTERLY[1].region_data.array[region].unemployment_rate_skill_5  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].average_wage>0.0)       {QUARTERLY_GROWTH_RATES.region_data.array[region].average_wage                = (HISTORY_QUARTERLY[0].region_data.array[region].average_wage / HISTORY_QUARTERLY[1].region_data.array[region].average_wage  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].no_firms>0)             {QUARTERLY_GROWTH_RATES.region_data.array[region].no_firms                    = (HISTORY_QUARTERLY[0].region_data.array[region].no_firms / HISTORY_QUARTERLY[1].region_data.array[region].no_firms  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].no_firm_births>0)       {QUARTERLY_GROWTH_RATES.region_data.array[region].no_firm_births              = (HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births / HISTORY_QUARTERLY[1].region_data.array[region].no_firm_births  -1)*100;}
        if(HISTORY_QUARTERLY[1].region_data.array[region].no_firm_deaths>0)       {QUARTERLY_GROWTH_RATES.region_data.array[region].no_firm_deaths              = (HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths / HISTORY_QUARTERLY[1].region_data.array[region].no_firm_deaths  -1)*100;}
        
        //compute annual rate of change of CPI: compounded inflation rate over the last 4 quarters (should equal the inflation rate measured over last 12 months)
         for (i=0; i<4; i++)
         {
            ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].cpi *= HISTORY_QUARTERLY[i].region_data.array[region].cpi;
         }
         ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].cpi = (ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].cpi-1)*100;

        //compute annual rates of change over the previous 4 quarters: respective to same quarter in previous year
        if(HISTORY_QUARTERLY[4].region_data.array[region].gdp>0.0)                {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].gdp                  = (HISTORY_QUARTERLY[0].region_data.array[region].gdp / HISTORY_QUARTERLY[4].region_data.array[region].gdp  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].output>0.0)             {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].output               = (HISTORY_QUARTERLY[0].region_data.array[region].output / HISTORY_QUARTERLY[4].region_data.array[region].output  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].employment>0)           {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].employment           = (HISTORY_QUARTERLY[0].region_data.array[region].employment / HISTORY_QUARTERLY[4].region_data.array[region].employment  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_1>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_1    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_1 / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_1  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_2>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_2    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_2 / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_2  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_3>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_3    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_3 / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_3  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_4>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_4    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_4 / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_4  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_5>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].unemployment_rate_skill_5    = (HISTORY_QUARTERLY[0].region_data.array[region].unemployment_rate_skill_5 / HISTORY_QUARTERLY[4].region_data.array[region].unemployment_rate_skill_5  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].average_wage>0.0)       {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].average_wage  = (HISTORY_QUARTERLY[0].region_data.array[region].average_wage / HISTORY_QUARTERLY[4].region_data.array[region].average_wage  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].no_firms>0)             {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firms             = (HISTORY_QUARTERLY[0].region_data.array[region].no_firms / HISTORY_QUARTERLY[4].region_data.array[region].no_firms  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].no_firm_births>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firm_births       = (HISTORY_QUARTERLY[0].region_data.array[region].no_firm_births / HISTORY_QUARTERLY[4].region_data.array[region].no_firm_births  -1)*100;}
        if(HISTORY_QUARTERLY[4].region_data.array[region].no_firm_deaths>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.region_data.array[region].no_firm_deaths       = (HISTORY_QUARTERLY[0].region_data.array[region].no_firm_deaths / HISTORY_QUARTERLY[4].region_data.array[region].no_firm_deaths  -1)*100;}
    }
    
    return 0;
}


/* \fn: int Eurostat_measure_recession(void)
 * \brief: Function to measure the start, duration and end of a recession.
 */
int Eurostat_measure_recession()
{
    //Signal start of recesson: 2 quarters of succesive negative growth of GDP
    if (RECESSION_STARTED==0)
    {
        if ( (HISTORY_QUARTERLY[0].gdp < HISTORY_QUARTERLY[1].gdp) && (HISTORY_QUARTERLY[1].gdp < HISTORY_QUARTERLY[2].gdp))
        {
            RECESSION_STARTED=1;
            RECESSION_DURATION = 0;
        }   
    }   
    //Signal end of recesson: 1 quarter of positive growth of GDP after start of recession
    if (RECESSION_STARTED==1)
    {
        RECESSION_DURATION++;

        if (HISTORY_QUARTERLY[0].gdp >= HISTORY_QUARTERLY[1].gdp)
        {
            RECESSION_STARTED=0;
        }
    }

    if (PRINT_LOG)
    {
        printf(" - recession started: %d\n", RECESSION_STARTED);
        printf(" - duration of recession: %d\n", RECESSION_DURATION);
    }
    
    return 0;
}

/* \fn: int Eurostat_check_flow_consistency(void)
 * \brief: Function to check cash flow consistency.
 */
int Eurostat_check_flow_consistency()
{
    //Reset all counters
    FIRM_BALANCE_SHEETS.flows.cum_revenue=0.0;
    FIRM_BALANCE_SHEETS.flows.labour_costs=0.0;
    FIRM_BALANCE_SHEETS.flows.capital_costs=0.0;
    FIRM_BALANCE_SHEETS.flows.tax_payment=0.0;
    FIRM_BALANCE_SHEETS.flows.total_debt_installment_payment=0.0;
    FIRM_BALANCE_SHEETS.flows.total_interest_payment=0.0;
    FIRM_BALANCE_SHEETS.flows.total_dividend_payment=0.0;
    FIRM_BALANCE_SHEETS.flows.total_income=0.0;
    FIRM_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_FIRM_BALANCE_SHEET_MESSAGE_LOOP
        FIRM_BALANCE_SHEETS.flows.cum_revenue += firm_balance_sheet_message->cum_revenue;
        FIRM_BALANCE_SHEETS.flows.labour_costs += firm_balance_sheet_message->labour_costs;
        FIRM_BALANCE_SHEETS.flows.capital_costs += firm_balance_sheet_message->capital_costs;
        FIRM_BALANCE_SHEETS.flows.tax_payment += firm_balance_sheet_message->tax_payment;
        FIRM_BALANCE_SHEETS.flows.total_debt_installment_payment += firm_balance_sheet_message->total_debt_installment_payment;
        FIRM_BALANCE_SHEETS.flows.total_interest_payment += firm_balance_sheet_message->total_interest_payment;
        FIRM_BALANCE_SHEETS.flows.total_dividend_payment += firm_balance_sheet_message->total_dividend_payment;
        FIRM_BALANCE_SHEETS.flows.total_income += firm_balance_sheet_message->total_income;
        FIRM_BALANCE_SHEETS.flows.total_expenses += firm_balance_sheet_message->total_expenses;
    FINISH_FIRM_BALANCE_SHEET_MESSAGE_LOOP

/*  
    //Reset all counters
    IGFIRM_BALANCE_SHEETS.flows.cum_revenue=0.0;
    IGFIRM_BALANCE_SHEETS.flows.labour_costs=0.0;
    IGFIRM_BALANCE_SHEETS.flows.energy_costs=0.0;
    IGFIRM_BALANCE_SHEETS.flows.tax_payment=0.0;
    IGFIRM_BALANCE_SHEETS.flows.total_debt_installment_payment=0.0;
    IGFIRM_BALANCE_SHEETS.flows.total_interest_payment=0.0;
    IGFIRM_BALANCE_SHEETS.flows.total_dividend_payment=0.0;
    IGFIRM_BALANCE_SHEETS.flows.total_income=0.0;
    IGFIRM_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_IGFIRM_BALANCE_SHEET_MESSAGE_LOOP
        IGFIRM_BALANCE_SHEETS.flows.cum_revenue += igfirm_balance_sheet_message->cum_revenue;
        IGFIRM_BALANCE_SHEETS.flows.labour_costs += igfirm_balance_sheet_message->labour_costs;
        IGFIRM_BALANCE_SHEETS.flows.energy_costs += igfirm_balance_sheet_message->energy_costs;
        IGFIRM_BALANCE_SHEETS.flows.tax_payment += igfirm_balance_sheet_message->tax_payment;
        IGFIRM_BALANCE_SHEETS.flows.total_debt_installment_payment += igfirm_balance_sheet_message->total_debt_installment_payment;
        IGFIRM_BALANCE_SHEETS.flows.total_interest_payment += igfirm_balance_sheet_message->total_interest_payment;
        IGFIRM_BALANCE_SHEETS.flows.total_dividend_payment += igfirm_balance_sheet_message->total_dividend_payment;
        IGFIRM_BALANCE_SHEETS.flows.total_income += igfirm_balance_sheet_message->total_income;
        IGFIRM_BALANCE_SHEETS.flows.total_expenses += igfirm_balance_sheet_message->total_expenses;
    FINISH_IGFIRM_BALANCE_SHEET_MESSAGE_LOOP
*/
    
    //Reset all counters
    HOUSEHOLD_BALANCE_SHEETS.flows.wage=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.gov_interest=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.stock_sales=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.cum_total_dividends=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.monthly_consumption_expenditure=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.tax_payment=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.stock_purchases=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.total_income=0.0;
    HOUSEHOLD_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_HOUSEHOLD_BALANCE_SHEET_MESSAGE_LOOP
        HOUSEHOLD_BALANCE_SHEETS.flows.wage += household_balance_sheet_message->wage;
        HOUSEHOLD_BALANCE_SHEETS.flows.gov_interest += household_balance_sheet_message->gov_interest;
        HOUSEHOLD_BALANCE_SHEETS.flows.stock_sales += household_balance_sheet_message->stock_sales;
        HOUSEHOLD_BALANCE_SHEETS.flows.cum_total_dividends += household_balance_sheet_message->cum_total_dividends;
        HOUSEHOLD_BALANCE_SHEETS.flows.monthly_consumption_expenditure += household_balance_sheet_message->monthly_consumption_expenditure;
        HOUSEHOLD_BALANCE_SHEETS.flows.tax_payment += household_balance_sheet_message->tax_payment;
        HOUSEHOLD_BALANCE_SHEETS.flows.stock_purchases += household_balance_sheet_message->stock_purchases;
        HOUSEHOLD_BALANCE_SHEETS.flows.total_income += household_balance_sheet_message->total_income;
        HOUSEHOLD_BALANCE_SHEETS.flows.total_expenses += household_balance_sheet_message->total_expenses;
    FINISH_HOUSEHOLD_BALANCE_SHEET_MESSAGE_LOOP

    //Reset all counters
    BANK_BALANCE_SHEETS.flows.firm_loan_installments=0.0;
    BANK_BALANCE_SHEETS.flows.firm_interest_payments=0.0;
    BANK_BALANCE_SHEETS.flows.firm_loan_issues=0.0;
    BANK_BALANCE_SHEETS.flows.ecb_interest_payment=0.0;
    BANK_BALANCE_SHEETS.flows.dividend_payment=0.0;
    BANK_BALANCE_SHEETS.flows.tax_payment=0.0;
    BANK_BALANCE_SHEETS.flows.total_income=0.0;
    BANK_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_BANK_BALANCE_SHEET_MESSAGE_LOOP
        BANK_BALANCE_SHEETS.flows.firm_loan_installments += bank_balance_sheet_message->firm_loan_installments;
        BANK_BALANCE_SHEETS.flows.firm_interest_payments += bank_balance_sheet_message->firm_interest_payments;
        BANK_BALANCE_SHEETS.flows.firm_loan_issues += bank_balance_sheet_message->firm_loan_issues;
        BANK_BALANCE_SHEETS.flows.ecb_interest_payment += bank_balance_sheet_message->ecb_interest_payment;
        BANK_BALANCE_SHEETS.flows.dividend_payment += bank_balance_sheet_message->dividend_payment;
        BANK_BALANCE_SHEETS.flows.tax_payment += bank_balance_sheet_message->tax_payment;
        BANK_BALANCE_SHEETS.flows.total_income += bank_balance_sheet_message->total_income;
        BANK_BALANCE_SHEETS.flows.total_expenses += bank_balance_sheet_message->total_expenses;
    FINISH_BANK_BALANCE_SHEET_MESSAGE_LOOP

    //Reset all counters
    GOV_BALANCE_SHEETS.flows.monthly_tax_revenues=0.0;
    GOV_BALANCE_SHEETS.flows.total_bond_financing=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_investment_expenditure=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_consumption_expenditure=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_benefit_payment=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_subsidy_payment=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_transfer_payment=0.0;
    GOV_BALANCE_SHEETS.flows.monthly_bond_interest_payment=0.0;
    GOV_BALANCE_SHEETS.flows.total_income=0.0;
    GOV_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_GOV_BALANCE_SHEET_MESSAGE_LOOP
        GOV_BALANCE_SHEETS.flows.monthly_tax_revenues += gov_balance_sheet_message->monthly_tax_revenues;
        GOV_BALANCE_SHEETS.flows.total_bond_financing += gov_balance_sheet_message->total_bond_financing;
        GOV_BALANCE_SHEETS.flows.monthly_investment_expenditure += gov_balance_sheet_message->monthly_investment_expenditure;
        GOV_BALANCE_SHEETS.flows.monthly_consumption_expenditure += gov_balance_sheet_message->monthly_consumption_expenditure;
        GOV_BALANCE_SHEETS.flows.monthly_benefit_payment += gov_balance_sheet_message->monthly_benefit_payment;
        GOV_BALANCE_SHEETS.flows.monthly_subsidy_payment += gov_balance_sheet_message->monthly_subsidy_payment;
        GOV_BALANCE_SHEETS.flows.monthly_transfer_payment += gov_balance_sheet_message->monthly_transfer_payment;
        GOV_BALANCE_SHEETS.flows.monthly_bond_interest_payment += gov_balance_sheet_message->monthly_bond_interest_payment;
        GOV_BALANCE_SHEETS.flows.total_income += gov_balance_sheet_message->total_income;
        GOV_BALANCE_SHEETS.flows.total_expenses += gov_balance_sheet_message->total_expenses;
    FINISH_GOV_BALANCE_SHEET_MESSAGE_LOOP

    //Reset all counters
    ECB_BALANCE_SHEETS.flows.bank_interest=0.0;
    ECB_BALANCE_SHEETS.flows.gov_interest=0.0;
    ECB_BALANCE_SHEETS.flows.gov_bond_purchase=0.0;
    ECB_BALANCE_SHEETS.flows.dividend_payment=0.0;
    ECB_BALANCE_SHEETS.flows.total_income=0.0;
    ECB_BALANCE_SHEETS.flows.total_expenses=0.0;

    //Reading cash flow messages
    START_ECB_BALANCE_SHEET_MESSAGE_LOOP
        ECB_BALANCE_SHEETS.flows.bank_interest += ecb_balance_sheet_message->bank_interest;
        ECB_BALANCE_SHEETS.flows.gov_interest += ecb_balance_sheet_message->gov_interest;
        ECB_BALANCE_SHEETS.flows.gov_bond_purchase += ecb_balance_sheet_message->gov_bond_purchase;
        ECB_BALANCE_SHEETS.flows.dividend_payment += ecb_balance_sheet_message->dividend_payment;       
        ECB_BALANCE_SHEETS.flows.total_income += ecb_balance_sheet_message->total_income;
        ECB_BALANCE_SHEETS.flows.total_expenses += ecb_balance_sheet_message->total_expenses;
    FINISH_ECB_BALANCE_SHEET_MESSAGE_LOOP

    /**************************** Check cash flow consistency requirements ****************************/
    
    //Revenues
    assert(FIRM_BALANCE_SHEETS.flows.cum_revenue >= 0.0);
    assert(IGFIRM_BALANCE_SHEETS.flows.cum_revenue >= 0.0);
    
    //Consumption: Household+Government
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Consumption.\n");
    printf("\n FIRM_BALANCE_SHEETS.flows.cum_revenue = %.4f\n", FIRM_BALANCE_SHEETS.flows.cum_revenue);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.monthly_consumption_expenditure = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.monthly_consumption_expenditure);

    //assert(abs(FIRM_BALANCE_SHEETS.flows.cum_revenue - HOUSEHOLD_BALANCE_SHEETS.flows.monthly_consumption_expenditure
    //- GOV_BALANCE_SHEETS.flows.monthly_consumption_expenditure) < 1e-3);
        
    //Investment: Firms+Government
    printf("\n -----------------------------------\n"); 
    printf("\n Checking cash flow: Investment.\n");
    printf("\n IGFIRM_BALANCE_SHEETS.flows.cum_revenue = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.cum_revenue);
    printf("\n FIRM_BALANCE_SHEETS.flows.capital_costs = %.4f\n", FIRM_BALANCE_SHEETS.flows.capital_costs);
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_investment_expenditure = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_investment_expenditure);

    //assert(abs(IGFIRM_BALANCE_SHEETS.flows.cum_revenue - FIRM_BALANCE_SHEETS.flows.capital_costs
    //- GOV_BALANCE_SHEETS.flows.monthly_investment_expenditure) < 1e-3);
    
    //Salaries
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Salaries.\n");
    printf("\n FIRM_BALANCE_SHEETS.flows.labour_costs = %.4f\n", FIRM_BALANCE_SHEETS.flows.labour_costs);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.labour_costs = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.labour_costs);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.wage = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.wage);

//  assert(abs(FIRM_BALANCE_SHEETS.flows.labour_costs + IGFIRM_BALANCE_SHEETS.flows.labour_costs
//  - HOUSEHOLD_BALANCE_SHEETS.flows.wage   ) < 1e-3);
    
    //Taxes
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Taxes.\n");
    printf("\n FIRM_BALANCE_SHEETS.flows.tax_payment = %.4f\n", FIRM_BALANCE_SHEETS.flows.tax_payment);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.tax_payment = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.tax_payment);
    printf("\n BANK_BALANCE_SHEETS.flows.tax_payment = %.4f\n", BANK_BALANCE_SHEETS.flows.tax_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.tax_payment = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.tax_payment);
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_tax_revenues = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_tax_revenues);
    
    //assert(abs(FIRM_BALANCE_SHEETS.flows.tax_payment + IGFIRM_BALANCE_SHEETS.flows.tax_payment
    //+ BANK_BALANCE_SHEETS.flows.tax_payment + HOUSEHOLD_BALANCE_SHEETS.flows.tax_payment - GOV_BALANCE_SHEETS.flows.monthly_tax_revenues) < 1e-3);
    
    //Dividend on stocks
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Dividend on stocks.\n");
    printf("\n FIRM_BALANCE_SHEETS.flows.total_dividend_payment = %.4f\n", FIRM_BALANCE_SHEETS.flows.total_dividend_payment);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.total_dividend_payment = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.total_dividend_payment);
    printf("\n BANK_BALANCE_SHEETS.flows.dividend_payment = %.4f\n", BANK_BALANCE_SHEETS.flows.dividend_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.cum_total_dividends = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.cum_total_dividends);

    //assert(abs(FIRM_BALANCE_SHEETS.flows.total_dividend_payment + IGFIRM_BALANCE_SHEETS.flows.total_dividend_payment
    //+ BANK_BALANCE_SHEETS.flows.dividend_payment - HOUSEHOLD_BALANCE_SHEETS.flows.cum_total_dividends) < 1e-3);

    //Interest on bank loans to firms
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Interest on bank loans to firms.\n");
    printf("\n BANK_BALANCE_SHEETS.flows.firm_interest_payments = %.4f\n", BANK_BALANCE_SHEETS.flows.firm_interest_payments);
    printf("\n FIRM_BALANCE_SHEETS.flows.total_interest_payment = %.4f\n", FIRM_BALANCE_SHEETS.flows.total_interest_payment);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.total_interest_payment = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.total_interest_payment);

    //assert(abs(FIRM_BALANCE_SHEETS.flows.total_interest_payment + IGFIRM_BALANCE_SHEETS.flows.total_interest_payment
    //- BANK_BALANCE_SHEETS.flows.firm_interest_payments) < 1e-3);

    //Debt installment payments by firms to banks
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Debt installment payments.\n");
    printf("\n BANK_BALANCE_SHEETS.flows.firm_loan_installments = %.4f\n", BANK_BALANCE_SHEETS.flows.firm_loan_installments);
    printf("\n FIRM_BALANCE_SHEETS.flows.total_debt_installment_payment = %.4f\n", FIRM_BALANCE_SHEETS.flows.total_debt_installment_payment);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.total_debt_installment_payment = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.total_debt_installment_payment);

    //assert(abs(FIRM_BALANCE_SHEETS.flows.total_debt_installment_payment + IGFIRM_BALANCE_SHEETS.flows.total_debt_installment_payment
    //- BANK_BALANCE_SHEETS.flows.firm_loan_installments) < 1e-3);

    //Interest on central bank loans to banks
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Interest on central bank loans to banks.\n");
    printf("\n BANK_BALANCE_SHEETS.flows.ecb_interest_payment = %.4f\n", BANK_BALANCE_SHEETS.flows.ecb_interest_payment);
    printf("\n ECB_BALANCE_SHEETS.flows.bank_interest = %.4f\n", ECB_BALANCE_SHEETS.flows.bank_interest);
    
    //assert(abs(BANK_BALANCE_SHEETS.flows.ecb_interest_payment
    //- ECB_BALANCE_SHEETS.flows.bank_interest) < 1e-3);
    
    //Interest on gov. bonds
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Interest on gov. bonds.\n");
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_bond_interest_payment = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_bond_interest_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.gov_interest = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.gov_interest);
    printf("\n ECB_BALANCE_SHEETS.flows.gov_interest = %.4f\n", ECB_BALANCE_SHEETS.flows.gov_interest);
    
    //assert(abs(GOV_BALANCE_SHEETS.flows.monthly_bond_interest_payment
    //- ECB_BALANCE_SHEETS.flows.gov_interest - HOUSEHOLD_BALANCE_SHEETS.flows.gov_interest) < 1e-3);
    
    //Benefits (not implemented)
/*
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Benefits.\n");
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_benefit_payment = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_benefit_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.benefit_income = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.benefit_income);
*/
    //assert(abs(GOV_BALANCE_SHEETS.flows.monthly_benefit_payment
    //- HOUSEHOLD_BALANCE_SHEETS.flows.benefit_income) < 1e-3);
    
    //Subsidies (not implemented)
/*
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Subsidies.\n");
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_subsidy_payment = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_subsidy_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.subsidy_income = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.subsidy_income);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.subsidy_income = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.subsidy_income);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.subsidy_income = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.subsidy_income);
*/
    //assert(abs(GOV_BALANCE_SHEETS.flows.monthly_subsidy_payment
    //- HOUSEHOLD_BALANCE_SHEETS.flows.subsidy_income - FIRM_BALANCE_SHEETS.flows.subsidy_income - IGFIRM_BALANCE_SHEETS.flows.subsidy_income) < 1e-3);
    
    //Transfers (not implemented)
/*
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Transfers.\n");
    printf("\n GOV_BALANCE_SHEETS.flows.monthly_transfer_payment = %.4f\n", GOV_BALANCE_SHEETS.flows.monthly_transfer_payment);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.transfer_income = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.transfer_income);
    printf("\n FIRM_BALANCE_SHEETS.flows.transfer_income = %.4f\n", FIRM_BALANCE_SHEETS.flows.transfer_income);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.transfer_income = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.transfer_income);
*/
    //assert(abs(GOV_BALANCE_SHEETS.flows.monthly_transfer_payment
    //- HOUSEHOLD_BALANCE_SHEETS.flows.transfer_income - FIRM_BALANCE_SHEETS.flows.transfer_income - IGFIRM_BALANCE_SHEETS.flows.transfer_income) < 1e-3);
    

    //Total income == Total expenses
    printf("\n -----------------------------------\n");
    printf("\n Checking cash flow: Total income == Total expenses.\n");
    printf("\n GOV_BALANCE_SHEETS.flows.total_income = %.4f\n", GOV_BALANCE_SHEETS.flows.total_income);
    printf("\n GOV_BALANCE_SHEETS.flows.total_expenses = %.4f\n", GOV_BALANCE_SHEETS.flows.total_expenses);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.total_income = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.total_income);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.flows.total_expenses = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.flows.total_expenses);
    printf("\n FIRM_BALANCE_SHEETS.flows.total_income = %.4f\n", FIRM_BALANCE_SHEETS.flows.total_income);
    printf("\n FIRM_BALANCE_SHEETS.flows.total_expenses = %.4f\n", FIRM_BALANCE_SHEETS.flows.total_expenses);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.total_income = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.total_income);
    printf("\n IGFIRM_BALANCE_SHEETS.flows.total_expenses = %.4f\n", IGFIRM_BALANCE_SHEETS.flows.total_expenses);
    printf("\n BANK_BALANCE_SHEETS.flows.total_income = %.4f\n", BANK_BALANCE_SHEETS.flows.total_income);
    printf("\n BANK_BALANCE_SHEETS.flows.total_expenses = %.4f\n", BANK_BALANCE_SHEETS.flows.total_expenses);
    printf("\n ECB_BALANCE_SHEETS.flows.total_income = %.4f\n", ECB_BALANCE_SHEETS.flows.total_income);
    printf("\n ECB_BALANCE_SHEETS.flows.total_expenses = %.4f\n", ECB_BALANCE_SHEETS.flows.total_expenses);

/*
    assert(abs(FIRM_BALANCE_SHEETS.flows.total_income - FIRM_BALANCE_SHEETS.flows.total_expenses +
    IGFIRM_BALANCE_SHEETS.flows.total_income - IGFIRM_BALANCE_SHEETS.flows.total_expenses +
    HOUSEHOLD_BALANCE_SHEETS.flows.total_income - HOUSEHOLD_BALANCE_SHEETS.flows.total_expenses +
    BANK_BALANCE_SHEETS.flows.total_income - BANK_BALANCE_SHEETS.flows.total_expenses +
    GOV_BALANCE_SHEETS.flows.total_income - GOV_BALANCE_SHEETS.flows.total_expenses +
    ECB_BALANCE_SHEETS.flows.total_income - ECB_BALANCE_SHEETS.flows.total_expenses ) < 1e-3);
*/
    
    return 0;
}

/* \fn: int Eurostat_check_stock_consistency(void)
 * \brief: Function to check the balance sheet stock-flow consistency.
 */
int Eurostat_check_stock_consistency()
{
    //Reset all counters
    FIRM_BALANCE_SHEETS.stocks.payment_account=0.0;
    FIRM_BALANCE_SHEETS.stocks.total_value_local_inventory=0.0;
    FIRM_BALANCE_SHEETS.stocks.total_value_capital_stock=0.0;
    FIRM_BALANCE_SHEETS.stocks.total_debt=0.0;
    FIRM_BALANCE_SHEETS.stocks.current_shares_outstanding=0;
    FIRM_BALANCE_SHEETS.stocks.total_assets=0.0;
    FIRM_BALANCE_SHEETS.stocks.total_liabilities=0.0;
    
    //Read stock messages
    START_FIRM_BALANCE_SHEET_MESSAGE_LOOP
        FIRM_BALANCE_SHEETS.stocks.payment_account += firm_balance_sheet_message->payment_account;
        FIRM_BALANCE_SHEETS.stocks.total_value_local_inventory += firm_balance_sheet_message->total_value_local_inventory;
        FIRM_BALANCE_SHEETS.stocks.total_value_capital_stock += firm_balance_sheet_message->total_value_capital_stock;
        FIRM_BALANCE_SHEETS.stocks.total_debt += firm_balance_sheet_message->total_debt;
        FIRM_BALANCE_SHEETS.stocks.current_shares_outstanding += firm_balance_sheet_message->current_shares_outstanding;
        FIRM_BALANCE_SHEETS.stocks.total_assets += firm_balance_sheet_message->total_assets;
        FIRM_BALANCE_SHEETS.stocks.total_liabilities += firm_balance_sheet_message->total_liabilities;
    FINISH_FIRM_BALANCE_SHEET_MESSAGE_LOOP
/*  
    //Reset all counters
    IGFIRM_BALANCE_SHEETS.stocks.payment_account=0.0;
    IGFIRM_BALANCE_SHEETS.stocks.total_value_local_inventory=0.0;
    IGFIRM_BALANCE_SHEETS.stocks.total_value_capital_stock=0.0;
    IGFIRM_BALANCE_SHEETS.stocks.total_debt=0.0;
    IGFIRM_BALANCE_SHEETS.stocks.current_shares_outstanding=0;
    IGFIRM_BALANCE_SHEETS.stocks.total_assets=0.0;
    IGFIRM_BALANCE_SHEETS.stocks.total_liabilities=0.0;

    //Reading stock messages
    START_IGFIRM_BALANCE_SHEET_MESSAGE_LOOP
        IGFIRM_BALANCE_SHEETS.stocks.payment_account += igfirm_balance_sheet_message->payment_account;
        IGFIRM_BALANCE_SHEETS.stocks.total_value_local_inventory += igfirm_balance_sheet_message->total_value_local_inventory;
        IGFIRM_BALANCE_SHEETS.stocks.total_value_capital_stock += igfirm_balance_sheet_message->total_value_capital_stock;
        IGFIRM_BALANCE_SHEETS.stocks.total_debt += igfirm_balance_sheet_message->total_debt;
        IGFIRM_BALANCE_SHEETS.stocks.current_shares_outstanding += igfirm_balance_sheet_message->current_shares_outstanding;
        IGFIRM_BALANCE_SHEETS.stocks.total_assets += igfirm_balance_sheet_message->total_assets;
        IGFIRM_BALANCE_SHEETS.stocks.total_liabilities += igfirm_balance_sheet_message->total_liabilities;
    FINISH_IGFIRM_BALANCE_SHEET_MESSAGE_LOOP
*/

    //Reset all counters
    HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account=0.0;
    HOUSEHOLD_BALANCE_SHEETS.stocks.gov_bond_holdings=0.0;
    HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds=0;
    HOUSEHOLD_BALANCE_SHEETS.stocks.nr_firm_shares=0;
    HOUSEHOLD_BALANCE_SHEETS.stocks.total_assets=0.0;
    HOUSEHOLD_BALANCE_SHEETS.stocks.total_liabilities=0.0;

    //Reading stock messages
    START_HOUSEHOLD_BALANCE_SHEET_MESSAGE_LOOP
        HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account += household_balance_sheet_message->payment_account;
        HOUSEHOLD_BALANCE_SHEETS.stocks.gov_bond_holdings += household_balance_sheet_message->gov_bond_holdings;
        HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds += household_balance_sheet_message->nr_gov_bonds;
        HOUSEHOLD_BALANCE_SHEETS.stocks.nr_firm_shares += household_balance_sheet_message->nr_firm_shares;
        HOUSEHOLD_BALANCE_SHEETS.stocks.total_assets += household_balance_sheet_message->total_assets;
        HOUSEHOLD_BALANCE_SHEETS.stocks.total_liabilities += household_balance_sheet_message->total_liabilities;
    FINISH_HOUSEHOLD_BALANCE_SHEET_MESSAGE_LOOP

    //Reset all counters
    BANK_BALANCE_SHEETS.stocks.cash=0.0; 
    BANK_BALANCE_SHEETS.stocks.total_credit=0.0;
    BANK_BALANCE_SHEETS.stocks.deposits=0.0;
    BANK_BALANCE_SHEETS.stocks.ecb_debt=0.0;
    BANK_BALANCE_SHEETS.stocks.total_assets=0.0;
    BANK_BALANCE_SHEETS.stocks.total_liabilities=0.0;

    //Reading stock messages
    START_BANK_BALANCE_SHEET_MESSAGE_LOOP
        BANK_BALANCE_SHEETS.stocks.cash += bank_balance_sheet_message->cash;
        BANK_BALANCE_SHEETS.stocks.total_credit += bank_balance_sheet_message->total_credit;        
        BANK_BALANCE_SHEETS.stocks.deposits += bank_balance_sheet_message->deposits;
        BANK_BALANCE_SHEETS.stocks.ecb_debt += bank_balance_sheet_message->ecb_debt;                
        BANK_BALANCE_SHEETS.stocks.total_assets += bank_balance_sheet_message->total_assets;
        BANK_BALANCE_SHEETS.stocks.total_liabilities += bank_balance_sheet_message->total_liabilities;
    FINISH_BANK_BALANCE_SHEET_MESSAGE_LOOP
    
    //Reset all counters
    GOV_BALANCE_SHEETS.stocks.payment_account=0.0; 
    GOV_BALANCE_SHEETS.stocks.value_bonds_outstanding=0.0;
    GOV_BALANCE_SHEETS.stocks.nr_bonds_outstanding=0;
    GOV_BALANCE_SHEETS.stocks.total_assets=0.0;
    GOV_BALANCE_SHEETS.stocks.total_liabilities=0.0;

    //Reading stock messages
    START_GOV_BALANCE_SHEET_MESSAGE_LOOP
        GOV_BALANCE_SHEETS.stocks.payment_account += gov_balance_sheet_message->payment_account;
        GOV_BALANCE_SHEETS.stocks.value_bonds_outstanding += gov_balance_sheet_message->value_bonds_outstanding;
        GOV_BALANCE_SHEETS.stocks.nr_bonds_outstanding += gov_balance_sheet_message->nr_bonds_outstanding;
        GOV_BALANCE_SHEETS.stocks.total_assets += gov_balance_sheet_message->total_assets;
        GOV_BALANCE_SHEETS.stocks.total_liabilities += gov_balance_sheet_message->total_liabilities;
    FINISH_GOV_BALANCE_SHEET_MESSAGE_LOOP

    //Reset all counters
    ECB_BALANCE_SHEETS.stocks.gov_bond_holdings=0.0;
    ECB_BALANCE_SHEETS.stocks.nr_gov_bonds = 0;
    ECB_BALANCE_SHEETS.stocks.total_ecb_debt=0.0;
    ECB_BALANCE_SHEETS.stocks.payment_account_private_sector=0.0;
    ECB_BALANCE_SHEETS.stocks.payment_account_public_sector=0.0;
    ECB_BALANCE_SHEETS.stocks.fiat_money=0.0;
    ECB_BALANCE_SHEETS.stocks.total_assets=0.0;
    ECB_BALANCE_SHEETS.stocks.total_liabilities=0.0;
    
    //Reading stock messages
    START_ECB_BALANCE_SHEET_MESSAGE_LOOP
        ECB_BALANCE_SHEETS.stocks.gov_bond_holdings += ecb_balance_sheet_message->gov_bond_holdings;
        ECB_BALANCE_SHEETS.stocks.nr_gov_bonds += ecb_balance_sheet_message->nr_gov_bonds;
        ECB_BALANCE_SHEETS.stocks.total_ecb_debt += ecb_balance_sheet_message->total_ecb_debt;
        ECB_BALANCE_SHEETS.stocks.payment_account_private_sector += ecb_balance_sheet_message->payment_account_private_sector;
        ECB_BALANCE_SHEETS.stocks.payment_account_public_sector += ecb_balance_sheet_message->payment_account_public_sector;
        ECB_BALANCE_SHEETS.stocks.fiat_money += ecb_balance_sheet_message->fiat_money;
        ECB_BALANCE_SHEETS.stocks.total_assets += ecb_balance_sheet_message->total_assets;
        ECB_BALANCE_SHEETS.stocks.total_liabilities += ecb_balance_sheet_message->total_liabilities;        
    FINISH_ECB_BALANCE_SHEET_MESSAGE_LOOP

    /**************************** Check stock consistency requirements ****************************/
    
    //Payment_accounts
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: payment_account\n");
/*  
    assert(FIRM_BALANCE_SHEETS.stocks.payment_account >= 0.0);
    assert(HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account >= 0.0);
    //assert(IGFIRM_BALANCE_SHEETS.stocks.payment_account >= 0.0);
    assert(GOV_BALANCE_SHEETS.stocks.payment_account >= 0.0);
    assert(BANK_BALANCE_SHEETS.stocks.cash >= 0.0);
*/  

    //Total Bank deposits
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Bank deposits\n");
    printf("\n FIRM_BALANCE_SHEETS.stocks.payment_account = %.4f\n", FIRM_BALANCE_SHEETS.stocks.payment_account);
    printf("\n IGFIRM_BALANCE_SHEETS.stocks.payment_account = %.4f\n", IGFIRM_BALANCE_SHEETS.stocks.payment_account);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account); 
    printf("\n BANK_BALANCE_SHEETS.stocks.deposits = %.4f\n", BANK_BALANCE_SHEETS.stocks.deposits);
    
//  assert(abs( FIRM_BALANCE_SHEETS.stocks.payment_account + IGFIRM_BALANCE_SHEETS.stocks.payment_account
//          + HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account - BANK_BALANCE_SHEETS.stocks.deposits ) < 1e-3);
    
    //Total Central Bank fiat money: 1st method
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Central Bank fiat money\n");
    printf("\n FIRM_BALANCE_SHEETS.stocks.payment_account = %.4f\n", FIRM_BALANCE_SHEETS.stocks.payment_account);
    printf("\n + IGFIRM_BALANCE_SHEETS.stocks.payment_account = %.4f\n", IGFIRM_BALANCE_SHEETS.stocks.payment_account);
    printf("\n + HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account);   
    printf("\n + GOV_BALANCE_SHEETS.stocks.payment_account = %.4f\n", GOV_BALANCE_SHEETS.stocks.payment_account);
    printf("\n + BANK_BALANCE_SHEETS.stocks.cash = %.4f\n", BANK_BALANCE_SHEETS.stocks.cash);
    printf("\n - BANK_BALANCE_SHEETS.stocks.total_credit = %.4f\n", BANK_BALANCE_SHEETS.stocks.total_credit);
    printf("\n -----------------------------------\n");
    printf("\n = ECB_BALANCE_SHEETS.stocks.fiat_money = %.4f\n", ECB_BALANCE_SHEETS.stocks.fiat_money);
/*
    assert(abs( FIRM_BALANCE_SHEETS.stocks.payment_account + IGFIRM_BALANCE_SHEETS.stocks.payment_account
            + HOUSEHOLD_BALANCE_SHEETS.stocks.payment_account + GOV_BALANCE_SHEETS.stocks.payment_account 
            + BANK_BALANCE_SHEETS.stocks.cash - BANK_BALANCE_SHEETS.stocks.total_credit 
            - ECB_BALANCE_SHEETS.stocks.fiat_money  ) < 1e-3);
*/
    
    //Total Central Bank fiat money: 2nd method
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Central Bank fiat money\n");
    printf("\n BANK_BALANCE_SHEETS.stocks.deposits = %.4f\n", BANK_BALANCE_SHEETS.stocks.deposits);
    printf("\n + BANK_BALANCE_SHEETS.stocks.cash = %.4f\n", BANK_BALANCE_SHEETS.stocks.cash);
    printf("\n - BANK_BALANCE_SHEETS.stocks.total_credit = %.4f\n", BANK_BALANCE_SHEETS.stocks.total_credit);
    printf("\n -----------------------------------\n");
    printf("\n = ECB_BALANCE_SHEETS.stocks.fiat_money = %.4f\n", ECB_BALANCE_SHEETS.stocks.fiat_money);
/*
    assert(abs( BANK_BALANCE_SHEETS.stocks.deposits + BANK_BALANCE_SHEETS.stocks.cash 
            - BANK_BALANCE_SHEETS.stocks.total_credit 
            - ECB_BALANCE_SHEETS.stocks.fiat_money  ) < 1e-3);
*/
    
    //Total bank loans to firms
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Total bank loans.\n");
    printf("\n FIRM_BALANCE_SHEETS.stocks.total_debt = %.4f\n", FIRM_BALANCE_SHEETS.stocks.total_debt);
    printf("\n BANK_BALANCE_SHEETS.stocks.total_credit = %.4f\n", BANK_BALANCE_SHEETS.stocks.total_credit);

//  assert(abs( FIRM_BALANCE_SHEETS.stocks.total_debt
//   - BANK_BALANCE_SHEETS.stocks.total_credit ) < 1e-3);
    
    //Total Central Bank loans to banks
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Central Bank loans.\n");
    printf("\n ECB_BALANCE_SHEETS.stocks.total_ecb_debt = %.4f\n", ECB_BALANCE_SHEETS.stocks.total_ecb_debt);
    printf("\n BANK_BALANCE_SHEETS.stocks.ecb_debt = %.4f\n", BANK_BALANCE_SHEETS.stocks.ecb_debt);
    
//  assert(abs( ECB_BALANCE_SHEETS.stocks.total_ecb_debt
//   - BANK_BALANCE_SHEETS.stocks.ecb_debt ) < 1e-3);


    //Holdings of Gov bonds
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Holdings of Gov bonds.\n");
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.gov_bond_holdings = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.stocks.gov_bond_holdings);
    printf("\n ECB_BALANCE_SHEETS.stocks.gov_bond_holdings = %.4f\n", ECB_BALANCE_SHEETS.stocks.gov_bond_holdings);
    printf("\n GOV_BALANCE_SHEETS.stocks.value_bonds_outstanding = %.4f\n", GOV_BALANCE_SHEETS.stocks.value_bonds_outstanding);

    assert(abs( HOUSEHOLD_BALANCE_SHEETS.stocks.gov_bond_holdings + ECB_BALANCE_SHEETS.stocks.gov_bond_holdings 
                - GOV_BALANCE_SHEETS.stocks.value_bonds_outstanding ) < 1e-3);

    
    //Nr of Gov bonds
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Number of Gov bonds.\n");
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds = %d\n", HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds);
    printf("\n ECB_BALANCE_SHEETS.stocks.nr_gov_bonds = %d\n", ECB_BALANCE_SHEETS.stocks.nr_gov_bonds);
    printf("\n GOV_BALANCE_SHEETS.stocks.nr_bonds_outstanding = %d\n", GOV_BALANCE_SHEETS.stocks.nr_bonds_outstanding);

//  assert(HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds + ECB_BALANCE_SHEETS.stocks.nr_gov_bonds 
//          - GOV_BALANCE_SHEETS.stocks.nr_bonds_outstanding == 0);

    //Nr of Firm shares
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Number of Firm shares.\n");
    printf("\n FIRM_BALANCE_SHEETS.stocks.current_shares_outstanding = %d\n", FIRM_BALANCE_SHEETS.stocks.current_shares_outstanding);
    printf("\n IGFIRM_BALANCE_SHEETS.stocks.current_shares_outstanding = %d\n", IGFIRM_BALANCE_SHEETS.stocks.current_shares_outstanding);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds = %d\n", HOUSEHOLD_BALANCE_SHEETS.stocks.nr_gov_bonds);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.nr_firm_shares = %d\n", HOUSEHOLD_BALANCE_SHEETS.stocks.nr_firm_shares);

//  assert(FIRM_BALANCE_SHEETS.stocks.current_shares_outstanding + IGFIRM_BALANCE_SHEETS.stocks.current_shares_outstanding 
//          - HOUSEHOLD_BALANCE_SHEETS.stocks.nr_firm_shares == 0);

    
    //Total assets == Total liabilities
    printf("\n -----------------------------------\n");
    printf("\n Checking Stocks: Total assets == Total liabilities.\n");
    printf("\n FIRM_BALANCE_SHEETS.stocks.total_assets = %.4f\n", FIRM_BALANCE_SHEETS.stocks.total_assets);
    printf("\n FIRM_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", FIRM_BALANCE_SHEETS.stocks.total_liabilities);
    printf("\n IGFIRM_BALANCE_SHEETS.stocks.total_assets = %.4f\n", IGFIRM_BALANCE_SHEETS.stocks.total_assets);
    printf("\n IGFIRM_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", IGFIRM_BALANCE_SHEETS.stocks.total_liabilities);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.total_assets = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.stocks.total_assets);
    printf("\n HOUSEHOLD_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", HOUSEHOLD_BALANCE_SHEETS.stocks.total_liabilities);
    printf("\n BANK_BALANCE_SHEETS.stocks.total_assets = %.4f\n", BANK_BALANCE_SHEETS.stocks.total_assets);
    printf("\n BANK_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", BANK_BALANCE_SHEETS.stocks.total_liabilities);
    printf("\n GOV_BALANCE_SHEETS.stocks.total_assets = %.4f\n", GOV_BALANCE_SHEETS.stocks.total_assets);
    printf("\n GOV_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", GOV_BALANCE_SHEETS.stocks.total_liabilities);
    printf("\n ECB_BALANCE_SHEETS.stocks.total_assets = %.4f\n", ECB_BALANCE_SHEETS.stocks.total_assets);
    printf("\n ECB_BALANCE_SHEETS.stocks.total_liabilities = %.4f\n", ECB_BALANCE_SHEETS.stocks.total_liabilities);

/*
    assert(abs(FIRM_BALANCE_SHEETS.stocks.total_assets - FIRM_BALANCE_SHEETS.stocks.total_liabilities +
    IGFIRM_BALANCE_SHEETS.stocks.total_assets - IGFIRM_BALANCE_SHEETS.stocks.total_liabilities +
    HOUSEHOLD_BALANCE_SHEETS.stocks.total_assets - HOUSEHOLD_BALANCE_SHEETS.stocks.total_liabilities +
    BANK_BALANCE_SHEETS.stocks.total_assets - BANK_BALANCE_SHEETS.stocks.total_liabilities +
    GOV_BALANCE_SHEETS.stocks.total_assets - GOV_BALANCE_SHEETS.stocks.total_liabilities +
    ECB_BALANCE_SHEETS.stocks.total_assets - ECB_BALANCE_SHEETS.stocks.total_liabilities    ) < 1e-3);
*/

    return 0;
}
