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
	(*temp_datatype).consumer_region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).consumer_region_id = atoi(arraydata);
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
			add_consumption_request(temp_datatype_array, 0, 0, 0, 0.0);
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
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;
	(*temp_datatype).previous_price = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).previous_price = atof(arraydata);
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
			add_mall_stock(temp_datatype_array, 0, 0, 0.0, 0.0, 0.0, 0.0);
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

/** \fn void read_account_item(char * buffer, int * j, account_item * temp_datatype)
 * \brief Reads account_item datatype.
 */
void read_account_item(char * buffer, int * j, account_item * temp_datatype)
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
	(*temp_datatype).payment_account = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;
}

void read_account_item_dynamic_array(char * buffer, int * j, account_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_account_item(temp_datatype_array, 0, 0.0);
			read_account_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_account_item_static_array(char * buffer, int * j, account_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_account_item(buffer, j, &temp_datatype_array[arraycount]);
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

/** \fn void read_Order(char * buffer, int * j, Order * temp_datatype)
 * \brief Reads Order datatype.
 */
void read_Order(char * buffer, int * j, Order * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).issuer = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).issuer = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
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
	(*temp_datatype).assetId = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).assetId = atoi(arraydata);
	(*j)++;
}

void read_Order_dynamic_array(char * buffer, int * j, Order_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Order(temp_datatype_array, 0, 0, 0.0, 0);
			read_Order(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Order_static_array(char * buffer, int * j, Order * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Order(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Belief(char * buffer, int * j, Belief * temp_datatype)
 * \brief Reads Belief datatype.
 */
void read_Belief(char * buffer, int * j, Belief * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).asset_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).asset_id = atoi(arraydata);
	(*j)++;
	(*temp_datatype).expectedPriceReturns = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedPriceReturns = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedTotalReturns = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedTotalReturns = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedCashFlowYield = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedCashFlowYield = atof(arraydata);
	(*j)++;
	(*temp_datatype).volatility = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).volatility = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedEarning = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedEarning = atof(arraydata);
	(*j)++;
	(*temp_datatype).expectedEarningPayout = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).expectedEarningPayout = atof(arraydata);
	(*j)++;
	(*temp_datatype).last_price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).last_price = atof(arraydata);
	(*j)++;
	(*temp_datatype).utility = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).utility = atof(arraydata);
	(*j)++;
}

void read_Belief_dynamic_array(char * buffer, int * j, Belief_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Belief(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			read_Belief(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Belief_static_array(char * buffer, int * j, Belief * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Belief(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Stock(char * buffer, int * j, Stock * temp_datatype)
 * \brief Reads Stock datatype.
 */
void read_Stock(char * buffer, int * j, Stock * temp_datatype)
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
	(*temp_datatype).nrOutStandingShares = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nrOutStandingShares = atoi(arraydata);
	(*j)++;
	(*temp_datatype).index = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).index = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).prices, 100);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).returns, 100);
	}
	
	(*j)++;
}

void read_Stock_dynamic_array(char * buffer, int * j, Stock_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Stock(temp_datatype_array, 0, 0, 0, NULL, NULL);
			read_Stock(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Stock_static_array(char * buffer, int * j, Stock * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Stock(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Bond(char * buffer, int * j, Bond * temp_datatype)
 * \brief Reads Bond datatype.
 */
void read_Bond(char * buffer, int * j, Bond * temp_datatype)
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
	(*temp_datatype).nr_outstanding = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_outstanding = atoi(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	(*temp_datatype).face_value = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).face_value = atof(arraydata);
	(*j)++;
	(*temp_datatype).nominal_yield = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nominal_yield = atof(arraydata);
	(*j)++;
	(*temp_datatype).maturity_day = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).maturity_day = atoi(arraydata);
	(*j)++;
	(*temp_datatype).issue_day = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).issue_day = atoi(arraydata);
	(*j)++;
	(*temp_datatype).yield2maturity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).yield2maturity = atof(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).prices, 100);
	}
	
	(*j)++;
	(*temp_datatype).index = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).index = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).returns, 100);
	}
	
	(*j)++;
}

