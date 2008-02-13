#include "TestCOrder.h"


COrder *colltst;
COrder *incColl;
COrder *decColl;
Order *anOrder1;
Order *anOrder2;
Order *anOrder3;
Order *anOrder4;
void setFixtureSorted()
{    
     
      addIncSortOrder(incColl,anOrder1);
      addIncSortOrder(incColl,anOrder2);
      addIncSortOrder(incColl,anOrder3);
      addIncSortOrder(incColl,anOrder4);
      addDecSortOrder(decColl,anOrder1);
      addDecSortOrder(decColl,anOrder2);
      addDecSortOrder(decColl,anOrder3);
      addDecSortOrder(decColl,anOrder4);
    
     
}
void setFixtureNormal()
{   
      addOrder(colltst,anOrder1);
      addOrder(colltst,anOrder2);
      addOrder(colltst,anOrder3);
      addOrder(colltst,anOrder4);
    
     
}
int suite_COrder_init(void) 
{
      
    colltst=newCOrder(20);
    incColl=newCOrder(20);
    decColl=newCOrder(20);
     anOrder1=newOrder();
     anOrder2=newOrder();
     anOrder3=newOrder();
     anOrder4=newOrder();
       
     setOrder(anOrder1,3.1,10,1,0);
     setOrder(anOrder2,3.3,10,2,0);
     setOrder(anOrder3,3.2,10,3,0);
     setOrder(anOrder4,3.0,10,4,0); 
     
    setFixtureNormal();   
    setFixtureSorted();
   
return 0;
}       
 int suite_COrder_clean(void)
 {   
     freeCOrder(colltst);
     freeCOrder(incColl);
     freeCOrder(decColl);
     free(anOrder1);
     free(anOrder2);
     free(anOrder3);
     free(anOrder4);
     return 0;
}
void testAddOrder( void)
{     Order *temp; 
      temp=lastCOrder(colltst);
     CU_ASSERT(isEqualOrder(temp,anOrder4));
     temp=firstCOrder(colltst);
     CU_ASSERT(isEqualOrder(temp,anOrder1));
}
// test for add an Order with decreasing or increasing relation respectively rel='<' or rel='>'

void testAddIncSortOrder(void)
{     Order *inc; 
      inc=lastCOrder(incColl);
    CU_ASSERT(isEqualOrder(inc,anOrder2));
      inc=firstCOrder(incColl);
    CU_ASSERT(isEqualOrder(inc,anOrder4));
    
}


void testAddDecSortOrder(void)
{     Order *dec; 
      
      dec=firstCOrder(decColl);
      printf(" price %f quantity %d", dec->price, dec->quantity);
    CU_ASSERT(isEqualOrder(dec,anOrder2));
     dec=lastCOrder(decColl);
       printf(" price %f quantity %d", dec->price, dec->quantity);
    CU_ASSERT(isEqualOrder(dec,anOrder4));
}
//test for find the max prince

void testMaxPriceOrder(void)
{    double max;
     max=maxPriceOrder(colltst);
     CU_ASSERT(max==3.3);
     max=maxPriceOrder(incColl);
     CU_ASSERT(max==3.3);
}    
 
void testremoveWithId()
{    Order *ord;
     int index;
     index=findCOrder(colltst,1);
      CU_ASSERT(index>0);
     ord=removeWithId(colltst,1);
     index=findCOrder(colltst,1);
     printf("index = %d",1);
      CU_ASSERT(index<0);
}

void testquicksort()
{ COrder *coll;
Order *ord;
     coll=newCOrder(10);
     anOrder1=newOrder();
     anOrder2=newOrder();
     anOrder3=newOrder();
     anOrder4=newOrder();
       
     setOrder(anOrder1,3.1,10,1,0);
     setOrder(anOrder2,3.3,10,2,0);
     setOrder(anOrder3,3.2,10,3,0);
     setOrder(anOrder4,3.0,10,4,0); 
     
     
      addOrder(coll,anOrder1);
      addOrder(coll,anOrder2);
      addOrder(coll,anOrder3);
      addOrder(coll,anOrder4);
     
     qSortCOrder(coll, 0, 3);
     ord=lastCOrder(coll);
      CU_ASSERT(isEqualOrder(ord,anOrder2));
           qSortCOrderDec(coll, 0, 3);
     ord=lastCOrder(coll);
      CU_ASSERT(isEqualOrder(ord,anOrder4));
     
}
     
