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
void single_point_cross_over(int size, double * string1, double * string2, int cross_point);
void two_point_cross_over(int size, double * string1, double * string2, int cross_point, int cross_length);
void mutation(int size, double * string, double * stepsize, double prob_mut);
