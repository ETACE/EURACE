#include <CUnit/Basic.h>
#include "../header.h"
#include "../Household_agent_header.h"
#include "../mylibraryheader.h"
#include "../some_new_functions.h"

/************Household: EWA learning Role ********************************/

/************ Unit tests ********************************/
void unittest_Household_send_rule_performance()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =1;
     PRIVATE_CLASSIFIERSYSTEM.experience=0.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     
     /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     Household_send_rule_performance();
     
     /***** Variables: Memory post-conditions *************************/
   
    /***** Messages: post-conditions **********************************/
     //rule_performance = random_unif()*100;
     //add_rule_performance_message(PRIVATE_CLASSIFIERSYSTEM.current_rule, rule_performance, MSGDATA);

     START_RULE_PERFORMANCE_MESSAGE_LOOP
         CU_ASSERT_EQUAL(rule_performance_message->rule_id, 0);
     FINISH_RULE_PERFORMANCE_MESSAGE_LOOP

     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_read_all_performances()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =2;
     PRIVATE_CLASSIFIERSYSTEM.experience=0.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;

     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;
     
     /***** Messages: pre-conditions **********************************/
     //add_new_performances_message(rule_id, avg_performance, 1.0, 0.0, 0.0, 0.0);
     add_new_performances_message(0, 10.0, 1.0, 0.0, 0.0, 0.0);
     add_new_performances_message(1, 20.0, 1.0, 0.0, 0.0, 0.0);

     /***** Function evaluation ***************************************/
     Household_read_all_performances();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance, 10.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance, 20.0, 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest1_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =2;
     PRIVATE_CLASSIFIERSYSTEM.experience=1.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=4.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=20.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance=8.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction=10.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob=0.0;

     /***** Messages: pre-conditions **********************************/
     //add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     Household_select_rule();
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);
     
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.nr_rules, 2);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.experience, 2.0, 1e-3);
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.current_rule, 1);
     
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id, 1);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance, 4.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction, 2.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob, 0.0, 1e-3);

     
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id, 2);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance, 8.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction, 4.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob, 0.0, 1e-3);
 
     //CU_ASSERT_TRUE((PRIVATE_CLASSIFIERSYSTEM.current_rule==0 || PRIVATE_CLASSIFIERSYSTEM.current_rule==1));
     
     /***** Messages: post-conditions **********************************/

     /************* At end of unit test, free the agent **************/
     free_agent();
     /************* At end of unit tests, free all Messages **********/
     free_messages();
}


void unittest2_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=1.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =2;
     PRIVATE_CLASSIFIERSYSTEM.experience=1.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=4.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=20.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance=8.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction=10.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob=0.0;

     /***** Messages: pre-conditions **********************************/
     //add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     Household_select_rule();
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);
     
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.nr_rules, 2);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.experience, 2.0, 1e-3);
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.current_rule, 1);
     
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id, 1);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance, 4.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction, 12.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob, 0.0, 1e-3);

     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id, 2);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance, 8.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction, 9.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob, 0.0, 1e-3);
 
     CU_ASSERT_TRUE((PRIVATE_CLASSIFIERSYSTEM.current_rule==0 || PRIVATE_CLASSIFIERSYSTEM.current_rule==1));
     
    /***** Messages: post-conditions **********************************/

    /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_read_and_update_rule_details()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules=2;
     PRIVATE_CLASSIFIERSYSTEM.experience=0.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;
     for (i=0;i<10;i++)
     {
    	 PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[i]=0.0;
     }
     
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id=2;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob=0.0;
     for (i=0;i<10;i++)
     {
    	 PRIVATE_CLASSIFIERSYSTEM.ruletable[1].parameters[i]=0.0;
     }

     /***** Messages: pre-conditions **********************************/
     //add_rule_details_message(i, PRIVATE_CLASSIFIERSYSTEM.ruletable[i].parameters, 1.0, 0.0, 0.0, 0.0);
     double paramters_1[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
     double paramters_2[10]={11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0};
     add_rule_details_message(0, paramters_1, 1.0, 0.0, 0.0, 0.0);
     add_rule_details_message(1, paramters_2, 1.0, 0.0, 0.0, 0.0);
     
     /***** Function evaluation ***************************************/
     Household_read_and_update_rule_details();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[0], 1.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[9], 10.0, 1e-3);

     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].parameters[0], 11.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].parameters[9], 20.0, 1e-3);
     
    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//NOT IMPLEMENTED YET
void unittest_Household_apply_rule()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =1;
     PRIVATE_CLASSIFIERSYSTEM.experience=0.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;
     for (i=0;i<10;i++)
     {
    	 PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[i]=0.0;
     }

     /***** Messages: pre-conditions **********************************/
     //add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     Household_apply_rule();
     
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

void unittest_Household_reset_private_classifiersystem()
{
	
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =1;
     PRIVATE_CLASSIFIERSYSTEM.experience=0.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=1;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=10.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;
    
     /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     Household_reset_private_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id, 1);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob, pow(10,-5), 1e-3);

    /***** Messages: post-conditions **********************************/
 
    /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

