#include "TestCDouble.h"
#include "Stream.h" 

 
/*set the Fixture to test the double  */ 

 static void setFixture(void)
{

 
}
 
/* init and clean-up suite */
 int suite_CDouble_init(void) { return 0; }
       
 int suite_CDouble_clean(void) { return 0; }

	
/*test case for serializeInt*/     
void testSerializeCDouble()
{   CDouble *dtest;
    CDouble *expected;
     dtest=newCDouble(10);
     
     addCDouble(dtest,4);
     addCDouble(dtest,6);
     
    Stream *str;
    str=newStream(10);
    serializeCDouble(dtest,str);
    expected=deserializeCDouble(str);
    //CU_ASSERT_DOUBLE_EQUAL(2, expected-, 0.000001);
    CU_ASSERT_EQUAL((dtest->size),(expected->size));
}



