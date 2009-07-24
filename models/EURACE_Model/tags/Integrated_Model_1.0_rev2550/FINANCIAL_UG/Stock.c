#include "my_library_header.h"


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
void initializeStock(Stock *aStock,int id,double price,int nr_outstanding)
{ int i; 
  double aux;
  double prec;
  aStock->id=id;
  aStock->index=0;
 aux=price;
aStock->nrOutStandingShares=nr_outstanding;
 for(i=0;i<MAXPRICES;i++)
     { prec=aux;
      aux=prec+0.01*gauss(0,0.1);
      addPriceStock(aStock,aux);
     }
}
void setStock(Stock *aStock, int id, double price, int nrOutStandingShares)
{
     aStock->id=id;
     addPriceStock(aStock,price);
     aStock->nrOutStandingShares=nrOutStandingShares;
}
void addPriceStock(Stock *stock, double price)
{    int precindex;
     precindex=stock->index;
     if(stock->index==MAXPRICES-1) stock->index=0;
                                    
     else stock->index++;
     stock->prices[stock->index]=price;
     stock->returns[stock->index]= (price-stock->prices[precindex])/price;
  
}

int issuerStock(Stock *aStock)
{
  return aStock->id;
} 

/*void addVolume(Stock *aStock, double volume)
{
    anStock->quantity=volume;
}*/

double  backreturnsAt(Stock *stock,int ind)
    { int index;
      index=stock->index-ind;
      if(index<0) index=MAXRETURNS+index;
        
       return stock->returns[index];
        
   }
double lastPriceStock(Stock *aStock)
{       
        double answer;
        answer=aStock->prices[aStock->index];
        return answer;
}
double expectedReturnStock(Stock *stock,int backwardWindow)
       { double mean;
         int i;
         mean=0;
         for(i=0;i<backwardWindow;i++)
             mean=mean+backreturnsAt(stock,i);
         mean=mean/(backwardWindow);
         return mean;
       }

     
double volatilityStock(Stock *stock,int backwardWindow)
     { double expectedreturn;
       double volatility;
       double aux;
       int i;
       volatility=0;
 
       expectedreturn=expectedReturnStock(stock,backwardWindow);
        for(i=0;i<backwardWindow;i++)
            {  
               aux=(backreturnsAt(stock,i)-expectedreturn);
               volatility=volatility+(aux*aux);
            }
  
      volatility=sqrt(volatility/backwardWindow);
      return volatility;
     }


void totalReturnsStock(Stock *stock, double *vect, int backwardWindow,double factor, double value)
  {  int i;
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturnsAt(stock,i)*factor+value;
  }
void priceReturnsStock(Stock *stock, double *vect, int backwardWindow)
  {  int i;
    
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturnsAt(stock,i);
  }



void historicalReturnsStock(Stock *stock, double *vect, int backwardWindow,double forwardWindow)
  {  int index,i;
     double *returns;
     index=stock->index;
     returns=stock->returns;
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturnsAt(stock,i)*forwardWindow;
  }

double computeStockUtilityFunction(Stock *stock,int backwardWindow, double factor, double value, double lossaversion, double *rndvect,double randomWeight)
{ 
  int i;
  double utility;
  double r;
  utility=0;
  for(i=0;i<backwardWindow;i++)
    { 
     r=backreturnsAt(stock,i)*factor+value+rndvect[i]*randomWeight;
     //printf("\n r %f rndvect %f value %f randomWeight %f",r, rndvect[i], value, randomWeight);
     //getchar();
     if (r<0) utility=utility+r*lossaversion;
     else     utility=utility+r;
    }
    //printf ("\n utilitystock %f", utility);
  //if(utility==NAN) printf("----------%f",rndvect[i]*randomWeight);
  return utility/backwardWindow;
}
/*aswer the variance of the prices with a time window.
 if the window is less than 2 the answer is zero because the array of the returns has a size equal to 1

*/     

