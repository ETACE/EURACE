#ifndef CLEARMECH
#include "COrder.h"
#include "Random.h"
#include <stdio.h>
#include "CDouble.h"
#include <math.h>
#include "Order.h"
#include "Double.h"
#define EPS 0.000001


typedef struct Clearing Clearing;
typedef struct Clearing ClearingMechanism;
struct Clearing
{     
        double lastPrice;
        int quantity;
        COrder *sellOrders;
        COrder *buyOrders;
        CDouble *prices;
} ;



Clearing *newClearingMechanism();
Clearing *newClearing();

COrder *buyOrders(Clearing *clear);
COrder *sellOrders(Clearing *clear);
void setClearingMechanism(Clearing *clearm, double lastprice);
void addBuyOrder(Clearing *aClearing , Order *anOrder);

void addSellOrder(Clearing*aClearing , Order *anOrder);
void sortOrders(Clearing *clear);
int aggregateDemand(Clearing *aClearing,double aPriceValue );
int aggregateSupply(Clearing *aClearing,double aPriceValue );

double computeNewPrice(Clearing *aClearing);
 double newPrice(Clearing *aClearing);

void runClearing(Clearing *aClearing);

void emptyClearing(Clearing *aClearing);

void freeClearingMechanism(Clearing *aClearing);
void ordersMacthing(COrder *coll, double price,int type);
void removeZeroOrders(COrder *coll);
void rationing(COrder *coll,int quantity , Random *rnd);
double formedPrice(Clearing *clearm);
#define CLEARMECH
#endif
  
                  
                   
