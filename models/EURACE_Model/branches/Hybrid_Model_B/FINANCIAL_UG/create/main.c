//#include "../../header.h"
#include "../my_library_header.h"
#define NUMFIRM  2
#define NUMHOUSE 1010
#define NUMRANDOM 900
#define NUMFUND 50
#define NUMCHAR 60

void initFirm(struct xmachine_memory_Firm *firm,int id, double price)
{  
        firm->earnings = 1001;
	firm->earnings_payout = 1000;
	firm->equity = NUMHOUSE*1000*price;
	firm->current_shares_outstanding = NUMHOUSE*1000;
	firm->id = id;
	firm->current_dividend_per_share = 1;
	init_Stock(&firm->stock);
        initializeStock(&firm->stock,id,price,firm->current_shares_outstanding);
        setStock(&firm->stock, id, price, NUMHOUSE*1000);
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
	//household->consumption_badget = 0.0;
	//household->cash_on_hand = 0.0;
	//household->payment_account = 50000;
	household->forwardWindow =nextBetween( 10 , 60);
	household->backwardWindow = nextBetween( 3 , 10);
	household->bins = nextBetween( 3 , 5);
	household->randomWeight = rW;
	household->fundamentalWeight = fW;
	household->chartistWeight = cW;
	household->holdingPeriodToForwardW = nextBetween( 3 , 6);;
	household->lossaversion = 2.25;
	
        init_Assetsowned(&household->assetsowned);
	return;
}
void initClearingHouse(struct xmachine_memory_Clearinghouse *clearing)
{

	
	clearing->id = 1;
	init_Asset_array(&clearing->assets);
        
	 init_Assetsowned(&clearing->assets);
init_ClearingMechanism(&clearing->clearingmechanism);
	return;
}
void initBank(struct xmachine_memory_Bank *bank)
{
  bank->id = 1;
}
void initGovernment(struct xmachine_memory_Government *government)
{
        government->id=2000;	/**< X-machine memory variable id of type int. */
	government->payment_account=-2000000;	
	//government->day_of_month_to_act;	
	init_Bond(&government->bond);
        initializeBond(&government->bond,2000,NUMHOUSE*100,50,0.02);
	init_Order(&government->pending_order);	
	government->deficit=0;	
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
        struct xmachine_memory_Government government;
     

       //initialization 


        fputs("<states>\n<itno>", file);
        fputs("0",file);
	fputs("</itno>\n", file);

       
         initFirm(&firms[0],0,50);
         write_Firm_agent(file,&firms[0]);
         initFirm(&firms[1],1,100);
         write_Firm_agent(file,&firms[1]);

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
       initGovernment(&government);
       write_Government_agent(file,&government);
fputs("</states>\n" , file);
       fclose(file);
}
       
