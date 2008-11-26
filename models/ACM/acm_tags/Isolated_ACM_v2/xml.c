/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
void read_int_static_array(char * buffer, int * j, int * int_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		int_static_array[arraycount] = atoi(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
void read_float_static_array(char * buffer, int * j, float * float_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		float_static_array[arraycount] = atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
void read_double_static_array(char * buffer, int * j, double * double_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		double_static_array[arraycount] = atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
void read_char_static_array(char * buffer, int * j, char * char_static_array, int size)
{
	while(buffer[(*j)] != '\0')
	{
		/* Add check here for buffer overrun */
		char_static_array[(*j)] = buffer[(*j)];
		
		(*j)++;
	}
	
	(*j)++;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
void read_int_dynamic_array(char * buffer, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_int(int_dynamic_array, atoi(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
void read_float_dynamic_array(char * buffer, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_float(float_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
void read_double_dynamic_array(char * buffer, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	(*j)++;
	
	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_double(double_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}
	
	(*j)++;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
void read_char_dynamic_array(char * buffer, int * j, char_array * char_dynamic_array)
{
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
}


/** \fn void read_residual_var_datatype(char * buffer, int * j, residual_var_datatype * temp_datatype)
 * \brief Reads residual_var_datatype datatype.
 */
void read_residual_var_datatype(char * buffer, int * j, residual_var_datatype * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).value, 10);
	}
	
	(*j)++;
}

void read_residual_var_datatype_dynamic_array(char * buffer, int * j, residual_var_datatype_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_residual_var_datatype(temp_datatype_array, NULL);
			read_residual_var_datatype(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_residual_var_datatype_static_array(char * buffer, int * j, residual_var_datatype * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_residual_var_datatype(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_debt_item(char * buffer, int * j, debt_item * temp_datatype)
 * \brief Reads debt_item datatype.
 */
void read_debt_item(char * buffer, int * j, debt_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).bank_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).bank_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).loan_value = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).loan_value = atof(arraydata);
	(*j)++;
	(*temp_datatype).interest_rate = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).interest_rate = atof(arraydata);
	(*j)++;
	(*temp_datatype).installment_amount = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).installment_amount = atof(arraydata);
	(*j)++;
	(*temp_datatype).var_per_installment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).var_per_installment = atof(arraydata);
	(*j)++;
	(*temp_datatype).residual_var = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).residual_var = atof(arraydata);
	(*j)++;
	(*temp_datatype).bad_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).bad_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).nr_periods_before_repayment = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_periods_before_repayment = atoi(arraydata);
	(*j)++;
}

void read_debt_item_dynamic_array(char * buffer, int * j, debt_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_debt_item(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
			read_debt_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_debt_item_static_array(char * buffer, int * j, debt_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_debt_item(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_capital_stock_item(char * buffer, int * j, capital_stock_item * temp_datatype)
 * \brief Reads capital_stock_item datatype.
 */
void read_capital_stock_item(char * buffer, int * j, capital_stock_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).units = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).units = atof(arraydata);
	(*j)++;
	(*temp_datatype).purchase_price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).purchase_price = atof(arraydata);
	(*j)++;
	(*temp_datatype).productivity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).productivity = atof(arraydata);
	(*j)++;
	(*temp_datatype).depreciation_units_per_period = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).depreciation_units_per_period = atof(arraydata);
	(*j)++;
}

void read_capital_stock_item_dynamic_array(char * buffer, int * j, capital_stock_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_capital_stock_item(temp_datatype_array, 0.0, 0.0, 0.0, 0.0);
			read_capital_stock_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_capital_stock_item_static_array(char * buffer, int * j, capital_stock_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_capital_stock_item(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_mall_info(char * buffer, int * j, mall_info * temp_datatype)
 * \brief Reads mall_info datatype.
 */
void read_mall_info(char * buffer, int * j, mall_info * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).mall_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).critical_stock = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).critical_stock = atof(arraydata);
	(*j)++;
	(*temp_datatype).current_stock = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_stock = atof(arraydata);
	(*j)++;
}

void read_mall_info_dynamic_array(char * buffer, int * j, mall_info_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_info(temp_datatype_array, 0, 0.0, 0.0);
			read_mall_info(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_mall_info_static_array(char * buffer, int * j, mall_info * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_mall_info(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, int * itno, double cloud_data[6], 
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[100000];
	char agentname[1000];
	//char arraydata[10000];
	//int array_k=0, arraycount=0;
	int j;

/* Things for round-robin partitioning */
	int agent_count;
	int number_partitions;
	int geometric=1;
	int other=2;
	double 	xmax=0,xmin=0,ymax=0,ymin=0,
		xcentre=0,ycentre=0,
		rrange=1.5;
	double posx=0.0, posy=0.0, posz=0.0;
	
	
	/* Cloud data array initialisation */
	cloud_data[0] = SPINF; cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF; cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF; cloud_data[5] = -SPINF;
	
	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading, i;
	int in_tag, in_itno, in_agent, in_name, in_environment, in_memory, in_functions;
	int in_Firm_agent;
	int in_Bank_agent;
	int in_Dummy_agent;

	int in_id;
	int in_region_id;
	int in_gov_id;
	int in_day_of_month_to_act;
	int in_payment_account;
	int in_bank_id;
	int in_dmarketmatrix;
	int in_residual_var;
	int in_ebit;
	int in_earnings;
	int in_tax_rate_corporate;
	int in_tax_rate_vat;
	int in_tax_payment;
	int in_net_earnings;
	int in_previous_net_earnings;
	int in_earnings_per_share;
	int in_cum_total_sold_quantity;
	int in_cum_revenue;
	int in_production_costs;
	int in_current_shares_outstanding;
	int in_total_payments;
	int in_current_mall_stocks;
	int in_price;
	int in_total_interest_payment;
	int in_total_debt_installment_payment;
	int in_total_dividend_payment;
	int in_current_share_price;
	int in_previous_dividend_per_share;
	int in_current_dividend_per_share;
	int in_previous_earnings_per_share;
	int in_current_earnings_per_share;
	int in_previous_dividend_per_earnings;
	int in_current_dividend_per_earnings;
	int in_debt_earnings_ratio;
	int in_debt_equity_ratio;
	int in_price_earnings_ratio;
	int in_retained_earnings_ratio;
	int in_earnings_per_share_ratio_growth;
	int in_critical_price_earnings_ratio;
	int in_critical_earnings_per_share_ratio;
	int in_loans;
	int in_total_debt;
	int in_total_value_local_inventory;
	int in_capital_stock;
	int in_total_units_capital_stock;
	int in_total_value_capital_stock;
	int in_total_capital_depreciation_value;
	int in_total_capital_depreciation_units;
	int in_total_assets;
	int in_equity;
	int in_production_liquidity_needs;
	int in_financial_liquidity_needs;
	int in_total_financial_needs;
	int in_external_financial_needs;
	int in_bankruptcy_state;
	int in_financial_crisis_state;
	int in_neighboring_region_ids;
	int in_no_regions;
	int in_cash;
	int in_total_credit;
	int in_bce_debt;
	int in_alfa;
	int in_value_at_risk;
	int in_min_interest;
	int in_bank_gamma;
	int in_profits;
	int in_bank_lambda;
	int in_bce_interest;
	int in_bank_dividend_rate;
	int in_number_of_shares;
	int in_debt_period;
	int in_loan_request_message_found;

	int in_number_of_banks_to_apply;

	/* Variables for initial state data */
//	int id;
//	int region_id;
//	int gov_id;
//	int day_of_month_to_act;
//	double payment_account;
//	int bank_id;
//	int dmarketmatrix[10];
//	residual_var_datatype ** residual_var;
//	double ebit;
//	double earnings;
//	double tax_rate_corporate;
//	double tax_rate_vat;
//	double tax_payment;
//	double net_earnings;
//	double previous_net_earnings;
//	double earnings_per_share;
//	double cum_total_sold_quantity;
//	double cum_revenue;
//	double production_costs;
//	int current_shares_outstanding;
//	double total_payments;
//	mall_info_array * current_mall_stocks;
//	double price;
//	double total_interest_payment;
//	double total_debt_installment_payment;
//	double total_dividend_payment;
//	double current_share_price;
//	double previous_dividend_per_share;
//	double current_dividend_per_share;
//	double previous_earnings_per_share;
//	double current_earnings_per_share;
//	double previous_dividend_per_earnings;
//	double current_dividend_per_earnings;
//	double debt_earnings_ratio;
//	double debt_equity_ratio;
//	double price_earnings_ratio;
//	double retained_earnings_ratio;
//	double earnings_per_share_ratio_growth;
//	double critical_price_earnings_ratio;
//	double critical_earnings_per_share_ratio;
//	debt_item_array * loans;
//	double total_debt;
//	double total_value_local_inventory;
//	capital_stock_item_array * capital_stock;
//	double total_units_capital_stock;
//	double total_value_capital_stock;
//	double total_capital_depreciation_value;
//	double total_capital_depreciation_units;
//	double total_assets;
//	double equity;
//	double production_liquidity_needs;
//	double financial_liquidity_needs;
//	double total_financial_needs;
//	double external_financial_needs;
//	int bankruptcy_state;
//	int financial_crisis_state;
//	int_array * neighboring_region_ids;
//	int no_regions;
//	double cash;
//	double total_credit;
//	double bce_debt;
//	double alfa;
//	double value_at_risk;
//	double min_interest;
//	double bank_gamma[2];
//	double profits[2];
//	double bank_lambda;
//	double bce_interest;
//	double bank_dividend_rate;
//	int number_of_shares;
//	double debt_period;
//	int loan_request_message_found;


	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_Dummy * current_Dummy_agent;


	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("error opening initial states\n");
		exit(0);
	}
	/* Initialise variables */
    *itno = 0;
	/* TODO: initialise static arrays with zero for each element? */
	next_avaliable_id = -1;
	reading = 1;
	i = 0;
	in_tag = 0;
	in_itno = 0;
	in_agent = 0;
	in_name = 0;
	in_environment = 0;
	in_memory = 0;
	in_functions = 0;
	in_Firm_agent = 0;
	in_Bank_agent = 0;
	in_Dummy_agent = 0;
	in_id = 0;
	in_region_id = 0;
	in_gov_id = 0;
	in_day_of_month_to_act = 0;
	in_payment_account = 0;
	in_bank_id = 0;
	in_dmarketmatrix = 0;
	in_residual_var = 0;
	in_ebit = 0;
	in_earnings = 0;
	in_tax_rate_corporate = 0;
	in_tax_rate_vat = 0;
	in_tax_payment = 0;
	in_net_earnings = 0;
	in_previous_net_earnings = 0;
	in_earnings_per_share = 0;
	in_cum_total_sold_quantity = 0;
	in_cum_revenue = 0;
	in_production_costs = 0;
	in_current_shares_outstanding = 0;
	in_total_payments = 0;
	in_current_mall_stocks = 0;
	in_price = 0;
	in_total_interest_payment = 0;
	in_total_debt_installment_payment = 0;
	in_total_dividend_payment = 0;
	in_current_share_price = 0;
	in_previous_dividend_per_share = 0;
	in_current_dividend_per_share = 0;
	in_previous_earnings_per_share = 0;
	in_current_earnings_per_share = 0;
	in_previous_dividend_per_earnings = 0;
	in_current_dividend_per_earnings = 0;
	in_debt_earnings_ratio = 0;
	in_debt_equity_ratio = 0;
	in_price_earnings_ratio = 0;
	in_retained_earnings_ratio = 0;
	in_earnings_per_share_ratio_growth = 0;
	in_critical_price_earnings_ratio = 0;
	in_critical_earnings_per_share_ratio = 0;
	in_loans = 0;
	in_total_debt = 0;
	in_total_value_local_inventory = 0;
	in_capital_stock = 0;
	in_total_units_capital_stock = 0;
	in_total_value_capital_stock = 0;
	in_total_capital_depreciation_value = 0;
	in_total_capital_depreciation_units = 0;
	in_total_assets = 0;
	in_equity = 0;
	in_production_liquidity_needs = 0;
	in_financial_liquidity_needs = 0;
	in_total_financial_needs = 0;
	in_external_financial_needs = 0;
	in_bankruptcy_state = 0;
	in_financial_crisis_state = 0;
	in_neighboring_region_ids = 0;
	in_no_regions = 0;
	in_cash = 0;
	in_total_credit = 0;
	in_bce_debt = 0;
	in_alfa = 0;
	in_value_at_risk = 0;
	in_min_interest = 0;
	in_bank_gamma = 0;
	in_profits = 0;
	in_bank_lambda = 0;
	in_bce_interest = 0;
	in_bank_dividend_rate = 0;
	in_number_of_shares = 0;
	in_debt_period = 0;
	in_loan_request_message_found = 0;
	in_number_of_banks_to_apply = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	region_id = 0;
//	gov_id = 0;
//	day_of_month_to_act = 0;
//	payment_account = 0.0;
//	bank_id = 0;
////	residual_var = init_residual_var_datatype_static_array(10);
//	ebit = 0.0;
//	earnings = 0.0;
//	tax_rate_corporate = 0.0;
//	tax_rate_vat = 0.0;
//	tax_payment = 0.0;
//	net_earnings = 0.0;
//	previous_net_earnings = 0.0;
//	earnings_per_share = 0.0;
//	cum_total_sold_quantity = 0.0;
//	cum_revenue = 0.0;
//	production_costs = 0.0;
//	current_shares_outstanding = 0;
//	total_payments = 0.0;
//	current_mall_stocks = init_mall_info_array();
//	price = 0.0;
//	total_interest_payment = 0.0;
//	total_debt_installment_payment = 0.0;
//	total_dividend_payment = 0.0;
//	current_share_price = 0.0;
//	previous_dividend_per_share = 0.0;
//	current_dividend_per_share = 0.0;
//	previous_earnings_per_share = 0.0;
//	current_earnings_per_share = 0.0;
//	previous_dividend_per_earnings = 0.0;
//	current_dividend_per_earnings = 0.0;
//	debt_earnings_ratio = 0.0;
//	debt_equity_ratio = 0.0;
//	price_earnings_ratio = 0.0;
//	retained_earnings_ratio = 0.0;
//	earnings_per_share_ratio_growth = 0.0;
//	critical_price_earnings_ratio = 0.0;
//	critical_earnings_per_share_ratio = 0.0;
//	loans = init_debt_item_array();
//	total_debt = 0.0;
//	total_value_local_inventory = 0.0;
//	capital_stock = init_capital_stock_item_array();
//	total_units_capital_stock = 0.0;
//	total_value_capital_stock = 0.0;
//	total_capital_depreciation_value = 0.0;
//	total_capital_depreciation_units = 0.0;
//	total_assets = 0.0;
//	equity = 0.0;
//	production_liquidity_needs = 0.0;
//	financial_liquidity_needs = 0.0;
//	total_financial_needs = 0.0;
//	external_financial_needs = 0.0;
//	bankruptcy_state = 0;
//	financial_crisis_state = 0;
//	neighboring_region_ids = init_int_array();
//	no_regions = 0;
//	cash = 0.0;
//	total_credit = 0.0;
//	bce_debt = 0.0;
//	alfa = 0.0;
//	value_at_risk = 0.0;
//	min_interest = 0.0;
//////	bank_lambda = 0.0;
//	bce_interest = 0.0;
//	bank_dividend_rate = 0.0;
//	number_of_shares = 0;
//	debt_period = 0.0;
//	loan_request_message_found = 0;

	number_of_banks_to_apply = 0;






	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list 
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */ 
	//p_xmachine = agent_list;
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;
	
	/* Read file until end of xml */
	while(reading==1)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		
		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;
			
			if(strcmp(buffer, "states") == 0) reading = 1;
			if(strcmp(buffer, "/states") == 0) reading = 0;
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "name") == 0) in_name = 1;
			if(strcmp(buffer, "/name") == 0)
			{
				in_name = 0;
				
				if(in_agent && !in_memory && !in_functions)
				{
					/*printf("in agent: %s\n", agentname);*/
					if(strcmp(agentname, "Firm") == 0)
					{
						current_Firm_agent = init_Firm_agent();
						in_Firm_agent = 1;
					}
					else if(strcmp(agentname, "Bank") == 0)
					{
						current_Bank_agent = init_Bank_agent();
						in_Bank_agent = 1;
					}
					else if(strcmp(agentname, "Dummy") == 0)
					{
						current_Dummy_agent = init_Dummy_agent();
						in_Dummy_agent = 1;
					}

				}
			}
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "memory") == 0) in_memory = 1;
			if(strcmp(buffer, "/memory") == 0) in_memory = 0;
			if(strcmp(buffer, "functions") == 0) in_functions = 1;
			if(strcmp(buffer, "/functions") == 0) in_functions = 0;
			if(strcmp(buffer, "xagent") == 0) in_agent = 1;
			if(strcmp(buffer, "/xagent") == 0)
			{
				in_agent = 0;
				in_Firm_agent = 0;
in_Bank_agent = 0;
in_Dummy_agent = 0;

				
				if(strcmp(agentname, "Firm") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, bank_id, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, cum_total_sold_quantity, cum_revenue, production_costs, current_shares_outstanding, total_payments, current_mall_stocks, price, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, bankruptcy_state, financial_crisis_state);
						add_Firm_agent_internal(current_Firm_agent, Firm_02_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, bank_id, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, cum_total_sold_quantity, cum_revenue, production_costs, current_shares_outstanding, total_payments, current_mall_stocks, price, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, bankruptcy_state, financial_crisis_state);
								add_Firm_agent_internal(current_Firm_agent, Firm_02_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, bank_id, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, cum_total_sold_quantity, cum_revenue, production_costs, current_shares_outstanding, total_payments, current_mall_stocks, price, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, bankruptcy_state, financial_crisis_state);
								add_Firm_agent_internal(current_Firm_agent, Firm_02_state);

								/*current_Firm_agent->0.0 = xcentre;
								current_Firm_agent->0.0 = ycentre;
								current_Firm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Bank") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Bank_agent(id, region_id, gov_id, cash, total_credit, equity, bce_debt, alfa, value_at_risk, min_interest, bank_gamma, profits, bank_lambda, bce_interest, bank_dividend_rate, tax_rate_corporate, number_of_shares, debt_period, loan_request_message_found, day_of_month_to_act);
						add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_credit_market_role_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, region_id, gov_id, cash, total_credit, equity, bce_debt, alfa, value_at_risk, min_interest, bank_gamma, profits, bank_lambda, bce_interest, bank_dividend_rate, tax_rate_corporate, number_of_shares, debt_period, loan_request_message_found, day_of_month_to_act);
								add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_credit_market_role_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, region_id, gov_id, cash, total_credit, equity, bce_debt, alfa, value_at_risk, min_interest, bank_gamma, profits, bank_lambda, bce_interest, bank_dividend_rate, tax_rate_corporate, number_of_shares, debt_period, loan_request_message_found, day_of_month_to_act);
								add_Bank_agent_internal(current_Bank_agent, Bank_Bank_start_credit_market_role_state);

								/*current_Bank_agent->0.0 = xcentre;
								current_Bank_agent->0.0 = ycentre;
								current_Bank_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Dummy") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Dummy_agent(id);
						add_Dummy_agent_internal(current_Dummy_agent, Dummy_001_state);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}

					else if (flag != 0)
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								//p_xmachine = &(current_node->agents);
								//add_Dummy_agent(id);
								add_Dummy_agent_internal(current_Dummy_agent, Dummy_001_state);
							} 
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								//p_xmachine = &(current_node->agents);
								//add_Dummy_agent(id);
								add_Dummy_agent_internal(current_Dummy_agent, Dummy_001_state);

								/*current_Dummy_agent->0.0 = xcentre;
								current_Dummy_agent->0.0 = ycentre;
								current_Dummy_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
				}
				

				
				/* Reset xagent variables */
				/* Not implemented static arrays */
//				id = 0;
//				region_id = 0;
//				gov_id = 0;
//				day_of_month_to_act = 0;
//				payment_account = 0.0;
//				bank_id = 0;
//////				ebit = 0.0;
//				earnings = 0.0;
//				tax_rate_corporate = 0.0;
//				tax_rate_vat = 0.0;
//				tax_payment = 0.0;
//				net_earnings = 0.0;
//				previous_net_earnings = 0.0;
//				earnings_per_share = 0.0;
//				cum_total_sold_quantity = 0.0;
//				cum_revenue = 0.0;
//				production_costs = 0.0;
//				current_shares_outstanding = 0;
//				total_payments = 0.0;
////				price = 0.0;
//				total_interest_payment = 0.0;
//				total_debt_installment_payment = 0.0;
//				total_dividend_payment = 0.0;
//				current_share_price = 0.0;
//				previous_dividend_per_share = 0.0;
//				current_dividend_per_share = 0.0;
//				previous_earnings_per_share = 0.0;
//				current_earnings_per_share = 0.0;
//				previous_dividend_per_earnings = 0.0;
//				current_dividend_per_earnings = 0.0;
//				debt_earnings_ratio = 0.0;
//				debt_equity_ratio = 0.0;
//				price_earnings_ratio = 0.0;
//				retained_earnings_ratio = 0.0;
//				earnings_per_share_ratio_growth = 0.0;
//				critical_price_earnings_ratio = 0.0;
//				critical_earnings_per_share_ratio = 0.0;
////				total_debt = 0.0;
//				total_value_local_inventory = 0.0;
////				total_units_capital_stock = 0.0;
//				total_value_capital_stock = 0.0;
//				total_capital_depreciation_value = 0.0;
//				total_capital_depreciation_units = 0.0;
//				total_assets = 0.0;
//				equity = 0.0;
//				production_liquidity_needs = 0.0;
//				financial_liquidity_needs = 0.0;
//				total_financial_needs = 0.0;
//				external_financial_needs = 0.0;
//				bankruptcy_state = 0;
//				financial_crisis_state = 0;
////				no_regions = 0;
//				cash = 0.0;
//				total_credit = 0.0;
//				bce_debt = 0.0;
//				alfa = 0.0;
//				value_at_risk = 0.0;
//				min_interest = 0.0;
//////				bank_lambda = 0.0;
//				bce_interest = 0.0;
//				bank_dividend_rate = 0.0;
//				number_of_shares = 0;
//				debt_period = 0.0;
//				loan_request_message_found = 0;

	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "region_id") == 0) in_region_id = 1;
			if(strcmp(buffer, "/region_id") == 0) in_region_id = 0;
			if(strcmp(buffer, "gov_id") == 0) in_gov_id = 1;
			if(strcmp(buffer, "/gov_id") == 0) in_gov_id = 0;
			if(strcmp(buffer, "day_of_month_to_act") == 0) in_day_of_month_to_act = 1;
			if(strcmp(buffer, "/day_of_month_to_act") == 0) in_day_of_month_to_act = 0;
			if(strcmp(buffer, "payment_account") == 0) in_payment_account = 1;
			if(strcmp(buffer, "/payment_account") == 0) in_payment_account = 0;
			if(strcmp(buffer, "bank_id") == 0) in_bank_id = 1;
			if(strcmp(buffer, "/bank_id") == 0) in_bank_id = 0;
			if(strcmp(buffer, "dmarketmatrix") == 0) in_dmarketmatrix = 1;
			if(strcmp(buffer, "/dmarketmatrix") == 0) in_dmarketmatrix = 0;
			if(strcmp(buffer, "residual_var") == 0) in_residual_var = 1;
			if(strcmp(buffer, "/residual_var") == 0) in_residual_var = 0;
			if(strcmp(buffer, "ebit") == 0) in_ebit = 1;
			if(strcmp(buffer, "/ebit") == 0) in_ebit = 0;
			if(strcmp(buffer, "earnings") == 0) in_earnings = 1;
			if(strcmp(buffer, "/earnings") == 0) in_earnings = 0;
			if(strcmp(buffer, "tax_rate_corporate") == 0) in_tax_rate_corporate = 1;
			if(strcmp(buffer, "/tax_rate_corporate") == 0) in_tax_rate_corporate = 0;
			if(strcmp(buffer, "tax_rate_vat") == 0) in_tax_rate_vat = 1;
			if(strcmp(buffer, "/tax_rate_vat") == 0) in_tax_rate_vat = 0;
			if(strcmp(buffer, "tax_payment") == 0) in_tax_payment = 1;
			if(strcmp(buffer, "/tax_payment") == 0) in_tax_payment = 0;
			if(strcmp(buffer, "net_earnings") == 0) in_net_earnings = 1;
			if(strcmp(buffer, "/net_earnings") == 0) in_net_earnings = 0;
			if(strcmp(buffer, "previous_net_earnings") == 0) in_previous_net_earnings = 1;
			if(strcmp(buffer, "/previous_net_earnings") == 0) in_previous_net_earnings = 0;
			if(strcmp(buffer, "earnings_per_share") == 0) in_earnings_per_share = 1;
			if(strcmp(buffer, "/earnings_per_share") == 0) in_earnings_per_share = 0;
			if(strcmp(buffer, "cum_total_sold_quantity") == 0) in_cum_total_sold_quantity = 1;
			if(strcmp(buffer, "/cum_total_sold_quantity") == 0) in_cum_total_sold_quantity = 0;
			if(strcmp(buffer, "cum_revenue") == 0) in_cum_revenue = 1;
			if(strcmp(buffer, "/cum_revenue") == 0) in_cum_revenue = 0;
			if(strcmp(buffer, "production_costs") == 0) in_production_costs = 1;
			if(strcmp(buffer, "/production_costs") == 0) in_production_costs = 0;
			if(strcmp(buffer, "current_shares_outstanding") == 0) in_current_shares_outstanding = 1;
			if(strcmp(buffer, "/current_shares_outstanding") == 0) in_current_shares_outstanding = 0;
			if(strcmp(buffer, "total_payments") == 0) in_total_payments = 1;
			if(strcmp(buffer, "/total_payments") == 0) in_total_payments = 0;
			if(strcmp(buffer, "current_mall_stocks") == 0) in_current_mall_stocks = 1;
			if(strcmp(buffer, "/current_mall_stocks") == 0) in_current_mall_stocks = 0;
			if(strcmp(buffer, "price") == 0) in_price = 1;
			if(strcmp(buffer, "/price") == 0) in_price = 0;
			if(strcmp(buffer, "total_interest_payment") == 0) in_total_interest_payment = 1;
			if(strcmp(buffer, "/total_interest_payment") == 0) in_total_interest_payment = 0;
			if(strcmp(buffer, "total_debt_installment_payment") == 0) in_total_debt_installment_payment = 1;
			if(strcmp(buffer, "/total_debt_installment_payment") == 0) in_total_debt_installment_payment = 0;
			if(strcmp(buffer, "total_dividend_payment") == 0) in_total_dividend_payment = 1;
			if(strcmp(buffer, "/total_dividend_payment") == 0) in_total_dividend_payment = 0;
			if(strcmp(buffer, "current_share_price") == 0) in_current_share_price = 1;
			if(strcmp(buffer, "/current_share_price") == 0) in_current_share_price = 0;
			if(strcmp(buffer, "previous_dividend_per_share") == 0) in_previous_dividend_per_share = 1;
			if(strcmp(buffer, "/previous_dividend_per_share") == 0) in_previous_dividend_per_share = 0;
			if(strcmp(buffer, "current_dividend_per_share") == 0) in_current_dividend_per_share = 1;
			if(strcmp(buffer, "/current_dividend_per_share") == 0) in_current_dividend_per_share = 0;
			if(strcmp(buffer, "previous_earnings_per_share") == 0) in_previous_earnings_per_share = 1;
			if(strcmp(buffer, "/previous_earnings_per_share") == 0) in_previous_earnings_per_share = 0;
			if(strcmp(buffer, "current_earnings_per_share") == 0) in_current_earnings_per_share = 1;
			if(strcmp(buffer, "/current_earnings_per_share") == 0) in_current_earnings_per_share = 0;
			if(strcmp(buffer, "previous_dividend_per_earnings") == 0) in_previous_dividend_per_earnings = 1;
			if(strcmp(buffer, "/previous_dividend_per_earnings") == 0) in_previous_dividend_per_earnings = 0;
			if(strcmp(buffer, "current_dividend_per_earnings") == 0) in_current_dividend_per_earnings = 1;
			if(strcmp(buffer, "/current_dividend_per_earnings") == 0) in_current_dividend_per_earnings = 0;
			if(strcmp(buffer, "debt_earnings_ratio") == 0) in_debt_earnings_ratio = 1;
			if(strcmp(buffer, "/debt_earnings_ratio") == 0) in_debt_earnings_ratio = 0;
			if(strcmp(buffer, "debt_equity_ratio") == 0) in_debt_equity_ratio = 1;
			if(strcmp(buffer, "/debt_equity_ratio") == 0) in_debt_equity_ratio = 0;
			if(strcmp(buffer, "price_earnings_ratio") == 0) in_price_earnings_ratio = 1;
			if(strcmp(buffer, "/price_earnings_ratio") == 0) in_price_earnings_ratio = 0;
			if(strcmp(buffer, "retained_earnings_ratio") == 0) in_retained_earnings_ratio = 1;
			if(strcmp(buffer, "/retained_earnings_ratio") == 0) in_retained_earnings_ratio = 0;
			if(strcmp(buffer, "earnings_per_share_ratio_growth") == 0) in_earnings_per_share_ratio_growth = 1;
			if(strcmp(buffer, "/earnings_per_share_ratio_growth") == 0) in_earnings_per_share_ratio_growth = 0;
			if(strcmp(buffer, "critical_price_earnings_ratio") == 0) in_critical_price_earnings_ratio = 1;
			if(strcmp(buffer, "/critical_price_earnings_ratio") == 0) in_critical_price_earnings_ratio = 0;
			if(strcmp(buffer, "critical_earnings_per_share_ratio") == 0) in_critical_earnings_per_share_ratio = 1;
			if(strcmp(buffer, "/critical_earnings_per_share_ratio") == 0) in_critical_earnings_per_share_ratio = 0;
			if(strcmp(buffer, "loans") == 0) in_loans = 1;
			if(strcmp(buffer, "/loans") == 0) in_loans = 0;
			if(strcmp(buffer, "total_debt") == 0) in_total_debt = 1;
			if(strcmp(buffer, "/total_debt") == 0) in_total_debt = 0;
			if(strcmp(buffer, "total_value_local_inventory") == 0) in_total_value_local_inventory = 1;
			if(strcmp(buffer, "/total_value_local_inventory") == 0) in_total_value_local_inventory = 0;
			if(strcmp(buffer, "capital_stock") == 0) in_capital_stock = 1;
			if(strcmp(buffer, "/capital_stock") == 0) in_capital_stock = 0;
			if(strcmp(buffer, "total_units_capital_stock") == 0) in_total_units_capital_stock = 1;
			if(strcmp(buffer, "/total_units_capital_stock") == 0) in_total_units_capital_stock = 0;
			if(strcmp(buffer, "total_value_capital_stock") == 0) in_total_value_capital_stock = 1;
			if(strcmp(buffer, "/total_value_capital_stock") == 0) in_total_value_capital_stock = 0;
			if(strcmp(buffer, "total_capital_depreciation_value") == 0) in_total_capital_depreciation_value = 1;
			if(strcmp(buffer, "/total_capital_depreciation_value") == 0) in_total_capital_depreciation_value = 0;
			if(strcmp(buffer, "total_capital_depreciation_units") == 0) in_total_capital_depreciation_units = 1;
			if(strcmp(buffer, "/total_capital_depreciation_units") == 0) in_total_capital_depreciation_units = 0;
			if(strcmp(buffer, "total_assets") == 0) in_total_assets = 1;
			if(strcmp(buffer, "/total_assets") == 0) in_total_assets = 0;
			if(strcmp(buffer, "equity") == 0) in_equity = 1;
			if(strcmp(buffer, "/equity") == 0) in_equity = 0;
			if(strcmp(buffer, "production_liquidity_needs") == 0) in_production_liquidity_needs = 1;
			if(strcmp(buffer, "/production_liquidity_needs") == 0) in_production_liquidity_needs = 0;
			if(strcmp(buffer, "financial_liquidity_needs") == 0) in_financial_liquidity_needs = 1;
			if(strcmp(buffer, "/financial_liquidity_needs") == 0) in_financial_liquidity_needs = 0;
			if(strcmp(buffer, "total_financial_needs") == 0) in_total_financial_needs = 1;
			if(strcmp(buffer, "/total_financial_needs") == 0) in_total_financial_needs = 0;
			if(strcmp(buffer, "external_financial_needs") == 0) in_external_financial_needs = 1;
			if(strcmp(buffer, "/external_financial_needs") == 0) in_external_financial_needs = 0;
			if(strcmp(buffer, "bankruptcy_state") == 0) in_bankruptcy_state = 1;
			if(strcmp(buffer, "/bankruptcy_state") == 0) in_bankruptcy_state = 0;
			if(strcmp(buffer, "financial_crisis_state") == 0) in_financial_crisis_state = 1;
			if(strcmp(buffer, "/financial_crisis_state") == 0) in_financial_crisis_state = 0;
			if(strcmp(buffer, "neighboring_region_ids") == 0) in_neighboring_region_ids = 1;
			if(strcmp(buffer, "/neighboring_region_ids") == 0) in_neighboring_region_ids = 0;
			if(strcmp(buffer, "no_regions") == 0) in_no_regions = 1;
			if(strcmp(buffer, "/no_regions") == 0) in_no_regions = 0;
			if(strcmp(buffer, "cash") == 0) in_cash = 1;
			if(strcmp(buffer, "/cash") == 0) in_cash = 0;
			if(strcmp(buffer, "total_credit") == 0) in_total_credit = 1;
			if(strcmp(buffer, "/total_credit") == 0) in_total_credit = 0;
			if(strcmp(buffer, "bce_debt") == 0) in_bce_debt = 1;
			if(strcmp(buffer, "/bce_debt") == 0) in_bce_debt = 0;
			if(strcmp(buffer, "alfa") == 0) in_alfa = 1;
			if(strcmp(buffer, "/alfa") == 0) in_alfa = 0;
			if(strcmp(buffer, "value_at_risk") == 0) in_value_at_risk = 1;
			if(strcmp(buffer, "/value_at_risk") == 0) in_value_at_risk = 0;
			if(strcmp(buffer, "min_interest") == 0) in_min_interest = 1;
			if(strcmp(buffer, "/min_interest") == 0) in_min_interest = 0;
			if(strcmp(buffer, "bank_gamma") == 0) in_bank_gamma = 1;
			if(strcmp(buffer, "/bank_gamma") == 0) in_bank_gamma = 0;
			if(strcmp(buffer, "profits") == 0) in_profits = 1;
			if(strcmp(buffer, "/profits") == 0) in_profits = 0;
			if(strcmp(buffer, "bank_lambda") == 0) in_bank_lambda = 1;
			if(strcmp(buffer, "/bank_lambda") == 0) in_bank_lambda = 0;
			if(strcmp(buffer, "bce_interest") == 0) in_bce_interest = 1;
			if(strcmp(buffer, "/bce_interest") == 0) in_bce_interest = 0;
			if(strcmp(buffer, "bank_dividend_rate") == 0) in_bank_dividend_rate = 1;
			if(strcmp(buffer, "/bank_dividend_rate") == 0) in_bank_dividend_rate = 0;
			if(strcmp(buffer, "number_of_shares") == 0) in_number_of_shares = 1;
			if(strcmp(buffer, "/number_of_shares") == 0) in_number_of_shares = 0;
			if(strcmp(buffer, "debt_period") == 0) in_debt_period = 1;
			if(strcmp(buffer, "/debt_period") == 0) in_debt_period = 0;
			if(strcmp(buffer, "loan_request_message_found") == 0) in_loan_request_message_found = 1;
			if(strcmp(buffer, "/loan_request_message_found") == 0) in_loan_request_message_found = 0;

			if(strcmp(buffer, "number_of_banks_to_apply") == 0) in_number_of_banks_to_apply = 1;
			if(strcmp(buffer, "/number_of_banks_to_apply") == 0) in_number_of_banks_to_apply = 0;

			
			/* End of tag and reset buffer */
			in_tag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			in_tag = 1;
			j = 0;
			
			if(in_itno) *itno = atoi(buffer);
			if(in_name) strcpy(agentname, buffer);
			if(in_environment)
			{
				if(in_number_of_banks_to_apply) number_of_banks_to_apply = atoi(buffer);
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_region_id) current_Firm_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Firm_agent->gov_id = atoi(buffer);
				if(in_day_of_month_to_act) current_Firm_agent->day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_Firm_agent->payment_account = atof(buffer);
				if(in_bank_id) current_Firm_agent->bank_id = atoi(buffer);
				if(in_dmarketmatrix) read_int_static_array(buffer, &j, current_Firm_agent->dmarketmatrix, 10);
				if(in_residual_var) read_residual_var_datatype_static_array(buffer, &j, current_Firm_agent->residual_var, 10);
				if(in_ebit) current_Firm_agent->ebit = atof(buffer);
				if(in_earnings) current_Firm_agent->earnings = atof(buffer);
				if(in_tax_rate_corporate) current_Firm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_vat) current_Firm_agent->tax_rate_vat = atof(buffer);
				if(in_tax_payment) current_Firm_agent->tax_payment = atof(buffer);
				if(in_net_earnings) current_Firm_agent->net_earnings = atof(buffer);
				if(in_previous_net_earnings) current_Firm_agent->previous_net_earnings = atof(buffer);
				if(in_earnings_per_share) current_Firm_agent->earnings_per_share = atof(buffer);
				if(in_cum_total_sold_quantity) current_Firm_agent->cum_total_sold_quantity = atof(buffer);
				if(in_cum_revenue) current_Firm_agent->cum_revenue = atof(buffer);
				if(in_production_costs) current_Firm_agent->production_costs = atof(buffer);
				if(in_current_shares_outstanding) current_Firm_agent->current_shares_outstanding = atoi(buffer);
				if(in_total_payments) current_Firm_agent->total_payments = atof(buffer);
				if(in_current_mall_stocks) read_mall_info_dynamic_array(buffer, &j, &current_Firm_agent->current_mall_stocks);
				if(in_price) current_Firm_agent->price = atof(buffer);
				if(in_total_interest_payment) current_Firm_agent->total_interest_payment = atof(buffer);
				if(in_total_debt_installment_payment) current_Firm_agent->total_debt_installment_payment = atof(buffer);
				if(in_total_dividend_payment) current_Firm_agent->total_dividend_payment = atof(buffer);
				if(in_current_share_price) current_Firm_agent->current_share_price = atof(buffer);
				if(in_previous_dividend_per_share) current_Firm_agent->previous_dividend_per_share = atof(buffer);
				if(in_current_dividend_per_share) current_Firm_agent->current_dividend_per_share = atof(buffer);
				if(in_previous_earnings_per_share) current_Firm_agent->previous_earnings_per_share = atof(buffer);
				if(in_current_earnings_per_share) current_Firm_agent->current_earnings_per_share = atof(buffer);
				if(in_previous_dividend_per_earnings) current_Firm_agent->previous_dividend_per_earnings = atof(buffer);
				if(in_current_dividend_per_earnings) current_Firm_agent->current_dividend_per_earnings = atof(buffer);
				if(in_debt_earnings_ratio) current_Firm_agent->debt_earnings_ratio = atof(buffer);
				if(in_debt_equity_ratio) current_Firm_agent->debt_equity_ratio = atof(buffer);
				if(in_price_earnings_ratio) current_Firm_agent->price_earnings_ratio = atof(buffer);
				if(in_retained_earnings_ratio) current_Firm_agent->retained_earnings_ratio = atof(buffer);
				if(in_earnings_per_share_ratio_growth) current_Firm_agent->earnings_per_share_ratio_growth = atof(buffer);
				if(in_critical_price_earnings_ratio) current_Firm_agent->critical_price_earnings_ratio = atof(buffer);
				if(in_critical_earnings_per_share_ratio) current_Firm_agent->critical_earnings_per_share_ratio = atof(buffer);
				if(in_loans) read_debt_item_dynamic_array(buffer, &j, &current_Firm_agent->loans);
				if(in_total_debt) current_Firm_agent->total_debt = atof(buffer);
				if(in_total_value_local_inventory) current_Firm_agent->total_value_local_inventory = atof(buffer);
				if(in_capital_stock) read_capital_stock_item_dynamic_array(buffer, &j, &current_Firm_agent->capital_stock);
				if(in_total_units_capital_stock) current_Firm_agent->total_units_capital_stock = atof(buffer);
				if(in_total_value_capital_stock) current_Firm_agent->total_value_capital_stock = atof(buffer);
				if(in_total_capital_depreciation_value) current_Firm_agent->total_capital_depreciation_value = atof(buffer);
				if(in_total_capital_depreciation_units) current_Firm_agent->total_capital_depreciation_units = atof(buffer);
				if(in_total_assets) current_Firm_agent->total_assets = atof(buffer);
				if(in_equity) current_Firm_agent->equity = atof(buffer);
				if(in_production_liquidity_needs) current_Firm_agent->production_liquidity_needs = atof(buffer);
				if(in_financial_liquidity_needs) current_Firm_agent->financial_liquidity_needs = atof(buffer);
				if(in_total_financial_needs) current_Firm_agent->total_financial_needs = atof(buffer);
				if(in_external_financial_needs) current_Firm_agent->external_financial_needs = atof(buffer);
				if(in_bankruptcy_state) current_Firm_agent->bankruptcy_state = atoi(buffer);
				if(in_financial_crisis_state) current_Firm_agent->financial_crisis_state = atoi(buffer);
			}
			else if(in_Bank_agent == 1)
			{
				if(in_id) current_Bank_agent->id = atoi(buffer);
				if(in_region_id) current_Bank_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Bank_agent->gov_id = atoi(buffer);
				if(in_cash) current_Bank_agent->cash = atof(buffer);
				if(in_total_credit) current_Bank_agent->total_credit = atof(buffer);
				if(in_equity) current_Bank_agent->equity = atof(buffer);
				if(in_bce_debt) current_Bank_agent->bce_debt = atof(buffer);
				if(in_alfa) current_Bank_agent->alfa = atof(buffer);
				if(in_value_at_risk) current_Bank_agent->value_at_risk = atof(buffer);
				if(in_min_interest) current_Bank_agent->min_interest = atof(buffer);
				if(in_bank_gamma) read_double_static_array(buffer, &j, current_Bank_agent->bank_gamma, 2);
				if(in_profits) read_double_static_array(buffer, &j, current_Bank_agent->profits, 2);
				if(in_bank_lambda) current_Bank_agent->bank_lambda = atof(buffer);
				if(in_bce_interest) current_Bank_agent->bce_interest = atof(buffer);
				if(in_bank_dividend_rate) current_Bank_agent->bank_dividend_rate = atof(buffer);
				if(in_tax_rate_corporate) current_Bank_agent->tax_rate_corporate = atof(buffer);
				if(in_number_of_shares) current_Bank_agent->number_of_shares = atoi(buffer);
				if(in_debt_period) current_Bank_agent->debt_period = atof(buffer);
				if(in_loan_request_message_found) current_Bank_agent->loan_request_message_found = atoi(buffer);
				if(in_day_of_month_to_act) current_Bank_agent->day_of_month_to_act = atoi(buffer);
			}
			else if(in_Dummy_agent == 1)
			{
				if(in_id) current_Dummy_agent->id = atoi(buffer);
			}
			
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(in_tag)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else
		{
			buffer[i] = c;
			i++;
		}
	}
	/* Make sure cloud data makes sense if any of x,y,z coords were all the same */
	if ( partition_method == geometric ) {
		if ( cloud_data[0] == cloud_data[1] ) {
			cloud_data[0] = -SPINF;
			cloud_data[1] = SPINF;
		}
		if ( cloud_data[2] == cloud_data[3] ) {
			cloud_data[2] = -SPINF;
			cloud_data[3] = SPINF;
		}
		if ( cloud_data[4] == cloud_data[5] ) {
			cloud_data[4] = -SPINF;
			cloud_data[5] = SPINF;
		}
	}

	/* Close the file */
	fclose(file);
	/* Free temp data structures */
