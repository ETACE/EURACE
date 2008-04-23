/****************************************************************
 * GameSolver_functions.c 
 * 26/02/08  Mariam - Start implementation
 ****************************************************************
 */
#include <math.h>
#include "GameSolver_agent_header.h"
#include "my_library_header.h"
#include "header.h"

int ipd_game_within_players()
{
	//iterates thorough player a list
	    	//fill in the list of players and strategies
	START_STRATEGY_I_USE_MESSAGE_LOOP
	   		add_player_list_element_array(PLAYER_LIST, strategy_i_use_message->player_id,strategy_i_use_message->strategy_id,strategy_i_use_message->previous_move,strategy_i_use_message->present_state);
	FINISH_STRATEGY_I_USE_MESSAGE_LOOP
   
	return 0;
	
}

int actual_game()
{
	//return size of playerlist
	int playerlistsize=PLAYER_LIST.size;
	int i,j,k,l;
	int s;
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
    int strategy_state_size_one;
    int unique_id_one, unique_id_two;
    int state_player, state_strategy;
    int player_one_now_state, player_two_now_state;
    int player_one_now_move, player_two_now_move;
    int prev_move_player_one, prev_move_player_two;
	int present_state_player_one,present_state_player_two;
	int payoff_one_total=0, payoff_two_total=0;
	double row_sum=0.0;
	int payoff_matrix[PLAYERS][PLAYERS];
	double row_sum_matrix[PLAYERS];
	int strategy_which;
	int player_number_per_strategy;
	double sum_of_row=0.0;
	//using nested for loops to make agents play against each other
	for (i=0;i<playerlistsize;i++)
	{
		player_one=PLAYER_LIST.array[i].player_id;
		player_one_strategy=PLAYER_LIST.array[i].strategy_id;
		prev_move_player_one=PLAYER_LIST.array[i].previous_move;
		present_state_player_one=PLAYER_LIST.array[i].present_state;
		//iterate through the list of strategies to find the strategy using the id
		
		//MARIAM: Dont do this we may use the strategy id as the array identifier... only 30 strategies!
				
		payoff_one_total=0;
		
		for(j=i;j<playerlistsize;j++)//play with itself too
		{
			player_two=PLAYER_LIST.array[j].player_id;
			player_two_strategy=PLAYER_LIST.array[j].strategy_id;
			prev_move_player_two=PLAYER_LIST.array[j].previous_move;
			present_state_player_two=PLAYER_LIST.array[j].present_state;
			payoff_two_total=0;
			
			//find the stratgey details of both players
			for(s=0;s<30;s++)
			{
				if(strategy_list[s].strategy_unique_id==player_one_strategy)
				{
					//set strategy
					strategy_one_size=strategy_list[s].strategy_path.size; //gives number of states in strategy
					unique_id_one=s;
				}
				if(strategy_list[s].strategy_unique_id==player_two_strategy)
				{
				//set strategy
					strategy_two_size=strategy_list[s].strategy_path.size; //gives number of states in strategy
					unique_id_two=s;
				}
			}
			
			//play game
			//return starting state of the strategy this is the state in which the stragey is in
			//collect payoff
			state_player_one=present_state_player_one;
			
			player_one_now_state=state_player;
			//player two's move
			player_one_now_move=prev_move_player_one;
			player_two_now_move=prev_move_player_two;
		
			for(k=0;k<game_times;k++)
			{
				//state_player=present_state_player_one;
				//find the desired transition for player one
				for(l=0;l<strategy_one_size;l++)
				{
					
					//state_strategy=state_unique_value(strategy_state->starting_state[4]);
					state_strategy_one=strategy_list[unique_id_one].strategy_path.array[l].starting_state;
					if(player_one_now_state==state_strategy)//found the transition
					{
						found_transition_one=l;
					}
				}
			
				//find the desired transition for player two
				for(l=0;l<strategy_two_size;l++)
				{
					
					//state_strategy=state_unique_value(strategy_state->starting_state[4]);
					state_strategy_two=strategy_list[unique_id_two].strategy_path.array[l].starting_state;
					if(player_two_now_state==state_strategy_two)//found the transition
					{
						found_transition_two=l;
					}
				}
				//both transtions are found, now perform the transition
				if(player_two_now_move==COOP)
				{
					player_one_state_now=strategy_list[unique_id_one].strategy_path.array[found_transition].state_ifcooperate;
					player_one_new_move=strategy_list[unique_id_one].strategy_path.array[found_transition].state_name;
				}
				
				else if(player_two_now_move==DEF)
				{
					player_one_state_now=strategy_list[unique_id_one].strategy_path.array[found_transition].state_ifdefect;
					player_one_new_move=strategy_list[unique_id_one].strategy_path.array[found_transition].state_name;
				}
						
				if(player_one_now_move==COOP)
				{
					player_two_state_now=strategy_list[unique_id_two].strategy_path.array[found_transition_two].state_ifcooperate;
					player_two_new_move=strategy_list[unique_id_two].strategy_path.array[found_transition_two].state_name;
				}
				
				else if(player_one_now_move==DEF)
				{
					player_two_state_now=strategy_list[unique_id_two].strategy_path.array[found_transition_two].state_ifdefect;
					player_two_new_move=strategy_list[unique_id_two].strategy_path.array[found_transition_two].state_name;
				}
				
				//putting in payoffs
				//have to put in after both players have finished moving
				if(player_one_new_move==COOP) 
				{
					if(player_two_new_move==COOP)//CC
					{
						payoff_matrix[player_one][player_two]=a;
						payoff_matrix[player_two][player_one]=a;
						if(player_one==player_two)
							payoff_matrix[player_one][player_two]=a;
					}
					else if(player_two_new_move==DEF)//CD
					{
						payoff_matrix[player_one][player_two]=c;
						payoff_matrix[player_two][player_one]=d;
						if(player_one==player_two)
							payoff_matrix[player_one][player_two]=(c+d)/2;
								
					}
				}
				else if(player_one_new_move==DEF)
				{
					if(player_two_new_move==COOP)//DC
					{
						payoff_matrix[player_one][player_two]=d;
						payoff_matrix[player_two][player_one]=c;
						if(player_one==player_two)
							payoff_matrix[player_one][player_two]=(c+d)/2;
					}
					else if(player_two_new_move==DEF)//DD
					{
						payoff_matrix[player_one][player_two]=b;
						payoff_matrix[player_two][player_one]=b;
						if(player_one==player_two)
							payoff_matrix[player_one][player_two]=b;
					}
				
				}
						
				//change to new states for players
				player_one_now_state=player_one_new_move;
				player_two_now_state=player_two_new_move;		
			} //end of for loop 150 times the same game
				
		}//endof j loop
	}//end of for loop for player list-->all players have finished playing
	
	//we can work out the optimum working strategy now 
	for(i=0;i<playerlistsize;i++)
	{
		for(j=0;j<playerlistsize;j++)
		{
			row_sum+=payoff_matrix[i][j];
		}
		row_sum_matrix[i]=row_sum;//all the players individually calculate their performance
	}
	
	//now we need to work out the strategy performance
	for(i=0;i<30;i++)
	{
		strategy_which=strategy_list[j].strategy_unique_id;
		player_number_per_strategy=0;	
		for(j=0;j<playerlistsize;j++)
		{
			//number of players using a particular strategy?
			if(strategy_which==PLAYER_LIST.array[j].strategy_id)
			{
				player_number_per_strategy++;
				sum_of_row+=row_sum_matrix;				
			}
		}
		strategy_list[j].strategy_performance=sum_of_row/player_number_per_strategy;
	}//end of performance loop
		
}

