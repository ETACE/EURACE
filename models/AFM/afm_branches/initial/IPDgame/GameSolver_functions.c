/*****************************************************************
 * GameSolver_functions.c
 * 29/11/07 Sander van der Hoog (svdhoog@gmail.com) 
 * ***************************************************************
 * History:
 * 29/11/07: Started implementation of IPD game 
 *****************************************************************/
 
#include <math.h>
#include "GameSolver_agent_header.h"
//path to mylibraryheader.h:
#include "mylibraryheader.h"
#include "header.h"

//Definitions
#define STATESIZE 4 //size of a state
#define NRSTATES 16 //number of states in the FSM
#define OFFSET 4    //size of first block
#define BLOCKSIZE 9 //1+2*STATESIZE //size of blocks, 9
#define LENGTH 148  //STATESIZE+NRSTATES*BLOCKSIZE  //length of bitstrings, 148
#define TMAX 150	//iterations of IPD game
#define NRAGENTS 100

//GameSolver_daily_reset_public_classifiersystem()
//Daily reset of the public classifiersystem
//Resets user counter, performance sum, and avgperformance.
//This should be run before any current_rule_messages are being read.
int GameSolver_daily_reset_public_classifiersystem()
{
    //total number of rules:
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<NRRULES; i++)
    {
        CLASSIFIERSYSTEM->array[i]->counter=0;
        CLASSIFIERSYSTEM->array[i]->performance=log(pow(10,-5));
        CLASSIFIERSYSTEM->array[i]->avgperformance=log(pow(10,-5));
    }
    
  return 0;
}

/* GameSolver_read_current_rule_message()
 *  GameSolver agent reads the current_rule_message
 */
int GameSolver_read_current_rule_message()
{
    int current_rule;
    int agent_id;
    
      current_rule_message = get_first_current_rule_message();
      while(current_rule_message)
      {
        //Read contents  
          agent_id     = current_rule_message->id;
          current_rule = current_rule_message->current_rule;

        //Store contents in memory array: automata[i].
        //AUTOMATA is the list of rule ids currently used by the players.
          AUTOMATA->array[agent_id]->current_rule = current_rule;
        
        //Go to next message:
          current_rule_message = get_next_current_rule_message(current_rule_message)
      }

   return 0;
 }
 
/* GameSolver_play_tournament()
 *  - retrieves rule details from RULEDETAILSYSTEM
 *  - runs the tournament procedure
 * Every submitted automaton plays a match (one 150-period iterated PD), including a match against a clone of itself.
 * This results in an upper-diagonal matrix of results (because the game-matrix is symmetric, we do not have to run 2 times the same game,
 * A vs. B and B vs. A). The outcome of a match is the average payoff for the automaton over the 150 periods.
 * After all matches have been computed, we construct the full matrix of outcomes, and compute the row-average payoff for each automaton.
 */
