#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** \def NAME
 * \brief Release name. */
#define NAME "FLAME X-machine agent parser"
/** \def VERSIONMAJOR
 * \brief Release number. */
#define VERSIONMAJOR 0
/** \def VERSIONMINOR
 * \brief New features. */
#define VERSIONMINOR 15
/** \def VERSIONMICRO
 * \brief Bug fixes. */
#define VERSIONMICRO 5
/** \def DEBUG
 * \brief Debug output. */
#define DEBUG 0
/** \def LOG
 * \brief Print to log. */
#define LOG 0
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5

/*****************************************************************
* NAME:    struct datatype definitions                           *
* PURPOSE: define data types used in the program                 *
*****************************************************************/

/** \struct char_list
 * \brief Holds characters for a string.
 *
 * Holds characters for a string by using a linked list of characters.
 */
struct char_list
{
	char character;				/**< Character being held. */
	
	struct char_list * next;		/**< Pointer to next character in list. */
};

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;
	
	int * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;
	
	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;
	
	char * array;
};

struct input_file
{
	char * file;
	char * fullfilepath;
	char * fulldirectory;
	char * localdirectory;
	int enabled;
	
	struct input_file * next;
};

typedef struct input_file input_file;

/** \struct variable
 * \brief Holds variable data from xmachine memory and messages.
 *
 * Holds variable data for xmachine memory and messages using a linked list. Some variables being redundant for different purposes.
 */
struct variable
{
	char * type;		/**< Pointer to variable C type. */
	struct model_datatype * datatype;	/**< Pointer to variable model datatype. */
	char * name;		/**< Pointer to variable name. */
	char * value;		/**< Pointer to variable value. */
	char * typenotarray;		/**< Pointer to type name used if array. */
	char mpi_type[50];				/**< Variable MPI type. */
	int arraylength;				/**< Variable array length. Zero for no array, -1 for dynamic array */
	char defaultvalue[5];			/**< Default value for the type. */
	char c_type[5];				/**< Variable C type, e.g 'i' or 'f'. */
	int ismodeldatatype;			/**< Flag for model defined data type. */
	
	struct variable * next;		/**< Pointer to next variable in list. */
};

/** \struct xmachine_memory
 * \brief Holds list of xmachine memories.
 *
 * Holds list of xmachine memories using a linked list.
 */
struct xmachine_memory
{
	struct variable * vars;		/**< Pointer to X-machine variables in memory. */

	struct xmachine_memory * next;	/**< Pointer to next X-machine memory in list. */
};

/** \struct xmachine_state
 * \brief Holds state name, attributes and transistions.
 */
struct xmachine_state
{
	char * name;		/**< Pointer to state name. */
	
	struct xmachine_state * next;	/**< Pointer to next state in list. */
};

/** \struct xmachine_state
 * \brief Holds state name, attributes and transistions.
 */
struct xmachine_state_holder
{
	struct xmachine_state * state;
	
	struct xmachine_state_holder * next;	/**< Pointer to next state in list. */
};

typedef struct xmachine_state_holder xmachine_state_holder;

struct state_pointer
{
	struct xmachine_state * state;
	
	struct state_pointer * next;
};

typedef struct state_pointer state_pointer;

/** \struct f_code
 * \brief Holds code.
 */
struct f_code
{
	char * code;	/**< Pointer to code. */
	
	struct f_code * next;		/**< Pointer to next code in list. */
};


/** \struct rule_data
 * \brief Holds rule data.
 */
struct rule_data
{
	char * lhs;
	char * op;
	char * rhs;
	struct rule_data * lhs_rule; /* If rule==NULL then use lhs,op,rhs data */
	struct rule_data * rhs_rule; /* If rule==NULL then use lhs,op,rhs data */
	int time_rule;
	int not;
	
	struct rule_data * next;
};

typedef struct rule_data rule_data;

struct xmachine_ioput
{
	char * messagetype;
	char * filter_function;		/**< The filter rule function name. */
	struct rule_data * filter_rule;
	
	struct xmachine_ioput * next;
};

typedef struct xmachine_ioput xmachine_ioput;

/** \struct xmachine_function
 * \brief Holds transistion name, note and code.
 */
struct xmachine_function
{
	char * name;		/**< Pointer to function name. */
	char * note;		/**< Pointer to function note. */
	struct f_code * code;			/**< Pointer to function code. */
	
	char * agent_name;
	
	double x;
	double y;
	int rank_in;
	int rank_out;
	
	struct rule_data * condition_rule;	/**< The condition rule function name. */
	char * condition_function;
	
	char * current_state;
	char * next_state;
	struct xmachine_ioput * inputs;
	struct xmachine_ioput * outputs;
	
	/* Holds first inputs and last outputs of specific message types */
	struct xmachine_ioput * first_inputs;
	struct xmachine_ioput * last_outputs;
	
	struct adj_function * dependson;	/**< Node list of dependencies. */
	struct adj_function * dependants;	/**< Node list of dependants. */
	
	struct adj_function * alldepends;
	
