#include <CUnit/Basic.h>
#include <math.h>
#include "header.h"
#include "mylibraryheader.h"

/************ Unit tests ********************************/
void unittest_sum()
{	
     /***** Variables: Memory pre-conditions **************************/
	  double outcome;
	  double * p;
	  int size;
	  
	  outcome = 0.0;
	  size = 4;
	  
	  //Input: p={0.6 0.2 0.8 0.4}
	  p = malloc(size * sizeof(double));
	  p[0]=0.6; p[1]=0.2; p[0]=0.8; p[1]=0.4;

     /***** Function evaluation ***************************************/
	  //double sum(double * p, int size)
	  outcome = sum(p, size);
	 
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(outcome, 2.0, 1e-3);
     
     free(p);
}

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
	  p = malloc(sizeof(double)*size);
	  p[0]=0.6; p[1]=0.2; p[0]=0.8; p[1]=0.4;
	  cumsum_p = malloc(sizeof(double)*size);
	  
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
	  p[0]=0.6; p[1]=0.2; p[0]=0.8; p[1]=0.4;
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


void unittest_draw()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size;
	  double * cpdf;
	  double outcome;
	  
	  size=4;
	  cpdf = malloc(sizeof(double)*size);
	  cpdf[0]=0.3; cpdf[1]=0.4; cpdf[0]=0.8; cpdf[1]=1.0;
	  
     /***** Function evaluation ***************************************/
	  //int draw(int size, double * cpdf)
	 outcome = draw(size, cpdf);
	 
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);

	 free(cpdf);
}

void unittest_ismember()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, ans;
	  double * x;
	  double i;
	  
	  size=4;
	  x = malloc(sizeof(double)*size);
	  x[0]=0.3; x[1]=0.4; x[0]=0.8; x[1]=1.0;
	  i=0.3;
	
     /***** Function evaluation ***************************************/
	 //int ismember(int i, int * x, int size)
	 ans = ismember(i, x, size);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans, 1);

     free(x);
}

void unittest_draw_without_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws, ans1, ans2, ans3, ans4;
	  double * x;
	  double * draws;
	  double i;
	  
	  size=4; nr_draws=4;
	  x = malloc(sizeof(double)*size);
	  x[0]=0.3; x[1]=0.4; x[0]=0.8; x[1]=1.0;
	  draws = malloc(nr_draws*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	//void draw_without_replacement(int size, double * cpdf, double * draws, int Nr_draws)
	 draw_without_replacement(size, x, draws, nr_draws);
     ans1 = ismember(draws[0], x, size);
     ans2 = ismember(draws[1], x, size);
     ans3 = ismember(draws[2], x, size);
     ans4 = ismember(draws[3], x, size);
	 
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans1, 1);
     CU_ASSERT_EQUAL(ans2, 1);
     CU_ASSERT_EQUAL(ans3, 1);
     CU_ASSERT_EQUAL(ans4, 1);
     
	 free(x);
	 free(draws);	 
}


void unittest_draw_with_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws;
	  double * x;
	  double * draws;
	  double i;
	  
	  size=4; nr_draws=4;
	  x = malloc(sizeof(double)*size);
	  x[0]=0.3; x[1]=0.4; x[0]=0.8; x[1]=1.0;
	  draws = malloc(sizeof(double)*nr_draws);
	  
     /***** Function evaluation ***************************************/
	//void draw_with_replacement(int size, double * cpdf, double * draws, int Nr_draws)
 	 draw_with_replacement(size, x, draws, nr_draws);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);

 	 free(x);
	 free(draws);
}

