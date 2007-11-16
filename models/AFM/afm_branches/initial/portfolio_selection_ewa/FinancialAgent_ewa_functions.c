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
	
	    //After all updates have been read and processed: send the result
	    //This message can be read by ALL household agents
	    add_all_performances_message(performances, range, x, y, z);

   return 0;
 }
 
 
int FinancialAgent_update_classifiersystem(int current_rule, double rule_performance)
{
  PublicClassifierSystem * classifiersystem;
  
  //Replace old performance adding new performance: 
  classifiersystem->array[current_rule]->performance += rule_performance;
  
  //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
  classifiersystem->array[current_rule]->counter +=1;
  
  //Avgperformance update:
  classifiersystem->array[current_rule]->avgperformance = classifiersystem->array[current_rule]->avgperformance / classifiersystem->array[current_rule]->counter;

  //set_classifiersystem(classifiersystem); // setting value classifiersystem is an array need reference here
   /*classifiersystem[current_rule]->int_ruleperformance = 9;
    * if you're adding a rule into the structure:
    * add_classifiersystem_(classifersystem_dynamic_array, 0,2,25);
    */
    
  return 0;
}

/* int FinancialAgent_send_all_performances_message()
 * Send dynamic array all_performances.
 */
int FinancialAgent_send_all_performances_message()
{
    PublicClassifierSystem * classifiersystem;
 	double[] all_performances;
 	 
 	//Get size of performance array:
	imax = CLASSIFIERSYSTEM->performance->size;

	//Assign values to dynamic array all_rule_performances
	for (i=0;i<imax;i++)
	{
		all_performances[i] = CLASSIFIERSYSTEM->array[i]->performance;
	}
	
	//Send the message containing the dynamic array
	add_all_performances_message(all_performances, range, x, y, z);
     
  return 0;
}
  