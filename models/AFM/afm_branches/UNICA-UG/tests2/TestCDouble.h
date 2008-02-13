#ifndef TESTCDOUBLE_INCL
#include <stdlib.h>
#include "CDouble.h"
#include <stdio.h>
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"

#ifndef EPS 
#define EPS 0.000001
#endif

 int suite_CDouble_init(void) ;
       
 int suite_CDouble_clean(void);
 
void testAddDouble( void);
void testSerializeCDouble();

// test for add an Double with decreasing or increasing relation respectively rel='<' or rel='>'

//void testAddIncSortDouble(void);


//void testVarianceLogReturns(void);

//void testLogReturns(void);

void testMean(void);

void testVariance(void);
//void testPrintDouble(void);


 
static CU_TestInfo tests_CDouble[] = {
   { "test for add new double", testAddDouble },
  { "test serializeDouble", testSerializeCDouble },
   { "test for mean", testMean },
   { "test for variance", testVariance},
   //{ "test for add new double with a incremental policy",testAddIncSortDouble },
   // { "test for VarianceLogReturns", testVarianceLogReturns },
   //{ "test for logReturns", testLogReturns },
   //{ "test for printDouble", testPrintDouble },


	CU_TEST_INFO_NULL,
};	

#define TESTCDOUBLE_INCL
#endif