void read_Bond_dynamic_array(char * buffer, int * j, Bond_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Bond(temp_datatype_array, 0, 0, 0, 0.0, 0.0, 0, 0, 0.0, NULL, 0, NULL);
			read_Bond(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Bond_static_array(char * buffer, int * j, Bond * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Bond(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Asset(char * buffer, int * j, Asset * temp_datatype)
 * \brief Reads Asset datatype.
 */
void read_Asset(char * buffer, int * j, Asset * temp_datatype)
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
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	(*temp_datatype).lastPrice = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).lastPrice = atof(arraydata);
	(*j)++;
}

void read_Asset_dynamic_array(char * buffer, int * j, Asset_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Asset(temp_datatype_array, 0, 0, 0.0);
			read_Asset(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Asset_static_array(char * buffer, int * j, Asset * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Asset(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_ClearingMechanism(char * buffer, int * j, ClearingMechanism * temp_datatype)
 * \brief Reads ClearingMechanism datatype.
 */
void read_ClearingMechanism(char * buffer, int * j, ClearingMechanism * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).lastPrice = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).lastPrice = atof(arraydata);
	(*j)++;
	(*temp_datatype).quantity = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_Order_dynamic_array(buffer, j, &(*temp_datatype).sellOrders);
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_Order_dynamic_array(buffer, j, &(*temp_datatype).buyOrders);
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, &(*temp_datatype).prices);
	}
	
	(*j)++;
}

void read_ClearingMechanism_dynamic_array(char * buffer, int * j, ClearingMechanism_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ClearingMechanism(temp_datatype_array, 0.0, 0, NULL, NULL, NULL);
			read_ClearingMechanism(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_ClearingMechanism_static_array(char * buffer, int * j, ClearingMechanism * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_ClearingMechanism(buffer, j, &temp_datatype_array[arraycount]);
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

/** \fn void read_logit(char * buffer, int * j, logit * temp_datatype)
 * \brief Reads logit datatype.
 */
void read_logit(char * buffer, int * j, logit * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).logit_value = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).logit_value = atof(arraydata);
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
	(*temp_datatype).general_skill = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).general_skill = atoi(arraydata);
	(*j)++;
}

void read_logit_dynamic_array(char * buffer, int * j, logit_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_logit(temp_datatype_array, 0.0, 0, 0);
			read_logit(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_logit_static_array(char * buffer, int * j, logit * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_logit(buffer, j, &temp_datatype_array[arraycount]);
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
	(*temp_datatype).no_firms = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firms = atoi(arraydata);
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
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).labour_share_ratio = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_sold_quantity = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_sold_quantity = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_output = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_output = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_revenue = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_revenue = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_planned_output = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_planned_output = atof(arraydata);
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
	(*temp_datatype).cpi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cpi = atof(arraydata);
	(*j)++;
	(*temp_datatype).cpi_last_month = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cpi_last_month = atof(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_births = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_births = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_deaths = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
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
			add_firm_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0);
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

/** \fn void read_region_data_item(char * buffer, int * j, region_data_item * temp_datatype)
 * \brief Reads region_data_item datatype.
 */
void read_region_data_item(char * buffer, int * j, region_data_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).cpi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cpi = atof(arraydata);
	(*j)++;
	(*temp_datatype).cpi_last_month = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cpi_last_month = atof(arraydata);
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
	(*temp_datatype).output = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).output = atof(arraydata);
	(*j)++;
	(*temp_datatype).employment = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employment = atoi(arraydata);
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
	(*temp_datatype).no_firms = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firms = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_births = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_births = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_deaths = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
	(*j)++;
}

void read_region_data_item_dynamic_array(char * buffer, int * j, region_data_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_region_data_item(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
			read_region_data_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_region_data_item_static_array(char * buffer, int * j, region_data_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_region_data_item(buffer, j, &temp_datatype_array[arraycount]);
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

/** \fn void read_history_item(char * buffer, int * j, history_item * temp_datatype)
 * \brief Reads history_item datatype.
 */
void read_history_item(char * buffer, int * j, history_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).cpi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cpi = atof(arraydata);
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
	(*temp_datatype).output = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).output = atof(arraydata);
	(*j)++;
	(*temp_datatype).employment = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).employment = atoi(arraydata);
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
	(*temp_datatype).no_firms = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firms = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_births = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_births = atoi(arraydata);
	(*j)++;
	(*temp_datatype).no_firm_deaths = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_region_data_item_dynamic_array(buffer, j, &(*temp_datatype).region_data);
	
	(*j)++;
}

void read_history_item_dynamic_array(char * buffer, int * j, history_item_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_history_item(temp_datatype_array, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, NULL);
			read_history_item(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_history_item_static_array(char * buffer, int * j, history_item * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_history_item(buffer, j, &temp_datatype_array[arraycount]);
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
	int in_Household_agent;
	int in_Mall_agent;
	int in_IGFirm_agent;
	int in_Eurostat_agent;
	int in_Clearinghouse_agent;
	int in_Bank_agent;
	int in_Government_agent;
	int in_Central_Bank_agent;

	int in_id;
	int in_region_id;
	int in_gov_id;
	int in_day_of_month_to_act;
	int in_last_day_of_month_to_act;
	int in_payment_account;
	int in_bank_id;
	int in_mean_wage;
	int in_needed_capital_stock;
	int in_actual_cap_price;
	int in_mean_specific_skills;
	int in_planned_production_quantity;
	int in_production_quantity;
	int in_planned_output;
	int in_output;
	int in_unit_costs;
	int in_total_supply;
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
	int in_total_external_financing_obtained;
	int in_capital_costs;
	int in_labour_costs;
	int in_capital_financing;
	int in_financial_resources_for_production;
	int in_planned_value_capital_stock;
	int in_total_units_local_inventory;
	int in_dmarketmatrix;
	int in_residual_var;
	int in_ebit;
	int in_earnings;
	int in_tax_rate_corporate;
	int in_tax_rate_vat;
	int in_tax_payment;
	int in_net_earnings;
	int in_previous_net_earnings;
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
	int in_earnings_per_share;
	int in_total_payments;
	int in_total_interest_payments;
	int in_previous_shares_outstanding;
	int in_earnings_payout;
	int in_current_shares_outstanding;
	int in_stock;
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
	int in_age;
	int in_transfer_payment;
	int in_subsidy_payment;
	int in_active;
	int in_bankruptcy_idle_counter;
	int in_bankruptcy_state;
	int in_bankruptcy_insolvency_state;
	int in_bankruptcy_illiquidity_state;
	int in_financial_crisis_state;
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
	int in_price_index;
	int in_price_index_base_period;
	int in_commuting_costs_price_level_weight;
	int in_last_income;
	int in_expenditures;
	int in_received_dividend;
	int in_wealth;
	int in_beliefs;
	int in_pendingOrders;
	int in_assetsowned;
	int in_assetWeights;
	int in_assetUtilities;
	int in_cash_on_hand;
	int in_forwardWindow;
	int in_backwardWindow;
	int in_bins;
	int in_randomWeight;
	int in_fundamentalWeight;
	int in_chartistWeight;
	int in_holdingPeriodToForwardW;
	int in_lossaversion;
	int in_strategy;
	int in_wage;
	int in_wage_reservation;
	int in_general_skill;
	int in_on_the_job_search;
	int in_number_applications;
	int in_last_labour_income;
	int in_specific_skill;
	int in_employee_firm_id;
	int in_employer_region_id;
	int in_day_of_month_receive_benefit;
	int in_unemployment_benefit_pct;
	int in_no_regions;
	int in_current_stock;
	int in_firm_revenues;
	int in_export_volume_matrix;
	int in_export_value_matrix;
	int in_export_previous_value_matrix;
	int in_productivity;
	int in_capital_good_price;
	int in_net_profit;
	int in_outstanding_shares;
	int in_cum_revenues;
	int in_switch_datastorage;
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
	int in_total_earnings;
	int in_total_equity;
	int in_average_debt_earnings_ratio;
	int in_average_debt_equity_ratio;
	int in_labour_share_ratio;
	int in_cpi;
	int in_gdp;
	int in_monthly_sold_quantity;
	int in_monthly_output;
	int in_monthly_revenue;
	int in_monthly_planned_output;
	int in_history_monthly;
	int in_history_quarterly;
	int in_monthly_growth_rates;
	int in_quarterly_growth_rates;
	int in_annual_growth_rates_monthly;
	int in_annual_growth_rates_quarterly;
	int in_no_firm_births;
	int in_no_firm_deaths;
	int in_firm_age_distribution;
	int in_firm_age_distribution_multiperiod;
	int in_firm_age_distribution_1_period_lag;
	int in_firm_age_distribution_2_period_lag;
	int in_firm_birth_rate;
	int in_firm_death_rate;
	int in_survival_rate;
	int in_survival_rate_multiperiod_1;
	int in_survival_rate_multiperiod_2;
	int in_survival_rate_multiperiod;
	int in_max_firm_creation;
	int in_recession_started;
	int in_recession_duration;
	int in_region_export_volume;
	int in_region_import_volume;
	int in_region_export_value;
	int in_region_import_value;
	int in_region_import_previous_value;
	int in_assets;
	int in_clearingmechanism;
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
	int in_list_of_regions;
	int in_bond;
	int in_pending_order;
	int in_deficit;
	int in_money_financing_fraction;
	int in_gdp_fraction_consumption;
	int in_gdp_fraction_investment;
	int in_monthly_tax_revenues;
	int in_yearly_tax_revenues;
	int in_monthly_unemployment_benefit_payment;
	int in_yearly_unemployment_benefit_payment;
	int in_hh_transfer_payment;
	int in_firm_transfer_payment;
	int in_monthly_transfer_payment;
	int in_yearly_transfer_payment;
	int in_hh_subsidy_payment;
	int in_firm_subsidy_payment;
	int in_monthly_subsidy_payment;
	int in_yearly_subsidy_payment;
	int in_monthly_bond_coupon_payment;
	int in_yearly_bond_coupon_payment;
	int in_gov_interest_rate;
	int in_yearly_investment_expenditure;
	int in_yearly_consumption_expenditure;
	int in_yearly_income;
	int in_yearly_expenditure;
	int in_yearly_budget_balance;
	int in_total_money_financing;
	int in_total_bond_financing;
	int in_country_wide_mean_wage;
	int in_num_unemployed;
	int in_gdp_growth;
	int in_gdp_forecast;
	int in_yearly_income_forecast;
	int in_yearly_expenditure_budget;
	int in_budget_balance_forecast;
	int in_monthly_consumption_expenditure;
	int in_monthly_investment_expenditure;
	int in_monthly_budget_balance;
	int in_monthly_consumption_budget;
	int in_monthly_investment_budget;
	int in_monthly_income;
	int in_monthly_expenditure;
	int in_yearly_consumption_budget;
	int in_yearly_investment_budget;
	int in_accounts;

	int in_print_log;
	int in_print_debug;
	int in_day;
	int in_week;
	int in_month;
	int in_quarter;
	int in_year;
	int in_number_of_banks_to_apply;
	int in_gamma_const;
	int in_alpha;
	int in_beta;
	int in_depreciation_rate;
	int in_discount_rate;
	int in_teta;
	int in_mark_up;
	int in_lambda;
	int in_wage_update;
	int in_min_vacancy;
	int in_wage_reservation_update;
	int in_region_cost;
	int in_inventory_costs_per_unit;
	int in_on_the_job_search_rate;
	int in_initial_consumption_propensity;
	int in_consumption_propensity;
	int in_firm_planning_horizon;
	int in_inv_inertia;
	int in_adaption_delivery_volume;
	int in_periods_to_repay_loans;
	int in_delivery_prob_if_critical_stock_0;
	int in_innovation_probability;
	int in_productivity_progress;
	int in_const_bankruptcy_idle_period;
	int in_debt_rescaling_factor;
	int in_target_leverage_ratio;
	int in_target_liquidity_ratio;
	int in_trading_activity;
	int in_BONDS_NEWISSUE_DISCOUNT;
	int in_gov_policy_unemployment_benefit_pct;
	int in_gov_policy_money_financing_fraction;
	int in_gov_policy_gdp_fraction_consumption;
	int in_gov_policy_gdp_fraction_investment;

	/* Variables for initial state data */
//	int id;
//	int region_id;
//	int gov_id;
//	int day_of_month_to_act;
//	int last_day_of_month_to_act;
//	double payment_account;
//	int bank_id;
//	double mean_wage;
//	double needed_capital_stock;
//	double actual_cap_price;
//	double mean_specific_skills;
//	double planned_production_quantity;
//	double production_quantity;
//	double planned_output;
//	double output;
//	double unit_costs;
//	double total_supply;
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
//	double total_external_financing_obtained;
//	double capital_costs;
//	double labour_costs;
//	financing_capital_array * capital_financing;
//	double financial_resources_for_production;
//	double planned_value_capital_stock;
//	double total_units_local_inventory;
//	int dmarketmatrix[10];
//	residual_var_datatype ** residual_var;
//	double ebit;
//	double earnings;
//	double tax_rate_corporate;
//	double tax_rate_vat;
//	double tax_payment;
//	double net_earnings;
//	double previous_net_earnings;
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
//	double earnings_per_share;
//	double total_payments;
//	double total_interest_payments;
//	double previous_shares_outstanding;
//	double earnings_payout;
//	double current_shares_outstanding;
//	Stock * stock;
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
//	int age;
//	double transfer_payment;
//	double subsidy_payment;
//	int active;
//	int bankruptcy_idle_counter;
//	int bankruptcy_state;
//	int bankruptcy_insolvency_state;
//	int bankruptcy_illiquidity_state;
//	int financial_crisis_state;
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
//	double price_index;
//	double price_index_base_period;
//	double commuting_costs_price_level_weight;
//	double_array * last_income;
//	double expenditures;
//	double received_dividend;
//	double wealth;
//	Belief_array * beliefs;
//	Order_array * pendingOrders;
//	Asset_array * assetsowned;
//	double_array * assetWeights;
//	double_array * assetUtilities;
//	double cash_on_hand;
//	int forwardWindow;
//	int backwardWindow;
//	int bins;
//	double randomWeight;
//	double fundamentalWeight;
//	double chartistWeight;
//	int holdingPeriodToForwardW;
//	double lossaversion;
//	double strategy;
//	double wage;
//	double wage_reservation;
//	int general_skill;
//	int on_the_job_search;
//	int number_applications;
//	double last_labour_income;
//	double specific_skill;
//	int employee_firm_id;
//	int employer_region_id;
//	int day_of_month_receive_benefit;
//	double unemployment_benefit_pct;
//	int no_regions;
//	mall_stock_array * current_stock;
//	sales_in_mall_array * firm_revenues;
//	double export_volume_matrix[900];
//	double export_value_matrix[900];
//	double export_previous_value_matrix[900];
//	double productivity;
//	double capital_good_price;
//	double net_profit;
//	int outstanding_shares;
//	double cum_revenues;
//	int switch_datastorage;
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
//	tax_rates_item ** government_tax_rates;
//	double total_earnings;
//	double total_equity;
//	double average_debt_earnings_ratio;
//	double average_debt_equity_ratio;
//	double labour_share_ratio;
//	double cpi;
//	double gdp;
//	double monthly_sold_quantity;
//	double monthly_output;
//	double monthly_revenue;
//	double monthly_planned_output;
//	history_item ** history_monthly;
//	history_item ** history_quarterly;
//	history_item * monthly_growth_rates;
//	history_item * quarterly_growth_rates;
//	history_item * annual_growth_rates_monthly;
//	history_item * annual_growth_rates_quarterly;
//	int no_firm_births;
//	int no_firm_deaths;
//	int firm_age_distribution[60];
//	int firm_age_distribution_multiperiod[720];
//	int firm_age_distribution_1_period_lag[60];
//	int firm_age_distribution_2_period_lag[60];
//	double firm_birth_rate;
//	double firm_death_rate;
//	double survival_rate[60];
//	double survival_rate_multiperiod_1[60];
//	double survival_rate_multiperiod_2[60];
//	double survival_rate_multiperiod[720];
//	int max_firm_creation;
//	int recession_started;
//	int recession_duration;
//	double region_export_volume[30];
//	double region_import_volume[30];
//	double region_export_value[30];
//	double region_import_value[30];
//	double region_import_previous_value[30];
//	Asset_array * assets;
//	ClearingMechanism * clearingmechanism;
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
//	int list_of_regions[1];
//	Bond * bond;
//	Order * pending_order;
//	double deficit;
//	double money_financing_fraction;
//	double gdp_fraction_consumption;
//	double gdp_fraction_investment;
//	double monthly_tax_revenues;
//	double yearly_tax_revenues;
//	double monthly_unemployment_benefit_payment;
//	double yearly_unemployment_benefit_payment;
//	double hh_transfer_payment;
//	double firm_transfer_payment;
//	double monthly_transfer_payment;
//	double yearly_transfer_payment;
//	double hh_subsidy_payment;
//	double firm_subsidy_payment;
//	double monthly_subsidy_payment;
//	double yearly_subsidy_payment;
//	double monthly_bond_coupon_payment;
//	double yearly_bond_coupon_payment;
//	double gov_interest_rate;
//	double yearly_investment_expenditure;
//	double yearly_consumption_expenditure;
//	double yearly_income;
//	double yearly_expenditure;
//	double yearly_budget_balance;
//	double total_money_financing;
//	double total_bond_financing;
//	double country_wide_mean_wage;
//	int num_unemployed;
//	double gdp_growth;
//	double gdp_forecast;
//	double yearly_income_forecast;
//	double yearly_expenditure_budget;
//	double budget_balance_forecast;
//	double monthly_consumption_expenditure;
//	double monthly_investment_expenditure;
//	double monthly_budget_balance;
//	double monthly_consumption_budget;
//	double monthly_investment_budget;
//	double monthly_income;
//	double monthly_expenditure;
//	double yearly_consumption_budget;
//	double yearly_investment_budget;
//	account_item_array * accounts;


	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Mall * current_Mall_agent;
	xmachine_memory_IGFirm * current_IGFirm_agent;
	xmachine_memory_Eurostat * current_Eurostat_agent;
	xmachine_memory_Clearinghouse * current_Clearinghouse_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_Government * current_Government_agent;
	xmachine_memory_Central_Bank * current_Central_Bank_agent;


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
	in_Household_agent = 0;
	in_Mall_agent = 0;
	in_IGFirm_agent = 0;
	in_Eurostat_agent = 0;
	in_Clearinghouse_agent = 0;
	in_Bank_agent = 0;
	in_Government_agent = 0;
	in_Central_Bank_agent = 0;
	in_id = 0;
	in_region_id = 0;
	in_gov_id = 0;
	in_day_of_month_to_act = 0;
	in_last_day_of_month_to_act = 0;
	in_payment_account = 0;
	in_bank_id = 0;
	in_mean_wage = 0;
	in_needed_capital_stock = 0;
	in_actual_cap_price = 0;
	in_mean_specific_skills = 0;
	in_planned_production_quantity = 0;
	in_production_quantity = 0;
	in_planned_output = 0;
	in_output = 0;
	in_unit_costs = 0;
	in_total_supply = 0;
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
	in_total_external_financing_obtained = 0;
	in_capital_costs = 0;
	in_labour_costs = 0;
	in_capital_financing = 0;
	in_financial_resources_for_production = 0;
	in_planned_value_capital_stock = 0;
	in_total_units_local_inventory = 0;
	in_dmarketmatrix = 0;
	in_residual_var = 0;
	in_ebit = 0;
	in_earnings = 0;
	in_tax_rate_corporate = 0;
	in_tax_rate_vat = 0;
	in_tax_payment = 0;
	in_net_earnings = 0;
	in_previous_net_earnings = 0;
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
	in_earnings_per_share = 0;
	in_total_payments = 0;
	in_total_interest_payments = 0;
	in_previous_shares_outstanding = 0;
	in_earnings_payout = 0;
	in_current_shares_outstanding = 0;
	in_stock = 0;
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
	in_age = 0;
	in_transfer_payment = 0;
	in_subsidy_payment = 0;
	in_active = 0;
	in_bankruptcy_idle_counter = 0;
	in_bankruptcy_state = 0;
	in_bankruptcy_insolvency_state = 0;
	in_bankruptcy_illiquidity_state = 0;
	in_financial_crisis_state = 0;
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
	in_price_index = 0;
	in_price_index_base_period = 0;
	in_commuting_costs_price_level_weight = 0;
	in_last_income = 0;
	in_expenditures = 0;
	in_received_dividend = 0;
	in_wealth = 0;
	in_beliefs = 0;
	in_pendingOrders = 0;
	in_assetsowned = 0;
	in_assetWeights = 0;
	in_assetUtilities = 0;
	in_cash_on_hand = 0;
	in_forwardWindow = 0;
	in_backwardWindow = 0;
	in_bins = 0;
	in_randomWeight = 0;
	in_fundamentalWeight = 0;
	in_chartistWeight = 0;
	in_holdingPeriodToForwardW = 0;
	in_lossaversion = 0;
	in_strategy = 0;
	in_wage = 0;
	in_wage_reservation = 0;
	in_general_skill = 0;
	in_on_the_job_search = 0;
	in_number_applications = 0;
	in_last_labour_income = 0;
	in_specific_skill = 0;
	in_employee_firm_id = 0;
	in_employer_region_id = 0;
	in_day_of_month_receive_benefit = 0;
	in_unemployment_benefit_pct = 0;
	in_no_regions = 0;
	in_current_stock = 0;
	in_firm_revenues = 0;
	in_export_volume_matrix = 0;
	in_export_value_matrix = 0;
	in_export_previous_value_matrix = 0;
	in_productivity = 0;
	in_capital_good_price = 0;
	in_net_profit = 0;
	in_outstanding_shares = 0;
	in_cum_revenues = 0;
	in_switch_datastorage = 0;
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
	in_total_earnings = 0;
	in_total_equity = 0;
	in_average_debt_earnings_ratio = 0;
	in_average_debt_equity_ratio = 0;
	in_labour_share_ratio = 0;
	in_cpi = 0;
	in_gdp = 0;
	in_monthly_sold_quantity = 0;
	in_monthly_output = 0;
	in_monthly_revenue = 0;
	in_monthly_planned_output = 0;
	in_history_monthly = 0;
	in_history_quarterly = 0;
	in_monthly_growth_rates = 0;
	in_quarterly_growth_rates = 0;
	in_annual_growth_rates_monthly = 0;
	in_annual_growth_rates_quarterly = 0;
	in_no_firm_births = 0;
	in_no_firm_deaths = 0;
	in_firm_age_distribution = 0;
	in_firm_age_distribution_multiperiod = 0;
	in_firm_age_distribution_1_period_lag = 0;
	in_firm_age_distribution_2_period_lag = 0;
	in_firm_birth_rate = 0;
	in_firm_death_rate = 0;
	in_survival_rate = 0;
	in_survival_rate_multiperiod_1 = 0;
	in_survival_rate_multiperiod_2 = 0;
	in_survival_rate_multiperiod = 0;
	in_max_firm_creation = 0;
	in_recession_started = 0;
	in_recession_duration = 0;
	in_region_export_volume = 0;
	in_region_import_volume = 0;
	in_region_export_value = 0;
	in_region_import_value = 0;
	in_region_import_previous_value = 0;
	in_assets = 0;
	in_clearingmechanism = 0;
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
	in_list_of_regions = 0;
	in_bond = 0;
	in_pending_order = 0;
	in_deficit = 0;
	in_money_financing_fraction = 0;
	in_gdp_fraction_consumption = 0;
	in_gdp_fraction_investment = 0;
	in_monthly_tax_revenues = 0;
	in_yearly_tax_revenues = 0;
	in_monthly_unemployment_benefit_payment = 0;
	in_yearly_unemployment_benefit_payment = 0;
	in_hh_transfer_payment = 0;
	in_firm_transfer_payment = 0;
	in_monthly_transfer_payment = 0;
	in_yearly_transfer_payment = 0;
	in_hh_subsidy_payment = 0;
	in_firm_subsidy_payment = 0;
	in_monthly_subsidy_payment = 0;
	in_yearly_subsidy_payment = 0;
	in_monthly_bond_coupon_payment = 0;
	in_yearly_bond_coupon_payment = 0;
	in_gov_interest_rate = 0;
	in_yearly_investment_expenditure = 0;
	in_yearly_consumption_expenditure = 0;
	in_yearly_income = 0;
	in_yearly_expenditure = 0;
	in_yearly_budget_balance = 0;
	in_total_money_financing = 0;
	in_total_bond_financing = 0;
	in_country_wide_mean_wage = 0;
	in_num_unemployed = 0;
	in_gdp_growth = 0;
	in_gdp_forecast = 0;
	in_yearly_income_forecast = 0;
	in_yearly_expenditure_budget = 0;
	in_budget_balance_forecast = 0;
	in_monthly_consumption_expenditure = 0;
	in_monthly_investment_expenditure = 0;
	in_monthly_budget_balance = 0;
	in_monthly_consumption_budget = 0;
	in_monthly_investment_budget = 0;
	in_monthly_income = 0;
	in_monthly_expenditure = 0;
	in_yearly_consumption_budget = 0;
	in_yearly_investment_budget = 0;
	in_accounts = 0;
	in_print_log = 0;
	in_print_debug = 0;
	in_day = 0;
	in_week = 0;
	in_month = 0;
	in_quarter = 0;
	in_year = 0;
	in_number_of_banks_to_apply = 0;
	in_gamma_const = 0;
	in_alpha = 0;
	in_beta = 0;
	in_depreciation_rate = 0;
	in_discount_rate = 0;
	in_teta = 0;
	in_mark_up = 0;
	in_lambda = 0;
	in_wage_update = 0;
	in_min_vacancy = 0;
	in_wage_reservation_update = 0;
	in_region_cost = 0;
	in_inventory_costs_per_unit = 0;
	in_on_the_job_search_rate = 0;
	in_initial_consumption_propensity = 0;
	in_consumption_propensity = 0;
	in_firm_planning_horizon = 0;
	in_inv_inertia = 0;
	in_adaption_delivery_volume = 0;
	in_periods_to_repay_loans = 0;
	in_delivery_prob_if_critical_stock_0 = 0;
	in_innovation_probability = 0;
	in_productivity_progress = 0;
	in_const_bankruptcy_idle_period = 0;
	in_debt_rescaling_factor = 0;
	in_target_leverage_ratio = 0;
	in_target_liquidity_ratio = 0;
	in_trading_activity = 0;
	in_BONDS_NEWISSUE_DISCOUNT = 0;
	in_gov_policy_unemployment_benefit_pct = 0;
	in_gov_policy_money_financing_fraction = 0;
	in_gov_policy_gdp_fraction_consumption = 0;
	in_gov_policy_gdp_fraction_investment = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	region_id = 0;
//	gov_id = 0;
//	day_of_month_to_act = 0;
//	last_day_of_month_to_act = 0;
//	payment_account = 0.0;
//	bank_id = 0;
//	mean_wage = 0.0;
//	needed_capital_stock = 0.0;
//	actual_cap_price = 0.0;
//	mean_specific_skills = 0.0;
//	planned_production_quantity = 0.0;
//	production_quantity = 0.0;
//	planned_output = 0.0;
//	output = 0.0;
//	unit_costs = 0.0;
//	total_supply = 0.0;
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
//	total_external_financing_obtained = 0.0;
//	capital_costs = 0.0;
//	labour_costs = 0.0;
//	capital_financing = init_financing_capital_array();
//	financial_resources_for_production = 0.0;
//	planned_value_capital_stock = 0.0;
//	total_units_local_inventory = 0.0;
////	residual_var = init_residual_var_datatype_static_array(10);
//	ebit = 0.0;
//	earnings = 0.0;
//	tax_rate_corporate = 0.0;
//	tax_rate_vat = 0.0;
//	tax_payment = 0.0;
//	net_earnings = 0.0;
//	previous_net_earnings = 0.0;
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
//	earnings_per_share = 0.0;
//	total_payments = 0.0;
//	total_interest_payments = 0.0;
//	previous_shares_outstanding = 0.0;
//	earnings_payout = 0.0;
//	current_shares_outstanding = 0.0;
//	stock = init_Stock();
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
//	age = 0;
//	transfer_payment = 0.0;
//	subsidy_payment = 0.0;
//	active = 0;
//	bankruptcy_idle_counter = 0;
//	bankruptcy_state = 0;
//	bankruptcy_insolvency_state = 0;
//	bankruptcy_illiquidity_state = 0;
//	financial_crisis_state = 0;
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
//	price_index = 0.0;
//	price_index_base_period = 0.0;
//	commuting_costs_price_level_weight = 0.0;
//	last_income = init_double_array();
//	expenditures = 0.0;
//	received_dividend = 0.0;
//	wealth = 0.0;
//	beliefs = init_Belief_array();
//	pendingOrders = init_Order_array();
//	assetsowned = init_Asset_array();
//	assetWeights = init_double_array();
//	assetUtilities = init_double_array();
//	cash_on_hand = 0.0;
//	forwardWindow = 0;
//	backwardWindow = 0;
//	bins = 0;
//	randomWeight = 0.0;
//	fundamentalWeight = 0.0;
//	chartistWeight = 0.0;
//	holdingPeriodToForwardW = 0;
//	lossaversion = 0.0;
//	strategy = 0.0;
//	wage = 0.0;
//	wage_reservation = 0.0;
//	general_skill = 0;
//	on_the_job_search = 0;
//	number_applications = 0;
//	last_labour_income = 0.0;
//	specific_skill = 0.0;
//	employee_firm_id = 0;
//	employer_region_id = 0;
//	day_of_month_receive_benefit = 0;
//	unemployment_benefit_pct = 0.0;
//	no_regions = 0;
//	current_stock = init_mall_stock_array();
//	firm_revenues = init_sales_in_mall_array();
////////	productivity = 0.0;
//	capital_good_price = 0.0;
//	net_profit = 0.0;
//	outstanding_shares = 0;
//	cum_revenues = 0.0;
//	switch_datastorage = 0;
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
//	government_tax_rates = init_tax_rates_item_static_array(27);
//	total_earnings = 0.0;
//	total_equity = 0.0;
//	average_debt_earnings_ratio = 0.0;
//	average_debt_equity_ratio = 0.0;
//	labour_share_ratio = 0.0;
//	cpi = 0.0;
//	gdp = 0.0;
//	monthly_sold_quantity = 0.0;
//	monthly_output = 0.0;
//	monthly_revenue = 0.0;
//	monthly_planned_output = 0.0;
//	history_monthly = init_history_item_static_array(13);
//	history_quarterly = init_history_item_static_array(5);
//	monthly_growth_rates = init_history_item();
//	quarterly_growth_rates = init_history_item();
//	annual_growth_rates_monthly = init_history_item();
//	annual_growth_rates_quarterly = init_history_item();
//	no_firm_births = 0;
//	no_firm_deaths = 0;
//////////	firm_birth_rate = 0.0;
//	firm_death_rate = 0.0;
//////////	max_firm_creation = 0;
//	recession_started = 0;
//	recession_duration = 0;
////////////	assets = init_Asset_array();
//	clearingmechanism = init_ClearingMechanism();
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
////	bond = init_Bond();
//	pending_order = init_Order();
//	deficit = 0.0;
//	money_financing_fraction = 0.0;
//	gdp_fraction_consumption = 0.0;
//	gdp_fraction_investment = 0.0;
//	monthly_tax_revenues = 0.0;
//	yearly_tax_revenues = 0.0;
//	monthly_unemployment_benefit_payment = 0.0;
//	yearly_unemployment_benefit_payment = 0.0;
//	hh_transfer_payment = 0.0;
//	firm_transfer_payment = 0.0;
//	monthly_transfer_payment = 0.0;
//	yearly_transfer_payment = 0.0;
//	hh_subsidy_payment = 0.0;
//	firm_subsidy_payment = 0.0;
//	monthly_subsidy_payment = 0.0;
//	yearly_subsidy_payment = 0.0;
//	monthly_bond_coupon_payment = 0.0;
//	yearly_bond_coupon_payment = 0.0;
//	gov_interest_rate = 0.0;
//	yearly_investment_expenditure = 0.0;
//	yearly_consumption_expenditure = 0.0;
//	yearly_income = 0.0;
//	yearly_expenditure = 0.0;
//	yearly_budget_balance = 0.0;
//	total_money_financing = 0.0;
//	total_bond_financing = 0.0;
//	country_wide_mean_wage = 0.0;
//	num_unemployed = 0;
//	gdp_growth = 0.0;
//	gdp_forecast = 0.0;
//	yearly_income_forecast = 0.0;
//	yearly_expenditure_budget = 0.0;
//	budget_balance_forecast = 0.0;
//	monthly_consumption_expenditure = 0.0;
//	monthly_investment_expenditure = 0.0;
//	monthly_budget_balance = 0.0;
//	monthly_consumption_budget = 0.0;
//	monthly_investment_budget = 0.0;
//	monthly_income = 0.0;
//	monthly_expenditure = 0.0;
//	yearly_consumption_budget = 0.0;
//	yearly_investment_budget = 0.0;
//	accounts = init_account_item_array();

	print_log = 0;
	print_debug = 0;
	day = 0;
	week = 0;
	month = 0;
	quarter = 0;
	year = 0;
	number_of_banks_to_apply = 0;
	gamma_const = 0;
	alpha = 0.0;
	beta = 0.0;
	depreciation_rate = 0.0;
	discount_rate = 0.0;
	teta = 0.0;
	mark_up = 0.0;
	lambda = 0.0;
	wage_update = 0.0;
	min_vacancy = 0;
	wage_reservation_update = 0.0;
	region_cost = 0.0;
	inventory_costs_per_unit = 0;
	on_the_job_search_rate = 0.0;
	initial_consumption_propensity = 0.0;
	consumption_propensity = 0.0;
	firm_planning_horizon = 0;
	inv_inertia = 0;
	adaption_delivery_volume = 0.0;
	periods_to_repay_loans = 0;
	delivery_prob_if_critical_stock_0 = 0;
	innovation_probability = 0;
	productivity_progress = 0.0;
	const_bankruptcy_idle_period = 0;
	debt_rescaling_factor = 0.0;
	target_leverage_ratio = 0.0;
	target_liquidity_ratio = 0.0;
	trading_activity = 0.0;
	BONDS_NEWISSUE_DISCOUNT = 0.0;
	gov_policy_unemployment_benefit_pct = 0.0;
	gov_policy_money_financing_fraction = 0.0;
	gov_policy_gdp_fraction_consumption = 0.0;
	gov_policy_gdp_fraction_investment = 0.0;






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
					else if(strcmp(agentname, "Clearinghouse") == 0)
					{
						current_Clearinghouse_agent = init_Clearinghouse_agent();
						in_Clearinghouse_agent = 1;
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
					else if(strcmp(agentname, "Central_Bank") == 0)
					{
						current_Central_Bank_agent = init_Central_Bank_agent();
						in_Central_Bank_agent = 1;
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
in_Clearinghouse_agent = 0;
in_Bank_agent = 0;
in_Government_agent = 0;
in_Central_Bank_agent = 0;

				
				if(strcmp(agentname, "Firm") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, last_day_of_month_to_act, payment_account, bank_id, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, planned_output, output, unit_costs, total_supply, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, total_external_financing_obtained, capital_costs, labour_costs, capital_financing, financial_resources_for_production, planned_value_capital_stock, total_units_local_inventory, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, earnings_per_share, total_payments, total_interest_payments, previous_shares_outstanding, earnings_payout, current_shares_outstanding, stock, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed, age, transfer_payment, subsidy_payment, active, bankruptcy_idle_counter, bankruptcy_state, bankruptcy_insolvency_state, bankruptcy_illiquidity_state, financial_crisis_state);
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
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, last_day_of_month_to_act, payment_account, bank_id, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, planned_output, output, unit_costs, total_supply, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, total_external_financing_obtained, capital_costs, labour_costs, capital_financing, financial_resources_for_production, planned_value_capital_stock, total_units_local_inventory, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, earnings_per_share, total_payments, total_interest_payments, previous_shares_outstanding, earnings_payout, current_shares_outstanding, stock, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed, age, transfer_payment, subsidy_payment, active, bankruptcy_idle_counter, bankruptcy_state, bankruptcy_insolvency_state, bankruptcy_illiquidity_state, financial_crisis_state);
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
								//add_Firm_agent(id, region_id, gov_id, day_of_month_to_act, last_day_of_month_to_act, payment_account, bank_id, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, planned_output, output, unit_costs, total_supply, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, demand_capital_stock, planned_production_costs, adaption_production_volume_due_to_insufficient_finances, fraction_reserved_for_delayed_payments, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, last_planned_production_quantities, total_external_financing_obtained, capital_costs, labour_costs, capital_financing, financial_resources_for_production, planned_value_capital_stock, total_units_local_inventory, dmarketmatrix, residual_var, ebit, earnings, tax_rate_corporate, tax_rate_vat, tax_payment, net_earnings, previous_net_earnings, total_interest_payment, total_debt_installment_payment, total_dividend_payment, current_share_price, previous_dividend_per_share, current_dividend_per_share, previous_earnings_per_share, current_earnings_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, debt_earnings_ratio, debt_equity_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, loans, total_debt, total_value_local_inventory, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, total_assets, equity, production_liquidity_needs, financial_liquidity_needs, total_financial_needs, external_financial_needs, earnings_per_share, total_payments, total_interest_payments, previous_shares_outstanding, earnings_payout, current_shares_outstanding, stock, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, employees_needed, age, transfer_payment, subsidy_payment, active, bankruptcy_idle_counter, bankruptcy_state, bankruptcy_insolvency_state, bankruptcy_illiquidity_state, financial_crisis_state);
								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);

								/*current_Firm_agent->0.0 = xcentre;
								current_Firm_agent->0.0 = ycentre;
								current_Firm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, day_of_month_to_act, payment_account, bank_id, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, price_index, price_index_base_period, commuting_costs_price_level_weight, last_income, expenditures, received_dividend, wealth, beliefs, pendingOrders, assetsowned, assetWeights, assetUtilities, cash_on_hand, forwardWindow, backwardWindow, bins, randomWeight, fundamentalWeight, chartistWeight, holdingPeriodToForwardW, lossaversion, strategy, wage, wage_reservation, general_skill, on_the_job_search, number_applications, last_labour_income, specific_skill, employee_firm_id, employer_region_id, day_of_month_receive_benefit, unemployment_benefit_pct, transfer_payment, subsidy_payment);
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
								//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, day_of_month_to_act, payment_account, bank_id, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, price_index, price_index_base_period, commuting_costs_price_level_weight, last_income, expenditures, received_dividend, wealth, beliefs, pendingOrders, assetsowned, assetWeights, assetUtilities, cash_on_hand, forwardWindow, backwardWindow, bins, randomWeight, fundamentalWeight, chartistWeight, holdingPeriodToForwardW, lossaversion, strategy, wage, wage_reservation, general_skill, on_the_job_search, number_applications, last_labour_income, specific_skill, employee_firm_id, employer_region_id, day_of_month_receive_benefit, unemployment_benefit_pct, transfer_payment, subsidy_payment);
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
								//add_Household_agent(id, region_id, neighboring_region_ids, gov_id, day_of_month_to_act, payment_account, bank_id, consumption_budget, mean_income, week_of_month, weekly_budget, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_week_to_act, day_of_month_receive_income, current_productivity_employer, current_mean_specific_skills_employer, total_taxes, cum_total_dividends, tax_rate_hh_capital, tax_rate_hh_labour, price_index, price_index_base_period, commuting_costs_price_level_weight, last_income, expenditures, received_dividend, wealth, beliefs, pendingOrders, assetsowned, assetWeights, assetUtilities, cash_on_hand, forwardWindow, backwardWindow, bins, randomWeight, fundamentalWeight, chartistWeight, holdingPeriodToForwardW, lossaversion, strategy, wage, wage_reservation, general_skill, on_the_job_search, number_applications, last_labour_income, specific_skill, employee_firm_id, employer_region_id, day_of_month_receive_benefit, unemployment_benefit_pct, transfer_payment, subsidy_payment);
								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);

								/*current_Household_agent->0.0 = xcentre;
								current_Household_agent->0.0 = ycentre;
								current_Household_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Mall") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Mall_agent(id, region_id, gov_id, no_regions, current_stock, firm_revenues, total_supply, export_volume_matrix, export_value_matrix, export_previous_value_matrix);
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
								//add_Mall_agent(id, region_id, gov_id, no_regions, current_stock, firm_revenues, total_supply, export_volume_matrix, export_value_matrix, export_previous_value_matrix);
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
								//add_Mall_agent(id, region_id, gov_id, no_regions, current_stock, firm_revenues, total_supply, export_volume_matrix, export_value_matrix, export_previous_value_matrix);
								add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);

								/*current_Mall_agent->0.0 = xcentre;
								current_Mall_agent->0.0 = ycentre;
								current_Mall_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "IGFirm") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues, age, transfer_payment, subsidy_payment);
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
								//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues, age, transfer_payment, subsidy_payment);
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
								//add_IGFirm_agent(id, region_id, gov_id, bank_id, day_of_month_to_act, payment_account, productivity, capital_good_price, revenue_per_day, tax_rate_corporate, tax_rate_vat, tax_payment, net_profit, outstanding_shares, current_dividend_per_share, cum_revenues, age, transfer_payment, subsidy_payment);
								add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);

								/*current_IGFirm_agent->0.0 = xcentre;
								current_IGFirm_agent->0.0 = ycentre;
								current_IGFirm_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Eurostat") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Eurostat_agent(id, region_id, no_regions, switch_datastorage, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, government_tax_rates, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio, cpi, gdp, monthly_sold_quantity, monthly_output, monthly_revenue, monthly_planned_output, price_index, history_monthly, history_quarterly, monthly_growth_rates, quarterly_growth_rates, annual_growth_rates_monthly, annual_growth_rates_quarterly, no_firm_births, no_firm_deaths, firm_age_distribution, firm_age_distribution_multiperiod, firm_age_distribution_1_period_lag, firm_age_distribution_2_period_lag, firm_birth_rate, firm_death_rate, survival_rate, survival_rate_multiperiod_1, survival_rate_multiperiod_2, survival_rate_multiperiod, max_firm_creation, recession_started, recession_duration, export_volume_matrix, export_value_matrix, export_previous_value_matrix, region_export_volume, region_import_volume, region_export_value, region_import_value, region_import_previous_value);
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
								//add_Eurostat_agent(id, region_id, no_regions, switch_datastorage, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, government_tax_rates, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio, cpi, gdp, monthly_sold_quantity, monthly_output, monthly_revenue, monthly_planned_output, price_index, history_monthly, history_quarterly, monthly_growth_rates, quarterly_growth_rates, annual_growth_rates_monthly, annual_growth_rates_quarterly, no_firm_births, no_firm_deaths, firm_age_distribution, firm_age_distribution_multiperiod, firm_age_distribution_1_period_lag, firm_age_distribution_2_period_lag, firm_birth_rate, firm_death_rate, survival_rate, survival_rate_multiperiod_1, survival_rate_multiperiod_2, survival_rate_multiperiod, max_firm_creation, recession_started, recession_duration, export_volume_matrix, export_value_matrix, export_previous_value_matrix, region_export_volume, region_import_volume, region_export_value, region_import_value, region_import_previous_value);
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
								//add_Eurostat_agent(id, region_id, no_regions, switch_datastorage, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, government_tax_rates, total_earnings, total_debt, total_assets, total_equity, average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio, cpi, gdp, monthly_sold_quantity, monthly_output, monthly_revenue, monthly_planned_output, price_index, history_monthly, history_quarterly, monthly_growth_rates, quarterly_growth_rates, annual_growth_rates_monthly, annual_growth_rates_quarterly, no_firm_births, no_firm_deaths, firm_age_distribution, firm_age_distribution_multiperiod, firm_age_distribution_1_period_lag, firm_age_distribution_2_period_lag, firm_birth_rate, firm_death_rate, survival_rate, survival_rate_multiperiod_1, survival_rate_multiperiod_2, survival_rate_multiperiod, max_firm_creation, recession_started, recession_duration, export_volume_matrix, export_value_matrix, export_previous_value_matrix, region_export_volume, region_import_volume, region_export_value, region_import_value, region_import_previous_value);
								add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);

								/*current_Eurostat_agent->0.0 = xcentre;
								current_Eurostat_agent->0.0 = ycentre;
								current_Eurostat_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Clearinghouse") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Clearinghouse_agent(id, region_id, assets, clearingmechanism);
						add_Clearinghouse_agent_internal(current_Clearinghouse_agent, Clearinghouse_start_Clearinghouse_state);
						
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
								//add_Clearinghouse_agent(id, region_id, assets, clearingmechanism);
								add_Clearinghouse_agent_internal(current_Clearinghouse_agent, Clearinghouse_start_Clearinghouse_state);
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
								//add_Clearinghouse_agent(id, region_id, assets, clearingmechanism);
								add_Clearinghouse_agent_internal(current_Clearinghouse_agent, Clearinghouse_start_Clearinghouse_state);

								/*current_Clearinghouse_agent->0.0 = xcentre;
								current_Clearinghouse_agent->0.0 = ycentre;
								current_Clearinghouse_agent-> = rrange;*/

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
						add_Bank_agent_internal(current_Bank_agent, Bank_start_Bank_state);
						
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
								add_Bank_agent_internal(current_Bank_agent, Bank_start_Bank_state);
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
								add_Bank_agent_internal(current_Bank_agent, Bank_start_Bank_state);

								/*current_Bank_agent->0.0 = xcentre;
								current_Bank_agent->0.0 = ycentre;
								current_Bank_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Government") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Government_agent(id, list_of_regions, payment_account, day_of_month_to_act, bond, pending_order, deficit, unemployment_benefit_pct, money_financing_fraction, gdp_fraction_consumption, gdp_fraction_investment, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_investment_expenditure, yearly_consumption_expenditure, yearly_income, yearly_expenditure, total_debt, yearly_budget_balance, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, yearly_income_forecast, yearly_expenditure_budget, budget_balance_forecast, monthly_consumption_expenditure, monthly_investment_expenditure, monthly_budget_balance, monthly_consumption_budget, monthly_investment_budget, monthly_income, monthly_expenditure, yearly_consumption_budget, yearly_investment_budget);
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
								//add_Government_agent(id, list_of_regions, payment_account, day_of_month_to_act, bond, pending_order, deficit, unemployment_benefit_pct, money_financing_fraction, gdp_fraction_consumption, gdp_fraction_investment, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_investment_expenditure, yearly_consumption_expenditure, yearly_income, yearly_expenditure, total_debt, yearly_budget_balance, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, yearly_income_forecast, yearly_expenditure_budget, budget_balance_forecast, monthly_consumption_expenditure, monthly_investment_expenditure, monthly_budget_balance, monthly_consumption_budget, monthly_investment_budget, monthly_income, monthly_expenditure, yearly_consumption_budget, yearly_investment_budget);
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
								//add_Government_agent(id, list_of_regions, payment_account, day_of_month_to_act, bond, pending_order, deficit, unemployment_benefit_pct, money_financing_fraction, gdp_fraction_consumption, gdp_fraction_investment, tax_rate_corporate, tax_rate_hh_labour, tax_rate_hh_capital, tax_rate_vat, monthly_tax_revenues, yearly_tax_revenues, monthly_unemployment_benefit_payment, yearly_unemployment_benefit_payment, hh_transfer_payment, firm_transfer_payment, monthly_transfer_payment, yearly_transfer_payment, hh_subsidy_payment, firm_subsidy_payment, monthly_subsidy_payment, yearly_subsidy_payment, monthly_bond_coupon_payment, yearly_bond_coupon_payment, gov_interest_rate, yearly_investment_expenditure, yearly_consumption_expenditure, yearly_income, yearly_expenditure, total_debt, yearly_budget_balance, total_money_financing, total_bond_financing, country_wide_mean_wage, num_unemployed, gdp, gdp_growth, gdp_forecast, yearly_income_forecast, yearly_expenditure_budget, budget_balance_forecast, monthly_consumption_expenditure, monthly_investment_expenditure, monthly_budget_balance, monthly_consumption_budget, monthly_investment_budget, monthly_income, monthly_expenditure, yearly_consumption_budget, yearly_investment_budget);
								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);

								/*current_Government_agent->0.0 = xcentre;
								current_Government_agent->0.0 = ycentre;
								current_Government_agent-> = rrange;*/

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Central_Bank") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Central_Bank_agent(id, accounts);
						add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);
						
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
								//add_Central_Bank_agent(id, accounts);
								add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);
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
								//add_Central_Bank_agent(id, accounts);
								add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);

								/*current_Central_Bank_agent->0.0 = xcentre;
								current_Central_Bank_agent->0.0 = ycentre;
								current_Central_Bank_agent-> = rrange;*/

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
//				last_day_of_month_to_act = 0;
//				payment_account = 0.0;
//				bank_id = 0;
//				mean_wage = 0.0;
//				needed_capital_stock = 0.0;
//				actual_cap_price = 0.0;
//				mean_specific_skills = 0.0;
//				planned_production_quantity = 0.0;
//				production_quantity = 0.0;
//				planned_output = 0.0;
//				output = 0.0;
//				unit_costs = 0.0;
//				total_supply = 0.0;
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
//////////				total_external_financing_obtained = 0.0;
//				capital_costs = 0.0;
//				labour_costs = 0.0;
////				financial_resources_for_production = 0.0;
//				planned_value_capital_stock = 0.0;
//				total_units_local_inventory = 0.0;
//////				ebit = 0.0;
//				earnings = 0.0;
//				tax_rate_corporate = 0.0;
//				tax_rate_vat = 0.0;
//				tax_payment = 0.0;
//				net_earnings = 0.0;
//				previous_net_earnings = 0.0;
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
//				total_units_capital_stock = 0.0;
//				total_value_capital_stock = 0.0;
//				total_capital_depreciation_value = 0.0;
//				total_capital_depreciation_units = 0.0;
//				total_assets = 0.0;
//				equity = 0.0;
//				production_liquidity_needs = 0.0;
//				financial_liquidity_needs = 0.0;
//				total_financial_needs = 0.0;
//				external_financial_needs = 0.0;
//				earnings_per_share = 0.0;
//				total_payments = 0.0;
//				total_interest_payments = 0.0;
//				previous_shares_outstanding = 0.0;
//				earnings_payout = 0.0;
//				current_shares_outstanding = 0.0;
//////				wage_offer = 0.0;
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
//				age = 0;
//				transfer_payment = 0.0;
//				subsidy_payment = 0.0;
//				active = 0;
//				bankruptcy_idle_counter = 0;
//				bankruptcy_state = 0;
//				bankruptcy_insolvency_state = 0;
//				bankruptcy_illiquidity_state = 0;
//				financial_crisis_state = 0;
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
//				price_index = 0.0;
//				price_index_base_period = 0.0;
//				commuting_costs_price_level_weight = 0.0;
////				expenditures = 0.0;
//				received_dividend = 0.0;
//				wealth = 0.0;
////////////				cash_on_hand = 0.0;
//				forwardWindow = 0;
//				backwardWindow = 0;
//				bins = 0;
//				randomWeight = 0.0;
//				fundamentalWeight = 0.0;
//				chartistWeight = 0.0;
//				holdingPeriodToForwardW = 0;
//				lossaversion = 0.0;
//				strategy = 0.0;
//				wage = 0.0;
//				wage_reservation = 0.0;
//				general_skill = 0;
//				on_the_job_search = 0;
//				number_applications = 0;
//				last_labour_income = 0.0;
//				specific_skill = 0.0;
//				employee_firm_id = 0;
//				employer_region_id = 0;
//				day_of_month_receive_benefit = 0;
//				unemployment_benefit_pct = 0.0;
//				no_regions = 0;
////////////				productivity = 0.0;
//				capital_good_price = 0.0;
//				net_profit = 0.0;
//				outstanding_shares = 0;
//				cum_revenues = 0.0;
//				switch_datastorage = 0;
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
////////				total_earnings = 0.0;
//				total_equity = 0.0;
//				average_debt_earnings_ratio = 0.0;
//				average_debt_equity_ratio = 0.0;
//				labour_share_ratio = 0.0;
//				cpi = 0.0;
//				gdp = 0.0;
//				monthly_sold_quantity = 0.0;
//				monthly_output = 0.0;
//				monthly_revenue = 0.0;
//				monthly_planned_output = 0.0;
//////////////				no_firm_births = 0;
//				no_firm_deaths = 0;
//////////				firm_birth_rate = 0.0;
//				firm_death_rate = 0.0;
//////////				max_firm_creation = 0;
//				recession_started = 0;
//				recession_duration = 0;
////////////////				cash = 0.0;
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
////////				deficit = 0.0;
//				money_financing_fraction = 0.0;
//				gdp_fraction_consumption = 0.0;
//				gdp_fraction_investment = 0.0;
//				monthly_tax_revenues = 0.0;
//				yearly_tax_revenues = 0.0;
//				monthly_unemployment_benefit_payment = 0.0;
//				yearly_unemployment_benefit_payment = 0.0;
//				hh_transfer_payment = 0.0;
//				firm_transfer_payment = 0.0;
//				monthly_transfer_payment = 0.0;
//				yearly_transfer_payment = 0.0;
//				hh_subsidy_payment = 0.0;
//				firm_subsidy_payment = 0.0;
//				monthly_subsidy_payment = 0.0;
//				yearly_subsidy_payment = 0.0;
//				monthly_bond_coupon_payment = 0.0;
//				yearly_bond_coupon_payment = 0.0;
//				gov_interest_rate = 0.0;
//				yearly_investment_expenditure = 0.0;
//				yearly_consumption_expenditure = 0.0;
//				yearly_income = 0.0;
//				yearly_expenditure = 0.0;
//				yearly_budget_balance = 0.0;
//				total_money_financing = 0.0;
//				total_bond_financing = 0.0;
//				country_wide_mean_wage = 0.0;
//				num_unemployed = 0;
//				gdp_growth = 0.0;
//				gdp_forecast = 0.0;
//				yearly_income_forecast = 0.0;
//				yearly_expenditure_budget = 0.0;
//				budget_balance_forecast = 0.0;
//				monthly_consumption_expenditure = 0.0;
//				monthly_investment_expenditure = 0.0;
//				monthly_budget_balance = 0.0;
//				monthly_consumption_budget = 0.0;
//				monthly_investment_budget = 0.0;
//				monthly_income = 0.0;
//				monthly_expenditure = 0.0;
//				yearly_consumption_budget = 0.0;
//				yearly_investment_budget = 0.0;
//
	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "region_id") == 0) in_region_id = 1;
			if(strcmp(buffer, "/region_id") == 0) in_region_id = 0;
			if(strcmp(buffer, "gov_id") == 0) in_gov_id = 1;
			if(strcmp(buffer, "/gov_id") == 0) in_gov_id = 0;
			if(strcmp(buffer, "day_of_month_to_act") == 0) in_day_of_month_to_act = 1;
			if(strcmp(buffer, "/day_of_month_to_act") == 0) in_day_of_month_to_act = 0;
			if(strcmp(buffer, "last_day_of_month_to_act") == 0) in_last_day_of_month_to_act = 1;
			if(strcmp(buffer, "/last_day_of_month_to_act") == 0) in_last_day_of_month_to_act = 0;
			if(strcmp(buffer, "payment_account") == 0) in_payment_account = 1;
			if(strcmp(buffer, "/payment_account") == 0) in_payment_account = 0;
			if(strcmp(buffer, "bank_id") == 0) in_bank_id = 1;
			if(strcmp(buffer, "/bank_id") == 0) in_bank_id = 0;
			if(strcmp(buffer, "mean_wage") == 0) in_mean_wage = 1;
			if(strcmp(buffer, "/mean_wage") == 0) in_mean_wage = 0;
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
			if(strcmp(buffer, "planned_output") == 0) in_planned_output = 1;
			if(strcmp(buffer, "/planned_output") == 0) in_planned_output = 0;
			if(strcmp(buffer, "output") == 0) in_output = 1;
			if(strcmp(buffer, "/output") == 0) in_output = 0;
			if(strcmp(buffer, "unit_costs") == 0) in_unit_costs = 1;
			if(strcmp(buffer, "/unit_costs") == 0) in_unit_costs = 0;
			if(strcmp(buffer, "total_supply") == 0) in_total_supply = 1;
			if(strcmp(buffer, "/total_supply") == 0) in_total_supply = 0;
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
			if(strcmp(buffer, "total_external_financing_obtained") == 0) in_total_external_financing_obtained = 1;
			if(strcmp(buffer, "/total_external_financing_obtained") == 0) in_total_external_financing_obtained = 0;
			if(strcmp(buffer, "capital_costs") == 0) in_capital_costs = 1;
			if(strcmp(buffer, "/capital_costs") == 0) in_capital_costs = 0;
			if(strcmp(buffer, "labour_costs") == 0) in_labour_costs = 1;
			if(strcmp(buffer, "/labour_costs") == 0) in_labour_costs = 0;
			if(strcmp(buffer, "capital_financing") == 0) in_capital_financing = 1;
			if(strcmp(buffer, "/capital_financing") == 0) in_capital_financing = 0;
			if(strcmp(buffer, "financial_resources_for_production") == 0) in_financial_resources_for_production = 1;
			if(strcmp(buffer, "/financial_resources_for_production") == 0) in_financial_resources_for_production = 0;
			if(strcmp(buffer, "planned_value_capital_stock") == 0) in_planned_value_capital_stock = 1;
			if(strcmp(buffer, "/planned_value_capital_stock") == 0) in_planned_value_capital_stock = 0;
			if(strcmp(buffer, "total_units_local_inventory") == 0) in_total_units_local_inventory = 1;
			if(strcmp(buffer, "/total_units_local_inventory") == 0) in_total_units_local_inventory = 0;
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
			if(strcmp(buffer, "earnings_per_share") == 0) in_earnings_per_share = 1;
			if(strcmp(buffer, "/earnings_per_share") == 0) in_earnings_per_share = 0;
			if(strcmp(buffer, "total_payments") == 0) in_total_payments = 1;
			if(strcmp(buffer, "/total_payments") == 0) in_total_payments = 0;
			if(strcmp(buffer, "total_interest_payments") == 0) in_total_interest_payments = 1;
			if(strcmp(buffer, "/total_interest_payments") == 0) in_total_interest_payments = 0;
			if(strcmp(buffer, "previous_shares_outstanding") == 0) in_previous_shares_outstanding = 1;
			if(strcmp(buffer, "/previous_shares_outstanding") == 0) in_previous_shares_outstanding = 0;
			if(strcmp(buffer, "earnings_payout") == 0) in_earnings_payout = 1;
			if(strcmp(buffer, "/earnings_payout") == 0) in_earnings_payout = 0;
			if(strcmp(buffer, "current_shares_outstanding") == 0) in_current_shares_outstanding = 1;
			if(strcmp(buffer, "/current_shares_outstanding") == 0) in_current_shares_outstanding = 0;
			if(strcmp(buffer, "stock") == 0) in_stock = 1;
			if(strcmp(buffer, "/stock") == 0) in_stock = 0;
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
			if(strcmp(buffer, "age") == 0) in_age = 1;
			if(strcmp(buffer, "/age") == 0) in_age = 0;
			if(strcmp(buffer, "transfer_payment") == 0) in_transfer_payment = 1;
			if(strcmp(buffer, "/transfer_payment") == 0) in_transfer_payment = 0;
			if(strcmp(buffer, "subsidy_payment") == 0) in_subsidy_payment = 1;
			if(strcmp(buffer, "/subsidy_payment") == 0) in_subsidy_payment = 0;
			if(strcmp(buffer, "active") == 0) in_active = 1;
			if(strcmp(buffer, "/active") == 0) in_active = 0;
			if(strcmp(buffer, "bankruptcy_idle_counter") == 0) in_bankruptcy_idle_counter = 1;
			if(strcmp(buffer, "/bankruptcy_idle_counter") == 0) in_bankruptcy_idle_counter = 0;
			if(strcmp(buffer, "bankruptcy_state") == 0) in_bankruptcy_state = 1;
			if(strcmp(buffer, "/bankruptcy_state") == 0) in_bankruptcy_state = 0;
			if(strcmp(buffer, "bankruptcy_insolvency_state") == 0) in_bankruptcy_insolvency_state = 1;
			if(strcmp(buffer, "/bankruptcy_insolvency_state") == 0) in_bankruptcy_insolvency_state = 0;
			if(strcmp(buffer, "bankruptcy_illiquidity_state") == 0) in_bankruptcy_illiquidity_state = 1;
			if(strcmp(buffer, "/bankruptcy_illiquidity_state") == 0) in_bankruptcy_illiquidity_state = 0;
			if(strcmp(buffer, "financial_crisis_state") == 0) in_financial_crisis_state = 1;
			if(strcmp(buffer, "/financial_crisis_state") == 0) in_financial_crisis_state = 0;
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
			if(strcmp(buffer, "price_index") == 0) in_price_index = 1;
			if(strcmp(buffer, "/price_index") == 0) in_price_index = 0;
			if(strcmp(buffer, "price_index_base_period") == 0) in_price_index_base_period = 1;
			if(strcmp(buffer, "/price_index_base_period") == 0) in_price_index_base_period = 0;
			if(strcmp(buffer, "commuting_costs_price_level_weight") == 0) in_commuting_costs_price_level_weight = 1;
			if(strcmp(buffer, "/commuting_costs_price_level_weight") == 0) in_commuting_costs_price_level_weight = 0;
			if(strcmp(buffer, "last_income") == 0) in_last_income = 1;
			if(strcmp(buffer, "/last_income") == 0) in_last_income = 0;
			if(strcmp(buffer, "expenditures") == 0) in_expenditures = 1;
			if(strcmp(buffer, "/expenditures") == 0) in_expenditures = 0;
			if(strcmp(buffer, "received_dividend") == 0) in_received_dividend = 1;
			if(strcmp(buffer, "/received_dividend") == 0) in_received_dividend = 0;
			if(strcmp(buffer, "wealth") == 0) in_wealth = 1;
			if(strcmp(buffer, "/wealth") == 0) in_wealth = 0;
			if(strcmp(buffer, "beliefs") == 0) in_beliefs = 1;
			if(strcmp(buffer, "/beliefs") == 0) in_beliefs = 0;
			if(strcmp(buffer, "pendingOrders") == 0) in_pendingOrders = 1;
			if(strcmp(buffer, "/pendingOrders") == 0) in_pendingOrders = 0;
			if(strcmp(buffer, "assetsowned") == 0) in_assetsowned = 1;
			if(strcmp(buffer, "/assetsowned") == 0) in_assetsowned = 0;
			if(strcmp(buffer, "assetWeights") == 0) in_assetWeights = 1;
			if(strcmp(buffer, "/assetWeights") == 0) in_assetWeights = 0;
			if(strcmp(buffer, "assetUtilities") == 0) in_assetUtilities = 1;
			if(strcmp(buffer, "/assetUtilities") == 0) in_assetUtilities = 0;
			if(strcmp(buffer, "cash_on_hand") == 0) in_cash_on_hand = 1;
			if(strcmp(buffer, "/cash_on_hand") == 0) in_cash_on_hand = 0;
			if(strcmp(buffer, "forwardWindow") == 0) in_forwardWindow = 1;
			if(strcmp(buffer, "/forwardWindow") == 0) in_forwardWindow = 0;
			if(strcmp(buffer, "backwardWindow") == 0) in_backwardWindow = 1;
			if(strcmp(buffer, "/backwardWindow") == 0) in_backwardWindow = 0;
			if(strcmp(buffer, "bins") == 0) in_bins = 1;
			if(strcmp(buffer, "/bins") == 0) in_bins = 0;
			if(strcmp(buffer, "randomWeight") == 0) in_randomWeight = 1;
			if(strcmp(buffer, "/randomWeight") == 0) in_randomWeight = 0;
			if(strcmp(buffer, "fundamentalWeight") == 0) in_fundamentalWeight = 1;
			if(strcmp(buffer, "/fundamentalWeight") == 0) in_fundamentalWeight = 0;
			if(strcmp(buffer, "chartistWeight") == 0) in_chartistWeight = 1;
			if(strcmp(buffer, "/chartistWeight") == 0) in_chartistWeight = 0;
			if(strcmp(buffer, "holdingPeriodToForwardW") == 0) in_holdingPeriodToForwardW = 1;
			if(strcmp(buffer, "/holdingPeriodToForwardW") == 0) in_holdingPeriodToForwardW = 0;
			if(strcmp(buffer, "lossaversion") == 0) in_lossaversion = 1;
			if(strcmp(buffer, "/lossaversion") == 0) in_lossaversion = 0;
			if(strcmp(buffer, "strategy") == 0) in_strategy = 1;
			if(strcmp(buffer, "/strategy") == 0) in_strategy = 0;
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
			if(strcmp(buffer, "last_labour_income") == 0) in_last_labour_income = 1;
			if(strcmp(buffer, "/last_labour_income") == 0) in_last_labour_income = 0;
			if(strcmp(buffer, "specific_skill") == 0) in_specific_skill = 1;
			if(strcmp(buffer, "/specific_skill") == 0) in_specific_skill = 0;
			if(strcmp(buffer, "employee_firm_id") == 0) in_employee_firm_id = 1;
			if(strcmp(buffer, "/employee_firm_id") == 0) in_employee_firm_id = 0;
			if(strcmp(buffer, "employer_region_id") == 0) in_employer_region_id = 1;
			if(strcmp(buffer, "/employer_region_id") == 0) in_employer_region_id = 0;
			if(strcmp(buffer, "day_of_month_receive_benefit") == 0) in_day_of_month_receive_benefit = 1;
			if(strcmp(buffer, "/day_of_month_receive_benefit") == 0) in_day_of_month_receive_benefit = 0;
			if(strcmp(buffer, "unemployment_benefit_pct") == 0) in_unemployment_benefit_pct = 1;
			if(strcmp(buffer, "/unemployment_benefit_pct") == 0) in_unemployment_benefit_pct = 0;
			if(strcmp(buffer, "no_regions") == 0) in_no_regions = 1;
			if(strcmp(buffer, "/no_regions") == 0) in_no_regions = 0;
			if(strcmp(buffer, "current_stock") == 0) in_current_stock = 1;
			if(strcmp(buffer, "/current_stock") == 0) in_current_stock = 0;
			if(strcmp(buffer, "firm_revenues") == 0) in_firm_revenues = 1;
			if(strcmp(buffer, "/firm_revenues") == 0) in_firm_revenues = 0;
			if(strcmp(buffer, "export_volume_matrix") == 0) in_export_volume_matrix = 1;
			if(strcmp(buffer, "/export_volume_matrix") == 0) in_export_volume_matrix = 0;
			if(strcmp(buffer, "export_value_matrix") == 0) in_export_value_matrix = 1;
			if(strcmp(buffer, "/export_value_matrix") == 0) in_export_value_matrix = 0;
			if(strcmp(buffer, "export_previous_value_matrix") == 0) in_export_previous_value_matrix = 1;
			if(strcmp(buffer, "/export_previous_value_matrix") == 0) in_export_previous_value_matrix = 0;
			if(strcmp(buffer, "productivity") == 0) in_productivity = 1;
			if(strcmp(buffer, "/productivity") == 0) in_productivity = 0;
			if(strcmp(buffer, "capital_good_price") == 0) in_capital_good_price = 1;
			if(strcmp(buffer, "/capital_good_price") == 0) in_capital_good_price = 0;
			if(strcmp(buffer, "net_profit") == 0) in_net_profit = 1;
			if(strcmp(buffer, "/net_profit") == 0) in_net_profit = 0;
			if(strcmp(buffer, "outstanding_shares") == 0) in_outstanding_shares = 1;
			if(strcmp(buffer, "/outstanding_shares") == 0) in_outstanding_shares = 0;
			if(strcmp(buffer, "cum_revenues") == 0) in_cum_revenues = 1;
			if(strcmp(buffer, "/cum_revenues") == 0) in_cum_revenues = 0;
			if(strcmp(buffer, "switch_datastorage") == 0) in_switch_datastorage = 1;
			if(strcmp(buffer, "/switch_datastorage") == 0) in_switch_datastorage = 0;
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
			if(strcmp(buffer, "cpi") == 0) in_cpi = 1;
			if(strcmp(buffer, "/cpi") == 0) in_cpi = 0;
			if(strcmp(buffer, "gdp") == 0) in_gdp = 1;
			if(strcmp(buffer, "/gdp") == 0) in_gdp = 0;
			if(strcmp(buffer, "monthly_sold_quantity") == 0) in_monthly_sold_quantity = 1;
			if(strcmp(buffer, "/monthly_sold_quantity") == 0) in_monthly_sold_quantity = 0;
			if(strcmp(buffer, "monthly_output") == 0) in_monthly_output = 1;
			if(strcmp(buffer, "/monthly_output") == 0) in_monthly_output = 0;
			if(strcmp(buffer, "monthly_revenue") == 0) in_monthly_revenue = 1;
			if(strcmp(buffer, "/monthly_revenue") == 0) in_monthly_revenue = 0;
			if(strcmp(buffer, "monthly_planned_output") == 0) in_monthly_planned_output = 1;
			if(strcmp(buffer, "/monthly_planned_output") == 0) in_monthly_planned_output = 0;
			if(strcmp(buffer, "history_monthly") == 0) in_history_monthly = 1;
			if(strcmp(buffer, "/history_monthly") == 0) in_history_monthly = 0;
			if(strcmp(buffer, "history_quarterly") == 0) in_history_quarterly = 1;
			if(strcmp(buffer, "/history_quarterly") == 0) in_history_quarterly = 0;
			if(strcmp(buffer, "monthly_growth_rates") == 0) in_monthly_growth_rates = 1;
			if(strcmp(buffer, "/monthly_growth_rates") == 0) in_monthly_growth_rates = 0;
			if(strcmp(buffer, "quarterly_growth_rates") == 0) in_quarterly_growth_rates = 1;
			if(strcmp(buffer, "/quarterly_growth_rates") == 0) in_quarterly_growth_rates = 0;
			if(strcmp(buffer, "annual_growth_rates_monthly") == 0) in_annual_growth_rates_monthly = 1;
			if(strcmp(buffer, "/annual_growth_rates_monthly") == 0) in_annual_growth_rates_monthly = 0;
			if(strcmp(buffer, "annual_growth_rates_quarterly") == 0) in_annual_growth_rates_quarterly = 1;
			if(strcmp(buffer, "/annual_growth_rates_quarterly") == 0) in_annual_growth_rates_quarterly = 0;
			if(strcmp(buffer, "no_firm_births") == 0) in_no_firm_births = 1;
			if(strcmp(buffer, "/no_firm_births") == 0) in_no_firm_births = 0;
			if(strcmp(buffer, "no_firm_deaths") == 0) in_no_firm_deaths = 1;
			if(strcmp(buffer, "/no_firm_deaths") == 0) in_no_firm_deaths = 0;
			if(strcmp(buffer, "firm_age_distribution") == 0) in_firm_age_distribution = 1;
			if(strcmp(buffer, "/firm_age_distribution") == 0) in_firm_age_distribution = 0;
			if(strcmp(buffer, "firm_age_distribution_multiperiod") == 0) in_firm_age_distribution_multiperiod = 1;
			if(strcmp(buffer, "/firm_age_distribution_multiperiod") == 0) in_firm_age_distribution_multiperiod = 0;
			if(strcmp(buffer, "firm_age_distribution_1_period_lag") == 0) in_firm_age_distribution_1_period_lag = 1;
			if(strcmp(buffer, "/firm_age_distribution_1_period_lag") == 0) in_firm_age_distribution_1_period_lag = 0;
			if(strcmp(buffer, "firm_age_distribution_2_period_lag") == 0) in_firm_age_distribution_2_period_lag = 1;
			if(strcmp(buffer, "/firm_age_distribution_2_period_lag") == 0) in_firm_age_distribution_2_period_lag = 0;
			if(strcmp(buffer, "firm_birth_rate") == 0) in_firm_birth_rate = 1;
			if(strcmp(buffer, "/firm_birth_rate") == 0) in_firm_birth_rate = 0;
			if(strcmp(buffer, "firm_death_rate") == 0) in_firm_death_rate = 1;
			if(strcmp(buffer, "/firm_death_rate") == 0) in_firm_death_rate = 0;
			if(strcmp(buffer, "survival_rate") == 0) in_survival_rate = 1;
			if(strcmp(buffer, "/survival_rate") == 0) in_survival_rate = 0;
			if(strcmp(buffer, "survival_rate_multiperiod_1") == 0) in_survival_rate_multiperiod_1 = 1;
			if(strcmp(buffer, "/survival_rate_multiperiod_1") == 0) in_survival_rate_multiperiod_1 = 0;
			if(strcmp(buffer, "survival_rate_multiperiod_2") == 0) in_survival_rate_multiperiod_2 = 1;
			if(strcmp(buffer, "/survival_rate_multiperiod_2") == 0) in_survival_rate_multiperiod_2 = 0;
			if(strcmp(buffer, "survival_rate_multiperiod") == 0) in_survival_rate_multiperiod = 1;
			if(strcmp(buffer, "/survival_rate_multiperiod") == 0) in_survival_rate_multiperiod = 0;
			if(strcmp(buffer, "max_firm_creation") == 0) in_max_firm_creation = 1;
			if(strcmp(buffer, "/max_firm_creation") == 0) in_max_firm_creation = 0;
			if(strcmp(buffer, "recession_started") == 0) in_recession_started = 1;
			if(strcmp(buffer, "/recession_started") == 0) in_recession_started = 0;
			if(strcmp(buffer, "recession_duration") == 0) in_recession_duration = 1;
			if(strcmp(buffer, "/recession_duration") == 0) in_recession_duration = 0;
			if(strcmp(buffer, "region_export_volume") == 0) in_region_export_volume = 1;
			if(strcmp(buffer, "/region_export_volume") == 0) in_region_export_volume = 0;
			if(strcmp(buffer, "region_import_volume") == 0) in_region_import_volume = 1;
			if(strcmp(buffer, "/region_import_volume") == 0) in_region_import_volume = 0;
			if(strcmp(buffer, "region_export_value") == 0) in_region_export_value = 1;
			if(strcmp(buffer, "/region_export_value") == 0) in_region_export_value = 0;
			if(strcmp(buffer, "region_import_value") == 0) in_region_import_value = 1;
			if(strcmp(buffer, "/region_import_value") == 0) in_region_import_value = 0;
			if(strcmp(buffer, "region_import_previous_value") == 0) in_region_import_previous_value = 1;
			if(strcmp(buffer, "/region_import_previous_value") == 0) in_region_import_previous_value = 0;
			if(strcmp(buffer, "assets") == 0) in_assets = 1;
			if(strcmp(buffer, "/assets") == 0) in_assets = 0;
			if(strcmp(buffer, "clearingmechanism") == 0) in_clearingmechanism = 1;
			if(strcmp(buffer, "/clearingmechanism") == 0) in_clearingmechanism = 0;
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
			if(strcmp(buffer, "list_of_regions") == 0) in_list_of_regions = 1;
			if(strcmp(buffer, "/list_of_regions") == 0) in_list_of_regions = 0;
			if(strcmp(buffer, "bond") == 0) in_bond = 1;
			if(strcmp(buffer, "/bond") == 0) in_bond = 0;
			if(strcmp(buffer, "pending_order") == 0) in_pending_order = 1;
			if(strcmp(buffer, "/pending_order") == 0) in_pending_order = 0;
			if(strcmp(buffer, "deficit") == 0) in_deficit = 1;
			if(strcmp(buffer, "/deficit") == 0) in_deficit = 0;
			if(strcmp(buffer, "money_financing_fraction") == 0) in_money_financing_fraction = 1;
			if(strcmp(buffer, "/money_financing_fraction") == 0) in_money_financing_fraction = 0;
			if(strcmp(buffer, "gdp_fraction_consumption") == 0) in_gdp_fraction_consumption = 1;
			if(strcmp(buffer, "/gdp_fraction_consumption") == 0) in_gdp_fraction_consumption = 0;
			if(strcmp(buffer, "gdp_fraction_investment") == 0) in_gdp_fraction_investment = 1;
			if(strcmp(buffer, "/gdp_fraction_investment") == 0) in_gdp_fraction_investment = 0;
			if(strcmp(buffer, "monthly_tax_revenues") == 0) in_monthly_tax_revenues = 1;
			if(strcmp(buffer, "/monthly_tax_revenues") == 0) in_monthly_tax_revenues = 0;
			if(strcmp(buffer, "yearly_tax_revenues") == 0) in_yearly_tax_revenues = 1;
			if(strcmp(buffer, "/yearly_tax_revenues") == 0) in_yearly_tax_revenues = 0;
			if(strcmp(buffer, "monthly_unemployment_benefit_payment") == 0) in_monthly_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/monthly_unemployment_benefit_payment") == 0) in_monthly_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "yearly_unemployment_benefit_payment") == 0) in_yearly_unemployment_benefit_payment = 1;
			if(strcmp(buffer, "/yearly_unemployment_benefit_payment") == 0) in_yearly_unemployment_benefit_payment = 0;
			if(strcmp(buffer, "hh_transfer_payment") == 0) in_hh_transfer_payment = 1;
			if(strcmp(buffer, "/hh_transfer_payment") == 0) in_hh_transfer_payment = 0;
			if(strcmp(buffer, "firm_transfer_payment") == 0) in_firm_transfer_payment = 1;
			if(strcmp(buffer, "/firm_transfer_payment") == 0) in_firm_transfer_payment = 0;
			if(strcmp(buffer, "monthly_transfer_payment") == 0) in_monthly_transfer_payment = 1;
			if(strcmp(buffer, "/monthly_transfer_payment") == 0) in_monthly_transfer_payment = 0;
			if(strcmp(buffer, "yearly_transfer_payment") == 0) in_yearly_transfer_payment = 1;
			if(strcmp(buffer, "/yearly_transfer_payment") == 0) in_yearly_transfer_payment = 0;
			if(strcmp(buffer, "hh_subsidy_payment") == 0) in_hh_subsidy_payment = 1;
			if(strcmp(buffer, "/hh_subsidy_payment") == 0) in_hh_subsidy_payment = 0;
			if(strcmp(buffer, "firm_subsidy_payment") == 0) in_firm_subsidy_payment = 1;
			if(strcmp(buffer, "/firm_subsidy_payment") == 0) in_firm_subsidy_payment = 0;
			if(strcmp(buffer, "monthly_subsidy_payment") == 0) in_monthly_subsidy_payment = 1;
			if(strcmp(buffer, "/monthly_subsidy_payment") == 0) in_monthly_subsidy_payment = 0;
			if(strcmp(buffer, "yearly_subsidy_payment") == 0) in_yearly_subsidy_payment = 1;
			if(strcmp(buffer, "/yearly_subsidy_payment") == 0) in_yearly_subsidy_payment = 0;
			if(strcmp(buffer, "monthly_bond_coupon_payment") == 0) in_monthly_bond_coupon_payment = 1;
			if(strcmp(buffer, "/monthly_bond_coupon_payment") == 0) in_monthly_bond_coupon_payment = 0;
			if(strcmp(buffer, "yearly_bond_coupon_payment") == 0) in_yearly_bond_coupon_payment = 1;
			if(strcmp(buffer, "/yearly_bond_coupon_payment") == 0) in_yearly_bond_coupon_payment = 0;
			if(strcmp(buffer, "gov_interest_rate") == 0) in_gov_interest_rate = 1;
			if(strcmp(buffer, "/gov_interest_rate") == 0) in_gov_interest_rate = 0;
			if(strcmp(buffer, "yearly_investment_expenditure") == 0) in_yearly_investment_expenditure = 1;
			if(strcmp(buffer, "/yearly_investment_expenditure") == 0) in_yearly_investment_expenditure = 0;
			if(strcmp(buffer, "yearly_consumption_expenditure") == 0) in_yearly_consumption_expenditure = 1;
			if(strcmp(buffer, "/yearly_consumption_expenditure") == 0) in_yearly_consumption_expenditure = 0;
			if(strcmp(buffer, "yearly_income") == 0) in_yearly_income = 1;
			if(strcmp(buffer, "/yearly_income") == 0) in_yearly_income = 0;
			if(strcmp(buffer, "yearly_expenditure") == 0) in_yearly_expenditure = 1;
			if(strcmp(buffer, "/yearly_expenditure") == 0) in_yearly_expenditure = 0;
			if(strcmp(buffer, "yearly_budget_balance") == 0) in_yearly_budget_balance = 1;
			if(strcmp(buffer, "/yearly_budget_balance") == 0) in_yearly_budget_balance = 0;
			if(strcmp(buffer, "total_money_financing") == 0) in_total_money_financing = 1;
			if(strcmp(buffer, "/total_money_financing") == 0) in_total_money_financing = 0;
			if(strcmp(buffer, "total_bond_financing") == 0) in_total_bond_financing = 1;
			if(strcmp(buffer, "/total_bond_financing") == 0) in_total_bond_financing = 0;
			if(strcmp(buffer, "country_wide_mean_wage") == 0) in_country_wide_mean_wage = 1;
			if(strcmp(buffer, "/country_wide_mean_wage") == 0) in_country_wide_mean_wage = 0;
			if(strcmp(buffer, "num_unemployed") == 0) in_num_unemployed = 1;
			if(strcmp(buffer, "/num_unemployed") == 0) in_num_unemployed = 0;
			if(strcmp(buffer, "gdp_growth") == 0) in_gdp_growth = 1;
			if(strcmp(buffer, "/gdp_growth") == 0) in_gdp_growth = 0;
			if(strcmp(buffer, "gdp_forecast") == 0) in_gdp_forecast = 1;
			if(strcmp(buffer, "/gdp_forecast") == 0) in_gdp_forecast = 0;
			if(strcmp(buffer, "yearly_income_forecast") == 0) in_yearly_income_forecast = 1;
			if(strcmp(buffer, "/yearly_income_forecast") == 0) in_yearly_income_forecast = 0;
			if(strcmp(buffer, "yearly_expenditure_budget") == 0) in_yearly_expenditure_budget = 1;
			if(strcmp(buffer, "/yearly_expenditure_budget") == 0) in_yearly_expenditure_budget = 0;
			if(strcmp(buffer, "budget_balance_forecast") == 0) in_budget_balance_forecast = 1;
			if(strcmp(buffer, "/budget_balance_forecast") == 0) in_budget_balance_forecast = 0;
			if(strcmp(buffer, "monthly_consumption_expenditure") == 0) in_monthly_consumption_expenditure = 1;
			if(strcmp(buffer, "/monthly_consumption_expenditure") == 0) in_monthly_consumption_expenditure = 0;
			if(strcmp(buffer, "monthly_investment_expenditure") == 0) in_monthly_investment_expenditure = 1;
			if(strcmp(buffer, "/monthly_investment_expenditure") == 0) in_monthly_investment_expenditure = 0;
			if(strcmp(buffer, "monthly_budget_balance") == 0) in_monthly_budget_balance = 1;
			if(strcmp(buffer, "/monthly_budget_balance") == 0) in_monthly_budget_balance = 0;
			if(strcmp(buffer, "monthly_consumption_budget") == 0) in_monthly_consumption_budget = 1;
			if(strcmp(buffer, "/monthly_consumption_budget") == 0) in_monthly_consumption_budget = 0;
			if(strcmp(buffer, "monthly_investment_budget") == 0) in_monthly_investment_budget = 1;
			if(strcmp(buffer, "/monthly_investment_budget") == 0) in_monthly_investment_budget = 0;
			if(strcmp(buffer, "monthly_income") == 0) in_monthly_income = 1;
			if(strcmp(buffer, "/monthly_income") == 0) in_monthly_income = 0;
			if(strcmp(buffer, "monthly_expenditure") == 0) in_monthly_expenditure = 1;
			if(strcmp(buffer, "/monthly_expenditure") == 0) in_monthly_expenditure = 0;
			if(strcmp(buffer, "yearly_consumption_budget") == 0) in_yearly_consumption_budget = 1;
			if(strcmp(buffer, "/yearly_consumption_budget") == 0) in_yearly_consumption_budget = 0;
			if(strcmp(buffer, "yearly_investment_budget") == 0) in_yearly_investment_budget = 1;
			if(strcmp(buffer, "/yearly_investment_budget") == 0) in_yearly_investment_budget = 0;
			if(strcmp(buffer, "accounts") == 0) in_accounts = 1;
			if(strcmp(buffer, "/accounts") == 0) in_accounts = 0;

			if(strcmp(buffer, "print_log") == 0) in_print_log = 1;
			if(strcmp(buffer, "/print_log") == 0) in_print_log = 0;
			if(strcmp(buffer, "print_debug") == 0) in_print_debug = 1;
			if(strcmp(buffer, "/print_debug") == 0) in_print_debug = 0;
			if(strcmp(buffer, "day") == 0) in_day = 1;
			if(strcmp(buffer, "/day") == 0) in_day = 0;
			if(strcmp(buffer, "week") == 0) in_week = 1;
			if(strcmp(buffer, "/week") == 0) in_week = 0;
			if(strcmp(buffer, "month") == 0) in_month = 1;
			if(strcmp(buffer, "/month") == 0) in_month = 0;
			if(strcmp(buffer, "quarter") == 0) in_quarter = 1;
			if(strcmp(buffer, "/quarter") == 0) in_quarter = 0;
			if(strcmp(buffer, "year") == 0) in_year = 1;
			if(strcmp(buffer, "/year") == 0) in_year = 0;
			if(strcmp(buffer, "number_of_banks_to_apply") == 0) in_number_of_banks_to_apply = 1;
			if(strcmp(buffer, "/number_of_banks_to_apply") == 0) in_number_of_banks_to_apply = 0;
			if(strcmp(buffer, "gamma_const") == 0) in_gamma_const = 1;
			if(strcmp(buffer, "/gamma_const") == 0) in_gamma_const = 0;
			if(strcmp(buffer, "alpha") == 0) in_alpha = 1;
			if(strcmp(buffer, "/alpha") == 0) in_alpha = 0;
			if(strcmp(buffer, "beta") == 0) in_beta = 1;
			if(strcmp(buffer, "/beta") == 0) in_beta = 0;
			if(strcmp(buffer, "depreciation_rate") == 0) in_depreciation_rate = 1;
			if(strcmp(buffer, "/depreciation_rate") == 0) in_depreciation_rate = 0;
			if(strcmp(buffer, "discount_rate") == 0) in_discount_rate = 1;
			if(strcmp(buffer, "/discount_rate") == 0) in_discount_rate = 0;
			if(strcmp(buffer, "teta") == 0) in_teta = 1;
			if(strcmp(buffer, "/teta") == 0) in_teta = 0;
			if(strcmp(buffer, "mark_up") == 0) in_mark_up = 1;
			if(strcmp(buffer, "/mark_up") == 0) in_mark_up = 0;
			if(strcmp(buffer, "lambda") == 0) in_lambda = 1;
			if(strcmp(buffer, "/lambda") == 0) in_lambda = 0;
			if(strcmp(buffer, "wage_update") == 0) in_wage_update = 1;
			if(strcmp(buffer, "/wage_update") == 0) in_wage_update = 0;
			if(strcmp(buffer, "min_vacancy") == 0) in_min_vacancy = 1;
			if(strcmp(buffer, "/min_vacancy") == 0) in_min_vacancy = 0;
			if(strcmp(buffer, "wage_reservation_update") == 0) in_wage_reservation_update = 1;
			if(strcmp(buffer, "/wage_reservation_update") == 0) in_wage_reservation_update = 0;
			if(strcmp(buffer, "region_cost") == 0) in_region_cost = 1;
			if(strcmp(buffer, "/region_cost") == 0) in_region_cost = 0;
			if(strcmp(buffer, "inventory_costs_per_unit") == 0) in_inventory_costs_per_unit = 1;
			if(strcmp(buffer, "/inventory_costs_per_unit") == 0) in_inventory_costs_per_unit = 0;
			if(strcmp(buffer, "on_the_job_search_rate") == 0) in_on_the_job_search_rate = 1;
			if(strcmp(buffer, "/on_the_job_search_rate") == 0) in_on_the_job_search_rate = 0;
			if(strcmp(buffer, "initial_consumption_propensity") == 0) in_initial_consumption_propensity = 1;
			if(strcmp(buffer, "/initial_consumption_propensity") == 0) in_initial_consumption_propensity = 0;
			if(strcmp(buffer, "consumption_propensity") == 0) in_consumption_propensity = 1;
			if(strcmp(buffer, "/consumption_propensity") == 0) in_consumption_propensity = 0;
			if(strcmp(buffer, "firm_planning_horizon") == 0) in_firm_planning_horizon = 1;
			if(strcmp(buffer, "/firm_planning_horizon") == 0) in_firm_planning_horizon = 0;
			if(strcmp(buffer, "inv_inertia") == 0) in_inv_inertia = 1;
			if(strcmp(buffer, "/inv_inertia") == 0) in_inv_inertia = 0;
			if(strcmp(buffer, "adaption_delivery_volume") == 0) in_adaption_delivery_volume = 1;
			if(strcmp(buffer, "/adaption_delivery_volume") == 0) in_adaption_delivery_volume = 0;
			if(strcmp(buffer, "periods_to_repay_loans") == 0) in_periods_to_repay_loans = 1;
			if(strcmp(buffer, "/periods_to_repay_loans") == 0) in_periods_to_repay_loans = 0;
			if(strcmp(buffer, "delivery_prob_if_critical_stock_0") == 0) in_delivery_prob_if_critical_stock_0 = 1;
			if(strcmp(buffer, "/delivery_prob_if_critical_stock_0") == 0) in_delivery_prob_if_critical_stock_0 = 0;
			if(strcmp(buffer, "innovation_probability") == 0) in_innovation_probability = 1;
			if(strcmp(buffer, "/innovation_probability") == 0) in_innovation_probability = 0;
			if(strcmp(buffer, "productivity_progress") == 0) in_productivity_progress = 1;
			if(strcmp(buffer, "/productivity_progress") == 0) in_productivity_progress = 0;
			if(strcmp(buffer, "const_bankruptcy_idle_period") == 0) in_const_bankruptcy_idle_period = 1;
			if(strcmp(buffer, "/const_bankruptcy_idle_period") == 0) in_const_bankruptcy_idle_period = 0;
			if(strcmp(buffer, "debt_rescaling_factor") == 0) in_debt_rescaling_factor = 1;
			if(strcmp(buffer, "/debt_rescaling_factor") == 0) in_debt_rescaling_factor = 0;
			if(strcmp(buffer, "target_leverage_ratio") == 0) in_target_leverage_ratio = 1;
			if(strcmp(buffer, "/target_leverage_ratio") == 0) in_target_leverage_ratio = 0;
			if(strcmp(buffer, "target_liquidity_ratio") == 0) in_target_liquidity_ratio = 1;
			if(strcmp(buffer, "/target_liquidity_ratio") == 0) in_target_liquidity_ratio = 0;
			if(strcmp(buffer, "trading_activity") == 0) in_trading_activity = 1;
			if(strcmp(buffer, "/trading_activity") == 0) in_trading_activity = 0;
			if(strcmp(buffer, "BONDS_NEWISSUE_DISCOUNT") == 0) in_BONDS_NEWISSUE_DISCOUNT = 1;
			if(strcmp(buffer, "/BONDS_NEWISSUE_DISCOUNT") == 0) in_BONDS_NEWISSUE_DISCOUNT = 0;
			if(strcmp(buffer, "gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 1;
			if(strcmp(buffer, "/gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 0;
			if(strcmp(buffer, "gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 1;
			if(strcmp(buffer, "/gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 0;

			
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
				if(in_print_log) print_log = atoi(buffer);
				if(in_print_debug) print_debug = atoi(buffer);
				if(in_day) day = atoi(buffer);
				if(in_week) week = atoi(buffer);
				if(in_month) month = atoi(buffer);
				if(in_quarter) quarter = atoi(buffer);
				if(in_year) year = atoi(buffer);
				if(in_number_of_banks_to_apply) number_of_banks_to_apply = atoi(buffer);
				if(in_gamma_const) gamma_const = atoi(buffer);
				if(in_alpha) alpha = atof(buffer);
				if(in_beta) beta = atof(buffer);
				if(in_depreciation_rate) depreciation_rate = atof(buffer);
				if(in_discount_rate) discount_rate = atof(buffer);
				if(in_teta) teta = atof(buffer);
				if(in_mark_up) mark_up = atof(buffer);
				if(in_lambda) lambda = atof(buffer);
				if(in_wage_update) wage_update = atof(buffer);
				if(in_min_vacancy) min_vacancy = atoi(buffer);
				if(in_wage_reservation_update) wage_reservation_update = atof(buffer);
				if(in_region_cost) region_cost = atof(buffer);
				if(in_inventory_costs_per_unit) inventory_costs_per_unit = atoi(buffer);
				if(in_on_the_job_search_rate) on_the_job_search_rate = atof(buffer);
				if(in_initial_consumption_propensity) initial_consumption_propensity = atof(buffer);
				if(in_consumption_propensity) consumption_propensity = atof(buffer);
				if(in_firm_planning_horizon) firm_planning_horizon = atoi(buffer);
				if(in_inv_inertia) inv_inertia = atoi(buffer);
				if(in_adaption_delivery_volume) adaption_delivery_volume = atof(buffer);
				if(in_periods_to_repay_loans) periods_to_repay_loans = atoi(buffer);
				if(in_delivery_prob_if_critical_stock_0) delivery_prob_if_critical_stock_0 = atoi(buffer);
				if(in_innovation_probability) innovation_probability = atoi(buffer);
				if(in_productivity_progress) productivity_progress = atof(buffer);
				if(in_const_bankruptcy_idle_period) const_bankruptcy_idle_period = atoi(buffer);
				if(in_debt_rescaling_factor) debt_rescaling_factor = atof(buffer);
				if(in_target_leverage_ratio) target_leverage_ratio = atof(buffer);
				if(in_target_liquidity_ratio) target_liquidity_ratio = atof(buffer);
				if(in_trading_activity) trading_activity = atof(buffer);
				if(in_BONDS_NEWISSUE_DISCOUNT) BONDS_NEWISSUE_DISCOUNT = atof(buffer);
				if(in_gov_policy_unemployment_benefit_pct) gov_policy_unemployment_benefit_pct = atof(buffer);
				if(in_gov_policy_money_financing_fraction) gov_policy_money_financing_fraction = atof(buffer);
				if(in_gov_policy_gdp_fraction_consumption) gov_policy_gdp_fraction_consumption = atof(buffer);
				if(in_gov_policy_gdp_fraction_investment) gov_policy_gdp_fraction_investment = atof(buffer);
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_region_id) current_Firm_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Firm_agent->gov_id = atoi(buffer);
				if(in_day_of_month_to_act) current_Firm_agent->day_of_month_to_act = atoi(buffer);
				if(in_last_day_of_month_to_act) current_Firm_agent->last_day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_Firm_agent->payment_account = atof(buffer);
				if(in_bank_id) current_Firm_agent->bank_id = atoi(buffer);
				if(in_mean_wage) current_Firm_agent->mean_wage = atof(buffer);
				if(in_needed_capital_stock) current_Firm_agent->needed_capital_stock = atof(buffer);
				if(in_actual_cap_price) current_Firm_agent->actual_cap_price = atof(buffer);
				if(in_mean_specific_skills) current_Firm_agent->mean_specific_skills = atof(buffer);
				if(in_planned_production_quantity) current_Firm_agent->planned_production_quantity = atof(buffer);
				if(in_production_quantity) current_Firm_agent->production_quantity = atof(buffer);
				if(in_planned_output) current_Firm_agent->planned_output = atof(buffer);
				if(in_output) current_Firm_agent->output = atof(buffer);
				if(in_unit_costs) current_Firm_agent->unit_costs = atof(buffer);
				if(in_total_supply) current_Firm_agent->total_supply = atof(buffer);
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
				if(in_total_external_financing_obtained) current_Firm_agent->total_external_financing_obtained = atof(buffer);
				if(in_capital_costs) current_Firm_agent->capital_costs = atof(buffer);
				if(in_labour_costs) current_Firm_agent->labour_costs = atof(buffer);
				if(in_capital_financing) read_financing_capital_dynamic_array(buffer, &j, &current_Firm_agent->capital_financing);
				if(in_financial_resources_for_production) current_Firm_agent->financial_resources_for_production = atof(buffer);
				if(in_planned_value_capital_stock) current_Firm_agent->planned_value_capital_stock = atof(buffer);
				if(in_total_units_local_inventory) current_Firm_agent->total_units_local_inventory = atof(buffer);
				if(in_dmarketmatrix) read_int_static_array(buffer, &j, current_Firm_agent->dmarketmatrix, 10);
				if(in_residual_var) read_residual_var_datatype_static_array(buffer, &j, current_Firm_agent->residual_var, 10);
				if(in_ebit) current_Firm_agent->ebit = atof(buffer);
				if(in_earnings) current_Firm_agent->earnings = atof(buffer);
				if(in_tax_rate_corporate) current_Firm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_vat) current_Firm_agent->tax_rate_vat = atof(buffer);
				if(in_tax_payment) current_Firm_agent->tax_payment = atof(buffer);
				if(in_net_earnings) current_Firm_agent->net_earnings = atof(buffer);
				if(in_previous_net_earnings) current_Firm_agent->previous_net_earnings = atof(buffer);
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
				if(in_earnings_per_share) current_Firm_agent->earnings_per_share = atof(buffer);
				if(in_total_payments) current_Firm_agent->total_payments = atof(buffer);
				if(in_total_interest_payments) current_Firm_agent->total_interest_payments = atof(buffer);
				if(in_previous_shares_outstanding) current_Firm_agent->previous_shares_outstanding = atof(buffer);
				if(in_earnings_payout) current_Firm_agent->earnings_payout = atof(buffer);
				if(in_current_shares_outstanding) current_Firm_agent->current_shares_outstanding = atof(buffer);
				if(in_stock) read_Stock(buffer, &j, &current_Firm_agent->stock);
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
				if(in_age) current_Firm_agent->age = atoi(buffer);
				if(in_transfer_payment) current_Firm_agent->transfer_payment = atof(buffer);
				if(in_subsidy_payment) current_Firm_agent->subsidy_payment = atof(buffer);
				if(in_active) current_Firm_agent->active = atoi(buffer);
				if(in_bankruptcy_idle_counter) current_Firm_agent->bankruptcy_idle_counter = atoi(buffer);
				if(in_bankruptcy_state) current_Firm_agent->bankruptcy_state = atoi(buffer);
				if(in_bankruptcy_insolvency_state) current_Firm_agent->bankruptcy_insolvency_state = atoi(buffer);
				if(in_bankruptcy_illiquidity_state) current_Firm_agent->bankruptcy_illiquidity_state = atoi(buffer);
				if(in_financial_crisis_state) current_Firm_agent->financial_crisis_state = atoi(buffer);
			}
			else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_region_id) current_Household_agent->region_id = atoi(buffer);
				if(in_neighboring_region_ids) read_int_dynamic_array(buffer, &j, &current_Household_agent->neighboring_region_ids);
				if(in_gov_id) current_Household_agent->gov_id = atoi(buffer);
				if(in_day_of_month_to_act) current_Household_agent->day_of_month_to_act = atoi(buffer);
				if(in_payment_account) current_Household_agent->payment_account = atof(buffer);
				if(in_bank_id) current_Household_agent->bank_id = atoi(buffer);
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
				if(in_price_index) current_Household_agent->price_index = atof(buffer);
				if(in_price_index_base_period) current_Household_agent->price_index_base_period = atof(buffer);
				if(in_commuting_costs_price_level_weight) current_Household_agent->commuting_costs_price_level_weight = atof(buffer);
				if(in_last_income) read_double_dynamic_array(buffer, &j, &current_Household_agent->last_income);
				if(in_expenditures) current_Household_agent->expenditures = atof(buffer);
				if(in_received_dividend) current_Household_agent->received_dividend = atof(buffer);
				if(in_wealth) current_Household_agent->wealth = atof(buffer);
				if(in_beliefs) read_Belief_dynamic_array(buffer, &j, &current_Household_agent->beliefs);
				if(in_pendingOrders) read_Order_dynamic_array(buffer, &j, &current_Household_agent->pendingOrders);
				if(in_assetsowned) read_Asset_dynamic_array(buffer, &j, &current_Household_agent->assetsowned);
				if(in_assetWeights) read_double_dynamic_array(buffer, &j, &current_Household_agent->assetWeights);
				if(in_assetUtilities) read_double_dynamic_array(buffer, &j, &current_Household_agent->assetUtilities);
				if(in_cash_on_hand) current_Household_agent->cash_on_hand = atof(buffer);
				if(in_forwardWindow) current_Household_agent->forwardWindow = atoi(buffer);
				if(in_backwardWindow) current_Household_agent->backwardWindow = atoi(buffer);
				if(in_bins) current_Household_agent->bins = atoi(buffer);
				if(in_randomWeight) current_Household_agent->randomWeight = atof(buffer);
				if(in_fundamentalWeight) current_Household_agent->fundamentalWeight = atof(buffer);
				if(in_chartistWeight) current_Household_agent->chartistWeight = atof(buffer);
				if(in_holdingPeriodToForwardW) current_Household_agent->holdingPeriodToForwardW = atoi(buffer);
				if(in_lossaversion) current_Household_agent->lossaversion = atof(buffer);
				if(in_strategy) current_Household_agent->strategy = atof(buffer);
				if(in_wage) current_Household_agent->wage = atof(buffer);
				if(in_wage_reservation) current_Household_agent->wage_reservation = atof(buffer);
				if(in_general_skill) current_Household_agent->general_skill = atoi(buffer);
				if(in_on_the_job_search) current_Household_agent->on_the_job_search = atoi(buffer);
				if(in_number_applications) current_Household_agent->number_applications = atoi(buffer);
				if(in_last_labour_income) current_Household_agent->last_labour_income = atof(buffer);
				if(in_specific_skill) current_Household_agent->specific_skill = atof(buffer);
				if(in_employee_firm_id) current_Household_agent->employee_firm_id = atoi(buffer);
				if(in_employer_region_id) current_Household_agent->employer_region_id = atoi(buffer);
				if(in_day_of_month_receive_benefit) current_Household_agent->day_of_month_receive_benefit = atoi(buffer);
				if(in_unemployment_benefit_pct) current_Household_agent->unemployment_benefit_pct = atof(buffer);
				if(in_transfer_payment) current_Household_agent->transfer_payment = atof(buffer);
				if(in_subsidy_payment) current_Household_agent->subsidy_payment = atof(buffer);
			}
			else if(in_Mall_agent == 1)
			{
				if(in_id) current_Mall_agent->id = atoi(buffer);
				if(in_region_id) current_Mall_agent->region_id = atoi(buffer);
				if(in_gov_id) current_Mall_agent->gov_id = atoi(buffer);
				if(in_no_regions) current_Mall_agent->no_regions = atoi(buffer);
				if(in_current_stock) read_mall_stock_dynamic_array(buffer, &j, &current_Mall_agent->current_stock);
				if(in_firm_revenues) read_sales_in_mall_dynamic_array(buffer, &j, &current_Mall_agent->firm_revenues);
				if(in_total_supply) current_Mall_agent->total_supply = atof(buffer);
				if(in_export_volume_matrix) read_double_static_array(buffer, &j, current_Mall_agent->export_volume_matrix, 900);
				if(in_export_value_matrix) read_double_static_array(buffer, &j, current_Mall_agent->export_value_matrix, 900);
				if(in_export_previous_value_matrix) read_double_static_array(buffer, &j, current_Mall_agent->export_previous_value_matrix, 900);
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
				if(in_capital_good_price) current_IGFirm_agent->capital_good_price = atof(buffer);
				if(in_revenue_per_day) current_IGFirm_agent->revenue_per_day = atof(buffer);
				if(in_tax_rate_corporate) current_IGFirm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_vat) current_IGFirm_agent->tax_rate_vat = atof(buffer);
				if(in_tax_payment) current_IGFirm_agent->tax_payment = atof(buffer);
				if(in_net_profit) current_IGFirm_agent->net_profit = atof(buffer);
				if(in_outstanding_shares) current_IGFirm_agent->outstanding_shares = atoi(buffer);
				if(in_current_dividend_per_share) current_IGFirm_agent->current_dividend_per_share = atof(buffer);
				if(in_cum_revenues) current_IGFirm_agent->cum_revenues = atof(buffer);
				if(in_age) current_IGFirm_agent->age = atoi(buffer);
				if(in_transfer_payment) current_IGFirm_agent->transfer_payment = atof(buffer);
				if(in_subsidy_payment) current_IGFirm_agent->subsidy_payment = atof(buffer);
			}
			else if(in_Eurostat_agent == 1)
			{
				if(in_id) current_Eurostat_agent->id = atoi(buffer);
				if(in_region_id) current_Eurostat_agent->region_id = atoi(buffer);
				if(in_no_regions) current_Eurostat_agent->no_regions = atoi(buffer);
				if(in_switch_datastorage) current_Eurostat_agent->switch_datastorage = atoi(buffer);
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
				if(in_government_tax_rates) read_tax_rates_item_static_array(buffer, &j, current_Eurostat_agent->government_tax_rates, 27);
				if(in_total_earnings) current_Eurostat_agent->total_earnings = atof(buffer);
				if(in_total_debt) current_Eurostat_agent->total_debt = atof(buffer);
				if(in_total_assets) current_Eurostat_agent->total_assets = atof(buffer);
				if(in_total_equity) current_Eurostat_agent->total_equity = atof(buffer);
				if(in_average_debt_earnings_ratio) current_Eurostat_agent->average_debt_earnings_ratio = atof(buffer);
				if(in_average_debt_equity_ratio) current_Eurostat_agent->average_debt_equity_ratio = atof(buffer);
				if(in_labour_share_ratio) current_Eurostat_agent->labour_share_ratio = atof(buffer);
				if(in_cpi) current_Eurostat_agent->cpi = atof(buffer);
				if(in_gdp) current_Eurostat_agent->gdp = atof(buffer);
				if(in_monthly_sold_quantity) current_Eurostat_agent->monthly_sold_quantity = atof(buffer);
				if(in_monthly_output) current_Eurostat_agent->monthly_output = atof(buffer);
				if(in_monthly_revenue) current_Eurostat_agent->monthly_revenue = atof(buffer);
				if(in_monthly_planned_output) current_Eurostat_agent->monthly_planned_output = atof(buffer);
				if(in_price_index) current_Eurostat_agent->price_index = atof(buffer);
				if(in_history_monthly) read_history_item_static_array(buffer, &j, current_Eurostat_agent->history_monthly, 13);
				if(in_history_quarterly) read_history_item_static_array(buffer, &j, current_Eurostat_agent->history_quarterly, 5);
				if(in_monthly_growth_rates) read_history_item(buffer, &j, &current_Eurostat_agent->monthly_growth_rates);
				if(in_quarterly_growth_rates) read_history_item(buffer, &j, &current_Eurostat_agent->quarterly_growth_rates);
				if(in_annual_growth_rates_monthly) read_history_item(buffer, &j, &current_Eurostat_agent->annual_growth_rates_monthly);
				if(in_annual_growth_rates_quarterly) read_history_item(buffer, &j, &current_Eurostat_agent->annual_growth_rates_quarterly);
				if(in_no_firm_births) current_Eurostat_agent->no_firm_births = atoi(buffer);
				if(in_no_firm_deaths) current_Eurostat_agent->no_firm_deaths = atoi(buffer);
				if(in_firm_age_distribution) read_int_static_array(buffer, &j, current_Eurostat_agent->firm_age_distribution, 60);
				if(in_firm_age_distribution_multiperiod) read_int_static_array(buffer, &j, current_Eurostat_agent->firm_age_distribution_multiperiod, 720);
				if(in_firm_age_distribution_1_period_lag) read_int_static_array(buffer, &j, current_Eurostat_agent->firm_age_distribution_1_period_lag, 60);
				if(in_firm_age_distribution_2_period_lag) read_int_static_array(buffer, &j, current_Eurostat_agent->firm_age_distribution_2_period_lag, 60);
				if(in_firm_birth_rate) current_Eurostat_agent->firm_birth_rate = atof(buffer);
				if(in_firm_death_rate) current_Eurostat_agent->firm_death_rate = atof(buffer);
				if(in_survival_rate) read_double_static_array(buffer, &j, current_Eurostat_agent->survival_rate, 60);
				if(in_survival_rate_multiperiod_1) read_double_static_array(buffer, &j, current_Eurostat_agent->survival_rate_multiperiod_1, 60);
				if(in_survival_rate_multiperiod_2) read_double_static_array(buffer, &j, current_Eurostat_agent->survival_rate_multiperiod_2, 60);
				if(in_survival_rate_multiperiod) read_double_static_array(buffer, &j, current_Eurostat_agent->survival_rate_multiperiod, 720);
				if(in_max_firm_creation) current_Eurostat_agent->max_firm_creation = atoi(buffer);
				if(in_recession_started) current_Eurostat_agent->recession_started = atoi(buffer);
				if(in_recession_duration) current_Eurostat_agent->recession_duration = atoi(buffer);
				if(in_export_volume_matrix) read_double_static_array(buffer, &j, current_Eurostat_agent->export_volume_matrix, 900);
				if(in_export_value_matrix) read_double_static_array(buffer, &j, current_Eurostat_agent->export_value_matrix, 900);
				if(in_export_previous_value_matrix) read_double_static_array(buffer, &j, current_Eurostat_agent->export_previous_value_matrix, 900);
				if(in_region_export_volume) read_double_static_array(buffer, &j, current_Eurostat_agent->region_export_volume, 30);
				if(in_region_import_volume) read_double_static_array(buffer, &j, current_Eurostat_agent->region_import_volume, 30);
				if(in_region_export_value) read_double_static_array(buffer, &j, current_Eurostat_agent->region_export_value, 30);
				if(in_region_import_value) read_double_static_array(buffer, &j, current_Eurostat_agent->region_import_value, 30);
				if(in_region_import_previous_value) read_double_static_array(buffer, &j, current_Eurostat_agent->region_import_previous_value, 30);
			}
			else if(in_Clearinghouse_agent == 1)
			{
				if(in_id) current_Clearinghouse_agent->id = atoi(buffer);
				if(in_region_id) current_Clearinghouse_agent->region_id = atoi(buffer);
				if(in_assets) read_Asset_dynamic_array(buffer, &j, &current_Clearinghouse_agent->assets);
				if(in_clearingmechanism) read_ClearingMechanism(buffer, &j, &current_Clearinghouse_agent->clearingmechanism);
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
			else if(in_Government_agent == 1)
			{
				if(in_id) current_Government_agent->id = atoi(buffer);
				if(in_list_of_regions) read_int_static_array(buffer, &j, current_Government_agent->list_of_regions, 1);
				if(in_payment_account) current_Government_agent->payment_account = atof(buffer);
				if(in_day_of_month_to_act) current_Government_agent->day_of_month_to_act = atoi(buffer);
				if(in_bond) read_Bond(buffer, &j, &current_Government_agent->bond);
				if(in_pending_order) read_Order(buffer, &j, &current_Government_agent->pending_order);
				if(in_deficit) current_Government_agent->deficit = atof(buffer);
				if(in_unemployment_benefit_pct) current_Government_agent->unemployment_benefit_pct = atof(buffer);
				if(in_money_financing_fraction) current_Government_agent->money_financing_fraction = atof(buffer);
				if(in_gdp_fraction_consumption) current_Government_agent->gdp_fraction_consumption = atof(buffer);
				if(in_gdp_fraction_investment) current_Government_agent->gdp_fraction_investment = atof(buffer);
				if(in_tax_rate_corporate) current_Government_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_rate_hh_labour) current_Government_agent->tax_rate_hh_labour = atof(buffer);
				if(in_tax_rate_hh_capital) current_Government_agent->tax_rate_hh_capital = atof(buffer);
				if(in_tax_rate_vat) current_Government_agent->tax_rate_vat = atof(buffer);
				if(in_monthly_tax_revenues) current_Government_agent->monthly_tax_revenues = atof(buffer);
				if(in_yearly_tax_revenues) current_Government_agent->yearly_tax_revenues = atof(buffer);
				if(in_monthly_unemployment_benefit_payment) current_Government_agent->monthly_unemployment_benefit_payment = atof(buffer);
				if(in_yearly_unemployment_benefit_payment) current_Government_agent->yearly_unemployment_benefit_payment = atof(buffer);
				if(in_hh_transfer_payment) current_Government_agent->hh_transfer_payment = atof(buffer);
				if(in_firm_transfer_payment) current_Government_agent->firm_transfer_payment = atof(buffer);
				if(in_monthly_transfer_payment) current_Government_agent->monthly_transfer_payment = atof(buffer);
				if(in_yearly_transfer_payment) current_Government_agent->yearly_transfer_payment = atof(buffer);
				if(in_hh_subsidy_payment) current_Government_agent->hh_subsidy_payment = atof(buffer);
				if(in_firm_subsidy_payment) current_Government_agent->firm_subsidy_payment = atof(buffer);
				if(in_monthly_subsidy_payment) current_Government_agent->monthly_subsidy_payment = atof(buffer);
				if(in_yearly_subsidy_payment) current_Government_agent->yearly_subsidy_payment = atof(buffer);
				if(in_monthly_bond_coupon_payment) current_Government_agent->monthly_bond_coupon_payment = atof(buffer);
				if(in_yearly_bond_coupon_payment) current_Government_agent->yearly_bond_coupon_payment = atof(buffer);
				if(in_gov_interest_rate) current_Government_agent->gov_interest_rate = atof(buffer);
				if(in_yearly_investment_expenditure) current_Government_agent->yearly_investment_expenditure = atof(buffer);
				if(in_yearly_consumption_expenditure) current_Government_agent->yearly_consumption_expenditure = atof(buffer);
				if(in_yearly_income) current_Government_agent->yearly_income = atof(buffer);
				if(in_yearly_expenditure) current_Government_agent->yearly_expenditure = atof(buffer);
				if(in_total_debt) current_Government_agent->total_debt = atof(buffer);
				if(in_yearly_budget_balance) current_Government_agent->yearly_budget_balance = atof(buffer);
				if(in_total_money_financing) current_Government_agent->total_money_financing = atof(buffer);
				if(in_total_bond_financing) current_Government_agent->total_bond_financing = atof(buffer);
				if(in_country_wide_mean_wage) current_Government_agent->country_wide_mean_wage = atof(buffer);
				if(in_num_unemployed) current_Government_agent->num_unemployed = atoi(buffer);
				if(in_gdp) current_Government_agent->gdp = atof(buffer);
				if(in_gdp_growth) current_Government_agent->gdp_growth = atof(buffer);
				if(in_gdp_forecast) current_Government_agent->gdp_forecast = atof(buffer);
				if(in_yearly_income_forecast) current_Government_agent->yearly_income_forecast = atof(buffer);
				if(in_yearly_expenditure_budget) current_Government_agent->yearly_expenditure_budget = atof(buffer);
				if(in_budget_balance_forecast) current_Government_agent->budget_balance_forecast = atof(buffer);
				if(in_monthly_consumption_expenditure) current_Government_agent->monthly_consumption_expenditure = atof(buffer);
				if(in_monthly_investment_expenditure) current_Government_agent->monthly_investment_expenditure = atof(buffer);
				if(in_monthly_budget_balance) current_Government_agent->monthly_budget_balance = atof(buffer);
				if(in_monthly_consumption_budget) current_Government_agent->monthly_consumption_budget = atof(buffer);
				if(in_monthly_investment_budget) current_Government_agent->monthly_investment_budget = atof(buffer);
				if(in_monthly_income) current_Government_agent->monthly_income = atof(buffer);
				if(in_monthly_expenditure) current_Government_agent->monthly_expenditure = atof(buffer);
				if(in_yearly_consumption_budget) current_Government_agent->yearly_consumption_budget = atof(buffer);
				if(in_yearly_investment_budget) current_Government_agent->yearly_investment_budget = atof(buffer);
			}
			else if(in_Central_Bank_agent == 1)
			{
				if(in_id) current_Central_Bank_agent->id = atoi(buffer);
				if(in_accounts) read_account_item_dynamic_array(buffer, &j, &current_Central_Bank_agent->accounts);
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
//////////////////////////////////////////////	free_sales_statistics_array(malls_sales_statistics);
////////////////	free_sold_quantities_per_mall_array(sold_quantities);
//////	free_delivery_volume_per_mall_array(delivery_volume);
//	free_delivery_volume_per_mall_array(planned_delivery_volume);
//	free_mall_info_array(current_mall_stocks);
//	free_double_array(last_planned_production_quantities);
////////	free_financing_capital_array(capital_financing);
//////////	free_residual_var_datatype_static_array(residual_var, 10);
//////////////////////////////////////////////////	free_debt_item_array(loans);
//////////////////////////////////////	free_Stock_datatype(stock);
//	free_employee_array(employees);
//////////////////////////////////////////////////////////////	free_int_array(neighboring_region_ids);
//////////////	free_ordered_quantity_static_array(order_quantity, 2);
//	free_received_quantities_static_array(received_quantity, 2);
////////////////////////	free_double_array(last_income);
////////	free_Belief_array(beliefs);
//	free_Order_array(pendingOrders);
//	free_Asset_array(assetsowned);
//	free_double_array(assetWeights);
//	free_double_array(assetUtilities);
//////////////////////////////////////////////	free_mall_stock_array(current_stock);
//	free_sales_in_mall_array(firm_revenues);
//////////////////////////////////////////////////////////////////////////////////////////////////////////////	free_firm_data_array(region_firm_data);
//	free_household_data_array(region_household_data);
//	free_tax_rates_item_static_array(government_tax_rates, 27);
////////////////////////	free_history_item_static_array(history_monthly, 13);
//	free_history_item_static_array(history_quarterly, 5);
//	free_history_item_datatype(monthly_growth_rates);
//	free_history_item_datatype(quarterly_growth_rates);
//	free_history_item_datatype(annual_growth_rates_monthly);
//	free_history_item_datatype(annual_growth_rates_quarterly);
//////////////////////////////////////////	free_Asset_array(assets);
//	free_ClearingMechanism_datatype(clearingmechanism);
////////////////////////////////	free_Bond_datatype(bond);
//	free_Order_datatype(pending_order);
//////////////////////////////////////////////////////////////////////////////////////	free_account_item_array(accounts);

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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).consumer_region_id);
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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).region_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).stock);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).quality);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).previous_price);
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