////////////////	free_residual_var_datatype_static_array(residual_var, 10);
////////////////////////////	free_mall_info_array(current_mall_stocks);
//////////////////////////////////////	free_debt_item_array(loans);
//////	free_capital_stock_item_array(capital_stock);
//////////////////////////	free_int_array(neighboring_region_ids);
//////////////////////////////
}

/** \fn void write_int_static_array(FILE *file, $name * temp)
 * \brief Writes int.
 */
void write_int_static_array(FILE *file, int * temp, int size)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%i", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_static_array(FILE *file, float * temp)
 * \brief Writes float.
 */
void write_float_static_array(FILE *file, float * temp, int size)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_static_array(FILE *file, double * temp)
 * \brief Writes double.
 */
void write_double_static_array(FILE *file, double * temp, int size)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_static_array(FILE *file, char * temp)
 * \brief Writes char.
 */
void write_char_static_array(FILE *file, char * temp, int size)
{
	int i;
	char data[1000];
	
	//fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%c", temp[i]);
		fputs(data, file);
		//if(i < size-1) fputs(", ", file);
	}
	//fputs("}", file);
}

/** \fn void write_int_dynamic_array(FILE *file, int_array* temp)
 * \brief Writes int.
 */
void write_int_dynamic_array(FILE *file, int_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%i", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[1000];
	
	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[1000];
	
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%c", (*temp).array[i]);
		fputs(data, file);
	}
}

