#include <CUnit/Basic.h>
#include "header.h"
#include "Household_agent_header.h"
#include "my_library_header.h"

/************Household: EWA learning Role ********************************/

/************ Unit tests ********************************/
void unittest_Household_send_rule_performance()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_read_all_performances()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/
     EWA_parameters.EWA_rho=1.0;
     EWA_parameters.EWA_phi=0.0;
     EWA_parameters.EWA_delta=1.0;
     EWA_parameters.EWA_beta=1.0;
     
     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_retrieve_rule_details()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_apply_rule()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_read_transaction()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

void unittest_Household_read_and_update_ruledetailsystem()
{
    /************* At start of unit test, add one agent **************/
     add_Household_agent_internal(init_Household_agent());
     current_xmachine = *p_xmachine;

     /***** Variables: Memory pre-conditions **************************/

     /***** Messages: pre-conditions **********************************/
     add_<message_name>_message(<msg_var>, MSGDATA);

     /***** Function evaluation ***************************************/
     <functionname>();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(<var_name2>, <value>);
     

    /***** Messages: post-conditions **********************************/
     START_<MSG_NAME>_MESSAGE_LOOP 
         CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
         CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
     FINISH_<MSG_NAME>_MESSAGE_LOOP
 
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
     CLASSIFIERSYSTEM.nr_rules =1;
     CLASSIFIERSYSTEM.experience=0.0;
     CLASSIFIERSYSTEM.current_rule=1;
     CLASSIFIERSYSTEM.ruletable.array[0].id=1;
     CLASSIFIERSYSTEM.ruletable.array[0].my_performance=0.0;
     CLASSIFIERSYSTEM.ruletable.array[0].avg_performance=0.0;
     CLASSIFIERSYSTEM.ruletable.array[0].attraction=0.0;
     CLASSIFIERSYSTEM.ruletable.array[0].choiceprob=0.0;

     /***** Messages: pre-conditions **********************************/

     /***** Function evaluation ***************************************/
     Household_reset_private_classifiersystem();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].id, 1);
     CU_ASSERT_DOUBLE_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].my_performance, 0.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].avg_performance, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].attraction, log(pow(10,-5)), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].choiceprob, pow(10,-5), 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(CLASSIFIERSYSTEM.ruletable.array[0].parameters[0], 0.0, 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     free_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

