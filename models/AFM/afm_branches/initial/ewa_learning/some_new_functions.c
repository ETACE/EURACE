#include "header.h"
#include "mylibraryheader.h"
#include "my_library_header.h"
//*********** BEGIN AUXILIARY FUNCTIONS ****************************

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

	printf("\n In sum_unittest: p=[%1.1f, %1.1f, %1.1f, %1.1f]\n", p[0], p[1], p[2], p[3]);

	sum_val=0.0;
	for (i=0;i<size;i++)
	{
		sum_val += p[i];
	}	
	printf("\n In function sum: sum_val=%f", sum_val);
	
    return(sum_val);
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

//double * cumpdf(int N, double * p)
//Cummulative probability density function.
//p: probability vector (can be non-scaled, i.e. probabilities need not add to 1).
//size: number of elements
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

//int draw(int N, double * cpdf)
//N: number of elements
//cpdf: vector of probabilities
//Drawing a random number from the cummulative probability density function cpdf.
//Returns the bin number of a randomly chosen number u.
//Given a cummulative pdf F(.), the random number u belongs to bin j
//if and only if F(j-1)<= u < F(j).
//
//USAGE:
//Before calling:
//double * cpdf;
//int size;
//cpdf = malloc(sizeof(double)*size);
//Call: draw(size, cpdf);
//After calling:
//free(cpdf);

double draw(int size, double * cpdf)
{	
	//Before calling this function you need to have done:
	//cpdf = malloc(sizeof(double)*size);

	int j, nr_selected_bin;
	double u,nr_drawn;
	
    //Random number:
	u=random_unif();
    printf("\n Random draw: %f\n", u);
    
    
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
    
    //return nr_selected_bin;
    return nr_drawn;
}

//int ismember(int i, int * xvec, int size)
//Checks if i is a member of the array "xvec" with length "size".
//is a double, we check whether: (i-eps) < xvec[k] < (i+eps)
//Returns 1 if i is a member, 0 else.
//
//USAGE:
//Before calling:
//double * x;
//int size;
//x = malloc(sizeof(double)*size);
//Call: draw(size, x);
//After calling:
//free(x);

int ismember(double i, double * xvec, int size)
{
	//Before calling this function you need to have done:
	//xvec = malloc(sizeof(double)*size);

	int k;
	int ans=0;
	double eps=0.0001;
	
	for (k=0;k<size;k++)
	{
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

void draw_without_replacement(int size, double * cpdf, int nr_draws, double * draws)
{
	//TO FIX: in draw we do not set the random seed correctly, so all random draws are equal!!
	
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
	safety_count = 10*nr_draws;
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


//void draw_with_replacement(int size, double * cpdf, double * draws, N)
//Drawing N random numbers (integers) with replacement
//from the cummulative probability density function cpdf.
//size: size of cpdf
//cpdf cpdf to sample from
//draws: output
//N: nr of draws
//
//UNIT TEST:
//Do 1000 draws from 4 bins with probabilities according to a given pdf.
//Input: 
//pdf={0.3 0.1 0.4 0.2};
//cpdf={0.3 0.4 0.8 1.0};
//draw_with_replacement(4, cpdf, draws, 1000)
//Outcome: approx. 300, 100, 400, 200 in each bin.
//
//USAGE:
//Before calling:
//double * cpdf;
//double * draws;
//int size;
//cpdf = malloc(sizeof(double)*size);
//draws = malloc(sizeof(double)*N);
//Call: draw(size, cpdf, draws, N);
//After calling:
//free(cpdf);
//free(draws);

void draw_with_replacement(int size, double * cpdf, int nr_draws, double * draws)
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

/* \fn void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
 * \brief Genetic operator: single_point_cross_over
 */
void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
{
	int k;
	double tmp;
	
	if (cross_point>size)
	{
		printf("Error in single_point_cross_over: cross_point > size of string");
		return;
	}

    //Crossover the bitstrings using single-point cross-over from the cross_point
    for (k=cross_point;k<size;k++)
    {
        tmp = string_a[k];
        string_a[k]= string_b[k];
        string_b[k]= tmp;
    }
}

/* \fn void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
 * \brief Genetic operator: two_point_cross_over
 */
void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
{
	int k, count;
	double tmp;
	
	if ((cross_point+cross_length)<size)
	{
	    // perform normal cross-over between parent pair
		for (k=cross_point; k<(cross_point+cross_length); k++)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;	
		}
	}
	else
	{
		//cross-over crossed the bitstring boundary, so wrap-around is needed
	
	    //1. perform cross-over starting at cross-point:
		count=0;
		for (k=cross_point; k<size; k++)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;
			count++;
		}
	    //2. perform cross-over at beginning of string until count reaches cross_length
		//for (k=0; k<(cross_point+cross_length)%size; k++)
		k=0;
		while (count!=cross_length)
		{
			tmp = string_a[k];
			string_a[k]=string_b[k];
			string_b[k]=tmp;
			count++;
		}
	}
}

/* \fn void two_point_cross_over_alt(int size, double * string_a, double * string_b, int cross_point, int cross_length)
 * \brief Genetic operator: two_point_cross_over
 */
void two_point_cross_over_alt(int size, double * string_a, double * string_b, int cross_point, int cross_length)
{
	int k, start, end;
	double tmp;
	
	//Set start and end bits
	if (cross_point+cross_length<=size)
	{
		start = cross_point;
		end   = cross_point+cross_length;
	}
	//Prevent overrun on right-hand side and cut to length
	/*
	if (cross_point+cross_length>size)
	{
	    start=cross_point;
	    end=size;            	
	}
	*/
	//Prevent overrun on right-hand side by making strings circular          
	if (cross_point+cross_length>size)
	{
		start=(cross_point+cross_length)%size;
		end=cross_point;
	}

	//Crossover the bitstrings
    for (k=start;k<end;k++)
    {
        tmp = string_a[k];
        string_a[k]=string_b[k];
        string_b[k]=tmp;
    }

}

/* \fn void mutation(int size, double * offspring_1, double * offspring_2);
 * \brief Genetic operator: Mutation of real-valued bitstrings 
 * Size of the mutation is delta*stepsize[k], where: 
 * delta = {-10, -5, 0, +5, +10} or delta in {-10,+10}
 * stepsize[k]: can be a parameter dependent gridsize
 */
void mutation(int size, double * string, double * stepsize, double prob_mut)
{
	int k;
	double delta;
	
	for (k=0; k<size; k++)
	{
		// apply mutation to the bit of string 1
		if (random_unif() > prob_mut)
		{	
			//Set units to mutate between -10% and +10%
			delta = random_unif_interval(-10.0, 10.0);
			
			//mutate the value at position k by a random percentage between -10% and +10% of the previous value
			string[k] = delta*stepsize[k]*string[k];
		}
	}    
}

/* \fn void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
 * \brief Genetic operator: Election of 2 out of 4 best bitstrings 
 */
/*
void election(int size, double * offspring_1, double * offspring_2, double * parent_1, double * parent_2)
{

}
*/

// *********** END AUXILIARY FUNCTIONS ****************************
