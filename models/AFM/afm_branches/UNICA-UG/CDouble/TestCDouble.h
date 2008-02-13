#ifndef TESTCD_INCL
#define TESTCD_INCL
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#include "CDouble.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

	
/* init and clean-up suite */
 int suite_CDouble_init(void);
 int suite_CDouble_clean(void);


/*test case for serializeCDouble*/ 
 void testSerializeCDouble(void);
 


/*Instance of CU_TestInfo array that allows to test large software*/	
 static CU_TestInfo tests_CDouble[] = {
  { "test serializeDouble", testSerializeCDouble },
	CU_TEST_INFO_NULL,
};	

#define TESTCD_INCL
#endif


