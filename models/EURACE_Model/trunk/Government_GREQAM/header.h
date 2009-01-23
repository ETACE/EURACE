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
#include "mboard.h"



/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT) 
#endif


/** \def GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_UNEMPLOYMENT_BENEFIT_PCT gov_policy_unemployment_benefit_pct
/** \def GOV_POLICY_MONEY_FINANCING_FRACTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_MONEY_FINANCING_FRACTION gov_policy_money_financing_fraction
/** \def GOV_POLICY_GDP_FRACTION_CONSUMPTION
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_CONSUMPTION gov_policy_gdp_fraction_consumption
/** \def GOV_POLICY_GDP_FRACTION_INVESTMENT
 * \brief Provide access to environment variables in uppercase. */
#define GOV_POLICY_GDP_FRACTION_INVESTMENT gov_policy_gdp_fraction_investment
/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Start of loop to process central_bank_account_update messages. */
#define START_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP  central_bank_account_update_message = get_first_central_bank_account_update_message(); while(central_bank_account_update_message) {
/** \def FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP
 * \brief Finish of loop to process central_bank_account_update messages. */
#define FINISH_CENTRAL_BANK_ACCOUNT_UPDATE_MESSAGE_LOOP central_bank_account_update_message = get_next_central_bank_account_update_message(central_bank_account_update_message); }
/** \def START_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Start of loop to process tax_payment messages. */
#define START_TAX_PAYMENT_MESSAGE_LOOP  tax_payment_message = get_first_tax_payment_message(); while(tax_payment_message) {
/** \def FINISH_TAX_PAYMENT_MESSAGE_LOOP
 * \brief Finish of loop to process tax_payment messages. */
#define FINISH_TAX_PAYMENT_MESSAGE_LOOP tax_payment_message = get_next_tax_payment_message(tax_payment_message); }
/** \def START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Start of loop to process data_for_government messages. */
#define START_DATA_FOR_GOVERNMENT_MESSAGE_LOOP  data_for_government_message = get_first_data_for_government_message(); while(data_for_government_message) {
/** \def FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP
 * \brief Finish of loop to process data_for_government messages. */
#define FINISH_DATA_FOR_GOVERNMENT_MESSAGE_LOOP data_for_government_message = get_next_data_for_government_message(data_for_government_message); }
/** \def START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Start of loop to process policy_announcement messages. */
#define START_POLICY_ANNOUNCEMENT_MESSAGE_LOOP  policy_announcement_message = get_first_policy_announcement_message(); while(policy_announcement_message) {
/** \def FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP
 * \brief Finish of loop to process policy_announcement messages. */
#define FINISH_POLICY_ANNOUNCEMENT_MESSAGE_LOOP policy_announcement_message = get_next_policy_announcement_message(policy_announcement_message); }
/** \def START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process unemployment_notification messages. */
#define START_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP  unemployment_notification_message = get_first_unemployment_notification_message(); while(unemployment_notification_message) {
/** \def FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process unemployment_notification messages. */
#define FINISH_UNEMPLOYMENT_NOTIFICATION_MESSAGE_LOOP unemployment_notification_message = get_next_unemployment_notification_message(unemployment_notification_message); }
/** \def START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_transfer_notification messages. */
#define START_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP  hh_transfer_notification_message = get_first_hh_transfer_notification_message(); while(hh_transfer_notification_message) {
/** \def FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_transfer_notification messages. */
#define FINISH_HH_TRANSFER_NOTIFICATION_MESSAGE_LOOP hh_transfer_notification_message = get_next_hh_transfer_notification_message(hh_transfer_notification_message); }
/** \def START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process hh_subsidy_notification messages. */
#define START_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  hh_subsidy_notification_message = get_first_hh_subsidy_notification_message(); while(hh_subsidy_notification_message) {
/** \def FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process hh_subsidy_notification messages. */
#define FINISH_HH_SUBSIDY_NOTIFICATION_MESSAGE_LOOP hh_subsidy_notification_message = get_next_hh_subsidy_notification_message(hh_subsidy_notification_message); }
/** \def START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_transfer_notification messages. */
#define START_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP  firm_transfer_notification_message = get_first_firm_transfer_notification_message(); while(firm_transfer_notification_message) {
/** \def FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_transfer_notification messages. */
#define FINISH_FIRM_TRANSFER_NOTIFICATION_MESSAGE_LOOP firm_transfer_notification_message = get_next_firm_transfer_notification_message(firm_transfer_notification_message); }
/** \def START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Start of loop to process firm_subsidy_notification messages. */
#define START_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP  firm_subsidy_notification_message = get_first_firm_subsidy_notification_message(); while(firm_subsidy_notification_message) {
/** \def FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP
 * \brief Finish of loop to process firm_subsidy_notification messages. */
#define FINISH_FIRM_SUBSIDY_NOTIFICATION_MESSAGE_LOOP firm_subsidy_notification_message = get_next_firm_subsidy_notification_message(firm_subsidy_notification_message); }

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


/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	int day_of_month_receive_income;	/**< X-machine memory variable day_of_month_receive_income of type int. */
	int day_of_month_receive_benefit;	/**< X-machine memory variable day_of_month_receive_benefit of type int. */
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

