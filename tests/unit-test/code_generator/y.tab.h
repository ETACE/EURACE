/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CAPMESSAGENAME = 258,
     MESSAGENAME = 259,
     REPEAT = 260,
     XAGENTS = 261,
     XAGENTNAME = 262,
     XAGENTSVAR = 263,
     VARIABLES = 264,
     ALLVARIABLES = 265,
     MESSAGES = 266,
     DATATYPES = 267,
     IDENT = 268,
     BEG = 269,
     END = 270,
     CONSTANT = 271,
     CONSTANTS = 272,
     TYPE = 273,
     DTYPE = 274,
     NAME = 275,
     CAPNAME = 276,
     DIM = 277,
     EOL = 278,
     DATATYPENAME = 279,
     SUITENAME = 280,
     FUNCTIONS = 281,
     UTESTNAME = 282,
     FUNCTIONNAME = 283,
     IFSTATIC = 284,
     IFNOTLAST = 285,
     IFNOTSTATIC = 286,
     IFPRIMTYPE = 287,
     IFINAGENT = 288,
     IFNOTPRIMTYPE = 289,
     PRIMITIVETYPES = 290,
     PRIMTYPE = 291,
     SPECIFIER = 292,
     UNITTESTS = 293,
     SUITES = 294,
     UAGENTNAME = 295,
     SUITEPATH = 296,
     XAGENTHEADERS = 297
   };
#endif
/* Tokens.  */
#define CAPMESSAGENAME 258
#define MESSAGENAME 259
#define REPEAT 260
#define XAGENTS 261
#define XAGENTNAME 262
#define XAGENTSVAR 263
#define VARIABLES 264
#define ALLVARIABLES 265
#define MESSAGES 266
#define DATATYPES 267
#define IDENT 268
#define BEG 269
#define END 270
#define CONSTANT 271
#define CONSTANTS 272
#define TYPE 273
#define DTYPE 274
#define NAME 275
#define CAPNAME 276
#define DIM 277
#define EOL 278
#define DATATYPENAME 279
#define SUITENAME 280
#define FUNCTIONS 281
#define UTESTNAME 282
#define FUNCTIONNAME 283
#define IFSTATIC 284
#define IFNOTLAST 285
#define IFNOTSTATIC 286
#define IFPRIMTYPE 287
#define IFINAGENT 288
#define IFNOTPRIMTYPE 289
#define PRIMITIVETYPES 290
#define PRIMTYPE 291
#define SPECIFIER 292
#define UNITTESTS 293
#define SUITES 294
#define UAGENTNAME 295
#define SUITEPATH 296
#define XAGENTHEADERS 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 113 "code_generator.y"
{                                     /* this is the data union  */
    char name[41500];                       /* names                   */
}
/* Line 1489 of yacc.c.  */
#line 137 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

