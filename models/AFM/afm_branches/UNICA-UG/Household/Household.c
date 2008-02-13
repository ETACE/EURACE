#include "Household.h"


//utility functions


int sendOrders()
{   COrder *orders;
    Order *ord;
    int i;
    
    orders=get_pendingOrders();
    //printf(" size = %d\n",sizeCOrder(orders));
    for(i=0;i<sizeCOrder(orders);i++)
    {
     ord=elementAtCOrder(orders,i);
     //printf("ddd ");
     add_order_message(ord->issuer,ord->assetId, ord->price, ord->quantity,message_range, get_posx(), get_posy(), 0);
    }
     return 0;
}

CDouble *assetUtilitiesToDesiredWeights()//assetUtilities);
{ CDouble *weights;
  int i;
  double weight;
  double sum;
  sum=0;
  weights=newCDouble(maxAssets+1);
   for(i=0;i<(maxAssets+1);i++)
   {
     weight=next(rnd);
     sum=sum+weight;
     addCDouble(weights,weight);
   }
  divide(weights,sum);
 return weights;
}  
  
int selectStrategy()
  { COrder *pending;
    CAsset *assetsowned;
    Belief *belief;
    Portfolio *port;
    port=get_portfolio();
    belief=get_belief();
    assetsowned=get_assetsowned();
    pending=get_pendingOrders();
    
    if (next(rnd)<0.1)  generatePendingOrders(assetsowned,pending,belief,port); 
    sendOrders();
    return 0;
  }
   
int updateTrader()
{ int i;
  int issuer;
  CAsset *assets;
  COrder *pendingOrders;
  Portfolio *portfolio;
  xmachine_message_orderStatus *info;
  Order ord;
  Order *currentOrder;
  currentOrder=&ord;
  pendingOrders=get_pendingOrders();
  assets=get_assetsowned();
  portfolio=get_portfolio();
  issuer=get_id();
  info=get_first_orderStatus_message();
  i=0;
  while(info)
  { if(info->issuer==issuer) 
      { i++;
         //printf("numero di execuzione =%d\n",info->assetId);
       setOrder(currentOrder,info->price,info->quantity,info->assetId,info->issuer);
       if(sizeCOrder(pendingOrders)>0)executeOrder(portfolio,currentOrder,assets,pendingOrders);
       //removeWithId(pendingOrders,info->assetId);
      
       }

     info=get_next_orderStatus_message(info);   
  }
 // if(i==2) printf("numero di execuzione =%d\n",i);
  return 0;
}

int distribuite(double cash, double totalwealth)
{
    Portfolio *ptfolio;
    double csh;
    double wealth;
    wealth=get_wealth();
    ptfolio=get_portfolio();
    csh=ptfolio->bankAccount+(cash*wealth)/totalwealth;
    setBankAccount(ptfolio,csh);
    return 0;
}


/* it compute a limitOrder on an Asset  anAsset contained into its Portfolio , */
Order *computeLimitOrder( Asset *anAsset, double weight, double resource,Belief *belief)
{
      double limitPrice;
      int quantity,deltaquantity;
      int assetId;
      int issuer;
      Order *order;
      issuer=get_id();
      order =newOrder();
      quantity=anAsset->quantity;
      assetId=anAsset->issuer;
      limitPrice=lastPrice(anAsset)*(1+stockExpectedPriceReturns(belief,anAsset));  
      deltaquantity=(int)(weight*resource/(limitPrice))-quantity;
      //if(deltaquantity<0) deltaquantity=deltaquantity*1.1;
      //else deltaquantity=deltaquantity*0.9;
      
      setOrder(order,limitPrice,deltaquantity,assetId,issuer);
      return order;
}

void generatePendingOrders(CAsset *assetsowned,COrder *pending, Belief *belief,Portfolio *port)
{ int size,i;
  Order *ord;
  CDouble *weights;
  double resource;
  double weight;
  Asset *asset;
   resource=wealth(port,assetsowned);
   set_wealth(resource);
  // if(resource>0)
   //{
  weights=assetUtilitiesToDesiredWeights();
  size=sizeCDouble(weights);
  resetCOrder(pending);
 
  assetBeliefFormation(belief, assetsowned,rnd);

  for(i=0;i<size-1;i++)
  { 
    asset=elementAtCAsset(assetsowned,i);
    weight=elementAtCDouble(weights,i);
    ord=computeLimitOrder(asset, weight,resource,belief);
    if(ord->quantity!=0) addCOrder(pending,ord);
    
  }
   
  freeCDouble(weights);
   
//}
}

int receiveAssetInformationHouse()
 { CAsset *assets;
   Asset *asset;
   int assetId;
   assets =get_assetsowned();
   xmachine_message_infoAsset *currentAsset;
   currentAsset=get_first_infoAsset_message();
   while(currentAsset){
                       assetId=currentAsset->issuer;
   if(isPresentCAsset(assets,assetId))
   {
   asset=elementAtCAsset(assets,assetId);
   setPrice(asset,currentAsset->price);}
   currentAsset=currentAsset->next;
  }
  return 0;
}

int totalassetsowned()
  { CAsset *assets;
    assets =get_assetsowned();
    return totalassets(assets);
  }
double cashowned()
{Portfolio *port;
 double answer;
 port=get_portfolio();
 answer=port->bankAccount;
 return answer;
}
                      
