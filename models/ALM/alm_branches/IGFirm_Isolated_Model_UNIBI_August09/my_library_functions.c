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
