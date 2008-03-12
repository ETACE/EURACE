/*********************************
 * mylibraryfunctions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * This contains the global functins
 * *********************************
 * History:
 * 13/11/07 Mariam: Global functions. 
 *********************************/
#include "header.h"
#include "mylibraryheader.h"

/** \fn double random_unif()
 * \brief Uniformly distributed random numbers, chosen from
 *   a uniform distribution on the closed interval (0.0,1.0).
 */
double random_unif()
{
    return ((double)rand()/(double)RAND_MAX);
}


/** \fn double random_unif_interval(double a, double b)
 * \brief Uniformly distributed random numbers, chosen from
 *   a uniform distribution on the closed interval (a,b).
 */
double random_unif_interval(double a, double b)
{
	return (a + (b-a)*random_unif());
}

/** \fn double random_norm()
 * \brief Normally distributed random numbers, chosen from
 *   a normal distribution with mean zero, variance one and standard
 *   deviation one.
 */
/*
double random_norm()
{

    return ();
}
*/
