#include "header.h"
#include "my_library_header.h"
#define NUMFIRM  2
#define NUMHOUSE 1100
#define NUMRANDOM 1000
#define NUMFUND 50
#define NUMCHAR 50

void initFirm(struct xmachine_memory_Firm *firm,int id)
{  
        firm->earnings = 1001;
	firm->earnings_payout = 1000;
	firm->equity = NUMHOUSE*1000*50;
	firm->current_shares_outstanding = NUMHOUSE*1000;
	firm->id = id;
	firm->current_dividend_per_share = 0.01;
	init_Stock(&firm->stock);
        initializeStock(&firm->stock,id);
        setStock(&firm->stock, id, 50, NUMHOUSE*1000);
        return;
}

void initHousehold(struct xmachine_memory_Household *household,int id,double rW,double fW,double cW)
 {

	
	household->id = id;
	household->wealth = 0.0;
	init_Belief_array(&household->beliefs);
	init_Order_array(&household->pendingOrders);
	init_Asset_array(&household->assetsowned);
	init_double_array(&household->assetWeights);
	init_double_array(&household->assetUtilities);
	household->payment_account = 50000;
	household->consumption_badget = 0.0;
	household->cash_on_hand = 0.0;
	household->portfolio_badget = 50000;
	household->forwardWindow =nextBetween( 3 , 60);
	household->backwardWindow = nextBetween( 3 , 10);
	household->bins = nextBetween( 3 , 5);
	household->randomWeight = rW;
	household->fundamentalWeight = fW;
	household->chartistWeight = cW;
	household->holdingPeriodToForwardW = 2*(household->forwardWindow);
	household->lossaversion = 2.25;
	
        init_Assetsowned(&household->assetsowned);
	return;
}
void initClearingHouse(struct xmachine_memory_Clearinghouse *clearing)
{

	
	clearing->id = 1;
	init_Asset_array(&clearing->assets);
	 init_Assetsowned(&clearing->assets);
	return;
}
void initBank(struct xmachine_memory_Bank *bank)
{
  bank->id = 1;
}

int main()
  {    

       FILE *file;
       int i;
       file = fopen("0.xml", "w");
       struct xmachine_memory_Firm    firms[NUMFIRM];
       struct xmachine_memory_Household    households[NUMHOUSE];
        struct xmachine_memory_Clearinghouse clearinghouse;
       struct xmachine_memory_Bank bank;
     

       //initialization 


        fputs("<states>\n<itno>", file);
        fputs("0",file);
	fputs("</itno>\n", file);

       for(i=0;i<NUMFIRM;i++)
        {
         initFirm(&firms[i],i);
         write_Firm_agent(file,&firms[i]);
        }
       for(i=0;i<NUMRANDOM;i++)
        {
         initHousehold(&households[i],i,1,0,0);
         write_Household_agent(file,&households[i]);
        }
       
        for(i=NUMRANDOM;i<NUMRANDOM+NUMFUND;i++)
        {
         initHousehold(&households[i],i,0,1,0);
         write_Household_agent(file,&households[i]);
        }
        for(i=NUMRANDOM+NUMFUND;i<(NUMRANDOM+NUMCHAR+NUMFUND);i++)
        {
         initHousehold(&households[i],i,0,0,1);
         write_Household_agent(file,&households[i]);
        }
       initClearingHouse(&clearinghouse);
       write_Clearinghouse_agent(file,&clearinghouse);
             
       initBank(&bank);
       write_Bank_agent(file,&bank);
fputs("</states>\n" , file);
       fclose(file);
}
       
