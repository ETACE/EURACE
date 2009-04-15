#include "../header.h"
#include "../Household_agent_header.h"
#include "../my_library_header.h"



/************************************ Household agent functions ************************************/
/*************************************Household Role: Statistics *********************************/

/** \fn Household_receive_data()
 * \brief Household is importing macro data from Eurostat to use in behavioral rules.
 */
int Household_receive_data()
{

    return 0;
}

/** \fn Household_send_data_to_Market_Research()
 * \brief Firms send data to Market Research: controlling results and creating macro data
 */
int Household_send_data_to_Eurostat()
{   
    add_household_send_data_message(ID, REGION_ID, GENERAL_SKILL,EMPLOYEE_FIRM_ID,
    WAGE, SPECIFIC_SKILL);
        
    if (SWITCH_STOCK_CONSISTENCY_CHECK)
    {
        //Set these to correct expressions:
        GOV_BOND_HOLDINGS=0.0;
        NR_GOV_BONDS=0;
        NR_FIRM_SHARES=0;
        GOV_INTEREST=0.0;
        STOCK_SALES=0.0;
//      MONTHLY_CONSUMPTION_EXPENDITURE=0.0;
        STOCK_PURCHASES=0.0;
        TOTAL_ASSETS=0.0;
        TOTAL_LIABILITIES=0.0;
        TOTAL_INCOME=0.0;
        TOTAL_EXPENSES=0.0;

        add_household_balance_sheet_message(PAYMENT_ACCOUNT, GOV_BOND_HOLDINGS, NR_GOV_BONDS, NR_FIRM_SHARES,
                WAGE, GOV_INTEREST, STOCK_SALES,
                CUM_TOTAL_DIVIDENDS, MONTHLY_CONSUMPTION_EXPENDITURE, TAX_PAYMENT, STOCK_PURCHASES, 
                TOTAL_ASSETS, TOTAL_LIABILITIES, TOTAL_INCOME, TOTAL_EXPENSES);
    }
    
    return 0;
}

