#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/* \fn: int Household_initialization()
 * \brief Function to initialize. Note: this overwrites pop settings for the NEIGHBORING_REGION_IDS.
 */
int Household_initialization()
{   
    //ADD HERE SOME FUNCTIONS THAT SET THE NEIGHBORHOOD STRUCTURE OF REGIONS

    /*********** NETWORK: complete graph **************/
/*    
    int j, k=TOTAL_REGIONS; //total number of regions
    
    reset_int_array(&NEIGHBORING_REGION_IDS);
    
    for (j=1; j<=k; j++) 
        add_int(&NEIGHBORING_REGION_IDS,j);
*/

    /*********** NETWORK: k neighbors with wrap-around */
    int j, k=2;
    for (j=1; j<=k; j++)
    { 
        if((REGION_ID+j)<=TOTAL_REGIONS)
            add_int(&NEIGHBORING_REGION_IDS,(REGION_ID+j));
        else
            add_int(&NEIGHBORING_REGION_IDS,(REGION_ID+j)%TOTAL_REGIONS);
    }
    /*********** NETWORK: k neighbors without wrap-around */
    //for (REGION_ID>k): use backward neighborhood
    //for (REGION_ID<=): use forward neighborhood
    /******************************************************/
/*    
    int j, k=2; //each region has k neighbors
    
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
*/

 
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
        SUBSIDY_PCT = policy_announcement_message->hh_subsidy_pct;
        
        
    }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG_CONSUMPTION)
    {
        printf("\n Household_read_policy_announcements ID: %d",ID);
        printf("\n \t TAX_RATE_HH_LABOUR: %f TAX_RATE_HH_CAPITAL: %f",TAX_RATE_HH_LABOUR,TAX_RATE_HH_CAPITAL);
        printf("\n \t UNEMPLOYMENT_BENEFIT_PCT: %f TRANSFER_PAYMENT: %f SUBSIDY_PCT: %f", UNEMPLOYMENT_BENEFIT_PCT, TRANSFER_PAYMENT, SUBSIDY_PCT);
        getchar();
    }
    #endif
    
   
    
    
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
                //ASSETSOWNED.array[i].lastPrice=0.0;
            }
        }
    FINISH_BANKRUPTCY_MESSAGE_LOOP  

    #ifdef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Household receive data ID: %d",ID);     
    }          
    #endif
    
    return 0;
}

/** \fn Household_send_data_to_Eurostat()
 * \brief Households send data to Eurostat
 */
int Household_send_data_to_Eurostat()
{   
    add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
    WAGE, SPECIFIC_SKILL);
    
    return 0;
}


/** \fn Household_read_data_from_Eurostat()
 * \brief Households read data from Eurostat
 */
int Household_read_data_from_Eurostat()
{   
    //The household reads the mean wage in its region (we assume this is a country)
    START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
            if(data_for_government_message->region_id==REGION_ID)
            {
                //Read region mean wage
                REGION_WIDE_MEAN_WAGE = data_for_government_message->mean_wage;
            }
    FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
    
    return 0;
}
