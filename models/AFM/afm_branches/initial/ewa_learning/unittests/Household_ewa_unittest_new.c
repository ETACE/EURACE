 /*********************************
 * Household_ewa_unittest.c 
 * Unit tests for Household EWA learning module.
 **********************************
 * History:
 * 15/07/08 Sander van der Hoog 
 *********************************/
#include <CUnit/Basic.h>
#include "../header.h"
#include "../some_new_functions.h"
#include "../Household_agent_header.h"
//#include "../mylibraryheader.h"

/************Household: EWA learning Role ********************************/


void unittest1_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Household_agent();

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
     //free_agent();
     unittest_free_Household_agent();
     /************* At end of unit tests, free all Messages **********/
     free_messages();
}

