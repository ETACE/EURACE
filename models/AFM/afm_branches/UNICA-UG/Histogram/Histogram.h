#ifndef HISTOGRAM_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HISTOGRAM_H_
#define MAX_DIM 20

typedef struct Histogram Histogram;

struct Histogram {
	double prob[MAX_DIM];
        double values[MAX_DIM];
	double max;
	double min;
	double delta;
	int bins;

};

#endif /*HISTOGRAM_H_*/


void histogram(Histogram *histogram, double *data, int len, int bins);


/* a partire dalle frequenze dei ritorni e da una funzione lineare a tratti calcola la funzione di utilita, 
la funzione di utilita e una funzione discreta calcolata per integrazione U*/
double *computeAssetUtilityFunction(Histogram *hist,double lossAversion);
void normalize(Histogram *hist, int realization);