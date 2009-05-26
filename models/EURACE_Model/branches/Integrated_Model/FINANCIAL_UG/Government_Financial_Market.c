#include "../Government_agent_header.h"
#include "my_library_header.h"
//#include "../header.h"


int Government_BondIssuing_decision()
{ int GovBondNewIssueAmount;
  Bond *bond;
  double limit_price,last_market_price;
  bond=get_bond();
  if(bond->maturity_day>CURRENTDAY) last_market_price=lastPriceBond(bond);
  limit_price = (1-BONDS_NEWISSUE_DISCOUNT)*last_market_price;
 GovBondNewIssueAmount = (int) TOTAL_BOND_FINANCING/limit_price;

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
        {
         //printf("invio ordini di vendita bond id%d price%f quantity%d",bond->id, pending_order->price,pending_order->quantity);
         add_order_message(issuer,bond->id, pending_order->price,pending_order->quantity);
        }
    return 0;
   }
int Government_generate_pending_orders(void)
    {int  qty,issuer;
     double  GovBondsInPortfolioValue,lastMarketPrice,govdeficit; 
     int GovBondNewIssueAmount;
     Bond *bond;
     Order *pending_order;
      double limitPrice;
     double payment_account;
     bond=get_bond();
     pending_order=get_pending_order();
     issuer=get_id();
     payment_account=get_payment_account();
     qty =bond->quantity;
     lastMarketPrice = lastPriceBond(bond);
     GovBondsInPortfolioValue =  qty*lastMarketPrice;
   // printf("BONDS_NEWISSUE_DISCOUNT==%f",BONDS_NEWISSUE_DISCOUNT);
if ((payment_account+GovBondsInPortfolioValue)<0)
   {
    govdeficit=(payment_account+GovBondsInPortfolioValue);
    //set_deficit(govdeficit);
    GovBondNewIssueAmount=Government_BondIssuing_decision();//govdeficit);
    bond->quantity = bond->quantity + GovBondNewIssueAmount;
    //bond->nr_outstanding= bond->nr_outstanding +GovBondNewIssueAmount;
    printf("BONDS_NEWISSUE_DISCOUNT==%f",BONDS_NEWISSUE_DISCOUNT);
    limitPrice = (1- BONDS_NEWISSUE_DISCOUNT)*lastMarketPrice;
   printf(" Government_generate_pending_orders id%d price%f quantity%d",ID, limitPrice,GovBondNewIssueAmount);
    qty =-bond->quantity;
    pending_order->quantity= qty;
    pending_order->price=limitPrice;
    pending_order->issuer=ID;
    pending_order->assetId=bond->id;
 }
return 0;
}

int Government_update_its_portfolio()
{ int issuer;
  double payment_account;
  Bond *bond;
  Order *pending_order;
  m_order_status *order_status;
  int sold_quantity;
  pending_order=get_pending_order();
  payment_account=get_payment_account();
  bond=get_bond();
  issuer=get_id();
  sold_quantity=0;
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
       sold_quantity=sold_quantity-order_status->quantity;
       }

     order_status=get_next_order_status_message(order_status);   
     
  }
  }
  bond->nr_outstanding = bond->nr_outstanding +sold_quantity;
 // if(i==2) printf("numero di execuzione =%d\n",i);
 printf("numero di outstanding bonds =%d\n",bond->nr_outstanding);
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
    current=get_next_infoAssetCH_message(current);
   }
  return 0;
}

