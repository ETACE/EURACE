#include "my_library_header.h"
#ifndef EPS 
#define EPS 0.000001
#endif


/* ATD to extend  the type double adding new functionality and a dinamic Behavior*/
 

int equals( double a1,double a2)
   { int answer;
     answer=0;
     if(a1<a2+EPS) answer=1;
     if((a2>a1+EPS)&&answer) answer=1;
     return answer;
}
     

/*	"constrains a number into the a logaritmic interval of aValue. Examples:
	120 forceTo: 50 logInterval: 2, returns 100
	10 forceTo: 50 logInterval: 2, returns 25"
*/
double forceTologInterval(double rec,double value, double aNumber )
{ double answer;
   double temp; 
	if (rec > (value * aNumber)) answer=value * aNumber;
	else { temp=  value / aNumber;
             answer= max(rec,temp);
          }
  return answer;
}
double *newDouble(double value)
{    double *temp;
     temp=malloc(sizeof(double));
     *temp=value;
     return temp;
}

int isEqualDouble(double a ,double b)
{ return a==b;
}
void copyDouble(double *dest ,double *orig)
{
     *dest=*orig;
  
  }


void swapDouble(double *dest ,double *orig)
{   double temp;
    copyDouble(&temp,dest);
    copyDouble(dest,orig);
    copyDouble(orig,&temp);
     
     }


int compareDouble(double a, double b)
{
    return a>b;
    
}


