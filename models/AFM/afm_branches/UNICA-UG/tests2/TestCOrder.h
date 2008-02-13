#ifndef TESTCOLLORDER_INCL
#include <stdlib.h>
#include "COrder.h"
#include <stdio.h>
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"

 int suite_COrder_init(void) ;
       
 int suite_COrder_clean(void);
 
void testAddOrder( void);

// test for add an Order with decreasing or increasing relation respectively rel='<' or rel='>'

void testAddIncSortOrder(void);

void testAddDecSortOrder(void);
//test for find the max prince

void testMaxPriceOrder(void);

void testremoveWithId();

void testquicksort();
 
static CU_TestInfo tests_COrder[] = {
  { "test for add new order", testAddOrder },
    { "test for find the max price ", testMaxPriceOrder },
{ "test for add new order with a incremental policy",testAddIncSortOrder },
{ "test for add new order with a decremental policy",testAddDecSortOrder },
{ "test remove with id",testremoveWithId },
{ "test quicksort",testquicksort },

	CU_TEST_INFO_NULL,
};	

#define TESTCOLLORDER_INCL
#endif
