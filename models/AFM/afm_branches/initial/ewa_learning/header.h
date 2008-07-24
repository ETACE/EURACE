/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
 
#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "mboard.h"



/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT) 
#endif


/** \def NR_PARAMS
 * \brief Provide access to environment variables in uppercase. */
#define NR_PARAMS nr_params
/** \def PRINT_DEBUG
 * \brief Provide access to environment variables in uppercase. */
#define PRINT_DEBUG print_debug
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Start of loop to process rule_performance messages. */
#define START_RULE_PERFORMANCE_MESSAGE_LOOP  rule_performance_message = get_first_rule_performance_message(); while(rule_performance_message) {
/** \def FINISH_RULE_PERFORMANCE_MESSAGE_LOOP
 * \brief Finish of loop to process rule_performance messages. */
#define FINISH_RULE_PERFORMANCE_MESSAGE_LOOP rule_performance_message = get_next_rule_performance_message(rule_performance_message); }
/** \def START_NEW_PERFORMANCES_MESSAGE_LOOP
 * \brief Start of loop to process new_performances messages. */
#define START_NEW_PERFORMANCES_MESSAGE_LOOP  new_performances_message = get_first_new_performances_message(); while(new_performances_message) {
/** \def FINISH_NEW_PERFORMANCES_MESSAGE_LOOP
 * \brief Finish of loop to process new_performances messages. */
#define FINISH_NEW_PERFORMANCES_MESSAGE_LOOP new_performances_message = get_next_new_performances_message(new_performances_message); }
/** \def START_RULE_DETAILS_MESSAGE_LOOP
 * \brief Start of loop to process rule_details messages. */
#define START_RULE_DETAILS_MESSAGE_LOOP  rule_details_message = get_first_rule_details_message(); while(rule_details_message) {
/** \def FINISH_RULE_DETAILS_MESSAGE_LOOP
 * \brief Finish of loop to process rule_details messages. */
#define FINISH_RULE_DETAILS_MESSAGE_LOOP rule_details_message = get_next_rule_details_message(rule_details_message); }

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

/** \struct EWAParameterStruct
 * \brief .
 *
 * .
 */
struct EWAParameterStruct
{
	double EWA_rho;	/**< Datatype memory variable EWA_rho of type double. */
	double EWA_phi;	/**< Datatype memory variable EWA_phi of type double. */
	double EWA_delta;	/**< Datatype memory variable EWA_delta of type double. */
	double EWA_beta;	/**< Datatype memory variable EWA_beta of type double. */
};

/** \struct EWAParameterStruct_array
 * \brief Dynamic array to hold EWAParameterStructs
 */
struct EWAParameterStruct_array
{
	int size;
	int total_size;
	
	struct EWAParameterStruct * array;
};

/** \var typedef EWAParameterStruct EWAParameterStruct
 * \brief Typedef for EWAParameterStruct struct.
 */
typedef struct EWAParameterStruct EWAParameterStruct;
/** \var typedef EWAParameterStruct_array EWAParameterStruct_array
 * \brief Typedef for EWAParameterStruct_array struct.
 */
typedef struct EWAParameterStruct_array EWAParameterStruct_array;
/** \struct GAParameterStruct
 * \brief .
 *
 * .
 */
struct GAParameterStruct
{
	double prob_cross;	/**< Datatype memory variable prob_cross of type double. */
	double prob_mut;	/**< Datatype memory variable prob_mut of type double. */
	int string_size;	/**< Datatype memory variable string_size of type int. */
	int pop_size;	/**< Datatype memory variable pop_size of type int. */
	double reproduction_proportion;	/**< Datatype memory variable reproduction_proportion of type double. */
	int single_point_cross_over;	/**< Datatype memory variable single_point_cross_over of type int. */
	int election;	/**< Datatype memory variable election of type int. */
	double stepsize[10];	/**< Datatype memory variable stepsize of type double. */
	double delta_min;	/**< Datatype memory variable delta_min of type double. */
	double delta_max;	/**< Datatype memory variable delta_max of type double. */
	double min_values[10];	/**< Datatype memory variable min_values of type double. */
	double max_values[10];	/**< Datatype memory variable max_values of type double. */
};

/** \struct GAParameterStruct_array
 * \brief Dynamic array to hold GAParameterStructs
 */
struct GAParameterStruct_array
{
	int size;
	int total_size;
	
	struct GAParameterStruct * array;
};

/** \var typedef GAParameterStruct GAParameterStruct
 * \brief Typedef for GAParameterStruct struct.
 */
