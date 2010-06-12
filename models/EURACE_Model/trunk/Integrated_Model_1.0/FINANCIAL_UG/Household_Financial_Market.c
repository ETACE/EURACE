#include "my_library_header.h"
#include "../Household_agent_header.h"


//utility functions

int Household_send_orders()
{   Order_array *orders;
    Order *ord;
    int i;
    Order_array *pending;
    Asset_array *assetsowned;
    Belief_array *beliefs;
    double_array *assetWeights;
    double_array *assetUtilities;
    assetsowned=get_assetsowned();
    pending=get_pendingOrders();
    assetWeights=get_assetWeights();
    assetUtilities=get_assetUtilities();
    beliefs=get_beliefs();
    computeUtilities(beliefs,assetUtilities);
    assetUtilitiesToWeights(assetWeights,assetUtilities,get_risk_free_rate());
    generatePendingOrders(assetsowned,pending,beliefs,&PAYMENT_ACCOUNT);
    
    orders=get_pendingOrders();
    

    for(i=0;i<sizeCOrder(orders);i++)
    {
     ord=elementAtCOrder(orders,i);
     
     if PRINT_DEBUG_AFM
     {
     if (ord->quantity>10e+6)
     {
        printf("Household_send_orders()\n");
        //printf("Line: 42 ->  ord->quantity>10e+6\n");
        printf("ID: %d PAYMENT_ACCOUNT: %f \n",ID,PAYMENT_ACCOUNT);
        printf("ASSET_ID %d, Order quantity: %d price: %f\n", ord->assetId,ord->quantity,ord->price);
        //printf("Press a number and then ENTER to continue ...");
        //scanf("%d", tmp);
     //   getchar();
     }
     }
     
     add_order_message(ord->issuer,ord->assetId, ord->price, ord->quantity);
     
 //    if (PRINT_DEBUG_AFM) 
  // printf("\n\t Household send order for asset: %d price: %f quantity: %d",ord->assetId,ord->price,ord->quantity);
     
    }
    return 0;

}


void computeUtilities(Belief_array *beliefs, double_array *assetUtilities)
{
  Belief *belief;
  int i;
  double utility;
  int size;
  size=beliefs->size;
  reset_double_array(assetUtilities);
  for(i=0;i<size;i++)
     {
     belief=&(beliefs->array[i]);

     utility=belief->utility;
     add_double(assetUtilities,utility);
     // printf("\n assetUtilities: %f",utility);
     }
     //getchar();
}
void assetUtilitiesToWeights(double_array *assetWeights,double_array *assetUtilities,double bankrate)
{
      double minimo;
      int size,i;
      double somma;
      
   //   printf("assetUtilitiesToWeights",size);
    //  getchar();
      
      reset_double_array(assetWeights);
      
      minimo=lessthan(assetUtilities);
  //     printf("minimo ====%f\n",minimo);
      size=sizeCDouble(assetUtilities);
 //     printf("size ====%d\n",size);
      somma=0;
      for(i=0;i<size;i++)
         { if(minimo<0) add_double(assetWeights,assetUtilities->array[i]-minimo);
           else add_double(assetWeights,assetUtilities->array[i]);
           somma=somma+assetWeights->array[i];
   //        printf("somma ====%f assetUtilities->array[i]: %f assetWeights->array[i] ====%f\n",somma,assetUtilities->array[i],assetWeights->array[i]);
           
         }

     if(minimo<0)  { somma=somma+bankrate-minimo;
                    add_double(assetWeights,bankrate-minimo);
                   }
              else { somma=somma+bankrate;
                     add_double(assetWeights,bankrate);
                   }
  // printf("\n\n bankrate: %f assetWeights->array[i]: %f somma: %f",bankrate,assetWeights->array[i],somma);                
 //printf("size pesi =====%d\n",assetWeights->size);
    divide(assetWeights,somma);
}

int  Household_select_strategy()
  { 
    set_strategy(next()<TRADING_ACTIVITY);
    
    if (PRINT_DEBUG)
    {
                    printf("\n Household_select_strategy Id: %d",ID);
                    printf("\n\t strategy: %f",STRATEGY);
                    
                    }
    
    return 0;
  }

   
