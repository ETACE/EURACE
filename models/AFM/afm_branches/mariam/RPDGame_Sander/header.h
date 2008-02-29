/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT) 
#endif



/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def e START_STRATEGY_I_USE_MESSAGE_LOOP
 * \brief Start of loop to process strategy_i_use messages. */
#define START_STRATEGY_I_USE_MESSAGE_LOOP  strategy_i_use_message = get_first_strategy_i_use_message(); while(strategy_i_use_message) {
/** \def FINISH_STRATEGY_I_USE_MESSAGE_LOOP
 * \brief Finish of loop to process strategy_i_use messages. */
#define FINISH_STRATEGY_I_USE_MESSAGE_LOOP strategy_i_use_message = get_next_strategy_i_use_message(strategy_i_use_message); }

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

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;
	
	float * array;
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

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;

/** \struct strategy_state
 * \brief À>.
 *
 * À>.
 */
struct strategy_state
{
	int starting_state[4];	/**< Datatype memory variable starting_state of type int. */
	int state_name;	/**< Datatype memory variable state_name of type int. */
	int state_ifcooperate[4];	/**< Datatype memory variable state_ifcooperate of type int. */
	int state_ifdefect[4];	/**< Datatype memory variable state_ifdefect of type int. */
};

/** \struct strategy_state_array
 * \brief Dynamic array to hold strategy_states
 */
struct strategy_state_array
{
	int size;
	int total_size;
	
	struct strategy_state * array;
};

/** \var typedef strategy_state strategy_state
 * \brief Typedef for strategy_state struct.
 */
typedef struct strategy_state strategy_state;
/** \var typedef strategy_state_array strategy_state_array
 * \brief Typedef for strategy_state_array struct.
 */
typedef struct strategy_state_array strategy_state_array;
/** \struct payoff_elements
 * \brief >.
 *
 * >.
 */
struct payoff_elements
{
	int payoffs[2];	/**< Datatype memory variable payoffs of type int. */
};

/** \struct payoff_elements_array
 * \brief Dynamic array to hold payoff_elementss
 */
struct payoff_elements_array
{
	int size;
	int total_size;
	
	struct payoff_elements * array;
};

/** \var typedef payoff_elements payoff_elements
 * \brief Typedef for payoff_elements struct.
 */
typedef struct payoff_elements payoff_elements;
/** \var typedef payoff_elements_array payoff_elements_array
 * \brief Typedef for payoff_elements_array struct.
 */
typedef struct payoff_elements_array payoff_elements_array;
/** \struct strategy_data
 * \brief  >.
 *
 *  >.
 */
struct strategy_data
{
	int strategy_id;	/**< Datatype memory variable strategy_id of type int. */
	double strategy_perf;	/**< Datatype memory variable strategy_perf of type double. */
};

/** \struct strategy_data_array
 * \brief Dynamic array to hold strategy_datas
 */
struct strategy_data_array
{
	int size;
	int total_size;
	
	struct strategy_data * array;
};

/** \var typedef strategy_data strategy_data
 * \brief Typedef for strategy_data struct.
 */
typedef struct strategy_data strategy_data;
/** \var typedef strategy_data_array strategy_data_array
 * \brief Typedef for strategy_data_array struct.
 */
typedef struct strategy_data_array strategy_data_array;
/** \struct complete_strategy
 * \brief àjI.
 *
 * àjI.
 */
struct complete_strategy
{
	strategy_state_array strategy_path;	/**< Datatype memory variable strategy_path of type strategy_state_array. */
};

/** \struct complete_strategy_array
 * \brief Dynamic array to hold complete_strategys
 */
struct complete_strategy_array
{
	int size;
	int total_size;
	
	struct complete_strategy * array;
};

/** \var typedef complete_strategy complete_strategy
 * \brief Typedef for complete_strategy struct.
 */
typedef struct complete_strategy complete_strategy;
/** \var typedef complete_strategy_array complete_strategy_array
 * \brief Typedef for complete_strategy_array struct.
 */
typedef struct complete_strategy_array complete_strategy_array;
/** \struct columns
 * \brief àjI.
 *
 * àjI.
 */
