#include "Int.h"

void writeInt(int a, Stream *stream)
{
     char buffer[40];
       sprintf(buffer,"%d",a);
       addAllStream(stream,buffer,sizeof(int));
}

void serializeInt(int a, Stream *stream)
{
     char buffer[sizeof(int)];
        memcpy((void*)buffer,(void*) &a, sizeof(int));
       addAllStream(stream,buffer,sizeof(int));
}

int deserializeInt( Stream *stream)
{ int *presult;
  int result;
  presult=upTo(stream,sizeof(int));
  result=*presult;
  return result;
 }