int Household_update_its_portfolio()
{ 
       
  int issuer;
  Asset_array *assets;
  Order_array *pendingOrders;
  m_order_status *info;
  Order ord;
  Order *currentOrder;
  float transactions;
  
    // #ifdef _DEBUG_MODE  
  char * filename;
  FILE * file1;
  
      // #endif

  currentOrder=&ord;
  pendingOrders=get_pendingOrders();
  assets=get_assetsowned();
  issuer=get_id();
  info=get_first_order_status_message();
  
  transactions = 0.0;
  
  if (PRINT_DEBUG) 
  {
                   printf("\n\n Household_update_its_portfolio ID: %d",ID);
                   printf("\n\t PAYMENT_ACCOUNT: %f",PAYMENT_ACCOUNT);}
  
  while(info)
  {  
     if(info->trader_id==issuer) 
      {        
       setOrder(currentOrder,info->price,info->quantity,info->asset_id,info->trader_id);
       if(sizeCOrder(pendingOrders)>0) 
       {
         executeOrder(&PAYMENT_ACCOUNT,currentOrder,assets,pendingOrders);
         transactions = transactions - (info->price)*(info->quantity);
         if (PRINT_DEBUG) 
        printf("\n\t asset_id: %d price: %f quantity: %d",info->asset_id,info->price,info->quantity); 
        }
        }
     info=get_next_order_status_message(info);   
  }
  
  /*
   #ifdef _DEBUG_MODE       
   if (PRINT_DEBUG_FILE_EXP1)
    {                       
        filename = malloc(40*sizeof(char));
        filename[0]=0;
        strcpy(filename, "its/households_transactions.txt");      
        file1 = fopen(filename,"a");
        fprintf(file1,"\n %d %d %f",CURRENTDAY,ID,transactions);
        fclose(file1);
        free(filename);
    }                
    #endif
  */
  
  if (PRINT_DEBUG) printf("\n\t PAYMENT_ACCOUNT: %f",PAYMENT_ACCOUNT);
    
  
  return 0;
}

int distribuite(double cash, double totalwealth)
{
    double payment_account;
    double csh;
    double wealth;
    wealth=get_wealth();
    payment_account=get_payment_account();
    csh=payment_account+(cash*wealth)/totalwealth;
    set_payment_account(csh);
    return 0;
}


/* it compute a limitOrder on an Asset  contained into its Portfolio , */
void computeLimitOrder( Asset *anAsset, double weight, double resource,Belief *belief, Order *order)
{
      double limitPrice,lastprice;
      int quantity,deltaquantity; 
      int assetId;
      int trader_id;
      double aux;
      trader_id=get_id();
      quantity=anAsset->quantity;
      assetId=anAsset->id;
     
      lastprice=belief->last_price;
      anAsset->lastPrice=belief->last_price;
      
      aux=expectedPriceReturns(belief);           
      aux= aux/NRDAYSINYEAR; 
      
     
       //printf("\n expected price return %f NRDAYSINYEAR %d", aux, NRDAYSINYEAR);
      //if(abs(aux)>1) printf("\n assetId %d expected price return %f exp_price_tmp %f",assetId,aux,aux_tmp);
      if(aux<-1) aux=-1; 
       //if(aux==-1) {printf("errore");getchar();} 
      
      limitPrice=lastprice*(1+aux); 
      if((weight==0)&&(limitPrice==0)) deltaquantity=-quantity;
      else
      if(limitPrice==0) deltaquantity=-quantity;
      else deltaquantity=(int)(weight*resource/(limitPrice))-quantity;
      
     // printf("\n limitPrice: %f resource: %f weight: %f quantity: %d deltaquantity: %d",limitPrice,resource,weight,quantity,deltaquantity);
      
      if( PRINT_DEBUG_AFM)
      if(abs(deltaquantity)>10000) 
        {
         printf("weight %f resource %f limitprice %f quantity %d\n",weight,resource,limitPrice,deltaquantity);
         printf("fund %f random %f chartist %f\n",FUNDAMENTALWEIGHT,RANDOMWEIGHT,CHARTISTWEIGHT); 
        }
      setOrder(order,limitPrice,deltaquantity,assetId,trader_id);
      
}

double cashDemand(Order_array *pending)
       {
          int size,i; 
          double value,cashFordemand;
          Order *ord;
          size= sizeCOrder(pending);
          cashFordemand=0;
          for(i=0; i<size ; i++)
            {
              ord=elementAtCOrder(pending,i);
              value=ord->price*ord->quantity;
              if(value>0) cashFordemand+=value;
            }
         return cashFordemand;
}

