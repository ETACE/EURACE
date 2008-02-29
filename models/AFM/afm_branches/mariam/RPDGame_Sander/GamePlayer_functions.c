/****************************************************************
 * GamePlayer_functions.c 
 * 26/02/08  Mariam - Start implementation
 ****************************************************************
 */
#include <math.h>
#include "GamePlayer_agent_header.h"
#include "my_library_header.h"
#include "header.h"

//function posts the strategy of the agents so that all agents read this first
int post_my_strategy()
{
	add_strategy_i_use_message(get_id(), get_strategy_used(), get_previous_performance(), get_present_state(), RANGE, get_posx(),get_posy(),0.0);
	return 0;
}

