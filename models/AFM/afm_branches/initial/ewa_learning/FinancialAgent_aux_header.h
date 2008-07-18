 /*********************************
 * FinancialAgent_aux_header.h
 * Header file for GA auxiliary functions.
 * *********************************
 * History:
 * 15/07/08 Sander 
 *********************************/

/* GA auxiliary functions */
void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point);
void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length);
void two_point_cross_over_alt(int size, double * string_a, double * string_b, int cross_point, int cross_length);
void mutation(int size, double * string, double * stepsize, double prob_mut);
void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2);

/* GA main functions */
int GA_selection(int * parent_index_1, int * parent_index_2, int * rule_id1, int * rule_id2);
void GA_reproduction(int id1, int id2, double * offspring_1, double * offspring_2);
void GA_mutation(int size, double * offspring_1, double * offspring_2);
void GA_election(int size, double * offspring_1, double * offspring_2);
void GA_reinsertion(int size, double * offspring_1, double * offspring_2, int id1, int id2);

/* Debugginhg functions */
//void FinancialAgent_print_public_classifiersystem();
//void Household_print_private_classifiersystem();
void test_print();