int GameSolver_play_tournament()
{
	int 		i,j,t;
    int      	result;//result of a game is int
    double		sum;   //sum can be double or int
    
    double 		outcome[NRAGENTS][NRAGENTS];
    int		    string_0[LENGTH],string_1[LENGTH];
    
    //Match [i vs. j]
    for (i=0;i<NRAGENTS; i++)
    {
        //Retrieve a copy of the automata bitstring for player i:
        nr_rule_1 = AUTOMATON->array[i]->current_rule;
        for (k=0;k<LENGTH;k++)
        {
            string_0[k] = RULEDETAILSYSTEM->array[nr_rule_1]->bitstring[k];
        }       
        for (j=0;j<i+1; j++) //j<i+1: each automaton also plays a clone of itself 
        {
            //Reset the starting state of automaton i (since during play, we update the initial state)
            for (k=0;k<4;k++)
            {
            	string_0[k] = CLASSIFIERSYSTEM->array[nr_rule_1]->bitstring[k];
            }
            //Retrieve a copy of the automata bitstring for player j:
            nr_rule_2 = AUTOMATON->array[j]->current_rule;
            for (k=0;k<LENGTH;k++)
            {
                string_1[k] = CLASSIFIERSYSTEM->array[nr_rule_2]->bitstring[k];
            }

            //Randomly initialize previous_moves in memory
            //we need to initialize these because the first state transition requires a value
            if (random_unif()>0.5)
            {
                set_previous_move_player0(0);
            }
            else set_previous_move_player0(1);
            if (random_unif()>0.5)
            {
                set_previous_move_player1(0);
            }
            else set_previous_move_player1(1);

            //***************** TOURNAMENT PLAY ***********************
            //Automaton of agent i plays against Automaton of agent j
            sum=0.0;
            for (t=0;t<TMAX; t++)
            {
                //play_game is a function that should give the outcome of a game played by 2 given automata
                result = play_game(string_0,string_1);
                sum += (double)result;
            }
            //Outcome of the match
            outcome[i][j]=sum/TMAX;
        }
    }
    //Full outcome matrix is symmetric
    for (i=0;i<NRAGENTS; i++)
    {
        for (j=0;j<i; j++)
        {
            outcome[j][i]=outcome[i][j];
        }
    }
     
    //Row-average payoffs of the symmetric outcome matrix
    for (i=0;i<NRAGENTS; i++)
    {
        sum=0.0;
        for (j=0;j<NRAGENTS; j++)
        {
            sum += outcome[i][j];
        }
        //Add the avg performance from the tournament directly to the memory variable AUTOMATA:
        AUTOMATA->array[i]->rule_performance = sum/NRAGENTS;
    }

    //Print entire matrix
      printf("Tournament outcomes:\n");
      for (i=0;i<NRAGENTS;i++)
      {
           for (j=0;j<NRAGENTS;j++)
           {
              	printf("[%d,%d]=%2.5f ", i, j, outcome[i][j]);
           }
           printf("|row avg=%2.5f\n", AUTOMATA->array[i]->rule_performance);
      }
      printf("\n");
   
    return 0;
}

/* int play_game(i,j)
 * Data for 2-person game.
 * We program how the automata play:
 * - retrieve a copy of the automata bitstrings
 * - read current state
 * - travers the state block corresponding to that state
 * - set next_move
 * - set state transition to new_state
 * - set payoffs fom game
 * - return payoff of player 1
 */
int play_game(int * string_0, int * string_1)
{
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
    int move_player0,move_player1;
    int payoff[2]={0,0};
    
    //int arrays for bitstrings, size=148 bits
    int bitstr[LENGTH];      //int arrays for bitstrings string_0, string_1
    int state_block[BLOCKSIZE];
    int next_move;
    int next_state[4];
    int i,n,player_index,count;
    
    //Get the previous moves from memory
    int previous_move_player0 = get(previous_move_player0);
    int previous_move_player1 = get(previous_move_player1);
    int opponent_move;
            
    for (player_index=0;player_index<2;player_index++)
    {
        //Set the bitstring to consider
        switch (player_index)
        {
            case 0:
                    for (i=0;i<LENGTH;i++)
                    {
                        bitstr[i]=string_0[i];
                    };
                    break;
            case 1:
                    for (i=0;i<LENGTH;i++)
                    {
                        bitstr[i]=string_1[i];
                    };
                    break;
            default:
                    printf("Error in GameSolver_functions.c, line 202");
                    break;
        }
        
        //read current state: 4 bits    
        //n is the current state 1-16: [0,2^n-1]
        n=0;
        for (i=0;i<STATESIZE;i++)
        {
            n += pow(2,bitstr[i]);
        }
        
        //Travers the state blocks: each block is 9 bits, the first starting after the 4 bit block 
        //States are 1-16, and we only consider the state block corresponding to current state n.
        
        //Enter into block n
        count=0;
        for (i=STATESIZE+(n-1)*BLOCKSIZE; i<STATESIZE+n*BLOCKSIZE; i++)
        {
            state_block[count] = bitstr[i];
            count+=1;
        }
        
        //Next move:        
        //bit 1 (index 0) of the state_block is next_move
            next_move = state_block[0];

        //Set Move
        switch (player_index)
        {
            case 0:
            		move_player0=next_move;
                    break;
            case 1:
              		move_player1=next_move;
                    break;
            default:
                    printf("Error in GameSolver_functions.c, line 172");
                    break;
        }        
        //State transitions
        //Set the next state, given the most recently observed move by opponent
        if (player_index==0)
        {
            opponent_move = previous_move_player1;
        }
        if (player_index==1)
        {
            opponent_move = previous_move_player0;
        }
        
        //if observed opponent move was 0, bits [2-5] (indexed 1-4) are next state
        if (opponent_move==0)
        {
            count=0;
            for (i=1;i<5; i++)
            {
                next_state[count]= state_block[i];
                count+=1;
            }
        }
        //if observed opponent move was 1, bits [6-9] (indexed 5-8) are next state
        if (opponent_move==1)
        {
            count=0;
            for (i=5;i<8; i++)
            {
                next_state[count]= state_block[i];
                count+=1;
            }
        }
        
    }
    //End for loop over player 1,2
    
    
    //Payoffs of the game
    if (move_player0==0 && move_player1==0)
    {
        payoff[0]=a; payoff[1]=a;
    }
    
    if (move_player0==0 && move_player1==1)
    {
        payoff[0]=c; payoff[1]=d;
    }
    
    if (move_player0==1 && move_player1==0)
    {
        payoff[0]=d; payoff[1]=c;
    }
    
    if (move_player0==1 && move_player1==1)
    {
        payoff[0]=b; payoff[1]=b;
    }
    
    //Set in memory the moves as previous_moves
    set_previous_move_player0(move_player0);
    set_previous_move_player1(move_player1);
    
    //Return only the payoff of player 0
    return payoff[0];
}


