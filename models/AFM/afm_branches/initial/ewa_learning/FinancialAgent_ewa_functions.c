/***************************************************************************************************
 * FinancialAgent_ewa_functions.c 
 * Functions for EWA learning module.
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *************************************************************************************************
 * History:
 * 24/07/08 Sander: Checked that all malloc pointers are freed at the end of functions. 
 * 22/05/08 Sander: Checked to conform to Xparser 0.15.7
 * 29/02/08 Sander: Converted code to use . instead of -> for structs.
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 * 15/07/08 Sander: Coded new function FinancialAgent_apply_GA_refactored() and auxiliary functions.
 ***************************************************************************************************/
#include <math.h>
//For stand-alone model:
//#include "header.h"
//#include "FinancialAgent_agent_header.h"
//For integrated model:
#include "../header.h"
#include "../FinancialAgent_agent_header.h"
//Always:
#include "FinancialAgent_aux_header.h"
#include "some_new_functions.h"
#include "mylibraryheader.h"

/* \fn: FinancialAgent_initialize_rule_details()
 * \brief Function to initialize the rule details. This function is run only once at the start of simulation,
 * in order to randomly initialize the parameters of the rules and propagate these rule details to all households.
 */
int FinancialAgent_initialize_rule_details()
{
	int i,j;

	//initialize the rules
	for (i=0;i<PUBLIC_CLASSIFIERSYSTEM.nr_rules;i++)
	{
		for (j=0;j<NR_PARAMS;j++)
		{
			//printf("\n Now entering param %d.\n");
			PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters[j] =  random_unif_interval((double)GA_PARAMETERS.min_values[j], (double)GA_PARAMETERS.max_values[j]);			
		}
		add_initial_rule_details_message(i, PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters);
	}
	
	return 0;
}

/* \fn FinancialAgent_read_rule_performance_and_update_classifiersystem()
 * \brief Financial Agent reads the rule_performance_messages and updates the average rule performance in its classifiersystem.
 */
int FinancialAgent_read_rule_performance_and_update_classifiersystem()
{
      int rule_id;
      double rule_performance;
    
      START_RULE_PERFORMANCE_MESSAGE_LOOP
      	rule_id = rule_performance_message->rule_id;
        rule_performance = rule_performance_message->rule_performance;
    
        /* Update rule performance: */
        //Replace old performance adding new performance: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY? 
        PUBLIC_CLASSIFIERSYSTEM.ruletable[rule_id].performance += rule_performance;
        
        //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
        PUBLIC_CLASSIFIERSYSTEM.ruletable[rule_id].counter +=1;
        
        //Average performance update:
        PUBLIC_CLASSIFIERSYSTEM.ruletable[rule_id].avg_performance = PUBLIC_CLASSIFIERSYSTEM.ruletable[rule_id].performance / PUBLIC_CLASSIFIERSYSTEM.ruletable[rule_id].counter;
      FINISH_RULE_PERFORMANCE_MESSAGE_LOOP

   return 0;}

/* \fn FinancialAgent_send_all_performances()
 * \brief FinancialAgent sends for each rule the avg_performance in a separate message.
 */
int FinancialAgent_send_all_performances()
{
	int i;
	
    //Send the average performance of each rule
    for (i=0;i<PUBLIC_CLASSIFIERSYSTEM.nr_rules;i++)
    {
        add_new_performances_message(i, PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance);
    }
    
  return 0;
}

/* \fn FinancialAgent_apply_GA_refactored()
 * \brief FinancialAgent applies the GA to the rule details parameters.
 */
