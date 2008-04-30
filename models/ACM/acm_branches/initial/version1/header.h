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

/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process loan_request messages. */
#define START_LOAN_REQUEST_MESSAGE_LOOP  loan_request_message = get_first_loan_request_message(); while(loan_request_message) {
/** \def FINISH_LOAN_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process loan_request messages. */
#define FINISH_LOAN_REQUEST_MESSAGE_LOOP loan_request_message = get_next_loan_request_message(loan_request_message); }
/** \def START_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Start of loop to process loan_conditions messages. */
#define START_LOAN_CONDITIONS_MESSAGE_LOOP  loan_conditions_message = get_first_loan_conditions_message(); while(loan_conditions_message) {
/** \def FINISH_LOAN_CONDITIONS_MESSAGE_LOOP
 * \brief Finish of loop to process loan_conditions messages. */
#define FINISH_LOAN_CONDITIONS_MESSAGE_LOOP loan_conditions_message = get_next_loan_conditions_message(loan_conditions_message); }
/** \def START_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP
 * \brief Start of loop to process household_deposit messages. */
#define START_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP  household_deposit_message = get_first_household_deposit_message(); while(household_deposit_message) {
/** \def FINISH_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP
 * \brief Finish of loop to process household_deposit messages. */
#define FINISH_HOUSEHOLD_DEPOSIT_MESSAGE_LOOP household_deposit_message = get_next_household_deposit_message(household_deposit_message); }
/** \def START_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
 * \brief Start of loop to process money_withdraw_request messages. */
#define START_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP  money_withdraw_request_message = get_first_money_withdraw_request_message(); while(money_withdraw_request_message) {
/** \def FINISH_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP
 * \brief Finish of loop to process money_withdraw_request messages. */
#define FINISH_MONEY_WITHDRAW_REQUEST_MESSAGE_LOOP money_withdraw_request_message = get_next_money_withdraw_request_message(money_withdraw_request_message); }
/** \def START_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Start of loop to process loan_acceptance messages. */
#define START_LOAN_ACCEPTANCE_MESSAGE_LOOP  loan_acceptance_message = get_first_loan_acceptance_message(); while(loan_acceptance_message) {
/** \def FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP
 * \brief Finish of loop to process loan_acceptance messages. */
#define FINISH_LOAN_ACCEPTANCE_MESSAGE_LOOP loan_acceptance_message = get_next_loan_acceptance_message(loan_acceptance_message); }
/** \def START_INSTALLMENT_MESSAGE_LOOP
 * \brief Start of loop to process installment messages. */
#define START_INSTALLMENT_MESSAGE_LOOP  installment_message = get_first_installment_message(); while(installment_message) {
/** \def FINISH_INSTALLMENT_MESSAGE_LOOP
 * \brief Finish of loop to process installment messages. */
#define FINISH_INSTALLMENT_MESSAGE_LOOP installment_message = get_next_installment_message(installment_message); }
/** \def START_WITHDRAWAL_ALLOWED_MESSAGE_LOOP
 * \brief Start of loop to process withdrawal_allowed messages. */
#define START_WITHDRAWAL_ALLOWED_MESSAGE_LOOP  withdrawal_allowed_message = get_first_withdrawal_allowed_message(); while(withdrawal_allowed_message) {
/** \def FINISH_WITHDRAWAL_ALLOWED_MESSAGE_LOOP
 * \brief Finish of loop to process withdrawal_allowed messages. */
#define FINISH_WITHDRAWAL_ALLOWED_MESSAGE_LOOP withdrawal_allowed_message = get_next_withdrawal_allowed_message(withdrawal_allowed_message); }
/** \def START_BANKRUPTCY_MESSAGE_LOOP
 * \brief Start of loop to process bankruptcy messages. */
#define START_BANKRUPTCY_MESSAGE_LOOP  bankruptcy_message = get_first_bankruptcy_message(); while(bankruptcy_message) {
/** \def FINISH_BANKRUPTCY_MESSAGE_LOOP
 * \brief Finish of loop to process bankruptcy messages. */
