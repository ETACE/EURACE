#ifndef ORDER_INCL
#include <stdlib.h>
#ifndef Order_dty
#define Order_dty
typedef struct Order Order;

struct Order 
   {   int issuer;
       int assetId;
       double price;
       int quantity;
   };
#endif

Order * newOrder();

void setOrder(Order *anOrder, double price, int quantity,int assetId, int issuer);

int getOrderQuantity(Order *anOrder);

void copyOrder(Order *dest ,Order *orig);

void swapOrder(Order *dest ,Order *orig);

int compareOrder(Order *a, Order *b);

int isEqualOrder(Order *a, Order *b);

int isBuyOrder(Order *anOrder);

int isSellOrder(Order *anOrder);


int isNullOrder(Order *anOrder);

void setAsNullOrder(Order *anOrder);
void setAsSellOrder(Order *anOrder);
void freeOrder(Order *ord);
int isGreaterOrder(Order *a, Order *b);
int isLessOrder(Order *a, Order *b);
#define ORDER_INCL
#endif

