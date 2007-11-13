/*********************************
 * Household_ewa_functions.c 
 * Adapted code from  Functions_Financial_market_PortfolioSelectionAlgorithm_Sander_v0.3.c
 * *********************************
 * History:
 * 13/11/07 Mariam: Converting the code into separate agent functions files. 
 *********************************/


#include "header.h"
#include "math.h"
#include "Household_agent_header.h"
#include "my_library_header.h"


/************ Household : Asset market role ************/

/* STEP 1. Updating performance.*/
/* HERE: Household sends message to FA agent with the per-day performance of it's own current rule, */
/* including the total value invested in the asset portfolio (this is needed later on, when another household uses the rule). */
int Household_send_rule_performance_message()
{ 
    /*Get input vars: declare and assign local vars */
    int nr_selected_rule      = get_nr_selected_rule();
    double current_rule_performance = get_current_rule_performance();
    
    rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    add_rule_performance_message(nr_selected_rule, rule_performance,range, x, y, z);

    return 0;
}



/* STEP 2. Obtain information.*/
/* Household reads the message from FA agent with all rule performances. */
int Household_reads_all_performances_messages()
{
  double performances[NRRULES];
  
  all_performances_message = get_first_all_performances_message();
  while(all_performances_message)
  {
    /* Read the message: */
     performances = all_performances_message->performances;

    /* Store in memory: */
    for (i=0; i<NRRULES; i++)
  	{  /// why do you need performances to be an array when only one value is being written?
 	 classifiersystem[i]->performance = performances[i]; //code for structs
 	 classifiersystem->performance[i] = performances[i]; //code for dynamic arrays
	}
	set_classifiersystem(classifiersystem); // check how to set values in structs in FA

    /* Proceed to next message: */
     all_performances_message = get_next_all_performances_message(all_performances_message);
  }
    /*Select a rule: */
    Household_select_rule();
  
    return 0;
}


/* STEP 3. Select a rule.*/
/* Household compares rules, selects a rule according to some internal selection mechanism. */
int Household_select_rule()
{
    int household_id=get_household_id();
    double[] performances=get_performances();
    int selected_rule_number=0;    
    
    // Comparison of the rule performances and computation of selected_rule_number
    // {C-CODE}: EWA Learning
    Household_EWA_learning_rule();

// ************************** START CODE SNIPPET ****************************
    /*Send a request for details of the selected rule: */
    add_rule_details_request_message(household_id, selected_rule_number, range, x, y, z);    
// ************************** END CODE SNIPPET ****************************


    return 0;
}


int Household_EWA_learning_rule();
{
/*
Household's Database of rules:
DBclassifiersystem.nr_rules           : number of rules in the database
DBclassifiersystem.nr_selected_rule   : id of currently used rule
DBclassifiersystem.performances       : array of rule performances
DBclassifiersystem.attractions        : array of rule attractions
DBclassifiersystem.experience         : number of observations

    rule.class = 'rule';
    rule.id = id;
    rule.agent_name = 'AgentID';
    rule.holdingperiod=1;       %Default holding period
    rule.performance = 0;       %total performance in agent population
    rule.counter = 0;           %number of users of the rule
    rule.avgperformance = 0;    %avg. performance
    rule.my_performance = 0;    %performance of agent
    rule.attraction = 1;        %attraction
    rule.choiceprob = 0;        %choice probability 

*/

    ClassifiersystemType agent_classifiersystem=get_agent_classifiersystem();
    int nr_selected_rule=get_nr_selected_rule();
    double[] performances=get_DBclassifiersystem.performances();
    double[] attractions=get_DBclassifiersystem.attractions();
    int experience=get_DBclassifiersystem.experience();
    int experience_old=0;

    int nr_rules=get_DBclassifiersystem.nr_rules();
    int j=0;
    
    //EWA learning parameters:
    EWA_rho=get_EWA_rho();
    EWA_phi=get_EWA_phi();
    EWA_delta=get_EWA_delta();
    EWA_beta=get_EWA_beta();
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j++;j<nr_rules)
    {
        //If rule j is the currently used rule:
        if (j==nr_selected_rule)
        {
            attractions[j] = (EWA_phi*experience_old*attractions[j] + rule_profit[j])/experience;
        }

        //If rule j is not currently used:
        if (j~=nr_selected_rule)
        {
            attractions[j] = (EWA_phi*experience_old*attractions[j] + EWA_delta*rule_profit[j])/experience;
        }
        //Set the attractions in the DBclassifiersystem:
        DBclassifiersystem.attractions[j] = attractions[j];
    }

    //Computing the choice probabilities: multi-logit
    sum_attr = sum(exp(EWA_beta * attractions));
    for j=1:nr_rules
        p(j) = exp(EWA_beta * attractions[j])/sum_attr;
    end;


    //Selecting a strategy according to the prob.dens. function:
    //The cumulative pdf is:
     cpdf = cumsum(p)/sum(p);
    
    //Random number generator:
    //To reset to a different seed each time:
    rand('state',sum(100*clock));
    
    //To use a fixed seed:
    rand('state',123456);
    
    u=rand;
    
    nr_selected_rule=0;
    
    //Case 1: u<F(1)
        if (0<=u & u<cpdf(1))
            nr_selected_rule=1;
        end;
    
    //Case 2: Now travers the cpdf until u >= F(j-1)
    for j=2:nr_rules
        if (cpdf(j-1)<=u & u<cpdf(j))
            nr_selected_rule=j;
            break;
        end;
    end;
    
    //Case 3: u>=F(J)
        if (cpdf(nr_rules)<=u)
            nr_selected_rule=nr_rules;
        end;
    
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule:
    DBclassifiersystem.nr_selected_rule=nr_selected_rule;

    //Output to new DBclassifiersystem:    
    set_DBclassifiersystem(DBclassifiersystem);

    return 0;
}


