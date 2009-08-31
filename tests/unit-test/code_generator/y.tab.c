/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 5 "code_generator.y"

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#define MAXDIM 120000
#define MAXCHAR 300
extern int  yylexlinenum;                   /* these are in YYlex      */
extern char *yytext;                        /* current token           */
extern FILE *yyin;
char *guard;
int ind;
FILE *file;
FILE *file_code;
char file_def[MAXCHAR];
char file_name_data[MAXCHAR];
char file_name[MAXCHAR];
  char sub_ext[10];
void read_and_write_external(FILE *file_code,char *name)
 { FILE *file; char c;
   file=fopen(name,"r");
   while(fscanf(file,"%c",&c)!=EOF)
    fprintf(file_code,"%c",c);
   fclose(file);
  
 }

void extract_name_ext(char *complete_name, char *name, char *extension)
  {
    int i,j,k,found;
    i=0;
    k=0;j=0;
    found=0;
    while(complete_name[i]!='\0')
      {
        
        if(!found) { name[k]=complete_name[i]; k++;}
                   else {extension[j]=complete_name[i]; j++; }
         
        i++;
        if((complete_name[i]=='.')&&(!found)) {found=1;i++;}
       
      }
   name[k]='\0';
   extension[j]='\0';
 }
void open_input_file(char *file_name)
{
  yyin      = NULL; 
  while(yyin == NULL){
    if(file_name){
      yyin = fopen(file_name,"r");
      if(yyin == NULL){
        printf("Unable to open \"%s\"\n",file_name);
      }
    } else {
      printf("stdin\n");
      yyin = stdin;
      break;
    }
  }
}
int copy_file(char *from_name,char *to_name )
 {FILE *from, *to;
  char ch;


  /* open source file */
  if((from = fopen(from_name, "rb"))==NULL) {
    printf("Cannot open source file.\n");
    return 1;
  }

  /* open destination file */
  if((to = fopen(to_name, "wb"))==NULL) {
    printf("Cannot open destination file%s.\n",to_name);
    return 1;
  }
  /* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
      return 1;
    }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      return 1;
    }
  }

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
    return 1;
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
    return 1;
  }

  return 0;
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 113 "code_generator.y"
{                                     /* this is the data union  */
    char name[41500];                       /* names                   */
}
/* Line 187 of yacc.c.  */
#line 292 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 305 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  81

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    14,    17,    20,
      21,    25,    30,    35,    40,    45,    50,    55,    61,    63,
      65,    67,    69,    71,    73,    75,    77,    79,    81,    83,
      86,    89,    91,    94,    97,   100,   103,   105,   107,   109,
     111,   113,   115,   117,   119,   121,   123,   125,   127,   129,
     131,   133,   135
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    47,    -1,    48,    -1,    50,
      -1,    50,    45,    -1,    45,    50,    -1,    45,    45,    -1,
      -1,    14,    45,    15,    -1,    29,    23,    46,    23,    -1,
      31,    23,    46,    23,    -1,    30,    23,    46,    23,    -1,
      33,    23,    46,    23,    -1,    32,    23,    46,    23,    -1,
      34,    23,    46,    23,    -1,     5,    49,    23,    46,    23,
      -1,     6,    -1,    11,    -1,     9,    -1,    35,    -1,    17,
      -1,    38,    -1,    39,    -1,    26,    -1,    42,    -1,    10,
      -1,    12,    -1,    50,    16,    -1,    16,    50,    -1,    16,
      -1,    51,    50,    -1,    50,    51,    -1,    50,    23,    -1,
      23,    50,    -1,    23,    -1,    20,    -1,    18,    -1,    36,
      -1,    37,    -1,    19,    -1,    22,    -1,     7,    -1,    24,
      -1,    27,    -1,    40,    -1,    28,    -1,     4,    -1,    25,
      -1,    41,    -1,     3,    -1,    21,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   172,   172,   191,   191,   191,   191,   191,   191,   191,
     195,   197,   201,   205,   209,   213,   217,   222,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   396,
     406,   416,   425,   426,   427,   428,   429,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   450
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CAPMESSAGENAME", "MESSAGENAME",
  "REPEAT", "XAGENTS", "XAGENTNAME", "XAGENTSVAR", "VARIABLES",
  "ALLVARIABLES", "MESSAGES", "DATATYPES", "IDENT", "BEG", "END",
  "CONSTANT", "CONSTANTS", "TYPE", "DTYPE", "NAME", "CAPNAME", "DIM",
  "EOL", "DATATYPENAME", "SUITENAME", "FUNCTIONS", "UTESTNAME",
  "FUNCTIONNAME", "IFSTATIC", "IFNOTLAST", "IFNOTSTATIC", "IFPRIMTYPE",
  "IFINAGENT", "IFNOTPRIMTYPE", "PRIMITIVETYPES", "PRIMTYPE", "SPECIFIER",
  "UNITTESTS", "SUITES", "UAGENTNAME", "SUITEPATH", "XAGENTHEADERS",
  "$accept", "input", "expression", "block", "ifexpr", "forexp",
  "iteration_expr", "c_code", "identifier", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    45,    45,    45,    45,    45,
      46,    47,    47,    47,    47,    47,    47,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     2,     2,     2,     0,
       3,     4,     4,     4,     4,     4,     4,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,    51,    48,     0,    43,    31,    38,    41,    37,    52,
      42,    36,    44,    49,    45,    47,     0,     0,     0,     0,
       0,     0,    39,    40,    46,    50,     0,     2,     3,     4,
       5,     0,    18,    20,    27,    19,    28,    22,    25,    21,
      23,    24,    26,     0,    30,    35,     0,     0,     0,     0,
       0,     0,     1,     8,     5,    29,    34,     6,    33,    32,
       0,    29,    34,    33,     9,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    13,    12,    15,    14,    16,    17,
      10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    26,    53,    65,    28,    29,    43,    30,    31
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -28
static const yytype_int16 yypact[] =
{
      92,   -28,   -28,    -2,   -28,   166,   -28,   -28,   -28,   -28,
     -28,   166,   -28,   -28,   -28,   -28,   -21,   -18,   -12,   -11,
     -10,    -9,   -28,   -28,   -28,   -28,    16,    92,   -28,   -28,
     131,   166,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,    -4,   192,   192,     6,     6,     6,     6,
       6,     6,   -28,    92,   131,   166,   166,    92,   166,   192,
       6,   -28,   -28,   -28,    92,     0,     2,     5,     7,    11,
      12,    15,    53,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -28,   -28,     1,    -6,   -28,   -28,   -28,    -5,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      44,    27,    46,    58,    32,    47,    45,    33,    34,    35,
      36,    48,    49,    50,    51,    37,    52,    63,    63,    60,
      64,     0,    54,    73,    38,    74,    59,    58,    75,     0,
      76,    57,    63,    39,    77,    78,    40,    41,    79,     0,
      42,    66,    67,    68,    69,    70,     0,     0,    54,     0,
      44,    45,    54,    59,    71,    57,     1,     2,     3,     0,
       4,     0,     0,     0,     0,    72,     0,    54,    80,     5,
       0,     6,     7,     8,     9,    10,    11,    12,    13,     0,
      14,    15,    16,    17,    18,    19,    20,    21,     0,    22,
      23,     0,     0,    24,    25,     1,     2,     3,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     0,
       6,     7,     8,     9,    10,    11,    12,    13,     0,    14,
      15,    16,    17,    18,    19,    20,    21,     0,    22,    23,
       0,     0,    24,    25,     1,     2,     3,     0,     4,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,     6,
       7,     8,     9,    10,    56,    12,    13,     0,    14,    15,
      16,    17,    18,    19,    20,    21,     0,    22,    23,     1,
       2,    24,    25,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     6,     7,     8,     9,    10,    11,
      12,    13,     0,    14,    15,     1,     2,     0,     0,     4,
       0,     0,    22,    23,     0,     0,    24,    25,    61,     0,
       6,     7,     8,     9,    10,    62,    12,    13,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,    22,    23,
       0,     0,    24,    25
};

