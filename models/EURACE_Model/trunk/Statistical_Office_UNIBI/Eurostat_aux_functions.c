/*********************************
 * Eurostat_aux_functions.c 
 * Eurostat auxiliary functions.
 * *********************************
 * History:
 * 16/09/08 Sander 
 *********************************/
#include <limits.h> //required to test for max. double: LONG_MAX
#include "../header.h"
#include "../Eurostat_agent_header.h"
#include "Eurostat_aux_header.h"

#define MAX_SURVIVAL_PERIODS 12 //length of the array to store the survival rate distribution, nr of bins
#define MAX_FIRM_AGE 60			//length of the array to store the firm age distribution, nr of bins

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
//    	printf("\n Entering region %d", i+1);
    	
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
		if(firm_send_data_message->region_id ==	REGION_FIRM_DATA.array[i].region_id)
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

/*\fn: void Eurostat_calc_price_index(void)
 * \brief: Compute price index for regions.
 * Q: REGION_FIRM_DATA.array[i].monthly_sold_quantity: total quantity sold in region
 * q: firm_send_data_message->cum_total_sold_quantity: Monthly sum of sold quantities in the different malls (= total quantity sold in all regions)             
 * weight=q/Q
 * p: firm_send_data_message->price
 * p_previous: firm_send_data_message->price_previous
 * sum_1= sum_firms(weight * p * q)
 * sum_2= sum_firms(weight * p_previous * q)
 * PRICE_INDEX =sum_1/sum2;
 * Assumed: firm uses the same price in all regions
 * firm_send_data_message->cum_total_sold_quantity refers to the firms own region.
 * TODO: Change this to use heterogenous prices for the regional sales
 * firm_send_data_message->mall_sales_array[mall_id].quantity
 * firm_send_data_message->mall_sales_array[mall_id].price
*/
void Eurostat_calc_price_index(void)
{
	int i;
	double weight, price, price_last_month, quantity, sum_1, sum_2;
	
    CPI = 0.0;
        
    /*Store the region data of the firms*/
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {                    
    	/*Reset sums for each region*/
	    sum_1 = 0.0;
	    sum_2 = 0.0;
	    
	    /*Start a new reading loop*/
	    START_FIRM_SEND_DATA_MESSAGE_LOOP
	        if(firm_send_data_message->region_id == REGION_FIRM_DATA.array[i].region_id)
	        {
	        	quantity = firm_send_data_message->cum_total_sold_quantity;
	        	weight = quantity/REGION_FIRM_DATA.array[i].monthly_sold_quantity;
	            price = firm_send_data_message->price;
	            price_last_month = firm_send_data_message->price_last_month;
	            sum_1 += weight * price * quantity;
	            sum_2 += weight * price_last_month * quantity;
	        }
	    FINISH_FIRM_SEND_DATA_MESSAGE_LOOP
	    
	    REGION_FIRM_DATA.array[i].cpi_last_month = REGION_FIRM_DATA.array[i].cpi;
	    REGION_FIRM_DATA.array[i].cpi = sum_1/sum_2;
	    
	    if (PRINT_DEBUG)
	    {
	        fprintf(stdout,"CPI for region %d = %f\n", i, REGION_FIRM_DATA.array[i].cpi);
	    }
    }
    
    //Compute overall economy-wide price index: loop over regions
    sum_1 = 0.0;
    sum_2 = 0.0;
    for(i = 0; i< REGION_FIRM_DATA.size; i++)
    {
    	quantity = REGION_FIRM_DATA.array[i].monthly_sold_quantity;
    	weight = quantity/MONTHLY_SOLD_QUANTITY;
        price = REGION_FIRM_DATA.array[i].cpi;
        price_last_month = REGION_FIRM_DATA.array[i].cpi_last_month;
        sum_1 += weight * price * quantity;
        sum_2 += weight * price_last_month * quantity;
    }
    CPI = sum_1/sum_2;
    if (PRINT_DEBUG)
    {
        fprintf(stdout,"CPI = %f\n", CPI);
    }
}
    
void Eurostat_calc_firm_population(void)
{
	int i;

    /* Reset the content of the memory variables*/
    NO_FIRMS =0;
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
    NO_FIRM_DEATHS = -1*(NO_FIRMS - HISTORY_MONTHLY[0].no_firms - NO_FIRM_BIRTHS);        
    for(i = 0; i < REGION_FIRM_DATA.size; i++)
    {
    	REGION_FIRM_DATA.array[i].no_firm_deaths = 
    		-1*(REGION_FIRM_DATA.array[i].no_firms - HISTORY_MONTHLY[0].region_data.array[i].no_firms - REGION_FIRM_DATA.array[i].no_firm_births); 
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
        //Using matrix-to-array transalation:
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

/* \fn: void Eurostat_measure_recession(void)
 * \brief: Function to measure the start, duration and end of a recession.
 */
void Eurostat_measure_recession(void)
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
        EXPORTS[i]=0.0;
        IMPORTS[i]=0.0;
        for (j=0; j<NO_REGIONS; j++)
        {
            index=i*NO_REGIONS+j;
            EXPORT_MATRIX[index]=0.0;
        }
    }
    
    //read in all data
    START_MALL_DATA_MESSAGE_LOOP
        index = (mall_data_message->firm_region-1)*NO_REGIONS + (mall_data_message->household_region-1);        
        EXPORT_MATRIX[index] += mall_data_message->value;
    FINISH_MALL_DATA_MESSAGE_LOOP
    
    //sum total exports (row sum) and imports (column sum)
    for (i=0; i<NO_REGIONS; i++)
    {
        for (j=0; j<NO_REGIONS; j++)
        {
            if(i!=j)
            {
                index=i*NO_REGIONS+j;
                EXPORTS[i] += EXPORT_MATRIX[index];
                IMPORTS[j] += EXPORT_MATRIX[index];
            }
        }
    }
   
}

