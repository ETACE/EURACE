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
	int nr_selected_rule;
	double rule_performance;
  rule_performance_message = get_first_rule_performance_message();
  while(rule_performance_message)
  {
   
    nr_selected_rule = rule_performance_message->nr_selected_rule;
    rule_performance = rule_performance_message->rule_performance;
   

    /* Update rule performance: */
    FinancialAgent_update_classifiersystem(nr_selected_rule, rule_performance);
    rule_performance_message = get_next_rule_performance_message(rule_performance_message)
  }

    //After all updates have been read and processed: send the result
    //This message can be read by ALL household agents
    add_all_performances_message(performances, range, x, y, z);

   return 0;
 }
 
 
int FinancialAgent_update_classifiersystem(int nr_selected_rule, double rule_performance)
{
  PublicClassifierSystem classifiersystem=get_classifiersystem();
  
  //Replace old performance adding new performance: 
  classifiersystem->performance[nr_selected_rule] += rule_performance;
  
  //Counter update: when do we reset the counter?   ******CHECK
  classifiersystem->counter[nr_selected_rule] +=1;
  
  //Avgperformance update:
  classifiersystem->avgperformance[nr_selected_rule] = classifiersystem->avgperformance[nr_selected_rule]/classifiersystem->counter[nr_selected_rule];

  //set_classifiersystem(classifiersystem); // setting value classifiersystem is an array need reference here
   /*classifiersystem[nr_selected_rule]->int_ruleperformance = 9;
    * if you're adding a rule into the structure:
    * add_classifiersystem_(classifersystem_dynamic_array, 0,2,25);
    */

  
  //********************* REDUNDANT CODE********************
  //Idea here was to have a history of performance for each rule
  //This is a bit exotic for classifier systems, so better to discard this.
  //
  //classifiersystem->performance_history[nr_selected_rule]
  //actually would need a dynamic array with 2 indices:
  //double_array[NrTotalRules][HISTLENGTH] performance_history
  
  double[HISTLENGTH] tmparray;
  /* Update the performance history of the rule: */
  //Shift history:
  for (i=1; i<HISTLENGTH; i++)
  {  
  //This is incorrect code:
      tmparray = classifiersystem[nr_selected_rule]->performance_history;
      classifiersystem[nr_selected_rule]->performance_history[i] = tmparray[i-1];
  }
  //This is incorrect code:
  classifiersystem[nr_selected_rule]->performance_history[0] = rule_performance;
  //********************* END REDUNDANT CODE********************
     
  return 0;
}

//********************* REDUNDANT CODE********************
/* DEP: The FA reads the rule_details_request_message. This is a private message. */
/* DEP: The FA sends a message with the exact details of the selected rule.*/
 int FinancialAgent_read_rule_details_request_message()
 {
   rule_details_request_message = get_first_rule_details_request_message();
   while(rule_details_request_message)
   {
     /*Read the message: */
      selected_rule_number = rule_details_request_message->selected_rule_number;
      household_id = rule_details_request_message->household_id;
  
     /* FA agent sends back a message with the requested details: */ 
      add_rule_details_message(household_id, classifiersystem[selected_rule_number].prescribed_assetportfolio, classifiersystem[selected_rule_number].prescribed_asset_value, range, x, y, z);
  
     /* Move on to process the next rule_details_request_message: */
      rule_details_request_message = get_next_rule_details_request_message(rule_details_request_message);
   }

  return 0;
}
//********************* END REDUNDANT CODE********************

 