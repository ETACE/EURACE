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
	temp_firm_bond_orders_message = NULL;
	p_firm_bond_orders_message = &temp_firm_bond_orders_message;
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
	temp_fa_rule_performance_message = NULL;
	p_fa_rule_performance_message = &temp_fa_rule_performance_message;
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
	current->xmachine_ClearingHouse = NULL;
	current->xmachine_LimitOrderBook = NULL;
	current->xmachine_Government = NULL;
	current->xmachine_FinancialAgent = NULL;
	current->next = *p_xmachine;
	*p_xmachine = current;
	
	current_node->agent_total++;

/* add by cg for round-robin so that set_ has something to point at */
	//current_xmachine = current;
	
	return current;
}



string * init_string()
{
	string *temp = (string *)malloc(sizeof(string));
	CHECK_POINTER(temp);
	temp->stringname = init_char_array();

	return temp;
}

string ** init_string_static_array(int size)
{
	int i;
	string ** temp = (string **)malloc(size * sizeof(string *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_string();
	}
	
	return temp;
}

void free_string_static_array(string ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_string_datatype(temp[i]);
	}
	free(temp);
}

void free_string_datatype(string * temp)
{
	free_char_array(temp->stringname);
	free(temp);
}

void copy_string_static_array(string ** from, string ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_string_datatype(from[i], to[i]);
	}
}

void copy_string_datatype(string * from, string * to)
{
	copy_char_array(from->stringname, to->stringname);
}


stringlist * init_stringlist()
{
	stringlist *temp = (stringlist *)malloc(sizeof(stringlist));
	CHECK_POINTER(temp);
	temp->stringlistname = init_string_array();

	return temp;
}

stringlist ** init_stringlist_static_array(int size)
{
	int i;
	stringlist ** temp = (stringlist **)malloc(size * sizeof(stringlist *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_stringlist();
	}
	
	return temp;
}

void free_stringlist_static_array(stringlist ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_stringlist_datatype(temp[i]);
	}
	free(temp);
}

void free_stringlist_datatype(stringlist * temp)
{
	free_string_array(temp->stringlistname);
	free(temp);
}

void copy_stringlist_static_array(stringlist ** from, stringlist ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_stringlist_datatype(from[i], to[i]);
	}
}

void copy_stringlist_datatype(stringlist * from, stringlist * to)
{
	copy_string_array(from->stringlistname, to->stringlistname);
}


word * init_word()
{
	word *temp = (word *)malloc(sizeof(word));
	CHECK_POINTER(temp);
	temp->wordname = init_char_array();

	return temp;
}

word ** init_word_static_array(int size)
{
	int i;
	word ** temp = (word **)malloc(size * sizeof(word *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_word();
	}
	
	return temp;
}

void free_word_static_array(word ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_word_datatype(temp[i]);
	}
	free(temp);
}

void free_word_datatype(word * temp)
{
	free_char_array(temp->wordname);
	free(temp);
}

void copy_word_static_array(word ** from, word ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_word_datatype(from[i], to[i]);
	}
}

void copy_word_datatype(word * from, word * to)
{
	copy_char_array(from->wordname, to->wordname);
}


wordlist * init_wordlist()
{
	wordlist *temp = (wordlist *)malloc(sizeof(wordlist));
	CHECK_POINTER(temp);
	temp->wordlistname = init_word_array();

	return temp;
}

wordlist ** init_wordlist_static_array(int size)
{
	int i;
	wordlist ** temp = (wordlist **)malloc(size * sizeof(wordlist *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_wordlist();
	}
	
	return temp;
}

void free_wordlist_static_array(wordlist ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_wordlist_datatype(temp[i]);
	}
	free(temp);
}

void free_wordlist_datatype(wordlist * temp)
{
	free_word_array(temp->wordlistname);
	free(temp);
}

void copy_wordlist_static_array(wordlist ** from, wordlist ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_wordlist_datatype(from[i], to[i]);
	}
}

void copy_wordlist_datatype(wordlist * from, wordlist * to)
{
	copy_word_array(from->wordlistname, to->wordlistname);
}


int2D * init_int2D()
{
	int2D *temp = (int2D *)malloc(sizeof(int2D));
	CHECK_POINTER(temp);
	temp->int2Dname = init_int_array();

	return temp;
}

int2D ** init_int2D_static_array(int size)
{
	int i;
	int2D ** temp = (int2D **)malloc(size * sizeof(int2D *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_int2D();
	}
	
	return temp;
}

void free_int2D_static_array(int2D ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_int2D_datatype(temp[i]);
	}
	free(temp);
}

void free_int2D_datatype(int2D * temp)
{
	free_int_array(temp->int2Dname);
	free(temp);
}

void copy_int2D_static_array(int2D ** from, int2D ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_int2D_datatype(from[i], to[i]);
	}
}

void copy_int2D_datatype(int2D * from, int2D * to)
{
	copy_int_array(from->int2Dname, to->int2Dname);
}


double2D * init_double2D()
{
	double2D *temp = (double2D *)malloc(sizeof(double2D));
	CHECK_POINTER(temp);
	temp->double2Dname = init_double_array();

	return temp;
}

double2D ** init_double2D_static_array(int size)
{
	int i;
	double2D ** temp = (double2D **)malloc(size * sizeof(double2D *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_double2D();
	}
	
	return temp;
}

void free_double2D_static_array(double2D ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_double2D_datatype(temp[i]);
	}
	free(temp);
}

void free_double2D_datatype(double2D * temp)
{
	free_double_array(temp->double2Dname);
	free(temp);
}

void copy_double2D_static_array(double2D ** from, double2D ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_double2D_datatype(from[i], to[i]);
	}
}

void copy_double2D_datatype(double2D * from, double2D * to)
{
	copy_double_array(from->double2Dname, to->double2Dname);
}


RuleDetailSystem * init_RuleDetailSystem()
{
	RuleDetailSystem *temp = (RuleDetailSystem *)malloc(sizeof(RuleDetailSystem));
	CHECK_POINTER(temp);
	temp->nr_params_per_type = init_int_array();
	temp->nr_params = init_int_array();
	temp->parameters = init_double2D_array();
	temp->myfunctionnames = init_wordlist();

	return temp;
}

RuleDetailSystem ** init_RuleDetailSystem_static_array(int size)
{
	int i;
	RuleDetailSystem ** temp = (RuleDetailSystem **)malloc(size * sizeof(RuleDetailSystem *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_RuleDetailSystem();
	}
	
	return temp;
}

void free_RuleDetailSystem_static_array(RuleDetailSystem ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_RuleDetailSystem_datatype(temp[i]);
	}
	free(temp);
}

void free_RuleDetailSystem_datatype(RuleDetailSystem * temp)
{
	free_int_array(temp->nr_params_per_type);
	free_int_array(temp->nr_params);
	free_double2D_array(temp->parameters);
	free_wordlist_datatype(temp->myfunctionnames);
	free(temp);
}

void copy_RuleDetailSystem_static_array(RuleDetailSystem ** from, RuleDetailSystem ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_RuleDetailSystem_datatype(from[i], to[i]);
	}
}

void copy_RuleDetailSystem_datatype(RuleDetailSystem * from, RuleDetailSystem * to)
{
	copy_int_array(from->nr_params_per_type, to->nr_params_per_type);
	copy_int_array(from->nr_params, to->nr_params);
	copy_double2D_array(from->parameters, to->parameters);
	copy_wordlist_datatype(from->myfunctionnames, to->myfunctionnames);
}


PublicClassifierSystem * init_PublicClassifierSystem()
{
	PublicClassifierSystem *temp = (PublicClassifierSystem *)malloc(sizeof(PublicClassifierSystem));
	CHECK_POINTER(temp);
	temp->nr_rules_per_type = init_int_array();
	temp->ids = init_int_array();
	temp->rule_type = init_int_array();
	temp->counter = init_int_array();
	temp->performance = init_double_array();
	temp->avgperformance = init_double_array();

	return temp;
}

PublicClassifierSystem ** init_PublicClassifierSystem_static_array(int size)
{
	int i;
	PublicClassifierSystem ** temp = (PublicClassifierSystem **)malloc(size * sizeof(PublicClassifierSystem *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_PublicClassifierSystem();
	}
	
	return temp;
}

void free_PublicClassifierSystem_static_array(PublicClassifierSystem ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_PublicClassifierSystem_datatype(temp[i]);
	}
	free(temp);
}

