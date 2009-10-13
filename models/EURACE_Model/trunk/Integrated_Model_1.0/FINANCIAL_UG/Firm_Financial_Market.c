#include "../header.h"
#include "../Firm_agent_header.h"
#include "my_library_header.h"

int Firm_send_info(void)
{    double earnings_exp;
     double earnings_payout_exp;
     Stock *stock;
     stock=get_stock();
     double dividend;
     
     //Use memory vars from financial management
     dividend=CURRENT_DIVIDEND_PER_SHARE;
     earnings_exp = EARNINGS;
     earnings_payout_exp = TOTAL_DIVIDEND_PAYMENT;
     
     if(ACTIVE==0)
     {
        printf("\n ID=%d, earnings_exp=%f,  dividend=%f, earnings_payout_exp=%f,  EQUITY=%f\n",ID, earnings_exp,  dividend, earnings_payout_exp,  EQUITY);
        
        if (EQUITY<0.0)
            printf("\n In Firm_send_info: EQUITY NEGATIVE\n");
     }
     
     add_info_firm_message(ID, earnings_exp,  dividend, earnings_payout_exp,  EQUITY, STOCK);
     
    return 0;
}



int Firm_receive_stock_info(void)
{  
     FILE *file1;
     char *filename;
   
    Stock *stock;
   stock =get_stock();
  
   START_INFOASSETCH_MESSAGE_LOOP
       if(ID==infoAssetCH_message->asset_id) 
          {  
             CURRENT_SHARE_PRICE = infoAssetCH_message->price;
             addPriceStock(stock,CURRENT_SHARE_PRICE);
             
          }
   FINISH_INFOASSETCH_MESSAGE_LOOP
  // printf("questo viene eseguito tran%d\n",ID);
  
  if (PRINT_DEBUG_FILE_EXP1)
        {
            filename = malloc(40*sizeof(char));
            filename[0]=0;
            strcpy(filename, "its/stock_prices.txt"); 
            file1 = fopen(filename,"a");
            fprintf(file1,"\n %d %d %f",CURRENTDAY,ID,CURRENT_SHARE_PRICE);
            fclose(file1);
            free(filename);
        }
   
   return 0;
}

