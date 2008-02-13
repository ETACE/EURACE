#ifndef CLEARHOUSE_
#define CLEARHOUSE_
#include "ClearingMechanism.h"
#include "header.h"
#include "Asset.h"
#include "CAsset.h"
#include "Order.h"
#include "COrder.h"
#ifndef maxAsset
#define maxAsset 2
#endif
#ifndef message_range
#define message_range 50.0
#endif

void receiveOrderOnAsset(Clearing *mechanism, Asset *anAsset);


void computeAssetPrice(Clearing *mechanism, Asset *anAsset);

void sendOrderStatus(Clearing *clearm);

int receiveOrdersAndRun();

int receiveAssetInformation();

int sendAssetInformation();

#endif
