 /*********************************
 * FinancialAgent_ewa_unittest.c 
 * Unit tests for EWA learning module.
 **********************************
 * History:
 * 24/07/08 Sander: Checked that all malloc pointers are freed at the end of functions.
 * 15/07/08 Sander van der Hoog 
 *********************************/
#include <CUnit/Basic.h>
#include "../header.h"
#include "../some_new_functions.h"
#include "../FinancialAgent_agent_header.h"
#include "../FinancialAgent_aux_header.h"

/************FinancialAgent: Financial Advisor Role ********************************/

/************ Unit tests ********************************/
//Status: Tested OK
void unittest_FinancialAgent_reset_public_classifiersystem()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_FinancialAgent_agent();

     /***** Variables: Memory pre-conditions **************************/
      PUBLIC_CLASSIFIERSYSTEM.nr_rules=1;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=100;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=10.0;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=20.0;

      /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     FinancialAgent_reset_public_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter, 0);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance, log(pow(10,-5)), 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     unittest_free_FinancialAgent_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Tested OK
void unittest_FinancialAgent_read_rule_performance_and_update_classifiersystem()
{
    /************* At start of unit test, add one agent **************/
     unittest_init_FinancialAgent_agent();
     

     /***** Variables: Memory pre-conditions **************************/
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     /***** Messages: pre-conditions **********************************/
     //add_rule_performance_message(current_rule, rule_performance);
     add_rule_performance_message(0, 10.0);
     add_rule_performance_message(0, 20.0);
     add_rule_performance_message(1, 30.0);
     add_rule_performance_message(1, 40.0);
     
     /***** Function evaluation ***************************************/
     FinancialAgent_read_rule_performance_and_update_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter, 2);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance, 30.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance, 15.0, 1e-3);

     CU_ASSERT_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter, 2);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance, 70.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance, 35.0, 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     unittest_free_FinancialAgent_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Tested OK
