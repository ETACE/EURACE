#include "../Firm_agent_header.h"
#include "my_library_header.h"
//#include "../header.h"

/*void CGP_income_statement_computing(double earnings, double earnings_payout, double *earnings_exp,double *earnings_payout_exp)
     {
       static double ROI=0.05;
       const double ROI_mean=0.05;
       const double ROI_std=0.01;
       const double ROI_a1= 0.9;
       const double corporateTaxRate= 0.1;
       const double bank_loan=0.0;
       const double lending_rates=0.0;
       const double payout_policy=0.1;
       const double fixed_assets=10000;
       double interests_expenses,earnings_taxes;
       double a0,a1,s;
       double EBIT;
       printf("ROI =======%f\n",ROI);
       
       a1 =ROI_a1;
       a0 = ROI_mean*(1-a1);
       s =  ROI_std*sqrt(1-a1*a1);

      ROI = a0 + a1*ROI + s*gauss(0,1);
      EBIT = (ROI/12)*fixed_assets; //capitale fisico delle imprese
      interests_expenses = (lending_rates/12)*bank_loan; // debito e interesse sul debito
      earnings_taxes= corporateTaxRate*max(0,EBIT-interests_expenses);
      earnings = EBIT -interests_expenses - earnings_taxes;
      *earnings_exp= earnings;
      if (earnings>0)  
               earnings_payout= payout_policy*earnings;
      else earnings_payout=0;
           *earnings_payout_exp = earnings_payout;
     }*/



int Firm_send_info(void)
{    double earnings_exp;
     double earnings_payout_exp;
     Stock *stock;
     stock=get_stock();
     double dividend;
     dividend=CURRENT_DIVIDEND_PER_SHARE;
     //EQUITY=50+next();
  // CGP_income_statement_computing(EARNINGS,EARNINGS_PAYOUT, &earnings_exp,&earnings_payout_exp);
     //("earnings_exp=%f   earnings_payout_exp=%f\n",earnings_exp,earnings_payout_exp);
     //STOCK.nrOutStandingShares=current_shares_outstanding;
     add_info_firm_message(ID, earnings_exp,  dividend, earnings_payout_exp,  EQUITY, STOCK);
     return 0;
}



int Firm_receive_stock_info(void)
{ Stock *stock;
   double price;
   stock =get_stock();
  
   m_infoAssetCH  *current;
   current=get_first_infoAssetCH_message();
    //printf(" receive info message");
   while(current)
  {
  //printf(" receive info message");
   if(ID==current->asset_id) 
       {  price=current->price;
          addPriceStock(stock,price);
       }
    current=get_first_infoAssetCH_message();
   }
  return 0;
}

