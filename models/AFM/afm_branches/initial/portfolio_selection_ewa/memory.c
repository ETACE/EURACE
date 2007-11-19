/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
	temp_xmachine = NULL;
	p_xmachine = &temp_xmachine;
	temp_WagePayment_message = NULL;
	p_WagePayment_message = &temp_WagePayment_message;
	temp_DividendPayment_message = NULL;
	p_DividendPayment_message = &temp_DividendPayment_message;
	temp_BondCouponPayment_message = NULL;
	p_BondCouponPayment_message = &temp_BondCouponPayment_message;
	temp_firm_bond_order_message = NULL;
	p_firm_bond_order_message = &temp_firm_bond_order_message;
	temp_firm_stock_order_message = NULL;
	p_firm_stock_order_message = &temp_firm_stock_order_message;
	temp_gov_bond_order_message = NULL;
	p_gov_bond_order_message = &temp_gov_bond_order_message;
	temp_firm_bond_transaction_message = NULL;
	p_firm_bond_transaction_message = &temp_firm_bond_transaction_message;
	temp_gov_bond_transaction_message = NULL;
	p_gov_bond_transaction_message = &temp_gov_bond_transaction_message;
	temp_firm_stock_transaction_message = NULL;
	p_firm_stock_transaction_message = &temp_firm_stock_transaction_message;
	temp_rule_performance_message = NULL;
	p_rule_performance_message = &temp_rule_performance_message;
	temp_all_performances_message = NULL;
	p_all_performances_message = &temp_all_performances_message;
	temp_rule_details_request_message = NULL;
	p_rule_details_request_message = &temp_rule_details_request_message;
	temp_ruledetailsystem_message = NULL;
	p_ruledetailsystem_message = &temp_ruledetailsystem_message;
	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;
	
	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}
	
	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);	
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}
	
	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_location = NULL;
}

/* add_xmachine */
/** \fn xmachine * add_xmachine()
 * \brief Add an X-machine to the current being used X-machine list.
 * \return Pointer to the added X-machine.
 */
xmachine * add_xmachine()
{
	xmachine * current = (xmachine *)malloc(sizeof(xmachine));
	CHECK_POINTER(current);

	current->xmachine_Household = NULL;
	current->xmachine_Firm = NULL;
	current->xmachine_Bank = NULL;
	current->xmachine_ClearingHouseMechanism = NULL;
	current->xmachine_LimitOrderBook = NULL;
	current->xmachine_Government = NULL;
	current->xmachine_FinancialAdvisor = NULL;
	current->next = *p_xmachine;
	*p_xmachine = current;
	
	current_node->agent_total++;

/* add by cg for round-robin so that set_ has something to point at */
	current_xmachine = current;
	
	return current;
}