/** \fn void write_residual_var_datatype(FILE *file, residual_var_datatype * temp_datatype)
 * \brief Writes residual_var_datatype datatype.
 */
void write_residual_var_datatype(FILE *file, residual_var_datatype * temp_datatype)
{
	
	
	fputs("{", file);
	write_double_static_array(file, (*temp_datatype).value, 10);
	fputs("}", file);
}

void write_residual_var_datatype_static_array(FILE *file, residual_var_datatype * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_residual_var_datatype(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_residual_var_datatype_dynamic_array(FILE *file, residual_var_datatype_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_residual_var_datatype(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_debt_item(FILE *file, debt_item * temp_datatype)
 * \brief Writes debt_item datatype.
 */
void write_debt_item(FILE *file, debt_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).bank_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).loan_value);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).interest_rate);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).installment_amount);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).var_per_installment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).residual_var);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).bad_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_periods_before_repayment);
	fputs(data, file);
	fputs("}", file);
}

void write_debt_item_static_array(FILE *file, debt_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_debt_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_debt_item_dynamic_array(FILE *file, debt_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_debt_item(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_capital_stock_item(FILE *file, capital_stock_item * temp_datatype)
 * \brief Writes capital_stock_item datatype.
 */
void write_capital_stock_item(FILE *file, capital_stock_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).units);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).purchase_price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).productivity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).depreciation_units_per_period);
	fputs(data, file);
	fputs("}", file);
}

