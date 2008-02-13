# Makefile

CC=gcc
CFLAGS=-c -std=c99 -Wall
LIBS=-lm
SOURCES=main.c memory.c xml.c messageboards.c partitioning.c 
DEPS=Makefile header.h low_primes.h

OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main
RM=rm -f

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o main.exe main
