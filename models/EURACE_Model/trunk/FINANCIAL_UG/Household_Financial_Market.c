#include "my_library_header.h"
#include "../Household_agent_header.h"

//extern Random rnd;

//utility functions

int sendOrders()
{   Order_array *orders;
    Order *ord;
    int i;
    
    orders=get_pendingOrders();
    //printf(" size = %d\n",sizeCOrder(orders));
    for(i=0;i<sizeCOrder(orders);i++)
    {
     ord=elementAtCOrder(orders,i);
     //printf("price=%f\n",ord->price);
     add_order_message(ord->issuer,ord->assetId, ord->price, ord->quantity);
    }
     return 0;

}

/*CDouble *assetUtilitiesToDesiredWeights()//assetUtilities);
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
}  */
void computeUtilities(Belief_array *beliefs, double_array *assetUtilities)
{
  Belief *belief;
  int i;
  double utility;
  int size;
  size=beliefs->size;
  reset_double_array(assetUtilities);
  for(i=0;i<size;i++)
     {
     belief=&(beliefs->array[i]);

     utility=belief->utility;
    // printf("%d\n",utility);
    // utility= next(rnd);//da rimuovere
     add_double(assetUtilities,utility);//da rivedere questo algoritmo
     }
}
void assetUtilitiesToWeights(double_array *assetWeights,double_array *assetUtilities,double bankrate)
{
      double minimo;
      int size,i;
      double somma;

      reset_double_array(assetWeights);
      
      minimo=lessthan(assetUtilities);
      size=sizeCDouble(assetUtilities);
 //printf("size ====%d\n",size);
      somma=0;
      for(i=0;i<size;i++)
         { if(minimo<0) add_double(assetWeights,assetUtilities->array[i]-minimo);
           else add_double(assetWeights,assetUtilities->array[i]);
           somma=somma+assetWeights->array[i];

         }

     if(minimo<0)  { somma=somma+bankrate-minimo;
                    add_double(assetWeights,bankrate-minimo);
                   }
              else { somma=somma+bankrate;
                     add_double(assetWeights,bankrate);
                   }
 //printf("size pesi =====%d\n",assetWeights->size);
    divide(assetWeights,somma);
}
/*void assetUtilitiesToWeights(double_array *assetWeights,double_array *assetUtilities,double bankrate)
{
      double elem;
      int size,i;
      double somma;

      reset_double_array(assetWeights);
      size=sizeCDouble(assetUtilities);
      somma=0;
      for(i=0;i<size;i++)
         { elem=elementAtCDouble(assetUtilities,i);
           if(elem>0) {somma=somma+elem;

                       add_double(assetWeights,elem);
                      }
           else add_double(assetWeights,0);
           
         }

      somma=somma+bankrate;
      add_double(assetWeights,bankrate);
                   
    divide(assetWeights,somma);
}
        
/*void assetUtilitiesToWeights(double_array *assetWeights,double_array *assetUtilities,double bankrate)
{ 
  int i;
  double weight;
  double sum;
  sum=0;
  reset_double_array(assetWeights);
   for(i=0;i<(3);i++)
   {
     weight=next(rnd);
     sum=sum+weight;
     add_double(assetWeights,weight);
   }
  divide(assetWeights,sum);
 return ;
}  */
int  Household_select_strategy()
  { double bankrate;
    Order_array *pending;
    Asset_array *assetsowned;
    Belief_array *beliefs;
    double_array *assetWeights;
    double_array *assetUtilities;

      
    bankrate=0.0001;
    assetsowned=get_assetsowned();
    pending=get_pendingOrders();
    assetWeights=get_assetWeights();
    assetUtilities=get_assetUtilities();
    beliefs=get_beliefs();
    if (next()<0.1)  
    {  
     assets_beliefs_formation();
   
    computeUtilities(beliefs,assetUtilities);
     //printf("\n");
    // print_double_array(assetUtilities);
     assetUtilitiesToWeights(assetWeights,assetUtilities,bankrate);
   //printf("\n");
   // print_double_array(assetWeights);
    // printf("size pesi =====%d",assetWeights->size);
     generatePendingOrders(assetsowned,pending,beliefs,&PAYMENT_ACCOUNT);

    } 
    sendOrders();
//printf("ci sono%d\n",ID);
    return 0;
  }
   
int Household_update_its_portfolio()
{ int i,issuer;
  Asset_array *assets;
  Order_array *pendingOrders;
  m_order_status *info;
  Order ord;
  Order *currentOrder;

  currentOrder=&ord;
  pendingOrders=get_pendingOrders();
  assets=get_assetsowned();
  issuer=get_id();
  info=get_first_order_status_message();
  i=0;
  while(info)
  { if(info->trader_id==issuer) 
      { i++;
         //printf("numero di execuzione =%d\n",info->assetId);
       setOrder(currentOrder,info->price,info->quantity,info->asset_id,info->trader_id);
       if(sizeCOrder(pendingOrders)>0)executeOrder(&PAYMENT_ACCOUNT,currentOrder,assets,pendingOrders); 
       }

     info=get_next_order_status_message(info);   
  }
 // if(i==2) printf("numero di execuzione =%d\n",i);
  return 0;
}

