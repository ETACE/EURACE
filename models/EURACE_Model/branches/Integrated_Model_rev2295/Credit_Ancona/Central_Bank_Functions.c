
    #include "../Central_Bank_agent_header.h"
    #include "../my_library_header.h"
    #include "../header.h"    
    
    
    /************Central_Bank Role: manage accounts for Governments and commercial banks********************************/
/** \fn Central_Bank_read_account_update()
 * \brief 
 */

int Central_Bank_monetary_policy()
{
    double inflation, gdp, unemployment_rate;

    ECB_INTEREST_RATE = ECB_INTEREST_RATE + 0.001;
 
    START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
        inflation = eurostat_send_macrodata_message->inflation;
        gdp = eurostat_send_macrodata_message->gdp;
        unemployment_rate = eurostat_send_macrodata_message->unemployment_rate;
    FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP 
 
    
    add_policy_rate_message(ECB_INTEREST_RATE);

    return 0;
}

int Central_Bank_read_fiat_money_requests()
{

    //Read the bond emission -> fiat money request from governments
    START_ISSUE_BONDS_TO_ECB_MESSAGE_LOOP
        FIAT_MONEY += issue_bonds_to_ecb_message->nominal_value*issue_bonds_to_ecb_message->quantity;
        BOND_HOLDINGS_VALUE += issue_bonds_to_ecb_message->nominal_value;
    FINISH_ISSUE_BONDS_TO_ECB_MESSAGE_LOOP


    //Read the fiat money request from governments
    //request_fiat_money_message(nominal_value);
    START_REQUEST_FIAT_MONEY_MESSAGE_LOOP
        FIAT_MONEY += request_fiat_money_message->nominal_value;
    FINISH_REQUEST_FIAT_MONEY_MESSAGE_LOOP


    return 0;
}

/** \fn Central_Bank_read_account_update()
 * \brief 
 */
int Central_Bank_read_account_update()
{
    int i;
    
    TOTAL_ECB_DEBT=0.0;
    ECB_DEPOSITS=0.0;

    START_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    //Search the correct account and update the value
    for (i=0;i<ACCOUNTS_BANKS.size;i++)
    {       
        if(ACCOUNTS_BANKS.array[i].id == bank_to_central_bank_account_update_message->id)
            {
                 ACCOUNTS_BANKS.array[i].payment_account = bank_to_central_bank_account_update_message->payment_account;
            }
        
        //The sum of negative payment_account values
        if (bank_to_central_bank_account_update_message->payment_account<0.0)
            TOTAL_ECB_DEBT += fabs(bank_to_central_bank_account_update_message->payment_account);
                    
        //Total deposits at ECB
        ECB_DEPOSITS += bank_to_central_bank_account_update_message->payment_account;
    }
    FINISH_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP


    START_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    //Search the correct account and update the value
    for (i=0;i<ACCOUNTS_GOVS.size;i++)
    {       
        if(ACCOUNTS_GOVS.array[i].id == gov_to_central_bank_account_update_message->id)
            {
                 ACCOUNTS_GOVS.array[i].payment_account = gov_to_central_bank_account_update_message->payment_account;
            }

        //Total deposits at ECB
        ECB_DEPOSITS += gov_to_central_bank_account_update_message->payment_account;
    }
    FINISH_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP

    return 0;
}

