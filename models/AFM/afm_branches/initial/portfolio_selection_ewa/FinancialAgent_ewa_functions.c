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
  PublicClassifierSystem * classifiersystem=get_central_classifiersystem();
  
  //Replace old performance adding new performance: 
  classifiersystem->array[nr_selected_rule]->performance += rule_performance;
  
  //Counter update: when do we reset the counter?   ******CHECK
  classifiersystem->array[nr_selected_rule]->counter +=1;
  
  //Avgperformance update:
  classifiersystem->array[nr_selected_rule]-> avgperformance = classifiersystem->array[nr_selected_rule]->avgperformance/classifiersystem->array[nr_selected_rule]->counter;

  //set_classifiersystem(classifiersystem); // setting value classifiersystem is an array need reference here
   /*classifiersystem[nr_selected_rule]->int_ruleperformance = 9;
    * if you're adding a rule into the structure:
    * add_classifiersystem_(classifersystem_dynamic_array, 0,2,25);
    */
    
  return 0;
}
