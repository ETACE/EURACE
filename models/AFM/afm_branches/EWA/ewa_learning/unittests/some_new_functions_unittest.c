/***************************************************************************************************
 * some_new_functions.c 
 * Auxiliary functions for the EWA learning module.
 **************************************************************************************************
 * History:
 * 24/07/08 Sander: Checked that all malloc pointers are freed at the end of functions. 
 * 15/07/08 Sander
 **************************************************************************************************/

#include <CUnit/Basic.h>
#include "../header.h"
#include "../some_new_functions.h"

/************ Unit tests ********************************/
void unittest_random_unif()
{
	int i;

	for (i=0;i<5;i++)
	{
		if(PRINT_DEBUG) printf("%f\n",	random_unif());		
	}
}

void unittest_random_unif_interval()
{	
	int i;
	
	for (i=0;i<5;i++)
	{
		if(PRINT_DEBUG) printf("%f\n",	random_unif_interval(0.0,10.0));		
	}
}

/*
 * \fn: void unittest_sum()
 * \brief: 
 * Status: Tested OK
 */
void unittest_sum()
{	
     /***** Variables: Memory pre-conditions **************************/
	  double sum_p;
	  double * p;
	  int size;
	  	  
	  size=4;
	  //Input: p={0.6 0.2 0.8 0.4}
	  p = malloc(sizeof(double)*size);
	  p[0]=0.6; p[1]=0.2; p[2]=0.8; p[3]=0.4;
	  if(PRINT_DEBUG) printf("\n In unittest_sum: p=[%1.1f, %1.1f, %1.1f, %1.1f]\n", p[0], p[1], p[2], p[3]);

	  /***** Function evaluation ***************************************/
	  //double sum(double * p, int size)
	  sum_p = 0.0;
	  sum_p = sum(p, size);
	  
	  if(PRINT_DEBUG) printf("\n In function unittest_sum: sum_p = %f \n", sum_p);
	  
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(sum_p, 2.0, 1e-3);
     
     free(p);
}


/*
 * \fn: void unittest_cumsum()
 * \brief: 
 * Status: Tested OK
 */
void unittest_cumsum()
{	
	//UNIT TEST:
	//Input: p={0.6 0.2 0.8 0.4}
	//cumsum(p,size,cumsum);
	//Outcome: cumsum = {0.6 0.8 1.6 2.0}

	/***** Variables: Memory pre-conditions **************************/
	  double * p;
	  double * cumsum_p;
	  int size;
	  
	  size = 4;
	  //Input: p={0.6 0.2 0.8 0.4}
	  p = malloc(size*sizeof(double));
	  p[0]=0.6; p[1]=0.2; p[2]=0.8; p[3]=0.4;
	  cumsum_p = malloc(size*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	  //void cumsum(double * p, int size, double * cumsum)
	  cumsum(p, size, cumsum_p);
	 
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(cumsum_p[0], 0.6, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cumsum_p[1], 0.8, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cumsum_p[2], 1.6, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cumsum_p[3], 2.0, 1e-3);
     
     free(p);
     free(cumsum_p);
}

/*
 * \fn: void unittest_cumpdf()
 * \brief: 
 * Status: Tested OK
 */
void unittest_cumpdf()
{
	//UNIT TEST:
	//Input: p={0.6 0.2 0.8 0.4}
	//cpdf = malloc(sizeof(double)*size);
	//cumpdf(p, 4, cpdf);
	//Outcome: cpdf={0.3 0.4 0.8 1.0}
	
     /***** Variables: Memory pre-conditions **************************/
	  double * p;
	  double * cpdf;
	  int size;
	  
	  size = 4;
	  //Input: p={0.6 0.2 0.8 0.4}
	  p = malloc(sizeof(double)*size);
	  p[0]=0.6; p[1]=0.2; p[2]=0.8; p[3]=0.4;
	  cpdf = malloc(sizeof(double)*size);
	  
     /***** Function evaluation ***************************************/
	  //void cumpdf(double * p, int size, double * cpdf)
	  cumpdf(p, size, cpdf);
	 
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(cpdf[0], 0.3, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cpdf[1], 0.4, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cpdf[2], 0.8, 1e-3);
     CU_ASSERT_DOUBLE_EQUAL(cpdf[3], 1.0, 1e-3);
     
     free(p);
     free(cpdf);
}


/*
 * \fn: void unittest_draw()
 * \brief: 
 * Status: Tested OK
 */
void unittest_draw()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size;
	  double * cpdf;
	  double outcome;
	  
	  size=4;
	  cpdf = malloc(sizeof(double)*size);
	  cpdf[0]=0.3; cpdf[1]=0.4; cpdf[2]=0.8; cpdf[3]=1.0;
	  
     /***** Function evaluation ***************************************/
	  //int draw(int size, double * cpdf)
	 outcome = draw(size, cpdf);
	 
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);

	 free(cpdf);
}

