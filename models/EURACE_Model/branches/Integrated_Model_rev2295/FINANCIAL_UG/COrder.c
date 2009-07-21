#include "my_library_header.h"
#define MINPRICE -1;
#define MAXPRICE 100000000;



Order_array *newCOrder(int size)

{    Order_array *temp;
     temp=malloc(sizeof(Order_array));
     temp->array=(Order *)malloc(sizeof(Order )*size);
     temp->total_size=size;
     reset_Order_array(temp);
     return temp;
}

int sizeCOrder(Order_array *coll )
{  
     return  coll->size;
}
    
    

Order *nextCOrder(Order_array *coll)
{   
    return &(coll->array[(coll->size)]);
     
}




void addOrder(Order_array *coll ,Order *elem)
{  
 add_Order(coll, elem->issuer, elem->quantity,  elem->price,  elem->assetId);
     
 }
     
     



Order *firstCOrder(Order_array *coll )
{   
    return &(coll->array[0]);  
}


Order *lastCOrder(Order_array *coll )
{   
    return &(coll->array[(coll->size)-1]);
     
}


int isEmptyCOrder(Order_array *coll )
{   
    int answer;
    answer=((coll->size)==0);
    return answer;
     
}

int isFullCOrder(Order_array *coll )
{   
    int answer;
    answer=(coll ->total_size)==(coll ->size);
    return answer;
     
}


 

      



Order *elementAtCOrder(Order_array *coll ,int index)
{ Order *answer;
  answer =&(coll->array[index]);
  return answer;
}
      
int findCOrder(Order_array *coll,int assetId)
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


double minPriceOrder(Order_array *aFixedC)
{    double min;
     int size,i;
     Order *each;
     min = MAXPRICE;
     size=sizeCOrder(aFixedC);
     for (i=0;i<size;i++)	
      {  
         each=&(aFixedC->array[i]);
         if(each->price < min) min = each->price;
      }
	return min;
}

double maxPriceOrder(Order_array *aFixedC)
{    double max;
     int size,i;
     Order *each;
     max = MINPRICE;
     size=sizeCOrder(aFixedC);
     for (i=0;i<size;i++)	
      {  
         each=&(aFixedC->array[i]);
         if(each->price > max) max = each->price;
      }
	return max;
}

void qSortCOrder(Order_array *v, int first, int last){
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

void randomize(Order_array *v, int first, int last)
{
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
      while (next()<0.5) {  i++;ci=elementAtCOrder(v,i);}
 
      cj=elementAtCOrder(v,j);
      while (next()>0.5) {j--;cj=elementAtCOrder(v,j);}
      if (i <= j) {
        swapOrder(ci, cj);
        i++, j--;
      }
    } while (i <= j);  
    randomize(v, first, j);
    randomize(v, i, last);
  }
}
void qSortCOrderDec(Order_array *v, int first, int last){
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

