/**
 * \file  my_library_functions.c
 * \brief Holds user created library functions.
 */

#include "header.h"
#include "my_library_header.h"

/*New sorting algorithm from Simon C 3.4.2008*/


int credit_request_function(const void *x, const void *y)
{
if( ((credit_request *)x)->prob_of_failure < ((credit_request *)y)->prob_of_failure) return -1;
    else if( ((credit_request *)x)->prob_of_failure > ((credit_request *)y)->prob_of_failure)   return 1;
else return 0;


}



int vacancy_list_rank_wage_offer_function(const void *x, const void *y)
{
    if( ((vacancy *)x)->wage_offer > ((vacancy *)y)->wage_offer) return -1;
    else if( ((vacancy *)x)->wage_offer < ((vacancy *)y)->wage_offer) return 1;
    else return 0;
}

int job_offer_list_rank_wage_offer_function(const void *x, const void *y)
{
    if( ((job_offer *)x)->wage_offer > ((job_offer *)y)->wage_offer) return -1;
    else if( ((job_offer *)x)->wage_offer < ((job_offer *)y)->wage_offer) return 1;
    else
    {
        /* If equal randomly sort */
        if(rand()/((double)RAND_MAX + 1) <= 0.5) return -1;
        else return 1;
    }
}

int employee_list_rank_specific_skills_function(const void *x, const void *y)
{
    if( ((employee *)x)->specific_skill > ((employee *)y)->specific_skill) return -1;
    else if( ((employee *)x)->specific_skill < ((employee *)y)->specific_skill) return 1;
    else return 0;
}

/** \fn int job_application_list_rank_general_skill_function(const void *x, const void *y)
 * \brief Returns an integer result of the comparision between the two elements
 * \param x The first element to compare.
 * \param y The second element to compare.
 * \return The compare result.
 */
int job_application_list_rank_general_skill_function(const void *x, const void *y)
{
    if( ((job_application *)x)->general_skill > ((job_application *)y)->general_skill) 
        return -1;
    else if( ((job_application *)x)->general_skill < ((job_application *)y)->general_skill)         return 1;
    else
    {
        if( ((job_application *)x)->specific_skill > ((job_application *)y)
        ->specific_skill) return -1;

        else if( ((job_application *)x)->specific_skill < ((job_application *)y)
        ->specific_skill) return 1;

        else
        {
            /* If equal randomly sort */
            if(rand()/((double)RAND_MAX + 1) <= 0.5) return -1;
            else return 1;
        }
    }
}

int sales_statistics_list_rank_sales_function(const void *x, const void *y)
{
    if( ((temporary_sales_statistics *)x)->sales < ((temporary_sales_statistics *)y)->sales) return -1;
    else if( ((temporary_sales_statistics *)x)->sales > ((temporary_sales_statistics *)y)->sales) return 1;
    else return 0;
}

/** \fn int random_int(int min,int max)
 * \brief Returns an integer between and including min and max
 * \param min The minimum integer.
 * \param max The maximum integer.
 * \return The random integer.
 */
int random_int(int min,int max)
{
    return min + rand() % (max - min + 1);
}

double max(double a, double b)
{
    return (a >= b) ? a : b; 
}

double min(double a, double b)
{
    return (a <= b) ? a : b; 
}
