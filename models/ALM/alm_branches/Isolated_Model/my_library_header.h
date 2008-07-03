/**
 * \file  my_library_header.h
 * \brief Header for user created library functions.
 */

/** \def MSGDATA
 * \brief The additional data that messages need when sent. */
#define MSGDATA 1.0, 0.0, 0.0, 0.0

/** \def PRINT_LOG
 * \brief A flag to print log to terminal. */
//#define PRINT_LOG 1

int first_day_of_month();
int not_first_day_of_month();
int last_day_of_month();
int not_last_day_of_month();

void sort_vacancy_list(vacancy_array * vacancy_list);
void sort_job_offer_list(job_offer_array * job_offer_list);
int random_int(int min,int max);
void sort_job_application_list(job_application_array * job_application_list);
void sort_mall_sales_list(sales_statistics_array * sales_mall_list);

int credit_request_function(const void *x, const void *y);
int vacancy_list_rank_wage_offer_function(const void *x, const void *y);
int job_offer_list_rank_wage_offer_function(const void *x, const void *y);
int employee_list_rank_specific_skills_function(const void *x, const void *y);
int job_application_list_rank_general_skill_function(const void *x, const void *y);
int sales_statistics_list_rank_sales_function(const void *x, const void *y);
int random_int(int min,int max);
double max(double a, double b);
double min(double a, double b);