/* Household reads message from FA agent with the exact details of the selected asset portfolio rule.*/
int Household_read_rule_details_message()
{
    int household_id=get_household_id();
    AssetPortfolioType prescribed_assetportfolio=EmptyPortfolio;
    double prescribed_asset_value=0.0;
    
    rule_details_message = get_first_rule_details_message();
    while(rule_details_message)
    {
       /* Test for correct household_id: We only want to read the message that is personally directed to this household */
        if(household_id == rule_details_request_message->household_id)
        {
            prescribed_assetportfolio = rule_details_message->prescribed_assetportfolio;
            prescribed_asset_value = rule_details_message->prescribed_asset_value;
        }
       rule_details_message = get_next_rule_details_request_message(rule_details_request_message); 
    }
    set_prescribed_assetportfolio(prescribed_assetportfolio);
    set_prescribed_asset_value(prescribed_asset_value);
    
    return 0;
}

/* STEP 4. Apply the selected rule.*/
 /* HERE: The household uses the details of the selected rule to compute its asset allocation.
 * It assigns its asset_budget to firm stocks, firm bonds and government bonds, according to the prescribed portfolio.
 * The prescribed asset portfolio is based on a prescribed_asset_value, which is the most recently
 * invested value in the prescribed_portfolio.
 * The prescribed_asset_value is an argument in the original rule_performance_message send by the household
 * that updated the rule's performance in the FA agent's database.
 * To determine the households target portfolio, we need to multiply the units in the prescribed_portfolio
 * by: asset_budget/prescribed_asset_value.
 *
 * The C-CODE simply consists of copying the selected rule details from the prescribed_assetportfolio
 * to the appropriate memory variables of the household. To compute the actual limit_orders we need
 * to take the difference between the current_assetportfolio and prescribed_assetportfolio. This is done later.
 */

int Household_apply_selected_rule()
{
   AssetPortfolioType current_assetportfolio=get_current_assetportfolio();
   AssetPortfolioType prescribed_assetportfolio=get_prescribed_assetportfolio();
   double prescribed_asset_value = get_prescribed_asset_value();
   double asset_budget = get_asset_budget();
   
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
    nr_assets = ArraySize(prescribed_assetportfolio.firmstocks);

    /* We need to travers through prescribed_asset_portfolio to handle all the assets */
    for (i=0; i<nr_assets; i++)
    {
        firm_id        = prescribed_assetportfolio.firmstocks[i].firm_id;

        /* Computation of the limit price is a function of:*/
        current_price=prescribed_assetportfolio.firmstocks[i].current_price;
        best_ask_price=prescribed_assetportfolio.firmstocks[i].best_ask_price;
        best_bid_price=prescribed_assetportfolio.firmstocks[i].best_bid_price;
 
        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);

    /* Limit quantity: diff between target and current holdings (maximum number of units to trade) */
        limit_quantity = current_assetportfolio.firmstocks[i].nr_units - (prescribed_assetportfolio.firmstocks[i].nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_firm_stock_order_message(household_id, firm_id, limit_price, limit_quantity);
    }
    
/* 2. Firm bond order messages */
    nr_assets = ArraySize(prescribed_assetportfolio.firmbonds);
    for (i=0; i<nr_assets; i++)
    {
        firm_id        = prescribed_assetportfolio.firmbonds[i].firm_id;

        current_price=prescribed_assetportfolio.firmbonds[i].current_price;
        best_ask_price=prescribed_assetportfolio.firmbonds[i].best_ask_price;
        best_bid_price=prescribed_assetportfolio.firmbonds[i].best_bid_price;

        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);
        limit_quantity = current_assetportfolio.firmbonds[i].nr_units - (prescribed_assetportfolio.firmbonds[i].nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_firm_bond_order_message(household_id, firm_id, limit_price, limit_quantity);
    }
    
/* 3. Government bond order messages */
    nr_assets = ArraySize(prescribed_assetportfolio.govbonds);
    for (i=0; i<nr_assets; i++)
    {
        gov_id         = prescribed_assetportfolio.govbonds[i].gov_id;

        current_price=prescribed_assetportfolio.govbonds[i].current_price;
        best_ask_price=prescribed_assetportfolio.govbonds[i].best_ask_price;
        best_bid_price=prescribed_assetportfolio.govbonds[i].best_bid_price;

        limit_price    = set_limit_price(current_price, best_ask_price, best_bid_price);
        limit_quantity = current_assetportfolio.govbonds[i].nr_units - (prescribed_assetportfolio.govbonds[i].nr_units * multfactor);

    /* Sending Limit Order Messages to the AssetMarketAgent */
        add_gov_bond_order_message(household_id, gov_id, limit_price, limit_quantity);
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


