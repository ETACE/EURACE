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
    int nr_selected_rule = get_nr_selected_rule();
    double current_rule_performance = get_current_rule_performance();
    
    //Here we compute the rule performance: this function uses the performance_history
    //since performance is computed as a time-average of capital gains obtained by the
    //current financial investment strategy. 
    
    //rule_performance = calc_rule_performance(current_assetportfolio->performance_history);
    
    //Random performance (uses the function random_no() from financial_management.c)
    rule_performance = random_no()*100;
    
    add_rule_performance_message(nr_selected_rule, rule_performance, range, x, y, z);

    return 0;
}



/* STEP 2. Obtain information.*/
/* Household reads the message from FA agent with all rule performances. */
int Household_read_all_performances_message()
{
 	double all_rule_performances[NRRULES];
    PrivateClassifierSystem * classifiersystem = get_agent_classifiersystem();
    int nr_selected_rule = classifiersystem->nr_selected_rule;
  
  all_performances_message = get_first_all_performances_message();
  while(all_performances_message)
  {
    /* Read the message: */
     all_rule_performances = all_performances_message->performances;

    /* Store in memory: */
    for (i=0; i<NRRULES; i++)
  	{
  	 // why do you need performances to be an array when only one value is being written?
 	 // Performances is the variable in the message that is coming from FA
 	 // So this is the array with the performances of ALL rules
 	 // Can we copy arrays instantaneously? I thought we need to loop over the elements. 
 	  
 	 classifiersystem->performance[i] = all_rule_performances[i]; //code for dynamic arrays, copies the elements one by one
	
	}

	set_classifiersystem(classifiersystem); // check how to set values in structs in FA

    /* Proceed to next message: */
     all_performances_message = get_next_all_performances_message(all_performances_message);
  }
 
    return 0;
}


/* STEP 3. Select a rule.*/
/* Household_select_rule()
 * Household compares rules, selects a rule according to choice probabilities.
 */
int Household_select_rule()
{
    int household_id=get_household_id();
    double[] performances=get_performances();// performances is part of a struct?
    int selected_rule_number=0;    
    
    //Comparison of rule performances and selection
    Household_EWA_learning();
	
    return 0;
}

/* Household_EWA_learning()
 * updates attractions
 * updates choice probabilities
 * selects a new rule
 * outputs the selected rule to memory
 * outputs the new classifier system to memory
 */
int Household_EWA_learning()
{

    PrivateClassifierSystem * agent_classifiersystem= get_agent_classifiersystem();
    int nr_selected_rule	= agent_classifiersystem->.nr_selected_rule;
    // i think we need to call a for loop here to copy values here
    double[] performance = agent_classifiersystem->performance[];
    double[] attraction = agent_classifiersystem->attraction[];
    //for dynamic array :test_datatype_1_var_dynamic_array->array[5]->int_datatype_var;
    int experience	= agent_classifiersystem->experience;
    int experience_old			= 0;


    int j=0;
    
    
    //EWA learning parameters:
    double EWA_rho=get_EWA_rho();
    double EWA_phi=get_EWA_phi();
    double EWA_delta=get_EWA_delta();
    double EWA_beta=get_EWA_beta();
  
    //Updating the experience weight
    experience_old=experience;
    experience=EWA_rho*experience + 1;

    //Updating the attractions
    for (j=0;j++;j<NRRULES)
    {
        //If rule j is the currently used rule:
        if (j==nr_selected_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + performance[j])/experience;
        }

        //If rule j is not currently used:
        if (j~=nr_selected_rule)
        {
            attraction[j] = (EWA_phi*experience_old*attraction[j] + EWA_delta*performance[j])/experience;
        }
        //Set the attractions in the DBclassifiersystem:
        agent_classifiersystem->attraction[j] = attraction[j];
    }
	//Computing the choice probabilities: multi-logit
    double sum_attr = 0;
    for (j=0;j++;j<NRRULES)
    {
        sum_attr += math.exp(EWA_beta * attractions[j]);
	}
    
    for (j=0;j++;j<NRRULES)
    {
        p[j] = math.exp(EWA_beta * attractions[j])/sum_attr;
	}
// *********** WARNING: MATLAB CODE BELOW ****************************

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
    for j=2:NRRULES
        if (cpdf(j-1)<=u & u<cpdf(j))
            nr_selected_rule=j;
            break;
        end;
    end;
    
    //Case 3: u>=F(J)
        if (cpdf(NRRULES)<=u)
            nr_selected_rule=NRRULES;
        end;
    
    //Test if a rule has been selected:
    if(nr_selected_rule==0)
        printf('Error in EWA learning: No rule selection from choice probabilities');
    end;
    
    //Set the selected rule:
    agent_classifiersystem.selected_rule=nr_selected_rule;

    //Output to new agent_classifiersystem:    
    set_agent_classifiersystem(agent_classifiersystem);

    return 0;
}

/* Household_retrieve_rule_details()
 * Retrieve rule details
 * Copying the selected rule details to the appropriate memory variables of the household. 
 */
int Household_retrieve_rule_details()
{
	//#include <string.h>
	//To use: 	char *strcat( char *str1, const char *str2 );
	//			char *strcpy( char *to, const char *from );



	//Does this work in this way? Ans: No need to create local copy. Can use directly.
	//PrivateClassifierSystem classifiersystem=CLASSIFIERSYSTEM;

	double* param_vector;
	char*	functioncall; 
	int	imax;
	char* str, new_str, param_vector_as_string;
	
	//Rule details:
	//The name of the rule
	functioncall = AGENT_CLASSIFIERSYSTEM->array[i]->rule_execution

	//Parameters: retrieve the list of parameter values for the current rule
	param_vector = AGENT_CLASSIFIERSYSTEM->array[i]->parameters;

	//Convert param_vector to string
	imax = param_vector->size;
	str="\0"; 			//empty, null-terminated string
	for (i=0;i<imax;i++)
	{
		new_str = sprintf('%s,%f',str,param_vector->array[i]);
		strcpy(str, new_str);	
	}
	strcpy(param_vector_as_string,new_str);
	
//**********WARNING: SERIOUSLY BAD CODING BELOW******************
	//Execute the rule's functioncall, with the appropriate parameter setting
	sprintf('%s(%s)',functioncall, param_vector_as_string);

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
   AssetPortfolioType * current_assetportfolio=get_current_assetportfolio();
   AssetPortfolioType * prescribed_assetportfolio=get_prescribed_assetportfolio();
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


/*******************************************
 * Adding the function names from the previously done work refer to financial_management.c file
 * Only functions heading are added to prevent errors encountered from parser.
 * This is done to test the ewa functions
 *******************************************/
 