typedef struct GAParameterStruct GAParameterStruct;
/** \var typedef GAParameterStruct_array GAParameterStruct_array
 * \brief Typedef for GAParameterStruct_array struct.
 */
typedef struct GAParameterStruct_array GAParameterStruct_array;
/** \struct PublicClassifierRule
 * \brief .
 *
 * .
 */
struct PublicClassifierRule
{
	int id;	/**< Datatype memory variable id of type int. */
	int counter;	/**< Datatype memory variable counter of type int. */
	double performance;	/**< Datatype memory variable performance of type double. */
	double avg_performance;	/**< Datatype memory variable avg_performance of type double. */
	double parameters[10];	/**< Datatype memory variable parameters of type double. */
};

/** \struct PublicClassifierRule_array
 * \brief Dynamic array to hold PublicClassifierRules
 */
struct PublicClassifierRule_array
{
	int size;
	int total_size;
	
	struct PublicClassifierRule * array;
};

/** \var typedef PublicClassifierRule PublicClassifierRule
 * \brief Typedef for PublicClassifierRule struct.
 */
typedef struct PublicClassifierRule PublicClassifierRule;
/** \var typedef PublicClassifierRule_array PublicClassifierRule_array
 * \brief Typedef for PublicClassifierRule_array struct.
 */
typedef struct PublicClassifierRule_array PublicClassifierRule_array;
/** \struct PrivateClassifierRule
 * \brief .
 *
 * .
 */
struct PrivateClassifierRule
{
	int id;	/**< Datatype memory variable id of type int. */
	double my_performance;	/**< Datatype memory variable my_performance of type double. */
	double avg_performance;	/**< Datatype memory variable avg_performance of type double. */
	double attraction;	/**< Datatype memory variable attraction of type double. */
	double choiceprob;	/**< Datatype memory variable choiceprob of type double. */
	double parameters[10];	/**< Datatype memory variable parameters of type double. */
};

/** \struct PrivateClassifierRule_array
 * \brief Dynamic array to hold PrivateClassifierRules
 */
struct PrivateClassifierRule_array
{
	int size;
	int total_size;
	
	struct PrivateClassifierRule * array;
};

/** \var typedef PrivateClassifierRule PrivateClassifierRule
 * \brief Typedef for PrivateClassifierRule struct.
 */
typedef struct PrivateClassifierRule PrivateClassifierRule;
/** \var typedef PrivateClassifierRule_array PrivateClassifierRule_array
 * \brief Typedef for PrivateClassifierRule_array struct.
 */
typedef struct PrivateClassifierRule_array PrivateClassifierRule_array;
/** \struct SimplePublicClassifierSystem
 * \brief .
 *
 * .
 */
struct SimplePublicClassifierSystem
{
	int nr_rules;	/**< Datatype memory variable nr_rules of type int. */
	PublicClassifierRule ruletable[100];	/**< Datatype memory variable ruletable of type PublicClassifierRule. */
};

/** \struct SimplePublicClassifierSystem_array
 * \brief Dynamic array to hold SimplePublicClassifierSystems
 */
struct SimplePublicClassifierSystem_array
{
	int size;
	int total_size;
	
	struct SimplePublicClassifierSystem * array;
};

/** \var typedef SimplePublicClassifierSystem SimplePublicClassifierSystem
 * \brief Typedef for SimplePublicClassifierSystem struct.
 */
typedef struct SimplePublicClassifierSystem SimplePublicClassifierSystem;
/** \var typedef SimplePublicClassifierSystem_array SimplePublicClassifierSystem_array
 * \brief Typedef for SimplePublicClassifierSystem_array struct.
 */
typedef struct SimplePublicClassifierSystem_array SimplePublicClassifierSystem_array;
/** \struct SimplePrivateClassifierSystem
 * \brief .
 *
 * .
 */
struct SimplePrivateClassifierSystem
{
	int nr_rules;	/**< Datatype memory variable nr_rules of type int. */
	double experience;	/**< Datatype memory variable experience of type double. */
	int current_rule;	/**< Datatype memory variable current_rule of type int. */
	PrivateClassifierRule ruletable[100];	/**< Datatype memory variable ruletable of type PrivateClassifierRule. */
};

/** \struct SimplePrivateClassifierSystem_array
 * \brief Dynamic array to hold SimplePrivateClassifierSystems
 */
struct SimplePrivateClassifierSystem_array
{
	int size;
	int total_size;
	
	struct SimplePrivateClassifierSystem * array;
};

/** \var typedef SimplePrivateClassifierSystem SimplePrivateClassifierSystem
 * \brief Typedef for SimplePrivateClassifierSystem struct.
 */
