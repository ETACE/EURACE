# $Id: Makefile 751 2008-03-18 13:17:01Z lsc $
# 
# Copyright (c) 2008 STFC Rutherford Appleton Laboratory 
# Author: Lee-Shawn Chin 
# Date  : Feb 2008
#
#
# Note:
#  - This is an attempt at using non-recursive make
#  - Requires GNU Make
#  - Ought to accomodate a better use of -j and -k options , although this project
#    may not be large enough to warrant them

# ========= User Config ====================

CC           = gcc
PARALLEL_CC  = mpicc
CFLAGS       = -Wall -pedantic -O3 -DNDEBUG -fno-common
DEBUG_CFLAGS = -pg -Wall -pedantic -fno-common

# ========= Project Config =================

# Directory to write output libraries
LIB_OUTPUT_DIR = ./lib

# Directory where all header files are stored
INCLUDE_DIR = ./include

# list modules in this project
MODULES = serial parallel utils

OUTPUTS = libmboard_s.a libmboard_p.a

# Options for splint
SPLINT_OPTIONS = -weak

# MPI Include dir (used to provide splint with include dir)
MPI_DIR = /usr/local/mpich2
MPI_INCLUDE_DIR = $(MPI_DIR)/include

# --------------------------------------------

# Allow users to append params during make
APPEND = -DNONE

# For calculating dependencies on common makefiles
MAKEFILES = Makefile include.mk

# Default target should build both serial and parallel libraries
all: serial parallel

# target names not associated to actual files
.PHONY: all clean serial parallel debug test doc

# all source refer to header files in ./include
CFLAGS += $(APPEND) -I$(INCLUDE_DIR) 
DEBUG_CFLAGS += $(APPEND)  -I$(INCLUDE_DIR)

# prepend paths to $(OUTPUTS)
OUTPUTS_FULL = $(patsubst %,$(LIB_OUTPUT_DIR)/%,$(OUTPUTS))

# config.mk from each module will append to this var
SRC := 

# Include config from each module
include $(patsubst %,src/%/config.mk,$(MODULES))

# All object files
OBJ := $(SRC:.c=.o)

# ----------- Custom Targets ----------

clean:
	rm -f $(OUTPUTS_FULL) $(OBJ)
	
debug: CFLAGS = $(DEBUG_CFLAGS)
debug: clean all

serial: $(LIB_OUTPUT_DIR)/libmboard_s.a

parallel: CC = $(PARALLEL_CC)
parallel: $(LIB_OUTPUT_DIR)/libmboard_p.a

test:
	(cd tests && make vclean all)
	
splint:
	@echo "Performing static analysis of serial implementation code ... "
	@echo "-------------------------------------------------------------"
	splint $(SPLINT_OPTIONS) -I$(INCLUDE_DIR) src/utils/*.c src/serial/*.c
	@echo ""
	@echo "Performing static analysis of parallel implementation code ... "
	@echo "---------------------------------------------------------------"
	splint $(SPLINT_OPTIONS) -I$(INCLUDE_DIR) -I$(MPI_INCLUDE_DIR) src/utils/*.c src/parallel/*.c
	
doc: Doxyfile_user Doxyfile_developer_serial Doxyfile_developer_parallel
	@mkdir -p doc/developer &> /dev/null
	@echo "Generating User documentation in ./doc/user"
	@doxygen Doxyfile_user
	@echo "Generating Developer documentation (serial code) in ./doc/developer/serial"
	@doxygen Doxyfile_developer_serial
	@echo "Generating Developer documentation (parallel code) in ./doc/developer/parallel"
	@doxygen Doxyfile_developer_parallel
	
$(LIB_OUTPUT_DIR)/libmboard_s.a: $(serial_OBJ) $(utils_OBJ)
	ar rcs $@ $(serial_OBJ) $(utils_OBJ)
	@echo -e "\n++ Serial MBoard Library written to: $@\n"
	
$(LIB_OUTPUT_DIR)/libmboard_p.a: $(parallel_OBJ) $(utils_OBJ)
	ar rcs $@ $(parallel_OBJ) $(utils_OBJ)
	@echo -e "\n++ Parallel MBoard Library written to: $@\n"
