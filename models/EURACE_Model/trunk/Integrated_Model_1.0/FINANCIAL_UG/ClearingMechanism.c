
#include "my_library_header.h"


double formedPrice(ClearingMechanism *clearm)
{
       return clearm->lastPrice;
}
void setClearingMechanism(ClearingMechanism *clearm, double lastprice)
{ 
 clearm->lastPrice=lastprice;
}

void addBuyOrder(ClearingMechanism *aClearing , Order *anOrder)
{  
     addOrder(&aClearing->buyOrders,anOrder);
     add_double(&aClearing->prices,anOrder->price);
}

void addSellOrder(ClearingMechanism *aClearing,Order *anOrder)
{    setAsSellOrder(anOrder);
     addOrder(&(aClearing->sellOrders),anOrder);
     add_double(&(aClearing->prices),anOrder->price);
}
Order_array *buyOrders(ClearingMechanism *clear)
{return &(clear->buyOrders);}

Order_array *sellOrders(ClearingMechanism *clear)
{return &(clear->sellOrders);}

void sortOrders(ClearingMechanism *clear)
{ int size;
     size=sizeCOrder(&clear->buyOrders);
     if(size>1)qSortCOrder(&clear->buyOrders,0,size-1);
     size=sizeCOrder(&clear->sellOrders);
     if(size>1)qSortCOrder(&clear->sellOrders,0,size-1);
     size=sizeCDouble(&clear->prices);
     qSort_double_array(&clear->prices,0,size-1);
}
int aggregateDemand(ClearingMechanism *aClearing,double aPriceValue ,int *i, double start_value)
	{
                                      
                                      
    int total,size,found;
    
	total = start_value;
	Order_array *aux;
	Order *each;
	aux=buyOrders(aClearing);
        size=sizeCOrder(aux);
        found=1;
    while((*i<size)&&(found))
	 {                       
              each=&(aux->array[*i]);
              if(each->price >= aPriceValue) 
              {
               total = total + each->quantity; 
                 printf("%d %f %d\n",total,aPriceValue,*i);
               *i=*i+1;
              }
              else found=0;
             
	   
         }
     return total;
}

int aggregateSupply(ClearingMechanism *aClearing,double aPriceValue ,int *i, double start_value)
	{
                                      
                                      
    int total,size,found;
    
	total = start_value;
	Order_array *aux;
	Order *each;
	aux=sellOrders(aClearing);
        size=sizeCOrder(aux);
        found=1;
    while((*i<size)&&(found))
	 {                       
              each=&(aux->array[*i]);
              if(each->price <= aPriceValue) 
              {
               total = total + each->quantity; 
                          printf("%d %f %d\n",total,aPriceValue,*i);
               *i++;
              }
              else found=0;
             
	   
         }
     return total;
}




 double newPrice(ClearingMechanism *aClearing)
 {
      double price;
      double formerprice;
      int i,size,cond,position_demand,position_supply;
      int demand,supply,Qcross,Qtrans,balance,bestbalance;
      double_array *sortedPrices;
      Order_array *sell_orders;
      Order_array *buy_orders;
      sortedPrices=&aClearing->prices;
      sell_orders=sellOrders(aClearing);
      buy_orders=buyOrders(aClearing);
      cond=1;
    if(isEmptyCOrder(buy_orders)) 
     { formerprice=0.9*(aClearing->lastPrice);
       cond=0;
     }
  else if(isEmptyCOrder(sell_orders)) 
     { formerprice=1.1*(aClearing->lastPrice);
       cond=0;
     }
    
    if(cond)
    {     bestbalance=10000000;
          position_demand=0;
          position_supply=0;
          supply=0;
          demand=0;
	  size=sizeCDouble(sortedPrices);
	  Qcross=0;
	  formerprice=aClearing->lastPrice;
	  for(i=0;i<size;i++)
	  {
	                price = elementAtCDouble(sortedPrices,i);
			demand = aggregateDemand(aClearing,price,&position_demand,demand);
			supply = aggregateSupply(aClearing,price,&position_supply,supply);
			Qtrans = min(supply,demand);
			balance=abs(supply-demand);
		     if(Qcross<Qtrans) 
                          {Qcross=Qtrans;
                           formerprice=price;
                          }
                     if(Qtrans==Qcross) 
			{ if(bestbalance>balance) 
			    {formerprice=price;
			     bestbalance=balance;
                            }
                        }
      } 
      
      }
    printf("former price %f",formerprice);
     return formerprice;
}                 
void ordersMacthing(Order_array *coll, double price,int type)
{ 
       int size,i;
       Order *ord; 
   Order_array aux;
  size=sizeCOrder(coll);
  init_Order_array(&aux);
  for(i=0;i<size;i++)
   {ord=elementAtCOrder(coll,i);
    if(type==1)
    if(ord->price>=price) addOrder(&aux,ord);
    
    if(type==-1)
     if(ord->price<=price) addOrder(&aux,ord);
     
   }

  //copy_Order_array(&aux,coll);
  //free_Order_array(&aux);
 free(coll->array);
   coll->array=aux.array;
   coll->total_size=aux.total_size;
   coll->size=aux.size;
}
/*void rationing(Order_array *coll,int quantity )
{ 
    int balance,max,index;
    Order *ord; 
    max=sizeCOrder(coll);
   // printf("sin qui ci siamo %d\n",max);
    balance=quantity;
  while(balance>0)
  { index=nextMax(max);
//  printf("sin qui ci siamo %d",index);
    ord=elementAtCOrder(coll,index);
    if(ord->quantity>0) {ord->quantity--;balance--;}
 
  }
  
  removeZeroOrders(coll);
}*/

