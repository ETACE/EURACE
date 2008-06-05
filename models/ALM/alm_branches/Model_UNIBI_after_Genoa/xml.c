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


/** \fn void read_portfolio(char * buffer, int * j, portfolio * temp_datatype)
 * \brief Reads portfolio datatype.
 */
void read_portfolio(char * buffer, int * j, portfolio * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).shares = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).shares = atoi(arraydata);
	(*j)++;
}

void read_portfolio_dynamic_array(char * buffer, int * j, portfolio_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_portfolio(temp_datatype_array, 0, 0);
			read_portfolio(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_portfolio_static_array(char * buffer, int * j, portfolio * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_portfolio(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_consumption_goods_offer(char * buffer, int * j, consumption_goods_offer * temp_datatype)
 * \brief Reads consumption_goods_offer datatype.
 */
void read_consumption_goods_offer(char * buffer, int * j, consumption_goods_offer * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quality = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
}

void read_consumption_goods_offer_dynamic_array(char * buffer, int * j, consumption_goods_offer_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_consumption_goods_offer(temp_datatype_array, 0, 0.0, 0.0);
			read_consumption_goods_offer(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_consumption_goods_offer_static_array(char * buffer, int * j, consumption_goods_offer * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_consumption_goods_offer(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_consumption_request(char * buffer, int * j, consumption_request * temp_datatype)
 * \brief Reads consumption_request datatype.
 */
void read_consumption_request(char * buffer, int * j, consumption_request * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).worker_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).worker_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;
}

void read_consumption_request_dynamic_array(char * buffer, int * j, consumption_request_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_consumption_request(temp_datatype_array, 0, 0, 0.0);
			read_consumption_request(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_consumption_request_static_array(char * buffer, int * j, consumption_request * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_consumption_request(buffer, j, &temp_datatype_array[arraycount]);
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

/** \fn void read_mall_quality_price_info(char * buffer, int * j, mall_quality_price_info * temp_datatype)
 * \brief Reads mall_quality_price_info datatype.
 */
void read_mall_quality_price_info(char * buffer, int * j, mall_quality_price_info * temp_datatype)
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
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).mall_region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).mall_region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quality = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).available = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).available = atoi(arraydata);
	(*j)++;
}

void read_mall_quality_price_info_dynamic_array(char * buffer, int * j, mall_quality_price_info_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_quality_price_info(temp_datatype_array, 0, 0, 0, 0.0, 0.0, 0);
			read_mall_quality_price_info(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_mall_quality_price_info_static_array(char * buffer, int * j, mall_quality_price_info * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_mall_quality_price_info(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_mall_stock(char * buffer, int * j, mall_stock * temp_datatype)
 * \brief Reads mall_stock datatype.
 */
void read_mall_stock(char * buffer, int * j, mall_stock * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).stock = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).stock = atof(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).quality = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;
}

void read_mall_stock_dynamic_array(char * buffer, int * j, mall_stock_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_stock(temp_datatype_array, 0, 0.0, 0.0, 0.0);
			read_mall_stock(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_mall_stock_static_array(char * buffer, int * j, mall_stock * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_mall_stock(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_delivery_volume_per_mall(char * buffer, int * j, delivery_volume_per_mall * temp_datatype)
 * \brief Reads delivery_volume_per_mall datatype.
 */
void read_delivery_volume_per_mall(char * buffer, int * j, delivery_volume_per_mall * temp_datatype)
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
	(*temp_datatype).quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
	(*temp_datatype).quality = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;
}

void read_delivery_volume_per_mall_dynamic_array(char * buffer, int * j, delivery_volume_per_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_delivery_volume_per_mall(temp_datatype_array, 0, 0.0, 0.0, 0.0);
			read_delivery_volume_per_mall(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_delivery_volume_per_mall_static_array(char * buffer, int * j, delivery_volume_per_mall * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_delivery_volume_per_mall(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_logit_firm_id(char * buffer, int * j, logit_firm_id * temp_datatype)
 * \brief Reads logit_firm_id datatype.
 */
void read_logit_firm_id(char * buffer, int * j, logit_firm_id * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).logit = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).logit = atof(arraydata);
	(*j)++;
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
}

void read_logit_firm_id_dynamic_array(char * buffer, int * j, logit_firm_id_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_logit_firm_id(temp_datatype_array, 0.0, 0);
			read_logit_firm_id(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_logit_firm_id_static_array(char * buffer, int * j, logit_firm_id * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_logit_firm_id(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_sales_in_mall(char * buffer, int * j, sales_in_mall * temp_datatype)
 * \brief Reads sales_in_mall datatype.
 */
void read_sales_in_mall(char * buffer, int * j, sales_in_mall * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).sales = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;
}

void read_sales_in_mall_dynamic_array(char * buffer, int * j, sales_in_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sales_in_mall(temp_datatype_array, 0, 0.0);
			read_sales_in_mall(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_sales_in_mall_static_array(char * buffer, int * j, sales_in_mall * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_sales_in_mall(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_ordered_quantity(char * buffer, int * j, ordered_quantity * temp_datatype)
 * \brief Reads ordered_quantity datatype.
 */
void read_ordered_quantity(char * buffer, int * j, ordered_quantity * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;
	(*temp_datatype).price = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;
}

void read_ordered_quantity_dynamic_array(char * buffer, int * j, ordered_quantity_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ordered_quantity(temp_datatype_array, 0, 0.0, 0.0);
			read_ordered_quantity(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_ordered_quantity_static_array(char * buffer, int * j, ordered_quantity * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_ordered_quantity(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_received_quantities(char * buffer, int * j, received_quantities * temp_datatype)
 * \brief Reads received_quantities datatype.
 */
void read_received_quantities(char * buffer, int * j, received_quantities * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;
}

void read_received_quantities_dynamic_array(char * buffer, int * j, received_quantities_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_received_quantities(temp_datatype_array, 0, 0.0);
			read_received_quantities(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_received_quantities_static_array(char * buffer, int * j, received_quantities * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_received_quantities(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_sold_quantities_per_mall(char * buffer, int * j, sold_quantities_per_mall * temp_datatype)
 * \brief Reads sold_quantities_per_mall datatype.
 */
void read_sold_quantities_per_mall(char * buffer, int * j, sold_quantities_per_mall * temp_datatype)
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
	(*temp_datatype).sold_quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sold_quantity = atof(arraydata);
	(*j)++;
	(*temp_datatype).stock_empty = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).stock_empty = atoi(arraydata);
	(*j)++;
	(*temp_datatype).estimated_demand = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).estimated_demand = atof(arraydata);
	(*j)++;
}

void read_sold_quantities_per_mall_dynamic_array(char * buffer, int * j, sold_quantities_per_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sold_quantities_per_mall(temp_datatype_array, 0, 0.0, 0, 0.0);
			read_sold_quantities_per_mall(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_sold_quantities_per_mall_static_array(char * buffer, int * j, sold_quantities_per_mall * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_sold_quantities_per_mall(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_sales_statistics(char * buffer, int * j, sales_statistics * temp_datatype)
 * \brief Reads sales_statistics datatype.
 */
void read_sales_statistics(char * buffer, int * j, sales_statistics * temp_datatype)
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
	(*temp_datatype).period = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).period = atoi(arraydata);
	(*j)++;
	(*temp_datatype).sales = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;
}

void read_sales_statistics_dynamic_array(char * buffer, int * j, sales_statistics_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sales_statistics(temp_datatype_array, 0, 0, 0.0);
			read_sales_statistics(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_sales_statistics_static_array(char * buffer, int * j, sales_statistics * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_sales_statistics(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_financing_capital(char * buffer, int * j, financing_capital * temp_datatype)
 * \brief Reads financing_capital datatype.
 */
void read_financing_capital(char * buffer, int * j, financing_capital * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).financing_per_month = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).financing_per_month = atof(arraydata);
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

void read_financing_capital_dynamic_array(char * buffer, int * j, financing_capital_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_financing_capital(temp_datatype_array, 0.0, 0);
			read_financing_capital(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_financing_capital_static_array(char * buffer, int * j, financing_capital * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_financing_capital(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_account(char * buffer, int * j, account * temp_datatype)
 * \brief Reads account datatype.
 */
void read_account(char * buffer, int * j, account * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).balance = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).balance = atof(arraydata);
	(*j)++;
}

void read_account_dynamic_array(char * buffer, int * j, account_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_account(temp_datatype_array, 0, 0.0);
			read_account(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_account_static_array(char * buffer, int * j, account * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_account(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_credit_request(char * buffer, int * j, credit_request * temp_datatype)
 * \brief Reads credit_request datatype.
 */
void read_credit_request(char * buffer, int * j, credit_request * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).credit_amount = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).credit_amount = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).prob_of_failure = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).prob_of_failure = atof(arraydata);
	(*j)++;
}

void read_credit_request_dynamic_array(char * buffer, int * j, credit_request_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_credit_request(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0);
			read_credit_request(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_credit_request_static_array(char * buffer, int * j, credit_request * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_credit_request(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_outstanding_loans(char * buffer, int * j, outstanding_loans * temp_datatype)
 * \brief Reads outstanding_loans datatype.
 */
void read_outstanding_loans(char * buffer, int * j, outstanding_loans * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_amount = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_amount = atof(arraydata);
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
	(*temp_datatype).credit_id = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).credit_id = atoi(arraydata);
	(*j)++;
}

void read_outstanding_loans_dynamic_array(char * buffer, int * j, outstanding_loans_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_outstanding_loans(temp_datatype_array, 0, 0.0, 0.0, 0);
			read_outstanding_loans(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_outstanding_loans_static_array(char * buffer, int * j, outstanding_loans * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_outstanding_loans(buffer, j, &temp_datatype_array[arraycount]);
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
	(*temp_datatype).credit_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).credit_id = atoi(arraydata);
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
	(*temp_datatype).interest_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).interest_payment = atof(arraydata);
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
			add_debt_item(temp_datatype_array, 0, 0, 0.0, 0.0, 0.0, 0.0, 0);
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

/** \fn void read_employee(char * buffer, int * j, employee * temp_datatype)
 * \brief Reads employee datatype.
 */
void read_employee(char * buffer, int * j, employee * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).wage = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage = atof(arraydata);
	(*j)++;
	(*temp_datatype).general_skill = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).general_skill = atoi(arraydata);
	(*j)++;
	(*temp_datatype).specific_skill = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).specific_skill = atof(arraydata);
	(*j)++;
}

void read_employee_dynamic_array(char * buffer, int * j, employee_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_employee(temp_datatype_array, 0, 0, 0.0, 0, 0.0);
			read_employee(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_employee_static_array(char * buffer, int * j, employee * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_employee(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_vacancy(char * buffer, int * j, vacancy * temp_datatype)
 * \brief Reads vacancy datatype.
 */
void read_vacancy(char * buffer, int * j, vacancy * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).wage_offer = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage_offer = atof(arraydata);
	(*j)++;
}

void read_vacancy_dynamic_array(char * buffer, int * j, vacancy_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_vacancy(temp_datatype_array, 0, 0, 0.0);
			read_vacancy(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_vacancy_static_array(char * buffer, int * j, vacancy * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_vacancy(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_job_application(char * buffer, int * j, job_application * temp_datatype)
 * \brief Reads job_application datatype.
 */
void read_job_application(char * buffer, int * j, job_application * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).worker_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).worker_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).general_skill = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).general_skill = atoi(arraydata);
	(*j)++;
	(*temp_datatype).specific_skill = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).specific_skill = atof(arraydata);
	(*j)++;
}

void read_job_application_dynamic_array(char * buffer, int * j, job_application_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_job_application(temp_datatype_array, 0, 0, 0, 0.0);
			read_job_application(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_job_application_static_array(char * buffer, int * j, job_application * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_job_application(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_job_offer(char * buffer, int * j, job_offer * temp_datatype)
 * \brief Reads job_offer datatype.
 */
void read_job_offer(char * buffer, int * j, job_offer * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).wage_offer = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage_offer = atof(arraydata);
	(*j)++;
}

void read_job_offer_dynamic_array(char * buffer, int * j, job_offer_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_job_offer(temp_datatype_array, 0, 0, 0.0);
			read_job_offer(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_job_offer_static_array(char * buffer, int * j, job_offer * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_job_offer(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_household_data(char * buffer, int * j, household_data * temp_datatype)
 * \brief Reads household_data datatype.
 */
void read_household_data(char * buffer, int * j, household_data * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households_skill_1 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households_skill_1 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households_skill_2 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households_skill_2 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households_skill_3 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households_skill_3 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households_skill_4 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households_skill_4 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_households_skill_5 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_households_skill_5 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed_skill_1 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed_skill_1 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed_skill_2 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed_skill_2 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed_skill_3 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed_skill_3 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed_skill_4 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed_skill_4 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employed_skill_5 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employed_skill_5 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).unemployed = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployed = atoi(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate = atof(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate_skill_1 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate_skill_1 = atof(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate_skill_2 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate_skill_2 = atof(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate_skill_3 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate_skill_3 = atof(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate_skill_4 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate_skill_4 = atof(arraydata);
	(*j)++;
	(*temp_datatype).unemployment_rate_skill_5 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).unemployment_rate_skill_5 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_1 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_1 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_2 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_2 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_3 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_3 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_4 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_4 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_5 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_5 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_1 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_1 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_2 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_2 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_3 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_3 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_4 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_4 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_5 = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_5 = atof(arraydata);
	(*j)++;
}

void read_household_data_dynamic_array(char * buffer, int * j, household_data_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_household_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			read_household_data(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_household_data_static_array(char * buffer, int * j, household_data * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_household_data(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_firm_data(char * buffer, int * j, firm_data * temp_datatype)
 * \brief Reads firm_data datatype.
 */
void read_firm_data(char * buffer, int * j, firm_data * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).region_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).firms = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firms = atoi(arraydata);
	(*j)++;
	(*temp_datatype).vacancies = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).vacancies = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees_skill_1 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees_skill_1 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees_skill_2 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees_skill_2 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees_skill_3 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees_skill_3 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees_skill_4 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees_skill_4 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).employees_skill_5 = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employees_skill_5 = atoi(arraydata);
	(*j)++;
	(*temp_datatype).average_wage = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_1 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_1 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_2 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_2 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_3 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_3 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_4 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_4 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_wage_skill_5 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_wage_skill_5 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_1 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_1 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_2 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_2 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_3 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_3 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_4 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_4 = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_s_skill_5 = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_5 = atof(arraydata);
	(*j)++;
	(*temp_datatype).gdp = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gdp = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_earnings = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_earnings = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_equity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_equity = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_debt_earnings_ratio = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_debt_earnings_ratio = atof(arraydata);
	(*j)++;
	(*temp_datatype).average_debt_equity_ratio = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_debt_equity_ratio = atof(arraydata);
	(*j)++;
	(*temp_datatype).labour_share_ratio = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).labour_share_ratio = atof(arraydata);
	(*j)++;
}

void read_firm_data_dynamic_array(char * buffer, int * j, firm_data_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			read_firm_data(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_firm_data_static_array(char * buffer, int * j, firm_data * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_firm_data(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_tax_rates_item(char * buffer, int * j, tax_rates_item * temp_datatype)
 * \brief Reads tax_rates_item datatype.
 */
void read_tax_rates_item(char * buffer, int * j, tax_rates_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).gov_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).tax_rate_corporate = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_rate_corporate = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_rate_hh_labour = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_rate_hh_labour = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_rate_hh_capital = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_rate_hh_capital = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_rate_vat = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_rate_vat = atof(arraydata);
	(*j)++;
}

void read_tax_rates_item_dynamic_array(char * buffer, int * j, tax_rates_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_tax_rates_item(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0);
			read_tax_rates_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_tax_rates_item_static_array(char * buffer, int * j, tax_rates_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_tax_rates_item(buffer, j, &temp_datatype_array[arraycount]);
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
	char buffer[10000];
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
	int in_Household_agent;
	int in_Mall_agent;
	int in_IGFirm_agent;
	int in_Eurostat_agent;
	int in_Bank_agent;
	int in_Government_agent;

	int in_id;
	int in_region_id;
	int in_gov_id;
	int in_day_of_month_to_act;
	int in_payment_account;
	int in_mean_wage;
	int in_total_units_capital_stock;
	int in_needed_capital_stock;
	int in_actual_cap_price;
	int in_mean_specific_skills;
	int in_planned_production_quantity;
	int in_production_quantity;
	int in_unit_costs;
	int in_production_costs;
	int in_revenue_per_day;
	int in_technological_frontier;
	int in_cum_revenue;
	int in_out_of_stock_costs;
	int in_malls_sales_statistics;
	int in_quality;
	int in_price;
	int in_price_last_month;
	int in_demand_capital_stock;
	int in_planned_production_costs;
	int in_adaption_production_volume_due_to_insufficient_finances;
	int in_fraction_reserved_for_delayed_payments;
	int in_sold_quantities;
	int in_total_sold_quantity;
	int in_cum_total_sold_quantity;
	int in_delivery_volume;
	int in_planned_delivery_volume;
	int in_current_mall_stocks;
	int in_last_planned_production_quantities;
	int in_direct_financial_needs_require_external_financing;
	int in_total_external_financing_obtained;
	int in_delayed_financial_needs_require_external_financing;
	int in_capital_costs;
	int in_labour_costs;
	int in_capital_financing;
	int in_bank_id;
	int in_ebit;
	int in_earnings;
	int in_tax_rate_corporate;
	int in_tax_rate_vat;
	int in_tax_payment;
	int in_net_earnings;
	int in_previous_net_earnings;
	int in_earnings_per_share;
	int in_current_shares_outstanding;
	int in_total_interest_payment;
	int in_total_debt_installment_payment;
	int in_total_dividend_payment;
	int in_previous_dividend_per_share;
	int in_current_dividend_per_share;
	int in_previous_earnings_per_share;
	int in_current_earnings_per_share;
	int in_previous_dividend_per_earnings;
	int in_current_dividend_per_earnings;
	int in_financial_resources_for_production;
	int in_loans;
	int in_total_debt;
	int in_total_value_local_inventory;
	int in_total_units_local_inventory;
	int in_total_value_capital_stock;
	int in_planned_value_capital_stock;
	int in_total_capital_depreciation_value;
	int in_total_capital_depreciation_units;
	int in_total_assets;
	int in_planned_total_assets;
	int in_equity;
	int in_production_liquidity_needs;
	int in_financial_liquidity_needs;
	int in_total_financial_needs;
	int in_external_financial_needs;
	int in_total_payments;
	int in_employees;
	int in_wage_offer;
	int in_technology;
	int in_no_employees;
	int in_no_employees_skill_1;
	int in_no_employees_skill_2;
	int in_no_employees_skill_3;
	int in_no_employees_skill_4;
	int in_no_employees_skill_5;
	int in_vacancies;
	int in_average_g_skill;
	int in_average_s_skill_of_1;
	int in_average_s_skill_of_2;
	int in_average_s_skill_of_3;
	int in_average_s_skill_of_4;
	int in_average_s_skill_of_5;
	int in_wage_offer_for_skill_1;
	int in_wage_offer_for_skill_2;
	int in_wage_offer_for_skill_3;
	int in_wage_offer_for_skill_4;
	int in_wage_offer_for_skill_5;
	int in_employees_needed;
	int in_neighboring_region_ids;
	int in_consumption_budget;
	int in_mean_income;
	int in_week_of_month;
	int in_weekly_budget;
	int in_rationed;
	int in_mall_completely_sold_out;
	int in_order_quantity;
	int in_received_quantity;
	int in_day_of_week_to_act;
	int in_day_of_month_receive_income;
	int in_current_productivity_employer;
	int in_current_mean_specific_skills_employer;
	int in_total_taxes;
	int in_cum_total_dividends;
	int in_tax_rate_hh_capital;
	int in_tax_rate_hh_labour;
	int in_last_income;
	int in_expenditures;
	int in_received_dividend;
	int in_household_portfolio;
	int in_wage;
	int in_wage_reservation;
	int in_general_skill;
	int in_on_the_job_search;
	int in_number_applications;
	int in_specific_skill;
	int in_employee_firm_id;
	int in_employer_region_id;
	int in_current_stock;
	int in_firm_revenues;
	int in_total_supply;
	int in_productivity;
	int in_innovation_probability;
	int in_productivity_progress;
	int in_capital_good_price;
	int in_net_profit;
	int in_outstanding_shares;
	int in_cum_revenues;
	int in_no_regions;
	int in_num_households;
	int in_no_households_skill_1;
	int in_no_households_skill_2;
	int in_no_households_skill_3;
	int in_no_households_skill_4;
	int in_no_households_skill_5;
	int in_employed;
	int in_employed_skill_1;
	int in_employed_skill_2;
	int in_employed_skill_3;
	int in_employed_skill_4;
	int in_employed_skill_5;
	int in_unemployed;
	int in_unemployment_rate;
	int in_unemployment_rate_skill_1;
	int in_unemployment_rate_skill_2;
	int in_unemployment_rate_skill_3;
	int in_unemployment_rate_skill_4;
	int in_unemployment_rate_skill_5;
	int in_average_wage;
	int in_average_wage_skill_1;
	int in_average_wage_skill_2;
	int in_average_wage_skill_3;
	int in_average_wage_skill_4;
	int in_average_wage_skill_5;
	int in_average_s_skill;
	int in_average_s_skill_1;
	int in_average_s_skill_2;
	int in_average_s_skill_3;
	int in_average_s_skill_4;
	int in_average_s_skill_5;
	int in_no_firms;
	int in_no_vacancies;
	int in_firm_average_wage;
	int in_firm_average_wage_skill_1;
	int in_firm_average_wage_skill_2;
	int in_firm_average_wage_skill_3;
	int in_firm_average_wage_skill_4;
	int in_firm_average_wage_skill_5;
	int in_firm_average_s_skill;
	int in_firm_average_s_skill_1;
	int in_firm_average_s_skill_2;
	int in_firm_average_s_skill_3;
	int in_firm_average_s_skill_4;
	int in_firm_average_s_skill_5;
	int in_region_firm_data;
	int in_region_household_data;
	int in_government_tax_rates;
	int in_gdp;
	int in_total_earnings;
	int in_total_equity;
	int in_average_debt_earnings_ratio;
	int in_average_debt_equity_ratio;
	int in_labour_share_ratio;
	int in_accounts;
	int in_loans_outstanding;
	int in_last_credit_id;
	int in_amount_credit_offer;
	int in_total_deposits;
	int in_total_loan_supply;
	int in_total_loan_demand;
	int in_tax_revenues;
	int in_unemployment_benefit_payment;
	int in_total_unemployment_benefit_payment;
	int in_num_unemployed;


	/* Variables for initial state data */
//	int id;
//	int region_id;
//	int gov_id;
//	int day_of_month_to_act;
//	double payment_account;
//	double mean_wage;
//	double total_units_capital_stock;
//	double needed_capital_stock;
//	double actual_cap_price;
//	double mean_specific_skills;
//	double planned_production_quantity;
//	double production_quantity;
//	double unit_costs;
//	double production_costs;
//	double revenue_per_day;
//	double technological_frontier;
//	double cum_revenue;
//	double out_of_stock_costs;
//	sales_statistics_array * malls_sales_statistics;
//	double quality;
//	double price;
//	double price_last_month;
//	double demand_capital_stock;
//	double planned_production_costs;
//	double adaption_production_volume_due_to_insufficient_finances;
//	double fraction_reserved_for_delayed_payments;
//	sold_quantities_per_mall_array * sold_quantities;
//	double total_sold_quantity;
//	double cum_total_sold_quantity;
//	delivery_volume_per_mall_array * delivery_volume;
//	delivery_volume_per_mall_array * planned_delivery_volume;
//	mall_info_array * current_mall_stocks;
//	double_array * last_planned_production_quantities;
//	double direct_financial_needs_require_external_financing;
//	double total_external_financing_obtained;
//	double delayed_financial_needs_require_external_financing;
//	double capital_costs;
//	double labour_costs;
//	financing_capital_array * capital_financing;
//	int bank_id;
//	double ebit;
//	double earnings;
//	double tax_rate_corporate;
//	double tax_rate_vat;
//	double tax_payment;
//	double net_earnings;
//	double previous_net_earnings;
//	double earnings_per_share;
//	int current_shares_outstanding;
//	double total_interest_payment;
//	double total_debt_installment_payment;
//	double total_dividend_payment;
//	double previous_dividend_per_share;
//	double current_dividend_per_share;
//	double previous_earnings_per_share;
//	double current_earnings_per_share;
//	double previous_dividend_per_earnings;
//	double current_dividend_per_earnings;
//	double financial_resources_for_production;
//	debt_item_array * loans;
//	double total_debt;
//	double total_value_local_inventory;
//	double total_units_local_inventory;
//	double total_value_capital_stock;
//	double planned_value_capital_stock;
//	double total_capital_depreciation_value;
//	double total_capital_depreciation_units;
//	double total_assets;
//	double planned_total_assets;
//	double equity;
//	double production_liquidity_needs;
//	double financial_liquidity_needs;
//	double total_financial_needs;
//	double external_financial_needs;
//	double total_payments;
//	employee_array * employees;
//	double wage_offer;
//	double technology;
//	int no_employees;
//	int no_employees_skill_1;
//	int no_employees_skill_2;
//	int no_employees_skill_3;
//	int no_employees_skill_4;
//	int no_employees_skill_5;
//	int vacancies;
//	double average_g_skill;
//	double average_s_skill_of_1;
//	double average_s_skill_of_2;
//	double average_s_skill_of_3;
//	double average_s_skill_of_4;
//	double average_s_skill_of_5;
//	double wage_offer_for_skill_1;
//	double wage_offer_for_skill_2;
//	double wage_offer_for_skill_3;
//	double wage_offer_for_skill_4;
//	double wage_offer_for_skill_5;
//	int employees_needed;
//	int_array * neighboring_region_ids;
//	double consumption_budget;
//	double mean_income;
//	int week_of_month;
//	double weekly_budget;
//	int rationed;
//	int mall_completely_sold_out;
//	ordered_quantity ** order_quantity;
//	received_quantities ** received_quantity;
//	int day_of_week_to_act;
//	int day_of_month_receive_income;
//	double current_productivity_employer;
//	double current_mean_specific_skills_employer;
//	double total_taxes;
//	double cum_total_dividends;
//	double tax_rate_hh_capital;
//	double tax_rate_hh_labour;
//	double_array * last_income;
//	double expenditures;
//	double received_dividend;
//	portfolio_array * household_portfolio;
//	double wage;
//	double wage_reservation;
//	int general_skill;
//	int on_the_job_search;
//	int number_applications;
//	double specific_skill;
//	int employee_firm_id;
//	int employer_region_id;
//	mall_stock_array * current_stock;
//	sales_in_mall_array * firm_revenues;
//	double total_supply;
//	double productivity;
//	int innovation_probability;
//	double productivity_progress;
//	double capital_good_price;
//	double net_profit;
//	int outstanding_shares;
//	double cum_revenues;
//	int no_regions;
//	int num_households;
//	int no_households_skill_1;
//	int no_households_skill_2;
//	int no_households_skill_3;
//	int no_households_skill_4;
//	int no_households_skill_5;
//	int employed;
//	int employed_skill_1;
//	int employed_skill_2;
//	int employed_skill_3;
//	int employed_skill_4;
//	int employed_skill_5;
//	int unemployed;
//	double unemployment_rate;
//	double unemployment_rate_skill_1;
//	double unemployment_rate_skill_2;
//	double unemployment_rate_skill_3;
//	double unemployment_rate_skill_4;
//	double unemployment_rate_skill_5;
//	double average_wage;
//	double average_wage_skill_1;
//	double average_wage_skill_2;
//	double average_wage_skill_3;
//	double average_wage_skill_4;
//	double average_wage_skill_5;
//	double average_s_skill;
//	double average_s_skill_1;
//	double average_s_skill_2;
//	double average_s_skill_3;
//	double average_s_skill_4;
//	double average_s_skill_5;
//	int no_firms;
//	int no_vacancies;
//	double firm_average_wage;
//	double firm_average_wage_skill_1;
//	double firm_average_wage_skill_2;
//	double firm_average_wage_skill_3;
//	double firm_average_wage_skill_4;
//	double firm_average_wage_skill_5;
//	double firm_average_s_skill;
//	double firm_average_s_skill_1;
//	double firm_average_s_skill_2;
//	double firm_average_s_skill_3;
//	double firm_average_s_skill_4;
//	double firm_average_s_skill_5;
//	firm_data_array * region_firm_data;
//	household_data_array * region_household_data;
//	tax_rates_item_array * government_tax_rates;
//	double gdp;
//	double total_earnings;
//	double total_equity;
//	double average_debt_earnings_ratio;
//	double average_debt_equity_ratio;
//	double labour_share_ratio;
//	account_array * accounts;
//	outstanding_loans_array * loans_outstanding;
//	int last_credit_id;
//	double amount_credit_offer;
//	double total_deposits;
//	double total_loan_supply;
//	double total_loan_demand;
//	double tax_revenues;
//	double unemployment_benefit_payment;
//	double total_unemployment_benefit_payment;
//	int num_unemployed;


	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Mall * current_Mall_agent;
	xmachine_memory_IGFirm * current_IGFirm_agent;
	xmachine_memory_Eurostat * current_Eurostat_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_Government * current_Government_agent;


	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("error opening initial states\n");
		exit(0);
	}
	/* Initialise variables */
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
	in_Household_agent = 0;
	in_Mall_agent = 0;
	in_IGFirm_agent = 0;
	in_Eurostat_agent = 0;
	in_Bank_agent = 0;
	in_Government_agent = 0;
	in_id = 0;
	in_region_id = 0;
	in_gov_id = 0;
	in_day_of_month_to_act = 0;
	in_payment_account = 0;
	in_mean_wage = 0;
	in_total_units_capital_stock = 0;
	in_needed_capital_stock = 0;
	in_actual_cap_price = 0;
	in_mean_specific_skills = 0;
	in_planned_production_quantity = 0;
	in_production_quantity = 0;
	in_unit_costs = 0;
	in_production_costs = 0;
	in_revenue_per_day = 0;
	in_technological_frontier = 0;
	in_cum_revenue = 0;
	in_out_of_stock_costs = 0;
	in_malls_sales_statistics = 0;
	in_quality = 0;
	in_price = 0;
	in_price_last_month = 0;
	in_demand_capital_stock = 0;
	in_planned_production_costs = 0;
	in_adaption_production_volume_due_to_insufficient_finances = 0;
	in_fraction_reserved_for_delayed_payments = 0;
	in_sold_quantities = 0;
	in_total_sold_quantity = 0;
	in_cum_total_sold_quantity = 0;
	in_delivery_volume = 0;
	in_planned_delivery_volume = 0;
	in_current_mall_stocks = 0;
	in_last_planned_production_quantities = 0;
	in_direct_financial_needs_require_external_financing = 0;
	in_total_external_financing_obtained = 0;
	in_delayed_financial_needs_require_external_financing = 0;
	in_capital_costs = 0;
	in_labour_costs = 0;
	in_capital_financing = 0;
	in_bank_id = 0;
	in_ebit = 0;
	in_earnings = 0;
	in_tax_rate_corporate = 0;
	in_tax_rate_vat = 0;
	in_tax_payment = 0;
	in_net_earnings = 0;
	in_previous_net_earnings = 0;
	in_earnings_per_share = 0;
	in_current_shares_outstanding = 0;
	in_total_interest_payment = 0;
	in_total_debt_installment_payment = 0;
	in_total_dividend_payment = 0;
	in_previous_dividend_per_share = 0;
	in_current_dividend_per_share = 0;
	in_previous_earnings_per_share = 0;
	in_current_earnings_per_share = 0;
	in_previous_dividend_per_earnings = 0;
	in_current_dividend_per_earnings = 0;
	in_financial_resources_for_production = 0;
	in_loans = 0;
	in_total_debt = 0;
	in_total_value_local_inventory = 0;
	in_total_units_local_inventory = 0;
	in_total_value_capital_stock = 0;
	in_planned_value_capital_stock = 0;
	in_total_capital_depreciation_value = 0;
	in_total_capital_depreciation_units = 0;
	in_total_assets = 0;
	in_planned_total_assets = 0;
	in_equity = 0;
	in_production_liquidity_needs = 0;
	in_financial_liquidity_needs = 0;
	in_total_financial_needs = 0;
	in_external_financial_needs = 0;
	in_total_payments = 0;
	in_employees = 0;
	in_wage_offer = 0;
	in_technology = 0;
	in_no_employees = 0;
	in_no_employees_skill_1 = 0;
	in_no_employees_skill_2 = 0;
	in_no_employees_skill_3 = 0;
	in_no_employees_skill_4 = 0;
	in_no_employees_skill_5 = 0;
	in_vacancies = 0;
	in_average_g_skill = 0;
	in_average_s_skill_of_1 = 0;
	in_average_s_skill_of_2 = 0;
	in_average_s_skill_of_3 = 0;
	in_average_s_skill_of_4 = 0;
	in_average_s_skill_of_5 = 0;
	in_wage_offer_for_skill_1 = 0;
	in_wage_offer_for_skill_2 = 0;
	in_wage_offer_for_skill_3 = 0;
	in_wage_offer_for_skill_4 = 0;
	in_wage_offer_for_skill_5 = 0;
	in_employees_needed = 0;
	in_neighboring_region_ids = 0;
	in_consumption_budget = 0;
	in_mean_income = 0;
	in_week_of_month = 0;
	in_weekly_budget = 0;
	in_rationed = 0;
	in_mall_completely_sold_out = 0;
	in_order_quantity = 0;
	in_received_quantity = 0;
	in_day_of_week_to_act = 0;
	in_day_of_month_receive_income = 0;
	in_current_productivity_employer = 0;
	in_current_mean_specific_skills_employer = 0;
	in_total_taxes = 0;
	in_cum_total_dividends = 0;
	in_tax_rate_hh_capital = 0;
	in_tax_rate_hh_labour = 0;
	in_last_income = 0;
	in_expenditures = 0;
	in_received_dividend = 0;
	in_household_portfolio = 0;
	in_wage = 0;
	in_wage_reservation = 0;
	in_general_skill = 0;
	in_on_the_job_search = 0;
	in_number_applications = 0;
	in_specific_skill = 0;
	in_employee_firm_id = 0;
	in_employer_region_id = 0;
	in_current_stock = 0;
	in_firm_revenues = 0;
	in_total_supply = 0;
	in_productivity = 0;
	in_innovation_probability = 0;
	in_productivity_progress = 0;
	in_capital_good_price = 0;
	in_net_profit = 0;
	in_outstanding_shares = 0;
	in_cum_revenues = 0;
	in_no_regions = 0;
	in_num_households = 0;
	in_no_households_skill_1 = 0;
	in_no_households_skill_2 = 0;
	in_no_households_skill_3 = 0;
	in_no_households_skill_4 = 0;
	in_no_households_skill_5 = 0;
	in_employed = 0;
	in_employed_skill_1 = 0;
	in_employed_skill_2 = 0;
	in_employed_skill_3 = 0;
	in_employed_skill_4 = 0;
	in_employed_skill_5 = 0;
	in_unemployed = 0;
	in_unemployment_rate = 0;
	in_unemployment_rate_skill_1 = 0;
	in_unemployment_rate_skill_2 = 0;
	in_unemployment_rate_skill_3 = 0;
	in_unemployment_rate_skill_4 = 0;
	in_unemployment_rate_skill_5 = 0;
	in_average_wage = 0;
	in_average_wage_skill_1 = 0;
	in_average_wage_skill_2 = 0;
	in_average_wage_skill_3 = 0;
	in_average_wage_skill_4 = 0;
	in_average_wage_skill_5 = 0;
	in_average_s_skill = 0;
	in_average_s_skill_1 = 0;
	in_average_s_skill_2 = 0;
	in_average_s_skill_3 = 0;
	in_average_s_skill_4 = 0;
	in_average_s_skill_5 = 0;
	in_no_firms = 0;
	in_no_vacancies = 0;
	in_firm_average_wage = 0;
	in_firm_average_wage_skill_1 = 0;
	in_firm_average_wage_skill_2 = 0;
	in_firm_average_wage_skill_3 = 0;
	in_firm_average_wage_skill_4 = 0;
	in_firm_average_wage_skill_5 = 0;
	in_firm_average_s_skill = 0;
	in_firm_average_s_skill_1 = 0;
	in_firm_average_s_skill_2 = 0;
	in_firm_average_s_skill_3 = 0;
	in_firm_average_s_skill_4 = 0;
	in_firm_average_s_skill_5 = 0;
	in_region_firm_data = 0;
	in_region_household_data = 0;
	in_government_tax_rates = 0;
	in_gdp = 0;
	in_total_earnings = 0;
	in_total_equity = 0;
	in_average_debt_earnings_ratio = 0;
	in_average_debt_equity_ratio = 0;
	in_labour_share_ratio = 0;
	in_accounts = 0;
	in_loans_outstanding = 0;
	in_last_credit_id = 0;
	in_amount_credit_offer = 0;
	in_total_deposits = 0;
	in_total_loan_supply = 0;
	in_total_loan_demand = 0;
	in_tax_revenues = 0;
	in_unemployment_benefit_payment = 0;
	in_total_unemployment_benefit_payment = 0;
	in_num_unemployed = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	region_id = 0;
//	gov_id = 0;
//	day_of_month_to_act = 0;
//	payment_account = 0.0;
//	mean_wage = 0.0;
//	total_units_capital_stock = 0.0;
//	needed_capital_stock = 0.0;
//	actual_cap_price = 0.0;
//	mean_specific_skills = 0.0;
//	planned_production_quantity = 0.0;
//	production_quantity = 0.0;
//	unit_costs = 0.0;
//	production_costs = 0.0;
//	revenue_per_day = 0.0;
//	technological_frontier = 0.0;
//	cum_revenue = 0.0;
//	out_of_stock_costs = 0.0;
//	malls_sales_statistics = init_sales_statistics_array();
//	quality = 0.0;
//	price = 0.0;
//	price_last_month = 0.0;
//	demand_capital_stock = 0.0;
//	planned_production_costs = 0.0;
//	adaption_production_volume_due_to_insufficient_finances = 0.0;
//	fraction_reserved_for_delayed_payments = 0.0;
//	sold_quantities = init_sold_quantities_per_mall_array();
//	total_sold_quantity = 0.0;
//	cum_total_sold_quantity = 0.0;
//	delivery_volume = init_delivery_volume_per_mall_array();
//	planned_delivery_volume = init_delivery_volume_per_mall_array();
//	current_mall_stocks = init_mall_info_array();
//	last_planned_production_quantities = init_double_array();
//	direct_financial_needs_require_external_financing = 0.0;
//	total_external_financing_obtained = 0.0;
//	delayed_financial_needs_require_external_financing = 0.0;
//	capital_costs = 0.0;
//	labour_costs = 0.0;
//	capital_financing = init_financing_capital_array();
//	bank_id = 0;
//	ebit = 0.0;
//	earnings = 0.0;
//	tax_rate_corporate = 0.0;
//	tax_rate_vat = 0.0;
//	tax_payment = 0.0;
//	net_earnings = 0.0;
//	previous_net_earnings = 0.0;
//	earnings_per_share = 0.0;
//	current_shares_outstanding = 0;
//	total_interest_payment = 0.0;
//	total_debt_installment_payment = 0.0;
//	total_dividend_payment = 0.0;
//	previous_dividend_per_share = 0.0;
//	current_dividend_per_share = 0.0;
//	previous_earnings_per_share = 0.0;
//	current_earnings_per_share = 0.0;
//	previous_dividend_per_earnings = 0.0;
//	current_dividend_per_earnings = 0.0;
//	financial_resources_for_production = 0.0;
//	loans = init_debt_item_array();
//	total_debt = 0.0;
//	total_value_local_inventory = 0.0;
//	total_units_local_inventory = 0.0;
//	total_value_capital_stock = 0.0;
//	planned_value_capital_stock = 0.0;
//	total_capital_depreciation_value = 0.0;
//	total_capital_depreciation_units = 0.0;
//	total_assets = 0.0;
//	planned_total_assets = 0.0;
//	equity = 0.0;
//	production_liquidity_needs = 0.0;
//	financial_liquidity_needs = 0.0;
//	total_financial_needs = 0.0;
//	external_financial_needs = 0.0;
//	total_payments = 0.0;
//	employees = init_employee_array();
//	wage_offer = 0.0;
//	technology = 0.0;
//	no_employees = 0;
//	no_employees_skill_1 = 0;
//	no_employees_skill_2 = 0;
//	no_employees_skill_3 = 0;
//	no_employees_skill_4 = 0;
//	no_employees_skill_5 = 0;
//	vacancies = 0;
//	average_g_skill = 0.0;
//	average_s_skill_of_1 = 0.0;
//	average_s_skill_of_2 = 0.0;
//	average_s_skill_of_3 = 0.0;
//	average_s_skill_of_4 = 0.0;
//	average_s_skill_of_5 = 0.0;
//	wage_offer_for_skill_1 = 0.0;
//	wage_offer_for_skill_2 = 0.0;
//	wage_offer_for_skill_3 = 0.0;
//	wage_offer_for_skill_4 = 0.0;
//	wage_offer_for_skill_5 = 0.0;
//	employees_needed = 0;
//	neighboring_region_ids = init_int_array();
//	consumption_budget = 0.0;
//	mean_income = 0.0;
//	week_of_month = 0;
//	weekly_budget = 0.0;
//	rationed = 0;
//	mall_completely_sold_out = 0;
//	order_quantity = init_ordered_quantity_static_array(2);
//	received_quantity = init_received_quantities_static_array(2);
//	day_of_week_to_act = 0;
//	day_of_month_receive_income = 0;
//	current_productivity_employer = 0.0;
//	current_mean_specific_skills_employer = 0.0;
//	total_taxes = 0.0;
//	cum_total_dividends = 0.0;
//	tax_rate_hh_capital = 0.0;
//	tax_rate_hh_labour = 0.0;
//	last_income = init_double_array();
//	expenditures = 0.0;
//	received_dividend = 0.0;
//	household_portfolio = init_portfolio_array();
//	wage = 0.0;
//	wage_reservation = 0.0;
//	general_skill = 0;
//	on_the_job_search = 0;
//	number_applications = 0;
//	specific_skill = 0.0;
//	employee_firm_id = 0;
//	employer_region_id = 0;
//	current_stock = init_mall_stock_array();
//	firm_revenues = init_sales_in_mall_array();
//	total_supply = 0.0;
//	productivity = 0.0;
//	innovation_probability = 0;
//	productivity_progress = 0.0;
//	capital_good_price = 0.0;
//	net_profit = 0.0;
//	outstanding_shares = 0;
//	cum_revenues = 0.0;
//	no_regions = 0;
//	num_households = 0;
//	no_households_skill_1 = 0;
//	no_households_skill_2 = 0;
//	no_households_skill_3 = 0;
//	no_households_skill_4 = 0;
//	no_households_skill_5 = 0;
//	employed = 0;
//	employed_skill_1 = 0;
//	employed_skill_2 = 0;
//	employed_skill_3 = 0;
//	employed_skill_4 = 0;
//	employed_skill_5 = 0;
//	unemployed = 0;
//	unemployment_rate = 0.0;
//	unemployment_rate_skill_1 = 0.0;
//	unemployment_rate_skill_2 = 0.0;
//	unemployment_rate_skill_3 = 0.0;
//	unemployment_rate_skill_4 = 0.0;
//	unemployment_rate_skill_5 = 0.0;
//	average_wage = 0.0;
//	average_wage_skill_1 = 0.0;
//	average_wage_skill_2 = 0.0;
//	average_wage_skill_3 = 0.0;
//	average_wage_skill_4 = 0.0;
//	average_wage_skill_5 = 0.0;
//	average_s_skill = 0.0;
//	average_s_skill_1 = 0.0;
//	average_s_skill_2 = 0.0;
//	average_s_skill_3 = 0.0;
//	average_s_skill_4 = 0.0;
//	average_s_skill_5 = 0.0;
//	no_firms = 0;
//	no_vacancies = 0;
//	firm_average_wage = 0.0;
//	firm_average_wage_skill_1 = 0.0;
//	firm_average_wage_skill_2 = 0.0;
//	firm_average_wage_skill_3 = 0.0;
//	firm_average_wage_skill_4 = 0.0;
//	firm_average_wage_skill_5 = 0.0;
//	firm_average_s_skill = 0.0;
//	firm_average_s_skill_1 = 0.0;
//	firm_average_s_skill_2 = 0.0;
//	firm_average_s_skill_3 = 0.0;
//	firm_average_s_skill_4 = 0.0;
//	firm_average_s_skill_5 = 0.0;
//	region_firm_data = init_firm_data_array();
//	region_household_data = init_household_data_array();
//	government_tax_rates = init_tax_rates_item_array();
//	gdp = 0.0;
//	total_earnings = 0.0;
//	total_equity = 0.0;
//	average_debt_earnings_ratio = 0.0;
//	average_debt_equity_ratio = 0.0;
//	labour_share_ratio = 0.0;
//	accounts = init_account_array();
//	loans_outstanding = init_outstanding_loans_array();
//	last_credit_id = 0;
//	amount_credit_offer = 0.0;
//	total_deposits = 0.0;
//	total_loan_supply = 0.0;
//	total_loan_demand = 0.0;
//	tax_revenues = 0.0;
//	unemployment_benefit_payment = 0.0;
//	total_unemployment_benefit_payment = 0.0;
//	num_unemployed = 0;







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
					else if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
					}
					else if(strcmp(agentname, "Mall") == 0)
					{
						current_Mall_agent = init_Mall_agent();
						in_Mall_agent = 1;
					}
					else if(strcmp(agentname, "IGFirm") == 0)
					{
						current_IGFirm_agent = init_IGFirm_agent();
						in_IGFirm_agent = 1;
					}
					else if(strcmp(agentname, "Eurostat") == 0)
					{
						current_Eurostat_agent = init_Eurostat_agent();
						in_Eurostat_agent = 1;
					}
					else if(strcmp(agentname, "Bank") == 0)
					{
						current_Bank_agent = init_Bank_agent();
						in_Bank_agent = 1;
					}
					else if(strcmp(agentname, "Government") == 0)
					{
						current_Government_agent = init_Government_agent();
						in_Government_agent = 1;
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
in_Household_agent = 0;
in_Mall_agent = 0;
in_IGFirm_agent = 0;
in_Eurostat_agent = 0;
in_Bank_agent = 0;
in_Government_agent = 0;

				
				if(strcmp(agentname, "Firm") == 0)
				{
					/*posx = current_Firm_agent->;
					posy = current_Firm_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, mean_wage, total_units_capital_stock, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, direct_financial_needs_require_external_financing, total_external_financing_obtained, delayed_financial_needs_require_external_financing, capital_costs, labour_costs, capital_financing, bank_id, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, current_shares_outstanding, total_interest_payment, total_debt_installment_payment, total_dividend_payment, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, financial_resources_for_production, loans, total_debt, total_value_local_inventory, total_units_local_inventory, total_value_capital_stock, planned_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, planned_total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, total_payments, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed);
						add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);
						
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
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, mean_wage, total_units_capital_stock, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, direct_financial_needs_require_external_financing, total_external_financing_obtained, delayed_financial_needs_require_external_financing, capital_costs, labour_costs, capital_financing, bank_id, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, current_shares_outstanding, total_interest_payment, total_debt_installment_payment, total_dividend_payment, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, financial_resources_for_production, loans, total_debt, total_value_local_inventory, total_units_local_inventory, total_value_capital_stock, planned_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, planned_total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, total_payments, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed);
								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);
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
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, payment_account, mean_wage, total_units_capital_stock, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, direct_financial_needs_require_external_financing, total_external_financing_obtained, delayed_financial_needs_require_external_financing, capital_costs, labour_costs, capital_financing, bank_id, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, earnings_per_share, current_shares_outstanding, total_interest_payment, total_debt_installment_payment, total_dividend_payment, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, financial_resources_for_production, loans, total_debt, total_value_local_inventory, total_units_local_inventory, total_value_capital_stock, planned_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, planned_total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, total_payments, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed);
								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);

								/*current_Firm_agent-> = xcentre;
								current_Firm_agent-> = ycentre;
								current_Firm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					/*posx = current_Household_agent->;
					posy = current_Household_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, bank_id, day_of_month_to_act, payment_account, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, last_income, expenditures, received_dividend, household_portfolio, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id);
						add_Household_agent_internal(current_Household_agent, Household_start_Household_state);
						
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
								//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, bank_id, day_of_month_to_act, payment_account, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, last_income, expenditures, received_dividend, household_portfolio, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id);
								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);
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
								//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, bank_id, day_of_month_to_act, payment_account, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, last_income, expenditures, received_dividend, household_portfolio, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id);
								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);

								/*current_Household_agent-> = xcentre;
								current_Household_agent-> = ycentre;
								current_Household_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Mall") == 0)
				{
					/*posx = current_Mall_agent->;
					posy = current_Mall_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Mall_agent(id, region_id, gov_id, current_stock, firm_revenues, total_supply);
						add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);
						
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
								//add_Mall_agent(id, region_id, gov_id, current_stock, firm_revenues, total_supply);
								add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);
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
								//add_Mall_agent(id, region_id, gov_id, current_stock, firm_revenues, total_supply);
								add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);

								/*current_Mall_agent-> = xcentre;
								current_Mall_agent-> = ycentre;
								current_Mall_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "IGFirm") == 0)
				{
					/*posx = current_IGFirm_agent->;
					posy = current_IGFirm_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues);
						add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);
						
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
								//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues);
								add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);
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
								//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues);
								add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);

								/*current_IGFirm_agent-> = xcentre;
								current_IGFirm_agent-> = ycentre;
								current_IGFirm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Eurostat") == 0)
				{
					/*posx = current_Eurostat_agent->;
					posy = current_Eurostat_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Eurostat_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, government_tax_rates, gdp, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio);
						add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);
						
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
								//add_Eurostat_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, government_tax_rates, gdp, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio);
								add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);
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
								//add_Eurostat_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, government_tax_rates, gdp, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio);
								add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);

								/*current_Eurostat_agent-> = xcentre;
								current_Eurostat_agent-> = ycentre;
								current_Eurostat_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Bank") == 0)
				{
					/*posx = current_Bank_agent->;
					posy = current_Bank_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Bank_agent(id, region_id, gov_id, accounts, loans_outstanding, last_credit_id, amount_credit_offer, total_deposits, total_loan_supply, total_loan_demand, payment_account);
						add_Bank_agent_internal(current_Bank_agent, Bank_Start_Bank_state);
						
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
								//add_Bank_agent(id, region_id, gov_id, accounts, loans_outstanding, last_credit_id, amount_credit_offer, total_deposits, total_loan_supply, total_loan_demand, payment_account);
								add_Bank_agent_internal(current_Bank_agent, Bank_Start_Bank_state);
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
								//add_Bank_agent(id, region_id, gov_id, accounts, loans_outstanding, last_credit_id, amount_credit_offer, total_deposits, total_loan_supply, total_loan_demand, payment_account);
								add_Bank_agent_internal(current_Bank_agent, Bank_Start_Bank_state);

								/*current_Bank_agent-> = xcentre;
								current_Bank_agent-> = ycentre;
								current_Bank_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Government") == 0)
				{
					/*posx = current_Government_agent->;
					posy = current_Government_agent->;
					posz = 0.0;*/
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Government_agent(id, bank_id, payment_account, tax_revenues, unemployment_benefit_payment, total_unemployment_benefit_payment, total_interest_payment, total_debt, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, num_unemployed);
						add_Government_agent_internal(current_Government_agent, Government_start_Government_state);
						
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
								//add_Government_agent(id, bank_id, payment_account, tax_revenues, unemployment_benefit_payment, total_unemployment_benefit_payment, total_interest_payment, total_debt, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, num_unemployed);
								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);
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
								//add_Government_agent(id, bank_id, payment_account, tax_revenues, unemployment_benefit_payment, total_unemployment_benefit_payment, total_interest_payment, total_debt, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, num_unemployed);
								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);

								/*current_Government_agent-> = xcentre;
								current_Government_agent-> = ycentre;
								current_Government_agent-> = rrange;*/

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
//				mean_wage = 0.0;
//				total_units_capital_stock = 0.0;
//				needed_capital_stock = 0.0;
//				actual_cap_price = 0.0;
//				mean_specific_skills = 0.0;
//				planned_production_quantity = 0.0;
//				production_quantity = 0.0;
//				unit_costs = 0.0;
//				production_costs = 0.0;
//				revenue_per_day = 0.0;
//				technological_frontier = 0.0;
//				cum_revenue = 0.0;
//				out_of_stock_costs = 0.0;
////				quality = 0.0;
//				price = 0.0;
//				price_last_month = 0.0;
//				demand_capital_stock = 0.0;
//				planned_production_costs = 0.0;
//				adaption_production_volume_due_to_insufficient_finances = 0.0;
//				fraction_reserved_for_delayed_payments = 0.0;
////				total_sold_quantity = 0.0;
//				cum_total_sold_quantity = 0.0;
//////////				direct_financial_needs_require_external_financing = 0.0;
//				total_external_financing_obtained = 0.0;
//				delayed_financial_needs_require_external_financing = 0.0;
//				capital_costs = 0.0;
//				labour_costs = 0.0;
////				bank_id = 0;
//				ebit = 0.0;
//				earnings = 0.0;
//				tax_rate_corporate = 0.0;
//				tax_rate_vat = 0.0;
//				tax_payment = 0.0;
//				net_earnings = 0.0;
//				previous_net_earnings = 0.0;
//				earnings_per_share = 0.0;
//				current_shares_outstanding = 0;
//				total_interest_payment = 0.0;
//				total_debt_installment_payment = 0.0;
//				total_dividend_payment = 0.0;
//				previous_dividend_per_share = 0.0;
//				current_dividend_per_share = 0.0;
//				previous_earnings_per_share = 0.0;
//				current_earnings_per_share = 0.0;
//				previous_dividend_per_earnings = 0.0;
//				current_dividend_per_earnings = 0.0;
//				financial_resources_for_production = 0.0;
////				total_debt = 0.0;
//				total_value_local_inventory = 0.0;
//				total_units_local_inventory = 0.0;
//				total_value_capital_stock = 0.0;
//				planned_value_capital_stock = 0.0;
//				total_capital_depreciation_value = 0.0;
//				total_capital_depreciation_units = 0.0;
//				total_assets = 0.0;
//				planned_total_assets = 0.0;
//				equity = 0.0;
//				production_liquidity_needs = 0.0;
//				financial_liquidity_needs = 0.0;
//				total_financial_needs = 0.0;
//				external_financial_needs = 0.0;
//				total_payments = 0.0;
////				wage_offer = 0.0;
//				technology = 0.0;
//				no_employees = 0;
//				no_employees_skill_1 = 0;
//				no_employees_skill_2 = 0;
//				no_employees_skill_3 = 0;
//				no_employees_skill_4 = 0;
//				no_employees_skill_5 = 0;
//				vacancies = 0;
//				average_g_skill = 0.0;
//				average_s_skill_of_1 = 0.0;
//				average_s_skill_of_2 = 0.0;
//				average_s_skill_of_3 = 0.0;
//				average_s_skill_of_4 = 0.0;
//				average_s_skill_of_5 = 0.0;
//				wage_offer_for_skill_1 = 0.0;
//				wage_offer_for_skill_2 = 0.0;
//				wage_offer_for_skill_3 = 0.0;
//				wage_offer_for_skill_4 = 0.0;
//				wage_offer_for_skill_5 = 0.0;
//				employees_needed = 0;
////				consumption_budget = 0.0;
//				mean_income = 0.0;
//				week_of_month = 0;
//				weekly_budget = 0.0;
//				rationed = 0;
//				mall_completely_sold_out = 0;
//////				day_of_week_to_act = 0;
//				day_of_month_receive_income = 0;
//				current_productivity_employer = 0.0;
//				current_mean_specific_skills_employer = 0.0;
//				total_taxes = 0.0;
//				cum_total_dividends = 0.0;
//				tax_rate_hh_capital = 0.0;
//				tax_rate_hh_labour = 0.0;
////				expenditures = 0.0;
//				received_dividend = 0.0;
////				wage = 0.0;
//				wage_reservation = 0.0;
//				general_skill = 0;
//				on_the_job_search = 0;
//				number_applications = 0;
//				specific_skill = 0.0;
//				employee_firm_id = 0;
//				employer_region_id = 0;
//////				total_supply = 0.0;
//				productivity = 0.0;
//				innovation_probability = 0;
//				productivity_progress = 0.0;
//				capital_good_price = 0.0;
//				net_profit = 0.0;
//				outstanding_shares = 0;
//				cum_revenues = 0.0;
//				no_regions = 0;
//				num_households = 0;
//				no_households_skill_1 = 0;
//				no_households_skill_2 = 0;
//				no_households_skill_3 = 0;
//				no_households_skill_4 = 0;
//				no_households_skill_5 = 0;
//				employed = 0;
//				employed_skill_1 = 0;
//				employed_skill_2 = 0;
//				employed_skill_3 = 0;
//				employed_skill_4 = 0;
//				employed_skill_5 = 0;
//				unemployed = 0;
//				unemployment_rate = 0.0;
//				unemployment_rate_skill_1 = 0.0;
//				unemployment_rate_skill_2 = 0.0;
//				unemployment_rate_skill_3 = 0.0;
//				unemployment_rate_skill_4 = 0.0;
//				unemployment_rate_skill_5 = 0.0;
//				average_wage = 0.0;
//				average_wage_skill_1 = 0.0;
//				average_wage_skill_2 = 0.0;
//				average_wage_skill_3 = 0.0;
//				average_wage_skill_4 = 0.0;
//				average_wage_skill_5 = 0.0;
//				average_s_skill = 0.0;
//				average_s_skill_1 = 0.0;
//				average_s_skill_2 = 0.0;
//				average_s_skill_3 = 0.0;
//				average_s_skill_4 = 0.0;
//				average_s_skill_5 = 0.0;
//				no_firms = 0;
//				no_vacancies = 0;
//				firm_average_wage = 0.0;
//				firm_average_wage_skill_1 = 0.0;
//				firm_average_wage_skill_2 = 0.0;
//				firm_average_wage_skill_3 = 0.0;
//				firm_average_wage_skill_4 = 0.0;
//				firm_average_wage_skill_5 = 0.0;
//				firm_average_s_skill = 0.0;
//				firm_average_s_skill_1 = 0.0;
//				firm_average_s_skill_2 = 0.0;
//				firm_average_s_skill_3 = 0.0;
//				firm_average_s_skill_4 = 0.0;
//				firm_average_s_skill_5 = 0.0;
////////				gdp = 0.0;
//				total_earnings = 0.0;
//				total_equity = 0.0;
//				average_debt_earnings_ratio = 0.0;
//				average_debt_equity_ratio = 0.0;
//				labour_share_ratio = 0.0;
//////				last_credit_id = 0;
//				amount_credit_offer = 0.0;
//				total_deposits = 0.0;
//				total_loan_supply = 0.0;
//				total_loan_demand = 0.0;
//				tax_revenues = 0.0;
//				unemployment_benefit_payment = 0.0;
//				total_unemployment_benefit_payment = 0.0;
//				num_unemployed = 0;

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
			if(strcmp(buffer, "mean_wage") == 0) in_mean_wage = 1;
			if(strcmp(buffer, "/mean_wage") == 0) in_mean_wage = 0;
			if(strcmp(buffer, "total_units_capital_stock") == 0) in_total_units_capital_stock = 1;
			if(strcmp(buffer, "/total_units_capital_stock") == 0) in_total_units_capital_stock = 0;
			if(strcmp(buffer, "needed_capital_stock") == 0) in_needed_capital_stock = 1;
			if(strcmp(buffer, "/needed_capital_stock") == 0) in_needed_capital_stock = 0;
			if(strcmp(buffer, "actual_cap_price") == 0) in_actual_cap_price = 1;
			if(strcmp(buffer, "/actual_cap_price") == 0) in_actual_cap_price = 0;
			if(strcmp(buffer, "mean_specific_skills") == 0) in_mean_specific_skills = 1;
			if(strcmp(buffer, "/mean_specific_skills") == 0) in_mean_specific_skills = 0;
			if(strcmp(buffer, "planned_production_quantity") == 0) in_planned_production_quantity = 1;
			if(strcmp(buffer, "/planned_production_quantity") == 0) in_planned_production_quantity = 0;
			if(strcmp(buffer, "production_quantity") == 0) in_production_quantity = 1;
			if(strcmp(buffer, "/production_quantity") == 0) in_production_quantity = 0;
			if(strcmp(buffer, "unit_costs") == 0) in_unit_costs = 1;
			if(strcmp(buffer, "/unit_costs") == 0) in_unit_costs = 0;
			if(strcmp(buffer, "production_costs") == 0) in_production_costs = 1;
			if(strcmp(buffer, "/production_costs") == 0) in_production_costs = 0;
			if(strcmp(buffer, "revenue_per_day") == 0) in_revenue_per_day = 1;
			if(strcmp(buffer, "/revenue_per_day") == 0) in_revenue_per_day = 0;
			if(strcmp(buffer, "technological_frontier") == 0) in_technological_frontier = 1;
			if(strcmp(buffer, "/technological_frontier") == 0) in_technological_frontier = 0;
			if(strcmp(buffer, "cum_revenue") == 0) in_cum_revenue = 1;
			if(strcmp(buffer, "/cum_revenue") == 0) in_cum_revenue = 0;
			if(strcmp(buffer, "out_of_stock_costs") == 0) in_out_of_stock_costs = 1;
			if(strcmp(buffer, "/out_of_stock_costs") == 0) in_out_of_stock_costs = 0;
			if(strcmp(buffer, "malls_sales_statistics") == 0) in_malls_sales_statistics = 1;
			if(strcmp(buffer, "/malls_sales_statistics") == 0) in_malls_sales_statistics = 0;
			if(strcmp(buffer, "quality") == 0) in_quality = 1;
			if(strcmp(buffer, "/quality") == 0) in_quality = 0;
			if(strcmp(buffer, "price") == 0) in_price = 1;
			if(strcmp(buffer, "/price") == 0) in_price = 0;
			if(strcmp(buffer, "price_last_month") == 0) in_price_last_month = 1;
			if(strcmp(buffer, "/price_last_month") == 0) in_price_last_month = 0;
			if(strcmp(buffer, "demand_capital_stock") == 0) in_demand_capital_stock = 1;
			if(strcmp(buffer, "/demand_capital_stock") == 0) in_demand_capital_stock = 0;
			if(strcmp(buffer, "planned_production_costs") == 0) in_planned_production_costs = 1;
			if(strcmp(buffer, "/planned_production_costs") == 0) in_planned_production_costs = 0;
			if(strcmp(buffer, "adaption_production_volume_due_to_insufficient_finances") == 0) in_adaption_production_volume_due_to_insufficient_finances = 1;
			if(strcmp(buffer, "/adaption_production_volume_due_to_insufficient_finances") == 0) in_adaption_production_volume_due_to_insufficient_finances = 0;
			if(strcmp(buffer, "fraction_reserved_for_delayed_payments") == 0) in_fraction_reserved_for_delayed_payments = 1;
			if(strcmp(buffer, "/fraction_reserved_for_delayed_payments") == 0) in_fraction_reserved_for_delayed_payments = 0;
			if(strcmp(buffer, "sold_quantities") == 0) in_sold_quantities = 1;
			if(strcmp(buffer, "/sold_quantities") == 0) in_sold_quantities = 0;
			if(strcmp(buffer, "total_sold_quantity") == 0) in_total_sold_quantity = 1;
			if(strcmp(buffer, "/total_sold_quantity") == 0) in_total_sold_quantity = 0;
			if(strcmp(buffer, "cum_total_sold_quantity") == 0) in_cum_total_sold_quantity = 1;
			if(strcmp(buffer, "/cum_total_sold_quantity") == 0) in_cum_total_sold_quantity = 0;
			if(strcmp(buffer, "delivery_volume") == 0) in_delivery_volume = 1;
			if(strcmp(buffer, "/delivery_volume") == 0) in_delivery_volume = 0;
			if(strcmp(buffer, "planned_delivery_volume") == 0) in_planned_delivery_volume = 1;
			if(strcmp(buffer, "/planned_delivery_volume") == 0) in_planned_delivery_volume = 0;
			if(strcmp(buffer, "current_mall_stocks") == 0) in_current_mall_stocks = 1;
			if(strcmp(buffer, "/current_mall_stocks") == 0) in_current_mall_stocks = 0;
			if(strcmp(buffer, "last_planned_production_quantities") == 0) in_last_planned_production_quantities = 1;
			if(strcmp(buffer, "/last_planned_production_quantities") == 0) in_last_planned_production_quantities = 0;
			if(strcmp(buffer, "direct_financial_needs_require_external_financing") == 0) in_direct_financial_needs_require_external_financing = 1;
			if(strcmp(buffer, "/direct_financial_needs_require_external_financing") == 0) in_direct_financial_needs_require_external_financing = 0;
			if(strcmp(buffer, "total_external_financing_obtained") == 0) in_total_external_financing_obtained = 1;
			if(strcmp(buffer, "/total_external_financing_obtained") == 0) in_total_external_financing_obtained = 0;
			if(strcmp(buffer, "delayed_financial_needs_require_external_financing") == 0) in_delayed_financial_needs_require_external_financing = 1;
			if(strcmp(buffer, "/delayed_financial_needs_require_external_financing") == 0) in_delayed_financial_needs_require_external_financing = 0;
			if(strcmp(buffer, "capital_costs") == 0) in_capital_costs = 1;
			if(strcmp(buffer, "/capital_costs") == 0) in_capital_costs = 0;
			if(strcmp(buffer, "labour_costs") == 0) in_labour_costs = 1;
			if(strcmp(buffer, "/labour_costs") == 0) in_labour_costs = 0;
			if(strcmp(buffer, "capital_financing") == 0) in_capital_financing = 1;
			if(strcmp(buffer, "/capital_financing") == 0) in_capital_financing = 0;
			if(strcmp(buffer, "bank_id") == 0) in_bank_id = 1;
			if(strcmp(buffer, "/bank_id") == 0) in_bank_id = 0;
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
			if(strcmp(buffer, "current_shares_outstanding") == 0) in_current_shares_outstanding = 1;
			if(strcmp(buffer, "/current_shares_outstanding") == 0) in_current_shares_outstanding = 0;
			if(strcmp(buffer, "total_interest_payment") == 0) in_total_interest_payment = 1;
			if(strcmp(buffer, "/total_interest_payment") == 0) in_total_interest_payment = 0;
			if(strcmp(buffer, "total_debt_installment_payment") == 0) in_total_debt_installment_payment = 1;
			if(strcmp(buffer, "/total_debt_installment_payment") == 0) in_total_debt_installment_payment = 0;
			if(strcmp(buffer, "total_dividend_payment") == 0) in_total_dividend_payment = 1;
			if(strcmp(buffer, "/total_dividend_payment") == 0) in_total_dividend_payment = 0;
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
			if(strcmp(buffer, "financial_resources_for_production") == 0) in_financial_resources_for_production = 1;
			if(strcmp(buffer, "/financial_resources_for_production") == 0) in_financial_resources_for_production = 0;
			if(strcmp(buffer, "loans") == 0) in_loans = 1;
			if(strcmp(buffer, "/loans") == 0) in_loans = 0;
			if(strcmp(buffer, "total_debt") == 0) in_total_debt = 1;
			if(strcmp(buffer, "/total_debt") == 0) in_total_debt = 0;
			if(strcmp(buffer, "total_value_local_inventory") == 0) in_total_value_local_inventory = 1;
			if(strcmp(buffer, "/total_value_local_inventory") == 0) in_total_value_local_inventory = 0;
			if(strcmp(buffer, "total_units_local_inventory") == 0) in_total_units_local_inventory = 1;
			if(strcmp(buffer, "/total_units_local_inventory") == 0) in_total_units_local_inventory = 0;
			if(strcmp(buffer, "total_value_capital_stock") == 0) in_total_value_capital_stock = 1;
			if(strcmp(buffer, "/total_value_capital_stock") == 0) in_total_value_capital_stock = 0;
			if(strcmp(buffer, "planned_value_capital_stock") == 0) in_planned_value_capital_stock = 1;
			if(strcmp(buffer, "/planned_value_capital_stock") == 0) in_planned_value_capital_stock = 0;
			if(strcmp(buffer, "total_capital_depreciation_value") == 0) in_total_capital_depreciation_value = 1;
			if(strcmp(buffer, "/total_capital_depreciation_value") == 0) in_total_capital_depreciation_value = 0;
			if(strcmp(buffer, "total_capital_depreciation_units") == 0) in_total_capital_depreciation_units = 1;
			if(strcmp(buffer, "/total_capital_depreciation_units") == 0) in_total_capital_depreciation_units = 0;
			if(strcmp(buffer, "total_assets") == 0) in_total_assets = 1;
			if(strcmp(buffer, "/total_assets") == 0) in_total_assets = 0;
			if(strcmp(buffer, "planned_total_assets") == 0) in_planned_total_assets = 1;
			if(strcmp(buffer, "/planned_total_assets") == 0) in_planned_total_assets = 0;
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
			if(strcmp(buffer, "total_payments") == 0) in_total_payments = 1;
			if(strcmp(buffer, "/total_payments") == 0) in_total_payments = 0;
			if(strcmp(buffer, "employees") == 0) in_employees = 1;
			if(strcmp(buffer, "/employees") == 0) in_employees = 0;
			if(strcmp(buffer, "wage_offer") == 0) in_wage_offer = 1;
			if(strcmp(buffer, "/wage_offer") == 0) in_wage_offer = 0;
			if(strcmp(buffer, "technology") == 0) in_technology = 1;
			if(strcmp(buffer, "/technology") == 0) in_technology = 0;
			if(strcmp(buffer, "no_employees") == 0) in_no_employees = 1;
			if(strcmp(buffer, "/no_employees") == 0) in_no_employees = 0;
			if(strcmp(buffer, "no_employees_skill_1") == 0) in_no_employees_skill_1 = 1;
			if(strcmp(buffer, "/no_employees_skill_1") == 0) in_no_employees_skill_1 = 0;
			if(strcmp(buffer, "no_employees_skill_2") == 0) in_no_employees_skill_2 = 1;
			if(strcmp(buffer, "/no_employees_skill_2") == 0) in_no_employees_skill_2 = 0;
			if(strcmp(buffer, "no_employees_skill_3") == 0) in_no_employees_skill_3 = 1;
			if(strcmp(buffer, "/no_employees_skill_3") == 0) in_no_employees_skill_3 = 0;
			if(strcmp(buffer, "no_employees_skill_4") == 0) in_no_employees_skill_4 = 1;
			if(strcmp(buffer, "/no_employees_skill_4") == 0) in_no_employees_skill_4 = 0;
			if(strcmp(buffer, "no_employees_skill_5") == 0) in_no_employees_skill_5 = 1;
			if(strcmp(buffer, "/no_employees_skill_5") == 0) in_no_employees_skill_5 = 0;
			if(strcmp(buffer, "vacancies") == 0) in_vacancies = 1;
			if(strcmp(buffer, "/vacancies") == 0) in_vacancies = 0;
			if(strcmp(buffer, "average_g_skill") == 0) in_average_g_skill = 1;
			if(strcmp(buffer, "/average_g_skill") == 0) in_average_g_skill = 0;
			if(strcmp(buffer, "average_s_skill_of_1") == 0) in_average_s_skill_of_1 = 1;
			if(strcmp(buffer, "/average_s_skill_of_1") == 0) in_average_s_skill_of_1 = 0;
			if(strcmp(buffer, "average_s_skill_of_2") == 0) in_average_s_skill_of_2 = 1;
			if(strcmp(buffer, "/average_s_skill_of_2") == 0) in_average_s_skill_of_2 = 0;
			if(strcmp(buffer, "average_s_skill_of_3") == 0) in_average_s_skill_of_3 = 1;
			if(strcmp(buffer, "/average_s_skill_of_3") == 0) in_average_s_skill_of_3 = 0;
			if(strcmp(buffer, "average_s_skill_of_4") == 0) in_average_s_skill_of_4 = 1;
			if(strcmp(buffer, "/average_s_skill_of_4") == 0) in_average_s_skill_of_4 = 0;
			if(strcmp(buffer, "average_s_skill_of_5") == 0) in_average_s_skill_of_5 = 1;
			if(strcmp(buffer, "/average_s_skill_of_5") == 0) in_average_s_skill_of_5 = 0;
			if(strcmp(buffer, "wage_offer_for_skill_1") == 0) in_wage_offer_for_skill_1 = 1;
			if(strcmp(buffer, "/wage_offer_for_skill_1") == 0) in_wage_offer_for_skill_1 = 0;
			if(strcmp(buffer, "wage_offer_for_skill_2") == 0) in_wage_offer_for_skill_2 = 1;
			if(strcmp(buffer, "/wage_offer_for_skill_2") == 0) in_wage_offer_for_skill_2 = 0;
			if(strcmp(buffer, "wage_offer_for_skill_3") == 0) in_wage_offer_for_skill_3 = 1;
			if(strcmp(buffer, "/wage_offer_for_skill_3") == 0) in_wage_offer_for_skill_3 = 0;
			if(strcmp(buffer, "wage_offer_for_skill_4") == 0) in_wage_offer_for_skill_4 = 1;
			if(strcmp(buffer, "/wage_offer_for_skill_4") == 0) in_wage_offer_for_skill_4 = 0;
			if(strcmp(buffer, "wage_offer_for_skill_5") == 0) in_wage_offer_for_skill_5 = 1;
			if(strcmp(buffer, "/wage_offer_for_skill_5") == 0) in_wage_offer_for_skill_5 = 0;
			if(strcmp(buffer, "employees_needed") == 0) in_employees_needed = 1;
			if(strcmp(buffer, "/employees_needed") == 0) in_employees_needed = 0;
			if(strcmp(buffer, "neighboring_region_ids") == 0) in_neighboring_region_ids = 1;
			if(strcmp(buffer, "/neighboring_region_ids") == 0) in_neighboring_region_ids = 0;
			if(strcmp(buffer, "consumption_budget") == 0) in_consumption_budget = 1;
			if(strcmp(buffer, "/consumption_budget") == 0) in_consumption_budget = 0;
			if(strcmp(buffer, "mean_income") == 0) in_mean_income = 1;
			if(strcmp(buffer, "/mean_income") == 0) in_mean_income = 0;
			if(strcmp(buffer, "week_of_month") == 0) in_week_of_month = 1;
			if(strcmp(buffer, "/week_of_month") == 0) in_week_of_month = 0;
			if(strcmp(buffer, "weekly_budget") == 0) in_weekly_budget = 1;
			if(strcmp(buffer, "/weekly_budget") == 0) in_weekly_budget = 0;
			if(strcmp(buffer, "rationed") == 0) in_rationed = 1;
			if(strcmp(buffer, "/rationed") == 0) in_rationed = 0;
			if(strcmp(buffer, "mall_completely_sold_out") == 0) in_mall_completely_sold_out = 1;
			if(strcmp(buffer, "/mall_completely_sold_out") == 0) in_mall_completely_sold_out = 0;
			if(strcmp(buffer, "order_quantity") == 0) in_order_quantity = 1;
			if(strcmp(buffer, "/order_quantity") == 0) in_order_quantity = 0;
			if(strcmp(buffer, "received_quantity") == 0) in_received_quantity = 1;
			if(strcmp(buffer, "/received_quantity") == 0) in_received_quantity = 0;
			if(strcmp(buffer, "day_of_week_to_act") == 0) in_day_of_week_to_act = 1;
			if(strcmp(buffer, "/day_of_week_to_act") == 0) in_day_of_week_to_act = 0;
			if(strcmp(buffer, "day_of_month_receive_income") == 0) in_day_of_month_receive_income = 1;
			if(strcmp(buffer, "/day_of_month_receive_income") == 0) in_day_of_month_receive_income = 0;
			if(strcmp(buffer, "current_productivity_employer") == 0) in_current_productivity_employer = 1;
			if(strcmp(buffer, "/current_productivity_employer") == 0) in_current_productivity_employer = 0;
			if(strcmp(buffer, "current_mean_specific_skills_employer") == 0) in_current_mean_specific_skills_employer = 1;
			if(strcmp(buffer, "/current_mean_specific_skills_employer") == 0) in_current_mean_specific_skills_employer = 0;
			if(strcmp(buffer, "total_taxes") == 0) in_total_taxes = 1;
			if(strcmp(buffer, "/total_taxes") == 0) in_total_taxes = 0;
			if(strcmp(buffer, "cum_total_dividends") == 0) in_cum_total_dividends = 1;
			if(strcmp(buffer, "/cum_total_dividends") == 0) in_cum_total_dividends = 0;
			if(strcmp(buffer, "tax_rate_hh_capital") == 0) in_tax_rate_hh_capital = 1;
			if(strcmp(buffer, "/tax_rate_hh_capital") == 0) in_tax_rate_hh_capital = 0;
			if(strcmp(buffer, "tax_rate_hh_labour") == 0) in_tax_rate_hh_labour = 1;
			if(strcmp(buffer, "/tax_rate_hh_labour") == 0) in_tax_rate_hh_labour = 0;
			if(strcmp(buffer, "last_income") == 0) in_last_income = 1;
			if(strcmp(buffer, "/last_income") == 0) in_last_income = 0;
			if(strcmp(buffer, "expenditures") == 0) in_expenditures = 1;
			if(strcmp(buffer, "/expenditures") == 0) in_expenditures = 0;
			if(strcmp(buffer, "received_dividend") == 0) in_received_dividend = 1;
			if(strcmp(buffer, "/received_dividend") == 0) in_received_dividend = 0;
			if(strcmp(buffer, "household_portfolio") == 0) in_household_portfolio = 1;
			if(strcmp(buffer, "/household_portfolio") == 0) in_household_portfolio = 0;
			if(strcmp(buffer, "wage") == 0) in_wage = 1;
			if(strcmp(buffer, "/wage") == 0) in_wage = 0;
			if(strcmp(buffer, "wage_reservation") == 0) in_wage_reservation = 1;
			if(strcmp(buffer, "/wage_reservation") == 0) in_wage_reservation = 0;
			if(strcmp(buffer, "general_skill") == 0) in_general_skill = 1;
			if(strcmp(buffer, "/general_skill") == 0) in_general_skill = 0;
			if(strcmp(buffer, "on_the_job_search") == 0) in_on_the_job_search = 1;
			if(strcmp(buffer, "/on_the_job_search") == 0) in_on_the_job_search = 0;
			if(strcmp(buffer, "number_applications") == 0) in_number_applications = 1;
			if(strcmp(buffer, "/number_applications") == 0) in_number_applications = 0;
			if(strcmp(buffer, "specific_skill") == 0) in_specific_skill = 1;
			if(strcmp(buffer, "/specific_skill") == 0) in_specific_skill = 0;
			if(strcmp(buffer, "employee_firm_id") == 0) in_employee_firm_id = 1;
			if(strcmp(buffer, "/employee_firm_id") == 0) in_employee_firm_id = 0;
			if(strcmp(buffer, "employer_region_id") == 0) in_employer_region_id = 1;
			if(strcmp(buffer, "/employer_region_id") == 0) in_employer_region_id = 0;
			if(strcmp(buffer, "current_stock") == 0) in_current_stock = 1;
			if(strcmp(buffer, "/current_stock") == 0) in_current_stock = 0;
			if(strcmp(buffer, "firm_revenues") == 0) in_firm_revenues = 1;
			if(strcmp(buffer, "/firm_revenues") == 0) in_firm_revenues = 0;
			if(strcmp(buffer, "total_supply") == 0) in_total_supply = 1;
			if(strcmp(buffer, "/total_supply") == 0) in_total_supply = 0;
			if(strcmp(buffer, "productivity") == 0) in_productivity = 1;
			if(strcmp(buffer, "/productivity") == 0) in_productivity = 0;
			if(strcmp(buffer, "innovation_probability") == 0) in_innovation_probability = 1;
			if(strcmp(buffer, "/innovation_probability") == 0) in_innovation_probability = 0;
			if(strcmp(buffer, "productivity_progress") == 0) in_productivity_progress = 1;
			if(strcmp(buffer, "/productivity_progress") == 0) in_productivity_progress = 0;
			if(strcmp(buffer, "capital_good_price") == 0) in_capital_good_price = 1;
			if(strcmp(buffer, "/capital_good_price") == 0) in_capital_good_price = 0;
			if(strcmp(buffer, "net_profit") == 0) in_net_profit = 1;
			if(strcmp(buffer, "/net_profit") == 0) in_net_profit = 0;
			if(strcmp(buffer, "outstanding_shares") == 0) in_outstanding_shares = 1;
			if(strcmp(buffer, "/outstanding_shares") == 0) in_outstanding_shares = 0;
			if(strcmp(buffer, "cum_revenues") == 0) in_cum_revenues = 1;
			if(strcmp(buffer, "/cum_revenues") == 0) in_cum_revenues = 0;
			if(strcmp(buffer, "no_regions") == 0) in_no_regions = 1;
			if(strcmp(buffer, "/no_regions") == 0) in_no_regions = 0;
			if(strcmp(buffer, "num_households") == 0) in_num_households = 1;
			if(strcmp(buffer, "/num_households") == 0) in_num_households = 0;
			if(strcmp(buffer, "no_households_skill_1") == 0) in_no_households_skill_1 = 1;
			if(strcmp(buffer, "/no_households_skill_1") == 0) in_no_households_skill_1 = 0;
			if(strcmp(buffer, "no_households_skill_2") == 0) in_no_households_skill_2 = 1;
			if(strcmp(buffer, "/no_households_skill_2") == 0) in_no_households_skill_2 = 0;
			if(strcmp(buffer, "no_households_skill_3") == 0) in_no_households_skill_3 = 1;
			if(strcmp(buffer, "/no_households_skill_3") == 0) in_no_households_skill_3 = 0;
			if(strcmp(buffer, "no_households_skill_4") == 0) in_no_households_skill_4 = 1;
			if(strcmp(buffer, "/no_households_skill_4") == 0) in_no_households_skill_4 = 0;
			if(strcmp(buffer, "no_households_skill_5") == 0) in_no_households_skill_5 = 1;
			if(strcmp(buffer, "/no_households_skill_5") == 0) in_no_households_skill_5 = 0;
			if(strcmp(buffer, "employed") == 0) in_employed = 1;
			if(strcmp(buffer, "/employed") == 0) in_employed = 0;
			if(strcmp(buffer, "employed_skill_1") == 0) in_employed_skill_1 = 1;
			if(strcmp(buffer, "/employed_skill_1") == 0) in_employed_skill_1 = 0;
			if(strcmp(buffer, "employed_skill_2") == 0) in_employed_skill_2 = 1;
			if(strcmp(buffer, "/employed_skill_2") == 0) in_employed_skill_2 = 0;
			if(strcmp(buffer, "employed_skill_3") == 0) in_employed_skill_3 = 1;
			if(strcmp(buffer, "/employed_skill_3") == 0) in_employed_skill_3 = 0;
			if(strcmp(buffer, "employed_skill_4") == 0) in_employed_skill_4 = 1;
			if(strcmp(buffer, "/employed_skill_4") == 0) in_employed_skill_4 = 0;
			if(strcmp(buffer, "employed_skill_5") == 0) in_employed_skill_5 = 1;
			if(strcmp(buffer, "/employed_skill_5") == 0) in_employed_skill_5 = 0;
			if(strcmp(buffer, "unemployed") == 0) in_unemployed = 1;
			if(strcmp(buffer, "/unemployed") == 0) in_unemployed = 0;
			if(strcmp(buffer, "unemployment_rate") == 0) in_unemployment_rate = 1;
			if(strcmp(buffer, "/unemployment_rate") == 0) in_unemployment_rate = 0;
			if(strcmp(buffer, "unemployment_rate_skill_1") == 0) in_unemployment_rate_skill_1 = 1;
			if(strcmp(buffer, "/unemployment_rate_skill_1") == 0) in_unemployment_rate_skill_1 = 0;
			if(strcmp(buffer, "unemployment_rate_skill_2") == 0) in_unemployment_rate_skill_2 = 1;
			if(strcmp(buffer, "/unemployment_rate_skill_2") == 0) in_unemployment_rate_skill_2 = 0;
			if(strcmp(buffer, "unemployment_rate_skill_3") == 0) in_unemployment_rate_skill_3 = 1;
			if(strcmp(buffer, "/unemployment_rate_skill_3") == 0) in_unemployment_rate_skill_3 = 0;
			if(strcmp(buffer, "unemployment_rate_skill_4") == 0) in_unemployment_rate_skill_4 = 1;
			if(strcmp(buffer, "/unemployment_rate_skill_4") == 0) in_unemployment_rate_skill_4 = 0;
			if(strcmp(buffer, "unemployment_rate_skill_5") == 0) in_unemployment_rate_skill_5 = 1;
			if(strcmp(buffer, "/unemployment_rate_skill_5") == 0) in_unemployment_rate_skill_5 = 0;
			if(strcmp(buffer, "average_wage") == 0) in_average_wage = 1;
			if(strcmp(buffer, "/average_wage") == 0) in_average_wage = 0;
			if(strcmp(buffer, "average_wage_skill_1") == 0) in_average_wage_skill_1 = 1;
			if(strcmp(buffer, "/average_wage_skill_1") == 0) in_average_wage_skill_1 = 0;
			if(strcmp(buffer, "average_wage_skill_2") == 0) in_average_wage_skill_2 = 1;
			if(strcmp(buffer, "/average_wage_skill_2") == 0) in_average_wage_skill_2 = 0;
			if(strcmp(buffer, "average_wage_skill_3") == 0) in_average_wage_skill_3 = 1;
			if(strcmp(buffer, "/average_wage_skill_3") == 0) in_average_wage_skill_3 = 0;
			if(strcmp(buffer, "average_wage_skill_4") == 0) in_average_wage_skill_4 = 1;
			if(strcmp(buffer, "/average_wage_skill_4") == 0) in_average_wage_skill_4 = 0;
			if(strcmp(buffer, "average_wage_skill_5") == 0) in_average_wage_skill_5 = 1;
			if(strcmp(buffer, "/average_wage_skill_5") == 0) in_average_wage_skill_5 = 0;
			if(strcmp(buffer, "average_s_skill") == 0) in_average_s_skill = 1;
			if(strcmp(buffer, "/average_s_skill") == 0) in_average_s_skill = 0;
			if(strcmp(buffer, "average_s_skill_1") == 0) in_average_s_skill_1 = 1;
			if(strcmp(buffer, "/average_s_skill_1") == 0) in_average_s_skill_1 = 0;
			if(strcmp(buffer, "average_s_skill_2") == 0) in_average_s_skill_2 = 1;
			if(strcmp(buffer, "/average_s_skill_2") == 0) in_average_s_skill_2 = 0;
			if(strcmp(buffer, "average_s_skill_3") == 0) in_average_s_skill_3 = 1;
			if(strcmp(buffer, "/average_s_skill_3") == 0) in_average_s_skill_3 = 0;
			if(strcmp(buffer, "average_s_skill_4") == 0) in_average_s_skill_4 = 1;
			if(strcmp(buffer, "/average_s_skill_4") == 0) in_average_s_skill_4 = 0;
			if(strcmp(buffer, "average_s_skill_5") == 0) in_average_s_skill_5 = 1;
			if(strcmp(buffer, "/average_s_skill_5") == 0) in_average_s_skill_5 = 0;
			if(strcmp(buffer, "no_firms") == 0) in_no_firms = 1;
			if(strcmp(buffer, "/no_firms") == 0) in_no_firms = 0;
			if(strcmp(buffer, "no_vacancies") == 0) in_no_vacancies = 1;
			if(strcmp(buffer, "/no_vacancies") == 0) in_no_vacancies = 0;
			if(strcmp(buffer, "firm_average_wage") == 0) in_firm_average_wage = 1;
			if(strcmp(buffer, "/firm_average_wage") == 0) in_firm_average_wage = 0;
			if(strcmp(buffer, "firm_average_wage_skill_1") == 0) in_firm_average_wage_skill_1 = 1;
			if(strcmp(buffer, "/firm_average_wage_skill_1") == 0) in_firm_average_wage_skill_1 = 0;
			if(strcmp(buffer, "firm_average_wage_skill_2") == 0) in_firm_average_wage_skill_2 = 1;
			if(strcmp(buffer, "/firm_average_wage_skill_2") == 0) in_firm_average_wage_skill_2 = 0;
			if(strcmp(buffer, "firm_average_wage_skill_3") == 0) in_firm_average_wage_skill_3 = 1;
			if(strcmp(buffer, "/firm_average_wage_skill_3") == 0) in_firm_average_wage_skill_3 = 0;
			if(strcmp(buffer, "firm_average_wage_skill_4") == 0) in_firm_average_wage_skill_4 = 1;
			if(strcmp(buffer, "/firm_average_wage_skill_4") == 0) in_firm_average_wage_skill_4 = 0;
			if(strcmp(buffer, "firm_average_wage_skill_5") == 0) in_firm_average_wage_skill_5 = 1;
			if(strcmp(buffer, "/firm_average_wage_skill_5") == 0) in_firm_average_wage_skill_5 = 0;
			if(strcmp(buffer, "firm_average_s_skill") == 0) in_firm_average_s_skill = 1;
			if(strcmp(buffer, "/firm_average_s_skill") == 0) in_firm_average_s_skill = 0;
			if(strcmp(buffer, "firm_average_s_skill_1") == 0) in_firm_average_s_skill_1 = 1;
			if(strcmp(buffer, "/firm_average_s_skill_1") == 0) in_firm_average_s_skill_1 = 0;
			if(strcmp(buffer, "firm_average_s_skill_2") == 0) in_firm_average_s_skill_2 = 1;
			if(strcmp(buffer, "/firm_average_s_skill_2") == 0) in_firm_average_s_skill_2 = 0;
			if(strcmp(buffer, "firm_average_s_skill_3") == 0) in_firm_average_s_skill_3 = 1;
			if(strcmp(buffer, "/firm_average_s_skill_3") == 0) in_firm_average_s_skill_3 = 0;
			if(strcmp(buffer, "firm_average_s_skill_4") == 0) in_firm_average_s_skill_4 = 1;
			if(strcmp(buffer, "/firm_average_s_skill_4") == 0) in_firm_average_s_skill_4 = 0;
			if(strcmp(buffer, "firm_average_s_skill_5") == 0) in_firm_average_s_skill_5 = 1;
			if(strcmp(buffer, "/firm_average_s_skill_5") == 0) in_firm_average_s_skill_5 = 0;
			if(strcmp(buffer, "region_firm_data") == 0) in_region_firm_data = 1;
			if(strcmp(buffer, "/region_firm_data") == 0) in_region_firm_data = 0;
			if(strcmp(buffer, "region_household_data") == 0) in_region_household_data = 1;
			if(strcmp(buffer, "/region_household_data") == 0) in_region_household_data = 0;
			if(strcmp(buffer, "government_tax_rates") == 0) in_government_tax_rates = 1;
			if(strcmp(buffer, "/government_tax_rates") == 0) in_government_tax_rates = 0;
			if(strcmp(buffer, "gdp") == 0) in_gdp = 1;
			if(strcmp(buffer, "/gdp") == 0) in_gdp = 0;
			if(strcmp(buffer, "total_earnings") == 0) in_total_earnings = 1;
			if(strcmp(buffer, "/total_earnings") == 0) in_total_earnings = 0;
			if(strcmp(buffer, "total_equity") == 0) in_total_equity = 1;
			if(strcmp(buffer, "/total_equity") == 0) in_total_equity = 0;
			if(strcmp(buffer, "average_debt_earnings_ratio") == 0) in_average_debt_earnings_ratio = 1;
			if(strcmp(buffer, "/average_debt_earnings_ratio") == 0) in_average_debt_earnings_ratio = 0;
			if(strcmp(buffer, "average_debt_equity_ratio") == 0) in_average_debt_equity_ratio = 1;
			if(strcmp(buffer, "/average_debt_equity_ratio") == 0) in_average_debt_equity_ratio = 0;
			if(strcmp(buffer, "labour_share_ratio") == 0) in_labour_share_ratio = 1;
			if(strcmp(buffer, "/labour_share_ratio") == 0) in_labour_share_ratio = 0;
			if(strcmp(buffer, "accounts") == 0) in_accounts = 1;
			if(strcmp(buffer, "/accounts") == 0) in_accounts = 0;
			if(strcmp(buffer, "loans_outstanding") == 0) in_loans_outstanding = 1;
			if(strcmp(buffer, "/loans_outstanding") == 0) in_loans_outstanding = 0;
			if(strcmp(buffer, "last_credit_id") == 0) in_last_credit_id = 1;
			if(strcmp(buffer, "/last_credit_id") == 0) in_last_credit_id = 0;
			if(strcmp(buffer, "amount_credit_offer") == 0) in_amount_credit_offer = 1;
			if(strcmp(buffer, "/amount_credit_offer") == 0) in_amount_credit_offer = 0;
			if(strcmp(buffer, "total_deposits") == 0) in_total_deposits = 1;
			if(strcmp(buffer, "/total_deposits") == 0) in_total_deposits = 0;
			if(strcmp(buffer, "total_loan_supply") == 0) in_total_loan_supply = 1;
			if(strcmp(buffer, "/total_loan_supply") == 0) in_total_loan_supply = 0;
			if(strcmp(buffer, "total_loan_demand") == 0) in_total_loan_demand = 1;
			if(strcmp(buffer, "/total_loan_demand") == 0) in_total_loan_demand = 0;
			if(strcmp(buffer, "tax_revenues") == 0) in_tax_revenues = 1;
			if(strcmp(buffer, "/tax_revenues") == 0) in_tax_revenues = 0;
			if(strcmp(buffer, "unemployment_benefit_payment") == 0) in_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/unemployment_benefit_payment") == 0) in_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "total_unemployment_benefit_payment") == 0) in_total_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/total_unemployment_benefit_payment") == 0) in_total_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "num_unemployed") == 0) in_num_unemployed = 1;
			if(strcmp(buffer, "/num_unemployed") == 0) in_num_unemployed = 0;


			
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
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_region_id) current_Firm_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Firm_agent->gov_id = atoi(buffer);
				if(in_day_of_month_to_act) current_Firm_agent->day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_Firm_agent->payment_account = atof(buffer);
				if(in_mean_wage) current_Firm_agent->mean_wage = atof(buffer);
				if(in_total_units_capital_stock) current_Firm_agent->total_units_capital_stock = atof(buffer);
				if(in_needed_capital_stock) current_Firm_agent->needed_capital_stock = atof(buffer);
				if(in_actual_cap_price) current_Firm_agent->actual_cap_price = atof(buffer);
				if(in_mean_specific_skills) current_Firm_agent->mean_specific_skills = atof(buffer);
				if(in_planned_production_quantity) current_Firm_agent->planned_production_quantity = atof(buffer);
				if(in_production_quantity) current_Firm_agent->production_quantity = atof(buffer);
				if(in_unit_costs) current_Firm_agent->unit_costs = atof(buffer);
				if(in_production_costs) current_Firm_agent->production_costs = atof(buffer);
				if(in_revenue_per_day) current_Firm_agent->revenue_per_day = atof(buffer);
				if(in_technological_frontier) current_Firm_agent->technological_frontier = atof(buffer);
				if(in_cum_revenue) current_Firm_agent->cum_revenue = atof(buffer);
				if(in_out_of_stock_costs) current_Firm_agent->out_of_stock_costs = atof(buffer);
				if(in_malls_sales_statistics) read_sales_statistics_dynamic_array(buffer, &j, &current_Firm_agent->malls_sales_statistics);
				if(in_quality) current_Firm_agent->quality = atof(buffer);
				if(in_price) current_Firm_agent->price = atof(buffer);
				if(in_price_last_month) current_Firm_agent->price_last_month = atof(buffer);
				if(in_demand_capital_stock) current_Firm_agent->demand_capital_stock = atof(buffer);
				if(in_planned_production_costs) current_Firm_agent->planned_production_costs = atof(buffer);
				if(in_adaption_production_volume_due_to_insufficient_finances) current_Firm_agent->adaption_production_volume_due_to_insufficient_finances = atof(buffer);
				if(in_fraction_reserved_for_delayed_payments) current_Firm_agent->fraction_reserved_for_delayed_payments = atof(buffer);
				if(in_sold_quantities) read_sold_quantities_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->sold_quantities);
				if(in_total_sold_quantity) current_Firm_agent->total_sold_quantity = atof(buffer);
				if(in_cum_total_sold_quantity) current_Firm_agent->cum_total_sold_quantity = atof(buffer);
				if(in_delivery_volume) read_delivery_volume_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->delivery_volume);
				if(in_planned_delivery_volume) read_delivery_volume_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->planned_delivery_volume);
				if(in_current_mall_stocks) read_mall_info_dynamic_array(buffer, &j, &current_Firm_agent->current_mall_stocks);
				if(in_last_planned_production_quantities) read_double_dynamic_array(buffer, &j, &current_Firm_agent->last_planned_production_quantities);
				if(in_direct_financial_needs_require_external_financing) current_Firm_agent->direct_financial_needs_require_external_financing = atof(buffer);
				if(in_total_external_financing_obtained) current_Firm_agent->total_external_financing_obtained = atof(buffer);
				if(in_delayed_financial_needs_require_external_financing) current_Firm_agent->delayed_financial_needs_require_external_financing = atof(buffer);
				if(in_capital_costs) current_Firm_agent->capital_costs = atof(buffer);
				if(in_labour_costs) current_Firm_agent->labour_costs = atof(buffer);
				if(in_capital_financing) read_financing_capital_dynamic_array(buffer, &j, &current_Firm_agent->capital_financing);
				if(in_bank_id) current_Firm_agent->bank_id = atoi(buffer);
				if(in_ebit) current_Firm_agent->ebit = atof(buffer);
				if(in_earnings) current_Firm_agent->earnings = atof(buffer);
				if(in_tax_rate_corporate) current_Firm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_vat) current_Firm_agent->tax_rate_vat = atof(buffer);
				if(in_tax_payment) current_Firm_agent->tax_payment = atof(buffer);
				if(in_net_earnings) current_Firm_agent->net_earnings = atof(buffer);
				if(in_previous_net_earnings) current_Firm_agent->previous_net_earnings = atof(buffer);
				if(in_earnings_per_share) current_Firm_agent->earnings_per_share = atof(buffer);
				if(in_current_shares_outstanding) current_Firm_agent->current_shares_outstanding = atoi(buffer);
				if(in_total_interest_payment) current_Firm_agent->total_interest_payment = atof(buffer);
				if(in_total_debt_installment_payment) current_Firm_agent->total_debt_installment_payment = atof(buffer);
				if(in_total_dividend_payment) current_Firm_agent->total_dividend_payment = atof(buffer);
				if(in_previous_dividend_per_share) current_Firm_agent->previous_dividend_per_share = atof(buffer);
				if(in_current_dividend_per_share) current_Firm_agent->current_dividend_per_share = atof(buffer);
				if(in_previous_earnings_per_share) current_Firm_agent->previous_earnings_per_share = atof(buffer);
				if(in_current_earnings_per_share) current_Firm_agent->current_earnings_per_share = atof(buffer);
				if(in_previous_dividend_per_earnings) current_Firm_agent->previous_dividend_per_earnings = atof(buffer);
				if(in_current_dividend_per_earnings) current_Firm_agent->current_dividend_per_earnings = atof(buffer);
				if(in_financial_resources_for_production) current_Firm_agent->financial_resources_for_production = atof(buffer);
				if(in_loans) read_debt_item_dynamic_array(buffer, &j, &current_Firm_agent->loans);
				if(in_total_debt) current_Firm_agent->total_debt = atof(buffer);
				if(in_total_value_local_inventory) current_Firm_agent->total_value_local_inventory = atof(buffer);
				if(in_total_units_local_inventory) current_Firm_agent->total_units_local_inventory = atof(buffer);
				if(in_total_value_capital_stock) current_Firm_agent->total_value_capital_stock = atof(buffer);
				if(in_planned_value_capital_stock) current_Firm_agent->planned_value_capital_stock = atof(buffer);
				if(in_total_capital_depreciation_value) current_Firm_agent->total_capital_depreciation_value = atof(buffer);
				if(in_total_capital_depreciation_units) current_Firm_agent->total_capital_depreciation_units = atof(buffer);
				if(in_total_assets) current_Firm_agent->total_assets = atof(buffer);
				if(in_planned_total_assets) current_Firm_agent->planned_total_assets = atof(buffer);
				if(in_equity) current_Firm_agent->equity = atof(buffer);
				if(in_production_liquidity_needs) current_Firm_agent->production_liquidity_needs = atof(buffer);
				if(in_financial_liquidity_needs) current_Firm_agent->financial_liquidity_needs = atof(buffer);
				if(in_total_financial_needs) current_Firm_agent->total_financial_needs = atof(buffer);
				if(in_external_financial_needs) current_Firm_agent->external_financial_needs = atof(buffer);
				if(in_total_payments) current_Firm_agent->total_payments = atof(buffer);
				if(in_employees) read_employee_dynamic_array(buffer, &j, &current_Firm_agent->employees);
				if(in_wage_offer) current_Firm_agent->wage_offer = atof(buffer);
				if(in_technology) current_Firm_agent->technology = atof(buffer);
				if(in_no_employees) current_Firm_agent->no_employees = atoi(buffer);
				if(in_no_employees_skill_1) current_Firm_agent->no_employees_skill_1 = atoi(buffer);
				if(in_no_employees_skill_2) current_Firm_agent->no_employees_skill_2 = atoi(buffer);
				if(in_no_employees_skill_3) current_Firm_agent->no_employees_skill_3 = atoi(buffer);
				if(in_no_employees_skill_4) current_Firm_agent->no_employees_skill_4 = atoi(buffer);
				if(in_no_employees_skill_5) current_Firm_agent->no_employees_skill_5 = atoi(buffer);
				if(in_vacancies) current_Firm_agent->vacancies = atoi(buffer);
				if(in_average_g_skill) current_Firm_agent->average_g_skill = atof(buffer);
				if(in_average_s_skill_of_1) current_Firm_agent->average_s_skill_of_1 = atof(buffer);
				if(in_average_s_skill_of_2) current_Firm_agent->average_s_skill_of_2 = atof(buffer);
				if(in_average_s_skill_of_3) current_Firm_agent->average_s_skill_of_3 = atof(buffer);
				if(in_average_s_skill_of_4) current_Firm_agent->average_s_skill_of_4 = atof(buffer);
				if(in_average_s_skill_of_5) current_Firm_agent->average_s_skill_of_5 = atof(buffer);
				if(in_wage_offer_for_skill_1) current_Firm_agent->wage_offer_for_skill_1 = atof(buffer);
				if(in_wage_offer_for_skill_2) current_Firm_agent->wage_offer_for_skill_2 = atof(buffer);
				if(in_wage_offer_for_skill_3) current_Firm_agent->wage_offer_for_skill_3 = atof(buffer);
				if(in_wage_offer_for_skill_4) current_Firm_agent->wage_offer_for_skill_4 = atof(buffer);
				if(in_wage_offer_for_skill_5) current_Firm_agent->wage_offer_for_skill_5 = atof(buffer);
				if(in_employees_needed) current_Firm_agent->employees_needed = atoi(buffer);
			}
			else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_region_id) current_Household_agent->region_id = atoi(buffer);
				if(in_neighboring_region_ids) read_int_dynamic_array(buffer, &j, &current_Household_agent->neighboring_region_ids);
				if(in_gov_id) current_Household_agent->gov_id = atoi(buffer);
				if(in_bank_id) current_Household_agent->bank_id = atoi(buffer);
				if(in_day_of_month_to_act) current_Household_agent->day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_Household_agent->payment_account = atof(buffer);
				if(in_consumption_budget) current_Household_agent->consumption_budget = atof(buffer);
				if(in_mean_income) current_Household_agent->mean_income = atof(buffer);
				if(in_week_of_month) current_Household_agent->week_of_month = atoi(buffer);
				if(in_weekly_budget) current_Household_agent->weekly_budget = atof(buffer);
				if(in_rationed) current_Household_agent->rationed = atoi(buffer);
				if(in_mall_completely_sold_out) current_Household_agent->mall_completely_sold_out = atoi(buffer);
				if(in_order_quantity) read_ordered_quantity_static_array(buffer, &j, current_Household_agent->order_quantity, 2);
				if(in_received_quantity) read_received_quantities_static_array(buffer, &j, current_Household_agent->received_quantity, 2);
				if(in_day_of_week_to_act) current_Household_agent->day_of_week_to_act = atoi(buffer);
				if(in_day_of_month_receive_income) current_Household_agent->day_of_month_receive_income = atoi(buffer);
				if(in_current_productivity_employer) current_Household_agent->current_productivity_employer = atof(buffer);
				if(in_current_mean_specific_skills_employer) current_Household_agent->current_mean_specific_skills_employer = atof(buffer);
				if(in_total_taxes) current_Household_agent->total_taxes = atof(buffer);
				if(in_cum_total_dividends) current_Household_agent->cum_total_dividends = atof(buffer);
				if(in_tax_rate_hh_capital) current_Household_agent->tax_rate_hh_capital = atof(buffer);
				if(in_tax_rate_hh_labour) current_Household_agent->tax_rate_hh_labour = atof(buffer);
				if(in_last_income) read_double_dynamic_array(buffer, &j, &current_Household_agent->last_income);
				if(in_expenditures) current_Household_agent->expenditures = atof(buffer);
				if(in_received_dividend) current_Household_agent->received_dividend = atof(buffer);
				if(in_household_portfolio) read_portfolio_dynamic_array(buffer, &j, &current_Household_agent->household_portfolio);
				if(in_wage) current_Household_agent->wage = atof(buffer);
				if(in_wage_reservation) current_Household_agent->wage_reservation = atof(buffer);
				if(in_general_skill) current_Household_agent->general_skill = atoi(buffer);
				if(in_on_the_job_search) current_Household_agent->on_the_job_search = atoi(buffer);
				if(in_number_applications) current_Household_agent->number_applications = atoi(buffer);
				if(in_specific_skill) current_Household_agent->specific_skill = atof(buffer);
				if(in_employee_firm_id) current_Household_agent->employee_firm_id = atoi(buffer);
				if(in_employer_region_id) current_Household_agent->employer_region_id = atoi(buffer);
			}
			else if(in_Mall_agent == 1)
			{
				if(in_id) current_Mall_agent->id = atoi(buffer);
				if(in_region_id) current_Mall_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Mall_agent->gov_id = atoi(buffer);
				if(in_current_stock) read_mall_stock_dynamic_array(buffer, &j, &current_Mall_agent->current_stock);
				if(in_firm_revenues) read_sales_in_mall_dynamic_array(buffer, &j, &current_Mall_agent->firm_revenues);
				if(in_total_supply) current_Mall_agent->total_supply = atof(buffer);
			}
			else if(in_IGFirm_agent == 1)
			{
				if(in_id) current_IGFirm_agent->id = atoi(buffer);
				if(in_region_id) current_IGFirm_agent->region_id = atoi(buffer);
				if(in_gov_id) current_IGFirm_agent->gov_id = atoi(buffer);
				if(in_bank_id) current_IGFirm_agent->bank_id = atoi(buffer);
				if(in_day_of_month_to_act) current_IGFirm_agent->day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_IGFirm_agent->payment_account = atof(buffer);
				if(in_productivity) current_IGFirm_agent->productivity = atof(buffer);
				if(in_innovation_probability) current_IGFirm_agent->innovation_probability = atoi(buffer);
				if(in_productivity_progress) current_IGFirm_agent->productivity_progress = atof(buffer);
				if(in_capital_good_price) current_IGFirm_agent->capital_good_price = atof(buffer);
				if(in_revenue_per_day) current_IGFirm_agent->revenue_per_day = atof(buffer);
				if(in_tax_rate_corporate) current_IGFirm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_vat) current_IGFirm_agent->tax_rate_vat = atof(buffer);
				if(in_tax_payment) current_IGFirm_agent->tax_payment = atof(buffer);
				if(in_net_profit) current_IGFirm_agent->net_profit = atof(buffer);
				if(in_outstanding_shares) current_IGFirm_agent->outstanding_shares = atoi(buffer);
				if(in_current_dividend_per_share) current_IGFirm_agent->current_dividend_per_share = atof(buffer);
				if(in_cum_revenues) current_IGFirm_agent->cum_revenues = atof(buffer);
			}
			else if(in_Eurostat_agent == 1)
			{
				if(in_id) current_Eurostat_agent->id = atoi(buffer);
				if(in_region_id) current_Eurostat_agent->region_id = atoi(buffer);
				if(in_no_regions) current_Eurostat_agent->no_regions = atoi(buffer);
				if(in_num_households) current_Eurostat_agent->num_households = atoi(buffer);
				if(in_no_households_skill_1) current_Eurostat_agent->no_households_skill_1 = atoi(buffer);
				if(in_no_households_skill_2) current_Eurostat_agent->no_households_skill_2 = atoi(buffer);
				if(in_no_households_skill_3) current_Eurostat_agent->no_households_skill_3 = atoi(buffer);
				if(in_no_households_skill_4) current_Eurostat_agent->no_households_skill_4 = atoi(buffer);
				if(in_no_households_skill_5) current_Eurostat_agent->no_households_skill_5 = atoi(buffer);
				if(in_employed) current_Eurostat_agent->employed = atoi(buffer);
				if(in_employed_skill_1) current_Eurostat_agent->employed_skill_1 = atoi(buffer);
				if(in_employed_skill_2) current_Eurostat_agent->employed_skill_2 = atoi(buffer);
				if(in_employed_skill_3) current_Eurostat_agent->employed_skill_3 = atoi(buffer);
				if(in_employed_skill_4) current_Eurostat_agent->employed_skill_4 = atoi(buffer);
				if(in_employed_skill_5) current_Eurostat_agent->employed_skill_5 = atoi(buffer);
				if(in_unemployed) current_Eurostat_agent->unemployed = atoi(buffer);
				if(in_unemployment_rate) current_Eurostat_agent->unemployment_rate = atof(buffer);
				if(in_unemployment_rate_skill_1) current_Eurostat_agent->unemployment_rate_skill_1 = atof(buffer);
				if(in_unemployment_rate_skill_2) current_Eurostat_agent->unemployment_rate_skill_2 = atof(buffer);
				if(in_unemployment_rate_skill_3) current_Eurostat_agent->unemployment_rate_skill_3 = atof(buffer);
				if(in_unemployment_rate_skill_4) current_Eurostat_agent->unemployment_rate_skill_4 = atof(buffer);
				if(in_unemployment_rate_skill_5) current_Eurostat_agent->unemployment_rate_skill_5 = atof(buffer);
				if(in_average_wage) current_Eurostat_agent->average_wage = atof(buffer);
				if(in_average_wage_skill_1) current_Eurostat_agent->average_wage_skill_1 = atof(buffer);
				if(in_average_wage_skill_2) current_Eurostat_agent->average_wage_skill_2 = atof(buffer);
				if(in_average_wage_skill_3) current_Eurostat_agent->average_wage_skill_3 = atof(buffer);
				if(in_average_wage_skill_4) current_Eurostat_agent->average_wage_skill_4 = atof(buffer);
				if(in_average_wage_skill_5) current_Eurostat_agent->average_wage_skill_5 = atof(buffer);
				if(in_average_s_skill) current_Eurostat_agent->average_s_skill = atof(buffer);
				if(in_average_s_skill_1) current_Eurostat_agent->average_s_skill_1 = atof(buffer);
				if(in_average_s_skill_2) current_Eurostat_agent->average_s_skill_2 = atof(buffer);
				if(in_average_s_skill_3) current_Eurostat_agent->average_s_skill_3 = atof(buffer);
				if(in_average_s_skill_4) current_Eurostat_agent->average_s_skill_4 = atof(buffer);
				if(in_average_s_skill_5) current_Eurostat_agent->average_s_skill_5 = atof(buffer);
				if(in_no_firms) current_Eurostat_agent->no_firms = atoi(buffer);
				if(in_no_vacancies) current_Eurostat_agent->no_vacancies = atoi(buffer);
				if(in_no_employees) current_Eurostat_agent->no_employees = atoi(buffer);
				if(in_no_employees_skill_1) current_Eurostat_agent->no_employees_skill_1 = atoi(buffer);
				if(in_no_employees_skill_2) current_Eurostat_agent->no_employees_skill_2 = atoi(buffer);
				if(in_no_employees_skill_3) current_Eurostat_agent->no_employees_skill_3 = atoi(buffer);
				if(in_no_employees_skill_4) current_Eurostat_agent->no_employees_skill_4 = atoi(buffer);
				if(in_no_employees_skill_5) current_Eurostat_agent->no_employees_skill_5 = atoi(buffer);
				if(in_firm_average_wage) current_Eurostat_agent->firm_average_wage = atof(buffer);
				if(in_firm_average_wage_skill_1) current_Eurostat_agent->firm_average_wage_skill_1 = atof(buffer);
				if(in_firm_average_wage_skill_2) current_Eurostat_agent->firm_average_wage_skill_2 = atof(buffer);
				if(in_firm_average_wage_skill_3) current_Eurostat_agent->firm_average_wage_skill_3 = atof(buffer);
				if(in_firm_average_wage_skill_4) current_Eurostat_agent->firm_average_wage_skill_4 = atof(buffer);
				if(in_firm_average_wage_skill_5) current_Eurostat_agent->firm_average_wage_skill_5 = atof(buffer);
				if(in_firm_average_s_skill) current_Eurostat_agent->firm_average_s_skill = atof(buffer);
				if(in_firm_average_s_skill_1) current_Eurostat_agent->firm_average_s_skill_1 = atof(buffer);
				if(in_firm_average_s_skill_2) current_Eurostat_agent->firm_average_s_skill_2 = atof(buffer);
				if(in_firm_average_s_skill_3) current_Eurostat_agent->firm_average_s_skill_3 = atof(buffer);
				if(in_firm_average_s_skill_4) current_Eurostat_agent->firm_average_s_skill_4 = atof(buffer);
				if(in_firm_average_s_skill_5) current_Eurostat_agent->firm_average_s_skill_5 = atof(buffer);
				if(in_region_firm_data) read_firm_data_dynamic_array(buffer, &j, &current_Eurostat_agent->region_firm_data);
				if(in_region_household_data) read_household_data_dynamic_array(buffer, &j, &current_Eurostat_agent->region_household_data);
				if(in_day_of_month_to_act) current_Eurostat_agent->day_of_month_to_act = atoi(buffer);
				if(in_government_tax_rates) read_tax_rates_item_dynamic_array(buffer, &j, &current_Eurostat_agent->government_tax_rates);
				if(in_gdp) current_Eurostat_agent->gdp = atof(buffer);
				if(in_total_earnings) current_Eurostat_agent->total_earnings = atof(buffer);
				if(in_total_debt) current_Eurostat_agent->total_debt = atof(buffer);
				if(in_total_assets) current_Eurostat_agent->total_assets = atof(buffer);
				if(in_total_equity) current_Eurostat_agent->total_equity = atof(buffer);
				if(in_average_debt_earnings_ratio) current_Eurostat_agent->average_debt_earnings_ratio = atof(buffer);
				if(in_average_debt_equity_ratio) current_Eurostat_agent->average_debt_equity_ratio = atof(buffer);
				if(in_labour_share_ratio) current_Eurostat_agent->labour_share_ratio = atof(buffer);
			}
			else if(in_Bank_agent == 1)
			{
				if(in_id) current_Bank_agent->id = atoi(buffer);
				if(in_region_id) current_Bank_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Bank_agent->gov_id = atoi(buffer);
				if(in_accounts) read_account_dynamic_array(buffer, &j, &current_Bank_agent->accounts);
				if(in_loans_outstanding) read_outstanding_loans_dynamic_array(buffer, &j, &current_Bank_agent->loans_outstanding);
				if(in_last_credit_id) current_Bank_agent->last_credit_id = atoi(buffer);
				if(in_amount_credit_offer) current_Bank_agent->amount_credit_offer = atof(buffer);
				if(in_total_deposits) current_Bank_agent->total_deposits = atof(buffer);
				if(in_total_loan_supply) current_Bank_agent->total_loan_supply = atof(buffer);
				if(in_total_loan_demand) current_Bank_agent->total_loan_demand = atof(buffer);
				if(in_payment_account) current_Bank_agent->payment_account = atof(buffer);
			}
			else if(in_Government_agent == 1)
			{
				if(in_id) current_Government_agent->id = atoi(buffer);
				if(in_bank_id) current_Government_agent->bank_id = atoi(buffer);
				if(in_payment_account) current_Government_agent->payment_account = atof(buffer);
				if(in_tax_revenues) current_Government_agent->tax_revenues = atof(buffer);
				if(in_unemployment_benefit_payment) current_Government_agent->unemployment_benefit_payment = atof(buffer);
				if(in_total_unemployment_benefit_payment) current_Government_agent->total_unemployment_benefit_payment = atof(buffer);
				if(in_total_interest_payment) current_Government_agent->total_interest_payment = atof(buffer);
				if(in_total_debt) current_Government_agent->total_debt = atof(buffer);
				if(in_tax_rate_corporate) current_Government_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_hh_labour) current_Government_agent->tax_rate_hh_labour = atof(buffer);
				if(in_tax_rate_hh_capital) current_Government_agent->tax_rate_hh_capital = atof(buffer);
				if(in_tax_rate_vat) current_Government_agent->tax_rate_vat = atof(buffer);
				if(in_num_unemployed) current_Government_agent->num_unemployed = atoi(buffer);
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
//////////////////////////////////////	free_sales_statistics_array(malls_sales_statistics);
////////////////	free_sold_quantities_per_mall_array(sold_quantities);
//////	free_delivery_volume_per_mall_array(delivery_volume);
//	free_delivery_volume_per_mall_array(planned_delivery_volume);
//	free_mall_info_array(current_mall_stocks);
//	free_double_array(last_planned_production_quantities);
////////////	free_financing_capital_array(capital_financing);
//////////////////////////////////////////	free_debt_item_array(loans);
////////////////////////////////	free_employee_array(employees);
////////////////////////////////////////////	free_int_array(neighboring_region_ids);
//////////////	free_ordered_quantity_static_array(order_quantity, 2);
//	free_received_quantities_static_array(received_quantity, 2);
//////////////////	free_double_array(last_income);
//////	free_portfolio_array(household_portfolio);
//////////////////	free_mall_stock_array(current_stock);
//	free_sales_in_mall_array(firm_revenues);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////	free_firm_data_array(region_firm_data);
//	free_household_data_array(region_household_data);
//	free_tax_rates_item_array(government_tax_rates);
//////////////	free_account_array(accounts);
//	free_outstanding_loans_array(loans_outstanding);
//////////////////
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

/** \fn void write_portfolio(FILE *file, portfolio * temp_datatype)
 * \brief Writes portfolio datatype.
 */
void write_portfolio(FILE *file, portfolio * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).shares);
	fputs(data, file);
	fputs("}", file);
}

void write_portfolio_static_array(FILE *file, portfolio * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_portfolio(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_portfolio_dynamic_array(FILE *file, portfolio_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_portfolio(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_consumption_goods_offer(FILE *file, consumption_goods_offer * temp_datatype)
 * \brief Writes consumption_goods_offer datatype.
 */
void write_consumption_goods_offer(FILE *file, consumption_goods_offer * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quality);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs("}", file);
}

void write_consumption_goods_offer_static_array(FILE *file, consumption_goods_offer * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_consumption_goods_offer(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_consumption_goods_offer_dynamic_array(FILE *file, consumption_goods_offer_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_consumption_goods_offer(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_consumption_request(FILE *file, consumption_request * temp_datatype)
 * \brief Writes consumption_request datatype.
 */
void write_consumption_request(FILE *file, consumption_request * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).worker_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quantity);
	fputs(data, file);
	fputs("}", file);
}

void write_consumption_request_static_array(FILE *file, consumption_request * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_consumption_request(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_consumption_request_dynamic_array(FILE *file, consumption_request_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_consumption_request(file, &(*temp_datatype).array[i]);
		
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

/** \fn void write_mall_quality_price_info(FILE *file, mall_quality_price_info * temp_datatype)
 * \brief Writes mall_quality_price_info datatype.
 */
void write_mall_quality_price_info(FILE *file, mall_quality_price_info * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).mall_region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quality);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).available);
	fputs(data, file);
	fputs("}", file);
}

void write_mall_quality_price_info_static_array(FILE *file, mall_quality_price_info * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_mall_quality_price_info(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_mall_quality_price_info_dynamic_array(FILE *file, mall_quality_price_info_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_mall_quality_price_info(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_mall_stock(FILE *file, mall_stock * temp_datatype)
 * \brief Writes mall_stock datatype.
 */
void write_mall_stock(FILE *file, mall_stock * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).stock);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quality);
	fputs(data, file);
	fputs("}", file);
}

void write_mall_stock_static_array(FILE *file, mall_stock * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_mall_stock(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_mall_stock_dynamic_array(FILE *file, mall_stock_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_mall_stock(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_delivery_volume_per_mall(FILE *file, delivery_volume_per_mall * temp_datatype)
 * \brief Writes delivery_volume_per_mall datatype.
 */
void write_delivery_volume_per_mall(FILE *file, delivery_volume_per_mall * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quality);
	fputs(data, file);
	fputs("}", file);
}

void write_delivery_volume_per_mall_static_array(FILE *file, delivery_volume_per_mall * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_delivery_volume_per_mall(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_delivery_volume_per_mall_dynamic_array(FILE *file, delivery_volume_per_mall_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_delivery_volume_per_mall(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_logit_firm_id(FILE *file, logit_firm_id * temp_datatype)
 * \brief Writes logit_firm_id datatype.
 */
void write_logit_firm_id(FILE *file, logit_firm_id * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).logit);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs("}", file);
}

void write_logit_firm_id_static_array(FILE *file, logit_firm_id * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_logit_firm_id(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_logit_firm_id_dynamic_array(FILE *file, logit_firm_id_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_logit_firm_id(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_sales_in_mall(FILE *file, sales_in_mall * temp_datatype)
 * \brief Writes sales_in_mall datatype.
 */
void write_sales_in_mall(FILE *file, sales_in_mall * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).sales);
	fputs(data, file);
	fputs("}", file);
}

void write_sales_in_mall_static_array(FILE *file, sales_in_mall * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_sales_in_mall(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_sales_in_mall_dynamic_array(FILE *file, sales_in_mall_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_sales_in_mall(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ordered_quantity(FILE *file, ordered_quantity * temp_datatype)
 * \brief Writes ordered_quantity datatype.
 */
void write_ordered_quantity(FILE *file, ordered_quantity * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs("}", file);
}

void write_ordered_quantity_static_array(FILE *file, ordered_quantity * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ordered_quantity(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ordered_quantity_dynamic_array(FILE *file, ordered_quantity_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ordered_quantity(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_received_quantities(FILE *file, received_quantities * temp_datatype)
 * \brief Writes received_quantities datatype.
 */
void write_received_quantities(FILE *file, received_quantities * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quantity);
	fputs(data, file);
	fputs("}", file);
}

void write_received_quantities_static_array(FILE *file, received_quantities * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_received_quantities(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_received_quantities_dynamic_array(FILE *file, received_quantities_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_received_quantities(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_sold_quantities_per_mall(FILE *file, sold_quantities_per_mall * temp_datatype)
 * \brief Writes sold_quantities_per_mall datatype.
 */
void write_sold_quantities_per_mall(FILE *file, sold_quantities_per_mall * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).sold_quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).stock_empty);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).estimated_demand);
	fputs(data, file);
	fputs("}", file);
}

void write_sold_quantities_per_mall_static_array(FILE *file, sold_quantities_per_mall * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_sold_quantities_per_mall(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_sold_quantities_per_mall_dynamic_array(FILE *file, sold_quantities_per_mall_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_sold_quantities_per_mall(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_sales_statistics(FILE *file, sales_statistics * temp_datatype)
 * \brief Writes sales_statistics datatype.
 */
void write_sales_statistics(FILE *file, sales_statistics * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).mall_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).period);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).sales);
	fputs(data, file);
	fputs("}", file);
}

void write_sales_statistics_static_array(FILE *file, sales_statistics * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_sales_statistics(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_sales_statistics_dynamic_array(FILE *file, sales_statistics_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_sales_statistics(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_financing_capital(FILE *file, financing_capital * temp_datatype)
 * \brief Writes financing_capital datatype.
 */
void write_financing_capital(FILE *file, financing_capital * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).financing_per_month);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_periods_before_repayment);
	fputs(data, file);
	fputs("}", file);
}

void write_financing_capital_static_array(FILE *file, financing_capital * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_financing_capital(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_financing_capital_dynamic_array(FILE *file, financing_capital_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_financing_capital(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_account(FILE *file, account * temp_datatype)
 * \brief Writes account datatype.
 */
void write_account(FILE *file, account * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).balance);
	fputs(data, file);
	fputs("}", file);
}

void write_account_static_array(FILE *file, account * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_account(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_account_dynamic_array(FILE *file, account_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_account(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_credit_request(FILE *file, credit_request * temp_datatype)
 * \brief Writes credit_request datatype.
 */
void write_credit_request(FILE *file, credit_request * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).credit_amount);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).prob_of_failure);
	fputs(data, file);
	fputs("}", file);
}

void write_credit_request_static_array(FILE *file, credit_request * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_credit_request(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_credit_request_dynamic_array(FILE *file, credit_request_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_credit_request(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_outstanding_loans(FILE *file, outstanding_loans * temp_datatype)
 * \brief Writes outstanding_loans datatype.
 */
void write_outstanding_loans(FILE *file, outstanding_loans * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_amount);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).interest_rate);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).credit_id);
	fputs(data, file);
	fputs("}", file);
}

void write_outstanding_loans_static_array(FILE *file, outstanding_loans * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_outstanding_loans(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_outstanding_loans_dynamic_array(FILE *file, outstanding_loans_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_outstanding_loans(file, &(*temp_datatype).array[i]);
		
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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).credit_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).loan_value);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).interest_rate);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).installment_amount);
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

/** \fn void write_employee(FILE *file, employee * temp_datatype)
 * \brief Writes employee datatype.
 */
void write_employee(FILE *file, employee * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).wage);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).general_skill);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).specific_skill);
	fputs(data, file);
	fputs("}", file);
}

void write_employee_static_array(FILE *file, employee * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_employee(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_employee_dynamic_array(FILE *file, employee_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_employee(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_vacancy(FILE *file, vacancy * temp_datatype)
 * \brief Writes vacancy datatype.
 */
void write_vacancy(FILE *file, vacancy * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).wage_offer);
	fputs(data, file);
	fputs("}", file);
}

void write_vacancy_static_array(FILE *file, vacancy * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_vacancy(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_vacancy_dynamic_array(FILE *file, vacancy_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_vacancy(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_job_application(FILE *file, job_application * temp_datatype)
 * \brief Writes job_application datatype.
 */
void write_job_application(FILE *file, job_application * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).worker_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).general_skill);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).specific_skill);
	fputs(data, file);
	fputs("}", file);
}

void write_job_application_static_array(FILE *file, job_application * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_job_application(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_job_application_dynamic_array(FILE *file, job_application_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_job_application(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_job_offer(FILE *file, job_offer * temp_datatype)
 * \brief Writes job_offer datatype.
 */
void write_job_offer(FILE *file, job_offer * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).firm_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).wage_offer);
	fputs(data, file);
	fputs("}", file);
}

void write_job_offer_static_array(FILE *file, job_offer * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_job_offer(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_job_offer_dynamic_array(FILE *file, job_offer_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_job_offer(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_household_data(FILE *file, household_data * temp_datatype)
 * \brief Writes household_data datatype.
 */
void write_household_data(FILE *file, household_data * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_households_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employed_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).unemployed);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).unemployment_rate_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_5);
	fputs(data, file);
	fputs("}", file);
}

void write_household_data_static_array(FILE *file, household_data * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_household_data(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_household_data_dynamic_array(FILE *file, household_data_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_household_data(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_firm_data(FILE *file, firm_data * temp_datatype)
 * \brief Writes firm_data datatype.
 */
void write_firm_data(FILE *file, firm_data * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).firms);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).vacancies);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employees_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_wage_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_1);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_2);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_3);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_4);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_s_skill_5);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gdp);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_earnings);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_equity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_debt_earnings_ratio);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).average_debt_equity_ratio);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).labour_share_ratio);
	fputs(data, file);
	fputs("}", file);
}

void write_firm_data_static_array(FILE *file, firm_data * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_firm_data(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_firm_data_dynamic_array(FILE *file, firm_data_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_firm_data(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_tax_rates_item(FILE *file, tax_rates_item * temp_datatype)
 * \brief Writes tax_rates_item datatype.
 */
void write_tax_rates_item(FILE *file, tax_rates_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).gov_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_rate_corporate);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_rate_hh_labour);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_rate_hh_capital);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_rate_vat);
	fputs(data, file);
	fputs("}", file);
}

void write_tax_rates_item_static_array(FILE *file, tax_rates_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_tax_rates_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_tax_rates_item_dynamic_array(FILE *file, tax_rates_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_tax_rates_item(file, &(*temp_datatype).array[i]);
		
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
		fputs("<mean_wage>", file);
	sprintf(data, "%f", current->mean_wage);
	fputs(data, file);
	fputs("</mean_wage>\n", file);
		fputs("<total_units_capital_stock>", file);
	sprintf(data, "%f", current->total_units_capital_stock);
	fputs(data, file);
	fputs("</total_units_capital_stock>\n", file);
		fputs("<needed_capital_stock>", file);
	sprintf(data, "%f", current->needed_capital_stock);
	fputs(data, file);
	fputs("</needed_capital_stock>\n", file);
		fputs("<actual_cap_price>", file);
	sprintf(data, "%f", current->actual_cap_price);
	fputs(data, file);
	fputs("</actual_cap_price>\n", file);
		fputs("<mean_specific_skills>", file);
	sprintf(data, "%f", current->mean_specific_skills);
	fputs(data, file);
	fputs("</mean_specific_skills>\n", file);
		fputs("<planned_production_quantity>", file);
	sprintf(data, "%f", current->planned_production_quantity);
	fputs(data, file);
	fputs("</planned_production_quantity>\n", file);
		fputs("<production_quantity>", file);
	sprintf(data, "%f", current->production_quantity);
	fputs(data, file);
	fputs("</production_quantity>\n", file);
		fputs("<unit_costs>", file);
	sprintf(data, "%f", current->unit_costs);
	fputs(data, file);
	fputs("</unit_costs>\n", file);
		fputs("<production_costs>", file);
	sprintf(data, "%f", current->production_costs);
	fputs(data, file);
	fputs("</production_costs>\n", file);
		fputs("<revenue_per_day>", file);
	sprintf(data, "%f", current->revenue_per_day);
	fputs(data, file);
	fputs("</revenue_per_day>\n", file);
		fputs("<technological_frontier>", file);
	sprintf(data, "%f", current->technological_frontier);
	fputs(data, file);
	fputs("</technological_frontier>\n", file);
		fputs("<cum_revenue>", file);
	sprintf(data, "%f", current->cum_revenue);
	fputs(data, file);
	fputs("</cum_revenue>\n", file);
		fputs("<out_of_stock_costs>", file);
	sprintf(data, "%f", current->out_of_stock_costs);
	fputs(data, file);
	fputs("</out_of_stock_costs>\n", file);
		fputs("<malls_sales_statistics>", file);
	write_sales_statistics_dynamic_array(file, &current->malls_sales_statistics);
	fputs("</malls_sales_statistics>\n", file);
		fputs("<quality>", file);
	sprintf(data, "%f", current->quality);
	fputs(data, file);
	fputs("</quality>\n", file);
		fputs("<price>", file);
	sprintf(data, "%f", current->price);
	fputs(data, file);
	fputs("</price>\n", file);
		fputs("<price_last_month>", file);
	sprintf(data, "%f", current->price_last_month);
	fputs(data, file);
	fputs("</price_last_month>\n", file);
		fputs("<demand_capital_stock>", file);
	sprintf(data, "%f", current->demand_capital_stock);
	fputs(data, file);
	fputs("</demand_capital_stock>\n", file);
		fputs("<planned_production_costs>", file);
	sprintf(data, "%f", current->planned_production_costs);
	fputs(data, file);
	fputs("</planned_production_costs>\n", file);
		fputs("<adaption_production_volume_due_to_insufficient_finances>", file);
	sprintf(data, "%f", current->adaption_production_volume_due_to_insufficient_finances);
	fputs(data, file);
	fputs("</adaption_production_volume_due_to_insufficient_finances>\n", file);
		fputs("<fraction_reserved_for_delayed_payments>", file);
	sprintf(data, "%f", current->fraction_reserved_for_delayed_payments);
	fputs(data, file);
	fputs("</fraction_reserved_for_delayed_payments>\n", file);
		fputs("<sold_quantities>", file);
	write_sold_quantities_per_mall_dynamic_array(file, &current->sold_quantities);
	fputs("</sold_quantities>\n", file);
		fputs("<total_sold_quantity>", file);
	sprintf(data, "%f", current->total_sold_quantity);
	fputs(data, file);
	fputs("</total_sold_quantity>\n", file);
		fputs("<cum_total_sold_quantity>", file);
	sprintf(data, "%f", current->cum_total_sold_quantity);
	fputs(data, file);
	fputs("</cum_total_sold_quantity>\n", file);
		fputs("<delivery_volume>", file);
	write_delivery_volume_per_mall_dynamic_array(file, &current->delivery_volume);
	fputs("</delivery_volume>\n", file);
		fputs("<planned_delivery_volume>", file);
	write_delivery_volume_per_mall_dynamic_array(file, &current->planned_delivery_volume);
	fputs("</planned_delivery_volume>\n", file);
		fputs("<current_mall_stocks>", file);
	write_mall_info_dynamic_array(file, &current->current_mall_stocks);
	fputs("</current_mall_stocks>\n", file);
		fputs("<last_planned_production_quantities>", file);
	write_double_dynamic_array(file, &current->last_planned_production_quantities);
	fputs("</last_planned_production_quantities>\n", file);
		fputs("<direct_financial_needs_require_external_financing>", file);
	sprintf(data, "%f", current->direct_financial_needs_require_external_financing);
	fputs(data, file);
	fputs("</direct_financial_needs_require_external_financing>\n", file);
		fputs("<total_external_financing_obtained>", file);
	sprintf(data, "%f", current->total_external_financing_obtained);
	fputs(data, file);
	fputs("</total_external_financing_obtained>\n", file);
		fputs("<delayed_financial_needs_require_external_financing>", file);
	sprintf(data, "%f", current->delayed_financial_needs_require_external_financing);
	fputs(data, file);
	fputs("</delayed_financial_needs_require_external_financing>\n", file);
		fputs("<capital_costs>", file);
	sprintf(data, "%f", current->capital_costs);
	fputs(data, file);
	fputs("</capital_costs>\n", file);
		fputs("<labour_costs>", file);
	sprintf(data, "%f", current->labour_costs);
	fputs(data, file);
	fputs("</labour_costs>\n", file);
		fputs("<capital_financing>", file);
	write_financing_capital_dynamic_array(file, &current->capital_financing);
	fputs("</capital_financing>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
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
		fputs("<current_shares_outstanding>", file);
	sprintf(data, "%i", current->current_shares_outstanding);
	fputs(data, file);
	fputs("</current_shares_outstanding>\n", file);
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
		fputs("<financial_resources_for_production>", file);
	sprintf(data, "%f", current->financial_resources_for_production);
	fputs(data, file);
	fputs("</financial_resources_for_production>\n", file);
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
		fputs("<total_units_local_inventory>", file);
	sprintf(data, "%f", current->total_units_local_inventory);
	fputs(data, file);
	fputs("</total_units_local_inventory>\n", file);
		fputs("<total_value_capital_stock>", file);
	sprintf(data, "%f", current->total_value_capital_stock);
	fputs(data, file);
	fputs("</total_value_capital_stock>\n", file);
		fputs("<planned_value_capital_stock>", file);
	sprintf(data, "%f", current->planned_value_capital_stock);
	fputs(data, file);
	fputs("</planned_value_capital_stock>\n", file);
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
		fputs("<planned_total_assets>", file);
	sprintf(data, "%f", current->planned_total_assets);
	fputs(data, file);
	fputs("</planned_total_assets>\n", file);
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
		fputs("<total_payments>", file);
	sprintf(data, "%f", current->total_payments);
	fputs(data, file);
	fputs("</total_payments>\n", file);
		fputs("<employees>", file);
	write_employee_dynamic_array(file, &current->employees);
	fputs("</employees>\n", file);
		fputs("<wage_offer>", file);
	sprintf(data, "%f", current->wage_offer);
	fputs(data, file);
	fputs("</wage_offer>\n", file);
		fputs("<technology>", file);
	sprintf(data, "%f", current->technology);
	fputs(data, file);
	fputs("</technology>\n", file);
		fputs("<no_employees>", file);
	sprintf(data, "%i", current->no_employees);
	fputs(data, file);
	fputs("</no_employees>\n", file);
		fputs("<no_employees_skill_1>", file);
	sprintf(data, "%i", current->no_employees_skill_1);
	fputs(data, file);
	fputs("</no_employees_skill_1>\n", file);
		fputs("<no_employees_skill_2>", file);
	sprintf(data, "%i", current->no_employees_skill_2);
	fputs(data, file);
	fputs("</no_employees_skill_2>\n", file);
		fputs("<no_employees_skill_3>", file);
	sprintf(data, "%i", current->no_employees_skill_3);
	fputs(data, file);
	fputs("</no_employees_skill_3>\n", file);
		fputs("<no_employees_skill_4>", file);
	sprintf(data, "%i", current->no_employees_skill_4);
	fputs(data, file);
	fputs("</no_employees_skill_4>\n", file);
		fputs("<no_employees_skill_5>", file);
	sprintf(data, "%i", current->no_employees_skill_5);
	fputs(data, file);
	fputs("</no_employees_skill_5>\n", file);
		fputs("<vacancies>", file);
	sprintf(data, "%i", current->vacancies);
	fputs(data, file);
	fputs("</vacancies>\n", file);
		fputs("<average_g_skill>", file);
	sprintf(data, "%f", current->average_g_skill);
	fputs(data, file);
	fputs("</average_g_skill>\n", file);
		fputs("<average_s_skill_of_1>", file);
	sprintf(data, "%f", current->average_s_skill_of_1);
	fputs(data, file);
	fputs("</average_s_skill_of_1>\n", file);
		fputs("<average_s_skill_of_2>", file);
	sprintf(data, "%f", current->average_s_skill_of_2);
	fputs(data, file);
	fputs("</average_s_skill_of_2>\n", file);
		fputs("<average_s_skill_of_3>", file);
	sprintf(data, "%f", current->average_s_skill_of_3);
	fputs(data, file);
	fputs("</average_s_skill_of_3>\n", file);
		fputs("<average_s_skill_of_4>", file);
	sprintf(data, "%f", current->average_s_skill_of_4);
	fputs(data, file);
	fputs("</average_s_skill_of_4>\n", file);
		fputs("<average_s_skill_of_5>", file);
	sprintf(data, "%f", current->average_s_skill_of_5);
	fputs(data, file);
	fputs("</average_s_skill_of_5>\n", file);
		fputs("<wage_offer_for_skill_1>", file);
	sprintf(data, "%f", current->wage_offer_for_skill_1);
	fputs(data, file);
	fputs("</wage_offer_for_skill_1>\n", file);
		fputs("<wage_offer_for_skill_2>", file);
	sprintf(data, "%f", current->wage_offer_for_skill_2);
	fputs(data, file);
	fputs("</wage_offer_for_skill_2>\n", file);
		fputs("<wage_offer_for_skill_3>", file);
	sprintf(data, "%f", current->wage_offer_for_skill_3);
	fputs(data, file);
	fputs("</wage_offer_for_skill_3>\n", file);
		fputs("<wage_offer_for_skill_4>", file);
	sprintf(data, "%f", current->wage_offer_for_skill_4);
	fputs(data, file);
	fputs("</wage_offer_for_skill_4>\n", file);
		fputs("<wage_offer_for_skill_5>", file);
	sprintf(data, "%f", current->wage_offer_for_skill_5);
	fputs(data, file);
	fputs("</wage_offer_for_skill_5>\n", file);
		fputs("<employees_needed>", file);
	sprintf(data, "%i", current->employees_needed);
	fputs(data, file);
	fputs("</employees_needed>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Household_agent(FILE *file, xmachine_memory_Household * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Household</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
		fputs("<neighboring_region_ids>", file);
	write_int_dynamic_array(file, &current->neighboring_region_ids);
	fputs("</neighboring_region_ids>\n", file);
		fputs("<gov_id>", file);
	sprintf(data, "%i", current->gov_id);
	fputs(data, file);
	fputs("</gov_id>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<consumption_budget>", file);
	sprintf(data, "%f", current->consumption_budget);
	fputs(data, file);
	fputs("</consumption_budget>\n", file);
		fputs("<mean_income>", file);
	sprintf(data, "%f", current->mean_income);
	fputs(data, file);
	fputs("</mean_income>\n", file);
		fputs("<week_of_month>", file);
	sprintf(data, "%i", current->week_of_month);
	fputs(data, file);
	fputs("</week_of_month>\n", file);
		fputs("<weekly_budget>", file);
	sprintf(data, "%f", current->weekly_budget);
	fputs(data, file);
	fputs("</weekly_budget>\n", file);
		fputs("<rationed>", file);
	sprintf(data, "%i", current->rationed);
	fputs(data, file);
	fputs("</rationed>\n", file);
		fputs("<mall_completely_sold_out>", file);
	sprintf(data, "%i", current->mall_completely_sold_out);
	fputs(data, file);
	fputs("</mall_completely_sold_out>\n", file);
		fputs("<order_quantity>", file);
	write_ordered_quantity_static_array(file, current->order_quantity, 2);
	fputs("</order_quantity>\n", file);
		fputs("<received_quantity>", file);
	write_received_quantities_static_array(file, current->received_quantity, 2);
	fputs("</received_quantity>\n", file);
		fputs("<day_of_week_to_act>", file);
	sprintf(data, "%i", current->day_of_week_to_act);
	fputs(data, file);
	fputs("</day_of_week_to_act>\n", file);
		fputs("<day_of_month_receive_income>", file);
	sprintf(data, "%i", current->day_of_month_receive_income);
	fputs(data, file);
	fputs("</day_of_month_receive_income>\n", file);
		fputs("<current_productivity_employer>", file);
	sprintf(data, "%f", current->current_productivity_employer);
	fputs(data, file);
	fputs("</current_productivity_employer>\n", file);
		fputs("<current_mean_specific_skills_employer>", file);
	sprintf(data, "%f", current->current_mean_specific_skills_employer);
	fputs(data, file);
	fputs("</current_mean_specific_skills_employer>\n", file);
		fputs("<total_taxes>", file);
	sprintf(data, "%f", current->total_taxes);
	fputs(data, file);
	fputs("</total_taxes>\n", file);
		fputs("<cum_total_dividends>", file);
	sprintf(data, "%f", current->cum_total_dividends);
	fputs(data, file);
	fputs("</cum_total_dividends>\n", file);
		fputs("<tax_rate_hh_capital>", file);
	sprintf(data, "%f", current->tax_rate_hh_capital);
	fputs(data, file);
	fputs("</tax_rate_hh_capital>\n", file);
		fputs("<tax_rate_hh_labour>", file);
	sprintf(data, "%f", current->tax_rate_hh_labour);
	fputs(data, file);
	fputs("</tax_rate_hh_labour>\n", file);
		fputs("<last_income>", file);
	write_double_dynamic_array(file, &current->last_income);
	fputs("</last_income>\n", file);
		fputs("<expenditures>", file);
	sprintf(data, "%f", current->expenditures);
	fputs(data, file);
	fputs("</expenditures>\n", file);
		fputs("<received_dividend>", file);
	sprintf(data, "%f", current->received_dividend);
	fputs(data, file);
	fputs("</received_dividend>\n", file);
		fputs("<household_portfolio>", file);
	write_portfolio_dynamic_array(file, &current->household_portfolio);
	fputs("</household_portfolio>\n", file);
		fputs("<wage>", file);
	sprintf(data, "%f", current->wage);
	fputs(data, file);
	fputs("</wage>\n", file);
		fputs("<wage_reservation>", file);
	sprintf(data, "%f", current->wage_reservation);
	fputs(data, file);
	fputs("</wage_reservation>\n", file);
		fputs("<general_skill>", file);
	sprintf(data, "%i", current->general_skill);
	fputs(data, file);
	fputs("</general_skill>\n", file);
		fputs("<on_the_job_search>", file);
	sprintf(data, "%i", current->on_the_job_search);
	fputs(data, file);
	fputs("</on_the_job_search>\n", file);
		fputs("<number_applications>", file);
	sprintf(data, "%i", current->number_applications);
	fputs(data, file);
	fputs("</number_applications>\n", file);
		fputs("<specific_skill>", file);
	sprintf(data, "%f", current->specific_skill);
	fputs(data, file);
	fputs("</specific_skill>\n", file);
		fputs("<employee_firm_id>", file);
	sprintf(data, "%i", current->employee_firm_id);
	fputs(data, file);
	fputs("</employee_firm_id>\n", file);
		fputs("<employer_region_id>", file);
	sprintf(data, "%i", current->employer_region_id);
	fputs(data, file);
	fputs("</employer_region_id>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Mall_agent(FILE *file, xmachine_memory_Mall * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Mall</name>\n", file);
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
		fputs("<current_stock>", file);
	write_mall_stock_dynamic_array(file, &current->current_stock);
	fputs("</current_stock>\n", file);
		fputs("<firm_revenues>", file);
	write_sales_in_mall_dynamic_array(file, &current->firm_revenues);
	fputs("</firm_revenues>\n", file);
		fputs("<total_supply>", file);
	sprintf(data, "%f", current->total_supply);
	fputs(data, file);
	fputs("</total_supply>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_IGFirm_agent(FILE *file, xmachine_memory_IGFirm * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>IGFirm</name>\n", file);
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
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<productivity>", file);
	sprintf(data, "%f", current->productivity);
	fputs(data, file);
	fputs("</productivity>\n", file);
		fputs("<innovation_probability>", file);
	sprintf(data, "%i", current->innovation_probability);
	fputs(data, file);
	fputs("</innovation_probability>\n", file);
		fputs("<productivity_progress>", file);
	sprintf(data, "%f", current->productivity_progress);
	fputs(data, file);
	fputs("</productivity_progress>\n", file);
		fputs("<capital_good_price>", file);
	sprintf(data, "%f", current->capital_good_price);
	fputs(data, file);
	fputs("</capital_good_price>\n", file);
		fputs("<revenue_per_day>", file);
	sprintf(data, "%f", current->revenue_per_day);
	fputs(data, file);
	fputs("</revenue_per_day>\n", file);
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
		fputs("<net_profit>", file);
	sprintf(data, "%f", current->net_profit);
	fputs(data, file);
	fputs("</net_profit>\n", file);
		fputs("<outstanding_shares>", file);
	sprintf(data, "%i", current->outstanding_shares);
	fputs(data, file);
	fputs("</outstanding_shares>\n", file);
		fputs("<current_dividend_per_share>", file);
	sprintf(data, "%f", current->current_dividend_per_share);
	fputs(data, file);
	fputs("</current_dividend_per_share>\n", file);
		fputs("<cum_revenues>", file);
	sprintf(data, "%f", current->cum_revenues);
	fputs(data, file);
	fputs("</cum_revenues>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Eurostat_agent(FILE *file, xmachine_memory_Eurostat * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Eurostat</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
		fputs("<no_regions>", file);
	sprintf(data, "%i", current->no_regions);
	fputs(data, file);
	fputs("</no_regions>\n", file);
		fputs("<num_households>", file);
	sprintf(data, "%i", current->num_households);
	fputs(data, file);
	fputs("</num_households>\n", file);
		fputs("<no_households_skill_1>", file);
	sprintf(data, "%i", current->no_households_skill_1);
	fputs(data, file);
	fputs("</no_households_skill_1>\n", file);
		fputs("<no_households_skill_2>", file);
	sprintf(data, "%i", current->no_households_skill_2);
	fputs(data, file);
	fputs("</no_households_skill_2>\n", file);
		fputs("<no_households_skill_3>", file);
	sprintf(data, "%i", current->no_households_skill_3);
	fputs(data, file);
	fputs("</no_households_skill_3>\n", file);
		fputs("<no_households_skill_4>", file);
	sprintf(data, "%i", current->no_households_skill_4);
	fputs(data, file);
	fputs("</no_households_skill_4>\n", file);
		fputs("<no_households_skill_5>", file);
	sprintf(data, "%i", current->no_households_skill_5);
	fputs(data, file);
	fputs("</no_households_skill_5>\n", file);
		fputs("<employed>", file);
	sprintf(data, "%i", current->employed);
	fputs(data, file);
	fputs("</employed>\n", file);
		fputs("<employed_skill_1>", file);
	sprintf(data, "%i", current->employed_skill_1);
	fputs(data, file);
	fputs("</employed_skill_1>\n", file);
		fputs("<employed_skill_2>", file);
	sprintf(data, "%i", current->employed_skill_2);
	fputs(data, file);
	fputs("</employed_skill_2>\n", file);
		fputs("<employed_skill_3>", file);
	sprintf(data, "%i", current->employed_skill_3);
	fputs(data, file);
	fputs("</employed_skill_3>\n", file);
		fputs("<employed_skill_4>", file);
	sprintf(data, "%i", current->employed_skill_4);
	fputs(data, file);
	fputs("</employed_skill_4>\n", file);
		fputs("<employed_skill_5>", file);
	sprintf(data, "%i", current->employed_skill_5);
	fputs(data, file);
	fputs("</employed_skill_5>\n", file);
		fputs("<unemployed>", file);
	sprintf(data, "%i", current->unemployed);
	fputs(data, file);
	fputs("</unemployed>\n", file);
		fputs("<unemployment_rate>", file);
	sprintf(data, "%f", current->unemployment_rate);
	fputs(data, file);
	fputs("</unemployment_rate>\n", file);
		fputs("<unemployment_rate_skill_1>", file);
	sprintf(data, "%f", current->unemployment_rate_skill_1);
	fputs(data, file);
	fputs("</unemployment_rate_skill_1>\n", file);
		fputs("<unemployment_rate_skill_2>", file);
	sprintf(data, "%f", current->unemployment_rate_skill_2);
	fputs(data, file);
	fputs("</unemployment_rate_skill_2>\n", file);
		fputs("<unemployment_rate_skill_3>", file);
	sprintf(data, "%f", current->unemployment_rate_skill_3);
	fputs(data, file);
	fputs("</unemployment_rate_skill_3>\n", file);
		fputs("<unemployment_rate_skill_4>", file);
	sprintf(data, "%f", current->unemployment_rate_skill_4);
	fputs(data, file);
	fputs("</unemployment_rate_skill_4>\n", file);
		fputs("<unemployment_rate_skill_5>", file);
	sprintf(data, "%f", current->unemployment_rate_skill_5);
	fputs(data, file);
	fputs("</unemployment_rate_skill_5>\n", file);
		fputs("<average_wage>", file);
	sprintf(data, "%f", current->average_wage);
	fputs(data, file);
	fputs("</average_wage>\n", file);
		fputs("<average_wage_skill_1>", file);
	sprintf(data, "%f", current->average_wage_skill_1);
	fputs(data, file);
	fputs("</average_wage_skill_1>\n", file);
		fputs("<average_wage_skill_2>", file);
	sprintf(data, "%f", current->average_wage_skill_2);
	fputs(data, file);
	fputs("</average_wage_skill_2>\n", file);
		fputs("<average_wage_skill_3>", file);
	sprintf(data, "%f", current->average_wage_skill_3);
	fputs(data, file);
	fputs("</average_wage_skill_3>\n", file);
		fputs("<average_wage_skill_4>", file);
	sprintf(data, "%f", current->average_wage_skill_4);
	fputs(data, file);
	fputs("</average_wage_skill_4>\n", file);
		fputs("<average_wage_skill_5>", file);
	sprintf(data, "%f", current->average_wage_skill_5);
	fputs(data, file);
	fputs("</average_wage_skill_5>\n", file);
		fputs("<average_s_skill>", file);
	sprintf(data, "%f", current->average_s_skill);
	fputs(data, file);
	fputs("</average_s_skill>\n", file);
		fputs("<average_s_skill_1>", file);
	sprintf(data, "%f", current->average_s_skill_1);
	fputs(data, file);
	fputs("</average_s_skill_1>\n", file);
		fputs("<average_s_skill_2>", file);
	sprintf(data, "%f", current->average_s_skill_2);
	fputs(data, file);
	fputs("</average_s_skill_2>\n", file);
		fputs("<average_s_skill_3>", file);
	sprintf(data, "%f", current->average_s_skill_3);
	fputs(data, file);
	fputs("</average_s_skill_3>\n", file);
		fputs("<average_s_skill_4>", file);
	sprintf(data, "%f", current->average_s_skill_4);
	fputs(data, file);
	fputs("</average_s_skill_4>\n", file);
		fputs("<average_s_skill_5>", file);
	sprintf(data, "%f", current->average_s_skill_5);
	fputs(data, file);
	fputs("</average_s_skill_5>\n", file);
		fputs("<no_firms>", file);
	sprintf(data, "%i", current->no_firms);
	fputs(data, file);
	fputs("</no_firms>\n", file);
		fputs("<no_vacancies>", file);
	sprintf(data, "%i", current->no_vacancies);
	fputs(data, file);
	fputs("</no_vacancies>\n", file);
		fputs("<no_employees>", file);
	sprintf(data, "%i", current->no_employees);
	fputs(data, file);
	fputs("</no_employees>\n", file);
		fputs("<no_employees_skill_1>", file);
	sprintf(data, "%i", current->no_employees_skill_1);
	fputs(data, file);
	fputs("</no_employees_skill_1>\n", file);
		fputs("<no_employees_skill_2>", file);
	sprintf(data, "%i", current->no_employees_skill_2);
	fputs(data, file);
	fputs("</no_employees_skill_2>\n", file);
		fputs("<no_employees_skill_3>", file);
	sprintf(data, "%i", current->no_employees_skill_3);
	fputs(data, file);
	fputs("</no_employees_skill_3>\n", file);
		fputs("<no_employees_skill_4>", file);
	sprintf(data, "%i", current->no_employees_skill_4);
	fputs(data, file);
	fputs("</no_employees_skill_4>\n", file);
		fputs("<no_employees_skill_5>", file);
	sprintf(data, "%i", current->no_employees_skill_5);
	fputs(data, file);
	fputs("</no_employees_skill_5>\n", file);
		fputs("<firm_average_wage>", file);
	sprintf(data, "%f", current->firm_average_wage);
	fputs(data, file);
	fputs("</firm_average_wage>\n", file);
		fputs("<firm_average_wage_skill_1>", file);
	sprintf(data, "%f", current->firm_average_wage_skill_1);
	fputs(data, file);
	fputs("</firm_average_wage_skill_1>\n", file);
		fputs("<firm_average_wage_skill_2>", file);
	sprintf(data, "%f", current->firm_average_wage_skill_2);
	fputs(data, file);
	fputs("</firm_average_wage_skill_2>\n", file);
		fputs("<firm_average_wage_skill_3>", file);
	sprintf(data, "%f", current->firm_average_wage_skill_3);
	fputs(data, file);
	fputs("</firm_average_wage_skill_3>\n", file);
		fputs("<firm_average_wage_skill_4>", file);
	sprintf(data, "%f", current->firm_average_wage_skill_4);
	fputs(data, file);
	fputs("</firm_average_wage_skill_4>\n", file);
		fputs("<firm_average_wage_skill_5>", file);
	sprintf(data, "%f", current->firm_average_wage_skill_5);
	fputs(data, file);
	fputs("</firm_average_wage_skill_5>\n", file);
		fputs("<firm_average_s_skill>", file);
	sprintf(data, "%f", current->firm_average_s_skill);
	fputs(data, file);
	fputs("</firm_average_s_skill>\n", file);
		fputs("<firm_average_s_skill_1>", file);
	sprintf(data, "%f", current->firm_average_s_skill_1);
	fputs(data, file);
	fputs("</firm_average_s_skill_1>\n", file);
		fputs("<firm_average_s_skill_2>", file);
	sprintf(data, "%f", current->firm_average_s_skill_2);
	fputs(data, file);
	fputs("</firm_average_s_skill_2>\n", file);
		fputs("<firm_average_s_skill_3>", file);
	sprintf(data, "%f", current->firm_average_s_skill_3);
	fputs(data, file);
	fputs("</firm_average_s_skill_3>\n", file);
		fputs("<firm_average_s_skill_4>", file);
	sprintf(data, "%f", current->firm_average_s_skill_4);
	fputs(data, file);
	fputs("</firm_average_s_skill_4>\n", file);
		fputs("<firm_average_s_skill_5>", file);
	sprintf(data, "%f", current->firm_average_s_skill_5);
	fputs(data, file);
	fputs("</firm_average_s_skill_5>\n", file);
		fputs("<region_firm_data>", file);
	write_firm_data_dynamic_array(file, &current->region_firm_data);
	fputs("</region_firm_data>\n", file);
		fputs("<region_household_data>", file);
	write_household_data_dynamic_array(file, &current->region_household_data);
	fputs("</region_household_data>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<government_tax_rates>", file);
	write_tax_rates_item_dynamic_array(file, &current->government_tax_rates);
	fputs("</government_tax_rates>\n", file);
		fputs("<gdp>", file);
	sprintf(data, "%f", current->gdp);
	fputs(data, file);
	fputs("</gdp>\n", file);
		fputs("<total_earnings>", file);
	sprintf(data, "%f", current->total_earnings);
	fputs(data, file);
	fputs("</total_earnings>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_equity>", file);
	sprintf(data, "%f", current->total_equity);
	fputs(data, file);
	fputs("</total_equity>\n", file);
		fputs("<average_debt_earnings_ratio>", file);
	sprintf(data, "%f", current->average_debt_earnings_ratio);
	fputs(data, file);
	fputs("</average_debt_earnings_ratio>\n", file);
		fputs("<average_debt_equity_ratio>", file);
	sprintf(data, "%f", current->average_debt_equity_ratio);
	fputs(data, file);
	fputs("</average_debt_equity_ratio>\n", file);
		fputs("<labour_share_ratio>", file);
	sprintf(data, "%f", current->labour_share_ratio);
	fputs(data, file);
	fputs("</labour_share_ratio>\n", file);
		
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
		fputs("<accounts>", file);
	write_account_dynamic_array(file, &current->accounts);
	fputs("</accounts>\n", file);
		fputs("<loans_outstanding>", file);
	write_outstanding_loans_dynamic_array(file, &current->loans_outstanding);
	fputs("</loans_outstanding>\n", file);
		fputs("<last_credit_id>", file);
	sprintf(data, "%i", current->last_credit_id);
	fputs(data, file);
	fputs("</last_credit_id>\n", file);
		fputs("<amount_credit_offer>", file);
	sprintf(data, "%f", current->amount_credit_offer);
	fputs(data, file);
	fputs("</amount_credit_offer>\n", file);
		fputs("<total_deposits>", file);
	sprintf(data, "%f", current->total_deposits);
	fputs(data, file);
	fputs("</total_deposits>\n", file);
		fputs("<total_loan_supply>", file);
	sprintf(data, "%f", current->total_loan_supply);
	fputs(data, file);
	fputs("</total_loan_supply>\n", file);
		fputs("<total_loan_demand>", file);
	sprintf(data, "%f", current->total_loan_demand);
	fputs(data, file);
	fputs("</total_loan_demand>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Government_agent(FILE *file, xmachine_memory_Government * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Government</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<tax_revenues>", file);
	sprintf(data, "%f", current->tax_revenues);
	fputs(data, file);
	fputs("</tax_revenues>\n", file);
		fputs("<unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->unemployment_benefit_payment);
	fputs(data, file);
	fputs("</unemployment_benefit_payment>\n", file);
		fputs("<total_unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->total_unemployment_benefit_payment);
	fputs(data, file);
	fputs("</total_unemployment_benefit_payment>\n", file);
		fputs("<total_interest_payment>", file);
	sprintf(data, "%f", current->total_interest_payment);
	fputs(data, file);
	fputs("</total_interest_payment>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<tax_rate_corporate>", file);
	sprintf(data, "%f", current->tax_rate_corporate);
	fputs(data, file);
	fputs("</tax_rate_corporate>\n", file);
		fputs("<tax_rate_hh_labour>", file);
	sprintf(data, "%f", current->tax_rate_hh_labour);
	fputs(data, file);
	fputs("</tax_rate_hh_labour>\n", file);
		fputs("<tax_rate_hh_capital>", file);
	sprintf(data, "%f", current->tax_rate_hh_capital);
	fputs(data, file);
	fputs("</tax_rate_hh_capital>\n", file);
		fputs("<tax_rate_vat>", file);
	sprintf(data, "%f", current->tax_rate_vat);
	fputs(data, file);
	fputs("</tax_rate_vat>\n", file);
		fputs("<num_unemployed>", file);
	sprintf(data, "%i", current->num_unemployed);
	fputs(data, file);
	fputs("</num_unemployed>\n", file);
		
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
	//double_array * last_planned_production_quantities;
	//int_array * neighboring_region_ids;
	//double_array * last_income;
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("</environment>\n" , file);

//	current_xmachine = *p_xmachine;
// todo loop through all agent types

current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
	while(current_xmachine_Firm_holder)
	{
		write_Firm_agent(file, current_xmachine_Firm_holder->agent);
		
		current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
	}

current_xmachine_Household_holder = Household_end_Household_state->agents;
	while(current_xmachine_Household_holder)
	{
		write_Household_agent(file, current_xmachine_Household_holder->agent);
		
		current_xmachine_Household_holder = current_xmachine_Household_holder->next;
	}

current_xmachine_Mall_holder = Mall_end_Mall_state->agents;
	while(current_xmachine_Mall_holder)
	{
		write_Mall_agent(file, current_xmachine_Mall_holder->agent);
		
		current_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
	}

current_xmachine_IGFirm_holder = IGFirm_end_IGFirm_state->agents;
	while(current_xmachine_IGFirm_holder)
	{
		write_IGFirm_agent(file, current_xmachine_IGFirm_holder->agent);
		
		current_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
	}

current_xmachine_Eurostat_holder = Eurostat_end_Eurostat_state->agents;
	while(current_xmachine_Eurostat_holder)
	{
		write_Eurostat_agent(file, current_xmachine_Eurostat_holder->agent);
		
		current_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
	}

current_xmachine_Bank_holder = Bank_end_BANK_state->agents;
	while(current_xmachine_Bank_holder)
	{
		write_Bank_agent(file, current_xmachine_Bank_holder->agent);
		
		current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
	}

current_xmachine_Government_holder = Government_end_Government_state->agents;
	while(current_xmachine_Government_holder)
	{
		write_Government_agent(file, current_xmachine_Government_holder->agent);
		
		current_xmachine_Government_holder = current_xmachine_Government_holder->next;
	}
	
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
