#include "../header.h"
#include "../Central_Bank_agent_header.h"
#include "my_library_header.h"


int CB_receives_info_bond(void)
{        
     return 0;
}

int CB_issues_orders(void)
{    
  /*   Bond *bond;
     Order *ord;
     
     START_INFO_BOND_MESSAGE_LOOP
                bond = info_bond_message->bond;      
     FINISH_INFO_BOND_MESSAGE_LOOP  
     
     ord->issuer = ID;
     ord->price = 0.2;
     ord->quantity = 1;
     ord->assetId = 10;
     
     add_order_message(ord->issuer,ord->assetId, ord->price, ord->quantity);
    */ 
       
     return 0;
}

int CB_receives_order_status(void)
{        
     return 0;
}
