#include "CAsset.h"
#define CONSTGROW 100


CAsset *newCAsset(int size)

{    CAsset *temp;
     temp=malloc(sizeof(CAsset));
     temp->array=(Asset **)malloc(sizeof(Asset *)*size);
     temp->total_size=size;
     emptyCAsset(temp);
     resetFullCAsset(temp);
     return temp;
}
int sizeCAsset(CAsset *coll )
{  
     return  coll->size;
}
    
    
void emptyCAsset(CAsset *coll )
{
    coll->size=0;
}

void resetCAsset(CAsset *coll )
{      int i;
     int size;
     size=coll->size;
       
      for(i=0;i<size;i++)
      {free(coll->array[i]);
      coll->array[i]=NULL;
      }
      coll->size=0;
}
void resetFullCAsset(CAsset *coll )
{      int i;
     int size;
     size=coll->total_size;
       
      for(i=0;i<size;i++)
      
      coll->array[i]=NULL;
      
     
}

void addCAsset(CAsset *coll ,Asset *elem)
{   if(!isFullCAsset(coll ))
       {
        coll ->array[coll->size]=elem;
        coll ->size++;
        }
    else {
          growCAsset(coll );
          addCAsset(coll ,elem);
     }
     }
     
void addAtCAsset(CAsset *coll ,Asset *elem,int index)
{   if(index<coll->total_size)
       {
        coll ->array[index]=elem;
        if(index>=coll ->size) coll->size=index+1;
        }
    else {
          growCAsset(coll );
          addCAsset(coll ,elem);
     }
     }
int isPresentCAsset(CAsset *coll, int index)
{
    int answer,size;
    size=sizeCAsset(coll);
    answer=index<size;
    return answer;
}



Asset *firstCAsset(CAsset *coll )
{   
    return coll->array[0];  
}


Asset *lastCAsset(CAsset *coll )
{   
    return coll ->array[(coll ->size)-1];
     
}


int isEmptyCAsset(CAsset *coll )
{   
    int answer;
    answer=((coll ->size)==0);
    return answer;
     
}

int isFullCAsset(CAsset *coll )
{   
    int answer;
    answer=(coll ->total_size)==(coll ->size);
    return answer;
     
}

void copyContentCAsset(CAsset *aDest,CAsset *aOrigin)
{ int i;
     for(i=0;i<aOrigin->size;i++)
      aDest->array[i]=aOrigin->array[i];
      aDest->size=aOrigin->size;
      
 }
 
 void growCAsset(CAsset *coll)
 {     Asset **dest;
      int i,size;
      size=(coll->total_size)+CONSTGROW;
      dest=(Asset **)malloc(sizeof(Asset *)*size);
      for(i=0;i<coll->size;i++)
      dest[i]=coll->array[i];
      for(i=coll->size;i<size;i++)
      dest[i]=NULL;
      coll->total_size=size;
      free(coll->array);
      coll->array=dest;
 }
      
void freeCAsset(CAsset *coll)
{    
     int i;
     int size;
     size=coll->size;
      for(i=0;i<size;i++)
      {free(coll->array[i]);
      coll->array[i]=NULL;
      }
      free(coll);
}

void removeCAsset(CAsset * coll, int index)
{
int i;
	if(index < coll->size)
	{
        free(coll->array[i]);
		for(i = index; i < coll->size; i++)
		{
			coll->array[i] = coll->array[i+1];
		}
		coll->size--;
	}
}

Asset *elementAtCAsset(CAsset *coll ,int index)
{ Asset *answer;
  answer =coll->array[index];
  return answer;
}
CAsset *newAssetsOwned()
{   CAsset *assets;
	assets=newCAsset(10);
    Asset *anAssetA;
    Asset *anAssetB;
    anAssetA=newAsset();
    anAssetB=newAsset();
    setAsset(anAssetA,0,50, 1000);
    setAsset(anAssetB,1,50, 1000);
    emptyCAsset(assets);
    addCAsset(assets,anAssetA);
    addCAsset(assets,anAssetB);
    return assets;
}
CAsset *newAssetsTotal(int quantity)
{   CAsset *assets;
	assets=newCAsset(10);
    Asset *anAssetA;
    Asset *anAssetB;
    anAssetA=newAsset();
    anAssetB=newAsset();
    setAsset(anAssetA,0,50, quantity);
    setAsset(anAssetB,1,50, quantity);
    emptyCAsset(assets);
    addCAsset(assets,anAssetA);
    addCAsset(assets,anAssetB);
    return assets;
}

//int findCAsset(CAsset *coll,int assetId){}
/*
void writeCAsset(CAsset *coll, Stream *buffer)
{  
     char separator;
     int i;
     separator=',';
     writeInt(coll->index,buffer);
     addStream(buffer,separator);
     for(i=0;i<coll->index;i++)
     {
       writeDouble(elementAtCD(coll,i),buffer);
       addStream(buffer,separator);
     }
}

void serializeCAsset(CAsset *coll, Stream *buffer)
{    int i;
     serializeInt(coll->index,buffer);
     serializeInt(coll->size,buffer);
     for(i=0;i<coll->index;i++)
      serializeDouble(coll->basic[i],buffer);
}  

CAsset *deserializeCAsset( Stream *buffer)
{    int i,size;
     CAsset *coll;
   
     size=deserializeInt(buffer);
     coll=newCAsset(size);
     coll->size=deserializeInt(buffer);
     for(i=0;i<size;i++)
      addCAsset(coll,deserializeDouble(buffer));
      return coll;
}  
*/
