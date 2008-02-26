/****************************************************************
 * GameSolver_functions.c 
 * 26/02/08  Mariam - Start implementation
 ****************************************************************
 */
#include <math.h>
#include "GameSolver_header.h"
#include "mylibraryheader.h"
#include "header.h"

int ipd_game_within_players()
{
	int_array * player_array=get_players();
	reset_int_array(player_array);
	
	int_array * player_strategy_array=get_startegy_id();
	reset_int_array(player__strategy_array);
	
	strategy_i_use_message = get_first_strategy_i_use_message();
	
    while(strategy_i_use_message)//iterates thorough player a list
    {    	
    	add_int(player_array,  strategy_i_use_message->player_id);
    	add_int(player_strategy_array,  strategy_i_use_message->strategy_id);
    	strategy_i_use_message = get_next_strategy_i_use_message(strategy_i_use_message);
    	 
    }
	return 0;
	
}

int actual_game()
{
	
}