/** \struct xmachine_memory_Firm
 * \brief Holds memory of xmachine Firm.
 */
struct xmachine_memory_Firm
{
	int id;	/**< X-machine memory variable id of type int. */
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

/** \struct xmachine_memory_Government
 * \brief Holds memory of xmachine Government.
 */
struct xmachine_memory_Government
{
	int id;	/**< X-machine memory variable id of type int. */
	double payment_account;	/**< X-machine memory variable payment_account of type double. */
	int list_of_regions[1];	/**< X-machine memory variable list_of_regions of type int. */
	double unemployment_benefit_pct;	/**< X-machine memory variable unemployment_benefit_pct of type double. */
	double tax_rate_corporate;	/**< X-machine memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< X-machine memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< X-machine memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< X-machine memory variable tax_rate_vat of type double. */
	double monthly_tax_revenues;	/**< X-machine memory variable monthly_tax_revenues of type double. */
	double yearly_tax_revenues;	/**< X-machine memory variable yearly_tax_revenues of type double. */
	double monthly_unemployment_benefit_payment;	/**< X-machine memory variable monthly_unemployment_benefit_payment of type double. */
	double yearly_unemployment_benefit_payment;	/**< X-machine memory variable yearly_unemployment_benefit_payment of type double. */
	double hh_transfer_payment;	/**< X-machine memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< X-machine memory variable firm_transfer_payment of type double. */
	double monthly_transfer_payment;	/**< X-machine memory variable monthly_transfer_payment of type double. */
	double yearly_transfer_payment;	/**< X-machine memory variable yearly_transfer_payment of type double. */
	double hh_subsidy_payment;	/**< X-machine memory variable hh_subsidy_payment of type double. */
	double firm_subsidy_payment;	/**< X-machine memory variable firm_subsidy_payment of type double. */
	double monthly_subsidy_payment;	/**< X-machine memory variable monthly_subsidy_payment of type double. */
	double yearly_subsidy_payment;	/**< X-machine memory variable yearly_subsidy_payment of type double. */
	double monthly_bond_coupon_payment;	/**< X-machine memory variable monthly_bond_coupon_payment of type double. */
	double yearly_bond_coupon_payment;	/**< X-machine memory variable yearly_bond_coupon_payment of type double. */
	double gov_interest_rate;	/**< X-machine memory variable gov_interest_rate of type double. */
	double yearly_interest_payment;	/**< X-machine memory variable yearly_interest_payment of type double. */
	double yearly_gov_investment;	/**< X-machine memory variable yearly_gov_investment of type double. */
	double yearly_gov_consumption;	/**< X-machine memory variable yearly_gov_consumption of type double. */
	double total_income;	/**< X-machine memory variable total_income of type double. */
	double total_expenditure;	/**< X-machine memory variable total_expenditure of type double. */
	double total_debt;	/**< X-machine memory variable total_debt of type double. */
	double budget_deficit;	/**< X-machine memory variable budget_deficit of type double. */
	double total_money_financing;	/**< X-machine memory variable total_money_financing of type double. */
	double total_bond_financing;	/**< X-machine memory variable total_bond_financing of type double. */
	double country_wide_mean_wage;	/**< X-machine memory variable country_wide_mean_wage of type double. */
	int num_unemployed;	/**< X-machine memory variable num_unemployed of type int. */
	double gdp;	/**< X-machine memory variable gdp of type double. */
	double gdp_growth;	/**< X-machine memory variable gdp_growth of type double. */
	double gdp_forecast;	/**< X-machine memory variable gdp_forecast of type double. */
	double total_income_forecast;	/**< X-machine memory variable total_income_forecast of type double. */
	double total_expenditure_forecast;	/**< X-machine memory variable total_expenditure_forecast of type double. */
	double budget_forecast;	/**< X-machine memory variable budget_forecast of type double. */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_holder
{
	struct xmachine_memory_Government * agent;	/**< Pointer to X-machine memory Government. */

	struct xmachine_memory_Government_holder * prev;	/**< Pointer to previous Government agent in the list.  */
	struct xmachine_memory_Government_holder * next;	/**< Pointer to next Government agent in the list.  */
};

/** \struct xmachine_memory_Government_holder
 * \brief Holds struct of memory of xmachine Government.
 */
struct xmachine_memory_Government_state
{
	struct xmachine_memory_Government_holder * agents;	/**< Pointer to X-machine memory Government. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Central_Bank
 * \brief Holds memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank
{
	double bank_accounts[30];	/**< X-machine memory variable bank_accounts of type double. */
	double gov_accounts[30];	/**< X-machine memory variable gov_accounts of type double. */
};

/** \struct xmachine_memory_Central_Bank_holder
 * \brief Holds struct of memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank_holder
{
	struct xmachine_memory_Central_Bank * agent;	/**< Pointer to X-machine memory Central_Bank. */

