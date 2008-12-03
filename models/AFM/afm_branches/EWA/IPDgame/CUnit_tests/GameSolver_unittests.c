/*********************************
 * GameSolver_unittest.c
 * Unit tests for GameSolver functions. 
 * *********************************
 * History:
 * 09/09/08 Sander
 *********************************/
#include <stdio.h>
#include <CUnit/Basic.h>

#include "../header.h"
#include "../GameSolver_agent_header.h"
#include "../some_new_functions.h"


/*
 * \fn: void unittest_GameSolver_play_tournament()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_play_tournament()
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
    
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	play_tournament(string_a,string_b);
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

/*
 * \fn: void unittest_GameSolver_play_game()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_play_game()
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
    
	//************* At start of unit test, add one agent **************
	//unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
    result = play_game(string_a,string_b);
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
    printf("\n %d\n", result);

	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	//unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	//free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

/*
 * \fn: void unittest_GameSolver_apply_GA()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_apply_GA()
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
    
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
    //Random cross-over point between 0-16
    n = (int)(16*random_unif());
    c = 4+n*9;
    
    //Random cross-over length between 0-16
    n = (int)(16*random_unif());
    ell= n*9;

	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
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

	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}


/*
 * \fn: void unittest_GameSolver_read_rule_performance_update_classifiersystem()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_read_rule_performance_update_classifiersystem()
{
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

/*
 * \fn: void unittest_GameSolver_send_all_performances()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_send_all_performances()
{
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

/*
 * \fn: void unittest_GameSolver_send_rule_details()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_send_rule_details()
{
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

/*
 * \fn: void unittest_GameSolver_reset_public_classifiersystem()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_reset_public_classifiersystem()
{
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}


/*
 * \fn: void unittest_GameSolver_reset_public_classifiersystem()
 * \brief: Unit test for 
 * Test for 
 * Status: Not Tested
 */
void unittest_GameSolver_print_public_classifiersystem()
{
	//************* At start of unit test, add one agent **************
	unittest_init_GameSolver_agent();
	
	//***** Variables: Memory pre-conditions **************************
	
	//***** Messages: pre-conditions **********************************
	
	//***** Function evaluation ***************************************
	
	
	//***** Variables: Memory post-conditions *************************
	//CU_ASSERT_DOUBLE_EQUAL(, 1.0, 1e-3);
	//CU_ASSERT_EQUAL(, 0.0);
	
	//***** Messages: post-conditions **********************************
	
	//************* At end of unit test, free the agent **************
	unittest_free_GameSolver_agent();
	
	//************* At end of unit tests, free all Messages **********
	free_messages();
	
	//************* At end of unit tests, free all pointers **********
	//	 free(offspring_1);	
}

