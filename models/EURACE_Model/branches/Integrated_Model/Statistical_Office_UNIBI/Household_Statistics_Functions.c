#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/

/** \fn Household_receive_data()
 * \brief Household receives macro data from Eurostat and bankruptcy messages from Firms
 */
int Household_receive_data()
{
    START_BANKRUPTCY_MESSAGE_LOOP
       add_int(&LIST_OF_BANKRUPT_FIRMS, bankruptcy_message->firm_id);
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
        GOV_BOND_HOLDINGS=0.0;
        NR_GOV_BONDS=0;
        NR_FIRM_SHARES=0;
        GOV_INTEREST=0.0;
        STOCK_SALES=0.0;
        MONTHLY_CONSUMPTION_EXPENDITURE=0.0;
        STOCK_PURCHASES=0.0;
        TOTAL_ASSETS=0.0;
        TOTAL_LIABILITIES=0.0;
        TOTAL_INCOME=0.0;
        TOTAL_EXPENSES=0.0;

        //printf("\n Household %d: my WAGE=%2.2f.\n", ID, WAGE);
        add_household_balance_sheet_message(PAYMENT_ACCOUNT, GOV_BOND_HOLDINGS, NR_GOV_BONDS, NR_FIRM_SHARES, 
                WAGE, GOV_INTEREST, STOCK_SALES,
                CUM_TOTAL_DIVIDENDS, MONTHLY_CONSUMPTION_EXPENDITURE, TAX_PAYMENT, STOCK_PURCHASES, 
                TOTAL_ASSETS, TOTAL_LIABILITIES, TOTAL_INCOME, TOTAL_EXPENSES);
    }
    
    return 0;
}