	struct xmachine_memory_Central_Bank_holder * prev;	/**< Pointer to previous Central_Bank agent in the list.  */
	struct xmachine_memory_Central_Bank_holder * next;	/**< Pointer to next Central_Bank agent in the list.  */
};

/** \struct xmachine_memory_Central_Bank_holder
 * \brief Holds struct of memory of xmachine Central_Bank.
 */
struct xmachine_memory_Central_Bank_state
{
	struct xmachine_memory_Central_Bank_holder * agents;	/**< Pointer to X-machine memory Central_Bank. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	struct xmachine_memory_Firm * xmachine_Firm;	/**< Pointer to X-machine memory of type Firm.  */
	struct xmachine_memory_Government * xmachine_Government;	/**< Pointer to X-machine memory of type Government.  */
	struct xmachine_memory_Central_Bank * xmachine_Central_Bank;	/**< Pointer to X-machine memory of type Central_Bank.  */
	
	//struct xmachine * prev;	/**< Pointer to previous X-machine in the list.  */
	//struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct m_central_bank_account_update
 * \brief Holds message of type central_bank_account_update_message.
 */
struct m_central_bank_account_update
{
	int id;	/**< Message memory variable id of type int. */
	double payment_account;	/**< Message memory variable payment_account of type double. */
};

/** \struct m_tax_payment
 * \brief Holds message of type tax_payment_message.
 */
struct m_tax_payment
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_payment;	/**< Message memory variable tax_payment of type double. */
};

/** \struct m_data_for_government
 * \brief Holds message of type data_for_government_message.
 */
struct m_data_for_government
{
	int region_id;	/**< Message memory variable region_id of type int. */
	double gdp;	/**< Message memory variable gdp of type double. */
	double mean_wage;	/**< Message memory variable mean_wage of type double. */
};

/** \struct m_policy_announcement
 * \brief Holds message of type policy_announcement_message.
 */
struct m_policy_announcement
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double tax_rate_corporate;	/**< Message memory variable tax_rate_corporate of type double. */
	double tax_rate_hh_labour;	/**< Message memory variable tax_rate_hh_labour of type double. */
	double tax_rate_hh_capital;	/**< Message memory variable tax_rate_hh_capital of type double. */
	double tax_rate_vat;	/**< Message memory variable tax_rate_vat of type double. */
	double unemployment_benefit_pct;	/**< Message memory variable unemployment_benefit_pct of type double. */
	double hh_subsidy_payment;	/**< Message memory variable hh_subsidy_payment of type double. */
	double firm_subsidy_payment;	/**< Message memory variable firm_subsidy_payment of type double. */
	double hh_transfer_payment;	/**< Message memory variable hh_transfer_payment of type double. */
	double firm_transfer_payment;	/**< Message memory variable firm_transfer_payment of type double. */
};

/** \struct m_unemployment_notification
 * \brief Holds message of type unemployment_notification_message.
 */
struct m_unemployment_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
	double last_labour_income;	/**< Message memory variable last_labour_income of type double. */
};

/** \struct m_hh_transfer_notification
 * \brief Holds message of type hh_transfer_notification_message.
 */
struct m_hh_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_hh_subsidy_notification
 * \brief Holds message of type hh_subsidy_notification_message.
 */
struct m_hh_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_firm_transfer_notification
 * \brief Holds message of type firm_transfer_notification_message.
 */
struct m_firm_transfer_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
};

/** \struct m_firm_subsidy_notification
 * \brief Holds message of type firm_subsidy_notification_message.
 */