typedef struct SimplePrivateClassifierSystem SimplePrivateClassifierSystem;
/** \var typedef SimplePrivateClassifierSystem_array SimplePrivateClassifierSystem_array
 * \brief Typedef for SimplePrivateClassifierSystem_array struct.
 */
typedef struct SimplePrivateClassifierSystem_array SimplePrivateClassifierSystem_array;
/** \struct ComplexPublicClassifierSystem
 * \brief .
 *
 * .
 */
struct ComplexPublicClassifierSystem
{
	int nr_types;	/**< Datatype memory variable nr_types of type int. */
	int_array nr_rules_per_type;	/**< Datatype memory variable nr_rules_per_type of type int_array. */
	int nr_rules;	/**< Datatype memory variable nr_rules of type int. */
	PublicClassifierRule ruletable[100];	/**< Datatype memory variable ruletable of type PublicClassifierRule. */
};

/** \struct ComplexPublicClassifierSystem_array
 * \brief Dynamic array to hold ComplexPublicClassifierSystems
 */
struct ComplexPublicClassifierSystem_array
{
	int size;
	int total_size;
	
	struct ComplexPublicClassifierSystem * array;
};

/** \var typedef ComplexPublicClassifierSystem ComplexPublicClassifierSystem
 * \brief Typedef for ComplexPublicClassifierSystem struct.
 */
typedef struct ComplexPublicClassifierSystem ComplexPublicClassifierSystem;
/** \var typedef ComplexPublicClassifierSystem_array ComplexPublicClassifierSystem_array
 * \brief Typedef for ComplexPublicClassifierSystem_array struct.
 */
typedef struct ComplexPublicClassifierSystem_array ComplexPublicClassifierSystem_array;

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_to_act;	/**< X-machine memory variable day_of_month_to_act of type int. */
	EWAParameterStruct EWA_parameters;	/**< X-machine memory variable EWA_parameters of type EWAParameterStruct. */
	SimplePrivateClassifierSystem private_classifiersystem;	/**< X-machine memory variable private_classifiersystem of type SimplePrivateClassifierSystem. */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_holder
{
	struct xmachine_memory_Household * agent;	/**< Pointer to X-machine memory Household. */

	struct xmachine_memory_Household_holder * prev;	/**< Pointer to previous Household agent in the list.  */
	struct xmachine_memory_Household_holder * next;	/**< Pointer to next Household agent in the list.  */
};

/** \struct xmachine_memory_Household_holder
 * \brief Holds struct of memory of xmachine Household.
 */
struct xmachine_memory_Household_state
{
	struct xmachine_memory_Household_holder * agents;	/**< Pointer to X-machine memory Household. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_FinancialAgent
 * \brief Holds memory of xmachine FinancialAgent.
 */
struct xmachine_memory_FinancialAgent
{
	int id;	/**< X-machine memory variable id of type int. */
	SimplePublicClassifierSystem public_classifiersystem;	/**< X-machine memory variable public_classifiersystem of type SimplePublicClassifierSystem. */
	GAParameterStruct GA_parameters;	/**< X-machine memory variable GA_parameters of type GAParameterStruct. */
	EWAParameterStruct EWA_parameters;	/**< X-machine memory variable EWA_parameters of type EWAParameterStruct. */
};

/** \struct xmachine_memory_FinancialAgent_holder
 * \brief Holds struct of memory of xmachine FinancialAgent.
 */
struct xmachine_memory_FinancialAgent_holder
{
	struct xmachine_memory_FinancialAgent * agent;	/**< Pointer to X-machine memory FinancialAgent. */

	struct xmachine_memory_FinancialAgent_holder * prev;	/**< Pointer to previous FinancialAgent agent in the list.  */
	struct xmachine_memory_FinancialAgent_holder * next;	/**< Pointer to next FinancialAgent agent in the list.  */
};

/** \struct xmachine_memory_FinancialAgent_holder
 * \brief Holds struct of memory of xmachine FinancialAgent.
 */
struct xmachine_memory_FinancialAgent_state
{
	struct xmachine_memory_FinancialAgent_holder * agents;	/**< Pointer to X-machine memory FinancialAgent. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	struct xmachine_memory_FinancialAgent * xmachine_FinancialAgent;	/**< Pointer to X-machine memory of type FinancialAgent.  */
	
