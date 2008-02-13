#ifndef TESTCLEHOUSE
#include "ClearingHouse.h"
#include "header.h"
#include "Asset.h"
#include "CAsset.h"
#include "Order.h"
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"


 
 int suite_ClearingHouse_init(void) ;
       
 int suite_ClearingHouse_clean(void);
 
void testReceiveOrderOnAsset(void);

void testComputeAssetPrice(void);

 
static CU_TestInfo tests_ClearingHouse[] = {
    { "test for receiveOrder",testReceiveOrderOnAsset},
  { "test for computeAssetPrice", testComputeAssetPrice},


	CU_TEST_INFO_NULL,
};	

#define TESTCLEHOUSE
#endif
