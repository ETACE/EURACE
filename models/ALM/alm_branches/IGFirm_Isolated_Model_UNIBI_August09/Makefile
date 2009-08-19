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
LIBS    = -lmboard_sd  -lm

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c rules.c timing.c

#FLAME auxilary files
AUX 	= stategraph.dot stategraph_colour.dot process_order_graph.dot Doxyfile

# FLAME generated model files
SOURCES =  my_library_functions.c  Cons_Goods_UNIBI/Firm_Producer_Functions.c  Cons_Goods_UNIBI/Household_Consumer_Functions.c  Cons_Goods_UNIBI/Mall_functions.c  Cons_Goods_UNIBI/Mall_aux_functions.c  Credit_UNIBI/Bank_Credit_Functions_Dummy.c  Credit_UNIBI/Firm_Credit_Functions_Dummy.c  Credit_UNIBI/IGFirm_Credit_Functions_Dummy.c  Credit_UNIBI/Central_Bank_Credit_Functions_Dummy.c  Financial_Management_UNIBI/Firm_Financial_Management_Functions.c  Financial_Management_UNIBI/IGFirm_Financial_Management_Functions.c  Inv_Goods_UNIBI/IGFirm_Producer_Functions.c  Labour_UNIBI/Firm_Employer_Functions.c  Labour_UNIBI/IGFirm_Employer_Functions.c  Labour_UNIBI/Household_Employee_Functions.c  Labour_UNIBI/Labour_aux_functions.c  Statistical_Office_UNIBI/Firm_Statistics_Functions.c  Statistical_Office_UNIBI/Household_Statistics_Functions.c  Statistical_Office_UNIBI/Eurostat_Functions.c  Statistical_Office_UNIBI/Eurostat_aux_functions.c  Statistical_Office_UNIBI/IGFirm_Statistics_Functions.c  Statistical_Office_UNIBI/Government_Statistics_Functions.c  Government_GREQAM/Government_Functions.c  Financial_UNIBI/Firm_Financial_Market_Functions.c  Financial_UNIBI/Household_Financial_Market_Functions.c  Financial_UNIBI/Government_Financial_Market_Functions.c 
HEADERS = header.h low_primes.h mboard.h  Firm_agent_header.h  Household_agent_header.h  Mall_agent_header.h  IGFirm_agent_header.h  Eurostat_agent_header.h  Bank_agent_header.h  Government_agent_header.h  Central_Bank_agent_header.h 

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
