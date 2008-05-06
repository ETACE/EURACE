void unittest_Firm_calc_production_quantity()
{
    /************* At start of unit test, add one agent **************/
    add_Firm_agent_internal(init_Firm_agent());
    current_xmachine = *p_xmachine;
    
    /***** Variables: Memory pre-conditions **************************/
    CURRENT_MALL_STOCKS.array[0].mall_id =1;
    CURRENT_MALL_STOCKS.array[0].current_stock=0.0;
    CURRENT_MALL_STOCKS.array[0].critical_stock=0.0;
        
    CURRENT_MALL_STOCKS.array[1].mall_id =2;
    CURRENT_MALL_STOCKS.array[1].current_stock=0.0;
    CURRENT_MALL_STOCKS.array[1].critical_stock=0.0;
    
    OUT_OF_STOCK_COSTS=0.0;
    
    PRICE =1.0;
    DISCOUNT_RATE=0.1;
    UNIT_COSTS = 10;
    INVENTORY_COSTS_PER_UNIT = 0.0;
    FIRM_PLANNING_HORIZON = 2.0;
    ADAPTION_DELIVERY_VOLUME = 0.0;
    
    LAMBDA=1.0;
    
    MALLS_SALES_STATISTICS.array[0].mall_id=1;
    MALLS_SALES_STATISTICS.array[0].period=1;
    MALLS_SALES_STATISTICS.array[0].sales={200};
    
    MALLS_SALES_STATISTICS.array[1].mall_id=1;
    MALLS_SALES_STATISTICS.array[1].period=2;
    MALLS_SALES_STATISTICS.array[1].sales={200};

    MALLS_SALES_STATISTICS.array[2].mall_id=2;
    MALLS_SALES_STATISTICS.array[2].period=1;
    MALLS_SALES_STATISTICS.array[2].sales={300};
    
    MALLS_SALES_STATISTICS.array[3].mall_id=2;
    MALLS_SALES_STATISTICS.array[3].period=2;
    MALLS_SALES_STATISTICS.array[3].sales={300};

    PLANNED_DELIVERY_VOLUME.array[0].mall_id=1;
    PLANNED_DELIVERY_VOLUME.array[1].mall_id=2;
    
    LAST_PLANNED_PRODUCTION_QUANTITIES.array[0]=0.0;
    LAST_PLANNED_PRODUCTION_QUANTITIES.array[1]=0.0;
    
    /***** Messages: pre-conditions **********************************/
//  add_<message_name>_message(<msg_var>, MSGDATA);
    add_current_mall_stock_info_message(1, 3, 10.0, MSGDATA);
    add_current_mall_stock_info_message(2, 3, 20.0, MSGDATA);
    
    /***** Function evaluation ***************************************/
    Firm_calc_production_quantity();

    /***** Variables: Memory post-conditions *************************/
    CU_ASSERT_EQUAL(CURRENT_MALL_STOCKS.size, 2);
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[0].current_stock, 10.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[1].current_stock, 20.0, 1e-3);
       
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[0].critical_stock, 200.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CURRENT_MALL_STOCKS.array[1].critical_stock, 300.0, 1e-3);
    
    CU_ASSERT_DOUBLE_EQUAL(OUT_OF_STOCK_COSTS, 0.0, 1e-3);
    
    CU_ASSERT_EQUAL(PLANNED_DELIVERY_VOLUME.array[0].mall_id, 1);
    CU_ASSERT_EQUAL(PLANNED_DELIVERY_VOLUME.array[1].mall_id, 2);
        
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_DELIVERY_VOLUME.array[0].quantity, 190.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_DELIVERY_VOLUME.array[1].quantity, 280.0, 1e-3);

    CU_ASSERT_DOUBLE_EQUAL(PLANNED_PRODUCTION_QUANTITY, 370.0, 1e-3);
    
    /***** Messages: post-conditions **********************************/   
    
    /************* At end of unit test, free the agent **************/
    free_agent();
    /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Firm_calc_input_demands()
 * \brief: Unit tests for: Firm_calc_input_demands
 */
