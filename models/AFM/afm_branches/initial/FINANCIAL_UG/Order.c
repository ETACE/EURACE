#include "my_library_header.h"


Order * newOrder()
{    
     Order *temp;
     temp= malloc(sizeof(Order));
     
     return temp;
      
}

void setOrder(Order *anOrder, double price, int quantity,int assetId, int issuer)

{
anOrder->issuer=issuer;
anOrder->price=price;
anOrder->quantity=quantity;
anOrder->assetId=assetId;
               
}
     
     
int getOrderQuantity(Order *anOrder)
{  return anOrder->quantity;
}         

void copyOrder(Order *dest ,Order *orig)
{
     dest->issuer=(orig->issuer);
     dest->price=(orig->price);
     dest->quantity=(orig->quantity);
     dest->assetId=orig->assetId;
}

void swapOrder(Order *dest ,Order *orig)
{   Order temp;
    Order *pt;
    pt=&temp;
    copyOrder(pt,dest);
    copyOrder(dest,orig);
    copyOrder(orig,pt);
     
}

int compareOrder(Order *a, Order *b)
{ 
     int result;
     result=(a->price)>(b->price);
    return result;
    
}

int isGreaterOrder(Order *a, Order *b)
{ 
     int result;
     result=(a->price)>(b->price);
    return result;
    
}
int isLessOrder(Order *a, Order *b)
{ 
     int result;
     result=(a->price)<(b->price);
    return result;
    
}

int isEqualOrder(Order *a, Order *b)
{  
    int result;
    result= ((a->price)==(b->price));
    if(result) result=(( a->quantity)==(b->quantity));
    return result;
}


int isBuyOrder(Order *anOrder)
{   int answer;
    answer=anOrder->quantity>0;
    return answer;
}

int isSellOrder(Order *anOrder)
{  int answer;
    answer=anOrder->quantity<0;
    return answer;
    }

int isNullOrder(Order *anOrder)
{  int answer;
    answer=anOrder->quantity==0;
    return answer;
}


void setAsSellOrder(Order *anOrder)
{ if(getOrderQuantity(anOrder)<0) anOrder->quantity=-anOrder->quantity;}

void setAsNullOrder(Order *anOrder)
{ anOrder->quantity=0;}

void freeOrder(Order *ord)
{free(ord);
}

