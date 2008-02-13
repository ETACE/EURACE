# Makefile

CC=gcc
CFLAGS=-c -std=c99 -Wall
LIBS=-lm 
ADTRND=Random.c TestRandom.c
ADTRNDH=Random.h  TestRandom.h

ADTORD=Order.c TestOrder.c
ADTORDH=Order.h TestOrder.h

ADTINT=Int.c 
ADTINTH=Int.h 

ADTCO=COrder.c TestCOrder.c
ADTFCOH=COrder.h TestCOrder.h

ADTCL=ClearingMechanism.c TestClearingMechanism.c
ADTCLH=ClearingMechanism.h TestClearingMechanism.h

ADTDB=Double.c
ADTDBH=Double.h

ADTDBC=CDouble.c TestCDouble.c
ADTDBCH=CDouble.h TestCDouble.h


ADTA=Asset.c CAsset.c
ADTP=Portfolio.c Belief.c
ADTAH=Asset.h CAsset.h
ADTPH=Portfolio.h Belief.h

ADTST=Stream.c 
ADTSTH=Stream.h 
AG=Household.c TestHousehold.c 
AGH=Household.h TestHousehold.h 
AGC=ClearingHouse.c TestClearingHouse.c
AGCH=ClearingHouse.h TestClearingHouse.h


XM=memory.c messageboards.c partitioning.c 
XMH=header.h low_primes.h 

SOURCES= $(ADTORD) $(ADTRND)   $(ADTCO)  $(ADTDB) $(ADTDBC) $(ADTCL)   $(ADTA) $(ADTST) $(ADTINT) $(XM) $(ADTP) $(AG) $(AGC) LauncherTest.c Suites.c libcunit.a

DEPS=Makefile $(XMH)  $(ADTRNDH) $(ADTORDH) $(ADTCOH)  $(ADTDBH) $(ADTDBCH) $(ADTCLH)  $(ADTSTH)$(ADTAH) $(ADTINTH) $(ADTPH) $(AGH) $(AGCH) LauncherTest.h Suites.h


OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=LauncherTest
RM=rm -f

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o LauncherTest.exe main 