/** \fn void add_Household_agent(int household_id, PrivateClassifierSystem * agent_classifiersystem, double asset_budget, AssetPortfolioType * current_assetportfolio, AssetPortfolioType * prescribed_assetportfolio, int nr_selected_rule, double current_rule_performance, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, double prescribed_asset_value, double asset_budget, double iradius, double posx, double posy)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param household_id Variable for the X-machine memory.
 * \param agent_classifiersystem Variable for the X-machine memory.
 * \param asset_budget Variable for the X-machine memory.
 * \param current_assetportfolio Variable for the X-machine memory.
 * \param prescribed_assetportfolio Variable for the X-machine memory.
 * \param nr_selected_rule Variable for the X-machine memory.
 * \param current_rule_performance Variable for the X-machine memory.
 * \param EWA_rho Variable for the X-machine memory.
 * \param EWA_phi Variable for the X-machine memory.
 * \param EWA_delta Variable for the X-machine memory.
 * \param EWA_beta Variable for the X-machine memory.
 * \param prescribed_asset_value Variable for the X-machine memory.
 * \param asset_budget Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Household_agent(int household_id, PrivateClassifierSystem * agent_classifiersystem, double asset_budget, AssetPortfolioType * current_assetportfolio, AssetPortfolioType * prescribed_assetportfolio, int nr_selected_rule, double current_rule_performance, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, double prescribed_asset_value, double asset_budget, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Household = current;
	current->household_id = household_id;
	current->agent_classifiersystem = agent_classifiersystem;
	current->asset_budget = asset_budget;
	current->current_assetportfolio = current_assetportfolio;
	current->prescribed_assetportfolio = prescribed_assetportfolio;
	current->nr_selected_rule = nr_selected_rule;
	current->current_rule_performance = current_rule_performance;
	current->EWA_rho = EWA_rho;
	current->EWA_phi = EWA_phi;
	current->EWA_delta = EWA_delta;
	current->EWA_beta = EWA_beta;
	current->prescribed_asset_value = prescribed_asset_value;
	current->asset_budget = asset_budget;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_Firm_agent(double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double iradius, double posx, double posy)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param revenues Variable for the X-machine memory.
 * \param sales_costs Variable for the X-machine memory.
 * \param total_revenue Variable for the X-machine memory.
 * \param net_revenue Variable for the X-machine memory.
 * \param operational_cost Variable for the X-machine memory.
 * \param total_wage_payments Variable for the X-machine memory.
 * \param total_input_payments Variable for the X-machine memory.
 * \param interest_payments Variable for the X-machine memory.
 * \param total_earnings Variable for the X-machine memory.
 * \param tax_rate_profits Variable for the X-machine memory.
 * \param pretax_profit Variable for the X-machine memory.
 * \param tax_provision Variable for the X-machine memory.
 * \param net_earnings Variable for the X-machine memory.
 * \param div_payments Variable for the X-machine memory.
 * \param retained_earnings Variable for the X-machine memory.
 * \param current_debt Variable for the X-machine memory.
 * \param debt_interest_rate Variable for the X-machine memory.
 * \param debt_repayments Variable for the X-machine memory.
 * \param share_repurchase_value Variable for the X-machine memory.
 * \param share_repurchase_units Variable for the X-machine memory.
 * \param target_total_shares Variable for the X-machine memory.
 * \param current_total_shares Variable for the X-machine memory.
 * \param total_financial_needs Variable for the X-machine memory.
 * \param financial_needs Variable for the X-machine memory.
 * \param add_financial_needs Variable for the X-machine memory.
 * \param financial_reserves Variable for the X-machine memory.
 * \param target_loans Variable for the X-machine memory.
 * \param target_equity Variable for the X-machine memory.
 * \param bonds_issue_target Variable for the X-machine memory.
 * \param stocks_issue_target Variable for the X-machine memory.
 * \param price Variable for the X-machine memory.
 * \param max_debt Variable for the X-machine memory.
 * \param div_earn_ratio Variable for the X-machine memory.
 * \param debt_earn_ratio Variable for the X-machine memory.
 * \param div_pshare_ratio Variable for the X-machine memory.
 * \param earn_pshare_ratio Variable for the X-machine memory.
 * \param price_earn_ratio Variable for the X-machine memory.
 * \param retained_earn_ratio Variable for the X-machine memory.
 * \param earn_pshare_ratio_growth Variable for the X-machine memory.
 * \param critical_price_earn_ratio Variable for the X-machine memory.
 * \param critical_earn_pshare_ratio Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Firm_agent(double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Firm = current;
	current->revenues = revenues;
	current->sales_costs = sales_costs;
	current->total_revenue = total_revenue;
	current->net_revenue = net_revenue;
	current->operational_cost = operational_cost;
	current->total_wage_payments = total_wage_payments;
	current->total_input_payments = total_input_payments;
	current->interest_payments = interest_payments;
	current->total_earnings = total_earnings;
	current->tax_rate_profits = tax_rate_profits;
	current->pretax_profit = pretax_profit;
	current->tax_provision = tax_provision;
	current->net_earnings = net_earnings;
	current->div_payments = div_payments;
	current->retained_earnings = retained_earnings;
	current->current_debt = current_debt;
	current->debt_interest_rate = debt_interest_rate;
	current->debt_repayments = debt_repayments;
	current->share_repurchase_value = share_repurchase_value;
	current->share_repurchase_units = share_repurchase_units;
	current->target_total_shares = target_total_shares;
	current->current_total_shares = current_total_shares;
	current->total_financial_needs = total_financial_needs;
	current->financial_needs = financial_needs;
	current->add_financial_needs = add_financial_needs;
	current->financial_reserves = financial_reserves;
	current->target_loans = target_loans;
	current->target_equity = target_equity;
	current->bonds_issue_target = bonds_issue_target;
	current->stocks_issue_target = stocks_issue_target;
	current->price = price;
	current->max_debt = max_debt;
	current->div_earn_ratio = div_earn_ratio;
	current->debt_earn_ratio = debt_earn_ratio;
	current->div_pshare_ratio = div_pshare_ratio;
	current->earn_pshare_ratio = earn_pshare_ratio;
	current->price_earn_ratio = price_earn_ratio;
	current->retained_earn_ratio = retained_earn_ratio;
	current->earn_pshare_ratio_growth = earn_pshare_ratio_growth;
	current->critical_price_earn_ratio = critical_price_earn_ratio;
	current->critical_earn_pshare_ratio = critical_earn_pshare_ratio;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_Bank_agent(int id, double iradius, double posx, double posy)
 * \brief Add Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Bank_agent(int id, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Bank * current = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Bank = current;
	current->id = id;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_ClearingHouseMechanism_agent(int id, double iradius, double posx, double posy)
 * \brief Add ClearingHouseMechanism X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_ClearingHouseMechanism_agent(int id, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_ClearingHouseMechanism * current = (xmachine_memory_ClearingHouseMechanism *)malloc(sizeof(xmachine_memory_ClearingHouseMechanism));
		CHECK_POINTER(current);

	new_xmachine->xmachine_ClearingHouseMechanism = current;
	current->id = id;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_LimitOrderBook_agent(double re, double iradius, double posx, double posy)
 * \brief Add LimitOrderBook X-machine to the current being used X-machine list.
 * \param re Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_LimitOrderBook_agent(double re, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_LimitOrderBook * current = (xmachine_memory_LimitOrderBook *)malloc(sizeof(xmachine_memory_LimitOrderBook));
		CHECK_POINTER(current);

	new_xmachine->xmachine_LimitOrderBook = current;
	current->re = re;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_Government_agent(double rj, double iradius, double posx, double posy)
 * \brief Add Government X-machine to the current being used X-machine list.
 * \param rj Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Government_agent(double rj, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Government * current = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Government = current;
	current->rj = rj;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_FinancialAdvisor_agent(PublicClassifierSystem * central_classifiersystem, double iradius, double posx, double posy)
 * \brief Add FinancialAdvisor X-machine to the current being used X-machine list.
 * \param central_classifiersystem Variable for the X-machine memory.
 * \param iradius Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_FinancialAdvisor_agent(PublicClassifierSystem * central_classifiersystem, double iradius, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_FinancialAdvisor * current = (xmachine_memory_FinancialAdvisor *)malloc(sizeof(xmachine_memory_FinancialAdvisor));
		CHECK_POINTER(current);

	new_xmachine->xmachine_FinancialAdvisor = current;
	current->central_classifiersystem = central_classifiersystem;
	current->iradius = iradius;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void free_agent()
 * \brief Free the currently being used X-machine.
 */
/* free_agent */
void free_agent()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		if(head == current_xmachine)
		{
			if(tmp) tmp->next = head->next;
			else *p_xmachine = head->next;
			if(head->xmachine_Household)
			{
				free(head->xmachine_Household);
			}
			if(head->xmachine_Firm)
			{
				free_double_array(head->xmachine_Firm->revenues);
				free_double_array(head->xmachine_Firm->sales_costs);
				free(head->xmachine_Firm);
			}
			if(head->xmachine_Bank)
			{
				free(head->xmachine_Bank);
			}
			if(head->xmachine_ClearingHouseMechanism)
			{
				free(head->xmachine_ClearingHouseMechanism);
			}
			if(head->xmachine_LimitOrderBook)
			{
				free(head->xmachine_LimitOrderBook);
			}
			if(head->xmachine_Government)
			{
				free(head->xmachine_Government);
			}
			if(head->xmachine_FinancialAdvisor)
			{
				free(head->xmachine_FinancialAdvisor);
			}

		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = tmp->next;
	}
}
	
	current_node->agent_total--;
}

/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		if(head->xmachine_Household)
		{
			free(head->xmachine_Household->agent_classifiersystem);
			free(head->xmachine_Household->current_assetportfolio);
			free(head->xmachine_Household->prescribed_assetportfolio);
			free(head->xmachine_Household);
		}
		if(head->xmachine_Firm)
		{
			free_double_array(head->xmachine_Firm->revenues);
			free_double_array(head->xmachine_Firm->sales_costs);
			free(head->xmachine_Firm);
		}
		if(head->xmachine_Bank)
		{
			free(head->xmachine_Bank);
		}
		if(head->xmachine_ClearingHouseMechanism)
		{
			free(head->xmachine_ClearingHouseMechanism);
		}
		if(head->xmachine_LimitOrderBook)
		{
			free(head->xmachine_LimitOrderBook);
		}
		if(head->xmachine_Government)
		{
			free(head->xmachine_Government);
		}
		if(head->xmachine_FinancialAdvisor)
		{
			free(head->xmachine_FinancialAdvisor->central_classifiersystem);
			free(head->xmachine_FinancialAdvisor);
		}
		free(head);
		head = tmp;
	}
	
	*p_xmachine = NULL;
}


