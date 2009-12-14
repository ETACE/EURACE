#include "../header.h"
#include "../Central_Bank_agent_header.h"
#include "my_library_header.h"


int CB_receives_info_bond(void)
{    
     Bond *bond;   
     double last_market_price;
     int j;
        
     START_INFO_BOND_MESSAGE_LOOP 
     bond = &(info_bond_message->bond);
     
   //  printf("\n CB_receives_info_bond. ID: %d face_value: %f",bond->id,bond->face_value);
     last_market_price = bond->prices[bond->index];
   //  printf("\n CB_receives_info_bond. bond->index: %d last_market_price: %f",bond->index,last_market_price);
     
     for(j = 0; j < NEW_BONDS_GOV_ID.size; j++)
        {
    //        printf("\n bond->id: %d NEW_BONDS_GOV_ID.array[j]: %d",bond->id,NEW_BONDS_GOV_ID.array[j]);
            if (bond->id==NEW_BONDS_GOV_ID.array[j])
            {
            NEW_BONDS_LAST_PRICE.array[j] = last_market_price;
   //         printf("\n CB_receives_info_bond. NEW_BONDS_LAST_PRICE.array: %f",NEW_BONDS_LAST_PRICE.array[j]);
            }
        }    
        
    
     
     FINISH_INFO_BOND_MESSAGE_LOOP 
 
     return 0;
}

int CB_issues_orders(void)
{    
     
     if (QE_POLICY==1)
     {
     int j;
     int diluition_coefficient;

          if ((CURRENTDAY%DAYS_PER_MONTH)==0)
             diluition_coefficient = 1;
          else
             diluition_coefficient = DAYS_PER_MONTH-(CURRENTDAY%DAYS_PER_MONTH)+1;
     
          for(j = 0; j < NEW_BONDS_GOV_ID.size; j++)
           {
              if (NEW_BONDS_QUANTITY.array[j]>0)
              add_order_message(ID,NEW_BONDS_GOV_ID.array[j], NEW_BONDS_LAST_PRICE.array[j],NEW_BONDS_QUANTITY.array[j]/diluition_coefficient);
           }       
      }
     return 0;
}

int CB_receives_order_status(void)
{    
    int j;
    FILE *file1=NULL;
    char * filename="";
    
   
    START_ORDER_STATUS_MESSAGE_LOOP
    
    if(order_status_message->trader_id==ID) 
      { 
      FIAT_MONEY_GOVS += order_status_message->price*order_status_message->quantity;
      FIAT_MONEY      += order_status_message->price*order_status_message->quantity;  
      
       for(j = 0; j < NEW_BONDS_GOV_ID.size; j++)
       {
           if (order_status_message->asset_id==NEW_BONDS_GOV_ID.array[j])
           {
            NEW_BONDS_QUANTITY.array[j] -= order_status_message->quantity;                               
            GOV_BONDS_HOLDING.array[j] += order_status_message->quantity;          
            }
       }        
       
       if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Centra_Bank_QE_trading.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f",CURRENTDAY,order_status_message->quantity,order_status_message->price);
            fclose(file1);
            free(filename);
        } 
                      
       }
       
      
    
    FINISH_ORDER_STATUS_MESSAGE_LOOP
    
    
      if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/Centra_Bank_QE_after.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %d %f",CURRENTDAY,NEW_BONDS_QUANTITY.array[0],GOV_BONDS_HOLDING.array[0], FIAT_MONEY_GOVS);
            fclose(file1);
            free(filename);
        } 
         
     return 0;
}
