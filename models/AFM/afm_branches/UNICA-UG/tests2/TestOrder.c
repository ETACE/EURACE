#include "TestOrder.h"


 Order *anOrderA;
 Order *anOrderB;
 

 int suite_Order_init(void) 
      {   
         anOrderA=newOrder();
           setOrder(anOrderA,3.5,10,0,0);
         anOrderB=newOrder();
           setOrder(anOrderB,7.5,10,0,0);
          return 0; 
      }
       
 int suite_Order_clean(void) { 
     free(  anOrderA);
     free(  anOrderB);
     return 0; 
     }



void testSwapOrder(void)
{    Order *anOrder;
     anOrder=newOrder();
     setOrder(anOrder,3.5,10,0,0);
     swapOrder(anOrderA,anOrderB);
     CU_ASSERT(isEqualOrder(anOrderB,anOrder));
     free(anOrder);
}


void testCompareOrder(void)
{    
     CU_ASSERT_FALSE(isEqualOrder(anOrderA,anOrderB));
}