/*
 * \fn: void unittest_ismember()
 * \brief: 
 * Status: Tested OK
 */
void unittest_ismember()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, ans;
	  int * xvec;
	  int i;
	  
	  size=2;
	  xvec = malloc(sizeof(int)*size);
	  xvec[0]=1; xvec[1]=2;
	  i=2;
	
     /***** Function evaluation ***************************************/
	 //int ismember(int i, int * xvec, int size)
	 ans = ismember(i, xvec, size);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans, 1);

     free(xvec);
}

/*
 * \fn: void unittest_ismember()
 * \brief: 
 * Status: Tested OK
 */
void unittest_ismember_double()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, ans;
	  double * xvec;
	  double i;
	  
	  size=2;
	  xvec = malloc(sizeof(double)*size);
	  xvec[0]=0.1; xvec[1]=0.2;
	  i=0.2;
	
     /***** Function evaluation ***************************************/
	 //int ismember(int i, int * xvec, int size)
	 ans = ismember_double(i, xvec, size);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans, 1);

     free(xvec);
}

/*
 * \fn: void unittest_draw_without_replacement()
 * \brief: UNIT TEST:
 * pdf=[1.0 1.0 1.0 1.0]
 * draw_without_replacement(4, pdf, 4, draws)
 * Outcome: array 'draws' should contain all values 0-3
 * draws=[0 1 2 3] in any order.
 * 
 * Status: Tested OK
 */
void unittest_draw_without_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws, ans1, ans2, ans3, ans4;
	  double * pdf;
	  int * draws;
	  double * value_draws;
	  int i, index;
	  
	  size=4;
	  nr_draws=4;
	  pdf = malloc(size*sizeof(double));
	  pdf[0]=1.0; pdf[1]=1.0; pdf[2]=1.0; pdf[3]=1.0;
	  
	  /* indices of the draws */
	  draws = malloc(nr_draws*sizeof(int));
	  	  
     /***** Function evaluation ***************************************/
	//void draw_without_replacement(int size, double * cpdf, int nr_draws, double * draws)
	 draw_without_replacement(size, pdf, nr_draws, draws);
	 
     if(PRINT_DEBUG) printf("\n In unittest_draw_without_replacement: draws=[%d, %d, %d, %d]\n", draws[0], draws[1], draws[2], draws[3]);
	 
     /***** Variables: Memory post-conditions *************************/
     
	 free(pdf);
	 free(draws);	 
	 free(value_draws);
}

/*
 * \fn: void unittest1_draw_with_replacement()
 * \brief: 
 * Status: Tested OK
 */
