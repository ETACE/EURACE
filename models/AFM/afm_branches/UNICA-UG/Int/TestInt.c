#include "TestInt.h"
#include "Stream.h" 
 
 
/*set the Fixture to test the double  */ 

 static void setFixture(void)
{

 
}
 
/* init and clean-up suite */
 int suite_int_init(void) { return 0; }
       
 int suite_int_clean(void) { return 0; }

	
/*test case for serializeInt*/     
void testSerializeInt()
{   int dtest;
    Stream *str;
    str=newStream(10);
    serializeInt(23,str);
    dtest=deserializeInt(str);
    CU_ASSERT_DOUBLE_EQUAL(23, dtest, 0.000001);
   
}