struct m_firm_subsidy_notification
{
	int gov_id;	/**< Message memory variable gov_id of type int. */
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
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government xmachine_memory_Government;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_holder xmachine_memory_Government_holder;
/** \var typedef xmachine_memory_Government xmachine_memory_Government
 * \brief Typedef for xmachine_memory_Government struct.
 */
typedef struct xmachine_memory_Government_state xmachine_memory_Government_state;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank xmachine_memory_Central_Bank;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank_holder xmachine_memory_Central_Bank_holder;
/** \var typedef xmachine_memory_Central_Bank xmachine_memory_Central_Bank
 * \brief Typedef for xmachine_memory_Central_Bank struct.
 */
typedef struct xmachine_memory_Central_Bank_state xmachine_memory_Central_Bank_state;
/** \typedef m_central_bank_account_update m_central_bank_account_update
 * \brief Typedef for m_central_bank_account_update struct.
 */
typedef struct m_central_bank_account_update m_central_bank_account_update;

/** \typedef m_tax_payment m_tax_payment
 * \brief Typedef for m_tax_payment struct.
 */
typedef struct m_tax_payment m_tax_payment;

/** \typedef m_data_for_government m_data_for_government
 * \brief Typedef for m_data_for_government struct.
 */
typedef struct m_data_for_government m_data_for_government;

/** \typedef m_policy_announcement m_policy_announcement
 * \brief Typedef for m_policy_announcement struct.
 */
typedef struct m_policy_announcement m_policy_announcement;

/** \typedef m_unemployment_notification m_unemployment_notification
 * \brief Typedef for m_unemployment_notification struct.
 */
typedef struct m_unemployment_notification m_unemployment_notification;

/** \typedef m_hh_transfer_notification m_hh_transfer_notification
 * \brief Typedef for m_hh_transfer_notification struct.
 */
typedef struct m_hh_transfer_notification m_hh_transfer_notification;

/** \typedef m_hh_subsidy_notification m_hh_subsidy_notification
 * \brief Typedef for m_hh_subsidy_notification struct.
 */
typedef struct m_hh_subsidy_notification m_hh_subsidy_notification;

/** \typedef m_firm_transfer_notification m_firm_transfer_notification
 * \brief Typedef for m_firm_transfer_notification struct.
 */
typedef struct m_firm_transfer_notification m_firm_transfer_notification;

/** \typedef m_firm_subsidy_notification m_firm_subsidy_notification
 * \brief Typedef for m_firm_subsidy_notification struct.
 */
typedef struct m_firm_subsidy_notification m_firm_subsidy_notification;


int Household_idle(void);
int Household_Household_idle_start_Household_01_condition(xmachine_memory_Household *a);
int Household_read_policy_announcements(void);
int Household_Household_read_policy_announcements_start_Household_01_condition(xmachine_memory_Household *a);
int Household_send_tax_payment(void);
int Household_send_subsidy_notification(void);
int Household_send_transfer_notification(void);
int Household_idle(void);
int Household_Household_idle_04_end_Household_condition(xmachine_memory_Household *a);
int Household_send_unemployment_benefit_notification(void);
int Household_Household_send_unemployment_benefit_notification_04_end_Household_condition(xmachine_memory_Household *a);
int Firm_idle(void);
int Firm_Firm_idle_start_Firm_01_condition(xmachine_memory_Firm *a);
int Firm_read_policy_announcements(void);
int Firm_Firm_read_policy_announcements_start_Firm_01_condition(xmachine_memory_Firm *a);
int Firm_send_tax_payment(void);
int Firm_send_subsidy_notification(void);
int Firm_send_transfer_notification(void);
int Government_idle(void);
int Government_Government_idle_start_Government_01_condition(xmachine_memory_Government *a);
int Government_send_policy_announcements(void);
int Government_Government_send_policy_announcements_start_Government_01_condition(xmachine_memory_Government *a);
int Government_read_tax_payments(void);
int Government_Government_read_tax_payments_tax_payment_filter(const void *msg, const void *params);
int Government_read_subsidy_notifications(void);
int Government_Government_read_subsidy_notifications_hh_subsidy_notification_filter(const void *msg, const void *params);
int Government_Government_read_subsidy_notifications_firm_subsidy_notification_filter(const void *msg, const void *params);
int Government_read_transfer_notifications(void);
int Government_Government_read_transfer_notifications_hh_transfer_notification_filter(const void *msg, const void *params);
int Government_Government_read_transfer_notifications_firm_transfer_notification_filter(const void *msg, const void *params);
int Government_read_unemployment_benefit_notifications(void);
int Government_Government_read_unemployment_benefit_notifications_unemployment_notification_filter(const void *msg, const void *params);
int Government_idle(void);
int Government_Government_idle_Gov_Start_Monthly_Loop_Gov_Start_Yearly_Loop_condition(xmachine_memory_Government *a);
int Government_monthly_budget_accounting(void);
int Government_Government_monthly_budget_accounting_Gov_Start_Monthly_Loop_05_condition(xmachine_memory_Government *a);
int Government_monthly_resetting(void);
int Government_send_account_update(void);
int Government_read_data_from_Eurostat(void);
int Government_set_policy(void);
int Government_yearly_resetting(void);
int idle(void);
int Government_idle_Gov_Start_Yearly_Loop_end_Government_condition(xmachine_memory_Government *a);
int Government_yearly_budget_accounting(void);
int Government_Government_yearly_budget_accounting_Gov_Start_Yearly_Loop_07_condition(xmachine_memory_Government *a);
int Central_Bank_read_account_update(void);

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
	struct m_central_bank_account_update * central_bank_account_update_messages;	/**< Pointer to central_bank_account_update message list. */
	struct m_tax_payment * tax_payment_messages;	/**< Pointer to tax_payment message list. */
	struct m_data_for_government * data_for_government_messages;	/**< Pointer to data_for_government message list. */
	struct m_policy_announcement * policy_announcement_messages;	/**< Pointer to policy_announcement message list. */
	struct m_unemployment_notification * unemployment_notification_messages;	/**< Pointer to unemployment_notification message list. */
	struct m_hh_transfer_notification * hh_transfer_notification_messages;	/**< Pointer to hh_transfer_notification message list. */
	struct m_hh_subsidy_notification * hh_subsidy_notification_messages;	/**< Pointer to hh_subsidy_notification message list. */
	struct m_firm_transfer_notification * firm_transfer_notification_messages;	/**< Pointer to firm_transfer_notification message list. */
	struct m_firm_subsidy_notification * firm_subsidy_notification_messages;	/**< Pointer to firm_subsidy_notification message list. */
	
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

/** \var double gov_policy_unemployment_benefit_pct
* \brief A constant variable from the environment. */
double gov_policy_unemployment_benefit_pct;
/** \var double gov_policy_money_financing_fraction
* \brief A constant variable from the environment. */
double gov_policy_money_financing_fraction;
/** \var double gov_policy_gdp_fraction_consumption
* \brief A constant variable from the environment. */
double gov_policy_gdp_fraction_consumption;
/** \var double gov_policy_gdp_fraction_investment
* \brief A constant variable from the environment. */
double gov_policy_gdp_fraction_investment;
/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_central_bank_account_update * temp_central_bank_account_update_message
* \brief Pointer to m_central_bank_account_update to initialise linked list. */
m_central_bank_account_update * temp_central_bank_account_update_message;
/** \var m_tax_payment * temp_tax_payment_message
* \brief Pointer to m_tax_payment to initialise linked list. */
m_tax_payment * temp_tax_payment_message;
/** \var m_data_for_government * temp_data_for_government_message
* \brief Pointer to m_data_for_government to initialise linked list. */
m_data_for_government * temp_data_for_government_message;
/** \var m_policy_announcement * temp_policy_announcement_message
* \brief Pointer to m_policy_announcement to initialise linked list. */
m_policy_announcement * temp_policy_announcement_message;
/** \var m_unemployment_notification * temp_unemployment_notification_message
* \brief Pointer to m_unemployment_notification to initialise linked list. */
m_unemployment_notification * temp_unemployment_notification_message;
/** \var m_hh_transfer_notification * temp_hh_transfer_notification_message
* \brief Pointer to m_hh_transfer_notification to initialise linked list. */
m_hh_transfer_notification * temp_hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * temp_hh_subsidy_notification_message
* \brief Pointer to m_hh_subsidy_notification to initialise linked list. */
m_hh_subsidy_notification * temp_hh_subsidy_notification_message;
/** \var m_firm_transfer_notification * temp_firm_transfer_notification_message
* \brief Pointer to m_firm_transfer_notification to initialise linked list. */
m_firm_transfer_notification * temp_firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * temp_firm_subsidy_notification_message
* \brief Pointer to m_firm_subsidy_notification to initialise linked list. */
m_firm_subsidy_notification * temp_firm_subsidy_notification_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[100]
* \brief Output path for files. */
char outputpath[100];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
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
/* Pointer to list of Household agents in state end_Household state */
//xmachine_memory_Household * temp_xmachine_Household_end_Household;
xmachine_memory_Household_state * Household_end_Household_state;
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
/* Pointer to list of Household agents in state start_Household state */
//xmachine_memory_Household * temp_xmachine_Household_start_Household;
xmachine_memory_Household_state * Household_start_Household_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Firm * current_xmachine_Firm;
xmachine_memory_Firm_holder * temp_xmachine_Firm_holder;
xmachine_memory_Firm_holder * current_xmachine_Firm_holder;
xmachine_memory_Firm_state * current_xmachine_Firm_next_state; /* New agents added to this state */
/* Pointer to list of Firm agents in state end_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_end_Firm;
xmachine_memory_Firm_state * Firm_end_Firm_state;
/* Pointer to list of Firm agents in state 03 state */
//xmachine_memory_Firm * temp_xmachine_Firm_03;
xmachine_memory_Firm_state * Firm_03_state;
/* Pointer to list of Firm agents in state 02 state */
//xmachine_memory_Firm * temp_xmachine_Firm_02;
xmachine_memory_Firm_state * Firm_02_state;
/* Pointer to list of Firm agents in state 01 state */
//xmachine_memory_Firm * temp_xmachine_Firm_01;
xmachine_memory_Firm_state * Firm_01_state;
/* Pointer to list of Firm agents in state start_Firm state */
//xmachine_memory_Firm * temp_xmachine_Firm_start_Firm;
xmachine_memory_Firm_state * Firm_start_Firm_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Government * current_xmachine_Government;
xmachine_memory_Government_holder * temp_xmachine_Government_holder;
xmachine_memory_Government_holder * current_xmachine_Government_holder;
xmachine_memory_Government_state * current_xmachine_Government_next_state; /* New agents added to this state */
/* Pointer to list of Government agents in state end_Government state */
//xmachine_memory_Government * temp_xmachine_Government_end_Government;
xmachine_memory_Government_state * Government_end_Government_state;
/* Pointer to list of Government agents in state 09 state */
//xmachine_memory_Government * temp_xmachine_Government_09;
xmachine_memory_Government_state * Government_09_state;
/* Pointer to list of Government agents in state 08 state */
//xmachine_memory_Government * temp_xmachine_Government_08;
xmachine_memory_Government_state * Government_08_state;
/* Pointer to list of Government agents in state 07 state */
//xmachine_memory_Government * temp_xmachine_Government_07;
xmachine_memory_Government_state * Government_07_state;
/* Pointer to list of Government agents in state 06 state */
//xmachine_memory_Government * temp_xmachine_Government_06;
xmachine_memory_Government_state * Government_06_state;
/* Pointer to list of Government agents in state 05 state */
//xmachine_memory_Government * temp_xmachine_Government_05;
xmachine_memory_Government_state * Government_05_state;
/* Pointer to list of Government agents in state Gov_Start_Yearly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Yearly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Yearly_Loop_state;
/* Pointer to list of Government agents in state Gov_Start_Monthly_Loop state */
//xmachine_memory_Government * temp_xmachine_Government_Gov_Start_Monthly_Loop;
xmachine_memory_Government_state * Government_Gov_Start_Monthly_Loop_state;
/* Pointer to list of Government agents in state 04 state */
//xmachine_memory_Government * temp_xmachine_Government_04;
xmachine_memory_Government_state * Government_04_state;
/* Pointer to list of Government agents in state 03 state */
//xmachine_memory_Government * temp_xmachine_Government_03;
xmachine_memory_Government_state * Government_03_state;
/* Pointer to list of Government agents in state 02 state */
//xmachine_memory_Government * temp_xmachine_Government_02;
xmachine_memory_Government_state * Government_02_state;
/* Pointer to list of Government agents in state 01 state */
//xmachine_memory_Government * temp_xmachine_Government_01;
xmachine_memory_Government_state * Government_01_state;
/* Pointer to list of Government agents in state start_Government state */
//xmachine_memory_Government * temp_xmachine_Government_start_Government;
xmachine_memory_Government_state * Government_start_Government_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Central_Bank * current_xmachine_Central_Bank;
xmachine_memory_Central_Bank_holder * temp_xmachine_Central_Bank_holder;
xmachine_memory_Central_Bank_holder * current_xmachine_Central_Bank_holder;
xmachine_memory_Central_Bank_state * current_xmachine_Central_Bank_next_state; /* New agents added to this state */
/* Pointer to list of Central_Bank agents in state end_Central_Bank state */
//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank_end_Central_Bank;
xmachine_memory_Central_Bank_state * Central_Bank_end_Central_Bank_state;
/* Pointer to list of Central_Bank agents in state start_Central_Bank state */
//xmachine_memory_Central_Bank * temp_xmachine_Central_Bank_start_Central_Bank;
xmachine_memory_Central_Bank_state * Central_Bank_start_Central_Bank_state;


MBt_Board b_central_bank_account_update;
MBt_Iterator i_central_bank_account_update;

MBt_Board b_tax_payment;
MBt_Iterator i_tax_payment;

MBt_Board b_data_for_government;
MBt_Iterator i_data_for_government;

MBt_Board b_policy_announcement;
MBt_Iterator i_policy_announcement;

MBt_Board b_unemployment_notification;
MBt_Iterator i_unemployment_notification;

MBt_Board b_hh_transfer_notification;
MBt_Iterator i_hh_transfer_notification;

MBt_Board b_hh_subsidy_notification;
MBt_Iterator i_hh_subsidy_notification;

MBt_Board b_firm_transfer_notification;
MBt_Iterator i_firm_transfer_notification;

MBt_Board b_firm_subsidy_notification;
MBt_Iterator i_firm_subsidy_notification;


/** \var m_central_bank_account_update * central_bank_account_update_message
* \brief Pointer to message struct for looping through central_bank_account_update message list */
m_central_bank_account_update * central_bank_account_update_message;
/** \var m_tax_payment * tax_payment_message
* \brief Pointer to message struct for looping through tax_payment message list */
m_tax_payment * tax_payment_message;
/** \var m_data_for_government * data_for_government_message
* \brief Pointer to message struct for looping through data_for_government message list */
m_data_for_government * data_for_government_message;
/** \var m_policy_announcement * policy_announcement_message
* \brief Pointer to message struct for looping through policy_announcement message list */
m_policy_announcement * policy_announcement_message;
/** \var m_unemployment_notification * unemployment_notification_message
* \brief Pointer to message struct for looping through unemployment_notification message list */
m_unemployment_notification * unemployment_notification_message;
/** \var m_hh_transfer_notification * hh_transfer_notification_message
* \brief Pointer to message struct for looping through hh_transfer_notification message list */
m_hh_transfer_notification * hh_transfer_notification_message;
/** \var m_hh_subsidy_notification * hh_subsidy_notification_message
* \brief Pointer to message struct for looping through hh_subsidy_notification message list */
m_hh_subsidy_notification * hh_subsidy_notification_message;
/** \var m_firm_transfer_notification * firm_transfer_notification_message
* \brief Pointer to message struct for looping through firm_transfer_notification message list */
m_firm_transfer_notification * firm_transfer_notification_message;
/** \var m_firm_subsidy_notification * firm_subsidy_notification_message
* \brief Pointer to message struct for looping through firm_subsidy_notification message list */
m_firm_subsidy_notification * firm_subsidy_notification_message;
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

void readinitialstates(char * filename, int * itno, double cloud_data[6], 
                       int partition_method, int flag);
void saveiterationdata(int iteration_number);


xmachine_memory_Household_state * init_Household_state();
xmachine_memory_Household * init_Household_agent();
void free_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * state);
void transition_Household_agent(xmachine_memory_Household_holder * tmp, xmachine_memory_Household_state * from_state, xmachine_memory_Household_state * to_state);
void add_Household_agent_internal(xmachine_memory_Household * agent, xmachine_memory_Household_state * state);
void add_Household_agent(int id, int day_of_month_receive_income, int day_of_month_receive_benefit);
void unittest_init_Household_agent();
void unittest_free_Household_agent();
xmachine_memory_Firm_state * init_Firm_state();
xmachine_memory_Firm * init_Firm_agent();
void free_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * state);
void transition_Firm_agent(xmachine_memory_Firm_holder * tmp, xmachine_memory_Firm_state * from_state, xmachine_memory_Firm_state * to_state);
void add_Firm_agent_internal(xmachine_memory_Firm * agent, xmachine_memory_Firm_state * state);
void add_Firm_agent(int id);
void unittest_init_Firm_agent();
void unittest_free_Firm_agent();
xmachine_memory_Government_state * init_Government_state();
xmachine_memory_Government * init_Government_agent();
void free_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * state);
void transition_Government_agent(xmachine_memory_Government_holder * tmp, xmachine_memory_Government_state * from_state, xmachine_memory_Government_state * to_state);
void add_Government_agent_internal(xmachine_memory_Government * agent, xmachine_memory_Government_state * state);
void add_Government_agent(int id, double payment_account, int list_of_regions[], double unemployment_benefit_pct, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double monthly_tax_revenues, double yearly_tax_revenues, double monthly_unemployment_benefit_payment, double yearly_unemployment_benefit_payment, double hh_transfer_payment, double firm_transfer_payment, double monthly_transfer_payment, double yearly_transfer_payment, double hh_subsidy_payment, double firm_subsidy_payment, double monthly_subsidy_payment, double yearly_subsidy_payment, double monthly_bond_coupon_payment, double yearly_bond_coupon_payment, double gov_interest_rate, double yearly_interest_payment, double yearly_gov_investment, double yearly_gov_consumption, double total_income, double total_expenditure, double total_debt, double budget_deficit, double total_money_financing, double total_bond_financing, double country_wide_mean_wage, int num_unemployed, double gdp, double gdp_growth, double gdp_forecast, double total_income_forecast, double total_expenditure_forecast, double budget_forecast);
void unittest_init_Government_agent();
void unittest_free_Government_agent();
xmachine_memory_Central_Bank_state * init_Central_Bank_state();
xmachine_memory_Central_Bank * init_Central_Bank_agent();
void free_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * state);
void transition_Central_Bank_agent(xmachine_memory_Central_Bank_holder * tmp, xmachine_memory_Central_Bank_state * from_state, xmachine_memory_Central_Bank_state * to_state);
void add_Central_Bank_agent_internal(xmachine_memory_Central_Bank * agent, xmachine_memory_Central_Bank_state * state);
void add_Central_Bank_agent(double bank_accounts[], double gov_accounts[]);
void unittest_init_Central_Bank_agent();
void unittest_free_Central_Bank_agent();