	//struct xmachine * prev;	/**< Pointer to previous X-machine in the list.  */
	//struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct m_rule_performance
 * \brief Holds message of type rule_performance_message.
 */
struct m_rule_performance
{
	int rule_id;	/**< Message memory variable rule_id of type int. */
	double rule_performance;	/**< Message memory variable rule_performance of type double. */
};

/** \struct m_new_performances
 * \brief Holds message of type new_performances_message.
 */
struct m_new_performances
{
	int rule_id;	/**< Message memory variable rule_id of type int. */
	double avg_performance;	/**< Message memory variable avg_performance of type double. */
};

/** \struct m_rule_details
 * \brief Holds message of type rule_details_message.
 */
struct m_rule_details
{
	int rule_id;	/**< Message memory variable rule_id of type int. */
	double parameters[10];	/**< Message memory variable parameters of type double. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_holder xmachine_memory_Household_holder;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household_state xmachine_memory_Household_state;
/** \var typedef xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent
 * \brief Typedef for xmachine_memory_FinancialAgent struct.
 */
typedef struct xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent;
/** \var typedef xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent
 * \brief Typedef for xmachine_memory_FinancialAgent struct.
 */
typedef struct xmachine_memory_FinancialAgent_holder xmachine_memory_FinancialAgent_holder;
/** \var typedef xmachine_memory_FinancialAgent xmachine_memory_FinancialAgent
 * \brief Typedef for xmachine_memory_FinancialAgent struct.
 */
typedef struct xmachine_memory_FinancialAgent_state xmachine_memory_FinancialAgent_state;
/** \typedef m_rule_performance m_rule_performance
 * \brief Typedef for m_rule_performance struct.
 */
typedef struct m_rule_performance m_rule_performance;

/** \typedef m_new_performances m_new_performances
 * \brief Typedef for m_new_performances struct.
 */
typedef struct m_new_performances m_new_performances;

/** \typedef m_rule_details m_rule_details
 * \brief Typedef for m_rule_details struct.
 */
typedef struct m_rule_details m_rule_details;


int idle(void);
int Household_idle_start_Household_EWA_Learning_end_GA_condition(xmachine_memory_Household *a);
int Household_reset_private_classifiersystem(void);
int Household_Household_reset_private_classifiersystem_start_Household_EWA_Learning_01_condition(xmachine_memory_Household *a);
int Household_read_and_update_rule_details(void);
int idle(void);
int Household_idle_end_GA_end_Household_EWA_Learning_condition(xmachine_memory_Household *a);
int Household_send_rule_performance(void);
int Household_Household_send_rule_performance_end_GA_02_condition(xmachine_memory_Household *a);
int Household_read_all_performances(void);
int Household_print_private_classifiersystem(void);
int Household_select_rule(void);
int idle(void);
int FinancialAgent_idle_start_FinancialAgent_end_GA_condition(xmachine_memory_FinancialAgent *a);
int FinancialAgent_reset_public_classifiersystem(void);
int FinancialAgent_FinancialAgent_reset_public_classifiersystem_start_FinancialAgent_01_condition(xmachine_memory_FinancialAgent *a);
int FinancialAgent_apply_GA(void);
int FinancialAgent_send_rule_details(void);
int FinancialAgent_read_rule_performance_and_update_classifiersystem(void);
int FinancialAgent_send_all_performances(void);
int FinancialAgent_print_public_classifiersystem(void);

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
	struct m_rule_performance * rule_performance_messages;	/**< Pointer to rule_performance message list. */
	struct m_new_performances * new_performances_messages;	/**< Pointer to new_performances message list. */
	struct m_rule_details * rule_details_messages;	/**< Pointer to rule_details message list. */
	
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

/** \var int nr_params
* \brief A constant variable from the environment. */
int nr_params;
/** \var int print_debug
* \brief A constant variable from the environment. */
int print_debug;
/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_rule_performance * temp_rule_performance_message
* \brief Pointer to m_rule_performance to initialise linked list. */
m_rule_performance * temp_rule_performance_message;
/** \var m_new_performances * temp_new_performances_message
* \brief Pointer to m_new_performances to initialise linked list. */
m_new_performances * temp_new_performances_message;
/** \var m_rule_details * temp_rule_details_message
* \brief Pointer to m_rule_details to initialise linked list. */
m_rule_details * temp_rule_details_message;
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
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
xmachine_memory_Household * current_xmachine_Household;
xmachine_memory_Household_holder * temp_xmachine_Household_holder;
xmachine_memory_Household_holder * current_xmachine_Household_holder;
xmachine_memory_Household_state * current_xmachine_Household_next_state; /* New agents added to this state */
/* Pointer to list of Household agents in state 04 state */
//xmachine_memory_Household * temp_xmachine_Household_04;
xmachine_memory_Household_state * Household_04_state;
/* Pointer to list of Household agents in state 03 state */
//xmachine_memory_Household * temp_xmachine_Household_03;
xmachine_memory_Household_state * Household_03_state;
/* Pointer to list of Household agents in state 02 state */
//xmachine_memory_Household * temp_xmachine_Household_02;
xmachine_memory_Household_state * Household_02_state;
/* Pointer to list of Household agents in state end_Household_EWA_Learning state */
//xmachine_memory_Household * temp_xmachine_Household_end_Household_EWA_Learning;
xmachine_memory_Household_state * Household_end_Household_EWA_Learning_state;
/* Pointer to list of Household agents in state 01 state */
//xmachine_memory_Household * temp_xmachine_Household_01;
xmachine_memory_Household_state * Household_01_state;
/* Pointer to list of Household agents in state end_GA state */
//xmachine_memory_Household * temp_xmachine_Household_end_GA;
xmachine_memory_Household_state * Household_end_GA_state;
/* Pointer to list of Household agents in state start_Household_EWA_Learning state */
//xmachine_memory_Household * temp_xmachine_Household_start_Household_EWA_Learning;
xmachine_memory_Household_state * Household_start_Household_EWA_Learning_state;
/* Pointer to current $agent_name agent */
xmachine_memory_FinancialAgent * current_xmachine_FinancialAgent;
xmachine_memory_FinancialAgent_holder * temp_xmachine_FinancialAgent_holder;
xmachine_memory_FinancialAgent_holder * current_xmachine_FinancialAgent_holder;
xmachine_memory_FinancialAgent_state * current_xmachine_FinancialAgent_next_state; /* New agents added to this state */
/* Pointer to list of FinancialAgent agents in state end_FinancialAgent state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_end_FinancialAgent;
xmachine_memory_FinancialAgent_state * FinancialAgent_end_FinancialAgent_state;
/* Pointer to list of FinancialAgent agents in state 04 state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_04;
xmachine_memory_FinancialAgent_state * FinancialAgent_04_state;
/* Pointer to list of FinancialAgent agents in state 03 state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_03;
xmachine_memory_FinancialAgent_state * FinancialAgent_03_state;
/* Pointer to list of FinancialAgent agents in state 02 state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_02;
xmachine_memory_FinancialAgent_state * FinancialAgent_02_state;
/* Pointer to list of FinancialAgent agents in state 01 state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_01;
xmachine_memory_FinancialAgent_state * FinancialAgent_01_state;
/* Pointer to list of FinancialAgent agents in state end_GA state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_end_GA;
xmachine_memory_FinancialAgent_state * FinancialAgent_end_GA_state;
/* Pointer to list of FinancialAgent agents in state start_FinancialAgent state */
//xmachine_memory_FinancialAgent * temp_xmachine_FinancialAgent_start_FinancialAgent;
xmachine_memory_FinancialAgent_state * FinancialAgent_start_FinancialAgent_state;


MBt_Board b_rule_performance;
MBt_Iterator i_rule_performance;

MBt_Board b_new_performances;
MBt_Iterator i_new_performances;

MBt_Board b_rule_details;
MBt_Iterator i_rule_details;


/** \var m_rule_performance * rule_performance_message
* \brief Pointer to message struct for looping through rule_performance message list */
m_rule_performance * rule_performance_message;
/** \var m_new_performances * new_performances_message
* \brief Pointer to message struct for looping through new_performances message list */
m_new_performances * new_performances_message;
/** \var m_rule_details * rule_details_message
* \brief Pointer to message struct for looping through rule_details message list */
m_rule_details * rule_details_message;
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
/** \var int output_offset
* \brief Offset to output results */
int output_offset;
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
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_EWAParameterStruct_array(EWAParameterStruct_array * array);
void reset_EWAParameterStruct_array(EWAParameterStruct_array * array);
void free_EWAParameterStruct_array(EWAParameterStruct_array * array);
void copy_EWAParameterStruct_array(EWAParameterStruct_array * from, EWAParameterStruct_array * to);
void add_EWAParameterStruct(EWAParameterStruct_array * array, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta);
void remove_EWAParameterStruct(EWAParameterStruct_array * array, int index);

void init_GAParameterStruct_array(GAParameterStruct_array * array);
void reset_GAParameterStruct_array(GAParameterStruct_array * array);
void free_GAParameterStruct_array(GAParameterStruct_array * array);
void copy_GAParameterStruct_array(GAParameterStruct_array * from, GAParameterStruct_array * to);
void add_GAParameterStruct(GAParameterStruct_array * array, double prob_cross, double prob_mut, int string_size, int pop_size, double reproduction_proportion, int single_point_cross_over, int election, double * stepsize, double delta_min, double delta_max, double * min_values, double * max_values);
void remove_GAParameterStruct(GAParameterStruct_array * array, int index);

void init_PublicClassifierRule_array(PublicClassifierRule_array * array);
void reset_PublicClassifierRule_array(PublicClassifierRule_array * array);
void free_PublicClassifierRule_array(PublicClassifierRule_array * array);
void copy_PublicClassifierRule_array(PublicClassifierRule_array * from, PublicClassifierRule_array * to);
void add_PublicClassifierRule(PublicClassifierRule_array * array, int id, int counter, double performance, double avg_performance, double * parameters);
void remove_PublicClassifierRule(PublicClassifierRule_array * array, int index);

void init_PrivateClassifierRule_array(PrivateClassifierRule_array * array);
void reset_PrivateClassifierRule_array(PrivateClassifierRule_array * array);
void free_PrivateClassifierRule_array(PrivateClassifierRule_array * array);
void copy_PrivateClassifierRule_array(PrivateClassifierRule_array * from, PrivateClassifierRule_array * to);
void add_PrivateClassifierRule(PrivateClassifierRule_array * array, int id, double my_performance, double avg_performance, double attraction, double choiceprob, double * parameters);
void remove_PrivateClassifierRule(PrivateClassifierRule_array * array, int index);

void init_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array);
void reset_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array);
void free_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * array);
void copy_SimplePublicClassifierSystem_array(SimplePublicClassifierSystem_array * from, SimplePublicClassifierSystem_array * to);
void add_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int nr_rules, PublicClassifierRule * ruletable);
void remove_SimplePublicClassifierSystem(SimplePublicClassifierSystem_array * array, int index);

