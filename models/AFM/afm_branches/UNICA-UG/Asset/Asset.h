#ifndef ASSET_INCL
#define ASSET_INCL
#include "CDouble.h"
#include "Double.h"


#ifndef Asset_dty
#define Asset_dty
typedef struct Asset Asset;
struct Asset 

{
      int issuer;
      int quantity;
      double lastPrice;
};

#endif

Asset *newAsset();
int assetId(Asset *anAsset);
void  freeAsset(Asset *anAsset);
void setAsset(Asset *anAsset, int issuer, double price, int quantity);
void setPrice(Asset *anAsset,double price);
void addPrice(Asset *anAsset, double price);
void addVolume(Asset *anAsset, double volume);

double lastPrice(Asset *anAsset);



#endif
        
