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
								set_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								set_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							if(prev_move_player_two==DEF)//CD
							{
								set_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								set_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							
						}
						
						if(prev_move_player_one==DEF)
						{
							if(prev_move_player_two==COOP)//DC
							{
								set_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								set_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							if(prev_move_player_two==DEF) //DD
							{
								set_rows->array[player_one]->columns[playertwo]->opponents->array[1]+=a;
								set_rows->array[player_one]->columns[playertwo]->opponents->array[2]+=d;
							}
							
						}
						
						
					} 
				}
				
			} 
			
		}
	}
}

int find_optimum_strategies()
{
	//identify the first 20 startegies....
	//find last 10 startegies...
	int i,j;
	double sum_row=0.0;
	int playerlistsize=player_list->size;
	for(i=0;i<playerlistsize;i++)
	{
		for(j=0;j<playerlistsize;j++)
		{
		sum_row+=get_rows->array[player_one]->columns[playertwo]->opponents->array[1];
		}
		strategy_performance[strategy_id].strategy_perf=sum_row/playerlistsize;
		
	}
	
	//sort the list in order of highest performance up
	qsort(strategy_performance[strategy_id].strategy_perf,30,sizeof(double),);
	return 0;
}


int apply_GA()
{
	int i;
	int parent_one, parent_two;
	
	int cross_over_bit;
	int strategy_size_parent_one,strategy_size_parent_two;
	int maxsize;
	int population=0;
	double probability_crossover;
	//copy first 20 parents into new startegies...
	
	//apply ga on last 10 parents
	while(population<10)
	{
		parent_one=random_unif_dist(20,30);
		parent_two=random_unif_dist(20,30);
		while(parent_two==parent_one)
		{
			parent_two=random_unif_dist(20,30);
		}
		//unique parents found... now mate them
		strategy_size_parent_one=strategy_list[parent_one].strategy_path.size;
		strategy_size_parent_two=strategy_list[parent_two].strategy_path.size;
		//find the crossover bit
		if(strategy_size_parent_one>strategy_size_parent_two)
		{
			cross_over_bit=rand()%strategy_size_parent_one;
			maxsize=strategy_size_parent_one;
		}
		else
		{
			cross_over_bit=rand()%strategy_size_parent_two;
			maxsize=strategy_size_parent_two;
		} 
		//copy the blocks to each other
		probability_crossover=rand()%1;
		if(probability_crossover<0.5)
		{
			//cross
			for(i=0;i<cross_over_bit;i++)
			{
				set_offspring[1].strategy_path.startegy_state.starting_state[4](strategy_list[parent_one].strategy_path.starting_state[4]);
				set_offspring[1].strategy_path.startegy_state.starting_name(strategy_list[parent_one].strategy_path.state_name);
				set_offspring[1].strategy_path.startegy_state.starting_state_ifcooperate[4](strategy_list[parent_one].strategy_path.state_ifcooperate[4]);
				set_offspring[1].strategy_path.startegy_state.starting_state_ifdefect[4](strategy_list[parent_one].strategy_path.state_ifdefect[4]);
			
				set_offspring[2].strategy_path.startegy_state.starting_state[4](strategy_list[parent_two].strategy_path.starting_state[4]);
				set_offspring[2].strategy_path.startegy_state.starting_name(strategy_list[parent_two].strategy_path.state_name);
				set_offspring[2].strategy_path.startegy_state.starting_state_ifcooperate[4](strategy_list[parent_two].strategy_path.state_ifcooperate[4]);
				set_offspring[2].strategy_path.startegy_state.starting_state_ifdefect[4](strategy_list[parent_two].strategy_path.state_ifdefect[4]);
			}
		
			for(i=cross_over_bit;i<maxsize;i++)
			{
				set_offspring[2].strategy_path.startegy_state.starting_state[4](strategy_list[parent_one].strategy_path.starting_state[4]);
				set_offspring[2].strategy_path.startegy_state.starting_name(strategy_list[parent_one].strategy_path.state_name);
				set_offspring[2].strategy_path.startegy_state.starting_state_ifcooperate[4](strategy_list[parent_one].strategy_path.state_ifcooperate[4]);
				set_offspring[2].strategy_path.startegy_state.starting_state_ifdefect[4](strategy_list[parent_one].strategy_path.state_ifdefect[4]);
			
				set_offspring[1].strategy_path.startegy_state.starting_state[4](strategy_list[parent_two].strategy_path.starting_state[4]);
				set_offspring[1].strategy_path.startegy_state.starting_name(strategy_list[parent_two].strategy_path.state_name);
				set_offspring[1].strategy_path.startegy_state.starting_state_ifcooperate[4](strategy_list[parent_two].strategy_path.state_ifcooperate[4]);
				set_offspring[1].strategy_path.startegy_state.starting_state_ifdefect[4](strategy_list[parent_two].strategy_path.state_ifdefect[4]);
		
			}
		
			//now copy the two offsprings in place of the dummy parents parents
			for(i=0;i<maxsize;i++)
			{
				//remove(strategy_list[parent_two]);
				//remove(strategy_list[parent_one]);
				add_new_children[parent_one](offspring[1].strategy_path.startegy_state.starting_state[4],offspring[1].strategy_path.startegy_state.starting_name,offspring[1].strategy_path.startegy_state.starting_state_ifcooperate[4],offspring[1].strategy_path.startegy_state.starting_state_ifdefect[4]);
				add_new_children[parent_two](offspring[2].strategy_path.startegy_state.starting_state[4],offspring[2].strategy_path.startegy_state.starting_name,offspring[2].strategy_path.startegy_state.starting_state_ifcooperate[4],offspring[2].strategy_path.startegy_state.starting_state_ifdefect[4]);
				population+=2;//adding two
			}
		}
	 
	}
	
	return 0;
}

int update_strategies()
{	
	int i;
	//remove last 10 elements and then start copying the new 10 elements
	for(i=20;i<30;i++)
	{
		remove(strategy_list->array[i]);
	}
	
	for(i=0;i<10;i++)
	{
		add_strategy_list(new_children[i].strategy_path.startegy_state.starting_state[4],offspring[i].strategy_path.strategy_state.starting_name,offspring[i].strategy_path.startegy_state.starting_state_ifcooperate[4],offspring[i].strategy_path.startegy_state.starting_state_ifdefect[4]);
	}
	
	
   
	 
	return 0;
}