#include "Stream.h"
#define CONSTGROW 100


Stream *newStream(int size)

{    Stream *temp;
     temp=malloc(sizeof(Stream));
     temp->basic=(char *)malloc(sizeof(char)*size);
     temp->size=size;
     temp->pos=0;
     emptyStream(temp);
     resetStream(temp);
     return temp;
}
int sizeStream(Stream *coll )
{  
     return  coll ->index;
    }
    
    
void emptyStream(Stream *coll )
{
    coll->index=0;
}

void resetStream(Stream *coll )
{    int i;
     int size;
     size=coll->size;
      for(i=0;i<size;i++)
      coll->basic[i]=0;
     }
void resetPos(Stream *coll )
{
     coll->pos=0;
}
void* upTo(Stream *coll,int step)
{ void *pointer;
  pointer=&(coll->basic[coll->pos]);
  coll->pos=coll->pos+step;
  return pointer;
}
      

void addStream(Stream *coll ,char elem)
{   if(!isFullStream(coll ))
       {
        coll ->basic[coll ->index]=elem;
        coll ->index++;
        }
    else {
          growStream(coll );
          addStream(coll ,elem);
     }
     }

void addAllStream(Stream *coll, char *str,int size)
{ int len,i;
  len=size;
  for(i=0;i<len;i++)
  addStream(coll,str[i]);
        
} 
     
char elementAt(Stream *coll ,int index)
{
      return coll ->basic[index];
}


char firstFixed(Stream *coll )
{   
    return coll ->basic[0];  
}


char lastStream(Stream *coll )
{   char result;
    result=coll->basic[(coll->index)-1];
    return result;
     
}


int isEmptyStream(Stream *coll )
{   
    int answer;
    answer=((coll ->index)==0);
    return answer;
     
}

int isFullStream(Stream *coll )
{   
    int answer;
    answer=(coll ->index)==(coll ->size);
    return answer;
     
}

void copyContent(Stream *aDest,Stream *aOrigin)
{ int i;
     for(i=0;i<aOrigin->index;i++)
      aDest->basic[i]=aOrigin->basic[i];
      aDest->index=aOrigin->index;
      
}
 
void growStream(Stream *coll)
 {    char *dest;
      int i,size;
      size=(coll->size)+CONSTGROW;
      dest=(char *)malloc(sizeof(char)*size);
      for(i=0;i<coll->size;i++)
      dest[i]=coll->basic[i];
      for(i=coll->size;i<size;i++)
      dest[i]=0;
      coll->size=size;
      free(coll->basic);
      coll->basic=dest;
      }
      
void freeStream(Stream *coll)
{  
      free(coll->basic);
      coll->basic=NULL;
      free(coll);
}