void add_central_bank_account_update_message(int id, double payment_account);
m_central_bank_account_update * add_central_bank_account_update_message_internal(void);
m_central_bank_account_update * get_first_central_bank_account_update_message(void);
m_central_bank_account_update * get_next_central_bank_account_update_message(m_central_bank_account_update * current);
void freecentral_bank_account_updatemessages(void);
void add_tax_payment_message(int gov_id, double tax_payment);
m_tax_payment * add_tax_payment_message_internal(void);
m_tax_payment * get_first_tax_payment_message(void);
m_tax_payment * get_next_tax_payment_message(m_tax_payment * current);
void freetax_paymentmessages(void);
void add_data_for_government_message(int region_id, double gdp, double mean_wage);
m_data_for_government * add_data_for_government_message_internal(void);
m_data_for_government * get_first_data_for_government_message(void);
m_data_for_government * get_next_data_for_government_message(m_data_for_government * current);
void freedata_for_governmentmessages(void);
void add_policy_announcement_message(int gov_id, double tax_rate_corporate, double tax_rate_hh_labour, double tax_rate_hh_capital, double tax_rate_vat, double unemployment_benefit_pct, double hh_subsidy_payment, double firm_subsidy_payment, double hh_transfer_payment, double firm_transfer_payment);
m_policy_announcement * add_policy_announcement_message_internal(void);
m_policy_announcement * get_first_policy_announcement_message(void);
m_policy_announcement * get_next_policy_announcement_message(m_policy_announcement * current);
void freepolicy_announcementmessages(void);
void add_unemployment_notification_message(int gov_id, double last_labour_income);
m_unemployment_notification * add_unemployment_notification_message_internal(void);
m_unemployment_notification * get_first_unemployment_notification_message(void);
m_unemployment_notification * get_next_unemployment_notification_message(m_unemployment_notification * current);
void freeunemployment_notificationmessages(void);
void add_hh_transfer_notification_message(int gov_id);
m_hh_transfer_notification * add_hh_transfer_notification_message_internal(void);
m_hh_transfer_notification * get_first_hh_transfer_notification_message(void);
m_hh_transfer_notification * get_next_hh_transfer_notification_message(m_hh_transfer_notification * current);
void freehh_transfer_notificationmessages(void);
void add_hh_subsidy_notification_message(int gov_id);
m_hh_subsidy_notification * add_hh_subsidy_notification_message_internal(void);
m_hh_subsidy_notification * get_first_hh_subsidy_notification_message(void);
m_hh_subsidy_notification * get_next_hh_subsidy_notification_message(m_hh_subsidy_notification * current);
void freehh_subsidy_notificationmessages(void);
void add_firm_transfer_notification_message(int gov_id);
m_firm_transfer_notification * add_firm_transfer_notification_message_internal(void);
m_firm_transfer_notification * get_first_firm_transfer_notification_message(void);
m_firm_transfer_notification * get_next_firm_transfer_notification_message(m_firm_transfer_notification * current);
void freefirm_transfer_notificationmessages(void);
void add_firm_subsidy_notification_message(int gov_id);
m_firm_subsidy_notification * add_firm_subsidy_notification_message_internal(void);
m_firm_subsidy_notification * get_first_firm_subsidy_notification_message(void);
m_firm_subsidy_notification * get_next_firm_subsidy_notification_message(m_firm_subsidy_notification * current);
void freefirm_subsidy_notificationmessages(void);

