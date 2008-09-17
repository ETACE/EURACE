#include <CUnit/Basic.h>

#include "../../header.h"
#include "../../Eurostat_agent_header.h"
#include "../../my_library_header.h"

/************Eurostat Role: Statistical Office ********************************/

/************ Unit tests ********************************/
/*
 * \fn: void unittest_Eurostat_calc_macro_data()
 * \brief: Unit test for: Eurostat_calc_macro_data.
 * Status: NOT Tested
 */
void unittest_Eurostat_calc_macro_data()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	MONTHLY_SOLD_QUANTITY=0.0;
	MONTHLY_REVENUE=0.0;
	LABOUR_SHARE_RATIO=0.0;
	
	//Allocate memory
/*	firm_data(REGION_ID, FIRMS, VACANCIES, NO_EMPLOYEES,
	NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4,	NO_EMPLOYEES_SKILL_5, 
	AVERAGE_WAGE, AVERAGE_WAGE_SKILL_1, AVERAGE_WAGE_SKILL_2, AVERAGE_WAGE_SKILL_3, AVERAGE_WAGE_SKILL_4, AVERAGE_WAGE_SKILL_5, 
	AVERAGE_S_SKILLS, AVERAGE_S_SKILL_1, AVERAGE_S_SKILL_2, AVERAGE_S_SKILL_3, AVERAGE_S_SKILL_4, AVERAGE_S_SKILL_5,
	GDP, TOTAL_EARNINGS, TOTAL_DEBT, TOTAL_ASSETS, TOTAL_EQUITY,
	AVERAGE_DEBT_EARNINGS_RATIO, AVERAGE_DEBT_EQUITY_RATIO, LABOR_SHARE_RATIO,
	MONTHLY_SOLD_QUANTITY, MONTHLY_OUTPUT, MONTHLY_REVENUE, MONTHLY_PLANNED_OUTPUT,
	CPI, CPI_LAST_MONTH	);
*/	
	add_firm_data(&REGION_FIRM_DATA,
	1, 0, 0, 0,		
	0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,
	0,0,0,0,
	0,0	);

	add_firm_data(&REGION_FIRM_DATA,
	2, 0, 0, 0,		
	0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,
	0,0,0,0,
	0,0	);

	/***** Messages: initialize message boards **********************************/
    rc = MB_Create(&b_firm_send_data, sizeof(m_firm_send_data));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'firm_send_data' board\n");
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

	/***** Messages: pre-conditions **********************************/
	//Set 4 firms in 2 regions, using these vars:
  	//	firm_send_data_message->region_id;
   	//	firm_send_data_message->cum_revenue;
   	//	firm_send_data_message->capital_costs;
   	//	firm_send_data_message->cum_total_sold_quantity;

