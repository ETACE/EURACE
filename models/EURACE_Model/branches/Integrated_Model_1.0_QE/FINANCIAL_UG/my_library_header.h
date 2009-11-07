#ifndef MYLIB
#define MYLIB
#define max(A,B) ( (A) > (B) ? (A):(B))
#define min(A,B) ( (A) < (B) ? (A):(B))
#define CURRENTDAY iteration_loop
#define MAXPRICES 100
#define MAXRETURNS MAXPRICES
//move constants to model.xml environment
#define NRDAYSINYEAR  (DAYS_IN_MONTH*12)

#include "../header.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
/***************Random*****************/




//initialie: Set a reasonable Park-Miller starting seed     
void initializeRandom();


//accessing at the structure 
double getSeed();



void setSeed( double seed);
 

// Eurace

double nextBetween( double min , double max);

//private methods
/*This method generates Random1 instances of Integer in the interval 0 to 16r7FFFFFFF. This 
	method does NOT update the seed; repeated sends answer the same value. The algorithm is 
	described in detail in 'Random1 Number Generators: Good Ones Are Hard to Find' by Stephen K. 
	Park and Keith W. Miller (Comm. Asso. Comp. Mach., 31(10):1192--1201, 1988).
*/
double nextValue();

//computation
//probArray holds a set of probabilities that a different event happens. The sum of probArray values 
//must be 1. Return the index in probArray of the event actually happening
int eventFrom(double probArray[] );



//Returns a random number with Gaussian distribution having average avg and s.d. std
double gauss(double avg ,double std );

//Answer a normally distributed random number with zero mean and standard deviation 1.0.
double gaussian();
double fast_gauss();

//Returns a random number with Lognormal distribution having average avg and s.d. std
double logNormal( double  avg ,double std) ;

//This method generates random instances of Float in the interval 0 to 1
double next();

//	Restituisce un numero casuale intero tra 1 e max
int nextMax(int max);

//Return the number of events, distributed according to a Poisson distribution with given lambda
int poissonNr( double lambda );



//Answer -1 with probability p1, 1 with probability p2 - p1, zero elsewhere. Assumes that p1, p2 << 
int prob1prob2(double p1,double p2);

	
//Answer true with probability p.
int prob(double p);

/******************Order *************/
 
Order * newOrder();

void setOrder(Order *anOrder, double price, int quantity,int assetId, int issuer);

int getOrderQuantity(Order *anOrder);

void copyOrder(Order *dest ,Order *orig);

void swapOrder(Order *dest ,Order *orig);

int compareOrder(Order *a, Order *b);

int isEqualOrder(Order *a, Order *b);

int isBuyOrder(Order *anOrder);

int isSellOrder(Order *anOrder);


int isNullOrder(Order *anOrder);

void setAsNullOrder(Order *anOrder);
void setAsSellOrder(Order *anOrder);
void freeOrder(Order *ord);
int isGreaterOrder(Order *a, Order *b);
int isLessOrder(Order *a, Order *b);


/********* Order array*************/
double_array *newCDouble(int size);       





double firstCDouble(double_array *coll );

int sizeCDouble(double_array *coll );

double lastCDouble(double_array *coll );


int isEmptyCDouble(double_array *coll );

int isFullCDouble(double_array *coll );


double lessthan(double_array *coll);


double elementAtCDouble(double_array *coll ,int index);
double mean(double_array *aFixedC);

double variance(double_array *aFixedC);

void divide(double_array *coll, double denominator);
// add an Double with decreasing or increasing relation respectively rel='<' or rel='>'

void addIncSortDouble(double_array *coll,double value);
void addIncSetSortDouble(double_array *coll,double value);
void qSort_double_array(double_array *v,int first, int last);


Order_array *newCOrder(int size);       





Order *firstCOrder(Order_array *coll );

int sizeCOrder(Order_array *coll );

Order *lastCOrder(Order_array *coll );


int isEmptyCOrder(Order_array *coll );

int isFullCOrder(Order_array *coll );



Order *removeWithId(Order_array *coll, int assetId);

int findCOrder(Order_array *coll,int assetId);

Order *elementAtCOrder(Order_array *coll ,int index);
 void addOrder(Order_array *coll, Order *anOrder);