/** \fn void set_household_id(int household_id) 
 * \brief Set household_id memory variable for current X-machine.
 * \param household_id New value for variable.
 */
void set_household_id(int household_id)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->household_id = household_id;
}

/** \fn int get_household_id()
 * \brief Get household_id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_household_id()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->household_id;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn PrivateClassifierSystem get_agent_classifiersystem()
 * \brief Get agent_classifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
PrivateClassifierSystem * get_agent_classifiersystem()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->agent_classifiersystem;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn void set_asset_budget(double asset_budget) 
 * \brief Set asset_budget memory variable for current X-machine.
 * \param asset_budget New value for variable.
 */
void set_asset_budget(double asset_budget)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->asset_budget = asset_budget;
}

/** \fn double get_asset_budget()
 * \brief Get asset_budget memory variable from current X-machine.
 * \return Value for variable.
 */
double get_asset_budget()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->asset_budget;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn AssetPortfolioType get_current_assetportfolio()
 * \brief Get current_assetportfolio memory variable from current X-machine.
 * \return Value for variable.
 */
AssetPortfolioType * get_current_assetportfolio()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->current_assetportfolio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn AssetPortfolioType get_prescribed_assetportfolio()
 * \brief Get prescribed_assetportfolio memory variable from current X-machine.
 * \return Value for variable.
 */
AssetPortfolioType * get_prescribed_assetportfolio()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->prescribed_assetportfolio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn void set_nr_selected_rule(int nr_selected_rule) 
 * \brief Set nr_selected_rule memory variable for current X-machine.
 * \param nr_selected_rule New value for variable.
 */
void set_nr_selected_rule(int nr_selected_rule)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->nr_selected_rule = nr_selected_rule;
}

/** \fn int get_nr_selected_rule()
 * \brief Get nr_selected_rule memory variable from current X-machine.
 * \return Value for variable.
 */
int get_nr_selected_rule()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->nr_selected_rule;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_current_rule_performance(double current_rule_performance) 
 * \brief Set current_rule_performance memory variable for current X-machine.
 * \param current_rule_performance New value for variable.
 */
void set_current_rule_performance(double current_rule_performance)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->current_rule_performance = current_rule_performance;
}

/** \fn double get_current_rule_performance()
 * \brief Get current_rule_performance memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_rule_performance()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->current_rule_performance;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_EWA_rho(double EWA_rho) 
 * \brief Set EWA_rho memory variable for current X-machine.
 * \param EWA_rho New value for variable.
 */
void set_EWA_rho(double EWA_rho)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->EWA_rho = EWA_rho;
}

/** \fn double get_EWA_rho()
 * \brief Get EWA_rho memory variable from current X-machine.
 * \return Value for variable.
 */
double get_EWA_rho()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->EWA_rho;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_EWA_phi(double EWA_phi) 
 * \brief Set EWA_phi memory variable for current X-machine.
 * \param EWA_phi New value for variable.
 */
void set_EWA_phi(double EWA_phi)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->EWA_phi = EWA_phi;
}

/** \fn double get_EWA_phi()
 * \brief Get EWA_phi memory variable from current X-machine.
 * \return Value for variable.
 */
double get_EWA_phi()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->EWA_phi;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_EWA_delta(double EWA_delta) 
 * \brief Set EWA_delta memory variable for current X-machine.
 * \param EWA_delta New value for variable.
 */
void set_EWA_delta(double EWA_delta)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->EWA_delta = EWA_delta;
}

/** \fn double get_EWA_delta()
 * \brief Get EWA_delta memory variable from current X-machine.
 * \return Value for variable.
 */
double get_EWA_delta()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->EWA_delta;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_EWA_beta(double EWA_beta) 
 * \brief Set EWA_beta memory variable for current X-machine.
 * \param EWA_beta New value for variable.
 */
void set_EWA_beta(double EWA_beta)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->EWA_beta = EWA_beta;
}

/** \fn double get_EWA_beta()
 * \brief Get EWA_beta memory variable from current X-machine.
 * \return Value for variable.
 */
double get_EWA_beta()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->EWA_beta;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_prescribed_asset_value(double prescribed_asset_value) 
 * \brief Set prescribed_asset_value memory variable for current X-machine.
 * \param prescribed_asset_value New value for variable.
 */
void set_prescribed_asset_value(double prescribed_asset_value)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->prescribed_asset_value = prescribed_asset_value;
}

/** \fn double get_prescribed_asset_value()
 * \brief Get prescribed_asset_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_prescribed_asset_value()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->prescribed_asset_value;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_iradius(double iradius) 
 * \brief Set iradius memory variable for current X-machine.
 * \param iradius New value for variable.
 */
void set_iradius(double iradius)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->iradius = iradius;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->iradius = iradius;
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->iradius = iradius;
	if(current_xmachine->xmachine_ClearingHouseMechanism) current_xmachine->xmachine_ClearingHouseMechanism->iradius = iradius;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->iradius = iradius;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->iradius = iradius;
	if(current_xmachine->xmachine_FinancialAdvisor) current_xmachine->xmachine_FinancialAdvisor->iradius = iradius;
}

/** \fn double get_iradius()
 * \brief Get iradius memory variable from current X-machine.
 * \return Value for variable.
 */
double get_iradius()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->iradius;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->iradius;
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->iradius;
	if(current_xmachine->xmachine_ClearingHouseMechanism) return current_xmachine->xmachine_ClearingHouseMechanism->iradius;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->iradius;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->iradius;
	if(current_xmachine->xmachine_FinancialAdvisor) return current_xmachine->xmachine_FinancialAdvisor->iradius;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_posx(double posx) 
 * \brief Set posx memory variable for current X-machine.
 * \param posx New value for variable.
 */
void set_posx(double posx)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->posx = posx;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->posx = posx;
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->posx = posx;
	if(current_xmachine->xmachine_ClearingHouseMechanism) current_xmachine->xmachine_ClearingHouseMechanism->posx = posx;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->posx = posx;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->posx = posx;
	if(current_xmachine->xmachine_FinancialAdvisor) current_xmachine->xmachine_FinancialAdvisor->posx = posx;
}

/** \fn double get_posx()
 * \brief Get posx memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posx()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->posx;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->posx;
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->posx;
	if(current_xmachine->xmachine_ClearingHouseMechanism) return current_xmachine->xmachine_ClearingHouseMechanism->posx;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->posx;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->posx;
	if(current_xmachine->xmachine_FinancialAdvisor) return current_xmachine->xmachine_FinancialAdvisor->posx;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_posy(double posy) 
 * \brief Set posy memory variable for current X-machine.
 * \param posy New value for variable.
 */
