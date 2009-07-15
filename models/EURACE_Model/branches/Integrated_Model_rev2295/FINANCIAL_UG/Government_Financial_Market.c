#include "../Government_agent_header.h"
#include "my_library_header.h"
//#include "../header.h"



int Government_send_info_bond(void)
{    Bond *bond;
     bond=get_bond();
     add_info_bond_message(*bond);
     return 0;
}

int Government_orders_issuing(void)
    {  double last_market_price, limit_price;
       Order *pending_order;
       Bond *bond;
       int issuer, qty;
       
       bond = get_bond();
       last_market_price = bond->prices[bond->index];
       limit_price = (1-BONDS_NEWISSUE_DISCOUNT)*last_market_price;
       
       pending_order=get_pending_order();
       qty =-bond->quantity;
       pending_order->quantity= qty;
       pending_order->price=limit_price;
       pending_order->issuer=ID;
       pending_order->assetId=bond->id;
       
       issuer = get_id();
              
       if(pending_order->quantity!=0)
        {
         //printf("invio ordini di vendita bond id%d price%f quantity%d",bond->id, pending_order->price,pending_order->quantity);
         add_order_message(issuer,bond->id, pending_order->price,pending_order->quantity);
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
  if (PRINT_DEBUG_GOV)
  {
  printf("\n Government_update_its_portfolio \n");
  printf("\t payment account before: %f \n",payment_account);
  }
  if(pending_order->quantity!=0)
  {
  order_status=get_first_order_status_message();
  while(order_status)
  { if(order_status->trader_id==issuer) 
      { 
       pending_order->quantity=pending_order->quantity-order_status->quantity;
       payment_account=payment_account-order_status->price*order_status->quantity;
       set_payment_account(payment_account);
       bond->quantity=bond->quantity+order_status->quantity;
       sold_quantity=sold_quantity-order_status->quantity;
       }

     order_status=get_next_order_status_message(order_status);   
     
  }
  }

  bond->nr_outstanding = bond->nr_outstanding +sold_quantity;
 
 if (PRINT_DEBUG_GOV)
 {
  printf("\t payment account after: %f \n",payment_account);
  printf("\t bond->quantity: %d sold_quantity: %d  bond->nr_outstanding: %d \n",bond->quantity,sold_quantity,bond->nr_outstanding);
  }
 // if(i==2) printf("numero di execuzione =%d\n",i);
 //printf("numero di outstanding bonds =%d\n",bond->nr_outstanding);
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

int Government_pays_coupons()
   { double coupon;
     coupon=(BOND.nominal_yield*BOND.face_value)/12;//Monthly coupon divided by 12
     PAYMENT_ACCOUNT=PAYMENT_ACCOUNT-(coupon*BOND.nr_outstanding);
     MONTHLY_BOND_INTEREST_PAYMENT = coupon*BOND.nr_outstanding; //Defined in Government/model.xml Gov memory
     add_payment_coupons_message(coupon,ID);
     return 0;
   }

int Government_read_policy_rate()
   { double tmp;
   
            START_POLICY_RATE_MESSAGE_LOOP
                tmp = policy_rate_message->policy_rate_value;      
            FINISH_POLICY_RATE_MESSAGE_LOOP
     
     BOND.nominal_yield = 1.1 * tmp;
     
     return 0;
   }



