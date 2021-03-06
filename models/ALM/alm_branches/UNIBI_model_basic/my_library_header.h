/**
 * \file  my_library_header.h
 * \brief Header for user created library functions.
 */

/** \def DAY
 * \brief The day count. */
#define DAY iteration_loop

/** \def WEEK
 * \brief Number of days in a week. */
#define WEEK 5
/** \def MONTH
 * \brief Number of days in a month. */
#define MONTH 20
/** \def QUARTER
 * \brief The number of days in a quarter. */
#define QUARTER 60
/** \def MSGDATA
 * \brief The additional data that messages need when sent. */
#define MSGDATA 1.0, 0.0, 0.0, 0.0
/** \def PRINT_LOG
 * \brief A flag to print log to terminal. */
#define PRINT_LOG 1

/*Number of Households*/
#define NO_HOUSEHOLDS 400

/*Strenght of logit*/
#define GAMMA -5

/*brief Paramater for production function. */
#define ALPHA 0.662

/*brief Paramater for production function. */
#define BETA 0.338

/*brief Dividend rate of consumption goods producers. */
#define DIVIDEND_RATE 1

/*brief deprication rate. */
#define DEPRECIATION_RATE 0.01

/*brief Discount rate*/
#define DISCOUNT_RATE 0.05

/*brief Strenght of adaption of the capital stock if firm is rationed on the labor market*/
#define TETA 0.0

/*additional production if stocks are empty*/
#define ADDITIONAL_PRODUCTION 0.6

/*brief Pricing rule: mark up on unit costs. */
#define MARK_UP 0.2

/*Strenght of the influence of the actual demand on the next production quantity: if LAMBDA = 0 then the planned production quantities of the last periods are recognized. If LAMBDA = 1 then the only the actual demand is recognized*/
#define LAMBDA 0.5

/*adaption of the wage offer: percent*/
#define wage_update 0.02

/*min number of vacancies to trigger vacancy counter*/
#define MIN_VACANCY 2

/*use of Deaton's saving rule (yes=1)*/
#define DEATON_SAVING_RULE_TRUE 1

		
/*adaption of the reservation wage: prercent*/
#define wage_reservation_update 0.02

/*Cost of working in a different region: for example travelling costs*/
#define region_cost 0.2

/*calculatory cost of storing one unit over one period*/
#define INVENTORY_COSTS_PER_UNIT 0

/*percent of employees who are searching for a new job*/
#define ON_THE_JOB_SEARCH_RATE 10

/*INITIAL_CONSUMPTION_PROPENSITY times the mean income is the upper limit of the consumtion during the first five periods: smooth the consumption expenditures because of high dividend payments of the capital goods producer*/
#define INITIAL_CONSUMPTION_PROPENSITY  0.95

/*percent of savings which can by used for consumption*/
#define CONSUMPTION_PROPENSITY 0.9

/*Planning horizon of firms*/
#define FIRM_PLANNING_HORIZON 10

#define INV_INERTIA 3

#define ADAPTION_DELIVERY_VOLUME 0.02

/*Probability for the delivery if the critical stock of one mall was zero for the last periods*/
#define DELIVERY_PROB_IF_CRITICAL_STOCK_0 25

/*Parameter for the adaptation of the production volume due to insufficient finances to pay for factor inputs*/
#define ADAPTION_PRODUCTION_VOLUME_DUE_TO_INSUFFICIENT_FINANCES 0.01

/* Fraction of the obtained external financial resources that is reserved for delayed payments
 * (subtracted from the payment account when we compare production costs to finances available)
 */
#define FRACTION_RESERVED_FOR_DELAYED_PAYMENTS 0.5


void sort_vacancy_list(vacancy_array * vacancy_list);
void sort_job_offer_list(job_offer_array * job_offer_list);
int random_int(int min,int max);
void sort_job_application_list(job_application_array * job_application_list);
void sort_mall_sales_list(sales_statistics_array * sales_mall_list);


int vacancy_list_rank_wage_offer_function(const void *x, const void *y);
int job_offer_list_rank_wage_offer_function(const void *x, const void *y);
int employee_list_rank_specific_skills_function(const void *x, const void *y);
int job_application_list_rank_general_skill_function(const void *x, const void *y);
int sales_statistics_list_rank_sales_function(const void *x, const void *y);
int random_int(int min,int max);
