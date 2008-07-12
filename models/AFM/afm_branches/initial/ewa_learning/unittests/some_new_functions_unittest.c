#include <CUnit/Basic.h>
#include "../header.h"
#include "../mylibraryheader.h"
#include "../my_library_header.h"
#include "../FinancialAgent_agent_header.h"

/************ Unit tests ********************************/
void unittest_random_unif()
{
	int i;

	for (i=0;i<5;i++)
	{
		printf("%f\n",	random_unif());		
	}
}

void unittest_random_unif_interval()
{	
	int i;
	
	for (i=0;i<5;i++)
	{
		printf("%f\n",	random_unif_interval(0.0,10.0));		
	}
}

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
	  printf("\n In sum: p=[%1.1f, %1.1f, %1.1f, %1.1f]\n", p[0], p[1], p[2], p[3]);

	  /***** Function evaluation ***************************************/
	  //double sum(double * p, int size)
	  sum_p = 0.0;
	  sum_p = sum(p, size);
	  
	  printf("\n In function sum_unittest: sum_p : %2.1f\n", sum_p);
	  
     /***** Variables: Memory post-conditions *************************/
     CU_ASSERT_DOUBLE_EQUAL(sum_p, 2.0, 1e-3);
     
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
	  
	  size=4;
	  nr_draws=4;
	  xvec = malloc(size*sizeof(double));
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  draws = malloc(nr_draws*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	//void draw_without_replacement(int size, double * cpdf, int nr_draws, double * draws)
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
	  int size, nr_draws, ans1, ans2;
	  double * xvec;
	  double * draws;
	  double i;
	  
	  size=4; nr_draws=2;
	  xvec = malloc(size*sizeof(double));
	  xvec[0]=0.3; xvec[1]=0.4; xvec[2]=0.8; xvec[3]=1.0;
	  draws = malloc(nr_draws*sizeof(double));
	  
     /***** Function evaluation ***************************************/
	//void draw_with_replacement(int size, double * cpdf, int nr_draws, double * draws)
 	 draw_with_replacement(size, xvec, nr_draws, draws);
     
     /***** Variables: Memory post-conditions *************************/
     ans1 = ismember(draws[0], xvec, size);
     ans2 = ismember(draws[1], xvec, size);

     CU_ASSERT_EQUAL(ans1, 1);
     CU_ASSERT_EQUAL(ans2, 1);

 	 free(xvec);
	 free(draws);
}


void unittest_single_point_cross_over()
{
	// Variables: Memory pre-conditions **************************
	int c;
	int size;
	double * x;
	double * y;

	size=4;
	x = malloc(size*sizeof(double));
	y = malloc(size*sizeof(double));
	x[0]=0.1; x[1]=0.1; x[2]=0.1; x[3]=0.1;
	y[0]=0.2; y[1]=0.2; y[2]=0.2; y[3]=0.2;

	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
		
	// Function evaluation ***************************************
	//void single_point_cross_over(int size, double * string_a, double * string_b, int cross_point)
	printf("\n Before single_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n Before single_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

	single_point_cross_over(size, x, y, c);

	printf("\n After single_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n After single_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

    // Variables: Memory post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(x[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[3], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[3], 0.1, 1e-3);

	free(x);
	free(y);
}


/*
void unittest_two_point_cross_over()
{
	int c, ell, size;
	double * x;
	double * y;
	
    // ***** Variables: Memory pre-conditions **************************
	size=4;
    x = malloc(size*sizeof(double));
    y = malloc(size*sizeof(double));
	x[0]=0.1; x[1]=0.1; x[2]=0.1; x[3]=0.1;
	y[0]=0.2; y[1]=0.2; y[2]=0.2; y[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=1;

    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n Before two_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

	two_point_cross_over(size, x, y, c, ell);

	printf("\n After two_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n After two_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

    // ***** Variables: Memory post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(x[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[3], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[3], 0.2, 1e-3);

	free(x);
	free(y);
}
*/
/*
void unittest_two_point_cross_over_alt()
{
	int c, ell, size;
	double * x;
	double * y;

	
    // ***** Variables: Memory pre-conditions **************************
	size=4;
    x = malloc(size*sizeof(double));
    y = malloc(size*sizeof(double));
	x[0]=0.1; x[1]=0.1; x[2]=0.1; x[3]=0.1;
	y[0]=0.2; y[1]=0.2; y[2]=0.2; y[3]=0.2;
	
	//Random cross-over point
	//c = (int)(size*random_unif());
	c=2;
	
	//Random cross-over length
	//ell = (int)(size*random_unif());
	ell=1;

    // ***** Function evaluation ***************************************
	//void two_point_cross_over(int size, double * string_a, double * string_b, int cross_point, int cross_length)
	printf("\n Before two_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n Before two_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

	two_point_cross_over_alt(size, x, y, c, ell);

	printf("\n After two_point_cross_over: x=[%1.1f, %1.1f, %1.1f, %1.1f]\n", x[0], x[1], x[2], x[3]);
	printf("\n After two_point_cross_over: y=[%1.1f, %1.1f, %1.1f, %1.1f]\n", y[0], y[1], y[2], y[3]);

    // ***** Variables: Memory post-conditions *************************
    CU_ASSERT_DOUBLE_EQUAL(x[0], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[1], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[2], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(x[3], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[0], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[1], 0.2, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[2], 0.1, 1e-3);
    CU_ASSERT_DOUBLE_EQUAL(y[3], 0.2, 1e-3);

	free(x);
	free(y);
}
*/

/*
void unittest_mutation()
{   
 	// At start of unit test, add one agent
    add_FinancialAgent_agent_internal(init_FinancialAgent_agent());
    current_xmachine = *p_xmachine;

    // Variables: Memory pre-conditions 
	int j;
	double string[4] = {1.0, 2.0, 3.0, 4.0};
	
	EWA_PARAMETERS.EWA_beta = 1.0;
	GA_PARAMETERS.stepsize[0]=0.01;
	GA_PARAMETERS.stepsize[1]=0.01;
	GA_PARAMETERS.stepsize[2]=0.01;
	GA_PARAMETERS.stepsize[3]=0.01;
	
    // Function evaluation  
	//void mutation(int size, double * string);
	mutation(4, string);
	
    printf("\n prob: [");
    for (j=0;j<4;j++){printf("%2.2f ", string[j]);}
    printf("]\n");

    // Variables: Memory post-conditions 
	//CU_ASSERT_EQUAL(<var_name2>, <value>);

	// free();
}
*/
