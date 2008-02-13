#include "Eurostat.h"

int receiveAssetInformationEURO()
 { CAsset *assets;
   Asset *asset;
   assets =get_assets();
   resetCAsset(assets);
   xmachine_message_infoAsset *currentAsset;
   currentAsset=get_first_infoAsset_message();
   
   while(currentAsset){
   asset=newAsset();
   setAsset(asset,currentAsset->issuer,currentAsset->price,currentAsset->quantity);
    addAtCAsset(assets,asset,asset->issuer);
   currentAsset=currentAsset->next;
  }
  return 0;
}

int sendAssetInformationEURO()
 { CAsset *assets;
   Asset *asset;
   int size,i;
   double price;
   assets =get_assets();
   size=sizeCAsset(assets);
   printf("numero di asset mandati = %d",size);
   for(i=0;i<size;i++)
   {
   asset=elementAtCAsset(assets,i);
   price=lastPrice(asset);
   add_asset_message(asset->issuer,price,asset->quantity,message_range,get_posx(),get_posy(),0);
  }
  return 0;
}
