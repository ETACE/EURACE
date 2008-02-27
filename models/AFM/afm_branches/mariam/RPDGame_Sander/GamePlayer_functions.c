/****************************************************************
 * GamePlayer_functions.c 
 * 26/02/08  Mariam - Start implementation
 ****************************************************************
 */
#include <math.h>
#include "GamePlayer_header.h"
#include "mylibraryheader.h"
#include "header.h"

//function posts the strategy of the agents so that all agents read this first
int post_my_strategy()
{
	add_strategy_i_use_message(get_id(), get_strategy_used());
}

/// Function to play game
int play_game()
{
	

}

//the solver plays the game for the players
void ipd_game(agent1, agent1_strategy, agent2, agent2_strategy)
{
	
}

//mutation would also be in solver