/* GameSolver_update_classifiersystem()
 * After running the tournament, update the public classifiersystem.
 */
int GameSolver_update_classifiersystem()
{
    int current_rule;
    int rule_performance;
    
    //For each agent, retrieve the automata used, and its performance:
    for (i=0;i<NRAGENTS;i++)
    {
        current_rule = AUTOMATA->array[i]->current_rule;
        rule_performance = AUTOMATA->array[i]->rule_performance;
        
      //Replace old performance adding new performance: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY? 
      CLASSIFIERSYSTEM->array[current_rule]->performance += rule_performance;
      
      //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
      CLASSIFIERSYSTEM->array[current_rule]->counter +=1;
    }

    //Avgperformance update:
    for (i=0;i<NRAGENTS;i++)
    {    
      CLASSIFIERSYSTEM->array[current_rule]->avgperformance = CLASSIFIERSYSTEM->array[current_rule]->avgperformance / CLASSIFIERSYSTEM->array[current_rule]->counter;       
    }
    
  return 0;
}

/* int GameSolver_send_all_performances_message()
 * Send dynamic array all_performances.
 */
int GameSolver_send_all_performances_message()
{
    double * all_performances;
     
    //Get size of performance array:
    imax = CLASSIFIERSYSTEM->performance->size;

    //Assign values to dynamic array all_performances to equal the average performances
    for (i=0;i<imax;i++)
    {
        all_performances[i] = CLASSIFIERSYSTEM->array[i]->avgperformance;
    }
    
    //Send the message containing the dynamic array
    add_all_performances_message(all_performances, range, x, y, z);
     
  return 0;
}

