#include "my_library_header.h"

Asset *newAsset()
{
      Asset *temp;
      temp=malloc(sizeof(Asset));
      return temp;
}
void  freeAsset(Asset *anAsset)
{
    free(anAsset);
} 

void setAsset(Asset *anAsset, int issuer, double price, int quantity)
{
     anAsset->id=issuer;
     anAsset->lastPrice=price;
     anAsset->quantity=quantity;
}
void addPrice(Asset *anAsset, double price)
{
    anAsset->lastPrice=price;
}

void setPrice(Asset *anAsset,double price)
{
     anAsset->lastPrice=price;
}
int assetId(Asset *anAsset)
{
return anAsset->id;
} 

void addVolume(Asset *anAsset, double volume)
{
    anAsset->quantity=volume;
}

double lastPrice(Asset *anAsset)
{       
        double answer;
        answer=anAsset->lastPrice;
        return answer;
}
/*answer the variance of the prices with a time window.
 if the window is less than 2 the answer is zero because the array of the returns has a size equal to 1

*/     

