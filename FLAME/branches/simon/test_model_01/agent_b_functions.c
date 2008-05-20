#include "header.h"
#include "agent_b_agent_header.h"

/** \fn agent_b_1()
 * \brief A description of the function
 */
int agent_b_1()
{
	/* code here */
	START_M1_MESSAGE_LOOP
		printf("%d - m1 from %d\n", ID, m1_message->id);
	FINISH_M1_MESSAGE_LOOP
	
	add_m2_message(ID);

	return 0;
}

/** \fn agent_b_2()
 * \brief A description of the function
 */
int agent_b_2()
{
	/* code here */
	START_M3_MESSAGE_LOOP
		printf("%d - m3 from %d\n", ID, m3_message->id);
	FINISH_M3_MESSAGE_LOOP
	
	return 0;
}