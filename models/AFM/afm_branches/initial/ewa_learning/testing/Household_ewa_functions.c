/*********************************
 * Household_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"
#include "Household_agent_header.h"
#include "mylibraryheader.h"


/************ Household : Asset market role ************/

/* STEP 1. Updating performance.*/
/* HERE: Household sends message to FA agent with the per-day performance of it's own current rule, */
/* including the total value invested in the asset portfolio (this is needed later on, when another household uses the rule). */
int Household_send_rule_performance_message()
{ 
    //Declare and assign local vars
    int current_rule = CLASSIFIERSYSTEM->current_rule;
    
    //Here we compute the rule performance: this function uses the performance_history
    //since performance is computed as a time-average of capital gains obtained by the
    //current financial investment strategy. 
    
    //rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    
    //Random performance (uses the function random_unif())
    rule_performance = random_unif()*100;
    
    add_rule_performance_message(current_rule, rule_performance, range, x, y, z);

    return 0;
}



/* STEP 2. Obtain information.*/
/* Household reads all_performances_message from FA
 * Updates classifiersystem
 * Stores classifiersystem in memory
 */
int Household_read_all_performances_message()
{
      double * all_performances;
      
      all_performances_message = get_first_all_performances_message();
      while(all_performances_message)
      {
        //Read the message
        //code for dynamic arrays, copies the elements one by one
        for (i=0; i<NRRULES; i++)
        {
         // Store in memory:              
         CLASSIFIERSYSTEM->array[i]->performance = all_performances[i];
        }
        
        //Proceed to next message
         all_performances_message = get_next_all_performances_message(all_performances_message);
      }
 
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
    int current_rule = CLASSIFIERSYSTEM->current_rule;   
    int NRRULES = CLASSIFIERSYSTEM->nr_rules;
    
    double[] performance;
    double[] attraction;

    int experience      = CLASSIFIERSYSTEM->experience;
    int experience_old = 0;
    int i,j=0;

    //Rule selection
    double sum_attr = 0;
    double[NRRULES] cpdf;
    
    
    //Assign values to local dynamic arrays
    for (i=0;i<NRRULES;i++)
    {
        performance[i] = CLASSIFIERSYSTEM->array[i]->performance;
        attraction[i]  = CLASSIFIERSYSTEM->array[i]->attraction;
    }
    
    //EWA learning parameters:
    double EWA_rho=CLASSIFIERSYSTEM->EWA_rho;
    double EWA_phi=CLASSIFIERSYSTEM->EWA_phi;
    double EWA_delta=CLASSIFIERSYSTEM->EWA_delta;
    double EWA_beta=CLASSIFIERSYSTEM->EWA_beta;
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j++;j<NRRULES)
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
        CLASSIFIERSYSTEM->array[j]->attraction = attraction[j];
    }
    
    //Computing the choice probabilities: multi-logit
    sum_attr=0;
    for (j=0;j++;j<NRRULES)
    {
        sum_attr += math.exp(EWA_beta * attractions[j]);
    }
    
    for (j=0;j++;j<NRRULES)
    {
        p[j] = math.exp(EWA_beta * attractions[j])/sum_attr;
    }

    //Construct cumm. prob. dens. function
    cpdf = cumpdf(p);
    
    //Selecting a strategy according to the pdf:
    nr_selected_rule = draw_with_replacement(1, cpdf, NRRULES);
    
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule in memory (0-indexed):
    CLASSIFIERSYSTEM->current_rule = nr_selected_rule - 1;

    return 0;
}

/* Household_retrieve_rule_details()
 * Retrieve rule details
 * Copying the selected rule details to the appropriate memory variables of the household. 
 */
