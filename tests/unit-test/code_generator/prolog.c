#include "xmachine_reader.h"
#include <stdio.h>
void read_intermediate_data(char *filename,char data[][MAXCHAR],int ind)
   { char aux[MAXCHAR];
    
     FILE *file;
     int index,i;
     file=fopen(filename,"r");
     if(!file) printf("could not open the intermediate data input");
     else 
     for(i=0;i<ind;i++) 
        { fscanf(file,"%d %s\n",&index,aux);
          //printf("car%d %s\n",index,aux);
          strcpy(data[index],aux);
        }
    }

Model *model;
Suites *suites;
FILE *file;
XMachines *xmachines;
Datatypes *datatypes;
Messages *messages;
Variables *constants;
Functions *functions;
char capitalized[MAXCHAR];
char new_path[MAXPATH];
char temp_path[MAXPATH];
 char primtype[4][10]={"int","char","float","double"};
 char specifier[4][10]={"%d","%c","%f","%lf"};