/** \fn void write_account_item(FILE *file, account_item * temp_datatype)
 * \brief Writes account_item datatype.
 */
void write_account_item(FILE *file, account_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).payment_account);
	fputs(data, file);
	fputs("}", file);
}

void write_account_item_static_array(FILE *file, account_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_account_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_account_item_dynamic_array(FILE *file, account_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_account_item(file, &(*temp_datatype).array[i]);
		
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

/** \fn void write_Order(FILE *file, Order * temp_datatype)
 * \brief Writes Order datatype.
 */
void write_Order(FILE *file, Order * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).issuer);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).assetId);
	fputs(data, file);
	fputs("}", file);
}

void write_Order_static_array(FILE *file, Order * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Order(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Order_dynamic_array(FILE *file, Order_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Order(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Belief(FILE *file, Belief * temp_datatype)
 * \brief Writes Belief datatype.
 */
void write_Belief(FILE *file, Belief * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).asset_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedPriceReturns);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedTotalReturns);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedCashFlowYield);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).volatility);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedEarning);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).expectedEarningPayout);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).last_price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).utility);
	fputs(data, file);
	fputs("}", file);
}

void write_Belief_static_array(FILE *file, Belief * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Belief(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Belief_dynamic_array(FILE *file, Belief_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Belief(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Stock(FILE *file, Stock * temp_datatype)
 * \brief Writes Stock datatype.
 */
void write_Stock(FILE *file, Stock * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nrOutStandingShares);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).index);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).prices, 100);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).returns, 100);
	fputs("}", file);
}