#define FINISH_BANKRUPTCY_MESSAGE_LOOP bankruptcy_message = get_next_bankruptcy_message(bankruptcy_message); }

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


/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
	double_array interest;	/**< X-machine memory variable interest of type double_array. */
	double_array credit_offer;	/**< X-machine memory variable credit_offer of type double_array. */
	int_array contacted_bank;	/**< X-machine memory variable contacted_bank of type int_array. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double asset;	/**< X-machine memory variable asset of type double. */
	double credit_demand;	/**< X-machine memory variable credit_demand of type double. */
	double_array installment_amount;	/**< X-machine memory variable installment_amount of type double_array. */
	int installment_number;	/**< X-machine memory variable installment_number of type int. */
	int loans_number;	/**< X-machine memory variable loans_number of type int. */
	double_array outstanding_debt;	/**< X-machine memory variable outstanding_debt of type double_array. */
	int_array lending_bank_id;	/**< X-machine memory variable lending_bank_id of type int_array. */
	double_array interest_amount;	/**< X-machine memory variable interest_amount of type double_array. */
	int bankruptcy_state;	/**< X-machine memory variable bankruptcy_state of type int. */
	double total_resources;	/**< X-machine memory variable total_resources of type double. */
	double_array residual_var;	/**< X-machine memory variable residual_var of type double_array. */
	double_array var_per_installment;	/**< X-machine memory variable var_per_installment of type double_array. */
	double_array value_at_risk;	/**< X-machine memory variable value_at_risk of type double_array. */
	double_array interest_left;	/**< X-machine memory variable interest_left of type double_array. */
	double current_equity;	/**< X-machine memory variable current_equity of type double. */
	double current_debt;	/**< X-machine memory variable current_debt of type double. */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_holder
{
	struct xmachine_memory_Firm * agent;	/**< Pointer to X-machine memory Firm. */

	struct xmachine_memory_Firm_holder * prev;	/**< Pointer to previous Firm agent in the list.  */
	struct xmachine_memory_Firm_holder * next;	/**< Pointer to next Firm agent in the list.  */
};

/** \struct xmachine_memory_Firm_holder
 * \brief Holds struct of memory of xmachine Firm.
 */