void unittest_FinancialAgent_send_all_performances()
{
    /************* At start of unit test, add one agent **************/
     unittest_init_FinancialAgent_agent();
     

     /***** Variables: Memory pre-conditions **************************/
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =2;
     
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=10.0;
     
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=20.0;

     /***** Messages: pre-conditions **********************************/
     //add_new_performances_message(0, PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance, 1.0, 0.0, 0.0, 0.0);
     //add_new_performances_message(1, PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance, 1.0, 0.0, 0.0, 0.0);

     /***** Function evaluation ***************************************/
     FinancialAgent_send_all_performances();
     
     /***** Variables: Memory post-conditions *************************/

     /***** Messages: post-conditions **********************************/
     START_NEW_PERFORMANCES_MESSAGE_LOOP
     	if (new_performances_message->rule_id == 0)
     	{
     		CU_ASSERT_DOUBLE_EQUAL(new_performances_message->avg_performance, 10.0, 1e-3);
     	}
	  	if (new_performances_message->rule_id == 1)
	  	{
	  		CU_ASSERT_DOUBLE_EQUAL(new_performances_message->avg_performance, 20.0, 1e-3);
	  	}
     FINISH_NEW_PERFORMANCES_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     unittest_free_FinancialAgent_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not Tested
void unittest_FinancialAgent_apply_GA()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     unittest_init_FinancialAgent_agent();
     

     /***** Variables: Memory pre-conditions **************************/
  	//Initializations:
  	//EWA_PARAMETERS.EWA_beta: used for the determination of fitness-proportional selection probabilities, exp(beta*performance)
  	//GA_PARAMETERS.prob_cross: cross-over probability
  	//GA_PARAMETERS.prob_mut: mutation  probability
  	//GA_PARAMETERS.string_size: length of strings
  	//GA_PARAMETERS.single_point_crossover: dummy for single_point_crossover (if 1: use single point cross-over, 0: use two point cross-over) 
  	//GA_PARAMETERS.pop_size: population size
  	//GA_PARAMETERS.reproduction_proportion: percentage of population
  	//GA_PARAMETERS.election: dummy for election operator
  	//GA_PARAMETERS.stepsize: vector of stepsizes for mutation of real-valued parameters
   	//GA_PARAMETERS.delta_min: Mutation lower range, delta_min*stepsize[i] 
   	//GA_PARAMETERS.delta_max: Mutation upper range, delta_max*stepsize[i]

      //mutation = value + delta*stepsize[k] with delta = random_unif_interval(delta_min, delta_max);
      //for unittesting:
      //prob_mut = 1.0, value = 0.0, stepsize = 0.01, delta_min = -10.0, delta_max = +10.0
      //0.0 -> 0.10
      //prob_mut = 1.0, value = 0.0, stepsize = 0.05, delta_min = -10.0, delta_max = +10.0
      //0.0 -> 0.50

  	EWA_PARAMETERS.EWA_beta = 1.0;
  	GA_PARAMETERS.prob_cross=1.00;	//always
  	GA_PARAMETERS.prob_mut = 0.00;	//no mutation

  	GA_PARAMETERS.string_size=10;
  	GA_PARAMETERS.single_point_cross_over=1;	//use single-point cross-over
  	GA_PARAMETERS.pop_size=2;
  	GA_PARAMETERS.reproduction_proportion=1.00;	//use whole population
  	GA_PARAMETERS.election=0;

  	GA_PARAMETERS.stepsize[0]=0.01;
  	GA_PARAMETERS.stepsize[1]=0.05;
  	GA_PARAMETERS.delta_min=-10.0;
  	GA_PARAMETERS.delta_max=10.0;

  	 PUBLIC_CLASSIFIERSYSTEM.nr_rules =2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     //PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
     for (i=0;i<GA_PARAMETERS.string_size;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[i]= 1.0 + i*1.0;
      }

     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;
     //PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[10]={11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0};
     for (i=0;i<GA_PARAMETERS.string_size;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[i]= 11.0 + i*1.0;
      }

     printf("\n In FinancialAgent_apply_GA, before:\n rule[0]_parameters=[ ");
     for (i=0;i<GA_PARAMETERS.string_size;i++){printf("%1.1f ", PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[i]);}
     printf("]\n"); 

     printf("\n In FinancialAgent_apply_GA, before:\n rule[1]_parameters=[ ");
     for (i=0;i<GA_PARAMETERS.string_size;i++){printf("%1.1f ", PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[i]);}
     printf("]\n"); 

     /***** Messages: pre-conditions **********************************/
     //add_<message_name>_message(<msg_var>);

     /***** Function evaluation ***************************************/
     FinancialAgent_apply_GA();
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);
     
     printf("\n In FinancialAgent_apply_GA, after:\n rule[0]_parameters=[ ");
     for (i=0;i<GA_PARAMETERS.string_size;i++){printf("%1.1f ", PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[i]);}
     printf("]\n"); 

     printf("\n In FinancialAgent_apply_GA, after:\n rule[1]_parameters=[ ");
     for (i=0;i<GA_PARAMETERS.string_size;i++){printf("%1.1f ", PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[i]);}
     printf("]\n"); 

    /***** Messages: post-conditions **********************************/
    // START_<MSG_NAME>_MESSAGE_LOOP 
    //     CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
    //     CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
    // FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     unittest_free_FinancialAgent_agent();
     /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Tested OK
void unittest_FinancialAgent_send_rule_details()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     unittest_init_FinancialAgent_agent();
     

     /***** Variables: Memory pre-conditions **************************/
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =1;
     
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     for (i=0;i<10;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[i]= 1.0 + i*1.0;
      }

     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;
     for (i=0;i<10;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[i]= 11.0 + i*1.0;
      }

     /***** Messages: pre-conditions **********************************/
     //add_rule_details_messsage(i, parameters, 1.0, 0.0, 0.0, 0.0);
     //add_rule_details_messsage(0, {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0}, 1.0, 0.0, 0.0, 0.0);
     //add_rule_details_messsage(1, {11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0}, 1.0, 0.0, 0.0, 0.0);

     /***** Function evaluation ***************************************/
     FinancialAgent_send_rule_details();
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);
     
    /***** Messages: post-conditions **********************************/

     START_RULE_DETAILS_MESSAGE_LOOP
     	if (rule_details_message->rule_id == 0)
     	{
     		CU_ASSERT_DOUBLE_EQUAL(rule_details_message->parameters[0], 1.0, 1e-3);
     		CU_ASSERT_DOUBLE_EQUAL(rule_details_message->parameters[9], 10.0, 1e-3);     		
     	}
	  	if (rule_details_message->rule_id == 1)
	  	{
	  		CU_ASSERT_DOUBLE_EQUAL(rule_details_message->parameters[0], 11.0, 1e-3);
	  		CU_ASSERT_DOUBLE_EQUAL(rule_details_message->parameters[9], 20.0, 1e-3);     		
	  	}
     FINISH_RULE_DETAILS_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     unittest_free_FinancialAgent_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}
