#include "TestClearingMechanism.h"


Clearing *clearm;
Order * aBuyOrder;
Order *aSellOrder ;

void setFixtureClearing()
{
  int i;
  int temp;
for(i=1;i<4;i++)
{       temp=10*i;
		aBuyOrder =newOrder();
		setOrder(aBuyOrder,temp,10,0,0);
	    addBuyOrder(clearm, aBuyOrder);
	    free(aBuyOrder);
}
}
void setFixtureForRun()
{
    setFixtureClearing();
    aSellOrder = newOrder();
    setOrder(aSellOrder,10,5,0,0);
    addSellOrder(clearm,aSellOrder);
}
void setNoBuyOrders()
{      emptyClearing(clearm);
      clearm->lastPrice=100;
    aSellOrder = newOrder(); 
    setOrder(aSellOrder,10,5,0,0);
    addSellOrder(clearm,aSellOrder);
    free(aSellOrder);
     };
void setNoSellOrders()
{      emptyClearing(clearm);
      clearm->lastPrice=100;
    aBuyOrder = newOrder(); 
    setOrder(aBuyOrder,10,5,0,0);
    addBuyOrder(clearm,aSellOrder);
    free(aSellOrder);
     };
     	

 int suite_ClearingMechanism_init(void) 
 {   clearm =newClearingMechanism();
     setFixtureClearing();
     return 0;
 }
  
 int suite_ClearingMechanism_clean(void)
 {   freeClearingMechanism(clearm);
     free(clearm);
     return 0;
}
void testComputeNewPrice(void)
{   double price;
       	//"Caso 1"
	aSellOrder = newOrder();
    setOrder(aSellOrder,10,5,0,0);
    addSellOrder(clearm,aSellOrder);
    price =computeNewPrice(clearm);
    CU_ASSERT(price== 30);
    printf("new price %f",price);
    free(aSellOrder);
	//"Caso 2"
	aSellOrder = newOrder();
    setOrder(aSellOrder,10,5,0,0);
    addSellOrder(clearm,aSellOrder);
    CU_ASSERT(computeNewPrice(clearm)== 25);
    free(aSellOrder);
    setNoBuyOrders();
    price =computeNewPrice(clearm);
      printf("new price %f",price);
      CU_ASSERT_DOUBLE_EQUAL(90,price,EPS);
      setNoSellOrders();
      price =computeNewPrice(clearm);
      printf("new price %f",price);
      CU_ASSERT_DOUBLE_EQUAL(110,price,EPS);

}

void testRunClearing(void)
{ 
  double price;
  int demand,supply;
  emptyClearing(clearm);
  setFixtureForRun();
  runClearing(clearm);
  price=clearm->lastPrice;
  printf("sin qui ci siamo %f",price);
  demand=aggregateDemand(clearm,price);
  supply=aggregateSupply(clearm,price);
  CU_ASSERT(price== 30);
  printf("supply = %d demand %d",supply,demand);
  CU_ASSERT(supply== demand);
}
