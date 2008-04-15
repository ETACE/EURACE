#include "Belief.h"

Belief *newBelief()
{ 
  Belief *temp;
  temp=(Belief *)malloc(sizeof(Belief));
  initializeBelief(temp);
  return temp;
 
}

void initializeBelief(Belief *belief)
{
      belief->expectedPriceReturns=0.0;
      belief->expectedTotalReturns=0.0;
      belief->expectedCashFlowYield=0.0;
      //belief->volatility=0.0;
      //belief->forwardWindow=0;
      //belief->backwordWindow=0;
      //belief->binsNumber=0;
      //belief->randomReturnWeigth=0.0;
      //belief->fundametalReturnWeigth=0.0;
      //belief->chartistReturnWeigth=0.0;
      //belief->holdingPeriodToForwardW=0;
}

void  assetBeliefFormation(Belief *belief, CAsset *assets,Random *rnd)
{ belief->expectedPriceReturns=gauss(rnd,0,sigma);
}

void computeStockExpectedPriceReturns(Belief *belief, Asset *asset)
{
     
}

double stockExpectedPriceReturns(Belief *belief,Asset *anAsset)
{     double expectedPriceReturn;
      
       expectedPriceReturn=belief->expectedPriceReturns;
       return expectedPriceReturn;
}

int forwardMonths(Belief *belief, int currentDay, int forwardWindow, int dayInMonth)
{   
    int nrForwardMonths;
    nrForwardMonths=quo(currentDay+forwardWindow,dayInMonth)-quo(forwardWindow,dayInMonth);
    return nrForwardMonths;
}
    
double horizonRetainedEarnings(Belief *belief,Stock *stock, int currentDay,int forwardWindow)
{
       int forwardmonths;
       double hRetainedEarnings;
       forwardmonths=forwardMonths(belief,currentDay,forwardWindow);
       hRetainedEarnings= forwardMonths*(stock->earningsExp-stock->earningsPayoutExp);  
       return hRetainedEarnings;
}

double futureFundamentalReturn(Belief *belief,Stock *stock,int currentDay)
{ double futureFundPrice;
  double fundamentalReturn;
  hRetainedEarnings=horizonRetainedEarnings(belief,stock,currentDay);
  futureFundlPrice = (stock->equity+hRetainedEarnings)/stock->nrOutStandingShares;
  fundamentalReturn = (FutureFundamentalPrice-lastPriceStock(stock))/lastPriceStock(stock);
  return fundamentalReturn;
       }

double randomReturn(Belief *belief, Stock *stock,int forwardWindow, Random *rnd)
{  double rndReturn;
   double volatility;
   double randn;
   volatility=volatilityStock(stock,backwordWindow);
   randn=gauss(rnd,0,1);
   rndRetun = sqrt(forwardWindow)*volatility*randn;
   return rndReturn;
}
void  stockBeliefFormation(Belief *belief, Stock *stock,int backwardWindow,double randomWeigth,double  fundametalWeigth, double chartistWeigth, , int bins ,Random *rnd)
{ 
  double fundamentalReturn;
  double rndReturn;
  double total_return_avg;
  Histogram *hist;
  rnd=randomReturn(belief, Stock *stock,forwardWindow, rnd);
  fundamentalReturn=futureFundamentalReturn(belief,stock,currentDay);
  returns=expectedReturns(stock,backwordWindow);
  price_returns_avg = randomWeight*rndReturn + chartistWeights*returns + fundamentalWeigth*FundamentalReturn; 
  total_return_avg=price_returns+stock->dividend_yield;
  hist=frequencyReturns(stock,backwordWindow, bins);
  belief->hist=hist;
  //prendo una finestra computo i ritorni da fare...
}