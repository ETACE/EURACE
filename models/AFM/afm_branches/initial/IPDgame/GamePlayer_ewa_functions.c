/*********************************
 * GamePlayer_ewa_functions.c 
 * *********************************
 * History:
 * 29/11/07 Sander: Started implementation of IPD game 
 *********************************/


#include "header.h"
#include "math.h"
#include "GamePlayer_agent_header.h"
#include "my_library_header.h"

/* STEP 1. Updating performance.*/
/* HERE: GamePlayer sends message to GameSolver agent with the per-day performance of it's own current rule, */
int GamePlayer_send_rule_performance_message()
{ 
    //Declare and assign local vars
    int current_rule = CLASSIFIERSYSTEM->current_rule;
    
    //Here we compute the rule performance: this function uses the performance_history
    //since performance is computed as a time-average of capital gains obtained by the
    //current financial investment strategy. 
    
    //rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    
    //Random performance (uses the function random_unif())
    rule_performance = random_unif()*100;
    
    add_rule_performance_message(current_rule, rule_performance, range, x, y, z);

    return 0;
}


/* STEP 2. Obtain information.
 * GamePlayer reads all_performances_message from GameSolver
 * Updates classifiersystem
 * Stores classifiersystem in memory
 */
int GamePlayer_read_all_performances_message()
{
 	  double * all_performances;
	  
	  all_performances_message = get_first_all_performances_message();
	  while(all_performances_message)
	  {
	    //Read the message
	    //code for dynamic arrays, copies the elements one by one
	    for (i=0; i<NRRULES; i++)
	  	{
		 // Store in memory:		 	  
	 	 CLASSIFIERSYSTEM->array[i]->performance = all_performances[i];
		}
		
	    //Proceed to next message
	     all_performances_message = get_next_all_performances_message(all_performances_message);
	  }
 
    return 0;
}


/* STEP 3. Select a rule.*/
/*
 * int GamePlayer_select_rule()
 * updates attractions
 * updates choice probabilities
 * selects a new rule
 * outputs the selected rule to memory
 * outputs the new classifier system to memory
 */
int GamePlayer_select_rule()
{
    int current_rule = CLASSIFIERSYSTEM->current_rule;   
	int NRRULES = CLASSIFIERSYSTEM->nr_rules;
	
    double[] performance;
    double[] attraction;

    int experience		= CLASSIFIERSYSTEM->experience;
    int experience_old = 0;
    int i,j=0;

	//Rule selection
	double sum_attr = 0;
	double[NRRULES] cpdf;
	
    
	//Assign values to local dynamic arrays
	for (i=0;i<NRRULES;i++)
	{
		performance[i] = CLASSIFIERSYSTEM->array[i]->performance;
		attraction[i]  = CLASSIFIERSYSTEM->array[i]->attraction;
	}
    
    //EWA learning parameters:
    double EWA_rho=CLASSIFIERSYSTEM->EWA_rho;
    double EWA_phi=CLASSIFIERSYSTEM->EWA_phi;
    double EWA_delta=CLASSIFIERSYSTEM->EWA_delta;
    double EWA_beta=CLASSIFIERSYSTEM->EWA_beta;
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j++;j<NRRULES)
    {
        //If rule j is the currently used rule:
        if (j==current_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + performance[j])/experience;
        }

        //If rule j is not currently used:
        if (j~=current_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + EWA_delta*performance[j])/experience;
        }
        //Set the attractions in the classifiersystem:
        CLASSIFIERSYSTEM->array[j]->attraction = attraction[j];
    }
    
	//Computing the choice probabilities: multi-logit
    sum_attr=0;
    for (j=0;j++;j<NRRULES)
    {
        sum_attr += math.exp(EWA_beta * attractions[j]);
	}
    
    for (j=0;j++;j<NRRULES)
    {
        p[j] = math.exp(EWA_beta * attractions[j])/sum_attr;
	}

    //Construct cumm. prob. dens. function
	cpdf = cumpdf(p);
    
    //Selecting a strategy according to the pdf:
	nr_selected_rule = draw_with_replacement(1, cpdf, NRRULES);
    
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule in memory (0-indexed):
    CLASSIFIERSYSTEM->current_rule = nr_selected_rule - 1;

    return 0;
}

/* GamePlayer_retrieve_rule_details()
 * Retrieve rule details
 * Copying the selected rule details to the appropriate memory variables of the household. 
 */
