/************************************
 * \file  some_new_functions.h
 * \brief Header file for auxiliary functions.
 * *********************************
 * History:
 * 15/07/08 Sander: General library functions. 
 *********************************/

/* Statistic auxiliary functions */
double random_unif();
double random_unif_interval(double a, double b);
double max(double a, double b);
double min(double a, double b);

double sum(double * p, int size);
void cumsum(double * p, int size, double * cumsum);
void cumpdf(double * p, int size, double * cpdf);
double draw(int size, double * cpdf);
int ismember(double i, double * xvec, int size);
void draw_without_replacement(int size, double * cpdf, int nr_draws, double * draws);
void draw_with_replacement(int size, double * cpdf, int nr_draws, double * draws);
