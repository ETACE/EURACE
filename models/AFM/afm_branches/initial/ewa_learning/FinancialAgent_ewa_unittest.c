#include <CUnit/Basic.h>
#include "header.h"
#include "FinancialAgent_agent_header.h"
#include "mylibraryheader.h"

#define NR_PARAMS 10;

/************FinancialAgent: Financial Advisor Role ********************************/

/************ Unit tests ********************************/
void unittest_FinancialAgent_daily_reset_public_classifiersystem()
{
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
      PUBLIC_CLASSIFIERSYSTEM.nr_rules=1;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=100;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=10.0;
      PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=20.0;

      /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     FinancialAgent_daily_reset_public_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter, 0);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance, log(pow(10,-5)), 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_FinancialAgent_read_rule_performance_and_update_classifiersystem()
{
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

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
     //add_rule_performance_message(current_rule, rule_performance, 0.0, 0, 0, 0);
     add_rule_performance_message(0, 10.0, 0.0,0.0,0.0,0.0);
     add_rule_performance_message(0, 20.0, 0.0,0.0,0.0,0.0);
     add_rule_performance_message(1, 30.0, 0.0,0.0,0.0,0.0);
     add_rule_performance_message(1, 40.0, 0.0,0.0,0.0,0.0);
     
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
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_FinancialAgent_send_all_performances()
{
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

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
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_FinancialAgent_apply_GA() /*NOT IMPLEMENTED*/
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     //PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
     for (i=0;i<10;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[0].parameters[i]= 1.0 + i*1.0;
      }

     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;
     //PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[10]={11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0};
     for (i=0;i<10;i++)
      {
     	 PUBLIC_CLASSIFIERSYSTEM.ruletable[1].parameters[i]= 11.0 + i*1.0;
      }

     /***** Messages: pre-conditions **********************************/
     //add_<message_name>_message(<msg_var>, 0.0,0.0,0.0,0.0);

     /***** Function evaluation ***************************************/
     FinancialAgent_apply_GA();
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
    // START_<MSG_NAME>_MESSAGE_LOOP 
    //     CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
    //     CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
    // FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
     /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_FinancialAgent_send_rule_details()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

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
     	if (rule_details_messsage->rule_id == 0)
     	{
     		CU_ASSERT_DOUBLE_EQUAL(rule_details_messsage->parameters[0], 1.0, 1e-3);
     		CU_ASSERT_DOUBLE_EQUAL(rule_details_messsage->parameters[9], 10.0, 1e-3);     		
     	}
	  	if (rule_details_messsage->rule_id == 1)
	  	{
	  		CU_ASSERT_DOUBLE_EQUAL(rule_details_messsage->parameters[0], 11.0, 1e-3);
	  		CU_ASSERT_DOUBLE_EQUAL(rule_details_messsage->parameters[9], 20.0, 1e-3);     		
	  	}
     FINISH_RULE_DETAILS_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_FinancialAgent_reset_public_classifiersystem()
{
    /************* At start of unit test, add one agent **************/
     add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     PUBLIC_CLASSIFIERSYSTEM.nr_rules =1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter=0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance=0.0;
     PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     FinancialAgent_reset_public_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].counter, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].performance, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PUBLIC_CLASSIFIERSYSTEM.ruletable[0].avg_performance, log(pow(10,-5)), 1e-3);

    /***** Messages: post-conditions **********************************/

     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

