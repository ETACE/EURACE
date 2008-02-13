/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */
#ifndef HEAD_INCL
#define HEAD_INCL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include  "Random.h"
#include "Household.h"



/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def e START_ORDER_MESSAGE_LOOP
 * \brief Start of loop to process order messages. */
#define START_ORDER_MESSAGE_LOOP  order_message = get_first_order_message(); while(order_message) {
/** \def FINISH_ORDER_MESSAGE_LOOP
 * \brief Finish of loop to process order messages. */
#define FINISH_ORDER_MESSAGE_LOOP order_message = get_next_order_message(order_message); }
/** \def e START_ORDERSTATUS_MESSAGE_LOOP
 * \brief Start of loop to process orderStatus messages. */
#define START_ORDERSTATUS_MESSAGE_LOOP  orderStatus_message = get_first_orderStatus_message(); while(orderStatus_message) {
/** \def FINISH_ORDERSTATUS_MESSAGE_LOOP
 * \brief Finish of loop to process orderStatus messages. */
#define FINISH_ORDERSTATUS_MESSAGE_LOOP orderStatus_message = get_next_orderStatus_message(orderStatus_message); }
/** \def e START_ASSET_MESSAGE_LOOP
 * \brief Start of loop to process asset messages. */
#define START_ASSET_MESSAGE_LOOP  asset_message = get_first_asset_message(); while(asset_message) {
/** \def FINISH_ASSET_MESSAGE_LOOP
 * \brief Finish of loop to process asset messages. */
#define FINISH_ASSET_MESSAGE_LOOP asset_message = get_next_asset_message(asset_message); }
/** \def e START_INFOASSET_MESSAGE_LOOP
 * \brief Start of loop to process infoAsset messages. */
#define START_INFOASSET_MESSAGE_LOOP  infoAsset_message = get_first_infoAsset_message(); while(infoAsset_message) {
/** \def FINISH_INFOASSET_MESSAGE_LOOP
 * \brief Finish of loop to process infoAsset messages. */
#define FINISH_INFOASSET_MESSAGE_LOOP infoAsset_message = get_next_infoAsset_message(infoAsset_message); }

/** \struct Portfolio
 * \brief ADT  portfolio .
 *
 * ADT  portfolio .
 */
#ifndef Portfolio_dty
#define Portfolio_dty
typedef struct Portfolio Portfolio;
/** \var typedef Portfolio_array Portfolio_array
 * \brief Typedef for Portfolio_array struct.
 */

struct Portfolio
{
	double bankAccount;
};

/** \struct Portfolio_array
 * \brief Dynamic array to hold Portfolios
 */
#endif
#ifndef CPortfolio_dty
#define CPortfolio_dty
struct Portfolio_array
{
	int size;
	int total_size;
	
	struct Portfolio ** array;
};
/** \var typedef Portfolio Portfolio
 * \brief Typedef for Portfolio struct.
 */

typedef struct Portfolio_array Portfolio_array;
#endif
/** \struct Asset
 * \brief ADT Asset .
 *
 * ADT Asset .
 */
#ifndef Asset_dty
#define Asset_dty
typedef struct Asset Asset;
/** \var typedef Asset_array Asset_array
 * \brief Typedef for Asset_array struct.
 */

struct Asset
{
	int issuer;
	int quantity;
	double lastPrice;
};

/** \struct Asset_array
 * \brief Dynamic array to hold Assets
 */
#endif
#ifndef CAsset_dty
#define CAsset_dty
struct Asset_array
{
	int size;
	int total_size;
	
	struct Asset ** array;
};
/** \var typedef Asset Asset
 * \brief Typedef for Asset struct.
 */

typedef struct Asset_array Asset_array;
#endif
/** \struct Belief
 * \brief ADT Belief .
 *
 * ADT Belief .
 */
#ifndef Belief_dty
#define Belief_dty
typedef struct Belief Belief;
/** \var typedef Belief_array Belief_array
 * \brief Typedef for Belief_array struct.
 */

struct Belief
{
	double assetsExpectedPriceReturns;
	double assetsExpectedTotalReturns;
	double assetsExpectedCashFlowYield;
	double volatility;
	int forwardWindow;
	int backwordWindow;
	int binsNumber;
	double randomReturnWeigth;
	double fundametalReturnWeigth;
	double chartistReturnWeigth;
	int holdingPeriodToForwardW;
};