void set_posy(double posy)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->posy = posy;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->posy = posy;
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->posy = posy;
	if(current_xmachine->xmachine_ClearingHouseMechanism) current_xmachine->xmachine_ClearingHouseMechanism->posy = posy;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->posy = posy;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->posy = posy;
	if(current_xmachine->xmachine_FinancialAdvisor) current_xmachine->xmachine_FinancialAdvisor->posy = posy;
}

/** \fn double get_posy()
 * \brief Get posy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posy()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->posy;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->posy;
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->posy;
	if(current_xmachine->xmachine_ClearingHouseMechanism) return current_xmachine->xmachine_ClearingHouseMechanism->posy;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->posy;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->posy;
	if(current_xmachine->xmachine_FinancialAdvisor) return current_xmachine->xmachine_FinancialAdvisor->posy;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn double_array get_revenues()
 * \brief Get revenues memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_revenues()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->revenues;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn double_array get_sales_costs()
 * \brief Get sales_costs memory variable from current X-machine.
 * \return Value for variable.
 */
double_array * get_sales_costs()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->sales_costs;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn void set_total_revenue(double total_revenue) 
 * \brief Set total_revenue memory variable for current X-machine.
 * \param total_revenue New value for variable.
 */
void set_total_revenue(double total_revenue)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_revenue = total_revenue;
}

/** \fn double get_total_revenue()
 * \brief Get total_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_revenue()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_revenue;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_net_revenue(double net_revenue) 
 * \brief Set net_revenue memory variable for current X-machine.
 * \param net_revenue New value for variable.
 */
void set_net_revenue(double net_revenue)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->net_revenue = net_revenue;
}

/** \fn double get_net_revenue()
 * \brief Get net_revenue memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_revenue()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->net_revenue;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_operational_cost(double operational_cost) 
 * \brief Set operational_cost memory variable for current X-machine.
 * \param operational_cost New value for variable.
 */
void set_operational_cost(double operational_cost)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->operational_cost = operational_cost;
}

/** \fn double get_operational_cost()
 * \brief Get operational_cost memory variable from current X-machine.
 * \return Value for variable.
 */
double get_operational_cost()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->operational_cost;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_total_wage_payments(double total_wage_payments) 
 * \brief Set total_wage_payments memory variable for current X-machine.
 * \param total_wage_payments New value for variable.
 */
void set_total_wage_payments(double total_wage_payments)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_wage_payments = total_wage_payments;
}

/** \fn double get_total_wage_payments()
 * \brief Get total_wage_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_wage_payments()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_wage_payments;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_total_input_payments(double total_input_payments) 
 * \brief Set total_input_payments memory variable for current X-machine.
 * \param total_input_payments New value for variable.
 */
void set_total_input_payments(double total_input_payments)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_input_payments = total_input_payments;
}

/** \fn double get_total_input_payments()
 * \brief Get total_input_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_input_payments()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_input_payments;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_interest_payments(double interest_payments) 
 * \brief Set interest_payments memory variable for current X-machine.
 * \param interest_payments New value for variable.
 */
void set_interest_payments(double interest_payments)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->interest_payments = interest_payments;
}

/** \fn double get_interest_payments()
 * \brief Get interest_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_interest_payments()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->interest_payments;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_total_earnings(double total_earnings) 
 * \brief Set total_earnings memory variable for current X-machine.
 * \param total_earnings New value for variable.
 */
void set_total_earnings(double total_earnings)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_earnings = total_earnings;
}

/** \fn double get_total_earnings()
 * \brief Get total_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_earnings()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_earnings;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_tax_rate_profits(double tax_rate_profits) 
 * \brief Set tax_rate_profits memory variable for current X-machine.
 * \param tax_rate_profits New value for variable.
 */
void set_tax_rate_profits(double tax_rate_profits)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->tax_rate_profits = tax_rate_profits;
}

/** \fn double get_tax_rate_profits()
 * \brief Get tax_rate_profits memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_rate_profits()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->tax_rate_profits;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_pretax_profit(double pretax_profit) 
 * \brief Set pretax_profit memory variable for current X-machine.
 * \param pretax_profit New value for variable.
 */
void set_pretax_profit(double pretax_profit)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->pretax_profit = pretax_profit;
}

/** \fn double get_pretax_profit()
 * \brief Get pretax_profit memory variable from current X-machine.
 * \return Value for variable.
 */
double get_pretax_profit()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->pretax_profit;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_tax_provision(double tax_provision) 
 * \brief Set tax_provision memory variable for current X-machine.
 * \param tax_provision New value for variable.
 */
void set_tax_provision(double tax_provision)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->tax_provision = tax_provision;
}

/** \fn double get_tax_provision()
 * \brief Get tax_provision memory variable from current X-machine.
 * \return Value for variable.
 */
double get_tax_provision()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->tax_provision;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_net_earnings(double net_earnings) 
 * \brief Set net_earnings memory variable for current X-machine.
 * \param net_earnings New value for variable.
 */
void set_net_earnings(double net_earnings)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->net_earnings = net_earnings;
}

/** \fn double get_net_earnings()
 * \brief Get net_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_net_earnings()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->net_earnings;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_div_payments(double div_payments) 
 * \brief Set div_payments memory variable for current X-machine.
 * \param div_payments New value for variable.
 */
void set_div_payments(double div_payments)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->div_payments = div_payments;
}

/** \fn double get_div_payments()
 * \brief Get div_payments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_div_payments()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->div_payments;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_retained_earnings(double retained_earnings) 
 * \brief Set retained_earnings memory variable for current X-machine.
 * \param retained_earnings New value for variable.
 */
void set_retained_earnings(double retained_earnings)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->retained_earnings = retained_earnings;
}

/** \fn double get_retained_earnings()
 * \brief Get retained_earnings memory variable from current X-machine.
 * \return Value for variable.
 */
double get_retained_earnings()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->retained_earnings;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_current_debt(double current_debt) 
 * \brief Set current_debt memory variable for current X-machine.
 * \param current_debt New value for variable.
 */
void set_current_debt(double current_debt)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->current_debt = current_debt;
}

/** \fn double get_current_debt()
 * \brief Get current_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_current_debt()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->current_debt;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_debt_interest_rate(double debt_interest_rate) 
 * \brief Set debt_interest_rate memory variable for current X-machine.
 * \param debt_interest_rate New value for variable.
 */
void set_debt_interest_rate(double debt_interest_rate)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->debt_interest_rate = debt_interest_rate;
}

