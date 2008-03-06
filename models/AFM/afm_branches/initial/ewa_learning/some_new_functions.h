/**
 * \file  some_new_functions.h
 * \brief Header file for auxiliary functions.
 */
double sum(double * p, int size);
void cumsum(double * p, int size, double * cumsum);
void cumpdf(double * p, int size, double * cpdf);
double draw(int size, double * cpdf);
int ismember(double i, double * xvec, int size);
void draw_without_replacement(int size, double * cpdf, int Nr_draws, double * draws);
void draw_with_replacement(int size, double * cpdf, int Nr_draws, double * draws);
