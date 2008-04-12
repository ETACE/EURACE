#ifndef STOCK_INCL
#define STOCK_INCL
#include "Double.h"


#ifndef Stock_dty
#define Stock_dty
#define MAXPRICES 1000

typedef struct Stock Stock;
struct Stock 

{
      int issuer;
      int quantity;
      double history[MAXPRICES];
      int head;
      int queue;

      
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
        
