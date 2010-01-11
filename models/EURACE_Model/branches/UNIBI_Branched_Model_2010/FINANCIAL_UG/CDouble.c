#include "my_library_header.h"

double_array *newCDouble(int size)

{    double_array *temp;
     temp=malloc(sizeof(double_array));
     temp->array=(double *)malloc(sizeof(double)*size);
     temp->total_size=size;
     reset_double_array(temp);
     return temp;
}
int sizeCDouble(double_array *coll )
{  
     return  coll->size;
}
    
    
void emptyCDouble(double_array *coll )
{
    coll->size=0;
}


     
     
double elementAtCDouble(double_array *coll ,int size)
{
      return coll->array[size];
}


double firstCDouble(double_array *coll )
{   
    return coll->array[0];  
}


double lastCDouble(double_array *coll )
{   
    return coll ->array[(coll->size)-1];
     
}


int isEmptyCDouble(double_array *coll )
{   
    int answer;
    answer=((coll->size)==0);
    return answer;
     
}

int isFullCDouble(double_array *coll )
{   
    int answer;
    answer=(coll ->size)==(coll ->total_size);
    return answer;
     
}


      
      



void addIncSortDouble(double_array *coll,double value)
{     
      int i,cond; 
      int size;
      double temp;
      double *ptorder;
      double *current;
      cond=1;
      ptorder=&temp;
      size=sizeCDouble(coll);
      i=0;
      temp=value;
     while(cond&&(i<size))
      { 
        if(!compareDouble(temp,coll->array[i]))
              {current=&(coll->array[i]);
              swapDouble(ptorder,current);
              }
          else cond=0;
        i++;
      }       
       add_double(coll, temp); 
      
}

void addIncSetSortDouble(double_array *coll,double value)
{     
      int i,cond,equa; 
      int size;
      double temp;
      double *ptorder;
      double *current;
      cond=1;
      ptorder=&temp;
      size=sizeCDouble(coll);
      i=0;
      equa=1;
      temp=value;
     while(cond&&(i<size)&&equa)
      { 
        if(isEqualDouble(temp,coll->array[i])) equa=0;
        else
        if(!compareDouble(temp,coll->array[i])) 
             {current=&(coll->array[i]);
              swapDouble(ptorder,current);
              }
          else cond=0;
        i++;
      }       
       if(equa) add_double(coll, temp); 
}
double mean(double_array *aFixedC)
{ 
  int i,size;
  double mn;
  double elem;
   size = sizeCDouble(aFixedC);
   mn=0;
  for(i=0;i<size;i++)
   {  elem=elementAtCDouble(aFixedC,i);
      mn=mn+elem;
   }
   return mn/size;
}

double variance(double_array *aFixedC)
{ 
  int i,size,den;
  double mn;
  double answer;
  double var;
  double elem;
   size = sizeCDouble(aFixedC);
   mn=mean(aFixedC);
   var=0;
   den =  max(1, size -1);
  for(i=0;i<size;i++)
   {  elem=elementAtCDouble(aFixedC,i);
      var=var+(pow(mn-(elem),2));
   }
   answer=var/den;
   return answer;
}



double lessthan(double_array *coll)
    {
     int i;
     int size;
     double min;
     double elem;
     size=sizeCDouble(coll);
     min=1000000000000;
     for(i=0;i<size;i++)
       { elem=elementAtCDouble(coll,i);
       if(elem<min) min=elem;
       }
      return min;
     }
double sum(double_array *coll)
    {
     int i;
     int size;
     double somma;
     double elem;
     size=sizeCDouble(coll);
     somma=0.0;
     for(i=0;i<size;i++)
       { 
       elem=elementAtCDouble(coll,i);
       somma=somma+elem;
       }
      return somma;
     }
         
void divide(double_array *coll, double denominator)
{ int i;
     for(i=0;i<coll->size;i++)
     coll->array[i]=(coll->array[i])/denominator;
}

void qSort_double_array(double_array *v,int first, int last)
{
  int i,j,index;
  double pivot;
  double ci;
  double cj;
  double aux;
  if (first<last) {
    i = first; j = last;
     index=(first+last)/2;
     pivot = elementAtCDouble(v,index);
 
    do {
      
      ci=elementAtCDouble(v,i);
      while (ci<pivot) {  i++;ci=elementAtCDouble(v,i);}
 
      cj=elementAtCDouble(v,j);
      while (cj>pivot) {j--;cj=elementAtCDouble(v,j);}
      if (i <= j) {
        aux=ci;
        v->array[i]=cj;
        v->array[j]=aux;
        i++, j--;
      }
    } while (i <= j);  
    qSort_double_array(v, first, j);
    qSort_double_array(v, i, last);
  }
}