void write_Stock_static_array(FILE *file, Stock * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Stock(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Stock_dynamic_array(FILE *file, Stock_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Stock(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Bond(FILE *file, Bond * temp_datatype)
 * \brief Writes Bond datatype.
 */
void write_Bond(FILE *file, Bond * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_outstanding);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).face_value);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).nominal_yield);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).maturity_day);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).issue_day);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).yield2maturity);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).prices, 100);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).index);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).returns, 100);
	fputs("}", file);
}

void write_Bond_static_array(FILE *file, Bond * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Bond(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Bond_dynamic_array(FILE *file, Bond_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Bond(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Asset(FILE *file, Asset * temp_datatype)
 * \brief Writes Asset datatype.
 */
void write_Asset(FILE *file, Asset * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).lastPrice);
	fputs(data, file);
	fputs("}", file);
}

void write_Asset_static_array(FILE *file, Asset * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Asset(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Asset_dynamic_array(FILE *file, Asset_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_Asset(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ClearingMechanism(FILE *file, ClearingMechanism * temp_datatype)
 * \brief Writes ClearingMechanism datatype.
 */
void write_ClearingMechanism(FILE *file, ClearingMechanism * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).lastPrice);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).quantity);
	fputs(data, file);
	fputs(", ", file);	write_Order_dynamic_array(file, &(*temp_datatype).sellOrders);
	fputs(", ", file);	write_Order_dynamic_array(file, &(*temp_datatype).buyOrders);
	fputs(", ", file);	write_double_dynamic_array(file, &(*temp_datatype).prices);
	fputs("}", file);
}

void write_ClearingMechanism_static_array(FILE *file, ClearingMechanism * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ClearingMechanism(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ClearingMechanism_dynamic_array(FILE *file, ClearingMechanism_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ClearingMechanism(file, &(*temp_datatype).array[i]);
		
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

/** \fn void write_logit(FILE *file, logit * temp_datatype)
 * \brief Writes logit datatype.
 */
void write_logit(FILE *file, logit * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).logit_value);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).worker_id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).general_skill);
	fputs(data, file);
	fputs("}", file);
}

