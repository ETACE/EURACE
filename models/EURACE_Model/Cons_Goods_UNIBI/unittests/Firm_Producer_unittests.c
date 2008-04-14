
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

/*
 * \fn: void unittest_Firm_calc_input_demands()
 * \brief: Unit tests for: Firm_calc_input_demands
 */
//  void unittest_Firm_calc_input_demands()
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
//      Firm_calc_input_demands();
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