void unittest1_Firm_calc_input_demands()
{
    /************* At start of unit test, add one agent **************/
    add_Firm_agent_internal(init_Firm_agent());
    current_xmachine = *p_xmachine;

    /***** Variables: Memory pre-conditions **************************/
    MEAN_SPECIFIC_SKILLS = 1.0;
    TECHNOLOGY = 1.5;
    DEPRECIATION_RATE = 1.0;
    PLANNED_PRODUCTION_QUANTITY = 100.0;
    BETA = 0.5;
    MEAN_WAGE = 1.0;
    ALPHA = 0.5;
    //temp_capital_demand==100.0
    
    TOTAL_UNITS_CAPITAL_STOCK = 100.0;//also test when this is 99.0
    INV_INERTIA = 1.0;
   
    DELIVERY_PROB_IF_CRITICAL_STOCK_0 = 100;
    
    /***** Messages: pre-conditions **********************************/
    //add_productivity_message(IGfirm_id, cap_productivity, cap_good_price, MSGDATA);
    add_productivity_message(2, 1.0, 1.0, MSGDATA);
    
    /***** Function evaluation ***************************************/
    Firm_calc_input_demands();
    
    /***** Variables: Memory post-conditions *************************/
    CU_ASSERT_DOUBLE_EQUAL(NEEDED_CAPITAL_STOCK, 100.0, 1e-3);
    
   /***** Messages: post-conditions **********************************/
    START_PRODUCTIVITY_MESSAGE _MESSAGE_LOOP
    	//TECHNOLOGICAL_FRONTIER = productivity_message->cap_productivity;
        CU_ASSERT_DOUBLE_EQUAL(TECHNOLOGICAL_FRONTIER, 1.0, 1e-3);
    	//ACTUAL_CAP_PRICE = productivity_message->cap_good_price;
        CU_ASSERT_EQUAL(ACTUAL_CAP_PRICE, 1.0);
    FINISH_PRODUCTIVITY_MESSAGE _MESSAGE_LOOP
    
    /************* At end of unit test, free the agent **************/
    free_agent();
   /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Firm_calc_input_demands()
 * \brief: Unit tests for: Firm_calc_input_demands
 */
void unittest2_Firm_calc_input_demands()
{
    /************* At start of unit test, add one agent **************/
    add_Firm_agent_internal(init_Firm_agent());
    current_xmachine = *p_xmachine;

    /***** Variables: Memory pre-conditions **************************/
    MEAN_SPECIFIC_SKILLS = 2.0;
    TECHNOLOGY = 1.5;
    DEPRECIATION_RATE = 1.0;
    PLANNED_PRODUCTION_QUANTITY = 100.0;
    BETA = 0.5;
    MEAN_WAGE = 1.0;
    ALPHA = 0.5;
    //temp_capital_demand==100.0
    
    TOTAL_UNITS_CAPITAL_STOCK = 99.0;//also test when this is 99.0
    INV_INERTIA = 1.0;
 
    DELIVERY_PROB_IF_CRITICAL_STOCK_0 = 100;
    
    /***** Messages: pre-conditions **********************************/
    //add_productivity_message(IGfirm_id, cap_productivity, cap_good_price, MSGDATA);
    add_productivity_message(2, 1.0, 1.0, MSGDATA);
    
    /***** Function evaluation ***************************************/
    Firm_calc_input_demands();
    
    /***** Variables: Memory post-conditions *************************/
    CU_ASSERT_DOUBLE_EQUAL(NEEDED_CAPITAL_STOCK, 99.0, 1e-3);
    
   /***** Messages: post-conditions **********************************/
   
    /************* At end of unit test, free the agent **************/
    free_agent();
   /************* At end of unit tests, free all Messages **********/
    free_messages();
}

/*
 * \fn: void unittest_Firm_calc_input_demands()
 * \brief: Unit tests for: Firm_calc_input_demands
 * Test: whether the capital stock is being depreciated, in units and value
 */
void unittest3_Firm_calc_input_demands()
{
    /************* At start of unit test, add one agent **************/
    add_Firm_agent_internal(init_Firm_agent());
    current_xmachine = *p_xmachine;

    /***** Variables: Memory pre-conditions **************************/
    ACTUAL_CAP_PRICE=0.0;
    MEAN_SPECIFIC_SKILLS = 1.0;
    TECHNOLOGY = 1.5;
    DEPRECIATION_RATE = 1.0;
    PLANNED_PRODUCTION_QUANTITY = 100.0;
    BETA = 1.0;
    MEAN_WAGE = 1.0;
    ALPHA = 1.0;
    //temp_capital_demand==100.0
 
    INV_INERTIA = 1.0;
    
    /*
    CAPITAL_STOCK[0].units=10.0;
    CAPITAL_STOCK[0].purchase_price=1.0;
    CAPITAL_STOCK[0].productivity=10.0;
    CAPITAL_STOCK[0].depreciation_units_per_period=1.0;

    CAPITAL_STOCK[1].units=20.0;
    CAPITAL_STOCK[1].purchase_price=1.0;
    CAPITAL_STOCK[1].productivity=20.0;
    CAPITAL_STOCK[1].depreciation_units_per_period=1.0;
*/
    add_capital_stock_item(&CAPITAL_STOCK, 10.0, 1.0, 10.0, 1.0);
    add_capital_stock_item(&CAPITAL_STOCK, 20.0, 1.0, 20.0, 1.0);
    TOTAL_UNITS_CAPITAL_STOCK=0.0;
    TOTAL_VALUE_CAPITAL_STOCK=0.0;
    
    NEEDED_CAPITAL_STOCK =30.0;
    DEMAND_CAPITAL_STOCK =0.0;
    
    /***** Messages: pre-conditions **********************************/
    //add_productivity_message(IGfirm_id, cap_productivity, ACTUAL_CAP_PRICE, MSGDATA);
    add_productivity_message(2, 1.0, 1.0, MSGDATA);
    
    /***** Function evaluation ***************************************/
    Firm_calc_input_demands();
    
    /***** Variables: Memory post-conditions *************************/
    
    /*
    CAPITAL_STOCK[0]
    {
        double units=900; was 1000
        double depreciation_units_per_period=100;
    }*/
    printf("CAPITAL_STOCK.array[0].units: %f", CAPITAL_STOCK.array[0].units);
    CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[0].units, 9.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[0].depreciation_units_per_period, 1.0, 1e-3);
    
    /*
    CAPITAL_STOCK[1]
    {
        double units=1900; was 2000
        double depreciation_units_per_period=100.0;
    }*/
    
    printf("CAPITAL_STOCK.array[1].units: %f", CAPITAL_STOCK.array[1].units);
    CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[1].units, 19.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(CAPITAL_STOCK.array[1].depreciation_units_per_period, 1.0, 1e-3);  
    
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_UNITS_CAPITAL_STOCK, 28.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(TOTAL_VALUE_CAPITAL_STOCK, 28.0, 1e-3);

    CU_ASSERT_EQUAL(EMPLOYEES_NEEDED, 3);
    CU_ASSERT_DOUBLE_EQUAL(DEMAND_CAPITAL_STOCK, 2.0, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(PLANNED_PRODUCTION_COSTS, 5.0, 1e-3);
   
   /***** Messages: post-conditions **********************************/
    
    /************* At end of unit test, free the agent **************/
    free_agent();
   /************* At end of unit tests, free all Messages **********/
    free_messages();
}


/*
 * \fn: void unittest_Firm_calc_production_quantity_2()
 * \brief: Unit tests for: Firm_calc_production_quantity_2
 */
//  void unittest_Firm_calc_production_quantity_2()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_calc_production_quantity_2();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_calc_input_demands_2()
 * \brief: Unit tests for: Firm_calc_input_demands_2
 */
//  void unittest_Firm_calc_input_demands_2()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_calc_input_demands_2();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_send_capital_demand()
 * \brief: Unit tests for: Firm_send_capital_demand
 */
//  void unittest_Firm_send_capital_demand()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_send_capital_demand();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_calc_pay_costs()
 * \brief: Unit tests for: Firm_calc_pay_costs
 */
//  void unittest_Firm_calc_pay_costs()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_calc_pay_costs();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_send_goods_to_mall()
 * \brief: Unit tests for: Firm_send_goods_to_mall
 */
//  void unittest_Firm_send_goods_to_mall()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_send_goods_to_mall();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_calc_revenue()
 * \brief: Unit tests for: Firm_calc_revenue
 */
//  void unittest_Firm_calc_revenue()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_calc_revenue();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_update_specific_skills_of_workers()
 * \brief: Unit tests for: Firm_update_specific_skills_of_workers
 */
//  void unittest_Firm_update_specific_skills_of_workers()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_update_specific_skills_of_workers();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }

/*
 * \fn: void unittest_Firm_send_data_to_Market_Research()
 * \brief: Unit tests for: Firm_send_data_to_Market_Research
 */
//  void unittest_Firm_send_data_to_Market_Research()
//  {
//      /************* At start of unit test, add one agent **************/
//      add_Firm_agent_internal(init_Firm_agent());
//      current_xmachine = *p_xmachine;
//
//      /***** Variables: Memory pre-conditions **************************/
//      <var_name1>=0.0;
//      <var_name2>=0;
//
//      /***** Messages: pre-conditions **********************************/
//      add_<message_name>_message(<msg_var>, MSGDATA);
//
//      /***** Function evaluation ***************************************/
//      Firm_send_data_to_Market_Research();
//      
//      /***** Variables: Memory post-conditions *************************/
//      CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
//      CU_ASSERT_EQUAL(<var_name2>, <value>);
//      
//     /***** Messages: post-conditions **********************************/
//      START_<MSG_NAME>_MESSAGE_LOOP 
//          CU_ASSERT_DOUBLE_EQUAL(<msg_name>_message-><var_name>, <value>, 1e-3);
//          CU_ASSERT_EQUAL(<msg_name>_message-><var_name>, <value>);
//      FINISH_<MSG_NAME>_MESSAGE_LOOP
//  
//      /************* At end of unit test, free the agent **************/
//      free_agent();
//     /************* At end of unit tests, free all Messages **********/
//      free_messages();
//  }
