#include "Double.h"
#include "Stream.h"
/* ATD to extend  the type double adding new functionality and a dinamic Behavior*/
 
double quo(double c,double b)
{  
    double temp;
    temp= (int)(c/b);
 
    return temp;

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


void writeDouble(double a, Stream *stream)
{
     char buffer[40];
       sprintf(buffer,"%f",a);
       addAllStream(stream,buffer,sizeof(double));
}

void serializeDouble(double a, Stream *stream)
{
     char buffer[sizeof(double)];
        memcpy((void*)buffer,(void*) &a, sizeof(double));
       addAllStream(stream,buffer,sizeof(double));
}

double deserializeDouble( Stream *stream)
{ double *presult;
  double result;
  presult=upTo(stream,sizeof(double));
  result=*presult;
  return result;
 }
