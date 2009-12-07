#include "../header.h"
#include "../IGFirm_agent_header.h"
#include "../my_library_header.h"


/** \fn IGFirm_read_policy_announcements()
 * \brief IGFirms reads the policy_announcement_messages from Governments
 */
int IGFirm_read_policy_announcements()
{
    //Message send by Government:
    START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP          
        //Filter: 
        if(policy_announcement_message->gov_id == GOV_ID)
        {
            TAX_RATE_CORPORATE = policy_announcement_message->tax_rate_corporate;
            TAX_RATE_VAT = policy_announcement_message->tax_rate_vat;
            TRANSFER_PAYMENT = policy_announcement_message->firm_transfer_payment;
            SUBSIDY_PCT = policy_announcement_message->firm_subsidy_pct;
        }
    FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
    
    return 0;
}
