/*
 * expr.lex : Scanner for a simple
 *            expression parser.
 */
D			[0-9]
CAP                     [A-Z_]
L			[a-z]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include "y.tab.h"

#define copy_and_return(token_type) { strcpy(yylval.name,yytext); \
                                      return(token_type); }

extern FILE *yyout;







%}

%%
"primitivetypes"      copy_and_return(PRIMITIVETYPES);
"ifprimtype"  copy_and_return(IFPRIMTYPE);
"ifnotprimtype"  copy_and_return(IFNOTPRIMTYPE);
"ifstatic"      copy_and_return(IFSTATIC);
"ifnotlast"      copy_and_return(IFNOTLAST);
"ifinagent"      copy_and_return(IFINAGENT);
"ifnotstatic" copy_and_return(IFNOTSTATIC);
"repeat"      copy_and_return(REPEAT);
"begin"    copy_and_return(BEG);
"end"      copy_and_return(END);
"xagents"       copy_and_return(XAGENTS);
"xagentheaders"       copy_and_return(XAGENTHEADERS);
"xagentsvar"       copy_and_return(XAGENTSVAR);
"messages"       copy_and_return(MESSAGES);
"variables"       copy_and_return(VARIABLES);
"allvariables"       copy_and_return(ALLVARIABLES);
"utests"       copy_and_return(UNITTESTS);
"suites"       copy_and_return(SUITES);
"__name"       copy_and_return(NAME);
"__utestname"       copy_and_return(UTESTNAME);
"__uagentname"       copy_and_return(UAGENTNAME);
"__suitename"       copy_and_return(SUITENAME);
"__suitepath"       copy_and_return(SUITEPATH);
"__function_name"       copy_and_return(FUNCTIONNAME);
"__primtype"       copy_and_return(PRIMTYPE);
"__type"       copy_and_return(TYPE);
"__spec"       copy_and_return(SPECIFIER);
"__dtype"       copy_and_return(DTYPE);
"__dim"       copy_and_return(DIM);
"__xagentname"       copy_and_return(XAGENTNAME);
"datatypes"       copy_and_return(DATATYPES);
"functions"       copy_and_return(FUNCTIONS);
"consts"       copy_and_return(CONSTANTS);
"__datatypename" copy_and_return(DATATYPENAME);
"__messagename" copy_and_return(MESSAGENAME);
"__MESSAGENAME" copy_and_return(CAPMESSAGENAME);
"__NAME" copy_and_return(CAPNAME);
[\n]*        return(EOL);

[\t]*     /* throw away whitespace or a newline*/

[!-~]*         copy_and_return(CONSTANT);  /*a-zA-Z0-9{}._*()/-+*/

%%



