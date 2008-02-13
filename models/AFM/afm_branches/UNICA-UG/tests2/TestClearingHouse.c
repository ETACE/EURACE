
#include "TestClearingHouse.h"
 



double cloud_data[6];
xmachine **agent_list;


static void initializeEnvironment(void){rnd=newRandom();};

static void initializePopulation(void)
{ int id;
 double posx;
 double posy;
 CAsset *assets;
	id = 0;
	posx = 0.0;
	posy = 0.0;
    assets=newAssetsOwned();
    add_ClearingHouse_agent(id, assets,  posx,  posy);
    
}

static void setFixOrders(void)
{ Order *ord;
  ord=newOrder();
  setOrder(ord,55,200,1,1);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,40.3,-300,1,2);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,49.5,123,1,3);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,49,-150,1,4);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,60,123,1,5);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,55,-22,1,6);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0);
  setOrder(ord,60,-150,1,7);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity,message_range,get_posx(),get_posy(),0.0); 
}

 int suite_ClearingHouse_init(void) 
 {
    initialise_pointers();
	add_node(0, -SPINF, SPINF, -SPINF, SPINF, -SPINF, SPINF);
	current_node = *p_node_info;
    initializeEnvironment();
    p_order_message = &current_node->order_messages;
	p_orderStatus_message = &current_node->orderStatus_messages;
	p_xmachine = &current_node->agents;
		
  initializePopulation();
	current_xmachine = * p_xmachine;
	setFixOrders();
    return 0;
}
 int suite_ClearingHouse_clean(void)
 
 { 
  
    return 0;
}

void testReceiveOrderOnAsset(void)
{ 
   int size;
     CAsset *assets;
     Asset *asset;
     ClearingMechanism *mechanism;
     mechanism =newClearing();
     assets =get_assets();
     asset=lastCAsset(assets);
     receiveOrderOnAsset(mechanism,asset);
     size=sizeCOrder(mechanism->buyOrders);
     CU_ASSERT(size==3);
     size=sizeCOrder(mechanism->sellOrders);
     CU_ASSERT(size==4);
     size=sizeCDouble(mechanism->prices);
     CU_ASSERT(size==6);
}

void testComputeAssetPrice(void)
{  int quantity;
 double price;
 CAsset *assets;
  Asset *asset;
  ClearingMechanism *mechanism;
  mechanism =newClearing();
 assets =get_assets();
 asset=lastCAsset(assets);
 receiveOrderOnAsset(mechanism,asset);
 computeAssetPrice(mechanism,asset);
 quantity=mechanism->quantity;
 price=mechanism->lastPrice;
 CU_ASSERT(price==49);
 CU_ASSERT(quantity==446);
}