void write_logit_static_array(FILE *file, logit * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_logit(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_logit_dynamic_array(FILE *file, logit_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_logit(file, &(*temp_datatype).array[i]);
		
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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firms);
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
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_sold_quantity);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_output);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_revenue);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_planned_output);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gdp);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).cpi);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).cpi_last_month);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_births);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_deaths);
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

/** \fn void write_region_data_item(FILE *file, region_data_item * temp_datatype)
 * \brief Writes region_data_item datatype.
 */
void write_region_data_item(FILE *file, region_data_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).cpi);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).cpi_last_month);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gdp);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).output);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employment);
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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firms);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_births);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_deaths);
	fputs(data, file);
	fputs("}", file);
}

void write_region_data_item_static_array(FILE *file, region_data_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_region_data_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_region_data_item_dynamic_array(FILE *file, region_data_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_region_data_item(file, &(*temp_datatype).array[i]);
		
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

/** \fn void write_history_item(FILE *file, history_item * temp_datatype)
 * \brief Writes history_item datatype.
 */
void write_history_item(FILE *file, history_item * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).cpi);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gdp);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).output);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).employment);
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
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firms);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_births);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).no_firm_deaths);
	fputs(data, file);
	fputs(", ", file);	write_region_data_item_dynamic_array(file, &(*temp_datatype).region_data);
	fputs("}", file);
}

