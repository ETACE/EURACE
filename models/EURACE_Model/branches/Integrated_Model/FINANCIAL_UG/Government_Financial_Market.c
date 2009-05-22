#include "../Government_agent_header.h"
#include "my_library_header.h"
//#include "../header.h"


int Government_BondIssuing_decision(void)
{ 
	//printf("________BOND ISSUING DECISION________\n");
	int GovBondNewIssueAmount;
  Bond *bond;
  double limit_price,last_market_price;
  bond=get_bond();
  

    
    if(bond->maturity_day>CURRENTDAY)
         last_market_price=lastPriceBond(bond);

   /*Simon G: Temporary solution: limit price != 0*/
   if(last_market_price>0.0)
    	limit_price = (1-BONDS_NEWISSUE_DISCOUNT)*last_market_price;
   else
   {
	   printf("Financial_UG/Government_Financial_Market.c/Government_BondIssuing_decision()\n");
	   printf("Line: 25 -> Simon G: temporary solution if limit price is zero");
	   limit_price = 0.25;
	   last_market_price = 0.25;
   }
    
   /* printf("TOTAL_BOND_FINANCING %f \n",TOTAL_BOND_FINANCING);
    printf("limit_price %f \n",limit_price);
    printf("BONDS_NEWISSUE_DISCOUNT %f \n",BONDS_NEWISSUE_DISCOUNT);
    printf("last_market_price %f \n",last_market_price);*/

GovBondNewIssueAmount = (int) TOTAL_BOND_FINANCING/limit_price;
//printf("1_GovBondNewIssueAmount %d \n",GovBondNewIssueAmount);

//printf("sono qui%f\n",last_market_price);
return GovBondNewIssueAmount;

}
int Government_send_info_bond(void)
{    Bond *bond;
     bond=get_bond();
     //printf("_____________GOVERNMENT SEND BOND INFO______________\n");
     //printf("BOND: nr_outstanding %d\n",bond->nr_outstanding);
     //printf("BOND: quantity %d\n",bond->quantity);
    // printf("BOND: face_value %f\n",bond->face_value);
     //printf("BOND: nominal_yield %f\n",bond->nominal_yield);
     //printf("BOND: price %f\n",bond->prices[99]);
     //printf("BOND: price %f\n",bond->prices[0]);
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
        //add_order_message(issuer,bond->id, pending_order->price,pending_order->quantity);
       printf("Financial_UG/Government_Financial_Market.c/Government_generate_pending_orders()\n");
       printf("Line: 65 -> Temporary solution: setting pending_order->price to 1.0 in order_message \n");
       add_order_message(issuer,bond->id, 1.0,pending_order->quantity);
       //printf("_____________GOVERNMENT ORDERS ISSUING______________\n");
         //   printf("BOND: pending_order->price %f\n",pending_order->price);
           // printf("BOND: pending_order->quantity %d\n",pending_order->quantity);
       }
            
    return 0;
   }
int Government_generate_pending_orders(void)
    {int  qty,issuer;
     double  GovBondsInPortfolioValue,lastMarketPrice,GovBondNewIssueAmount;
     Bond *bond;
     Order *pending_order;
     int limitPrice;
     double payment_account;
    // int * tmp;
     
     GovBondsInPortfolioValue = 0;
     bond=get_bond();
     pending_order=get_pending_order();
     issuer=get_id();
     payment_account=get_payment_account();
     qty =bond->quantity;
     
     lastMarketPrice = lastPriceBond(bond);
     
     /*Simon G: Temporary solution: limit price != 0*/
     if(lastMarketPrice >0.0)
         limitPrice = (1- BONDS_NEWISSUE_DISCOUNT)*lastMarketPrice;
     else
     {
    	 printf("Financial_UG/Government_Financial_Market.c/Government_generate_pending_orders()\n");
    	 printf("Line: 99 -> Simon G: temporary solution if limit price is zero \n");
         limitPrice = 0.25;
         lastMarketPrice = 0.25;
     }
     
     GovBondsInPortfolioValue = GovBondsInPortfolioValue + qty*lastMarketPrice;
if ((payment_account+GovBondsInPortfolioValue)<0)
   {
    GovBondNewIssueAmount=Government_BondIssuing_decision();
    bond->quantity = bond->quantity + GovBondNewIssueAmount;
    bond->nr_outstanding= bond->nr_outstanding +GovBondNewIssueAmount;
    lastMarketPrice = lastPriceBond(bond);
    
    /*Simon G: Temporary solution: limit price != 0*/
    if(lastMarketPrice >0.0)
    	limitPrice = (1- BONDS_NEWISSUE_DISCOUNT)*lastMarketPrice;
    else
    {
    	printf("Financial_UG/Government_Financial_Market.c/Government_generate_pending_orders()\n");
    	printf("Line: 118 -> Simon G: temporary solution if limit price is zero\n");
    	limitPrice = 0.25;
    	lastMarketPrice = 0.25;
    }
    
    qty =-bond->quantity;
    pending_order->quantity= qty;
    pending_order->price=limitPrice;
    pending_order->issuer=ID;
    pending_order->assetId=bond->id;
    
    //if(GovBondNewIssueAmount > 20000)
    //scanf("%d", tmp);
    
 }
//printf("2__GovBondNewIssueAmount %d \n",GovBondNewIssueAmount);
//printf("2__qty %d \n",qty);
return 0;
}

int Government_update_its_portfolio()
{ int issuer;
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

