 /*********************************
 * some_new_functions.c
 * General library functions.
 * *********************************
 * History:
 * 15/07/08 Sander 
 *********************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "some_new_functions.h"

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

double max(double a, double b)
{
	return (a >= b) ? a : b; 
}

double min(double a, double b)
{
	return (a <= b) ? a : b; 
}


//double sum(double * p, int size)
//Sum of elements of a vector p.
//
//USAGE:
//Before calling:
//double * p;
//int size
//p = malloc(sizeof(double)*size);
//Call: sum = sum(p, size);
//After calling:
//free(p);
//
//UNIT TEST:
//Input: p={0.6 0.2 0.8 0.4}
//sum = sum(p,4);
//Outcome: sum=2.0;
double sum(double * p, int size)
{
	int i;
	double sum_val;

	if(PRINT_DEBUG) printf("\n In function sum: p=[%1.1f, %1.1f, %1.1f, %1.1f]\n", p[0], p[1], p[2], p[3]);

	sum_val=0.0;
	for (i=0;i<size;i++)
	{
		sum_val += p[i];
	}	
	if(PRINT_DEBUG) printf("\n In function sum: sum_val=%f\n", sum_val);
	
    return sum_val;
}

//\brief: Cumulative sum of elements of a vector p.
//\fn: cumsum(double * p, int size, double * cumsum)
//Call: cumsum(p, size, cumsum);
//
//USAGE:
//Before calling:
//double * p;
//double * cumsum;
//int size;
//cumsum = malloc(sizeof(double)*size);
//Call: cumsum(p, size, cumsum);
//After calling:
//free(cumsum);
//
//UNIT TEST:
//Input: p={0.6 0.2 0.8 0.4}
//cumsum = cumsum(p);
//Outcome: cumsum={0.6 0.8 1.6 2.0}
void cumsum(double * p, int size, double * cumsum)
{
	//Before calling this function you need to have done:
	//cumsum = malloc(sizeof(double)*size);

	int i;
	
	//Cummulative sum
	cumsum[0]=p[0];
	for (i=0;i<size-2;i++)
	{
		cumsum[i+1]=cumsum[i]+p[i+1];
	}
	cumsum[size-1]=cumsum[size-2]+p[size-1];
}

//void cumpdf(double * p, int size, double * cpdf)
//Cummulative probability density function.
//p: probability vector (can be non-scaled, i.e. probabilities need not add to 1).
//size: number of elements, size of array p, cpdf
//Given a vector of probabilities p, the cumulative pdf is given by
//the normalized values in the cummulative sum:
//  cpdf = cumsum(p)/sum(p);
//
//USAGE:
//Before calling:
//double * p;
//double * cpdf;
//int size;
//p = malloc(sizeof(double)*size);
//cpdf = malloc(sizeof(double)*size);
//Call: cumpdf(p, size, cumpdf);
//After calling:
//free(cpdf);
//free(p);
//
//UNIT TEST:
//Input: p={0.6 0.2 0.8 0.4}
//cpdf = malloc(sizeof(double)*size);
//cumpdf(p, 4, cpdf);
//Outcome: cpdf={0.3 0.4 0.8 1.0}
//free(cpdf);
void cumpdf(double * p, int size, double * cpdf)
{
	//Before calling this function you need to have done:
	//cpdf = malloc(sizeof(double)*size);
	
	int i;
	double sum_p;		//this is the sum of p
	double * cumsum_p;	//this is the cumulative sum of p	
	
	cumsum_p = malloc(sizeof(double)*size);
	
	//The sum is passed to sum_p:
	sum_p = sum(p, size);
	
	//The cumulative sum is passed to cumsum_p:
	cumsum(p, size, cumsum_p);
    
	//The cumulative pdf is:
	for (i=0;i<size;i++)
	{    	
     	cpdf[i] = cumsum_p[i]/sum_p;
	}
	free(cumsum_p);
}

/*
 * \fn: int draw(int size, double * cpdf)
 * \bief: Draws a random number according to the inversion method, using the cummulative probability density function cpdf.
 * Draw() returns the bin number associated to a uniform random u.
 * Given a cummulative pdf F(.), the random number u belongs to bin j if and only if F(j-1) <= u < F(j).
 * 
 * int size: size of the array cpdf
 * double cpdf: cummulative probability density function
 */
//USAGE:
//Before calling:
//double * cpdf;
//int size;
//cpdf = malloc(sizeof(double)*size);
//Call: draw(size, cpdf);
//After calling:
//free(cpdf);
int draw(int size, double * cpdf)
{	
	//Before calling this function you need to have done:
	//cpdf = malloc(sizeof(double)*size);

	int j, nr_selected_bin;
	double u, nr_drawn;
	
    //Random number:
	u=random_unif();
    //printf("\n Random draw: %f\n", u);
    
    
    nr_selected_bin=0;
    
    //Case 1: u<F(1)
    if (0<=u && u<cpdf[0])
    {
        nr_selected_bin=1;
        nr_drawn = cpdf[0];
    }
        
    if (size>1)
    {
    	//Case 2: Travers the cpdf until u >= F(j-1)
	    for (j=2;j<size;j++)
	    {
	        if (cpdf[j-1]<=u && u<cpdf[j])
	        {
	            nr_selected_bin=j;
	            nr_drawn = cpdf[j];
	            break;
	    	}
	    }
	    
	    //Case 3: u>=F(J)
        if (cpdf[size-1]<=u)
        {
            nr_selected_bin=size-1;
            nr_drawn = cpdf[size-1];
        }
    }
    
    return nr_selected_bin;
}

