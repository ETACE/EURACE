/*********************************
 * FinancialAgent_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/
#include "header.h"
#include "FinancialAgent_agent_header.h"
#include "mylibraryheader.h"
#include "some_new_functions.h"

#define NR_PARAMS 10

/* \fn int FinancialAgent_daily_reset_public_classifiersystem()
 * \brief Daily reset of the public classifiersystem, resetting user counter, performance sum, and avg_performance. 
 *        This should be run before any rule_performance_messages are being read.
 */
int FinancialAgent_daily_reset_public_classifiersystem()
{
	int i;
	
    //Resetting and storing values to memory:
    for (i=0; i<CLASSIFIERSYSTEM.nr_rules; i++)
    {
        CLASSIFIERSYSTEM.ruletable[i].counter=0;
        CLASSIFIERSYSTEM.ruletable[i].performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable[i].avg_performance=log(pow(10,-5));
    }
    
  return 0;
}

/* \fn int FinancialAgent_read_rule_performance_and_update_classifiersystem()
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
        CLASSIFIERSYSTEM.ruletable[rule_id].performance += rule_performance;
        
        //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
        CLASSIFIERSYSTEM.ruletable[rule_id].counter +=1;
        
        //Average performance update:
        CLASSIFIERSYSTEM.ruletable[rule_id].avg_performance = CLASSIFIERSYSTEM.ruletable[rule_id].performance / CLASSIFIERSYSTEM.ruletable[rule_id].counter;
      FINISH_RULE_PERFORMANCE_MESSAGE_LOOP

   return 0;}

/* \fn int FinancialAgent_send_all_performances()
 * \brief FinancialAgent sends for each rule the avg_performance in a separate message.
 */
int FinancialAgent_send_all_performances()
{
	int i;
	
    //Send the average performance of each rule
    for (i=0;i<CLASSIFIERSYSTEM.nr_rules;i++)
    {
        add_new_performances_message(i, CLASSIFIERSYSTEM.ruletable[i].avg_performance, 1.0, 0.0, 0.0, 0.0);
    }
    
  return 0;
}

/* \fn int FinancialAgent_apply_GA()
 * \brief FinancialAgent applies the GA to the rule details parameters.
 */
