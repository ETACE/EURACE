#ifndef COrder_INCL
#define  COrder_INCL
#include <stdio.h>
#include "Order.h"
//#include "Stream.h"
//#include "Int.h"
//#include "Double.h"
#ifdef COrder_dty
#include "header.h"
typedef Order_array COrder;
#endif
#ifndef COrder_dty
#define COrder_dty
typedef struct COrder COrder;

struct COrder
{
       int size;
       int total_size;
       Order **array;
};

typedef  COrder Order_array ;
#endif
COrder *newCOrder(int size);       


void emptyCOrder(COrder *coll );

void addCOrder(COrder *coll ,Order *elem);

Order *firstCOrder(COrder *coll );

int sizeCOrder(COrder *coll );

Order *lastCOrder(COrder *coll );


int isEmptyCOrder(COrder *coll );

int isFullCOrder(COrder *coll );

void growCOrder(COrder *aFixed);

void resetCOrder(COrder *coll );
void resetFullCOrder(COrder *coll );
Order *removeWithId(COrder *coll, int assetId);
void freeCOrder(COrder *aFixed);
int findCOrder(COrder *coll,int assetId);
Order *removeCOrder(COrder * coll, int index);
Order *elementAtCOrder(COrder *coll ,int index);

void addOrder( COrder *coll, Order *ord);

void addIncSortOrder(COrder *coll,Order *order);

void addDecSortOrder(COrder *coll,Order *order);

double minPriceOrder(COrder *aFixedC);

void qSortCOrder(COrder *v, int first, int last);
void qSortCOrderDec(COrder *v, int first, int last);
double maxPriceOrder(COrder *aFixedC);

//void writeCOrder(COrder *coll, Stream *buffer);
//COrder *readCOrder(Stream *buffer);

//void serializeCOrder(COrder *coll, Stream *buffer);
//COrder *deserializeCOrder( Stream *buffer);
#endif