//int ismember(int i, int * xvec, int size)
//Checks whether i is a member of the int array xvec with length size.
//Returns 1 if i is a member, 0 else.
//
//USAGE:
//Before calling:
//int * xvec;
//int size;
//xvec = malloc(sizeof(int)*size);
//Call: ismember_double(i, xvec, size);
//After calling:
//free(xvec);

int ismember(int i, int * xvec, int size)
{
	//Before calling this function you need to have done:
	//xvec = malloc(sizeof(int)*size);

	int k;
	int ans=0;
	
	for (k=0;k<size;k++)
	{
		if (xvec[k]==i)
		{
			ans=1;
			break;
		}
	}
	return ans;
}

//int ismember_double(double i, double * xvec, int size)
//Checks if i is a member of the double array xvec with length size.
//Returns 1 if i is a member, 0 else.
//
//USAGE:
//Before calling:
//double * xvec;
//int size;
//xvec = malloc(sizeof(double)*size);
//Call: ismember_double(i, xvec, size);
//After calling:
//free(xvec);

int ismember_double(double i, double * xvec, int size)
{
	//Before calling this function you need to have done:
	//xvec = malloc(sizeof(double)*size);

	int k;
	int ans=0;
	double eps=0.0001;
	
	for (k=0;k<size;k++)
	{
		//Code for double arrays
		if ((i-eps<xvec[k])&&(xvec[k]<i+eps))
		{
			ans=1;
			break;
		}
	}
	return ans;
}

//void draw_without_replacement(int N, double * cpdf, double * draws)
//Drawing N random numbers (integers) without replacement from the cummulative probability density function cpdf.
//UNIT TEST:
//cpdf={0.1 0.2 0.3 0.4 0.5};
//draw_without_replacement(5, cpdf)
//Outcome: array 'draws' should contain all values 1-5
//draw={0.1 0.2 0.3 0.4 0.5} in any order.
//
//USAGE:
//Before calling:
//double * cpdf;
//double * draws;
//int size;
//cpdf = malloc(sizeof(double)*size);
//draws = malloc(sizeof(double)*size);
//Call: draw(size, cpdf);
//After calling:
//free(cpdf);
//free(draws);

void draw_without_replacement(int size, double * cpdf, int nr_draws, int * draws)
{
	//Before calling this function you need to have done:
	//cpdf = malloc(sizeof(double)*size);
	//draws = malloc(sizeof(double)*nr_draws);
	
	double i;
	int k;
	int count, count_2, safety_count;
	
	
	//printf("\n Setting drawns to -1\n");
	for (k=0; k<size; k++)
	{
		draws[k]=-1;
	}
	
	//printf("\n Continuing with drawing\n");
	//Continue drawing until nr_draws different elements have been drawn
	count=0;
	count_2=0;
	safety_count = 100*nr_draws;
	while(count != nr_draws)
	{
		//printf("\n count %d != %d:\n", count, nr_draws);

		//printf("\n A draw:\n");
		i = draw(size, cpdf);
		
		//Check membership, only add if new draw not already a member
		if (ismember(i,draws,size)==0)
		{
			draws[count]=i;
			count += 1;
		}
		//Stop after 10*nr_drawns:
		count_2 +=1;
		if (count_2==safety_count) break;
	}
	if (count_2==safety_count)
	{
		printf("\n Function draw_without_replacement: reached safety count %d, while nr_draws = %d\n", count_2, nr_draws);
	}
}


//void draw_with_replacement(int size, double * cpdf, int nr_draws, double * draws)
//Drawing nr_draws random numbers (integers) with replacement
//from the cummulative probability density function cpdf.
//size: size of cpdf
//cpdf: cpdf to sample from
//nr_draws: number of draws
//draws: output
//
//UNIT TEST:
//Do 1000 draws from 4 bins with probabilities according to a given pdf.
//Input: 
//pdf={0.3 0.1 0.4 0.2};
//cpdf={0.3 0.4 0.8 1.0};
//draw_with_replacement(4, cpdf, 1000, draws)
//Outcome: approx. 300, 100, 400, 200 in each bin.
//
//USAGE:
//Before calling:
//double * cpdf;
//double * draws;
//int size;
//cpdf = malloc(sizeof(double)*size);
//draws = malloc(sizeof(double)*nr_draws);
//Call: draw(size, cpdf);
//After calling:
//free(cpdf);
//free(draws);

void draw_with_replacement(int size, double * cpdf, int nr_draws, int * draws)
{
	//Before calling this function you need to have done:
	//cpdf = malloc(sizeof(double)*size);
	//draws = malloc(sizeof(double)*nr_draws);

	int k=0;

	for (k=0; k<nr_draws; k++)
	{
		draws[k]=draw(size, cpdf);
	}
}