void write_capital_stock_item_static_array(FILE *file, capital_stock_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_capital_stock_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_capital_stock_item_dynamic_array(FILE *file, capital_stock_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_capital_stock_item(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_mall_info(FILE *file, mall_info * temp_datatype)
 * \brief Writes mall_info datatype.
 */
void write_mall_info(FILE *file, mall_info * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).critical_stock);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).current_stock);
	fputs(data, file);
	fputs("}", file);
}

void write_mall_info_static_array(FILE *file, mall_info * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_mall_info(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_mall_info_dynamic_array(FILE *file, mall_info_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_mall_info(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}



void write_Firm_agent(FILE *file, xmachine_memory_Firm * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Firm</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
		fputs("<gov_id>", file);
	sprintf(data, "%i", current->gov_id);
	fputs(data, file);
	fputs("</gov_id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<dmarketmatrix>", file);
	write_int_static_array(file, current->dmarketmatrix, 10);
	fputs("</dmarketmatrix>\n", file);
		fputs("<residual_var>", file);
	write_residual_var_datatype_static_array(file, current->residual_var, 10);
	fputs("</residual_var>\n", file);
		fputs("<ebit>", file);
	sprintf(data, "%f", current->ebit);
	fputs(data, file);
	fputs("</ebit>\n", file);
		fputs("<earnings>", file);
	sprintf(data, "%f", current->earnings);
	fputs(data, file);
	fputs("</earnings>\n", file);
		fputs("<tax_rate_corporate>", file);
	sprintf(data, "%f", current->tax_rate_corporate);
	fputs(data, file);
	fputs("</tax_rate_corporate>\n", file);
		fputs("<tax_rate_vat>", file);
	sprintf(data, "%f", current->tax_rate_vat);
	fputs(data, file);
	fputs("</tax_rate_vat>\n", file);
		fputs("<tax_payment>", file);
	sprintf(data, "%f", current->tax_payment);
	fputs(data, file);
	fputs("</tax_payment>\n", file);
		fputs("<net_earnings>", file);
	sprintf(data, "%f", current->net_earnings);
	fputs(data, file);
	fputs("</net_earnings>\n", file);
		fputs("<previous_net_earnings>", file);
	sprintf(data, "%f", current->previous_net_earnings);
	fputs(data, file);
	fputs("</previous_net_earnings>\n", file);
		fputs("<earnings_per_share>", file);
	sprintf(data, "%f", current->earnings_per_share);
	fputs(data, file);
	fputs("</earnings_per_share>\n", file);
		fputs("<cum_total_sold_quantity>", file);
	sprintf(data, "%f", current->cum_total_sold_quantity);
	fputs(data, file);
	fputs("</cum_total_sold_quantity>\n", file);
		fputs("<cum_revenue>", file);
	sprintf(data, "%f", current->cum_revenue);
	fputs(data, file);
	fputs("</cum_revenue>\n", file);
		fputs("<production_costs>", file);
	sprintf(data, "%f", current->production_costs);
	fputs(data, file);
	fputs("</production_costs>\n", file);
		fputs("<current_shares_outstanding>", file);
	sprintf(data, "%i", current->current_shares_outstanding);
	fputs(data, file);
	fputs("</current_shares_outstanding>\n", file);
		fputs("<total_payments>", file);
	sprintf(data, "%f", current->total_payments);
	fputs(data, file);
	fputs("</total_payments>\n", file);
		fputs("<current_mall_stocks>", file);
	write_mall_info_dynamic_array(file, &current->current_mall_stocks);
	fputs("</current_mall_stocks>\n", file);
		fputs("<price>", file);
	sprintf(data, "%f", current->price);
	fputs(data, file);
	fputs("</price>\n", file);
		fputs("<total_interest_payment>", file);
	sprintf(data, "%f", current->total_interest_payment);
	fputs(data, file);
	fputs("</total_interest_payment>\n", file);
		fputs("<total_debt_installment_payment>", file);
	sprintf(data, "%f", current->total_debt_installment_payment);
	fputs(data, file);
	fputs("</total_debt_installment_payment>\n", file);
		fputs("<total_dividend_payment>", file);
	sprintf(data, "%f", current->total_dividend_payment);
	fputs(data, file);
	fputs("</total_dividend_payment>\n", file);
		fputs("<current_share_price>", file);
	sprintf(data, "%f", current->current_share_price);
	fputs(data, file);
	fputs("</current_share_price>\n", file);
		fputs("<previous_dividend_per_share>", file);
	sprintf(data, "%f", current->previous_dividend_per_share);
	fputs(data, file);
	fputs("</previous_dividend_per_share>\n", file);
		fputs("<current_dividend_per_share>", file);
	sprintf(data, "%f", current->current_dividend_per_share);
	fputs(data, file);
	fputs("</current_dividend_per_share>\n", file);
		fputs("<previous_earnings_per_share>", file);
	sprintf(data, "%f", current->previous_earnings_per_share);
	fputs(data, file);
	fputs("</previous_earnings_per_share>\n", file);
		fputs("<current_earnings_per_share>", file);
	sprintf(data, "%f", current->current_earnings_per_share);
	fputs(data, file);
	fputs("</current_earnings_per_share>\n", file);
		fputs("<previous_dividend_per_earnings>", file);
	sprintf(data, "%f", current->previous_dividend_per_earnings);
	fputs(data, file);
	fputs("</previous_dividend_per_earnings>\n", file);
		fputs("<current_dividend_per_earnings>", file);
	sprintf(data, "%f", current->current_dividend_per_earnings);
	fputs(data, file);
	fputs("</current_dividend_per_earnings>\n", file);
		fputs("<debt_earnings_ratio>", file);
	sprintf(data, "%f", current->debt_earnings_ratio);
	fputs(data, file);
	fputs("</debt_earnings_ratio>\n", file);
		fputs("<debt_equity_ratio>", file);
	sprintf(data, "%f", current->debt_equity_ratio);
	fputs(data, file);
	fputs("</debt_equity_ratio>\n", file);
		fputs("<price_earnings_ratio>", file);
	sprintf(data, "%f", current->price_earnings_ratio);
	fputs(data, file);
	fputs("</price_earnings_ratio>\n", file);
		fputs("<retained_earnings_ratio>", file);
	sprintf(data, "%f", current->retained_earnings_ratio);
	fputs(data, file);
	fputs("</retained_earnings_ratio>\n", file);
		fputs("<earnings_per_share_ratio_growth>", file);
	sprintf(data, "%f", current->earnings_per_share_ratio_growth);
	fputs(data, file);
	fputs("</earnings_per_share_ratio_growth>\n", file);
		fputs("<critical_price_earnings_ratio>", file);
	sprintf(data, "%f", current->critical_price_earnings_ratio);
	fputs(data, file);
	fputs("</critical_price_earnings_ratio>\n", file);
		fputs("<critical_earnings_per_share_ratio>", file);
	sprintf(data, "%f", current->critical_earnings_per_share_ratio);
	fputs(data, file);
	fputs("</critical_earnings_per_share_ratio>\n", file);
		fputs("<loans>", file);
	write_debt_item_dynamic_array(file, &current->loans);
	fputs("</loans>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<total_value_local_inventory>", file);
	sprintf(data, "%f", current->total_value_local_inventory);
	fputs(data, file);
	fputs("</total_value_local_inventory>\n", file);
		fputs("<capital_stock>", file);
	write_capital_stock_item_dynamic_array(file, &current->capital_stock);
	fputs("</capital_stock>\n", file);
		fputs("<total_units_capital_stock>", file);
	sprintf(data, "%f", current->total_units_capital_stock);
	fputs(data, file);
	fputs("</total_units_capital_stock>\n", file);
		fputs("<total_value_capital_stock>", file);
	sprintf(data, "%f", current->total_value_capital_stock);
	fputs(data, file);
	fputs("</total_value_capital_stock>\n", file);
		fputs("<total_capital_depreciation_value>", file);
	sprintf(data, "%f", current->total_capital_depreciation_value);
	fputs(data, file);
	fputs("</total_capital_depreciation_value>\n", file);
		fputs("<total_capital_depreciation_units>", file);
	sprintf(data, "%f", current->total_capital_depreciation_units);
	fputs(data, file);
	fputs("</total_capital_depreciation_units>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<production_liquidity_needs>", file);
	sprintf(data, "%f", current->production_liquidity_needs);
	fputs(data, file);
	fputs("</production_liquidity_needs>\n", file);
		fputs("<financial_liquidity_needs>", file);
	sprintf(data, "%f", current->financial_liquidity_needs);
	fputs(data, file);
	fputs("</financial_liquidity_needs>\n", file);
		fputs("<total_financial_needs>", file);
	sprintf(data, "%f", current->total_financial_needs);
	fputs(data, file);
	fputs("</total_financial_needs>\n", file);
		fputs("<external_financial_needs>", file);
	sprintf(data, "%f", current->external_financial_needs);
	fputs(data, file);
	fputs("</external_financial_needs>\n", file);
		fputs("<bankruptcy_state>", file);
	sprintf(data, "%i", current->bankruptcy_state);
	fputs(data, file);
	fputs("</bankruptcy_state>\n", file);
		fputs("<financial_crisis_state>", file);
	sprintf(data, "%i", current->financial_crisis_state);
	fputs(data, file);
	fputs("</financial_crisis_state>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Bank_agent(FILE *file, xmachine_memory_Bank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Bank</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
		fputs("<gov_id>", file);
	sprintf(data, "%i", current->gov_id);
	fputs(data, file);
	fputs("</gov_id>\n", file);
		fputs("<cash>", file);
	sprintf(data, "%f", current->cash);
	fputs(data, file);
	fputs("</cash>\n", file);
		fputs("<total_credit>", file);
	sprintf(data, "%f", current->total_credit);
	fputs(data, file);
	fputs("</total_credit>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<bce_debt>", file);
	sprintf(data, "%f", current->bce_debt);
	fputs(data, file);
	fputs("</bce_debt>\n", file);
		fputs("<alfa>", file);
	sprintf(data, "%f", current->alfa);
	fputs(data, file);
	fputs("</alfa>\n", file);
		fputs("<value_at_risk>", file);
	sprintf(data, "%f", current->value_at_risk);
	fputs(data, file);
	fputs("</value_at_risk>\n", file);
		fputs("<min_interest>", file);
	sprintf(data, "%f", current->min_interest);
	fputs(data, file);
	fputs("</min_interest>\n", file);
		fputs("<bank_gamma>", file);
	write_double_static_array(file, current->bank_gamma, 2);
	fputs("</bank_gamma>\n", file);
		fputs("<profits>", file);
	write_double_static_array(file, current->profits, 2);
	fputs("</profits>\n", file);
		fputs("<bank_lambda>", file);
	sprintf(data, "%f", current->bank_lambda);
	fputs(data, file);
	fputs("</bank_lambda>\n", file);
		fputs("<bce_interest>", file);
	sprintf(data, "%f", current->bce_interest);
	fputs(data, file);
	fputs("</bce_interest>\n", file);
		fputs("<bank_dividend_rate>", file);
	sprintf(data, "%f", current->bank_dividend_rate);
	fputs(data, file);
	fputs("</bank_dividend_rate>\n", file);
		fputs("<tax_rate_corporate>", file);
	sprintf(data, "%f", current->tax_rate_corporate);
	fputs(data, file);
	fputs("</tax_rate_corporate>\n", file);
		fputs("<number_of_shares>", file);
	sprintf(data, "%i", current->number_of_shares);
	fputs(data, file);
	fputs("</number_of_shares>\n", file);
		fputs("<debt_period>", file);
	sprintf(data, "%f", current->debt_period);
	fputs(data, file);
	fputs("</debt_period>\n", file);
		fputs("<loan_request_message_found>", file);
	sprintf(data, "%i", current->loan_request_message_found);
	fputs(data, file);
	fputs("</loan_request_message_found>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Dummy_agent(FILE *file, xmachine_memory_Dummy * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Dummy</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		
	fputs("</xagent>\n", file);
}


/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	//int_array * neighboring_region_ids;
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("<number_of_banks_to_apply>", file);
	sprintf(data, "%i", number_of_banks_to_apply);
	fputs(data, file);
	fputs("</number_of_banks_to_apply>\n", file);
	fputs("</environment>\n" , file);

//	current_xmachine = *p_xmachine;
// todo loop through all agent types

current_xmachine_Firm_holder = Firm_end_Firm_cycle_state->agents;
	while(current_xmachine_Firm_holder)
	{
		write_Firm_agent(file, current_xmachine_Firm_holder->agent);
		
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}

current_xmachine_Firm_holder = Firm_Start_Firm_Labour_Role_state->agents;
	while(current_xmachine_Firm_holder)
	{
		write_Firm_agent(file, current_xmachine_Firm_holder->agent);
		
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}

current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
	while(current_xmachine_Bank_holder)
	{
		write_Bank_agent(file, current_xmachine_Bank_holder->agent);
		
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}

current_xmachine_Dummy_holder = Dummy_003_state->agents;
	while(current_xmachine_Dummy_holder)
	{
		write_Dummy_agent(file, current_xmachine_Dummy_holder->agent);
		
		current_xmachine_Dummy_holder = current_xmachine_Dummy_holder->next;
	}
	
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