struct columns
{
	payoff_elements_array opponents;	/**< Datatype memory variable opponents of type payoff_elements_array. */
};

/** \struct columns_array
 * \brief Dynamic array to hold columnss
 */
struct columns_array
{
	int size;
	int total_size;
	
	struct columns * array;
};

/** \var typedef columns columns
 * \brief Typedef for columns struct.
 */
typedef struct columns columns;
/** \var typedef columns_array columns_array
 * \brief Typedef for columns_array struct.
 */
typedef struct columns_array columns_array;
/** \struct player_list_element
 * \brief àjI.
 *
 * àjI.
 */
struct player_list_element
{
	int player_id;	/**< Datatype memory variable player_id of type int. */
	int strategy_id;	/**< Datatype memory variable strategy_id of type int. */
	int previous_move;	/**< Datatype memory variable previous_move of type int. */
};

/** \struct player_list_element_array
 * \brief Dynamic array to hold player_list_elements
 */
struct player_list_element_array
{
	int size;
	int total_size;
	
	struct player_list_element * array;
};

/** \var typedef player_list_element player_list_element
 * \brief Typedef for player_list_element struct.
 */
typedef struct player_list_element player_list_element;
/** \var typedef player_list_element_array player_list_element_array
 * \brief Typedef for player_list_element_array struct.
 */
typedef struct player_list_element_array player_list_element_array;

/** \struct xmachine_memory_GamePlayer
 * \brief Holds memory of xmachine GamePlayer.
 */
struct xmachine_memory_GamePlayer
{
	int id;	/**< X-machine memory variable id of type int. */
	int strategy_used;	/**< X-machine memory variable strategy_used of type int. */
	int previous_performance;	/**< X-machine memory variable previous_performance of type int. */
	int present_state;	/**< X-machine memory variable present_state of type int. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_GameSolver
 * \brief Holds memory of xmachine GameSolver.
 */
struct xmachine_memory_GameSolver
{
	complete_strategy strategy_list[30];	/**< X-machine memory variable strategy_list of type complete_strategy. */
	complete_strategy new_children[10];	/**< X-machine memory variable new_children of type complete_strategy. */
	int nragents;	/**< X-machine memory variable nragents of type int. */
	int_array automata_id;	/**< X-machine memory variable automata_id of type int_array. */
	int_array players;	/**< X-machine memory variable players of type int_array. */
	int player_one_state[4];	/**< X-machine memory variable player_one_state of type int. */
	int player_two_state[4];	/**< X-machine memory variable player_two_state of type int. */
	int player_one_move;	/**< X-machine memory variable player_one_move of type int. */
	int player_two_move;	/**< X-machine memory variable player_two_move of type int. */
	strategy_data strategy_performance[30];	/**< X-machine memory variable strategy_performance of type strategy_data. */
	complete_strategy offspring[2];	/**< X-machine memory variable offspring of type complete_strategy. */
	columns_array rows;	/**< X-machine memory variable rows of type columns_array. */
	player_list_element_array player_list;	/**< X-machine memory variable player_list of type player_list_element_array. */
	double iradius;	/**< X-machine memory variable iradius of type double. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_GamePlayer * xmachine_GamePlayer;	/**< Pointer to X-machine memory of type GamePlayer.  */
	struct xmachine_memory_GameSolver * xmachine_GameSolver;	/**< Pointer to X-machine memory of type GameSolver.  */
	
	struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct xmachine_message_strategy_i_use
 * \brief Holds message of type strategy_i_use_message.
 */
struct xmachine_message_strategy_i_use
{
	int player_id;	/**< Message memory variable player_id of type int. */
	int strategy_used;	/**< Message memory variable strategy_used of type int. */
	int previous_move;	/**< Message memory variable previous_move of type int. */
	int previous_state;	/**< Message memory variable previous_state of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_strategy_i_use * next;	/**< Pointer to next message in the list. */
};


/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_GamePlayer xmachine_memory_GamePlayer
 * \brief Typedef for xmachine_memory_GamePlayer struct.
 */
typedef struct xmachine_memory_GamePlayer xmachine_memory_GamePlayer;
/** \var typedef xmachine_memory_GameSolver xmachine_memory_GameSolver
 * \brief Typedef for xmachine_memory_GameSolver struct.
 */
typedef struct xmachine_memory_GameSolver xmachine_memory_GameSolver;
/** \typedef xmachine_message_strategy_i_use xmachine_message_strategy_i_use
 * \brief Typedef for xmachine_message_strategy_i_use struct.
 */
typedef struct xmachine_message_strategy_i_use xmachine_message_strategy_i_use;


int post_my_strategy(void);
int ipd_game_within_players(void);
int actual_game(void);
int find_optimum_strategies(void);
int applyGA(void);
int update_strategies(void);

/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */
	
	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct xmachine_message_strategy_i_use * strategy_i_use_messages;	/**< Pointer to strategy_i_use message list. */
	
	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var xmachine_message_strategy_i_use * temp_strategy_i_use_message
* \brief Pointer to xmachine_message_strategy_i_use to initialise linked list. */
xmachine_message_strategy_i_use * temp_strategy_i_use_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[100]
* \brief Output path for files. */
char outputpath[100];
/** \var long total_time
* \brief Total time for the simulation run */
long total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;

/** \var xmachine_message_strategy_i_use ** p_strategy_i_use_message
* \brief Pointer to first pointer of strategy_i_use message list */
xmachine_message_strategy_i_use ** p_strategy_i_use_message;

/** \var xmachine_message_strategy_i_use * strategy_i_use_message
* \brief Pointer to message struct for looping through strategy_i_use message list */
xmachine_message_strategy_i_use * strategy_i_use_message;
/** \var node_information ** p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int use_binary_output
* \brief Tag to save results in a binary file */
int use_binary_output;
/** \var int next_avaliable_id
* \brief Next avaliable id number for a new agent */
int next_avaliable_id;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void randomisexagent(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_strategy_state_array(strategy_state_array * array);
void reset_strategy_state_array(strategy_state_array * array);
void free_strategy_state_array(strategy_state_array * array);
void copy_strategy_state_array(strategy_state_array * from, strategy_state_array * to);
void add_strategy_state(strategy_state_array * array, int * starting_state, int state_name, int * state_ifcooperate, int * state_ifdefect);
void remove_strategy_state(strategy_state_array * array, int index);

void init_payoff_elements_array(payoff_elements_array * array);
void reset_payoff_elements_array(payoff_elements_array * array);
void free_payoff_elements_array(payoff_elements_array * array);
void copy_payoff_elements_array(payoff_elements_array * from, payoff_elements_array * to);
void add_payoff_elements(payoff_elements_array * array, int * payoffs);
void remove_payoff_elements(payoff_elements_array * array, int index);

void init_strategy_data_array(strategy_data_array * array);
void reset_strategy_data_array(strategy_data_array * array);
void free_strategy_data_array(strategy_data_array * array);
void copy_strategy_data_array(strategy_data_array * from, strategy_data_array * to);
void add_strategy_data(strategy_data_array * array, int strategy_id, double strategy_perf);
void remove_strategy_data(strategy_data_array * array, int index);

void init_complete_strategy_array(complete_strategy_array * array);
void reset_complete_strategy_array(complete_strategy_array * array);
void free_complete_strategy_array(complete_strategy_array * array);
void copy_complete_strategy_array(complete_strategy_array * from, complete_strategy_array * to);
void add_complete_strategy(complete_strategy_array * array, strategy_state_array * strategy_path);
void remove_complete_strategy(complete_strategy_array * array, int index);

void init_columns_array(columns_array * array);
void reset_columns_array(columns_array * array);
void free_columns_array(columns_array * array);
void copy_columns_array(columns_array * from, columns_array * to);
void add_columns(columns_array * array, payoff_elements_array * opponents);
void remove_columns(columns_array * array, int index);

void init_player_list_element_array(player_list_element_array * array);
void reset_player_list_element_array(player_list_element_array * array);
void free_player_list_element_array(player_list_element_array * array);
void copy_player_list_element_array(player_list_element_array * from, player_list_element_array * to);
void add_player_list_element(player_list_element_array * array, int player_id, int strategy_id, int previous_move);
void remove_player_list_element(player_list_element_array * array, int index);


void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
/* xml.c */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size);
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size);
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size);
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size);
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array);
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array);
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array);
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array);

