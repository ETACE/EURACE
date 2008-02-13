#ifndef TESTORD_INCL
#include "Order.h"
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"

 int suite_Order_init(void) ;
       
 int suite_Order_clean(void);
 
void testSwapOrder(void);
void testCompareOrder(void);
 
static CU_TestInfo tests_Order[] = {
  { "test for swap two orders", testSwapOrder },
  { "test for compare two orders",testCompareOrder },
  
	CU_TEST_INFO_NULL,
};	

#define TESTORD_INCL
#endif
