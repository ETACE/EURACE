CC         = gcc
CFLAGS     = -c -g -std=c99 -Wall -pedantic  
LDFLAGS    =
LIBS       = -lxml2 -lm 
SOURCES    = xmachine_reader.c main_code.c
OBJECTS    = $(SOURCES:.c=.o)
EXECUTABLE = test_generator
DEPS       = Makefile xmachine_reader.h 


all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@