int find_optimum_strategies()
{
	//identify the first 20 strategies....
	//find last 10 strategies...
	int i,j;
	double sum_row=0.0;
	int playerlistsize=player_list->size;
	
	
	//sort the list in order of highest performance up
	qsort(strategy_performance[strategy_id].strategy_perf,30,sizeof(double),k);
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
	//copy first 20 parents into new strategies...
	
	//apply ga on last 10 parents
	while(population<10)
	{
		parent_one=random_unif_dist(20,30);//randomly choosing parents
		parent_two=random_unif_dist(20,30);
		while(parent_two==parent_one)
		{
			parent_two=random_unif_dist(20,30);
		}
		//unique parents found... now mate them
		strategy_size_parent_one=STRATEGY_LIST[parent_one].strategy_path.size;
		strategy_size_parent_two=STRATEGY_LIST[parent_two].strategy_path.size;
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
				OFFSPRING[1].strategy_path.array[i].starting_state[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].starting_state[4];
				OFFSPRING[1].strategy_path.array[i].state_name=STRATEGY_LIST[parent_one].strategy_path.array[i].state_name;
				OFFSPRING[1].strategy_path.array[i].state_ifcooperate[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].state_ifcooperate[4];
				OFFSPRING[1].strategy_path.array[i].state_ifdefect[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].state_ifdefect[4];
			
				OFFSPRING[2].strategy_path.array[i].starting_state[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].starting_state[4];
				OFFSPRING[2].strategy_path.array[i].state_name=STRATEGY_LIST[parent_two].strategy_path.array[i].state_name;
				OFFSPRING[2].strategy_path.array[i].state_ifcooperate[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].state_ifcooperate[4];
				OFFSPRING[2].strategy_path.array[i].state_ifdefect[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].state_ifdefect[4];
			}
		
			for(i=cross_over_bit;i<maxsize;i++)
			{
				OFFSPRING[2].strategy_path.array[i].starting_state[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].starting_state[4];
				OFFSPRING[2].strategy_path.array[i].state_name=STRATEGY_LIST[parent_one].strategy_path.array[i].state_name;
				OFFSPRING[2].strategy_path.array[i].state_ifcooperate[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].state_ifcooperate[4];
				OFFSPRING[2].strategy_path.array[i].state_ifdefect[4]=STRATEGY_LIST[parent_one].strategy_path.array[i].state_ifdefect[4];
			
				OFFSPRING[1].strategy_path.array[i].starting_state[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].starting_state[4];
				OFFSPRING[1].strategy_path.array[i].state_name=STRATEGY_LIST[parent_two].strategy_path.array[i].state_name;
				OFFSPRING[1].strategy_path.array[i].state_ifcooperate[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].state_ifcooperate[4];
				OFFSPRING[1].strategy_path.array[i].state_ifdefect[4]=STRATEGY_LIST[parent_two].strategy_path.array[i].state_ifdefect[4];
		
			}
		
			//now copy the two offsprings in place of the dummy parents parents
			for(i=0;i<maxsize;i++)
			{
				//remove(strategy_list[parent_two]);
				//remove(strategy_list[parent_one]);
				NEW_CHILDREN[population].strategy_path.array[i].starting_state[4]=OFFSPRING[0].strategy_path.array[i].starting_state[4];
				NEW_CHILDREN[population].strategy_path.array[i].state_name=OFFSPRING[0].strategy_path.array[i].state_name;
				NEW_CHILDREN[population].strategy_path.array[i].state_ifcooperate[4]=OFFSPRING[0].strategy_path.array[i].state_ifcooperate[4];
				NEW_CHILDREN[population].strategy_path.array[i].state_ifdefect[4]=OFFSPRING[0].strategy_path.array[i].state_ifdefect[4];
				
				NEW_CHILDREN[population+1].strategy_path.array[i].starting_state[4]=OFFSPRING[1].strategy_path.array[i].starting_state[4];
				NEW_CHILDREN[population+1].strategy_path.array[i].state_name=OFFSPRING[1].strategy_path.array[i].state_name;
				NEW_CHILDREN[population+1].strategy_path.array[i].state_ifcooperate[4]=OFFSPRING[1].strategy_path.array[i].state_ifcooperate[4];
				NEW_CHILDREN[population+1].strategy_path.array[i].state_ifdefect[4]=OFFSPRING[1].strategy_path.array[i].state_ifdefect[4];


				
				population=+2;
				//adding two
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
		//MARIAM: which array[i] to use here fo the dynamic array
		STRATEGY_LIST[i].strategy_path.array[i].starting_state[4]=NEW_CHILDREN[i-20].strategy_path.array[i].starting_state[4];
		STRATEGY_LIST[i].strategy_path.array[i].state_name=NEW_CHILDREN[i-20].strategy_path.array[i].state_name;
		STRATEGY_LIST[i].strategy_path.array[i].state_ifcooperate[4]=NEW_CHILDREN[i-20].strategy_path.array[i].state_ifcooperate[4];
		STRATEGY_LIST[i].strategy_path.array[i].state_ifdefect[4]=NEW_CHILDREN[i-20].strategy_path.array[i].state_ifdefect[4];
	}
		
   	return 0;
	
}