/** \struct Belief_array
 * \brief Dynamic array to hold Beliefs
 */
#endif
#ifndef CBelief_dty
#define CBelief_dty
struct Belief_array
{
	int size;
	int total_size;
	
	struct Belief ** array;
};
/** \var typedef Belief Belief
 * \brief Typedef for Belief struct.
 */

typedef struct Belief_array Belief_array;
#endif
/** \struct Order
 * \brief ADT order .
 *
 * ADT order .
 */
#ifndef Order_dty
#define Order_dty
typedef struct Order Order;
/** \var typedef Order_array Order_array
 * \brief Typedef for Order_array struct.
 */

struct Order
{
	int issuer;
	int quantity;
	double price;
	int assetId;
};

/** \struct Order_array
 * \brief Dynamic array to hold Orders
 */
#endif
#ifndef COrder_dty
#define COrder_dty
struct Order_array
{
	int size;
	int total_size;
	
	struct Order ** array;
};
/** \var typedef Order Order
 * \brief Typedef for Order struct.
 */

typedef struct Order_array Order_array;
#endif
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


/** \struct xmachine_memory_Eurostat
 * \brief Holds memory of xmachine Eurostat.
 */
struct xmachine_memory_Eurostat
{
	Asset_array * assets;	/**< X-machine memory variable assets of type Asset_array. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_Household
 * \brief Holds memory of xmachine Household.
 */
struct xmachine_memory_Household
{
	int id;	/**< X-machine memory variable id of type int. */
	double wealth;	/**< X-machine memory variable wealth of type double. */
	Belief * belief;	/**< X-machine memory variable belief of type Belief. */
	Portfolio * portfolio;	/**< X-machine memory variable portfolio of type Portfolio. */
	Order_array * pendingOrders;	/**< X-machine memory variable pendingOrders of type Order_array. */
	Asset_array * assetsowned;	/**< X-machine memory variable assetsowned of type Asset_array. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine_memory_ClearingHouse
 * \brief Holds memory of xmachine ClearingHouse.
 */
struct xmachine_memory_ClearingHouse
{
	int id;	/**< X-machine memory variable id of type int. */
	Asset_array * assets;	/**< X-machine memory variable assets of type Asset_array. */
	double posx;	/**< X-machine memory variable posx of type double. */
	double posy;	/**< X-machine memory variable posy of type double. */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Eurostat * xmachine_Eurostat;	/**< Pointer to X-machine memory of type Eurostat.  */
	struct xmachine_memory_Household * xmachine_Household;	/**< Pointer to X-machine memory of type Household.  */
	struct xmachine_memory_ClearingHouse * xmachine_ClearingHouse;	/**< Pointer to X-machine memory of type ClearingHouse.  */
	
	struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \struct xmachine_message_order
 * \brief Holds message of type order_message.
 */
struct xmachine_message_order
{
	int issuer;	/**< Message memory variable issuer of type int. */
	int assetId;	/**< Message memory variable assetId of type int. */
	double limitPrice;	/**< Message memory variable limitPrice of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_order * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_orderStatus
 * \brief Holds message of type orderStatus_message.
 */
struct xmachine_message_orderStatus
{
	int issuer;	/**< Message memory variable issuer of type int. */
	int assetId;	/**< Message memory variable assetId of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_orderStatus * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_asset
 * \brief Holds message of type asset_message.
 */
struct xmachine_message_asset
{
	int issuer;	/**< Message memory variable issuer of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_asset * next;	/**< Pointer to next message in the list. */
};


/** \struct xmachine_message_infoAsset
 * \brief Holds message of type infoAsset_message.
 */
struct xmachine_message_infoAsset
{
	int issuer;	/**< Message memory variable issuer of type int. */
	double price;	/**< Message memory variable price of type double. */
	int quantity;	/**< Message memory variable quantity of type int. */
	double range;	/**< Message memory variable range of type double. */
	double x;	/**< Message memory variable x of type double. */
	double y;	/**< Message memory variable y of type double. */
	double z;	/**< Message memory variable z of type double. */
	
