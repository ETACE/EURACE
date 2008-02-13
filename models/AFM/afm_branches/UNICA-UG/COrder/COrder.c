#include "COrder.h"
#define CONSTGROW 100
#define MINPRICE -1;
#define MAXPRICE 100000000;


COrder *newCOrder(int size)

{    COrder *temp;
     temp=malloc(sizeof(COrder));
     temp->array=(Order **)malloc(sizeof(Order *)*size);
     temp->total_size=size;
     emptyCOrder(temp);
     resetFullCOrder(temp);
     return temp;
}
int sizeCOrder(COrder *coll )
{  
     return  coll->size;
}
    
    
void emptyCOrder(COrder *coll )
{
    coll->size=0;
}
Order *nextCOrder(COrder *coll)
{   
    return coll->array[(coll->size)];
     
}
void resetFullCOrder(COrder *coll )
{    int i;
     int size;
     size=coll->total_size;
      for(i=0;i<size;i++) 
      coll->array[i]=NULL;
}

void resetCOrder(COrder *coll )
{    int i;
     int size;
     size=coll->size;
      for(i=0;i<size;i++)
      {free(coll->array[i]);
      coll->array[i]=NULL;
      }
      coll->size=0;
}

void addCOrder(COrder *coll ,Order *elem)
{   if(!isFullCOrder(coll ))
       {
        coll->array[coll->size]=elem;
        coll->size++;
        }
    else {
          growCOrder(coll );
          addCOrder(coll ,elem);
     }
 }
     
     



Order *firstCOrder(COrder *coll )
{   
    return coll->array[0];  
}


Order *lastCOrder(COrder *coll )
{   
    return coll->array[(coll->size)-1];
     
}


int isEmptyCOrder(COrder *coll )
{   
    int answer;
    answer=((coll->size)==0);
    return answer;
     
}

int isFullCOrder(COrder *coll )
{   
    int answer;
    answer=(coll ->total_size)==(coll ->size);
    return answer;
     
}

void copyContentCOrder(COrder *aDest,COrder *aOrigin)
{ int i;
     for(i=0;i<aOrigin->size;i++)
      aDest->array[i]=aOrigin->array[i];
      aDest->size=aOrigin->size;
      
 }
 
 void growCOrder(COrder *coll)
 {    Order **dest;
      int i,size;
      size=(coll->total_size)+CONSTGROW;
      dest=(Order **)malloc(sizeof(Order *)*size);
      for(i=0;i<coll->size;i++)
      dest[i]=coll->array[i];
      for(i=coll->size;i<size;i++)
      dest[i]=NULL;
      coll->total_size=size;
      free(coll->array);
      coll->array=dest;
 }
      
void freeCOrder(COrder *coll)
{    int i;
     int size;
     size=coll->size;
      for(i=0;i<size;i++)
      {free(coll->array[i]);
      coll->array[i]=NULL;
      }
      free(coll);
}

Order *removeCOrder(COrder * coll, int index)
{
	int i,size;
	Order *answer;
	size=sizeCOrder(coll);
	if(index==(size-1)) answer=coll->array[index]; 
	else
	{
        answer=coll->array[index];
		for(i = index; i < (size-1); i++)
	      coll->array[i] = coll->array[i+1];
    
	}
	coll->size--;
	return answer;
}
Order *elementAtCOrder(COrder *coll ,int index)
{ Order *answer;
  answer =coll->array[index];
  return answer;
}
      
int findCOrder(COrder *coll,int assetId)
{   int answer;
    Order *current;
    int found;
    found=0;
    int i;
    i=0;
    answer=-1;
    while(i<sizeCOrder(coll)&&(found==0))
    { current=elementAtCOrder(coll,i);
      found=((current->assetId)==assetId);
      if(found) answer=i;
      i++;
    }                    
    if(!found)  answer=-1;
    return answer;
}   

Order *removeWithId(COrder *coll, int assetId)
{
     int index;
     Order *answer;
     index=findCOrder(coll,assetId);
     if(index>-1) 
                  answer=removeCOrder(coll,index);
                  return answer;
}




void addOrder( COrder *coll, Order *ord)
{         
          Order *temp;
          Order *next;
          if(isFullCOrder(coll))
          { temp=newOrder();
            copyOrder(temp,ord);
            addCOrder(coll,temp);
           }
          else
          {
           next=nextCOrder(coll);
           if((next==NULL))
             {
               temp=newOrder();
               copyOrder(temp,ord);
               addCOrder(coll,temp);
             }
          else
            {  
             copyOrder(next,ord);
              coll->size++;
           }
          }
}

