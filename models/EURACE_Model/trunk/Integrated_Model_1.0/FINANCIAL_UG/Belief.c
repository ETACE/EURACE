#include "my_library_header.h"





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
{ double futureFundPrice;
  double fundamentalReturn;
  int hRetainedEarnings;
  hRetainedEarnings=horizonRetainedEarnings(belief,currentDay,forwardWindow);
  futureFundPrice = (equity+hRetainedEarnings)/(stock->nrOutStandingShares);
 // printf(" return%f\n",futureFundPrice);
  fundamentalReturn = (futureFundPrice-lastPriceStock(stock))/lastPriceStock(stock);
  return fundamentalReturn;
       }

double randomReturnStock(Belief *belief, Stock *stock, int forwardWindow, int backwardWindow,double *rndvect)
{  double rndReturn;
   double volatility;
   double randn;
   double sqrtvol;
   int i;
   volatility = volatilityStock(stock,backwardWindow);
  // printf("volatility %f\n",volatility);
   volatility=max(0.0001,volatility);
   rndReturn=0;
   sqrtvol=sqrt(forwardWindow)*volatility;
   //printf("randomReturnStock");
   //getchar();
   
   for(i=0;i<backwardWindow;i++)
    { 
     randn=fast_gauss();
     rndvect[i]= sqrtvol*randn;
     rndReturn=rndReturn+rndvect[i];
             
    }
    return rndReturn/backwardWindow;
}

double randomReturnBond(Bond *bond,int backwardWindow,int holding_period,double *rndvect)
{  double rndReturn;
   double volatility;
   double randn;
    double factor;
   int i;
   
   volatility=volatilityBond(bond,backwardWindow);
   //printf("\n backwardWindow %d",backwardWindow);
   volatility=max(0.0001,volatility);
   rndReturn=0;
   factor=sqrt(holding_period)*volatility;
   for(i=0;i<backwardWindow;i++)
    { randn=fast_gauss();
     rndvect[i]= factor*randn;
     rndReturn=rndReturn+rndvect[i];
     }
        
   //return rndReturn/backwardWindow;
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
  double rndreturn[100];
  double total_returns_avg;
  double price_returns_avg;
  double return_random, return_chartist, return_fundamental;
  double dividend_yield_annualized,annual_coeff;
  double r1, r2, r3, r, utility_tmp;
  //   FILE *file1=NULL;
 // char * filename="";
  int i;
 
  annual_coeff=(NRDAYSINYEAR/forwardWindow);
 /*some of the  behavior weights are usually zero so some computation could be unuseful, this increase certanly the performance,*/

  return_random = randomReturnStock(belief, stock,forwardWindow,backwardWindow,rndreturn);
     
  if (fundamentalWeight!=0) 
     return_fundamental = futureFundamentalReturn(belief,stock,currentDay,forwardWindow, equity);
  else return_fundamental=0;
     
  if(chartistWeight!=0) 
     return_chartist = forwardWindow*expectedReturnStock(stock,backwardWindow);
  else return_chartist=0;
  
  price_returns_avg = annual_coeff*(randomWeight*return_random + chartistWeight*return_chartist + fundamentalWeight*return_fundamental);

  dividend_yield_annualized = annual_coeff*belief->expectedCashFlowYield;

  total_returns_avg = price_returns_avg + dividend_yield_annualized;

  belief->expectedPriceReturns = price_returns_avg;
  belief->expectedTotalReturns = total_returns_avg;
  belief->last_price = lastPriceStock(stock);
  
  utility_tmp = 0;
  
//  printf("n chartistWeight %f fundamentalWeight %f randomWeight %f",chartistWeight,fundamentalWeight,randomWeight);
//  getchar();
// Computation of utility  
  for(i=0;i<backwardWindow;i++)
    {
     r1 = chartistWeight*forwardWindow*backreturnsAt(stock,i);
     r2 = fundamentalWeight*return_fundamental;
     r3 = randomWeight*rndreturn[i];                           
     r = r1 + r2 + r3 + dividend_yield_annualized;
  
     if (r<0) utility_tmp = utility_tmp + r*lossaversion;
     else     utility_tmp = utility_tmp+r;
  //   printf("\n r1: %f r2: %f rndreturn[i]: %f r3: %f r: %f utility_tmp %f",r1,r2,rndreturn[i],r3,r,utility_tmp);  
    }
// 
 // printf("\n return_fundamental: %f dividend_yield_annualized: %f lossaversion: %f",return_fundamental,dividend_yield_annualized,lossaversion);

  belief->utility = utility_tmp/backwardWindow;
 //printf("\n stock id: %d belief->utility: %f backwardWindow: %d",stock->id,belief->utility,backwardWindow);
 //getchar();
  
   /*     if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_stocks_beliefs.txt");      
        file1 = fopen(filename,"a");
    //    fprintf(file1,"%d %f %d %f %f %f",CURRENTDAY,bond->nominal_yield,nrCoupons,coupon_stream,last_market_price,coupon_yield_annualized);
     //   fprintf(file1," %f %f %f %f %f %f",factor_random,return_random,factor_chartist,return_chartist,factor_fundamental,return_fundamental);
     //   fprintf(file1," %f %f\n",belief->expectedPriceReturns,belief->expectedTotalReturns);
        fprintf(file1,"\n%d %f %f %f %f",CURRENTDAY,belief->last_price);
        fprintf(file1,"\n%d %f %f %f %f",CURRENTDAY,belief->last_price,return_random,return_chartist,return_fundamental);
        fprintf(file1," %f %f %f %f",price_returns_avg,dividend_yield_annualized,total_returns_avg,belief->utility);
        fclose(file1);
        free(filename);        
    } */ 
  
}



