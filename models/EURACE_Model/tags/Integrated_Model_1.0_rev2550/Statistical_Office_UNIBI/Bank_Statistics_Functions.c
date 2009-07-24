#include "../header.h"
#include "../Bank_agent_header.h"
#include "../my_library_header.h"


/** \fn Bank_read_policy_announcements()
 * \brief Function to read the policy_announcements from Governments.
 */
int Bank_read_policy_announcements()
{
    //Message send by Government:
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP          
        //Filter: 
        if(policy_announcement_message->gov_id == GOV_ID)
        {
            TAX_RATE_CORPORATE = policy_announcement_message->tax_rate_corporate;
        }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    
    return 0;
}
