#ifndef TESTCLM_INCL
#include "ClearingMechanism.h"
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#include <stdlib.h>
#include <stdio.h>

 int suite_ClearingMechanism_init(void) ;
       
 int suite_ClearingMechanism_clean(void);
 
void testComputeNewPrice(void);
void testRunClearing(void);
 
static CU_TestInfo tests_Clearing[] = {
  { "test for compute new price", testComputeNewPrice },
  { "test for run clearing", testRunClearing },
	CU_TEST_INFO_NULL,
};	

#define TESTCLM_INCL
#endif