void free_PublicClassifierSystem_datatype(PublicClassifierSystem * temp)
{
	free_int_array(temp->nr_rules_per_type);
	free_int_array(temp->ids);
	free_int_array(temp->rule_type);
	free_int_array(temp->counter);
	free_double_array(temp->performance);
	free_double_array(temp->avgperformance);
	free(temp);
}

void copy_PublicClassifierSystem_static_array(PublicClassifierSystem ** from, PublicClassifierSystem ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_PublicClassifierSystem_datatype(from[i], to[i]);
	}
}

void copy_PublicClassifierSystem_datatype(PublicClassifierSystem * from, PublicClassifierSystem * to)
{
	to->nr_types = from->nr_types;
	copy_int_array(from->nr_rules_per_type, to->nr_rules_per_type);
	to->nr_rules = from->nr_rules;
	copy_int_array(from->ids, to->ids);
	copy_int_array(from->rule_type, to->rule_type);
	copy_int_array(from->counter, to->counter);
	copy_double_array(from->performance, to->performance);
	copy_double_array(from->avgperformance, to->avgperformance);
}


PrivateClassifierSystem * init_PrivateClassifierSystem()
{
	PrivateClassifierSystem *temp = (PrivateClassifierSystem *)malloc(sizeof(PrivateClassifierSystem));
	CHECK_POINTER(temp);
	temp->nr_rules_per_type = init_int_array();
	temp->ids = init_int_array();
	temp->rule_type = init_int_array();
	temp->avgperformance = init_double_array();
	temp->attraction = init_double_array();
	temp->choiceprob = init_double_array();

	return temp;
}

PrivateClassifierSystem ** init_PrivateClassifierSystem_static_array(int size)
{
	int i;
	PrivateClassifierSystem ** temp = (PrivateClassifierSystem **)malloc(size * sizeof(PrivateClassifierSystem *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_PrivateClassifierSystem();
	}
	
	return temp;
}

void free_PrivateClassifierSystem_static_array(PrivateClassifierSystem ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_PrivateClassifierSystem_datatype(temp[i]);
	}
	free(temp);
}

void free_PrivateClassifierSystem_datatype(PrivateClassifierSystem * temp)
{
	free_int_array(temp->nr_rules_per_type);
	free_int_array(temp->ids);
	free_int_array(temp->rule_type);
	free_double_array(temp->avgperformance);
	free_double_array(temp->attraction);
	free_double_array(temp->choiceprob);
	free(temp);
}

void copy_PrivateClassifierSystem_static_array(PrivateClassifierSystem ** from, PrivateClassifierSystem ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_PrivateClassifierSystem_datatype(from[i], to[i]);
	}
}

void copy_PrivateClassifierSystem_datatype(PrivateClassifierSystem * from, PrivateClassifierSystem * to)
{
	to->nr_types = from->nr_types;
	copy_int_array(from->nr_rules_per_type, to->nr_rules_per_type);
	to->nr_rules = from->nr_rules;
	copy_int_array(from->ids, to->ids);
	copy_int_array(from->rule_type, to->rule_type);
	to->EWA_rho = from->EWA_rho;
	to->EWA_phi = from->EWA_phi;
	to->EWA_delta = from->EWA_delta;
	to->EWA_beta = from->EWA_beta;
	to->experience = from->experience;
	to->current_rule = from->current_rule;
	to->my_performance = from->my_performance;
	copy_double_array(from->avgperformance, to->avgperformance);
	copy_double_array(from->attraction, to->attraction);
	copy_double_array(from->choiceprob, to->choiceprob);
}


StockDataType * init_StockDataType()
{
	StockDataType *temp = (StockDataType *)malloc(sizeof(StockDataType));
	CHECK_POINTER(temp);
	temp->NrOutStandingShares = init_int_array();
	temp->dividends = init_int_array();

	return temp;
}

StockDataType ** init_StockDataType_static_array(int size)
{
	int i;
	StockDataType ** temp = (StockDataType **)malloc(size * sizeof(StockDataType *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_StockDataType();
	}
	
	return temp;
}

void free_StockDataType_static_array(StockDataType ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_StockDataType_datatype(temp[i]);
	}
	free(temp);
}

void free_StockDataType_datatype(StockDataType * temp)
{
	free_int_array(temp->NrOutStandingShares);
	free_int_array(temp->dividends);
	free(temp);
}

void copy_StockDataType_static_array(StockDataType ** from, StockDataType ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_StockDataType_datatype(from[i], to[i]);
	}
}

void copy_StockDataType_datatype(StockDataType * from, StockDataType * to)
{
	memcpy(to->class, from->class, 5*sizeof(char));
	memcpy(to->id, from->id, 5*sizeof(int));
	copy_int_array(from->NrOutStandingShares, to->NrOutStandingShares);
	to->price = from->price;
	to->Book_intraday_transaction = from->Book_intraday_transaction;
	copy_int_array(from->dividends, to->dividends);
}


BondDataType * init_BondDataType()
{
	BondDataType *temp = (BondDataType *)malloc(sizeof(BondDataType));
	CHECK_POINTER(temp);

	return temp;
}

BondDataType ** init_BondDataType_static_array(int size)
{
	int i;
	BondDataType ** temp = (BondDataType **)malloc(size * sizeof(BondDataType *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_BondDataType();
	}
	
	return temp;
}

void free_BondDataType_static_array(BondDataType ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_BondDataType_datatype(temp[i]);
	}
	free(temp);
}

void free_BondDataType_datatype(BondDataType * temp)
{
	free(temp);
}

void copy_BondDataType_static_array(BondDataType ** from, BondDataType ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_BondDataType_datatype(from[i], to[i]);
	}
}

void copy_BondDataType_datatype(BondDataType * from, BondDataType * to)
{
	memcpy(to->class, from->class, 5*sizeof(char));
	memcpy(to->id, from->id, 5*sizeof(int));
}


DBFinancialAssets * init_DBFinancialAssets()
{
	DBFinancialAssets *temp = (DBFinancialAssets *)malloc(sizeof(DBFinancialAssets));
	CHECK_POINTER(temp);

	return temp;
}

DBFinancialAssets ** init_DBFinancialAssets_static_array(int size)
{
	int i;
	DBFinancialAssets ** temp = (DBFinancialAssets **)malloc(size * sizeof(DBFinancialAssets *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_DBFinancialAssets();
	}
	
	return temp;
}

void free_DBFinancialAssets_static_array(DBFinancialAssets ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_DBFinancialAssets_datatype(temp[i]);
	}
	free(temp);
}

void free_DBFinancialAssets_datatype(DBFinancialAssets * temp)
{
	free(temp);
}

void copy_DBFinancialAssets_static_array(DBFinancialAssets ** from, DBFinancialAssets ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_DBFinancialAssets_datatype(from[i], to[i]);
	}
}

void copy_DBFinancialAssets_datatype(DBFinancialAssets * from, DBFinancialAssets * to)
{
}


Asset * init_Asset()
{
	Asset *temp = (Asset *)malloc(sizeof(Asset));
	CHECK_POINTER(temp);
	temp->ids = init_int_array();
	temp->nr_units = init_int_array();
	temp->current_price = init_double_array();
	temp->best_ask_price = init_double_array();
	temp->best_bid_price = init_double_array();

	return temp;
}

Asset ** init_Asset_static_array(int size)
{
	int i;
	Asset ** temp = (Asset **)malloc(size * sizeof(Asset *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_Asset();
	}
	
	return temp;
}

void free_Asset_static_array(Asset ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_Asset_datatype(temp[i]);
	}
	free(temp);
}

void free_Asset_datatype(Asset * temp)
{
	free_int_array(temp->ids);
	free_int_array(temp->nr_units);
	free_double_array(temp->current_price);
	free_double_array(temp->best_ask_price);
	free_double_array(temp->best_bid_price);
	free(temp);
}

void copy_Asset_static_array(Asset ** from, Asset ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_Asset_datatype(from[i], to[i]);
	}
}

void copy_Asset_datatype(Asset * from, Asset * to)
{
	copy_int_array(from->ids, to->ids);
	copy_int_array(from->nr_units, to->nr_units);
	copy_double_array(from->current_price, to->current_price);
	copy_double_array(from->best_ask_price, to->best_ask_price);
	copy_double_array(from->best_bid_price, to->best_bid_price);
}


