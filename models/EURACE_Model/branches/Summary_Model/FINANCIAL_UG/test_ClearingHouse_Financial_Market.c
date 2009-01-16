
#include "../Suites.h"
#include "../header.h"
#include "../Clearinghouse_agent_header.h"





static void setFixOrders(void)
{ Order *ord;
  Order pord;
  ord=&pord;
  setOrder(ord,55,200,1,1);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,40.3,-300,1,2);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,49.5,123,1,3);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,49,-150,1,4);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,60,123,1,5);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,55,-22,1,6);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity);
  setOrder(ord,60,-150,1,7);
       add_order_message(ord->issuer,ord->assetId, ord->price,ord->quantity); 
}

 
void test_ClearingHouse_receive_info(void)
  {    int id; double earnings;double dividend;double earnings_payout; double equity; Stock stock;Bond bond;
       double price; int nr_outstanding; double face_value; double nominal_yield;
       int size;

     

       id=1;
       earnings=1000;
       dividend=1;
       earnings_payout=900;
       equity=100000;
       price=100;
       nr_outstanding=1000;
       setSeed(2345678901.0);
       initializeStock(&stock,id,price,nr_outstanding);
       id=2;
       nr_outstanding=1000;
       face_value=100;
       nominal_yield=0.1;
       initializeBond(&bond,id,  nr_outstanding,face_value,  nominal_yield);

       add_info_firm_message(id, earnings,  dividend, earnings_payout, equity,  stock);
       add_info_bond_message(bond);
       MB_Iterator_Create(b_info_firm, &i_info_firm);
       MB_Iterator_Create(b_info_bond, &i_info_bond);
       ClearingHouse_receive_info();
       size=sizeCDouble(&ASSETS);
       CU_ASSERT(size==2);
       }
void test_ReceiveOrderOnAsset(void)
{ 
   int size;
     Asset_array *assets;
     Asset *asset;
     assets =get_assets();
     asset=lastCAsset(assets);
     setFixOrders();
     MB_Iterator_Create(b_order, &i_order);
     receiveOrderOnAsset(&CLEARINGMECHANISM,asset);
     size=sizeCOrder(&CLEARINGMECHANISM.buyOrders);
     CU_ASSERT(size==3);
     size=sizeCOrder(&CLEARINGMECHANISM.sellOrders);
     CU_ASSERT(size==4);
     size=sizeCDouble(&CLEARINGMECHANISM.prices);
     CU_ASSERT(size==6);
}

void testComputeAssetPrice(void)
{  int quantity;
 double price;
 Asset_array *assets;
  Asset *asset;

 assets =get_assets();
 asset=lastCAsset(assets);
 //setFixOrders();
 //MB_Iterator_Create(b_order, &i_order);

 receiveOrderOnAsset(&CLEARINGMECHANISM,asset);
 computeAssetPrice(&CLEARINGMECHANISM,asset);

 quantity=CLEARINGMECHANISM.quantity;
 price=CLEARINGMECHANISM.lastPrice;
 CU_ASSERT(price==49);
 CU_ASSERT(quantity==446);
}

void test_ClearingHouse_receive_orders_and_run()
{
}
void test_ClearingHouse_send_asset_information()
{
}
