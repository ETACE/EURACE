#include "../header.h"     
#include "../Central_Bank_agent_header.h"
#include "../my_library_header.h"

    
    
    /************Central_Bank Role: manage accounts for Governments and commercial banks********************************/
/** \fn Central_Bank_read_account_update()
 * \brief 
 */

int Central_Bank_monetary_policy()
{
	double inflation=0.0;
 	double gdp=0.0;
	double unemployment_rate=0.0;

 
    START_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP
        inflation = eurostat_send_macrodata_message->inflation;
        gdp = eurostat_send_macrodata_message->gdp;
        unemployment_rate = eurostat_send_macrodata_message->unemployment_rate;
    FINISH_EUROSTAT_SEND_MACRODATA_MESSAGE_LOOP 
    
    ECB_INTEREST_RATE = 0.05;
    
    add_policy_rate_message(ECB_INTEREST_RATE);

    #ifndef _DEBUG_MODE    
    if (PRINT_DEBUG)
    {
        printf("\n Central_Bank_monetary_policy ID: %d",ID); 
        printf("\n\t inflation: %f gdp: %f unemployment_rate: %f",inflation,gdp,unemployment_rate);
        printf("\n\t ECB_INTEREST_RATE: %f",ECB_INTEREST_RATE);   
        getchar(); 
    }              
    #endif    
    return 0;
}

int Central_Bank_read_fiat_money_requests()
{

    //Read the bond emission -> fiat money request from governments
    START_ISSUE_BONDS_TO_ECB_MESSAGE_LOOP
        FIAT_MONEY_GOVS += issue_bonds_to_ecb_message->nominal_value;
        BOND_HOLDINGS_VALUE += issue_bonds_to_ecb_message->nominal_value;
        NR_GOV_BONDS += issue_bonds_to_ecb_message->quantity;
    FINISH_ISSUE_BONDS_TO_ECB_MESSAGE_LOOP


    //Read the fiat money request from governments
    //request_fiat_money_message(nominal_value);
    START_REQUEST_FIAT_MONEY_MESSAGE_LOOP
        FIAT_MONEY_GOVS += request_fiat_money_message->nominal_value;
    FINISH_REQUEST_FIAT_MONEY_MESSAGE_LOOP


    return 0;
}

/** \fn Central_Bank_read_account_update()
 * \brief 
 */
int Central_Bank_read_account_update()
{
    int i;

    #ifndef _DEBUG_MODE
       int bank_mesg_count=0; //debug
        int gov_mesg_count=0; //debug
    #endif
        FILE * file1=NULL;
        char * filename="";
  
    
    ECB_DEPOSITS=0.0;    
    FIAT_MONEY_BANKS=0.0;

    START_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
        ECB_DEPOSITS += bank_to_central_bank_account_update_message->payment_account;
        FIAT_MONEY_BANKS += bank_to_central_bank_account_update_message->ecb_debt;
    
        //Search the correct account and update the value    
        for (i=0;i<ACCOUNTS_BANKS.size;i++)
        {       
            if(ACCOUNTS_BANKS.array[i].id == bank_to_central_bank_account_update_message->id)
            {
            ACCOUNTS_BANKS.array[i].payment_account = bank_to_central_bank_account_update_message->payment_account;
            }
        }
        
        #ifndef _DEBUG_MODE
        if(PRINT_DEBUG_CREDIT)
            bank_mesg_count++;        
        #endif
    FINISH_BANK_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP

    START_BANK_INTEREST_PAYMENT_MESSAGE_LOOP
        CASH += bank_interest_payment_message->bank_interest_amount;
    FINISH_BANK_INTEREST_PAYMENT_MESSAGE_LOOP

    #ifndef _DEBUG_MODE
        if(PRINT_DEBUG_CREDIT)
        {                        
            if(bank_mesg_count!=ACCOUNTS_BANKS.size)
            {    
                printf("\nERROR in Central_Bank_Functions.c, line 86: nr of mesg not equal to size of bank account array.\n");
                printf("\n Nr of Bank_mesg=%d, size of bank account array=%d\n", bank_mesg_count, ACCOUNTS_BANKS.size);
            }    
            else
                printf("\n Nr of mesg equal to size of bank account array.\n");
        }
    #endif
    
    START_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
        for (i=0;i<ACCOUNTS_GOVS.size;i++)
        {       
            //Search the correct account and update the value
            if(ACCOUNTS_GOVS.array[i].id == gov_to_central_bank_account_update_message->id)
            {
            ACCOUNTS_GOVS.array[i].payment_account = gov_to_central_bank_account_update_message->payment_account;
            }
    
            //Total deposits at ECB
            ECB_DEPOSITS += gov_to_central_bank_account_update_message->payment_account;
        }
        
        #ifndef _DEBUG_MODE        
        if(PRINT_DEBUG_CREDIT)
            gov_mesg_count++;    
        #endif
        
    FINISH_GOV_TO_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP

/* CHECK THIS FOR CORRECTNESS: if multiple governments pay different coupons?
    START_PAYMENT_COUPONS_MESSAGE_LOOP
        CASH += payment_coupons_message->coupon*NR_GOV_BONDS;
    FINISH_PAYMENT_COUPONS_MESSAGE_LOOP
*/
    #ifndef _DEBUG_MODE
        if(PRINT_DEBUG_CREDIT)
        {                        
            if(gov_mesg_count!=ACCOUNTS_GOVS.size)
            {
                printf("\nERROR in Central_Bank_Functions.c, line 107: nr of mesg not equal to size of gov account array.\n");
                printf("\n Nr of Gov_mesg=%d, size of gov account array=%d\n", gov_mesg_count, ACCOUNTS_GOVS.size);
            }
            else
                printf("\n Nr of mesg equal to size of gov account array.\n");
        }
    #endif        
   // #ifndef _DEBUG_MODE        
        if (PRINT_DEBUG_FILE_EXP1)
        {                       
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/CentralBank_balance_sheet.txt");      
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %f %f",DAY,FIAT_MONEY_GOVS,FIAT_MONEY_BANKS);
            fprintf(file1," %f %f",CASH,ECB_DEPOSITS);
            fclose(file1);
            free(filename);
        }                
   // #endif
    return 0;
}
