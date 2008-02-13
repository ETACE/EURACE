#ifndef PORT_INCL
#define PORT_INCL
#define traderStartingCash 50000
#define assetStartingQuantity 1000
#define initialPrice 20
#ifndef maxAssets
#define maxAssets 2
#endif
#include "Order.h"
#include "Asset.h"
#include "CAsset.h"
#include "COrder.h"
#include "Belief.h"

#ifndef Portfolio_dty
#define Portfolio_dty
typedef struct Portfolio Portfolio;

struct Portfolio
{
       //CAsset *assets;
       double bankAccount;
};
#endif

Portfolio *newPortfolio();
void setBankAccount(Portfolio *ptfolio, double cash);


void initializePortfolio(Portfolio *port, CAsset *assets);
Portfolio *expectedPortfolio(Portfolio *port, Belief *belief);
void executeOrder(Portfolio *portfolio,Order *anOrder,CAsset *assets,COrder *pending);
double wealth(Portfolio *port, CAsset *assetsowned);
int totalassets(CAsset *assetsowned);


#endif