AssetPortfolio * init_AssetPortfolio()
{
	AssetPortfolio *temp = (AssetPortfolio *)malloc(sizeof(AssetPortfolio));
	CHECK_POINTER(temp);
	temp->performance_history = init_double_array();
	temp->firm_stocks = init_Asset();
	temp->firm_bonds = init_Asset();
	temp->gov_bonds = init_Asset();

	return temp;
}

AssetPortfolio ** init_AssetPortfolio_static_array(int size)
{
	int i;
	AssetPortfolio ** temp = (AssetPortfolio **)malloc(size * sizeof(AssetPortfolio *));
	CHECK_POINTER(temp);
	
	for(i = 0; i < size; i++)
	{
		temp[i] = init_AssetPortfolio();
	}
	
	return temp;
}

void free_AssetPortfolio_static_array(AssetPortfolio ** temp, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		free_AssetPortfolio_datatype(temp[i]);
	}
	free(temp);
}

void free_AssetPortfolio_datatype(AssetPortfolio * temp)
{
	free_double_array(temp->performance_history);
	free_Asset_datatype(temp->firm_stocks);
	free_Asset_datatype(temp->firm_bonds);
	free_Asset_datatype(temp->gov_bonds);
	free(temp);
}

void copy_AssetPortfolio_static_array(AssetPortfolio ** from, AssetPortfolio ** to, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		copy_AssetPortfolio_datatype(from[i], to[i]);
	}
}

void copy_AssetPortfolio_datatype(AssetPortfolio * from, AssetPortfolio * to)
{
	copy_double_array(from->performance_history, to->performance_history);
	copy_Asset_datatype(from->firm_stocks, to->firm_stocks);
	copy_Asset_datatype(from->firm_bonds, to->firm_bonds);
	copy_Asset_datatype(from->gov_bonds, to->gov_bonds);
}



xmachine_memory_Household * init_Household_agent()
{
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
	CHECK_POINTER(current);
	
	current->privateclassifiersystem = init_PrivateClassifierSystem();
	current->current_assetportfolio = init_AssetPortfolio();
	current->prescribed_assetportfolio = init_AssetPortfolio();
	
	return current;
}

void add_Household_agent_internal(xmachine_memory_Household * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Household = current;
}

/** \fn void add_Household_agent(int id, PrivateClassifierSystem * privateclassifiersystem, AssetPortfolio * current_assetportfolio, AssetPortfolio * prescribed_assetportfolio, double asset_budget, double range, double posx, double posy)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param privateclassifiersystem Variable for the X-machine memory.
 * \param current_assetportfolio Variable for the X-machine memory.
 * \param prescribed_assetportfolio Variable for the X-machine memory.
 * \param asset_budget Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Household_agent(int id, PrivateClassifierSystem * privateclassifiersystem, AssetPortfolio * current_assetportfolio, AssetPortfolio * prescribed_assetportfolio, double asset_budget, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Household * current = init_Household_agent();
	new_xmachine->xmachine_Household = current;
	
	current->id = id;
	copy_PrivateClassifierSystem_datatype(privateclassifiersystem, current->privateclassifiersystem);
	copy_AssetPortfolio_datatype(current_assetportfolio, current->current_assetportfolio);
	copy_AssetPortfolio_datatype(prescribed_assetportfolio, current->prescribed_assetportfolio);
	current->asset_budget = asset_budget;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Firm * init_Firm_agent()
{
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
	CHECK_POINTER(current);
	
	current->revenues = init_double_array();
	current->sales_costs = init_double_array();
	
	return current;
}

void add_Firm_agent_internal(xmachine_memory_Firm * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Firm = current;
}

/** \fn void add_Firm_agent(int id, double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double range, double posx, double posy)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
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
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Firm_agent(int id, double_array * revenues, double_array * sales_costs, double total_revenue, double net_revenue, double operational_cost, double total_wage_payments, double total_input_payments, double interest_payments, double total_earnings, double tax_rate_profits, double pretax_profit, double tax_provision, double net_earnings, double div_payments, double retained_earnings, double current_debt, double debt_interest_rate, double debt_repayments, double share_repurchase_value, int share_repurchase_units, int target_total_shares, int current_total_shares, double total_financial_needs, double financial_needs, double add_financial_needs, double financial_reserves, double target_loans, double target_equity, double bonds_issue_target, double stocks_issue_target, double price, double max_debt, double div_earn_ratio, double debt_earn_ratio, double div_pshare_ratio, double earn_pshare_ratio, double price_earn_ratio, double retained_earn_ratio, double earn_pshare_ratio_growth, double critical_price_earn_ratio, double critical_earn_pshare_ratio, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Firm * current = init_Firm_agent();
	new_xmachine->xmachine_Firm = current;
	
	current->id = id;
	copy_double_array(revenues, current->revenues);
	copy_double_array(sales_costs, current->sales_costs);
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
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Bank * init_Bank_agent()
{
	xmachine_memory_Bank * current = (xmachine_memory_Bank *)malloc(sizeof(xmachine_memory_Bank));
	CHECK_POINTER(current);
	
	
	return current;
}

void add_Bank_agent_internal(xmachine_memory_Bank * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Bank = current;
}

/** \fn void add_Bank_agent(int id, double ra, double range, double posx, double posy)
 * \brief Add Bank X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param ra Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Bank_agent(int id, double ra, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Bank * current = init_Bank_agent();
	new_xmachine->xmachine_Bank = current;
	
	current->id = id;
	current->ra = ra;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_ClearingHouse * init_ClearingHouse_agent()
{
	xmachine_memory_ClearingHouse * current = (xmachine_memory_ClearingHouse *)malloc(sizeof(xmachine_memory_ClearingHouse));
	CHECK_POINTER(current);
	
	
	return current;
}

void add_ClearingHouse_agent_internal(xmachine_memory_ClearingHouse * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_ClearingHouse = current;
}

/** \fn void add_ClearingHouse_agent(int id, double rg, double range, double posx, double posy)
 * \brief Add ClearingHouse X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param rg Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_ClearingHouse_agent(int id, double rg, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_ClearingHouse * current = init_ClearingHouse_agent();
	new_xmachine->xmachine_ClearingHouse = current;
	
	current->id = id;
	current->rg = rg;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_LimitOrderBook * init_LimitOrderBook_agent()
{
	xmachine_memory_LimitOrderBook * current = (xmachine_memory_LimitOrderBook *)malloc(sizeof(xmachine_memory_LimitOrderBook));
	CHECK_POINTER(current);
	
	
	return current;
}

void add_LimitOrderBook_agent_internal(xmachine_memory_LimitOrderBook * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_LimitOrderBook = current;
}

/** \fn void add_LimitOrderBook_agent(int id, double re, double range, double posx, double posy)
 * \brief Add LimitOrderBook X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param re Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_LimitOrderBook_agent(int id, double re, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_LimitOrderBook * current = init_LimitOrderBook_agent();
	new_xmachine->xmachine_LimitOrderBook = current;
	
	current->id = id;
	current->re = re;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_Government * init_Government_agent()
{
	xmachine_memory_Government * current = (xmachine_memory_Government *)malloc(sizeof(xmachine_memory_Government));
	CHECK_POINTER(current);
	
	
	return current;
}

void add_Government_agent_internal(xmachine_memory_Government * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_Government = current;
}

/** \fn void add_Government_agent(int id, double rj, double range, double posx, double posy)
 * \brief Add Government X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param rj Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Government_agent(int id, double rj, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Government * current = init_Government_agent();
	new_xmachine->xmachine_Government = current;
	
	current->id = id;
	current->rj = rj;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

xmachine_memory_FinancialAgent * init_FinancialAgent_agent()
{
	xmachine_memory_FinancialAgent * current = (xmachine_memory_FinancialAgent *)malloc(sizeof(xmachine_memory_FinancialAgent));
	CHECK_POINTER(current);
	
	current->publicclassifiersystem = init_PublicClassifierSystem();
	
	return current;
}

void add_FinancialAgent_agent_internal(xmachine_memory_FinancialAgent * current)
{
	xmachine * new_xmachine = add_xmachine();
	new_xmachine->xmachine_FinancialAgent = current;
}

/** \fn void add_FinancialAgent_agent(int id, PublicClassifierSystem * publicclassifiersystem, double range, double posx, double posy)
 * \brief Add FinancialAgent X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param publicclassifiersystem Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_FinancialAgent_agent(int id, PublicClassifierSystem * publicclassifiersystem, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_FinancialAgent * current = init_FinancialAgent_agent();
	new_xmachine->xmachine_FinancialAgent = current;
	
	current->id = id;
	copy_PublicClassifierSystem_datatype(publicclassifiersystem, current->publicclassifiersystem);
	current->range = range;
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
				free_PrivateClassifierSystem_datatype(head->xmachine_Household->privateclassifiersystem);
				free_AssetPortfolio_datatype(head->xmachine_Household->current_assetportfolio);
				free_AssetPortfolio_datatype(head->xmachine_Household->prescribed_assetportfolio);
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
			if(head->xmachine_ClearingHouse)
			{
				free(head->xmachine_ClearingHouse);
			}
			if(head->xmachine_LimitOrderBook)
			{
				free(head->xmachine_LimitOrderBook);
			}
			if(head->xmachine_Government)
			{
				free(head->xmachine_Government);
			}
			if(head->xmachine_FinancialAgent)
			{
				free_PublicClassifierSystem_datatype(head->xmachine_FinancialAgent->publicclassifiersystem);
				free(head->xmachine_FinancialAgent);
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
			free(head->xmachine_Household->privateclassifiersystem);
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
		if(head->xmachine_ClearingHouse)
		{
			free(head->xmachine_ClearingHouse);
		}
		if(head->xmachine_LimitOrderBook)
		{
			free(head->xmachine_LimitOrderBook);
		}
		if(head->xmachine_Government)
		{
			free(head->xmachine_Government);
		}
		if(head->xmachine_FinancialAgent)
		{
			free(head->xmachine_FinancialAgent->publicclassifiersystem);
			free(head->xmachine_FinancialAgent);
		}
		free(head);
		head = tmp;
	}
	
	*p_xmachine = NULL;
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->id = id;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->id = id;
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->id = id;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->id = id;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->id = id;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->id = id;
	if(current_xmachine->xmachine_FinancialAgent) current_xmachine->xmachine_FinancialAgent->id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->id;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->id;
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->id;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->id;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->id;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->id;
	if(current_xmachine->xmachine_FinancialAgent) return current_xmachine->xmachine_FinancialAgent->id;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn PrivateClassifierSystem get_privateclassifiersystem()
 * \brief Get privateclassifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
PrivateClassifierSystem * get_privateclassifiersystem()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->privateclassifiersystem;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn AssetPortfolio get_current_assetportfolio()
 * \brief Get current_assetportfolio memory variable from current X-machine.
 * \return Value for variable.
 */
