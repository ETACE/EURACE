#include "my_library_header.h"




 void executeOrder(double *payment_account,Order *anOrder,Asset_array *assets,Order_array *pending)
 {     
       double cash;
       int assetId;
       int quantity;
       int size;
       int index;
       Order *order;
       Asset *currentAsset;
       quantity=anOrder->quantity;
       assetId=anOrder->assetId;
       cash=(anOrder->price)*(anOrder->quantity);
       *payment_account=*payment_account-cash;
       
       size=sizeCAsset(assets);
       index=findCAsset(assets,assetId);
       currentAsset=elementAtCAsset(assets,index);
       currentAsset->quantity=currentAsset->quantity+quantity;
       size=sizeCOrder(pending);
       index=findCOrder(pending,assetId);
                       if(index>-1)
                       { order=elementAtCOrder(pending,index);
                         order->quantity=order->quantity-quantity;
                        }
                        else  {printf("assetId =%d size= %d",assetId,size);}
       
    
}

double wealth(double payment_account, Asset_array *assetsowned)
{ double wea,price;
  int i;
  int size,quantity;
  Asset *asset;
  size=sizeCAsset(assetsowned);
  wea=0;
  for(i=0; i<size ;i++)
  { asset=elementAtCAsset(assetsowned,i);
     quantity=(asset->quantity);
    price=asset->lastPrice;
    wea=wea+(quantity*price);
  }
  wea=wea+payment_account;
return wea;
}

int totalassets(Asset_array *assetsowned)
{  int quantity,total,i,size;
   Asset *asset;
  size=sizeCAsset(assetsowned);
  total=0;

  for(i=0; i<size ;i++)
  { asset=elementAtCAsset(assetsowned,i);
  quantity=(asset->quantity);
    total=total+quantity;
  }
  return total;
  }
