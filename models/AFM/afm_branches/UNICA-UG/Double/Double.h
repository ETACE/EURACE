#ifndef DOUBLE_INCL
#define DOUBLE_INCL
#include <stdlib.h>
#include <math.h>
#include "Stream.h"
#define max(A,B) ( (A) > (B) ? (A):(B))
#define min(A,B) ( (A) < (B) ? (A):(B))

double quo(double c,double b);

double * newDouble(double value);

void copyDouble(double *dest ,double *orig);

void swapDouble(double *dest ,double *orig);

int compareDouble(double a, double b);

int isEqualDouble(double a ,double b);

double forceTologInterval(double rec,double value, double aNumber );


void writeDouble(double a, Stream *stream);
void serializeDouble(double a, Stream *stream);


double deserializeDouble( Stream *stream);

#endif
