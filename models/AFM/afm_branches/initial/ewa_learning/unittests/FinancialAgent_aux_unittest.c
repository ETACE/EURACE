/*********************************
 * FinancialAgent_aux_unittest.c
 * Unit tests for GA auxiliary functions. 
 * *********************************
 * History:
 * 16/07/08 Sander 
 *********************************/
#include <CUnit/Basic.h>
#include "../header.h"
#include "../FinancialAgent_agent_header.h"
#include "../FinancialAgent_aux_header.h"
#include "../some_new_functions.h"

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



void unittest_two_point_cross_over()
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


void unittest_two_point_cross_over_alt()
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


//int GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id_1, int * rule_id_2)
void unittest_GA_selection()
{
	int size, N_pairs;
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

     EWA_PARAMETERS.EWA_beta = 99;
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
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=1.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].id=20;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[2].avg_performance=1.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].id=30;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[3].avg_performance=1000.0;

     size=4;
 	 parent_index_1 = malloc(size*sizeof(int));
 	 parent_index_2 = malloc(size*sizeof(int));
 	 rule_id_1 = malloc(size*sizeof(int));
 	 rule_id_2 = malloc(size*sizeof(int));

     //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
	 //Unittest 1: 4 rules, reproduction uses 100% of population
	 //Expected result: N_pairs = 2
 	 //EWA.beta=99, so the rule with the best performance gets selected with highest prob.
 	 //Expected result: 
 	 // parent_index_1 = [3,3], parent_index_2 = [3,3]  
 	 // rule_id_1 = [3,3], rule_id_2 = [3,3]

 	 //If reproduction uses only a subset of the population, the size of 'draws' will be different,
 	 //so parent_index_i will differ in size from rule_id_i.
 	 //Then parent_index_i contains indices from 'draws'
 	 
     N_pairs = GA_selection(parent_index_1, parent_index_2, rule_id_1, rule_id_2);
     
     //***** Variables: Memory post-conditions *************************
     CU_ASSERT_EQUAL(N_pairs, 2);
     
     printf("In unittest_GA_selection: parent_index_1[0]=%d, parent_index_1[1]=%d", parent_index_1[0], parent_index_1[1]);
     printf("In unittest_GA_selection: parent_index_2[0]=%d, parent_index_2[1]=%d", parent_index_2[0], parent_index_2[1]);
     CU_ASSERT_EQUAL(parent_index_1[0], 3);
     CU_ASSERT_EQUAL(parent_index_1[1], 3);
     CU_ASSERT_EQUAL(parent_index_2[0], 3);
     CU_ASSERT_EQUAL(parent_index_2[1], 3);

     printf("In unittest_GA_selection: rule_id_1[0]=%d, rule_id_1[1]=%d", rule_id_1[0], rule_id_1[1]);
     printf("In unittest_GA_selection: rule_id_2[0]=%d, rule_id_2[1]=%d", rule_id_2[0], rule_id_2[1]);
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
//GA_reproduction(rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
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
  	GA_PARAMETERS.prob_cross = 0.0;
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

	 rule_id_1[0]=1; rule_id_1[1]=1;
	 rule_id_2[0]=1; rule_id_2[1]=1;
	 
  	 //***** Messages: pre-conditions **********************************

     //***** Function evaluation ***************************************
	 //Unittest 1: reproduction uses 100% of population, cross-over probability is 0%
	 //Random draws of parents to match are all string_1
	 //Expected result: offspring are direct copies of parent_1
  	 j=0;
     GA_reproduction(rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
     
     //***** Variables: Memory post-conditions *************************
     printf("In unittest_GA_reproduction: offspring_1[0]=%d, offspring_1[1]=%d", offspring_1[0], offspring_1[1]);
     printf("In unittest_GA_reproduction: offspring_2[0]=%d, offspring_2[1]=%d", offspring_2[0], offspring_2[1]);
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
*/

/*
//GA_mutation(NR_PARAMS, offspring_1, offspring_2);
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
*/

/*
//GA_election(NR_PARAMS, offspring_1, offspring_2);
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
     GA_election(2, offspring_1, offspring_2);
     
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
*/

/*
//GA_reinsertion(NR_PARAMS, offspring_1, offspring_2, rule_id_1[j], rule_id_2[j]);
void unittest_GA_reinsertion()
{
	int j, size;
	
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
	 rule_id_1 = malloc(size*sizeof(int));
	 rule_id_2 = malloc(size*sizeof(int));

	 offspring_1[0]=1.0;
	 offspring_1[1]=2.0;
	 
	 offspring_2[0]=3.0;
	 offspring_2[1]=4.0;
	 
	 rule_id_1[0]=1;
	 rule_id_1[1]=2;
	 
	 rule_id_2[0]=1;
	 rule_id_2[1]=2;
	 
	 
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
	 GA_reinsertion(NR_PARAMS, offspring_1, offspring_2, rule_id_1[j], rule_id_2[j]);
     
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
*/