/** \fn double get_debt_interest_rate()
 * \brief Get debt_interest_rate memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_interest_rate()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->debt_interest_rate;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_debt_repayments(double debt_repayments) 
 * \brief Set debt_repayments memory variable for current X-machine.
 * \param debt_repayments New value for variable.
 */
void set_debt_repayments(double debt_repayments)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->debt_repayments = debt_repayments;
}

/** \fn double get_debt_repayments()
 * \brief Get debt_repayments memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_repayments()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->debt_repayments;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_share_repurchase_value(double share_repurchase_value) 
 * \brief Set share_repurchase_value memory variable for current X-machine.
 * \param share_repurchase_value New value for variable.
 */
void set_share_repurchase_value(double share_repurchase_value)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->share_repurchase_value = share_repurchase_value;
}

/** \fn double get_share_repurchase_value()
 * \brief Get share_repurchase_value memory variable from current X-machine.
 * \return Value for variable.
 */
double get_share_repurchase_value()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->share_repurchase_value;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_share_repurchase_units(int share_repurchase_units) 
 * \brief Set share_repurchase_units memory variable for current X-machine.
 * \param share_repurchase_units New value for variable.
 */
void set_share_repurchase_units(int share_repurchase_units)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->share_repurchase_units = share_repurchase_units;
}

/** \fn int get_share_repurchase_units()
 * \brief Get share_repurchase_units memory variable from current X-machine.
 * \return Value for variable.
 */
int get_share_repurchase_units()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->share_repurchase_units;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_target_total_shares(int target_total_shares) 
 * \brief Set target_total_shares memory variable for current X-machine.
 * \param target_total_shares New value for variable.
 */
void set_target_total_shares(int target_total_shares)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->target_total_shares = target_total_shares;
}

/** \fn int get_target_total_shares()
 * \brief Get target_total_shares memory variable from current X-machine.
 * \return Value for variable.
 */
int get_target_total_shares()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->target_total_shares;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_current_total_shares(int current_total_shares) 
 * \brief Set current_total_shares memory variable for current X-machine.
 * \param current_total_shares New value for variable.
 */
void set_current_total_shares(int current_total_shares)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->current_total_shares = current_total_shares;
}

/** \fn int get_current_total_shares()
 * \brief Get current_total_shares memory variable from current X-machine.
 * \return Value for variable.
 */
int get_current_total_shares()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->current_total_shares;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_total_financial_needs(double total_financial_needs) 
 * \brief Set total_financial_needs memory variable for current X-machine.
 * \param total_financial_needs New value for variable.
 */
void set_total_financial_needs(double total_financial_needs)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_financial_needs = total_financial_needs;
}

/** \fn double get_total_financial_needs()
 * \brief Get total_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_financial_needs;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_financial_needs(double financial_needs) 
 * \brief Set financial_needs memory variable for current X-machine.
 * \param financial_needs New value for variable.
 */
void set_financial_needs(double financial_needs)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->financial_needs = financial_needs;
}

/** \fn double get_financial_needs()
 * \brief Get financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->financial_needs;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_add_financial_needs(double add_financial_needs) 
 * \brief Set add_financial_needs memory variable for current X-machine.
 * \param add_financial_needs New value for variable.
 */
void set_add_financial_needs(double add_financial_needs)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->add_financial_needs = add_financial_needs;
}

/** \fn double get_add_financial_needs()
 * \brief Get add_financial_needs memory variable from current X-machine.
 * \return Value for variable.
 */
double get_add_financial_needs()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->add_financial_needs;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_financial_reserves(double financial_reserves) 
 * \brief Set financial_reserves memory variable for current X-machine.
 * \param financial_reserves New value for variable.
 */
void set_financial_reserves(double financial_reserves)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->financial_reserves = financial_reserves;
}

/** \fn double get_financial_reserves()
 * \brief Get financial_reserves memory variable from current X-machine.
 * \return Value for variable.
 */
double get_financial_reserves()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->financial_reserves;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_target_loans(double target_loans) 
 * \brief Set target_loans memory variable for current X-machine.
 * \param target_loans New value for variable.
 */
void set_target_loans(double target_loans)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->target_loans = target_loans;
}

/** \fn double get_target_loans()
 * \brief Get target_loans memory variable from current X-machine.
 * \return Value for variable.
 */
double get_target_loans()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->target_loans;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_target_equity(double target_equity) 
 * \brief Set target_equity memory variable for current X-machine.
 * \param target_equity New value for variable.
 */
void set_target_equity(double target_equity)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->target_equity = target_equity;
}

/** \fn double get_target_equity()
 * \brief Get target_equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_target_equity()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->target_equity;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_bonds_issue_target(double bonds_issue_target) 
 * \brief Set bonds_issue_target memory variable for current X-machine.
 * \param bonds_issue_target New value for variable.
 */
void set_bonds_issue_target(double bonds_issue_target)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->bonds_issue_target = bonds_issue_target;
}

/** \fn double get_bonds_issue_target()
 * \brief Get bonds_issue_target memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bonds_issue_target()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->bonds_issue_target;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_stocks_issue_target(double stocks_issue_target) 
 * \brief Set stocks_issue_target memory variable for current X-machine.
 * \param stocks_issue_target New value for variable.
 */
void set_stocks_issue_target(double stocks_issue_target)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->stocks_issue_target = stocks_issue_target;
}

/** \fn double get_stocks_issue_target()
 * \brief Get stocks_issue_target memory variable from current X-machine.
 * \return Value for variable.
 */
double get_stocks_issue_target()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->stocks_issue_target;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_price(double price) 
 * \brief Set price memory variable for current X-machine.
 * \param price New value for variable.
 */
void set_price(double price)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->price = price;
}

/** \fn double get_price()
 * \brief Get price memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->price;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_max_debt(double max_debt) 
 * \brief Set max_debt memory variable for current X-machine.
 * \param max_debt New value for variable.
 */
void set_max_debt(double max_debt)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->max_debt = max_debt;
}

/** \fn double get_max_debt()
 * \brief Get max_debt memory variable from current X-machine.
 * \return Value for variable.
 */
double get_max_debt()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->max_debt;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_div_earn_ratio(double div_earn_ratio) 
 * \brief Set div_earn_ratio memory variable for current X-machine.
 * \param div_earn_ratio New value for variable.
 */
void set_div_earn_ratio(double div_earn_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->div_earn_ratio = div_earn_ratio;
}

/** \fn double get_div_earn_ratio()
 * \brief Get div_earn_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_div_earn_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->div_earn_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_debt_earn_ratio(double debt_earn_ratio) 
 * \brief Set debt_earn_ratio memory variable for current X-machine.
 * \param debt_earn_ratio New value for variable.
 */
