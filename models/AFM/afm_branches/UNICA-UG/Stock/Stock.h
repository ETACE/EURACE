#ifndef STOCK_INCL
#define STOCK_INCL
#include "Double.h"
#include "math.h"
#include "Histogram.h"

#ifndef Stock_dty
#define Stock_dty
#define MAXPRICES 1000
#define MAXRETURNS MAXPRICES-1

typedef struct Stock Stock;
struct Stock 

{
      int issuer;
      int quantity;
      double dividend_yield;
      double prices[MAXPRICES];
      double returns[MAXRETURNS];
      int index;
      double earningExp;
      double earningPayoutExp;
      double nrOutStandingShares;
      double equity;
    
      
};

#endif

Stock *newStock();
void  freeStock(Stock *aStock);

void initializeStock(Stock *aStock);

void setStock(Stock *aStock, int issuer, double price, int quantity);

void addPriceStock(Stock *aStock, double price);


int issuerStock(Stock *aStock);


/*void addVolume(Stock *aStock, double volume)
{
    anStock->quantity=volume;
}*/


double lastPriceStock(Stock *aStock);

double expectedReturnStock(Stock *aStock,int backwordWindow);
  
double  backreturnsAt(Stock *stock,int ind);
  
     
double volatilityStock(Stock *aStock,int backwordWindow);
   
void copyWindowReturn(Stock *stock, double *vect, int backwordWindow);

void frequencyReturns(Stock *stock,Histogram *hist, int backwardWindow,int bins);

#endif