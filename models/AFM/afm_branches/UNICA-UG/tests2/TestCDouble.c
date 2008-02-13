#include "TestCDouble.h"


CDouble *colltst;
CDouble *incColl;

double aDouble1;
double aDouble2;
double aDouble3;
double aDouble4;
static void setFixtureSorted()
{    
     
      addIncSortDouble(incColl,aDouble1);
      addIncSortDouble(incColl,aDouble2);
      addIncSortDouble(incColl,aDouble3);
      addIncSortDouble(incColl,aDouble4);
    
    
     
}
static void setFixtureNormal()
{   
      addCDouble(colltst,aDouble1);
      addCDouble(colltst,aDouble2);
      addCDouble(colltst,aDouble3);
      addCDouble(colltst,aDouble4);
    
     
}
int suite_CDouble_init(void) 
{
      
    colltst=newCDouble(20);
    incColl=newCDouble(20);

     aDouble1=3.1;
     aDouble2=3.3;
     aDouble3=3.2;
     aDouble4=3.0;    
    setFixtureNormal();   
    setFixtureSorted();
   
return 0;
}       
 int suite_CDouble_clean(void)
 {   
     freeCDouble(colltst);
     freeCDouble(incColl);
     return 0;
}
void testAddDouble( void)
{     double temp; 
      temp=lastCDouble(colltst);
     CU_ASSERT(isEqualDouble(temp,aDouble4));
     temp=firstCDouble(colltst);
     CU_ASSERT(isEqualDouble(temp,aDouble1));
}
// test for add an Double with decreasing or increasing relation respectively rel='<' or rel='>'

void testAddIncSortDouble(void)
{     double inc; 
      inc=lastCDouble(incColl);
    CU_ASSERT(isEqualDouble(inc,aDouble2));
      inc=firstCDouble(incColl);
    CU_ASSERT(isEqualDouble(inc,aDouble4));
    
}

void testSerializeCDouble()
{   CDouble *dtest;
    CDouble *expected;
     dtest=newCDouble(10);
     
     addCDouble(dtest,4);
     addCDouble(dtest,6);
     
    Stream *str;
    str=newStream(10);
    serializeCDouble(dtest,str);
    expected=deserializeCDouble(str);
    //CU_ASSERT_DOUBLE_EQUAL(2, expected-, 0.000001);
    CU_ASSERT_EQUAL((dtest->size),(expected->size));
    freeStream(str);
}

void testMean(void)
{ double mn;
  mn=mean(colltst);
  CU_ASSERT_DOUBLE_EQUAL(mn,3.15, EPS);
}

void testVariance(void)
{ double var;
  var=variance(colltst);
  CU_ASSERT_DOUBLE_EQUAL(var,0.0166667, EPS);
}
/*
void testVarianceLogReturns(void){
      double var;
      var=varianceLogReturns(colltst,4);
       CU_ASSERT_DOUBLE_EQUAL(var, 0.00433125, EPS);
      }

void testLogReturns(void)
{ FixedCollection *aux;
   double var;
  aux=copyFromTo(colltst,0,sizeFixed(colltst));
  logReturns(aux);
  var=variance(aux);
  CU_ASSERT_DOUBLE_EQUAL(var, 0.00433125, EPS);
}

void testPrintDouble(void)
{
     printCollectionDouble(colltst,"/testprint.txt");
}
*/
