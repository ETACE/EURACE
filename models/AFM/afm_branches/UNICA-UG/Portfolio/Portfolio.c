#include "Portfolio.h"



Portfolio *newPortfolio()
{
      Portfolio *temp;
      temp=malloc(sizeof(Portfolio));
      return temp;
}

void setBankAccount(Portfolio *ptfolio, double cash)
{ 
     ptfolio->bankAccount=cash;
}

void initializePortfolio(Portfolio *port, CAsset *assets)
{  
int i;
   Asset *currentAsset;
  port->bankAccount=traderStartingCash;
  for(i=1;i<sizeCAsset(assets);i++)
  {currentAsset=elementAtCAsset(assets,i);
   setAsset(currentAsset,i,initialPrice,assetStartingQuantity);
  }
}


Portfolio *expectedPortfolio(Portfolio *port, Belief *belief)
{ Portfolio *answer;
  answer =newPortfolio();
  return answer; 
}

 void executeOrder(Portfolio *portfolio,Order *anOrder,CAsset *assets,COrder *pending)
 {     double cash;
       int assetId;
       int quantity;
       int size;
       int index;
       Order *order;
       Asset *currentAsset;
       quantity=anOrder->quantity;
       assetId=anOrder->assetId;
       cash=(anOrder->price)*(anOrder->quantity);
       portfolio->bankAccount=portfolio->bankAccount-cash;
       size=sizeCAsset(assets);
       currentAsset=elementAtCAsset(assets,assetId);
       currentAsset->quantity=currentAsset->quantity+quantity;
       size=sizeCOrder(pending);
       index=findCOrder(pending,assetId);
                       if(index>-1)
                       { order=elementAtCOrder(pending,index);
                         order->quantity=order->quantity-quantity;
                        }
       else  {printf("assetId =%d size= %d",assetId,size);getchar();}
       
    
}

double wealth(Portfolio *port, CAsset *assetsowned)
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
  wea=wea+port->bankAccount;
return wea;
}

int totalassets(CAsset *assetsowned)
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