void  bondBeliefFormation(Belief *belief, Bond *bond,int backwardWindow,int forwardWindow, double randomWeight,double  fundamentalWeight,double chartistWeight, int bins ,int currentDay,int holdingPeriodToForwardW, double lossaversion)
{
  // FILE *file1=NULL;
  // char * filename="";
  //int bins_number;
  int holding_period;
  int i, nrCoupons;
  double coupon, coupon_stream, coupon_yield, coupon_yield_annualized, last_market_price;
  double random_return_weight_bond, fundamental_return_weight_bond, chartist_return_weight_bond;
  double return_rnd;
  return_rnd =0.0;
  double return_fundamental, return_chartist, return_random;
  double days2maturity;
  double factor_chartist, factor_random, factor_fundamental, factor_chartist2;
  double annual_coeff;
  double rndreturns[100];
  double r1, r2, r3, r, utility_tmp;

  holding_period=holdingPeriodToForwardW*forwardWindow;
  nrCoupons=coupons_payment_days(bond,currentDay,holding_period);
  //printf("numero di coupon%d\n",nrCoupons);
  last_market_price=lastPriceBond(bond);
  annual_coeff=(NRDAYSINYEAR/holding_period);

if (nrCoupons>0)
    {
    coupon = ((bond->nominal_yield*bond->face_value)*(COUPONPERIODICITYNRMONTHS)/12);
    coupon_stream = nrCoupons*coupon;
    coupon_yield = coupon_stream/last_market_price;
    }
else coupon_yield = 0;

coupon_yield_annualized = annual_coeff*coupon_yield;

// Fundamental Return
days2maturity = bond->maturity_day-currentDay;

// weights rescaling for bonds
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

// factor computation
if (holding_period>=days2maturity)
    {factor_fundamental = 1; 
     factor_chartist=0;
     factor_random=0;
    }
else
   {
     factor_fundamental = fundamental_return_weight_bond;
     factor_chartist = 0;
     factor_random = 1-factor_fundamental;
   }

// The three components of returns expected in the holding period
return_fundamental = (min(holding_period,days2maturity)/days2maturity)*(bond->face_value-last_market_price)/last_market_price;
return_chartist = holding_period*expectedReturnBond(bond,backwardWindow);
return_random = randomReturnBond(bond, backwardWindow, holding_period, rndreturns);
   

//return_rnd = sumvector(rndreturns,backwardWindow)/backwardWindow;
belief->expectedPriceReturns=annual_coeff*(factor_fundamental*return_fundamental+factor_chartist*return_chartist+ factor_random*return_random);
//if (abs(belief->expectedPriceReturns)/NRDAYSINYEAR > 1)
 //printf("\n bondBeliefFormation \n exp_price_ret %f fund %f char %f rnd %f ",belief->expectedPriceReturns, value, factor_chartist*returns_char,factor_random*return_rnd);

belief->expectedTotalReturns = belief->expectedPriceReturns + coupon_yield_annualized;

//printf("\n TotalReturns: %f PriceReturns %f coupon_yield_annualized %f",belief->expectedTotalReturns,belief->expectedPriceReturns,coupon_yield_annualized);

factor_chartist2 = holding_period*factor_chartist;

utility_tmp = 0;

//printf("\n factor_chartist: %f factor_fundamental: %f factor_random: %f",factor_chartist,factor_fundamental,factor_random);
  
// Computation of utility  
  for(i=0;i<backwardWindow;i++)
    {
     r1 = factor_chartist*holding_period*backreturns_bond(bond,i);
     r2 = factor_fundamental*return_fundamental;
     r3 = factor_random*rndreturns[i];                           
     r = r1 + r2 + r3 + coupon_yield_annualized;
  
     if (r<0) utility_tmp = utility_tmp + r*lossaversion;
     else     utility_tmp = utility_tmp+r;
  //   printf("\n utility_tmp: %f",utility_tmp);
    }
// 
    
belief->utility = utility_tmp/backwardWindow;
//printf("\n bond belief->utility: %f backwardWindow: %d",belief->utility,backwardWindow);

belief->last_price=lastPriceBond(bond);


   /* if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_bonds_beliefs.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"%d %f %d %f %f %f",CURRENTDAY,bond->nominal_yield,nrCoupons,coupon_stream,last_market_price,coupon_yield_annualized);
        fprintf(file1," %f %f %f %f %f %f",factor_random,return_random,factor_chartist,return_chartist,factor_fundamental,return_fundamental);
        fprintf(file1," %f %f %f\n",belief->expectedPriceReturns,belief->expectedTotalReturns,belief->utility);
        fclose(file1);
        free(filename);        
    } */
  
}