AssetPortfolio * get_current_assetportfolio()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->current_assetportfolio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn AssetPortfolio get_prescribed_assetportfolio()
 * \brief Get prescribed_assetportfolio memory variable from current X-machine.
 * \return Value for variable.
 */
AssetPortfolio * get_prescribed_assetportfolio()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->prescribed_assetportfolio;

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

/** \fn void set_range(double range) 
 * \brief Set range memory variable for current X-machine.
 * \param range New value for variable.
 */
void set_range(double range)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->range = range;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->range = range;
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->range = range;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->range = range;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->range = range;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->range = range;
	if(current_xmachine->xmachine_FinancialAgent) current_xmachine->xmachine_FinancialAgent->range = range;
}

/** \fn double get_range()
 * \brief Get range memory variable from current X-machine.
 * \return Value for variable.
 */
double get_range()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->range;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->range;
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->range;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->range;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->range;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->range;
	if(current_xmachine->xmachine_FinancialAgent) return current_xmachine->xmachine_FinancialAgent->range;

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
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->posx = posx;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->posx = posx;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->posx = posx;
	if(current_xmachine->xmachine_FinancialAgent) current_xmachine->xmachine_FinancialAgent->posx = posx;
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
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->posx;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->posx;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->posx;
	if(current_xmachine->xmachine_FinancialAgent) return current_xmachine->xmachine_FinancialAgent->posx;

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
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->posy = posy;
	if(current_xmachine->xmachine_LimitOrderBook) current_xmachine->xmachine_LimitOrderBook->posy = posy;
	if(current_xmachine->xmachine_Government) current_xmachine->xmachine_Government->posy = posy;
	if(current_xmachine->xmachine_FinancialAgent) current_xmachine->xmachine_FinancialAgent->posy = posy;
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
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->posy;
	if(current_xmachine->xmachine_LimitOrderBook) return current_xmachine->xmachine_LimitOrderBook->posy;
	if(current_xmachine->xmachine_Government) return current_xmachine->xmachine_Government->posy;
	if(current_xmachine->xmachine_FinancialAgent) return current_xmachine->xmachine_FinancialAgent->posy;

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

/** \fn void set_ra(double ra) 
 * \brief Set ra memory variable for current X-machine.
 * \param ra New value for variable.
 */
void set_ra(double ra)
{
	if(current_xmachine->xmachine_Bank) current_xmachine->xmachine_Bank->ra = ra;
}

/** \fn double get_ra()
 * \brief Get ra memory variable from current X-machine.
 * \return Value for variable.
 */
