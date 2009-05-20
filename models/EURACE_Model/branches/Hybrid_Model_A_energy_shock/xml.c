/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size)
{
	int arraycount;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		char_static_array[arraycount] = buffer[(*j)];
		(*j)++;
	}

	//(*j)++;
	return 0;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
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
	return 0;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array)
{
	if(*j > buffer_size) return -1;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
	
	return 0;
}


/** \fn void read_consumption_goods_offer(char * buffer, int * j, consumption_goods_offer * temp_datatype)
 * \brief Reads consumption_goods_offer datatype.
 */
int read_consumption_goods_offer(char * buffer, int buffer_size, int * j, consumption_goods_offer * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;

	return 0;
}

int read_consumption_goods_offer_dynamic_array(char * buffer, int buffer_size, int * j, consumption_goods_offer_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_consumption_goods_offer(temp_datatype_array, 0, 0.0, 0.0);
			rc = read_consumption_goods_offer(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'consumption_goods_offer' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_consumption_goods_offer_static_array(char * buffer, int buffer_size, int * j, consumption_goods_offer * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_consumption_goods_offer(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'consumption_goods_offer' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_consumption_request(char * buffer, int * j, consumption_request * temp_datatype)
 * \brief Reads consumption_request datatype.
 */
int read_consumption_request(char * buffer, int buffer_size, int * j, consumption_request * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).worker_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;

	return 0;
}

int read_consumption_request_dynamic_array(char * buffer, int buffer_size, int * j, consumption_request_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_consumption_request(temp_datatype_array, 0, 0, 0, 0.0);
			rc = read_consumption_request(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'consumption_request' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_consumption_request_static_array(char * buffer, int buffer_size, int * j, consumption_request * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_consumption_request(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'consumption_request' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_mall_info(char * buffer, int * j, mall_info * temp_datatype)
 * \brief Reads mall_info datatype.
 */
int read_mall_info(char * buffer, int buffer_size, int * j, mall_info * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_stock = atof(arraydata);
	(*j)++;

	return 0;
}

int read_mall_info_dynamic_array(char * buffer, int buffer_size, int * j, mall_info_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_info(temp_datatype_array, 0, 0.0, 0.0);
			rc = read_mall_info(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'mall_info' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_mall_info_static_array(char * buffer, int buffer_size, int * j, mall_info * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_mall_info(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'mall_info' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_mall_quality_price_info(char * buffer, int * j, mall_quality_price_info * temp_datatype)
 * \brief Reads mall_quality_price_info datatype.
 */
int read_mall_quality_price_info(char * buffer, int buffer_size, int * j, mall_quality_price_info * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).available = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_mall_quality_price_info_dynamic_array(char * buffer, int buffer_size, int * j, mall_quality_price_info_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_quality_price_info(temp_datatype_array, 0, 0, 0, 0.0, 0.0, 0);
			rc = read_mall_quality_price_info(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'mall_quality_price_info' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_mall_quality_price_info_static_array(char * buffer, int buffer_size, int * j, mall_quality_price_info * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_mall_quality_price_info(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'mall_quality_price_info' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_mall_stock(char * buffer, int * j, mall_stock * temp_datatype)
 * \brief Reads mall_stock datatype.
 */
int read_mall_stock(char * buffer, int buffer_size, int * j, mall_stock * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).previous_price = atof(arraydata);
	(*j)++;

	return 0;
}

int read_mall_stock_dynamic_array(char * buffer, int buffer_size, int * j, mall_stock_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_mall_stock(temp_datatype_array, 0, 0, 0.0, 0.0, 0.0, 0.0);
			rc = read_mall_stock(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'mall_stock' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_mall_stock_static_array(char * buffer, int buffer_size, int * j, mall_stock * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_mall_stock(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'mall_stock' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_delivery_volume_per_mall(char * buffer, int * j, delivery_volume_per_mall * temp_datatype)
 * \brief Reads delivery_volume_per_mall datatype.
 */
int read_delivery_volume_per_mall(char * buffer, int buffer_size, int * j, delivery_volume_per_mall * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quality = atof(arraydata);
	(*j)++;

	return 0;
}

int read_delivery_volume_per_mall_dynamic_array(char * buffer, int buffer_size, int * j, delivery_volume_per_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_delivery_volume_per_mall(temp_datatype_array, 0, 0.0, 0.0, 0.0);
			rc = read_delivery_volume_per_mall(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'delivery_volume_per_mall' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_delivery_volume_per_mall_static_array(char * buffer, int buffer_size, int * j, delivery_volume_per_mall * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_delivery_volume_per_mall(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'delivery_volume_per_mall' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_logit_firm_id(char * buffer, int * j, logit_firm_id * temp_datatype)
 * \brief Reads logit_firm_id datatype.
 */
int read_logit_firm_id(char * buffer, int buffer_size, int * j, logit_firm_id * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).logit = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_id = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_logit_firm_id_dynamic_array(char * buffer, int buffer_size, int * j, logit_firm_id_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_logit_firm_id(temp_datatype_array, 0.0, 0);
			rc = read_logit_firm_id(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'logit_firm_id' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_logit_firm_id_static_array(char * buffer, int buffer_size, int * j, logit_firm_id * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_logit_firm_id(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'logit_firm_id' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_sales_in_mall(char * buffer, int * j, sales_in_mall * temp_datatype)
 * \brief Reads sales_in_mall datatype.
 */
int read_sales_in_mall(char * buffer, int buffer_size, int * j, sales_in_mall * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;

	return 0;
}

int read_sales_in_mall_dynamic_array(char * buffer, int buffer_size, int * j, sales_in_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sales_in_mall(temp_datatype_array, 0, 0.0);
			rc = read_sales_in_mall(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'sales_in_mall' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_sales_in_mall_static_array(char * buffer, int buffer_size, int * j, sales_in_mall * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_sales_in_mall(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'sales_in_mall' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_ordered_quantity(char * buffer, int * j, ordered_quantity * temp_datatype)
 * \brief Reads ordered_quantity datatype.
 */
int read_ordered_quantity(char * buffer, int buffer_size, int * j, ordered_quantity * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).price = atof(arraydata);
	(*j)++;

	return 0;
}

int read_ordered_quantity_dynamic_array(char * buffer, int buffer_size, int * j, ordered_quantity_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ordered_quantity(temp_datatype_array, 0, 0.0, 0.0);
			rc = read_ordered_quantity(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'ordered_quantity' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_ordered_quantity_static_array(char * buffer, int buffer_size, int * j, ordered_quantity * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_ordered_quantity(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'ordered_quantity' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_received_quantities(char * buffer, int * j, received_quantities * temp_datatype)
 * \brief Reads received_quantities datatype.
 */
int read_received_quantities(char * buffer, int buffer_size, int * j, received_quantities * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atof(arraydata);
	(*j)++;

	return 0;
}

int read_received_quantities_dynamic_array(char * buffer, int buffer_size, int * j, received_quantities_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_received_quantities(temp_datatype_array, 0, 0.0);
			rc = read_received_quantities(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'received_quantities' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_received_quantities_static_array(char * buffer, int buffer_size, int * j, received_quantities * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_received_quantities(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'received_quantities' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_sold_quantities_per_mall(char * buffer, int * j, sold_quantities_per_mall * temp_datatype)
 * \brief Reads sold_quantities_per_mall datatype.
 */
int read_sold_quantities_per_mall(char * buffer, int buffer_size, int * j, sold_quantities_per_mall * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).estimated_demand = atof(arraydata);
	(*j)++;

	return 0;
}

int read_sold_quantities_per_mall_dynamic_array(char * buffer, int buffer_size, int * j, sold_quantities_per_mall_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sold_quantities_per_mall(temp_datatype_array, 0, 0.0, 0, 0.0);
			rc = read_sold_quantities_per_mall(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'sold_quantities_per_mall' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_sold_quantities_per_mall_static_array(char * buffer, int buffer_size, int * j, sold_quantities_per_mall * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_sold_quantities_per_mall(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'sold_quantities_per_mall' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_data_type_sales(char * buffer, int * j, data_type_sales * temp_datatype)
 * \brief Reads data_type_sales datatype.
 */
int read_data_type_sales(char * buffer, int buffer_size, int * j, data_type_sales * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).period = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;

	return 0;
}

int read_data_type_sales_dynamic_array(char * buffer, int buffer_size, int * j, data_type_sales_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_data_type_sales(temp_datatype_array, 0, 0.0);
			rc = read_data_type_sales(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'data_type_sales' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_data_type_sales_static_array(char * buffer, int buffer_size, int * j, data_type_sales * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_data_type_sales(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'data_type_sales' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_sales_statistics(char * buffer, int * j, sales_statistics * temp_datatype)
 * \brief Reads sales_statistics datatype.
 */
int read_sales_statistics(char * buffer, int buffer_size, int * j, sales_statistics * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).mall_id = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_data_type_sales_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).sales);
	if(rc != 0) return -1;
	
	(*j)++;

	return 0;
}

int read_sales_statistics_dynamic_array(char * buffer, int buffer_size, int * j, sales_statistics_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	data_type_sales_array sales; init_data_type_sales_array(&sales);

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_sales_statistics(temp_datatype_array, 0, &sales);
			rc = read_sales_statistics(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'sales_statistics' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_sales_statistics_static_array(char * buffer, int buffer_size, int * j, sales_statistics * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_sales_statistics(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'sales_statistics' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_financing_capital(char * buffer, int * j, financing_capital * temp_datatype)
 * \brief Reads financing_capital datatype.
 */
int read_financing_capital(char * buffer, int buffer_size, int * j, financing_capital * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).financing_per_month = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_periods_before_repayment = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_financing_capital_dynamic_array(char * buffer, int buffer_size, int * j, financing_capital_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_financing_capital(temp_datatype_array, 0.0, 0);
			rc = read_financing_capital(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'financing_capital' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_financing_capital_static_array(char * buffer, int buffer_size, int * j, financing_capital * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_financing_capital(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'financing_capital' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_temporary_sales_statistics(char * buffer, int * j, temporary_sales_statistics * temp_datatype)
 * \brief Reads temporary_sales_statistics datatype.
 */
int read_temporary_sales_statistics(char * buffer, int buffer_size, int * j, temporary_sales_statistics * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).mall_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).sales = atof(arraydata);
	(*j)++;

	return 0;
}

int read_temporary_sales_statistics_dynamic_array(char * buffer, int buffer_size, int * j, temporary_sales_statistics_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_temporary_sales_statistics(temp_datatype_array, 0, 0, 0.0);
			rc = read_temporary_sales_statistics(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'temporary_sales_statistics' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_temporary_sales_statistics_static_array(char * buffer, int buffer_size, int * j, temporary_sales_statistics * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_temporary_sales_statistics(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'temporary_sales_statistics' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_potential_lender(char * buffer, int * j, potential_lender * temp_datatype)
 * \brief Reads potential_lender datatype.
 */
int read_potential_lender(char * buffer, int buffer_size, int * j, potential_lender * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).bank_name = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).bank_name = atoi(arraydata);
	(*j)++;
	(*temp_datatype).contacted = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).contacted = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_potential_lender_dynamic_array(char * buffer, int buffer_size, int * j, potential_lender_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_potential_lender(temp_datatype_array, 0, 0);
			rc = read_potential_lender(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'potential_lender' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_potential_lender_static_array(char * buffer, int buffer_size, int * j, potential_lender * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_potential_lender(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'potential_lender' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_account_item(char * buffer, int * j, account_item * temp_datatype)
 * \brief Reads account_item datatype.
 */
int read_account_item(char * buffer, int buffer_size, int * j, account_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;

	return 0;
}

int read_account_item_dynamic_array(char * buffer, int buffer_size, int * j, account_item_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_account_item(temp_datatype_array, 0, 0.0);
			rc = read_account_item(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'account_item' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_account_item_static_array(char * buffer, int buffer_size, int * j, account_item * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_account_item(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'account_item' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_debt_item(char * buffer, int * j, debt_item * temp_datatype)
 * \brief Reads debt_item datatype.
 */
int read_debt_item(char * buffer, int buffer_size, int * j, debt_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).bank_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_periods_before_repayment = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_debt_item_dynamic_array(char * buffer, int buffer_size, int * j, debt_item_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_debt_item(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0);
			rc = read_debt_item(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'debt_item' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_debt_item_static_array(char * buffer, int buffer_size, int * j, debt_item * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_debt_item(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'debt_item' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_Order(char * buffer, int * j, Order * temp_datatype)
 * \brief Reads Order datatype.
 */
int read_Order(char * buffer, int buffer_size, int * j, Order * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).issuer = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).assetId = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_Order_dynamic_array(char * buffer, int buffer_size, int * j, Order_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Order(temp_datatype_array, 0, 0, 0.0, 0);
			rc = read_Order(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'Order' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_Order_static_array(char * buffer, int buffer_size, int * j, Order * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_Order(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'Order' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_Belief(char * buffer, int * j, Belief * temp_datatype)
 * \brief Reads Belief datatype.
 */
int read_Belief(char * buffer, int buffer_size, int * j, Belief * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).asset_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).utility = atof(arraydata);
	(*j)++;

	return 0;
}

int read_Belief_dynamic_array(char * buffer, int buffer_size, int * j, Belief_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Belief(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_Belief(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'Belief' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_Belief_static_array(char * buffer, int buffer_size, int * j, Belief * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_Belief(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'Belief' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_Stock(char * buffer, int * j, Stock * temp_datatype)
 * \brief Reads Stock datatype.
 */
int read_Stock(char * buffer, int buffer_size, int * j, Stock * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).index = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_double_static_array(buffer, buffer_size, j, (*temp_datatype).prices, 100);
		if(rc != 0) { printf("Error: reading variable 'prices' of type 'double'\n"); return -1; }
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_double_static_array(buffer, buffer_size, j, (*temp_datatype).returns, 100);
		if(rc != 0) { printf("Error: reading variable 'returns' of type 'double'\n"); return -1; }
	}
	
	(*j)++;

	return 0;
}

int read_Stock_dynamic_array(char * buffer, int buffer_size, int * j, Stock_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
		double prices[100]; init_double_static_array(prices, 100);
	
	
		double returns[100]; init_double_static_array(returns, 100);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Stock(temp_datatype_array, 0, 0, 0, prices, returns);
			rc = read_Stock(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'Stock' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_Stock_static_array(char * buffer, int buffer_size, int * j, Stock * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_Stock(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'Stock' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_Bond(char * buffer, int * j, Bond * temp_datatype)
 * \brief Reads Bond datatype.
 */
int read_Bond(char * buffer, int buffer_size, int * j, Bond * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).yield2maturity = atof(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_double_static_array(buffer, buffer_size, j, (*temp_datatype).prices, 100);
		if(rc != 0) { printf("Error: reading variable 'prices' of type 'double'\n"); return -1; }
	}
	
	(*j)++;
	(*temp_datatype).index = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).index = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		rc = read_double_static_array(buffer, buffer_size, j, (*temp_datatype).returns, 100);
		if(rc != 0) { printf("Error: reading variable 'returns' of type 'double'\n"); return -1; }
	}
	
	(*j)++;

	return 0;
}

int read_Bond_dynamic_array(char * buffer, int buffer_size, int * j, Bond_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
		double prices[100]; init_double_static_array(prices, 100);
	
	
	
	
		double returns[100]; init_double_static_array(returns, 100);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Bond(temp_datatype_array, 0, 0, 0, 0.0, 0.0, 0, 0, 0.0, prices, 0, returns);
			rc = read_Bond(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'Bond' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_Bond_static_array(char * buffer, int buffer_size, int * j, Bond * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_Bond(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'Bond' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_Asset(char * buffer, int * j, Asset * temp_datatype)
 * \brief Reads Asset datatype.
 */
int read_Asset(char * buffer, int buffer_size, int * j, Asset * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).lastPrice = atof(arraydata);
	(*j)++;

	return 0;
}

int read_Asset_dynamic_array(char * buffer, int buffer_size, int * j, Asset_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_Asset(temp_datatype_array, 0, 0, 0.0);
			rc = read_Asset(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'Asset' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_Asset_static_array(char * buffer, int buffer_size, int * j, Asset * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_Asset(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'Asset' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_ClearingMechanism(char * buffer, int * j, ClearingMechanism * temp_datatype)
 * \brief Reads ClearingMechanism datatype.
 */
int read_ClearingMechanism(char * buffer, int buffer_size, int * j, ClearingMechanism * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).lastPrice = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).quantity = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_Order_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).sellOrders);
	if(rc != 0) return -1;
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_Order_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).buyOrders);
	if(rc != 0) return -1;
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		while(buffer[*j] != '{') (*j)++;
		
		rc = read_double_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).prices);
		if(rc != 0) { printf("Error: reading variable 'prices' of type 'double_array'\n"); return -1; }
	}
	
	(*j)++;

	return 0;
}

int read_ClearingMechanism_dynamic_array(char * buffer, int buffer_size, int * j, ClearingMechanism_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	Order_array sellOrders; init_Order_array(&sellOrders);
	
	Order_array buyOrders; init_Order_array(&buyOrders);
	
	double_array prices; init_double_array(&prices);

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ClearingMechanism(temp_datatype_array, 0.0, 0, &sellOrders, &buyOrders, &prices);
			rc = read_ClearingMechanism(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'ClearingMechanism' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_ClearingMechanism_static_array(char * buffer, int buffer_size, int * j, ClearingMechanism * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_ClearingMechanism(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'ClearingMechanism' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_employee(char * buffer, int * j, employee * temp_datatype)
 * \brief Reads employee datatype.
 */
int read_employee(char * buffer, int buffer_size, int * j, employee * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).specific_skill = atof(arraydata);
	(*j)++;

	return 0;
}

int read_employee_dynamic_array(char * buffer, int buffer_size, int * j, employee_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_employee(temp_datatype_array, 0, 0, 0.0, 0, 0.0);
			rc = read_employee(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'employee' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_employee_static_array(char * buffer, int buffer_size, int * j, employee * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_employee(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'employee' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_vacancy(char * buffer, int * j, vacancy * temp_datatype)
 * \brief Reads vacancy datatype.
 */
int read_vacancy(char * buffer, int buffer_size, int * j, vacancy * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage_offer = atof(arraydata);
	(*j)++;

	return 0;
}

int read_vacancy_dynamic_array(char * buffer, int buffer_size, int * j, vacancy_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_vacancy(temp_datatype_array, 0, 0, 0.0);
			rc = read_vacancy(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'vacancy' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_vacancy_static_array(char * buffer, int buffer_size, int * j, vacancy * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_vacancy(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'vacancy' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_job_application(char * buffer, int * j, job_application * temp_datatype)
 * \brief Reads job_application datatype.
 */
int read_job_application(char * buffer, int buffer_size, int * j, job_application * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).worker_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).specific_skill = atof(arraydata);
	(*j)++;

	return 0;
}

int read_job_application_dynamic_array(char * buffer, int buffer_size, int * j, job_application_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_job_application(temp_datatype_array, 0, 0, 0, 0.0);
			rc = read_job_application(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'job_application' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_job_application_static_array(char * buffer, int buffer_size, int * j, job_application * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_job_application(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'job_application' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_job_offer(char * buffer, int * j, job_offer * temp_datatype)
 * \brief Reads job_offer datatype.
 */
int read_job_offer(char * buffer, int buffer_size, int * j, job_offer * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage_offer = atof(arraydata);
	(*j)++;

	return 0;
}

int read_job_offer_dynamic_array(char * buffer, int buffer_size, int * j, job_offer_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_job_offer(temp_datatype_array, 0, 0, 0.0);
			rc = read_job_offer(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'job_offer' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_job_offer_static_array(char * buffer, int buffer_size, int * j, job_offer * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_job_offer(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'job_offer' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_logit(char * buffer, int * j, logit * temp_datatype)
 * \brief Reads logit datatype.
 */
int read_logit(char * buffer, int buffer_size, int * j, logit * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).logit_value = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).general_skill = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_logit_dynamic_array(char * buffer, int buffer_size, int * j, logit_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_logit(temp_datatype_array, 0.0, 0, 0);
			rc = read_logit(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'logit' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_logit_static_array(char * buffer, int buffer_size, int * j, logit * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_logit(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'logit' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_household_data(char * buffer, int * j, household_data * temp_datatype)
 * \brief Reads household_data datatype.
 */
int read_household_data(char * buffer, int buffer_size, int * j, household_data * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).average_s_skill_5 = atof(arraydata);
	(*j)++;

	return 0;
}

int read_household_data_dynamic_array(char * buffer, int buffer_size, int * j, household_data_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_household_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_household_data(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'household_data' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_household_data_static_array(char * buffer, int buffer_size, int * j, household_data * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_household_data(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'household_data' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_firm_data(char * buffer, int * j, firm_data * temp_datatype)
 * \brief Reads firm_data datatype.
 */
int read_firm_data(char * buffer, int buffer_size, int * j, firm_data * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).region_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
	(*j)++;
	(*temp_datatype).productivity_progress = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).productivity_progress = atof(arraydata);
	(*j)++;
	(*temp_datatype).productivity = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).productivity = atof(arraydata);
	(*j)++;

	return 0;
}

int read_firm_data_dynamic_array(char * buffer, int buffer_size, int * j, firm_data_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0.0, 0.0);
			rc = read_firm_data(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'firm_data' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_firm_data_static_array(char * buffer, int buffer_size, int * j, firm_data * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_firm_data(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'firm_data' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_region_data_item(char * buffer, int * j, region_data_item * temp_datatype)
 * \brief Reads region_data_item datatype.
 */
int read_region_data_item(char * buffer, int buffer_size, int * j, region_data_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).cpi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
	(*j)++;

	return 0;
}

int read_region_data_item_dynamic_array(char * buffer, int buffer_size, int * j, region_data_item_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_region_data_item(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0);
			rc = read_region_data_item(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'region_data_item' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_region_data_item_static_array(char * buffer, int buffer_size, int * j, region_data_item * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_region_data_item(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'region_data_item' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_tax_rates_item(char * buffer, int * j, tax_rates_item * temp_datatype)
 * \brief Reads tax_rates_item datatype.
 */
int read_tax_rates_item(char * buffer, int buffer_size, int * j, tax_rates_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).gov_id = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_rate_vat = atof(arraydata);
	(*j)++;

	return 0;
}

int read_tax_rates_item_dynamic_array(char * buffer, int buffer_size, int * j, tax_rates_item_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_tax_rates_item(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0);
			rc = read_tax_rates_item(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'tax_rates_item' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_tax_rates_item_static_array(char * buffer, int buffer_size, int * j, tax_rates_item * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_tax_rates_item(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'tax_rates_item' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_history_item(char * buffer, int * j, history_item * temp_datatype)
 * \brief Reads history_item datatype.
 */
int read_history_item(char * buffer, int buffer_size, int * j, history_item * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	int rc;
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).cpi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
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
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).no_firm_deaths = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	rc = read_region_data_item_dynamic_array(buffer, buffer_size, j, &(*temp_datatype).region_data);
	if(rc != 0) return -1;
	
	(*j)++;

	return 0;
}

int read_history_item_dynamic_array(char * buffer, int buffer_size, int * j, history_item_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	region_data_item_array region_data; init_region_data_item_array(&region_data);

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_history_item(temp_datatype_array, 0.0, 0.0, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0, 0, 0, &region_data);
			rc = read_history_item(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'history_item' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_history_item_static_array(char * buffer, int buffer_size, int * j, history_item * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_history_item(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'history_item' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_firm_stocks_adt(char * buffer, int * j, firm_stocks_adt * temp_datatype)
 * \brief Reads firm_stocks_adt datatype.
 */
int read_firm_stocks_adt(char * buffer, int buffer_size, int * j, firm_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).payment_account = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_value_local_inventory = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_value_local_inventory = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_value_capital_stock = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_value_capital_stock = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).current_shares_outstanding = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_shares_outstanding = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_firm_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_stocks_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0, 0.0, 0.0);
			rc = read_firm_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'firm_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_firm_stocks_adt_static_array(char * buffer, int buffer_size, int * j, firm_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_firm_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'firm_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_firm_flows_adt(char * buffer, int * j, firm_flows_adt * temp_datatype)
 * \brief Reads firm_flows_adt datatype.
 */
int read_firm_flows_adt(char * buffer, int buffer_size, int * j, firm_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).cum_revenue = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cum_revenue = atof(arraydata);
	(*j)++;
	(*temp_datatype).labour_costs = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).labour_costs = atof(arraydata);
	(*j)++;
	(*temp_datatype).capital_costs = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).capital_costs = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt_installment_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt_installment_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_interest_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_interest_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_dividend_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_dividend_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_firm_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_firm_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'firm_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_firm_flows_adt_static_array(char * buffer, int buffer_size, int * j, firm_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_firm_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'firm_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_household_stocks_adt(char * buffer, int * j, household_stocks_adt * temp_datatype)
 * \brief Reads household_stocks_adt datatype.
 */
int read_household_stocks_adt(char * buffer, int buffer_size, int * j, household_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).payment_account = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;
	(*temp_datatype).gov_bond_holdings = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_bond_holdings = atof(arraydata);
	(*j)++;
	(*temp_datatype).nr_gov_bonds = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_gov_bonds = atoi(arraydata);
	(*j)++;
	(*temp_datatype).nr_firm_shares = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_firm_shares = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_household_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_household_stocks_adt(temp_datatype_array, 0.0, 0.0, 0, 0, 0.0, 0.0);
			rc = read_household_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'household_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_household_stocks_adt_static_array(char * buffer, int buffer_size, int * j, household_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_household_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'household_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_household_flows_adt(char * buffer, int * j, household_flows_adt * temp_datatype)
 * \brief Reads household_flows_adt datatype.
 */
int read_household_flows_adt(char * buffer, int buffer_size, int * j, household_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).wage = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).wage = atof(arraydata);
	(*j)++;
	(*temp_datatype).gov_interest = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_interest = atof(arraydata);
	(*j)++;
	(*temp_datatype).stock_sales = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).stock_sales = atof(arraydata);
	(*j)++;
	(*temp_datatype).cum_total_dividends = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cum_total_dividends = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_consumption_expenditure = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_consumption_expenditure = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).stock_purchases = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).stock_purchases = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_household_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_household_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_household_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'household_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_household_flows_adt_static_array(char * buffer, int buffer_size, int * j, household_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_household_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'household_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_igfirm_stocks_adt(char * buffer, int * j, igfirm_stocks_adt * temp_datatype)
 * \brief Reads igfirm_stocks_adt datatype.
 */
int read_igfirm_stocks_adt(char * buffer, int buffer_size, int * j, igfirm_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).payment_account = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).current_shares_outstanding = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_shares_outstanding = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_igfirm_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_igfirm_stocks_adt(temp_datatype_array, 0.0, 0.0, 0, 0.0, 0.0);
			rc = read_igfirm_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'igfirm_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_igfirm_stocks_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_igfirm_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'igfirm_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_igfirm_flows_adt(char * buffer, int * j, igfirm_flows_adt * temp_datatype)
 * \brief Reads igfirm_flows_adt datatype.
 */
int read_igfirm_flows_adt(char * buffer, int buffer_size, int * j, igfirm_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).cum_revenue = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cum_revenue = atof(arraydata);
	(*j)++;
	(*temp_datatype).labour_costs = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).labour_costs = atof(arraydata);
	(*j)++;
	(*temp_datatype).energy_costs = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).energy_costs = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_debt_installment_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_debt_installment_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_interest_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_interest_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_dividend_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_dividend_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_igfirm_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_igfirm_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_igfirm_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'igfirm_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_igfirm_flows_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_igfirm_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'igfirm_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_bank_stocks_adt(char * buffer, int * j, bank_stocks_adt * temp_datatype)
 * \brief Reads bank_stocks_adt datatype.
 */
int read_bank_stocks_adt(char * buffer, int buffer_size, int * j, bank_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).cash = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).cash = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_credit = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_credit = atof(arraydata);
	(*j)++;
	(*temp_datatype).deposits = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).deposits = atof(arraydata);
	(*j)++;
	(*temp_datatype).ecb_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).ecb_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_bank_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_bank_stocks_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_bank_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'bank_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_bank_stocks_adt_static_array(char * buffer, int buffer_size, int * j, bank_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_bank_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'bank_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_bank_flows_adt(char * buffer, int * j, bank_flows_adt * temp_datatype)
 * \brief Reads bank_flows_adt datatype.
 */
int read_bank_flows_adt(char * buffer, int buffer_size, int * j, bank_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).firm_loan_installments = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_loan_installments = atof(arraydata);
	(*j)++;
	(*temp_datatype).firm_interest_payments = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_interest_payments = atof(arraydata);
	(*j)++;
	(*temp_datatype).firm_loan_issues = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).firm_loan_issues = atof(arraydata);
	(*j)++;
	(*temp_datatype).ecb_interest_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).ecb_interest_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).dividend_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).dividend_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).tax_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).tax_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_bank_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_bank_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_bank_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'bank_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_bank_flows_adt_static_array(char * buffer, int buffer_size, int * j, bank_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_bank_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'bank_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_gov_stocks_adt(char * buffer, int * j, gov_stocks_adt * temp_datatype)
 * \brief Reads gov_stocks_adt datatype.
 */
int read_gov_stocks_adt(char * buffer, int buffer_size, int * j, gov_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).payment_account = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account = atof(arraydata);
	(*j)++;
	(*temp_datatype).value_bonds_outstanding = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).value_bonds_outstanding = atof(arraydata);
	(*j)++;
	(*temp_datatype).nr_bonds_outstanding = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_bonds_outstanding = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_gov_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_gov_stocks_adt(temp_datatype_array, 0.0, 0.0, 0, 0.0, 0.0);
			rc = read_gov_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'gov_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_gov_stocks_adt_static_array(char * buffer, int buffer_size, int * j, gov_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_gov_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'gov_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_gov_flows_adt(char * buffer, int * j, gov_flows_adt * temp_datatype)
 * \brief Reads gov_flows_adt datatype.
 */
int read_gov_flows_adt(char * buffer, int buffer_size, int * j, gov_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).monthly_tax_revenues = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_tax_revenues = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_bond_financing = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_bond_financing = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_investment_expenditure = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_investment_expenditure = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_consumption_expenditure = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_consumption_expenditure = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_benefit_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_benefit_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_subsidy_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_subsidy_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_transfer_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_transfer_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).monthly_bond_interest_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).monthly_bond_interest_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_gov_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_gov_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_gov_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'gov_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_gov_flows_adt_static_array(char * buffer, int buffer_size, int * j, gov_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_gov_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'gov_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_ecb_stocks_adt(char * buffer, int * j, ecb_stocks_adt * temp_datatype)
 * \brief Reads ecb_stocks_adt datatype.
 */
int read_ecb_stocks_adt(char * buffer, int buffer_size, int * j, ecb_stocks_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).gov_bond_holdings = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_bond_holdings = atof(arraydata);
	(*j)++;
	(*temp_datatype).nr_gov_bonds = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_gov_bonds = atoi(arraydata);
	(*j)++;
	(*temp_datatype).total_ecb_debt = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_ecb_debt = atof(arraydata);
	(*j)++;
	(*temp_datatype).payment_account_private_sector = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account_private_sector = atof(arraydata);
	(*j)++;
	(*temp_datatype).payment_account_public_sector = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).payment_account_public_sector = atof(arraydata);
	(*j)++;
	(*temp_datatype).fiat_money = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).fiat_money = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_assets = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_assets = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_liabilities = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_liabilities = atof(arraydata);
	(*j)++;

	return 0;
}

int read_ecb_stocks_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_stocks_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ecb_stocks_adt(temp_datatype_array, 0.0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_ecb_stocks_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'ecb_stocks_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_ecb_stocks_adt_static_array(char * buffer, int buffer_size, int * j, ecb_stocks_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_ecb_stocks_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'ecb_stocks_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_ecb_flows_adt(char * buffer, int * j, ecb_flows_adt * temp_datatype)
 * \brief Reads ecb_flows_adt datatype.
 */
int read_ecb_flows_adt(char * buffer, int buffer_size, int * j, ecb_flows_adt * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	(*temp_datatype).bank_interest = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).bank_interest = atof(arraydata);
	(*j)++;
	(*temp_datatype).gov_interest = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_interest = atof(arraydata);
	(*j)++;
	(*temp_datatype).gov_bond_purchase = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).gov_bond_purchase = atof(arraydata);
	(*j)++;
	(*temp_datatype).dividend_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).dividend_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_income = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_income = atof(arraydata);
	(*j)++;
	(*temp_datatype).total_expenses = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		if(buffer[(*j)] == '\0') return -1;
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).total_expenses = atof(arraydata);
	(*j)++;

	return 0;
}

int read_ecb_flows_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_flows_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	
	
	
	
	
	
	
	
	
	
	
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ecb_flows_adt(temp_datatype_array, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
			rc = read_ecb_flows_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'ecb_flows_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_ecb_flows_adt_static_array(char * buffer, int buffer_size, int * j, ecb_flows_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_ecb_flows_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'ecb_flows_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_firm_balance_sheet_adt(char * buffer, int * j, firm_balance_sheet_adt * temp_datatype)
 * \brief Reads firm_balance_sheet_adt datatype.
 */
int read_firm_balance_sheet_adt(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_firm_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_firm_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_firm_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	firm_stocks_adt stocks; init_firm_stocks_adt(&stocks);
	
	firm_flows_adt flows; init_firm_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_firm_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'firm_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_firm_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, firm_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_firm_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'firm_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_household_balance_sheet_adt(char * buffer, int * j, household_balance_sheet_adt * temp_datatype)
 * \brief Reads household_balance_sheet_adt datatype.
 */
int read_household_balance_sheet_adt(char * buffer, int buffer_size, int * j, household_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_household_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_household_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_household_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, household_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	household_stocks_adt stocks; init_household_stocks_adt(&stocks);
	
	household_flows_adt flows; init_household_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_household_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_household_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'household_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_household_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, household_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_household_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'household_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_igfirm_balance_sheet_adt(char * buffer, int * j, igfirm_balance_sheet_adt * temp_datatype)
 * \brief Reads igfirm_balance_sheet_adt datatype.
 */
int read_igfirm_balance_sheet_adt(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_igfirm_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_igfirm_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_igfirm_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	igfirm_stocks_adt stocks; init_igfirm_stocks_adt(&stocks);
	
	igfirm_flows_adt flows; init_igfirm_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_igfirm_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_igfirm_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'igfirm_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_igfirm_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, igfirm_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_igfirm_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'igfirm_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_bank_balance_sheet_adt(char * buffer, int * j, bank_balance_sheet_adt * temp_datatype)
 * \brief Reads bank_balance_sheet_adt datatype.
 */
int read_bank_balance_sheet_adt(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_bank_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_bank_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_bank_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	bank_stocks_adt stocks; init_bank_stocks_adt(&stocks);
	
	bank_flows_adt flows; init_bank_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_bank_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_bank_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'bank_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_bank_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, bank_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_bank_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'bank_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_gov_balance_sheet_adt(char * buffer, int * j, gov_balance_sheet_adt * temp_datatype)
 * \brief Reads gov_balance_sheet_adt datatype.
 */
int read_gov_balance_sheet_adt(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_gov_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_gov_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_gov_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	gov_stocks_adt stocks; init_gov_stocks_adt(&stocks);
	
	gov_flows_adt flows; init_gov_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_gov_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_gov_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'gov_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_gov_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, gov_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_gov_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'gov_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}

/** \fn void read_ecb_balance_sheet_adt(char * buffer, int * j, ecb_balance_sheet_adt * temp_datatype)
 * \brief Reads ecb_balance_sheet_adt datatype.
 */
int read_ecb_balance_sheet_adt(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt * temp_datatype)
{
	
	
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[*j] != '{') (*j)++;
	read_ecb_stocks_adt(buffer, buffer_size, j, &(*temp_datatype).stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_ecb_flows_adt(buffer, buffer_size, j, &(*temp_datatype).flows);
	(*j)++;

	return 0;
}

int read_ecb_balance_sheet_adt_dynamic_array(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt_array * temp_datatype_array)
{
	int arraycount = 0;
	int rc;
	
	ecb_stocks_adt stocks; init_ecb_stocks_adt(&stocks);
	
	ecb_flows_adt flows; init_ecb_flows_adt(&flows);
	

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ecb_balance_sheet_adt(temp_datatype_array, &stocks, &flows);
			rc = read_ecb_balance_sheet_adt(buffer, buffer_size, j, &(*temp_datatype_array).array[arraycount]);
			if(rc != 0) { printf("Error: reading variable 'ecb_balance_sheet_adt' of type '\n"); return -1; }
			arraycount++;
			(*j)++;
		}
		while(buffer[(*j)] != '}' && buffer[(*j)] != '\0' && buffer[(*j)] != '{') { (*j)++; }
	}

	return 0;
}

int read_ecb_balance_sheet_adt_static_array(char * buffer, int buffer_size, int * j, ecb_balance_sheet_adt * temp_datatype_array, int size)
{
	int arraycount;
	int rc;

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	for(arraycount = 0; arraycount < size; arraycount++)
	{
		rc = read_ecb_balance_sheet_adt(buffer, buffer_size, j, &temp_datatype_array[arraycount]);
		if(rc != 0) { printf("Error: reading variable 'ecb_balance_sheet_adt' of type '\n"); return -1; }
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}

	(*j)++;
	return 0;
}



int readEnvironmentXML(char * location)
{
	FILE * file;
	char c = '\0';
	char buffer[10000];
	int index = 0;
	int in_environment = 0;
	int in_print_log = 0;
	int in_print_debug = 0;
	int in_number_of_banks_to_apply = 0;
	int in_gamma_const = 0;
	int in_alpha = 0;
	int in_beta = 0;
	int in_depreciation_rate = 0;
	int in_discount_rate = 0;
	int in_teta = 0;
	int in_mark_up = 0;
	int in_lambda = 0;
	int in_wage_update = 0;
	int in_min_vacancy = 0;
	int in_wage_reservation_update = 0;
	int in_region_cost = 0;
	int in_inventory_costs_per_unit = 0;
	int in_on_the_job_search_rate = 0;
	int in_initial_consumption_propensity = 0;
	int in_consumption_propensity = 0;
	int in_firm_planning_horizon = 0;
	int in_inv_inertia = 0;
	int in_adaption_delivery_volume = 0;
	int in_delivery_prob_if_critical_stock_0 = 0;
	int in_innovation_probability = 0;
	int in_productivity_progress = 0;
	int in_lower_bound_firing = 0;
	int in_upper_bound_firing = 0;
	int in_const_bankruptcy_idle_period = 0;
	int in_const_installment_periods = 0;
	int in_const_firm_leverage = 0;
	int in_const_number_of_banks = 0;
	int in_switch_stock_consistency_check = 0;
	int in_switch_flow_consistency_check = 0;
	int in_debt_rescaling_factor = 0;
	int in_target_leverage_ratio = 0;
	int in_target_liquidity_ratio = 0;
	int in_const_dividend_earnings_ratio = 0;
	int in_discrete_shock = 0;
	int in_energy_shock_start = 0;
	int in_energy_shock_end = 0;
	int in_const_energy_price_markup = 0;
	int in_energy_shock_frequency = 0;
	int in_gov_policy_unemployment_benefit_pct = 0;
	int in_gov_policy_money_financing_fraction = 0;
	int in_gov_policy_gdp_fraction_consumption = 0;
	int in_gov_policy_gdp_fraction_investment = 0;
	int in_no_regions_per_gov = 0;
	

	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading environment data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			if(strcmp(buffer, "print_log") == 0) in_print_log = 1;
			if(strcmp(buffer, "/print_log") == 0) in_print_log = 0;
			if(strcmp(buffer, "print_debug") == 0) in_print_debug = 1;
			if(strcmp(buffer, "/print_debug") == 0) in_print_debug = 0;
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
			if(strcmp(buffer, "delivery_prob_if_critical_stock_0") == 0) in_delivery_prob_if_critical_stock_0 = 1;
			if(strcmp(buffer, "/delivery_prob_if_critical_stock_0") == 0) in_delivery_prob_if_critical_stock_0 = 0;
			if(strcmp(buffer, "innovation_probability") == 0) in_innovation_probability = 1;
			if(strcmp(buffer, "/innovation_probability") == 0) in_innovation_probability = 0;
			if(strcmp(buffer, "productivity_progress") == 0) in_productivity_progress = 1;
			if(strcmp(buffer, "/productivity_progress") == 0) in_productivity_progress = 0;
			if(strcmp(buffer, "lower_bound_firing") == 0) in_lower_bound_firing = 1;
			if(strcmp(buffer, "/lower_bound_firing") == 0) in_lower_bound_firing = 0;
			if(strcmp(buffer, "upper_bound_firing") == 0) in_upper_bound_firing = 1;
			if(strcmp(buffer, "/upper_bound_firing") == 0) in_upper_bound_firing = 0;
			if(strcmp(buffer, "const_bankruptcy_idle_period") == 0) in_const_bankruptcy_idle_period = 1;
			if(strcmp(buffer, "/const_bankruptcy_idle_period") == 0) in_const_bankruptcy_idle_period = 0;
			if(strcmp(buffer, "const_installment_periods") == 0) in_const_installment_periods = 1;
			if(strcmp(buffer, "/const_installment_periods") == 0) in_const_installment_periods = 0;
			if(strcmp(buffer, "const_firm_leverage") == 0) in_const_firm_leverage = 1;
			if(strcmp(buffer, "/const_firm_leverage") == 0) in_const_firm_leverage = 0;
			if(strcmp(buffer, "const_number_of_banks") == 0) in_const_number_of_banks = 1;
			if(strcmp(buffer, "/const_number_of_banks") == 0) in_const_number_of_banks = 0;
			if(strcmp(buffer, "switch_stock_consistency_check") == 0) in_switch_stock_consistency_check = 1;
			if(strcmp(buffer, "/switch_stock_consistency_check") == 0) in_switch_stock_consistency_check = 0;
			if(strcmp(buffer, "switch_flow_consistency_check") == 0) in_switch_flow_consistency_check = 1;
			if(strcmp(buffer, "/switch_flow_consistency_check") == 0) in_switch_flow_consistency_check = 0;
			if(strcmp(buffer, "debt_rescaling_factor") == 0) in_debt_rescaling_factor = 1;
			if(strcmp(buffer, "/debt_rescaling_factor") == 0) in_debt_rescaling_factor = 0;
			if(strcmp(buffer, "target_leverage_ratio") == 0) in_target_leverage_ratio = 1;
			if(strcmp(buffer, "/target_leverage_ratio") == 0) in_target_leverage_ratio = 0;
			if(strcmp(buffer, "target_liquidity_ratio") == 0) in_target_liquidity_ratio = 1;
			if(strcmp(buffer, "/target_liquidity_ratio") == 0) in_target_liquidity_ratio = 0;
			if(strcmp(buffer, "const_dividend_earnings_ratio") == 0) in_const_dividend_earnings_ratio = 1;
			if(strcmp(buffer, "/const_dividend_earnings_ratio") == 0) in_const_dividend_earnings_ratio = 0;
			if(strcmp(buffer, "discrete_shock") == 0) in_discrete_shock = 1;
			if(strcmp(buffer, "/discrete_shock") == 0) in_discrete_shock = 0;
			if(strcmp(buffer, "energy_shock_start") == 0) in_energy_shock_start = 1;
			if(strcmp(buffer, "/energy_shock_start") == 0) in_energy_shock_start = 0;
			if(strcmp(buffer, "energy_shock_end") == 0) in_energy_shock_end = 1;
			if(strcmp(buffer, "/energy_shock_end") == 0) in_energy_shock_end = 0;
			if(strcmp(buffer, "const_energy_price_markup") == 0) in_const_energy_price_markup = 1;
			if(strcmp(buffer, "/const_energy_price_markup") == 0) in_const_energy_price_markup = 0;
			if(strcmp(buffer, "energy_shock_frequency") == 0) in_energy_shock_frequency = 1;
			if(strcmp(buffer, "/energy_shock_frequency") == 0) in_energy_shock_frequency = 0;
			if(strcmp(buffer, "gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 1;
			if(strcmp(buffer, "/gov_policy_unemployment_benefit_pct") == 0) in_gov_policy_unemployment_benefit_pct = 0;
			if(strcmp(buffer, "gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 1;
			if(strcmp(buffer, "/gov_policy_money_financing_fraction") == 0) in_gov_policy_money_financing_fraction = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_consumption") == 0) in_gov_policy_gdp_fraction_consumption = 0;
			if(strcmp(buffer, "gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 1;
			if(strcmp(buffer, "/gov_policy_gdp_fraction_investment") == 0) in_gov_policy_gdp_fraction_investment = 0;
			if(strcmp(buffer, "no_regions_per_gov") == 0) in_no_regions_per_gov = 1;
			if(strcmp(buffer, "/no_regions_per_gov") == 0) in_no_regions_per_gov = 0;
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(in_environment)
			{
				if(in_print_log) { FLAME_environment_variable_print_log = atoi(buffer); }
				if(in_print_debug) { FLAME_environment_variable_print_debug = atoi(buffer); }
				if(in_number_of_banks_to_apply) { FLAME_environment_variable_number_of_banks_to_apply = atoi(buffer); }
				if(in_gamma_const) { FLAME_environment_variable_gamma_const = atof(buffer); }
				if(in_alpha) { FLAME_environment_variable_alpha = atof(buffer); }
				if(in_beta) { FLAME_environment_variable_beta = atof(buffer); }
				if(in_depreciation_rate) { FLAME_environment_variable_depreciation_rate = atof(buffer); }
				if(in_discount_rate) { FLAME_environment_variable_discount_rate = atof(buffer); }
				if(in_teta) { FLAME_environment_variable_teta = atof(buffer); }
				if(in_mark_up) { FLAME_environment_variable_mark_up = atof(buffer); }
				if(in_lambda) { FLAME_environment_variable_lambda = atof(buffer); }
				if(in_wage_update) { FLAME_environment_variable_wage_update = atof(buffer); }
				if(in_min_vacancy) { FLAME_environment_variable_min_vacancy = atoi(buffer); }
				if(in_wage_reservation_update) { FLAME_environment_variable_wage_reservation_update = atof(buffer); }
				if(in_region_cost) { FLAME_environment_variable_region_cost = atof(buffer); }
				if(in_inventory_costs_per_unit) { FLAME_environment_variable_inventory_costs_per_unit = atof(buffer); }
				if(in_on_the_job_search_rate) { FLAME_environment_variable_on_the_job_search_rate = atof(buffer); }
				if(in_initial_consumption_propensity) { FLAME_environment_variable_initial_consumption_propensity = atof(buffer); }
				if(in_consumption_propensity) { FLAME_environment_variable_consumption_propensity = atof(buffer); }
				if(in_firm_planning_horizon) { FLAME_environment_variable_firm_planning_horizon = atoi(buffer); }
				if(in_inv_inertia) { FLAME_environment_variable_inv_inertia = atof(buffer); }
				if(in_adaption_delivery_volume) { FLAME_environment_variable_adaption_delivery_volume = atof(buffer); }
				if(in_delivery_prob_if_critical_stock_0) { FLAME_environment_variable_delivery_prob_if_critical_stock_0 = atof(buffer); }
				if(in_innovation_probability) { FLAME_environment_variable_innovation_probability = atof(buffer); }
				if(in_productivity_progress) { FLAME_environment_variable_productivity_progress = atof(buffer); }
				if(in_lower_bound_firing) { FLAME_environment_variable_lower_bound_firing = atoi(buffer); }
				if(in_upper_bound_firing) { FLAME_environment_variable_upper_bound_firing = atoi(buffer); }
				if(in_const_bankruptcy_idle_period) { FLAME_environment_variable_const_bankruptcy_idle_period = atoi(buffer); }
				if(in_const_installment_periods) { FLAME_environment_variable_const_installment_periods = atoi(buffer); }
				if(in_const_firm_leverage) { FLAME_environment_variable_const_firm_leverage = atof(buffer); }
				if(in_const_number_of_banks) { FLAME_environment_variable_const_number_of_banks = atoi(buffer); }
				if(in_switch_stock_consistency_check) { FLAME_environment_variable_switch_stock_consistency_check = atoi(buffer); }
				if(in_switch_flow_consistency_check) { FLAME_environment_variable_switch_flow_consistency_check = atoi(buffer); }
				if(in_debt_rescaling_factor) { FLAME_environment_variable_debt_rescaling_factor = atof(buffer); }
				if(in_target_leverage_ratio) { FLAME_environment_variable_target_leverage_ratio = atof(buffer); }
				if(in_target_liquidity_ratio) { FLAME_environment_variable_target_liquidity_ratio = atof(buffer); }
				if(in_const_dividend_earnings_ratio) { FLAME_environment_variable_const_dividend_earnings_ratio = atof(buffer); }
				if(in_discrete_shock) { FLAME_environment_variable_discrete_shock = atoi(buffer); }
				if(in_energy_shock_start) { FLAME_environment_variable_energy_shock_start = atoi(buffer); }
				if(in_energy_shock_end) { FLAME_environment_variable_energy_shock_end = atoi(buffer); }
				if(in_const_energy_price_markup) { FLAME_environment_variable_const_energy_price_markup = atof(buffer); }
				if(in_energy_shock_frequency) { FLAME_environment_variable_energy_shock_frequency = atoi(buffer); }
				if(in_gov_policy_unemployment_benefit_pct) { FLAME_environment_variable_gov_policy_unemployment_benefit_pct = atof(buffer); }
				if(in_gov_policy_money_financing_fraction) { FLAME_environment_variable_gov_policy_money_financing_fraction = atof(buffer); }
				if(in_gov_policy_gdp_fraction_consumption) { FLAME_environment_variable_gov_policy_gdp_fraction_consumption = atof(buffer); }
				if(in_gov_policy_gdp_fraction_investment) { FLAME_environment_variable_gov_policy_gdp_fraction_investment = atof(buffer); }
				if(in_no_regions_per_gov) { FLAME_environment_variable_no_regions_per_gov = atoi(buffer); }
				
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 999) index++;
		}
	}
	/* Close file */
	fclose(file);

	return 0;
}

int readAgentXML(char * location,
				double cloud_data[6],
				int partition_method,
				int flag,
				int number_partitions,
				int agent_count)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	char agentname[10000];
	int index = 0;
	int j = 0; /* Index for reading arrays */
	int rc;
	int FLAME_in_xagent = 0;
	int FLAME_in_name = 0;
	int in_Firm_agent = 0;
	int in_Household_agent = 0;
	int in_Mall_agent = 0;
	int in_IGFirm_agent = 0;
	int in_Eurostat_agent = 0;
	int in_Bank_agent = 0;
	int in_Government_agent = 0;
	int in_Central_Bank_agent = 0;
	int in_Clearinghouse_agent = 0;
	
	int in_id = 0;
	int in_region_id = 0;
	int in_gov_id = 0;
	int in_day_of_month_to_act = 0;
	int in_last_day_of_month_to_act = 0;
	int in_payment_account = 0;
	int in_bank_id = 0;
	int in_partition_id = 0;
	int in_mean_wage = 0;
	int in_needed_capital_stock = 0;
	int in_actual_cap_price = 0;
	int in_mean_specific_skills = 0;
	int in_planned_production_quantity = 0;
	int in_production_quantity = 0;
	int in_planned_output = 0;
	int in_output = 0;
	int in_unit_costs = 0;
	int in_total_supply = 0;
	int in_production_costs = 0;
	int in_revenue_per_day = 0;
	int in_technological_frontier = 0;
	int in_cum_revenue = 0;
	int in_out_of_stock_costs = 0;
	int in_malls_sales_statistics = 0;
	int in_quality = 0;
	int in_price = 0;
	int in_price_last_month = 0;
	int in_demand_capital_stock = 0;
	int in_planned_production_costs = 0;
	int in_adaption_production_volume_due_to_insufficient_finances = 0;
	int in_fraction_reserved_for_delayed_payments = 0;
	int in_sold_quantities = 0;
	int in_total_sold_quantity = 0;
	int in_cum_total_sold_quantity = 0;
	int in_sold_quantity_in_calendar_month = 0;
	int in_delivery_volume = 0;
	int in_planned_delivery_volume = 0;
	int in_current_mall_stocks = 0;
	int in_last_planned_production_quantities = 0;
	int in_total_external_financing_obtained = 0;
	int in_capital_costs = 0;
	int in_labour_costs = 0;
	int in_capital_financing = 0;
	int in_financial_resources_for_production = 0;
	int in_planned_value_capital_stock = 0;
	int in_total_units_local_inventory = 0;
	int in_calc_capital_costs = 0;
	int in_calc_production_costs = 0;
	int in_firm_productivity = 0;
	int in_firm_productivity_last_year = 0;
	int in_firm_productivity_progress = 0;
	int in_set_of_lenders = 0;
	int in_number_of_banks_asked = 0;
	int in_ebit = 0;
	int in_earnings = 0;
	int in_tax_rate_corporate = 0;
	int in_tax_rate_vat = 0;
	int in_tax_payment = 0;
	int in_net_earnings = 0;
	int in_previous_net_earnings = 0;
	int in_total_interest_payment = 0;
	int in_total_debt_installment_payment = 0;
	int in_total_dividend_payment = 0;
	int in_current_share_price = 0;
	int in_previous_dividend_per_share = 0;
	int in_current_dividend_per_share = 0;
	int in_previous_earnings_per_share = 0;
	int in_current_earnings_per_share = 0;
	int in_previous_dividend_per_earnings = 0;
	int in_current_dividend_per_earnings = 0;
	int in_debt_earnings_ratio = 0;
	int in_debt_equity_ratio = 0;
	int in_price_earnings_ratio = 0;
	int in_retained_earnings_ratio = 0;
	int in_earnings_per_share_ratio_growth = 0;
	int in_critical_price_earnings_ratio = 0;
	int in_critical_earnings_per_share_ratio = 0;
	int in_loans = 0;
	int in_total_debt = 0;
	int in_total_value_local_inventory = 0;
	int in_total_units_capital_stock = 0;
	int in_total_value_capital_stock = 0;
	int in_total_capital_depreciation_value = 0;
	int in_total_capital_depreciation_units = 0;
	int in_total_assets = 0;
	int in_equity = 0;
	int in_production_liquidity_needs = 0;
	int in_financial_liquidity_needs = 0;
	int in_total_financial_needs = 0;
	int in_external_financial_needs = 0;
	int in_earnings_per_share = 0;
	int in_total_payments = 0;
	int in_previous_shares_outstanding = 0;
	int in_total_income = 0;
	int in_total_liabilities = 0;
	int in_total_expenses = 0;
	int in_current_shares_outstanding = 0;
	int in_employees = 0;
	int in_wage_offer = 0;
	int in_technology = 0;
	int in_no_employees = 0;
	int in_no_employees_skill_1 = 0;
	int in_no_employees_skill_2 = 0;
	int in_no_employees_skill_3 = 0;
	int in_no_employees_skill_4 = 0;
	int in_no_employees_skill_5 = 0;
	int in_vacancies = 0;
	int in_average_g_skill = 0;
	int in_average_s_skill_of_1 = 0;
	int in_average_s_skill_of_2 = 0;
	int in_average_s_skill_of_3 = 0;
	int in_average_s_skill_of_4 = 0;
	int in_average_s_skill_of_5 = 0;
	int in_wage_offer_for_skill_1 = 0;
	int in_wage_offer_for_skill_2 = 0;
	int in_wage_offer_for_skill_3 = 0;
	int in_wage_offer_for_skill_4 = 0;
	int in_wage_offer_for_skill_5 = 0;
	int in_employees_needed = 0;
	int in_age = 0;
	int in_transfer_payment = 0;
	int in_subsidy_payment = 0;
	int in_active = 0;
	int in_bankruptcy_idle_counter = 0;
	int in_bankruptcy_state = 0;
	int in_bankruptcy_insolvency_state = 0;
	int in_bankruptcy_illiquidity_state = 0;
	int in_financial_crisis_state = 0;
	int in_neighboring_region_ids = 0;
	int in_consumption_budget = 0;
	int in_mean_income = 0;
	int in_week_of_month = 0;
	int in_weekly_budget = 0;
	int in_rationed = 0;
	int in_mall_completely_sold_out = 0;
	int in_order_quantity = 0;
	int in_received_quantity = 0;
	int in_day_of_week_to_act = 0;
	int in_day_of_month_receive_income = 0;
	int in_current_productivity_employer = 0;
	int in_current_mean_specific_skills_employer = 0;
	int in_cum_total_dividends = 0;
	int in_tax_rate_hh_capital = 0;
	int in_tax_rate_hh_labour = 0;
	int in_price_index = 0;
	int in_price_index_base_period = 0;
	int in_commuting_costs_price_level_weight = 0;
	int in_last_income = 0;
	int in_expenditures = 0;
	int in_received_dividend = 0;
	int in_flag_consumption_shifting = 0;
	int in_excess_weekly_budget = 0;
	int in_assetsowned = 0;
	int in_wage = 0;
	int in_wage_reservation = 0;
	int in_general_skill = 0;
	int in_on_the_job_search = 0;
	int in_number_applications = 0;
	int in_last_labour_income = 0;
	int in_specific_skill = 0;
	int in_employee_firm_id = 0;
	int in_employer_region_id = 0;
	int in_day_of_month_receive_benefit = 0;
	int in_unemployment_benefit_pct = 0;
	int in_gov_interest = 0;
	int in_stock_sales = 0;
	int in_stock_purchases = 0;
	int in_gov_bond_purchases = 0;
	int in_monthly_consumption_expenditure = 0;
	int in_gov_bond_holdings = 0;
	int in_nr_gov_bonds = 0;
	int in_nr_firm_shares = 0;
	int in_no_regions = 0;
	int in_current_stock = 0;
	int in_firm_revenues = 0;
	int in_export_volume_matrix = 0;
	int in_export_value_matrix = 0;
	int in_export_previous_value_matrix = 0;
	int in_productivity = 0;
	int in_capital_good_price = 0;
	int in_net_profit = 0;
	int in_outstanding_shares = 0;
	int in_energy_price_markup = 0;
	int in_energy_costs_per_day = 0;
	int in_earnings_per_day = 0;
	int in_cum_energy_costs = 0;
	int in_switch_datastorage = 0;
	int in_num_households = 0;
	int in_no_households_skill_1 = 0;
	int in_no_households_skill_2 = 0;
	int in_no_households_skill_3 = 0;
	int in_no_households_skill_4 = 0;
	int in_no_households_skill_5 = 0;
	int in_employed = 0;
	int in_employed_skill_1 = 0;
	int in_employed_skill_2 = 0;
	int in_employed_skill_3 = 0;
	int in_employed_skill_4 = 0;
	int in_employed_skill_5 = 0;
	int in_unemployed = 0;
	int in_unemployment_rate = 0;
	int in_unemployment_rate_skill_1 = 0;
	int in_unemployment_rate_skill_2 = 0;
	int in_unemployment_rate_skill_3 = 0;
	int in_unemployment_rate_skill_4 = 0;
	int in_unemployment_rate_skill_5 = 0;
	int in_average_wage = 0;
	int in_average_wage_skill_1 = 0;
	int in_average_wage_skill_2 = 0;
	int in_average_wage_skill_3 = 0;
	int in_average_wage_skill_4 = 0;
	int in_average_wage_skill_5 = 0;
	int in_average_s_skill = 0;
	int in_average_s_skill_1 = 0;
	int in_average_s_skill_2 = 0;
	int in_average_s_skill_3 = 0;
	int in_average_s_skill_4 = 0;
	int in_average_s_skill_5 = 0;
	int in_no_firms = 0;
	int in_no_vacancies = 0;
	int in_firm_average_wage = 0;
	int in_firm_average_wage_skill_1 = 0;
	int in_firm_average_wage_skill_2 = 0;
	int in_firm_average_wage_skill_3 = 0;
	int in_firm_average_wage_skill_4 = 0;
	int in_firm_average_wage_skill_5 = 0;
	int in_firm_average_s_skill = 0;
	int in_firm_average_s_skill_1 = 0;
	int in_firm_average_s_skill_2 = 0;
	int in_firm_average_s_skill_3 = 0;
	int in_firm_average_s_skill_4 = 0;
	int in_firm_average_s_skill_5 = 0;
	int in_region_firm_data = 0;
	int in_region_household_data = 0;
	int in_government_tax_rates = 0;
	int in_total_earnings = 0;
	int in_total_equity = 0;
	int in_average_debt_earnings_ratio = 0;
	int in_average_debt_equity_ratio = 0;
	int in_labour_share_ratio = 0;
	int in_cpi = 0;
	int in_gdp = 0;
	int in_monthly_sold_quantity = 0;
	int in_monthly_output = 0;
	int in_monthly_revenue = 0;
	int in_monthly_planned_output = 0;
	int in_history_monthly = 0;
	int in_history_quarterly = 0;
	int in_monthly_growth_rates = 0;
	int in_quarterly_growth_rates = 0;
	int in_annual_growth_rates_monthly = 0;
	int in_annual_growth_rates_quarterly = 0;
	int in_no_firm_births = 0;
	int in_no_firm_deaths = 0;
	int in_firm_age_distribution = 0;
	int in_firm_age_distribution_multiperiod = 0;
	int in_firm_age_distribution_1_period_lag = 0;
	int in_firm_age_distribution_2_period_lag = 0;
	int in_firm_birth_rate = 0;
	int in_firm_death_rate = 0;
	int in_survival_rate = 0;
	int in_survival_rate_multiperiod_1 = 0;
	int in_survival_rate_multiperiod_2 = 0;
	int in_survival_rate_multiperiod = 0;
	int in_max_firm_creation = 0;
	int in_recession_started = 0;
	int in_recession_duration = 0;
	int in_region_export_volume = 0;
	int in_region_import_volume = 0;
	int in_region_export_value = 0;
	int in_region_import_value = 0;
	int in_region_import_previous_value = 0;
	int in_firm_balance_sheets = 0;
	int in_household_balance_sheets = 0;
	int in_igfirm_balance_sheets = 0;
	int in_gov_balance_sheets = 0;
	int in_bank_balance_sheets = 0;
	int in_ecb_balance_sheets = 0;
	int in_firm_average_productivity_progress = 0;
	int in_firm_average_productivity = 0;
	int in_cash = 0;
	int in_total_credit = 0;
	int in_ecb_debt = 0;
	int in_alfa = 0;
	int in_value_at_risk = 0;
	int in_bank_gamma = 0;
	int in_profits = 0;
	int in_bank_lambda = 0;
	int in_ecb_interest_rate = 0;
	int in_bank_dividend_rate = 0;
	int in_debt_period = 0;
	int in_loan_request_message_found = 0;
	int in_deposits = 0;
	int in_firm_loan_installments = 0;
	int in_firm_interest_payments = 0;
	int in_firm_loan_issues = 0;
	int in_ecb_interest_payment = 0;
	int in_dividend_payment = 0;
	int in_taxes = 0;
	int in_list_of_regions = 0;
	int in_money_financing_fraction = 0;
	int in_gdp_fraction_consumption = 0;
	int in_gdp_fraction_investment = 0;
	int in_monthly_tax_revenues = 0;
	int in_yearly_tax_revenues = 0;
	int in_monthly_benefit_payment = 0;
	int in_yearly_benefit_payment = 0;
	int in_hh_transfer_payment = 0;
	int in_firm_transfer_payment = 0;
	int in_monthly_transfer_payment = 0;
	int in_yearly_transfer_payment = 0;
	int in_hh_subsidy_payment = 0;
	int in_firm_subsidy_payment = 0;
	int in_monthly_subsidy_payment = 0;
	int in_yearly_subsidy_payment = 0;
	int in_monthly_bond_interest_payment = 0;
	int in_yearly_bond_interest_payment = 0;
	int in_gov_interest_rate = 0;
	int in_yearly_investment_expenditure = 0;
	int in_yearly_consumption_expenditure = 0;
	int in_yearly_income = 0;
	int in_yearly_expenditure = 0;
	int in_yearly_budget_balance = 0;
	int in_total_money_financing = 0;
	int in_total_bond_financing = 0;
	int in_country_wide_mean_wage = 0;
	int in_num_unemployed = 0;
	int in_gdp_growth = 0;
	int in_gdp_forecast = 0;
	int in_yearly_income_forecast = 0;
	int in_yearly_expenditure_budget = 0;
	int in_budget_balance_forecast = 0;
	int in_monthly_investment_expenditure = 0;
	int in_monthly_budget_balance = 0;
	int in_monthly_consumption_budget = 0;
	int in_monthly_investment_budget = 0;
	int in_monthly_income = 0;
	int in_monthly_expenditure = 0;
	int in_yearly_consumption_budget = 0;
	int in_yearly_investment_budget = 0;
	int in_value_bonds_outstanding = 0;
	int in_nr_bonds_outstanding = 0;
	int in_accounts = 0;
	int in_total_ecb_debt = 0;
	int in_payment_account_private_sector = 0;
	int in_payment_account_public_sector = 0;
	int in_fiat_money = 0;
	int in_bank_interest = 0;
	int in_gov_bond_purchase = 0;
	int in_assets = 0;
	int in_clearingmechanism = 0;
	
	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Mall * current_Mall_agent;
	xmachine_memory_IGFirm * current_IGFirm_agent;
	xmachine_memory_Eurostat * current_Eurostat_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_Government * current_Government_agent;
	xmachine_memory_Central_Bank * current_Central_Bank_agent;
	xmachine_memory_Clearinghouse * current_Clearinghouse_agent;
	
	/* Things for round-robin partitioning */
	int geometric = 1;
	int other = 2;
	double 	xmax=0, xmin=0, ymax=0, ymin=0;
	double xcentre=0, ycentre=0, rrange=1.5;
	double posx=0.0, posy=0.0, posz=0.0;

	agentname[0] = '\0';
	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(1);
	}
	printf("Reading agent data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "xagent") == 0)
			{
				FLAME_in_xagent = 1;
				agentname[0] = '\0';
			}
			if(strcmp(buffer, "/xagent") == 0)
			{
				if(strcmp(agentname, "Firm") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Firm_agent_internal(current_Firm_agent, Firm_start_Firm_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Household_agent_internal(current_Household_agent, Household_start_Household_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Household_agent_internal(current_Household_agent, Household_start_Household_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Mall_agent_internal(current_Mall_agent, Mall_start_Mall_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_IGFirm_agent_internal(current_IGFirm_agent, IGFirm_start_IGFirm_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Eurostat_agent_internal(current_Eurostat_agent, Eurostat_start_Eurostat_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Bank_agent_internal(current_Bank_agent, Bank_start_Bank_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Bank_agent_internal(current_Bank_agent, Bank_start_Bank_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Government_agent_internal(current_Government_agent, Government_start_Government_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Government_agent_internal(current_Government_agent, Government_start_Government_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Central_Bank_agent_internal(current_Central_Bank_agent, Central_Bank_start_Central_Bank_state);
							}
							++agent_count;
						}
					}
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
						/* Next line should be commented out? */
						add_Clearinghouse_agent_internal(current_Clearinghouse_agent, Clearinghouse_start_Clearinghouse_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
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

								add_Clearinghouse_agent_internal(current_Clearinghouse_agent, Clearinghouse_start_Clearinghouse_state);
							}
							++agent_count;
						}
					}
				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
					exit(0);
				}
				agentname[0] = '\0';
				FLAME_in_xagent = 0;
				in_Firm_agent = 0;
				in_Household_agent = 0;
				in_Mall_agent = 0;
				in_IGFirm_agent = 0;
				in_Eurostat_agent = 0;
				in_Bank_agent = 0;
				in_Government_agent = 0;
				in_Central_Bank_agent = 0;
				in_Clearinghouse_agent = 0;
				
			}
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;
			if(strcmp(buffer, "id") == 0) { in_id = 1; }
			if(strcmp(buffer, "/id") == 0) { in_id = 0; }
			if(strcmp(buffer, "region_id") == 0) { in_region_id = 1; }
			if(strcmp(buffer, "/region_id") == 0) { in_region_id = 0; }
			if(strcmp(buffer, "gov_id") == 0) { in_gov_id = 1; }
			if(strcmp(buffer, "/gov_id") == 0) { in_gov_id = 0; }
			if(strcmp(buffer, "day_of_month_to_act") == 0) { in_day_of_month_to_act = 1; }
			if(strcmp(buffer, "/day_of_month_to_act") == 0) { in_day_of_month_to_act = 0; }
			if(strcmp(buffer, "last_day_of_month_to_act") == 0) { in_last_day_of_month_to_act = 1; }
			if(strcmp(buffer, "/last_day_of_month_to_act") == 0) { in_last_day_of_month_to_act = 0; }
			if(strcmp(buffer, "payment_account") == 0) { in_payment_account = 1; }
			if(strcmp(buffer, "/payment_account") == 0) { in_payment_account = 0; }
			if(strcmp(buffer, "bank_id") == 0) { in_bank_id = 1; }
			if(strcmp(buffer, "/bank_id") == 0) { in_bank_id = 0; }
			if(strcmp(buffer, "partition_id") == 0) { in_partition_id = 1; }
			if(strcmp(buffer, "/partition_id") == 0) { in_partition_id = 0; }
			if(strcmp(buffer, "mean_wage") == 0) { in_mean_wage = 1; }
			if(strcmp(buffer, "/mean_wage") == 0) { in_mean_wage = 0; }
			if(strcmp(buffer, "needed_capital_stock") == 0) { in_needed_capital_stock = 1; }
			if(strcmp(buffer, "/needed_capital_stock") == 0) { in_needed_capital_stock = 0; }
			if(strcmp(buffer, "actual_cap_price") == 0) { in_actual_cap_price = 1; }
			if(strcmp(buffer, "/actual_cap_price") == 0) { in_actual_cap_price = 0; }
			if(strcmp(buffer, "mean_specific_skills") == 0) { in_mean_specific_skills = 1; }
			if(strcmp(buffer, "/mean_specific_skills") == 0) { in_mean_specific_skills = 0; }
			if(strcmp(buffer, "planned_production_quantity") == 0) { in_planned_production_quantity = 1; }
			if(strcmp(buffer, "/planned_production_quantity") == 0) { in_planned_production_quantity = 0; }
			if(strcmp(buffer, "production_quantity") == 0) { in_production_quantity = 1; }
			if(strcmp(buffer, "/production_quantity") == 0) { in_production_quantity = 0; }
			if(strcmp(buffer, "planned_output") == 0) { in_planned_output = 1; }
			if(strcmp(buffer, "/planned_output") == 0) { in_planned_output = 0; }
			if(strcmp(buffer, "output") == 0) { in_output = 1; }
			if(strcmp(buffer, "/output") == 0) { in_output = 0; }
			if(strcmp(buffer, "unit_costs") == 0) { in_unit_costs = 1; }
			if(strcmp(buffer, "/unit_costs") == 0) { in_unit_costs = 0; }
			if(strcmp(buffer, "total_supply") == 0) { in_total_supply = 1; }
			if(strcmp(buffer, "/total_supply") == 0) { in_total_supply = 0; }
			if(strcmp(buffer, "production_costs") == 0) { in_production_costs = 1; }
			if(strcmp(buffer, "/production_costs") == 0) { in_production_costs = 0; }
			if(strcmp(buffer, "revenue_per_day") == 0) { in_revenue_per_day = 1; }
			if(strcmp(buffer, "/revenue_per_day") == 0) { in_revenue_per_day = 0; }
			if(strcmp(buffer, "technological_frontier") == 0) { in_technological_frontier = 1; }
			if(strcmp(buffer, "/technological_frontier") == 0) { in_technological_frontier = 0; }
			if(strcmp(buffer, "cum_revenue") == 0) { in_cum_revenue = 1; }
			if(strcmp(buffer, "/cum_revenue") == 0) { in_cum_revenue = 0; }
			if(strcmp(buffer, "out_of_stock_costs") == 0) { in_out_of_stock_costs = 1; }
			if(strcmp(buffer, "/out_of_stock_costs") == 0) { in_out_of_stock_costs = 0; }
			if(strcmp(buffer, "malls_sales_statistics") == 0) { in_malls_sales_statistics = 1; }
			if(strcmp(buffer, "/malls_sales_statistics") == 0) { in_malls_sales_statistics = 0; }
			if(strcmp(buffer, "quality") == 0) { in_quality = 1; }
			if(strcmp(buffer, "/quality") == 0) { in_quality = 0; }
			if(strcmp(buffer, "price") == 0) { in_price = 1; }
			if(strcmp(buffer, "/price") == 0) { in_price = 0; }
			if(strcmp(buffer, "price_last_month") == 0) { in_price_last_month = 1; }
			if(strcmp(buffer, "/price_last_month") == 0) { in_price_last_month = 0; }
			if(strcmp(buffer, "demand_capital_stock") == 0) { in_demand_capital_stock = 1; }
			if(strcmp(buffer, "/demand_capital_stock") == 0) { in_demand_capital_stock = 0; }
			if(strcmp(buffer, "planned_production_costs") == 0) { in_planned_production_costs = 1; }
			if(strcmp(buffer, "/planned_production_costs") == 0) { in_planned_production_costs = 0; }
			if(strcmp(buffer, "adaption_production_volume_due_to_insufficient_finances") == 0) { in_adaption_production_volume_due_to_insufficient_finances = 1; }
			if(strcmp(buffer, "/adaption_production_volume_due_to_insufficient_finances") == 0) { in_adaption_production_volume_due_to_insufficient_finances = 0; }
			if(strcmp(buffer, "fraction_reserved_for_delayed_payments") == 0) { in_fraction_reserved_for_delayed_payments = 1; }
			if(strcmp(buffer, "/fraction_reserved_for_delayed_payments") == 0) { in_fraction_reserved_for_delayed_payments = 0; }
			if(strcmp(buffer, "sold_quantities") == 0) { in_sold_quantities = 1; }
			if(strcmp(buffer, "/sold_quantities") == 0) { in_sold_quantities = 0; }
			if(strcmp(buffer, "total_sold_quantity") == 0) { in_total_sold_quantity = 1; }
			if(strcmp(buffer, "/total_sold_quantity") == 0) { in_total_sold_quantity = 0; }
			if(strcmp(buffer, "cum_total_sold_quantity") == 0) { in_cum_total_sold_quantity = 1; }
			if(strcmp(buffer, "/cum_total_sold_quantity") == 0) { in_cum_total_sold_quantity = 0; }
			if(strcmp(buffer, "sold_quantity_in_calendar_month") == 0) { in_sold_quantity_in_calendar_month = 1; }
			if(strcmp(buffer, "/sold_quantity_in_calendar_month") == 0) { in_sold_quantity_in_calendar_month = 0; }
			if(strcmp(buffer, "delivery_volume") == 0) { in_delivery_volume = 1; }
			if(strcmp(buffer, "/delivery_volume") == 0) { in_delivery_volume = 0; }
			if(strcmp(buffer, "planned_delivery_volume") == 0) { in_planned_delivery_volume = 1; }
			if(strcmp(buffer, "/planned_delivery_volume") == 0) { in_planned_delivery_volume = 0; }
			if(strcmp(buffer, "current_mall_stocks") == 0) { in_current_mall_stocks = 1; }
			if(strcmp(buffer, "/current_mall_stocks") == 0) { in_current_mall_stocks = 0; }
			if(strcmp(buffer, "last_planned_production_quantities") == 0) { in_last_planned_production_quantities = 1; }
			if(strcmp(buffer, "/last_planned_production_quantities") == 0) { in_last_planned_production_quantities = 0; }
			if(strcmp(buffer, "total_external_financing_obtained") == 0) { in_total_external_financing_obtained = 1; }
			if(strcmp(buffer, "/total_external_financing_obtained") == 0) { in_total_external_financing_obtained = 0; }
			if(strcmp(buffer, "capital_costs") == 0) { in_capital_costs = 1; }
			if(strcmp(buffer, "/capital_costs") == 0) { in_capital_costs = 0; }
			if(strcmp(buffer, "labour_costs") == 0) { in_labour_costs = 1; }
			if(strcmp(buffer, "/labour_costs") == 0) { in_labour_costs = 0; }
			if(strcmp(buffer, "capital_financing") == 0) { in_capital_financing = 1; }
			if(strcmp(buffer, "/capital_financing") == 0) { in_capital_financing = 0; }
			if(strcmp(buffer, "financial_resources_for_production") == 0) { in_financial_resources_for_production = 1; }
			if(strcmp(buffer, "/financial_resources_for_production") == 0) { in_financial_resources_for_production = 0; }
			if(strcmp(buffer, "planned_value_capital_stock") == 0) { in_planned_value_capital_stock = 1; }
			if(strcmp(buffer, "/planned_value_capital_stock") == 0) { in_planned_value_capital_stock = 0; }
			if(strcmp(buffer, "total_units_local_inventory") == 0) { in_total_units_local_inventory = 1; }
			if(strcmp(buffer, "/total_units_local_inventory") == 0) { in_total_units_local_inventory = 0; }
			if(strcmp(buffer, "calc_capital_costs") == 0) { in_calc_capital_costs = 1; }
			if(strcmp(buffer, "/calc_capital_costs") == 0) { in_calc_capital_costs = 0; }
			if(strcmp(buffer, "calc_production_costs") == 0) { in_calc_production_costs = 1; }
			if(strcmp(buffer, "/calc_production_costs") == 0) { in_calc_production_costs = 0; }
			if(strcmp(buffer, "firm_productivity") == 0) { in_firm_productivity = 1; }
			if(strcmp(buffer, "/firm_productivity") == 0) { in_firm_productivity = 0; }
			if(strcmp(buffer, "firm_productivity_last_year") == 0) { in_firm_productivity_last_year = 1; }
			if(strcmp(buffer, "/firm_productivity_last_year") == 0) { in_firm_productivity_last_year = 0; }
			if(strcmp(buffer, "firm_productivity_progress") == 0) { in_firm_productivity_progress = 1; }
			if(strcmp(buffer, "/firm_productivity_progress") == 0) { in_firm_productivity_progress = 0; }
			if(strcmp(buffer, "set_of_lenders") == 0) { in_set_of_lenders = 1; }
			if(strcmp(buffer, "/set_of_lenders") == 0) { in_set_of_lenders = 0; }
			if(strcmp(buffer, "number_of_banks_asked") == 0) { in_number_of_banks_asked = 1; }
			if(strcmp(buffer, "/number_of_banks_asked") == 0) { in_number_of_banks_asked = 0; }
			if(strcmp(buffer, "ebit") == 0) { in_ebit = 1; }
			if(strcmp(buffer, "/ebit") == 0) { in_ebit = 0; }
			if(strcmp(buffer, "earnings") == 0) { in_earnings = 1; }
			if(strcmp(buffer, "/earnings") == 0) { in_earnings = 0; }
			if(strcmp(buffer, "tax_rate_corporate") == 0) { in_tax_rate_corporate = 1; }
			if(strcmp(buffer, "/tax_rate_corporate") == 0) { in_tax_rate_corporate = 0; }
			if(strcmp(buffer, "tax_rate_vat") == 0) { in_tax_rate_vat = 1; }
			if(strcmp(buffer, "/tax_rate_vat") == 0) { in_tax_rate_vat = 0; }
			if(strcmp(buffer, "tax_payment") == 0) { in_tax_payment = 1; }
			if(strcmp(buffer, "/tax_payment") == 0) { in_tax_payment = 0; }
			if(strcmp(buffer, "net_earnings") == 0) { in_net_earnings = 1; }
			if(strcmp(buffer, "/net_earnings") == 0) { in_net_earnings = 0; }
			if(strcmp(buffer, "previous_net_earnings") == 0) { in_previous_net_earnings = 1; }
			if(strcmp(buffer, "/previous_net_earnings") == 0) { in_previous_net_earnings = 0; }
			if(strcmp(buffer, "total_interest_payment") == 0) { in_total_interest_payment = 1; }
			if(strcmp(buffer, "/total_interest_payment") == 0) { in_total_interest_payment = 0; }
			if(strcmp(buffer, "total_debt_installment_payment") == 0) { in_total_debt_installment_payment = 1; }
			if(strcmp(buffer, "/total_debt_installment_payment") == 0) { in_total_debt_installment_payment = 0; }
			if(strcmp(buffer, "total_dividend_payment") == 0) { in_total_dividend_payment = 1; }
			if(strcmp(buffer, "/total_dividend_payment") == 0) { in_total_dividend_payment = 0; }
			if(strcmp(buffer, "current_share_price") == 0) { in_current_share_price = 1; }
			if(strcmp(buffer, "/current_share_price") == 0) { in_current_share_price = 0; }
			if(strcmp(buffer, "previous_dividend_per_share") == 0) { in_previous_dividend_per_share = 1; }
			if(strcmp(buffer, "/previous_dividend_per_share") == 0) { in_previous_dividend_per_share = 0; }
			if(strcmp(buffer, "current_dividend_per_share") == 0) { in_current_dividend_per_share = 1; }
			if(strcmp(buffer, "/current_dividend_per_share") == 0) { in_current_dividend_per_share = 0; }
			if(strcmp(buffer, "previous_earnings_per_share") == 0) { in_previous_earnings_per_share = 1; }
			if(strcmp(buffer, "/previous_earnings_per_share") == 0) { in_previous_earnings_per_share = 0; }
			if(strcmp(buffer, "current_earnings_per_share") == 0) { in_current_earnings_per_share = 1; }
			if(strcmp(buffer, "/current_earnings_per_share") == 0) { in_current_earnings_per_share = 0; }
			if(strcmp(buffer, "previous_dividend_per_earnings") == 0) { in_previous_dividend_per_earnings = 1; }
			if(strcmp(buffer, "/previous_dividend_per_earnings") == 0) { in_previous_dividend_per_earnings = 0; }
			if(strcmp(buffer, "current_dividend_per_earnings") == 0) { in_current_dividend_per_earnings = 1; }
			if(strcmp(buffer, "/current_dividend_per_earnings") == 0) { in_current_dividend_per_earnings = 0; }
			if(strcmp(buffer, "debt_earnings_ratio") == 0) { in_debt_earnings_ratio = 1; }
			if(strcmp(buffer, "/debt_earnings_ratio") == 0) { in_debt_earnings_ratio = 0; }
			if(strcmp(buffer, "debt_equity_ratio") == 0) { in_debt_equity_ratio = 1; }
			if(strcmp(buffer, "/debt_equity_ratio") == 0) { in_debt_equity_ratio = 0; }
			if(strcmp(buffer, "price_earnings_ratio") == 0) { in_price_earnings_ratio = 1; }
			if(strcmp(buffer, "/price_earnings_ratio") == 0) { in_price_earnings_ratio = 0; }
			if(strcmp(buffer, "retained_earnings_ratio") == 0) { in_retained_earnings_ratio = 1; }
			if(strcmp(buffer, "/retained_earnings_ratio") == 0) { in_retained_earnings_ratio = 0; }
			if(strcmp(buffer, "earnings_per_share_ratio_growth") == 0) { in_earnings_per_share_ratio_growth = 1; }
			if(strcmp(buffer, "/earnings_per_share_ratio_growth") == 0) { in_earnings_per_share_ratio_growth = 0; }
			if(strcmp(buffer, "critical_price_earnings_ratio") == 0) { in_critical_price_earnings_ratio = 1; }
			if(strcmp(buffer, "/critical_price_earnings_ratio") == 0) { in_critical_price_earnings_ratio = 0; }
			if(strcmp(buffer, "critical_earnings_per_share_ratio") == 0) { in_critical_earnings_per_share_ratio = 1; }
			if(strcmp(buffer, "/critical_earnings_per_share_ratio") == 0) { in_critical_earnings_per_share_ratio = 0; }
			if(strcmp(buffer, "loans") == 0) { in_loans = 1; }
			if(strcmp(buffer, "/loans") == 0) { in_loans = 0; }
			if(strcmp(buffer, "total_debt") == 0) { in_total_debt = 1; }
			if(strcmp(buffer, "/total_debt") == 0) { in_total_debt = 0; }
			if(strcmp(buffer, "total_value_local_inventory") == 0) { in_total_value_local_inventory = 1; }
			if(strcmp(buffer, "/total_value_local_inventory") == 0) { in_total_value_local_inventory = 0; }
			if(strcmp(buffer, "total_units_capital_stock") == 0) { in_total_units_capital_stock = 1; }
			if(strcmp(buffer, "/total_units_capital_stock") == 0) { in_total_units_capital_stock = 0; }
			if(strcmp(buffer, "total_value_capital_stock") == 0) { in_total_value_capital_stock = 1; }
			if(strcmp(buffer, "/total_value_capital_stock") == 0) { in_total_value_capital_stock = 0; }
			if(strcmp(buffer, "total_capital_depreciation_value") == 0) { in_total_capital_depreciation_value = 1; }
			if(strcmp(buffer, "/total_capital_depreciation_value") == 0) { in_total_capital_depreciation_value = 0; }
			if(strcmp(buffer, "total_capital_depreciation_units") == 0) { in_total_capital_depreciation_units = 1; }
			if(strcmp(buffer, "/total_capital_depreciation_units") == 0) { in_total_capital_depreciation_units = 0; }
			if(strcmp(buffer, "total_assets") == 0) { in_total_assets = 1; }
			if(strcmp(buffer, "/total_assets") == 0) { in_total_assets = 0; }
			if(strcmp(buffer, "equity") == 0) { in_equity = 1; }
			if(strcmp(buffer, "/equity") == 0) { in_equity = 0; }
			if(strcmp(buffer, "production_liquidity_needs") == 0) { in_production_liquidity_needs = 1; }
			if(strcmp(buffer, "/production_liquidity_needs") == 0) { in_production_liquidity_needs = 0; }
			if(strcmp(buffer, "financial_liquidity_needs") == 0) { in_financial_liquidity_needs = 1; }
			if(strcmp(buffer, "/financial_liquidity_needs") == 0) { in_financial_liquidity_needs = 0; }
			if(strcmp(buffer, "total_financial_needs") == 0) { in_total_financial_needs = 1; }
			if(strcmp(buffer, "/total_financial_needs") == 0) { in_total_financial_needs = 0; }
			if(strcmp(buffer, "external_financial_needs") == 0) { in_external_financial_needs = 1; }
			if(strcmp(buffer, "/external_financial_needs") == 0) { in_external_financial_needs = 0; }
			if(strcmp(buffer, "earnings_per_share") == 0) { in_earnings_per_share = 1; }
			if(strcmp(buffer, "/earnings_per_share") == 0) { in_earnings_per_share = 0; }
			if(strcmp(buffer, "total_payments") == 0) { in_total_payments = 1; }
			if(strcmp(buffer, "/total_payments") == 0) { in_total_payments = 0; }
			if(strcmp(buffer, "previous_shares_outstanding") == 0) { in_previous_shares_outstanding = 1; }
			if(strcmp(buffer, "/previous_shares_outstanding") == 0) { in_previous_shares_outstanding = 0; }
			if(strcmp(buffer, "total_income") == 0) { in_total_income = 1; }
			if(strcmp(buffer, "/total_income") == 0) { in_total_income = 0; }
			if(strcmp(buffer, "total_liabilities") == 0) { in_total_liabilities = 1; }
			if(strcmp(buffer, "/total_liabilities") == 0) { in_total_liabilities = 0; }
			if(strcmp(buffer, "total_expenses") == 0) { in_total_expenses = 1; }
			if(strcmp(buffer, "/total_expenses") == 0) { in_total_expenses = 0; }
			if(strcmp(buffer, "current_shares_outstanding") == 0) { in_current_shares_outstanding = 1; }
			if(strcmp(buffer, "/current_shares_outstanding") == 0) { in_current_shares_outstanding = 0; }
			if(strcmp(buffer, "employees") == 0) { in_employees = 1; }
			if(strcmp(buffer, "/employees") == 0) { in_employees = 0; }
			if(strcmp(buffer, "wage_offer") == 0) { in_wage_offer = 1; }
			if(strcmp(buffer, "/wage_offer") == 0) { in_wage_offer = 0; }
			if(strcmp(buffer, "technology") == 0) { in_technology = 1; }
			if(strcmp(buffer, "/technology") == 0) { in_technology = 0; }
			if(strcmp(buffer, "no_employees") == 0) { in_no_employees = 1; }
			if(strcmp(buffer, "/no_employees") == 0) { in_no_employees = 0; }
			if(strcmp(buffer, "no_employees_skill_1") == 0) { in_no_employees_skill_1 = 1; }
			if(strcmp(buffer, "/no_employees_skill_1") == 0) { in_no_employees_skill_1 = 0; }
			if(strcmp(buffer, "no_employees_skill_2") == 0) { in_no_employees_skill_2 = 1; }
			if(strcmp(buffer, "/no_employees_skill_2") == 0) { in_no_employees_skill_2 = 0; }
			if(strcmp(buffer, "no_employees_skill_3") == 0) { in_no_employees_skill_3 = 1; }
			if(strcmp(buffer, "/no_employees_skill_3") == 0) { in_no_employees_skill_3 = 0; }
			if(strcmp(buffer, "no_employees_skill_4") == 0) { in_no_employees_skill_4 = 1; }
			if(strcmp(buffer, "/no_employees_skill_4") == 0) { in_no_employees_skill_4 = 0; }
			if(strcmp(buffer, "no_employees_skill_5") == 0) { in_no_employees_skill_5 = 1; }
			if(strcmp(buffer, "/no_employees_skill_5") == 0) { in_no_employees_skill_5 = 0; }
			if(strcmp(buffer, "vacancies") == 0) { in_vacancies = 1; }
			if(strcmp(buffer, "/vacancies") == 0) { in_vacancies = 0; }
			if(strcmp(buffer, "average_g_skill") == 0) { in_average_g_skill = 1; }
			if(strcmp(buffer, "/average_g_skill") == 0) { in_average_g_skill = 0; }
			if(strcmp(buffer, "average_s_skill_of_1") == 0) { in_average_s_skill_of_1 = 1; }
			if(strcmp(buffer, "/average_s_skill_of_1") == 0) { in_average_s_skill_of_1 = 0; }
			if(strcmp(buffer, "average_s_skill_of_2") == 0) { in_average_s_skill_of_2 = 1; }
			if(strcmp(buffer, "/average_s_skill_of_2") == 0) { in_average_s_skill_of_2 = 0; }
			if(strcmp(buffer, "average_s_skill_of_3") == 0) { in_average_s_skill_of_3 = 1; }
			if(strcmp(buffer, "/average_s_skill_of_3") == 0) { in_average_s_skill_of_3 = 0; }
			if(strcmp(buffer, "average_s_skill_of_4") == 0) { in_average_s_skill_of_4 = 1; }
			if(strcmp(buffer, "/average_s_skill_of_4") == 0) { in_average_s_skill_of_4 = 0; }
			if(strcmp(buffer, "average_s_skill_of_5") == 0) { in_average_s_skill_of_5 = 1; }
			if(strcmp(buffer, "/average_s_skill_of_5") == 0) { in_average_s_skill_of_5 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_1") == 0) { in_wage_offer_for_skill_1 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_1") == 0) { in_wage_offer_for_skill_1 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_2") == 0) { in_wage_offer_for_skill_2 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_2") == 0) { in_wage_offer_for_skill_2 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_3") == 0) { in_wage_offer_for_skill_3 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_3") == 0) { in_wage_offer_for_skill_3 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_4") == 0) { in_wage_offer_for_skill_4 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_4") == 0) { in_wage_offer_for_skill_4 = 0; }
			if(strcmp(buffer, "wage_offer_for_skill_5") == 0) { in_wage_offer_for_skill_5 = 1; }
			if(strcmp(buffer, "/wage_offer_for_skill_5") == 0) { in_wage_offer_for_skill_5 = 0; }
			if(strcmp(buffer, "employees_needed") == 0) { in_employees_needed = 1; }
			if(strcmp(buffer, "/employees_needed") == 0) { in_employees_needed = 0; }
			if(strcmp(buffer, "age") == 0) { in_age = 1; }
			if(strcmp(buffer, "/age") == 0) { in_age = 0; }
			if(strcmp(buffer, "transfer_payment") == 0) { in_transfer_payment = 1; }
			if(strcmp(buffer, "/transfer_payment") == 0) { in_transfer_payment = 0; }
			if(strcmp(buffer, "subsidy_payment") == 0) { in_subsidy_payment = 1; }
			if(strcmp(buffer, "/subsidy_payment") == 0) { in_subsidy_payment = 0; }
			if(strcmp(buffer, "active") == 0) { in_active = 1; }
			if(strcmp(buffer, "/active") == 0) { in_active = 0; }
			if(strcmp(buffer, "bankruptcy_idle_counter") == 0) { in_bankruptcy_idle_counter = 1; }
			if(strcmp(buffer, "/bankruptcy_idle_counter") == 0) { in_bankruptcy_idle_counter = 0; }
			if(strcmp(buffer, "bankruptcy_state") == 0) { in_bankruptcy_state = 1; }
			if(strcmp(buffer, "/bankruptcy_state") == 0) { in_bankruptcy_state = 0; }
			if(strcmp(buffer, "bankruptcy_insolvency_state") == 0) { in_bankruptcy_insolvency_state = 1; }
			if(strcmp(buffer, "/bankruptcy_insolvency_state") == 0) { in_bankruptcy_insolvency_state = 0; }
			if(strcmp(buffer, "bankruptcy_illiquidity_state") == 0) { in_bankruptcy_illiquidity_state = 1; }
			if(strcmp(buffer, "/bankruptcy_illiquidity_state") == 0) { in_bankruptcy_illiquidity_state = 0; }
			if(strcmp(buffer, "financial_crisis_state") == 0) { in_financial_crisis_state = 1; }
			if(strcmp(buffer, "/financial_crisis_state") == 0) { in_financial_crisis_state = 0; }
			if(strcmp(buffer, "neighboring_region_ids") == 0) { in_neighboring_region_ids = 1; }
			if(strcmp(buffer, "/neighboring_region_ids") == 0) { in_neighboring_region_ids = 0; }
			if(strcmp(buffer, "consumption_budget") == 0) { in_consumption_budget = 1; }
			if(strcmp(buffer, "/consumption_budget") == 0) { in_consumption_budget = 0; }
			if(strcmp(buffer, "mean_income") == 0) { in_mean_income = 1; }
			if(strcmp(buffer, "/mean_income") == 0) { in_mean_income = 0; }
			if(strcmp(buffer, "week_of_month") == 0) { in_week_of_month = 1; }
			if(strcmp(buffer, "/week_of_month") == 0) { in_week_of_month = 0; }
			if(strcmp(buffer, "weekly_budget") == 0) { in_weekly_budget = 1; }
			if(strcmp(buffer, "/weekly_budget") == 0) { in_weekly_budget = 0; }
			if(strcmp(buffer, "rationed") == 0) { in_rationed = 1; }
			if(strcmp(buffer, "/rationed") == 0) { in_rationed = 0; }
			if(strcmp(buffer, "mall_completely_sold_out") == 0) { in_mall_completely_sold_out = 1; }
			if(strcmp(buffer, "/mall_completely_sold_out") == 0) { in_mall_completely_sold_out = 0; }
			if(strcmp(buffer, "order_quantity") == 0) { in_order_quantity = 1; }
			if(strcmp(buffer, "/order_quantity") == 0) { in_order_quantity = 0; }
			if(strcmp(buffer, "received_quantity") == 0) { in_received_quantity = 1; }
			if(strcmp(buffer, "/received_quantity") == 0) { in_received_quantity = 0; }
			if(strcmp(buffer, "day_of_week_to_act") == 0) { in_day_of_week_to_act = 1; }
			if(strcmp(buffer, "/day_of_week_to_act") == 0) { in_day_of_week_to_act = 0; }
			if(strcmp(buffer, "day_of_month_receive_income") == 0) { in_day_of_month_receive_income = 1; }
			if(strcmp(buffer, "/day_of_month_receive_income") == 0) { in_day_of_month_receive_income = 0; }
			if(strcmp(buffer, "current_productivity_employer") == 0) { in_current_productivity_employer = 1; }
			if(strcmp(buffer, "/current_productivity_employer") == 0) { in_current_productivity_employer = 0; }
			if(strcmp(buffer, "current_mean_specific_skills_employer") == 0) { in_current_mean_specific_skills_employer = 1; }
			if(strcmp(buffer, "/current_mean_specific_skills_employer") == 0) { in_current_mean_specific_skills_employer = 0; }
			if(strcmp(buffer, "cum_total_dividends") == 0) { in_cum_total_dividends = 1; }
			if(strcmp(buffer, "/cum_total_dividends") == 0) { in_cum_total_dividends = 0; }
			if(strcmp(buffer, "tax_rate_hh_capital") == 0) { in_tax_rate_hh_capital = 1; }
			if(strcmp(buffer, "/tax_rate_hh_capital") == 0) { in_tax_rate_hh_capital = 0; }
			if(strcmp(buffer, "tax_rate_hh_labour") == 0) { in_tax_rate_hh_labour = 1; }
			if(strcmp(buffer, "/tax_rate_hh_labour") == 0) { in_tax_rate_hh_labour = 0; }
			if(strcmp(buffer, "price_index") == 0) { in_price_index = 1; }
			if(strcmp(buffer, "/price_index") == 0) { in_price_index = 0; }
			if(strcmp(buffer, "price_index_base_period") == 0) { in_price_index_base_period = 1; }
			if(strcmp(buffer, "/price_index_base_period") == 0) { in_price_index_base_period = 0; }
			if(strcmp(buffer, "commuting_costs_price_level_weight") == 0) { in_commuting_costs_price_level_weight = 1; }
			if(strcmp(buffer, "/commuting_costs_price_level_weight") == 0) { in_commuting_costs_price_level_weight = 0; }
			if(strcmp(buffer, "last_income") == 0) { in_last_income = 1; }
			if(strcmp(buffer, "/last_income") == 0) { in_last_income = 0; }
			if(strcmp(buffer, "expenditures") == 0) { in_expenditures = 1; }
			if(strcmp(buffer, "/expenditures") == 0) { in_expenditures = 0; }
			if(strcmp(buffer, "received_dividend") == 0) { in_received_dividend = 1; }
			if(strcmp(buffer, "/received_dividend") == 0) { in_received_dividend = 0; }
			if(strcmp(buffer, "flag_consumption_shifting") == 0) { in_flag_consumption_shifting = 1; }
			if(strcmp(buffer, "/flag_consumption_shifting") == 0) { in_flag_consumption_shifting = 0; }
			if(strcmp(buffer, "excess_weekly_budget") == 0) { in_excess_weekly_budget = 1; }
			if(strcmp(buffer, "/excess_weekly_budget") == 0) { in_excess_weekly_budget = 0; }
			if(strcmp(buffer, "assetsowned") == 0) { in_assetsowned = 1; }
			if(strcmp(buffer, "/assetsowned") == 0) { in_assetsowned = 0; }
			if(strcmp(buffer, "wage") == 0) { in_wage = 1; }
			if(strcmp(buffer, "/wage") == 0) { in_wage = 0; }
			if(strcmp(buffer, "wage_reservation") == 0) { in_wage_reservation = 1; }
			if(strcmp(buffer, "/wage_reservation") == 0) { in_wage_reservation = 0; }
			if(strcmp(buffer, "general_skill") == 0) { in_general_skill = 1; }
			if(strcmp(buffer, "/general_skill") == 0) { in_general_skill = 0; }
			if(strcmp(buffer, "on_the_job_search") == 0) { in_on_the_job_search = 1; }
			if(strcmp(buffer, "/on_the_job_search") == 0) { in_on_the_job_search = 0; }
			if(strcmp(buffer, "number_applications") == 0) { in_number_applications = 1; }
			if(strcmp(buffer, "/number_applications") == 0) { in_number_applications = 0; }
			if(strcmp(buffer, "last_labour_income") == 0) { in_last_labour_income = 1; }
			if(strcmp(buffer, "/last_labour_income") == 0) { in_last_labour_income = 0; }
			if(strcmp(buffer, "specific_skill") == 0) { in_specific_skill = 1; }
			if(strcmp(buffer, "/specific_skill") == 0) { in_specific_skill = 0; }
			if(strcmp(buffer, "employee_firm_id") == 0) { in_employee_firm_id = 1; }
			if(strcmp(buffer, "/employee_firm_id") == 0) { in_employee_firm_id = 0; }
			if(strcmp(buffer, "employer_region_id") == 0) { in_employer_region_id = 1; }
			if(strcmp(buffer, "/employer_region_id") == 0) { in_employer_region_id = 0; }
			if(strcmp(buffer, "day_of_month_receive_benefit") == 0) { in_day_of_month_receive_benefit = 1; }
			if(strcmp(buffer, "/day_of_month_receive_benefit") == 0) { in_day_of_month_receive_benefit = 0; }
			if(strcmp(buffer, "unemployment_benefit_pct") == 0) { in_unemployment_benefit_pct = 1; }
			if(strcmp(buffer, "/unemployment_benefit_pct") == 0) { in_unemployment_benefit_pct = 0; }
			if(strcmp(buffer, "gov_interest") == 0) { in_gov_interest = 1; }
			if(strcmp(buffer, "/gov_interest") == 0) { in_gov_interest = 0; }
			if(strcmp(buffer, "stock_sales") == 0) { in_stock_sales = 1; }
			if(strcmp(buffer, "/stock_sales") == 0) { in_stock_sales = 0; }
			if(strcmp(buffer, "stock_purchases") == 0) { in_stock_purchases = 1; }
			if(strcmp(buffer, "/stock_purchases") == 0) { in_stock_purchases = 0; }
			if(strcmp(buffer, "gov_bond_purchases") == 0) { in_gov_bond_purchases = 1; }
			if(strcmp(buffer, "/gov_bond_purchases") == 0) { in_gov_bond_purchases = 0; }
			if(strcmp(buffer, "monthly_consumption_expenditure") == 0) { in_monthly_consumption_expenditure = 1; }
			if(strcmp(buffer, "/monthly_consumption_expenditure") == 0) { in_monthly_consumption_expenditure = 0; }
			if(strcmp(buffer, "gov_bond_holdings") == 0) { in_gov_bond_holdings = 1; }
			if(strcmp(buffer, "/gov_bond_holdings") == 0) { in_gov_bond_holdings = 0; }
			if(strcmp(buffer, "nr_gov_bonds") == 0) { in_nr_gov_bonds = 1; }
			if(strcmp(buffer, "/nr_gov_bonds") == 0) { in_nr_gov_bonds = 0; }
			if(strcmp(buffer, "nr_firm_shares") == 0) { in_nr_firm_shares = 1; }
			if(strcmp(buffer, "/nr_firm_shares") == 0) { in_nr_firm_shares = 0; }
			if(strcmp(buffer, "no_regions") == 0) { in_no_regions = 1; }
			if(strcmp(buffer, "/no_regions") == 0) { in_no_regions = 0; }
			if(strcmp(buffer, "current_stock") == 0) { in_current_stock = 1; }
			if(strcmp(buffer, "/current_stock") == 0) { in_current_stock = 0; }
			if(strcmp(buffer, "firm_revenues") == 0) { in_firm_revenues = 1; }
			if(strcmp(buffer, "/firm_revenues") == 0) { in_firm_revenues = 0; }
			if(strcmp(buffer, "export_volume_matrix") == 0) { in_export_volume_matrix = 1; }
			if(strcmp(buffer, "/export_volume_matrix") == 0) { in_export_volume_matrix = 0; }
			if(strcmp(buffer, "export_value_matrix") == 0) { in_export_value_matrix = 1; }
			if(strcmp(buffer, "/export_value_matrix") == 0) { in_export_value_matrix = 0; }
			if(strcmp(buffer, "export_previous_value_matrix") == 0) { in_export_previous_value_matrix = 1; }
			if(strcmp(buffer, "/export_previous_value_matrix") == 0) { in_export_previous_value_matrix = 0; }
			if(strcmp(buffer, "productivity") == 0) { in_productivity = 1; }
			if(strcmp(buffer, "/productivity") == 0) { in_productivity = 0; }
			if(strcmp(buffer, "capital_good_price") == 0) { in_capital_good_price = 1; }
			if(strcmp(buffer, "/capital_good_price") == 0) { in_capital_good_price = 0; }
			if(strcmp(buffer, "net_profit") == 0) { in_net_profit = 1; }
			if(strcmp(buffer, "/net_profit") == 0) { in_net_profit = 0; }
			if(strcmp(buffer, "outstanding_shares") == 0) { in_outstanding_shares = 1; }
			if(strcmp(buffer, "/outstanding_shares") == 0) { in_outstanding_shares = 0; }
			if(strcmp(buffer, "energy_price_markup") == 0) { in_energy_price_markup = 1; }
			if(strcmp(buffer, "/energy_price_markup") == 0) { in_energy_price_markup = 0; }
			if(strcmp(buffer, "energy_costs_per_day") == 0) { in_energy_costs_per_day = 1; }
			if(strcmp(buffer, "/energy_costs_per_day") == 0) { in_energy_costs_per_day = 0; }
			if(strcmp(buffer, "earnings_per_day") == 0) { in_earnings_per_day = 1; }
			if(strcmp(buffer, "/earnings_per_day") == 0) { in_earnings_per_day = 0; }
			if(strcmp(buffer, "cum_energy_costs") == 0) { in_cum_energy_costs = 1; }
			if(strcmp(buffer, "/cum_energy_costs") == 0) { in_cum_energy_costs = 0; }
			if(strcmp(buffer, "switch_datastorage") == 0) { in_switch_datastorage = 1; }
			if(strcmp(buffer, "/switch_datastorage") == 0) { in_switch_datastorage = 0; }
			if(strcmp(buffer, "num_households") == 0) { in_num_households = 1; }
			if(strcmp(buffer, "/num_households") == 0) { in_num_households = 0; }
			if(strcmp(buffer, "no_households_skill_1") == 0) { in_no_households_skill_1 = 1; }
			if(strcmp(buffer, "/no_households_skill_1") == 0) { in_no_households_skill_1 = 0; }
			if(strcmp(buffer, "no_households_skill_2") == 0) { in_no_households_skill_2 = 1; }
			if(strcmp(buffer, "/no_households_skill_2") == 0) { in_no_households_skill_2 = 0; }
			if(strcmp(buffer, "no_households_skill_3") == 0) { in_no_households_skill_3 = 1; }
			if(strcmp(buffer, "/no_households_skill_3") == 0) { in_no_households_skill_3 = 0; }
			if(strcmp(buffer, "no_households_skill_4") == 0) { in_no_households_skill_4 = 1; }
			if(strcmp(buffer, "/no_households_skill_4") == 0) { in_no_households_skill_4 = 0; }
			if(strcmp(buffer, "no_households_skill_5") == 0) { in_no_households_skill_5 = 1; }
			if(strcmp(buffer, "/no_households_skill_5") == 0) { in_no_households_skill_5 = 0; }
			if(strcmp(buffer, "employed") == 0) { in_employed = 1; }
			if(strcmp(buffer, "/employed") == 0) { in_employed = 0; }
			if(strcmp(buffer, "employed_skill_1") == 0) { in_employed_skill_1 = 1; }
			if(strcmp(buffer, "/employed_skill_1") == 0) { in_employed_skill_1 = 0; }
			if(strcmp(buffer, "employed_skill_2") == 0) { in_employed_skill_2 = 1; }
			if(strcmp(buffer, "/employed_skill_2") == 0) { in_employed_skill_2 = 0; }
			if(strcmp(buffer, "employed_skill_3") == 0) { in_employed_skill_3 = 1; }
			if(strcmp(buffer, "/employed_skill_3") == 0) { in_employed_skill_3 = 0; }
			if(strcmp(buffer, "employed_skill_4") == 0) { in_employed_skill_4 = 1; }
			if(strcmp(buffer, "/employed_skill_4") == 0) { in_employed_skill_4 = 0; }
			if(strcmp(buffer, "employed_skill_5") == 0) { in_employed_skill_5 = 1; }
			if(strcmp(buffer, "/employed_skill_5") == 0) { in_employed_skill_5 = 0; }
			if(strcmp(buffer, "unemployed") == 0) { in_unemployed = 1; }
			if(strcmp(buffer, "/unemployed") == 0) { in_unemployed = 0; }
			if(strcmp(buffer, "unemployment_rate") == 0) { in_unemployment_rate = 1; }
			if(strcmp(buffer, "/unemployment_rate") == 0) { in_unemployment_rate = 0; }
			if(strcmp(buffer, "unemployment_rate_skill_1") == 0) { in_unemployment_rate_skill_1 = 1; }
			if(strcmp(buffer, "/unemployment_rate_skill_1") == 0) { in_unemployment_rate_skill_1 = 0; }
			if(strcmp(buffer, "unemployment_rate_skill_2") == 0) { in_unemployment_rate_skill_2 = 1; }
			if(strcmp(buffer, "/unemployment_rate_skill_2") == 0) { in_unemployment_rate_skill_2 = 0; }
			if(strcmp(buffer, "unemployment_rate_skill_3") == 0) { in_unemployment_rate_skill_3 = 1; }
			if(strcmp(buffer, "/unemployment_rate_skill_3") == 0) { in_unemployment_rate_skill_3 = 0; }
			if(strcmp(buffer, "unemployment_rate_skill_4") == 0) { in_unemployment_rate_skill_4 = 1; }
			if(strcmp(buffer, "/unemployment_rate_skill_4") == 0) { in_unemployment_rate_skill_4 = 0; }
			if(strcmp(buffer, "unemployment_rate_skill_5") == 0) { in_unemployment_rate_skill_5 = 1; }
			if(strcmp(buffer, "/unemployment_rate_skill_5") == 0) { in_unemployment_rate_skill_5 = 0; }
			if(strcmp(buffer, "average_wage") == 0) { in_average_wage = 1; }
			if(strcmp(buffer, "/average_wage") == 0) { in_average_wage = 0; }
			if(strcmp(buffer, "average_wage_skill_1") == 0) { in_average_wage_skill_1 = 1; }
			if(strcmp(buffer, "/average_wage_skill_1") == 0) { in_average_wage_skill_1 = 0; }
			if(strcmp(buffer, "average_wage_skill_2") == 0) { in_average_wage_skill_2 = 1; }
			if(strcmp(buffer, "/average_wage_skill_2") == 0) { in_average_wage_skill_2 = 0; }
			if(strcmp(buffer, "average_wage_skill_3") == 0) { in_average_wage_skill_3 = 1; }
			if(strcmp(buffer, "/average_wage_skill_3") == 0) { in_average_wage_skill_3 = 0; }
			if(strcmp(buffer, "average_wage_skill_4") == 0) { in_average_wage_skill_4 = 1; }
			if(strcmp(buffer, "/average_wage_skill_4") == 0) { in_average_wage_skill_4 = 0; }
			if(strcmp(buffer, "average_wage_skill_5") == 0) { in_average_wage_skill_5 = 1; }
			if(strcmp(buffer, "/average_wage_skill_5") == 0) { in_average_wage_skill_5 = 0; }
			if(strcmp(buffer, "average_s_skill") == 0) { in_average_s_skill = 1; }
			if(strcmp(buffer, "/average_s_skill") == 0) { in_average_s_skill = 0; }
			if(strcmp(buffer, "average_s_skill_1") == 0) { in_average_s_skill_1 = 1; }
			if(strcmp(buffer, "/average_s_skill_1") == 0) { in_average_s_skill_1 = 0; }
			if(strcmp(buffer, "average_s_skill_2") == 0) { in_average_s_skill_2 = 1; }
			if(strcmp(buffer, "/average_s_skill_2") == 0) { in_average_s_skill_2 = 0; }
			if(strcmp(buffer, "average_s_skill_3") == 0) { in_average_s_skill_3 = 1; }
			if(strcmp(buffer, "/average_s_skill_3") == 0) { in_average_s_skill_3 = 0; }
			if(strcmp(buffer, "average_s_skill_4") == 0) { in_average_s_skill_4 = 1; }
			if(strcmp(buffer, "/average_s_skill_4") == 0) { in_average_s_skill_4 = 0; }
			if(strcmp(buffer, "average_s_skill_5") == 0) { in_average_s_skill_5 = 1; }
			if(strcmp(buffer, "/average_s_skill_5") == 0) { in_average_s_skill_5 = 0; }
			if(strcmp(buffer, "no_firms") == 0) { in_no_firms = 1; }
			if(strcmp(buffer, "/no_firms") == 0) { in_no_firms = 0; }
			if(strcmp(buffer, "no_vacancies") == 0) { in_no_vacancies = 1; }
			if(strcmp(buffer, "/no_vacancies") == 0) { in_no_vacancies = 0; }
			if(strcmp(buffer, "firm_average_wage") == 0) { in_firm_average_wage = 1; }
			if(strcmp(buffer, "/firm_average_wage") == 0) { in_firm_average_wage = 0; }
			if(strcmp(buffer, "firm_average_wage_skill_1") == 0) { in_firm_average_wage_skill_1 = 1; }
			if(strcmp(buffer, "/firm_average_wage_skill_1") == 0) { in_firm_average_wage_skill_1 = 0; }
			if(strcmp(buffer, "firm_average_wage_skill_2") == 0) { in_firm_average_wage_skill_2 = 1; }
			if(strcmp(buffer, "/firm_average_wage_skill_2") == 0) { in_firm_average_wage_skill_2 = 0; }
			if(strcmp(buffer, "firm_average_wage_skill_3") == 0) { in_firm_average_wage_skill_3 = 1; }
			if(strcmp(buffer, "/firm_average_wage_skill_3") == 0) { in_firm_average_wage_skill_3 = 0; }
			if(strcmp(buffer, "firm_average_wage_skill_4") == 0) { in_firm_average_wage_skill_4 = 1; }
			if(strcmp(buffer, "/firm_average_wage_skill_4") == 0) { in_firm_average_wage_skill_4 = 0; }
			if(strcmp(buffer, "firm_average_wage_skill_5") == 0) { in_firm_average_wage_skill_5 = 1; }
			if(strcmp(buffer, "/firm_average_wage_skill_5") == 0) { in_firm_average_wage_skill_5 = 0; }
			if(strcmp(buffer, "firm_average_s_skill") == 0) { in_firm_average_s_skill = 1; }
			if(strcmp(buffer, "/firm_average_s_skill") == 0) { in_firm_average_s_skill = 0; }
			if(strcmp(buffer, "firm_average_s_skill_1") == 0) { in_firm_average_s_skill_1 = 1; }
			if(strcmp(buffer, "/firm_average_s_skill_1") == 0) { in_firm_average_s_skill_1 = 0; }
			if(strcmp(buffer, "firm_average_s_skill_2") == 0) { in_firm_average_s_skill_2 = 1; }
			if(strcmp(buffer, "/firm_average_s_skill_2") == 0) { in_firm_average_s_skill_2 = 0; }
			if(strcmp(buffer, "firm_average_s_skill_3") == 0) { in_firm_average_s_skill_3 = 1; }
			if(strcmp(buffer, "/firm_average_s_skill_3") == 0) { in_firm_average_s_skill_3 = 0; }
			if(strcmp(buffer, "firm_average_s_skill_4") == 0) { in_firm_average_s_skill_4 = 1; }
			if(strcmp(buffer, "/firm_average_s_skill_4") == 0) { in_firm_average_s_skill_4 = 0; }
			if(strcmp(buffer, "firm_average_s_skill_5") == 0) { in_firm_average_s_skill_5 = 1; }
			if(strcmp(buffer, "/firm_average_s_skill_5") == 0) { in_firm_average_s_skill_5 = 0; }
			if(strcmp(buffer, "region_firm_data") == 0) { in_region_firm_data = 1; }
			if(strcmp(buffer, "/region_firm_data") == 0) { in_region_firm_data = 0; }
			if(strcmp(buffer, "region_household_data") == 0) { in_region_household_data = 1; }
			if(strcmp(buffer, "/region_household_data") == 0) { in_region_household_data = 0; }
			if(strcmp(buffer, "government_tax_rates") == 0) { in_government_tax_rates = 1; }
			if(strcmp(buffer, "/government_tax_rates") == 0) { in_government_tax_rates = 0; }
			if(strcmp(buffer, "total_earnings") == 0) { in_total_earnings = 1; }
			if(strcmp(buffer, "/total_earnings") == 0) { in_total_earnings = 0; }
			if(strcmp(buffer, "total_equity") == 0) { in_total_equity = 1; }
			if(strcmp(buffer, "/total_equity") == 0) { in_total_equity = 0; }
			if(strcmp(buffer, "average_debt_earnings_ratio") == 0) { in_average_debt_earnings_ratio = 1; }
			if(strcmp(buffer, "/average_debt_earnings_ratio") == 0) { in_average_debt_earnings_ratio = 0; }
			if(strcmp(buffer, "average_debt_equity_ratio") == 0) { in_average_debt_equity_ratio = 1; }
			if(strcmp(buffer, "/average_debt_equity_ratio") == 0) { in_average_debt_equity_ratio = 0; }
			if(strcmp(buffer, "labour_share_ratio") == 0) { in_labour_share_ratio = 1; }
			if(strcmp(buffer, "/labour_share_ratio") == 0) { in_labour_share_ratio = 0; }
			if(strcmp(buffer, "cpi") == 0) { in_cpi = 1; }
			if(strcmp(buffer, "/cpi") == 0) { in_cpi = 0; }
			if(strcmp(buffer, "gdp") == 0) { in_gdp = 1; }
			if(strcmp(buffer, "/gdp") == 0) { in_gdp = 0; }
			if(strcmp(buffer, "monthly_sold_quantity") == 0) { in_monthly_sold_quantity = 1; }
			if(strcmp(buffer, "/monthly_sold_quantity") == 0) { in_monthly_sold_quantity = 0; }
			if(strcmp(buffer, "monthly_output") == 0) { in_monthly_output = 1; }
			if(strcmp(buffer, "/monthly_output") == 0) { in_monthly_output = 0; }
			if(strcmp(buffer, "monthly_revenue") == 0) { in_monthly_revenue = 1; }
			if(strcmp(buffer, "/monthly_revenue") == 0) { in_monthly_revenue = 0; }
			if(strcmp(buffer, "monthly_planned_output") == 0) { in_monthly_planned_output = 1; }
			if(strcmp(buffer, "/monthly_planned_output") == 0) { in_monthly_planned_output = 0; }
			if(strcmp(buffer, "history_monthly") == 0) { in_history_monthly = 1; }
			if(strcmp(buffer, "/history_monthly") == 0) { in_history_monthly = 0; }
			if(strcmp(buffer, "history_quarterly") == 0) { in_history_quarterly = 1; }
			if(strcmp(buffer, "/history_quarterly") == 0) { in_history_quarterly = 0; }
			if(strcmp(buffer, "monthly_growth_rates") == 0) { in_monthly_growth_rates = 1; }
			if(strcmp(buffer, "/monthly_growth_rates") == 0) { in_monthly_growth_rates = 0; }
			if(strcmp(buffer, "quarterly_growth_rates") == 0) { in_quarterly_growth_rates = 1; }
			if(strcmp(buffer, "/quarterly_growth_rates") == 0) { in_quarterly_growth_rates = 0; }
			if(strcmp(buffer, "annual_growth_rates_monthly") == 0) { in_annual_growth_rates_monthly = 1; }
			if(strcmp(buffer, "/annual_growth_rates_monthly") == 0) { in_annual_growth_rates_monthly = 0; }
			if(strcmp(buffer, "annual_growth_rates_quarterly") == 0) { in_annual_growth_rates_quarterly = 1; }
			if(strcmp(buffer, "/annual_growth_rates_quarterly") == 0) { in_annual_growth_rates_quarterly = 0; }
			if(strcmp(buffer, "no_firm_births") == 0) { in_no_firm_births = 1; }
			if(strcmp(buffer, "/no_firm_births") == 0) { in_no_firm_births = 0; }
			if(strcmp(buffer, "no_firm_deaths") == 0) { in_no_firm_deaths = 1; }
			if(strcmp(buffer, "/no_firm_deaths") == 0) { in_no_firm_deaths = 0; }
			if(strcmp(buffer, "firm_age_distribution") == 0) { in_firm_age_distribution = 1; }
			if(strcmp(buffer, "/firm_age_distribution") == 0) { in_firm_age_distribution = 0; }
			if(strcmp(buffer, "firm_age_distribution_multiperiod") == 0) { in_firm_age_distribution_multiperiod = 1; }
			if(strcmp(buffer, "/firm_age_distribution_multiperiod") == 0) { in_firm_age_distribution_multiperiod = 0; }
			if(strcmp(buffer, "firm_age_distribution_1_period_lag") == 0) { in_firm_age_distribution_1_period_lag = 1; }
			if(strcmp(buffer, "/firm_age_distribution_1_period_lag") == 0) { in_firm_age_distribution_1_period_lag = 0; }
			if(strcmp(buffer, "firm_age_distribution_2_period_lag") == 0) { in_firm_age_distribution_2_period_lag = 1; }
			if(strcmp(buffer, "/firm_age_distribution_2_period_lag") == 0) { in_firm_age_distribution_2_period_lag = 0; }
			if(strcmp(buffer, "firm_birth_rate") == 0) { in_firm_birth_rate = 1; }
			if(strcmp(buffer, "/firm_birth_rate") == 0) { in_firm_birth_rate = 0; }
			if(strcmp(buffer, "firm_death_rate") == 0) { in_firm_death_rate = 1; }
			if(strcmp(buffer, "/firm_death_rate") == 0) { in_firm_death_rate = 0; }
			if(strcmp(buffer, "survival_rate") == 0) { in_survival_rate = 1; }
			if(strcmp(buffer, "/survival_rate") == 0) { in_survival_rate = 0; }
			if(strcmp(buffer, "survival_rate_multiperiod_1") == 0) { in_survival_rate_multiperiod_1 = 1; }
			if(strcmp(buffer, "/survival_rate_multiperiod_1") == 0) { in_survival_rate_multiperiod_1 = 0; }
			if(strcmp(buffer, "survival_rate_multiperiod_2") == 0) { in_survival_rate_multiperiod_2 = 1; }
			if(strcmp(buffer, "/survival_rate_multiperiod_2") == 0) { in_survival_rate_multiperiod_2 = 0; }
			if(strcmp(buffer, "survival_rate_multiperiod") == 0) { in_survival_rate_multiperiod = 1; }
			if(strcmp(buffer, "/survival_rate_multiperiod") == 0) { in_survival_rate_multiperiod = 0; }
			if(strcmp(buffer, "max_firm_creation") == 0) { in_max_firm_creation = 1; }
			if(strcmp(buffer, "/max_firm_creation") == 0) { in_max_firm_creation = 0; }
			if(strcmp(buffer, "recession_started") == 0) { in_recession_started = 1; }
			if(strcmp(buffer, "/recession_started") == 0) { in_recession_started = 0; }
			if(strcmp(buffer, "recession_duration") == 0) { in_recession_duration = 1; }
			if(strcmp(buffer, "/recession_duration") == 0) { in_recession_duration = 0; }
			if(strcmp(buffer, "region_export_volume") == 0) { in_region_export_volume = 1; }
			if(strcmp(buffer, "/region_export_volume") == 0) { in_region_export_volume = 0; }
			if(strcmp(buffer, "region_import_volume") == 0) { in_region_import_volume = 1; }
			if(strcmp(buffer, "/region_import_volume") == 0) { in_region_import_volume = 0; }
			if(strcmp(buffer, "region_export_value") == 0) { in_region_export_value = 1; }
			if(strcmp(buffer, "/region_export_value") == 0) { in_region_export_value = 0; }
			if(strcmp(buffer, "region_import_value") == 0) { in_region_import_value = 1; }
			if(strcmp(buffer, "/region_import_value") == 0) { in_region_import_value = 0; }
			if(strcmp(buffer, "region_import_previous_value") == 0) { in_region_import_previous_value = 1; }
			if(strcmp(buffer, "/region_import_previous_value") == 0) { in_region_import_previous_value = 0; }
			if(strcmp(buffer, "firm_balance_sheets") == 0) { in_firm_balance_sheets = 1; }
			if(strcmp(buffer, "/firm_balance_sheets") == 0) { in_firm_balance_sheets = 0; }
			if(strcmp(buffer, "household_balance_sheets") == 0) { in_household_balance_sheets = 1; }
			if(strcmp(buffer, "/household_balance_sheets") == 0) { in_household_balance_sheets = 0; }
			if(strcmp(buffer, "igfirm_balance_sheets") == 0) { in_igfirm_balance_sheets = 1; }
			if(strcmp(buffer, "/igfirm_balance_sheets") == 0) { in_igfirm_balance_sheets = 0; }
			if(strcmp(buffer, "gov_balance_sheets") == 0) { in_gov_balance_sheets = 1; }
			if(strcmp(buffer, "/gov_balance_sheets") == 0) { in_gov_balance_sheets = 0; }
			if(strcmp(buffer, "bank_balance_sheets") == 0) { in_bank_balance_sheets = 1; }
			if(strcmp(buffer, "/bank_balance_sheets") == 0) { in_bank_balance_sheets = 0; }
			if(strcmp(buffer, "ecb_balance_sheets") == 0) { in_ecb_balance_sheets = 1; }
			if(strcmp(buffer, "/ecb_balance_sheets") == 0) { in_ecb_balance_sheets = 0; }
			if(strcmp(buffer, "firm_average_productivity_progress") == 0) { in_firm_average_productivity_progress = 1; }
			if(strcmp(buffer, "/firm_average_productivity_progress") == 0) { in_firm_average_productivity_progress = 0; }
			if(strcmp(buffer, "firm_average_productivity") == 0) { in_firm_average_productivity = 1; }
			if(strcmp(buffer, "/firm_average_productivity") == 0) { in_firm_average_productivity = 0; }
			if(strcmp(buffer, "cash") == 0) { in_cash = 1; }
			if(strcmp(buffer, "/cash") == 0) { in_cash = 0; }
			if(strcmp(buffer, "total_credit") == 0) { in_total_credit = 1; }
			if(strcmp(buffer, "/total_credit") == 0) { in_total_credit = 0; }
			if(strcmp(buffer, "ecb_debt") == 0) { in_ecb_debt = 1; }
			if(strcmp(buffer, "/ecb_debt") == 0) { in_ecb_debt = 0; }
			if(strcmp(buffer, "alfa") == 0) { in_alfa = 1; }
			if(strcmp(buffer, "/alfa") == 0) { in_alfa = 0; }
			if(strcmp(buffer, "value_at_risk") == 0) { in_value_at_risk = 1; }
			if(strcmp(buffer, "/value_at_risk") == 0) { in_value_at_risk = 0; }
			if(strcmp(buffer, "bank_gamma") == 0) { in_bank_gamma = 1; }
			if(strcmp(buffer, "/bank_gamma") == 0) { in_bank_gamma = 0; }
			if(strcmp(buffer, "profits") == 0) { in_profits = 1; }
			if(strcmp(buffer, "/profits") == 0) { in_profits = 0; }
			if(strcmp(buffer, "bank_lambda") == 0) { in_bank_lambda = 1; }
			if(strcmp(buffer, "/bank_lambda") == 0) { in_bank_lambda = 0; }
			if(strcmp(buffer, "ecb_interest_rate") == 0) { in_ecb_interest_rate = 1; }
			if(strcmp(buffer, "/ecb_interest_rate") == 0) { in_ecb_interest_rate = 0; }
			if(strcmp(buffer, "bank_dividend_rate") == 0) { in_bank_dividend_rate = 1; }
			if(strcmp(buffer, "/bank_dividend_rate") == 0) { in_bank_dividend_rate = 0; }
			if(strcmp(buffer, "debt_period") == 0) { in_debt_period = 1; }
			if(strcmp(buffer, "/debt_period") == 0) { in_debt_period = 0; }
			if(strcmp(buffer, "loan_request_message_found") == 0) { in_loan_request_message_found = 1; }
			if(strcmp(buffer, "/loan_request_message_found") == 0) { in_loan_request_message_found = 0; }
			if(strcmp(buffer, "deposits") == 0) { in_deposits = 1; }
			if(strcmp(buffer, "/deposits") == 0) { in_deposits = 0; }
			if(strcmp(buffer, "firm_loan_installments") == 0) { in_firm_loan_installments = 1; }
			if(strcmp(buffer, "/firm_loan_installments") == 0) { in_firm_loan_installments = 0; }
			if(strcmp(buffer, "firm_interest_payments") == 0) { in_firm_interest_payments = 1; }
			if(strcmp(buffer, "/firm_interest_payments") == 0) { in_firm_interest_payments = 0; }
			if(strcmp(buffer, "firm_loan_issues") == 0) { in_firm_loan_issues = 1; }
			if(strcmp(buffer, "/firm_loan_issues") == 0) { in_firm_loan_issues = 0; }
			if(strcmp(buffer, "ecb_interest_payment") == 0) { in_ecb_interest_payment = 1; }
			if(strcmp(buffer, "/ecb_interest_payment") == 0) { in_ecb_interest_payment = 0; }
			if(strcmp(buffer, "dividend_payment") == 0) { in_dividend_payment = 1; }
			if(strcmp(buffer, "/dividend_payment") == 0) { in_dividend_payment = 0; }
			if(strcmp(buffer, "taxes") == 0) { in_taxes = 1; }
			if(strcmp(buffer, "/taxes") == 0) { in_taxes = 0; }
			if(strcmp(buffer, "list_of_regions") == 0) { in_list_of_regions = 1; }
			if(strcmp(buffer, "/list_of_regions") == 0) { in_list_of_regions = 0; }
			if(strcmp(buffer, "money_financing_fraction") == 0) { in_money_financing_fraction = 1; }
			if(strcmp(buffer, "/money_financing_fraction") == 0) { in_money_financing_fraction = 0; }
			if(strcmp(buffer, "gdp_fraction_consumption") == 0) { in_gdp_fraction_consumption = 1; }
			if(strcmp(buffer, "/gdp_fraction_consumption") == 0) { in_gdp_fraction_consumption = 0; }
			if(strcmp(buffer, "gdp_fraction_investment") == 0) { in_gdp_fraction_investment = 1; }
			if(strcmp(buffer, "/gdp_fraction_investment") == 0) { in_gdp_fraction_investment = 0; }
			if(strcmp(buffer, "monthly_tax_revenues") == 0) { in_monthly_tax_revenues = 1; }
			if(strcmp(buffer, "/monthly_tax_revenues") == 0) { in_monthly_tax_revenues = 0; }
			if(strcmp(buffer, "yearly_tax_revenues") == 0) { in_yearly_tax_revenues = 1; }
			if(strcmp(buffer, "/yearly_tax_revenues") == 0) { in_yearly_tax_revenues = 0; }
			if(strcmp(buffer, "monthly_benefit_payment") == 0) { in_monthly_benefit_payment = 1; }
			if(strcmp(buffer, "/monthly_benefit_payment") == 0) { in_monthly_benefit_payment = 0; }
			if(strcmp(buffer, "yearly_benefit_payment") == 0) { in_yearly_benefit_payment = 1; }
			if(strcmp(buffer, "/yearly_benefit_payment") == 0) { in_yearly_benefit_payment = 0; }
			if(strcmp(buffer, "hh_transfer_payment") == 0) { in_hh_transfer_payment = 1; }
			if(strcmp(buffer, "/hh_transfer_payment") == 0) { in_hh_transfer_payment = 0; }
			if(strcmp(buffer, "firm_transfer_payment") == 0) { in_firm_transfer_payment = 1; }
			if(strcmp(buffer, "/firm_transfer_payment") == 0) { in_firm_transfer_payment = 0; }
			if(strcmp(buffer, "monthly_transfer_payment") == 0) { in_monthly_transfer_payment = 1; }
			if(strcmp(buffer, "/monthly_transfer_payment") == 0) { in_monthly_transfer_payment = 0; }
			if(strcmp(buffer, "yearly_transfer_payment") == 0) { in_yearly_transfer_payment = 1; }
			if(strcmp(buffer, "/yearly_transfer_payment") == 0) { in_yearly_transfer_payment = 0; }
			if(strcmp(buffer, "hh_subsidy_payment") == 0) { in_hh_subsidy_payment = 1; }
			if(strcmp(buffer, "/hh_subsidy_payment") == 0) { in_hh_subsidy_payment = 0; }
			if(strcmp(buffer, "firm_subsidy_payment") == 0) { in_firm_subsidy_payment = 1; }
			if(strcmp(buffer, "/firm_subsidy_payment") == 0) { in_firm_subsidy_payment = 0; }
			if(strcmp(buffer, "monthly_subsidy_payment") == 0) { in_monthly_subsidy_payment = 1; }
			if(strcmp(buffer, "/monthly_subsidy_payment") == 0) { in_monthly_subsidy_payment = 0; }
			if(strcmp(buffer, "yearly_subsidy_payment") == 0) { in_yearly_subsidy_payment = 1; }
			if(strcmp(buffer, "/yearly_subsidy_payment") == 0) { in_yearly_subsidy_payment = 0; }
			if(strcmp(buffer, "monthly_bond_interest_payment") == 0) { in_monthly_bond_interest_payment = 1; }
			if(strcmp(buffer, "/monthly_bond_interest_payment") == 0) { in_monthly_bond_interest_payment = 0; }
			if(strcmp(buffer, "yearly_bond_interest_payment") == 0) { in_yearly_bond_interest_payment = 1; }
			if(strcmp(buffer, "/yearly_bond_interest_payment") == 0) { in_yearly_bond_interest_payment = 0; }
			if(strcmp(buffer, "gov_interest_rate") == 0) { in_gov_interest_rate = 1; }
			if(strcmp(buffer, "/gov_interest_rate") == 0) { in_gov_interest_rate = 0; }
			if(strcmp(buffer, "yearly_investment_expenditure") == 0) { in_yearly_investment_expenditure = 1; }
			if(strcmp(buffer, "/yearly_investment_expenditure") == 0) { in_yearly_investment_expenditure = 0; }
			if(strcmp(buffer, "yearly_consumption_expenditure") == 0) { in_yearly_consumption_expenditure = 1; }
			if(strcmp(buffer, "/yearly_consumption_expenditure") == 0) { in_yearly_consumption_expenditure = 0; }
			if(strcmp(buffer, "yearly_income") == 0) { in_yearly_income = 1; }
			if(strcmp(buffer, "/yearly_income") == 0) { in_yearly_income = 0; }
			if(strcmp(buffer, "yearly_expenditure") == 0) { in_yearly_expenditure = 1; }
			if(strcmp(buffer, "/yearly_expenditure") == 0) { in_yearly_expenditure = 0; }
			if(strcmp(buffer, "yearly_budget_balance") == 0) { in_yearly_budget_balance = 1; }
			if(strcmp(buffer, "/yearly_budget_balance") == 0) { in_yearly_budget_balance = 0; }
			if(strcmp(buffer, "total_money_financing") == 0) { in_total_money_financing = 1; }
			if(strcmp(buffer, "/total_money_financing") == 0) { in_total_money_financing = 0; }
			if(strcmp(buffer, "total_bond_financing") == 0) { in_total_bond_financing = 1; }
			if(strcmp(buffer, "/total_bond_financing") == 0) { in_total_bond_financing = 0; }
			if(strcmp(buffer, "country_wide_mean_wage") == 0) { in_country_wide_mean_wage = 1; }
			if(strcmp(buffer, "/country_wide_mean_wage") == 0) { in_country_wide_mean_wage = 0; }
			if(strcmp(buffer, "num_unemployed") == 0) { in_num_unemployed = 1; }
			if(strcmp(buffer, "/num_unemployed") == 0) { in_num_unemployed = 0; }
			if(strcmp(buffer, "gdp_growth") == 0) { in_gdp_growth = 1; }
			if(strcmp(buffer, "/gdp_growth") == 0) { in_gdp_growth = 0; }
			if(strcmp(buffer, "gdp_forecast") == 0) { in_gdp_forecast = 1; }
			if(strcmp(buffer, "/gdp_forecast") == 0) { in_gdp_forecast = 0; }
			if(strcmp(buffer, "yearly_income_forecast") == 0) { in_yearly_income_forecast = 1; }
			if(strcmp(buffer, "/yearly_income_forecast") == 0) { in_yearly_income_forecast = 0; }
			if(strcmp(buffer, "yearly_expenditure_budget") == 0) { in_yearly_expenditure_budget = 1; }
			if(strcmp(buffer, "/yearly_expenditure_budget") == 0) { in_yearly_expenditure_budget = 0; }
			if(strcmp(buffer, "budget_balance_forecast") == 0) { in_budget_balance_forecast = 1; }
			if(strcmp(buffer, "/budget_balance_forecast") == 0) { in_budget_balance_forecast = 0; }
			if(strcmp(buffer, "monthly_investment_expenditure") == 0) { in_monthly_investment_expenditure = 1; }
			if(strcmp(buffer, "/monthly_investment_expenditure") == 0) { in_monthly_investment_expenditure = 0; }
			if(strcmp(buffer, "monthly_budget_balance") == 0) { in_monthly_budget_balance = 1; }
			if(strcmp(buffer, "/monthly_budget_balance") == 0) { in_monthly_budget_balance = 0; }
			if(strcmp(buffer, "monthly_consumption_budget") == 0) { in_monthly_consumption_budget = 1; }
			if(strcmp(buffer, "/monthly_consumption_budget") == 0) { in_monthly_consumption_budget = 0; }
			if(strcmp(buffer, "monthly_investment_budget") == 0) { in_monthly_investment_budget = 1; }
			if(strcmp(buffer, "/monthly_investment_budget") == 0) { in_monthly_investment_budget = 0; }
			if(strcmp(buffer, "monthly_income") == 0) { in_monthly_income = 1; }
			if(strcmp(buffer, "/monthly_income") == 0) { in_monthly_income = 0; }
			if(strcmp(buffer, "monthly_expenditure") == 0) { in_monthly_expenditure = 1; }
			if(strcmp(buffer, "/monthly_expenditure") == 0) { in_monthly_expenditure = 0; }
			if(strcmp(buffer, "yearly_consumption_budget") == 0) { in_yearly_consumption_budget = 1; }
			if(strcmp(buffer, "/yearly_consumption_budget") == 0) { in_yearly_consumption_budget = 0; }
			if(strcmp(buffer, "yearly_investment_budget") == 0) { in_yearly_investment_budget = 1; }
			if(strcmp(buffer, "/yearly_investment_budget") == 0) { in_yearly_investment_budget = 0; }
			if(strcmp(buffer, "value_bonds_outstanding") == 0) { in_value_bonds_outstanding = 1; }
			if(strcmp(buffer, "/value_bonds_outstanding") == 0) { in_value_bonds_outstanding = 0; }
			if(strcmp(buffer, "nr_bonds_outstanding") == 0) { in_nr_bonds_outstanding = 1; }
			if(strcmp(buffer, "/nr_bonds_outstanding") == 0) { in_nr_bonds_outstanding = 0; }
			if(strcmp(buffer, "accounts") == 0) { in_accounts = 1; }
			if(strcmp(buffer, "/accounts") == 0) { in_accounts = 0; }
			if(strcmp(buffer, "total_ecb_debt") == 0) { in_total_ecb_debt = 1; }
			if(strcmp(buffer, "/total_ecb_debt") == 0) { in_total_ecb_debt = 0; }
			if(strcmp(buffer, "payment_account_private_sector") == 0) { in_payment_account_private_sector = 1; }
			if(strcmp(buffer, "/payment_account_private_sector") == 0) { in_payment_account_private_sector = 0; }
			if(strcmp(buffer, "payment_account_public_sector") == 0) { in_payment_account_public_sector = 1; }
			if(strcmp(buffer, "/payment_account_public_sector") == 0) { in_payment_account_public_sector = 0; }
			if(strcmp(buffer, "fiat_money") == 0) { in_fiat_money = 1; }
			if(strcmp(buffer, "/fiat_money") == 0) { in_fiat_money = 0; }
			if(strcmp(buffer, "bank_interest") == 0) { in_bank_interest = 1; }
			if(strcmp(buffer, "/bank_interest") == 0) { in_bank_interest = 0; }
			if(strcmp(buffer, "gov_bond_purchase") == 0) { in_gov_bond_purchase = 1; }
			if(strcmp(buffer, "/gov_bond_purchase") == 0) { in_gov_bond_purchase = 0; }
			if(strcmp(buffer, "assets") == 0) { in_assets = 1; }
			if(strcmp(buffer, "/assets") == 0) { in_assets = 0; }
			if(strcmp(buffer, "clearingmechanism") == 0) { in_clearingmechanism = 1; }
			if(strcmp(buffer, "/clearingmechanism") == 0) { in_clearingmechanism = 0; }
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(FLAME_in_xagent)
			{
				if(FLAME_in_name)
				{
					strcpy(agentname, buffer);

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
					else if(strcmp(agentname, "Central_Bank") == 0)
					{
						current_Central_Bank_agent = init_Central_Bank_agent();
						in_Central_Bank_agent = 1;
					}
					else if(strcmp(agentname, "Clearinghouse") == 0)
					{
						current_Clearinghouse_agent = init_Clearinghouse_agent();
						in_Clearinghouse_agent = 1;
					}
					else
					{
						printf("Warning: agent name undefined - '%s'\n", agentname);
						exit(0);
					}
				}
				else if(in_Firm_agent == 1)
				{
					if(in_id) { current_Firm_agent->id = atoi(buffer); }
					if(in_region_id) { current_Firm_agent->region_id = atoi(buffer); }
					if(in_gov_id) { current_Firm_agent->gov_id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_Firm_agent->day_of_month_to_act = atoi(buffer); }
					if(in_last_day_of_month_to_act) { current_Firm_agent->last_day_of_month_to_act = atoi(buffer); }
					if(in_payment_account) { current_Firm_agent->payment_account = atof(buffer); }
					if(in_bank_id) { current_Firm_agent->bank_id = atoi(buffer); }
					if(in_partition_id) { current_Firm_agent->partition_id = atoi(buffer); }
					if(in_mean_wage) { current_Firm_agent->mean_wage = atof(buffer); }
					if(in_needed_capital_stock) { current_Firm_agent->needed_capital_stock = atof(buffer); }
					if(in_actual_cap_price) { current_Firm_agent->actual_cap_price = atof(buffer); }
					if(in_mean_specific_skills) { current_Firm_agent->mean_specific_skills = atof(buffer); }
					if(in_planned_production_quantity) { current_Firm_agent->planned_production_quantity = atof(buffer); }
					if(in_production_quantity) { current_Firm_agent->production_quantity = atof(buffer); }
					if(in_planned_output) { current_Firm_agent->planned_output = atof(buffer); }
					if(in_output) { current_Firm_agent->output = atof(buffer); }
					if(in_unit_costs) { current_Firm_agent->unit_costs = atof(buffer); }
					if(in_total_supply) { current_Firm_agent->total_supply = atof(buffer); }
					if(in_production_costs) { current_Firm_agent->production_costs = atof(buffer); }
					if(in_revenue_per_day) { current_Firm_agent->revenue_per_day = atof(buffer); }
					if(in_technological_frontier) { current_Firm_agent->technological_frontier = atof(buffer); }
					if(in_cum_revenue) { current_Firm_agent->cum_revenue = atof(buffer); }
					if(in_out_of_stock_costs) { current_Firm_agent->out_of_stock_costs = atof(buffer); }
					if(in_malls_sales_statistics) { j = 0;
						rc = read_sales_statistics_dynamic_array(buffer, index, &j, &current_Firm_agent->malls_sales_statistics);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'malls_sales_statistics' of type 'sales_statistics_array'\n"); exit(0); } }
					if(in_quality) { current_Firm_agent->quality = atof(buffer); }
					if(in_price) { current_Firm_agent->price = atof(buffer); }
					if(in_price_last_month) { current_Firm_agent->price_last_month = atof(buffer); }
					if(in_demand_capital_stock) { current_Firm_agent->demand_capital_stock = atof(buffer); }
					if(in_planned_production_costs) { current_Firm_agent->planned_production_costs = atof(buffer); }
					if(in_adaption_production_volume_due_to_insufficient_finances) { current_Firm_agent->adaption_production_volume_due_to_insufficient_finances = atof(buffer); }
					if(in_fraction_reserved_for_delayed_payments) { current_Firm_agent->fraction_reserved_for_delayed_payments = atof(buffer); }
					if(in_sold_quantities) { j = 0;
						rc = read_sold_quantities_per_mall_dynamic_array(buffer, index, &j, &current_Firm_agent->sold_quantities);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'sold_quantities' of type 'sold_quantities_per_mall_array'\n"); exit(0); } }
					if(in_total_sold_quantity) { current_Firm_agent->total_sold_quantity = atof(buffer); }
					if(in_cum_total_sold_quantity) { current_Firm_agent->cum_total_sold_quantity = atof(buffer); }
					if(in_sold_quantity_in_calendar_month) { current_Firm_agent->sold_quantity_in_calendar_month = atof(buffer); }
					if(in_delivery_volume) { j = 0;
						rc = read_delivery_volume_per_mall_dynamic_array(buffer, index, &j, &current_Firm_agent->delivery_volume);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'delivery_volume' of type 'delivery_volume_per_mall_array'\n"); exit(0); } }
					if(in_planned_delivery_volume) { j = 0;
						rc = read_delivery_volume_per_mall_dynamic_array(buffer, index, &j, &current_Firm_agent->planned_delivery_volume);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'planned_delivery_volume' of type 'delivery_volume_per_mall_array'\n"); exit(0); } }
					if(in_current_mall_stocks) { j = 0;
						rc = read_mall_info_dynamic_array(buffer, index, &j, &current_Firm_agent->current_mall_stocks);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'current_mall_stocks' of type 'mall_info_array'\n"); exit(0); } }
					if(in_last_planned_production_quantities) { j = 0;
						rc = read_double_dynamic_array(buffer, index, &j, &current_Firm_agent->last_planned_production_quantities);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'last_planned_production_quantities' of type 'double_array'\n"); exit(0); } }
					if(in_total_external_financing_obtained) { current_Firm_agent->total_external_financing_obtained = atof(buffer); }
					if(in_capital_costs) { current_Firm_agent->capital_costs = atof(buffer); }
					if(in_labour_costs) { current_Firm_agent->labour_costs = atof(buffer); }
					if(in_capital_financing) { j = 0;
						rc = read_financing_capital_dynamic_array(buffer, index, &j, &current_Firm_agent->capital_financing);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'capital_financing' of type 'financing_capital_array'\n"); exit(0); } }
					if(in_financial_resources_for_production) { current_Firm_agent->financial_resources_for_production = atof(buffer); }
					if(in_planned_value_capital_stock) { current_Firm_agent->planned_value_capital_stock = atof(buffer); }
					if(in_total_units_local_inventory) { current_Firm_agent->total_units_local_inventory = atof(buffer); }
					if(in_calc_capital_costs) { current_Firm_agent->calc_capital_costs = atof(buffer); }
					if(in_calc_production_costs) { current_Firm_agent->calc_production_costs = atof(buffer); }
					if(in_firm_productivity) { current_Firm_agent->firm_productivity = atof(buffer); }
					if(in_firm_productivity_last_year) { current_Firm_agent->firm_productivity_last_year = atof(buffer); }
					if(in_firm_productivity_progress) { current_Firm_agent->firm_productivity_progress = atof(buffer); }
					if(in_set_of_lenders) { j = 0;
						rc = read_potential_lender_dynamic_array(buffer, index, &j, &current_Firm_agent->set_of_lenders);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'set_of_lenders' of type 'potential_lender_array'\n"); exit(0); } }
					if(in_number_of_banks_asked) { current_Firm_agent->number_of_banks_asked = atoi(buffer); }
					if(in_ebit) { current_Firm_agent->ebit = atof(buffer); }
					if(in_earnings) { current_Firm_agent->earnings = atof(buffer); }
					if(in_tax_rate_corporate) { current_Firm_agent->tax_rate_corporate = atof(buffer); }
					if(in_tax_rate_vat) { current_Firm_agent->tax_rate_vat = atof(buffer); }
					if(in_tax_payment) { current_Firm_agent->tax_payment = atof(buffer); }
					if(in_net_earnings) { current_Firm_agent->net_earnings = atof(buffer); }
					if(in_previous_net_earnings) { current_Firm_agent->previous_net_earnings = atof(buffer); }
					if(in_total_interest_payment) { current_Firm_agent->total_interest_payment = atof(buffer); }
					if(in_total_debt_installment_payment) { current_Firm_agent->total_debt_installment_payment = atof(buffer); }
					if(in_total_dividend_payment) { current_Firm_agent->total_dividend_payment = atof(buffer); }
					if(in_current_share_price) { current_Firm_agent->current_share_price = atof(buffer); }
					if(in_previous_dividend_per_share) { current_Firm_agent->previous_dividend_per_share = atof(buffer); }
					if(in_current_dividend_per_share) { current_Firm_agent->current_dividend_per_share = atof(buffer); }
					if(in_previous_earnings_per_share) { current_Firm_agent->previous_earnings_per_share = atof(buffer); }
					if(in_current_earnings_per_share) { current_Firm_agent->current_earnings_per_share = atof(buffer); }
					if(in_previous_dividend_per_earnings) { current_Firm_agent->previous_dividend_per_earnings = atof(buffer); }
					if(in_current_dividend_per_earnings) { current_Firm_agent->current_dividend_per_earnings = atof(buffer); }
					if(in_debt_earnings_ratio) { current_Firm_agent->debt_earnings_ratio = atof(buffer); }
					if(in_debt_equity_ratio) { current_Firm_agent->debt_equity_ratio = atof(buffer); }
					if(in_price_earnings_ratio) { current_Firm_agent->price_earnings_ratio = atof(buffer); }
					if(in_retained_earnings_ratio) { current_Firm_agent->retained_earnings_ratio = atof(buffer); }
					if(in_earnings_per_share_ratio_growth) { current_Firm_agent->earnings_per_share_ratio_growth = atof(buffer); }
					if(in_critical_price_earnings_ratio) { current_Firm_agent->critical_price_earnings_ratio = atof(buffer); }
					if(in_critical_earnings_per_share_ratio) { current_Firm_agent->critical_earnings_per_share_ratio = atof(buffer); }
					if(in_loans) { j = 0;
						rc = read_debt_item_dynamic_array(buffer, index, &j, &current_Firm_agent->loans);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'loans' of type 'debt_item_array'\n"); exit(0); } }
					if(in_total_debt) { current_Firm_agent->total_debt = atof(buffer); }
					if(in_total_value_local_inventory) { current_Firm_agent->total_value_local_inventory = atof(buffer); }
					if(in_total_units_capital_stock) { current_Firm_agent->total_units_capital_stock = atof(buffer); }
					if(in_total_value_capital_stock) { current_Firm_agent->total_value_capital_stock = atof(buffer); }
					if(in_total_capital_depreciation_value) { current_Firm_agent->total_capital_depreciation_value = atof(buffer); }
					if(in_total_capital_depreciation_units) { current_Firm_agent->total_capital_depreciation_units = atof(buffer); }
					if(in_total_assets) { current_Firm_agent->total_assets = atof(buffer); }
					if(in_equity) { current_Firm_agent->equity = atof(buffer); }
					if(in_production_liquidity_needs) { current_Firm_agent->production_liquidity_needs = atof(buffer); }
					if(in_financial_liquidity_needs) { current_Firm_agent->financial_liquidity_needs = atof(buffer); }
					if(in_total_financial_needs) { current_Firm_agent->total_financial_needs = atof(buffer); }
					if(in_external_financial_needs) { current_Firm_agent->external_financial_needs = atof(buffer); }
					if(in_earnings_per_share) { current_Firm_agent->earnings_per_share = atof(buffer); }
					if(in_total_payments) { current_Firm_agent->total_payments = atof(buffer); }
					if(in_previous_shares_outstanding) { current_Firm_agent->previous_shares_outstanding = atof(buffer); }
					if(in_total_income) { current_Firm_agent->total_income = atof(buffer); }
					if(in_total_liabilities) { current_Firm_agent->total_liabilities = atof(buffer); }
					if(in_total_expenses) { current_Firm_agent->total_expenses = atof(buffer); }
					if(in_current_shares_outstanding) { current_Firm_agent->current_shares_outstanding = atoi(buffer); }
					if(in_employees) { j = 0;
						rc = read_employee_dynamic_array(buffer, index, &j, &current_Firm_agent->employees);
						if(rc != 0) { printf("Error: reading 'Firm' agent variable 'employees' of type 'employee_array'\n"); exit(0); } }
					if(in_wage_offer) { current_Firm_agent->wage_offer = atof(buffer); }
					if(in_technology) { current_Firm_agent->technology = atof(buffer); }
					if(in_no_employees) { current_Firm_agent->no_employees = atoi(buffer); }
					if(in_no_employees_skill_1) { current_Firm_agent->no_employees_skill_1 = atoi(buffer); }
					if(in_no_employees_skill_2) { current_Firm_agent->no_employees_skill_2 = atoi(buffer); }
					if(in_no_employees_skill_3) { current_Firm_agent->no_employees_skill_3 = atoi(buffer); }
					if(in_no_employees_skill_4) { current_Firm_agent->no_employees_skill_4 = atoi(buffer); }
					if(in_no_employees_skill_5) { current_Firm_agent->no_employees_skill_5 = atoi(buffer); }
					if(in_vacancies) { current_Firm_agent->vacancies = atoi(buffer); }
					if(in_average_g_skill) { current_Firm_agent->average_g_skill = atof(buffer); }
					if(in_average_s_skill_of_1) { current_Firm_agent->average_s_skill_of_1 = atof(buffer); }
					if(in_average_s_skill_of_2) { current_Firm_agent->average_s_skill_of_2 = atof(buffer); }
					if(in_average_s_skill_of_3) { current_Firm_agent->average_s_skill_of_3 = atof(buffer); }
					if(in_average_s_skill_of_4) { current_Firm_agent->average_s_skill_of_4 = atof(buffer); }
					if(in_average_s_skill_of_5) { current_Firm_agent->average_s_skill_of_5 = atof(buffer); }
					if(in_wage_offer_for_skill_1) { current_Firm_agent->wage_offer_for_skill_1 = atof(buffer); }
					if(in_wage_offer_for_skill_2) { current_Firm_agent->wage_offer_for_skill_2 = atof(buffer); }
					if(in_wage_offer_for_skill_3) { current_Firm_agent->wage_offer_for_skill_3 = atof(buffer); }
					if(in_wage_offer_for_skill_4) { current_Firm_agent->wage_offer_for_skill_4 = atof(buffer); }
					if(in_wage_offer_for_skill_5) { current_Firm_agent->wage_offer_for_skill_5 = atof(buffer); }
					if(in_employees_needed) { current_Firm_agent->employees_needed = atoi(buffer); }
					if(in_age) { current_Firm_agent->age = atoi(buffer); }
					if(in_transfer_payment) { current_Firm_agent->transfer_payment = atof(buffer); }
					if(in_subsidy_payment) { current_Firm_agent->subsidy_payment = atof(buffer); }
					if(in_active) { current_Firm_agent->active = atoi(buffer); }
					if(in_bankruptcy_idle_counter) { current_Firm_agent->bankruptcy_idle_counter = atoi(buffer); }
					if(in_bankruptcy_state) { current_Firm_agent->bankruptcy_state = atoi(buffer); }
					if(in_bankruptcy_insolvency_state) { current_Firm_agent->bankruptcy_insolvency_state = atoi(buffer); }
					if(in_bankruptcy_illiquidity_state) { current_Firm_agent->bankruptcy_illiquidity_state = atoi(buffer); }
					if(in_financial_crisis_state) { current_Firm_agent->financial_crisis_state = atoi(buffer); }
				 }else if(in_Household_agent == 1)
				{
					if(in_id) { current_Household_agent->id = atoi(buffer); }
					if(in_region_id) { current_Household_agent->region_id = atoi(buffer); }
					if(in_neighboring_region_ids) { j = 0;
						rc = read_int_dynamic_array(buffer, index, &j, &current_Household_agent->neighboring_region_ids);
						if(rc != 0) { printf("Error: reading 'Household' agent variable 'neighboring_region_ids' of type 'int_array'\n"); exit(0); } }
					if(in_gov_id) { current_Household_agent->gov_id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_Household_agent->day_of_month_to_act = atoi(buffer); }
					if(in_payment_account) { current_Household_agent->payment_account = atof(buffer); }
					if(in_bank_id) { current_Household_agent->bank_id = atoi(buffer); }
					if(in_partition_id) { current_Household_agent->partition_id = atoi(buffer); }
					if(in_consumption_budget) { current_Household_agent->consumption_budget = atof(buffer); }
					if(in_mean_income) { current_Household_agent->mean_income = atof(buffer); }
					if(in_week_of_month) { current_Household_agent->week_of_month = atoi(buffer); }
					if(in_weekly_budget) { current_Household_agent->weekly_budget = atof(buffer); }
					if(in_rationed) { current_Household_agent->rationed = atoi(buffer); }
					if(in_mall_completely_sold_out) { current_Household_agent->mall_completely_sold_out = atoi(buffer); }
					if(in_order_quantity) { j = 0;
						rc = read_ordered_quantity_static_array(buffer, index, &j, current_Household_agent->order_quantity, 2);
						if(rc != 0) { printf("Error: reading 'Household' agent variable 'order_quantity' of type 'ordered_quantity'\n"); exit(0); } }
					if(in_received_quantity) { j = 0;
						rc = read_received_quantities_static_array(buffer, index, &j, current_Household_agent->received_quantity, 2);
						if(rc != 0) { printf("Error: reading 'Household' agent variable 'received_quantity' of type 'received_quantities'\n"); exit(0); } }
					if(in_day_of_week_to_act) { current_Household_agent->day_of_week_to_act = atoi(buffer); }
					if(in_day_of_month_receive_income) { current_Household_agent->day_of_month_receive_income = atoi(buffer); }
					if(in_current_productivity_employer) { current_Household_agent->current_productivity_employer = atof(buffer); }
					if(in_current_mean_specific_skills_employer) { current_Household_agent->current_mean_specific_skills_employer = atof(buffer); }
					if(in_tax_payment) { current_Household_agent->tax_payment = atof(buffer); }
					if(in_cum_total_dividends) { current_Household_agent->cum_total_dividends = atof(buffer); }
					if(in_tax_rate_hh_capital) { current_Household_agent->tax_rate_hh_capital = atof(buffer); }
					if(in_tax_rate_hh_labour) { current_Household_agent->tax_rate_hh_labour = atof(buffer); }
					if(in_price_index) { current_Household_agent->price_index = atof(buffer); }
					if(in_price_index_base_period) { current_Household_agent->price_index_base_period = atof(buffer); }
					if(in_commuting_costs_price_level_weight) { current_Household_agent->commuting_costs_price_level_weight = atof(buffer); }
					if(in_last_income) { j = 0;
						rc = read_double_dynamic_array(buffer, index, &j, &current_Household_agent->last_income);
						if(rc != 0) { printf("Error: reading 'Household' agent variable 'last_income' of type 'double_array'\n"); exit(0); } }
					if(in_expenditures) { current_Household_agent->expenditures = atof(buffer); }
					if(in_received_dividend) { current_Household_agent->received_dividend = atof(buffer); }
					if(in_flag_consumption_shifting) { current_Household_agent->flag_consumption_shifting = atoi(buffer); }
					if(in_excess_weekly_budget) { current_Household_agent->excess_weekly_budget = atof(buffer); }
					if(in_assetsowned) { j = 0;
						rc = read_Asset_dynamic_array(buffer, index, &j, &current_Household_agent->assetsowned);
						if(rc != 0) { printf("Error: reading 'Household' agent variable 'assetsowned' of type 'Asset_array'\n"); exit(0); } }
					if(in_wage) { current_Household_agent->wage = atof(buffer); }
					if(in_wage_reservation) { current_Household_agent->wage_reservation = atof(buffer); }
					if(in_general_skill) { current_Household_agent->general_skill = atoi(buffer); }
					if(in_on_the_job_search) { current_Household_agent->on_the_job_search = atoi(buffer); }
					if(in_number_applications) { current_Household_agent->number_applications = atoi(buffer); }
					if(in_last_labour_income) { current_Household_agent->last_labour_income = atof(buffer); }
					if(in_specific_skill) { current_Household_agent->specific_skill = atof(buffer); }
					if(in_employee_firm_id) { current_Household_agent->employee_firm_id = atoi(buffer); }
					if(in_employer_region_id) { current_Household_agent->employer_region_id = atoi(buffer); }
					if(in_day_of_month_receive_benefit) { current_Household_agent->day_of_month_receive_benefit = atoi(buffer); }
					if(in_unemployment_benefit_pct) { current_Household_agent->unemployment_benefit_pct = atof(buffer); }
					if(in_transfer_payment) { current_Household_agent->transfer_payment = atof(buffer); }
					if(in_subsidy_payment) { current_Household_agent->subsidy_payment = atof(buffer); }
					if(in_total_income) { current_Household_agent->total_income = atof(buffer); }
					if(in_total_expenses) { current_Household_agent->total_expenses = atof(buffer); }
					if(in_total_assets) { current_Household_agent->total_assets = atof(buffer); }
					if(in_total_liabilities) { current_Household_agent->total_liabilities = atof(buffer); }
					if(in_gov_interest) { current_Household_agent->gov_interest = atof(buffer); }
					if(in_stock_sales) { current_Household_agent->stock_sales = atof(buffer); }
					if(in_stock_purchases) { current_Household_agent->stock_purchases = atof(buffer); }
					if(in_gov_bond_purchases) { current_Household_agent->gov_bond_purchases = atof(buffer); }
					if(in_monthly_consumption_expenditure) { current_Household_agent->monthly_consumption_expenditure = atof(buffer); }
					if(in_gov_bond_holdings) { current_Household_agent->gov_bond_holdings = atof(buffer); }
					if(in_nr_gov_bonds) { current_Household_agent->nr_gov_bonds = atoi(buffer); }
					if(in_nr_firm_shares) { current_Household_agent->nr_firm_shares = atoi(buffer); }
				 }else if(in_Mall_agent == 1)
				{
					if(in_id) { current_Mall_agent->id = atoi(buffer); }
					if(in_region_id) { current_Mall_agent->region_id = atoi(buffer); }
					if(in_gov_id) { current_Mall_agent->gov_id = atoi(buffer); }
					if(in_no_regions) { current_Mall_agent->no_regions = atoi(buffer); }
					if(in_partition_id) { current_Mall_agent->partition_id = atoi(buffer); }
					if(in_current_stock) { j = 0;
						rc = read_mall_stock_dynamic_array(buffer, index, &j, &current_Mall_agent->current_stock);
						if(rc != 0) { printf("Error: reading 'Mall' agent variable 'current_stock' of type 'mall_stock_array'\n"); exit(0); } }
					if(in_firm_revenues) { j = 0;
						rc = read_sales_in_mall_dynamic_array(buffer, index, &j, &current_Mall_agent->firm_revenues);
						if(rc != 0) { printf("Error: reading 'Mall' agent variable 'firm_revenues' of type 'sales_in_mall_array'\n"); exit(0); } }
					if(in_total_supply) { current_Mall_agent->total_supply = atof(buffer); }
					if(in_export_volume_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Mall_agent->export_volume_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Mall' agent variable 'export_volume_matrix' of type 'double'\n"); exit(0); } }
					if(in_export_value_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Mall_agent->export_value_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Mall' agent variable 'export_value_matrix' of type 'double'\n"); exit(0); } }
					if(in_export_previous_value_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Mall_agent->export_previous_value_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Mall' agent variable 'export_previous_value_matrix' of type 'double'\n"); exit(0); } }
				 }else if(in_IGFirm_agent == 1)
				{
					if(in_id) { current_IGFirm_agent->id = atoi(buffer); }
					if(in_region_id) { current_IGFirm_agent->region_id = atoi(buffer); }
					if(in_gov_id) { current_IGFirm_agent->gov_id = atoi(buffer); }
					if(in_bank_id) { current_IGFirm_agent->bank_id = atoi(buffer); }
					if(in_day_of_month_to_act) { current_IGFirm_agent->day_of_month_to_act = atoi(buffer); }
					if(in_payment_account) { current_IGFirm_agent->payment_account = atof(buffer); }
					if(in_partition_id) { current_IGFirm_agent->partition_id = atoi(buffer); }
					if(in_productivity) { current_IGFirm_agent->productivity = atof(buffer); }
					if(in_capital_good_price) { current_IGFirm_agent->capital_good_price = atof(buffer); }
					if(in_revenue_per_day) { current_IGFirm_agent->revenue_per_day = atof(buffer); }
					if(in_tax_rate_corporate) { current_IGFirm_agent->tax_rate_corporate = atof(buffer); }
					if(in_tax_rate_vat) { current_IGFirm_agent->tax_rate_vat = atof(buffer); }
					if(in_tax_payment) { current_IGFirm_agent->tax_payment = atof(buffer); }
					if(in_net_profit) { current_IGFirm_agent->net_profit = atof(buffer); }
					if(in_outstanding_shares) { current_IGFirm_agent->outstanding_shares = atoi(buffer); }
					if(in_current_dividend_per_share) { current_IGFirm_agent->current_dividend_per_share = atof(buffer); }
					if(in_earnings) { current_IGFirm_agent->earnings = atof(buffer); }
					if(in_energy_price_markup) { current_IGFirm_agent->energy_price_markup = atof(buffer); }
					if(in_energy_costs_per_day) { current_IGFirm_agent->energy_costs_per_day = atof(buffer); }
					if(in_earnings_per_day) { current_IGFirm_agent->earnings_per_day = atof(buffer); }
					if(in_cum_energy_costs) { current_IGFirm_agent->cum_energy_costs = atof(buffer); }
					if(in_age) { current_IGFirm_agent->age = atoi(buffer); }
					if(in_transfer_payment) { current_IGFirm_agent->transfer_payment = atof(buffer); }
					if(in_subsidy_payment) { current_IGFirm_agent->subsidy_payment = atof(buffer); }
				 }else if(in_Eurostat_agent == 1)
				{
					if(in_id) { current_Eurostat_agent->id = atoi(buffer); }
					if(in_region_id) { current_Eurostat_agent->region_id = atoi(buffer); }
					if(in_no_regions) { current_Eurostat_agent->no_regions = atoi(buffer); }
					if(in_partition_id) { current_Eurostat_agent->partition_id = atoi(buffer); }
					if(in_switch_datastorage) { current_Eurostat_agent->switch_datastorage = atoi(buffer); }
					if(in_num_households) { current_Eurostat_agent->num_households = atoi(buffer); }
					if(in_no_households_skill_1) { current_Eurostat_agent->no_households_skill_1 = atoi(buffer); }
					if(in_no_households_skill_2) { current_Eurostat_agent->no_households_skill_2 = atoi(buffer); }
					if(in_no_households_skill_3) { current_Eurostat_agent->no_households_skill_3 = atoi(buffer); }
					if(in_no_households_skill_4) { current_Eurostat_agent->no_households_skill_4 = atoi(buffer); }
					if(in_no_households_skill_5) { current_Eurostat_agent->no_households_skill_5 = atoi(buffer); }
					if(in_employed) { current_Eurostat_agent->employed = atoi(buffer); }
					if(in_employed_skill_1) { current_Eurostat_agent->employed_skill_1 = atoi(buffer); }
					if(in_employed_skill_2) { current_Eurostat_agent->employed_skill_2 = atoi(buffer); }
					if(in_employed_skill_3) { current_Eurostat_agent->employed_skill_3 = atoi(buffer); }
					if(in_employed_skill_4) { current_Eurostat_agent->employed_skill_4 = atoi(buffer); }
					if(in_employed_skill_5) { current_Eurostat_agent->employed_skill_5 = atoi(buffer); }
					if(in_unemployed) { current_Eurostat_agent->unemployed = atoi(buffer); }
					if(in_unemployment_rate) { current_Eurostat_agent->unemployment_rate = atof(buffer); }
					if(in_unemployment_rate_skill_1) { current_Eurostat_agent->unemployment_rate_skill_1 = atof(buffer); }
					if(in_unemployment_rate_skill_2) { current_Eurostat_agent->unemployment_rate_skill_2 = atof(buffer); }
					if(in_unemployment_rate_skill_3) { current_Eurostat_agent->unemployment_rate_skill_3 = atof(buffer); }
					if(in_unemployment_rate_skill_4) { current_Eurostat_agent->unemployment_rate_skill_4 = atof(buffer); }
					if(in_unemployment_rate_skill_5) { current_Eurostat_agent->unemployment_rate_skill_5 = atof(buffer); }
					if(in_average_wage) { current_Eurostat_agent->average_wage = atof(buffer); }
					if(in_average_wage_skill_1) { current_Eurostat_agent->average_wage_skill_1 = atof(buffer); }
					if(in_average_wage_skill_2) { current_Eurostat_agent->average_wage_skill_2 = atof(buffer); }
					if(in_average_wage_skill_3) { current_Eurostat_agent->average_wage_skill_3 = atof(buffer); }
					if(in_average_wage_skill_4) { current_Eurostat_agent->average_wage_skill_4 = atof(buffer); }
					if(in_average_wage_skill_5) { current_Eurostat_agent->average_wage_skill_5 = atof(buffer); }
					if(in_average_s_skill) { current_Eurostat_agent->average_s_skill = atof(buffer); }
					if(in_average_s_skill_1) { current_Eurostat_agent->average_s_skill_1 = atof(buffer); }
					if(in_average_s_skill_2) { current_Eurostat_agent->average_s_skill_2 = atof(buffer); }
					if(in_average_s_skill_3) { current_Eurostat_agent->average_s_skill_3 = atof(buffer); }
					if(in_average_s_skill_4) { current_Eurostat_agent->average_s_skill_4 = atof(buffer); }
					if(in_average_s_skill_5) { current_Eurostat_agent->average_s_skill_5 = atof(buffer); }
					if(in_no_firms) { current_Eurostat_agent->no_firms = atoi(buffer); }
					if(in_no_vacancies) { current_Eurostat_agent->no_vacancies = atoi(buffer); }
					if(in_no_employees) { current_Eurostat_agent->no_employees = atoi(buffer); }
					if(in_no_employees_skill_1) { current_Eurostat_agent->no_employees_skill_1 = atoi(buffer); }
					if(in_no_employees_skill_2) { current_Eurostat_agent->no_employees_skill_2 = atoi(buffer); }
					if(in_no_employees_skill_3) { current_Eurostat_agent->no_employees_skill_3 = atoi(buffer); }
					if(in_no_employees_skill_4) { current_Eurostat_agent->no_employees_skill_4 = atoi(buffer); }
					if(in_no_employees_skill_5) { current_Eurostat_agent->no_employees_skill_5 = atoi(buffer); }
					if(in_firm_average_wage) { current_Eurostat_agent->firm_average_wage = atof(buffer); }
					if(in_firm_average_wage_skill_1) { current_Eurostat_agent->firm_average_wage_skill_1 = atof(buffer); }
					if(in_firm_average_wage_skill_2) { current_Eurostat_agent->firm_average_wage_skill_2 = atof(buffer); }
					if(in_firm_average_wage_skill_3) { current_Eurostat_agent->firm_average_wage_skill_3 = atof(buffer); }
					if(in_firm_average_wage_skill_4) { current_Eurostat_agent->firm_average_wage_skill_4 = atof(buffer); }
					if(in_firm_average_wage_skill_5) { current_Eurostat_agent->firm_average_wage_skill_5 = atof(buffer); }
					if(in_firm_average_s_skill) { current_Eurostat_agent->firm_average_s_skill = atof(buffer); }
					if(in_firm_average_s_skill_1) { current_Eurostat_agent->firm_average_s_skill_1 = atof(buffer); }
					if(in_firm_average_s_skill_2) { current_Eurostat_agent->firm_average_s_skill_2 = atof(buffer); }
					if(in_firm_average_s_skill_3) { current_Eurostat_agent->firm_average_s_skill_3 = atof(buffer); }
					if(in_firm_average_s_skill_4) { current_Eurostat_agent->firm_average_s_skill_4 = atof(buffer); }
					if(in_firm_average_s_skill_5) { current_Eurostat_agent->firm_average_s_skill_5 = atof(buffer); }
					if(in_region_firm_data) { j = 0;
						rc = read_firm_data_dynamic_array(buffer, index, &j, &current_Eurostat_agent->region_firm_data);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_firm_data' of type 'firm_data_array'\n"); exit(0); } }
					if(in_region_household_data) { j = 0;
						rc = read_household_data_dynamic_array(buffer, index, &j, &current_Eurostat_agent->region_household_data);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_household_data' of type 'household_data_array'\n"); exit(0); } }
					if(in_government_tax_rates) { j = 0;
						rc = read_tax_rates_item_static_array(buffer, index, &j, current_Eurostat_agent->government_tax_rates, 27);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'government_tax_rates' of type 'tax_rates_item'\n"); exit(0); } }
					if(in_total_earnings) { current_Eurostat_agent->total_earnings = atof(buffer); }
					if(in_total_debt) { current_Eurostat_agent->total_debt = atof(buffer); }
					if(in_total_assets) { current_Eurostat_agent->total_assets = atof(buffer); }
					if(in_total_equity) { current_Eurostat_agent->total_equity = atof(buffer); }
					if(in_average_debt_earnings_ratio) { current_Eurostat_agent->average_debt_earnings_ratio = atof(buffer); }
					if(in_average_debt_equity_ratio) { current_Eurostat_agent->average_debt_equity_ratio = atof(buffer); }
					if(in_labour_share_ratio) { current_Eurostat_agent->labour_share_ratio = atof(buffer); }
					if(in_cpi) { current_Eurostat_agent->cpi = atof(buffer); }
					if(in_gdp) { current_Eurostat_agent->gdp = atof(buffer); }
					if(in_monthly_sold_quantity) { current_Eurostat_agent->monthly_sold_quantity = atof(buffer); }
					if(in_monthly_output) { current_Eurostat_agent->monthly_output = atof(buffer); }
					if(in_monthly_revenue) { current_Eurostat_agent->monthly_revenue = atof(buffer); }
					if(in_monthly_planned_output) { current_Eurostat_agent->monthly_planned_output = atof(buffer); }
					if(in_price_index) { current_Eurostat_agent->price_index = atof(buffer); }
					if(in_history_monthly) { j = 0;
						rc = read_history_item_static_array(buffer, index, &j, current_Eurostat_agent->history_monthly, 13);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'history_monthly' of type 'history_item'\n"); exit(0); } }
					if(in_history_quarterly) { j = 0;
						rc = read_history_item_static_array(buffer, index, &j, current_Eurostat_agent->history_quarterly, 5);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'history_quarterly' of type 'history_item'\n"); exit(0); } }
					if(in_monthly_growth_rates) { j = 0;
						rc = read_history_item(buffer, index, &j, &current_Eurostat_agent->monthly_growth_rates);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'monthly_growth_rates' of type 'history_item'\n"); exit(0); } }
					if(in_quarterly_growth_rates) { j = 0;
						rc = read_history_item(buffer, index, &j, &current_Eurostat_agent->quarterly_growth_rates);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'quarterly_growth_rates' of type 'history_item'\n"); exit(0); } }
					if(in_annual_growth_rates_monthly) { j = 0;
						rc = read_history_item(buffer, index, &j, &current_Eurostat_agent->annual_growth_rates_monthly);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'annual_growth_rates_monthly' of type 'history_item'\n"); exit(0); } }
					if(in_annual_growth_rates_quarterly) { j = 0;
						rc = read_history_item(buffer, index, &j, &current_Eurostat_agent->annual_growth_rates_quarterly);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'annual_growth_rates_quarterly' of type 'history_item'\n"); exit(0); } }
					if(in_no_firm_births) { current_Eurostat_agent->no_firm_births = atoi(buffer); }
					if(in_no_firm_deaths) { current_Eurostat_agent->no_firm_deaths = atoi(buffer); }
					if(in_firm_age_distribution) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_Eurostat_agent->firm_age_distribution, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'firm_age_distribution' of type 'int'\n"); exit(0); } }
					if(in_firm_age_distribution_multiperiod) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_Eurostat_agent->firm_age_distribution_multiperiod, 720);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'firm_age_distribution_multiperiod' of type 'int'\n"); exit(0); } }
					if(in_firm_age_distribution_1_period_lag) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_Eurostat_agent->firm_age_distribution_1_period_lag, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'firm_age_distribution_1_period_lag' of type 'int'\n"); exit(0); } }
					if(in_firm_age_distribution_2_period_lag) { j = 0;
						rc = read_int_static_array(buffer, index, &j, current_Eurostat_agent->firm_age_distribution_2_period_lag, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'firm_age_distribution_2_period_lag' of type 'int'\n"); exit(0); } }
					if(in_firm_birth_rate) { current_Eurostat_agent->firm_birth_rate = atof(buffer); }
					if(in_firm_death_rate) { current_Eurostat_agent->firm_death_rate = atof(buffer); }
					if(in_survival_rate) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->survival_rate, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'survival_rate' of type 'double'\n"); exit(0); } }
					if(in_survival_rate_multiperiod_1) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->survival_rate_multiperiod_1, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'survival_rate_multiperiod_1' of type 'double'\n"); exit(0); } }
					if(in_survival_rate_multiperiod_2) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->survival_rate_multiperiod_2, 60);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'survival_rate_multiperiod_2' of type 'double'\n"); exit(0); } }
					if(in_survival_rate_multiperiod) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->survival_rate_multiperiod, 720);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'survival_rate_multiperiod' of type 'double'\n"); exit(0); } }
					if(in_max_firm_creation) { current_Eurostat_agent->max_firm_creation = atoi(buffer); }
					if(in_recession_started) { current_Eurostat_agent->recession_started = atoi(buffer); }
					if(in_recession_duration) { current_Eurostat_agent->recession_duration = atoi(buffer); }
					if(in_export_volume_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->export_volume_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'export_volume_matrix' of type 'double'\n"); exit(0); } }
					if(in_export_value_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->export_value_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'export_value_matrix' of type 'double'\n"); exit(0); } }
					if(in_export_previous_value_matrix) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->export_previous_value_matrix, 900);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'export_previous_value_matrix' of type 'double'\n"); exit(0); } }
					if(in_region_export_volume) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->region_export_volume, 30);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_export_volume' of type 'double'\n"); exit(0); } }
					if(in_region_import_volume) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->region_import_volume, 30);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_import_volume' of type 'double'\n"); exit(0); } }
					if(in_region_export_value) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->region_export_value, 30);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_export_value' of type 'double'\n"); exit(0); } }
					if(in_region_import_value) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->region_import_value, 30);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_import_value' of type 'double'\n"); exit(0); } }
					if(in_region_import_previous_value) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Eurostat_agent->region_import_previous_value, 30);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'region_import_previous_value' of type 'double'\n"); exit(0); } }
					if(in_firm_balance_sheets) { j = 0;
						rc = read_firm_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->firm_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'firm_balance_sheets' of type 'firm_balance_sheet_adt'\n"); exit(0); } }
					if(in_household_balance_sheets) { j = 0;
						rc = read_household_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->household_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'household_balance_sheets' of type 'household_balance_sheet_adt'\n"); exit(0); } }
					if(in_igfirm_balance_sheets) { j = 0;
						rc = read_igfirm_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->igfirm_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'igfirm_balance_sheets' of type 'igfirm_balance_sheet_adt'\n"); exit(0); } }
					if(in_gov_balance_sheets) { j = 0;
						rc = read_gov_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->gov_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'gov_balance_sheets' of type 'gov_balance_sheet_adt'\n"); exit(0); } }
					if(in_bank_balance_sheets) { j = 0;
						rc = read_bank_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->bank_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'bank_balance_sheets' of type 'bank_balance_sheet_adt'\n"); exit(0); } }
					if(in_ecb_balance_sheets) { j = 0;
						rc = read_ecb_balance_sheet_adt(buffer, index, &j, &current_Eurostat_agent->ecb_balance_sheets);
						if(rc != 0) { printf("Error: reading 'Eurostat' agent variable 'ecb_balance_sheets' of type 'ecb_balance_sheet_adt'\n"); exit(0); } }
					if(in_firm_average_productivity_progress) { current_Eurostat_agent->firm_average_productivity_progress = atof(buffer); }
					if(in_firm_average_productivity) { current_Eurostat_agent->firm_average_productivity = atof(buffer); }
				 }else if(in_Bank_agent == 1)
				{
					if(in_id) { current_Bank_agent->id = atoi(buffer); }
					if(in_region_id) { current_Bank_agent->region_id = atoi(buffer); }
					if(in_gov_id) { current_Bank_agent->gov_id = atoi(buffer); }
					if(in_partition_id) { current_Bank_agent->partition_id = atoi(buffer); }
					if(in_cash) { current_Bank_agent->cash = atof(buffer); }
					if(in_total_credit) { current_Bank_agent->total_credit = atof(buffer); }
					if(in_equity) { current_Bank_agent->equity = atof(buffer); }
					if(in_ecb_debt) { current_Bank_agent->ecb_debt = atof(buffer); }
					if(in_alfa) { current_Bank_agent->alfa = atof(buffer); }
					if(in_value_at_risk) { current_Bank_agent->value_at_risk = atof(buffer); }
					if(in_bank_gamma) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Bank_agent->bank_gamma, 2);
						if(rc != 0) { printf("Error: reading 'Bank' agent variable 'bank_gamma' of type 'double'\n"); exit(0); } }
					if(in_profits) { j = 0;
						rc = read_double_static_array(buffer, index, &j, current_Bank_agent->profits, 2);
						if(rc != 0) { printf("Error: reading 'Bank' agent variable 'profits' of type 'double'\n"); exit(0); } }
					if(in_bank_lambda) { current_Bank_agent->bank_lambda = atof(buffer); }
					if(in_ecb_interest_rate) { current_Bank_agent->ecb_interest_rate = atof(buffer); }
					if(in_bank_dividend_rate) { current_Bank_agent->bank_dividend_rate = atof(buffer); }
					if(in_tax_rate_corporate) { current_Bank_agent->tax_rate_corporate = atof(buffer); }
					if(in_current_shares_outstanding) { current_Bank_agent->current_shares_outstanding = atoi(buffer); }
					if(in_debt_period) { current_Bank_agent->debt_period = atof(buffer); }
					if(in_loan_request_message_found) { current_Bank_agent->loan_request_message_found = atoi(buffer); }
					if(in_day_of_month_to_act) { current_Bank_agent->day_of_month_to_act = atoi(buffer); }
					if(in_deposits) { current_Bank_agent->deposits = atof(buffer); }
					if(in_firm_loan_installments) { current_Bank_agent->firm_loan_installments = atof(buffer); }
					if(in_firm_interest_payments) { current_Bank_agent->firm_interest_payments = atof(buffer); }
					if(in_firm_loan_issues) { current_Bank_agent->firm_loan_issues = atof(buffer); }
					if(in_ecb_interest_payment) { current_Bank_agent->ecb_interest_payment = atof(buffer); }
					if(in_dividend_payment) { current_Bank_agent->dividend_payment = atof(buffer); }
					if(in_taxes) { current_Bank_agent->taxes = atof(buffer); }
					if(in_total_income) { current_Bank_agent->total_income = atof(buffer); }
					if(in_total_expenses) { current_Bank_agent->total_expenses = atof(buffer); }
					if(in_total_assets) { current_Bank_agent->total_assets = atof(buffer); }
					if(in_total_liabilities) { current_Bank_agent->total_liabilities = atof(buffer); }
				 }else if(in_Government_agent == 1)
				{
					if(in_id) { current_Government_agent->id = atoi(buffer); }
					if(in_list_of_regions) { j = 0;
						rc = read_int_dynamic_array(buffer, index, &j, &current_Government_agent->list_of_regions);
						if(rc != 0) { printf("Error: reading 'Government' agent variable 'list_of_regions' of type 'int_array'\n"); exit(0); } }
					if(in_payment_account) { current_Government_agent->payment_account = atof(buffer); }
					if(in_day_of_month_to_act) { current_Government_agent->day_of_month_to_act = atoi(buffer); }
					if(in_partition_id) { current_Government_agent->partition_id = atoi(buffer); }
					if(in_region_id) { current_Government_agent->region_id = atoi(buffer); }
					if(in_unemployment_benefit_pct) { current_Government_agent->unemployment_benefit_pct = atof(buffer); }
					if(in_money_financing_fraction) { current_Government_agent->money_financing_fraction = atof(buffer); }
					if(in_gdp_fraction_consumption) { current_Government_agent->gdp_fraction_consumption = atof(buffer); }
					if(in_gdp_fraction_investment) { current_Government_agent->gdp_fraction_investment = atof(buffer); }
					if(in_tax_rate_corporate) { current_Government_agent->tax_rate_corporate = atof(buffer); }
					if(in_tax_rate_hh_labour) { current_Government_agent->tax_rate_hh_labour = atof(buffer); }
					if(in_tax_rate_hh_capital) { current_Government_agent->tax_rate_hh_capital = atof(buffer); }
					if(in_tax_rate_vat) { current_Government_agent->tax_rate_vat = atof(buffer); }
					if(in_monthly_tax_revenues) { current_Government_agent->monthly_tax_revenues = atof(buffer); }
					if(in_yearly_tax_revenues) { current_Government_agent->yearly_tax_revenues = atof(buffer); }
					if(in_monthly_benefit_payment) { current_Government_agent->monthly_benefit_payment = atof(buffer); }
					if(in_yearly_benefit_payment) { current_Government_agent->yearly_benefit_payment = atof(buffer); }
					if(in_hh_transfer_payment) { current_Government_agent->hh_transfer_payment = atof(buffer); }
					if(in_firm_transfer_payment) { current_Government_agent->firm_transfer_payment = atof(buffer); }
					if(in_monthly_transfer_payment) { current_Government_agent->monthly_transfer_payment = atof(buffer); }
					if(in_yearly_transfer_payment) { current_Government_agent->yearly_transfer_payment = atof(buffer); }
					if(in_hh_subsidy_payment) { current_Government_agent->hh_subsidy_payment = atof(buffer); }
					if(in_firm_subsidy_payment) { current_Government_agent->firm_subsidy_payment = atof(buffer); }
					if(in_monthly_subsidy_payment) { current_Government_agent->monthly_subsidy_payment = atof(buffer); }
					if(in_yearly_subsidy_payment) { current_Government_agent->yearly_subsidy_payment = atof(buffer); }
					if(in_monthly_bond_interest_payment) { current_Government_agent->monthly_bond_interest_payment = atof(buffer); }
					if(in_yearly_bond_interest_payment) { current_Government_agent->yearly_bond_interest_payment = atof(buffer); }
					if(in_gov_interest_rate) { current_Government_agent->gov_interest_rate = atof(buffer); }
					if(in_yearly_investment_expenditure) { current_Government_agent->yearly_investment_expenditure = atof(buffer); }
					if(in_yearly_consumption_expenditure) { current_Government_agent->yearly_consumption_expenditure = atof(buffer); }
					if(in_yearly_income) { current_Government_agent->yearly_income = atof(buffer); }
					if(in_yearly_expenditure) { current_Government_agent->yearly_expenditure = atof(buffer); }
					if(in_total_debt) { current_Government_agent->total_debt = atof(buffer); }
					if(in_yearly_budget_balance) { current_Government_agent->yearly_budget_balance = atof(buffer); }
					if(in_total_money_financing) { current_Government_agent->total_money_financing = atof(buffer); }
					if(in_total_bond_financing) { current_Government_agent->total_bond_financing = atof(buffer); }
					if(in_country_wide_mean_wage) { current_Government_agent->country_wide_mean_wage = atof(buffer); }
					if(in_num_unemployed) { current_Government_agent->num_unemployed = atoi(buffer); }
					if(in_gdp) { current_Government_agent->gdp = atof(buffer); }
					if(in_gdp_growth) { current_Government_agent->gdp_growth = atof(buffer); }
					if(in_gdp_forecast) { current_Government_agent->gdp_forecast = atof(buffer); }
					if(in_yearly_income_forecast) { current_Government_agent->yearly_income_forecast = atof(buffer); }
					if(in_yearly_expenditure_budget) { current_Government_agent->yearly_expenditure_budget = atof(buffer); }
					if(in_budget_balance_forecast) { current_Government_agent->budget_balance_forecast = atof(buffer); }
					if(in_monthly_consumption_expenditure) { current_Government_agent->monthly_consumption_expenditure = atof(buffer); }
					if(in_monthly_investment_expenditure) { current_Government_agent->monthly_investment_expenditure = atof(buffer); }
					if(in_monthly_budget_balance) { current_Government_agent->monthly_budget_balance = atof(buffer); }
					if(in_monthly_consumption_budget) { current_Government_agent->monthly_consumption_budget = atof(buffer); }
					if(in_monthly_investment_budget) { current_Government_agent->monthly_investment_budget = atof(buffer); }
					if(in_monthly_income) { current_Government_agent->monthly_income = atof(buffer); }
					if(in_monthly_expenditure) { current_Government_agent->monthly_expenditure = atof(buffer); }
					if(in_yearly_consumption_budget) { current_Government_agent->yearly_consumption_budget = atof(buffer); }
					if(in_yearly_investment_budget) { current_Government_agent->yearly_investment_budget = atof(buffer); }
					if(in_total_assets) { current_Government_agent->total_assets = atof(buffer); }
					if(in_total_liabilities) { current_Government_agent->total_liabilities = atof(buffer); }
					if(in_value_bonds_outstanding) { current_Government_agent->value_bonds_outstanding = atof(buffer); }
					if(in_nr_bonds_outstanding) { current_Government_agent->nr_bonds_outstanding = atoi(buffer); }
				 }else if(in_Central_Bank_agent == 1)
				{
					if(in_id) { current_Central_Bank_agent->id = atoi(buffer); }
					if(in_partition_id) { current_Central_Bank_agent->partition_id = atoi(buffer); }
					if(in_accounts) { j = 0;
						rc = read_account_item_dynamic_array(buffer, index, &j, &current_Central_Bank_agent->accounts);
						if(rc != 0) { printf("Error: reading 'Central_Bank' agent variable 'accounts' of type 'account_item_array'\n"); exit(0); } }
					if(in_ecb_interest_rate) { current_Central_Bank_agent->ecb_interest_rate = atof(buffer); }
					if(in_equity) { current_Central_Bank_agent->equity = atof(buffer); }
					if(in_dividend_payment) { current_Central_Bank_agent->dividend_payment = atof(buffer); }
					if(in_total_ecb_debt) { current_Central_Bank_agent->total_ecb_debt = atof(buffer); }
					if(in_gov_bond_holdings) { current_Central_Bank_agent->gov_bond_holdings = atof(buffer); }
					if(in_nr_gov_bonds) { current_Central_Bank_agent->nr_gov_bonds = atoi(buffer); }
					if(in_payment_account_private_sector) { current_Central_Bank_agent->payment_account_private_sector = atof(buffer); }
					if(in_payment_account_public_sector) { current_Central_Bank_agent->payment_account_public_sector = atof(buffer); }
					if(in_fiat_money) { current_Central_Bank_agent->fiat_money = atof(buffer); }
					if(in_bank_interest) { current_Central_Bank_agent->bank_interest = atof(buffer); }
					if(in_gov_interest) { current_Central_Bank_agent->gov_interest = atof(buffer); }
					if(in_gov_bond_purchase) { current_Central_Bank_agent->gov_bond_purchase = atof(buffer); }
					if(in_total_income) { current_Central_Bank_agent->total_income = atof(buffer); }
					if(in_total_expenses) { current_Central_Bank_agent->total_expenses = atof(buffer); }
					if(in_total_assets) { current_Central_Bank_agent->total_assets = atof(buffer); }
					if(in_total_liabilities) { current_Central_Bank_agent->total_liabilities = atof(buffer); }
				 }else if(in_Clearinghouse_agent == 1)
				{
					if(in_id) { current_Clearinghouse_agent->id = atoi(buffer); }
					if(in_region_id) { current_Clearinghouse_agent->region_id = atoi(buffer); }
					if(in_partition_id) { current_Clearinghouse_agent->partition_id = atoi(buffer); }
					if(in_assets) { j = 0;
						rc = read_Asset_dynamic_array(buffer, index, &j, &current_Clearinghouse_agent->assets);
						if(rc != 0) { printf("Error: reading 'Clearinghouse' agent variable 'assets' of type 'Asset_array'\n"); exit(0); } }
					if(in_clearingmechanism) { j = 0;
						rc = read_ClearingMechanism(buffer, index, &j, &current_Clearinghouse_agent->clearingmechanism);
						if(rc != 0) { printf("Error: reading 'Clearinghouse' agent variable 'clearingmechanism' of type 'ClearingMechanism'\n"); exit(0); } }
				 }
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 99999) index++;
			else
			{
				printf("Error: agent reading buffer too small\n");
				printf("%s\n", buffer);
				exit(0);
			}
		}
	}
	/* Close file */
	fclose(file);

	return 0;
}

/** \fn void check_location_exists(char * location)
 * \brief Check that a directory exists.
 * \param location The directory location to check.
 */
int check_location_exists(char * location)
{
	/* Save a dummy file to directory and remove.
	 * This checks directory exists and is writable */
	FILE * file;
	char * buffer;

	buffer = (char *)malloc( (strlen(location) + strlen("dummy.temp") + 1) * sizeof(char));
	strcpy(buffer, location);
	strcat(buffer, "dummy.temp");

	if((file = fopen(buffer, "w")) == NULL) return 0;

	fclose(file);
	/* Remove dummy file */
	remove(buffer);

	return 1;
}

/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param filelocation The directory of the location
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[6],
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = '\0';
	char buffer[100000];
	char FLAME_location[1000];
	char FLAME_format[1000];
	char FLAME_type[1000];
	FLAME_output * current_FLAME_output;

	/* Things for round-robin partitioning */
	int agent_count;
	int number_partitions;
	int geometric=1;
	int other=2;
	

	/* Cloud data array initialisation */
	cloud_data[0] = SPINF; cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF; cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF; cloud_data[5] = -SPINF;

	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading = 1;
	int i = 0;
	int rc;
	int in_tag = 0;
	int in_itno = 0;
	int FLAME_in_imports = 0;
	int FLAME_in_import = 0;
	int FLAME_in_outputs = 0;
	int FLAME_in_output = 0;
	int FLAME_in_location = 0;
	int FLAME_in_format = 0;
	int FLAME_in_type = 0;
	int FLAME_in_time = 0;
	int FLAME_in_period = 0;
	int FLAME_in_phase = 0;
	int FLAME_in_name = 0;

	/* Initialise environment vars */
	FLAME_environment_variable_print_log = 0;
	FLAME_environment_variable_print_debug = 0;
	FLAME_environment_variable_number_of_banks_to_apply = 0;
	FLAME_environment_variable_gamma_const = 0.0;
	FLAME_environment_variable_alpha = 0.0;
	FLAME_environment_variable_beta = 0.0;
	FLAME_environment_variable_depreciation_rate = 0.0;
	FLAME_environment_variable_discount_rate = 0.0;
	FLAME_environment_variable_teta = 0.0;
	FLAME_environment_variable_mark_up = 0.0;
	FLAME_environment_variable_lambda = 0.0;
	FLAME_environment_variable_wage_update = 0.0;
	FLAME_environment_variable_min_vacancy = 0;
	FLAME_environment_variable_wage_reservation_update = 0.0;
	FLAME_environment_variable_region_cost = 0.0;
	FLAME_environment_variable_inventory_costs_per_unit = 0.0;
	FLAME_environment_variable_on_the_job_search_rate = 0.0;
	FLAME_environment_variable_initial_consumption_propensity = 0.0;
	FLAME_environment_variable_consumption_propensity = 0.0;
	FLAME_environment_variable_firm_planning_horizon = 0;
	FLAME_environment_variable_inv_inertia = 0.0;
	FLAME_environment_variable_adaption_delivery_volume = 0.0;
	FLAME_environment_variable_delivery_prob_if_critical_stock_0 = 0.0;
	FLAME_environment_variable_innovation_probability = 0.0;
	FLAME_environment_variable_productivity_progress = 0.0;
	FLAME_environment_variable_lower_bound_firing = 0;
	FLAME_environment_variable_upper_bound_firing = 0;
	FLAME_environment_variable_const_bankruptcy_idle_period = 0;
	FLAME_environment_variable_const_installment_periods = 0;
	FLAME_environment_variable_const_firm_leverage = 0.0;
	FLAME_environment_variable_const_number_of_banks = 0;
	FLAME_environment_variable_switch_stock_consistency_check = 0;
	FLAME_environment_variable_switch_flow_consistency_check = 0;
	FLAME_environment_variable_debt_rescaling_factor = 0.0;
	FLAME_environment_variable_target_leverage_ratio = 0.0;
	FLAME_environment_variable_target_liquidity_ratio = 0.0;
	FLAME_environment_variable_const_dividend_earnings_ratio = 0.0;
	FLAME_environment_variable_discrete_shock = 0;
	FLAME_environment_variable_energy_shock_start = 0;
	FLAME_environment_variable_energy_shock_end = 0;
	FLAME_environment_variable_const_energy_price_markup = 0.0;
	FLAME_environment_variable_energy_shock_frequency = 0;
	FLAME_environment_variable_gov_policy_unemployment_benefit_pct = 0.0;
	FLAME_environment_variable_gov_policy_money_financing_fraction = 0.0;
	FLAME_environment_variable_gov_policy_gdp_fraction_consumption = 0.0;
	FLAME_environment_variable_gov_policy_gdp_fraction_investment = 0.0;
	FLAME_environment_variable_no_regions_per_gov = 0;
	

	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("Error: opening initial states '%s'\n", filename);
		exit(0);
	}
	
	/* Initialise variables */
    *itno = 0;





	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;

	printf("Reading initial data file: %s\n", filename);
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
			if(strcmp(buffer, "imports") == 0) FLAME_in_imports = 1;
			if(strcmp(buffer, "/imports") == 0) FLAME_in_imports = 0;
			if(strcmp(buffer, "import") == 0)
			{
				/*FLAME_location[0] = '\0';*/
				strcpy(FLAME_location, filelocation);
				FLAME_format[0] = '\0';
				FLAME_type[0] = '\0';

				FLAME_in_import = 1;
			}
			if(strcmp(buffer, "/import") == 0)
			{
				if(strcmp("agent", FLAME_type) == 0 || strcmp("environment", FLAME_type) == 0)
				{
					if(strcmp("xml", FLAME_format) == 0)
					{
						if(strcmp("agent", FLAME_type) == 0) readAgentXML(FLAME_location, cloud_data, partition_method, flag, number_partitions, agent_count);
						if(strcmp("environment", FLAME_type) == 0) readEnvironmentXML(FLAME_location);
					}
					else
					{
						printf("Error: import format '%s' is unsupported\n", FLAME_format);
						exit(0);
					}
				}
				else
				{
					printf("Error: import type '%s' is not agent or environment\n", FLAME_type);
					exit(0);
				}

				FLAME_in_import = 0;
			}
			if(strcmp(buffer, "location") == 0) FLAME_in_location = 1;
			if(strcmp(buffer, "/location") == 0) FLAME_in_location = 0;
			if(strcmp(buffer, "format") == 0) FLAME_in_format = 1;
			if(strcmp(buffer, "/format") == 0) FLAME_in_format = 0;
			if(strcmp(buffer, "type") == 0) FLAME_in_type = 1;
			if(strcmp(buffer, "/type") == 0) FLAME_in_type = 0;
			if(strcmp(buffer, "outputs") == 0) FLAME_in_outputs = 1;
			if(strcmp(buffer, "/outputs") == 0) FLAME_in_outputs = 0;
			if(strcmp(buffer, "output") == 0)
			{
				if(FLAME_in_outputs)
				{
					current_FLAME_output = add_FLAME_output(&FLAME_outputs);
	
					FLAME_in_output = 1;
				}
			}
			if(strcmp(buffer, "/output") == 0)
			{
				if(FLAME_in_outputs)
				{
					if(current_FLAME_output->type == -1)
					{
						printf("Error: an output type has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->format == -1)
					{
						printf("Error: an output format has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->location == NULL)
					{
						printf("Error: an output location has not been set\n");
						exit(0);
					}
					/* If type is xml check if location exists */
					if(current_FLAME_output->type == 0)
					{
						rc = check_location_exists(current_FLAME_output->location);
						if(rc == 0)
						{
							printf("Error: location directory '%s' does not exist\n", current_FLAME_output->location);
							exit(0);
						}
					}
					/* Period has to be larger than 0 */
					if(current_FLAME_output->period < 1)
					{
						printf("Error: output period is less than 1: '%d'\n", current_FLAME_output->period);
						exit(0);
					}
					/* Phase cannot be equal or larger than period */
					if(current_FLAME_output->phase >= current_FLAME_output->period)
					{
						printf("Error: output phase is more or equal to period: '%d'\n", current_FLAME_output->phase);
						exit(0);
					}
	
					FLAME_in_output = 0;
				}
			}
			if(strcmp(buffer, "time") == 0) FLAME_in_time = 1;
			if(strcmp(buffer, "/time") == 0) FLAME_in_time = 0;
			if(strcmp(buffer, "period") == 0) FLAME_in_period = 1;
			if(strcmp(buffer, "/period") == 0) FLAME_in_period = 0;
			if(strcmp(buffer, "phase") == 0) FLAME_in_phase = 1;
			if(strcmp(buffer, "/phase") == 0) FLAME_in_phase = 0;
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;

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

			if(in_itno) *itno = atoi(buffer);
			if(FLAME_in_imports)
			{
				if(FLAME_in_import)
				{
					if(FLAME_in_location) strcat(FLAME_location, buffer);
					if(FLAME_in_format) strcpy(FLAME_format, buffer);
					if(FLAME_in_type) strcpy(FLAME_type, buffer);
				}
			}
			if(FLAME_in_outputs)
			{
				if(FLAME_in_output)
				{
					if(FLAME_in_type)
					{
						if(strcmp("snapshot", buffer) == 0) current_FLAME_output->type = 0;
						else if(strcmp("agent", buffer) != 0)
						{
							printf("Error: output type is not 'snapshot' or an 'agent': '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_name)
					{
						if(strcmp("Firm", buffer) == 0) current_FLAME_output->type = 1;
						else if(strcmp("Household", buffer) == 0) current_FLAME_output->type = 2;
						else if(strcmp("Mall", buffer) == 0) current_FLAME_output->type = 3;
						else if(strcmp("IGFirm", buffer) == 0) current_FLAME_output->type = 4;
						else if(strcmp("Eurostat", buffer) == 0) current_FLAME_output->type = 5;
						else if(strcmp("Bank", buffer) == 0) current_FLAME_output->type = 6;
						else if(strcmp("Government", buffer) == 0) current_FLAME_output->type = 7;
						else if(strcmp("Central_Bank", buffer) == 0) current_FLAME_output->type = 8;
						else if(strcmp("Clearinghouse", buffer) == 0) current_FLAME_output->type = 9;
						else 
						{
							printf("Error: output name is not an agent name: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_format)
					{
						if(strcmp("xml", buffer) == 0) current_FLAME_output->format = 0;
						else
						{
							printf("Error: output format is unsupported: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_location)
					{
						current_FLAME_output->location = (char *)malloc( (strlen(filelocation) + strlen(buffer) + 1) * sizeof(char));
						strcpy(current_FLAME_output->location, filelocation);
						strcat(current_FLAME_output->location, buffer);
					}
					if(FLAME_in_time)
					{
						if(FLAME_in_period) current_FLAME_output->period = atoi(buffer);
						if(FLAME_in_phase)  current_FLAME_output->phase = atoi(buffer);
					}
				}
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

	/* Close the file */
	fclose(file);

	/* Also try and read environment and agents from 0.xml */
	readEnvironmentXML(filename);
	readAgentXML(filename, cloud_data, partition_method, flag, number_partitions, agent_count);

	/* If outputs is empty add default snapshot for every iteration */
	if(FLAME_outputs == NULL)
	{
		current_FLAME_output = add_FLAME_output(&FLAME_outputs);
		current_FLAME_output->type   = 0; /* snapshot */
		current_FLAME_output->format = 0; /* xml */
		current_FLAME_output->location = (char *)malloc( (strlen(filelocation) +  1) * sizeof(char));
		strcpy(current_FLAME_output->location, filelocation); /* location = 0.xml location */
		current_FLAME_output->period = 1; /* every iteration */
		current_FLAME_output->phase  = 0; /* no phase */
	}
	
	/* Print output settings to CLI */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		printf("output: type='");
		if(current_FLAME_output->type == 0) printf("snapshot");
		else if(current_FLAME_output->type == 1) printf("agent' name='Firm");
		else if(current_FLAME_output->type == 2) printf("agent' name='Household");
		else if(current_FLAME_output->type == 3) printf("agent' name='Mall");
		else if(current_FLAME_output->type == 4) printf("agent' name='IGFirm");
		else if(current_FLAME_output->type == 5) printf("agent' name='Eurostat");
		else if(current_FLAME_output->type == 6) printf("agent' name='Bank");
		else if(current_FLAME_output->type == 7) printf("agent' name='Government");
		else if(current_FLAME_output->type == 8) printf("agent' name='Central_Bank");
		else if(current_FLAME_output->type == 9) printf("agent' name='Clearinghouse");
		else printf("undefined");
		printf("' format='");
		if(current_FLAME_output->format == 0) printf("xml");
		else printf("undefined");
		printf("' location='%s'", current_FLAME_output->location);
		printf(" period='%d' phase='%d'\n", current_FLAME_output->period, current_FLAME_output->phase);
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

/** \fn void write_data_type_sales(FILE *file, data_type_sales * temp_datatype)
 * \brief Writes data_type_sales datatype.
 */
void write_data_type_sales(FILE *file, data_type_sales * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).period);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).sales);
	fputs(data, file);
	fputs("}", file);
}

void write_data_type_sales_static_array(FILE *file, data_type_sales * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_data_type_sales(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_data_type_sales_dynamic_array(FILE *file, data_type_sales_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_data_type_sales(file, &(*temp_datatype).array[i]);

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
	fputs(", ", file);	write_data_type_sales_dynamic_array(file, &(*temp_datatype).sales);
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

/** \fn void write_temporary_sales_statistics(FILE *file, temporary_sales_statistics * temp_datatype)
 * \brief Writes temporary_sales_statistics datatype.
 */
void write_temporary_sales_statistics(FILE *file, temporary_sales_statistics * temp_datatype)
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

void write_temporary_sales_statistics_static_array(FILE *file, temporary_sales_statistics * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_temporary_sales_statistics(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_temporary_sales_statistics_dynamic_array(FILE *file, temporary_sales_statistics_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_temporary_sales_statistics(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_potential_lender(FILE *file, potential_lender * temp_datatype)
 * \brief Writes potential_lender datatype.
 */
void write_potential_lender(FILE *file, potential_lender * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).bank_name);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).contacted);
	fputs(data, file);
	fputs("}", file);
}

void write_potential_lender_static_array(FILE *file, potential_lender * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_potential_lender(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_potential_lender_dynamic_array(FILE *file, potential_lender_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_potential_lender(file, &(*temp_datatype).array[i]);

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
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).productivity_progress);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).productivity);
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

/** \fn void write_firm_stocks_adt(FILE *file, firm_stocks_adt * temp_datatype)
 * \brief Writes firm_stocks_adt datatype.
 */
void write_firm_stocks_adt(FILE *file, firm_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).payment_account);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_value_local_inventory);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_value_capital_stock);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).current_shares_outstanding);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_firm_stocks_adt_static_array(FILE *file, firm_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_firm_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_firm_stocks_adt_dynamic_array(FILE *file, firm_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_firm_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_firm_flows_adt(FILE *file, firm_flows_adt * temp_datatype)
 * \brief Writes firm_flows_adt datatype.
 */
void write_firm_flows_adt(FILE *file, firm_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).cum_revenue);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).labour_costs);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).capital_costs);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt_installment_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_dividend_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_firm_flows_adt_static_array(FILE *file, firm_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_firm_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_firm_flows_adt_dynamic_array(FILE *file, firm_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_firm_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_household_stocks_adt(FILE *file, household_stocks_adt * temp_datatype)
 * \brief Writes household_stocks_adt datatype.
 */
void write_household_stocks_adt(FILE *file, household_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).payment_account);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gov_bond_holdings);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_gov_bonds);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_firm_shares);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_household_stocks_adt_static_array(FILE *file, household_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_household_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_household_stocks_adt_dynamic_array(FILE *file, household_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_household_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_household_flows_adt(FILE *file, household_flows_adt * temp_datatype)
 * \brief Writes household_flows_adt datatype.
 */
void write_household_flows_adt(FILE *file, household_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).wage);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gov_interest);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).stock_sales);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).cum_total_dividends);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_consumption_expenditure);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).stock_purchases);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_household_flows_adt_static_array(FILE *file, household_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_household_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_household_flows_adt_dynamic_array(FILE *file, household_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_household_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_igfirm_stocks_adt(FILE *file, igfirm_stocks_adt * temp_datatype)
 * \brief Writes igfirm_stocks_adt datatype.
 */
void write_igfirm_stocks_adt(FILE *file, igfirm_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).payment_account);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).current_shares_outstanding);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_igfirm_stocks_adt_static_array(FILE *file, igfirm_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_igfirm_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_igfirm_stocks_adt_dynamic_array(FILE *file, igfirm_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_igfirm_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_igfirm_flows_adt(FILE *file, igfirm_flows_adt * temp_datatype)
 * \brief Writes igfirm_flows_adt datatype.
 */
void write_igfirm_flows_adt(FILE *file, igfirm_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).cum_revenue);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).labour_costs);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).energy_costs);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_debt_installment_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_dividend_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_igfirm_flows_adt_static_array(FILE *file, igfirm_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_igfirm_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_igfirm_flows_adt_dynamic_array(FILE *file, igfirm_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_igfirm_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_bank_stocks_adt(FILE *file, bank_stocks_adt * temp_datatype)
 * \brief Writes bank_stocks_adt datatype.
 */
void write_bank_stocks_adt(FILE *file, bank_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).cash);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_credit);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).deposits);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).ecb_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_bank_stocks_adt_static_array(FILE *file, bank_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_bank_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_bank_stocks_adt_dynamic_array(FILE *file, bank_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_bank_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_bank_flows_adt(FILE *file, bank_flows_adt * temp_datatype)
 * \brief Writes bank_flows_adt datatype.
 */
void write_bank_flows_adt(FILE *file, bank_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).firm_loan_installments);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).firm_interest_payments);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).firm_loan_issues);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).ecb_interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).dividend_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).tax_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_bank_flows_adt_static_array(FILE *file, bank_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_bank_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_bank_flows_adt_dynamic_array(FILE *file, bank_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_bank_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_gov_stocks_adt(FILE *file, gov_stocks_adt * temp_datatype)
 * \brief Writes gov_stocks_adt datatype.
 */
void write_gov_stocks_adt(FILE *file, gov_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).payment_account);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).value_bonds_outstanding);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_bonds_outstanding);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_gov_stocks_adt_static_array(FILE *file, gov_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_gov_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_gov_stocks_adt_dynamic_array(FILE *file, gov_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_gov_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_gov_flows_adt(FILE *file, gov_flows_adt * temp_datatype)
 * \brief Writes gov_flows_adt datatype.
 */
void write_gov_flows_adt(FILE *file, gov_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).monthly_tax_revenues);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_bond_financing);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_investment_expenditure);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_consumption_expenditure);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_benefit_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_subsidy_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_transfer_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).monthly_bond_interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_gov_flows_adt_static_array(FILE *file, gov_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_gov_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_gov_flows_adt_dynamic_array(FILE *file, gov_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_gov_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ecb_stocks_adt(FILE *file, ecb_stocks_adt * temp_datatype)
 * \brief Writes ecb_stocks_adt datatype.
 */
void write_ecb_stocks_adt(FILE *file, ecb_stocks_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).gov_bond_holdings);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_gov_bonds);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_ecb_debt);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).payment_account_private_sector);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).payment_account_public_sector);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).fiat_money);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_assets);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_liabilities);
	fputs(data, file);
	fputs("}", file);
}

void write_ecb_stocks_adt_static_array(FILE *file, ecb_stocks_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ecb_stocks_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ecb_stocks_adt_dynamic_array(FILE *file, ecb_stocks_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ecb_stocks_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ecb_flows_adt(FILE *file, ecb_flows_adt * temp_datatype)
 * \brief Writes ecb_flows_adt datatype.
 */
void write_ecb_flows_adt(FILE *file, ecb_flows_adt * temp_datatype)
{
	char data[1000];

	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).bank_interest);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gov_interest);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).gov_bond_purchase);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).dividend_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_income);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).total_expenses);
	fputs(data, file);
	fputs("}", file);
}

void write_ecb_flows_adt_static_array(FILE *file, ecb_flows_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ecb_flows_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ecb_flows_adt_dynamic_array(FILE *file, ecb_flows_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ecb_flows_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_firm_balance_sheet_adt(FILE *file, firm_balance_sheet_adt * temp_datatype)
 * \brief Writes firm_balance_sheet_adt datatype.
 */
void write_firm_balance_sheet_adt(FILE *file, firm_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_firm_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_firm_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_firm_balance_sheet_adt_static_array(FILE *file, firm_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_firm_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_firm_balance_sheet_adt_dynamic_array(FILE *file, firm_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_firm_balance_sheet_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_household_balance_sheet_adt(FILE *file, household_balance_sheet_adt * temp_datatype)
 * \brief Writes household_balance_sheet_adt datatype.
 */
void write_household_balance_sheet_adt(FILE *file, household_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_household_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_household_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_household_balance_sheet_adt_static_array(FILE *file, household_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_household_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_household_balance_sheet_adt_dynamic_array(FILE *file, household_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_household_balance_sheet_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_igfirm_balance_sheet_adt(FILE *file, igfirm_balance_sheet_adt * temp_datatype)
 * \brief Writes igfirm_balance_sheet_adt datatype.
 */
void write_igfirm_balance_sheet_adt(FILE *file, igfirm_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_igfirm_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_igfirm_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_igfirm_balance_sheet_adt_static_array(FILE *file, igfirm_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_igfirm_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_igfirm_balance_sheet_adt_dynamic_array(FILE *file, igfirm_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_igfirm_balance_sheet_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_bank_balance_sheet_adt(FILE *file, bank_balance_sheet_adt * temp_datatype)
 * \brief Writes bank_balance_sheet_adt datatype.
 */
void write_bank_balance_sheet_adt(FILE *file, bank_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_bank_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_bank_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_bank_balance_sheet_adt_static_array(FILE *file, bank_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_bank_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_bank_balance_sheet_adt_dynamic_array(FILE *file, bank_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_bank_balance_sheet_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_gov_balance_sheet_adt(FILE *file, gov_balance_sheet_adt * temp_datatype)
 * \brief Writes gov_balance_sheet_adt datatype.
 */
void write_gov_balance_sheet_adt(FILE *file, gov_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_gov_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_gov_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_gov_balance_sheet_adt_static_array(FILE *file, gov_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_gov_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_gov_balance_sheet_adt_dynamic_array(FILE *file, gov_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_gov_balance_sheet_adt(file, &(*temp_datatype).array[i]);

		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ecb_balance_sheet_adt(FILE *file, ecb_balance_sheet_adt * temp_datatype)
 * \brief Writes ecb_balance_sheet_adt datatype.
 */
void write_ecb_balance_sheet_adt(FILE *file, ecb_balance_sheet_adt * temp_datatype)
{
	

	fputs("{", file);
	write_ecb_stocks_adt(file, &(*temp_datatype).stocks);
	fputs(", ", file);	write_ecb_flows_adt(file, &(*temp_datatype).flows);
	fputs("}", file);
}

void write_ecb_balance_sheet_adt_static_array(FILE *file, ecb_balance_sheet_adt * temp_datatype, int size)
{
	int i;

	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ecb_balance_sheet_adt(file, &temp_datatype[i]);

		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ecb_balance_sheet_adt_dynamic_array(FILE *file, ecb_balance_sheet_adt_array * temp_datatype)
{
	int i;

	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ecb_balance_sheet_adt(file, &(*temp_datatype).array[i]);

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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<sold_quantity_in_calendar_month>", file);
	sprintf(data, "%f", current->sold_quantity_in_calendar_month);
	fputs(data, file);
	fputs("</sold_quantity_in_calendar_month>\n", file);
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
		fputs("<calc_capital_costs>", file);
	sprintf(data, "%f", current->calc_capital_costs);
	fputs(data, file);
	fputs("</calc_capital_costs>\n", file);
		fputs("<calc_production_costs>", file);
	sprintf(data, "%f", current->calc_production_costs);
	fputs(data, file);
	fputs("</calc_production_costs>\n", file);
		fputs("<firm_productivity>", file);
	sprintf(data, "%f", current->firm_productivity);
	fputs(data, file);
	fputs("</firm_productivity>\n", file);
		fputs("<firm_productivity_last_year>", file);
	sprintf(data, "%f", current->firm_productivity_last_year);
	fputs(data, file);
	fputs("</firm_productivity_last_year>\n", file);
		fputs("<firm_productivity_progress>", file);
	sprintf(data, "%f", current->firm_productivity_progress);
	fputs(data, file);
	fputs("</firm_productivity_progress>\n", file);
		fputs("<set_of_lenders>", file);
	write_potential_lender_dynamic_array(file, &current->set_of_lenders);
	fputs("</set_of_lenders>\n", file);
		fputs("<number_of_banks_asked>", file);
	sprintf(data, "%i", current->number_of_banks_asked);
	fputs(data, file);
	fputs("</number_of_banks_asked>\n", file);
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
		fputs("<previous_shares_outstanding>", file);
	sprintf(data, "%f", current->previous_shares_outstanding);
	fputs(data, file);
	fputs("</previous_shares_outstanding>\n", file);
		fputs("<total_income>", file);
	sprintf(data, "%f", current->total_income);
	fputs(data, file);
	fputs("</total_income>\n", file);
		fputs("<total_liabilities>", file);
	sprintf(data, "%f", current->total_liabilities);
	fputs(data, file);
	fputs("</total_liabilities>\n", file);
		fputs("<total_expenses>", file);
	sprintf(data, "%f", current->total_expenses);
	fputs(data, file);
	fputs("</total_expenses>\n", file);
		fputs("<current_shares_outstanding>", file);
	sprintf(data, "%i", current->current_shares_outstanding);
	fputs(data, file);
	fputs("</current_shares_outstanding>\n", file);
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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<tax_payment>", file);
	sprintf(data, "%f", current->tax_payment);
	fputs(data, file);
	fputs("</tax_payment>\n", file);
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
		fputs("<flag_consumption_shifting>", file);
	sprintf(data, "%i", current->flag_consumption_shifting);
	fputs(data, file);
	fputs("</flag_consumption_shifting>\n", file);
		fputs("<excess_weekly_budget>", file);
	sprintf(data, "%f", current->excess_weekly_budget);
	fputs(data, file);
	fputs("</excess_weekly_budget>\n", file);
		fputs("<assetsowned>", file);
	write_Asset_dynamic_array(file, &current->assetsowned);
	fputs("</assetsowned>\n", file);
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
		fputs("<total_income>", file);
	sprintf(data, "%f", current->total_income);
	fputs(data, file);
	fputs("</total_income>\n", file);
		fputs("<total_expenses>", file);
	sprintf(data, "%f", current->total_expenses);
	fputs(data, file);
	fputs("</total_expenses>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_liabilities>", file);
	sprintf(data, "%f", current->total_liabilities);
	fputs(data, file);
	fputs("</total_liabilities>\n", file);
		fputs("<gov_interest>", file);
	sprintf(data, "%f", current->gov_interest);
	fputs(data, file);
	fputs("</gov_interest>\n", file);
		fputs("<stock_sales>", file);
	sprintf(data, "%f", current->stock_sales);
	fputs(data, file);
	fputs("</stock_sales>\n", file);
		fputs("<stock_purchases>", file);
	sprintf(data, "%f", current->stock_purchases);
	fputs(data, file);
	fputs("</stock_purchases>\n", file);
		fputs("<gov_bond_purchases>", file);
	sprintf(data, "%f", current->gov_bond_purchases);
	fputs(data, file);
	fputs("</gov_bond_purchases>\n", file);
		fputs("<monthly_consumption_expenditure>", file);
	sprintf(data, "%f", current->monthly_consumption_expenditure);
	fputs(data, file);
	fputs("</monthly_consumption_expenditure>\n", file);
		fputs("<gov_bond_holdings>", file);
	sprintf(data, "%f", current->gov_bond_holdings);
	fputs(data, file);
	fputs("</gov_bond_holdings>\n", file);
		fputs("<nr_gov_bonds>", file);
	sprintf(data, "%i", current->nr_gov_bonds);
	fputs(data, file);
	fputs("</nr_gov_bonds>\n", file);
		fputs("<nr_firm_shares>", file);
	sprintf(data, "%i", current->nr_firm_shares);
	fputs(data, file);
	fputs("</nr_firm_shares>\n", file);

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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<earnings>", file);
	sprintf(data, "%f", current->earnings);
	fputs(data, file);
	fputs("</earnings>\n", file);
		fputs("<energy_price_markup>", file);
	sprintf(data, "%f", current->energy_price_markup);
	fputs(data, file);
	fputs("</energy_price_markup>\n", file);
		fputs("<energy_costs_per_day>", file);
	sprintf(data, "%f", current->energy_costs_per_day);
	fputs(data, file);
	fputs("</energy_costs_per_day>\n", file);
		fputs("<earnings_per_day>", file);
	sprintf(data, "%f", current->earnings_per_day);
	fputs(data, file);
	fputs("</earnings_per_day>\n", file);
		fputs("<cum_energy_costs>", file);
	sprintf(data, "%f", current->cum_energy_costs);
	fputs(data, file);
	fputs("</cum_energy_costs>\n", file);
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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<firm_balance_sheets>", file);
	write_firm_balance_sheet_adt(file, &current->firm_balance_sheets);
	fputs("</firm_balance_sheets>\n", file);
		fputs("<household_balance_sheets>", file);
	write_household_balance_sheet_adt(file, &current->household_balance_sheets);
	fputs("</household_balance_sheets>\n", file);
		fputs("<igfirm_balance_sheets>", file);
	write_igfirm_balance_sheet_adt(file, &current->igfirm_balance_sheets);
	fputs("</igfirm_balance_sheets>\n", file);
		fputs("<gov_balance_sheets>", file);
	write_gov_balance_sheet_adt(file, &current->gov_balance_sheets);
	fputs("</gov_balance_sheets>\n", file);
		fputs("<bank_balance_sheets>", file);
	write_bank_balance_sheet_adt(file, &current->bank_balance_sheets);
	fputs("</bank_balance_sheets>\n", file);
		fputs("<ecb_balance_sheets>", file);
	write_ecb_balance_sheet_adt(file, &current->ecb_balance_sheets);
	fputs("</ecb_balance_sheets>\n", file);
		fputs("<firm_average_productivity_progress>", file);
	sprintf(data, "%f", current->firm_average_productivity_progress);
	fputs(data, file);
	fputs("</firm_average_productivity_progress>\n", file);
		fputs("<firm_average_productivity>", file);
	sprintf(data, "%f", current->firm_average_productivity);
	fputs(data, file);
	fputs("</firm_average_productivity>\n", file);

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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
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
		fputs("<ecb_debt>", file);
	sprintf(data, "%f", current->ecb_debt);
	fputs(data, file);
	fputs("</ecb_debt>\n", file);
		fputs("<alfa>", file);
	sprintf(data, "%f", current->alfa);
	fputs(data, file);
	fputs("</alfa>\n", file);
		fputs("<value_at_risk>", file);
	sprintf(data, "%f", current->value_at_risk);
	fputs(data, file);
	fputs("</value_at_risk>\n", file);
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
		fputs("<ecb_interest_rate>", file);
	sprintf(data, "%f", current->ecb_interest_rate);
	fputs(data, file);
	fputs("</ecb_interest_rate>\n", file);
		fputs("<bank_dividend_rate>", file);
	sprintf(data, "%f", current->bank_dividend_rate);
	fputs(data, file);
	fputs("</bank_dividend_rate>\n", file);
		fputs("<tax_rate_corporate>", file);
	sprintf(data, "%f", current->tax_rate_corporate);
	fputs(data, file);
	fputs("</tax_rate_corporate>\n", file);
		fputs("<current_shares_outstanding>", file);
	sprintf(data, "%i", current->current_shares_outstanding);
	fputs(data, file);
	fputs("</current_shares_outstanding>\n", file);
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
		fputs("<deposits>", file);
	sprintf(data, "%f", current->deposits);
	fputs(data, file);
	fputs("</deposits>\n", file);
		fputs("<firm_loan_installments>", file);
	sprintf(data, "%f", current->firm_loan_installments);
	fputs(data, file);
	fputs("</firm_loan_installments>\n", file);
		fputs("<firm_interest_payments>", file);
	sprintf(data, "%f", current->firm_interest_payments);
	fputs(data, file);
	fputs("</firm_interest_payments>\n", file);
		fputs("<firm_loan_issues>", file);
	sprintf(data, "%f", current->firm_loan_issues);
	fputs(data, file);
	fputs("</firm_loan_issues>\n", file);
		fputs("<ecb_interest_payment>", file);
	sprintf(data, "%f", current->ecb_interest_payment);
	fputs(data, file);
	fputs("</ecb_interest_payment>\n", file);
		fputs("<dividend_payment>", file);
	sprintf(data, "%f", current->dividend_payment);
	fputs(data, file);
	fputs("</dividend_payment>\n", file);
		fputs("<taxes>", file);
	sprintf(data, "%f", current->taxes);
	fputs(data, file);
	fputs("</taxes>\n", file);
		fputs("<total_income>", file);
	sprintf(data, "%f", current->total_income);
	fputs(data, file);
	fputs("</total_income>\n", file);
		fputs("<total_expenses>", file);
	sprintf(data, "%f", current->total_expenses);
	fputs(data, file);
	fputs("</total_expenses>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_liabilities>", file);
	sprintf(data, "%f", current->total_liabilities);
	fputs(data, file);
	fputs("</total_liabilities>\n", file);

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
	write_int_dynamic_array(file, &current->list_of_regions);
	fputs("</list_of_regions>\n", file);
		fputs("<payment_account>", file);
	sprintf(data, "%f", current->payment_account);
	fputs(data, file);
	fputs("</payment_account>\n", file);
		fputs("<day_of_month_to_act>", file);
	sprintf(data, "%i", current->day_of_month_to_act);
	fputs(data, file);
	fputs("</day_of_month_to_act>\n", file);
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
		fputs("<region_id>", file);
	sprintf(data, "%i", current->region_id);
	fputs(data, file);
	fputs("</region_id>\n", file);
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
		fputs("<monthly_benefit_payment>", file);
	sprintf(data, "%f", current->monthly_benefit_payment);
	fputs(data, file);
	fputs("</monthly_benefit_payment>\n", file);
		fputs("<yearly_benefit_payment>", file);
	sprintf(data, "%f", current->yearly_benefit_payment);
	fputs(data, file);
	fputs("</yearly_benefit_payment>\n", file);
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
		fputs("<monthly_bond_interest_payment>", file);
	sprintf(data, "%f", current->monthly_bond_interest_payment);
	fputs(data, file);
	fputs("</monthly_bond_interest_payment>\n", file);
		fputs("<yearly_bond_interest_payment>", file);
	sprintf(data, "%f", current->yearly_bond_interest_payment);
	fputs(data, file);
	fputs("</yearly_bond_interest_payment>\n", file);
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
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_liabilities>", file);
	sprintf(data, "%f", current->total_liabilities);
	fputs(data, file);
	fputs("</total_liabilities>\n", file);
		fputs("<value_bonds_outstanding>", file);
	sprintf(data, "%f", current->value_bonds_outstanding);
	fputs(data, file);
	fputs("</value_bonds_outstanding>\n", file);
		fputs("<nr_bonds_outstanding>", file);
	sprintf(data, "%i", current->nr_bonds_outstanding);
	fputs(data, file);
	fputs("</nr_bonds_outstanding>\n", file);

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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
		fputs("<accounts>", file);
	write_account_item_dynamic_array(file, &current->accounts);
	fputs("</accounts>\n", file);
		fputs("<ecb_interest_rate>", file);
	sprintf(data, "%f", current->ecb_interest_rate);
	fputs(data, file);
	fputs("</ecb_interest_rate>\n", file);
		fputs("<equity>", file);
	sprintf(data, "%f", current->equity);
	fputs(data, file);
	fputs("</equity>\n", file);
		fputs("<dividend_payment>", file);
	sprintf(data, "%f", current->dividend_payment);
	fputs(data, file);
	fputs("</dividend_payment>\n", file);
		fputs("<total_ecb_debt>", file);
	sprintf(data, "%f", current->total_ecb_debt);
	fputs(data, file);
	fputs("</total_ecb_debt>\n", file);
		fputs("<gov_bond_holdings>", file);
	sprintf(data, "%f", current->gov_bond_holdings);
	fputs(data, file);
	fputs("</gov_bond_holdings>\n", file);
		fputs("<nr_gov_bonds>", file);
	sprintf(data, "%i", current->nr_gov_bonds);
	fputs(data, file);
	fputs("</nr_gov_bonds>\n", file);
		fputs("<payment_account_private_sector>", file);
	sprintf(data, "%f", current->payment_account_private_sector);
	fputs(data, file);
	fputs("</payment_account_private_sector>\n", file);
		fputs("<payment_account_public_sector>", file);
	sprintf(data, "%f", current->payment_account_public_sector);
	fputs(data, file);
	fputs("</payment_account_public_sector>\n", file);
		fputs("<fiat_money>", file);
	sprintf(data, "%f", current->fiat_money);
	fputs(data, file);
	fputs("</fiat_money>\n", file);
		fputs("<bank_interest>", file);
	sprintf(data, "%f", current->bank_interest);
	fputs(data, file);
	fputs("</bank_interest>\n", file);
		fputs("<gov_interest>", file);
	sprintf(data, "%f", current->gov_interest);
	fputs(data, file);
	fputs("</gov_interest>\n", file);
		fputs("<gov_bond_purchase>", file);
	sprintf(data, "%f", current->gov_bond_purchase);
	fputs(data, file);
	fputs("</gov_bond_purchase>\n", file);
		fputs("<total_income>", file);
	sprintf(data, "%f", current->total_income);
	fputs(data, file);
	fputs("</total_income>\n", file);
		fputs("<total_expenses>", file);
	sprintf(data, "%f", current->total_expenses);
	fputs(data, file);
	fputs("</total_expenses>\n", file);
		fputs("<total_assets>", file);
	sprintf(data, "%f", current->total_assets);
	fputs(data, file);
	fputs("</total_assets>\n", file);
		fputs("<total_liabilities>", file);
	sprintf(data, "%f", current->total_liabilities);
	fputs(data, file);
	fputs("</total_liabilities>\n", file);

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
		fputs("<partition_id>", file);
	sprintf(data, "%i", current->partition_id);
	fputs(data, file);
	fputs("</partition_id>\n", file);
		fputs("<assets>", file);
	write_Asset_dynamic_array(file, &current->assets);
	fputs("</assets>\n", file);
		fputs("<clearingmechanism>", file);
	write_ClearingMechanism(file, &current->clearingmechanism);
	fputs("</clearingmechanism>\n", file);

	fputs("</xagent>\n", file);
}


void FLAME_write_xml(char * location, int iteration_number, int output_type)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];

		sprintf(data, "%s%i.xml", location, iteration_number);
	
	if((file = fopen(data, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", data);
		exit(0);
	}
	
	/*printf("xml file written: '%s' it=%d type=%d\n", data, iteration_number, output_type);*/
	
	
	fputs("<states>\n", file);
	if(output_type == 0)
	{
		fputs("<itno>", file);
		sprintf(data, "%i", iteration_number);
		fputs(data, file);
		fputs("</itno>\n", file);
		fputs("<environment>\n" , file);
			fputs("<print_log>", file);
		sprintf(data, "%i", FLAME_environment_variable_print_log);
		fputs(data, file);
		fputs("</print_log>\n", file);
			fputs("<print_debug>", file);
		sprintf(data, "%i", FLAME_environment_variable_print_debug);
		fputs(data, file);
		fputs("</print_debug>\n", file);
			fputs("<number_of_banks_to_apply>", file);
		sprintf(data, "%i", FLAME_environment_variable_number_of_banks_to_apply);
		fputs(data, file);
		fputs("</number_of_banks_to_apply>\n", file);
			fputs("<gamma_const>", file);
		sprintf(data, "%f", FLAME_environment_variable_gamma_const);
		fputs(data, file);
		fputs("</gamma_const>\n", file);
			fputs("<alpha>", file);
		sprintf(data, "%f", FLAME_environment_variable_alpha);
		fputs(data, file);
		fputs("</alpha>\n", file);
			fputs("<beta>", file);
		sprintf(data, "%f", FLAME_environment_variable_beta);
		fputs(data, file);
		fputs("</beta>\n", file);
			fputs("<depreciation_rate>", file);
		sprintf(data, "%f", FLAME_environment_variable_depreciation_rate);
		fputs(data, file);
		fputs("</depreciation_rate>\n", file);
			fputs("<discount_rate>", file);
		sprintf(data, "%f", FLAME_environment_variable_discount_rate);
		fputs(data, file);
		fputs("</discount_rate>\n", file);
			fputs("<teta>", file);
		sprintf(data, "%f", FLAME_environment_variable_teta);
		fputs(data, file);
		fputs("</teta>\n", file);
			fputs("<mark_up>", file);
		sprintf(data, "%f", FLAME_environment_variable_mark_up);
		fputs(data, file);
		fputs("</mark_up>\n", file);
			fputs("<lambda>", file);
		sprintf(data, "%f", FLAME_environment_variable_lambda);
		fputs(data, file);
		fputs("</lambda>\n", file);
			fputs("<wage_update>", file);
		sprintf(data, "%f", FLAME_environment_variable_wage_update);
		fputs(data, file);
		fputs("</wage_update>\n", file);
			fputs("<min_vacancy>", file);
		sprintf(data, "%i", FLAME_environment_variable_min_vacancy);
		fputs(data, file);
		fputs("</min_vacancy>\n", file);
			fputs("<wage_reservation_update>", file);
		sprintf(data, "%f", FLAME_environment_variable_wage_reservation_update);
		fputs(data, file);
		fputs("</wage_reservation_update>\n", file);
			fputs("<region_cost>", file);
		sprintf(data, "%f", FLAME_environment_variable_region_cost);
		fputs(data, file);
		fputs("</region_cost>\n", file);
			fputs("<inventory_costs_per_unit>", file);
		sprintf(data, "%f", FLAME_environment_variable_inventory_costs_per_unit);
		fputs(data, file);
		fputs("</inventory_costs_per_unit>\n", file);
			fputs("<on_the_job_search_rate>", file);
		sprintf(data, "%f", FLAME_environment_variable_on_the_job_search_rate);
		fputs(data, file);
		fputs("</on_the_job_search_rate>\n", file);
			fputs("<initial_consumption_propensity>", file);
		sprintf(data, "%f", FLAME_environment_variable_initial_consumption_propensity);
		fputs(data, file);
		fputs("</initial_consumption_propensity>\n", file);
			fputs("<consumption_propensity>", file);
		sprintf(data, "%f", FLAME_environment_variable_consumption_propensity);
		fputs(data, file);
		fputs("</consumption_propensity>\n", file);
			fputs("<firm_planning_horizon>", file);
		sprintf(data, "%i", FLAME_environment_variable_firm_planning_horizon);
		fputs(data, file);
		fputs("</firm_planning_horizon>\n", file);
			fputs("<inv_inertia>", file);
		sprintf(data, "%f", FLAME_environment_variable_inv_inertia);
		fputs(data, file);
		fputs("</inv_inertia>\n", file);
			fputs("<adaption_delivery_volume>", file);
		sprintf(data, "%f", FLAME_environment_variable_adaption_delivery_volume);
		fputs(data, file);
		fputs("</adaption_delivery_volume>\n", file);
			fputs("<delivery_prob_if_critical_stock_0>", file);
		sprintf(data, "%f", FLAME_environment_variable_delivery_prob_if_critical_stock_0);
		fputs(data, file);
		fputs("</delivery_prob_if_critical_stock_0>\n", file);
			fputs("<innovation_probability>", file);
		sprintf(data, "%f", FLAME_environment_variable_innovation_probability);
		fputs(data, file);
		fputs("</innovation_probability>\n", file);
			fputs("<productivity_progress>", file);
		sprintf(data, "%f", FLAME_environment_variable_productivity_progress);
		fputs(data, file);
		fputs("</productivity_progress>\n", file);
			fputs("<lower_bound_firing>", file);
		sprintf(data, "%i", FLAME_environment_variable_lower_bound_firing);
		fputs(data, file);
		fputs("</lower_bound_firing>\n", file);
			fputs("<upper_bound_firing>", file);
		sprintf(data, "%i", FLAME_environment_variable_upper_bound_firing);
		fputs(data, file);
		fputs("</upper_bound_firing>\n", file);
			fputs("<const_bankruptcy_idle_period>", file);
		sprintf(data, "%i", FLAME_environment_variable_const_bankruptcy_idle_period);
		fputs(data, file);
		fputs("</const_bankruptcy_idle_period>\n", file);
			fputs("<const_installment_periods>", file);
		sprintf(data, "%i", FLAME_environment_variable_const_installment_periods);
		fputs(data, file);
		fputs("</const_installment_periods>\n", file);
			fputs("<const_firm_leverage>", file);
		sprintf(data, "%f", FLAME_environment_variable_const_firm_leverage);
		fputs(data, file);
		fputs("</const_firm_leverage>\n", file);
			fputs("<const_number_of_banks>", file);
		sprintf(data, "%i", FLAME_environment_variable_const_number_of_banks);
		fputs(data, file);
		fputs("</const_number_of_banks>\n", file);
			fputs("<switch_stock_consistency_check>", file);
		sprintf(data, "%i", FLAME_environment_variable_switch_stock_consistency_check);
		fputs(data, file);
		fputs("</switch_stock_consistency_check>\n", file);
			fputs("<switch_flow_consistency_check>", file);
		sprintf(data, "%i", FLAME_environment_variable_switch_flow_consistency_check);
		fputs(data, file);
		fputs("</switch_flow_consistency_check>\n", file);
			fputs("<debt_rescaling_factor>", file);
		sprintf(data, "%f", FLAME_environment_variable_debt_rescaling_factor);
		fputs(data, file);
		fputs("</debt_rescaling_factor>\n", file);
			fputs("<target_leverage_ratio>", file);
		sprintf(data, "%f", FLAME_environment_variable_target_leverage_ratio);
		fputs(data, file);
		fputs("</target_leverage_ratio>\n", file);
			fputs("<target_liquidity_ratio>", file);
		sprintf(data, "%f", FLAME_environment_variable_target_liquidity_ratio);
		fputs(data, file);
		fputs("</target_liquidity_ratio>\n", file);
			fputs("<const_dividend_earnings_ratio>", file);
		sprintf(data, "%f", FLAME_environment_variable_const_dividend_earnings_ratio);
		fputs(data, file);
		fputs("</const_dividend_earnings_ratio>\n", file);
			fputs("<discrete_shock>", file);
		sprintf(data, "%i", FLAME_environment_variable_discrete_shock);
		fputs(data, file);
		fputs("</discrete_shock>\n", file);
			fputs("<energy_shock_start>", file);
		sprintf(data, "%i", FLAME_environment_variable_energy_shock_start);
		fputs(data, file);
		fputs("</energy_shock_start>\n", file);
			fputs("<energy_shock_end>", file);
		sprintf(data, "%i", FLAME_environment_variable_energy_shock_end);
		fputs(data, file);
		fputs("</energy_shock_end>\n", file);
			fputs("<const_energy_price_markup>", file);
		sprintf(data, "%f", FLAME_environment_variable_const_energy_price_markup);
		fputs(data, file);
		fputs("</const_energy_price_markup>\n", file);
			fputs("<energy_shock_frequency>", file);
		sprintf(data, "%i", FLAME_environment_variable_energy_shock_frequency);
		fputs(data, file);
		fputs("</energy_shock_frequency>\n", file);
			fputs("<gov_policy_unemployment_benefit_pct>", file);
		sprintf(data, "%f", FLAME_environment_variable_gov_policy_unemployment_benefit_pct);
		fputs(data, file);
		fputs("</gov_policy_unemployment_benefit_pct>\n", file);
			fputs("<gov_policy_money_financing_fraction>", file);
		sprintf(data, "%f", FLAME_environment_variable_gov_policy_money_financing_fraction);
		fputs(data, file);
		fputs("</gov_policy_money_financing_fraction>\n", file);
			fputs("<gov_policy_gdp_fraction_consumption>", file);
		sprintf(data, "%f", FLAME_environment_variable_gov_policy_gdp_fraction_consumption);
		fputs(data, file);
		fputs("</gov_policy_gdp_fraction_consumption>\n", file);
			fputs("<gov_policy_gdp_fraction_investment>", file);
		sprintf(data, "%f", FLAME_environment_variable_gov_policy_gdp_fraction_investment);
		fputs(data, file);
		fputs("</gov_policy_gdp_fraction_investment>\n", file);
			fputs("<no_regions_per_gov>", file);
		sprintf(data, "%i", FLAME_environment_variable_no_regions_per_gov);
		fputs(data, file);
		fputs("</no_regions_per_gov>\n", file);
			fputs("</environment>\n" , file);
	}
	
	
	if(output_type == 0 || output_type == 1)
	{
		
		current_xmachine_Firm_holder = Firm_end_Firm_state->agents;
			while(current_xmachine_Firm_holder)
			{
				write_Firm_agent(file, current_xmachine_Firm_holder->agent);

				current_xmachine_Firm_holder = current_xmachine_Firm_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 2)
	{
		
		current_xmachine_Household_holder = Household_end_Household_state->agents;
			while(current_xmachine_Household_holder)
			{
				write_Household_agent(file, current_xmachine_Household_holder->agent);

				current_xmachine_Household_holder = current_xmachine_Household_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 3)
	{
		
		current_xmachine_Mall_holder = Mall_end_Mall_state->agents;
			while(current_xmachine_Mall_holder)
			{
				write_Mall_agent(file, current_xmachine_Mall_holder->agent);

				current_xmachine_Mall_holder = current_xmachine_Mall_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 4)
	{
		
		current_xmachine_IGFirm_holder = IGFirm_end_IGFirm_state->agents;
			while(current_xmachine_IGFirm_holder)
			{
				write_IGFirm_agent(file, current_xmachine_IGFirm_holder->agent);

				current_xmachine_IGFirm_holder = current_xmachine_IGFirm_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 5)
	{
		
		current_xmachine_Eurostat_holder = Eurostat_end_Eurostat_state->agents;
			while(current_xmachine_Eurostat_holder)
			{
				write_Eurostat_agent(file, current_xmachine_Eurostat_holder->agent);

				current_xmachine_Eurostat_holder = current_xmachine_Eurostat_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 6)
	{
		
		current_xmachine_Bank_holder = Bank_end_Bank_cycle_state->agents;
			while(current_xmachine_Bank_holder)
			{
				write_Bank_agent(file, current_xmachine_Bank_holder->agent);

				current_xmachine_Bank_holder = current_xmachine_Bank_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 7)
	{
		
		current_xmachine_Government_holder = Government_end_Government_state->agents;
			while(current_xmachine_Government_holder)
			{
				write_Government_agent(file, current_xmachine_Government_holder->agent);

				current_xmachine_Government_holder = current_xmachine_Government_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 8)
	{
		
		current_xmachine_Central_Bank_holder = Central_Bank_end_Central_Bank_state->agents;
			while(current_xmachine_Central_Bank_holder)
			{
				write_Central_Bank_agent(file, current_xmachine_Central_Bank_holder->agent);

				current_xmachine_Central_Bank_holder = current_xmachine_Central_Bank_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 9)
	{
		
		current_xmachine_Clearinghouse_holder = Clearinghouse_end_Clearinghouse_state->agents;
			while(current_xmachine_Clearinghouse_holder)
			{
				write_Clearinghouse_agent(file, current_xmachine_Clearinghouse_holder->agent);

				current_xmachine_Clearinghouse_holder = current_xmachine_Clearinghouse_holder->next;
			}
		
	}
	
	fputs("</states>\n" , file);

	/* Close the file */
	fclose(file);
}

/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	FLAME_output * current_FLAME_output;
	FLAME_output * current_FLAME_output2;
	int flag;
	char * snapshot_location = NULL;

	/* First check snapshot */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		if(iteration_number%current_FLAME_output->period == current_FLAME_output->phase)
		{
			if(current_FLAME_output->type == 0)
			{
				snapshot_location = current_FLAME_output->location;
				FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
			}
			if(current_FLAME_output->type == 1)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 2)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 3)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 4)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 5)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 6)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 7)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 8)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 9)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			
		}
	}
}