void addCOrder(Order_array *coll ,Order *elem);

double minPriceOrder(Order_array *aFixedC);

void qSortCOrder(Order_array *v, int first, int last);
void qSortCOrderDec(Order_array *v, int first, int last);
void randomize(Order_array *v, int first, int last);
double maxPriceOrder(Order_array *aFixedC);

/********Asset******************/

Asset *newAsset();
int assetId(Asset *anAsset);
void  freeAsset(Asset *anAsset);
void setAsset(Asset *anAsset, int issuer, double price, int quantity);
void setPrice(Asset *anAsset,double price);
void addPrice(Asset *anAsset, double price);
void addVolume(Asset *anAsset, double volume);

double lastPrice(Asset *anAsset);

/***********Asset Array**********/

Asset_array *newCAsset(int size);       


void emptyCAsset(Asset_array *coll );

Asset *firstCAsset(Asset_array *coll );

int sizeCAsset(Asset_array *coll );

Asset *lastCAsset(Asset_array *coll );
int isPresentCAsset(Asset_array *coll, int index);

int isEmptyCAsset(Asset_array *coll );

int isFullCAsset(Asset_array *coll );

void growCAsset(Asset_array *aFixed);




Asset *elementAtCAsset(Asset_array *coll ,int index);

void init_Assetsowned(Asset_array *assets);
Asset_array *newAssetsTotal(int quantity);
int findCAsset(Asset_array *coll,int assetId);

/***********Portfolio********/

void initializePortfolio(double *payment_account, Asset_array *assets);
double *expectedPortfolio(double *payment_account, Belief *belief);
void executeOrder(double *payment_account,Order *anOrder,Asset_array *assets,Order_array *pending);
double wealth(double payment_account, Asset_array *assetsowned);
int totalassets(Asset_array *assetsowned);


/************Double***********/


int equals( double a1,double a2);

double quo(double c,double b);

double * newDouble(double value);

void copyDouble(double *dest ,double *orig);

void swapDouble(double *dest ,double *orig);

int compareDouble(double a, double b);

int isEqualDouble(double a ,double b);

double forceTologInterval(double rec,double value, double aNumber );

/************Double array ***********/
double_array *newCDouble(int size);       





double firstCDouble(double_array *coll );

int sizeCDouble(double_array *coll );

double lastCDouble(double_array *coll );


int isEmptyCDouble(double_array *coll );

int isFullCDouble(double_array *coll );


double lessthan(double_array *coll);


double elementAtCDouble(double_array *coll ,int index);
double mean(double_array *aFixedC);

double variance(double_array *aFixedC);

void divide(double_array *coll, double denominator);
// add an Double with decreasing or increasing relation respectively rel='<' or rel='>'

void addIncSortDouble(double_array *coll,double value);
void addIncSetSortDouble(double_array *coll,double value);

/**********Clearing Mechanism*********/

double formedPrice(ClearingMechanism *clearm);
void setClearingMechanism(ClearingMechanism *clearm, double lastprice);
void addBuyOrder(ClearingMechanism *aClearing , Order *anOrder);

void addSellOrder(ClearingMechanism *aClearing,Order *anOrder);
Order_array *buyOrders(ClearingMechanism *clear);

Order_array *sellOrders(ClearingMechanism *clear);

void sortOrders(ClearingMechanism *clear);
int aggregateDemand(ClearingMechanism *aClearing,double aPriceValue ,int *i, int start_value);

int aggregateSupply(ClearingMechanism *aClearing,double aPriceValue ,int *i, int start_value);



 double newPrice(ClearingMechanism *aClearing);                 
void ordersMacthing(Order_array *coll, double price,int type);

void rationing(Order_array *coll,int quantity );
void removeZeroOrders(Order_array *coll);
  
	  
void runClearing(ClearingMechanism *aClearing);
   
void emptyClearing(ClearingMechanism *aClearing);


/***********Stock **************/


void addPriceStock(Stock *aStock, double price);

int issuerStock(Stock *aStock);