void set_debt_earn_ratio(double debt_earn_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->debt_earn_ratio = debt_earn_ratio;
}

/** \fn double get_debt_earn_ratio()
 * \brief Get debt_earn_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_debt_earn_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->debt_earn_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_div_pshare_ratio(double div_pshare_ratio) 
 * \brief Set div_pshare_ratio memory variable for current X-machine.
 * \param div_pshare_ratio New value for variable.
 */
void set_div_pshare_ratio(double div_pshare_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->div_pshare_ratio = div_pshare_ratio;
}

/** \fn double get_div_pshare_ratio()
 * \brief Get div_pshare_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_div_pshare_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->div_pshare_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_earn_pshare_ratio(double earn_pshare_ratio) 
 * \brief Set earn_pshare_ratio memory variable for current X-machine.
 * \param earn_pshare_ratio New value for variable.
 */
void set_earn_pshare_ratio(double earn_pshare_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->earn_pshare_ratio = earn_pshare_ratio;
}

/** \fn double get_earn_pshare_ratio()
 * \brief Get earn_pshare_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earn_pshare_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->earn_pshare_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_price_earn_ratio(double price_earn_ratio) 
 * \brief Set price_earn_ratio memory variable for current X-machine.
 * \param price_earn_ratio New value for variable.
 */
void set_price_earn_ratio(double price_earn_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->price_earn_ratio = price_earn_ratio;
}

/** \fn double get_price_earn_ratio()
 * \brief Get price_earn_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_price_earn_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->price_earn_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_retained_earn_ratio(double retained_earn_ratio) 
 * \brief Set retained_earn_ratio memory variable for current X-machine.
 * \param retained_earn_ratio New value for variable.
 */
void set_retained_earn_ratio(double retained_earn_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->retained_earn_ratio = retained_earn_ratio;
}

/** \fn double get_retained_earn_ratio()
 * \brief Get retained_earn_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_retained_earn_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->retained_earn_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_earn_pshare_ratio_growth(double earn_pshare_ratio_growth) 
 * \brief Set earn_pshare_ratio_growth memory variable for current X-machine.
 * \param earn_pshare_ratio_growth New value for variable.
 */
void set_earn_pshare_ratio_growth(double earn_pshare_ratio_growth)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->earn_pshare_ratio_growth = earn_pshare_ratio_growth;
}

/** \fn double get_earn_pshare_ratio_growth()
 * \brief Get earn_pshare_ratio_growth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_earn_pshare_ratio_growth()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->earn_pshare_ratio_growth;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_critical_price_earn_ratio(double critical_price_earn_ratio) 
 * \brief Set critical_price_earn_ratio memory variable for current X-machine.
 * \param critical_price_earn_ratio New value for variable.
 */
void set_critical_price_earn_ratio(double critical_price_earn_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->critical_price_earn_ratio = critical_price_earn_ratio;
}

/** \fn double get_critical_price_earn_ratio()
 * \brief Get critical_price_earn_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_price_earn_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->critical_price_earn_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_critical_earn_pshare_ratio(double critical_earn_pshare_ratio) 
 * \brief Set critical_earn_pshare_ratio memory variable for current X-machine.
 * \param critical_earn_pshare_ratio New value for variable.
 */
void set_critical_earn_pshare_ratio(double critical_earn_pshare_ratio)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->critical_earn_pshare_ratio = critical_earn_pshare_ratio;
}

/** \fn double get_critical_earn_pshare_ratio()
 * \brief Get critical_earn_pshare_ratio memory variable from current X-machine.
 * \return Value for variable.
 */
double get_critical_earn_pshare_ratio()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->critical_earn_pshare_ratio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->id = id;
	if(current_xmachine->xmachine_ClearingHouseMechanism) current_xmachine->xmachine_ClearingHouseMechanism->id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->id;
	if(current_xmachine->xmachine_ClearingHouseMechanism) return current_xmachine->xmachine_ClearingHouseMechanism->id;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_re(double re) 
 * \brief Set re memory variable for current X-machine.
 * \param re New value for variable.
 */
void set_re(double re)
{
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->re = re;
}

/** \fn double get_re()
 * \brief Get re memory variable from current X-machine.
 * \return Value for variable.
 */