void set_id(int id);
int get_id();
void set_day_of_month_receive_income(int day_of_month_receive_income);
int get_day_of_month_receive_income();
void set_day_of_month_receive_benefit(int day_of_month_receive_benefit);
int get_day_of_month_receive_benefit();
void set_payment_account(double payment_account);
double get_payment_account();
int * get_list_of_regions();
void set_unemployment_benefit_pct(double unemployment_benefit_pct);
double get_unemployment_benefit_pct();
void set_tax_rate_corporate(double tax_rate_corporate);
double get_tax_rate_corporate();
void set_tax_rate_hh_labour(double tax_rate_hh_labour);
double get_tax_rate_hh_labour();
void set_tax_rate_hh_capital(double tax_rate_hh_capital);
double get_tax_rate_hh_capital();
void set_tax_rate_vat(double tax_rate_vat);
double get_tax_rate_vat();
void set_monthly_tax_revenues(double monthly_tax_revenues);
double get_monthly_tax_revenues();
void set_yearly_tax_revenues(double yearly_tax_revenues);
double get_yearly_tax_revenues();
void set_monthly_unemployment_benefit_payment(double monthly_unemployment_benefit_payment);
double get_monthly_unemployment_benefit_payment();
void set_yearly_unemployment_benefit_payment(double yearly_unemployment_benefit_payment);
double get_yearly_unemployment_benefit_payment();
void set_hh_transfer_payment(double hh_transfer_payment);
double get_hh_transfer_payment();
void set_firm_transfer_payment(double firm_transfer_payment);
double get_firm_transfer_payment();
void set_monthly_transfer_payment(double monthly_transfer_payment);
double get_monthly_transfer_payment();
void set_yearly_transfer_payment(double yearly_transfer_payment);
double get_yearly_transfer_payment();
void set_hh_subsidy_payment(double hh_subsidy_payment);
double get_hh_subsidy_payment();
void set_firm_subsidy_payment(double firm_subsidy_payment);
double get_firm_subsidy_payment();
void set_monthly_subsidy_payment(double monthly_subsidy_payment);
double get_monthly_subsidy_payment();
void set_yearly_subsidy_payment(double yearly_subsidy_payment);
double get_yearly_subsidy_payment();
void set_monthly_bond_coupon_payment(double monthly_bond_coupon_payment);
double get_monthly_bond_coupon_payment();
void set_yearly_bond_coupon_payment(double yearly_bond_coupon_payment);
double get_yearly_bond_coupon_payment();
void set_gov_interest_rate(double gov_interest_rate);
double get_gov_interest_rate();
void set_yearly_interest_payment(double yearly_interest_payment);
double get_yearly_interest_payment();
void set_yearly_gov_investment(double yearly_gov_investment);
double get_yearly_gov_investment();
void set_yearly_gov_consumption(double yearly_gov_consumption);
double get_yearly_gov_consumption();
void set_total_income(double total_income);
double get_total_income();
void set_total_expenditure(double total_expenditure);
double get_total_expenditure();
void set_total_debt(double total_debt);
double get_total_debt();
void set_budget_deficit(double budget_deficit);
double get_budget_deficit();
void set_total_money_financing(double total_money_financing);
double get_total_money_financing();
void set_total_bond_financing(double total_bond_financing);
double get_total_bond_financing();
void set_country_wide_mean_wage(double country_wide_mean_wage);
double get_country_wide_mean_wage();
void set_num_unemployed(int num_unemployed);
int get_num_unemployed();
void set_gdp(double gdp);
double get_gdp();
void set_gdp_growth(double gdp_growth);
double get_gdp_growth();
void set_gdp_forecast(double gdp_forecast);
double get_gdp_forecast();
void set_total_income_forecast(double total_income_forecast);
double get_total_income_forecast();
void set_total_expenditure_forecast(double total_expenditure_forecast);
double get_total_expenditure_forecast();
void set_budget_forecast(double budget_forecast);
double get_budget_forecast();
double * get_bank_accounts();
double * get_gov_accounts();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
m_central_bank_account_update * get_next_message_central_bank_account_update_in_range(m_central_bank_account_update * current);
m_tax_payment * get_next_message_tax_payment_in_range(m_tax_payment * current);
m_data_for_government * get_next_message_data_for_government_in_range(m_data_for_government * current);
m_policy_announcement * get_next_message_policy_announcement_in_range(m_policy_announcement * current);
m_unemployment_notification * get_next_message_unemployment_notification_in_range(m_unemployment_notification * current);
m_hh_transfer_notification * get_next_message_hh_transfer_notification_in_range(m_hh_transfer_notification * current);
m_hh_subsidy_notification * get_next_message_hh_subsidy_notification_in_range(m_hh_subsidy_notification * current);
m_firm_transfer_notification * get_next_message_firm_transfer_notification_in_range(m_firm_transfer_notification * current);
m_firm_subsidy_notification * get_next_message_firm_subsidy_notification_in_range(m_firm_subsidy_notification * current);

/* memory.c */
xmachine * add_xmachine(void);
/* timing.c */
double get_time(void);
