#ifndef TESTHOUSE_INCL
#include "Household.h"
#include "header.h"
#include "Asset.h"
#include "CDouble.h"
#include "Portfolio.h"
#include "Order.h"
#include "COrder.h"
#include "Belief.h"
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#ifndef EPS 
#define EPS 0.001
#endif
#include <stdio.h>

 int suite_Household_init(void) ;
       
 int suite_Household_clean(void);
 

void testassetUtilitiesToDesiredWeights(void);
void testSendOrders(void);
void testComputeLimitOrder(void);
void testSelectStrategy(void);
void testgeneratePendingOrders(void);
void testUpdateTrader(void);
 
static CU_TestInfo tests_Household[] = {
  { "test assetUtilitiesToDesiredWeights", testassetUtilitiesToDesiredWeights},
  { "test ComputeLimitOrder",testComputeLimitOrder},
   { "test generatePendingOrders",testgeneratePendingOrders },
   { "test sendOrder", testSendOrders },
   { "test selectStrategy",testSelectStrategy},
   { "test updateTrader",testUpdateTrader},
	CU_TEST_INFO_NULL,
};	

#define TESTHOUSE_INCL
#endif
