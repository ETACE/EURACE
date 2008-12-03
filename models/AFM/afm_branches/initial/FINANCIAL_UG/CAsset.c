#include "my_library_header.h"




int sizeCAsset(Asset_array *coll )
{  
     return  coll->size;
}
    

int isPresentCAsset(Asset_array *coll, int index)
{
    int answer,size;
    size=sizeCAsset(coll);
    answer=index<size;
    return answer;
}



Asset *firstCAsset(Asset_array *coll )
{   
    return &(coll->array[0]);  
}


Asset *lastCAsset(Asset_array *coll )
{   
    return &(coll ->array[(coll ->size)-1]);
     
}


int isEmptyCAsset(Asset_array *coll )
{   
    int answer;
    answer=((coll ->size)==0);
    return answer;
     
}

int isFullCAsset(Asset_array *coll )
{   
    int answer;
    answer=(coll ->total_size)==(coll ->size);
    return answer;
     
}

 

Asset *elementAtCAsset(Asset_array *coll ,int index)
{ Asset *answer;
  answer =&(coll->array[index]);
  return answer;
}


void init_Assetsowned(Asset_array *assets)
{  
    init_Asset_array(assets);
    reset_Asset_array(assets);
    add_Asset(assets, 0, 1000, 50);
    add_Asset(assets, 1, 500, 100);
    add_Asset(assets, 2000, 1000, 100);
}
Asset_array *newAssetsTotal(int quantity)
{   Asset_array *assets;
    init_Asset_array(assets);
    reset_Asset_array(assets);
    add_Asset(assets, 0, quantity, 50);
    add_Asset(assets, 1, quantity, 50);
    return assets;
}

int findCAsset(Asset_array *coll,int assetId)
{   int answer;
    Asset *current;
    int found;
    found=0;
    int i;
    i=0;
    answer=-1;
    while(i<sizeCAsset(coll)&&(found==0))
    { current=elementAtCAsset(coll,i);
      found=((current->id)==assetId);
      if(found) answer=i;
      i++;
    }                    
    if(!found)  answer=-1;
    return answer;
} 

