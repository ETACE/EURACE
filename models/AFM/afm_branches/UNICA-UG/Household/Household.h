#ifndef TRADER_
#define TRADER_
#include "Asset.h"
#include "Portfolio.h"
#include "Order.h"
#include "COrder.h"
#include "CDouble.h"
#include "Belief.h"
#include "header.h"
#include "Random.h"
#include "Belief.h"
#ifndef PARK
#define PARK 1.5
#endif
#ifndef mu
#define mu 1.01
#endif
#ifndef maxAssets
#define maxAssets 2
#endif

#ifndef message_range
#define message_range 50.0
#endif
extern Random *rnd;

//extern Asset *asset;
/*typedef struct Household Household;
struct Household 
{
       int id;
       Portfolio *portfolio;
       Belief *belief;
       CAsset *assetowns;
       Corder *pendingOrders;
};*/
int sendOrders(void);

int updateTrader(void);
CDouble *assetUtilitiesToDesiredWeights();
Order *computeLimitOrder( Asset *anAsset, double weight, double resource,Belief *belief);
int  distribuite(double cash, double totalwealth);
void generatePendingOrders(CAsset *assetsowned,COrder *pending, Belief *belief,Portfolio *port);
int totalassetsowned();
double cashowned();
#endif

