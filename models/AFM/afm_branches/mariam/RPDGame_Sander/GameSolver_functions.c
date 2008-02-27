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
    {    	//fill in the list of players and strategies
    	add_int(player_array,  strategy_i_use_message->player_id);
    	add_int(player_strategy_array,  strategy_i_use_message->strategy_id);
    	add_int(player_strategy_array,strategy_i_use_message->previous_move);
		add_int(player_state_array, strategy_i_use_message->present_state);    
    	strategy_i_use_message = get_next_strategy_i_use_message(strategy_i_use_message);
    	 
    }
	return 0;
	
}

int actual_game()
{
	//return size of playerlist
	int playerlistsize=player_list->size;
	int i,j,k;
	int player_one, player_one_strategy;
	int player_two, player_two_strategy;
	int game_times=150;
	//Standard classification of games:
    // |---------------|
    // | (a,a) | (c,d) |
    // |---------------|
    // | (d,c) | (b,b) |
    // |---------------|    
    
    //Prisoner's Dilemma: c < b <  a < d
    int a=3;
    int b=1;
    int c=0;
    int d=5;
    int player1_move,player2_move;
    int payoff[2]={0,0};
    int prev_move_player_one, prev_move_player_two;
	int present_state_player_one[4],present_state_player_two[4];
	int payoff_one=0, payoff_two=0;
	for (i=0;i<playerlistsize;i++)
	{
		player_one=player_list-> player_id;
		player_one_startegy=player_list->strategy_id;
		prev_move_player_one=player_list->previous_move;
		present_state_player_one[4]=player_list->present_state;
		//iterate through the list of startegies to find the strategy using the id.
		//MARIAM: Dont do this we may use the startegy id as the array identifier... only 30 startegies!
				
		payoff_one_total=0;
		
		for(j=0;j<playerlistsize;j++)
		{
			player_two=player_list-> player_id;
			player_two_strategy=player_list->strategy_id;
			prev_move_player_two=player_list->previous_move;
			present_state_player_two[4]->present state
			payoff_two_total=0;
			//play game
			//return starting state of the strategy
			//collect payoff
			for(k=0;k<game_times;k++)
			{
				//find the desired transition
				strategy_state_size_one=get_strategy_list[player_one_strategy]->size; //gives number of states in strategy
				for(l=0;l<strategy_state_size_one;l++)
				{
					int state_player, state_strategy;
					state_player=state_unique_value(present_state_player_one[4]);
					state_strategy=state_unique_value(strategy_state->starting_state[4]);
					if(state_player==state_strategy)//found the transition
					{
						if(prev_move_player_two==COOP)
						{
							set_player_one_state[4]=strategy_state->stateifcoop[4];
							prev_move_player_one=strategy_state->state_name;
						}
						if(prev_move_player_two==DEF)
						{
							set_player_one_state[4]=strategy_state->stateifdeflect[4];
							prev_move_player_one=strategy_state->state_name;
						}
						
						if(prev_move_player_one==COOP)
						{
							if(prev_move_player_two==COOP) //CC
							{
								get_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								get_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							if(prev_move_player_two==DEF)//CD
							{
								get_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								get_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							
						}
						
						if(prev_move_player_one==DEF)
						{
							if(prev_move_player_two==COOP)//DC
							{
								get_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								get_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							if(prev_move_player_two==DEF) //DD
							{
								get_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								get_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							
						}
						
						
					} 
				}
				
			} 
			
		}
	}
}

int 