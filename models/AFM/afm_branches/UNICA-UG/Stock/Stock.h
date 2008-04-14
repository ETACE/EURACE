#ifndef STOCK_INCL
#define STOCK_INCL
#include "Double.h"
#include "math.h"

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

      
};

#endif

Stock *newStock();
void  freeStock(Stock *aStock);
#void setStock(Stock *aStock, int issuer, double price, int quantity);
#void setPrice(Stock *aStock,double price);
#void addPrice(Stock *aStock, double price);
#void addVolume(Stock *aStock, double volume);

#double lastPrice(Stock *anStock);



#endif
        
