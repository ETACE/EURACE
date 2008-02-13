#include "Belief.h"

Belief *newBelief()
{ Belief *temp;
  temp=(Belief *)malloc(sizeof(Belief));
   initializeBelief(temp);
  return temp;
 
}

void initializeBelief(Belief *belief)
{
                      belief->assetsExpectedPriceReturns=0.0;
       belief->assetsExpectedTotalReturns=0.0;
      belief->assetsExpectedCashFlowYield=0.0;
      belief->volatility=0.0;
      belief->forwardWindow=0;
      belief->backwordWindow=0;
      belief->binsNumber=0;
       belief->randomReturnWeigth=0.0;
       belief->fundametalReturnWeigth=0.0;
       belief->chartistReturnWeigth=0.0;
      belief->holdingPeriodToForwardW=0;
}

void  assetBeliefFormation(Belief *belief, CAsset *assets,Random *rnd)
{ belief->assetsExpectedPriceReturns=gauss(rnd,0,sigma);
}

void computeStockExpectedPriceReturns(Belief *belief, Asset *asset)
{
     
}

double stockExpectedPriceReturns(Belief *belief,Asset *anAsset)
{     double expectedPriceReturn;
      
       expectedPriceReturn=belief->assetsExpectedPriceReturns;
       return expectedPriceReturn;
}
