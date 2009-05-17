#include <stdio.h>
#include <string.h>
#include "compileNode.h"
#include "tags.h"
#include <stdlib.h>

#define STRLEN 100
#define MAX 100


int main(int argc,char *arg[])
 {  
    IntegrityTest  *test;
    test=(IntegrityTest *)malloc(sizeof(IntegrityTest ));
    char filename[STRLEN]; 
    initialize_integrity(test);
    if( argc<1) printf("Error - input commands file must be specified");
    else
    if( argc<2) printf("Error - output  file must be specified");
    else
     {
       strcpy(filename,arg[1]);
       printf("opening the file %s\n",filename); 
       compile_test_rules(filename,test);
       strcpy(filename,arg[2]);
       readModel(test,filename);
     }
   
   return 0;
 }
     
