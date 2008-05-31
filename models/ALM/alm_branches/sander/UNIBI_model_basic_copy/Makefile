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
SOURCES =  Firm_functions.c  Firm_financial_management_functions.c  Household_functions.c  Bank_financial_management_functions.c  Clearinghouse_financial_management_functions.c  Mall_functions.c  IGfirm_functions.c  Market_Research_functions.c  my_library_functions.c 
HEADERS = header.h low_primes.h  Firm_agent_header.h  Household_agent_header.h  Mall_agent_header.h  IGFirm_agent_header.h  Market_Research_agent_header.h  Clearinghouse_agent_header.h  Bank_agent_header.h  

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
