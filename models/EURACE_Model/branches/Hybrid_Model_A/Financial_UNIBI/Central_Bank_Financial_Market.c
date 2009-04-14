   #include "../header.h"
    #include "../Central_Bank_agent_header.h"
    #include "../my_library_header.h"
    
    
    
    /************Central_Bank Role: manage accounts for Governments and commercial banks********************************/
/** \fn Central_Bank_read_bond_update()
 * \brief Read bond messages from Governments
 */
int Central_Bank_read_bond_update()
{
    GOV_BOND_PURCHASE=0;
    
    START_GOV_BOND_MESSAGE_LOOP
        GOV_BOND_PURCHASE += gov_bond_message->amount;
    FINISH_GOV_BOND_MESSAGE_LOOP
    
    //Update stock variables
    GOV_BOND_HOLDINGS += GOV_BOND_PURCHASE;
    FIAT_MONEY += GOV_BOND_PURCHASE;
    
    return 0;
} 