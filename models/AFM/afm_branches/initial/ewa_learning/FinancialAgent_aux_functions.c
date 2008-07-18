/*********************************
 * FinancialAgent_aux_functions.c 
 * GA auxiliary functions.
 * *********************************
 * History:
 * 16/07/08 Sander 
 *********************************/
#include "header.h"
#include "FinancialAgent_agent_header.h"
#include "FinancialAgent_aux_header.h"
#include "some_new_functions.h"


/* \fn void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
 * \brief Genetic operator: single_point_cross_over
 */
void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
{
	int k;
	double tmp;
	
	if (cross_point>size)
	{
		printf("Error in single_point_cross_over: cross_point > size of string");
		return;
	}

    //Crossover the bitstrings using single-point cross-over from the cross_point
    for (k=cross_point;k<size;k++)
    {
        tmp = string_a[k];
        string_a[k]= string_b[k];
        string_b[k]= tmp;
    }
}

/* \fn void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
 * \brief Genetic operator: two_point_cross_over
 */
void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
{
	int k, count;
	double tmp;
	
	if ((cross_point+cross_length)<size)
	{
	    // perform normal cross-over between parent pair
		for (k=cross_point; k<(cross_point+cross_length); k++)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;	
		}
	}
	else
	{
		//Case: cross-over crossed the bitstring boundary, so wrap-around is needed
	
	    //first, perform cross-over starting from the cross-point to end of string:
		count=0;
		for (k=cross_point; k<size; k++)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;
			count++;
		}
	    //second, perform cross-over from the beginning of string until the count reaches the cross_length
		k=0;
		while (count!=cross_length)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;
			count++;
		}
	}
}

/* \fn void two_point_cross_over_alt(int size, double * string_a, double * string_b, int cross_point, int cross_length)
 * \brief Genetic operator: two_point_cross_over. Alternative code for the 2-point crossover operation.
 */
void two_point_cross_over_alt(int size, double * string_a, double * string_b, int cross_point, int cross_length)
{
	int k, start, end;
	double tmp;
	
	//Set start and end bits
	if (cross_point+cross_length<=size)
	{
		start = cross_point;
		end   = cross_point+cross_length;
	}
	//Prevent overrun on right-hand side and cut to length
	/*
	if (cross_point+cross_length>size)
	{
	    start=cross_point;
	    end=size;            	
	}
	*/
	//Prevent overrun on right-hand side by making strings circular
	//Here we switch the start and end points: the substring that is crossed over is the negative of the actual substring
	//that should have been crossed over, but the result is the same. 
	if (cross_point+cross_length>size)
	{
		start=(cross_point+cross_length)%size;
		end=cross_point;
	}

	//Crossover the bitstrings
    for (k=start;k<end;k++)
    {
        tmp = string_a[k];
        string_a[k]=string_b[k];
        string_b[k]=tmp;
    }
    
}

/* \fn void mutation(int size, double * string, double * stepsize, double prob_mut)
 * 
 * \brief Genetic operator: Mutation of real-valued bitstrings.
 * The size of the mutation is delta*stepsize[k], where: 
 * delta: a random percentage between -10% and +10% (or: delta = {-10%, -5%, 0%, +5%, +10%} )
 * stepsize[k]: can be a parameter dependent gridsize
 */
void mutation(int size, double * string, double * stepsize, double prob_mut)
{
	int k;
	double delta;
	
	for (k=0; k<size; k++)
	{
		// apply mutation to the bit of string 1
		if (random_unif() < prob_mut)
		{	
			//Set units to mutate between -10% and +10%
			//delta = random_unif_interval(-10.0, 10.0);
			  delta= 10.0;
				  
			//mutate the value at position k by a random percentage between -10% and +10% of the previous value
			string[k] = string[k] + delta*stepsize[k]*string[k];
		}
	}    
}

/* \fn void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
 * \brief Genetic operator: Election of 2 out of 4 best bitstrings 
 */

void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
{

}



int GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id_1, int * rule_id_2)
{
	int j, index;
	int nr_rules, N_rep, N_pairs;
	double avg_performance, sum;
	
	double * p;
	double * cpdf;
	double * draws;
		
	// *********************** Start of Selection function **************************************
	// 1. Selection/Reproduction
			
	// N_rep is some fixed percentage of the population size pop_size, and should be even.
	N_rep = (int) 2*floor((GA_PARAMETERS.reproduction_proportion * GA_PARAMETERS.pop_size)/2);

	// N_pairs is the number of parent pairs that are produced by random matching from the N_rep draws
    N_pairs = (int) 0.5*N_rep;

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

    // Construct cumulative probability density function: cpdf
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
     // using the fitness-based probabilities ('draws' contains the indices of the selected rules)
     //WARNING: draws contains indices (int), but draw_without_replacement() returns a double array.
     //Is this correctly type-cast inside the function draw_without_replacement() when it fills in draws?
     draws = malloc(sizeof(int)*N_rep);
     draw_without_replacement(nr_rules, cpdf, N_rep, draws);
	
	 // Create N_pairs parent pairs by random matching from the N_rep draws (N_pairs = (int) 0.5*N_rep)
     parent_index_1 = malloc(sizeof(int)*N_pairs);
     parent_index_2 = malloc(sizeof(int)*N_pairs);
     
     // For the random matching, drawing is WITH replacement using uniform probabilities from the discrete interval: [0, N_pairs+1]
     // Drawing with replacement allows for both parents to be a copy of the same bitstring.
     // We use (N_pairs+0.999) below to allow also the last string to be drawn (casting as int takes the floor of the double).
     for (j=0; j<N_pairs; j++)
     {
    	 parent_index_1[j] = (int)((N_pairs+0.999)*random_unif());
    	 parent_index_2[j] = (int)((N_pairs+0.999)*random_unif());
     
    	 //equivalent code:
    	 // parent_index_1[j] = (int)(random_unif_interval(0.0, N_pairs+0.999));
    	 // parent_index_2[j] = (int)(random_unif_interval(0.0, N_pairs+0.999));

     // Now we have selected the indices of N_pairs parent pairs that will undergo crossover and mutation.
     // To retrieve the 2 rule_ids associated to these two indices parent_index_1, parent_index_2
     // we need to get them from 'draws'.

	 // Rule indices id1, id2 are stored in the vector 'draws':
		index=parent_index_1[j];
		rule_id_1[j]=draws[index];
		
		index=parent_index_2[j];
		rule_id_2[j]=draws[index];
     }

	 //Now we have 2 arrays of rule_ids that are randomly matched, and these can be used in the next functions.
     // *********************** End of Selection function **************************************

    free(p);
 	free(cpdf);
 	free(draws);
 	
 	return N_pairs;
}


void GA_reproduction(int id1, int id2, double * offspring_1, double * offspring_2)
{
	int k;
	int cross_point, cross_length;

    /*********************** Start of Reproduction function **************************************************/
	 //void GA_reproduction() : applies to each parent pair, nr_pair=0,...,N_pairs
     //2. Genetic operators: cross-over
		
		//make a copy of the parents
		offspring_1 = malloc(sizeof(double)*NR_PARAMS);
		offspring_2 = malloc(sizeof(double)*NR_PARAMS);
	
		for (k=0; k<NR_PARAMS; k++)
		{
			offspring_1[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id1].parameters[k];
			offspring_2[k]=PUBLIC_CLASSIFIERSYSTEM.ruletable[id2].parameters[k];
		}

		//now cross-over the strings
		if (random_unif() < GA_PARAMETERS.prob_cross)
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
}

void GA_mutation(int size, double * offspring_1, double * offspring_2)
{
	
	/*********************** Start of Mutation function ****************************************************/
	//void GA_mutation(int size, double * offspring_1, double * offspring_2): applies to each pair, nr_pair j=0,...,N_pairs
	// 3. Mutation: each bit has a probability of mutating by a stepsize
 	//For each of the strings offspring_1 and offspring_2 that have just undergone cross-over, now perform mutation

    //void mutation(int size, double * offspring_1, double * offspring_2);
	mutation(NR_PARAMS, offspring_1, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);
	mutation(NR_PARAMS, offspring_2, GA_PARAMETERS.stepsize, GA_PARAMETERS.prob_mut);

	/*********************** End of Mutation function ****************************************************/
}

void GA_election(int size, double * offspring_1, double * offspring_2)
{
	int k;
	double * parent_1;
	double * parent_2;

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
 	free(parent_1);
 	free(parent_2);
}

void GA_reinsertion(int size, double * offspring_1, double * offspring_2, int id1, int id2)
{
	int k;
	
    /*********************** Start of Reinsertion function ****************************************************/
	//void GA_reinsertion() : applies to each pair
	//5. Finally, add the new strings to the population to replace the old ones
	//This means: copy the parameters into the classifier system
	for (k=0; k<NR_PARAMS; k++)
	{
		PUBLIC_CLASSIFIERSYSTEM.ruletable[id1].parameters[k] = offspring_1[k];
		PUBLIC_CLASSIFIERSYSTEM.ruletable[id2].parameters[k] = offspring_2[k];
	}
	/*********************** End of Reinsertion function ****************************************************/
}
// *********** END GA AUXILIARY FUNCTIONS ****************************
