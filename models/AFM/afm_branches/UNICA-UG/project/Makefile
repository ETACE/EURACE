# Makefile

CC=gcc
CFLAGS=-c -std=c99 -Wall
LIBS=-lm
SOURCES=main.c memory.c messageboards.c xml.c partitioning.c   Household.c ClearingHouse.c Asset.c Belief.c Portfolio.c ClearingMechanism.c CAsset.c Double.c CDouble.c Order.c COrder.c Int.c Random.c Eurostat.c Stream.c
DEPS=Makefile header.h low_primes.h  Household.h  ClearingHouse.h  Asset.h  Portfolio.h  ClearingMechanism.h  CAsset.h  Belief.h Double.h  CDouble.h  Order.h  COrder.h  Random.h Int.h  Eurostat.h Stream.h

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
