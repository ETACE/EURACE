#include "TestHousehold.h"
 



double cloud_data[6];
xmachine **agent_list;
//agent_list=p_xmachine;



void setHouseholdState(void)
 {  
    
}

void setOrderForUpdateTrader()
{
     
}
     
static void initializeEnvironment(void){rnd=newRandom();};
void initializePopulation(void)
{   int id;
    double wealth;
    Portfolio * portfolio;
    Belief *belief;
    COrder *pendingOrders;
   CAsset *assetsowned;
    double posx;
    double posy;
	id = 1;
	wealth = 0.0;
	belief=newBelief();
	portfolio = newPortfolio();
	setBankAccount(portfolio,5000);
   pendingOrders = newCOrder(10);
	assetsowned=newAssetsOwned();
	posx = 0.0;
	posy = 0.0;
	
   add_Household_agent(id, wealth,  belief,  portfolio,   pendingOrders, assetsowned,posx,  posy);  
}


 int suite_Household_init(void)
 
 {  initialise_pointers();
	add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
	current_node = *p_node_info;
	
    initializeEnvironment();
    p_order_message = &current_node->order_messages;
	p_orderStatus_message = &current_node->orderStatus_messages;
	p_xmachine = &current_node->agents;
	//agent_list=p_xmachine;
    initializePopulation();
    current_xmachine = * p_xmachine;
   // printf("sono qui");
    return 0;

}

 int suite_Household_clean(void)
 
 {  
  
    return 0;
}
     
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
     
}
void testComputeLimitOrder(void)
{   Order *ord;
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
     CU_ASSERT_EQUAL(ord->quantity,-997);
}  
void testSelectStrategy(void)
  {  COrder *pendingOrders;
     /*fixture*/
     pendingOrders=get_pendingOrders();
     emptyCOrder(pendingOrders);
     setSeed(rnd,2345678901.0);
     selectStrategy();
     
     CU_ASSERT_EQUAL(sizeCOrder(pendingOrders),0);
     };
void testgeneratePendingOrders(void){
      COrder *pending;
    CAsset *assetsowned;
    Belief *belief;
    Portfolio *port;
     /*fixture*/
     setSeed(rnd,2345678901.0);
    port=get_portfolio();
    belief=get_belief();
    assetsowned=get_assetsowned();
    pending=get_pendingOrders();
    generatePendingOrders(assetsowned,pending,belief,port); 
    CU_ASSERT_EQUAL(sizeCOrder(pending),2);};
    
    
void testUpdateTrader(void)
{      COrder *pending;
       CAsset *assetsowned;
       Asset *asset;
    Order *ord;
    Portfolio *port;
     /*fixture*/
     setSeed(rnd,2345678901.0);
    port=get_portfolio();
    ord=newOrder();
    setOrder(ord,50.8,-400,1,0);
    pending=get_pendingOrders();
    addOrder(pending,ord);
    add_orderStatus_message(1,0,50.9,-300,message_range, get_posx(),get_posy(),0.0);
     updateTrader();
     assetsowned=get_assetsowned();
     asset=firstCAsset(assetsowned);
     printf("quantity %d",asset->quantity);
      CU_ASSERT_EQUAL(asset->quantity,700);
     };

 
 