double get_re()
{
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->re;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_rj(double rj) 
 * \brief Set rj memory variable for current X-machine.
 * \param rj New value for variable.
 */
void set_rj(double rj)
{
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->rj = rj;
}

/** \fn double get_rj()
 * \brief Get rj memory variable from current X-machine.
 * \return Value for variable.
 */
double get_rj()
{
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->rj;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn PublicClassifierSystem get_central_classifiersystem()
 * \brief Get central_classifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
PublicClassifierSystem * get_central_classifiersystem()
{
	if(current_xmachine->xmachine_FinancialAdvisor) return current_xmachine->xmachine_FinancialAdvisor->central_classifiersystem;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->;
    if (current_xmachine->xmachine_ClearingHouseMechanism) value = current_xmachine->xmachine_ClearingHouseMechanism->;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->;
    if (current_xmachine->xmachine_FinancialAdvisor) value = current_xmachine->xmachine_FinancialAdvisor->;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;
    if (current_xmachine->xmachine_ClearingHouseMechanism) value = current_xmachine->xmachine_ClearingHouseMechanism->id;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->;
    if (current_xmachine->xmachine_FinancialAdvisor) value = current_xmachine->xmachine_FinancialAdvisor->;

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posx;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posx;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->posx;
    if (current_xmachine->xmachine_ClearingHouseMechanism) value = current_xmachine->xmachine_ClearingHouseMechanism->posx;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->posx;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->posx;
    if (current_xmachine->xmachine_FinancialAdvisor) value = current_xmachine->xmachine_FinancialAdvisor->posx;

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posy; 
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posy; 
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->posy; 
    if (current_xmachine->xmachine_ClearingHouseMechanism) value = current_xmachine->xmachine_ClearingHouseMechanism->posy; 
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->posy; 
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->posy; 
    if (current_xmachine->xmachine_FinancialAdvisor) value = current_xmachine->xmachine_FinancialAdvisor->posy; 

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}
/** \fn void randomisexagent()
 * \brief Randomise the current X-machine list.
 * 
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
void randomisexagent() {

    int i, rnd;
    int xm_count;
    xmachine *current;
    xmachine **address_list;
    
    xm_count = current_node->agent_total;

    /* allocate mem for dynamic temp array */
    address_list = (xmachine **)malloc(sizeof(xmachine *) * xm_count);
	CHECK_POINTER(address_list);

    p_xmachine = &current_node->agents;
    
    /* populate address list */
    i = 0;
    current = *p_xmachine;
    while(current)
    {
        address_list[i] = current;
        current = current->next;
        i++;
    }

    /* randomise address list */
    for (i = xm_count - 1; i > 0; i--)
    {
        /* get random number */
        rnd = (int)((double)i * rand() / (RAND_MAX + 1.0));

        if (rnd == i) continue;

        /* use 'current' as temp var to swap addresses */
        current = address_list[i];
        address_list[i] = address_list[rnd];
        address_list[rnd] = current;
    }

    /* build new xmachine list from randomised address list */
    *p_xmachine = NULL;
    for (i = 0; i < xm_count; i++)
    {
        address_list[i]->next = *p_xmachine;
        *p_xmachine = address_list[i];
    }

    free(address_list);
}


/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;
	
	while(current)
	{
		tmp = current;
		current = current->next;
	}
	
	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}
	
	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->WagePayment_messages = NULL;
	current->DividendPayment_messages = NULL;
	current->BondCouponPayment_messages = NULL;
	current->firm_bond_order_messages = NULL;
	current->firm_stock_order_messages = NULL;
	current->gov_bond_order_messages = NULL;
	current->firm_bond_transaction_messages = NULL;
	current->gov_bond_transaction_messages = NULL;
	current->firm_stock_transaction_messages = NULL;
	current->rule_performance_messages = NULL;
	current->all_performances_messages = NULL;
	current->rule_details_request_messages = NULL;
	current->ruledetailsystem_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
	FILE *file;
	char data[100];
	
	
	/* Free x-machine memory */

	current_node = *p_node_info;
	while(current_node)
	{
		p_xmachine = &current_node->agents;

	freexmachines();
	current_node->agent_total = 0;

		current_node = current_node->next;
	}

	/* Free space partitions linked list */
	free_node_info();
	

	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%ld", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);

	
	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");
		
		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->posx;
			y_xmachine = current_xmachine->xmachine_Firm->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Bank->posx;
			y_xmachine = current_xmachine->xmachine_Bank->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_ClearingHouseMechanism != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ClearingHouseMechanism->posx;
			y_xmachine = current_xmachine->xmachine_ClearingHouseMechanism->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			x_xmachine = current_xmachine->xmachine_LimitOrderBook->posx;
			y_xmachine = current_xmachine->xmachine_LimitOrderBook->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Government->posx;
			y_xmachine = current_xmachine->xmachine_Government->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_FinancialAdvisor != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FinancialAdvisor->posx;
			y_xmachine = current_xmachine->xmachine_FinancialAdvisor->posy;
			z_xmachine = 0.0;
		}
		
		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    /* Remove agent */
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    /* Add agent */
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;
			
			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