//-Date-event triggered: every 100 days run the GA
int GameSolver_apply_GA()
{
    int i,n,c,ell;
    int N = CLASSIFIERSYSTEM->nr_rules; 
    int draw;
    int a,b,k,temp_a,temp_b, start, end;
    double p;
    
    //GA parameters
    int prob_cross = 0.05;      //cross-over probability
    int prob_mut = 0.01;        //mutation probability

    int Nrep_prop = 0.5;        //Proportion of population used for reproduction                   
    int Nrep = (int)(Nrep_prop*0.5*N); //Set reproduction population Nrep
    
    int candidates[2*Nrep];     //Candidates for reproduction
    int pair[Nrep][2];          //Nrep matched pairs of parents
    int prob[2*Nrep];           //Selection probabilities (fitness proportional)

    //***************** SELECTION ************************************
    //Draw 2*Nrep candidate bitstrings with relative probabilities (draw with replacement)  
    for (i=0;i<2*Nrep;i++)
    {
        prob[i] = CLASSIFIERSYSTEM->array[i]->avgperformance;
    }
    
    //use: cumpdf(int N, double * p)
    cpdf = cumpdf(2*Nrep, prob);
    
    //use: draw_with_replacement(int N, double * cpdf)
    candidates = draw_with_replacement(2*Nrep, cpdf)        
    
    //Random matching of the 2*Nrep candidates into Nrep pairs with uniform prob. (draw with replacement)
    for (i=0;i<Nrep;i++)
    {
        //draw a uniform number in [0,2*Nrep]
        n = (int)(2*Nrep*random_unif());
        pair[i][0] = candidates[n]; 
        
        n = (int)(2*Nrep*random_unif());
        pair[i][1] = candidates[n];  
    }
    
    //***************** REPRODUCTION ************************************
    //Perform reproduction with each pair
    for (i=0;i<Nrep;i++)
    {
        //Cross-over only occurs with probability prob_cross
        p = random_unif();
        if (p<=prob_cross)
        {
            //Get the indices for the two bitstrings of the pair
            a = pair[i][0];
            b = pair[i][1];
            
            //**********BEGIN REDUNANT CODE*********************        
            //Get bitstrings from memory
            for (k=0;k<LENGTH;k++)
            {
                string_a[k] = CLASSIFIERSYSTEM->array[a]->bitstring->array[k];
                string_b[k] = CLASSIFIERSYSTEM->array[b]->bitstring->array[k];
            }
            //**********END REDUNANT CODE*********************
            
            //Random cross-over point
            n = (int)(16*random_unif());
            c = 4+n*9;
            
            //Random cross-over length
            n = (int)(16*random_unif());
            ell= n*9;
            
            //Set start and end bits
            if (c+ell<=LENGTH)
            {
            	start=c;
            	end=c+ell;
            }
            //Prevent overrun on right-hand side and cut to length
/*
            if (c+ell>LENGTH)
            {
                start=c;
                end=LENGTH;            	
            }
*/
            //Prevent overrun on right-hand side and make strings circular
            
            if (c+ell>LENGTH)
            {
            	start=(c+ell)%LENGTH;
            	end=c;
            }
           
            //Crossover the bitstrings
            //**********BEGIN REDUNANT CODE*********************
/*
            for (k=start;k<end;k++)
            {
                temp_a = string_a[k];
                temp_b = string_b[k];
                string_a[k]=temp_b;
                string_b[k]=temp_a;
            }
*/
            //**********END REDUNANT CODE*********************
            
            //Crossover the bitstrings directly in memory
            //Instead of making a local copy, then crossover, then copy to memory
            //we can take the shorter route and copy the crossover bits directly in the memory
            for (k=START;k<END;k++)
            {
                temp_a = CLASSIFIERSYSTEM->array[a]->bitstring->array[k];
                temp_b = CLASSIFIERSYSTEM->array[b]->bitstring->array[k];
                
                CLASSIFIERSYSTEM->array[b]->bitstring->array[k] = temp_a;
                CLASSIFIERSYSTEM->array[a]->bitstring->array[k] = temp_b;
            }
            
            //***************** MUTATION ************************************
            //Mutation of offspring: each bit has probability prob_mut to mutate
            //Case 1. ALL bits have possibility to mutate
            //for (k=0;k<LENGTH;k++)
            //Case 2. Only the copied bits have possibility to mutate
            //This represents errors in copying the bits
            //for (k=start;k<end;k++)
            
            for (k=start;k<end;k++)            {
            {
            	//Mutation only occurs with probability prob_mut
                p = random_unif();
                if (p<=prob_mut)
                {
                    CLASSIFIERSYSTEM->array[a]->bitstring->array[k] = (CLASSIFIERSYSTEM->array[a]->bitstring->array[k]+1)%2;
                }
                p = random_unif();
                if (p<=prob_mut)
                {               
                    CLASSIFIERSYSTEM->array[b]->bitstring->array[k] = (CLASSIFIERSYSTEM->array[b]->bitstring->array[k]+1)%2;
                }
            }           
        }
    }
    
    return 0;
}

//GameSolver_send_ruledetailsystem_message()
//Function sends empty ruledetailsystem_message to signal to 
//GamePlayer agents that there has been a change in rule details.
//(they then need to reset their private classifier to restart a learning round)
int GameSolver_send_ruledetailsystem_message()
{
    add_ruledetailsystem_message(range, x, y, z);
        
    return 0;
}

/* GameSolver_reset_public_classifiersystem()
 * Resets public classifiersystem.
 */
int GameSolver_reset_public_classifiersystem()
{
    //total number of rules:
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<NRRULES; i++)
    {
        CLASSIFIERSYSTEM->array[i]->counter=0;
        CLASSIFIERSYSTEM->array[i]->performance=log(pow(10,-5));
        CLASSIFIERSYSTEM->array[i]->avgperformance=log(pow(10,-5));
    }

    return 0;
} 