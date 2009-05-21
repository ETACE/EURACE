    #include "../header.h"
    #include "../Central_Bank_agent_header.h"
    #include "../my_library_header.h"
    
    
    
    /************Central_Bank Role: manage accounts for Governments and commercial banks********************************/
/** \fn Central_Bank_read_account_update()
 * \brief 
 */
int Central_Bank_read_account_update()
{
    int i;

    START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    //Search the correct account
    for (i=0;i<ACCOUNTS.size;i++)
    {       
        if(ACCOUNTS.array[i].id == central_bank_account_update_message->id)
            {
                 ACCOUNTS.array[i].payment_account = central_bank_account_update_message->payment_account;
            }
            
        //if  (central_bank_account_update_message->payment_account<0)
          //  { 
                 TOTAL_ECB_DEBT+=fabs(central_bank_account_update_message->payment_account);
          //  }                  
            
    }
    FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    return 0;
}

/** \fn Central_Bank_send_data_to_Eurostat()
 * \brief 
 */
int Central_Bank_send_data_to_Eurostat()
{
    if (SWITCH_STOCK_CONSISTENCY_CHECK)
    {
        //********** Stocks
        //GOV_BOND_HOLDINGS=0.0;
        NR_GOV_BONDS=0;
        PAYMENT_ACCOUNT_PRIVATE_SECTOR=0.0;
        PAYMENT_ACCOUNT_PUBLIC_SECTOR=0.0; 
        FIAT_MONEY=0.0;
        BANK_INTEREST=0.0;
        GOV_INTEREST=0.0;
        
        //********** Flows
        //GOV_BOND_PURCHASE=0.0;
        DIVIDEND_PAYMENT=0.0;
        TOTAL_ASSETS=0.0;
        TOTAL_LIABILITIES=0.0;
        TOTAL_INCOME=0.0;
        TOTAL_EXPENSES=0.0;
    
        add_ecb_balance_sheet_message(GOV_BOND_HOLDINGS, NR_GOV_BONDS,
                TOTAL_ECB_DEBT, PAYMENT_ACCOUNT_PRIVATE_SECTOR, PAYMENT_ACCOUNT_PUBLIC_SECTOR, 
                FIAT_MONEY, BANK_INTEREST, GOV_INTEREST, GOV_BOND_PURCHASE, DIVIDEND_PAYMENT, 
                TOTAL_ASSETS, TOTAL_LIABILITIES, TOTAL_INCOME, TOTAL_EXPENSES);
    }   
    return 0;
}
