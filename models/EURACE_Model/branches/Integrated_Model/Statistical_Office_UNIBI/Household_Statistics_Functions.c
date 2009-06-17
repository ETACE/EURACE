#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/* \fn: int Household_initialization()
 * \brief Function to initialize. Note: this overwrites pop settings for the NEIGHBORING_REGION_IDS.
 */
int Household_initialization()
{   
    //ADD HERE SOME FUNCTION THAT SETS THE NEIGHBORHOOD STRUCTURE
    int j;
    int k=2; //each region has k neighbors
    
    reset_int_array(&NEIGHBORING_REGION_IDS);

    //add the region_id of regions that are in the household's neighbourhood
    if (REGION_ID>k)
    {
        //set neighbourhood_regions={REGION_ID-k,...,REGION_ID-1}
        for (j=1; j<=k; j++) 
            add_int(&NEIGHBORING_REGION_IDS,REGION_ID-j);
    }
    if (REGION_ID<=k)
    {
        //set neighbourhood_regions={REGION_ID+1,...,REGION_ID+k}
        for (j=1; j<=k; j++) 
            add_int(&NEIGHBORING_REGION_IDS,REGION_ID+j);
    }

    return 0;   
}

/*************************************Household Role: Statistics *********************************/
/** \fn Household_read_policy_announcements()
 * \brief This function reads messages send by the government announcing tax rates, benefits, transfer payments and subsidies.
 */
int Household_read_policy_announcements()
{
    /*Read tax announcement*/
    /*Read unemployment benefit announcement*/
    /*Read transfer announcement*/
    /*Read subsidy announcement*/
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    if(policy_announcement_message->gov_id == GOV_ID)
    {
        TAX_RATE_HH_LABOUR  = policy_announcement_message->tax_rate_hh_labour;
        TAX_RATE_HH_CAPITAL = policy_announcement_message->tax_rate_hh_capital;

        /*This is the endogeneous unemployment percentage (the global parameter is: GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT)*/
        UNEMPLOYMENT_BENEFIT_PCT = policy_announcement_message->unemployment_benefit_pct;
        TRANSFER_PAYMENT = policy_announcement_message->hh_transfer_payment;
        SUBSIDY_PAYMENT = policy_announcement_message->hh_subsidy_payment;
    }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP

    return 0;
}

/** \fn Household_receive_data()
 * \brief Household receives macro data from Eurostat and bankruptcy messages from Firms
 */
int Household_receive_data()
{
    int i;

    START_BANKRUPTCY_MESSAGE_LOOP
       //Resetting the quantity in portfolio to zero:
        for (i=0; i<ASSETSOWNED.size; i++)
        {
            if (ASSETSOWNED.array[i].id == bankruptcy_message->firm_id)
            {
                ASSETSOWNED.array[i].quantity=0;
                ASSETSOWNED.array[i].lastPrice=0.0;
            }
        }
    FINISH_BANKRUPTCY_MESSAGE_LOOP  

    return 0;
}

/** \fn Household_send_data_to_Market_Research()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Household_send_data_to_Eurostat()
{   
    add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
    WAGE, SPECIFIC_SKILL);
    
    /*AIX*/
    if ((SWITCH_FLOW_CONSISTENCY_CHECK)||(SWITCH_STOCK_CONSISTENCY_CHECK))
    {
        //Set these to correct expressions:
        MONTHLY_CONSUMPTION_EXPENDITURE=0.0;
        TOTAL_ASSETS=0.0;
        TOTAL_LIABILITIES=0.0;
        TOTAL_INCOME=0.0;
        TOTAL_EXPENSES=0.0;

        //printf("\n Household %d: my WAGE=%2.2f.\n", ID, WAGE);
        add_household_balance_sheet_message(PAYMENT_ACCOUNT, 
                WAGE, CUM_TOTAL_DIVIDENDS, MONTHLY_CONSUMPTION_EXPENDITURE, TAX_PAYMENT, 
                TOTAL_ASSETS, TOTAL_LIABILITIES, TOTAL_INCOME, TOTAL_EXPENSES);
    }
    
    return 0;
}

