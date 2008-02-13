#ifndef  STR_INCL 
#define STR_INCL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stream Stream;

struct Stream
{
       int index;
       int size;
       int pos;
       char *basic;
};

Stream *newStream(int size);       


void emptyStream(Stream *coll );

void addStream(Stream *coll ,char elem);

void addAllStream(Stream *coll, char *str,int size);
void firstStream(Stream *coll );

int sizeStream(Stream *coll );

char lastStream(Stream *coll );
void* upTo(Stream *coll,int step);


int isEmptyStream(Stream *coll );

int isFullStream(Stream *coll );

void growStream(Stream *aFixed);

void resetStream(Stream *coll );

void freeStream(Stream *aFixed);

char elementAt(Stream *coll ,int index);
#endif

