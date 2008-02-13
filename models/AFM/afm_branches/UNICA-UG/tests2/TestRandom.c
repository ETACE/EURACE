#include "TestRandom.h"
 
 /*instance of ADT Random*/
 Random *rng;
 
/*set the Fixture to test the random generating functions */ 

 static void setFixture(Random *rng)
{
    double co;
    co = (double) 2345678901.0;
	setSeed(rng, co);
 
}
 
/* init and clean-up suite */
 int suite_random_init(void) { rng=newRandom(); setFixture(rng);return 0; }
       
 int suite_random_clean(void) { free(rng); return 0; }

/*Random  test_next the Its Completely Broken Test
The above should print as... (0.149243269650845 0.331633021743797 0.75619644800024 
0.393701540023881 0.941783181364547 0.549929193942775 0.659962596213428 
0.991354559078512 0.696074432551896 0.922987899707159 ) If they are not these values 
(accounting for precision of printing) then something is horribly wrong: DO NOT USE THIS CODE 
FOR ANYTHING.*/ 

static double  randomValues[]={0.149243269650845, 0.331633021743797, 0.75619644800024 ,
	0.393701540023881, 0.941783181364547, 0.549929193942775, 0.659962596213428 ,
	0.991354559078512, 0.696074432551896, 0.922987899707159};
	
/*test case for next*/     
void testnext()
{   
    int k;
    double result[10];
    setFixture(rng);
    for(k=0;k< 10;k++) result[k]= next(rng);
     for(k=0;k< 10;k++) 
    CU_ASSERT_DOUBLE_EQUAL(randomValues[k], result[k], 0.000001);
   
}

/*test case for nextBetween*/   
void testNextBetween()
{    
     double temp;
         setFixture(rng);
     temp=nextBetween(rng, 1, 2);
     CU_ASSERT_DOUBLE_EQUAL(temp, 1.149243269650845, 0.000001);
   ;
}
/*test case for  gaussian*/   
void testGaussian()
{
     double temp;
     setFixture(rng);
	 temp=gaussian(rng);
	 CU_ASSERT_DOUBLE_EQUAL(temp, TESTGAUSS, 0.000001);
	
	 
}

void testNextMax()
{ int result,i;
  result=0;
  for(i=0;i<100;i++)
   if(nextMax(rng,10)<10) result++;
  CU_ASSERT(result==100);
}

