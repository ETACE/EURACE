/*********************************
 * FinancialAgent_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/
 
 
#include "header.h"
#include "math.h"
#include "FinancialAgent_agent_header.h"
#include "my_library_header.h"


/* DEP: FA agent reads the rule_performance_message */  
/* DEP: FA agent updates the rule_performance in its classifiersystem (for the selected_rule_number)*/
/* DEP: FA agent responds by sending the performance measures of all the rules*/
int FinancialAgent_read_rule_performance_message()
{
	  int current_rule;
	  double rule_performance;
	
	  rule_performance_message = get_first_rule_performance_message();
	  while(rule_performance_message)
	  {
	    current_rule = rule_performance_message->current_rule;
	    rule_performance = rule_performance_message->rule_performance;
	
	    /* Update rule performance: */
	    FinancialAgent_update_classifiersystem(current_rule, rule_performance);
	    rule_performance_message = get_next_rule_performance_message(rule_performance_message)
	  }

   return 0;
 }
 
 
int FinancialAgent_update_classifiersystem(int current_rule, double rule_performance)
{
  
  //Replace old performance adding new performance: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY? 
  CLASSIFIERSYSTEM->array[current_rule]->performance += rule_performance;
  
  //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
  CLASSIFIERSYSTEM->array[current_rule]->counter +=1;
  
  //Avgperformance update:
  CLASSIFIERSYSTEM->array[current_rule]->avgperformance = CLASSIFIERSYSTEM->array[current_rule]->avgperformance / CLASSIFIERSYSTEM->array[current_rule]->counter;
    
  return 0;
}

/* int FinancialAgent_send_all_performances_message()
 * Send dynamic array all_performances.
 */
int FinancialAgent_send_all_performances_message()
{
  	double[] all_performances;
 	 
 	//Get size of performance array:
	imax = CLASSIFIERSYSTEM->performance->size;

	//Assign values to dynamic array all_performances to equal the average performances
	for (i=0;i<imax;i++)
	{
		all_performances[i] = CLASSIFIERSYSTEM->array[i]->avgperformance;
	}
	
	//Send the message containing the dynamic array
	add_all_performances_message(all_performances, range, x, y, z);
     
  return 0;
}

int FinancialAgent_update_ruledetailsystem()
{
	//<!--Date-event triggered: every 100 days run the GA-->
	return 0;
}

//-Date-event triggered: every 100 days run the GA
int FinancialAgent_updateGA()
{
	return 0;
}
//FinancialAgent_send_ruledetailsystem_message()
//Function to send ruledetailsystem updates.
int FinancialAgent_send_ruledetailsystem_message()
{
	//Send a message containing the entire ruledetailsystem:
    //--> commenting the follwing line: another message sent out at the end of this fn
	//add_ruledetailsystem_message(RULEDETAILSYSTEM, range, x, y, z);

	//Alternative: we only need to send the double2D_array 
	//RULEDETAILSYSTEM->parameters
	double** parameters = RULEDETAILSYSTEM->parameters;
	add_ruledetailsystem_message(parameters, range, x, y, z);
		
    return 0;
}

int FinancialAgent_reset_public_classifiersystem()
{
	return 0;
}