double lastPriceStock(Stock *aStock);
double expectedReturnStock(Stock *aStock,int backwardWindow);
double  backreturnsAt(Stock *stock,int ind);
double volatilityStock(Stock *aStock,int backwardWindow);
void totalReturnsStock(Stock *stock, double *vect, int backwardWindow,double factor, double value);
void priceReturnsStock(Stock *stock, double *vect, int backwardWindow);
void historicalReturnsStock(Stock *stock, double *vect, int backwardWindow,double forwardWindow);
//void frequencyTotalReturns(Stock *stock,Histogram *hist, int backwardWindow, int bins,double factor,double value);
double computeStockUtilityFunction(Stock *stock,int backwardWindow, double factor, double value, double lossAversion, double *rndvect,double randomWeight);

/********Belief*******************/



/*it compute the price return of the stocks as a weighted sum of different components*/
void computeStockExpectedPriceReturns(Belief *belief, Asset *asset);

double expectedPriceReturns(Belief *belief);
/*restituisce un istogramma delle frequenze dei expectedTotalReturn degli asset);*/



void firmBeliefFormation(Belief *belief,Stock *stock,int currentDay,int forwardWindow,double dividendExp,double earning,double earningPayout);
void computeStockExpectedPriceReturns(Belief *belief, Asset *asset);

double expectedPriceReturns(Belief *belief);

int forwardMonths( int currentDay, int forwardWindow);
    
double horizonRetainedEarnings(Belief *belief, int currentDay,int forwardWindow);


double futureFundamentalReturn(Belief *belief,Stock *stock,int currentDay,int forwardWindow, double equity);

double randomReturnStock(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow,double *rndvect);

double randomReturnBond(Bond *bond,int backwardWindow,int forwardWindow,double *rndvect);

void  stockBeliefFormation(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,double equity,double lossaversion);


void dividendYield(Belief *belief,Stock *stock,int currentDay, int forwardWindow,double dividendExp);
void  bondBeliefFormation(Belief *belief, Bond *bond,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,int holdingPeriodToForwardW, double lossaversion);
/****************Household*************/
int sendOrders();
void computeUtilities(Belief_array *beliefs, double_array *assetweigths);
void assetUtilitiesToWeights(double_array *assetWeigths,double_array *assetUtilities,double bankrate);
        
int distribuite(double cash, double totalwealth);


/* it compute a limitOrder on an Asset  anAsset contained into its Portfolio , */
void computeLimitOrder( Asset *anAsset, double weight, double resource,Belief *belief, Order *ord);

void generatePendingOrders(Asset_array *assetsowned,Order_array *pending, Belief_array *beliefs,double *payment_account);
//void assetBeliefFormation(Belief_array *beliefs);
int stock_beliefs_formation();
int bond_beliefs_formation();
int totalassetsowned();

/******************Clearing House***********/
void receiveOrderOnAsset(ClearingMechanism *mechanism, Asset *anAsset);


void computeAssetPrice(ClearingMechanism *mechanism, Asset *anAsset);

void sendOrderStatus(ClearingMechanism *clearm);
void ClearingHouse_receive_info_stock(Asset_array *assets);

void ClearingHouse_receive_info_bond(Asset_array *assets);

/******************Firm*******************/
void CGP_income_statement_computing(double earnings, double earnings_payout, double *earnings_exp,double *earnings_payout_exp);


/****************Bond*******************/
void initializeBond(Bond *aBond,int id, int nr_outstanding,double face_value, double nominal_yield);
double  backreturns_bond(Bond *bond,int ind);
 
double lastPriceBond(Bond *aBond);

double expectedReturnBond(Bond *bond,int backwardWindow);

  void addPriceBond(Bond *bond, double price);

     
double volatilityBond(Bond *bond,int backwardWindow);

void totalReturnsBond(Bond *bond, double *vect, int backwardWindow,double factor, double value);
 
void priceReturnsBond(Bond *bond, double *vect, int backwardWindow);
 



void historicalReturnsBond(Bond *bond, double *vect, int backwardWindow,double forwardWindow);


int  coupons_payment_days(Bond *bond,int currentDay,int holding_period);


double computeBondUtilityFunction(Bond *bond, double *rnd_returns, int backwardWindow, double factor_chartist, double factor_random, double value, double lossaversion, double randomWeight);
#endif
