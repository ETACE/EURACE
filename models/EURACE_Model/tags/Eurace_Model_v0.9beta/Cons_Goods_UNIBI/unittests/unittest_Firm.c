#include <Basic.h>
//For trunk model
#include "../../header.h"
#include "../../Firm_agent_header.h"


/*
 * 1) initialize agent
 * 2) add memory pre-conditions
 * 3) initialise MBs
 * 4) add message pre-conditions
 * 5) create MB iterators
 * 6) evaluate function to be tested
 * 7) assertions on memory post-conditions
 * 8) assertions on message post-conditions
 * 9) free agent
 * 10) free MBs
 */

/*
 * \fn: void unittest_<Agentname>_function()
 * \brief: Unit test for: <Agentname>_function.
 * Status: NOT Tested
 */
void unittest_Firm_execute_production()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Firm_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	    
	        MEAN_SPECIFIC_SKILLS=1;
	        TECHNOLOGY = 1.5;
	        NO_EMPLOYEES=100;
	    
	        TOTAL_UNITS_CAPITAL_STOCK=100;
	      
	   
	    
	    	    
    /***** Function evaluation ***************************************/
	Firm_execute_production();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(PRODUCTION_QUANTITY,100, 1e-3);

    
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Firm_agent();
    /************* At end of unit tests, free all Messages **********/

}