int distribuite(double cash, double totalwealth)
{
    double payment_account;
    double csh;
    double wealth;
    wealth=get_wealth();
    payment_account=get_payment_account();
    csh=payment_account+(cash*wealth)/totalwealth;
    set_payment_account(csh);
    return 0;
}


/* it compute a limitOrder on an Asset  anAsset contained into its Portfolio , */
Order *computeLimitOrder( Asset *anAsset, double weight, double resource,Belief *belief)
{
      double limitPrice,lastprice;
      int quantity,deltaquantity; 
      int assetId;
      int trader_id;
      double aux;
      Order *order;
      trader_id=get_id();
      order =newOrder();
      quantity=anAsset->quantity;
      assetId=anAsset->id;
      if(assetId!=belief->asset_id) printf("------------errore----------\n");
      lastprice=belief->last_price;
      anAsset->lastPrice=belief->last_price;
      aux=stockExpectedPriceReturns(belief);
     // printf("aux========%f\n",aux);
      limitPrice=lastprice*(1+aux); 
//printf("expeceted=%f\n",aux);
//printf("last price=%f\n",lastprice);
//printf("limitprice=%f\n",limitPrice);
      deltaquantity=(int)(weight*resource/(limitPrice))-quantity;
//printf("quantity=%d\n",deltaquantity);
      //if(deltaquantity<0) deltaquantity=deltaquantity*1.1;
      //else deltaquantity=deltaquantity*0.9;  
      setOrder(order,limitPrice,deltaquantity,assetId,trader_id);
      return order;
}

void generatePendingOrders(Asset_array *assetsowned,Order_array *pending, Belief_array *beliefs,double *payment_account)
{ int size,i;
  int index;
  Order *ord;
  double resource;
  double weight;
  Asset *asset;
  Belief *belief;

  double_array *weights;
  resource=wealth(*payment_account-CONSUMPTION_BUDGET,assetsowned);
  set_wealth(resource);
  size=beliefs->size;
  reset_Order_array(pending);
  weights=get_assetWeights();
  //printf("size=%d\n",size);
  for(i=0;i<size;i++)
  { 
    belief=&(beliefs->array[i]);
    index=findCAsset(assetsowned,belief->asset_id);

    if(index>=0) asset=elementAtCAsset(assetsowned,index);
    else 
         { index=assetsowned->size;
           add_Asset(assetsowned, belief->asset_id,0,belief->last_price);
           asset=elementAtCAsset(assetsowned,index);
         }
    weight=elementAtCDouble(weights,i);
    ord=computeLimitOrder(asset, weight,resource,belief);
    if((ord->quantity!=0)&&(ord->price>0)) addOrder(pending,ord);
    
  }
   
   
//}
}
int assets_beliefs_formation()
{ 
  Stock *stock;
  int i;
  m_info_firm *cinfo_stock; 
  Belief *belief;
  Belief_array *beliefs;
  double dividend, earning_payout,earnings,equity;
  cinfo_stock=get_first_info_firm_message();
  beliefs=get_beliefs();
  reset_Belief_array(beliefs);
  i=0;
  while( cinfo_stock)
    {  
     
     stock=&(cinfo_stock->stock);
     dividend=cinfo_stock->dividend;
     earning_payout=cinfo_stock->earnings_payout;
     earnings=cinfo_stock->earnings;
     equity=cinfo_stock->equity;
     add_Belief(beliefs,stock->id, 0, 0, 0,0, 0,0, 0,0);
     belief=&(beliefs->array[i]); 

     firmBeliefFormation(belief,stock,CURRENTDAY,FORWARDWINDOW,dividend,earnings,earning_payout);

     stockBeliefFormation(belief,stock,BACKWARDWINDOW,FORWARDWINDOW, RANDOMWEIGHT,FUNDAMENTALWEIGHT,CHARTISTWEIGHT, BINS,CURRENTDAY,equity,LOSSAVERSION);
    
     cinfo_stock= get_next_info_firm_message(cinfo_stock);
     i++;
    }
return 0;
}
/*int  Household_receive_info_asset_to_eurostat()
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
}*/

int totalassetsowned()
  { Asset_array *assets;
    assets =get_assetsowned();
    return totalassets(assets);
  }

                      
//int Household_receive_info_asset_from_firm(){return 0;}
int Household_receive_info_interest_from_bank(){return 0;}
