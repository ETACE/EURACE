/*********************************
 * Household_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 29/02/08 Sander: Converted code to use . instead of -> for structs.
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "Household_agent_header.h"
#include "mylibraryheader.h"

#define NR_PARAMS 10

/************ Household : Asset market role ************/

/* STEP 1. Updating performance.*/
/* HERE: Household sends message to FA agent with the per-day performance of it's own current rule, */
/* including the total value invested in the asset portfolio (this is needed later on, when another household uses the rule). */
int Household_send_rule_performance()
{ 
    //Declare and assign local vars
    int current_rule = CLASSIFIERSYSTEM.current_rule;
    
    //Here we compute the rule performance: this function uses the performance_history
    //since performance is computed as THE time-average of capital gains obtained by the
    //current financial investment strategy. 
    
    //rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    
    //Random performance (uses the function random_unif())
    rule_performance = random_unif()*100;
    
    add_rule_performance_message(current_rule, rule_performance, range, x, y, z);

    return 0;
}

/* STEP 2. Obtain information.*/
/* Household reads all_performances_message from FA
 * Updates the classifiersystem
 */
int Household_read_all_performances()
{
	int rule_index;
	
	//Read the messages: copies the elements one by one	
      START_NEW_PERFORMANCES_MESSAGE_LOOP
      	 rule_index=new_performances_message->rule_id;
         CLASSIFIERSYSTEM.array[rule_index].avg_performance = new_performances_message->avg_performance;
      FINISH_NEW_PERFORMANCES_MESSAGE_LOOP
 
    return 0;
}


/* STEP 3. Select a rule.*/
/*
 * int Household_select_rule()
 * Was: Household_EWA_learning()
 * updates attractions
 * updates choice probabilities
 * selects a new rule
 * outputs the selected rule to memory
 * outputs the new classifier system to memory
 */
int Household_select_rule()
{
    int current_rule = CLASSIFIERSYSTEM.current_rule;   
    int nr_rules = CLASSIFIERSYSTEM.nr_rules;
    
    double[] performance;
    double[] attraction;

    int experience     = CLASSIFIERSYSTEM.experience;
    int experience_old = 0.0;
    int i,j=0;

    //Rule selection
    double sum_attr = 0;
    double * cpdf;
    
    //Assign values to local dynamic arrays
    for (i=0;i<nr_rules;i++)
    {
        performance[i] = CLASSIFIERSYSTEM.array[i].avg_performance;
        attraction[i]  = CLASSIFIERSYSTEM.array[i].attraction;
    }
    
    //EWA learning parameters:
    double EWA_rho=EWA_PARAMETERS.EWA_rho;
    double EWA_phi=EWA_PARAMETERS.EWA_phi;
    double EWA_delta=EWA_PARAMETERS.EWA_delta;
    double EWA_beta=EWA_PARAMETERS.EWA_beta;
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j<nr_rules;j++)
    {
        //If rule j is the currently used rule:
        if (j==current_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + performance[j])/experience;
        }

        //If rule j is not currently used:
        if (j~=current_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + EWA_delta*performance[j])/experience;
        }
        //Set the attractions in the classifiersystem:
        CLASSIFIERSYSTEM.array[j].attraction = attraction[j];
    }
    
    //Computing the choice probabilities: multi-logit
    sum_attr=0;
    for (j=0;j++;j<nr_rules)
    {
        sum_attr += math.exp(EWA_beta * attractions[j]);
    }
    
    for (j=0;j++;j<nr_rules)
    {
        p[j] = math.exp(EWA_beta * attractions[j])/sum_attr;
    }

    //Construct cumulative probability density function: cpdf
    cpdf = malloc(sizeof((double)*nr_rules);
    cumpdf(p, nr_rules, cpdf);
    
    //Selecting a strategy according to the pdf:
    nr_selected_rule = draw_with_replacement(1, cpdf, nr_rules);
    
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule in memory (0-indexed):
    CLASSIFIERSYSTEM.current_rule = nr_selected_rule - 1;

    return 0;
}

 /* STEP 4. Apply the selected rule.
 * The household uses the details of the selected rule to compute its new asset allocation.
 * It assigns its asset_budget to firm stocks, firm bonds and government bonds, according to the rule's
 * prescribed asset portfolio. To determine the households target portfolio, we need to take the 
 * difference between the current_assetportfolio and prescribed_assetportfolio. This is done later. 
 * If the prescribed_portfolio is based on a prescribed_asset_value then  we have to multiply the units
 * in the prescribed_portfolio by: asset_budget/prescribed_asset_value.
 */

