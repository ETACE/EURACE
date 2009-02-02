#include "Suites.h"
#include "header.h"


void print_example_results(void)
{
  fprintf(stdout, "\n\nExpected Test Results:"
                  "\n\n  Error Handling  Type      # Run   # Pass   # Fail"
                  "\n\n  ignore errors   suites%9u%9u%9u"
                    "\n                  tests %9u%9u%9u"
                    "\n                  asserts%8u%9u%9u"
                  "\n\n  stop on error   suites%9u%9u%9u"
                    "\n                  tests %9u%9u%9u"
                    "\n                  asserts%8u%9u%9u\n\n",
                  14, 14, 3,
                  31, 10, 21,
                  89, 47, 42,
                  4, 4, 1,
                  12, 9, 3,
                  12, 9, 3);
}

void AddTests()
{
  assert(NULL != CU_get_registry());
  assert(!CU_is_test_running());

	/* Register suites. */
	if (CU_register_suites(suites) != CUE_SUCCESS) {
		fprintf(stderr, "suite registration failed - %s\n",
			CU_get_error_msg());
		exit(EXIT_FAILURE);
	}

}

int suite_Firm_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Firm_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Firm=current_xmachine_Firm;
    return 0;

}

int suite_Firm_clean(void)
 {  
    unittest_free_Firm_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Household_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Household_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Household=current_xmachine_Household;
    return 0;

}

int suite_Household_clean(void)
 {  
    unittest_free_Household_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Mall_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Mall_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Mall=current_xmachine_Mall;
    return 0;

}

int suite_Mall_clean(void)
 {  
    unittest_free_Mall_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_IGFirm_init(void)
{  
   // initialise_unit_testing();
    unittest_init_IGFirm_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_IGFirm=current_xmachine_IGFirm;
    return 0;

}

int suite_IGFirm_clean(void)
 {  
    unittest_free_IGFirm_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Eurostat_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Eurostat_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Eurostat=current_xmachine_Eurostat;
    return 0;

}

int suite_Eurostat_clean(void)
 {  
    unittest_free_Eurostat_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Clearinghouse_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Clearinghouse_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Clearinghouse=current_xmachine_Clearinghouse;
    return 0;

}

int suite_Clearinghouse_clean(void)
 {  
    unittest_free_Clearinghouse_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Bank_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Bank_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Bank=current_xmachine_Bank;
    return 0;

}

int suite_Bank_clean(void)
 {  
    unittest_free_Bank_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Government_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Government_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Government=current_xmachine_Government;
    return 0;

}

int suite_Government_clean(void)
 {  
    unittest_free_Government_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}

int suite_Central_Bank_init(void)
{  
   // initialise_unit_testing();
    unittest_init_Central_Bank_agent();
    current_xmachine = (xmachine *)malloc(sizeof(xmachine));
    CHECK_POINTER(current_xmachine);
    current_xmachine->xmachine_Central_Bank=current_xmachine_Central_Bank;
    return 0;

}

int suite_Central_Bank_clean(void)
 {  
    unittest_free_Central_Bank_agent();
    //MB_Env_Finalise ();
    free_messages();
    return 0;
}
 