int Household_retrieve_rule_details()
{
    //#include <string.h>
    //To use:   char *strcat( char *str1, const char *str2 );
    //          char *strcpy( char *to, const char *from );
    int rule_type;
    double* param_vector;
    int imax;
    char* str, new_str, param_vector_as_string;
    
    //Rule details:
    rule_type = RULEDETAILSYSTEM->rule_type[i]

    //Execute the rule's functioncall, with the appropriate parameter setting
    //Parameters: retrieve the list of parameter values for the current rule
    //Since parameter is double array, we have as prototype 
    //int rule_function_1(* double var_name)

    switch (rule_type)
    {
        case 1: rule_functioncall_1(RULEDETAILSYSTEM->parameters->array[1]);
        break;
        
        case 2: rule_functioncall_2(RULEDETAILSYSTEM->parameters->array[2]);
        break;
    
        case 3: rule_functioncall_3(RULEDETAILSYSTEM->parameters->array[3]);
        break;
    
        default;
    }

    return 0;
}


 /* STEP 4. Apply the selected rule.
 *The household uses the details of the selected rule to compute its new asset allocation.
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
int Household_read_transaction_message()
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
 
//Household_read_and_update_ruledetailsystem_message()
//Reads and updates a new rule_detail_system.
//Used by agents to refresh their rule detail system.
int Household_read_and_update_ruledetailsystem_message()
{
    //In Classifiersystem we store the size settings:

	//Getting the size of the system:
    int NR_TYPES=CLASSIFIERSYSTEM->nr_types;

    //total number of rules:
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;

    //dynamic array with number of rules in each type (size of subsets of rules)
    int[NR_TYPES] nr_rules_per_type; //this requires a malloc
        
    //In Ruledetailsystem we store the parameter settings:
    int[NR_TYPES] nr_params_per_type; //this requires a malloc
    
    //Local vars:
    int[NRRULES]        ids;
    int[NRRULES]        nr_params;
    int MAX_PARAMS; 
   
    char*               rule_function_call; //string
    int[NRRULES]        rule_type;          //rule_type indicator
    
    word_array *        my_function_names = get_my_function_names(); //list of function names
    
    int                 i,j,k,m,jmax=0;

    //Setting nr_rules for each type
    for (i=0; i<NR_TYPES; i++)
    {
    	nr_rules_per_type[i]=CLASSIFIERSYSTEM->nr_rules_per_type[i];
    }

    //Setting nr_params for each type
    for (i=0; i<NR_TYPES; i++)
    {
    	nr_params_per_type[i]=RULEDETAILSYSTEM->nr_params_per_type[i];
    }
    
    //Only at this point can we allocate size for the paramater vector
    MAX_PARAMS = max(nr_params_per_type); //max function gives max of a vector
    
    double[NRRULES][MAX_PARAMS] parameter;   //this requires a malloc

    
    //HERE: We need a local copy of the contents of the ruledetailsystem_message
    //because we need to copy it from the message before storing it in memory.
    
    //Reading the ruledetailsystem_message
    ruledetailsystem_message = get_first_ruledetailsystem_message();
    while(ruledetailsystem_message)
    {
     
        //Reading the contents of the message one rule at a time
        for (i=0; i<NRRULES; i++)
        {
            //Filling the double_array parameter[i] with the parameter values of rule i
            jmax=nr_params[i];
            
            for (j=0; j<jmax; j++)
            {
                //Filling the field parameters[i][j]
                  parameters[i][j] = ruledetailsystem_message->parameters[i][j];
            }
        }
                
        //Proceed to next message
        ruledetailsystem_message = get_next_ruledetailsystem_message(ruledetailsystem_message);
    }
    
    //After copying the message contents to the local variable, we store it in memory
    for (i=0; i<NRRULES; i++)
    {
        jmax=nr_params[i];
        
        for (j=0; j<jmax; j++)
        {
            //Filling the field parameters[i][j]
             RULEDETAILSYSTEM->parameters[i][j] = parameters[i][j];
        }
    }
    
    return 0;
}

int Household_reset_private_classifiersystem()
{
    //total number of rules:
    int NRRULES=CLASSIFIERSYSTEM->nr_rules;

    //Resetting and storing values to memory:
    CLASSIFIERSYSTEM->experience=0;
    CLASSIFIERSYSTEM->current_rule=0;
    CLASSIFIERSYSTEM->my_performance=0;

    for (i=0; i<NRRULES; i++)
    {
        CLASSIFIERSYSTEM->avgperformance[i]=log(pow(10,-5));
        CLASSIFIERSYSTEM->attraction[i]=log(pow(10,-5));
        CLASSIFIERSYSTEM->choiceprob[i]=pow(10,-5);
    }

    return 0;
} 