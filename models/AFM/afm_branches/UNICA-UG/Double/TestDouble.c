#include "TestDouble.h"
#include "Stream.h" 
 
 
/*set the Fixture to test the double  */ 

 static void setFixture(void)
{

 
}
 
/* init and clean-up suite */
 int suite_double_init(void) { return 0; }
       
 int suite_double_clean(void) { return 0; }

	
/*test case for serializeDouble*/     
void testSerializeDouble()
{   double dtest;
    Stream *str;
    str=newStream(10);
    serializeDouble(23.5,str);
    dtest=deserializeDouble(str);
    CU_ASSERT_DOUBLE_EQUAL(23.5, dtest, 0.000001);
   
}



