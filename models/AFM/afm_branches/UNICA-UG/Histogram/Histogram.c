#include "histogram.h"

void evaluateMaxMin(Histogram *Histogram, double data[], int len);

Histogram * newHistogram() {
	int x;
	Histogram *temp;
	temp = malloc(sizeof(Histogram));
	for(x=0; x<MAX_DIM; x++) {
		temp->values[x] = 0;
                temp->prob[x] = 0;
	}
	return temp;
}

/* 
 * Questa funzione riceve in ingresso un histogram, i dati dai quali si vuole calcolare l'istogramma,
 * la lunghezza dell'array di tali dati ed il numero di intervalli che si vogliono considerare
 * nell'istogramma. L'intervallo [min,max] viene così suddiviso in bin intervallini di dimensione delta
 * (il primo intervallo va da min a min+delta);
 * index rappresenta l'indice (nell'array che contiene i valori dell'istogramma)
 * in cui ricade il dato considerato; l'indice 0 rappresenta l'intervallo che va da min a min+delta,
 * e così via...
 */

void histogram(Histogram *hist, double data[], int len, int bins) { 
	int x=0;
	int index = 0;
	evaluateMaxMin(hist, data, len);
	hist->delta = (hist->max - hist->min)/bins; 
	while(x<len) {
		index = (data[x]-hist->min)/hist->delta;
		//printf("Indice: %d - valore: %f - delta: %f\n", index, data[x], histogram->delta);
		hist->prob[index]++;
                hist->values[index]= histogram->values[index]+data[x];
		x++;
	}
 normalize(hist, realization);

}
void normalize(Histogram *hist, int realization)
    { int i;
      for(i=0;i<hist->bins;i++)
        {if(hist->prob[i]) hist->values[i]=hist->values[i]/hist->prob[i]; //it computes the mean value on the bin
         hist->prob[i]=hist->prob[i]/len;
        }
   }
         
void evaluateMaxMin(Histogram* hist, double data[], int len) {
	int x = 0;
	double tempMax=0, tempMin=0;
	double temp;
	while(x < len) {
		temp = data[x];
		if(x==0)
			tempMax = tempMin = temp;
		else if(temp > tempMax)
			tempMax = temp;
		else if (temp < tempMin)
			tempMin = temp;
		x++;
	}
	hist->max = tempMax;
	hist->min = tempMin;
}
void multipleBet(Histogram *dest, Histogram *source, int numIter)
{ int iter;
  for(i=0;i<numIter;i++)
    {
     
    }

}
  
double *computeAssetUtilityFunction(Histogram *hist,double lossAversion)
{ double *result;
  return resutl;
}
