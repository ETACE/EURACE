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
