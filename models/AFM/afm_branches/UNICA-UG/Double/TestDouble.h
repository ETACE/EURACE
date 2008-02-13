#ifndef TESTDBL_INCL
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#include "Double.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

	
/* init and clean-up suite */
 int suite_double_init(void);
 int suite_double_clean(void);


/*test case for serializeDouble*/ 
 void testSerializeDouble(void);
 


/*Instance of CU_TestInfo array that allows to test large software*/	
 static CU_TestInfo tests_double[] = {
  { "test serializeDouble", testSerializeDouble },
	CU_TEST_INFO_NULL,
};	

#define TESTRAND_INCL
#endif