/* Household_apply_rule()
 * Apply a rule.
 * To compute the actual limit_orders we need to apply the rule to obtain the prescribed_assetportfolio.
 */
int Household_apply_rule()
{

   //Can be replaced with direct memory access:
   //AssetPortfolioType * current_assetportfolio=get_current_assetportfolio();
   //AssetPortfolioType * prescribed_assetportfolio=get_prescribed_assetportfolio();
   //double prescribed_asset_value = get_prescribed_asset_value();
   //double asset_budget = get_asset_budget();
   
   double multfactor= 0.0;
   int nr_assets=0;
   int firm_id=0;
   int gov_id=0;
   double current_price=0.0;
   double best_ask_price=0.0;
   double best_bid_price=0.0;
   double limit_price=0.0;    
   int limit_quantity=0;
   
   /*Multiplication factor*/
   multfactor=asset_budget/prescribed_asset_value;
   
    /* 1. Firm stock order messages */
    nr_assets = prescribed_assetportfolio->firmstocks->size;// checkcode after compiling!

    /* We need to travers through prescribed_asset_portfolio to handle all the assets */
    for (i=0; i<nr_assets; i++)
    {
        firm_id = prescribed_assetportfolio->array[i]->firm_id;

        /* Computation of the limit price is a function of:*/
        current_price=prescribed_assetportfolio->array[i]->current_price;
        best_ask_price=prescribed_assetportfolio->array[i]->best_ask_price;
        best_bid_price=prescribed_assetportfolio->array[i]->best_bid_price;
 
        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);

    /* Limit quantity: diff between target and current holdings (maximum number of units to trade) */
        limit_quantity = current_assetportfolio->array[i]->nr_units - (prescribed_assetportfolio->array[i]->nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_firm_stock_order_message(household_id, firm_id, limit_price, limit_quantity,range,x,y,z);
    }
    
/* 2. Firm bond order messages */
    nr_assets = prescribed_assetportfolio->firmbonds->size;
    for (i=0; i<nr_assets; i++)
    {
        firm_id        = prescribed_assetportfolio->array[i]->firmbonds_firm_id;

        current_price=prescribed_assetportfolio->array[i]->firmbonds_current_price;
        best_ask_price=prescribed_assetportfolio->array[i]->firmbonds_best_ask_price;
        best_bid_price=prescribed_assetportfolio->array[i]->firmbonds_best_bid_price;

        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);
        limit_quantity = current_assetportfolio->array[i]->firmbonds_nr_units - (prescribed_assetportfolio->array[i]->firmbonds_nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_firm_bond_order_message(household_id, firm_id, limit_price, limit_quantity,range,x,y,z);
    }
    
/* 3. Government bond order messages */
    nr_assets = prescribed_assetportfolio->govbonds->size;
    for (i=0; i<nr_assets; i++)
    {
        gov_id     = prescribed_assetportfolio->array[i]->govbonds_gov_id;

        current_price=prescribed_assetportfolio->array[i]->govbonds_current_price;
        best_ask_price=prescribed_assetportfolio->array[i]->govbonds_best_ask_price;
        best_bid_price=prescribed_assetportfolio->array[i]->govbonds_best_bid_price;

        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);
        limit_quantity = current_assetportfolio->array[i]->govbonds_nr_units - (prescribed_assetportfolio->array[i]->govbonds_nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_gov_bond_order_message(household_id, gov_id, limit_price, limit_quantity,range,x,y,z);
    }

    return 0;
}


