# Makefile template file for FLAME
#
# FLAME is the FLAME source files
# SOURCE is the user source files
#
# The assumption is that the user only provides C files
# and a model files <file>.xml
#
DEFINES=-DNONE

CC=gcc


CFLAGS=-c -std=c99 -Wall ${DEFINES}
LDFLAGS = 
LIBS=-lm

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c 
#FLAME auxilary files
AUX 	= dgraph.dot dgraph.svg

# FLAME generated model files
SOURCES =  Household_ewa_functions.c  Firm_ewa_functions.c  ClearingHouseMechanism_ewa_functions.c  LimitOrderBook_ewa_functions.c  FinancialAgent_ewa_functions.c  mylibraryfunctions.c 
HEADERS = header.h low_primes.h  Household_agent_header.h  Firm_agent_header.h  Bank_agent_header.h  ClearingHouse_agent_header.h  LimitOrderBook_agent_header.h  Government_agent_header.h  FinancialAgent_agent_header.h  

DEPS=Makefile header.h low_primes.h

OBJECTS=$(SOURCES:.c=.o) $(FLAME:.c=.o)
EXECUTABLE=main
RM=rm -f

all: $(SOURCES) $(FLAME) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(EXECUTABLE) $(EXECUTABLE).exe
vclean:
	$(RM) main $(EXECUTABLE) $(EXECUTABLE).exe *.o  $(FLAME) $(HEADERS)  $(AUX) Makefile