static const yytype_int8 yycheck[] =
{
       5,     0,    23,    30,     6,    23,    11,     9,    10,    11,
      12,    23,    23,    23,    23,    17,     0,    44,    45,    23,
      14,    -1,    27,    23,    26,    23,    31,    54,    23,    -1,
      23,    30,    59,    35,    23,    23,    38,    39,    23,    -1,
      42,    47,    48,    49,    50,    51,    -1,    -1,    53,    -1,
      55,    56,    57,    58,    60,    54,     3,     4,     5,    -1,
       7,    -1,    -1,    -1,    -1,    64,    -1,    72,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    36,
      37,    -1,    -1,    40,    41,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      -1,    -1,    40,    41,     3,     4,     5,    -1,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    25,    -1,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    36,    37,     3,
       4,    40,    41,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,     3,     4,    -1,    -1,     7,
      -1,    -1,    36,    37,    -1,    -1,    40,    41,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,    37,
      -1,    -1,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,    16,    18,    19,    20,    21,
      22,    23,    24,    25,    27,    28,    29,    30,    31,    32,
      33,    34,    36,    37,    40,    41,    44,    45,    47,    48,
      50,    51,     6,     9,    10,    11,    12,    17,    26,    35,
      38,    39,    42,    49,    50,    50,    23,    23,    23,    23,
      23,    23,     0,    45,    50,    16,    23,    45,    51,    50,
      23,    16,    23,    51,    14,    46,    46,    46,    46,    46,
      46,    46,    45,    23,    23,    23,    23,    23,    23,    23,
      15
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 172 "code_generator.y"
    {     char aux[400];
            
                   sprintf(aux,"\nint generate_%s_%s_code()\n{\n",sub_ext,file_name);
                   strcpy((yyval.name),aux);
                   sprintf(aux,"char car[%d][MAXCHAR];\n char path[MAXPATH];\n read_intermediate_data(\"%s\",car,%d);\n",ind,file_name_data,ind);
                   strcat((yyval.name),aux);
                  sprintf(aux,"file=fopen(\"%s\",\"w\");\n",file_def);
                   strcat((yyval.name),aux);
           
                   strcat((yyval.name),(yyvsp[(1) - (1)].name)); 
                   sprintf(aux,"fclose(file);\nffind_and_substitute(\"%s\");\n",file_def);
                   strcat((yyval.name),aux);
                   sprintf(aux,"strcpy(path,new_path);\nstrcat(path,\"%s\");\n",file_def);
                   strcat((yyval.name),aux);
                   sprintf(aux,"copy_file(\"%s\",path);\n",file_def);
                   strcat((yyval.name),aux);
                   strcat((yyval.name),"   return 0;\n}\n");fprintf(file_code,"%s",(yyval.name));}
    break;

  case 3:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (1)].name));}
    break;

  case 4:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (1)].name));}
    break;

  case 5:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (1)].name));}
    break;

  case 6:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (2)].name));strcat((yyval.name),(yyvsp[(2) - (2)].name));}
    break;

  case 7:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (2)].name));strcat((yyval.name),(yyvsp[(2) - (2)].name));}
    break;

  case 8:
