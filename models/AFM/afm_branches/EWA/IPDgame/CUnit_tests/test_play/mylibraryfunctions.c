
/*********************************
 * mylibraryfunctions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * This contains the global functins
 * *********************************
 * History:
 * 13/11/07 Mariam: Global functions. 
 *********************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** \fn double random_unif()
 * \brief Uniformly distributed random numbers, chosen from
    a uniform distribution on the interval (0.0,1.0).
 */
double random_unif(void)
{
    return ((double)rand()/(double)RAND_MAX);
}

 