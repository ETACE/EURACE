/***************************************************************************************************
 * FinancialAgent_ewa_functions.c 
 * Functions for EWA learning module.
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *************************************************************************************************
 * History:
 * 22/05/08 Sander: Checked to conform to Xparser 0.15.7
 * 29/02/08 Sander: Converted code to use . instead of -> for structs.
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 * 15/07/08 Sander: Coded new function FinancialAgent_apply_GA_refactored() and auxiliary functions.
 ***************************************************************************************************/
#include "header.h"
#include "FinancialAgent_agent_header.h"
#include "FinancialAgent_aux_header.h"
#include "some_new_functions.h"

//#include "FinancialAgent_aux_functions.c"

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
int FinancialAgent_apply_GA_refactored()
{
	// Prototypes used:
	//N_pairs = GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id1, int * rule_id2);
	//void GA_reproduction(int id1, int id2, double * offspring_1, double * offspring_2);
	//void GA_mutation(int size, double * offspring_1, double * offspring_2);
	//void GA_election(int size, double * offspring_1, double * offspring_2);
	//void GA_reinsertion(int size, double * offspring_1, double * offspring_2, int id1, int id2);

	int j, N_pairs;
	double * offspring_1; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	double * offspring_2; //copy from PUBLIC_CLASSIFIERSYSTEM.ruletable[id2]
	int * parent_index_1; //contains random draws from interval [0, N_pairs], used for random matching
	int * parent_index_2; //contains random draws from interval [0, N_pairs], used for random matching
	int * rule_id_1;      //contains the rule_ids from PUBLIC_CLASSIFIERSYSTEM.ruletable[id1]
	int * rule_id_2;
	
	//uncomment this:
	N_pairs = GA_selection(parent_index_1, parent_index_2, rule_id_1, rule_id_2);
	for (j=0; j<N_pairs; j++)
	{    
		GA_reproduction(rule_id_1[j], rule_id_2[j], offspring_1, offspring_2);
		GA_mutation(NR_PARAMS, offspring_1, offspring_2);
		GA_election(NR_PARAMS, offspring_1, offspring_2);
		GA_reinsertion(NR_PARAMS, offspring_1, offspring_2, rule_id_1[j], rule_id_2[j]);
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


/* \fn FinancialAgent_apply_GA()
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
		
    /*********************** Start of Selection function **************************************/
	//void GA_selection()
	// 1. Selection/Reproduction
			
	// N_rep is some fixed percentage of the population size pop_size, and should be even.
	N_rep = (int) 2*floor((GA_PARAMETERS.reproduction_proportion * GA_PARAMETERS.pop_size)/2);

    //Computing fitness-based probabilities using multi-logit probabilities
	nr_rules = PUBLIC_CLASSIFIERSYSTEM.nr_rules;
	sum=0.0;
    for (j=0;j<nr_rules;j++)
    {
    	avg_performance  = PUBLIC_CLASSIFIERSYSTEM.ruletable[j].avg_performance;
        sum += exp(EWA_PARAMETERS.EWA_beta * avg_performance);
    }
    
    p = malloc(sizeof(double)*nr_rules);
    for (j=0;j<nr_rules;j++)
    {
    	avg_performance  = PUBLIC_CLASSIFIERSYSTEM.ruletable[j].avg_performance;
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
    //WARNING: draws contains indices (int), but draw_without_replacement() returns a double array.
    //Is this correctly type-cast inside the function draw_without_replacement() when it fills in draws?
     draws = malloc(sizeof(double)*N_rep);
     draw_without_replacement(nr_rules, cpdf, N_rep, draws);
	
	// Create N_pairs parent pairs by random matching (N_pairs = (int) 0.5*N_rep)
     N_pairs = (int) 0.5*N_rep;
     parent_index_1 = malloc(sizeof(int)*N_pairs);
     parent_index_2 = malloc(sizeof(int)*N_pairs);
     
    // Drawing is with replacement using uniform probabilities from the discrete interval: [0, N_pairs+1]
     //(both parents can be the same bitstring) 
     //We use (N_pairs+0.999) to allow the last string to be drawn (casting as int takes the floor of the double).
     //void draw_with_replacement(int size, double * vector, int nr_draws, double * draws)
     //draw_with_replacement(N_pairs, double * vector, N_pairs, parent_index_1)
     
     for (j=0; j<N_pairs; j++)
     {
    	 parent_index_1[j] = (int)((N_pairs+0.999)*random_unif());
    	 parent_index_2[j] = (int)((N_pairs+0.999)*random_unif());

    	 // Now we have selected the indices of N_pairs parent pairs that will undergo crossover and mutation.
         // To retrieve the 2 rule_ids associated to these two indices parent_index_1, parent_index_2
         // we need to get them from 'draws'.

    	 // Rule indices id1, id2 are stored in the vector 'draws':
    	 index=parent_index_1[j];
     	 id1=draws[index];
 	    	
     	 index=parent_index_2[j];
     	 id2=draws[index];
     }
	 //Now we have the correct 2 rule_ids that are randomly matched, and can be used in the following functions.     
     /*********************** End of Selection function **************************************/
     
     /*********************** Start of Reproduction function **************************************************/
 	 //void GA_reproduction(j): applies to each pair, nr_pair j=0,...,N_pairs
     //2. Genetic operators: cross-over
     for (j=0; j<N_pairs; j++)
     {			
		//make a copy of the parents
		offspring_1 = malloc(sizeof(double)*NR_PARAMS);
		offspring_2 = malloc(sizeof(double)*NR_PARAMS);
	
		for (k=0; k<NR_PARAMS; k++)
		{
			offspring_1[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id1].parameters[k];
			offspring_2[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id2].parameters[k];
		}
		
		//Cross-over the strings offspring_1 and offspring_2
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
	        //No cross-over occurs: 2 offspring remain identical copies of the parents
		}
     
		/*********************** End of Reproduction function **************************************************/
		
		/*********************** Start of Mutation function ****************************************************/
		//void GA_mutation(int size, double * offspring_1, double * offspring_2): applies to each pair, nr_pair j=0,...,N_pairs
		// 3. Mutation: each bit has a probability of mutating by a stepsize
	 	//For each of the strings offspring_1 and offspring_2 that have just undergone cross-over, now perform mutation
	
	    //void mutation(int size, double * offspring_1, double * offspring_2);
		mutation(NR_PARAMS, offspring_1, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);
		mutation(NR_PARAMS, offspring_2, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);
	
		/*********************** End of Mutation function ****************************************************/
		
	    /*********************** Start of Election function ****************************************************/		
		//void GA_election() : applies to each pair, nr_pair j=0,...,N_pairs
		// 4. Election: before 2 offsprings are added to the gene pool, they are tested against their parents.
		// Out ot the 4 candidates (2 parents, 2 offsprings) the best 4 are retained.
		if (GA_PARAMETERS.election)
		{
			//1. Make 2 local copies of the parents
			/*
			 parent_1 = malloc(sizeof(double)*NR_PARAMS);
			 parent_2 = malloc(sizeof(double)*NR_PARAMS);
	
			for (k=0; k<NR_PARAMS; k++)
			{
	 		    parent_1[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id1].parameters[k];
	 		    parent_2[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id2].parameters[k];
			}
			*/
			
			//2. Compare the 2 offspring to their 2 parents: test for higher fitness between 2 offspring and 2 parents
			// void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
			// election(NR_PARAMS, offspring_1, offspring_2, parent_1, parent_2);
			
			//3. Add 2 out of 4 best bitstrings to new generation
			
		}
	    /*********************** End of Election function ****************************************************/
		
	    /*********************** Start of Replacement function ****************************************************/
		//void GA_reinsertion() : applies to each pair
		//5. Finally, add the new strings to the population to replace the old ones
		//This means: copy the parameters into the classifier system
		for (k=0; k<NR_PARAMS; k++)
		{
			PUBLIC_CLASSIFIERSYSTEM.ruletable[id1].parameters[k] = offspring_1[k];
			PUBLIC_CLASSIFIERSYSTEM.ruletable[id2].parameters[k] = offspring_2[k];
		}
		/*********************** End of Replacement function ****************************************************/
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
    }

    return 0;
} 
