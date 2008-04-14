#include <CUnit/Basic.h>
#include "header.h"
#include "mylibraryheader.h"
#include "FinancialAgent_agent_header.h"

/************ Unit tests ********************************/
void unittest_sum()
{	
     /***** Variables: Memory pre-conditions **************************/
	  double outcome;
	  double * p;
	  int size;
	  	  
	  //Input: p={0.6 0.2 0.8 0.4}
	  p = malloc(size * sizeof(double));
	  p[0]=0.6; p[1]=0.2; p[2]=0.8; p[3]=0.4;

     /***** Function evaluation ***************************************/
	  //double sum(double * p, int size)
	  outcome = 0.0;
	  size=4;
	  outcome = sum(p, size);
	  printf("\n outcome : %f", outcome);
	  
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
	  p[0]=0.6; p[1]=0.2; p[2]=0.8; p[3]=0.4;
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

void unittest_ismember()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, ans;
	  double * xvec;
	  double i;
	  
	  size=4;
	  xvec = malloc(sizeof(double)*size);
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  i=0.3;
	
     /***** Function evaluation ***************************************/
	 //int ismember(int i, int * xvec, int size)
	 ans = ismember(i, xvec, size);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans, 1);

     free(xvec);
}

void unittest_draw_without_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws, ans1, ans2, ans3, ans4;
	  double * xvec;
	  double * draws;
	  double i;
	  
	  size=4; nr_draws=4;
	  xvec = malloc(sizeof(double)*size);
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  draws = malloc(nr_draws*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	//void draw_without_replacement(int size, double * cpdf, int Nr_draws, double * draws)
	 draw_without_replacement(size, xvec, nr_draws, draws);
     ans1 = ismember(draws[0], xvec, size);
     ans2 = ismember(draws[1], xvec, size);
     ans3 = ismember(draws[2], xvec, size);
     ans4 = ismember(draws[3], xvec, size);
	 
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     CU_ASSERT_EQUAL(ans1, 1);
     CU_ASSERT_EQUAL(ans2, 1);
     CU_ASSERT_EQUAL(ans3, 1);
     CU_ASSERT_EQUAL(ans4, 1);
     
	 free(xvec);
	 free(draws);	 
}


void unittest_draw_with_replacement()
{
     /***** Variables: Memory pre-conditions **************************/
	  int size, nr_draws;
	  double * xvec;
	  double * draws;
	  double i;
	  
	  size=4; nr_draws=4;
	  xvec = malloc(sizeof(double)*size);
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  draws = malloc(sizeof(double)*nr_draws);
	  
     /***** Function evaluation ***************************************/
	//void draw_with_replacement(int size, double * cpdf, int Nr_draws, double * draws)
 	 draw_with_replacement(size, xvec, nr_draws, draws);
     
     /***** Variables: Memory post-conditions *************************/
     //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
     //CU_ASSERT_EQUAL(<var_name2>, <value>);

 	 free(xvec);
	 free(draws);
}


void unittest_single_point_cross_over()
{
    /***** Variables: Memory pre-conditions **************************/
	
    /***** Function evaluation ***************************************/
	//void single_point_cross_over(int size, double * string1, double * string2, int cross_point)
	
	
    /***** Variables: Memory post-conditions *************************/
    //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
    //CU_ASSERT_EQUAL(<var_name2>, <value>);

	// free();
}

void unittest_two_point_cross_over()
{
    /***** Variables: Memory pre-conditions **************************/
	
    /***** Function evaluation ***************************************/
	//void two_point_cross_over(int size, double * string1, double * string2, int cross_point, int cross_length)
	
	
    /***** Variables: Memory post-conditions *************************/
    //CU_ASSERT_DOUBLE_EQUAL(<var_name1>, <value>, 1e-3);
    //CU_ASSERT_EQUAL(<var_name2>, <value>);

	// free();
}

void unittest_mutation()
{    /************* At start of unit test, add one agent **************/
    add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
    current_xmachine = *p_xmachine;

    /***** Variables: Memory pre-conditions **************************/
	int j;
	double string[4] = {1.0, 2.0, 3.0, 4.0};
	
	EWA_PARAMETERS.EWA_beta = 1.0;
	GA_PARAMETERS.stepsize[0]=0.01;
	GA_PARAMETERS.stepsize[1]=0.01;
	GA_PARAMETERS.stepsize[2]=0.01;
	GA_PARAMETERS.stepsize[3]=0.01;
	
    /***** Function evaluation ***************************************/
	//void mutation(int size, double * string);
	mutation(4, string);
	
    printf("\n prob: [");
    for (j=0;j<4;j++){printf("%2.2f ", string[j]);}
    printf("]\n");

    /***** Variables: Memory post-conditions *************************/
	//CU_ASSERT_EQUAL(<var_name2>, <value>);

	// free();
}