void unittest1_draw_with_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws, ans1, ans2, ans3, ans4;
	  double * xvec;
	  int * draws;
	  double * value_draws;
	  int i, index;
	  
	  size=4; nr_draws=4;
	  xvec = malloc(size*sizeof(double));
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  
	  /* indices of the draws */
	  draws = malloc(nr_draws*sizeof(int));
	  
	  /* values of the draws */
	  value_draws = malloc(nr_draws*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	//void draw_with_replacement(int size, double * cpdf, int nr_draws, double * draws)
 	 draw_with_replacement(size, xvec, nr_draws, draws);
     if(PRINT_DEBUG) printf("\n In unittest_draw_with_replacement: draws=[%d, %d, %d, %d]\n", draws[0], draws[1], draws[2], draws[3]);

     /***** Variables: Memory post-conditions *************************/
 	 for (i=0;i<nr_draws;i++)
 	 {
 	  index = draws[i];
	  value_draws[i] = xvec[index];
 	 }
     if(PRINT_DEBUG) printf("\n value_draws=[%1.2f, %1.2f, %1.2f, %1.2f]\n", value_draws[0], value_draws[1], value_draws[2], value_draws[3]);

      ans1 = ismember_double(value_draws[0], xvec, size);
      ans2 = ismember_double(value_draws[1], xvec, size);
      ans3 = ismember_double(value_draws[2], xvec, size);
      ans4 = ismember_double(value_draws[3], xvec, size);

     CU_ASSERT_EQUAL(ans1, 1);
     CU_ASSERT_EQUAL(ans2, 1);
     CU_ASSERT_EQUAL(ans3, 1);
     CU_ASSERT_EQUAL(ans4, 1);

 	 free(xvec);
	 free(draws);
	 free(value_draws);
}

/*
 * \fn: void unittest2_draw_with_replacement()
 * \brief: Performs 1,000 draws from 4 bins with probabilities according to a given pdf:
 * pdf={0.3 0.1 0.4 0.2}; 
 * draw_with_replacement(4, pdf, draws, 1000) 
 * 
 * Expected result: approx. 300, 100, 400, 200 in each bin.
 * 
 * Status: Tested OK
 */
void unittest2_draw_with_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws;
	  double * pdf;
	  int * draws;
	  int * sum;
	  int i, j;
	  
	  size=4;
	  nr_draws=1000;
	  
	  pdf = malloc(size*sizeof(double));
	  pdf[0]=0.3; pdf[1]=0.1; pdf[2]=0.4; pdf[3]=0.2;
	  	  
	  /* indices of the draws */
	  draws = malloc(nr_draws*sizeof(int));
	  	  
     /***** Function evaluation ***************************************/
	//void draw_with_replacement(int size, double * pdf, int nr_draws, double * draws)
 	 draw_with_replacement(size, pdf, nr_draws, draws);

     /***** Variables: Memory post-conditions *************************/
     
	  //Construct sums
	  sum = malloc(size*sizeof(int));
	  for (j=0;j<size;j++) sum[j]=0;
	  
	  //traverse draws, compute sums
	    for (i=0;i<nr_draws;i++)
	    {
	    	for (j=0;j<size;j++)
	    	{
	    		if(draws[i]==j)
	    			{
	    				sum[j] += 1;
	    				//if(PRINT_DEBUG) printf("\n Encountered: %d (draw %d)\n", draws[i], i);
	    			}
	    	}
	    }
	    if(PRINT_DEBUG) printf("\n  In unittest_draw_with_replacement: sum=[%d, %d, %d, %d]\n", sum[0], sum[1], sum[2], sum[3]);
	    if(PRINT_DEBUG) printf("  Expected: sum=[%d, %d, %d, %d]\n", 300, 100, 400, 200);

     
     CU_ASSERT_DOUBLE_EQUAL(sum[0], 300.0, 50.0);
     CU_ASSERT_DOUBLE_EQUAL(sum[1], 100.0, 50.0);
     CU_ASSERT_DOUBLE_EQUAL(sum[2], 400.0, 50.0);
     CU_ASSERT_DOUBLE_EQUAL(sum[3], 200.0, 50.0);
     
     
 	 free(pdf);
	 free(draws);
     free(sum);
}