int FinancialAgent_apply_GA()
{
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
	
	int index, j, k;
	int nr_rules, N_rep, N_pairs;
	double avg_performance, sum;
	
	double * p;
	double * cpdf;
	double * draws;
	
	int * parent_index_1;
	int * parent_index_2; 
	int id1,id2;
	double * offspring_1;
	double * offspring_2;

	//If election is used, uncomment the next 2 lines
	//double * parent_1;
	//double * parent_2;
	
	int cross_point, cross_length;
		
	//<!--Date-event triggered: every 100 days run the GA-->
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT)
	{
		//GA CODE HERE

		// read current generation of bitstrings from LCS
		// read current fitness of bitstrings from LCS

		// 1. Selection/Reproduction
				
		// N_rep is some fixed percentage of the population size pop_size, and should be even.
		N_rep = (int) 2*floor((GA_PARAMETERS.reproduction_proportion * GA_PARAMETERS.pop_size)/2);

	    //Computing fitness-based probabilities using multi-logit probabilities
		nr_rules = CLASSIFIERSYSTEM.nr_rules;
		sum=0.0;
	    for (j=0;j<nr_rules;j++)
	    {
	    	avg_performance  = CLASSIFIERSYSTEM.ruletable[j].avg_performance;
	        sum += exp(EWA_PARAMETERS.EWA_beta * avg_performance);
	    }
	    
	    p = malloc(sizeof(double)*nr_rules);
	    for (j=0;j<nr_rules;j++)
	    {
	    	avg_performance  = CLASSIFIERSYSTEM.ruletable[j].avg_performance;
	        p[j] = exp(EWA_PARAMETERS.EWA_beta * avg_performance)/sum;
	    }

	    //Construct cumulative probability density function: cpdf
	     cpdf = malloc(sizeof(double)*nr_rules);
	     cumpdf(p, nr_rules, cpdf);
	     
	    //print prob. vector:
	     printf("\n prob: [");
	     for (j=0;j<nr_rules;j++){printf("%2.2f ", p[j]);}
	     printf("]\n");
	          
	    //print cpdf:
	     printf("\n cpdf: [");
	     for (j=0;j<nr_rules;j++){printf("%2.2f ", cpdf[j]);}
	     printf("]\n");
	     
	    // Drawing N_rep random copies (without replacement) from the entire population
	    // using the fitness-based probabilities ('draws' contains indices of drawn rules)
	     draws = malloc(sizeof(double)*N_rep);
	     draw_without_replacement(nr_rules, cpdf, N_rep, draws);
		
		// Create N_pairs parent pairs by random matching (N_pairs = (int) 0.5*N_rep)
	     N_pairs = (int) 0.5*N_rep;
	     parent_index_1 = malloc(sizeof(int)*N_pairs);
	     parent_index_2 = malloc(sizeof(int)*N_pairs);
	     
	    // Drawing is with replacement (so same string can be both parents) using uniform probabilities:
	     for (j=0; j<N_pairs; j++)
	     {
	    	 parent_index_1[j] = (int)((N_pairs+0.999)*random_unif());
	    	 parent_index_2[j] = (int)((N_pairs+0.999)*random_unif());
	     }
		
		//2. Genetic operators
	     for (j=0; j<N_pairs; j++)
	     {
	    	//rule indices id1, id2 are in the vector 'draws':
    		index=parent_index_1[j];
	    	id1=draws[index];
	    	
	    	index=parent_index_2[j];
    		id2=draws[index];
    		
    		//make a copy of the parents
    		offspring_1 = malloc(sizeof(double)*NR_PARAMS);
    		offspring_2 = malloc(sizeof(double)*NR_PARAMS);

    		for (k=0; k<NR_PARAMS; k++)
    		{
    			offspring_1[k]=CLASSIFIERSYSTEM.ruletable[id1].parameters[k];
    			offspring_2[k]=CLASSIFIERSYSTEM.ruletable[id2].parameters[k];
    		}
    		
    		//now cross-over the strings
    		if (random_unif() > GA_PARAMETERS.prob_cross)
    		{
    			// 2a. Cross-over: 1-point cross-over
    			if (GA_PARAMETERS.single_point_cross_over)
    			{
	    			// draw random cross-over point between $[1,L-1]$
	    			cross_point = (int)random_unif_interval(1, NR_PARAMS-1);	
	    			single_point_cross_over(NR_PARAMS, offspring_1, offspring_2, cross_point);
    			}
    			else
    			{
    			    // 2b. Cross-over: 2-point cross-over
    				// draw random cross-over point between $[1,L-1]$
	    			cross_point = (int)random_unif_interval(1, NR_PARAMS-1);
    				
    				// draw random cross-over length between $[1,L-1]$
	    			cross_length = (int)random_unif_interval(1, NR_PARAMS-1);
    				
	    			two_point_cross_over(NR_PARAMS, offspring_1, offspring_2, cross_point, cross_length);
	    		}
    		}
    		else
    		{
		        //No cross-over: 2 offspring bitstrings are identical copies of parents
    		}
	        // add 2 offspings to potential new generation (this step is only needed if election operator is on)  
    		// else: add offspring directly, replacing the original strings

    		// 3. Mutation: each bit has a probability of mutating
			//void mutation(int size, double * offspring_1, double * offspring_2);
			mutation(NR_PARAMS, offspring_1, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);
			mutation(NR_PARAMS, offspring_2, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);
    		
    		// 4. Election
    		if (GA_PARAMETERS.election)
    		{
    		    // test for higher fitness between 2 offspring and 2 parents
    			// add 2 out of 4 best bitstrings to new generation
    			
    			//Make extra copies of the parents
	    		/*
	    		 parent_1 = malloc(sizeof(double)*NR_PARAMS);
    			 parent_2 = malloc(sizeof(double)*NR_PARAMS);

    			for (k=0; k<NR_PARAMS; k++)
	    		{
	     		    parent_1[k]=CLASSIFIERSYSTEM.ruletable[id1].parameters[k];
	     		    parent_2[k]=CLASSIFIERSYSTEM.ruletable[id2].parameters[k];
	    		}
	    		*/
    			// void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
    			// election(NR_PARAMS, offspring_1, offspring_2, parent_1, parent_2);
    		}

    		//5. Finally, add the new strings to the population to replace the old ones
    		//This means: copy the parameters into the classifier system
    		for (k=0; k<NR_PARAMS; k++)
    		{
    			CLASSIFIERSYSTEM.ruletable[id1].parameters[k] = offspring_1[k];
	    		CLASSIFIERSYSTEM.ruletable[id2].parameters[k] = offspring_2[k];
    		}
	     }		
	}

	free(p);
	free(cpdf);
	free(draws);
	free(parent_index_1);
	free(parent_index_2);
	free(offspring_1);
	free(offspring_2);
	
	//If election is used, uncomment the next 2 lines
	//free(parent_1);
	//free(parent_2);
	
    return 0;
}

/* \fn int FinancialAgent_send_rule_details()
 * \brief FinancialAgent sends new rule details. For each rule, a separate message is sent containing the static array parameters[10].
 */
int FinancialAgent_send_rule_details()
{
	int i;
	
	//Send new rule details in a rule_details_messsage
	//The message contains the static array parameters[10]
	for (i=0;i<CLASSIFIERSYSTEM.nr_rules;i++)
	{
		add_rule_details_messsage(i, CLASSIFIERSYSTEM.ruletable[i].parameters, 1.0, 0.0, 0.0, 0.0);
	}
        
    return 0;
}

/* \fn int FinancialAgent_reset_public_classifiersystem()
 * \brief FinancialAgent resets the public classifiersystem.
 */
int FinancialAgent_reset_public_classifiersystem()
{
	int i;
	
    //total number of rules:
    int nr_rules=CLASSIFIERSYSTEM.nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<nr_rules; i++)
    {
        CLASSIFIERSYSTEM.ruletable[i].counter=0;
        CLASSIFIERSYSTEM.ruletable[i].performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable[i].avg_performance=log(pow(10,-5));
    }

    return 0;
} 
