#include "CDouble.h"
#define CONSTGROW 100


CDouble *newCDouble(int size)

{    CDouble *temp;
     temp=malloc(sizeof(CDouble));
     temp->basic=(double *)malloc(sizeof(double)*size);
     temp->size=size;
     emptyCDouble(temp);
     resetCDouble(temp);
     return temp;
}
int sizeCDouble(CDouble *coll )
{  
     return  coll ->index;
    }
    
    
void emptyCDouble(CDouble *coll )
{
    coll->index=0;
}

void resetCDouble(CDouble *coll )
{    int i;
     int size;
     size=coll->size;
      for(i=0;i<size;i++)
      coll->basic[i]=0;
     }

void addCDouble(CDouble *coll ,double elem)
{   if(!isFullCDouble(coll ))
       {
        coll ->basic[coll ->index]=elem;
        coll ->index++;
        }
    else {
          growCDouble(coll );
          addCDouble(coll ,elem);
     }
     }
     
     
double elementAtCDouble(CDouble *coll ,int index)
{
      return coll ->basic[index];
}


double firstCDouble(CDouble *coll )
{   
    return coll->basic[0];  
}


double lastCDouble(CDouble *coll )
{   
    return coll ->basic[(coll ->index)-1];
     
}


int isEmptyCDouble(CDouble *coll )
{   
    int answer;
    answer=((coll ->index)==0);
    return answer;
     
}

int isFullCDouble(CDouble *coll )
{   
    int answer;
    answer=(coll ->index)==(coll ->size);
    return answer;
     
}

void copyContentCD(CDouble *aDest,CDouble *aOrigin)
{ int i;
     for(i=0;i<aOrigin->index;i++)
      aDest->basic[i]=aOrigin->basic[i];
      aDest->index=aOrigin->index;
      
 }
 
 void growCDouble(CDouble *coll)
 {    double *dest;
      int i,size;
      size=(coll->size)+CONSTGROW;
      dest=(double *)malloc(sizeof(double)*size);
      for(i=0;i<coll->size;i++)
      dest[i]=coll->basic[i];
      for(i=coll->size;i<size;i++)
      dest[i]=0;
      coll->size=size;
      free(coll->basic);
      coll->basic=dest;
 }
      
void freeCDouble(CDouble *coll)
{    
      free(coll->basic);
      coll->basic=NULL;
      free(coll);
}


void addIncSortDouble(CDouble *coll,double value)
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
        if(!compareDouble(temp,coll->basic[i]))
              {current=&(coll->basic[i]);
              swapDouble(ptorder,current);
              }
          else cond=0;
        i++;
      }       
       addCDouble(coll, temp); 
      
}

void addIncSetSortDouble(CDouble *coll,double value)
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
        if(isEqualDouble(temp,coll->basic[i])) equa=0;
        else
        if(!compareDouble(temp,coll->basic[i])) 
             {current=&(coll->basic[i]);
              swapDouble(ptorder,current);
              }
          else cond=0;
        i++;
      }       
       if(equa) addCDouble(coll, temp); 
}
double mean(CDouble *aFixedC)
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

double variance(CDouble *aFixedC)
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
void writeCDouble(CDouble *coll, Stream *buffer)
{  
     char separator;
     int i;
     separator=',';
     writeInt(coll->index,buffer);
     addStream(buffer,separator);
     for(i=0;i<coll->index;i++)
     {
       writeDouble(elementAtCDouble(coll,i),buffer);
       addStream(buffer,separator);
     }
}

void serializeCDouble(CDouble *coll, Stream *buffer)
{    int i;
     serializeInt(coll->index,buffer);
     serializeInt(coll->size,buffer);
     for(i=0;i<coll->index;i++)
      serializeDouble(coll->basic[i],buffer);
}  

CDouble *deserializeCDouble( Stream *buffer)
{    int i,size;
     CDouble *coll;
   
     size=deserializeInt(buffer);
     coll=newCDouble(size);
     coll->size=deserializeInt(buffer);
     for(i=0;i<size;i++)
      addCDouble(coll,deserializeDouble(buffer));
      return coll;
}  

void divide(CDouble *coll, double denominator)
{ int i;
     for(i=0;i<coll->size;i++)
     coll->basic[i]=(coll->basic[i])/denominator;
}
