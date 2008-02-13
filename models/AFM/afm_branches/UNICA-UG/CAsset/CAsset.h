#ifndef CAsset_INCL
#define  CAsset_INCL
#include <stdio.h>
#include "Asset.h"
//#include "Stream.h"
//#include "Int.h"
//#include "Double.h"
#ifdef CAsset_dty
typedef Asset_array CAsset;
#endif
#ifndef CAsset_dty
#define CAsset_dty
typedef struct CAsset CAsset;

struct CAsset
{
       int size;
       int total_size;
       Asset **array;
};
typedef CAsset Asset_array ;
#endif
CAsset *newCAsset(int size);       


void emptyCAsset(CAsset *coll );

void addCAsset(CAsset *coll ,Asset *elem);
void addAtCAsset(CAsset *coll ,Asset *elem,int index);

Asset *firstCAsset(CAsset *coll );

int sizeCAsset(CAsset *coll );

Asset *lastCAsset(CAsset *coll );
int isPresentCAsset(CAsset *coll, int index);

int isEmptyCAsset(CAsset *coll );

int isFullCAsset(CAsset *coll );

void growCAsset(CAsset *aFixed);

void resetCAsset(CAsset *coll );
void resetFullCAsset(CAsset *coll );

void freeCAsset(CAsset *aFixed);

Asset *elementAtCAsset(CAsset *coll ,int index);

CAsset *newAssetsOwned();
CAsset *newAssetsTotal(int quantity);
//void writeCAsset(CAsset *coll, Stream *buffer);
//CAsset *readCAsset(Stream *buffer);

//void serializeCAsset(CAsset *coll, Stream *buffer);
//CAsset *deserializeCAsset( Stream *buffer);
#endif
