 /****************************************************************
 * test_GA.c
 * 04/12/07  Sander van der Hoog (svdhoog@gmail.com)
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylibraryheader.h"
#include "test_GA.h"

//Definitions
#define STATESIZE 4 //size of a state
#define NRSTATES 16 //number of states in the FSM
#define OFFSET 4    //size of first block
#define BLOCKSIZE 9 //1+2*STATESIZE //size of blocks, 9
#define LENGTH 148  //STATESIZE+NRSTATES*BLOCKSIZE  //length of bitstrings, 148

int main()
{
    
	test_GA();
    
    return 0;
}

int test_GA()
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
    
    test_apply_GA(string_a,string_b);
        
    return 0;
}


int test_apply_GA(int * string_a,int * string_b)
{
    int i,n,c,ell;
    int N = 2; 
    int draw;
    int a,b,k,temp_a,temp_b, start, end;
    double p;
    
    //GA parameters
    int prob_cross = 1.0;      //cross-over probability
    int prob_mut = 0.01;        //mutation probability

    int Nrep_prop = 1.0;        //Proportion of population used for reproduction
    int Nrep = (int)(Nrep_prop*0.5*N); //Number of pairs for reproduction
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
            //Get the two bitstrings of the pair
            a = pair[i][0];
            b = pair[i][1];
            
            //**********BEGIN REDUNANT CODE*********************        
            //Get bitstrings from memory
/*
            for (k=0;k<LENGTH;k++)
            {
                string_a[k] = RULEDETAILSYSTEM->array[a]->bitstring->array[k];
                string_b[k] = RULEDETAILSYSTEM->array[b]->bitstring->array[k];
            }
*/
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
            if (c+ell>LENGTH)
            {
                start=c;
                end=LENGTH;            	
            }
            //Prevent overrun on right-hand side and make strings circular
/*            
            if (c+ell>LENGTH)
            {
            	start=(c+ell)%LENGTH;
            	end=c;
            }
*/
            
            //Crossover the bitstrings
            //**********BEGIN TESTING CODE*********************
            for (k=start;k<end;k++)
            {
                temp_a = string_a[k];
                temp_b = string_b[k];
                string_a[k]=temp_b;
                string_b[k]=temp_a;
            }
            //**********END TESTING CODE*********************
            
            //Crossover the bitstrings directly in memory
            //Instead of making a local copy, then crossover, then copy to memory
            //we can take the shorter route and copy the crossover bits directly in the memory
/*
            for (k=start;k<end;k++)
            {
                temp_a = RULEDETAILSYSTEM->array[a]->bitstring->array[k];
                temp_b = RULEDETAILSYSTEM->array[b]->bitstring->array[k];
                
                RULEDETAILSYSTEM->array[b]->bitstring->array[k] = temp_a;
                RULEDETAILSYSTEM->array[a]->bitstring->array[k] = temp_b;
            }
*/            
            //***************** MUTATION ************************************
            //Mutation of offspring: each bit has probability prob_mut to mutate
            //Case 1. ALL bits have possibility to mutate
            //for (k=0;k<LENGTH;k++)
            //Case 2. Only the copied bits have possibility to mutate
            //This represents errors in copying the bits
            //for (k=start;k<end;k++)
            
/*
            for (k=start;k<end;k++)
            {
                //Mutation only occurs with probability prob_mut
                p = random_unif();
                if (p<=prob_mut)
                {
                    RULEDETAILSYSTEM->array[a]->bitstring->array[k] = (RULEDETAILSYSTEM->array[a]->bitstring->array[k]+1)%2;
                }
                p = random_unif();
                if (p<=prob_mut)
                {               
                    RULEDETAILSYSTEM->array[b]->bitstring->array[k] = (RULEDETAILSYSTEM->array[b]->bitstring->array[k]+1)%2;
                }
            }           
*/
        }
    }

    //Printing the string after crossover
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
    
    
	return 0;
}
