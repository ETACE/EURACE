#include "my_library_header.h"




int sizeCBond(Bond_array *coll )
{  
     return  coll->size;
}
    

int isPresentCBond(Bond_array *coll, int index)
{
    int answer,size;
    size=sizeCBond(coll);
    answer=index<size;
    return answer;
}


Bond *lastCBond(Bond_array *coll )
{   
    return &(coll ->array[(coll ->size)-1]);
     
}



int isEmptyCBond(Bond_array *coll )
{   
    int answer;
    answer=((coll ->size)==0);
    return answer;
     
}

int isFullCBond(Bond_array *coll )
{   
    int answer;
    answer=(coll ->total_size)==(coll ->size);
    return answer;
     
}

 

Bond *elementAtCBond(Bond_array *coll ,int index)
{ Bond *answer;
  answer =&(coll->array[index]);
  return answer;
}



int findCBond(Bond_array *coll,int id)
{   int answer;
    Bond *current;
    int found;
    found=0;
    int i;
    i=0;
    answer=-1;
    while(i<sizeCBond(coll)&&(found==0))
    { current=elementAtCBond(coll,i);
      found=((current->id)==id);
      if(found) answer=i;
      i++;
    }                    
    if(!found)  answer=-1;
    return answer;
} 

 