void init_strategy_state(strategy_state * temp);
void init_strategy_state_static_array(strategy_state * temp, int size);
void read_strategy_state(char * buffer, int * j, strategy_state * temp_datatype);
void read_strategy_state_dynamic_array(char * buffer, int * j, strategy_state_array * temp_datatype_array);
void read_strategy_state_static_array(char * buffer, int * j, strategy_state * temp_datatype_array, int size);
void write_strategy_state(FILE *file, strategy_state * temp_datatype);
void write_strategy_state_static_array(FILE *file, strategy_state * temp_datatype, int size);
void write_strategy_state_dynamic_array(FILE *file, strategy_state_array * temp_datatype);
void init_payoff_elements(payoff_elements * temp);
void init_payoff_elements_static_array(payoff_elements * temp, int size);
void read_payoff_elements(char * buffer, int * j, payoff_elements * temp_datatype);
void read_payoff_elements_dynamic_array(char * buffer, int * j, payoff_elements_array * temp_datatype_array);
void read_payoff_elements_static_array(char * buffer, int * j, payoff_elements * temp_datatype_array, int size);
void write_payoff_elements(FILE *file, payoff_elements * temp_datatype);
void write_payoff_elements_static_array(FILE *file, payoff_elements * temp_datatype, int size);
void write_payoff_elements_dynamic_array(FILE *file, payoff_elements_array * temp_datatype);
void init_strategy_data(strategy_data * temp);
void init_strategy_data_static_array(strategy_data * temp, int size);
void read_strategy_data(char * buffer, int * j, strategy_data * temp_datatype);
void read_strategy_data_dynamic_array(char * buffer, int * j, strategy_data_array * temp_datatype_array);
void read_strategy_data_static_array(char * buffer, int * j, strategy_data * temp_datatype_array, int size);
void write_strategy_data(FILE *file, strategy_data * temp_datatype);
void write_strategy_data_static_array(FILE *file, strategy_data * temp_datatype, int size);
void write_strategy_data_dynamic_array(FILE *file, strategy_data_array * temp_datatype);
void init_complete_strategy(complete_strategy * temp);
void init_complete_strategy_static_array(complete_strategy * temp, int size);
void read_complete_strategy(char * buffer, int * j, complete_strategy * temp_datatype);
void read_complete_strategy_dynamic_array(char * buffer, int * j, complete_strategy_array * temp_datatype_array);
void read_complete_strategy_static_array(char * buffer, int * j, complete_strategy * temp_datatype_array, int size);
void write_complete_strategy(FILE *file, complete_strategy * temp_datatype);
void write_complete_strategy_static_array(FILE *file, complete_strategy * temp_datatype, int size);
void write_complete_strategy_dynamic_array(FILE *file, complete_strategy_array * temp_datatype);
void init_columns(columns * temp);
void init_columns_static_array(columns * temp, int size);
void read_columns(char * buffer, int * j, columns * temp_datatype);
void read_columns_dynamic_array(char * buffer, int * j, columns_array * temp_datatype_array);
void read_columns_static_array(char * buffer, int * j, columns * temp_datatype_array, int size);
void write_columns(FILE *file, columns * temp_datatype);
void write_columns_static_array(FILE *file, columns * temp_datatype, int size);
void write_columns_dynamic_array(FILE *file, columns_array * temp_datatype);
void init_player_list_element(player_list_element * temp);
void init_player_list_element_static_array(player_list_element * temp, int size);
void read_player_list_element(char * buffer, int * j, player_list_element * temp_datatype);
void read_player_list_element_dynamic_array(char * buffer, int * j, player_list_element_array * temp_datatype_array);
void read_player_list_element_static_array(char * buffer, int * j, player_list_element * temp_datatype_array, int size);
void write_player_list_element(FILE *file, player_list_element * temp_datatype);
void write_player_list_element_static_array(FILE *file, player_list_element * temp_datatype, int size);
void write_player_list_element_dynamic_array(FILE *file, player_list_element_array * temp_datatype);
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata_binary(int iteration_number);
void saveiterationdata(int iteration_number);

