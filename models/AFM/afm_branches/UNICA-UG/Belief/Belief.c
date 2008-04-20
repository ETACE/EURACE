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
      belief->volatility=0.0;
      //belief->forwardWindow=0;
      //belief->backwardWindow=0;
      //belief->binsNumber=0;
      //belief->randomReturnWeight=0.0;
      //belief->fundametalReturnWeight=0.0;
      //belief->chartistReturnWeight=0.0;
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

int forwardMonths(Belief *belief, int currentDay, int forwardWindow)
{   
    int nrForwardMonths;
    nrForwardMonths=quo(currentDay+forwardWindow, DAYINMONTH)-quo(forwardWindow, DAYINMONTH);
    return nrForwardMonths;
}
    
double horizonRetainedEarnings(Belief *belief,Stock *stock, int currentDay,int forwardWindow)
{
       int forwardmonths;
       double hRetainedEarnings;
       forwardmonths=forwardMonths(belief,currentDay,forwardWindow);
       hRetainedEarnings= forwardmonths*(stock->earningExp-stock->earningPayoutExp);  
       return hRetainedEarnings;
}

double futureFundamentalReturn(Belief *belief,Stock *stock,int currentDay,int forwardWindow)
{ double futureFundPrice;
  double fundamentalReturn;
  int hRetainedEarnings;
  hRetainedEarnings=horizonRetainedEarnings(belief,stock,currentDay,forwardWindow);
  futureFundPrice = (stock->equity+hRetainedEarnings)/stock->nrOutStandingShares;
  fundamentalReturn = (futureFundPrice-lastPriceStock(stock))/lastPriceStock(stock);
  return fundamentalReturn;
       }

double randomReturn(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow, Random *rnd)
{  double rndReturn;
   double volatility;
   double randn;
   volatility=volatilityStock(stock,backwardWindow);
   randn=gauss(rnd,0,1);
   rndReturn = sqrt(forwardWindow)*volatility*randn;
   return rndReturn;
}
void  stockBeliefFormation(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay, Random *rnd)
{ 
  double fundreturn;
  double rndreturn;
  double total_returns_avg;
  double price_returns_avg;
  double expreturn;
  int binsnumber;
  Histogram *hist;
   hist=&(belief->hist);
  rndreturn=randomReturn(belief, stock,forwardWindow,backwardWindow, rnd);
  fundreturn=futureFundamentalReturn(belief,stock,currentDay,forwardWindow);
  expreturn=expectedReturnStock(stock,backwardWindow);
  price_returns_avg = randomWeight*rndreturn + chartistWeight*expreturn + fundamentalWeight*fundreturn; 
  total_returns_avg=price_returns_avg+stock->dividend_yield;
  binsnumber = min(bins,backwardWindow);
  frequencyReturns(stock,hist,backwardWindow,binsnumber);

  //prendo una finestra computo i ritorni da fare...
}