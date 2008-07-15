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

/* GA auxiliary functions */
void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point);
void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length);
void mutation(int size, double * string, double * stepsize, double prob_mut);

/* GA auxiliary functions */
int GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id1, int * rule_id2);
void GA_reproduction(int id1, int id2, double * offspring_1, double * offspring_2);
void GA_mutation(int size, double * offspring_1, double * offspring_2);
void GA_election(int size, double * offspring_1, double * offspring_2);
void GA_reinsertion(int size, double * offspring_1, double * offspring_2, int id1, int id2);
