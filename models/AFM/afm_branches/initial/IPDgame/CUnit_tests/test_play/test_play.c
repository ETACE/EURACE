/****************************************************************
 * test_GA.c
 * 04/12/07  Sander van der Hoog (svdhoog@gmail.com)
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <D:\Docs\EURACE\X-models\ModelFinancialMarket\SVNWorktree--AFM--C\test_play\mylibraryheader.h>
#include <D:\Docs\EURACE\X-models\ModelFinancialMarket\SVNWorktree--AFM--C\test_play\test_play.h>

//Definitions
#define STATESIZE 4 //size of a state
#define NRSTATES 16 //number of states in the FSM
#define OFFSET 4    //size of first block
#define BLOCKSIZE 9 //1+2*STATESIZE //size of blocks, 9
#define LENGTH 148  //STATESIZE+NRSTATES*BLOCKSIZE  //length of bitstrings, 148

int main()
{
    
    test_play();
    
    return 0;
}

int test_play()
{

    int n,i, result;
    
    int string_a[LENGTH];
    int string_b[LENGTH];
    int string_all_one[LENGTH];
    int string_all_zero[LENGTH];
    
    //Set example automata:

    //  int block[NRSTATES][STATESIZE];

    /*
    block[0][]  = {0,0,0,0};
    block[1][]  = {0,0,0,1};
    block[2][]  = {0,0,1,0};
    block[3][]  = {0,0,1,1};
    block[4][]  = {0,1,0,0};
    block[5][]  = {0,1,0,1};
    block[6][]  = {0,1,1,0};
    block[7][]  = {0,1,1,1};
    block[8][]  = {1,0,0,0};
    block[9][]  = {1,0,0,1};
    block[10][] = {1,0,1,0};
    block[11][] = {1,0,1,1};
    block[12][] = {1,1,0,0};
    block[13][] = {1,1,0,1};
    block[14][] = {1,1,1,0};
    block[15][] = {1,1,1,1};
*/
    
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
    
    result = test_play_game(string_a,string_b);
    
    printf("%d", result);
    
    return 0;
}


int test_play_game(int * string_0, int * string_1)
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
    int previous_move_player0 = 0;
    int previous_move_player1 = 1;
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