void rationing(Order_array *coll,int quantity )
{ 
    int balance,max,index,i;
    Order *ord; 
    max=sizeCOrder(coll);
   // printf("sin qui ci siamo %d\n",max);
    balance=quantity;
    randomize(coll,0,max-1);
  i=0;
  while(balance>0)
  { index=i%max;
//  printf("sin qui ci siamo %d",index);
    ord=elementAtCOrder(coll,index);
    if(ord->quantity>0) {ord->quantity--;balance--;}
    i++;
 
  }
  
  removeZeroOrders(coll);
}
void removeZeroOrders(Order_array *coll)
{ 
       int size,i;
       Order *ord; 
       Order_array *aux;
       Order_array temp;
       size=sizeCOrder(coll);
       aux=&temp;
       init_Order_array(aux);
      for(i=0;i<size;i++)
       {
         ord=elementAtCOrder(coll,i);
         if(ord->quantity>0) addOrder(aux,ord);
        }
   //copy_Order_array(aux,coll);
   //free_Order_array(aux);
 free(coll->array);
   coll->array=aux->array;
   coll->total_size=aux->total_size;
   coll->size=aux->size;
}
  
	  
void runClearing(ClearingMechanism *aClearing)
{   double price;
    int demand,supply,i,j;
    int balance;
    Order_array *buyorders;
    Order_array *sellorders;
    buyorders=buyOrders(aClearing);
    sellorders=sellOrders(aClearing);
    sortOrders(aClearing);
    price=newPrice(aClearing);

    aClearing->lastPrice=price;
    i=0;
    j=0;
    demand=aggregateDemand(aClearing,price,&i,0);
    supply=aggregateSupply(aClearing,price,&j,0);
    
    if (PRINT_DEBUG_AFM)
    printf("prima di bilanciare  supply %d demand %d\n",supply,demand);
    
    aClearing->quantity=min(supply,demand);
    ordersMacthing(buyorders, price,1);
    ordersMacthing(sellorders, price,-1);
    balance=abs(supply-demand);
    if(supply>demand) rationing(sellorders, balance);
    if(supply<demand) rationing(buyorders, balance);
    
    if (PRINT_DEBUG_AFM)  
    printf("sin qui ci siamo %d\n",balance);
    i=0;
    j=0;
    demand=aggregateDemand(aClearing,price,&i,0);
    supply=aggregateSupply(aClearing,price,&j,0);
   
   if (PRINT_DEBUG_AFM)
     printf("former price %f supply %d demand %d\n",price,supply,demand);
}
   
void emptyClearing(ClearingMechanism *aClearing)
{
      reset_Order_array(&aClearing->sellOrders);
      reset_Order_array(&aClearing->buyOrders);
      reset_double_array(&aClearing->prices);
}

