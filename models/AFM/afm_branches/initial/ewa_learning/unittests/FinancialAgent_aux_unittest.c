/*********************************
 * FinancialAgent_aux_unittest.c
 * Unit tests for GA auxiliary functions. 
 * *********************************
 * History:
 * 16/07/08 Sander 
 *********************************/
#include <stdio.h>
#include <CUnit/Basic.h>
#include <string.h> //required for strcat, strcpy
#include <limits.h> //required to test for max. double: ULONG_MAX

#include "../header.h"
#include "../FinancialAgent_agent_header.h"
#include "../FinancialAgent_aux_header.h"
#include "../some_new_functions.h"

/*
 * \fn: void unittest_single_point_cross_over()
 * \brief: Unit test for single_point_cross_over()
 * Test for 1-point cross-over: 2 bits crossed over.
 * Status: Tested OK
 */
void unittest_single_point_cross_over()
{
	// Variables: Memory pre-conditions **************************
	int c;
	int size;
	double * xvec;
	double * yvec;

	size=4;
	xvec = malloc(size*sizeof(double));
	yvec = malloc(size*sizeof(double));
	xvec[0]=0.1; xvec[1]=0.1; xvec[2]=0.1; xvec[3]=0.1;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2;

	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
		
	// Function evaluation ***************************************
	//void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
	printf("\n Before single_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n Before single_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

	single_point_cross_over(size, xvec, yvec, c);

	printf("\n After single_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n After single_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

    // Variables: Memoryvec post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.1, 1e-3);

	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest1_two_point_cross_over()
 * \brief: Unit test for two_point_cross_over()
 * Simple test for 2-point cross-over: 1 bit crossed over.
 * Status: Tested OK
 */
void unittest1_two_point_cross_over()
{
	int c, ell, size;
	double * xvec;
	double * yvec;
	
    // ***** Variables: Memoryvec pre-conditions **************************
	size=4;
    xvec = malloc(size*sizeof(double));
    yvec = malloc(size*sizeof(double));
	xvec[0]=0.1; xvec[1]=0.1; xvec[2]=0.1; xvec[3]=0.1;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=1;
	printf("\n point c=%d, length ell=%d",c, ell);
	
    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n Before two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

	two_point_cross_over(size, xvec, yvec, c, ell);

	printf("\n After two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n After two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

    // ***** Variables: Memory post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.2, 1e-3);

	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest1_two_point_cross_over()
 * \brief: Unit test for two_point_cross_over()
 * Test 2-point cross-over for proper handling of wrap-around: string size=4, cross-over point=2, length=3.
 * Status: Tested OK
 */
void unittest2_two_point_cross_over()
{
	int c, ell, size;
	double * xvec;
	double * yvec;
	
    // ***** Variables: Memoryvec pre-conditions **************************
	size=4;
    xvec = malloc(size*sizeof(double));
    yvec = malloc(size*sizeof(double));
	xvec[0]=0.1; xvec[1]=0.1; xvec[2]=0.1; xvec[3]=0.1;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=3;
	printf("\n point c=%d, length ell=%d",c, ell);
	
    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n Before two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

	two_point_cross_over(size, xvec, yvec, c, ell);

	printf("\n After two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n After two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

    // ***** Variables: Memory post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.1, 1e-3);

	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest1_two_point_cross_over_alt()
 * \brief: Unit test for two_point_cross_over_alt()
 * Simple test for 2-point cross-over: 1 bit crossed over.
 * Status: Tested OK
 */
void unittest1_two_point_cross_over_alt()
{
	int c, ell, size;
	double * xvec;
	double * yvec;

	
    // ***** Variables: Memory pre-conditions **************************
	size=4;
    xvec = malloc(size*sizeof(double));
    yvec = malloc(size*sizeof(double));
	xvec[0]=0.1; xvec[1]=0.1; xvec[2]=0.1; xvec[3]=0.1;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=1;
	printf("\n point c=%d, length ell=%d",c, ell);
	
    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n Before two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

	two_point_cross_over_alt(size, xvec, yvec, c, ell);

	printf("\n After two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n After two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

    // ***** Variables: Memoryvec post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.2, 1e-3);

	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest2_two_point_cross_over_alt()
 * \brief: Unit test for two_point_cross_over_alt()
 * Test 2-point cross-over for proper handling of wrap-around: string size=4, cross-over point=2, length=3.
 * Status: Tested OK
 */
void unittest2_two_point_cross_over_alt()
{
	int c, ell, size;
	double * xvec;
	double * yvec;

	
    // ***** Variables: Memory pre-conditions **************************
	size=4;
    xvec = malloc(size*sizeof(double));
    yvec = malloc(size*sizeof(double));
	xvec[0]=0.1; xvec[1]=0.1; xvec[2]=0.1; xvec[3]=0.1;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=3;
	printf("\n point c=%d, length ell=%d",c, ell);
	
    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n Before two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

	two_point_cross_over_alt(size, xvec, yvec, c, ell);

	printf("\n After two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3]);
	printf("\n After two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3]);

    // ***** Variables: Memoryvec post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.2, 1e-3);
    
	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest3_two_point_cross_over_alt()
 * \brief: Unit test for two_point_cross_over_alt()
 * Test 2-point cross-over for proper handling of wrap-around: string size=8, cross-over point=7, length=3.
 * Status: Tested OK
 */
void unittest3_two_point_cross_over_alt()
{
	int c, ell, size;
	double * xvec;
	double * yvec;

	
    // ***** Variables: Memory pre-conditions **************************
	size=8;
    xvec = malloc(size*sizeof(double));
    yvec = malloc(size*sizeof(double));
	xvec[0]=0.0; xvec[1]=0.0; xvec[2]=0.0; xvec[3]=0.0; xvec[4]=0.0; xvec[5]=0.0; xvec[6]=0.0; xvec[7]=0.0;
	yvec[0]=0.2; yvec[1]=0.2; yvec[2]=0.2; yvec[3]=0.2; yvec[4]=0.2; yvec[5]=0.2; yvec[6]=0.2; yvec[7]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=7;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=3;
	printf("\n point c=%d, length ell=%d",c, ell);
	
    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3], xvec[4], xvec[5], xvec[6], xvec[7]);
	printf("\n Before two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3], yvec[4], yvec[5], yvec[6], yvec[7]);

	two_point_cross_over_alt(size, xvec, yvec, c, ell);

	printf("\n After two_point_cross_over: xvec=[%1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f]\n", xvec[0], xvec[1], xvec[2], xvec[3], xvec[4], xvec[5], xvec[6], xvec[7]);
	printf("\n After two_point_cross_over: yvec=[%1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f, %1.1f]\n", yvec[0], yvec[1], yvec[2], yvec[3], yvec[4], yvec[5], yvec[6], yvec[7]);

    // ***** Variables: Memoryvec post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(xvec[0], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[1], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[3], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[4], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[5], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[6], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(xvec[7], 0.0, 1e-3);
    
    CU_ASSERT_DOUBLE_EQUAL(yvec[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[2], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[3], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[4], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[5], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[6], 0.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(yvec[7], 0.2, 1e-3);
    
	free(xvec);
	free(yvec);
}

/*
 * \fn: void unittest_mutation()
 * \brief: Unit test for 
 * Status: Not tested
 */
void unittest_mutation()
{   
 	// At start of unit test, add one agent
    //unittest_init_FinancialAgent_agent();
    //current_xmachine = *p_xmachine;

    // Variables: Memory pre-conditions 
	int j, size;
	
	double * string;
	double * stepsize;
	double prob_mut;
	
	size = 4;
	string = malloc(size*sizeof(double));
	stepsize = malloc(size*sizeof(double));
	
	string[0]=1.0; string[1]=1.0; string[2]=1.0; string[3]=1.0;
	stepsize[0]=0.01; stepsize[1]=0.01; stepsize[2]=0.01; stepsize[3]=0.01;
	prob_mut = 1.0;
	
    printf("\n Before mutation vec = [ ");
    for (j=0;j<size;j++)
    {
    	printf("%2.2f ", string[j]);
    }
    printf("]\n");

    // Function evaluation  
	//void mutation(int size, double * string);
	mutation(size, string, stepsize, prob_mut);
	
    printf("\n After mutation vec = [ ");
    for (j=0;j<size;j++)
    {
    	printf("%2.2f ", string[j]);
    }
    printf("]\n");

    // Variables: Memory post-conditions 
	//CU_ASSERT_EQUAL(<var_name2>, <value>);

	// free();
}

/*
 * \fn: void unittest_GA_selection()
 * \brief: Unit test for int GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id_1, int * rule_id_2)
 * Expected result: rule 3 is selected. 
 * Status: Tested OK, using max value for (beta*performance)=709.0.
 */
void unittest_GA_selection()
{
	int N_rep, N_pairs;
	int * parent_index_1; //contains random draws from interval [0, N_pairs], used for random matching
	int * parent_index_2; //contains random draws from interval [0, N_pairs], used for random matching
	int * rule_id_1;      //contains the rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	int * rule_id_2;

    //************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();

    //***** Variables: Memory pre-conditions **************************
   	//Initializations:
   	//EWA_PARAMETERS.EWA_beta: used for the determination of fitness-proportional selection probabilities, exp(beta*performance)
   	//GA_PARAMETERS.prob_cross: cross-over probability
   	//GA_PARAMETERS.prob_mut: mutation  probability
   	//GA_PARAMETERS.string_size: length of strings
   	//GA_PARAMETERS.single_point_crossover: dummy for single_point_crossover (if 1: use single point cross-over, 0: use two point cross-over) 
   	//GA_PARAMETERS.pop_size
   	//GA_PARAMETERS.reproduction_proportion 
   	//GA_PARAMETERS.election: dummy for election operator
   	//GA_PARAMETERS.stepsize: vector of stepsizes for mutation of real-valued parameters

     EWA_PARAMETERS.EWA_beta = 1;
   	 GA_PARAMETERS.pop_size = 4;
   	 GA_PARAMETERS.reproduction_proportion = 1.0;
   	
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =4;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=10;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].id=20;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].avg_performance=0.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].id=30;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].avg_performance=709.0;

     N_rep = (int) 2*floor((GA_PARAMETERS.reproduction_proportion * GA_PARAMETERS.pop_size)/2);
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: N_rep=%d\n", N_rep);
 	
 	 // N_pairs is the number of parent pairs that are produced by random matching from the N_rep draws
     N_pairs = (int) N_rep/2;
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: N_pairs=%d\n", N_pairs);

     //all mallocs are done inside the function GA_selection():
     parent_index_1 = malloc(sizeof(int)*N_pairs);
     parent_index_2 = malloc(sizeof(int)*N_pairs);
     rule_id_1 = malloc(sizeof(int)*N_pairs);
     rule_id_2 = malloc(sizeof(int)*N_pairs);

     //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
	 //Unittest 1:
 	 // - 4 rules, reproduction uses 100% of population
 	 // - EWA.beta=1, performance of rule 3 is highest.
	 //Expected result:
 	 // - N_pairs = 2; 1st pair: (rule 3, rule 3); 2nd pair: (rule 3, rule 3)
  	 // - parent_index_1 = [3,3], parent_index_2 = [3,3]  
 	 // - rule_id_1 = [3,3], rule_id_2 = [3,3]
 	 
 	 //If reproduction uses only a subset of the population, the size of 'draws' will be different,
 	 //so parent_index_i will differ in size from rule_id_i.
 	 //Then parent_index_i contains indices from 'draws'
 	 
     GA_selection(N_pairs, parent_index_1, parent_index_2, rule_id_1, rule_id_2);
     
     //***** Variables: Memory post-conditions *************************
     CU_ASSERT_EQUAL(N_pairs, 2);
     
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: parent_index_1=[%d, %d]\n", parent_index_1[0], parent_index_1[1]);
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: parent_index_2=[%d, %d]\n", parent_index_2[0], parent_index_2[1]);
     
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: rule_id_1=[%d, %d]\n", rule_id_1[0], rule_id_1[1]);
     if(PRINT_DEBUG) printf("\n In unittest_GA_selection: rule_id_2=[%d, %d]\n", rule_id_2[0], rule_id_2[1]);
     
     CU_ASSERT_EQUAL(rule_id_1[0], 3);
     CU_ASSERT_EQUAL(rule_id_1[1], 3);
     CU_ASSERT_EQUAL(rule_id_2[0], 3);
     CU_ASSERT_EQUAL(rule_id_2[1], 3);

     //***** Messages: post-conditions **********************************

     //************* At end of unit test, free the agent **************
     unittest_free_FinancialAgent_agent();
     //************* At end of unit tests, free all Messages **********
     free_messages();

     //************* At end of unit tests, free all pointers **********
 	 free(parent_index_1);
 	 free(parent_index_2);	
 	 free(rule_id_1);
 	 free(rule_id_2);
}

/*
 * \fn: void unittest_GA_reproduction()
 * \brief: Unit test for GA_reproduction(rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
 * Status: Tested OK
 */
void unittest_GA_reproduction()
{
	int j, size;
	int * rule_id_1;      //contains rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	int * rule_id_2;      //contains rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

    //************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();


    //***** Variables: Memory pre-conditions **************************
  	//Initializations:
  	//EWA_PARAMETERS.EWA_beta: used for the determination of fitness-proportional selection probabilities, exp(beta*performance)
  	//GA_PARAMETERS.prob_cross: cross-over probability
  	//GA_PARAMETERS.prob_mut: mutation  probability
  	//GA_PARAMETERS.string_size: length of strings
  	//GA_PARAMETERS.single_point_crossover: dummy for single_point_crossover (if 1: use single point cross-over, 0: use two point cross-over) 
  	//GA_PARAMETERS.pop_size: population size
  	//GA_PARAMETERS.reproduction_proportion: percentage of population
  	//GA_PARAMETERS.election: dummy for election operator
  	//GA_PARAMETERS.stepsize: vector of stepsizes for mutation of real-valued parameters
      //mutation = value + delta*stepsize[k]*string[k] with delta = random_unif_interval(-10.0%, +10.0%);
      //for unittesting:
      //prob_mut = 1.0, value = 0.0, delta = 10.0, stepsize = 0.01
      //0.0 -> 0.10
      //prob_mut = 1.0, value = 0.0, delta = 10.0, stepsize = 0.05
      //0.0 -> 0.50

  	EWA_PARAMETERS.EWA_beta = 1.0;
  	GA_PARAMETERS.prob_cross = 0.0; //no cross-over
  	GA_PARAMETERS.pop_size = 2;
  	GA_PARAMETERS.reproduction_proportion = 1.00;

    PUBLIC_CLASSIFIERSYSTEM.nr_rules =2;
    PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
    PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[0]=1.0;
    PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[1]=2.0;
    
    PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
    PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[0]=3.0;
    PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[1]=4.0;

	 size=2;
	 offspring_1 = malloc(size*sizeof(double));
	 offspring_2 = malloc(size*sizeof(double));
	 rule_id_1 = malloc(size*sizeof(int));
	 rule_id_2 = malloc(size*sizeof(int));

 	 offspring_1[0]=0.0; offspring_1[1]=0.0;
 	 offspring_2[0]=0.0; offspring_2[1]=0.0;

	 rule_id_1[0]=0; rule_id_1[1]=0; //this should create: parent_1=[1.0, 2.0]
	 rule_id_2[0]=0; rule_id_2[1]=0; //this should create: parent_2=[1.0, 2.0] as well.
	 
  	 //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
	 //Unittest 1: reproduction uses 100% of population, cross-over probability is 0%
	 //Random draws of parents to match are all string_1
	 //Expected result: offspring are direct copies of parent_1
  	 j=0;
  	 printf("\n Entering GA_reproduction with: rule_id_1[j]=%d rule_id_2[j]=%d.\n", rule_id_1[j], rule_id_1[j]);
     GA_reproduction(size, rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
     
     //***** Variables: Memory post-conditions *************************
     printf("\n In unittest_GA_reproduction: offspring_1=[%1.1f, %1.1f]\n", offspring_1[0], offspring_1[1]);
     printf("\n In unittest_GA_reproduction: offspring_2=[%1.1f, %1.1f]\n", offspring_2[0], offspring_2[1]);
     CU_ASSERT_DOUBLE_EQUAL(offspring_1[0], 1.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_1[1], 2.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_2[0], 1.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_2[1], 2.0, 1e-3);

     //***** Messages: post-conditions **********************************

     //************* At end of unit test, free the agent **************
     unittest_free_FinancialAgent_agent();
     //************* At end of unit tests, free all Messages **********
     //free_messages();

     //************* At end of unit tests, free all pointers **********
 	 free(rule_id_1);
 	 free(rule_id_2);
 	 free(offspring_1);
 	 free(offspring_2);	
}

/*
 * \fn: void unittest_GA_mutation()
 * \brief: Unit test for GA_mutation(NR_PARAMS, offspring_1, offspring_2);
 * Status: Tested OK
 */
void unittest_GA_mutation()
{
	int size;
	
	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

    //************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();


     //***** Variables: Memory pre-conditions **************************
 	//Initializations:
 	//EWA_PARAMETERS.EWA_beta: used for the determination of fitness-proportional selection probabilities, exp(beta*performance)
 	//GA_PARAMETERS.prob_cross: cross-over probability
 	//GA_PARAMETERS.prob_mut: mutation  probability
 	//GA_PARAMETERS.string_size: length of strings
 	//GA_PARAMETERS.single_point_crossover: dummy for single_point_crossover (if 1: use single point cross-over, 0: use two point cross-over) 
 	//GA_PARAMETERS.pop_size: population size
 	//GA_PARAMETERS.reproduction_proportion: percentage of population
 	//GA_PARAMETERS.election: dummy for election operator
 	//GA_PARAMETERS.stepsize: vector of stepsizes for mutation of real-valued parameters
     //mutation = value + delta*stepsize[k]*string[k] with delta = random_unif_interval(-10.0%, +10.0%);
     //for unittesting:
     //prob_mut = 1.0, value = 0.0, delta = 10.0, stepsize = 0.01
     //0.0 -> 0.10
     //prob_mut = 1.0, value = 0.0, delta = 10.0, stepsize = 0.05
     //0.0 -> 0.50

 	EWA_PARAMETERS.EWA_beta = 1.0;
 	GA_PARAMETERS.prob_mut=1.00;
 	GA_PARAMETERS.stepsize[0]=0.01;
 	GA_PARAMETERS.stepsize[1]=0.05;

 	size=2;
 	offspring_1 = malloc(size*sizeof(double));
 	offspring_2 = malloc(size*sizeof(double));
	
 	offspring_1[0]=0.0; offspring_1[1]=0.0;
 	offspring_2[0]=0.0; offspring_2[1]=0.0;

     //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
 	 //Unittest 1: mutation is certain, mutate bits of both strings by certain stepsize
 	 GA_mutation(size, offspring_1, offspring_2);
     
     //***** Variables: Memory post-conditions *************************
     printf("\n In unittest_GA_mutation: offspring_1=[%1.5f, %1.5f]\n", offspring_1[0], offspring_1[1]);
     printf("\n In unittest_GA_mutation: offspring_2=[%1.5f, %1.5f]\n", offspring_2[0], offspring_2[1]);
     CU_ASSERT_DOUBLE_EQUAL(offspring_1[0], 0.01, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_1[1], 0.05, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_2[0], 0.01, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(offspring_2[1], 0.05, 1e-3);
     
     
     //***** Messages: post-conditions **********************************

     //************* At end of unit test, free the agent **************
     unittest_free_FinancialAgent_agent();
     //************* At end of unit tests, free all Messages **********
     //free_messages();

     //************* At end of unit tests, free all pointers **********
  	 free(offspring_1);
  	 free(offspring_2);	
}

/*
 * \fn: void unittest_GA_election()
 * \brief: Unit test for GA_election(NR_PARAMS, offspring_1, offspring_2);
 * Status: Not tested
 */
void unittest_GA_election()
{
	int size;
	
	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

    ///************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();


    //***** Variables: Memory pre-conditions **************************
  	size=2;
  	offspring_1 = malloc(size*sizeof(double));
  	offspring_2 = malloc(size*sizeof(double));
 	
  	offspring_1[0]=0.0; offspring_1[1]=0.0;
  	offspring_2[0]=0.0; offspring_2[1]=0.0;

     //***** Messages: pre-conditions *********************************

     //***** Function evaluation **************************************
     GA_election(size, offspring_1, offspring_2);
     
     //***** Variables: Memory post-conditions ************************
//     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter, 0.0, 1e-3);

     //***** Messages: post-conditions ********************************

     //************* At end of unit test, free the agent **************
     unittest_free_FinancialAgent_agent();
     //************* At end of unit tests, free all Messages **********
     free_messages();

     //************* At end of unit tests, free all pointers **********
   	 free(offspring_1);
   	 free(offspring_2);	
}

/*
 * \fn: void unittest_GA_reinsertion()
 * \brief: Unit test for GA_reinsertion(NR_PARAMS, offspring_1, offspring_2, rule_id_1[j], rule_id_2[j]);
 * \desc: Tests whether 2 strings are correctly inserted in the rule table.
 * Status: Tested OK
 */
void unittest_GA_reinsertion()
{
	int j, size, Npairs;
	
	int * rule_id_1;      //contains rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	int * rule_id_2;      //contains rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]

     //************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();

     //***** Variables: Memory pre-conditions **************************
	 size=2;
	 offspring_1 = malloc(size*sizeof(double));
	 offspring_2 = malloc(size*sizeof(double));

	 offspring_1[0]=1.0; offspring_1[1]=2.0;
	 offspring_2[0]=3.0; offspring_2[1]=4.0;
	 
	 Npairs=1;
	 rule_id_1 = malloc(Npairs*sizeof(int));
	 rule_id_2 = malloc(Npairs*sizeof(int));
	 
	 rule_id_1[0]=0; //This gives the 1st index in the ruletable[id1]
	 rule_id_2[0]=1; //This gives the 2nd index in the ruletable[id2]
	 
	 
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[0]=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[1]=0.0;
     
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[0]=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[1]=0.0;

     //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
     //Unittest 1: copy offspring_1 -> ruletable[id1] and offspring_2 -> ruletable[id2] 
     j=0;
	 GA_reinsertion(size, offspring_1, offspring_2, rule_id_1[j], rule_id_2[j]);
     
     //***** Variables: Memory post-conditions *************************
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[0], 1.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[1], 2.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[0], 3.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[1], 4.0, 1e-3);

     //***** Messages: post-conditions **********************************

     //************* At end of unit test, free the agent **************
     unittest_free_FinancialAgent_agent();
     //************* At end of unit tests, free all Messages **********
     //free_messages();

     //************* At end of unit tests, free all pointers **********
   	 free(offspring_1);
   	 free(offspring_2);	
 	 free(rule_id_1);
 	 free(rule_id_2);
}


//Status: Tested OK
void test_print()
{	
	char str[10];
	char * filename;
	FILE * file;
	int i;
	
	//Set the output file:
	i = sprintf(str, "%d", iteration_loop);

	printf("iteration_loop in sprintf is %s\n", str);
	printf("sprintf returns: %d\n\n", i);
		
	filename = malloc(20*sizeof(char));
	filename[0]=0;
	
	//now concatenate
	strcpy(filename, "./log/CS_");
	strcat(filename, str);
	strcat(filename, ".txt");
	printf("File to write data to: %s\n\n", filename);

	//Open a file pointer: FILE *Fp 
	printf("\n Appending data to file: %s. Starting to write...\n", filename);
	file = fopen(filename,"a");

	fprintf(file, "\n Appending data to file\n");
	
	//Enter code here
	
	
	fclose(file);
}

/*
 * \fn: void unittest_FinancialAgent_print_public_classifiersystem()
 * \brief: Unit test for FinancialAgent_print_public_classifiersystem
 * Status: Tested OK
 */
void unittest_FinancialAgent_print_public_classifiersystem()
{	
	char str[10];
	char * filename;
	FILE * file;

	int i, rule_id, counter;
	double performance, avg_performance, choiceprob;
	double p0,p1,p2,p3;

 	//Set the output file:
 	i = sprintf(str, "%d", iteration_loop);
 	printf("\n iteration_loop in sprintf is %s\n", str);
 	//printf("sprintf returns: %d\n\n", i);
 	
 	//Start an empty string for the filename
 	filename = malloc(20*sizeof(char));
 	filename[0]=0;
 	
 	//Concatenate
 	strcpy(filename, "./log/CS_");
 	strcat(filename, str);
 	strcat(filename, ".txt");
 	printf(" File to write data to: %s\n", filename);

 	//Open a file pointer: FILE * file 
 	printf("\nAppending data to file: %s. Starting to write...\n", filename);
 	file = fopen(filename,"a");
 	fprintf(file, "\nAppending data to file\n");

    //************* At start of unit test, add one agent **************
     unittest_init_FinancialAgent_agent();

    //***** Variables: Memory pre-conditions **************************    
    //Initializations:
   	//EWA_PARAMETERS.EWA_beta: used for the determination of fitness-proportional selection probabilities, exp(beta*performance)
   	//GA_PARAMETERS.prob_cross: cross-over probability
   	//GA_PARAMETERS.prob_mut: mutation  probability
   	//GA_PARAMETERS.string_size: length of strings
   	//GA_PARAMETERS.single_point_crossover: dummy for single_point_crossover (if 1: use single point cross-over, 0: use two point cross-over) 
   	//GA_PARAMETERS.pop_size
   	//GA_PARAMETERS.reproduction_proportion 
   	//GA_PARAMETERS.election: dummy for election operator
   	//GA_PARAMETERS.stepsize: vector of stepsizes for mutation of real-valued parameters

     EWA_PARAMETERS.EWA_beta = 99;
   	 GA_PARAMETERS.pop_size = 4;
   	 GA_PARAMETERS.reproduction_proportion = 1.0;
   	
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =4;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=10;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=3;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=1.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].id=20;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].counter=5;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].avg_performance=1.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].id=30;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].counter=7;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].avg_performance=1000.0;

     
	//Print comments/notes:
    fprintf(file,"Logfile: Print-out of all classifier systems. \n");
    fprintf(file,"Note 1: The performance and counter columns for the households are copied from the FinancialAdvisors CS. \n");
    fprintf(file,"Note 2: The avgperformance column can contain different values for two households, since it contains the copy from the FinancialAdvisors CS at the moment of the households most recent portfolio update. \n\n");

    //Print FinancialAdvisor classifier system:
    fprintf(file,"=============================================================================================\n");
    fprintf(file,"FinancialAdvisor:\n");
    fprintf(file,"rule id\t performance\t counter\t avg_performance\t rule details\n");
    fprintf(file,"=============================================================================================\n"); 

    for (i=0;i<PUBLIC_CLASSIFIERSYSTEM.nr_rules;i++)
    {
        rule_id 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].id;
        performance 	= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].performance;
		counter 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].counter;         
        avg_performance = PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance;
  	    p0		 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters[0];
 	    p1		 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters[1];
 	    p2		 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters[2];
 	    p3		 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters[3];

        fprintf(file,"%8d\t %.4f\t %8d\t %.4f\t [%1.1f, %1.1f, %1.1f, %1.1f]\n", rule_id, performance, counter, avg_performance, p0, p1, p2, p3);
    }
     fprintf(file,"=============================================================================================\n");

    fprintf(file,"\n");
	fclose(file);
 	printf("\n Finished writing and closed the file stream.\n");

}
