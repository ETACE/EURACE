#ifndef CUNIT_EXAMPLETESTS_H_SEEN
#define CUNIT_EXAMPLETESTS_H_SEEN
#include "TestRandom.h"
#include "TestCOrder.h"
#include "TestCDouble.h"
#include "TestHousehold.h"
#include "TestClearingHouse.h"
#include "TestClearingMechanism.h"
#include "TestOrder.h"
#include "CUnit/Basic.h"
#include "CUnit/CUnit.h"
#include <stdio.h>
#include <assert.h>



//add all test to the suites
void AddTests();

void print_example_results(void);

 static CU_SuiteInfo suites[] = {
{ "suite_random_both",  suite_random_init, suite_random_clean, tests_random },
 { "suite_Order_both",  suite_Order_init, suite_Order_clean, tests_Order },
 { "suite_COrder_both",  suite_COrder_init, suite_COrder_clean, tests_COrder },
  { "suite_ClearingMechanism",  suite_ClearingMechanism_init, suite_ClearingMechanism_clean, tests_Clearing},
  { "suite_CDouble",  suite_CDouble_init, suite_CDouble_clean, tests_CDouble},
  { "suite_Household",  suite_Household_init, suite_Household_clean, tests_Household},
  { "suite_ClearingHouse",  suite_ClearingHouse_init, suite_ClearingHouse_clean, tests_ClearingHouse},
	CU_SUITE_INFO_NULL,
};




#endif


 
