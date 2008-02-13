#ifndef TESTRAND_INCL
#include "CUnit\Basic.h"
#include "CUnit\CUnit.h"
#include "Random.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define TESTGAUSS 1.8442632806693
#ifndef EPS 
#define EPS 0.000001
#endif

/*Random  test_next the Its Completely Broken Test"
	The above should print as... (0.149243269650845 0.331633021743797 0.75619644800024 
	0.393701540023881 0.941783181364547 0.549929193942775 0.659962596213428 
	0.991354559078512 0.696074432551896 0.922987899707159 ) If they are not these values 
	(accounting for precision of printing) then something is horribly wrong: DO NOT USE THIS CODE 
	FOR ANYTHING.*/
	
/* init and clean-up suite */
 int suite_random_init(void);
 int suite_random_clean(void);


/*test case for next*/ 
 void testnext(void);
 
/*test case for nextBetween*/    
 void testNextBetween(void);

/*test case for  gaussian*/  
 void testGaussian(void);

 void testNextMax(void);
/*Instance of CU_TestInfo array that allows to test large software*/	
 static CU_TestInfo tests_random[] = {
  { "test next", testnext },
  { "test nextBetween", testNextBetween },
  { "test gaussian", testGaussian },
   { "test nextMax", testNextMax },
	CU_TEST_INFO_NULL,
};	

#define TESTRAND_INCL
#endif