void init_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array);
void reset_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array);
void free_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * array);
void copy_SimplePrivateClassifierSystem_array(SimplePrivateClassifierSystem_array * from, SimplePrivateClassifierSystem_array * to);
void add_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int nr_rules, double experience, int current_rule, PrivateClassifierRule * ruletable);
void remove_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem_array * array, int index);

void init_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array);
void reset_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array);
void free_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * array);
void copy_ComplexPublicClassifierSystem_array(ComplexPublicClassifierSystem_array * from, ComplexPublicClassifierSystem_array * to);
void add_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, PublicClassifierRule * ruletable);
void remove_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem_array * array, int index);


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
int idle();
/* xml.c */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size);
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size);
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size);
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size);
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array);
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array);
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array);
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array);

void init_EWAParameterStruct(EWAParameterStruct * temp);
void init_EWAParameterStruct_static_array(EWAParameterStruct * array, int size);
void read_EWAParameterStruct(char * buffer, int * j, EWAParameterStruct * temp_datatype);
void read_EWAParameterStruct_dynamic_array(char * buffer, int * j, EWAParameterStruct_array * temp_datatype_array);
void read_EWAParameterStruct_static_array(char * buffer, int * j, EWAParameterStruct * temp_datatype_array, int size);
void write_EWAParameterStruct(FILE *file, EWAParameterStruct * temp_datatype);
void write_EWAParameterStruct_static_array(FILE *file, EWAParameterStruct * temp_datatype, int size);
void write_EWAParameterStruct_dynamic_array(FILE *file, EWAParameterStruct_array * temp_datatype);
void init_GAParameterStruct(GAParameterStruct * temp);
void init_GAParameterStruct_static_array(GAParameterStruct * array, int size);
void read_GAParameterStruct(char * buffer, int * j, GAParameterStruct * temp_datatype);
void read_GAParameterStruct_dynamic_array(char * buffer, int * j, GAParameterStruct_array * temp_datatype_array);
void read_GAParameterStruct_static_array(char * buffer, int * j, GAParameterStruct * temp_datatype_array, int size);
void write_GAParameterStruct(FILE *file, GAParameterStruct * temp_datatype);
void write_GAParameterStruct_static_array(FILE *file, GAParameterStruct * temp_datatype, int size);
void write_GAParameterStruct_dynamic_array(FILE *file, GAParameterStruct_array * temp_datatype);
void init_PublicClassifierRule(PublicClassifierRule * temp);
void init_PublicClassifierRule_static_array(PublicClassifierRule * array, int size);
void read_PublicClassifierRule(char * buffer, int * j, PublicClassifierRule * temp_datatype);
void read_PublicClassifierRule_dynamic_array(char * buffer, int * j, PublicClassifierRule_array * temp_datatype_array);
void read_PublicClassifierRule_static_array(char * buffer, int * j, PublicClassifierRule * temp_datatype_array, int size);
void write_PublicClassifierRule(FILE *file, PublicClassifierRule * temp_datatype);
void write_PublicClassifierRule_static_array(FILE *file, PublicClassifierRule * temp_datatype, int size);
void write_PublicClassifierRule_dynamic_array(FILE *file, PublicClassifierRule_array * temp_datatype);
void init_PrivateClassifierRule(PrivateClassifierRule * temp);
void init_PrivateClassifierRule_static_array(PrivateClassifierRule * array, int size);
void read_PrivateClassifierRule(char * buffer, int * j, PrivateClassifierRule * temp_datatype);
void read_PrivateClassifierRule_dynamic_array(char * buffer, int * j, PrivateClassifierRule_array * temp_datatype_array);
void read_PrivateClassifierRule_static_array(char * buffer, int * j, PrivateClassifierRule * temp_datatype_array, int size);
void write_PrivateClassifierRule(FILE *file, PrivateClassifierRule * temp_datatype);
void write_PrivateClassifierRule_static_array(FILE *file, PrivateClassifierRule * temp_datatype, int size);
void write_PrivateClassifierRule_dynamic_array(FILE *file, PrivateClassifierRule_array * temp_datatype);
void init_SimplePublicClassifierSystem(SimplePublicClassifierSystem * temp);
void init_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * array, int size);
void read_SimplePublicClassifierSystem(char * buffer, int * j, SimplePublicClassifierSystem * temp_datatype);
void read_SimplePublicClassifierSystem_dynamic_array(char * buffer, int * j, SimplePublicClassifierSystem_array * temp_datatype_array);
void read_SimplePublicClassifierSystem_static_array(char * buffer, int * j, SimplePublicClassifierSystem * temp_datatype_array, int size);
void write_SimplePublicClassifierSystem(FILE *file, SimplePublicClassifierSystem * temp_datatype);
void write_SimplePublicClassifierSystem_static_array(FILE *file, SimplePublicClassifierSystem * temp_datatype, int size);
void write_SimplePublicClassifierSystem_dynamic_array(FILE *file, SimplePublicClassifierSystem_array * temp_datatype);
void init_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * temp);
void init_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * array, int size);
void read_SimplePrivateClassifierSystem(char * buffer, int * j, SimplePrivateClassifierSystem * temp_datatype);
void read_SimplePrivateClassifierSystem_dynamic_array(char * buffer, int * j, SimplePrivateClassifierSystem_array * temp_datatype_array);
void read_SimplePrivateClassifierSystem_static_array(char * buffer, int * j, SimplePrivateClassifierSystem * temp_datatype_array, int size);
void write_SimplePrivateClassifierSystem(FILE *file, SimplePrivateClassifierSystem * temp_datatype);
void write_SimplePrivateClassifierSystem_static_array(FILE *file, SimplePrivateClassifierSystem * temp_datatype, int size);
void write_SimplePrivateClassifierSystem_dynamic_array(FILE *file, SimplePrivateClassifierSystem_array * temp_datatype);
void init_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * temp);
void init_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * array, int size);
void read_ComplexPublicClassifierSystem(char * buffer, int * j, ComplexPublicClassifierSystem * temp_datatype);
void read_ComplexPublicClassifierSystem_dynamic_array(char * buffer, int * j, ComplexPublicClassifierSystem_array * temp_datatype_array);
void read_ComplexPublicClassifierSystem_static_array(char * buffer, int * j, ComplexPublicClassifierSystem * temp_datatype_array, int size);
void write_ComplexPublicClassifierSystem(FILE *file, ComplexPublicClassifierSystem * temp_datatype);
void write_ComplexPublicClassifierSystem_static_array(FILE *file, ComplexPublicClassifierSystem * temp_datatype, int size);
void write_ComplexPublicClassifierSystem_dynamic_array(FILE *file, ComplexPublicClassifierSystem_array * temp_datatype);
void readinitialstates(char * filename, int * itno, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata(int iteration_number);

void free_EWAParameterStruct(EWAParameterStruct * temp);
void free_EWAParameterStruct_static_array(EWAParameterStruct * array, int size);
void copy_EWAParameterStruct(EWAParameterStruct * from, EWAParameterStruct * to);
void copy_EWAParameterStruct_static_array(EWAParameterStruct * from, EWAParameterStruct * to, int size);
void free_GAParameterStruct(GAParameterStruct * temp);
void free_GAParameterStruct_static_array(GAParameterStruct * array, int size);
void copy_GAParameterStruct(GAParameterStruct * from, GAParameterStruct * to);
void copy_GAParameterStruct_static_array(GAParameterStruct * from, GAParameterStruct * to, int size);
void free_PublicClassifierRule(PublicClassifierRule * temp);
void free_PublicClassifierRule_static_array(PublicClassifierRule * array, int size);
void copy_PublicClassifierRule(PublicClassifierRule * from, PublicClassifierRule * to);
void copy_PublicClassifierRule_static_array(PublicClassifierRule * from, PublicClassifierRule * to, int size);
void free_PrivateClassifierRule(PrivateClassifierRule * temp);
void free_PrivateClassifierRule_static_array(PrivateClassifierRule * array, int size);
void copy_PrivateClassifierRule(PrivateClassifierRule * from, PrivateClassifierRule * to);
void copy_PrivateClassifierRule_static_array(PrivateClassifierRule * from, PrivateClassifierRule * to, int size);
void free_SimplePublicClassifierSystem(SimplePublicClassifierSystem * temp);
void free_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * array, int size);
void copy_SimplePublicClassifierSystem(SimplePublicClassifierSystem * from, SimplePublicClassifierSystem * to);
void copy_SimplePublicClassifierSystem_static_array(SimplePublicClassifierSystem * from, SimplePublicClassifierSystem * to, int size);
void free_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * temp);
void free_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * array, int size);
void copy_SimplePrivateClassifierSystem(SimplePrivateClassifierSystem * from, SimplePrivateClassifierSystem * to);
void copy_SimplePrivateClassifierSystem_static_array(SimplePrivateClassifierSystem * from, SimplePrivateClassifierSystem * to, int size);
void free_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * temp);
void free_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * array, int size);
void copy_ComplexPublicClassifierSystem(ComplexPublicClassifierSystem * from, ComplexPublicClassifierSystem * to);
void copy_ComplexPublicClassifierSystem_static_array(ComplexPublicClassifierSystem * from, ComplexPublicClassifierSystem * to, int size);