int GamePlayer_retrieve_rule_details()
{
	//#include <string.h>
	//To use: 	char *strcat( char *str1, const char *str2 );
	//			char *strcpy( char *to, const char *from );

	double* param_vector;
	char*	functioncall; 
	int	imax;
	char* str, new_str, param_vector_as_string;
	
	//Rule details:
	//The name of the rule
	functioncall = RULEDETAILSYSTEM->array[i]->rule_execution;

	//Parameters: retrieve the list of parameter values for the current rule
	param_vector = RULEDETAILSYSTEM->array[i]->parameters;

	//Convert param_vector to string
	imax = param_vector->size;
	str="\0"; 			//empty, null-terminated string
	for (i=0;i<imax;i++)
	{
		new_str = sprintf('%s,%f',str,param_vector->array[i]);
		strcpy(str, new_str);	
	}
	strcpy(param_vector_as_string,new_str);
	
//**********WARNING: SERIOUSLY BAD CODING BELOW******************
	//Execute the rule's functioncall, with the appropriate parameter setting
	sprintf('%s(%s)',functioncall, param_vector_as_string);

    return 0;
}


 /* STEP 4. Apply the selected rule.
 */

/* GamePlayer_apply_rule()
 * Apply a rule.
 */
int GamePlayer_apply_rule()
{

    return 0;
}


//GamePlayer_read_ruledetailsystem_message()
//Function to download a new rule_detail_system.
//Used by agents to refresh their rule detail system
//We allow for changes in:
//parameters: changes occur due to crossover, mutation
int GamePlayer_read_ruledetailsystem_message()
{
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->nr_types;

	//dynamic array with number of rules in each type (size of subpopulations)
	int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM->nr_rules_per_type;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->nr_rules;
	
	//Local vars:
	int[NRRULES] 		ids;
	int[NRRULES]		nr_params;
	double**			parameters;			//parameter[NRRULES][MAX_PARAMS];
	
	char**				rule_execution;	    //rule_execution[NRRULES]
	int[NRRULES]		rule_type;			//rule_type[NRRULES]
	
	word_array * 		my_function_names = get_my_function_names(); //list of function names
	
	double				param_value;
	int					i,j,k,m,jmax=0;

	//HERE: As an exception, we need a local copy of ruledetailsystem
	//because we need to copy it from the message.
	//And then we need to copy the values using a for loop.
	//So we need to temporarily store the contents of the message.
	//Do we need to free memory space afterward if we make a local copy of the struct?
	
	RuleDetailSystem *	ruledetailsystem;
	
	//Reading the ruledetailsystem_message
	ruledetailsystem_message = get_first_ruledetailsystem_message();
	while(ruledetailsystem_message)
	{
		ruledetailsystem = ruledetailsystem_message->parameters;
				
		//Proceed to next message
		ruledetailsystem_message = get_next_ruledetailsystem_message(ruledetailsystem_message);
	}
	
	for (i=0; i<NRRULES; i++)
	{
		//Filling the double_array parameter[i] with the parameter values of rule i
		jmax=CLASSIFIERSYSTEM->array[i]->nr_params;
		for (j=0; j<jmax; j++)
		{
			//Filling the field parameters[i][j]
			//Problem: in xml we cannot add a name for the array[j]->(double param_value);
			//parameters[i] is a double_array, so to access its elements we need:
			  parameters[i][j] = ruledetailsystem->array[i]->parameters->array[j]->(double param_value);
		}
	}
	
    return 0;
}

int GamePlayer_update_ruledetailsystem()
{
	return 0;
}

int GamePlayer_reset_private_classifiersystem()
{
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->NR_TYPES;

	//dynamic array with number of rules in each type (size of subpopulations)
	int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM->NRRULES_PER_TYPE;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->NRRULES;

	//Resetting and storing values to memory:
	CLASSIFIERSYSTEM->experience=0;
	CLASSIFIERSYSTEM->current_rule=0;
	CLASSIFIERSYSTEM->my_performance=0;

	for (i=0; i<NRRULES; i++)
	{
		CLASSIFIERSYSTEM->array[i]->avgperformance=log(pow(10,-5));
		CLASSIFIERSYSTEM->array[i]->attraction=log(pow(10,-5));
		CLASSIFIERSYSTEM->array[i]->choiceprob=pow(10,-5);
	}

    return 0;
}