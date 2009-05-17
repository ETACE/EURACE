#include "my_library_header.h"
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
/*
void  assetBeliefFormation(Belief *belief, Asset_array *assets,Random *rnd)
{ belief->expectedPriceReturns=gauss(rnd,0,sigma);
}
*/



double stockExpectedPriceReturns(Belief *belief)
{   
       return belief->expectedPriceReturns;
}

int forwardMonths( int currentDay, int forwardWindow)
{   
    int nrForwardMonths;
    nrForwardMonths=((currentDay+forwardWindow)/ DAYINMONTH)-(currentDay/DAYINMONTH);
    return nrForwardMonths;
}
    
double horizonRetainedEarnings(Belief *belief, int currentDay,int forwardWindow)
{
       int forwardmonths;
       double hRetainedEarnings;
       double earningExp;
       double earningPayoutExp;
       earningExp=belief->expectedEarning;
       earningPayoutExp=belief->expectedEarningPayout;
       forwardmonths=forwardMonths(currentDay,forwardWindow);
       hRetainedEarnings= forwardmonths*(earningExp-earningPayoutExp);  
       return hRetainedEarnings;
}

double futureFundamentalReturn(Belief *belief,Stock *stock,int currentDay,int forwardWindow, double equity)
{ double futureFundPrice;
  double fundamentalReturn;
  int hRetainedEarnings;
  hRetainedEarnings=horizonRetainedEarnings(belief,currentDay,forwardWindow);
  futureFundPrice = (equity+hRetainedEarnings)/(stock->nrOutStandingShares);
  fundamentalReturn = (futureFundPrice-lastPriceStock(stock))/lastPriceStock(stock);
  return fundamentalReturn;
       }

double randomReturn(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow)
{  double rndReturn;
   double volatility;
   double randn;
   volatility=volatilityStock(stock,backwardWindow);
   volatility=max(0.01,volatility);
   randn=gauss(0,1);
   rndReturn = sqrt(forwardWindow)*volatility*randn;//sqrt(forwardWindow)*volatility*randn;
 //rndReturn = volatility*randn;//sqrt(forwardWindow)*volatility*randn;
   return rndReturn;
}
void dividendYield(Belief *belief,Stock *stock,int currentDay, int forwardWindow,double dividendExp)
   {  int fwmonths;
      double divYield;
      fwmonths=forwardMonths(currentDay, forwardWindow);
      divYield=(fwmonths*(dividendExp))/lastPriceStock(stock);
      belief->expectedCashFlowYield=divYield;
   }


void firmBeliefFormation(Belief *belief,Stock *stock,int currentDay,int forwardWindow,double dividendExp,double earning,double earningPayout)
{
  belief->expectedEarning=earning;
  belief->expectedEarningPayout=earningPayout;
  dividendYield(belief,stock,currentDay, forwardWindow,dividendExp);
}

void  stockBeliefFormation(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,double equity,double lossaversion)
{ 
  double fundreturn;
  double rndreturn;
  double total_returns_avg;
  double price_returns_avg;
  double returns_avg;
  double value,factor;
 
  //dividendYield(belief,stock,currentDay, forwardWindow);
  rndreturn=randomReturn(belief, stock,forwardWindow,backwardWindow);
 
  fundreturn= futureFundamentalReturn(belief,stock,currentDay,forwardWindow, equity);

  returns_avg=expectedReturnStock(stock,backwardWindow);
  //printf(" return%f\n",returns_avg);
 
  value= randomWeight*rndreturn + fundamentalWeight*fundreturn + belief->expectedCashFlowYield; 
  factor=forwardWindow*chartistWeight;
  price_returns_avg=randomWeight*rndreturn+fundamentalWeight*fundreturn+chartistWeight*forwardWindow*returns_avg;
  total_returns_avg=value+factor*returns_avg;
 
  /*if(chartistWeight) { //printf("un chartista?");
                       binsnumber = min(bins,backwardWindow);
                      frequencyTotalReturns(stock,hist,backwardWindow-1,binsnumber,factor,value);
                     }
  else frequencyTotalReturns(stock,hist,1,1,0,value);*/
  if(chartistWeight) belief->utility= computeAssetUtilityFunction(stock, backwardWindow, factor,  value, lossaversion);
  else belief->utility= computeAssetUtilityFunction(stock, 1, factor,  value, lossaversion);
  belief->expectedPriceReturns=price_returns_avg;//gauss(rnd,0,0.1);//price_returns_avg;
//printf("expected price return%f\n",price_returns_avg);
  belief->expectedTotalReturns=total_returns_avg;
  belief->last_price=lastPriceStock(stock);
}
