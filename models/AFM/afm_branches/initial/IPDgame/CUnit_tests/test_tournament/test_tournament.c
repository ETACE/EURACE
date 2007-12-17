 /****************************************************************
 * test_tournament.c
 * 04/12/07  Sander van der Hoog (svdhoog@gmail.com)
 *****************************************************************
 * TODO:
 * line 163 - 172: why doesn't random_unif() work?
 * line 187 - 190: How can we test the tournament code by iterating the game?
 * How to pass 3 output arguments from a function in order to recursively iterate?
 *****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <D:\Docs\EURACE\X-models\ModelFinancialMarket\SVNWorktree--AFM--C\test_tournament\mylibraryheader.h>
#include <D:\Docs\EURACE\X-models\ModelFinancialMarket\SVNWorktree--AFM--C\test_tournament\test_tournament.h>

//Definitions
#define STATESIZE 4 //size of a state
#define NRSTATES 16 //number of states in the FSM
#define OFFSET 4    //size of first block
#define BLOCKSIZE 9 //1+2*STATESIZE //size of blocks, 9
#define LENGTH 148  //STATESIZE+NRSTATES*BLOCKSIZE  //length of bitstrings, 148
#define TMAX 150	//iterations of IPD game
#define NRAGENTS 2

int main()
{
    
    test_tournament();
    
    return 0;
}

int test_tournament()
{

    int n,i;
    
    int string_a[LENGTH];
    int string_b[LENGTH];
    int string_all_one[LENGTH];
    int string_all_zero[LENGTH];
    
    //Set example automata:
 
    //Always play 0:
    //Start state: 0000
    for (i=0;i<4;i++)
    {
        string_all_zero[i]=0;
    }   
    //Enter into block n=0:15
    for (n=0;n<16;n++)
    {
        for (i=OFFSET+n*BLOCKSIZE; i<OFFSET+(n+1)*BLOCKSIZE; i++)       
        {
            //Check for first bit in block
            if (  ((i%BLOCKSIZE)-OFFSET)==0  )
            {
                string_all_zero[i]=0; //always play 0, no matter what state
            }
            else
            {
                string_all_zero[i]=0; //all other bits 0 means return to state 0000 (and play 0)
            }
        }
    }
    
    //Always play 1:
    //Start state: 0000
    for (i=0;i<4;i++)
    {
        string_all_one[i]=0;
    }
    //Enter into block n=0:15
    for (n=0;n<16;n++)
    {
        //printf("n=%d\n",n);
        for (i=OFFSET+n*BLOCKSIZE; i<OFFSET+(n+1)*BLOCKSIZE; i++)
        {
            //printf("%d\n",i);
            //Check for first bit in block
            if (  ((i%BLOCKSIZE)-OFFSET)==0  )
            {
                string_all_one[i]=1; //play 1, no matter what state
            }
            else
            {
                string_all_one[i]=0; //all other bits 0 means return to state 0000 (and play 1)
            }
        }
    }
        
    for (i=0;i<LENGTH;i++)
    {
        string_a[i] = string_all_zero[i];
        string_b[i] = string_all_one[i];
    }
    
    //Print strings
    printf("String all zero:\n");
    for (i=0;i<LENGTH;i++)
    {
        printf("%d", string_all_zero[i]);
    }
    printf("\n");
    printf("String all one:\n");
    for (i=0;i<LENGTH;i++)
    {
        printf("%d", string_all_one[i]);
    }
    printf("\n");

    printf("String a:\n");
    for (i=0;i<LENGTH;i++)
    {
        printf("%d", string_a[i]);
    }
    printf("\n");
    printf("String b:\n");
    for (i=0;i<LENGTH;i++)
    {
        printf("%d", string_b[i]);
    }
    printf("\n");
    
    test_play_tournament(string_a,string_b);
    
    return 0;
}

int test_play_tournament(int * string_0, int * string_1)
{
	int 		i,j,t;
    int      	result;//result of a game is int
    double		sum;   //sum can be double or int
    double 		outcome[NRAGENTS][NRAGENTS];
    //For testing:
	double 		rule_performance[NRAGENTS];
//	int			move_player0, move_player1;
	int			previous_move_player0, previous_move_player1;
	
    //Match [i vs. j]
    for (i=0;i<NRAGENTS; i++)
    {

    	//Retrieve a copy of the automata bitstring for player i:
/*
    	nr_rule_1 = AUTOMATON->array[i]->current_rule;
        for (k=0;k<LENGTH;k++)
        {
            string_0[k] = RULEDETAILSYSTEM->array[nr_rule_1]->bitstring[k];
        }       
*/
        for (j=0;j<i+1; j++)
        {
/*
            //Reset the starting state of automaton i (since during play, we update the initial state)
            for (k=0;k<4;k++)
            {
            	string_0[k] = RULEDETAILSYSTEM->array[nr_rule_1]->bitstring[k];
            }
            //Retrieve a copy of the automata bitstring for player j:
            nr_rule_2 = AUTOMATON->array[j]->current_rule;
            for (k=0;k<LENGTH;k++)
            {
                string_1[k] = RULEDETAILSYSTEM->array[nr_rule_2]->bitstring[k];
            }
*/
            //Randomly initialize previous_moves in memory
            //we need to initialize these because the first state transition requires a value
/*
        	if (random_unif()>0.5)
            {
                previous_move_player0=0;
            }
            else previous_move_player0=1;
            if (random_unif()>0.5)
            {
                previous_move_player1=0;
            }
            else previous_move_player1=1;
*/
            previous_move_player0=0;
            previous_move_player1=1;
            
            //***************** TOURNAMENT PLAY ***********************            
            //Automaton of agent i plays against Automaton of agent j
            sum=0.0;
            for (t=0;t<TMAX; t++)
            {
                //play_game is a function that should give the outcome of a game played by 2 given automata
                result  = test_play_game(string_0,string_1, previous_move_player0, previous_move_player1);
                sum += (double)result;
                printf("Result t=%d: %d\n",t,result);
                
                //iteration step: outcome of funtion test_play_game is fed back into itself 
                //[result,move_player0,move_player1]  = test_play_game(string_0,string_1, previous_move_player0, previous_move_player1);                
                //previous_move_player0 = move_player0;
                //previous_move_player1 = move_player1;
            }
            //Outcome of the match
            outcome[i][j] = sum/TMAX;
        }
    }
    //Full outcome matrix is symmetric
    for (i=0;i<NRAGENTS;i++)
    {
        for (j=0;j<i;j++)
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
        //AUTOMATA->array[i]->rule_performance = sum/NRAGENTS;
        rule_performance[i] = sum/NRAGENTS;
    }

    //Print entire matrix
     printf("Tournament outcomes:\n");
     for (i=0;i<NRAGENTS;i++)
     {
          for (j=0;j<NRAGENTS;j++)
          {
             	printf("[%d,%d]=%2.5f", i, j, outcome[i][j]);
          }
          printf("|row avg=%2.5f\n", rule_performance[i]);
     }
     printf("\n");
  
    return 0;
}


int test_play_game(int * string_0, int * string_1, int previous_move_player0, int previous_move_player1)
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
    
    //Set the previous moves
/*  
	int previous_move_player0 = 0;
    int previous_move_player1 = 1;
*/
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
        for (i=0;i<4;i++)
        {
            n += pow(2,bitstr[i]);
        }
        
        //Travers the state blocks: each block is 9 bits, the first starting after the 4 bit block 
        //States are 1-16, and we only consider the state block corresponding to current state n.
        
        //Enter into block n
        count=0;
        for (i=OFFSET+(n-1)*BLOCKSIZE; i<OFFSET+n*BLOCKSIZE; i++)
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
    //set_previous_move_player0(move_player0);
    //set_previous_move_player1(move_player1);
    
    //Return only the payoff of player 0
    return payoff[0];
}
