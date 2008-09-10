#include "../Government_agent_header.h"
#include "my_library_header.h"
//#include "../header.h"
#define BONDS_NEWISSUE_DISCOUNT 0.01


int Government_BondIssuing_decision(double gov_deficit)
{ int GovBondNewIssueAmount;
  Bond *bond;
  double limit_price,last_market_price;
  bond=get_bond();
  

    
    if(bond->maturity_day>CURRENTDAY)
         last_market_price=lastPriceBond(bond);
limit_price = (1-BONDS_NEWISSUE_DISCOUNT)*last_market_price;
GovBondNewIssueAmount = (int) abs(gov_deficit)/limit_price;
//printf("sono qui%f\n",last_market_price);
return GovBondNewIssueAmount;

}
int Government_send_info_bond(void)
{    Bond *bond;
     bond=get_bond();
     add_info_bond_message(*bond);
     return 0;
}
int Government_orders_issuing(void)
    {  Order *pending_order;
       Bond *bond;
       int issuer;
       pending_order=get_pending_order();
       issuer=get_id();
       bond=get_bond();
       if(pending_order->quantity!=0)
        add_order_message(issuer,bond->id, pending_order->price,pending_order->quantity);
    return 0;
   }
int Government_generate_pending_orders(void)
    {int  qty,issuer;
     double  GovBondsInPortfolioValue,lastMarketPrice,GovDeficit,GovBondNewIssueAmount;
     Bond *bond;
     Order *pending_order;
     int limitPrice;
     double payment_account;

     GovBondsInPortfolioValue = 0;
     bond=get_bond();
     pending_order=get_pending_order();
     issuer=get_id();
     payment_account=get_payment_account();
     qty =bond->quantity;
     lastMarketPrice = lastPriceBond(bond);
     GovBondsInPortfolioValue = GovBondsInPortfolioValue + qty*lastMarketPrice;
if ((payment_account+GovBondsInPortfolioValue)<0)
   {
    GovDeficit = payment_account+GovBondsInPortfolioValue;
    set_deficit(GovDeficit);
    GovBondNewIssueAmount=Government_BondIssuing_decision(GovDeficit);
    bond->quantity = bond->quantity + GovBondNewIssueAmount;
    bond->nr_outstanding= bond->nr_outstanding +GovBondNewIssueAmount;
    lastMarketPrice = lastPriceBond(bond);
    limitPrice = (1- BONDS_NEWISSUE_DISCOUNT)*lastMarketPrice;
    qty =-bond->quantity;
    pending_order->quantity= qty;
    pending_order->price=limitPrice;
    pending_order->issuer=ID;
    pending_order->assetId=bond->id;
 }
return 0;
}

int Government_update_its_portfolio()
{ int issuer,quantity;
  double payment_account;
  Bond *bond;
  Order *pending_order;
  m_order_status *order_status;

  pending_order=get_pending_order();
  payment_account=get_payment_account();
  bond=get_bond();
  issuer=get_id();
  if(pending_order->quantity!=0)
  {
  order_status=get_first_order_status_message();
  while(order_status)
  { if(order_status->trader_id==issuer) 
      { 
       pending_order->quantity=pending_order->quantity-order_status->quantity;
       payment_account=payment_account-order_status->price*order_status->quantity;
;      set_payment_account(payment_account);
       bond->quantity=bond->quantity+order_status->quantity;
       }

     order_status=get_next_order_status_message(order_status);   
  }
  }
 // if(i==2) printf("numero di execuzione =%d\n",i);
  return 0;
}

int Government_receive_info_bond(void)
{ Bond *bond;
   double price;
   bond =get_bond();
  
   m_infoAssetCH  *current;
   current=get_first_infoAssetCH_message();
   
   while(current)
  {
   
   if(ID==current->asset_id) 
       {  price=current->price;
          addPriceBond(bond,price);
       }
    current=get_first_infoAssetCH_message();
   }
  return 0;
}

