/*********************************
 * Household_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 29/02/08 Sander: Converted code to use . instead of -> for structs.
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "Household_agent_header.h"
#include "mylibraryheader.h"
#include "some_new_functions.h"

#define NR_PARAMS 10

/************ Household : Asset market role ************/

/* STEP 1. Updating performance.*/
/* HERE: Household sends message to FA agent with the per-day performance of it's own current rule, */
/* including the total value invested in the asset portfolio (this is needed later on, when another household uses the rule). */
int Household_send_rule_performance()
{ 
    //Declare and assign local vars
    int current_rule = CLASSIFIERSYSTEM.current_rule;
    double rule_performance = 0.0;
    
    //Here we compute the rule performance: this function uses the performance_history
    //since performance is computed as THE time-average of capital gains obtained by the
    //current financial investment strategy. 
    
    //rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    
    //Random performance (uses the function random_unif())
    rule_performance = random_unif()*100;
    
    add_rule_performance_message(current_rule, rule_performance, MSGDATA);

    return 0;
}

/* STEP 2. Obtain information.*/
/* Household reads all_performances_message from FA
 * Updates the classifiersystem
 */
int Household_read_all_performances()
{
	int rule_index;
	
	//Read the messages: copies the elements one by one	
      START_NEW_PERFORMANCES_MESSAGE_LOOP
      	 rule_index = new_performances_message->rule_id;
         CLASSIFIERSYSTEM.ruletable[rule_index].avg_performance = new_performances_message->avg_performance;
      FINISH_NEW_PERFORMANCES_MESSAGE_LOOP
 
    return 0;
}


/* STEP 3. Select a rule.*/
/*
 *\fn: int Household_select_rule()
 *\brief: updates attractions
 * updates choice probabilities
 * selects a new rule
 * outputs the selected rule to memory
 * outputs the new classifier system to memory
 */
