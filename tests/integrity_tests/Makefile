# Makefile for xparserCC         = gcc
CFLAGS     = -c -g -Wall -I /media/disk/xmachine/integrity_tests  -L /media/disk/xmachine/integrity_tests
LDFLAGS    =
LIBS       = -lxml2 -lm
SOURCES    = main.c compileNode.c tags.c
OBJECTS    = $(SOURCES:.c=.o)
EXECUTABLE = integrity
DEPS       = Makefile compileNode.h tags.h
RM         = rm -f

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o integrity.exe integrity

