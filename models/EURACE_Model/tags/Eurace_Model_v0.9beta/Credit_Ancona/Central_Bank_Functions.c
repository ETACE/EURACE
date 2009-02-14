    #include "../header.h"
    #include "../Central_Bank_agent_header.h"
    #include "../my_library_header.h"
    
    
    
    /************Central_Bank Role: manage accounts for Governments and commercial banks********************************/
    
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
                
            if  (central_bank_account_update_message->payment_account<0)
                { 
                     TOTAL_ECB_DEBT+=fabs(central_bank_account_update_message->payment_account);
                }                  
    			
    	}
    	FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
    	return 0;
    }