#line 191 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (2)].name));strcat((yyval.name),(yyvsp[(2) - (2)].name));}
    break;

  case 9:
#line 191 "code_generator.y"
    {strcpy((yyval.name)," ");}
    break;

  case 10:
#line 195 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(2) - (3)].name)); }
    break;

  case 11:
#line 197 "code_generator.y"
    {strcpy((yyval.name),"if(variable->dim>0)\n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 12:
#line 201 "code_generator.y"
    {strcpy((yyval.name),"if(variable->dim==0)\n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 13:
#line 205 "code_generator.y"
    {strcpy((yyval.name),"if((variables->index)>j)\n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 14:
#line 209 "code_generator.y"
    {strcpy((yyval.name),"if(find_variable(variables,xvariable->name)>=0) \n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 15:
#line 213 "code_generator.y"
    {strcpy((yyval.name),"if((strcmp(variable->type,\"int\")==0)||(strcmp(variable->type,\"double\")==0)||(strcmp(variable->type,\"float\")==0)||(strcmp(variable->type,\"char\")==0))\n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 16:
#line 217 "code_generator.y"
    {strcpy((yyval.name),"if(!((strcmp(variable->type,\"int\")==0)||(strcmp(variable->type,\"double\")==0)||(strcmp(variable->type,\"float\")==0)||(strcmp(variable->type,\"char\")==0)))\n{\n");
                          strcat((yyval.name),(yyvsp[(3) - (4)].name));
                          strcat((yyval.name),"\n}\n");
                          }
    break;

  case 17:
#line 223 "code_generator.y"
    {  char aux[300];
                                          strcpy(guard,"");
                                        
                                        if(strcmp((yyvsp[(2) - (5)].name),"xagents")==0) 
                                          {strcpy(guard,"{\n  XMachine *xmachine;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<=xmachines->index;i++)\n");
                                           strcat(guard,"  {\nxmachine=&xmachines->list[i];\n");
                                           strcat(guard,"variables=&xmachine->variables;\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                          if(strcmp((yyvsp[(2) - (5)].name),"xagentheaders")==0) 
                                          {strcpy(guard,"{\n  XMachine *xmachine;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"  FILE  *file;\n");
                                           strcat(guard,"  char local_path[100];\n");
                                           sprintf(aux,"char aux[]=\"%s\";\n",file_def);
                                           strcat(guard,aux);
                                           strcat(guard,"for(i=0;i<=xmachines->index;i++)\n");
                                           strcat(guard,"  {\nxmachine=&xmachines->list[i];\n");
                                           strcat(guard,"variables=&xmachine->variables;\n");
                                           strcat(guard,"strcpy(local_path,xmachine->name);\n");
                                           strcat(guard,"strcat(local_path,aux);\n");
                                           strcat(guard,"file=fopen(local_path,\"w\");\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"fclose(file);\n");
                                           strcat(guard,"ffind_and_substitute(local_path);\n");
                                           strcat(guard,"strcpy(path,new_path);\n strcat(path,local_path);\n");
                                           strcat(guard,"copy_file(local_path,path);\n");
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                         if(strcmp((yyvsp[(2) - (5)].name),"utests")==0) 
                                          {strcpy(guard,"{\n  UnitaryTest *utest;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  Messages *messages;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<=suite->index;i++)\n");
                                           strcat(guard,"  {\nutest=&suite->list[i];\n");
                                           strcat(guard,"variables=&utest->variables;\n");
                                           strcat(guard,"messages=&utest->messages;\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                      if(strcmp((yyvsp[(2) - (5)].name),"suites")==0) 
                                          {strcpy(guard,"{\n  Suite *suite;\n");
                                        
                                           strcat(guard,"  int l;\n");
                                           strcat(guard,"for(l=0;l<=suites->index;l++)\n");
                                           strcat(guard,"  {\nsuite=&suites->list[l];\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy((yyval.name),guard);
                                      
                                          }

                                         if(strcmp((yyvsp[(2) - (5)].name),"variables")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   for(j=0;j<=variables->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&variables->list[j];\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                           if(strcmp((yyvsp[(2) - (5)].name),"allvariables")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   Variable *xvariable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   Variables *variables;\n variables=&model->variables;\n");
                                           strcat(guard,"   for(j=0;j<=variables->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&variables->list[j];\n");
                                           strcat(guard,"      xvariable=variable;\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                          if(strcmp((yyvsp[(2) - (5)].name),"datatypes")==0) 
                                          {strcpy(guard,"{\n   Datatype *datatype;\n");
                                           strcat(guard,"   Variables *variables;\n");
                                           strcat(guard,"   int k;\n");
                                           strcat(guard,"   for(k=0;k<=datatypes->index;k++)\n");
                                           strcat(guard,"   {\ndatatype=&datatypes->list[k];\n");
                                           strcat(guard,"variables=&datatype->variables;\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n   }\n}\n");
                                          
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                           if(strcmp((yyvsp[(2) - (5)].name),"messages")==0) 
                                          {strcpy(guard,"{\n  Message *message;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int w;\n");
                                           strcat(guard,"for(w=0;w<=messages->index;w++)\n");
                                           strcat(guard,"  {\n   message=&messages->list[w];\n");
                                           strcat(guard,"   variables=&message->variables;\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n  }}\n");
                                      
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                     if(strcmp((yyvsp[(2) - (5)].name),"primitivetypes")==0) 
                                          {strcpy(guard,"{\n");
                                         
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<4;i++)\n");
                                           strcat(guard,"  {\n "); 
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"}\n}\n");
                                      
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                      if(strcmp((yyvsp[(2) - (5)].name),"consts")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   for(j=0;j<=constants->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&constants->list[j];\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy((yyval.name),guard);
                                      
                                          }
                                      if(strcmp((yyvsp[(2) - (5)].name),"functions")==0) 
                                          {strcpy(guard,"{\n  Function *variable;\n");
                                        
                                           strcat(guard,"  int l;\n");
                                           strcat(guard,"for(l=0;l<=functions->index;l++)\n");
                                           strcat(guard,"  {\nvariable=&functions->list[l];\n");
                                           strcat(guard,(yyvsp[(4) - (5)].name));
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy((yyval.name),guard);
                                      
                                          }

                                         }
    break;

  case 18:
#line 381 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 19:
#line 382 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 20:
#line 383 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 21:
#line 384 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 22:
#line 385 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 23:
#line 386 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 24:
#line 387 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 25:
#line 388 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 26:
#line 389 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 27:
#line 390 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 28:
#line 391 "code_generator.y"
    { strcpy((yyval.name),(yyvsp[(1) - (1)].name)); }
    break;

  case 29:
#line 396 "code_generator.y"
    {
                 char car[20];
                 sprintf(car,"car[%d]",ind);
                 strcpy((yyval.name),(yyvsp[(1) - (2)].name));
                 strcat((yyval.name),"fprintf(file,\"\%s\",");
                 strcat((yyval.name),car);
                 strcat((yyval.name),");\n");
                 fprintf(file,"%d %s\n",ind,(yyvsp[(2) - (2)].name)); 
                 ind++;
                }
    break;

  case 30:
#line 406 "code_generator.y"
    {
                 char car[20]; 
                 sprintf(car,"car[%d]",ind);
                 strcpy((yyval.name),"fprintf(file,\"\%s\",");
                 strcat((yyval.name),car);
                 strcat((yyval.name),");\n");
                 strcat((yyval.name),(yyvsp[(2) - (2)].name));
                 fprintf(file,"%d %s\n",ind,(yyvsp[(1) - (2)].name)); 
                 ind++;
                }
    break;

  case 31:
#line 416 "code_generator.y"
    { 
                 char car[20]; 
                 sprintf(car,"car[%d]);\n",ind);
                 strcpy((yyval.name),"fprintf(file,\"\%s\",");
                 strcat((yyval.name),car);
                 strcat((yyval.name),");\n");
                 fprintf(file,"%d %s\n",ind,(yyvsp[(1) - (1)].name)); 
                 ind++;
               }
    break;

  case 32:
#line 425 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (2)].name));strcat((yyval.name),(yyvsp[(2) - (2)].name));}
    break;

  case 33:
#line 426 "code_generator.y"
    {strcpy((yyval.name),(yyvsp[(1) - (2)].name)); strcat((yyval.name),(yyvsp[(1) - (2)].name));}
    break;

  case 34:
#line 427 "code_generator.y"
    { strcpy ((yyval.name),(yyvsp[(1) - (2)].name)) ;strcat((yyval.name),"");}
    break;

  case 35:
#line 428 "code_generator.y"
    { strcpy((yyval.name),"") ;strcat((yyval.name),(yyvsp[(2) - (2)].name));}
    break;

  case 36:
#line 429 "code_generator.y"
    { strcpy((yyval.name),"") ;}
    break;

  case 37:
#line 432 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",variable->name);\n");}
    break;

  case 38:
#line 433 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",variable->type);\n");}
    break;

  case 39:
#line 434 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",primtype[i]);\n");}
    break;

  case 40:
#line 435 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",specifier[i]);\n");}
    break;

  case 41:
#line 436 "code_generator.y"
    {strcpy((yyval.name),"if(variable->dim>0)\n{char aux[30];\n strcpy(aux,variable->type);\nstrcat(aux,\"_static\");\nfprintf(file,\"\%s\",aux);\n}\n else fprintf(file,\"\%s\",variable->type);\n");}
    break;

  case 42:
#line 437 "code_generator.y"
    {strcpy((yyval.name),"if(variable->dim>0)\n fprintf(file,\"\%d\",variable->dim);\n");}
    break;

  case 43:
#line 438 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",xmachine->name);\n");}
    break;

  case 44:
#line 439 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",datatype->name);\n");}
    break;

  case 45:
#line 440 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",utest->name);\n");}
    break;

  case 46:
#line 441 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",utest->xagent_name);\n");}
    break;

  case 47:
#line 442 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",utest->function_name);\n");}
    break;

  case 48:
#line 443 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",message->name);\n");}
    break;

  case 49:
#line 444 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",suite->name);\n");}
    break;

  case 50:
#line 445 "code_generator.y"
    {strcpy((yyval.name),"fprintf(file,\"\%s\",suite->path);\n");}
    break;

  case 51:
#line 446 "code_generator.y"
    { 
                   strcpy((yyval.name),"strcpy(capitalized,message->name);\n");
                   strcat((yyval.name),"capitalize(capitalized);\n");
                   strcat((yyval.name),"fprintf(file,\"\%s\",capitalized);\n");}
    break;

  case 52:
#line 450 "code_generator.y"
    { 
                   strcpy((yyval.name),"strcpy(capitalized,variable->name);\n");
                   strcat((yyval.name),"capitalize(capitalized);\n");
                   strcat((yyval.name),"fprintf(file,\"\%s\",capitalized);\n");}
    break;


/* Line 1267 of yacc.c.  */
#line 2079 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 456 "code_generator.y"



yyerror(char *message)
{
  printf("%s\n",message);
}

int main(int argc, char *argv[])
{ 
  
 guard=(char *) malloc(sizeof(char)*MAXDIM );
  char file_name_code[MAXCHAR];
  char file_name_input[MAXCHAR];
  char current_name[MAXCHAR];
  char real_ext[10];

  char current_ext[10];
  char directory[MAXCHAR];
  char tempdir[MAXCHAR];
  struct dirent * Dirent;
  DIR * dir;
  file_code=NULL;
if( argc<2) printf("Error - input directory must be specified");
    else
     {
     strcpy(directory,argv[1]);
     
    if(!file_code) 
        {strcpy(file_name_code,directory);
         strcat(file_name_code,"main_code.c");
         file_code=fopen(file_name_code,"w");
         printf("writing file %s\n",file_name_code); 
         read_and_write_external(file_code,"prolog.c");
     
  
  

 dir = opendir(directory);
  while((Dirent = readdir(dir)) != NULL)	
  {
    extract_name_ext(Dirent->d_name, file_name, current_ext);
    extract_name_ext(current_ext, sub_ext, real_ext);
    //printf("%s %s\n",sub_ext,real_ext);
    if((strcmp(real_ext,"lkp")==0)||((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0)))
    {  
      ind=0;
      if(strlen(sub_ext)==0) strcpy(sub_ext,"x");
      if((strcmp(sub_ext,"lkp")==0)) {strcpy(real_ext,sub_ext); strcpy(sub_ext,"");}
      strcpy(current_name,directory);
      strcat(current_name,file_name);
      strcpy(file_name_data,file_name);
       if(strlen(sub_ext)!=0)  strcat(file_name_data,".");
      strcat(file_name_data,sub_ext);
      strcat(file_name_data,".tmp");
      strcpy(file_name_input,current_name);
      strcat(file_name_input,".");
      strcat(file_name_input,current_ext);
      strcpy(file_def,file_name); 
      if(strlen(sub_ext)!=0) strcat(file_def,".");
      strcat(file_def,sub_ext); 
      printf("opening like-pascal code file %s\n",file_name_data);
      open_input_file(file_name_input);
      strcpy(tempdir,directory);
      strcat(tempdir,file_name_data);
      file=fopen(tempdir,"w");
      printf("writing file %s\n",file_name_data);
      yyparse();
      fclose(file);
    }
  }
read_and_write_external(file_code,"epilog.c");
   dir = opendir(directory);
while((Dirent = readdir(dir)) != NULL)	
  {
    extract_name_ext(Dirent->d_name, file_name, current_ext);
    extract_name_ext(current_ext, sub_ext, real_ext);
    if((strcmp(real_ext,"lkp")==0)||((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0)))
    { 
      if(((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0))) fprintf(file_code,"   generate_%s_%s_code();\n","",file_name);
    else fprintf(file_code,"   generate_%s_%s_code();\n",sub_ext,file_name);
    }
  }
  fprintf(file_code,"return 0;\n}");

fclose(file_code);
 } }
strcpy(tempdir,directory);
strcat(tempdir,"xmachine_reader.c");
copy_file("xmachine_reader.c",tempdir);
strcpy(tempdir,directory);
strcat(tempdir,"xmachine_reader.h");
copy_file("xmachine_reader.h",tempdir);
strcpy(tempdir,directory);
strcat(tempdir,"Makefile");
copy_file("Makefile2",tempdir);
free(guard);
  return(0);
}

 
     
      

