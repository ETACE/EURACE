#############################################################
#
# Makefile     : Makefile for code generator
# Author       : MF.locci
# Last Updated : 2009/5/05
#
# If you use bison, you may have to supply an alloca
#
#############################################################

CC       = gcc -g
LEX      = flex -I 
YACC     = bison -d -y
ALLOCA   =

############################################################
#
# DO NOT CHANGE ANYTHING FROM HERE ON !!!!!!!!! 
#
############################################################

all: code_generator

code_generator:  code_generator.y code_generator.lex
	$(YACC) code_generator.y
	$(LEX)  code_generator.lex 
	$(CC) -o code_generator lex.yy.c y.tab.c $(ALLOCA) -ll -lm


clean:
	rm -f *.BAK *.o core *~* *.a 
	rm -f *.tab.h *.tab.c
	rm -f code_generator