void write_history_item_static_array(FILE *file, history_item * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_history_item(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_history_item_dynamic_array(FILE *file, history_item_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_history_item(file, &(*temp_datatype).array[i]);
		
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
		fputs("<last_day_of_month_to_act>", file);
	sprintf(data, "%i", current->last_day_of_month_to_act);
	fputs(data, file);
	fputs("</last_day_of_month_to_act>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<bank_id>", file);
	sprintf(data, "%i", current->bank_id);
	fputs(data, file);
	fputs("</bank_id>\n", file);
		fputs("<mean_wage>", file);
	sprintf(data, "%f", current->mean_wage);
	fputs(data, file);
	fputs("</mean_wage>\n", file);
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
		fputs("<planned_output>", file);
	sprintf(data, "%f", current->planned_output);
	fputs(data, file);
	fputs("</planned_output>\n", file);
		fputs("<output>", file);
	sprintf(data, "%f", current->output);
	fputs(data, file);
	fputs("</output>\n", file);
		fputs("<unit_costs>", file);
	sprintf(data, "%f", current->unit_costs);
	fputs(data, file);
	fputs("</unit_costs>\n", file);
		fputs("<total_supply>", file);
	sprintf(data, "%f", current->total_supply);
	fputs(data, file);
	fputs("</total_supply>\n", file);
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
		fputs("<total_external_financing_obtained>", file);
	sprintf(data, "%f", current->total_external_financing_obtained);
	fputs(data, file);
	fputs("</total_external_financing_obtained>\n", file);
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
		fputs("<financial_resources_for_production>", file);
	sprintf(data, "%f", current->financial_resources_for_production);
	fputs(data, file);
	fputs("</financial_resources_for_production>\n", file);
		fputs("<planned_value_capital_stock>", file);
	sprintf(data, "%f", current->planned_value_capital_stock);
	fputs(data, file);
	fputs("</planned_value_capital_stock>\n", file);
		fputs("<total_units_local_inventory>", file);
	sprintf(data, "%f", current->total_units_local_inventory);
	fputs(data, file);
	fputs("</total_units_local_inventory>\n", file);
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
		fputs("<earnings_per_share>", file);
	sprintf(data, "%f", current->earnings_per_share);
	fputs(data, file);
	fputs("</earnings_per_share>\n", file);
		fputs("<total_payments>", file);
	sprintf(data, "%f", current->total_payments);
	fputs(data, file);
	fputs("</total_payments>\n", file);
		fputs("<total_interest_payments>", file);
	sprintf(data, "%f", current->total_interest_payments);
	fputs(data, file);
	fputs("</total_interest_payments>\n", file);
		fputs("<previous_shares_outstanding>", file);
	sprintf(data, "%f", current->previous_shares_outstanding);
	fputs(data, file);
	fputs("</previous_shares_outstanding>\n", file);
		fputs("<earnings_payout>", file);
	sprintf(data, "%f", current->earnings_payout);
	fputs(data, file);
	fputs("</earnings_payout>\n", file);
		fputs("<current_shares_outstanding>", file);
	sprintf(data, "%f", current->current_shares_outstanding);
	fputs(data, file);
	fputs("</current_shares_outstanding>\n", file);
		fputs("<stock>", file);
	write_Stock(file, &current->stock);
	fputs("</stock>\n", file);
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
		fputs("<age>", file);
	sprintf(data, "%i", current->age);
	fputs(data, file);
	fputs("</age>\n", file);
		fputs("<transfer_payment>", file);
	sprintf(data, "%f", current->transfer_payment);
	fputs(data, file);
	fputs("</transfer_payment>\n", file);
		fputs("<subsidy_payment>", file);
	sprintf(data, "%f", current->subsidy_payment);
	fputs(data, file);
	fputs("</subsidy_payment>\n", file);
		fputs("<active>", file);
	sprintf(data, "%i", current->active);
	fputs(data, file);
	fputs("</active>\n", file);
		fputs("<bankruptcy_idle_counter>", file);
	sprintf(data, "%i", current->bankruptcy_idle_counter);
	fputs(data, file);
	fputs("</bankruptcy_idle_counter>\n", file);
		fputs("<bankruptcy_state>", file);
	sprintf(data, "%i", current->bankruptcy_state);
	fputs(data, file);
	fputs("</bankruptcy_state>\n", file);
		fputs("<bankruptcy_insolvency_state>", file);
	sprintf(data, "%i", current->bankruptcy_insolvency_state);
	fputs(data, file);
	fputs("</bankruptcy_insolvency_state>\n", file);
		fputs("<bankruptcy_illiquidity_state>", file);
	sprintf(data, "%i", current->bankruptcy_illiquidity_state);
	fputs(data, file);
	fputs("</bankruptcy_illiquidity_state>\n", file);
		fputs("<financial_crisis_state>", file);
	sprintf(data, "%i", current->financial_crisis_state);
	fputs(data, file);
	fputs("</financial_crisis_state>\n", file);
		
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
		fputs("<price_index>", file);
	sprintf(data, "%f", current->price_index);
	fputs(data, file);
	fputs("</price_index>\n", file);
		fputs("<price_index_base_period>", file);
	sprintf(data, "%f", current->price_index_base_period);
	fputs(data, file);
	fputs("</price_index_base_period>\n", file);
		fputs("<commuting_costs_price_level_weight>", file);
	sprintf(data, "%f", current->commuting_costs_price_level_weight);
	fputs(data, file);
	fputs("</commuting_costs_price_level_weight>\n", file);
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
		fputs("<wealth>", file);
	sprintf(data, "%f", current->wealth);
	fputs(data, file);
	fputs("</wealth>\n", file);
		fputs("<beliefs>", file);
	write_Belief_dynamic_array(file, &current->beliefs);
	fputs("</beliefs>\n", file);
		fputs("<pendingOrders>", file);
	write_Order_dynamic_array(file, &current->pendingOrders);
	fputs("</pendingOrders>\n", file);
		fputs("<assetsowned>", file);
	write_Asset_dynamic_array(file, &current->assetsowned);
	fputs("</assetsowned>\n", file);
		fputs("<assetWeights>", file);
	write_double_dynamic_array(file, &current->assetWeights);
	fputs("</assetWeights>\n", file);
		fputs("<assetUtilities>", file);
	write_double_dynamic_array(file, &current->assetUtilities);
	fputs("</assetUtilities>\n", file);
		fputs("<cash_on_hand>", file);
	sprintf(data, "%f", current->cash_on_hand);
	fputs(data, file);
	fputs("</cash_on_hand>\n", file);
		fputs("<forwardWindow>", file);
	sprintf(data, "%i", current->forwardWindow);
	fputs(data, file);
	fputs("</forwardWindow>\n", file);
		fputs("<backwardWindow>", file);
	sprintf(data, "%i", current->backwardWindow);
	fputs(data, file);
	fputs("</backwardWindow>\n", file);
		fputs("<bins>", file);
	sprintf(data, "%i", current->bins);
	fputs(data, file);
	fputs("</bins>\n", file);
		fputs("<randomWeight>", file);
	sprintf(data, "%f", current->randomWeight);
	fputs(data, file);
	fputs("</randomWeight>\n", file);
		fputs("<fundamentalWeight>", file);
	sprintf(data, "%f", current->fundamentalWeight);
	fputs(data, file);
	fputs("</fundamentalWeight>\n", file);
		fputs("<chartistWeight>", file);
	sprintf(data, "%f", current->chartistWeight);
	fputs(data, file);
	fputs("</chartistWeight>\n", file);
		fputs("<holdingPeriodToForwardW>", file);
	sprintf(data, "%i", current->holdingPeriodToForwardW);
	fputs(data, file);
	fputs("</holdingPeriodToForwardW>\n", file);
		fputs("<lossaversion>", file);
	sprintf(data, "%f", current->lossaversion);
	fputs(data, file);
	fputs("</lossaversion>\n", file);
		fputs("<strategy>", file);
	sprintf(data, "%f", current->strategy);
	fputs(data, file);
	fputs("</strategy>\n", file);
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
		fputs("<last_labour_income>", file);
	sprintf(data, "%f", current->last_labour_income);
	fputs(data, file);
	fputs("</last_labour_income>\n", file);
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
		fputs("<day_of_month_receive_benefit>", file);
	sprintf(data, "%i", current->day_of_month_receive_benefit);
	fputs(data, file);
	fputs("</day_of_month_receive_benefit>\n", file);
		fputs("<unemployment_benefit_pct>", file);
	sprintf(data, "%f", current->unemployment_benefit_pct);
	fputs(data, file);
	fputs("</unemployment_benefit_pct>\n", file);
		fputs("<transfer_payment>", file);
	sprintf(data, "%f", current->transfer_payment);
	fputs(data, file);
	fputs("</transfer_payment>\n", file);
		fputs("<subsidy_payment>", file);
	sprintf(data, "%f", current->subsidy_payment);
	fputs(data, file);
	fputs("</subsidy_payment>\n", file);
		
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
		fputs("<no_regions>", file);
	sprintf(data, "%i", current->no_regions);
	fputs(data, file);
	fputs("</no_regions>\n", file);
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
		fputs("<export_volume_matrix>", file);
	write_double_static_array(file, current->export_volume_matrix, 900);
	fputs("</export_volume_matrix>\n", file);
		fputs("<export_value_matrix>", file);
	write_double_static_array(file, current->export_value_matrix, 900);
	fputs("</export_value_matrix>\n", file);
		fputs("<export_previous_value_matrix>", file);
	write_double_static_array(file, current->export_previous_value_matrix, 900);
	fputs("</export_previous_value_matrix>\n", file);
		
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
		fputs("<age>", file);
	sprintf(data, "%i", current->age);
	fputs(data, file);
	fputs("</age>\n", file);
		fputs("<transfer_payment>", file);
	sprintf(data, "%f", current->transfer_payment);
	fputs(data, file);
	fputs("</transfer_payment>\n", file);
		fputs("<subsidy_payment>", file);
	sprintf(data, "%f", current->subsidy_payment);
	fputs(data, file);
	fputs("</subsidy_payment>\n", file);
		
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
		fputs("<switch_datastorage>", file);
	sprintf(data, "%i", current->switch_datastorage);
	fputs(data, file);
	fputs("</switch_datastorage>\n", file);
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
		fputs("<government_tax_rates>", file);
	write_tax_rates_item_static_array(file, current->government_tax_rates, 27);
	fputs("</government_tax_rates>\n", file);
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
		fputs("<cpi>", file);
	sprintf(data, "%f", current->cpi);
	fputs(data, file);
	fputs("</cpi>\n", file);
		fputs("<gdp>", file);
	sprintf(data, "%f", current->gdp);
	fputs(data, file);
	fputs("</gdp>\n", file);
		fputs("<monthly_sold_quantity>", file);
	sprintf(data, "%f", current->monthly_sold_quantity);
	fputs(data, file);
	fputs("</monthly_sold_quantity>\n", file);
		fputs("<monthly_output>", file);
	sprintf(data, "%f", current->monthly_output);
	fputs(data, file);
	fputs("</monthly_output>\n", file);
		fputs("<monthly_revenue>", file);
	sprintf(data, "%f", current->monthly_revenue);
	fputs(data, file);
	fputs("</monthly_revenue>\n", file);
		fputs("<monthly_planned_output>", file);
	sprintf(data, "%f", current->monthly_planned_output);
	fputs(data, file);
	fputs("</monthly_planned_output>\n", file);
		fputs("<price_index>", file);
	sprintf(data, "%f", current->price_index);
	fputs(data, file);
	fputs("</price_index>\n", file);
		fputs("<history_monthly>", file);
	write_history_item_static_array(file, current->history_monthly, 13);
	fputs("</history_monthly>\n", file);
		fputs("<history_quarterly>", file);
	write_history_item_static_array(file, current->history_quarterly, 5);
	fputs("</history_quarterly>\n", file);
		fputs("<monthly_growth_rates>", file);
	write_history_item(file, &current->monthly_growth_rates);
	fputs("</monthly_growth_rates>\n", file);
		fputs("<quarterly_growth_rates>", file);
	write_history_item(file, &current->quarterly_growth_rates);
	fputs("</quarterly_growth_rates>\n", file);
		fputs("<annual_growth_rates_monthly>", file);
	write_history_item(file, &current->annual_growth_rates_monthly);
	fputs("</annual_growth_rates_monthly>\n", file);
		fputs("<annual_growth_rates_quarterly>", file);
	write_history_item(file, &current->annual_growth_rates_quarterly);
	fputs("</annual_growth_rates_quarterly>\n", file);
		fputs("<no_firm_births>", file);
	sprintf(data, "%i", current->no_firm_births);
	fputs(data, file);
	fputs("</no_firm_births>\n", file);
		fputs("<no_firm_deaths>", file);
	sprintf(data, "%i", current->no_firm_deaths);
	fputs(data, file);
	fputs("</no_firm_deaths>\n", file);
		fputs("<firm_age_distribution>", file);
	write_int_static_array(file, current->firm_age_distribution, 60);
	fputs("</firm_age_distribution>\n", file);
		fputs("<firm_age_distribution_multiperiod>", file);
	write_int_static_array(file, current->firm_age_distribution_multiperiod, 720);
	fputs("</firm_age_distribution_multiperiod>\n", file);
		fputs("<firm_age_distribution_1_period_lag>", file);
	write_int_static_array(file, current->firm_age_distribution_1_period_lag, 60);
	fputs("</firm_age_distribution_1_period_lag>\n", file);
		fputs("<firm_age_distribution_2_period_lag>", file);
	write_int_static_array(file, current->firm_age_distribution_2_period_lag, 60);
	fputs("</firm_age_distribution_2_period_lag>\n", file);
		fputs("<firm_birth_rate>", file);
	sprintf(data, "%f", current->firm_birth_rate);
	fputs(data, file);
	fputs("</firm_birth_rate>\n", file);
		fputs("<firm_death_rate>", file);
	sprintf(data, "%f", current->firm_death_rate);
	fputs(data, file);
	fputs("</firm_death_rate>\n", file);
		fputs("<survival_rate>", file);
	write_double_static_array(file, current->survival_rate, 60);
	fputs("</survival_rate>\n", file);
		fputs("<survival_rate_multiperiod_1>", file);
	write_double_static_array(file, current->survival_rate_multiperiod_1, 60);
	fputs("</survival_rate_multiperiod_1>\n", file);
		fputs("<survival_rate_multiperiod_2>", file);
	write_double_static_array(file, current->survival_rate_multiperiod_2, 60);
	fputs("</survival_rate_multiperiod_2>\n", file);
		fputs("<survival_rate_multiperiod>", file);
	write_double_static_array(file, current->survival_rate_multiperiod, 720);
	fputs("</survival_rate_multiperiod>\n", file);
		fputs("<max_firm_creation>", file);
	sprintf(data, "%i", current->max_firm_creation);
	fputs(data, file);
	fputs("</max_firm_creation>\n", file);
		fputs("<recession_started>", file);
	sprintf(data, "%i", current->recession_started);
	fputs(data, file);
	fputs("</recession_started>\n", file);
		fputs("<recession_duration>", file);
	sprintf(data, "%i", current->recession_duration);
	fputs(data, file);
	fputs("</recession_duration>\n", file);
		fputs("<export_volume_matrix>", file);
	write_double_static_array(file, current->export_volume_matrix, 900);
	fputs("</export_volume_matrix>\n", file);
		fputs("<export_value_matrix>", file);
	write_double_static_array(file, current->export_value_matrix, 900);
	fputs("</export_value_matrix>\n", file);
		fputs("<export_previous_value_matrix>", file);
	write_double_static_array(file, current->export_previous_value_matrix, 900);
	fputs("</export_previous_value_matrix>\n", file);
		fputs("<region_export_volume>", file);
	write_double_static_array(file, current->region_export_volume, 30);
	fputs("</region_export_volume>\n", file);
		fputs("<region_import_volume>", file);
	write_double_static_array(file, current->region_import_volume, 30);
	fputs("</region_import_volume>\n", file);
		fputs("<region_export_value>", file);
	write_double_static_array(file, current->region_export_value, 30);
	fputs("</region_export_value>\n", file);
		fputs("<region_import_value>", file);
	write_double_static_array(file, current->region_import_value, 30);
	fputs("</region_import_value>\n", file);
		fputs("<region_import_previous_value>", file);
	write_double_static_array(file, current->region_import_previous_value, 30);
	fputs("</region_import_previous_value>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Clearinghouse_agent(FILE *file, xmachine_memory_Clearinghouse * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Clearinghouse</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
		fputs("<assets>", file);
	write_Asset_dynamic_array(file, &current->assets);
	fputs("</assets>\n", file);
		fputs("<clearingmechanism>", file);
	write_ClearingMechanism(file, &current->clearingmechanism);
	fputs("</clearingmechanism>\n", file);
		
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

void write_Government_agent(FILE *file, xmachine_memory_Government * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Government</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<list_of_regions>", file);
	write_int_static_array(file, current->list_of_regions, 1);
	fputs("</list_of_regions>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<bond>", file);
	write_Bond(file, &current->bond);
	fputs("</bond>\n", file);
		fputs("<pending_order>", file);
	write_Order(file, &current->pending_order);
	fputs("</pending_order>\n", file);
		fputs("<deficit>", file);
	sprintf(data, "%f", current->deficit);
	fputs(data, file);
	fputs("</deficit>\n", file);
		fputs("<unemployment_benefit_pct>", file);
	sprintf(data, "%f", current->unemployment_benefit_pct);
	fputs(data, file);
	fputs("</unemployment_benefit_pct>\n", file);
		fputs("<money_financing_fraction>", file);
	sprintf(data, "%f", current->money_financing_fraction);
	fputs(data, file);
	fputs("</money_financing_fraction>\n", file);
		fputs("<gdp_fraction_consumption>", file);
	sprintf(data, "%f", current->gdp_fraction_consumption);
	fputs(data, file);
	fputs("</gdp_fraction_consumption>\n", file);
		fputs("<gdp_fraction_investment>", file);
	sprintf(data, "%f", current->gdp_fraction_investment);
	fputs(data, file);
	fputs("</gdp_fraction_investment>\n", file);
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
		fputs("<monthly_tax_revenues>", file);
	sprintf(data, "%f", current->monthly_tax_revenues);
	fputs(data, file);
	fputs("</monthly_tax_revenues>\n", file);
		fputs("<yearly_tax_revenues>", file);
	sprintf(data, "%f", current->yearly_tax_revenues);
	fputs(data, file);
	fputs("</yearly_tax_revenues>\n", file);
		fputs("<monthly_unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->monthly_unemployment_benefit_payment);
	fputs(data, file);
	fputs("</monthly_unemployment_benefit_payment>\n", file);
		fputs("<yearly_unemployment_benefit_payment>", file);
	sprintf(data, "%f", current->yearly_unemployment_benefit_payment);
	fputs(data, file);
	fputs("</yearly_unemployment_benefit_payment>\n", file);
		fputs("<hh_transfer_payment>", file);
	sprintf(data, "%f", current->hh_transfer_payment);
	fputs(data, file);
	fputs("</hh_transfer_payment>\n", file);
		fputs("<firm_transfer_payment>", file);
	sprintf(data, "%f", current->firm_transfer_payment);
	fputs(data, file);
	fputs("</firm_transfer_payment>\n", file);
		fputs("<monthly_transfer_payment>", file);
	sprintf(data, "%f", current->monthly_transfer_payment);
	fputs(data, file);
	fputs("</monthly_transfer_payment>\n", file);
		fputs("<yearly_transfer_payment>", file);
	sprintf(data, "%f", current->yearly_transfer_payment);
	fputs(data, file);
	fputs("</yearly_transfer_payment>\n", file);
		fputs("<hh_subsidy_payment>", file);
	sprintf(data, "%f", current->hh_subsidy_payment);
	fputs(data, file);
	fputs("</hh_subsidy_payment>\n", file);
		fputs("<firm_subsidy_payment>", file);
	sprintf(data, "%f", current->firm_subsidy_payment);
	fputs(data, file);
	fputs("</firm_subsidy_payment>\n", file);
		fputs("<monthly_subsidy_payment>", file);
	sprintf(data, "%f", current->monthly_subsidy_payment);
	fputs(data, file);
	fputs("</monthly_subsidy_payment>\n", file);
		fputs("<yearly_subsidy_payment>", file);
	sprintf(data, "%f", current->yearly_subsidy_payment);
	fputs(data, file);
	fputs("</yearly_subsidy_payment>\n", file);
		fputs("<monthly_bond_coupon_payment>", file);
	sprintf(data, "%f", current->monthly_bond_coupon_payment);
	fputs(data, file);
	fputs("</monthly_bond_coupon_payment>\n", file);
		fputs("<yearly_bond_coupon_payment>", file);
	sprintf(data, "%f", current->yearly_bond_coupon_payment);
	fputs(data, file);
	fputs("</yearly_bond_coupon_payment>\n", file);
		fputs("<gov_interest_rate>", file);
	sprintf(data, "%f", current->gov_interest_rate);
	fputs(data, file);
	fputs("</gov_interest_rate>\n", file);
		fputs("<yearly_investment_expenditure>", file);
	sprintf(data, "%f", current->yearly_investment_expenditure);
	fputs(data, file);
	fputs("</yearly_investment_expenditure>\n", file);
		fputs("<yearly_consumption_expenditure>", file);
	sprintf(data, "%f", current->yearly_consumption_expenditure);
	fputs(data, file);
	fputs("</yearly_consumption_expenditure>\n", file);
		fputs("<yearly_income>", file);
	sprintf(data, "%f", current->yearly_income);
	fputs(data, file);
	fputs("</yearly_income>\n", file);
		fputs("<yearly_expenditure>", file);
	sprintf(data, "%f", current->yearly_expenditure);
	fputs(data, file);
	fputs("</yearly_expenditure>\n", file);
		fputs("<total_debt>", file);
	sprintf(data, "%f", current->total_debt);
	fputs(data, file);
	fputs("</total_debt>\n", file);
		fputs("<yearly_budget_balance>", file);
	sprintf(data, "%f", current->yearly_budget_balance);
	fputs(data, file);
	fputs("</yearly_budget_balance>\n", file);
		fputs("<total_money_financing>", file);
	sprintf(data, "%f", current->total_money_financing);
	fputs(data, file);
	fputs("</total_money_financing>\n", file);
		fputs("<total_bond_financing>", file);
	sprintf(data, "%f", current->total_bond_financing);
	fputs(data, file);
	fputs("</total_bond_financing>\n", file);
		fputs("<country_wide_mean_wage>", file);
	sprintf(data, "%f", current->country_wide_mean_wage);
	fputs(data, file);
	fputs("</country_wide_mean_wage>\n", file);
		fputs("<num_unemployed>", file);
	sprintf(data, "%i", current->num_unemployed);
	fputs(data, file);
	fputs("</num_unemployed>\n", file);
		fputs("<gdp>", file);
	sprintf(data, "%f", current->gdp);
	fputs(data, file);
	fputs("</gdp>\n", file);
		fputs("<gdp_growth>", file);
	sprintf(data, "%f", current->gdp_growth);
	fputs(data, file);
	fputs("</gdp_growth>\n", file);
		fputs("<gdp_forecast>", file);
	sprintf(data, "%f", current->gdp_forecast);
	fputs(data, file);
	fputs("</gdp_forecast>\n", file);
		fputs("<yearly_income_forecast>", file);
	sprintf(data, "%f", current->yearly_income_forecast);
	fputs(data, file);
	fputs("</yearly_income_forecast>\n", file);
		fputs("<yearly_expenditure_budget>", file);
	sprintf(data, "%f", current->yearly_expenditure_budget);
	fputs(data, file);
	fputs("</yearly_expenditure_budget>\n", file);
		fputs("<budget_balance_forecast>", file);
	sprintf(data, "%f", current->budget_balance_forecast);
	fputs(data, file);
	fputs("</budget_balance_forecast>\n", file);
		fputs("<monthly_consumption_expenditure>", file);
	sprintf(data, "%f", current->monthly_consumption_expenditure);
	fputs(data, file);
	fputs("</monthly_consumption_expenditure>\n", file);
		fputs("<monthly_investment_expenditure>", file);
	sprintf(data, "%f", current->monthly_investment_expenditure);
	fputs(data, file);
	fputs("</monthly_investment_expenditure>\n", file);
		fputs("<monthly_budget_balance>", file);
	sprintf(data, "%f", current->monthly_budget_balance);
	fputs(data, file);
	fputs("</monthly_budget_balance>\n", file);
		fputs("<monthly_consumption_budget>", file);
	sprintf(data, "%f", current->monthly_consumption_budget);
	fputs(data, file);
	fputs("</monthly_consumption_budget>\n", file);
		fputs("<monthly_investment_budget>", file);
	sprintf(data, "%f", current->monthly_investment_budget);
	fputs(data, file);
	fputs("</monthly_investment_budget>\n", file);
		fputs("<monthly_income>", file);
	sprintf(data, "%f", current->monthly_income);
	fputs(data, file);
	fputs("</monthly_income>\n", file);
		fputs("<monthly_expenditure>", file);
	sprintf(data, "%f", current->monthly_expenditure);
	fputs(data, file);
	fputs("</monthly_expenditure>\n", file);
		fputs("<yearly_consumption_budget>", file);
	sprintf(data, "%f", current->yearly_consumption_budget);
	fputs(data, file);
	fputs("</yearly_consumption_budget>\n", file);
		fputs("<yearly_investment_budget>", file);
	sprintf(data, "%f", current->yearly_investment_budget);
	fputs(data, file);
	fputs("</yearly_investment_budget>\n", file);
		
	fputs("</xagent>\n", file);
}

void write_Central_Bank_agent(FILE *file, xmachine_memory_Central_Bank * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Central_Bank</name>\n", file);
		fputs("<id>", file);
	sprintf(data, "%i", current->id);
	fputs(data, file);
	fputs("</id>\n", file);
		fputs("<accounts>", file);
	write_account_item_dynamic_array(file, &current->accounts);
	fputs("</accounts>\n", file);
		
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
	//double_array * assetWeights;
	//double_array * assetUtilities;
	
	sprintf(data, "%s%i.xml", outputpath, iteration_number);
	file = fopen(data, "w");
	fputs("<states>\n<itno>", file);
	sprintf(data, "%i", iteration_number);
	fputs(data, file);
	fputs("</itno>\n", file);
	fputs("<environment>\n" , file);
	fputs("<print_log>", file);
	sprintf(data, "%i", print_log);
	fputs(data, file);
	fputs("</print_log>\n", file);
	fputs("<print_debug>", file);
	sprintf(data, "%i", print_debug);
	fputs(data, file);
	fputs("</print_debug>\n", file);
	fputs("<day>", file);
	sprintf(data, "%i", day);
	fputs(data, file);
	fputs("</day>\n", file);
	fputs("<week>", file);
	sprintf(data, "%i", week);
	fputs(data, file);
	fputs("</week>\n", file);
	fputs("<month>", file);
	sprintf(data, "%i", month);
	fputs(data, file);
	fputs("</month>\n", file);
	fputs("<quarter>", file);
	sprintf(data, "%i", quarter);
	fputs(data, file);
	fputs("</quarter>\n", file);
	fputs("<year>", file);
	sprintf(data, "%i", year);
	fputs(data, file);
	fputs("</year>\n", file);
	fputs("<number_of_banks_to_apply>", file);
	sprintf(data, "%i", number_of_banks_to_apply);
	fputs(data, file);
	fputs("</number_of_banks_to_apply>\n", file);
	fputs("<gamma_const>", file);
	sprintf(data, "%i", gamma_const);
	fputs(data, file);
	fputs("</gamma_const>\n", file);
	fputs("<alpha>", file);
	sprintf(data, "%f", alpha);
	fputs(data, file);
	fputs("</alpha>\n", file);
	fputs("<beta>", file);
	sprintf(data, "%f", beta);
	fputs(data, file);
	fputs("</beta>\n", file);
	fputs("<depreciation_rate>", file);
	sprintf(data, "%f", depreciation_rate);
	fputs(data, file);
	fputs("</depreciation_rate>\n", file);
	fputs("<discount_rate>", file);
	sprintf(data, "%f", discount_rate);
	fputs(data, file);
	fputs("</discount_rate>\n", file);
	fputs("<teta>", file);
	sprintf(data, "%f", teta);
	fputs(data, file);
	fputs("</teta>\n", file);
	fputs("<mark_up>", file);
	sprintf(data, "%f", mark_up);
	fputs(data, file);
	fputs("</mark_up>\n", file);
	fputs("<lambda>", file);
	sprintf(data, "%f", lambda);
	fputs(data, file);
	fputs("</lambda>\n", file);
	fputs("<wage_update>", file);
	sprintf(data, "%f", wage_update);
	fputs(data, file);
	fputs("</wage_update>\n", file);
	fputs("<min_vacancy>", file);
	sprintf(data, "%i", min_vacancy);
	fputs(data, file);
	fputs("</min_vacancy>\n", file);
	fputs("<wage_reservation_update>", file);
	sprintf(data, "%f", wage_reservation_update);
	fputs(data, file);
	fputs("</wage_reservation_update>\n", file);
	fputs("<region_cost>", file);
	sprintf(data, "%f", region_cost);
	fputs(data, file);
	fputs("</region_cost>\n", file);
	fputs("<inventory_costs_per_unit>", file);
	sprintf(data, "%i", inventory_costs_per_unit);
	fputs(data, file);
	fputs("</inventory_costs_per_unit>\n", file);
	fputs("<on_the_job_search_rate>", file);
	sprintf(data, "%f", on_the_job_search_rate);
	fputs(data, file);
	fputs("</on_the_job_search_rate>\n", file);
	fputs("<initial_consumption_propensity>", file);
	sprintf(data, "%f", initial_consumption_propensity);
	fputs(data, file);
	fputs("</initial_consumption_propensity>\n", file);
	fputs("<consumption_propensity>", file);
	sprintf(data, "%f", consumption_propensity);
	fputs(data, file);
	fputs("</consumption_propensity>\n", file);
	fputs("<firm_planning_horizon>", file);
	sprintf(data, "%i", firm_planning_horizon);
	fputs(data, file);
	fputs("</firm_planning_horizon>\n", file);
	fputs("<inv_inertia>", file);
	sprintf(data, "%i", inv_inertia);
	fputs(data, file);
	fputs("</inv_inertia>\n", file);
	fputs("<adaption_delivery_volume>", file);
	sprintf(data, "%f", adaption_delivery_volume);
	fputs(data, file);
	fputs("</adaption_delivery_volume>\n", file);
	fputs("<periods_to_repay_loans>", file);
	sprintf(data, "%i", periods_to_repay_loans);
	fputs(data, file);
	fputs("</periods_to_repay_loans>\n", file);
	fputs("<delivery_prob_if_critical_stock_0>", file);
	sprintf(data, "%i", delivery_prob_if_critical_stock_0);
	fputs(data, file);
	fputs("</delivery_prob_if_critical_stock_0>\n", file);
	fputs("<innovation_probability>", file);
	sprintf(data, "%i", innovation_probability);
	fputs(data, file);
	fputs("</innovation_probability>\n", file);
	fputs("<productivity_progress>", file);
	sprintf(data, "%f", productivity_progress);
	fputs(data, file);
	fputs("</productivity_progress>\n", file);
	fputs("<const_bankruptcy_idle_period>", file);
	sprintf(data, "%i", const_bankruptcy_idle_period);
	fputs(data, file);
	fputs("</const_bankruptcy_idle_period>\n", file);
	fputs("<debt_rescaling_factor>", file);
	sprintf(data, "%f", debt_rescaling_factor);
	fputs(data, file);
	fputs("</debt_rescaling_factor>\n", file);
	fputs("<target_leverage_ratio>", file);
	sprintf(data, "%f", target_leverage_ratio);
	fputs(data, file);
	fputs("</target_leverage_ratio>\n", file);
	fputs("<target_liquidity_ratio>", file);
	sprintf(data, "%f", target_liquidity_ratio);
	fputs(data, file);
	fputs("</target_liquidity_ratio>\n", file);
	fputs("<trading_activity>", file);
	sprintf(data, "%f", trading_activity);
	fputs(data, file);
	fputs("</trading_activity>\n", file);
	fputs("<BONDS_NEWISSUE_DISCOUNT>", file);
	sprintf(data, "%f", BONDS_NEWISSUE_DISCOUNT);
	fputs(data, file);
	fputs("</BONDS_NEWISSUE_DISCOUNT>\n", file);
	fputs("<gov_policy_unemployment_benefit_pct>", file);
	sprintf(data, "%f", gov_policy_unemployment_benefit_pct);
	fputs(data, file);
	fputs("</gov_policy_unemployment_benefit_pct>\n", file);
	fputs("<gov_policy_money_financing_fraction>", file);
	sprintf(data, "%f", gov_policy_money_financing_fraction);
	fputs(data, file);
	fputs("</gov_policy_money_financing_fraction>\n", file);
	fputs("<gov_policy_gdp_fraction_consumption>", file);
	sprintf(data, "%f", gov_policy_gdp_fraction_consumption);
	fputs(data, file);
	fputs("</gov_policy_gdp_fraction_consumption>\n", file);
	fputs("<gov_policy_gdp_fraction_investment>", file);
	sprintf(data, "%f", gov_policy_gdp_fraction_investment);
	fputs(data, file);
	fputs("</gov_policy_gdp_fraction_investment>\n", file);
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

current_xmachine_Clearinghouse_holder = Clearinghouse_end_Clearinghouse_state->agents;
	while(current_xmachine_Clearinghouse_holder)
	{
		write_Clearinghouse_agent(file, current_xmachine_Clearinghouse_holder->agent);
		
		current_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
	}

current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
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

current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
	while(current_xmachine_Central_Bank_holder)
	{
		write_Central_Bank_agent(file, current_xmachine_Central_Bank_holder->agent);
		
		current_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
	}
	
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