struct xmachine_memory_Firm_state
{
	struct xmachine_memory_Firm_holder * agents;	/**< Pointer to X-machine memory Firm. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Bank
 * \brief Holds memory of xmachine Bank.
 */
struct xmachine_memory_Bank
{
	int id;	/**< X-machine memory variable id of type int. */
	double cash;	/**< X-machine memory variable cash of type double. */
	double total_credit;	/**< X-machine memory variable total_credit of type double. */
	double equity;	/**< X-machine memory variable equity of type double. */
	double bce_debt;	/**< X-machine memory variable bce_debt of type double. */
	double alfa;	/**< X-machine memory variable alfa of type double. */
	double var;	/**< X-machine memory variable var of type double. */
	double min_interest;	/**< X-machine memory variable min_interest of type double. */
	double gamma[2];	/**< X-machine memory variable gamma of type double. */
	double profits[2];	/**< X-machine memory variable profits of type double. */
	double lambda;	/**< X-machine memory variable lambda of type double. */
	double bce_interest;	/**< X-machine memory variable bce_interest of type double. */
	double debt_period;	/**< X-machine memory variable debt_period of type double. */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_holder
{
	struct xmachine_memory_Bank * agent;	/**< Pointer to X-machine memory Bank. */

	struct xmachine_memory_Bank_holder * prev;	/**< Pointer to previous Bank agent in the list.  */
	struct xmachine_memory_Bank_holder * next;	/**< Pointer to next Bank agent in the list.  */
};

/** \struct xmachine_memory_Bank_holder
 * \brief Holds struct of memory of xmachine Bank.
 */
struct xmachine_memory_Bank_state
{
	struct xmachine_memory_Bank_holder * agents;	/**< Pointer to X-machine memory Bank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	double total_deposit;	/**< X-machine memory variable total_deposit of type double. */
	int bank_account;	/**< X-machine memory variable bank_account of type int. */
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

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	struct xmachine_memory_Bank * xmachine_Bank;	/**< Pointer to X-machine memory of type Bank.  */
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	
	//struct xmachine * prev;	/**< Pointer to previous X-machine in the list.  */
	//struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct m_loan_request
 * \brief Holds message of type loan_request_message.
 */
struct m_loan_request
{
	double current_equity;	/**< Message memory variable current_equity of type double. */
	double current_debt;	/**< Message memory variable current_debt of type double. */
	double credit_demand;	/**< Message memory variable credit_demand of type double. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
};

/** \struct m_loan_conditions
 * \brief Holds message of type loan_conditions_message.
 */
struct m_loan_conditions
{
	double proposed_interest_rate;	/**< Message memory variable proposed_interest_rate of type double. */
	double amount_offered_credit;	/**< Message memory variable amount_offered_credit of type double. */
	int firm_id;	/**< Message memory variable firm_id of type int. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double var;	/**< Message memory variable var of type double. */
};

/** \struct m_household_deposit
 * \brief Holds message of type household_deposit_message.
 */
struct m_household_deposit
{
	double money_deposited;	/**< Message memory variable money_deposited of type double. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
};

/** \struct m_money_withdraw_request
 * \brief Holds message of type money_withdraw_request_message.
 */
struct m_money_withdraw_request
{
	double money_withdraw_request;	/**< Message memory variable money_withdraw_request of type double. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	int household_id;	/**< Message memory variable household_id of type int. */
};

/** \struct m_loan_acceptance
 * \brief Holds message of type loan_acceptance_message.
 */
struct m_loan_acceptance
{
	double credit_amount_taken;	/**< Message memory variable credit_amount_taken of type double. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
};

/** \struct m_installment
 * \brief Holds message of type installment_message.
 */
struct m_installment
{
	double installment;	/**< Message memory variable installment of type double. */
	double interest;	/**< Message memory variable interest of type double. */
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double var_per_installment;	/**< Message memory variable var_per_installment of type double. */
};

/** \struct m_withdrawal_allowed
 * \brief Holds message of type withdrawal_allowed_message.
 */
struct m_withdrawal_allowed
{
	double withdrawal_allowed;	/**< Message memory variable withdrawal_allowed of type double. */
	int household_id;	/**< Message memory variable household_id of type int. */
};

/** \struct m_bankruptcy
 * \brief Holds message of type bankruptcy_message.
 */
struct m_bankruptcy
{
	int bank_id;	/**< Message memory variable bank_id of type int. */
	double bad_debt;	/**< Message memory variable bad_debt of type double. */
	double credit_refunded;	/**< Message memory variable credit_refunded of type double. */
	double residual_var;	/**< Message memory variable residual_var of type double. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm xmachine_memory_Firm;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_holder xmachine_memory_Firm_holder;
/** \var typedef xmachine_memory_Firm xmachine_memory_Firm
 * \brief Typedef for xmachine_memory_Firm struct.
 */
typedef struct xmachine_memory_Firm_state xmachine_memory_Firm_state;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank xmachine_memory_Bank;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_holder xmachine_memory_Bank_holder;
/** \var typedef xmachine_memory_Bank xmachine_memory_Bank
 * \brief Typedef for xmachine_memory_Bank struct.
 */
typedef struct xmachine_memory_Bank_state xmachine_memory_Bank_state;
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
/** \typedef m_loan_request m_loan_request
 * \brief Typedef for m_loan_request struct.
 */
typedef struct m_loan_request m_loan_request;

/** \typedef m_loan_conditions m_loan_conditions
 * \brief Typedef for m_loan_conditions struct.
 */
typedef struct m_loan_conditions m_loan_conditions;

/** \typedef m_household_deposit m_household_deposit
 * \brief Typedef for m_household_deposit struct.
 */
typedef struct m_household_deposit m_household_deposit;

/** \typedef m_money_withdraw_request m_money_withdraw_request
 * \brief Typedef for m_money_withdraw_request struct.
 */
typedef struct m_money_withdraw_request m_money_withdraw_request;

/** \typedef m_loan_acceptance m_loan_acceptance
 * \brief Typedef for m_loan_acceptance struct.
 */
typedef struct m_loan_acceptance m_loan_acceptance;

/** \typedef m_installment m_installment
 * \brief Typedef for m_installment struct.
 */
typedef struct m_installment m_installment;

/** \typedef m_withdrawal_allowed m_withdrawal_allowed
 * \brief Typedef for m_withdrawal_allowed struct.
 */
typedef struct m_withdrawal_allowed m_withdrawal_allowed;

/** \typedef m_bankruptcy m_bankruptcy
 * \brief Typedef for m_bankruptcy struct.
 */
typedef struct m_bankruptcy m_bankruptcy;


int Firm_ask_loan(void);
int Firm_get_loan(void);
int Firm_pay_interest_installment(void);
int Bank_decide_credit_conditions(void);
int Bank_receive_deposits(void);
int Bank_return_deposits(void);
int Bank_receive_installment(void);
int Bank_give_loan(void);
int Household_put_money(void);
int Household_choose_bank(void);
int Household_withdraw(void);
int Household_withdraw_request(void);

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
	struct m_loan_request * loan_request_messages;	/**< Pointer to loan_request message list. */
	struct m_loan_conditions * loan_conditions_messages;	/**< Pointer to loan_conditions message list. */
	struct m_household_deposit * household_deposit_messages;	/**< Pointer to household_deposit message list. */
	struct m_money_withdraw_request * money_withdraw_request_messages;	/**< Pointer to money_withdraw_request message list. */
	struct m_loan_acceptance * loan_acceptance_messages;	/**< Pointer to loan_acceptance message list. */
	struct m_installment * installment_messages;	/**< Pointer to installment message list. */
	struct m_withdrawal_allowed * withdrawal_allowed_messages;	/**< Pointer to withdrawal_allowed message list. */
	struct m_bankruptcy * bankruptcy_messages;	/**< Pointer to bankruptcy message list. */
	
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

/** \var m_loan_request * temp_loan_request_message
* \brief Pointer to m_loan_request to initialise linked list. */
m_loan_request * temp_loan_request_message;
/** \var m_loan_conditions * temp_loan_conditions_message
* \brief Pointer to m_loan_conditions to initialise linked list. */
m_loan_conditions * temp_loan_conditions_message;
/** \var m_household_deposit * temp_household_deposit_message
* \brief Pointer to m_household_deposit to initialise linked list. */
m_household_deposit * temp_household_deposit_message;
/** \var m_money_withdraw_request * temp_money_withdraw_request_message
* \brief Pointer to m_money_withdraw_request to initialise linked list. */
m_money_withdraw_request * temp_money_withdraw_request_message;
/** \var m_loan_acceptance * temp_loan_acceptance_message
* \brief Pointer to m_loan_acceptance to initialise linked list. */
m_loan_acceptance * temp_loan_acceptance_message;
/** \var m_installment * temp_installment_message
* \brief Pointer to m_installment to initialise linked list. */
m_installment * temp_installment_message;
/** \var m_withdrawal_allowed * temp_withdrawal_allowed_message
* \brief Pointer to m_withdrawal_allowed to initialise linked list. */
m_withdrawal_allowed * temp_withdrawal_allowed_message;
/** \var m_bankruptcy * temp_bankruptcy_message
* \brief Pointer to m_bankruptcy to initialise linked list. */
m_bankruptcy * temp_bankruptcy_message;
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
xmachine_memory_Firm * current_xmachine_Firm;
xmachine_memory_Firm_holder * temp_xmachine_Firm_holder;
xmachine_memory_Firm_holder * current_xmachine_Firm_holder;
xmachine_memory_Firm_state * current_xmachine_Firm_next_state; /* New agents added to this state */
/* Pointer to list of Firm agents in state 04 state */
//xmachine_memory_Firm * temp_xmachine_Firm_04;
xmachine_memory_Firm_state * Firm_04_state;
/* Pointer to list of Firm agents in state 03 state */
//xmachine_memory_Firm * temp_xmachine_Firm_03;
xmachine_memory_Firm_state * Firm_03_state;
/* Pointer to list of Firm agents in state 02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_02;
xmachine_memory_Firm_state * Firm_02_state;
/* Pointer to list of Firm agents in state 01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_01;
xmachine_memory_Firm_state * Firm_01_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Bank * current_xmachine_Bank;
xmachine_memory_Bank_holder * temp_xmachine_Bank_holder;
xmachine_memory_Bank_holder * current_xmachine_Bank_holder;
xmachine_memory_Bank_state * current_xmachine_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Bank agents in state 06 state */
//xmachine_memory_Bank * temp_xmachine_Bank_06;
xmachine_memory_Bank_state * Bank_06_state;
/* Pointer to list of Bank agents in state 05 state */
//xmachine_memory_Bank * temp_xmachine_Bank_05;
xmachine_memory_Bank_state * Bank_05_state;
/* Pointer to list of Bank agents in state 04 state */
//xmachine_memory_Bank * temp_xmachine_Bank_04;
xmachine_memory_Bank_state * Bank_04_state;
/* Pointer to list of Bank agents in state 03 state */
//xmachine_memory_Bank * temp_xmachine_Bank_03;
xmachine_memory_Bank_state * Bank_03_state;
/* Pointer to list of Bank agents in state 02 state */
//xmachine_memory_Bank * temp_xmachine_Bank_02;
xmachine_memory_Bank_state * Bank_02_state;
/* Pointer to list of Bank agents in state 01 state */
//xmachine_memory_Bank * temp_xmachine_Bank_01;
xmachine_memory_Bank_state * Bank_01_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Household * current_xmachine_Household;
xmachine_memory_Household_holder * temp_xmachine_Household_holder;
xmachine_memory_Household_holder * current_xmachine_Household_holder;
xmachine_memory_Household_state * current_xmachine_Household_next_state; /* New agents added to this state */
/* Pointer to list of Household agents in state 05 state */
//xmachine_memory_Household * temp_xmachine_Household_05;
xmachine_memory_Household_state * Household_05_state;
/* Pointer to list of Household agents in state 04 state */
//xmachine_memory_Household * temp_xmachine_Household_04;
xmachine_memory_Household_state * Household_04_state;
/* Pointer to list of Household agents in state 03 state */
//xmachine_memory_Household * temp_xmachine_Household_03;
xmachine_memory_Household_state * Household_03_state;
/* Pointer to list of Household agents in state 02 state */
//xmachine_memory_Household * temp_xmachine_Household_02;
xmachine_memory_Household_state * Household_02_state;
/* Pointer to list of Household agents in state 01 state */
//xmachine_memory_Household * temp_xmachine_Household_01;
xmachine_memory_Household_state * Household_01_state;


MBt_Board b_loan_request;
MBt_Iterator i_loan_request;

MBt_Board b_loan_conditions;
MBt_Iterator i_loan_conditions;

MBt_Board b_household_deposit;
MBt_Iterator i_household_deposit;

MBt_Board b_money_withdraw_request;
MBt_Iterator i_money_withdraw_request;

MBt_Board b_loan_acceptance;
MBt_Iterator i_loan_acceptance;

MBt_Board b_installment;
MBt_Iterator i_installment;

MBt_Board b_withdrawal_allowed;
MBt_Iterator i_withdrawal_allowed;

MBt_Board b_bankruptcy;
MBt_Iterator i_bankruptcy;


/** \var m_loan_request * loan_request_message
* \brief Pointer to message struct for looping through loan_request message list */
m_loan_request * loan_request_message;
/** \var m_loan_conditions * loan_conditions_message
* \brief Pointer to message struct for looping through loan_conditions message list */
m_loan_conditions * loan_conditions_message;
/** \var m_household_deposit * household_deposit_message
* \brief Pointer to message struct for looping through household_deposit message list */
m_household_deposit * household_deposit_message;
/** \var m_money_withdraw_request * money_withdraw_request_message
* \brief Pointer to message struct for looping through money_withdraw_request message list */
m_money_withdraw_request * money_withdraw_request_message;
/** \var m_loan_acceptance * loan_acceptance_message
* \brief Pointer to message struct for looping through loan_acceptance message list */
m_loan_acceptance * loan_acceptance_message;
/** \var m_installment * installment_message
* \brief Pointer to message struct for looping through installment message list */
m_installment * installment_message;
/** \var m_withdrawal_allowed * withdrawal_allowed_message
* \brief Pointer to message struct for looping through withdrawal_allowed message list */
m_withdrawal_allowed * withdrawal_allowed_message;
/** \var m_bankruptcy * bankruptcy_message
* \brief Pointer to message struct for looping through bankruptcy message list */
m_bankruptcy * bankruptcy_message;
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

void readinitialstates(char * filename, int * itno, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata(int iteration_number);


xmachine_memory_Firm_state * init_Firm_state();
xmachine_memory_Firm * init_Firm_agent();
void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state);
void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state);
void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state);
void add_Firm_agent(int id, double_array * interest, double_array * credit_offer, int_array * contacted_bank, double total_debt, double asset, double credit_demand, double_array * installment_amount, int installment_number, int loans_number, double_array * outstanding_debt, int_array * lending_bank_id, double_array * interest_amount, int bankruptcy_state, double total_resources, double_array * residual_var, double_array * var_per_installment, double_array * value_at_risk, double_array * interest_left, double current_equity, double current_debt);
xmachine_memory_Bank_state * init_Bank_state();
xmachine_memory_Bank * init_Bank_agent();
void free_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * state);
void transition_Bank_agent(xmachine_memory_Bank_holder * tmp, xmachine_memory_Bank_state * from_state, xmachine_memory_Bank_state * to_state);
void add_Bank_agent_internal(xmachine_memory_Bank * agent, xmachine_memory_Bank_state * state);
void add_Bank_agent(int id, double cash, double total_credit, double equity, double bce_debt, double alfa, double var, double min_interest, double gamma[], double profits[], double lambda, double bce_interest, double debt_period);
xmachine_memory_Household_state * init_Household_state();
xmachine_memory_Household * init_Household_agent();
void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state);
void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state);
void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state);
void add_Household_agent(int id, double total_deposit, int bank_account);

void add_loan_request_message(double current_equity, double current_debt, double credit_demand, int firm_id, int bank_id);
m_loan_request * add_loan_request_message_internal(void);
m_loan_request * get_first_loan_request_message(void);
m_loan_request * get_next_loan_request_message(m_loan_request * current);
void freeloan_requestmessages(void);
void add_loan_conditions_message(double proposed_interest_rate, double amount_offered_credit, int firm_id, int bank_id, double var);
m_loan_conditions * add_loan_conditions_message_internal(void);
m_loan_conditions * get_first_loan_conditions_message(void);
m_loan_conditions * get_next_loan_conditions_message(m_loan_conditions * current);
void freeloan_conditionsmessages(void);
void add_household_deposit_message(double money_deposited, int bank_id, int household_id);
m_household_deposit * add_household_deposit_message_internal(void);
m_household_deposit * get_first_household_deposit_message(void);
m_household_deposit * get_next_household_deposit_message(m_household_deposit * current);
void freehousehold_depositmessages(void);
void add_money_withdraw_request_message(double money_withdraw_request, int bank_id, int household_id);
m_money_withdraw_request * add_money_withdraw_request_message_internal(void);
m_money_withdraw_request * get_first_money_withdraw_request_message(void);
m_money_withdraw_request * get_next_money_withdraw_request_message(m_money_withdraw_request * current);
void freemoney_withdraw_requestmessages(void);
void add_loan_acceptance_message(double credit_amount_taken, int bank_id);
m_loan_acceptance * add_loan_acceptance_message_internal(void);
m_loan_acceptance * get_first_loan_acceptance_message(void);
m_loan_acceptance * get_next_loan_acceptance_message(m_loan_acceptance * current);
void freeloan_acceptancemessages(void);
void add_installment_message(double installment, double interest, int bank_id, double var_per_installment);
m_installment * add_installment_message_internal(void);
m_installment * get_first_installment_message(void);
m_installment * get_next_installment_message(m_installment * current);
void freeinstallmentmessages(void);
void add_withdrawal_allowed_message(double withdrawal_allowed, int household_id);
m_withdrawal_allowed * add_withdrawal_allowed_message_internal(void);
m_withdrawal_allowed * get_first_withdrawal_allowed_message(void);
m_withdrawal_allowed * get_next_withdrawal_allowed_message(m_withdrawal_allowed * current);
void freewithdrawal_allowedmessages(void);
void add_bankruptcy_message(int bank_id, double bad_debt, double credit_refunded, double residual_var);
m_bankruptcy * add_bankruptcy_message_internal(void);
m_bankruptcy * get_first_bankruptcy_message(void);
m_bankruptcy * get_next_bankruptcy_message(m_bankruptcy * current);
void freebankruptcymessages(void);

void set_id(int id);
int get_id();
double_array * get_interest();
double_array * get_credit_offer();
int_array * get_contacted_bank();
void set_total_debt(double total_debt);
double get_total_debt();
void set_asset(double asset);
double get_asset();
void set_credit_demand(double credit_demand);
double get_credit_demand();
double_array * get_installment_amount();
void set_installment_number(int installment_number);
int get_installment_number();
void set_loans_number(int loans_number);
int get_loans_number();
double_array * get_outstanding_debt();
int_array * get_lending_bank_id();
double_array * get_interest_amount();
void set_bankruptcy_state(int bankruptcy_state);
int get_bankruptcy_state();
void set_total_resources(double total_resources);
double get_total_resources();
double_array * get_residual_var();
double_array * get_var_per_installment();
double_array * get_value_at_risk();
double_array * get_interest_left();
void set_current_equity(double current_equity);
double get_current_equity();
void set_current_debt(double current_debt);
double get_current_debt();
void set_cash(double cash);
double get_cash();
void set_total_credit(double total_credit);
double get_total_credit();
void set_equity(double equity);
double get_equity();
void set_bce_debt(double bce_debt);
double get_bce_debt();
void set_alfa(double alfa);
double get_alfa();
void set_var(double var);
double get_var();
void set_min_interest(double min_interest);
double get_min_interest();
double * get_gamma();
double * get_profits();
void set_lambda(double lambda);
double get_lambda();
void set_bce_interest(double bce_interest);
double get_bce_interest();
void set_debt_period(double debt_period);
double get_debt_period();
void set_total_deposit(double total_deposit);
double get_total_deposit();
void set_bank_account(int bank_account);
int get_bank_account();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
m_loan_request * get_next_message_loan_request_in_range(m_loan_request * current);
m_loan_conditions * get_next_message_loan_conditions_in_range(m_loan_conditions * current);
m_household_deposit * get_next_message_household_deposit_in_range(m_household_deposit * current);
m_money_withdraw_request * get_next_message_money_withdraw_request_in_range(m_money_withdraw_request * current);
m_loan_acceptance * get_next_message_loan_acceptance_in_range(m_loan_acceptance * current);
m_installment * get_next_message_installment_in_range(m_installment * current);
m_withdrawal_allowed * get_next_message_withdrawal_allowed_in_range(m_withdrawal_allowed * current);
m_bankruptcy * get_next_message_bankruptcy_in_range(m_bankruptcy * current);

/* memory.c */
xmachine * add_xmachine(void);
