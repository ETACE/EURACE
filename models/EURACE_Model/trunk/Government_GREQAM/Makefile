# Makefile template file for FLAME
#
# FLAME is the FLAME source files
# SOURCE is the user source files
#
# The assumption is that the user only provides C files
# and a model files <file>.xml
#
DEFINES       = -DNONE
LIBMBOARD_DIR = libmboard
LIBMBOARD_INC = $(LIBMBOARD_DIR)/include
LIBMBOARD_LIB = $(LIBMBOARD_DIR)/lib

CC      = gcc
CFLAGS  = -c -std=c99 -Wall -I$(LIBMBOARD_INC) ${DEFINES} 

CFLAGS += -D_DEBUG_MODE -g # uncomment this line for DEBUG runs
#CFLAGS += -DNDEBUG -O3     # uncomment this line for PRODUCTION runs

LDFLAGS = -L$(LIBMBOARD_LIB)
LIBS    = -lmboard_s  -lm

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c rules.c timing.c

#FLAME auxilary files
AUX 	= stategraph.dot Doxyfile

# FLAME generated model files
SOURCES =  Government_Functions.c 
HEADERS = header.h low_primes.h mboard.h  Household_agent_header.h  Firm_agent_header.h  Government_agent_header.h  Central_Bank_agent_header.h  

DEPS    = Makefile header.h low_primes.h

OBJECTS = $(SOURCES:.c=.o) $(FLAME:.c=.o)
EXECUTABLE = main
RM = rm -f

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
