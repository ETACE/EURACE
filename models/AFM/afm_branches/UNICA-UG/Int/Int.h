#ifndef INT_INCL
#define INT_INCL
#include "Stream.h"


void writeInt(int a, Stream *stream);
void serializeInt(int a, Stream *stream);

int deserializeInt( Stream *stream);
#endif