	struct xmachine_message_infoAsset * next;	/**< Pointer to next message in the list. */
};


/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Eurostat xmachine_memory_Eurostat
 * \brief Typedef for xmachine_memory_Eurostat struct.
 */
typedef struct xmachine_memory_Eurostat xmachine_memory_Eurostat;
/** \var typedef xmachine_memory_Household xmachine_memory_Household
 * \brief Typedef for xmachine_memory_Household struct.
 */
typedef struct xmachine_memory_Household xmachine_memory_Household;
/** \var typedef xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse
 * \brief Typedef for xmachine_memory_ClearingHouse struct.
 */
typedef struct xmachine_memory_ClearingHouse xmachine_memory_ClearingHouse;
/** \typedef xmachine_message_order xmachine_message_order
 * \brief Typedef for xmachine_message_order struct.
 */
typedef struct xmachine_message_order xmachine_message_order;

/** \typedef xmachine_message_orderStatus xmachine_message_orderStatus
 * \brief Typedef for xmachine_message_orderStatus struct.
 */
typedef struct xmachine_message_orderStatus xmachine_message_orderStatus;

/** \typedef xmachine_message_asset xmachine_message_asset
 * \brief Typedef for xmachine_message_asset struct.
 */
typedef struct xmachine_message_asset xmachine_message_asset;

/** \typedef xmachine_message_infoAsset xmachine_message_infoAsset
 * \brief Typedef for xmachine_message_infoAsset struct.
 */
typedef struct xmachine_message_infoAsset xmachine_message_infoAsset;


int sendAssetInformationEURO(void);
int receiveAssetInformationEURO(void);
int selectStrategy(void);
int updateTrader(void);
int receiveAssetInformationHouse(void);
int receiveAssetInformation(void);
int receiveOrdersAndRun(void);
int sendAssetInformation(void);

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
	struct xmachine_message_order * order_messages;	/**< Pointer to order message list. */
	struct xmachine_message_orderStatus * orderStatus_messages;	/**< Pointer to orderStatus message list. */
	struct xmachine_message_asset * asset_messages;	/**< Pointer to asset message list. */
	struct xmachine_message_infoAsset * infoAsset_messages;	/**< Pointer to infoAsset message list. */
	
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

/** \var xmachine_message_order * temp_order_message
* \brief Pointer to xmachine_message_order to initialise linked list. */
xmachine_message_order * temp_order_message;
/** \var xmachine_message_orderStatus * temp_orderStatus_message
* \brief Pointer to xmachine_message_orderStatus to initialise linked list. */
xmachine_message_orderStatus * temp_orderStatus_message;
/** \var xmachine_message_asset * temp_asset_message
* \brief Pointer to xmachine_message_asset to initialise linked list. */
xmachine_message_asset * temp_asset_message;
/** \var xmachine_message_infoAsset * temp_infoAsset_message
* \brief Pointer to xmachine_message_infoAsset to initialise linked list. */
xmachine_message_infoAsset * temp_infoAsset_message;
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

/** \var xmachine_message_order ** p_order_message
* \brief Pointer to first pointer of order message list */
xmachine_message_order ** p_order_message;
/** \var xmachine_message_orderStatus ** p_orderStatus_message
* \brief Pointer to first pointer of orderStatus message list */
xmachine_message_orderStatus ** p_orderStatus_message;
/** \var xmachine_message_asset ** p_asset_message
* \brief Pointer to first pointer of asset message list */
xmachine_message_asset ** p_asset_message;
/** \var xmachine_message_infoAsset ** p_infoAsset_message
* \brief Pointer to first pointer of infoAsset message list */
xmachine_message_infoAsset ** p_infoAsset_message;

/** \var xmachine_message_order * order_message
* \brief Pointer to message struct for looping through order message list */
xmachine_message_order * order_message;
/** \var xmachine_message_orderStatus * orderStatus_message
* \brief Pointer to message struct for looping through orderStatus message list */
xmachine_message_orderStatus * orderStatus_message;
/** \var xmachine_message_asset * asset_message
* \brief Pointer to message struct for looping through asset message list */
xmachine_message_asset * asset_message;
/** \var xmachine_message_infoAsset * infoAsset_message
* \brief Pointer to message struct for looping through infoAsset message list */
xmachine_message_infoAsset * infoAsset_message;
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

Portfolio_array * init_Portfolio_array();
void reset_Portfolio_array(Portfolio_array * array);
void free_Portfolio_array(Portfolio_array * array);
void add_Portfolio(Portfolio_array * array, double bankAccount);
void remove_Portfolio(Portfolio_array * array, int index);

Asset_array * init_Asset_array();
void reset_Asset_array(Asset_array * array);
void free_Asset_array(Asset_array * array);
void add_Asset(Asset_array * array, int issuer, int quantity, double lastPrice);
void remove_Asset(Asset_array * array, int index);

Belief_array * init_Belief_array();
void reset_Belief_array(Belief_array * array);
void free_Belief_array(Belief_array * array);
void add_Belief(Belief_array * array, double assetsExpectedPriceReturns, double assetsExpectedTotalReturns, double assetsExpectedCashFlowYield, double volatility, int forwardWindow, int backwordWindow, int binsNumber, double randomReturnWeigth, double fundametalReturnWeigth, double chartistReturnWeigth, int holdingPeriodToForwardW);
void remove_Belief(Belief_array * array, int index);

Order_array * init_Order_array();
void reset_Order_array(Order_array * array);
void free_Order_array(Order_array * array);
void add_Order(Order_array * array, int issuer, int quantity, double price, int assetId);
void remove_Order(Order_array * array, int index);


int_array * init_int_array(void);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void sort_int_array(int_array * array);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
float_array * init_float_array(void);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void sort_float_array(float_array * array);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
double_array * init_double_array(void);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void sort_double_array(double_array * array);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
char_array * init_char_array(void);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
/* xml.c */
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag);
void saveiterationdata_binary(int iteration_number);
void saveiterationdata(int iteration_number);

void add_Eurostat_agent(Asset_array * assets, double posx, double posy);
void add_Household_agent(int id, double wealth, Belief * belief, Portfolio * portfolio, Order_array * pendingOrders, Asset_array * assetsowned, double posx, double posy);
void add_ClearingHouse_agent(int id, Asset_array * assets, double posx, double posy);

void add_order_message(int issuer, int assetId, double limitPrice, int quantity, double range, double x, double y, double z);
xmachine_message_order * add_order_message_internal(void);
xmachine_message_order * get_first_order_message(void);
xmachine_message_order * get_next_order_message(xmachine_message_order * current);
void freeordermessages(void);
void add_orderStatus_message(int issuer, int assetId, double price, int quantity, double range, double x, double y, double z);
xmachine_message_orderStatus * add_orderStatus_message_internal(void);
xmachine_message_orderStatus * get_first_orderStatus_message(void);
xmachine_message_orderStatus * get_next_orderStatus_message(xmachine_message_orderStatus * current);
void freeorderStatusmessages(void);
void add_asset_message(int issuer, double price, int quantity, double range, double x, double y, double z);
xmachine_message_asset * add_asset_message_internal(void);
xmachine_message_asset * get_first_asset_message(void);
xmachine_message_asset * get_next_asset_message(xmachine_message_asset * current);
void freeassetmessages(void);
void add_infoAsset_message(int issuer, double price, int quantity, double range, double x, double y, double z);
xmachine_message_infoAsset * add_infoAsset_message_internal(void);
xmachine_message_infoAsset * get_first_infoAsset_message(void);
xmachine_message_infoAsset * get_next_infoAsset_message(xmachine_message_infoAsset * current);
void freeinfoAssetmessages(void);

Asset_array * get_assets(void);
void set_posx(double posx);
double get_posx(void);
void set_posy(double posy);
double get_posy(void);
void set_id(int id);
int get_id(void);
void set_wealth(double wealth);
double get_wealth(void);
Belief * get_belief(void);
Portfolio * get_portfolio(void);
Order_array * get_pendingOrders(void);
Asset_array * get_assetsowned(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6]);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions);

/* messageboard.c */
xmachine_message_order * get_next_message_order_in_range(xmachine_message_order * current);
xmachine_message_orderStatus * get_next_message_orderStatus_in_range(xmachine_message_orderStatus * current);
xmachine_message_asset * get_next_message_asset_in_range(xmachine_message_asset * current);
xmachine_message_infoAsset * get_next_message_infoAsset_in_range(xmachine_message_infoAsset * current);

/* memory.c */
xmachine * add_xmachine(void);
Random *rnd;
#endif
