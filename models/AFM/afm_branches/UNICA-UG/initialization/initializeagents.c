#include "init.h"
int inc;
inc=0;
void initializeEnvironment()
{
 rnd=newRandom();
}	
void initializeEurostat_agent(xmachine ** agent_list,double cloud_data[6], int flag)

 {
    
 CAsset * assets;
 double posx;
 double posy;


	assets = newAssetsTotal(1000*1000);;
	posx = 0.0;
	posy = 0.0;

       
    /* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Eurostat_agent(assets, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_Eurostat_agent(assets, posx, posy);
					}
}
	
void initializeHousehold_agent(xmachine ** agent_list,double cloud_data[6], int flag)

 {
    
 int id;
 double wealth;
 Belief * belief;
 Portfolio * portfolio;
 COrder * pendingOrders;
 CAsset * assetsowned;
 double posx;
 double posy;


	id = inc++;
	wealth = 0.0;
	belief = newBelief(); 
	portfolio =newPortfolio();setBankAccount(portfolio,100000);
	pendingOrders = newCOrder(10);
	assetsowned = newAssetsOwned();
	posx = 0.0;
	posy = 0.0;

       
    /* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_Household_agent(id, wealth, belief, portfolio, pendingOrders, assetsowned, posx, posy);
					}
}
	
void initializeClearingHouse_agent(xmachine ** agent_list,double cloud_data[6], int flag)

 {
    
 int id;
 CAsset * assets;
 double posx;
 double posy;


	id = inc++;
	assets = newAssetsTotal(1000*1000);
	posx = 0.0;
	posy = 0.0;

       
    /* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						add_ClearingHouse_agent(id, assets, posx, posy);
        				/* Update the cloud data */
                        if ( posx < cloud_data[0]) cloud_data[0] = posx ;
                        if ( posx > cloud_data[1]) cloud_data[1] = posx ;
                        if ( posy < cloud_data[2]) cloud_data[2] = posy ;
                        if ( posy > cloud_data[3]) cloud_data[3] = posy ;
                        if ( 0.0 < cloud_data[2]) cloud_data[4] = 0.0 ;
                        if ( 0.0 > cloud_data[3]) cloud_data[5] = 0.0 ;
					}
					else if (
					    ((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
					    ((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
					    ((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
					    ((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
					    ((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && 0.0 >= current_node->partition_data[4])) &&
					    ((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && 0.0 < current_node->partition_data[5]))
					)
					{
					    p_xmachine = &(current_node->agents);
					    add_ClearingHouse_agent(id, assets, posx, posy);
					}
}


void initialstates(xmachine ** agent_list, double cloud_data[6], int flag)
{   xmachine **p_xmachine;
    node_information temp_node;
    p_xmachine = agent_list;
   int i;

  cloud_data[0] = SPINF; cloud_data[1] = -SPINF;
  cloud_data[2] = SPINF; cloud_data[3] = -SPINF;
  cloud_data[4] = SPINF; cloud_data[5] = -SPINF;
  if (flag == 0) current_node = &temp_node;

initializeEnvironment();

for(i=0;i<1;i++)
 initializeEurostat_agent(agent_list,cloud_data, flag);

for(i=0;i<1000;i++)
 initializeHousehold_agent(agent_list,cloud_data, flag);

for(i=0;i<1;i++)
 initializeClearingHouse_agent(agent_list,cloud_data, flag);

}