xmachine_memory_Household_state * init_Household_state();
xmachine_memory_Household * init_Household_agent();
void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state);
void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state);
void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state);
void add_Household_agent(int id, int day_of_month_to_act, EWAParameterStruct EWA_parameters, SimplePrivateClassifierSystem private_classifiersystem);
void unittest_init_Household_agent();
void unittest_free_Household_agent();
xmachine_memory_FinancialAgent_state * init_FinancialAgent_state();
xmachine_memory_FinancialAgent * init_FinancialAgent_agent();
void free_FinancialAgent_agent(xmachine_memory_FinancialAgent_holder * tmp, xmachine_memory_FinancialAgent_state * state);
void transition_FinancialAgent_agent(xmachine_memory_FinancialAgent_holder * tmp, xmachine_memory_FinancialAgent_state * from_state, xmachine_memory_FinancialAgent_state * to_state);
void add_FinancialAgent_agent_internal(xmachine_memory_FinancialAgent * agent, xmachine_memory_FinancialAgent_state * state);
void add_FinancialAgent_agent(int id, SimplePublicClassifierSystem public_classifiersystem, GAParameterStruct GA_parameters, EWAParameterStruct EWA_parameters);
void unittest_init_FinancialAgent_agent();
void unittest_free_FinancialAgent_agent();

