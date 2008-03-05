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
//Daily reset of the public classifiersystem, resetting user counter, performance sum, and avg_performance.
//This should be run before any rule_performance_messages are being read.
int FinancialAgent_daily_reset_public_classifiersystem()
{
    //total number of rules:
    int nr_rules=CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<nr_rules; i++)
    {
        CLASSIFIERSYSTEM.ruletable.array[i].counter=0;
        CLASSIFIERSYSTEM.ruletable.array[i].performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable.array[i].avg_performance=log(pow(10,-5));
    }
    
  return 0;
}

/* DEP: FA agent reads the rule_performance_message */  
/* DEP: FA agent updates the rule_performance in its classifiersystem (for the selected_rule_number)*/
/* DEP: FA agent responds by sending the performance measures of all the rules*/
int FinancialAgent_read_rule_performance_and_update_classifiersystem()
{
      int current_rule;
      double rule_performance;
    

      START_RULE_PERFORMANCE_MESSAGE_LOOP

      	current_rule = rule_performance_message->current_rule;
        rule_performance = rule_performance_message->rule_performance;
    
        /* Update rule performance: */
        //Replace old performance adding new performance: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY? 
        CLASSIFIERSYSTEM.ruletable.array[current_rule].performance += rule_performance;
        
        //Counter update: ******CHECK WHEN RESET OCCURS: SHOULD BE DAILY?
        CLASSIFIERSYSTEM.ruletable.array[current_rule].counter +=1;
        
        //Avgperformance update:
        CLASSIFIERSYSTEM.ruletable.array[current_rule].avg_performance = CLASSIFIERSYSTEM.ruletable.array[current_rule].avg_performance / CLASSIFIERSYSTEM.ruletable.array[current_rule].counter;

      FINISH_RULE_PERFORMANCE_MESSAGE_LOOP

   return 0; }
}

/* int FinancialAgent_send_all_performances()
 * Send dynamic array with new_performance.
 */
int FinancialAgent_send_all_performances()
{
	int i;
	
    //Send the average performance of each rule
    for (i=0;i<CLASSIFIERSYSTEM.nr_rules;i++)
    {
        add_new_performances_message(i, CLASSIFIERSYSTEM.ruletable.array[i].avg_performance, range, x, y, z);
    }
    
  return 0;
}

int FinancialAgent_apply_GA()
{
    //<!--Date-event triggered: every 100 days run the GA-->
	if(DAY%MONTH == DAY_OF_MONTH_TO_ACT)
	{
		//GA CODE HERE

		
	}

    return 0;
}
//FinancialAgent_send_rule_details()
//Function to send rule_details updates.
int FinancialAgent_send_rule_details()
{
	int i;
	
	//Send new rule details in a rule_details_messsage
	//The message contains the static array parameters[10]
	for (i=0;i<CLASSIFIERSYSTEM.nr_rules;i++)
	{
		add_new_rule_details_messsage(i, CLASSIFIERSYSTEM.ruletable.array[i].parameters, MSGDATA);
	}
        
    return 0;
}

int FinancialAgent_reset_public_classifiersystem()
{
    //total number of rules:
    int nr_rules=CLASSIFIERSYSTEM->nr_rules;
    
    //Resetting and storing values to memory:
    for (i=0; i<nr_rules; i++)
    {
        CLASSIFIERSYSTEM.ruletable.array[i].counter=0;
        CLASSIFIERSYSTEM.ruletable.array[i].performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.ruletable.array[i].avg_performance=log(pow(10,-5));
    }

    return 0;
} 