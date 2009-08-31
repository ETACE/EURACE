#ifndef XMACREADH
#define XMACREADH
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define MAXPATH 600
#define MAXCHAR 300
#define MAXTYPE 50
#define MAXTEXT 700000
#define DIM 150
#define MAXM 30
#define MAXFUN 200
#define MAXMOD 20
#define BLOCK 7
#define MAXUNITTESTS 80
#define MAXSUITES 20	
struct  module_s 
{ 
int  flag; 
char  path[MAXCHAR]; 
}; 
typedef  struct  module_s  Module; 
struct  module_array_s 
{ 
int  index; 
int  real_size; 
Module  list[MAXMOD]; 
}; 
typedef  struct  module_array_s  Modules; 
struct  variable
          {
             char name[MAXCHAR];
             char type[MAXTYPE];
             int dim;
          };
typedef struct variable Variable;

struct variables_s
         { 
           int index;
           int real_size;
           Variable *list;
           
         };
typedef struct variables_s Variables; 

struct function_s
       {   char name[MAXCHAR];
           char currentState[MAXCHAR];
           char nextState[MAXCHAR];
        };
typedef struct function_s Function;
           
struct functions_s
       { int index;
         Function list[MAXFUN];
       };
typedef struct functions_s Functions;

struct xmachine_s
      {
        char name[MAXCHAR];
        int index;
	Variables variables;
        Functions functions;
      };
typedef struct xmachine_s XMachine;
struct xmachines_s 
       { 
         int index;
         XMachine list[MAXM];
       };
typedef struct xmachines_s XMachines;
 
struct message_s
      {
         char name[MAXCHAR];
         Variables variables;
      };

typedef struct message_s Message;

typedef Message Datatype;


struct messages_s 
       { 
         int index;
         Message list[DIM];
       };
typedef struct messages_s Messages;
typedef Messages Datatypes;

struct model_s 
       { 
         char name[MAXCHAR];
         Functions functions; 
         Datatypes datatypes;
         XMachines xmachines;
         Messages messages;
         Variables constants;
         Modules modules;
         Variables variables;
       };

typedef struct model_s Model;

struct unittest_s
{
  char name[MAXCHAR];
  char function_name[MAXCHAR];
  char xagent_name[MAXCHAR];
  Variables variables;
  Messages messages;
};
typedef struct unittest_s UnitaryTest;

struct suite_s
       { 
         char name[MAXCHAR];
         char path[MAXPATH];
         
         int index;
         UnitaryTest *list;
       };
typedef struct suite_s Suite;

struct suites_s
       { 
         char name[MAXCHAR];
         char model_path[MAXPATH];
         int index;
         Suite *list;
       };
typedef struct suites_s Suites;
void trim_blanks(char *string);
void initialize_variable(Variable *variable);
void free_variable(Variable *variable);
void initialize_variables(Variables *variables);
void reset_variables(Variables *variables);
void free_variables(Variables *variables);
void initialize_message(Message *message);
void reset_message(Message *message);
void free_message(Message *message);
void initialize_xmachine(XMachine *xmachine);
void reset_xmachine(XMachine *xmachine);
void free_xmachine(XMachine *xmachine);
void initialize_unitarytest(UnitaryTest *unitarytest);
void reset_unitarytest(UnitaryTest *unitarytest);
void free_unitarytest(UnitaryTest *unitarytest);
void initialize_suite(Suite *suite);
void reset_suite(Suite *suite);
void free_suite(Suite *suite);
void initialize_suites(Suites *suites);
void free_suites(Suites *suites);
void initialize_model(Model *model);
void add_unitarytest(Suite *suite, UnitaryTest *unitarytest);
void add_suite(Suites *suites, Suite *suite);
void add_newpath_suite(Suites *suites, char *path);
void initialize_xmachines(XMachines *xmachines);
void free_xmachines(XMachines *xmachines);
void initialize_messages(Messages *messages);
void free_messages(Messages *messages);
void initialize_function(Function *function);
void initialize_functions(Functions *messages);
void reset_functions(Functions *functions);
void add_variable(Variables *variables, Variable *variable);
void add_xmachine(XMachines *xmachines, XMachine *xmachine);
void add_message(Messages *messages, Message *message);
void copy_variables(Variables *dest,Variables *source);
void copy_xmachine(XMachine *dest,XMachine *source );
void copy_message(Message *dest,Message *source);
void copy_unitarytest(UnitaryTest *dest,UnitaryTest *source);
void copy_messages(Messages *dest,Messages *source);
void copy_suite(Suite *dest,Suite *source);
int find_variable(Variables *variables, char *name);
int find_xmachine(XMachines *xmachines, char *name);
int find_message(Messages *messages, char *name); 
int find_datatype(Datatypes *datatypes, char *name);
void compile_type(xmlNode * a_node, char *str);
void compile_name(xmlNode * a_node, char *str);
int  compile_varname(xmlNode * a_node, char *name);
void compile_variable(xmlNode * a_node, Variable *variable);
void compile_memory(xmlNode * a_node,Variables *variables);
void compile_envfunction(xmlNode * a_node,Functions *functions);
 void compile_environment(xmlNode * a_node, Model  *model);
void compile_function(xmlNode * a_node, Function *function); 
void compile_functions(xmlNode * a_node,Functions *functions);
void compile_xagent(xmlNode * a_node,XMachine *xmachine);
void compile_xagents(xmlNode * a_node,XMachines *xmachines);
void compile_message(xmlNode * a_node,Message *message);
void compile_variables(xmlNode * a_node,Variables *variables);
void compile_messages(xmlNode * a_node,Messages *messages);  
void compile_model(xmlNode * a_node,Model *model);
void compile(char *filename, Model *model);
void readModel(char * filename,Model *model);void compile_datatypes(xmlNode * a_node,Datatypes *datatypes);
void compile_datatype(xmlNode * a_node,Datatype *datatype);
void compile_constants(xmlNode * a_node,Variables *variables);

void put_and_shift(char *str,char car);
int find_and_substitute(char *text, char *variable, char *value );
void xagents_code_producer(char *source,char *dest, XMachines *xmachines,char keyword[]);
void messages_code_producer(char *source,char *dest, Messages *messages,char *keyword);
void datatypes_code_producer(char *source,char *dest, Datatypes *datatypes,char *keyword);
void variables_code_producer(char *source,char *dest, Variables *variables);
void xagents_and_var_code_producer(char *source,char *dest, XMachines *xmachines);
int ffind_and_substitute(char *nome_file );
void capitalize(char *simple_word);
void compile_unittest(xmlNode * a_node, UnitaryTest  *unitarytest);
void compile_suite(xmlNode * a_node,Suite *suite);
void compile_suites(xmlNode * a_node,Suites *suite);
 void compile_declaration(xmlNode * a_node, UnitaryTest *unitarytest);
int read_suite(char *filename, Suite *suite);

int main_read_model(int argc, char * argv[],Model *model,Suites *suites);
void add_module(Modules *modules, Module *module);
void initialize_module(Module *module);
void initialize_modules(Modules *modules);
void compile_modules(xmlNode * a_node, Modules *modules);
void compile_module(xmlNode * a_node, Module *module);
void read_sub_modules(char *path, Model *model);
void read_all_suites(char *directory,Suites *suites);
void extract_directory(char *inputfile, char *directory);
int copy_file(char *from_name,char *to_name );
void collect_all_variables(Model *model);
char relative_path[MAXPATH];// hidden variable!!
#endif


