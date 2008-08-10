#include "../header.h"
#include "../Eurostat_agent_header.h"
#include "../my_library_header.h"


int Eurostat_idle()
{
    
    return 0;
}

int Eurostat_Initialization()
{
	int i;
	
    /*Create data content of REGION_FIRM/HOUSEHOLD_DATA at the beginning of the first day.      The first firms will send the data at the end of the first day and the other firms at the       end of their activation days*/  
        
    for(i = 1; i <= NO_REGIONS; i++)
    {
        add_firm_data(&REGION_FIRM_DATA,
                i,0,0,
                0,0,0,0,0,0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0);
        
        add_household_data(&REGION_HOUSEHOLD_DATA,
                i,
                0,0,0,0,0,0,
                0,0,0,0,0,0,
                0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,1.0,1.0,1.0,1.0,1.0);
    }
    
    return 0;
        
}

/** \Eurostat_send_data_to_government()
 * \brief Eurostat send data: mean wage  ...
 */   
int Eurostat_send_data_to_government()
{
    //printf("AVERAGE_WAGE %f\n",AVERAGE_WAGE);
add_mean_wage_for_government_message(1,AVERAGE_WAGE);

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
int Eurostat_calculate_data()
{
    int i,j,m, x;

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
    
    double sum_consumption_good_supply;
    
    int counter_firms_in_region;
    
    /*delete the content of the memmory variables in order to store the data for the            new month*/
    NO_FIRMS =0;
    NO_FIRM_BIRTHS=0;
    NO_FIRM_DEATHS=0;
    
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
    
    PRICE_INDEX = 0.0;
    
    /*delete the content of the data arrays in order to store the data for the new          month*/
    //free(REGION_HOUSEHOLD_DATA);
    //free(REGION_FIRM_DATA);
    
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


    for(i = 1; i <= NO_REGIONS; i++)
    {
        add_firm_data(&REGION_FIRM_DATA,
                i,0,0,
                0,0,0,0,0,0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0);
        
        add_household_data(&REGION_HOUSEHOLD_DATA,
                i,
                0,0,0,0,0,0,
                0,0,0,0,0,0,
                0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,0.0,0.0,0.0,0.0,0.0,
                0.0,1.0,1.0,1.0,1.0,1.0);
    }
    
        //Reset total economy sums: these are updated inside the message loop to sum across all firms
        sum_total_debt_earnings_ratios = 0.0;
        sum_total_debt_equity_ratios   = 0.0;
        sum_total_labour_share_ratios  = 0.0;
        sum_total_sold_quantity        = 0.0;
        sum_total_output               = 0.0;
        sum_total_cum_revenue          = 0.0;
        sum_total_planned_output       = 0.0;
        sum_consumption_good_supply    = 0.0;

        //Reset the age distribution, and store the previous distribution (needed to compute the 1-period survival rates)
        for (i=0;i<60;i++)
        {
            FIRM_AGE_DISTRIBUTION_2_PERIOD_LAG[i]=FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i];
            FIRM_AGE_DISTRIBUTION_1_PERIOD_LAG[i]=FIRM_AGE_DISTRIBUTION[i];
            FIRM_AGE_DISTRIBUTION[i]=0;
            SURVIVAL_RATE[i]=0.0;
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
            counter_firms_in_region =0;
            REGION_FIRM_DATA.array[i].firms = 0;
            
            //Reset region sums: these are updated to sum across all firms in the region
            sum_region_debt_earnings_ratios = 0.0;
            sum_region_debt_equity_ratios   = 0.0;
            sum_region_labour_share_ratios  = 0.0;
            sum_region_sold_quantity        = 0.0;
            sum_region_output               = 0.0;
            sum_region_cum_revenue          = 0.0;
            sum_region_planned_output       = 0.0;
            
            START_FIRM_SEND_DATA_MESSAGE_LOOP
            
            if(firm_send_data_message->region_id == 
            REGION_FIRM_DATA.array[i].region_id)
            {
                REGION_FIRM_DATA.array[i].firms += 1;
                NO_FIRMS++;
                counter_firms_in_region++;
                
                REGION_FIRM_DATA.array[i].vacancies += 
                    firm_send_data_message->vacancies;
                NO_VACANCIES += firm_send_data_message->vacancies;;

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
                    firm_send_data_message->average_s_skill*
                    firm_send_data_message->employees;
                FIRM_AVERAGE_S_SKILL += 
                    firm_send_data_message->average_s_skill*
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
                
                /***************** Sum of: no_firm_births *********************/
                if (firm_send_data_message->age==1)
                {
                    //REGION_FIRM_DATA.array[i].no_firm_births++;
                    NO_FIRM_BIRTHS++;
                }
                
                /***************** Firm age distribution *********************/
                //add the firm's age to correct bin (we assume max. age is 60 months, all firms older than 60 are in the last bin)
                if (firm_send_data_message->age<60)
                {
                    FIRM_AGE_DISTRIBUTION[firm_send_data_message->age -1]++;
                }
                else
                {
                    FIRM_AGE_DISTRIBUTION[59]++;
                }
            }
            
            FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
            
            //Compute regional averages after the regional-specific message loop
            REGION_FIRM_DATA.array[i].average_debt_earnings_ratio = sum_region_debt_earnings_ratios/counter_firms_in_region;
            REGION_FIRM_DATA.array[i].average_debt_equity_ratio = sum_region_debt_equity_ratios/counter_firms_in_region;
            REGION_FIRM_DATA.array[i].labour_share_ratio = sum_region_labour_share_ratios/counter_firms_in_region;
            
            REGION_FIRM_DATA.array[i].monthly_sold_quantity = sum_region_sold_quantity/counter_firms_in_region;
            REGION_FIRM_DATA.array[i].monthly_output = sum_region_output/counter_firms_in_region;
            REGION_FIRM_DATA.array[i].monthly_revenue = sum_region_cum_revenue/counter_firms_in_region;
            REGION_FIRM_DATA.array[i].monthly_planned_output = sum_region_planned_output/counter_firms_in_region;
        
        }
        
        //Compute total averages after the region for-loop
        AVERAGE_DEBT_EARNINGS_RATIO = sum_total_debt_earnings_ratios/NO_FIRMS;
        AVERAGE_DEBT_EQUITY_RATIO = sum_total_debt_equity_ratios/NO_FIRMS;
        LABOUR_SHARE_RATIO  = sum_total_labour_share_ratios/NO_FIRMS;

        MONTHLY_SOLD_QUANTITY = sum_total_sold_quantity/NO_FIRMS;
        MONTHLY_OUTPUT = sum_total_output/NO_FIRMS;
        MONTHLY_REVENUE = sum_total_cum_revenue/NO_FIRMS;
        MONTHLY_PLANNED_OUTPUT = sum_total_planned_output/NO_FIRMS;

        /***************** Sum of: no_firm_deaths *********************/
        NO_FIRM_DEATHS = (NO_FIRMS - HISTORY_MONTHLY[0].no_firms - NO_FIRM_BIRTHS);        

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
        
        /***************** Firm survival rate *********************/
        //Def: The survival rate after x years (or months) is the percentage of all enterprise births of year n which are still active in year n+x.
        //This is related to the age. We measure the age in months.
        //We need information on: the age distribution in the current period, and the age distribution in the previous period
        //Then we take into account that the demographics moves along the distribution from left to right.
        //For each age, we then define the survival rate as the percentage.

        //1-month survival rate
        //The survival rate for firms that in the previous period had an age in the range [0,59] months:
        for (i=0; i<60; i++)
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
        //Generalized code for any x-period survival rate:
        //For each period x, we need bins i = 0...59
        //SURVIVAL_RATE_MULTIPERIOD[0][]: 1-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[1][]: 2-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[x][]: x+1-period survival rate
        //SURVIVAL_RATE_MULTIPERIOD[11][]: 11+1=12-period survival rate

        //In model.xml add these variables:
        // <variable><type>int</type><name>firm_age_distribution_multiperiod[12][60]</name><description>Multi-period firm_age_distributions.</description></variable>
        // <variable><type>double</type><name>survival_rate_multiperiod[12][60]</name><description>Multi-period survival rates. Definition: "The survival rate after x years is the percentage of all enterprise births of year n which are still active in year n+x." The 1st row survival_rate_multiperiod[0][.] equals survival_rate[], and contains the 1-period survival rates (for all age bins 0-59). The 2nd row survival_rate_multiperiod[1][.] contains the 2-period survival rates (for all age bins 0-59), etc.</description></variable>

        /* SURVIVAL_RATE |  AGE_DISTRIBUTION    | Compare to old AGE_DISTRIBUTION
         *      [x][i]   | [x+1][i+x+1]         | [0][i]
         * ----------------------------------------------------------------------
         * x=0: [0][i]   |   [1][i+1]           | [0][i]  | 1-period
         * x=1: [1][i]   |   [2][i+2]           | [0][i]  | 2-period
         * x=2: [2][i]   |   [3][i+3]           | [0][i]  | 3-period
         * x=3: [3][i]   |   [4][i+4]           | [0][i]  | 4-period
         */

        for (x=0; x<12; x++)
        {
            if (PRINT_DEBUG){fprintf(stdout,"Entering row %d: %d-period ahead survival rate\n", x, x+1);}
            
            for (i=0; i<60-x-1; i++)
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
            }
            for (i=60-x-1; i<60; i++)
            {
                if (PRINT_DEBUG){fprintf(stdout,"Entering element [%d][%d], padding element %d of SURVIVAL_RATE_MULTIPERIOD[%d][%d] with 0.0\n", x, i, i, x, i);}
                //padding
/*
                SURVIVAL_RATE_MULTIPERIOD[x][i]=0.0;
*/
            }
        }
        /******************************* end of general survival rate code *******************************/
        
    /*Create the REGIONAL data which is needed for controlling the results or sending           back to the Firms*/
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

    
    /*Create the GLOBAL data which is needed for controlling the results or sending         back to the Households*/
    
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

    return 0;
}