/* HERE: The household reads the transaction messages send by the Asset Market Agent*/
int Household_read_transaction()
{

/* 1. Reading all firm_stock_transaction_messages: */
 /* firm_stock_transaction_message = get_first_firm_stock_transaction_message()
 * while(firm_stock_transaction_message)
 * {
 *    if (firm_stock_transaction_message->household_id==household_id)
 *    {
 *      firm_id = firm_stock_transaction_message->firm_id;
 *      transaction_price = firm_stock_transaction_message->transaction_price;
 *      transaction_quantity = firm_stock_transaction_message->transaction_quantity; 
 *
 *      {ADD C-CODE TO PROCESS THE TRANSACTION: UPDATE STOCKS, UPDATE SAVINGS}
 *    }
 *    firm_stock_transaction_message = get_next_firm_stock_transaction_message(firm_stock_transaction_message)
 * }
*/
/* 2. Reading all firm_bond_transaction_messages: */
/* firm_bond_transaction_message = get_first_firm_bond_transaction_message()
 * while(firm_bond_transaction_message)
 * {
 *    if (firm_bond_transaction_message->household_id == household_id)
 *    {
 *      firm_id = firm_bond_transaction_message->firm_id;
 *      transaction_price = firm_bond_transaction_message->transaction_price;
 *      transaction_quantity = firm_bond_transaction_message->transaction_quantity; 
 *
 *      {ADD C-CODE TO PROCESS THE TRANSACTION: UPDATE STOCKS, UPDATE SAVINGS}
 *    }
 *    firm_bond_transaction_message = get_next_firm_bond_transaction_message(firm_bond_transaction_message)
 * }
*/
/* 3. Reading all gov_bond_transaction_messages: */
 /* gov_bond_transaction_message = get_first_gov_bond_transaction_message()
 * while(gov_bond_transaction_message)
 * {
 *    if (gov_bond_transaction_message->household_id == household_id)
 *    {
 *      gov_id = gov_bond_transaction_message->firm_id;
 *      transaction_price = gov_bond_transaction_message->transaction_price;
 *      transaction_quantity = gov_bond_transaction_message->transaction_quantity; 
 *
 *      {ADD C-CODE TO PROCESS THE TRANSACTION: UPDATE STOCKS, UPDATE SAVINGS}
 *    }
 *
 *    gov_bond_transaction_message = get_next_gov_bond_transaction_message(gov_bond_transaction_message)
 * }
*/
    return 0;
}

 
//Household_read_and_update_rule_details()
//Function to download new rule details.
//Used by agents to refresh their rule detail system.
//We allow for changes in the rule parameters that occur due to crossover, mutation.
int Household_read_and_update_rule_details()
{
    //Getting the size of the system:
    //int NR_TYPES=CLASSIFIERSYSTEM.nr_types;

    //Dynamic array with number of rules in each type (size of subpopulations)
    //int NRRULES_PER_TYPE[NR_TYPES];
	//NRRULES_PER_TYPE[i]=CLASSIFIERSYSTEM.array[i].nr_rules_per_type;

    int i,rule_id=0;
   
    //Reading the rule_details_message
    START_RULE_DETAILS_MESSAGE
	    rule_id = new_rule_details_message->rule_id;
	    
    	//Filling the double array parameters[i] with the parameter values
		for (i=0; i<NR_PARAMS; i++)
		{
			//Filling the fields of the rule with parameters[i]
			CLASSIFIERSYSTEM.rule_table.array[rule_id].parameters[i] = new_rule_details_message->parameters[i];
		}
    FINISH_RULE_DETAILS_MESSAGE
    
    return 0;
}

int Household_reset_private_classifiersystem()
{
    //Getting the size of the system:
    //int NR_TYPES=CLASSIFIERSYSTEM.NR_TYPES;

    //dynamic array with number of rules in each type (size of subpopulations)
    //int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM.NRRULES_PER_TYPE;

    //Total number of rules:
    int nr_rules=CLASSIFIERSYSTEM.nr_rules;

    //Resetting and storing values to memory:
    CLASSIFIERSYSTEM.experience=0.0;
    CLASSIFIERSYSTEM.current_rule=0;

    for (i=0; i<nr_rules; i++)
    {
    	CLASSIFIERSYSTEM.array[i].my_performance=0.0;
    	CLASSIFIERSYSTEM.array[i].avg_performance=log(pow(10,-5));
        CLASSIFIERSYSTEM.array[i].attraction=log(pow(10,-5));
        CLASSIFIERSYSTEM.array[i].choiceprob=pow(10,-5);
    }

    return 0;
} 