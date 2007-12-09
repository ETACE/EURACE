/*********************************
 * FinancialAgent_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "FinancialAgent_header.h"
#include "mylibraryheader.h"

//FinancialAgent_daily_reset_public_classifiersystem
//Daily reset of the public classifiersystem, resetting user counter, performance sum, and avgperformance.
//This should be run before any rule_performance_messages are being read.
int FinancialAgent_daily_reset_public_classifiersystem()
{
    //total number of rules:
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<NRRULES; i++)
    {
        CLASSIFIERSYSTEM->counter[i]=0;
        CLASSIFIERSYSTEM->performance[i]=log(pow(10,-5));
        CLASSIFIERSYSTEM->avgperformance[i]=log(pow(10,-5));
    }
    
  return 0;
}

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
  CLASSIFIERSYSTEM->performance[current_rule] += rule_performance;
  
  //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
  CLASSIFIERSYSTEM->counter[current_rule] +=1;
  
  //Avgperformance update:
  CLASSIFIERSYSTEM->avgperformance[current_rule] = CLASSIFIERSYSTEM->avgperformance[current_rule] / CLASSIFIERSYSTEM->counter[current_rule];
    
  return 0;
}

/* int FinancialAgent_send_all_performances_message()
 * Send dynamic array all_performances.
 */
int FinancialAgent_send_all_performances_message()
{
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    double[NRRULES] all_performances;
     
    //Get size of performance array:
    imax = CLASSIFIERSYSTEM->performance->size;

    //Assign values to dynamic array all_performances to equal the average performances
    for (i=0;i<imax;i++)
    {
        all_performances[i] = CLASSIFIERSYSTEM->avgperformance[i];
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
	
	int i,j,jmax;
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    int MAX_PARAMS
    
    
    //Send a message containing the entire ruledetailsystem:
    //--> commenting the follwing line: another message sent out at the end of this fn
    //add_ruledetailsystem_message(RULEDETAILSYSTEM, range, x, y, z);

    //Alternative: we only need to send the double2D_array 
    //RULEDETAILSYSTEM->parameters
    //uses: int_array nr_params[NRRULES]
    //for each rule, the nr_params is stored in nr_params[i]
    
    double parameters[NRRULES][MAX_PARAMS]; //intialize rows too max nr params (too large), or else do it with a pointer array

    for (i=0;i<NRRULES;i++)
    {
    	jmax=CLASSIFIERSYSTEM->nr_params[i];  //this sets the nr_params for this particuler rule i
        for (j=0;j<jmax;j++)
        {
            rule_id = i;
            param_id = j;
            parameters[rule_id][param_id] = RULEDETAILSYSTEM->parameters[rule_id][param_id];
            //Here: do we send a message per rule, or for all rules at one go?
            add_ruledetailsystem_message(rule_id, parameters[rule_id], range, x, y, z);
        }
    }
    //If all in one message:
    add_ruledetailsystem_message(parameters, range, x, y, z);
    
        
    return 0;
}

int FinancialAgent_reset_public_classifiersystem()
{
    //total number of rules:
    int NRRULES = CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<NRRULES; i++)
    {
        CLASSIFIERSYSTEM->counter[i]=0;
        CLASSIFIERSYSTEM->performance[i]=log(pow(10,-5));
        CLASSIFIERSYSTEM->avgperformance[i]=log(pow(10,-5));
    }

    return 0;
} 