	/* To hold depends tag info */
	struct adj_function * depends;		/**< Pointer to function note. */
	
	struct xmachine_function * next;	/**< Pointer to next function in list. */
};

struct adj_function
{
	struct xmachine_function * function;
	char * type;
	
	char * name;
	
	struct adj_function * next;
};

typedef struct adj_function adj_function;

/** \struct env_func
 * \brief Holds environment functions.
 */
struct env_func
{
	int header;	/**< Pointer to flag if header file (1) or functions file (2). */
	char * code;	/**< Pointer to environment function code. */
	char * filepath;	/**< Pointer to environment function filepath. */
	
	struct env_func * next;	/**< Pointer to next environment function in list. */
};

/** \struct xmachine_message
 * \brief Holds name and list of variables for a message type.
 *
 * Holds name and list of variables for a message type using a linked list.
 */
struct xmachine_message
{
	char * name;						/**< Pointer to message name. */
	struct variable * vars;			/**< Pointer to message variables. */
	struct env_func * functions;		/**< Pointer to dependency functions. */
	int var_number;						/**< Number of variables in memory. */
	int first;
	int last;
	
	struct xmachine_message * next;	/**< Pointer to next message in list.*/
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	int number;								/**< X-machine number !check. */
	char * name;							/**< Pointer X-machine name. */
	struct xmachine_memory * memory;		/**< Pointer X-machine memory. */
	struct xmachine_state * states;			/**< Pointer X-machine states. */
	struct xmachine_function * functions;	/**< Pointer X-machine functions. */
	
	struct xmachine_state * start_state;
	struct xmachine_state_holder * end_states;
	
	char rangevar[50];						/**< Variable name for range */
	char idvar[50]; 						/**< Variable name for agent id. */
	char xvar[50];							/**< Variable name for position in x-axis. */
	char yvar[50];							/**< Variable name for position in y-axis. */
	char zvar[50];							/**< Variable name for position in z-axis. */
	int var_number;							/**< Number of variables in memory. */
	
	struct xmachine * next;				/**< Pointer next X-machine in list. */
};

/** \struct layer
 * \brief Holds layers of functions.
 */
struct layer
{
	int number;
	struct function_pointer * functions;	/**< Pointer to list of functions. */
	
	struct layer * next;					/**< Pointer next X-machine in list. */
};

/** \struct function_pointer
 * \brief Holds pointer to a function.
 */
struct function_pointer
{
	struct xmachine_function * function;	/**< Pointer to list of functions. */
		
	struct function_pointer * next;		/**< Pointer next X-machine in list. */
};

/** \struct model_datatype
 * \brief Holds model datatypes.
 */
struct model_datatype
{
	char * name;					/**< Name of the datatype. */
	char * desc;					/**< Description of the datatype. */
	struct variable * vars;		/**< Pointer to variables of the datatype. */
	int has_single_vars;			/**< Flag if the datatype holds single variables. */
	int has_dynamic_arrays;			/**< Flag if the datatype holds dynamic arrays. */
	
	struct model_datatype * next;		/**< Pointer next model datatype. */
};

struct flame_communication
{
	char * messagetype;
	struct xmachine_function * output_function;
	struct xmachine_function * input_function;
	
	struct flame_communication * next;
};

typedef struct flame_communication flame_communication;

/** \struct time_data
 * \brief Holds time data.
 */
struct time_data
{
	char * name;
	int period;
	struct time_data * unit;
	int iterations;
	
	struct time_data * next;
};

typedef struct time_data time_data;

/** \struct model_data
 * \brief Holds model data.
 */
struct model_data
{
	char * name;
	int code_type;
	struct model_datatype ** p_datatypes;
	struct xmachine ** p_xmachines;
	struct xmachine_message ** p_xmessages;
	struct variable ** p_envvars;
	struct variable ** p_envdefines;
	struct env_func ** p_envfuncs;
	struct variable ** p_allvars;
	struct f_code ** p_it_end_code;
	struct layer ** p_layers;
	struct flame_communication ** p_communications;
	int number_messages;
	int number_xmachines;
	int agents_include_array_variables;
	int layer_total;
	struct time_data ** p_time_units;
	int depends_style;
};

/* explicit define datatypes so dont need to use struct anymore */
/** \typedef struct model_data model_data
 * \brief Typedef for model_data struct.
 */
typedef struct model_data model_data;
/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \typedef struct xmachine_memory xmachine_memory
 * \brief Typedef for xmachine_memory struct.
 */
typedef struct xmachine_memory xmachine_memory;
/** \typedef struct function_dependency function_dependency
 * \brief Typedef for function_dependency struct.
 */
typedef struct function_dependency function_dependency;
/** \typedef struct xmachine_message xmachine_message
 * \brief Typedef for xmachine_message struct.
 */
typedef struct xmachine_message xmachine_message;
/** \typedef struct xmachine_state xmachine_state
 * \brief Typedef for xmachine_state struct.
 */
typedef struct xmachine_state xmachine_state;
/** \typedef struct xmachine_function xmachine_function
 * \brief Typedef for xmachine_function struct.
 */
