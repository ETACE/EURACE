#include "../Clearinghouse_agent_header.h"
#include "my_library_header.h"

void receiveOrderOnAsset(ClearingMechanism *mechanism, Asset *anAsset)
{    Order *pord;
     Order ord;
     pord=&ord;
     int id; 
     int issuer;
     int quantity;
     double limit_price;
     if (PRINT_DEBUG_AFM)
        {
        printf("\n Orders sent to clearing house. Asset: %d\n",anAsset->id);
        }
     START_ORDER_MESSAGE_LOOP                        
       id=order_message->asset_id;
       if(anAsset->id==id)
        {
          quantity=order_message->quantity;
          issuer=order_message->trader_id;
          limit_price=order_message->limit_price;
          setOrder(pord,limit_price,quantity,id,issuer);
      
          //if (anAsset->id==24)
//          {
//          printf("\t quantity: %d limit Price: %f trader: %d\n",quantity,limit_price,issuer);
//          }
              
          if (PRINT_DEBUG_AFM)
          {
          printf("\t quantity: %d limit Price: %f trader: %d\n",quantity,limit_price,issuer);
          }
          
       //printf("id %d price %f quantity %d\n",id,limit_price,quantity);
           if(isBuyOrder(pord)) addBuyOrder(mechanism,pord);
           if(isSellOrder(pord))addSellOrder(mechanism,pord); 
     }
   
     FINISH_ORDER_MESSAGE_LOOP
}



void computeAssetPrice(ClearingMechanism *mechanism, Asset *anAsset)
  {  double price;
     int quantity;
      // printf("computed asset price id ===%d\n",anAsset->id);
     setClearingMechanism(mechanism,lastPrice(anAsset));
     runClearing(mechanism);
     quantity=mechanism->quantity;
     price=mechanism->lastPrice;
     addPrice(anAsset,price);
     addVolume(anAsset,quantity);
     
//      if (anAsset->id==24)
//        {
//        printf("\t Clearing of asset: %d volume: %d price: %f \n",anAsset->id,quantity,price);
//        //getchar();
//        }
        
     if (PRINT_DEBUG_AFM)
        {
        printf("\t Clearing of asset: %d volume: %d price: %f \n",anAsset->id,quantity,price);
        getchar();
        }
     
     //sendOrderStatus(mechanism);
     
   }

void sendOrderStatus(ClearingMechanism *clearm)
{ int i,size;
  Order_array *orders;
  Order *ord;
  double fprice;
  orders=buyOrders(clearm);
  size=sizeCOrder(orders);
  fprice=formedPrice(clearm);
  for(i=0;i<size;i++)
   {
    ord=elementAtCOrder(orders,i);
    add_order_status_message(ord->issuer,ord->assetId,fprice,ord->quantity);
    //printf(" issuer = %d\n",ord->issuer);
   }
  orders=sellOrders(clearm);
  size=sizeCOrder(orders);
  for(i=0;i<size;i++)
   {
    ord=elementAtCOrder(orders,i);
    add_order_status_message(ord->issuer,ord->assetId,fprice,-(ord->quantity));
      // printf(" --issuer = %d\n",ord->issuer);
   }
   
}

int ClearingHouse_receive_orders_and_run()
{ int size,i;
  ClearingMechanism *mechanism;
  //mechanism=newClearing();
  mechanism=&CLEARINGMECHANISM;
  Asset_array *assets;
  Asset *asset;
  assets=get_assets();
  size=sizeCAsset(assets);
 
  for(i=0;i<size;i++)
  {
   asset=elementAtCAsset(assets,i);
   emptyClearing(mechanism);
   receiveOrderOnAsset(mechanism, asset);

   computeAssetPrice(mechanism, asset);
   sendOrderStatus(mechanism);
      
  }
  emptyClearing(mechanism);
  //printf("sono qui---");
  return 0;
}


int ClearingHouse_send_asset_information()
 { Asset_array *assets;
   Asset *asset;
   int size,i;
   double price;
   assets =get_assets();
   size=sizeCAsset(assets);
     //printf("numero di asset aggiornati= %d\n",size);
   for(i=0;i<size;i++)
   {
   asset=elementAtCAsset(assets,i);
   price=lastPrice(asset);
   add_infoAssetCH_message(asset->id,price,asset->quantity);

  }
  return 0;
}
int ClearingHouse_receive_info()
   {
    Asset_array *assets;
    assets =get_assets();
    reset_Asset_array(assets);
    ClearingHouse_receive_info_stock(assets);
    ClearingHouse_receive_info_bond(assets);
 return 0;
   }
void ClearingHouse_receive_info_stock(Asset_array *assets)
{  
   m_info_firm *cinfo_stock; 
   Stock *stock;
 
   cinfo_stock=get_first_info_firm_message();
 
  while( cinfo_stock)
    {  
     stock= &(cinfo_stock->stock);
     add_Asset(assets, stock->id,stock-> nrOutStandingShares, lastPriceStock(stock));
    
     cinfo_stock= get_next_info_firm_message(cinfo_stock);
  
    }

}
void ClearingHouse_receive_info_bond(Asset_array *assets)
{  
   m_info_bond *cinfo_bond; 
   Bond *bond;
 
   cinfo_bond=get_first_info_bond_message();
  
  while( cinfo_bond)
    {  
     bond= &(cinfo_bond->bond);
     add_Asset(assets, bond->id,bond-> nr_outstanding, lastPriceBond(bond));
    
     cinfo_bond= get_next_info_bond_message(cinfo_bond);
  
    }
 
}
