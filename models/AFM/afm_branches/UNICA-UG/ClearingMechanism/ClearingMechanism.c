
#include "ClearingMechanism.h"





Clearing *newClearingMechanism()
{ 
  Clearing *temp;
  temp=malloc(sizeof(Clearing ));
  temp->sellOrders=newCOrder(10000);
  temp->buyOrders=newCOrder(10000);
  temp->prices=newCDouble(10000);
  temp->lastPrice=20;
  temp->quantity=0;
  return temp;
  
}

Clearing *newClearing()
{ 
  return newClearingMechanism();
  
}

double formedPrice(Clearing *clearm)
{
       return clearm->lastPrice;
}
void setClearingMechanism(Clearing *clearm, double lastprice)
{ clearm->lastPrice=lastprice;}

void addBuyOrder(Clearing *aClearing , Order *anOrder)
{  
     addOrder(aClearing->buyOrders,anOrder);
     addIncSetSortDouble(aClearing->prices,anOrder->price);
}

void addSellOrder(Clearing *aClearing,Order *anOrder)
{     setAsSellOrder(anOrder);
     addOrder(aClearing->sellOrders,anOrder);
     addIncSetSortDouble(aClearing->prices,anOrder->price);
}
COrder *buyOrders(Clearing *clear)
{return clear->buyOrders;}

COrder *sellOrders(Clearing *clear)
{return clear->sellOrders;}

void sortOrders(Clearing *clear)
{ int size;
     size=sizeCOrder(clear->buyOrders);
     if(size>1)qSortCOrder(clear->buyOrders,0,size-1);
     size=sizeCOrder(clear->sellOrders);
     if(size>1)qSortCOrderDec(clear->sellOrders,0,size-1);
}
int aggregateDemand(Clearing *aClearing,double aPriceValue )
	{
                                      
                                      
    int total ;
    int i;
	total = 0;
	COrder *aux;
	Order *each;
	aux=aClearing->buyOrders;
    for(i=0;i<sizeCOrder(aux);i++)
	 {                       
       each=aux->array[i];
       if(each->price >= aPriceValue) total = total + each->quantity;
	   
     }
     return total;
}

int aggregateSupply(Clearing *aClearing,double aPriceValue )
	{              
    int total ;
    int i;
	total = 0;
	COrder *aux;
	Order *each;
	aux=aClearing->sellOrders;
    for(i=0;i<sizeCOrder(aux);i++)
	 {                    
       each=aux->array[i];
       if(each->price <= aPriceValue) total = total + each->quantity;
	  
     }
      return total;
}

double computeNewPrice(Clearing *aClearing)
	{ double price;
      double formerPrice;
      double maxBuyPrice,minSellPrice;
      double pointerPrice;
      int index,size;
	  int demand,supply;
	  int cond;
	  Order *ptord;
      COrder *sellOrders;
      COrder  *buyOrders;
      CDouble *sortedPrices;
	
    sellOrders=aClearing->sellOrders;
    buyOrders=aClearing->buyOrders;
    sortedPrices=aClearing->prices;
    cond=1;
    if(isEmptyCOrder(buyOrders)) 
     { formerPrice=0.9*(aClearing->lastPrice);
       cond=0;
     }
  else if(isEmptyCOrder(sellOrders)) 
     { formerPrice=1.1*(aClearing->lastPrice);
       cond=0;
     }
     else{
    // ptord=lastCOrder(buyOrders);
    // maxBuyPrice=ptord->price;
    maxBuyPrice=maxPriceOrder(buyOrders);
     //ptord=lastCOrder(sellOrders);
     //minSellPrice=ptord->price;
    minSellPrice=minPriceOrder(sellOrders);
    if( maxBuyPrice < minSellPrice ){
        formerPrice= aClearing->lastPrice;
        cond=0;
        }
    if(cond)
    {
    formerPrice= firstCDouble(sortedPrices);
	size=sizeCDouble(sortedPrices);
	index=0;
	while(cond&&(index<size))
	{  
	        price = elementAtCDouble(sortedPrices,index);
			demand = aggregateDemand(aClearing, price);
			supply = aggregateSupply(aClearing,price);
			if(demand < supply)
			  {        
                      if(aggregateDemand(aClearing, price-EPS) >= aggregateSupply(aClearing,price-EPS)) 
					   formerPrice=price;
                       cond=0;
              }
              
		    if(	demand ==supply )
				{  if(aggregateDemand(aClearing, price-EPS) > aggregateSupply(aClearing,price-EPS))  
						{ if( index < (size -1))
						   {pointerPrice = elementAtCDouble(sortedPrices,index+1);
                            formerPrice=(price + pointerPrice) / 2;
                            }
						  else formerPrice=price;
					
                        }	
					else formerPrice=(price + formerPrice) / 2;
				
    	         cond=0;
                }
        
		if(cond)  formerPrice = price;
		index++;
        }
        
       if((cond)&&(index==size) )formerPrice = lastCDouble(sortedPrices);
                                  
       }
}
 return formerPrice;
}

 double newPrice(Clearing *aClearing)
 {
      double price;
      double formerprice;
      int i,size,cond;
	  int demand,supply,Qcross,Qtrans,balance,bestbalance;
	  CDouble *sortedPrices;
      COrder *sellOrders;
      COrder  *buyOrders;
	  sortedPrices=aClearing->prices;
	  sellOrders=aClearing->sellOrders;
      buyOrders=aClearing->buyOrders;
      cond=1;
    if(isEmptyCOrder(buyOrders)) 
     { formerprice=0.9*(aClearing->lastPrice);
       cond=0;
     }
  else if(isEmptyCOrder(sellOrders)) 
     { formerprice=1.1*(aClearing->lastPrice);
       cond=0;
     }
    
    if(cond)
    {
	  size=sizeCDouble(sortedPrices);
	  Qcross=0;
	  formerprice=aClearing->lastPrice;
	  for(i=0;i<size;i++)
	  {
	        price = elementAtCDouble(sortedPrices,i);
			demand = aggregateDemand(aClearing, price);
			supply = aggregateSupply(aClearing,price);
			Qtrans = min(supply,demand);
			balance=abs(supply-demand);
			if(Qcross<Qtrans) 
            {Qcross=Qtrans;
            formerprice=price;
            }
      }  bestbalance=10000000;
      for(i=0;i<size;i++)
        { 
	        price = elementAtCDouble(sortedPrices,i);
            demand = aggregateDemand(aClearing, price);
			supply = aggregateSupply(aClearing,price);
			Qtrans = min(supply,demand);
			balance=abs(supply-demand);
			if(Qtrans==Qcross) 
			{ if(balance<bestbalance) 
			    {formerprice=price;
			     bestbalance=balance;
                }
             }
         }
      }
     return formerprice;
}                 
	  