int Household_select_rule()
{
    int current_rule   = CLASSIFIERSYSTEM.current_rule;   
    int nr_rules 	   = CLASSIFIERSYSTEM.nr_rules;
    int experience     = CLASSIFIERSYSTEM.experience;
    int experience_old = 0.0;
    int i,j=0;
    int nr_selected_rule;
    double attraction, performance;
    
    //Rule selection
    double sum_attr;
    double * cpdf;
    double * p;
    
    //EWA learning parameters:
    double EWA_rho	=	EWA_PARAMETERS.EWA_rho;
    double EWA_phi	=	EWA_PARAMETERS.EWA_phi;
    double EWA_delta=	EWA_PARAMETERS.EWA_delta;
    double EWA_beta	=	EWA_PARAMETERS.EWA_beta;
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j<nr_rules;j++)
    {
    	//Set temporary vars:
    	attraction  = CLASSIFIERSYSTEM.ruletable[j].attraction;
    	performance = CLASSIFIERSYSTEM.ruletable[j].avg_performance;

        //If rule j is the currently used rule:
        if (j==current_rule)
        {
        	CLASSIFIERSYSTEM.ruletable[j].attraction = (EWA_phi*experience_old*attraction + performance)/experience;
        }
        else
        {
        	CLASSIFIERSYSTEM.ruletable[j].attraction = (EWA_phi*experience_old*attraction + EWA_delta*performance)/experience;
        }
    }
    
    //Computing the choice probabilities: multi-logit
    sum_attr=0.0;
    for (j=0;j<nr_rules;j++)
    {
    	attraction  = CLASSIFIERSYSTEM.ruletable[j].attraction;
        sum_attr += math.exp(EWA_beta * attraction);
    }
    
    p = malloc(sizeof((double)*nr_rules);
    for (j=0;j<nr_rules;j++)
    {
    	attraction  = CLASSIFIERSYSTEM.ruletable[j].attraction;
        p[j] = math.exp(EWA_beta * attraction)/sum_attr;
    }

    //Construct cumulative probability density function: cpdf
    cpdf = malloc(sizeof((double)*nr_rules);
    cumpdf(p, nr_rules, cpdf);
    draws = malloc(sizeof((double)*N);
    
    //Selecting a strategy according to the pdf:
     draw_with_replacement(nr_rules, cpdf, draws, 1);
     nr_selected_rule = draws[0];
     
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule in memory (0-indexed):
    CLASSIFIERSYSTEM.current_rule = nr_selected_rule - 1;

    //Free allocated memory
    free(p);
    free(cpdf);
    
    return 0;
}

 /* STEP 4. Apply the selected rule.
 * The household uses the details of the selected rule to compute its new asset allocation.
 * It assigns its asset_budget to firm stocks, firm bonds and government bonds, according to the rule's
 * prescribed asset portfolio. To determine the households target portfolio, we need to take the 
 * difference between the current_assetportfolio and prescribed_assetportfolio. This is done later. 
 * If the prescribed_portfolio is based on a prescribed_asset_value then  we have to multiply the units
 * in the prescribed_portfolio by: asset_budget/prescribed_asset_value.
 */

/* \fn: Household_apply_rule()
 * \brief: Apply a rule. To compute actual limit_orders we need to apply the rule to be able to obtain a prescribed_asset_portfolio.
 */
int Household_apply_rule()
{

    return 0;
}


/*
 * \fn: Household_read_and_update_rule_details()
 * \brief: Function to download new rule details. Used by agents to refresh their rule detail system.
 * We allow for changes in the rule parameters that occur due to crossover, mutation.
*/
int Household_read_and_update_rule_details()
{
    //Getting the size of the system:
    //int NR_TYPES=CLASSIFIERSYSTEM.nr_types;

    //Dynamic array with number of rules in each type (size of subpopulations)
    //int NRRULES_PER_TYPE[NR_TYPES];
	//NRRULES_PER_TYPE[i]=CLASSIFIERSYSTEM.ruletable[i].nr_rules_per_type;

    int i,rule_id=0;
   
    //Reading the rule_details_message
    START_RULE_DETAILS_MESSAGE
	    rule_id = new_rule_details_message->rule_id;
	    
    	//Filling the static array parameters[10] with parameter values
		for (i=0; i<NR_PARAMS; i++)
		{
			//Filling the fields of the rule with parameters[i]
			CLASSIFIERSYSTEM.ruletable[rule_id].parameters[i] = new_rule_details_message->parameters[i];
		}
    FINISH_RULE_DETAILS_MESSAGE
    
    return 0;
}

/* \fn: Household_reset_private_classifiersystem()
 * \brief:
 */
int Household_reset_private_classifiersystem()
{
    //Getting the size of the system:
    //int NR_TYPES=CLASSIFIERSYSTEM.NR_TYPES;

    //dynamic array with number of rules in each type (size of subpopulations)
    //int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM.NRRULES_PER_TYPE;

    //Total number of rules:
    int nr_rules=CLASSIFIERSYSTEM.nr_rules;

    //Resetting and storing values to memory:
    CLASSIFIERSYSTEM.experience=0.0;
    CLASSIFIERSYSTEM.current_rule=0;

    for (i=0; i<nr_rules; i++)
    {
    	CLASSIFIERSYSTEM.ruletable[i].my_performance=0.0;
    	CLASSIFIERSYSTEM.ruletable[i].avg_performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable[i].attraction=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable[i].choiceprob=pow(10,-5);
        for (j=0; j<NR_PARAMS; j++)
        {        
        	CLASSIFIERSYSTEM.ruletable[i].parameters[j]=0.0;
        }
    }

    return 0;
} 


//HERE: function to initialize the rule_detail_system.
//Contains arrays for:
//NR_TYPES: number of different types of rules (typically NR_TYPES=3)
//NRRULES_PER_TYPE[NR_TYPES]: number of rules per type (typically the same, equal to 10)
//NRRULES_PER_TYPE=[10,10,10];
//rule_type: type identifier for each rule
//nr_params_per_type: number of parameters for each rule type
//nr_params: no. of parameters for each rule
//parameters: parameter setting for each rule 
//rule_execution:  function name to execute the rule
//my_function_names: the names of the functions to call to execute a rule
//my_function_name[1]='Markowitz';
//my_function_name[2]='ProspectTheory';
//my_function_name[3]='RandomRule';
/*
int initialize_ruledetailsystem()
{
	int i;
	
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->nr_types;

	//dynamic array with number of rules in each type (size of subpopulations)
	int * NRRULES_PER_TYPE=CLASSIFIERSYSTEM->nr_rules_per_type;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->nr_rules;
	
	//dynamic array with number of parameters in each type
	int nr_params_per_type[NR_TYPES];
	for (i=0; i<NRRULES; i++)
	{	
		nr_params_per_type[i]=CLASSIFIERSYSTEM->array[i]->nr_params_per_type;
	}
	
	//Local vars:
	int 		ids[NRRULES];
	
	//Here: nr_params is the number of parameters for a rule of certain type
	//For each type we should have a prototype and then fill in the dynamic array
	int			rule_type[NRRULES];
	int			nr_params[NRRULES];
	double**	parameters;			//parameter[NRRULES][MAX_PARAMS];
	
	double 		p0[NRRULES];
	double 		dp[NRRULES];
	double 		p1[NRRULES];
	
	char**		rule_execution;	    //rule_execution[NRRULES]
	
	word_array * my_function_names = get_my_function_names(); //list of function names
	
	double		param_value;
	int			j,jmax,k,m, count, par_resolution;

	//Getting parameter settings
	for (i=0; i<NRRULES; i++)
	{
		p0[i] = CLASSIFIERSYSTEM->array[i]->param_start_values;
		dp[i] = CLASSIFIERSYSTEM->array[i]->param_increment_values;
		p1[i] = CLASSIFIERSYSTEM->array[i]->param_end_values;
	}
	
	//First we set the field 'rule_type':
	count = 0;
	for (i=0;i<NR_TYPES;i++)
	{
		//Set nr_rules in the current type
		jmax = CLASSIFIERSYSTEM->array[i]->nr_rules_per_type;
		
		//For type i, traverse the rule ids from 0+count to jmax+count
		//such that we go through all rules of type i
		for (j=count;j<count+jmax;j++)
		{
			//We are now in rule id j
			CLASSIFIERSYSTEM->array[j]->rule_type = i;
			CLASSIFIERSYSTEM->array[j]->nr_params = CLASSIFIERSYSTEM->array[i]->nr_params_per_type;
			
		}
		//Set counter to current rule id
		count=count+jmax;
	}
	
	//Filling in random parameter settings
	for (i=0; i<NRRULES; i++)
	{
		//I want to add an empty double_array to the double2D_array parameter
		add_double_array(double2D_parameter_dynamic_array->array[i], {});
		
		//Filling the just added double_array parameter[i] with the parameter values of rule i
		for (j=0; j<nr_params[i]; j++)
		{
			//Filling the parameters[i][j]
			//A random value is chosen from the parameter resolution given by:
			//[p0:dp:p1] where dp is the step size.
				
			par_resolution = (p1[i]-p0[i])/dp[i]; //total possibilities
			k=rand_unif();
			m=(int)(k*par_resolution); //random uniform in [0,par_res]: selecting a random param. setting
	
			//Can we add a double directly inside the function add_double?
			add_double(parameters[i][j], p0[i] + m*dp[i]);		

			//param_value = p0[i] + m*dp[i];
			//add_double(parameters[i][j], param_value);
		}		

		//We set the field 'rule_execution':
		//First possibility: we test which function name the rule has
		j=CLASSIFIERSYSTEM->array[i]->rule_type;
		CLASSIFIERSYSTEM->array[i]->rule_execution[i]=sprintf('my_function_names[%d]',j);
	}

	//ALTERNATIVE CODE for rule_execution
	//we loop over the different rule types
	//this avoids the rule_type[i]	
	count = 0;
	for (i=0;i<NR_TYPES;i++)
	{
		//Set nr_rules in the current type
		jmax = CLASSIFIERSYSTEM->array[i]->nr_rules_per_type;
		
		//For type i, traverse the rule ids from 0+count to jmax+count
		for (j=count;j<count+jmax;j++)
		{
			//We are now in rule id j
			//Set the function call for rule j, which is just my_function_names[i]
			CLASSIFIERSYSTEM->array[j]->rule_execution=sprintf('my_function_names[%d]', i);
		}
		//Set counter to current rule id
		count=count+jmax;
	}
	
    return 0;
}
*/
