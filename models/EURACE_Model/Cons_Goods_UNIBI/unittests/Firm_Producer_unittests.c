
/*
 * \fn: void unittest_Firm_calc_production_quantity()
 * \brief: Unit tests for: Firm_calc_production_quantity
 */
void unittest_Firm_calc_production_quantity()
{
    /************* At start of unit test, add one agent **************/
	add_Firm_agent_internal(init_Firm_agent());
	current_xmachine = *p_xmachine;
	
    /***** Variables: Memory pre-conditions **************************/
    
    /*
    CAPITAL_STOCK[0].units=1000.0;
    CAPITAL_STOCK[0].purchase_price=10.0;
    CAPITAL_STOCK[0].productivity=10.0;
    CAPITAL_STOCK[0].depreciation_units_per_period=100.0;

    CAPITAL_STOCK[1].units=2000.0;
    CAPITAL_STOCK[1].purchase_price=20.0;
    CAPITAL_STOCK[1].productivity=20.0;
    CAPITAL_STOCK[1].depreciation_units_per_period=100.0;
*/
    add_capital_stock_item(&CAPITAL_STOCK, 1000.0, 10.0, 10.0, 100.0);
    add_capital_stock_item(&CAPITAL_STOCK, 2000.0, 20.0, 20.0, 100.0);
    TOTAL_UNITS_CAPITAL_STOCK=0.0;
    TOTAL_VALUE_CAPITAL_STOCK=0.0;
	
	/***** Messages: pre-conditions **********************************/
    
    /***** Function evaluation ***************************************/
    Firm_calc_production_quantity();

    /***** Variables: Memory post-conditions *************************/
	
	/*
	CAPITAL_STOCK[0]
	{
	    double units=900; was 1000
	    double depreciation_units_per_period=100;
	}*/
	printf("CAPITAL_STOCK.array[0].units: %f", CAPITAL_STOCK.array[0].units);
	CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[0].units, 900.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[0].depreciation_units_per_period, 100.0, 1e-3);
	
	/*
	CAPITAL_STOCK[1]
	{
	    double units=1900; was 2000
	    double depreciation_units_per_period=100.0;
	}*/
	
	printf("CAPITAL_STOCK.array[1].units: %f", CAPITAL_STOCK.array[1].units);
	CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[1].units, 1900.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[1].depreciation_units_per_period, 100.0, 1e-3);  
	
	CU_ASSERT_DOUBLE_EQUAL(TOTAL_UNITS_CAPITAL_STOCK, 2800.0, 1e-3);
	CU_ASSERT_DOUBLE_EQUAL(TOTAL_VALUE_CAPITAL_STOCK, 38900.0, 1e-3);

    /***** Messages: post-conditions **********************************/

    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}