void reduce_demand(Order_array *pending, double budget)
     {    int size,i; 
          double cashFordemand,demand_budget,value;
          Order *ord;
          size= sizeCOrder(pending);
          cashFordemand= cashDemand(pending);
          demand_budget=cashFordemand;
          if(budget<demand_budget)
          for(i=0; i<size ; i++)
            {
              ord=elementAtCOrder(pending,i);
              value=ord->price*ord->quantity;
              if(value>0) ord->quantity=(int)ord->quantity*(budget/demand_budget);
            }
}
              
              
              
              
void generatePendingOrders(Asset_array *assetsowned,Order_array *pending, Belief_array *beliefs,double *payment_account)
{ int size,i;
  int index;
  Order *ord;
  Order anorder;
  double resource;
  double weight;
  double tem_wealth;
  Asset *asset;
  Belief *belief;
  int target_quantity;
  ord=&anorder;
  double_array *weights;
  tem_wealth=wealth(PAYMENT_ACCOUNT,assetsowned);
  resource=wealth(PAYMENT_ACCOUNT-CONSUMPTION_BUDGET,assetsowned);
  
   if (PRINT_DEBUG_AFM)
             {
             printf("\n HOUSEHOLD %d generatePendingOrders (I): \n",ID);
             printf("\t PAYMENT_ACCOUNT %f WEALTH %f \n",PAYMENT_ACCOUNT,WEALTH);
             printf("\t tem_wealth %f CONSUMPTION_BUDGET %f resource %f\n",tem_wealth,CONSUMPTION_BUDGET,resource);
             getchar();  
             } 
  

  set_wealth(tem_wealth);
  size=beliefs->size;
  reset_Order_array(pending);
  weights=get_assetWeights();
  //printf("size=%d\n",size);

   if (PRINT_DEBUG_AFM)
             {
             printf("\t WEALTH after: %d\n",ID);
             } 

   if (PRINT_DEBUG_AFM)
             {
             printf("\n HOUSEHOLD: %d generatePendingOrders (II) \n",ID);
             } 


  for(i=0;i<size;i++)
  { 
    belief=&(beliefs->array[i]);
    index=findCAsset(assetsowned,belief->asset_id);

    if(index>=0) asset=elementAtCAsset(assetsowned,index);
    else 
         { index=assetsowned->size;
           add_Asset(assetsowned, belief->asset_id,0,belief->last_price);
           asset=elementAtCAsset(assetsowned,index);
         }
    weight=elementAtCDouble(weights,i);
    //printf("\n generatePendingOrders i %d weight %f", i, weight);
    computeLimitOrder(asset, weight,resource,belief, ord);
    
    if((ord->quantity!=0)&&(ord->price>0)) addOrder(pending,ord);
    
    if (PRINT_DEBUG_AFM)
             {
             printf("\t asset_id %d \n",belief->asset_id);
             printf("\t portfolio quantity: %d last market price: %f\n",asset->quantity,asset->lastPrice);
             printf("\t target weight: %f target weight*resource: %f\n",weight,weight*resource);
             printf("\t order quantity: %d limit price: %f\n",ord->quantity,ord->price);
             target_quantity = asset->quantity+ord->quantity;
             printf("\t target quantity: %d target resource: %f\n",target_quantity,ord->price*target_quantity);
             
             }   
  }
    //if (PRINT_DEBUG)
//    {getchar();}


    /*double prima,dopo;
    prima=cashDemand(pending);
    reduce_demand(pending, PAYMENT_ACCOUNT-CONSUMPTION_BUDGET);
    dopo=cashDemand(pending);
    printf("budget =%f prima=%f dopo=%f \n",PAYMENT_ACCOUNT-CONSUMPTION_BUDGET,prima,dopo);
   */
//}
}


int Household_stock_beliefs_formation()
{ 
  Stock *stock;
  int i;
  m_info_firm *cinfo_stock;
  Belief *belief;
  Belief_array *beliefs;
  double dividend, earning_payout,earnings,equity;
  
  beliefs=get_beliefs();
  reset_Belief_array(beliefs);
  i=0;
  cinfo_stock=get_first_info_firm_message();
  while( cinfo_stock)
    {  
     
     stock=&(cinfo_stock->stock);
     dividend=cinfo_stock->dividend;
     earning_payout=cinfo_stock->earnings_payout;
     earnings=cinfo_stock->earnings;
     equity=cinfo_stock->equity;
     add_Belief(beliefs,stock->id, 0, 0, 0,0, 0,0, 0,0);
     belief=&(beliefs->array[i]); 

     firmBeliefFormation(belief,stock,CURRENTDAY,FORWARDWINDOW,dividend,earnings,earning_payout);

     stockBeliefFormation(belief,stock,BACKWARDWINDOW,FORWARDWINDOW, RANDOMWEIGHT,FUNDAMENTALWEIGHT,CHARTISTWEIGHT, BINS,CURRENTDAY,equity,LOSSAVERSION);
    
     cinfo_stock= get_next_info_firm_message(cinfo_stock);
     i++;
    }
    
    if (PRINT_DEBUG) printf("\n Household_stock_beliefs_formation ID: %d",ID);
    
    
return 0;
}