double get_ra()
{
	if(current_xmachine->xmachine_Bank) return current_xmachine->xmachine_Bank->ra;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_rg(double rg) 
 * \brief Set rg memory variable for current X-machine.
 * \param rg New value for variable.
 */
void set_rg(double rg)
{
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->rg = rg;
}

/** \fn double get_rg()
 * \brief Get rg memory variable from current X-machine.
 * \return Value for variable.
 */
double get_rg()
{
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->rg;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
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

/** \fn PublicClassifierSystem get_publicclassifiersystem()
 * \brief Get publicclassifiersystem memory variable from current X-machine.
 * \return Value for variable.
 */
PublicClassifierSystem * get_publicclassifiersystem()
{
	if(current_xmachine->xmachine_FinancialAgent) return current_xmachine->xmachine_FinancialAgent->publicclassifiersystem;

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
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->range;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->range;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->range;
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->range;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->range;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->range;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->range;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;
    if (current_xmachine->xmachine_Bank) value = current_xmachine->xmachine_Bank->id;
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->id;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->id;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->id;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->id;

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
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->posx;
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->posx;
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->posx;
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->posx;

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
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->posy; 
    if (current_xmachine->xmachine_LimitOrderBook) value = current_xmachine->xmachine_LimitOrderBook->posy; 
    if (current_xmachine->xmachine_Government) value = current_xmachine->xmachine_Government->posy; 
    if (current_xmachine->xmachine_FinancialAgent) value = current_xmachine->xmachine_FinancialAgent->posy; 

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
	current->firm_bond_orders_messages = NULL;
	current->firm_stock_order_messages = NULL;
	current->gov_bond_order_messages = NULL;
	current->firm_bond_transaction_messages = NULL;
	current->gov_bond_transaction_messages = NULL;
	current->firm_stock_transaction_messages = NULL;
	current->rule_performance_messages = NULL;
	current->fa_rule_performance_messages = NULL;
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
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ClearingHouse->posx;
			y_xmachine = current_xmachine->xmachine_ClearingHouse->posy;
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
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FinancialAgent->posx;
			y_xmachine = current_xmachine->xmachine_FinancialAgent->posy;
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

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();
	
	for (i = 0; i < from->size; i++)
	{
		add_int(to, from->array[i]);
	}
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

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();
	
	for (i = 0; i < from->size; i++)
	{
		add_float(to, from->array[i]);
	}
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

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();
	
	for (i = 0; i < from->size; i++)
	{
		add_double(to, from->array[i]);
	}
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

void copy_char_array(char_array * from, char_array * to)
{
	int i;
	//to = init_char_array();
	
	for (i = 0; i < from->size; i++)
	{
		add_char(to, from->array[i]);
	}
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

/* Functions for the string datatype */
/** \fn string_array * init_string_array()
 * \brief Allocate memory for a dynamic string array.
 * \return string_array Pointer to the new dynamic string array.
 */
string_array * init_string_array()
{
	string_array * new_array = (string_array *)malloc(sizeof(string_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (string **)malloc(ARRAY_BLOCK_SIZE * sizeof(string *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_string_array(string_array* array)
* \brief Reset the string array to hold nothing.
* \param array Pointer to the dynamic string array.
*/
void reset_string_array(string_array * array)
{
	array->size = 0;
}

/** \fn void free_string_array(string_array * array)
* \brief Free the memory of a dynamic string array.
* \param array Pointer to the dynamic string array.
*/
void free_string_array(string_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_string_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_string_array(string_array * from, string_array * to)
{
	int i;
	
	//to = init_string_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_string(to, from->array[i]->stringname);
	}
}

/** \fn void add_string(string_array * array, char_array stringname)
* \brief Add an string to the dynamic string array.
* \param array Pointer to the dynamic string array.
* \param new_int The string to add
*/
void add_string(string_array * array, char_array * stringname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (string **)realloc(array->array, (array->total_size * sizeof(string *)));
	}
	array->array[array->size] = init_string();
	
	array->array[array->size]->stringname = init_char_array();
	copy_char_array(stringname, array->array[array->size]->stringname);

	array->size++;
}

/** \fn void remove_string(string_array * array, int index)
 * \brief Remove an string from a dynamic string array.
 * \param array Pointer to the dynamic string array.
 * \param index The index of the string to remove.
 */
void remove_string(string_array * array, int index)
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
/* Functions for the stringlist datatype */
/** \fn stringlist_array * init_stringlist_array()
 * \brief Allocate memory for a dynamic stringlist array.
 * \return stringlist_array Pointer to the new dynamic stringlist array.
 */
stringlist_array * init_stringlist_array()
{
	stringlist_array * new_array = (stringlist_array *)malloc(sizeof(stringlist_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (stringlist **)malloc(ARRAY_BLOCK_SIZE * sizeof(stringlist *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_stringlist_array(stringlist_array* array)
* \brief Reset the stringlist array to hold nothing.
* \param array Pointer to the dynamic stringlist array.
*/
void reset_stringlist_array(stringlist_array * array)
{
	array->size = 0;
}

/** \fn void free_stringlist_array(stringlist_array * array)
* \brief Free the memory of a dynamic stringlist array.
* \param array Pointer to the dynamic stringlist array.
*/
void free_stringlist_array(stringlist_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_stringlist_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_stringlist_array(stringlist_array * from, stringlist_array * to)
{
	int i;
	
	//to = init_stringlist_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_stringlist(to, from->array[i]->stringlistname);
	}
}

/** \fn void add_stringlist(stringlist_array * array, string_array * stringlistname)
* \brief Add an stringlist to the dynamic stringlist array.
* \param array Pointer to the dynamic stringlist array.
* \param new_int The stringlist to add
*/
void add_stringlist(stringlist_array * array, string_array * stringlistname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (stringlist **)realloc(array->array, (array->total_size * sizeof(stringlist *)));
	}
	array->array[array->size] = init_stringlist();
	
	array->array[array->size]->stringlistname = init_string_array();
	copy_string_array(stringlistname, array->array[array->size]->stringlistname);

	array->size++;
}

/** \fn void remove_stringlist(stringlist_array * array, int index)
 * \brief Remove an stringlist from a dynamic stringlist array.
 * \param array Pointer to the dynamic stringlist array.
 * \param index The index of the stringlist to remove.
 */
void remove_stringlist(stringlist_array * array, int index)
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
/* Functions for the word datatype */
/** \fn word_array * init_word_array()
 * \brief Allocate memory for a dynamic word array.
 * \return word_array Pointer to the new dynamic word array.
 */
word_array * init_word_array()
{
	word_array * new_array = (word_array *)malloc(sizeof(word_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (word **)malloc(ARRAY_BLOCK_SIZE * sizeof(word *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_word_array(word_array* array)
* \brief Reset the word array to hold nothing.
* \param array Pointer to the dynamic word array.
*/
void reset_word_array(word_array * array)
{
	array->size = 0;
}

/** \fn void free_word_array(word_array * array)
* \brief Free the memory of a dynamic word array.
* \param array Pointer to the dynamic word array.
*/
void free_word_array(word_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_word_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_word_array(word_array * from, word_array * to)
{
	int i;
	
	//to = init_word_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_word(to, from->array[i]->wordname);
	}
}

/** \fn void add_word(word_array * array, char_array wordname)
* \brief Add an word to the dynamic word array.
* \param array Pointer to the dynamic word array.
* \param new_int The word to add
*/
void add_word(word_array * array, char_array * wordname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (word **)realloc(array->array, (array->total_size * sizeof(word *)));
	}
	array->array[array->size] = init_word();
	
	array->array[array->size]->wordname = init_char_array();
	copy_char_array(wordname, array->array[array->size]->wordname);

	array->size++;
}

/** \fn void remove_word(word_array * array, int index)
 * \brief Remove an word from a dynamic word array.
 * \param array Pointer to the dynamic word array.
 * \param index The index of the word to remove.
 */
void remove_word(word_array * array, int index)
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
/* Functions for the wordlist datatype */
/** \fn wordlist_array * init_wordlist_array()
 * \brief Allocate memory for a dynamic wordlist array.
 * \return wordlist_array Pointer to the new dynamic wordlist array.
 */
wordlist_array * init_wordlist_array()
{
	wordlist_array * new_array = (wordlist_array *)malloc(sizeof(wordlist_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (wordlist **)malloc(ARRAY_BLOCK_SIZE * sizeof(wordlist *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_wordlist_array(wordlist_array* array)
* \brief Reset the wordlist array to hold nothing.
* \param array Pointer to the dynamic wordlist array.
*/
void reset_wordlist_array(wordlist_array * array)
{
	array->size = 0;
}

/** \fn void free_wordlist_array(wordlist_array * array)
* \brief Free the memory of a dynamic wordlist array.
* \param array Pointer to the dynamic wordlist array.
*/
void free_wordlist_array(wordlist_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_wordlist_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_wordlist_array(wordlist_array * from, wordlist_array * to)
{
	int i;
	
	//to = init_wordlist_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_wordlist(to, from->array[i]->wordlistname);
	}
}

/** \fn void add_wordlist(wordlist_array * array, word_array * wordlistname)
* \brief Add an wordlist to the dynamic wordlist array.
* \param array Pointer to the dynamic wordlist array.
* \param new_int The wordlist to add
*/
void add_wordlist(wordlist_array * array, word_array * wordlistname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (wordlist **)realloc(array->array, (array->total_size * sizeof(wordlist *)));
	}
	array->array[array->size] = init_wordlist();
	
	array->array[array->size]->wordlistname = init_word_array();
	copy_word_array(wordlistname, array->array[array->size]->wordlistname);

	array->size++;
}

/** \fn void remove_wordlist(wordlist_array * array, int index)
 * \brief Remove an wordlist from a dynamic wordlist array.
 * \param array Pointer to the dynamic wordlist array.
 * \param index The index of the wordlist to remove.
 */
void remove_wordlist(wordlist_array * array, int index)
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
/* Functions for the int2D datatype */
/** \fn int2D_array * init_int2D_array()
 * \brief Allocate memory for a dynamic int2D array.
 * \return int2D_array Pointer to the new dynamic int2D array.
 */
int2D_array * init_int2D_array()
{
	int2D_array * new_array = (int2D_array *)malloc(sizeof(int2D_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (int2D **)malloc(ARRAY_BLOCK_SIZE * sizeof(int2D *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int2D_array(int2D_array* array)
* \brief Reset the int2D array to hold nothing.
* \param array Pointer to the dynamic int2D array.
*/
void reset_int2D_array(int2D_array * array)
{
	array->size = 0;
}

/** \fn void free_int2D_array(int2D_array * array)
* \brief Free the memory of a dynamic int2D array.
* \param array Pointer to the dynamic int2D array.
*/
void free_int2D_array(int2D_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_int2D_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_int2D_array(int2D_array * from, int2D_array * to)
{
	int i;
	
	//to = init_int2D_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_int2D(to, from->array[i]->int2Dname);
	}
}

/** \fn void add_int2D(int2D_array * array, int_array int2Dname)
* \brief Add an int2D to the dynamic int2D array.
* \param array Pointer to the dynamic int2D array.
* \param new_int The int2D to add
*/
void add_int2D(int2D_array * array, int_array * int2Dname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (int2D **)realloc(array->array, (array->total_size * sizeof(int2D *)));
	}
	array->array[array->size] = init_int2D();
	
	array->array[array->size]->int2Dname = init_int_array();
	copy_int_array(int2Dname, array->array[array->size]->int2Dname);

	array->size++;
}

/** \fn void remove_int2D(int2D_array * array, int index)
 * \brief Remove an int2D from a dynamic int2D array.
 * \param array Pointer to the dynamic int2D array.
 * \param index The index of the int2D to remove.
 */
void remove_int2D(int2D_array * array, int index)
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
/* Functions for the double2D datatype */
/** \fn double2D_array * init_double2D_array()
 * \brief Allocate memory for a dynamic double2D array.
 * \return double2D_array Pointer to the new dynamic double2D array.
 */
double2D_array * init_double2D_array()
{
	double2D_array * new_array = (double2D_array *)malloc(sizeof(double2D_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (double2D **)malloc(ARRAY_BLOCK_SIZE * sizeof(double2D *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_double2D_array(double2D_array* array)
* \brief Reset the double2D array to hold nothing.
* \param array Pointer to the dynamic double2D array.
*/
void reset_double2D_array(double2D_array * array)
{
	array->size = 0;
}

/** \fn void free_double2D_array(double2D_array * array)
* \brief Free the memory of a dynamic double2D array.
* \param array Pointer to the dynamic double2D array.
*/
void free_double2D_array(double2D_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_double2D_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_double2D_array(double2D_array * from, double2D_array * to)
{
	int i;
	
	//to = init_double2D_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_double2D(to, from->array[i]->double2Dname);
	}
}

/** \fn void add_double2D(double2D_array * array, double_array double2Dname)
* \brief Add an double2D to the dynamic double2D array.
* \param array Pointer to the dynamic double2D array.
* \param new_int The double2D to add
*/
void add_double2D(double2D_array * array, double_array * double2Dname)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (double2D **)realloc(array->array, (array->total_size * sizeof(double2D *)));
	}
	array->array[array->size] = init_double2D();
	
	array->array[array->size]->double2Dname = init_double_array();
	copy_double_array(double2Dname, array->array[array->size]->double2Dname);

	array->size++;
}

/** \fn void remove_double2D(double2D_array * array, int index)
 * \brief Remove an double2D from a dynamic double2D array.
 * \param array Pointer to the dynamic double2D array.
 * \param index The index of the double2D to remove.
 */
void remove_double2D(double2D_array * array, int index)
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
/* Functions for the RuleDetailSystem datatype */
/** \fn RuleDetailSystem_array * init_RuleDetailSystem_array()
 * \brief Allocate memory for a dynamic RuleDetailSystem array.
 * \return RuleDetailSystem_array Pointer to the new dynamic RuleDetailSystem array.
 */
RuleDetailSystem_array * init_RuleDetailSystem_array()
{
	RuleDetailSystem_array * new_array = (RuleDetailSystem_array *)malloc(sizeof(RuleDetailSystem_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (RuleDetailSystem **)malloc(ARRAY_BLOCK_SIZE * sizeof(RuleDetailSystem *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_RuleDetailSystem_array(RuleDetailSystem_array* array)
* \brief Reset the RuleDetailSystem array to hold nothing.
* \param array Pointer to the dynamic RuleDetailSystem array.
*/
void reset_RuleDetailSystem_array(RuleDetailSystem_array * array)
{
	array->size = 0;
}

/** \fn void free_RuleDetailSystem_array(RuleDetailSystem_array * array)
* \brief Free the memory of a dynamic RuleDetailSystem array.
* \param array Pointer to the dynamic RuleDetailSystem array.
*/
void free_RuleDetailSystem_array(RuleDetailSystem_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_RuleDetailSystem_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_RuleDetailSystem_array(RuleDetailSystem_array * from, RuleDetailSystem_array * to)
{
	int i;
	
	//to = init_RuleDetailSystem_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_RuleDetailSystem(to, from->array[i]->nr_params_per_type, from->array[i]->nr_params, from->array[i]->parameters, from->array[i]->myfunctionnames);
	}
}

/** \fn void add_RuleDetailSystem(RuleDetailSystem_array * array, int_array nr_params_per_type, int_array nr_params, double2D_array * parameters, wordlist * myfunctionnames)
* \brief Add an RuleDetailSystem to the dynamic RuleDetailSystem array.
* \param array Pointer to the dynamic RuleDetailSystem array.
* \param new_int The RuleDetailSystem to add
*/
void add_RuleDetailSystem(RuleDetailSystem_array * array, int_array * nr_params_per_type, int_array * nr_params, double2D_array * parameters, wordlist * myfunctionnames)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (RuleDetailSystem **)realloc(array->array, (array->total_size * sizeof(RuleDetailSystem *)));
	}
	array->array[array->size] = init_RuleDetailSystem();
	
	array->array[array->size]->nr_params_per_type = init_int_array();
	copy_int_array(nr_params_per_type, array->array[array->size]->nr_params_per_type);
	array->array[array->size]->nr_params = init_int_array();
	copy_int_array(nr_params, array->array[array->size]->nr_params);
	array->array[array->size]->parameters = init_double2D_array();
	copy_double2D_array(parameters, array->array[array->size]->parameters);
	array->array[array->size]->myfunctionnames = init_wordlist();
	copy_wordlist_datatype(myfunctionnames, array->array[array->size]->myfunctionnames);

	array->size++;
}

/** \fn void remove_RuleDetailSystem(RuleDetailSystem_array * array, int index)
 * \brief Remove an RuleDetailSystem from a dynamic RuleDetailSystem array.
 * \param array Pointer to the dynamic RuleDetailSystem array.
 * \param index The index of the RuleDetailSystem to remove.
 */
void remove_RuleDetailSystem(RuleDetailSystem_array * array, int index)
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
/** \fn PublicClassifierSystem_array * init_PublicClassifierSystem_array()
 * \brief Allocate memory for a dynamic PublicClassifierSystem array.
 * \return PublicClassifierSystem_array Pointer to the new dynamic PublicClassifierSystem array.
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

/** \fn void reset_PublicClassifierSystem_array(PublicClassifierSystem_array* array)
* \brief Reset the PublicClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic PublicClassifierSystem array.
*/
void reset_PublicClassifierSystem_array(PublicClassifierSystem_array * array)
{
	array->size = 0;
}

/** \fn void free_PublicClassifierSystem_array(PublicClassifierSystem_array * array)
* \brief Free the memory of a dynamic PublicClassifierSystem array.
* \param array Pointer to the dynamic PublicClassifierSystem array.
*/
void free_PublicClassifierSystem_array(PublicClassifierSystem_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_PublicClassifierSystem_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_PublicClassifierSystem_array(PublicClassifierSystem_array * from, PublicClassifierSystem_array * to)
{
	int i;
	
	//to = init_PublicClassifierSystem_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_PublicClassifierSystem(to, from->array[i]->nr_types, from->array[i]->nr_rules_per_type, from->array[i]->nr_rules, from->array[i]->ids, from->array[i]->rule_type, from->array[i]->counter, from->array[i]->performance, from->array[i]->avgperformance);
	}
}

/** \fn void add_PublicClassifierSystem(PublicClassifierSystem_array * array, int nr_types, int_array nr_rules_per_type, int nr_rules, int_array ids, int_array rule_type, int_array counter, double_array performance, double_array avgperformance)
* \brief Add an PublicClassifierSystem to the dynamic PublicClassifierSystem array.
* \param array Pointer to the dynamic PublicClassifierSystem array.
* \param new_int The PublicClassifierSystem to add
*/
void add_PublicClassifierSystem(PublicClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, int_array * ids, int_array * rule_type, int_array * counter, double_array * performance, double_array * avgperformance)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (PublicClassifierSystem **)realloc(array->array, (array->total_size * sizeof(PublicClassifierSystem *)));
	}
	array->array[array->size] = init_PublicClassifierSystem();
	
	array->array[array->size]->nr_types = nr_types;
	array->array[array->size]->nr_rules_per_type = init_int_array();
	copy_int_array(nr_rules_per_type, array->array[array->size]->nr_rules_per_type);
	array->array[array->size]->nr_rules = nr_rules;
	array->array[array->size]->ids = init_int_array();
	copy_int_array(ids, array->array[array->size]->ids);
	array->array[array->size]->rule_type = init_int_array();
	copy_int_array(rule_type, array->array[array->size]->rule_type);
	array->array[array->size]->counter = init_int_array();
	copy_int_array(counter, array->array[array->size]->counter);
	array->array[array->size]->performance = init_double_array();
	copy_double_array(performance, array->array[array->size]->performance);
	array->array[array->size]->avgperformance = init_double_array();
	copy_double_array(avgperformance, array->array[array->size]->avgperformance);

	array->size++;
}

/** \fn void remove_PublicClassifierSystem(PublicClassifierSystem_array * array, int index)
 * \brief Remove an PublicClassifierSystem from a dynamic PublicClassifierSystem array.
 * \param array Pointer to the dynamic PublicClassifierSystem array.
 * \param index The index of the PublicClassifierSystem to remove.
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
/* Functions for the PrivateClassifierSystem datatype */
/** \fn PrivateClassifierSystem_array * init_PrivateClassifierSystem_array()
 * \brief Allocate memory for a dynamic PrivateClassifierSystem array.
 * \return PrivateClassifierSystem_array Pointer to the new dynamic PrivateClassifierSystem array.
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

/** \fn void reset_PrivateClassifierSystem_array(PrivateClassifierSystem_array* array)
* \brief Reset the PrivateClassifierSystem array to hold nothing.
* \param array Pointer to the dynamic PrivateClassifierSystem array.
*/
void reset_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array)
{
	array->size = 0;
}

/** \fn void free_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array)
* \brief Free the memory of a dynamic PrivateClassifierSystem array.
* \param array Pointer to the dynamic PrivateClassifierSystem array.
*/
void free_PrivateClassifierSystem_array(PrivateClassifierSystem_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_PrivateClassifierSystem_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_PrivateClassifierSystem_array(PrivateClassifierSystem_array * from, PrivateClassifierSystem_array * to)
{
	int i;
	
	//to = init_PrivateClassifierSystem_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_PrivateClassifierSystem(to, from->array[i]->nr_types, from->array[i]->nr_rules_per_type, from->array[i]->nr_rules, from->array[i]->ids, from->array[i]->rule_type, from->array[i]->EWA_rho, from->array[i]->EWA_phi, from->array[i]->EWA_delta, from->array[i]->EWA_beta, from->array[i]->experience, from->array[i]->current_rule, from->array[i]->my_performance, from->array[i]->avgperformance, from->array[i]->attraction, from->array[i]->choiceprob);
	}
}

/** \fn void add_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int nr_types, int_array nr_rules_per_type, int nr_rules, int_array ids, int_array rule_type, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, int experience, int current_rule, double my_performance, double_array avgperformance, double_array attraction, double_array choiceprob)
* \brief Add an PrivateClassifierSystem to the dynamic PrivateClassifierSystem array.
* \param array Pointer to the dynamic PrivateClassifierSystem array.
* \param new_int The PrivateClassifierSystem to add
*/
void add_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int nr_types, int_array * nr_rules_per_type, int nr_rules, int_array * ids, int_array * rule_type, double EWA_rho, double EWA_phi, double EWA_delta, double EWA_beta, int experience, int current_rule, double my_performance, double_array * avgperformance, double_array * attraction, double_array * choiceprob)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (PrivateClassifierSystem **)realloc(array->array, (array->total_size * sizeof(PrivateClassifierSystem *)));
	}
	array->array[array->size] = init_PrivateClassifierSystem();
	
	array->array[array->size]->nr_types = nr_types;
	array->array[array->size]->nr_rules_per_type = init_int_array();
	copy_int_array(nr_rules_per_type, array->array[array->size]->nr_rules_per_type);
	array->array[array->size]->nr_rules = nr_rules;
	array->array[array->size]->ids = init_int_array();
	copy_int_array(ids, array->array[array->size]->ids);
	array->array[array->size]->rule_type = init_int_array();
	copy_int_array(rule_type, array->array[array->size]->rule_type);
	array->array[array->size]->EWA_rho = EWA_rho;
	array->array[array->size]->EWA_phi = EWA_phi;
	array->array[array->size]->EWA_delta = EWA_delta;
	array->array[array->size]->EWA_beta = EWA_beta;
	array->array[array->size]->experience = experience;
	array->array[array->size]->current_rule = current_rule;
	array->array[array->size]->my_performance = my_performance;
	array->array[array->size]->avgperformance = init_double_array();
	copy_double_array(avgperformance, array->array[array->size]->avgperformance);
	array->array[array->size]->attraction = init_double_array();
	copy_double_array(attraction, array->array[array->size]->attraction);
	array->array[array->size]->choiceprob = init_double_array();
	copy_double_array(choiceprob, array->array[array->size]->choiceprob);

	array->size++;
}

/** \fn void remove_PrivateClassifierSystem(PrivateClassifierSystem_array * array, int index)
 * \brief Remove an PrivateClassifierSystem from a dynamic PrivateClassifierSystem array.
 * \param array Pointer to the dynamic PrivateClassifierSystem array.
 * \param index The index of the PrivateClassifierSystem to remove.
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
/* Functions for the StockDataType datatype */
/** \fn StockDataType_array * init_StockDataType_array()
 * \brief Allocate memory for a dynamic StockDataType array.
 * \return StockDataType_array Pointer to the new dynamic StockDataType array.
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

/** \fn void reset_StockDataType_array(StockDataType_array* array)
* \brief Reset the StockDataType array to hold nothing.
* \param array Pointer to the dynamic StockDataType array.
*/
void reset_StockDataType_array(StockDataType_array * array)
{
	array->size = 0;
}

/** \fn void free_StockDataType_array(StockDataType_array * array)
* \brief Free the memory of a dynamic StockDataType array.
* \param array Pointer to the dynamic StockDataType array.
*/
void free_StockDataType_array(StockDataType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_StockDataType_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_StockDataType_array(StockDataType_array * from, StockDataType_array * to)
{
	int i;
	
	//to = init_StockDataType_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_StockDataType(to, from->array[i]->class, from->array[i]->id, from->array[i]->NrOutStandingShares, from->array[i]->price, from->array[i]->Book_intraday_transaction, from->array[i]->dividends);
	}
}

/** \fn void add_StockDataType(StockDataType_array * array, char class, int id, int_array NrOutStandingShares, double price, int Book_intraday_transaction, int_array dividends)
* \brief Add an StockDataType to the dynamic StockDataType array.
* \param array Pointer to the dynamic StockDataType array.
* \param new_int The StockDataType to add
*/
void add_StockDataType(StockDataType_array * array, char * class, int * id, int_array * NrOutStandingShares, double price, int Book_intraday_transaction, int_array * dividends)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (StockDataType **)realloc(array->array, (array->total_size * sizeof(StockDataType *)));
	}
	array->array[array->size] = init_StockDataType();
	
	memcpy(array->array[array->size]->class, class, 5*sizeof(char));
	memcpy(array->array[array->size]->id, id, 5*sizeof(int));
	array->array[array->size]->NrOutStandingShares = init_int_array();
	copy_int_array(NrOutStandingShares, array->array[array->size]->NrOutStandingShares);
	array->array[array->size]->price = price;
	array->array[array->size]->Book_intraday_transaction = Book_intraday_transaction;
	array->array[array->size]->dividends = init_int_array();
	copy_int_array(dividends, array->array[array->size]->dividends);

	array->size++;
}

/** \fn void remove_StockDataType(StockDataType_array * array, int index)
 * \brief Remove an StockDataType from a dynamic StockDataType array.
 * \param array Pointer to the dynamic StockDataType array.
 * \param index The index of the StockDataType to remove.
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
/* Functions for the BondDataType datatype */
/** \fn BondDataType_array * init_BondDataType_array()
 * \brief Allocate memory for a dynamic BondDataType array.
 * \return BondDataType_array Pointer to the new dynamic BondDataType array.
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

/** \fn void reset_BondDataType_array(BondDataType_array* array)
* \brief Reset the BondDataType array to hold nothing.
* \param array Pointer to the dynamic BondDataType array.
*/
void reset_BondDataType_array(BondDataType_array * array)
{
	array->size = 0;
}

/** \fn void free_BondDataType_array(BondDataType_array * array)
* \brief Free the memory of a dynamic BondDataType array.
* \param array Pointer to the dynamic BondDataType array.
*/
void free_BondDataType_array(BondDataType_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_BondDataType_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_BondDataType_array(BondDataType_array * from, BondDataType_array * to)
{
	int i;
	
	//to = init_BondDataType_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_BondDataType(to, from->array[i]->class, from->array[i]->id);
	}
}

/** \fn void add_BondDataType(BondDataType_array * array, char class, int id)
* \brief Add an BondDataType to the dynamic BondDataType array.
* \param array Pointer to the dynamic BondDataType array.
* \param new_int The BondDataType to add
*/
void add_BondDataType(BondDataType_array * array, char * class, int * id)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (BondDataType **)realloc(array->array, (array->total_size * sizeof(BondDataType *)));
	}
	array->array[array->size] = init_BondDataType();
	
	memcpy(array->array[array->size]->class, class, 5*sizeof(char));
	memcpy(array->array[array->size]->id, id, 5*sizeof(int));

	array->size++;
}

/** \fn void remove_BondDataType(BondDataType_array * array, int index)
 * \brief Remove an BondDataType from a dynamic BondDataType array.
 * \param array Pointer to the dynamic BondDataType array.
 * \param index The index of the BondDataType to remove.
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
/* Functions for the DBFinancialAssets datatype */
/** \fn DBFinancialAssets_array * init_DBFinancialAssets_array()
 * \brief Allocate memory for a dynamic DBFinancialAssets array.
 * \return DBFinancialAssets_array Pointer to the new dynamic DBFinancialAssets array.
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

/** \fn void reset_DBFinancialAssets_array(DBFinancialAssets_array* array)
* \brief Reset the DBFinancialAssets array to hold nothing.
* \param array Pointer to the dynamic DBFinancialAssets array.
*/
void reset_DBFinancialAssets_array(DBFinancialAssets_array * array)
{
	array->size = 0;
}

/** \fn void free_DBFinancialAssets_array(DBFinancialAssets_array * array)
* \brief Free the memory of a dynamic DBFinancialAssets array.
* \param array Pointer to the dynamic DBFinancialAssets array.
*/
void free_DBFinancialAssets_array(DBFinancialAssets_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_DBFinancialAssets_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_DBFinancialAssets_array(DBFinancialAssets_array * from, DBFinancialAssets_array * to)
{
	int i;
	
	//to = init_DBFinancialAssets_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_DBFinancialAssets(to);
	}
}

/** \fn void add_DBFinancialAssets(DBFinancialAssets_array * array)
* \brief Add an DBFinancialAssets to the dynamic DBFinancialAssets array.
* \param array Pointer to the dynamic DBFinancialAssets array.
* \param new_int The DBFinancialAssets to add
*/
void add_DBFinancialAssets(DBFinancialAssets_array * array)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (DBFinancialAssets **)realloc(array->array, (array->total_size * sizeof(DBFinancialAssets *)));
	}
	array->array[array->size] = init_DBFinancialAssets();
	

	array->size++;
}

/** \fn void remove_DBFinancialAssets(DBFinancialAssets_array * array, int index)
 * \brief Remove an DBFinancialAssets from a dynamic DBFinancialAssets array.
 * \param array Pointer to the dynamic DBFinancialAssets array.
 * \param index The index of the DBFinancialAssets to remove.
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
/* Functions for the Asset datatype */
/** \fn Asset_array * init_Asset_array()
 * \brief Allocate memory for a dynamic Asset array.
 * \return Asset_array Pointer to the new dynamic Asset array.
 */
Asset_array * init_Asset_array()
{
	Asset_array * new_array = (Asset_array *)malloc(sizeof(Asset_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (Asset **)malloc(ARRAY_BLOCK_SIZE * sizeof(Asset *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_Asset_array(Asset_array* array)
* \brief Reset the Asset array to hold nothing.
* \param array Pointer to the dynamic Asset array.
*/
void reset_Asset_array(Asset_array * array)
{
	array->size = 0;
}

/** \fn void free_Asset_array(Asset_array * array)
* \brief Free the memory of a dynamic Asset array.
* \param array Pointer to the dynamic Asset array.
*/
void free_Asset_array(Asset_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_Asset_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_Asset_array(Asset_array * from, Asset_array * to)
{
	int i;
	
	//to = init_Asset_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_Asset(to, from->array[i]->ids, from->array[i]->nr_units, from->array[i]->current_price, from->array[i]->best_ask_price, from->array[i]->best_bid_price);
	}
}

/** \fn void add_Asset(Asset_array * array, int_array ids, int_array nr_units, double_array current_price, double_array best_ask_price, double_array best_bid_price)
* \brief Add an Asset to the dynamic Asset array.
* \param array Pointer to the dynamic Asset array.
* \param new_int The Asset to add
*/
void add_Asset(Asset_array * array, int_array * ids, int_array * nr_units, double_array * current_price, double_array * best_ask_price, double_array * best_bid_price)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (Asset **)realloc(array->array, (array->total_size * sizeof(Asset *)));
	}
	array->array[array->size] = init_Asset();
	
	array->array[array->size]->ids = init_int_array();
	copy_int_array(ids, array->array[array->size]->ids);
	array->array[array->size]->nr_units = init_int_array();
	copy_int_array(nr_units, array->array[array->size]->nr_units);
	array->array[array->size]->current_price = init_double_array();
	copy_double_array(current_price, array->array[array->size]->current_price);
	array->array[array->size]->best_ask_price = init_double_array();
	copy_double_array(best_ask_price, array->array[array->size]->best_ask_price);
	array->array[array->size]->best_bid_price = init_double_array();
	copy_double_array(best_bid_price, array->array[array->size]->best_bid_price);

	array->size++;
}

/** \fn void remove_Asset(Asset_array * array, int index)
 * \brief Remove an Asset from a dynamic Asset array.
 * \param array Pointer to the dynamic Asset array.
 * \param index The index of the Asset to remove.
 */
void remove_Asset(Asset_array * array, int index)
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
/* Functions for the AssetPortfolio datatype */
/** \fn AssetPortfolio_array * init_AssetPortfolio_array()
 * \brief Allocate memory for a dynamic AssetPortfolio array.
 * \return AssetPortfolio_array Pointer to the new dynamic AssetPortfolio array.
 */
AssetPortfolio_array * init_AssetPortfolio_array()
{
	AssetPortfolio_array * new_array = (AssetPortfolio_array *)malloc(sizeof(AssetPortfolio_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (AssetPortfolio **)malloc(ARRAY_BLOCK_SIZE * sizeof(AssetPortfolio *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_AssetPortfolio_array(AssetPortfolio_array* array)
* \brief Reset the AssetPortfolio array to hold nothing.
* \param array Pointer to the dynamic AssetPortfolio array.
*/
void reset_AssetPortfolio_array(AssetPortfolio_array * array)
{
	array->size = 0;
}

/** \fn void free_AssetPortfolio_array(AssetPortfolio_array * array)
* \brief Free the memory of a dynamic AssetPortfolio array.
* \param array Pointer to the dynamic AssetPortfolio array.
*/
void free_AssetPortfolio_array(AssetPortfolio_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free_AssetPortfolio_datatype(array->array[i]);
	}
	free(array->array);
	free(array);
}

void copy_AssetPortfolio_array(AssetPortfolio_array * from, AssetPortfolio_array * to)
{
	int i;
	
	//to = init_AssetPortfolio_array();
	
	for(i = 0; i < from->size; i++)
	{
		add_AssetPortfolio(to, from->array[i]->performance_history, from->array[i]->firm_stocks, from->array[i]->firm_bonds, from->array[i]->gov_bonds);
	}
}

/** \fn void add_AssetPortfolio(AssetPortfolio_array * array, double_array performance_history, Asset * firm_stocks, Asset * firm_bonds, Asset * gov_bonds)
* \brief Add an AssetPortfolio to the dynamic AssetPortfolio array.
* \param array Pointer to the dynamic AssetPortfolio array.
* \param new_int The AssetPortfolio to add
*/
void add_AssetPortfolio(AssetPortfolio_array * array, double_array * performance_history, Asset * firm_stocks, Asset * firm_bonds, Asset * gov_bonds)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (AssetPortfolio **)realloc(array->array, (array->total_size * sizeof(AssetPortfolio *)));
	}
	array->array[array->size] = init_AssetPortfolio();
	
	array->array[array->size]->performance_history = init_double_array();
	copy_double_array(performance_history, array->array[array->size]->performance_history);
	array->array[array->size]->firm_stocks = init_Asset();
	copy_Asset_datatype(firm_stocks, array->array[array->size]->firm_stocks);
	array->array[array->size]->firm_bonds = init_Asset();
	copy_Asset_datatype(firm_bonds, array->array[array->size]->firm_bonds);
	array->array[array->size]->gov_bonds = init_Asset();
	copy_Asset_datatype(gov_bonds, array->array[array->size]->gov_bonds);

	array->size++;
}

/** \fn void remove_AssetPortfolio(AssetPortfolio_array * array, int index)
 * \brief Remove an AssetPortfolio from a dynamic AssetPortfolio array.
 * \param array Pointer to the dynamic AssetPortfolio array.
 * \param index The index of the AssetPortfolio to remove.
 */
void remove_AssetPortfolio(AssetPortfolio_array * array, int index)
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