void runClearing(Clearing *aClearing)
{   double price;
    int demand,supply;
    int balance;
    Random *rnd;
    rnd=newRandom();
    COrder *buyorders;
    COrder *sellorders;
    sortOrders(aClearing);
    price=newPrice(aClearing);
    aClearing->lastPrice=price;
    demand=aggregateDemand(aClearing,price);
    supply=aggregateSupply(aClearing,price);
    aClearing->quantity=min(supply,demand);

    ordersMacthing(aClearing->buyOrders, price,1);
    ordersMacthing(aClearing->sellOrders, price,-1);
        buyorders=aClearing->buyOrders;
    sellorders=aClearing->sellOrders;
    freeRandom(rnd);
    balance=abs(supply-demand);
    printf("sin qui ci siamo %d\n",balance);
    if(supply>demand) rationing(sellorders, balance , rnd);
    if(supply<demand) rationing(buyorders, balance , rnd);
    
   printf("former price %f supply %d demand %d\n",price,supply,demand);
  demand=aggregateDemand(aClearing,price);
    supply=aggregateSupply(aClearing,price);
    printf("former price %f supply %d demand %d\n",price,supply,demand);
}
   
void emptyClearing(Clearing *aClearing)
{
      emptyCOrder(aClearing->sellOrders);
      emptyCOrder(aClearing->buyOrders);
      emptyCDouble(aClearing->prices);
}
void freeClearingMechanism(Clearing *clearm)
{ freeCOrder(clearm->buyOrders);
  freeCDouble(clearm->prices);
  freeCOrder(clearm->sellOrders);
}

void ordersMacthing(COrder *coll, double price,int type)
{ 
       int size,i;
       Order *ord; 
  COrder *aux;
  size=sizeCOrder(coll);
  aux=newCOrder(size+1);
  for(i=0;i<size;i++)
   {ord=elementAtCOrder(coll,i);
    if(type==1)
    {if(ord->price>=price) addCOrder(aux,ord);
     else freeOrder(ord);}
    if(type==-1)
     {if(ord->price<=price) addCOrder(aux,ord);
      else freeOrder(ord);}
   }
   free(coll->array);
   coll->array=aux->array;
   coll->total_size=aux->total_size;
   coll->size=aux->size;
}

void rationing(COrder *coll,int quantity , Random *rnd)
{ int balance,max,index;
    Order *ord; 
    max=sizeCOrder(coll);
   // printf("sin qui ci siamo %d\n",max);
    balance=quantity;
  while(balance>0)
  { index=nextMax(rnd,max);
//  printf("sin qui ci siamo %d",index);
    ord=elementAtCOrder(coll,index);
    if(ord->quantity>0) {ord->quantity--;balance--;}
 
  }
  
  removeZeroOrders(coll);
}

void removeZeroOrders(COrder *coll)
{ 
       int size,i;
       Order *ord; 
  COrder *aux;
  size=sizeCOrder(coll);
  aux=newCOrder(size+1);
  for(i=0;i<size;i++)
   {ord=elementAtCOrder(coll,i);
   if(ord->quantity>0) addOrder(aux,ord);
   else freeOrder(ord);
   }
   free(coll->array);
   coll->array=aux->array;
   coll->total_size=aux->total_size;
   coll->size=aux->size;
  
  
}
