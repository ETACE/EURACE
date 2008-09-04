#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Eurostat_agent_header.h"
#include "../../my_library_header.h"

/************Eurostat Role: Statistical Office ********************************/

/************ Unit tests ********************************/
/*
 * \fn: void unittest_Eurostat_store_history_monthly()
 * \brief: Unit test for: Eurostat_store_history_monthly.
 * Status: Not tested
 */
void unittest_Eurostat_store_history_monthly()
{
	int k;
	double var, result;
	//PRINT_LOG =0;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	for (k=1;k<=13;k++)
	{
		HISTORY_MONTHLY[k].cpi = (double) k;
		//printf("\n HISTORY_MONTHLY[%d].cpi=%f\n", k, HISTORY_MONTHLY[k].cpi);
	}
	CPI=0.0;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_store_history_monthly();
    
    /***** Variables: Memory post-conditions *****/
    //CU_ASSERT_DOUBLE_EQUAL(, 0.0, 1e-3);
    //CU_ASSERT_EQUAL();
	for (k=1;k<13;k++)
	{
		var = HISTORY_MONTHLY[k].cpi;
		result = (double) (k-1);

		//printf("\n HISTORY_MONTHLY[%d].cpi=%f\n", k, HISTORY_MONTHLY[k].cpi);
		//printf("\n k=%d, var=%f, result=%f\n", k, var, result);		
		
		CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	}
//	CU_ASSERT_DOUBLE_EQUAL(HISTORY_MONTHLY[1].cpi, 0.0, 1e-3);
	//CU_ASSERT_DOUBLE_EQUAL(HISTORY_MONTHLY[2].cpi, 1.0, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_store_history_quarterly()
 * \brief: Unit test for: Eurostat_store_history_quarterly.
 * Status: Not tested
 */
void unittest_Eurostat_store_history_quarterly()
{
	int k;
	double var, result;
	//PRINT_LOG =0;

    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	for (k=1;k<=5;k++)
	{
		HISTORY_QUARTERLY[k].cpi = (double) k;
	}
	CPI=0.0;

    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_store_history_quarterly();
    
    /***** Variables: Memory post-conditions *****/
	for (k=1;k<5;k++)
	{
		var = HISTORY_QUARTERLY[k].cpi;
		result = (double) (k-1);
	
		CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	}
    		
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_compute_growth_rates_monthly()
 * \brief: Unit test for: Eurostat_compute_growth_rates_monthly.
 * Status: Not tested
 */
void unittest_Eurostat_compute_growth_rates_monthly()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	HISTORY_MONTHLY[0].cpi = 2.0;
	HISTORY_MONTHLY[1].cpi = 1.0;
	HISTORY_MONTHLY[12].cpi = 0.20;
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_compute_growth_rates_monthly();
    
    /***** Variables: Memory post-conditions *****/
    CU_ASSERT_DOUBLE_EQUAL(MONTHLY_GROWTH_RATES.cpi, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(ANNUAL_GROWTH_RATES_MONTHLY.cpi, 900.0, 1e-3);
    
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_compute_growth_rates_quarterly()
 * \brief: Unit test for: Eurostat_compute_growth_rates_quarterly.
 * Status: Not tested
 */
void unittest_Eurostat_compute_growth_rates_quarterly()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	HISTORY_QUARTERLY[0].cpi = 2.0;
	HISTORY_QUARTERLY[1].cpi = 1.0;
	HISTORY_QUARTERLY[4].cpi = 0.20;
    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_compute_growth_rates_quarterly();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(QUARTERLY_GROWTH_RATES.cpi, 100.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(ANNUAL_GROWTH_RATES_QUARTERLY.cpi, 900.0, 1e-3);
    
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_firm_creation()
 * \brief: Unit test for: Eurostat_firm_creation.
 * Status: Not tested
 */
void unittest_Eurostat_firm_creation()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_firm_creation();
    
    /***** Variables: Memory post-conditions *****/
	//CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[0][0], 100.0, 1e-3);
    
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}


/*
 * \fn: void unittest_Eurostat_firm_creation()
 * \brief: Unit test for: Eurostat_measure_recession.
 * Status: Not tested
 */
void unittest_Eurostat_measure_recession()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
    
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_measure_recession();
    
    /***** Variables: Memory post-conditions *****/
	//CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[0][0], 100.0, 1e-3);
    
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_measure_export()
 * \brief: Unit test for: Eurostat_measure_export.
 * Status: Tested OK
 */
void unittest_Eurostat_measure_export()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	NO_REGIONS=2;
    
	/***** Messages: pre-conditions **********************************/
    rc = MB_Create(&b_mall_data, sizeof(m_mall_data));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'mall_data' board\n");
    	       switch(rc) {
    	           case MB_ERR_INVALID:
    	               fprintf(stderr, "\t reason: Invalid message size\n");
    	               break;
    	           case MB_ERR_MEMALLOC:
    	               fprintf(stderr, "\t reason: out of memory\n");
    	               break;
    	           case MB_ERR_INTERNAL:
    	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
    	               break;
    	       }
    	    }
    	    #endif

    //Adding mall 1 elements
	add_mall_data_message(1, 1, 1, 1.0);
    add_mall_data_message(1, 1, 2, 100.0);
    add_mall_data_message(1, 2, 1, 100.0);
    add_mall_data_message(1, 2, 2, 1.0);

    //Adding mall 2 elements
    add_mall_data_message(2, 1, 1, 1.0);
    add_mall_data_message(2, 1, 2, 100.0);
    add_mall_data_message(2, 2, 1, 100.0);
    add_mall_data_message(2, 2, 2, 1.0);

	rc = MB_Iterator_Create(b_mall_data, &i_mall_data);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for 'mall_data'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'mall_data' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'mall_data' board is locked\n");
		               break;
		           case MB_ERR_MEMALLOC:
		               fprintf(stderr, "\t reason: out of memory\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
			   }
			}
	
    /***** Function evaluation ***************************************/
	Eurostat_measure_export();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[0], 2.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[1], 200.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[2], 200.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(EXPORT_MATRIX[3], 2.0, 1e-3);
    
    CU_ASSERT_DOUBLE_EQUAL(EXPORTS[0], 200.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(EXPORTS[1], 200.0, 1e-3);
    
    CU_ASSERT_DOUBLE_EQUAL(IMPORTS[0], 200.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(IMPORTS[1], 200.0, 1e-3);

    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}