int Household_bond_beliefs_formation()
{ 
 
  Bond *bond;
  int i;
  m_info_bond *cinfo_bond;
  Belief *belief;
  Belief_array *beliefs;
  cinfo_bond=get_first_info_bond_message();
  beliefs=get_beliefs();
  //reset_Belief_array(beliefs);
  i=0;
  while( cinfo_bond)
    {  
     
     bond=&(cinfo_bond->bond);
     
     add_Belief(beliefs,bond->id, 0, 0, 0,0, 0,0, 0,0);
     belief=&(beliefs->array[beliefs->size-1]); 
     //printf("\n ID %d BACKWARDWINDOW %d", ID, BACKWARDWINDOW);
     bondBeliefFormation(belief, bond,BACKWARDWINDOW,FORWARDWINDOW, RANDOMWEIGHT,FUNDAMENTALWEIGHT, CHARTISTWEIGHT, BINS , CURRENTDAY, HOLDINGPERIODTOFORWARDW,  LOSSAVERSION);
     //printf("ricevuto bond shares=%d quantity=%d\n",bond->nr_outstanding,bond->quantity);
     cinfo_bond= get_next_info_bond_message(cinfo_bond);
     i++;
    }
    
    if (PRINT_DEBUG) printf("\n Household_bond_beliefs_formation ID: %d",ID);
    
    
return 0;
}


int totalassetsowned()
  { Asset_array *assets;
    assets =get_assetsowned();
    return totalassets(assets);
  }
int Household_does_not_trading()
 {return 0;
 }
                      
//int Household_receive_info_asset_from_firm(){return 0;}
int Household_receive_info_interest_from_bank() {
    START_ACCOUNTINTEREST_MESSAGE_LOOP
       if(accountInterest_message->bank_id == get_bank_id())
          set_risk_free_rate(accountInterest_message->interest);
    FINISH_ACCOUNTINTEREST_MESSAGE_LOOP
    
    if (PRINT_DEBUG)
    {printf("\n Household_receive_info_interest_from_bank ID: %d",ID);
    printf("\n\t RISK_FREE_RATE: %f",RISK_FREE_RATE);
                      }
    
    return 0;
}

int Household_receives_payment_coupons()
   { int index=0;
     int quantity=0;
     Asset *asset;
     Asset_array *assetsowned;
     assetsowned=get_assetsowned();
     
     MONTHLY_BOND_INTEREST_INCOME=0.0; //defined in Statistical_Office//model.xml Household memory
   
   if (PRINT_DEBUG)
      {
       printf("\n Household_receives_payment_coupons ID: %d",ID);
       printf("\n\t PAYMENT_ACCOUNT before: %f",PAYMENT_ACCOUNT);
                   }   
   
     START_PAYMENT_COUPONS_MESSAGE_LOOP 
       index=findCAsset(assetsowned,payment_coupons_message->government_id);
    if(index>=0) 
     {
      asset=elementAtCAsset(assetsowned,index);
      quantity=asset->quantity;
      PAYMENT_ACCOUNT=PAYMENT_ACCOUNT+(quantity*payment_coupons_message->coupon);
      MONTHLY_BOND_INTEREST_INCOME += quantity*payment_coupons_message->coupon;      
     }
     FINISH_PAYMENT_COUPONS_MESSAGE_LOOP
     
      if (PRINT_DEBUG)
      {
       printf("\n\t quantity: %d MONTHLY_BOND_INTEREST_INCOME: %f",quantity,MONTHLY_BOND_INTEREST_INCOME);
       printf("\n\t PAYMENT_ACCOUNT after: %f",PAYMENT_ACCOUNT);
       getchar();
                   }   
     
    return 0;
   }

int Household_revises_expected_portfolio()
   {
    reset_Order_array(&PENDINGORDERS);
    return 0;
   }

