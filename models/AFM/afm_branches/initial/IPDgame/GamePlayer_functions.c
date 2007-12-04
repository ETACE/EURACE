/****************************************************************
 * GamePlayer_functions.c 
 * 29/11/07  Sander van der Hoog (svdhoog@gmail.com)
 ****************************************************************
 * History:
 * 29/11/07 Sander: Started implementation of IPD game 
 ****************************************************************/

#include "header.h"
#include "math.h"
#include "GamePlayer_agent_header.h"
//path to mylibraryheader.h:
#include "D:\Docs\EURACE\X-models\ModelFinancialMarket\SVNWorktree-xagents-Eclipse\Artificial_financial_market\IPDgame\mylibraryheader.h"

/* STEP 1. Send current rule.
 * GamePlayer_send_current_rule_message()
 * GamePlayer sends message to GameSolver agent with its current rule.
 */
int GamePlayer_send_current_rule_message()
{ 
    //Declare and assign local vars
    int current_rule = CLASSIFIERSYSTEM->current_rule;
    int id = get_id();
    
    add_current_rule_message(id, current_rule, range, x, y, z);

    return 0;
}


/* STEP 2. Obtain information.
 * GamePlayer_read_all_performances_message()
 * GamePlayer reads all_performances_message from GameSolver.
 * Updates classifiersystem.
 * Stores classifiersystem in memory.
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


/* STEP 3. Select a rule.
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

/* STEP 4. Change in RuleDetailSystem. 
 * GamePlayer_read_ruledetailsystem_message()
 * Function to check if there is a new rule_detail_system in the GameSolver agent.
 */
int GamePlayer_read_ruledetailsystem_message()
{
	
	//Reading the ruledetailsystem_message
	ruledetailsystem_message = get_first_ruledetailsystem_message();
	while(ruledetailsystem_message)
	{
		//If there are new rules, there is a ruledetailsystem_message in the MB,
		//then set new_rules to 1 in memory:
		set_new_rules(1);
				
		//Proceed to next message
		ruledetailsystem_message = get_next_ruledetailsystem_message(ruledetailsystem_message);
	}
	
    return 0;
}

/* GamePlayer_reset_private_classifiersystem()
 * Only reset the private_classifiersystem when there has been a update in the ruledetailsystem.
 */
int GamePlayer_reset_private_classifiersystem()
{
	int new_rules = get_new_rules();
	
	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->NRRULES;

	//Only reset if the memory variable NEWRDS==1
	if (new_rules)
	{
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
	}
	
	//Reset the memory variable to 0:
	set_new_rules(0);
	
    return 0;
}