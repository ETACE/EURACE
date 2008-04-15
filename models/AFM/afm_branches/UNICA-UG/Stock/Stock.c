#include "Stock.h"


Stock *newStock()
{
      Stock *temp;
      temp=malloc(sizeof(Stock));

      return temp;

}
void  freeStock(Stock *aStock)
{
    free(aStock);
} 
void initializeStock(Stock *aStock)
{ int i;
  aStock->index=MAXPRICES;
 for(i=0;i<MAXPRICES;i++)
      aStock->prices[i]=0;
}
void setStock(Stock *aStock, int issuer, double price, int quantity)
{
     anStock->issuer=issuer;
     addPriceStock(aStock);
     anStock->quantity=quantity;
}
void addPriceStock(Stock *aStock, double price)
{    int precindex;
     precindex=index;
     if(index==MAXPRICES) index=0;
     else index++;
     aStock->prices[index]=price;
     aStock->returns[index]= price-aStock->prices[precindex];
  
}

int issuerStock(Stock *aStock)
{
  return anStock->issuer;
} 

/*void addVolume(Stock *aStock, double volume)
{
    anStock->quantity=volume;
}*/


double lastPriceStock(Stock *aStock)
{       
        double answer;
        answer=anStock->prices[index];
        return answer;
}
double expectedReturnStock(Stock *aStock,int backwordWindow)
       { double mean;
         double *returns;
         int i;
         mean=0;
         returns=aStock->returns;
         for(i=backwordWindow-1;i>=0;i++)
             mean=mean+returns[i];
         mean=mean/(backwordWindow-1);
         return mean;
       }
double  backreturnsAt(Stock *stock,int ind)
    { int index;
      index=stock->index-ind;
      if(index<0) index=MAXRETURNS+index;
       return stock->returns[index];
   }
     
double volatilityStock(Stock *aStock,int backwordWindow)
     { double expectedreturn;
       double volatility;
       double returns;
       double aux;
       volatility=0;
       returns=aStock->returns;
       expectedreturn=expectedReturnStock(aStock,backwordWindow);
        for(i=backwordWindow-1;i>=0;i++)
            {  aux=(returns[i]-expectedreturn);
               volatility=volatility+aux*aux;
            }
       volatility=sqrt(volatility)/(backwordWindow-1);
      return volatility;
     }
void copyWindowReturn(Stock *stock, double *vect, int backwordWindow)
  {  int index,i;
     double *returns;
     index=stock->index;
     returns=stock->returns;
     for(i=0;i<(backwordWindow-1);i++)
     temp[i]=backreturnsAt(stock,i);
  }
Histogram *frequencyReturns(Stock *stock, int backwordWindow,int bins)
 { double temp[MAXRETURNS];
   Histogram *hist;
   hist=newHistogram();
   copyWindowReturn(stock,temp,backwordWindow);
   histogram(hist,temp,backwordWindow-1,bins);
   return hist;
   
  
 }
     
/*aswer the variance of the prices with a time window.
 if the window is less than 2 the answer is zero because the array of the returns has a size equal to 1

*/     