//Include newObject as one of the receiver's elements.  Answer newObject.
void addIncSortOrder(COrder *coll,Order *order)
{     
      int i,cond; 
      int size;
      Order temp;
      Order *ptorder;
      cond=1;
      ptorder=&temp;
      size=sizeCOrder(coll);
      i=0;
      copyOrder(ptorder,order);
     while(cond&&(i<size))
      { 
        if(!compareOrder(ptorder,coll->array[i])) 
              swapOrder(ptorder,coll->array[i]);
          else cond=0;
        i++;
      }       
       addOrder(coll, ptorder); 
      
}

void addDecSortOrder(COrder *coll,Order *order)
{     
      int i,cond; 
      int size;
      Order temp;
      Order *ptorder;
      cond=1;
      ptorder=&temp;
     
      i=size;
      size=sizeCOrder(coll);
      copyOrder(ptorder,order);
      addOrder(coll, ptorder); 
      
     while(cond&&(i==0))
      {  
        
        if(compareOrder(ptorder,coll->array[i])) 
              swapOrder(ptorder,coll->array[i]);
          else cond=0;
        i--;
      }       
}

double minPriceOrder(COrder *aFixedC)
{    double min;
     int size,i;
     Order *each;
     min = MAXPRICE;
     size=sizeCOrder(aFixedC);
     for (i=0;i<size;i++)	
      {  
         each=aFixedC->array[i];
         if(each->price < min) min = each->price;
      }
	return min;
}

double maxPriceOrder(COrder *aFixedC)
{    double max;
     int size,i;
     Order *each;
     max = MINPRICE;
     size=sizeCOrder(aFixedC);
     for (i=0;i<size;i++)	
      {  
         each=aFixedC->array[i];
         if(each->price > max) max = each->price;
      }
	return max;
}

void qSortCOrder(COrder *v, int first, int last){
  int i,j,index;
  Order *pivot;
  Order *ci;
  Order *cj;
  if (first<last) {
    i = first; j = last;
     index=(first+last)/2;
     pivot = elementAtCOrder(v,index);
 
    do {
      
      ci=elementAtCOrder(v,i);
      while (isLessOrder(ci,pivot)) {  i++;ci=elementAtCOrder(v,i);}
 
      cj=elementAtCOrder(v,j);
      while (isGreaterOrder(cj,pivot)) {j--;cj=elementAtCOrder(v,j);}
      if (i <= j) {
        swapOrder(ci, cj);
        i++, j--;
      }
    } while (i <= j);  
    qSortCOrder(v, first, j);
    qSortCOrder(v, i, last);
  }
}
void qSortCOrderDec(COrder *v, int first, int last){
  int i,j,index;
  Order *pivot;
  Order *ci;
  Order *cj;
  if (first<last) {
    i = first; j = last;
     index=(first+last)/2;
     pivot = elementAtCOrder(v,index);
 
    do {
      
      ci=elementAtCOrder(v,i);
      while (isGreaterOrder(ci,pivot)) {  i++;ci=elementAtCOrder(v,i);}
 
      cj=elementAtCOrder(v,j);
      while (isLessOrder(cj,pivot)) {j--;cj=elementAtCOrder(v,j);}
      if (i <= j) {
        swapOrder(ci, cj);
        i++, j--;
      }
    } while (i <= j);  
    qSortCOrderDec(v, first, j);
    qSortCOrderDec(v, i, last);
  }
}
/*
void writeCOrder(COrder *coll, Stream *buffer)
{  
     char separator;
     int i;
     separator=',';
     writeInt(coll->index,buffer);
     addStream(buffer,separator);
     for(i=0;i<coll->index;i++)
     {
       writeDouble(elementAtCD(coll,i),buffer);
       addStream(buffer,separator);
     }
}

void serializeCOrder(COrder *coll, Stream *buffer)
{    int i;
     serializeInt(coll->index,buffer);
     serializeInt(coll->size,buffer);
     for(i=0;i<coll->index;i++)
      serializeDouble(coll->basic[i],buffer);
}  

COrder *deserializeCOrder( Stream *buffer)
{    int i,size;
     COrder *coll;
   
     size=deserializeInt(buffer);
     coll=newCOrder(size);
     coll->size=deserializeInt(buffer);
     for(i=0;i<size;i++)
      addCOrder(coll,deserializeDouble(buffer));
      return coll;
}  
*/
