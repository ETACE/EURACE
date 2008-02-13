#ifndef TESTINT_INCL
#define TESTINT_INCL
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#include "Int.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

	
/* init and clean-up suite */
 int suite_int_init(void);
 int suite_int_clean(void);


/*test case for serializeDouble*/ 
 void testSerializeInt(void);
 


/*Instance of CU_TestInfo array that allows to test large software*/	
 static CU_TestInfo tests_int[] = {
  { "test serializeInt", testSerializeInt },
	CU_TEST_INFO_NULL,
};	

#define TESTINT_INCL
#endif


