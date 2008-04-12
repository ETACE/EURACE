#include "Stock.h"


Stock *newStock()
{
      Stock *temp;
      temp=malloc(sizeof(Stock));

      return temp;

}
void  freeStock(Stock *aStock)
{
    free(anStock);
} 

void setStock(Stock *aStock, int issuer, double price, int quantity)
{
     anStock->issuer=issuer;
     anStock->lastPrice=price;
     anStock->quantity=quantity;
}
void addPrice(Stock *aStock, double price)
{
    anStock->lastPrice=price;
}

void setPrice(Stock *aStock,double price)
{
     anStock->lastPrice=price;
}
int assetId(Stock *aStock)
{return anStock->issuer;} 
void addVolume(Stock *aStock, double volume)
{
    anStock->quantity=volume;
}

double lastPrice(Stock *aStock)
{       
        double answer;
        answer=anStock->lastPrice;
        return answer;
}
/*aswer the variance of the prices with a time window.
 if the window is less than 2 the answer is zero because the array of the returns has a size equal to 1

*/     

