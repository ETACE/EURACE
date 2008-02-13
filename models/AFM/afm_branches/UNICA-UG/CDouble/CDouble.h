#ifndef ADTCDOUBLE
#define ADTCDOUBLE
#include <stdio.h>
#include "Stream.h"
#include "Int.h"
#include "Double.h"
typedef struct CDouble CDouble;

struct CDouble
{
       int index;
       int size;
       double *basic;
};

CDouble *newCDouble(int size);       


void emptyCDouble(CDouble *coll );

void addCDouble(CDouble *coll ,double elem);

double firstCDouble(CDouble *coll );

int sizeCDouble(CDouble *coll );

double lastCDouble(CDouble *coll );


int isEmptyCDouble(CDouble *coll );

int isFullCDouble(CDouble *coll );

void growCDouble(CDouble *aFixed);

void resetCDouble(CDouble *coll );

void freeCDouble(CDouble *aFixed);

double elementAtCDouble(CDouble *coll ,int index);
double mean(CDouble *aFixedC);

double variance(CDouble *aFixedC);

void addDouble( CDouble *coll, double value);
void divide(CDouble *coll, double denominator);
// add an Double with decreasing or increasing relation respectively rel='<' or rel='>'

void addIncSortDouble(CDouble *coll,double value);
void addIncSetSortDouble(CDouble *coll,double value);

void writeCDouble(CDouble *coll, Stream *buffer);
CDouble *readCDouble(Stream *buffer);

void serializeCDouble(CDouble *coll, Stream *buffer);
CDouble *deserializeCDouble( Stream *buffer);
#endif