int FinancialAgent_apply_GA()
{
	// Prototypes used:
	//void GA_selection(int N_pairs, int * parent_index_1, int * parent_index_2, int * rule_id_1, int * rule_id_2);
	//void GA_reproduction(int id1, int id2, double * offspring_1, double * offspring_2);
	//void GA_mutation(int size, double * offspring_1, double * offspring_2);
	//void GA_election(int size, double * offspring_1, double * offspring_2);
	//void GA_reinsertion(int size, double * offspring_1, double * offspring_2, int id1, int id2);

	int j, N_rep, N_pairs;
	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]
	int * parent_index_1; //contains random draws from interval [0, N_pairs], used for random matching
	int * parent_index_2; //contains random draws from interval [0, N_pairs], used for random matching
	int * rule_id_1;      //contains the rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	int * rule_id_2;

	
	//create space for offspring copy of the parents
	offspring_1 = malloc(sizeof(double)*NR_PARAMS);
	offspring_2 = malloc(sizeof(double)*NR_PARAMS);

	//all malloc calls that depend on N_pairs:
	//parent_index_1, parent_index_2, rule_id_1, rule_id_2
	
	// N_rep is some fixed percentage of the population size pop_size, and should be even.
	N_rep = (int) 2*floor((GA_PARAMETERS.reproduction_proportion * GA_PARAMETERS.pop_size)/2);
	if(PRINT_DEBUG) printf("\n In FinancialAgent_apply_GA: N_rep=%d\n", N_rep);
	
	// N_pairs is the number of parent pairs that are produced by random matching from the N_rep draws
    N_pairs = (int) N_rep/2;
    if(PRINT_DEBUG) printf("\n In FinancialAgent_apply_GA: N_pairs=%d\n", N_pairs);

	// Create N_pairs parent pairs by random matching from the N_rep draws (N_pairs = (int) 0.5*N_rep)
    parent_index_1 = malloc(sizeof(int)*N_pairs);
    parent_index_2 = malloc(sizeof(int)*N_pairs);
    rule_id_1 = malloc(sizeof(int)*N_pairs);
    rule_id_2 = malloc(sizeof(int)*N_pairs);

	//Evolutionary operators:
    // - select N_pairs by randomly matching N_rep individuals
    // - fill in the rule_id arrays with rule indices.
	GA_selection(N_pairs, parent_index_1, parent_index_2, rule_id_1, rule_id_2);
	
	for (j=0; j<N_pairs; j++)
	{    
		GA_reproduction(NR_PARAMS, rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
		GA_mutation(NR_PARAMS, offspring_1, offspring_2);
		GA_election(NR_PARAMS, rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
		GA_reinsertion(NR_PARAMS, rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
	}

	
	
	// free all allocated memory
	free(offspring_1);
	free(offspring_2);
	free(parent_index_1);
	free(parent_index_2);	
	free(rule_id_1);
	free(rule_id_2);

	return 0;
}

/* \fn FinancialAgent_send_rule_details()
 * \brief FinancialAgent sends new rule details. For each rule, a separate message is sent containing the static array parameters[10].
 */
int FinancialAgent_send_rule_details()
{
	int i;
	
	//Send new rule details in a rule_details_messsage
	//The message contains the static array parameters[10]
	for (i=0;i<PUBLIC_CLASSIFIERSYSTEM.nr_rules;i++)
	{
		add_rule_details_message(i, PUBLIC_CLASSIFIERSYSTEM.ruletable[i].parameters);
	}
        
    return 0;
}

/* \fn FinancialAgent_reset_public_classifiersystem()
 * \brief Reset of the public classifiersystem, resetting user counter, performance sum, and avg_performance. 
 *        This should be run before any rule_performance_messages are being read.
 */
int FinancialAgent_reset_public_classifiersystem()
{
	int i;
	
    //total number of rules:
    int nr_rules=PUBLIC_CLASSIFIERSYSTEM.nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<nr_rules; i++)
    {
        PUBLIC_CLASSIFIERSYSTEM.ruletable[i].counter=0;
        PUBLIC_CLASSIFIERSYSTEM.ruletable[i].performance=log(pow(10,-5));
        PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance=log(pow(10,-5));
        PUBLIC_CLASSIFIERSYSTEM.ruletable[i].selection_prob=pow(10,-5);
    }

    return 0;
} 