/*	add_firm_send_data_message(ID, REGION_ID, VACANCIES, NO_EMPLOYEES,
	NO_EMPLOYEES_SKILL_1, NO_EMPLOYEES_SKILL_2, NO_EMPLOYEES_SKILL_3, NO_EMPLOYEES_SKILL_4,	NO_EMPLOYEES_SKILL_5, 
	MEAN_WAGE, MEAN_SPECIFIC_SKILLS,
	AVERAGE_S_SKILL_OF_1, AVERAGE_S_SKILL_OF_2, AVERAGE_S_SKILL_OF_3, AVERAGE_S_SKILL_OF_4, AVERAGE_S_SKILL_OF_5,
	CUM_REVENUE, CAPITAL_COSTS,	NET_EARNINGS, TOTAL_DEBT, TOTAL_ASSETS, EQUITY,
	PRICE, PRICE_LAST_MONTH, TOTAL_SUPPLY, CUM_TOTAL_SOLD_QUANTITY, OUTPUT, PLANNED_OUTPUT, AGE);
*/	
	//Fixture:
	//NO_EMPLOYEES=10
	//MEAN_WAGE=1
	//NET_EARNINGS=100
	//labour_share=1*10/100 = 0.10

	add_firm_send_data_message(1,1,0,10, 0,0,0,0,0, 0,0, 1,0,0,0,0, 100,100,100,0,0,0, 0,0,0,1000,0,0,0);
	add_firm_send_data_message(2,1,0,10, 0,0,0,0,0, 0,0, 1,0,0,0,0, 100,100,100,0,0,0, 0,0,0,1000,0,0,0);
	add_firm_send_data_message(3,2,0,10, 0,0,0,0,0, 0,0, 1,0,0,0,0, 10,10,100,0,0,0,   0,0,0,100, 0,0,0);
	add_firm_send_data_message(4,2,0,10, 0,0,0,0,0, 0,0, 1,0,0,0,0, 10,10,100,0,0,0,   0,0,0,100, 0,0,0);

    /***** Adding message iterators ***************************************/
	rc = MB_Iterator_Create(b_firm_send_data, &i_firm_send_data);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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
	Eurostat_calc_macro_data();
    
    /***** Variables: Memory post-conditions *****/
	//CU_ASSERT_DOUBLE_EQUAL(, result, 1e-3);
	
	//After the message loop, check the aggregate in both regions
	//GDP=cum_revenue+capital_costs
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[0].gdp, 400.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[0].monthly_sold_quantity, 2000.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[0].monthly_revenue, 200.0, 1e-3);
	
	//GDP=cum_revenue+capital_costs
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[1].gdp, 40.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[1].monthly_sold_quantity, 200.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(REGION_FIRM_DATA.array[1].monthly_revenue, 20.0, 1e-3);
	
	//And the economy-wide totals
	CU_ASSERT_DOUBLE_EQUAL(MONTHLY_SOLD_QUANTITY, 2200.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(MONTHLY_REVENUE, 220.0, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_calc_price_index()
 * \brief: Unit test for: Eurostat_calc_price_index.
 * Status: NOT Tested
 */
void unittest_Eurostat_calc_price_index()
{
	int rc;
	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	/***** Messages: initialize message boards **********************************/
    rc = MB_Create(&b_firm_send_data, sizeof(m_firm_send_data));
    	    #ifdef ERRCHECK
    	    if (rc != MB_SUCCESS)
    	    {
    	       fprintf(stderr, "ERROR: Could not create 'firm_send_data' board\n");
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
	
	/***** Messages: pre-conditions **********************************/
//    add_<message_name>_message();
    	    
    /***** Adding message iterators ***************************************/
	rc = MB_Iterator_Create(b_firm_send_data, &i_firm_send_data);
			
	if (rc != MB_SUCCESS)
			{
			   fprintf(stderr, "ERROR: Could not create Iterator for '<message>'\n");
			   switch(rc) {
			       case MB_ERR_INVALID:
			           fprintf(stderr, "\t reason: 'firm_send_data' board is invalid\n");
			           break;
			       case MB_ERR_LOCKED:
		               fprintf(stderr, "\t reason: 'firm_send_data' board is locked\n");
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
	Eurostat_calc_price_index();
    
    /***** Variables: Memory post-conditions *****/
//	CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_calc_firm_population()
 * \brief: Unit test for: Eurostat_calc_firm_population.
 * Status: NOT Tested
 */
void unittest_Eurostat_calc_firm_population()
{

	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_calc_firm_population();
    
    /***** Variables: Memory post-conditions *****/
	//CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_calc_firm_survival_rates()
 * \brief: Unit test for: Eurostat_calc_firm_survival_rates.
 * Status: NOT Tested
 */
void unittest_Eurostat_calc_firm_survival_rates()
{

	
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/

	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_calc_firm_survival_rates();
    
    /***** Variables: Memory post-conditions *****/
//		CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_store_history_monthly()
 * \brief: Unit test for: Eurostat_store_history_monthly.
 * Status: Tested OK
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
	for (k=1;k<13;k++)
	{
		var = HISTORY_MONTHLY[k].cpi;
		result = (double) (k-1);

		//printf("\n HISTORY_MONTHLY[%d].cpi=%f\n", k, HISTORY_MONTHLY[k].cpi);
		//printf("\n k=%d, var=%f, result=%f\n", k, var, result);		
		
		CU_ASSERT_DOUBLE_EQUAL(var, result, 1e-3);
	}
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Eurostat_store_history_quarterly()
 * \brief: Unit test for: Eurostat_store_history_quarterly.
 * Status: Tested OK
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
 * Status: Tested OK
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
 * Status: Tested OK
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
 * \fn: void unittest1_Eurostat_measure_recession()
 * \brief: Unit test for: Eurostat_measure_recession.
 * Status: Not tested
 */
void unittest1_Eurostat_measure_recession()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	RECESSION_STARTED=0;
	HISTORY_QUARTERLY[0].gdp=90;
	HISTORY_QUARTERLY[1].gdp=100;
	HISTORY_QUARTERLY[2].gdp=110;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_measure_recession();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(RECESSION_STARTED, 1);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest2_Eurostat_measure_recession()
 * \brief: Unit test for: Eurostat_measure_recession.
 * Case: RECESSION_STARTED=1 and after updating RECESSION_DURATION from 0 to 1, the recession continues: RECESSION_STARTED=1
 * Status: Not tested
 */
void unittest2_Eurostat_measure_recession()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	RECESSION_STARTED=1;
	RECESSION_DURATION=0;
	HISTORY_QUARTERLY[0].gdp=90;
	HISTORY_QUARTERLY[1].gdp=100;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_measure_recession();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(RECESSION_STARTED, 1);
	CU_ASSERT_EQUAL(RECESSION_DURATION, 1);	
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest3_Eurostat_measure_recession()
 * \brief: Unit test for: Eurostat_measure_recession.
 * Case: RECESSION_STARTED=1 and after updating RECESSION_DURATION from 0 to 1, the recession is ended: RECESSION_STARTED=0.
 * Status: Not tested
 */
void unittest3_Eurostat_measure_recession()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	RECESSION_STARTED=1;
	RECESSION_DURATION=0;
	HISTORY_QUARTERLY[0].gdp=110;
	HISTORY_QUARTERLY[1].gdp=100;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_measure_recession();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(RECESSION_STARTED, 0);
	CU_ASSERT_EQUAL(RECESSION_DURATION, 1);
	
    /************* At end of unit test, free the agent **************/
	unittest_free_Eurostat_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest4_Eurostat_measure_recession()
 * \brief: Unit test for: Eurostat_measure_recession.
 * Case: Recession does not occur: before RECESSION_STARTED=0, and after RECESSION_STARTED=0.
 * Status: Not tested
 */
void unittest4_Eurostat_measure_recession()
{
    /************* At start of unit test, add one agent **************/
	unittest_init_Eurostat_agent();
	
    /***** Variables: Memory pre-conditions **************************/
	RECESSION_STARTED=0;
	HISTORY_QUARTERLY[0].gdp=90;
	HISTORY_QUARTERLY[1].gdp=100;
	HISTORY_QUARTERLY[2].gdp=90;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
	Eurostat_measure_recession();
    
    /***** Variables: Memory post-conditions *****/
	CU_ASSERT_EQUAL(RECESSION_STARTED, 0);
	
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
    
	/***** Messages: initialize message boards **********************************/
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

	/***** Messages: pre-conditions **********************************/
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