typedef struct xmachine_function xmachine_function;
/** \typedef struct variable variable
 * \brief Typedef for variable struct.
 */
typedef struct variable variable;
/** \typedef struct char_list char_list
 * \brief Typedef for char_list struct.
 */
typedef struct char_list char_list;
/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;
/** \typedef struct s_attrib s_attrib
 * \brief Typedef for s_attrib struct.
 */
typedef struct s_attrib s_attrib;
/** \typedef struct s_trans s_trans
 * \brief Typedef for s_trans struct.
 */
typedef struct s_trans s_trans;
/** \typedef struct f_code f_code
 * \brief Typedef for f_code struct.
 */
typedef struct f_code f_code;
/** \typedef struct env_func env_func
 * \brief Typedef for env_func struct.
 */
typedef struct env_func env_func;
/** \typedef struct layer layer
 * \brief Typedef for layer struct.
 */
typedef struct layer layer;
/** \typedef struct function_pointer function_pointer
 * \brief Typedef for function_pointer struct.
 */
typedef struct function_pointer function_pointer;
/** \typedef struct model_datatype model_datatype
 * \brief Typedef for model_datatype struct.
 */
typedef struct model_datatype model_datatype;

/* memory.c */
input_file * add_input_file(input_file ** p_files);
void free_input_files(input_file ** p_files);
void addstateholder(xmachine_state * state, xmachine_state_holder ** p_list);
void freestateholder(xmachine_state_holder ** p_list);
rule_data * add_rule_data(rule_data ** p_data);
void free_rule_data(rule_data ** p_data);
void add_time_unit(char * name, char * unit_name, int period, time_data ** p_time_units);
void free_time_units(time_data ** p_time_units);
xmachine_ioput * addioput(xmachine_ioput ** p_ioput);
void free_ioput(xmachine_ioput ** p_ioput);
f_code * addfcode(f_code ** p_code);
void freefcode(f_code ** p_code);
variable * addvariable(variable ** p_vars);
void freevariables(variable ** p_vars);
xmachine_memory * addxmemory(xmachine_memory ** p_xmemory);
void freexmemory(xmachine_memory ** p_xmemory);
env_func * addenvfunc(env_func ** p_env_funcs);
void freeenvfunc(env_func ** p_env_funcs);
xmachine_message * addxmessage(xmachine_message ** p_xmessage);
void freexmessages(xmachine_message ** p_xmessage);
void addxstate(char * name, xmachine_state ** p_xstates);
void freexstates(xmachine_state ** p_xstates);
xmachine_function * addxfunction(xmachine_function ** p_xfunctions);
void freexfunctions(xmachine_function ** p_xfunctions);
xmachine * addxmachine(xmachine ** p_xmachines, char * name);
void freexmachines(xmachine ** p_xmachines);
layer * addlayer(layer ** p_layer);
void freelayers(layer ** p_layers);
void addfunction_pointer(function_pointer ** p_function_pointers, xmachine_function * function);
void freefunction_pointers(function_pointer ** p_function_pointers);
model_datatype * adddatatype(model_datatype ** p_datatypes);
void freedatatypes(model_datatype ** p_datatypes);
void add_flame_communication(char * messagetype, xmachine_function * function1, xmachine_function * function2, flame_communication ** communications);
void free_flame_communications(flame_communication ** communications);
adj_function * add_depends_adj_function(xmachine_function * current_function);
void add_adj_function_simple(xmachine_function * function1, xmachine_function * function2);
void remove_adj_function_simple(xmachine_function * function1);
void add_adj_function(xmachine_function * function1, xmachine_function * function2, char * type);
void free_adj_function(adj_function *adj_functions);
/* charlist.c */
void ws(int tabcount, char * string);
void printcharlist(char_list ** p_charlist);
void writecharlist(char_list ** p_charlist, FILE * file);
void copycharlist(char_list ** p_charlist, char * chardata);
void makecharlist(char * chardata, char_list ** p_charlist);
/* dynamicarray.c */
char_array * init_char_array(void);
int_array * init_int_array(void);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void free_int_array(int_array * array);
void add_char(char_array * array, char new_char);
char * copy_array_to_str(char_array * array);
void remove_char(char_array * array, int index);
void print_char_array(char_array * array);
void sort_int_array(int_array * array);
int quicksort_int(int * array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
double_array * init_double_array(void);
void free_double_array(double_array * array);
void sort_double_array(double_array * array);
int quicksort_double(double * array, int elements);
void print_double_array(double_array * array);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
/* readmodel.c */
void readModel(input_file * inputfile, char * directory, model_data * modeldata, input_file ** p_files);
void checkmodel(model_data * modeldata);
/* dependencygraph.c */
char * copystr(char * string);
void create_dependency_graph(char * filepath, model_data * modeldata);
/* parsetemplate.c */
void parseTemplate(char * filename, char * templatename, model_data * modeldata);
void parseAgentHeaderTemplate(char * directory, model_data * modeldata);
void parseRuleFunctionsTemplate(char * directory, model_data * modeldata);