void add_rule_performance_message(int rule_id, double rule_performance);
m_rule_performance * add_rule_performance_message_internal(void);
m_rule_performance * get_first_rule_performance_message(void);
m_rule_performance * get_next_rule_performance_message(m_rule_performance * current);
void freerule_performancemessages(void);
void add_new_performances_message(int rule_id, double avg_performance);
m_new_performances * add_new_performances_message_internal(void);
m_new_performances * get_first_new_performances_message(void);
m_new_performances * get_next_new_performances_message(m_new_performances * current);
void freenew_performancesmessages(void);
void add_rule_details_message(int rule_id, double parameters[]);
m_rule_details * add_rule_details_message_internal(void);
m_rule_details * get_first_rule_details_message(void);
m_rule_details * get_next_rule_details_message(m_rule_details * current);
void freerule_detailsmessages(void);

void set_id(int id);
int get_id();
void set_day_of_month_to_act(int day_of_month_to_act);
int get_day_of_month_to_act();
EWAParameterStruct * get_EWA_parameters();
SimplePrivateClassifierSystem * get_private_classifiersystem();
SimplePublicClassifierSystem * get_public_classifiersystem();
GAParameterStruct * get_GA_parameters();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
m_rule_performance * get_next_message_rule_performance_in_range(m_rule_performance * current);
m_new_performances * get_next_message_new_performances_in_range(m_new_performances * current);
m_rule_details * get_next_message_rule_details_in_range(m_rule_details * current);

/* memory.c */
xmachine * add_xmachine(void);
