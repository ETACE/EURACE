#include "header.h"
#include "agent_a_agent_header.h"

/** \fn agent_a_1()
 * \brief A description of the function
 */
int agent_a_1()
{
	/* code here */
	add_m1_message(ID);

   return 0;
}

/** \fn agent_a_2()
 * \brief A description of the function
 */
int agent_a_2()
{
	/* code here */
	START_M2_MESSAGE_LOOP
		printf("%d - m2 from %d\n", ID, m2_message->id);
	FINISH_M2_MESSAGE_LOOP
	
	add_m3_message(ID);

   return 0;
}