#include "../Suites.h"
#include "../header.h"
#include "../Household_agent_header.h"
#include "my_library_header.h"


/*     
void testassetUtilitiesToDesiredWeights(void)
{     CDouble *weights;
      double expected;
      double m;
      expected=1.0/(maxAssets+1);
      weights=assetUtilitiesToDesiredWeights();
      m=mean(weights);
     // printf(" valore %f xx %f",m,expected);
      CU_ASSERT_DOUBLE_EQUAL(m,expected, EPS);
}

void testSendOrders(void)
{
     
}*/
void testComputeLimitOrder(void)
{  /* Order *ord;
    double weight,resource;
     Belief *belief;
     weight=0.2;
     resource=1000;
     Asset *asset;
     CAsset *assets;
     assets=get_assetsowned();
     belief=get_belief();
     asset=firstCAsset(assets);
     setSeed(rnd,2345678901.0);
     assetBeliefFormation(belief, assets,rnd);
 
     ord=computeLimitOrder(asset,weight,resource,belief);
     printf("price %f quantity%d",ord->price,ord->quantity);
     CU_ASSERT_DOUBLE_EQUAL(ord->price,50.9887, EPS);
     CU_ASSERT_EQUAL(ord->quantity,-997);*/
}  
void test_Household_select_strategy(void)
  {  double strategy;
     
     Household_select_strategy();
     strategy=get_strategy();
     CU_ASSERT_EQUAL(strategy,0);
     };
/*void testgeneratePendingOrders(void){
      COrder *pending;
    CAsset *assetsowned;
    Belief *belief;
    Portfolio *port;
     
     setSeed(rnd,2345678901.0);
    port=get_portfolio();
    belief=get_belief();
    assetsowned=get_assetsowned();
    pending=get_pendingOrders();
    generatePendingOrders(assetsowned,pending,belief,port); 
    CU_ASSERT_EQUAL(sizeCOrder(pending),2);};
    
 */   
void test_Household_update_its_portfolio(void)
{     Order_array *pending;
       Asset_array *assetsowned;
       Asset *asset;
      

 
     setSeed(2345678901.0);
     PAYMENT_ACCOUNT=5000;
     assetsowned=get_assetsowned();
     set_id(1);
   
     add_Asset(assetsowned, 1,1000,50);
     pending=get_pendingOrders();
     add_Order(pending, 1, -400, 50.8,1);
     add_order_status_message(1,1,50.9,-300);
    
     MB_Iterator_Create(b_order_status, &i_order_status);

     Household_update_its_portfolio();

     assetsowned=get_assetsowned();
     asset=firstCAsset(assetsowned);


     //printf("quantity %d",asset->quantity);
     CU_ASSERT_EQUAL(asset->quantity,700);
     }

void test_Household_receive_info_interest_from_bank(void)
{
}



void test_Household_stock_beliefs_formation(void)
{
}

void test_Household_bond_beliefs_formation(void)
{
}

void test_Household_does_not_trading(void)
{
}

void test_Household_send_orders(void)
{
}



 