void free_strategy_state_datatype(strategy_state * temp);
void copy_strategy_state_datatype(strategy_state * from, strategy_state * to);
void copy_strategy_state_static_array(strategy_state * from, strategy_state * to, int size);
void free_payoff_elements_datatype(payoff_elements * temp);
void copy_payoff_elements_datatype(payoff_elements * from, payoff_elements * to);
void copy_payoff_elements_static_array(payoff_elements * from, payoff_elements * to, int size);
void free_strategy_data_datatype(strategy_data * temp);
void copy_strategy_data_datatype(strategy_data * from, strategy_data * to);
void copy_strategy_data_static_array(strategy_data * from, strategy_data * to, int size);
void free_complete_strategy_datatype(complete_strategy * temp);
void copy_complete_strategy_datatype(complete_strategy * from, complete_strategy * to);
void copy_complete_strategy_static_array(complete_strategy * from, complete_strategy * to, int size);
void free_columns_datatype(columns * temp);
void copy_columns_datatype(columns * from, columns * to);
void copy_columns_static_array(columns * from, columns * to, int size);
void free_player_list_element_datatype(player_list_element * temp);
void copy_player_list_element_datatype(player_list_element * from, player_list_element * to);
void copy_player_list_element_static_array(player_list_element * from, player_list_element * to, int size);

xmachine_memory_GamePlayer * init_GamePlayer_agent();
void add_GamePlayer_agent_internal(xmachine_memory_GamePlayer * current);
void add_GamePlayer_agent(int id, int strategy_used, int previous_performance, int present_state, double iradius, double posx, double posy);
xmachine_memory_GameSolver * init_GameSolver_agent();
void add_GameSolver_agent_internal(xmachine_memory_GameSolver * current);
void add_GameSolver_agent(complete_strategy *strategy_list[], complete_strategy *new_children[], int nragents, int_array * automata_id, int_array * players, int *player_one_state[], int *player_two_state[], int player_one_move, int player_two_move, strategy_data *strategy_performance[], complete_strategy *offspring[], columns_array * rows, player_list_element_array * player_list, double iradius, double posx, double posy);

void add_strategy_i_use_message(int player_id, int strategy_used, int previous_move, int previous_state, double range, double x, double y, double z);
xmachine_message_strategy_i_use * add_strategy_i_use_message_internal(void);
xmachine_message_strategy_i_use * get_first_strategy_i_use_message(void);
xmachine_message_strategy_i_use * get_next_strategy_i_use_message(xmachine_message_strategy_i_use * current);
void freestrategy_i_usemessages(void);

void set_id(int id);
int get_id();
void set_strategy_used(int strategy_used);
int get_strategy_used();
void set_previous_performance(int previous_performance);
int get_previous_performance();
void set_present_state(int present_state);
int get_present_state();
void set_iradius(double iradius);
double get_iradius();
void set_posx(double posx);
double get_posx();
void set_posy(double posy);
double get_posy();
complete_strategy * get_strategy_list();
complete_strategy * get_new_children();
void set_nragents(int nragents);
int get_nragents();
int_array * get_automata_id();
int_array * get_players();
int * get_player_one_state();
int * get_player_two_state();
void set_player_one_move(int player_one_move);
int get_player_one_move();
void set_player_two_move(int player_two_move);
int get_player_two_move();
strategy_data * get_strategy_performance();
complete_strategy * get_offspring();
columns_array * get_rows();
player_list_element_array * get_player_list();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
xmachine_message_strategy_i_use * get_next_message_strategy_i_use_in_range(xmachine_message_strategy_i_use * current);

/* memory.c */
xmachine * add_xmachine(void);
