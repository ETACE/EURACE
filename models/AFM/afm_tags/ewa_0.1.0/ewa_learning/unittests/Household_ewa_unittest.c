 /*********************************
 * Household_ewa_unittest.c 
 * Unit tests for Household EWA learning module.
 **********************************
 * History:
 * 24/07/08 Sander: Checked that all malloc pointers are freed at the end of functions.
 * 15/07/08 Sander van der Hoog 
 *********************************/
#include <CUnit/Basic.h>
#include "../header.h"
#include "../some_new_functions.h"
#include "../Household_agent_header.h"

/************Household: EWA learning Role ********************************/

/************ Unit tests ********************************/

//Status: Not tested
void unittest_Household_send_rule_performance()
{
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

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
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not tested
void unittest_Household_read_all_performances()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

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
     //add_new_performances_message(rule_id, avg_performance);
     add_new_performances_message(0, 10.0);
     add_new_performances_message(1, 20.0);

     /***** Function evaluation ***************************************/
     Household_read_all_performances();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance, 10.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance, 20.0, 1e-3);

    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not tested
void unittest1_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
//     unittest_init_Household_agent();
//     
	unittest_init_Household_agent();

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=0.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =2;
     PRIVATE_CLASSIFIERSYSTEM.experience=1.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=-1;
     
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
 
     CU_ASSERT_TRUE((PRIVATE_CLASSIFIERSYSTEM.current_rule==1 || PRIVATE_CLASSIFIERSYSTEM.current_rule==2));
     
     /***** Messages: post-conditions **********************************/

     /************* At end of unit test, free the agent **************/
     //unittest_free_Household_agent();
     unittest_free_Household_agent();
     /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not tested
void unittest2_Household_select_rule()
{
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

     /***** Variables: Memory pre-conditions **************************/
     EWA_PARAMETERS.EWA_rho=1.0;
     EWA_PARAMETERS.EWA_phi=1.0;
     EWA_PARAMETERS.EWA_delta=1.0;
     EWA_PARAMETERS.EWA_beta=1.0;
     
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =2;
     PRIVATE_CLASSIFIERSYSTEM.experience=1.0;
     PRIVATE_CLASSIFIERSYSTEM.current_rule=-1;
     
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
 
     CU_ASSERT_TRUE((PRIVATE_CLASSIFIERSYSTEM.current_rule==1 || PRIVATE_CLASSIFIERSYSTEM.current_rule==2));
     
    /***** Messages: post-conditions **********************************/

    /************* At end of unit test, free the agent **************/
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not tested
void unittest_Household_read_and_update_rule_details()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

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
     //add_rule_details_message(i, PRIVATE_CLASSIFIERSYSTEM.ruletable[i].parameters);
     double parameters_1[10]={1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
     double parameters_2[10]={11.0,12.0,13.0,14.0,15.0,16.0,17.0,18.0,19.0,20.0};
     add_rule_details_message(0, parameters_1);
     add_rule_details_message(1, parameters_2);
     
     /***** Function evaluation ***************************************/
     Household_read_and_update_rule_details();
     
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[0], 1.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[0].parameters[9], 10.0, 1e-3);

     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].parameters[0], 11.0, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(PRIVATE_CLASSIFIERSYSTEM.ruletable[1].parameters[9], 20.0, 1e-3);
     
    /***** Messages: post-conditions **********************************/
 
     /************* At end of unit test, free the agent **************/
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//NOT IMPLEMENTED YET
//Status: Not tested
void unittest_Household_apply_rule()
{
	int i;
	
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

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
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}

//Status: Not tested
void unittest_Household_reset_private_classifiersystem()
{
	
    /************* At start of unit test, add one agent **************/
     unittest_init_Household_agent();
     

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
     unittest_free_Household_agent();
    /************* At end of unit tests, free all Messages **********/
     free_messages();
}


//Status: Tested OK
void unittest_Household_print_private_classifiersystem()
{
	char str[10];
	char * filename;
	FILE * file;

	int i, rule_id, counter;
	double performance, avg_performance, my_performance, attraction, choiceprob;
	double p0,p1,p2,p3;
	
	//Set the output file:
	i = sprintf(str, "%d", iteration_loop);
	printf("iteration_loop in sprintf is %s\n", str);
	printf("sprintf returns: %d\n\n", i);
	
	//Start an empty string for the filename
	filename = malloc(40*sizeof(char));
	filename[0]=0;
	
	//Concatenate
	strcpy(filename, "./log/CS_Household_");
	strcat(filename, str);
	strcat(filename, ".txt");
	printf("File to write data to: %s\n\n", filename);

	//Open a file pointer: FILE * file 
	printf("\n Appending data to file: %s. Starting to write...\n", filename);
	file = fopen(filename,"w");

    //************* At start of unit test, add one agent **************
     unittest_init_Household_agent();
     
    //***** Variables: Memory pre-conditions **************************
     PRIVATE_CLASSIFIERSYSTEM.nr_rules =4;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].id=0;
 	 PRIVATE_CLASSIFIERSYSTEM.ruletable[0].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[0].avg_performance=0.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[0].attraction=0.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[0].choiceprob=0.0;

     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].id=10;
 	 PRIVATE_CLASSIFIERSYSTEM.ruletable[1].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[1].avg_performance=1.0;
 	 PRIVATE_CLASSIFIERSYSTEM.ruletable[1].attraction=0.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[1].choiceprob=0.0;

     PRIVATE_CLASSIFIERSYSTEM.ruletable[2].id=20;
 	 PRIVATE_CLASSIFIERSYSTEM.ruletable[2].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[2].avg_performance=1.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[2].attraction=0.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[2].choiceprob=0.0;

     PRIVATE_CLASSIFIERSYSTEM.ruletable[3].id=30;
 	 PRIVATE_CLASSIFIERSYSTEM.ruletable[3].my_performance=0.0;
     PRIVATE_CLASSIFIERSYSTEM.ruletable[3].avg_performance=1000.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[3].attraction=0.0;
	 PRIVATE_CLASSIFIERSYSTEM.ruletable[3].choiceprob=0.0;


	//Print per household classifier system:
	 fprintf(file,"============================================================================================================\n");
	 fprintf(file,"Household: %d Current rule: %d\n", ID, PRIVATE_CLASSIFIERSYSTEM.current_rule);
	 fprintf(file,"rule\t my_performance\t avg_performance\t attraction\t choice prob\n");
	 fprintf(file,"============================================================================================================\n"); 
	
	for (i=0;i<PRIVATE_CLASSIFIERSYSTEM.nr_rules;i++)
	{
		rule_id 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].id;
		my_performance 	= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].my_performance;
		avg_performance	= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].avg_performance;
	    attraction 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].attraction;
	    choiceprob 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].choiceprob;
	    
	    fprintf(file,"%8d\t|\t %.4f\t|\t %.4f\t|\t %.4f\t|\t %.4f\n", rule_id, my_performance, avg_performance, attraction, choiceprob);
	}
	fprintf(file,"============================================================================================================\n");

	fprintf(file,"\n");
	fclose(file);
 	if(PRINT_DEBUG) printf("\n Finished writing and closed the file stream.\n");

 	free(filename);
 	if(PRINT_DEBUG) printf("\n Freed the filename pointer.\n");
}
