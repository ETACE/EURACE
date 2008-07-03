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
#define NO_HOUSEHOLDS 1600

/*Strenght of logit*/
#define GAMMA -2

/*brief Paramater for production function. */
#define ALPHA 0.662

/*brief Paramater for production function. */
#define BETA 0.338

/*brief Dividend rate of consumption goods producers. */
#define DIVIDEND_RATE 0.4

/*brief deprication rate. */
#define DEPRECIATION_RATE 0.01

/*brief Discount rate*/
#define DISCOUNT_RATE 0.05

/*brief Strenght of adaption of the capital stock if firm is rationed on the labor market*/
#define TETA 0.0


/*brief Pricing rule: mark up on unit costs. */
#define MARK_UP 0.2

/*Strenght of the influence of the actual demand on the next production quantity: if LAMBDA = 0 then the planned production quantities of the last periods are recognized. If LAMBDA = 1 then the only the actual demand is recognized*/
#define LAMBDA 0.5

/*adaption of the wage offer: percent*/
#define wage_update 0.02

/*min number of vacancies to trigger vacancy counter*/
#define MIN_VACANCY 2

		
/*adaption of the reservation wage: prercent*/
#define wage_reservation_update 0.02

/*Cost of working in a different region: for example travelling costs*/
#define region_cost 0.2

/*calculatory cost of storing one unit over one period*/
#define INVENTORY_COSTS_PER_UNIT 2

/*percent of employees who are searching for a new job*/
#define ON_THE_JOB_SEARCH_RATE 10

/*INITIAL_CONSUMPTION_PROPENSITY times the mean income is the upper limit of the consumtion during the first five periods: smooth the consumption expenditures because of high dividend payments of the capital goods producer*/
#define INITIAL_CONSUMPTION_PROPENSITY  0.95

/*percent of savings which can by used for consumption*/
#define CONSUMPTION_PROPENSITY 0.95

/*Planning horizon of firms*/
#define FIRM_PLANNING_HORIZON 10

#define DEBT_ASSETS_RATIO_THRESHOLD 0.8

#define INTEREST_RATE 0.005

#define INV_INERTIA 3


#define ADAPTION_DELIVERY_VOLUME 0.05

#define PERIODS_TO_REPAY_LOANS 12

/*Probability for the delivery if the critical stock of one mall was zero for the last periods*/
#define DELIVERY_PROB_IF_CRITICAL_STOCK_0 25


#define INNOVATION_PROBABILITY 10  

#define PRODUCTIVITY_PROGRESS 0.05


int first_day_of_month();
int not_first_day_of_month();
int last_day_of_month();
int not_last_day_of_month();

void sort_vacancy_list(vacancy_array * vacancy_list);
void sort_job_offer_list(job_offer_array * job_offer_list);
int random_int(int min,int max);
void sort_job_application_list(job_application_array * job_application_list);
void sort_mall_sales_list(sales_statistics_array * sales_mall_list);

int credit_request_function(const void *x, const void *y);
int vacancy_list_rank_wage_offer_function(const void *x, const void *y);
int job_offer_list_rank_wage_offer_function(const void *x, const void *y);
int employee_list_rank_specific_skills_function(const void *x, const void *y);
int job_application_list_rank_general_skill_function(const void *x, const void *y);
int sales_statistics_list_rank_sales_function(const void *x, const void *y);
int random_int(int min,int max);
double max(double a, double b);
double min(double a, double b);
