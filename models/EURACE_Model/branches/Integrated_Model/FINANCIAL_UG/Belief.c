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
}



double expectedPriceReturns(Belief *belief)
{   
       return belief->expectedPriceReturns;
}

int forwardMonths( int currentDay, int forwardWindow)
{   
    int nrForwardMonths;
    //printf("%d %d %d",currentDay,forwardWindow,DAYS_IN_MONTH);
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
{

  double futureFundPrice;
  double fundamentalReturn;
  int hRetainedEarnings;
  hRetainedEarnings=horizonRetainedEarnings(belief,currentDay,forwardWindow);
  futureFundPrice = (equity+hRetainedEarnings)/(stock->nrOutStandingShares);
  //printf(" fundamentalprice%f\n",futureFundPrice);
  fundamentalReturn = (futureFundPrice-lastPriceStock(stock))/lastPriceStock(stock);
  //printf(" fundamentalreturn%f\n",fundamentalReturn);
  return fundamentalReturn;
}

double randomReturnStock(Belief *belief, Stock *stock,int backwardWindow,int forwardWindow,double *rndvect)
{  double rndReturn;
   double volatility;
   double randn;
   int i;
   volatility=volatilityStock(stock,backwardWindow);
  // printf("volatility %f\n",volatility);
   volatility=max(0.0001,volatility);
   rndReturn=0;
   for(i=0;i<backwardWindow;i++)
    { randn=gauss(0,1);
     rndvect[i]= sqrt(forwardWindow)*volatility*randn;
     rndReturn=rndReturn+rndvect[i];
    }
   return rndReturn/backwardWindow;
}
double randomReturnBond(Belief *belief, Bond *bond,int backwardWindow,int forwardWindow,double *rndvect)
{  double rndReturn;
   double volatility;
   double randn;
   int i;
   volatility=volatilityBond(bond,backwardWindow);
  // printf("volatility %f\n",volatility);
   volatility=max(0.0001,volatility);
   rndReturn=0;
   for(i=0;i<backwardWindow;i++)
    { randn=gauss(0,1);
     rndvect[i]= sqrt(forwardWindow)*volatility*randn;
     rndReturn=rndReturn+rndvect[i];
    }
   return rndReturn/backwardWindow;
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
  double rndreturn[100];
  double total_returns_avg;
  double price_returns_avg;
  double returns_avg;
  double rnd_avg;
  double value,factor,dividend_yield_annualized,annual_coeff;
 
  annual_coeff=(NRDAYSINYEAR/forwardWindow);
  rnd_avg=randomReturnStock(belief, stock,forwardWindow,backwardWindow,rndreturn);
  printf("random return%f\n",rnd_avg);
  fundreturn= futureFundamentalReturn(belief,stock,currentDay,forwardWindow, equity);
  printf("fundamental return%f\n",fundreturn);
  returns_avg=expectedReturnStock(stock,backwardWindow);
  printf("chartist return%f\n",returns_avg);
  value= fundamentalWeight*fundreturn + belief->expectedCashFlowYield; 
  factor=forwardWindow*chartistWeight;
  price_returns_avg=((randomWeight*rnd_avg)+(fundamentalWeight*fundreturn)+(chartistWeight*forwardWindow*returns_avg))*annual_coeff;
  dividend_yield_annualized=belief->expectedCashFlowYield*annual_coeff;

  printf("pesi %f %f %f",randomWeight,fundamentalWeight,chartistWeight);
  
//printf("forwardWindow %d\n",forwardWindow);  
  printf("coeff di annualizz %f\n",annual_coeff); 
  printf("dividend yield annualized %f\n",dividend_yield_annualized);
  total_returns_avg=price_returns_avg+ dividend_yield_annualized;
  belief->utility= computeStockUtilityFunction(stock, backwardWindow, factor,  value, lossaversion,rndreturn, randomWeight);
  belief->expectedPriceReturns=price_returns_avg;
  belief->expectedTotalReturns=total_returns_avg;
  belief->last_price=lastPriceStock(stock);

  printf("price_return %f\n",belief->expectedPriceReturns/NRDAYSINYEAR);
  //if(abs(belief->expectedPriceReturns/NRDAYSINYEAR)>1) getchar();
}


void  bondBeliefFormation(Belief *belief, Bond *bond,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,int holdingPeriodToForwardW, double lossaversion)
{ int holding_period;
  int nrCoupons;
  double coupon;
  double coupon_stream,last_market_price;
  double fundamental_return_weight_bond;
  double random_return_weight_bond;
  double chartist_return_weight_bond;
  double fundamentalReturn,aux;
  double factor,value,coupon_yield,coupon_yield_annualized,returns_avg,annual_coeff;
  double rndreturn[100];
  double rnd_avg;


  holding_period=holdingPeriodToForwardW*forwardWindow;
  nrCoupons=coupons_payment_days(bond,currentDay,holding_period);
  //printf("numero di coupon%d\n",nrCoupons);
  last_market_price=lastPriceBond(bond);

if (nrCoupons>0)
    {
    coupon = ((bond->nominal_yield*bond->face_value)*(COUPONPERIODICITYNRMONTHS)/12);
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
    }
else
    // Random Return
   {
     rnd_avg = randomReturnBond(belief,bond,forwardWindow,backwardWindow,rndreturn);
     value= rnd_avg+fundamental_return_weight_bond*fundamentalReturn+coupon_yield;
     factor = holding_period* chartist_return_weight_bond;
   }
returns_avg=expectedReturnBond(bond,backwardWindow);
annual_coeff=(NRDAYSINYEAR/holding_period);
belief->expectedPriceReturns=(value+factor*returns_avg)*annual_coeff;
coupon_yield_annualized = coupon_yield*annual_coeff;
belief->expectedTotalReturns=value+factor*returns_avg+coupon_yield_annualized;
belief->utility= computeBondUtilityFunction(bond, backwardWindow, factor,  value, lossaversion,rndreturn,randomWeight);
belief->last_price=lastPriceBond(bond);
}
