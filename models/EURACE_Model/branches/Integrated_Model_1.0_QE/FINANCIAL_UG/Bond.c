#include "my_library_header.h"
void initializeBond(Bond *aBond,int id, int nr_outstanding,double face_value, double nominal_yield)
{ int i; 
  double aux;
  double prec;
  aBond->id=id;
  aBond->index=0;
   aBond->nr_outstanding=nr_outstanding;
  aBond->face_value=face_value;
  aBond->nominal_yield=nominal_yield;
  aBond->maturity_day=10000;
  aBond->issue_day=0;
  aux=face_value;

 for(i=0;i<MAXPRICES;i++)
     { prec=aux;
      aux=prec+0.01*gauss(0,0.1);
      addPriceBond(aBond,aux);
     }
}
double  backreturns_bond(Bond *bond,int ind)
    { int index;
      index=bond->index-ind;
      if(index<0) index=MAXRETURNS+index;
        
       return bond->returns[index];
        
   }
double lastPriceBond(Bond *aBond)
{       
        double answer;
        answer=aBond->prices[aBond->index];
        return answer;
}


void addPriceBond(Bond *bond, double price)
{    int precindex;
     precindex=bond->index;
     if(bond->index==MAXPRICES-1) bond->index=0;
                                    
     else bond->index++;
     bond->prices[bond->index]=price;
     bond->returns[bond->index]= (price-bond->prices[precindex])/price;
  
}
double expectedReturnBond(Bond *bond,int backwardWindow)
       { double mean;
         int i;
         mean=0;
         for(i=0;i<backwardWindow;i++)
             mean=mean+backreturns_bond(bond,i);
         mean=mean/(backwardWindow);
         return mean;
       }

     
double volatilityBond(Bond *bond,int backwardWindow)
     { double expectedreturn;
       double volatility;
       double aux;
       int i;
       volatility=0;
 
       expectedreturn=expectedReturnBond(bond,backwardWindow);
        for(i=0;i<backwardWindow;i++)
            {  
               aux=(backreturns_bond(bond,i)-expectedreturn);
               volatility=volatility+(aux*aux);
            }
      volatility=sqrt(volatility/backwardWindow);
      return volatility;
     }
void totalReturnsBond(Bond *bond, double *vect, int backwardWindow,double factor, double value)
  {  int i;
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturns_bond(bond,i)*factor+value;
  }
void priceReturnsBond(Bond *bond, double *vect, int backwardWindow)
  {  int i;
    
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturns_bond(bond,i);
  }



void historicalReturnsBond(Bond *bond, double *vect, int backwardWindow,double forwardWindow)
  {  int index,i;
     double *returns;
     index=bond->index;
     returns=bond->returns;
     for(i=0;i<(backwardWindow);i++)
     vect[i]=backreturns_bond(bond,i)*forwardWindow;
  }
/**/
int  coupons_payment_days(Bond *bond,int currentDay,int holding_period)
{ 
   int nrCoupons;
   int coupon_day_period;
   int issue_day;
   issue_day=bond->issue_day;
   coupon_day_period=(int)DAYS_IN_MONTH*COUPONPERIODICITYNRMONTHS;
   nrCoupons= ((currentDay+issue_day+holding_period)/coupon_day_period)-(currentDay+issue_day)/coupon_day_period;
   return nrCoupons;
}

double computeBondUtilityFunction(Bond *bond, double *rnd_returns, int backwardWindow, double return_fundamental, double factor_chartist, double factor_random, double factor_fundamental, double lossaversion)
{ 
  int i;
  double utility;
  double r;
  utility=0;

  for(i=0;i<backwardWindow;i++)
    { 
   r=factor_chartist*backreturns_bond(bond,i) + factor_fundamental*return_fundamental + factor_random*rnd_returns[i];
  
     if (r<0) utility=utility+r*lossaversion;
     else     utility=utility+r;
    }
//  if(utility==NAN) printf("----------%f",rndvect[i]*randomWeight);
  return utility/backwardWindow;
}