int_array * init_int_array()
{
	int_array * new_array = (int_array *)malloc(sizeof(int_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
void sort_int_array(int_array * array)
{
	int i, j, temp;
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_int(int * array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (int *)realloc(array->array, (array->total_size * sizeof(int)));
	}
	array->array[array->size] = new_int;
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prints */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %d", i, array->array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
float_array * init_float_array()
{
	float_array * new_array = (float_array *)malloc(sizeof(float_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	array->size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
void sort_float_array(float_array * array)
{
	int i, j;
	float temp;
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_float(float * array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (float *)realloc(array->array, (array->total_size * sizeof(float)));
	}
	array->array[array->size] = new_float;
	array->size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %f", i, array->array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
double_array * init_double_array()
{
	double_array * new_array = (double_array *)malloc(sizeof(double_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
		CHECK_POINTER(new_array->array);
	return new_array;
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	array->size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
void sort_double_array(double_array * array)
{
	int i, j;
	double temp;
	
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_double(double * array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ; 
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (double *)realloc(array->array, (array->total_size * sizeof(double)));
	}
	array->array[array->size] = new_double;
	array->size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prints */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %f", i, array->array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
char_array * init_char_array()
{
	char_array * new_array = (char_array *)malloc(sizeof(char_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
		CHECK_POINTER(new_array->array);
	new_array->array[0] = '\0';
	return new_array;
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	array->size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if(array->size + 1 == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (char *)realloc(array->array, (array->total_size * sizeof(char)));
	}
	array->array[array->size] = new_char;
	array->array[array->size + 1] = '\0';
	array->size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( (array->size + 1) * sizeof(char));
		CHECK_POINTER(new_string);
	return strcpy(new_string, array->array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", array->array);
}

/* Functions for the AssetPortfolioType datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
AssetPortfolioType_array * init_AssetPortfolioType_array()
{
	AssetPortfolioType_array * new_array = (AssetPortfolioType_array *)malloc(sizeof(AssetPortfolioType_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (AssetPortfolioType **)malloc(ARRAY_BLOCK_SIZE * sizeof(AssetPortfolioType *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_AssetPortfolioType_array(AssetPortfolioType_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_AssetPortfolioType_array(AssetPortfolioType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_AssetPortfolioType(AssetPortfolioType_array * array, int performance_history, int_array firmstocks, int_array firm_id, double_array current_price, double_array best_ask_price, double_array best_bid_price, double_array nr_units, int_array firmbonds, int_array firmbonds_firm_id, double_array firmbonds_current_price, double_array firmbonds_best_ask_price, double_array firmbonds_best_bid_price, double_array firmbonds_nr_units, int_array govbonds, int_array govbonds_gov_id, double_array govbonds_current_price, double_array govbonds_best_ask_price, double_array govbonds_best_bid_price, double_array govbonds_nr_units)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (AssetPortfolioType **)realloc(array->array, (array->total_size * sizeof(AssetPortfolioType *)));
	}
	array->array[array->size] = (AssetPortfolioType *)malloc(sizeof(AssetPortfolioType));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->performance_history = performance_history;
	array->array[array->size]->firmstocks = firmstocks;
	array->array[array->size]->firm_id = firm_id;
	array->array[array->size]->current_price = current_price;
	array->array[array->size]->best_ask_price = best_ask_price;
	array->array[array->size]->best_bid_price = best_bid_price;
	array->array[array->size]->nr_units = nr_units;
	array->array[array->size]->firmbonds = firmbonds;
	array->array[array->size]->firmbonds_firm_id = firmbonds_firm_id;
	array->array[array->size]->firmbonds_current_price = firmbonds_current_price;
	array->array[array->size]->firmbonds_best_ask_price = firmbonds_best_ask_price;
	array->array[array->size]->firmbonds_best_bid_price = firmbonds_best_bid_price;
	array->array[array->size]->firmbonds_nr_units = firmbonds_nr_units;
	array->array[array->size]->govbonds = govbonds;
	array->array[array->size]->govbonds_gov_id = govbonds_gov_id;
	array->array[array->size]->govbonds_current_price = govbonds_current_price;
	array->array[array->size]->govbonds_best_ask_price = govbonds_best_ask_price;
	array->array[array->size]->govbonds_best_bid_price = govbonds_best_bid_price;
	array->array[array->size]->govbonds_nr_units = govbonds_nr_units;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_AssetPortfolioType(AssetPortfolioType_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the PrivateClassifierSystem datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
PrivateClassifierSystem_array * init_PrivateClassifierSystem_array()
{
	PrivateClassifierSystem_array * new_array = (PrivateClassifierSystem_array *)malloc(sizeof(PrivateClassifierSystem_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (PrivateClassifierSystem **)malloc(ARRAY_BLOCK_SIZE * sizeof(PrivateClassifierSystem *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int ids, double experience, int current_rule, double my_performance, double avgperformance, double attraction, double choiceprob, int nr_selected_rule)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (PrivateClassifierSystem **)realloc(array->array, (array->total_size * sizeof(PrivateClassifierSystem *)));
	}
	array->array[array->size] = (PrivateClassifierSystem *)malloc(sizeof(PrivateClassifierSystem));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->ids = ids;
	array->array[array->size]->experience = experience;
	array->array[array->size]->current_rule = current_rule;
	array->array[array->size]->my_performance = my_performance;
	array->array[array->size]->avgperformance = avgperformance;
	array->array[array->size]->attraction = attraction;
	array->array[array->size]->choiceprob = choiceprob;
	array->array[array->size]->nr_selected_rule = nr_selected_rule;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the PublicClassifierSystem datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
PublicClassifierSystem_array * init_PublicClassifierSystem_array()
{
	PublicClassifierSystem_array * new_array = (PublicClassifierSystem_array *)malloc(sizeof(PublicClassifierSystem_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (PublicClassifierSystem **)malloc(ARRAY_BLOCK_SIZE * sizeof(PublicClassifierSystem *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_PublicClassifierSystem_array(PublicClassifierSystem_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_PublicClassifierSystem_array(PublicClassifierSystem_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_PublicClassifierSystem(PublicClassifierSystem_array * array, int counter, double performance, double avgperformance, double performance_history)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (PublicClassifierSystem **)realloc(array->array, (array->total_size * sizeof(PublicClassifierSystem *)));
	}
	array->array[array->size] = (PublicClassifierSystem *)malloc(sizeof(PublicClassifierSystem));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->counter = counter;
	array->array[array->size]->performance = performance;
	array->array[array->size]->avgperformance = avgperformance;
	array->array[array->size]->performance_history = performance_history;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_PublicClassifierSystem(PublicClassifierSystem_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the RuleDataType datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
RuleDataType_array * init_RuleDataType_array()
{
	RuleDataType_array * new_array = (RuleDataType_array *)malloc(sizeof(RuleDataType_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (RuleDataType **)malloc(ARRAY_BLOCK_SIZE * sizeof(RuleDataType *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_RuleDataType_array(RuleDataType_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_RuleDataType_array(RuleDataType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_RuleDataType(RuleDataType_array * array, char class, int id, int performance, int counter, int avgperformance, int my_performance, int attraction, int choiceprob)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (RuleDataType **)realloc(array->array, (array->total_size * sizeof(RuleDataType *)));
	}
	array->array[array->size] = (RuleDataType *)malloc(sizeof(RuleDataType));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->class = class;
	array->array[array->size]->id = id;
	array->array[array->size]->performance = performance;
	array->array[array->size]->counter = counter;
	array->array[array->size]->avgperformance = avgperformance;
	array->array[array->size]->my_performance = my_performance;
	array->array[array->size]->attraction = attraction;
	array->array[array->size]->choiceprob = choiceprob;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_RuleDataType(RuleDataType_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the DBFinancialAssets datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
DBFinancialAssets_array * init_DBFinancialAssets_array()
{
	DBFinancialAssets_array * new_array = (DBFinancialAssets_array *)malloc(sizeof(DBFinancialAssets_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (DBFinancialAssets **)malloc(ARRAY_BLOCK_SIZE * sizeof(DBFinancialAssets *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_DBFinancialAssets_array(DBFinancialAssets_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_DBFinancialAssets_array(DBFinancialAssets_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_DBFinancialAssets(DBFinancialAssets_array * array)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (DBFinancialAssets **)realloc(array->array, (array->total_size * sizeof(DBFinancialAssets *)));
	}
	array->array[array->size] = (DBFinancialAssets *)malloc(sizeof(DBFinancialAssets));
		CHECK_POINTER(array->array[array->size]);

	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_DBFinancialAssets(DBFinancialAssets_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the BondDataType datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
BondDataType_array * init_BondDataType_array()
{
	BondDataType_array * new_array = (BondDataType_array *)malloc(sizeof(BondDataType_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (BondDataType **)malloc(ARRAY_BLOCK_SIZE * sizeof(BondDataType *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_BondDataType_array(BondDataType_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_BondDataType_array(BondDataType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_BondDataType(BondDataType_array * array, char class, int id)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (BondDataType **)realloc(array->array, (array->total_size * sizeof(BondDataType *)));
	}
	array->array[array->size] = (BondDataType *)malloc(sizeof(BondDataType));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->class = class;
	array->array[array->size]->id = id;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_BondDataType(BondDataType_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the StockDataType datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
StockDataType_array * init_StockDataType_array()
{
	StockDataType_array * new_array = (StockDataType_array *)malloc(sizeof(StockDataType_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (StockDataType **)malloc(ARRAY_BLOCK_SIZE * sizeof(StockDataType *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_StockDataType_array(StockDataType_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_StockDataType_array(StockDataType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_StockDataType(StockDataType_array * array, char class, int id, int NrOutStandingShares, int NrOutStandingShares(1:Parameters.NrDaysInitialization), double price, int Book_intraday_transaction, int dividends, int dividends(1:Parameters.NrMonthsInitialization))
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (StockDataType **)realloc(array->array, (array->total_size * sizeof(StockDataType *)));
	}
	array->array[array->size] = (StockDataType *)malloc(sizeof(StockDataType));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->class = class;
	array->array[array->size]->id = id;
	array->array[array->size]->NrOutStandingShares = NrOutStandingShares;
	array->array[array->size]->NrOutStandingShares(1:Parameters.NrDaysInitialization) = NrOutStandingShares(1:Parameters.NrDaysInitialization);
	array->array[array->size]->price = price;
	array->array[array->size]->Book_intraday_transaction = Book_intraday_transaction;
	array->array[array->size]->dividends = dividends;
	array->array[array->size]->dividends(1:Parameters.NrMonthsInitialization) = dividends(1:Parameters.NrMonthsInitialization);
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_StockDataType(StockDataType_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