int Eurostat_read_tax_rates()
{
    int i;
    
    START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP
    for (i=0; i<27; i++)
    {
        if(government_tax_rates_message->gov_id == GOVERNMENT_TAX_RATES[i].gov_id)
        {
            GOVERNMENT_TAX_RATES[i].tax_rate_corporate = government_tax_rates_message->tax_rate_corporate;
            GOVERNMENT_TAX_RATES[i].tax_rate_hh_labour = government_tax_rates_message->tax_rate_hh_labour;
            GOVERNMENT_TAX_RATES[i].tax_rate_hh_capital = government_tax_rates_message->tax_rate_hh_capital;
            GOVERNMENT_TAX_RATES[i].tax_rate_vat = government_tax_rates_message->tax_rate_vat;
            break;
        }
    }
    FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP
    
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
            double wages;    
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
    int i;
    
    //Shift history backwards
    /*
     * history_monthly[4].GDP = history_monthly[3].GDP;     //t-4 gets filled with value from t-3
     * history_monthly[3].GDP = history_monthly[2].GDP;     //t-3 gets filled with value from t-3
     * history_monthly[2].GDP = history_monthly[1].GDP;     //t-2 gets filled with value from t-2
     * history_monthly[1].GDP = history_monthly[0].GDP;     //t-1 gets filled with value from t-1
     * history_monthly[0].GDP = GDP;                        //t gets filled with value from t
     */
    for (i=12; i>0; i--)
    {
    //t-i-1 gets filled with value from t-i
      HISTORY_MONTHLY[i].cpi = HISTORY_MONTHLY[i-1].cpi;
      HISTORY_MONTHLY[i].gdp = HISTORY_MONTHLY[i-1].gdp;
      HISTORY_MONTHLY[i].output = HISTORY_MONTHLY[i-1].output;
      HISTORY_MONTHLY[i].employment = HISTORY_MONTHLY[i-1].employment;
      HISTORY_MONTHLY[i].unemployment_rate = HISTORY_MONTHLY[i-1].unemployment_rate;
      HISTORY_MONTHLY[i].wages = HISTORY_MONTHLY[i-1].wages;
      HISTORY_MONTHLY[i].no_firms = HISTORY_MONTHLY[i-1].no_firms;
      HISTORY_MONTHLY[i].no_firm_births = HISTORY_MONTHLY[i-1].no_firm_births;
      HISTORY_MONTHLY[i].no_firm_deaths = HISTORY_MONTHLY[i-1].no_firm_deaths;
    }
    
    //Store first value of history: [0] gets filled with value from t
    HISTORY_MONTHLY[0].cpi = CPI;
    HISTORY_MONTHLY[0].gdp = GDP;                   
    HISTORY_MONTHLY[0].output = MONTHLY_OUTPUT;     
    HISTORY_MONTHLY[0].employment = EMPLOYED;       
    HISTORY_MONTHLY[0].unemployment_rate = UNEMPLOYMENT_RATE; 
    HISTORY_MONTHLY[0].wages = AVERAGE_WAGE;        
    HISTORY_MONTHLY[0].no_firms = NO_FIRMS;         
    HISTORY_MONTHLY[0].no_firm_births = NO_FIRM_BIRTHS; 
    HISTORY_MONTHLY[0].no_firm_deaths = NO_FIRM_DEATHS; 

    if (PRINT_LOG)
    {
        printf("Monthly data recorded by Eurostat:\n");
        printf(" - monthly CPI: %f\n", HISTORY_MONTHLY[0].cpi);
        printf(" - monthly GDP: %f\n", HISTORY_MONTHLY[0].gdp);
        printf(" - monthly output: %f\n", HISTORY_MONTHLY[0].output);
        printf(" - monthly average employment: %d\n", HISTORY_MONTHLY[0].employment);
        printf(" - monthly average unemployment rate: %f\n", HISTORY_MONTHLY[0].unemployment_rate);
        printf(" - monthly average wage: %f\n", HISTORY_MONTHLY[0].wages);
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
    int i;
    
    //Shift history backwards
    for (i=4; i>0; i--)
    {
      //t-i-1 gets filled with value from t-i
      HISTORY_QUARTERLY[i].cpi = HISTORY_QUARTERLY[i-1].cpi;
      HISTORY_QUARTERLY[i].gdp = HISTORY_QUARTERLY[i-1].gdp;
      HISTORY_QUARTERLY[i].output = HISTORY_QUARTERLY[i-1].output;
      HISTORY_QUARTERLY[i].employment = HISTORY_QUARTERLY[i-1].employment;
      HISTORY_QUARTERLY[i].unemployment_rate = HISTORY_QUARTERLY[i-1].unemployment_rate;
      HISTORY_QUARTERLY[i].wages = HISTORY_QUARTERLY[i-1].wages;
      HISTORY_QUARTERLY[i].no_firms = HISTORY_QUARTERLY[i-1].no_firms;
      HISTORY_QUARTERLY[i].no_firm_births = HISTORY_QUARTERLY[i-1].no_firm_births;
      HISTORY_QUARTERLY[i].no_firm_deaths = HISTORY_QUARTERLY[i-1].no_firm_deaths;
    }
    
    //Reset first elements for sum
    HISTORY_QUARTERLY[0].cpi=0.0;
    HISTORY_QUARTERLY[0].gdp=0.0;
    HISTORY_QUARTERLY[0].output=0.0;
    HISTORY_QUARTERLY[0].employment=0.0;
    HISTORY_QUARTERLY[0].unemployment_rate=0.0;
    HISTORY_QUARTERLY[0].wages=0.0;
    HISTORY_QUARTERLY[0].no_firms=0;
    HISTORY_QUARTERLY[0].no_firm_births=0;
    HISTORY_QUARTERLY[0].no_firm_deaths=0;

    //Store first value: construct quarterly sums from monthly history
    for (i=0; i<3; i++)
    {
        HISTORY_QUARTERLY[0].cpi                += HISTORY_MONTHLY[i].cpi;
        HISTORY_QUARTERLY[0].gdp                += HISTORY_MONTHLY[i].gdp;
        HISTORY_QUARTERLY[0].output             += HISTORY_MONTHLY[i].output;
        HISTORY_QUARTERLY[0].employment         += HISTORY_MONTHLY[i].employment;
        HISTORY_QUARTERLY[0].unemployment_rate  += HISTORY_MONTHLY[i].unemployment_rate;
        HISTORY_QUARTERLY[0].wages              += HISTORY_MONTHLY[i].wages;
        HISTORY_QUARTERLY[0].no_firms           += HISTORY_MONTHLY[i].no_firms;
        HISTORY_QUARTERLY[0].no_firm_births     += HISTORY_MONTHLY[i].no_firm_births;
        HISTORY_QUARTERLY[0].no_firm_deaths     += HISTORY_MONTHLY[i].no_firm_deaths;
    }
    //The following quarterly statistics are averages of monthly statistics
    HISTORY_QUARTERLY[0].cpi                    = HISTORY_QUARTERLY[0].cpi/3;
    HISTORY_QUARTERLY[0].employment             = HISTORY_QUARTERLY[0].employment/3;
    HISTORY_QUARTERLY[0].unemployment_rate      = HISTORY_QUARTERLY[0].unemployment_rate/3;
    HISTORY_QUARTERLY[0].wages                  = HISTORY_QUARTERLY[0].wages/3;
    HISTORY_QUARTERLY[0].no_firms               = HISTORY_QUARTERLY[0].no_firms/3;
    
    if (PRINT_LOG)
    {
        printf("Quarterly data recorded by Eurostat:\n");
        printf(" - quarterly CPI: %f\n", HISTORY_QUARTERLY[0].cpi);
        printf(" - quarterly GDP: %f\n", HISTORY_QUARTERLY[0].gdp);
        printf(" - quarterly output: %f\n", HISTORY_QUARTERLY[0].output);
        printf(" - quarterly average employment: %d\n", HISTORY_QUARTERLY[0].employment);
        printf(" - quarterly average unemployment rate: %f\n", HISTORY_QUARTERLY[0].unemployment_rate);
        printf(" - quarterly average wage: %f\n", HISTORY_QUARTERLY[0].wages);
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
    MONTHLY_GROWTH_RATES.cpi                       = 0.0;
    MONTHLY_GROWTH_RATES.gdp                       = 0.0; 
    MONTHLY_GROWTH_RATES.output                    = 0.0;
    MONTHLY_GROWTH_RATES.employment                = 0.0;
    MONTHLY_GROWTH_RATES.unemployment_rate         = 0.0;
    MONTHLY_GROWTH_RATES.wages                     = 0.0;
    MONTHLY_GROWTH_RATES.no_firms                  = 0.0;
    MONTHLY_GROWTH_RATES.no_firm_births            = 0.0;
    MONTHLY_GROWTH_RATES.no_firm_deaths            = 0.0;
    
    ANNUAL_GROWTH_RATES_MONTHLY.cpi                = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.gdp                = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.output             = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.employment         = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate  = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.wages              = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.no_firms           = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.no_firm_births     = 0.0;
    ANNUAL_GROWTH_RATES_MONTHLY.no_firm_deaths     = 0.0;
    
    //compute monthly rates of change: change over the previous month
    if(HISTORY_MONTHLY[1].cpi>0.0)              {MONTHLY_GROWTH_RATES.cpi                       = (HISTORY_MONTHLY[0].cpi / HISTORY_MONTHLY[1].cpi -1)*100;}
    if(HISTORY_MONTHLY[1].gdp>0.0)              {MONTHLY_GROWTH_RATES.gdp                       = (HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[1].gdp -1)*100;}
    if(HISTORY_MONTHLY[1].output>0.0)           {MONTHLY_GROWTH_RATES.output                    = (HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[1].output  -1)*100;}
    if(HISTORY_MONTHLY[1].employment>0)         {MONTHLY_GROWTH_RATES.employment                = (HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[1].employment  -1)*100;}
    if(HISTORY_MONTHLY[1].unemployment_rate>0.0){MONTHLY_GROWTH_RATES.unemployment_rate         = (HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[1].unemployment_rate  -1)*100;}
    if(HISTORY_MONTHLY[1].wages>0.0)            {MONTHLY_GROWTH_RATES.wages                     = (HISTORY_MONTHLY[0].wages / HISTORY_MONTHLY[1].wages  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firms>0)           {MONTHLY_GROWTH_RATES.no_firms                  = (HISTORY_MONTHLY[0].no_firms / HISTORY_MONTHLY[1].no_firms  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firm_births>0)     {MONTHLY_GROWTH_RATES.no_firm_births            = (HISTORY_MONTHLY[0].no_firm_births / HISTORY_MONTHLY[1].no_firm_births  -1)*100;}
    if(HISTORY_MONTHLY[1].no_firm_deaths>0)     {MONTHLY_GROWTH_RATES.no_firm_deaths            = (HISTORY_MONTHLY[0].no_firm_deaths / HISTORY_MONTHLY[1].no_firm_deaths  -1)*100;}   

    //compute annual rates of change over the previous 12 months: respective to same month in previous year
    if(HISTORY_MONTHLY[12].cpi>0.0)             {ANNUAL_GROWTH_RATES_MONTHLY.cpi                = (HISTORY_MONTHLY[0].cpi / HISTORY_MONTHLY[12].cpi -1)*100;}
    if(HISTORY_MONTHLY[12].gdp>0.0)             {ANNUAL_GROWTH_RATES_MONTHLY.gdp                = (HISTORY_MONTHLY[0].gdp / HISTORY_MONTHLY[12].gdp  -1)*100;}
    if(HISTORY_MONTHLY[12].output>0.0)          {ANNUAL_GROWTH_RATES_MONTHLY.output             = (HISTORY_MONTHLY[0].output / HISTORY_MONTHLY[12].output  -1)*100;}
    if(HISTORY_MONTHLY[12].employment>0)        {ANNUAL_GROWTH_RATES_MONTHLY.employment         = (HISTORY_MONTHLY[0].employment / HISTORY_MONTHLY[12].employment  -1)*100;}
    if(HISTORY_MONTHLY[12].unemployment_rate>0) {ANNUAL_GROWTH_RATES_MONTHLY.unemployment_rate  = (HISTORY_MONTHLY[0].unemployment_rate / HISTORY_MONTHLY[12].unemployment_rate  -1)*100;}
    if(HISTORY_MONTHLY[12].wages>0)             {ANNUAL_GROWTH_RATES_MONTHLY.wages              = (HISTORY_MONTHLY[0].wages / HISTORY_MONTHLY[12].wages  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firms>0)          {ANNUAL_GROWTH_RATES_MONTHLY.no_firms           = (HISTORY_MONTHLY[0].no_firms / HISTORY_MONTHLY[12].no_firms  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firm_births>0)    {ANNUAL_GROWTH_RATES_MONTHLY.no_firm_births     = (HISTORY_MONTHLY[0].no_firm_births / HISTORY_MONTHLY[12].no_firm_births  -1)*100;}
    if(HISTORY_MONTHLY[12].no_firm_deaths>0)    {ANNUAL_GROWTH_RATES_MONTHLY.no_firm_deaths     = (HISTORY_MONTHLY[0].no_firm_deaths / HISTORY_MONTHLY[12].no_firm_deaths  -1)*100;}

    return 0;
}

/* \fn: int Eurostat_compute_growth_rates_quarterly()
 * \brief: Computes rates of change from the current history at the end of every quarterly.
 */
int Eurostat_compute_growth_rates_quarterly()
{
    QUARTERLY_GROWTH_RATES.cpi                         = 0.0;
    QUARTERLY_GROWTH_RATES.gdp                         = 0.0;
    QUARTERLY_GROWTH_RATES.output                      = 0.0;
    QUARTERLY_GROWTH_RATES.employment                  = 0.0;
    QUARTERLY_GROWTH_RATES.unemployment_rate           = 0.0;
    QUARTERLY_GROWTH_RATES.wages                       = 0.0;
    QUARTERLY_GROWTH_RATES.no_firms                    = 0.0;
    QUARTERLY_GROWTH_RATES.no_firm_births              = 0.0;
    QUARTERLY_GROWTH_RATES.no_firm_deaths              = 0.0;
    
    ANNUAL_GROWTH_RATES_QUARTERLY.cpi                  = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.gdp                  = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.output               = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.employment           = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate    = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.wages                = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firms             = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_births       = 0.0;
    ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_deaths       = 0.0;

    //compute quarterly rates of change: change over the previous quarter
    if(HISTORY_QUARTERLY[1].cpi>0.0)                {QUARTERLY_GROWTH_RATES.cpi                         = (HISTORY_QUARTERLY[0].cpi / HISTORY_QUARTERLY[1].cpi -1)*100;}
    if(HISTORY_QUARTERLY[1].gdp>0.0)                {QUARTERLY_GROWTH_RATES.gdp                         = (HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[1].gdp  -1)*100;}
    if(HISTORY_QUARTERLY[1].output>0.0)             {QUARTERLY_GROWTH_RATES.output                      = (HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[1].output  -1)*100;}
    if(HISTORY_QUARTERLY[1].employment>0)           {QUARTERLY_GROWTH_RATES.employment                  = (HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[1].employment  -1)*100;}
    if(HISTORY_QUARTERLY[1].unemployment_rate>0.0)  {QUARTERLY_GROWTH_RATES.unemployment_rate           = (HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[1].unemployment_rate  -1)*100;}
    if(HISTORY_QUARTERLY[1].wages>0.0)              {QUARTERLY_GROWTH_RATES.wages                       = (HISTORY_QUARTERLY[0].wages / HISTORY_QUARTERLY[1].wages  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firms>0)             {QUARTERLY_GROWTH_RATES.no_firms                    = (HISTORY_QUARTERLY[0].no_firms / HISTORY_QUARTERLY[1].no_firms  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firm_births>0)       {QUARTERLY_GROWTH_RATES.no_firm_births              = (HISTORY_QUARTERLY[0].no_firm_births / HISTORY_QUARTERLY[1].no_firm_births  -1)*100;}
    if(HISTORY_QUARTERLY[1].no_firm_deaths>0)       {QUARTERLY_GROWTH_RATES.no_firm_deaths              = (HISTORY_QUARTERLY[0].no_firm_deaths / HISTORY_QUARTERLY[1].no_firm_deaths  -1)*100;}
    
    //compute annual rates of change over the previous 4 quarters: respective to same quarter in previous year
    if(HISTORY_QUARTERLY[4].cpi>0.0)                {ANNUAL_GROWTH_RATES_QUARTERLY.cpi                  = (HISTORY_QUARTERLY[0].cpi / HISTORY_QUARTERLY[4].cpi -1)*100;}    
    if(HISTORY_QUARTERLY[4].gdp>0.0)                {ANNUAL_GROWTH_RATES_QUARTERLY.gdp                  = (HISTORY_QUARTERLY[0].gdp / HISTORY_QUARTERLY[4].gdp  -1)*100;}
    if(HISTORY_QUARTERLY[4].output>0.0)             {ANNUAL_GROWTH_RATES_QUARTERLY.output               = (HISTORY_QUARTERLY[0].output / HISTORY_QUARTERLY[4].output  -1)*100;}
    if(HISTORY_QUARTERLY[4].employment>0)           {ANNUAL_GROWTH_RATES_QUARTERLY.employment           = (HISTORY_QUARTERLY[0].employment / HISTORY_QUARTERLY[4].employment  -1)*100;}
    if(HISTORY_QUARTERLY[4].unemployment_rate>0.0)  {ANNUAL_GROWTH_RATES_QUARTERLY.unemployment_rate    = (HISTORY_QUARTERLY[0].unemployment_rate / HISTORY_QUARTERLY[4].unemployment_rate  -1)*100;}
    if(HISTORY_QUARTERLY[4].wages>0.0)              {ANNUAL_GROWTH_RATES_QUARTERLY.wages                = (HISTORY_QUARTERLY[0].wages / HISTORY_QUARTERLY[4].wages  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firms>0)             {ANNUAL_GROWTH_RATES_QUARTERLY.no_firms             = (HISTORY_QUARTERLY[0].no_firms / HISTORY_QUARTERLY[4].no_firms  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firm_births>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_births       = (HISTORY_QUARTERLY[0].no_firm_births / HISTORY_QUARTERLY[4].no_firm_births  -1)*100;}
    if(HISTORY_QUARTERLY[4].no_firm_deaths>0)       {ANNUAL_GROWTH_RATES_QUARTERLY.no_firm_deaths       = (HISTORY_QUARTERLY[0].no_firm_deaths / HISTORY_QUARTERLY[4].no_firm_deaths  -1)*100;}
    
    return 0;
}

/* \fn: int Eurostat_firm_creation()
 * \brief: The firm creation process
 */
int Eurostat_firm_creation()
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
    
    return 0;
}
