#include "../header.h"
#include "../Government_agent_header.h"
#include "../my_library_header.h"

/* \fn: int Government_send_data_to_Eurostat()
 * \brief Function to send balance sheet data to Eurostat.
 */
int Government_send_data_to_Eurostat()
{        

	add_government_send_data_message(ID,REGION_ID,MONTHLY_INCOME,MONTHLY_EXPENDITURE,
			MONTHLY_BUDGET_BALANCE,TOTAL_DEBT,MONTHLY_TAX_REVENUES,MONTHLY_BENEFIT_PAYMENT);

    return 0;
}