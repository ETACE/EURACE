#include "ClearingHouse.h"

void receiveOrderOnAsset(Clearing *mechanism, Asset *anAsset)
{    Order *pord;
     Order ord;
     pord=&ord;
     int Id;
     int issuer;
     int quantity;
     xmachine_message_order *currentOrder;
     currentOrder=get_first_order_message();
     while(currentOrder){  
                            
     Id=currentOrder->assetId;
     if(anAsset->issuer==Id)
     {
     quantity=currentOrder->quantity;
     issuer=currentOrder->issuer;
     setOrder(pord,currentOrder->limitPrice,quantity,Id,issuer);
     if(isBuyOrder(pord)) addBuyOrder(mechanism,pord);
     if(isSellOrder(pord))addSellOrder(mechanism,pord); 
     }
     currentOrder=currentOrder->next;
     }
}



void computeAssetPrice(Clearing *mechanism, Asset *anAsset)
  {  double price;
     int quantity;
     setClearingMechanism(mechanism,lastPrice(anAsset));
     runClearing(mechanism);
     quantity=mechanism->quantity;
     price=mechanism->lastPrice;
     addPrice(anAsset,price);
     addVolume(anAsset,quantity);
     //sendOrderStatus(mechanism);
     
   }

void sendOrderStatus(Clearing *clearm)
{ int i,size;
  COrder *orders;
  Order *ord;
  double fprice;
  orders=buyOrders(clearm);
  size=sizeCOrder(orders);
  fprice=formedPrice(clearm);
  for(i=0;i<size;i++)
   {
    ord=elementAtCOrder(orders,i);
    add_orderStatus_message(ord->issuer,ord->assetId,fprice,ord->quantity,message_range, get_posx(),get_posy(),0);
    //printf(" issuer = %d\n",ord->issuer);
   }
  orders=sellOrders(clearm);
  size=sizeCOrder(orders);
  for(i=0;i<size;i++)
   {
    ord=elementAtCOrder(orders,i);
    add_orderStatus_message(ord->issuer,ord->assetId,fprice,-(ord->quantity),message_range, get_posx(),get_posy(),0);
      // printf(" --issuer = %d\n",ord->issuer);
   }
   
}

int receiveOrdersAndRun()
{ int size,i;
  Clearing *mechanism;
  mechanism=newClearing();
  CAsset *assets;
  Asset *asset;
  assets=get_assets();
  size=sizeCAsset(assets);
  //printf("numero di asset---- %d\n",size);
  for(i=0;i<size;i++)
  {asset=elementAtCAsset(assets,i);
   emptyClearing(mechanism);
  //  printf("asset id = %d\n",asset->issuer);
   receiveOrderOnAsset(mechanism, asset);

   computeAssetPrice(mechanism, asset);
   sendOrderStatus(mechanism);
      
  }
  freeClearingMechanism(mechanism);
  printf("sono qui---");
  return 0;
}

int receiveAssetInformation()
 { int i;
 i=0;
   CAsset *assets;
   Asset *asset;
   assets =get_assets();
   resetCAsset(assets);
   xmachine_message_asset *currentAsset;
   currentAsset=get_first_asset_message();
   while(currentAsset){
    i++;                  
   asset=newAsset();
   setAsset(asset,currentAsset->issuer,currentAsset->price,currentAsset->quantity);
   addAtCAsset(assets,asset,asset->issuer);
   currentAsset=currentAsset->next;
  }
  //printf("numero di asset ricevuti= %d\n",i);
  return 0;
}

int sendAssetInformation()
 { CAsset *assets;
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
   add_infoAsset_message(asset->issuer,price,asset->quantity,message_range,get_posx(),get_posy(),0);
  }
  return 0;
}
