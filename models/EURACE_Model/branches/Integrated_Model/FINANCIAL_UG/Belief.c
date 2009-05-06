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



double expectedPriceReturns(Belief *belief)
{   
       return belief->expectedPriceReturns;
}

int forwardMonths( int currentDay, int forwardWindow)
{   
    int nrForwardMonths;
    nrForwardMonths=((currentDay+forwardWindow)/ DAYS_IN_MONTH)-(currentDay/DAYS_IN_MONTH);
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
 // printf(" return%f\n",futureFundPrice);
  fundamentalReturn = (futureFundPrice-lastPriceStock(stock))/lastPriceStock(stock);
  return fundamentalReturn;
       }

double randomReturn(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow)
{  double rndReturn;
   double volatility;
   double randn;
   volatility=volatilityStock(stock,backwardWindow);
   volatility=max(0.1,volatility);
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
  double value,factor,dividend_yield_annualized;
 
  //dividendYield(belief,stock,currentDay, forwardWindow);
  rndreturn=randomReturn(belief, stock,forwardWindow,backwardWindow);
 
  fundreturn= futureFundamentalReturn(belief,stock,currentDay,forwardWindow, equity);

  returns_avg=expectedReturnStock(stock,backwardWindow);
  //printf(" return%f\n",returns_avg);
 
  value= randomWeight*rndreturn + fundamentalWeight*fundreturn + belief->expectedCashFlowYield; 
  factor=forwardWindow*chartistWeight;
 price_returns_avg=(randomWeight*rndreturn+fundamentalWeight*fundreturn+chartistWeight*forwardWindow*returns_avg)*(NRDAYSINYEAR/forwardWindow);
  //price_returns_avg=(randomWeight*rndreturn+fundamentalWeight*fundreturn+chartistWeight*forwardWindow*returns_avg)/forwardWindow;

  dividend_yield_annualized=belief->expectedCashFlowYield*(NRDAYSINYEAR/forwardWindow);
  total_returns_avg=price_returns_avg+ dividend_yield_annualized;
 

  belief->utility= computeStockUtilityFunction(stock, backwardWindow, factor,  value, lossaversion);
  belief->expectedPriceReturns=price_returns_avg;//gauss(rnd,0,0.1);//price_returns_avg;
//printf("expected price return%f\n",price_returns_avg);
  belief->expectedTotalReturns=total_returns_avg;
  belief->last_price=lastPriceStock(stock);
}


void  bondBeliefFormation(Belief *belief, Bond *bond,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,int holdingPeriodToForwardW, double lossaversion)
{ int holding_period;
  int nrCoupons;
  int bins_number;
  double coupon;
  double coupon_stream,last_market_price;
  double fundamental_return_weight_bond;
  double random_return_weight_bond;
  double chartist_return_weight_bond;
  double fundamentalReturn,aux;
  double factor,value,coupon_yield,coupon_yield_annualized,volatility,returns_avg,randomReturn;


  holding_period=holdingPeriodToForwardW*forwardWindow;
  nrCoupons=coupons_payment_days(bond,currentDay,holding_period);
  //printf("numero di coupon%d\n",nrCoupons);
  last_market_price=lastPriceBond(bond);

if (nrCoupons>0)
    {
    coupon = ((bond->nominal_yield*bond->face_value)*COUPONPERIODICITYNRMONTHS)/12;
    coupon_stream = nrCoupons*coupon;
    coupon_yield = coupon_stream/last_market_price;
    }
else coupon_yield = 0;

// Fundamental Return
aux=bond->maturity_day-currentDay;
fundamentalReturn=min(holding_period,aux)/aux;
fundamentalReturn=fundamentalReturn*(bond->face_value-last_market_price)/last_market_price;
//yearly fundamental return


fundamental_return_weight_bond = max(FUNDAMENTAL_RETURN_WEIGHT_MIN,fundamentalWeight);
if (fundamental_return_weight_bond==1)
    {
    random_return_weight_bond = 0;
    chartist_return_weight_bond = 0;
    }
else
    {

    random_return_weight_bond = (randomWeight/(randomWeight+chartistWeight))*(1-fundamental_return_weight_bond);
    chartist_return_weight_bond = (chartistWeight/(randomWeight+chartistWeight))*(1-fundamental_return_weight_bond);
    }

if (holding_period>=aux)
    {value=fundamentalReturn; 
     factor=0;
    }//priceReturns=fundamentalReturn;
else
    // Random Return
   {
     volatility=volatilityBond(bond,backwardWindow);
     volatility=max(0.1,volatility);
     randomReturn = sqrt(holding_period)*volatility*gauss(0,1);
    //total return Returns
    value= random_return_weight_bond*randomReturn +fundamental_return_weight_bond*fundamentalReturn+coupon_yield;
    factor = holding_period* chartist_return_weight_bond;
    
   }
bins_number = min(bins,backwardWindow);
returns_avg=expectedReturnBond(bond,backwardWindow);
//belief->expectedPriceReturns=(value+factor*returns_avg)/holding_period;
belief->expectedPriceReturns=((value+factor*returns_avg)*NRDAYSINYEAR)/holding_period;
coupon_yield_annualized = coupon_yield*(NRDAYSINYEAR/holding_period);
belief->expectedTotalReturns=value+factor*returns_avg+coupon_yield_annualized;
belief->utility= computeBondUtilityFunction(bond, backwardWindow, factor,  value, lossaversion);
belief->last_price=lastPriceBond(bond);
}
