#include "my_library_header.h"




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
  {  
     int i;
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturnsAt(stock,i);
  }



void historicalReturnsStock(Stock *stock, double *vect, int backwardWindow,double forwardWindow)
  {  
     int index,i;
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
     if(randomWeight!=0) r=backreturnsAt(stock,i)*factor+value+rndvect[i]*randomWeight;
      else r=backreturnsAt(stock,i)*factor+value; 
     if (r<0) utility=utility+r*lossaversion;
       else     utility=utility+r;
    }
  return utility/backwardWindow;
}

