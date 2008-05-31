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
	(*temp_datatype).debt_installment_payment = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).debt_installment_payment = atof(arraydata);
	(*j)++;
	(*temp_datatype).nr_periods_before_maturity = 0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_periods_before_maturity = atoi(arraydata);
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
			add_debt_item(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, 0);
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

void read_firm_data_dynamic_array(char * buffer, int * j, firm_data_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_firm_data(temp_datatype_array, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
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

/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], 
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
	int j=0;

/* Things for round-robin partitioning */
	int agent_count;
	int number_partitions;
	int geometric=1;
	int other=2;
	double 	xmax=0,xmin=0,ymax=0,ymin=0,
		xcentre=0,ycentre=0,
		rrange=1.5;
	double posx, posy, posz;
	
	
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
	int in_Market_Research_agent;
	int in_Clearinghouse_agent;
	int in_Bank_agent;

	int in_id;
	int in_region_id;
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
	int in_wage_update_was_made;
	int in_share_net_investments;
	int in_mean_wage;
	int in_needed_capital_stock;
	int in_actual_cap_price;
	int in_mean_specific_skills;
	int in_planned_production_quantity;
	int in_production_quantity;
	int in_unit_costs;
	int in_planned_production_costs;
	int in_production_costs;
	int in_revenue_per_day;
	int in_technological_frontier;
	int in_cum_revenue;
	int in_out_of_stock_costs;
	int in_malls_sales_statistics;
	int in_quality;
	int in_price;
	int in_price_last_month;
	int in_capital_stock;
	int in_total_units_capital_stock;
	int in_total_value_capital_stock;
	int in_total_capital_depreciation_value;
	int in_total_capital_depreciation_units;
	int in_employees_needed;
	int in_sold_quantities;
	int in_total_sold_quantity;
	int in_cum_total_sold_quantity;
	int in_delivery_volume;
	int in_planned_delivery_volume;
	int in_current_mall_stocks;
	int in_demand_capital_stock;
	int in_last_planned_production_quantities;
	int in_day_of_month_to_act;
	int in_gov_id;
	int in_bank_id;
	int in_ebit;
	int in_payment_account;
	int in_earnings;
	int in_tax_rate_corporate;
	int in_tax_payment;
	int in_net_earnings;
	int in_previous_net_earnings;
	int in_loans;
	int in_total_interest_payment;
	int in_total_debt_installment_payment;
	int in_total_debt;
	int in_total_dividend_payment;
	int in_total_value_local_inventory;
	int in_total_assets;
	int in_planned_cum_revenue;
	int in_planned_total_interest_payment;
	int in_planned_total_debt_installment_payment;
	int in_planned_total_dividend_payment;
	int in_direct_financial_needs;
	int in_delayed_financial_needs;
	int in_total_financial_needs;
	int in_internal_financial_needs;
	int in_external_financial_needs;
	int in_total_external_financing_obtained;
	int in_direct_financial_needs_require_external_financing;
	int in_delayed_financial_needs_require_external_financing;
	int in_current_share_price;
	int in_current_shares_outstanding;
	int in_previous_dividend_per_share;
	int in_current_dividend_per_share;
	int in_previous_dividend_per_earnings;
	int in_current_dividend_per_earnings;
	int in_earnings_per_share_ratio;
	int in_debt_earnings_ratio;
	int in_price_earnings_ratio;
	int in_retained_earnings_ratio;
	int in_earnings_per_share_ratio_growth;
	int in_critical_price_earnings_ratio;
	int in_critical_earnings_per_share_ratio;
	int in_target_loans;
	int in_target_equity;
	int in_bonds_issue_target;
	int in_stocks_issue_target;
	int in_range;
	int in_posx;
	int in_posy;
	int in_neighboring_region_ids;
	int in_wage;
	int in_wage_reservation;
	int in_general_skill;
	int in_on_the_job_search;
	int in_number_applications;
	int in_specific_skill;
	int in_employee_firm_id;
	int in_employer_region_id;
	int in_budget;
	int in_week_of_month;
	int in_weekly_budget;
	int in_expenditures;
	int in_received_dividend_cap;
	int in_received_dividend_cons;
	int in_savings;
	int in_last_income;
	int in_rationed;
	int in_mall_completely_sold_out;
	int in_order_quantity;
	int in_received_quantity;
	int in_day_of_week_to_act;
	int in_current_stock;
	int in_firm_revenues;
	int in_total_supply;
	int in_productivity;
	int in_innovation_probability;
	int in_productivity_progress;
	int in_capital_good_price;
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
	int in_trader_id;
	int in_stock_id;
	int in_bond_id;
	int in_gov_bond_id;
	int in_limit_price;
	int in_limit_quantity;
	int in_proposed_interest_rate;
	int in_amount_credit_offer;


	/* Variables for initial state data */
//	int id;
//	int region_id;
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
//	int wage_update_was_made;
//	double share_net_investments;
//	double mean_wage;
//	double needed_capital_stock;
//	double actual_cap_price;
//	double mean_specific_skills;
//	double planned_production_quantity;
//	double production_quantity;
//	double unit_costs;
//	double planned_production_costs;
//	double production_costs;
//	double revenue_per_day;
//	double technological_frontier;
//	double cum_revenue;
//	double out_of_stock_costs;
//	sales_statistics_array * malls_sales_statistics;
//	double quality;
//	double price;
//	double price_last_month;
//	capital_stock_item_array * capital_stock;
//	double total_units_capital_stock;
//	double total_value_capital_stock;
//	double total_capital_depreciation_value;
//	double total_capital_depreciation_units;
//	int employees_needed;
//	sold_quantities_per_mall_array * sold_quantities;
//	double total_sold_quantity;
//	double cum_total_sold_quantity;
//	delivery_volume_per_mall_array * delivery_volume;
//	delivery_volume_per_mall_array * planned_delivery_volume;
//	mall_info_array * current_mall_stocks;
//	double demand_capital_stock;
//	double_array * last_planned_production_quantities;
//	int day_of_month_to_act;
//	int gov_id;
//	int bank_id;
//	double ebit;
//	double payment_account;
//	double earnings;
//	double tax_rate_corporate;
//	double tax_payment;
//	double net_earnings;
//	double previous_net_earnings;
//	debt_item_array * loans;
//	double total_interest_payment;
//	double total_debt_installment_payment;
//	double total_debt;
//	double total_dividend_payment;
//	double total_value_local_inventory;
//	double total_assets;
//	double planned_cum_revenue;
//	double planned_total_interest_payment;
//	double planned_total_debt_installment_payment;
//	double planned_total_dividend_payment;
//	double direct_financial_needs;
//	double delayed_financial_needs;
//	double total_financial_needs;
//	double internal_financial_needs;
//	double external_financial_needs;
//	double total_external_financing_obtained;
//	int direct_financial_needs_require_external_financing;
//	int delayed_financial_needs_require_external_financing;
//	double current_share_price;
//	double current_shares_outstanding;
//	double previous_dividend_per_share;
//	double current_dividend_per_share;
//	double previous_dividend_per_earnings;
//	double current_dividend_per_earnings;
//	double earnings_per_share_ratio;
//	double debt_earnings_ratio;
//	double price_earnings_ratio;
//	double retained_earnings_ratio;
//	double earnings_per_share_ratio_growth;
//	double critical_price_earnings_ratio;
//	double critical_earnings_per_share_ratio;
//	double target_loans;
//	double target_equity;
//	double bonds_issue_target;
//	double stocks_issue_target;
//	double range;
//	double posx;
//	double posy;
//	int_array * neighboring_region_ids;
//	double wage;
//	double wage_reservation;
//	int general_skill;
//	int on_the_job_search;
//	int number_applications;
//	double specific_skill;
//	int employee_firm_id;
//	int employer_region_id;
//	double budget;
//	int week_of_month;
//	double weekly_budget;
//	double expenditures;
//	double received_dividend_cap;
//	double received_dividend_cons;
//	double savings;
//	double_array * last_income;
//	int rationed;
//	int mall_completely_sold_out;
//	ordered_quantity ** order_quantity;
//	received_quantities ** received_quantity;
//	int day_of_week_to_act;
//	mall_stock_array * current_stock;
//	sales_in_mall_array * firm_revenues;
//	double total_supply;
//	double productivity;
//	int innovation_probability;
//	double productivity_progress;
//	double capital_good_price;
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
//	int trader_id;
//	int stock_id;
//	int bond_id;
//	int gov_bond_id;
//	double limit_price;
//	double limit_quantity;
//	double proposed_interest_rate;
//	double amount_credit_offer;


	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Mall * current_Mall_agent;
	xmachine_memory_IGFirm * current_IGFirm_agent;
	xmachine_memory_Market_Research * current_Market_Research_agent;
	xmachine_memory_Clearinghouse * current_Clearinghouse_agent;
	xmachine_memory_Bank * current_Bank_agent;


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
	in_Market_Research_agent = 0;
	in_Clearinghouse_agent = 0;
	in_Bank_agent = 0;
	in_id = 0;
	in_region_id = 0;
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
	in_wage_update_was_made = 0;
	in_share_net_investments = 0;
	in_mean_wage = 0;
	in_needed_capital_stock = 0;
	in_actual_cap_price = 0;
	in_mean_specific_skills = 0;
	in_planned_production_quantity = 0;
	in_production_quantity = 0;
	in_unit_costs = 0;
	in_planned_production_costs = 0;
	in_production_costs = 0;
	in_revenue_per_day = 0;
	in_technological_frontier = 0;
	in_cum_revenue = 0;
	in_out_of_stock_costs = 0;
	in_malls_sales_statistics = 0;
	in_quality = 0;
	in_price = 0;
	in_price_last_month = 0;
	in_capital_stock = 0;
	in_total_units_capital_stock = 0;
	in_total_value_capital_stock = 0;
	in_total_capital_depreciation_value = 0;
	in_total_capital_depreciation_units = 0;
	in_employees_needed = 0;
	in_sold_quantities = 0;
	in_total_sold_quantity = 0;
	in_cum_total_sold_quantity = 0;
	in_delivery_volume = 0;
	in_planned_delivery_volume = 0;
	in_current_mall_stocks = 0;
	in_demand_capital_stock = 0;
	in_last_planned_production_quantities = 0;
	in_day_of_month_to_act = 0;
	in_gov_id = 0;
	in_bank_id = 0;
	in_ebit = 0;
	in_payment_account = 0;
	in_earnings = 0;
	in_tax_rate_corporate = 0;
	in_tax_payment = 0;
	in_net_earnings = 0;
	in_previous_net_earnings = 0;
	in_loans = 0;
	in_total_interest_payment = 0;
	in_total_debt_installment_payment = 0;
	in_total_debt = 0;
	in_total_dividend_payment = 0;
	in_total_value_local_inventory = 0;
	in_total_assets = 0;
	in_planned_cum_revenue = 0;
	in_planned_total_interest_payment = 0;
	in_planned_total_debt_installment_payment = 0;
	in_planned_total_dividend_payment = 0;
	in_direct_financial_needs = 0;
	in_delayed_financial_needs = 0;
	in_total_financial_needs = 0;
	in_internal_financial_needs = 0;
	in_external_financial_needs = 0;
	in_total_external_financing_obtained = 0;
	in_direct_financial_needs_require_external_financing = 0;
	in_delayed_financial_needs_require_external_financing = 0;
	in_current_share_price = 0;
	in_current_shares_outstanding = 0;
	in_previous_dividend_per_share = 0;
	in_current_dividend_per_share = 0;
	in_previous_dividend_per_earnings = 0;
	in_current_dividend_per_earnings = 0;
	in_earnings_per_share_ratio = 0;
	in_debt_earnings_ratio = 0;
	in_price_earnings_ratio = 0;
	in_retained_earnings_ratio = 0;
	in_earnings_per_share_ratio_growth = 0;
	in_critical_price_earnings_ratio = 0;
	in_critical_earnings_per_share_ratio = 0;
	in_target_loans = 0;
	in_target_equity = 0;
	in_bonds_issue_target = 0;
	in_stocks_issue_target = 0;
	in_range = 0;
	in_posx = 0;
	in_posy = 0;
	in_neighboring_region_ids = 0;
	in_wage = 0;
	in_wage_reservation = 0;
	in_general_skill = 0;
	in_on_the_job_search = 0;
	in_number_applications = 0;
	in_specific_skill = 0;
	in_employee_firm_id = 0;
	in_employer_region_id = 0;
	in_budget = 0;
	in_week_of_month = 0;
	in_weekly_budget = 0;
	in_expenditures = 0;
	in_received_dividend_cap = 0;
	in_received_dividend_cons = 0;
	in_savings = 0;
	in_last_income = 0;
	in_rationed = 0;
	in_mall_completely_sold_out = 0;
	in_order_quantity = 0;
	in_received_quantity = 0;
	in_day_of_week_to_act = 0;
	in_current_stock = 0;
	in_firm_revenues = 0;
	in_total_supply = 0;
	in_productivity = 0;
	in_innovation_probability = 0;
	in_productivity_progress = 0;
	in_capital_good_price = 0;
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
	in_trader_id = 0;
	in_stock_id = 0;
	in_bond_id = 0;
	in_gov_bond_id = 0;
	in_limit_price = 0;
	in_limit_quantity = 0;
	in_proposed_interest_rate = 0;
	in_amount_credit_offer = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	region_id = 0;
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
//	wage_update_was_made = 0;
//	share_net_investments = 0.0;
//	mean_wage = 0.0;
//	needed_capital_stock = 0.0;
//	actual_cap_price = 0.0;
//	mean_specific_skills = 0.0;
//	planned_production_quantity = 0.0;
//	production_quantity = 0.0;
//	unit_costs = 0.0;
//	planned_production_costs = 0.0;
//	production_costs = 0.0;
//	revenue_per_day = 0.0;
//	technological_frontier = 0.0;
//	cum_revenue = 0.0;
//	out_of_stock_costs = 0.0;
//	malls_sales_statistics = init_sales_statistics_array();
//	quality = 0.0;
//	price = 0.0;
//	price_last_month = 0.0;
//	capital_stock = init_capital_stock_item_array();
//	total_units_capital_stock = 0.0;
//	total_value_capital_stock = 0.0;
//	total_capital_depreciation_value = 0.0;
//	total_capital_depreciation_units = 0.0;
//	employees_needed = 0;
//	sold_quantities = init_sold_quantities_per_mall_array();
//	total_sold_quantity = 0.0;
//	cum_total_sold_quantity = 0.0;
//	delivery_volume = init_delivery_volume_per_mall_array();
//	planned_delivery_volume = init_delivery_volume_per_mall_array();
//	current_mall_stocks = init_mall_info_array();
//	demand_capital_stock = 0.0;
//	last_planned_production_quantities = init_double_array();
//	day_of_month_to_act = 0;
//	gov_id = 0;
//	bank_id = 0;
//	ebit = 0.0;
//	payment_account = 0.0;
//	earnings = 0.0;
//	tax_rate_corporate = 0.0;
//	tax_payment = 0.0;
//	net_earnings = 0.0;
//	previous_net_earnings = 0.0;
//	loans = init_debt_item_array();
//	total_interest_payment = 0.0;
//	total_debt_installment_payment = 0.0;
//	total_debt = 0.0;
//	total_dividend_payment = 0.0;
//	total_value_local_inventory = 0.0;
//	total_assets = 0.0;
//	planned_cum_revenue = 0.0;
//	planned_total_interest_payment = 0.0;
//	planned_total_debt_installment_payment = 0.0;
//	planned_total_dividend_payment = 0.0;
//	direct_financial_needs = 0.0;
//	delayed_financial_needs = 0.0;
//	total_financial_needs = 0.0;
//	internal_financial_needs = 0.0;
//	external_financial_needs = 0.0;
//	total_external_financing_obtained = 0.0;
//	direct_financial_needs_require_external_financing = 0;
//	delayed_financial_needs_require_external_financing = 0;
//	current_share_price = 0.0;
//	current_shares_outstanding = 0.0;
//	previous_dividend_per_share = 0.0;
//	current_dividend_per_share = 0.0;
//	previous_dividend_per_earnings = 0.0;
//	current_dividend_per_earnings = 0.0;
//	earnings_per_share_ratio = 0.0;
//	debt_earnings_ratio = 0.0;
//	price_earnings_ratio = 0.0;
//	retained_earnings_ratio = 0.0;
//	earnings_per_share_ratio_growth = 0.0;
//	critical_price_earnings_ratio = 0.0;
//	critical_earnings_per_share_ratio = 0.0;
//	target_loans = 0.0;
//	target_equity = 0.0;
//	bonds_issue_target = 0.0;
//	stocks_issue_target = 0.0;
//	range = 0.0;
//	posx = 0.0;
//	posy = 0.0;
//	neighboring_region_ids = init_int_array();
//	wage = 0.0;
//	wage_reservation = 0.0;
//	general_skill = 0;
//	on_the_job_search = 0;
//	number_applications = 0;
//	specific_skill = 0.0;
//	employee_firm_id = 0;
//	employer_region_id = 0;
//	budget = 0.0;
//	week_of_month = 0;
//	weekly_budget = 0.0;
//	expenditures = 0.0;
//	received_dividend_cap = 0.0;
//	received_dividend_cons = 0.0;
//	savings = 0.0;
//	last_income = init_double_array();
//	rationed = 0;
//	mall_completely_sold_out = 0;
//	order_quantity = init_ordered_quantity_static_array(2);
//	received_quantity = init_received_quantities_static_array(2);
//	day_of_week_to_act = 0;
//	current_stock = init_mall_stock_array();
//	firm_revenues = init_sales_in_mall_array();
//	total_supply = 0.0;
//	productivity = 0.0;
//	innovation_probability = 0;
//	productivity_progress = 0.0;
//	capital_good_price = 0.0;
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
//	trader_id = 0;
//	stock_id = 0;
//	bond_id = 0;
//	gov_bond_id = 0;
//	limit_price = 0.0;
//	limit_quantity = 0.0;
//	proposed_interest_rate = 0.0;
//	amount_credit_offer = 0.0;







	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list 
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */ 
	p_xmachine = agent_list;
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
					else if(strcmp(agentname, "Market_Research") == 0)
					{
						current_Market_Research_agent = init_Market_Research_agent();
						in_Market_Research_agent = 1;
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
in_Market_Research_agent = 0;
in_Clearinghouse_agent = 0;
in_Bank_agent = 0;

				
				if(strcmp(agentname, "Firm") == 0)
				{
					posx = current_Firm_agent->posx;
					posy = current_Firm_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, region_id, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, wage_update_was_made, share_net_investments, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, planned_production_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, employees_needed, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, demand_capital_stock, last_planned_production_quantities, day_of_month_to_act, gov_id, bank_id, ebit, payment_account, earnings, tax_rate_corporate, tax_payment, net_earnings, previous_net_earnings, loans, total_interest_payment, total_debt_installment_payment, total_debt, total_dividend_payment, total_value_local_inventory, total_assets, planned_cum_revenue, planned_total_interest_payment, planned_total_debt_installment_payment, planned_total_dividend_payment, direct_financial_needs, delayed_financial_needs, total_financial_needs, internal_financial_needs, external_financial_needs, total_external_financing_obtained, direct_financial_needs_require_external_financing, delayed_financial_needs_require_external_financing, current_share_price, current_shares_outstanding, previous_dividend_per_share, current_dividend_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, earnings_per_share_ratio, debt_earnings_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, target_loans, target_equity, bonds_issue_target, stocks_issue_target, range, posx, posy);
						add_Firm_agent_internal(current_Firm_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, region_id, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, wage_update_was_made, share_net_investments, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, planned_production_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, employees_needed, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, demand_capital_stock, last_planned_production_quantities, day_of_month_to_act, gov_id, bank_id, ebit, payment_account, earnings, tax_rate_corporate, tax_payment, net_earnings, previous_net_earnings, loans, total_interest_payment, total_debt_installment_payment, total_debt, total_dividend_payment, total_value_local_inventory, total_assets, planned_cum_revenue, planned_total_interest_payment, planned_total_debt_installment_payment, planned_total_dividend_payment, direct_financial_needs, delayed_financial_needs, total_financial_needs, internal_financial_needs, external_financial_needs, total_external_financing_obtained, direct_financial_needs_require_external_financing, delayed_financial_needs_require_external_financing, current_share_price, current_shares_outstanding, previous_dividend_per_share, current_dividend_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, earnings_per_share_ratio, debt_earnings_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, target_loans, target_equity, bonds_issue_target, stocks_issue_target, range, posx, posy);
								add_Firm_agent_internal(current_Firm_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Firm_agent(id, region_id, employees, wage_offer, technology, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, vacancies, average_g_skill, average_s_skill_of_1, average_s_skill_of_2, average_s_skill_of_3, average_s_skill_of_4, average_s_skill_of_5, wage_offer_for_skill_1, wage_offer_for_skill_2, wage_offer_for_skill_3, wage_offer_for_skill_4, wage_offer_for_skill_5, wage_update_was_made, share_net_investments, mean_wage, needed_capital_stock, actual_cap_price, mean_specific_skills, planned_production_quantity, production_quantity, unit_costs, planned_production_costs, production_costs, revenue_per_day, technological_frontier, cum_revenue, out_of_stock_costs, malls_sales_statistics, quality, price, price_last_month, capital_stock, total_units_capital_stock, total_value_capital_stock, total_capital_depreciation_value, total_capital_depreciation_units, employees_needed, sold_quantities, total_sold_quantity, cum_total_sold_quantity, delivery_volume, planned_delivery_volume, current_mall_stocks, demand_capital_stock, last_planned_production_quantities, day_of_month_to_act, gov_id, bank_id, ebit, payment_account, earnings, tax_rate_corporate, tax_payment, net_earnings, previous_net_earnings, loans, total_interest_payment, total_debt_installment_payment, total_debt, total_dividend_payment, total_value_local_inventory, total_assets, planned_cum_revenue, planned_total_interest_payment, planned_total_debt_installment_payment, planned_total_dividend_payment, direct_financial_needs, delayed_financial_needs, total_financial_needs, internal_financial_needs, external_financial_needs, total_external_financing_obtained, direct_financial_needs_require_external_financing, delayed_financial_needs_require_external_financing, current_share_price, current_shares_outstanding, previous_dividend_per_share, current_dividend_per_share, previous_dividend_per_earnings, current_dividend_per_earnings, earnings_per_share_ratio, debt_earnings_ratio, price_earnings_ratio, retained_earnings_ratio, earnings_per_share_ratio_growth, critical_price_earnings_ratio, critical_earnings_per_share_ratio, target_loans, target_equity, bonds_issue_target, stocks_issue_target, range, posx, posy);
								add_Firm_agent_internal(current_Firm_agent);

								current_Firm_agent->posx = xcentre;
								current_Firm_agent->posy = ycentre;
								current_Firm_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Household") == 0)
				{
					posx = current_Household_agent->posx;
					posy = current_Household_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, region_id, neighboring_region_ids, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id, budget, week_of_month, weekly_budget, expenditures, received_dividend_cap, received_dividend_cons, savings, last_income, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_month_to_act, day_of_week_to_act, range, posx, posy);
						add_Household_agent_internal(current_Household_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Household_agent(id, region_id, neighboring_region_ids, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id, budget, week_of_month, weekly_budget, expenditures, received_dividend_cap, received_dividend_cons, savings, last_income, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_month_to_act, day_of_week_to_act, range, posx, posy);
								add_Household_agent_internal(current_Household_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Household_agent(id, region_id, neighboring_region_ids, wage, wage_reservation, general_skill, on_the_job_search, number_applications, specific_skill, employee_firm_id, employer_region_id, budget, week_of_month, weekly_budget, expenditures, received_dividend_cap, received_dividend_cons, savings, last_income, rationed, mall_completely_sold_out, order_quantity, received_quantity, day_of_month_to_act, day_of_week_to_act, range, posx, posy);
								add_Household_agent_internal(current_Household_agent);

								current_Household_agent->posx = xcentre;
								current_Household_agent->posy = ycentre;
								current_Household_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Mall") == 0)
				{
					posx = current_Mall_agent->posx;
					posy = current_Mall_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Mall_agent(id, region_id, current_stock, firm_revenues, total_supply, range, posx, posy);
						add_Mall_agent_internal(current_Mall_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Mall_agent(id, region_id, current_stock, firm_revenues, total_supply, range, posx, posy);
								add_Mall_agent_internal(current_Mall_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Mall_agent(id, region_id, current_stock, firm_revenues, total_supply, range, posx, posy);
								add_Mall_agent_internal(current_Mall_agent);

								current_Mall_agent->posx = xcentre;
								current_Mall_agent->posy = ycentre;
								current_Mall_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "IGFirm") == 0)
				{
					posx = current_IGFirm_agent->posx;
					posy = current_IGFirm_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_IGFirm_agent(id, region_id, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, day_of_month_to_act, range, posx, posy);
						add_IGFirm_agent_internal(current_IGFirm_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_IGFirm_agent(id, region_id, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, day_of_month_to_act, range, posx, posy);
								add_IGFirm_agent_internal(current_IGFirm_agent);
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

								p_xmachine = &(current_node->agents);
								//add_IGFirm_agent(id, region_id, productivity, innovation_probability, productivity_progress, capital_good_price, revenue_per_day, day_of_month_to_act, range, posx, posy);
								add_IGFirm_agent_internal(current_IGFirm_agent);

								current_IGFirm_agent->posx = xcentre;
								current_IGFirm_agent->posy = ycentre;
								current_IGFirm_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Market_Research") == 0)
				{
					posx = current_Market_Research_agent->posx;
					posy = current_Market_Research_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Market_Research_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, range, posx, posy);
						add_Market_Research_agent_internal(current_Market_Research_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Market_Research_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, range, posx, posy);
								add_Market_Research_agent_internal(current_Market_Research_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Market_Research_agent(id, region_id, no_regions, num_households, no_households_skill_1, no_households_skill_2, no_households_skill_3, no_households_skill_4, no_households_skill_5, employed, employed_skill_1, employed_skill_2, employed_skill_3, employed_skill_4, employed_skill_5, unemployed, unemployment_rate, unemployment_rate_skill_1, unemployment_rate_skill_2, unemployment_rate_skill_3, unemployment_rate_skill_4, unemployment_rate_skill_5, average_wage, average_wage_skill_1, average_wage_skill_2, average_wage_skill_3, average_wage_skill_4, average_wage_skill_5, average_s_skill, average_s_skill_1, average_s_skill_2, average_s_skill_3, average_s_skill_4, average_s_skill_5, no_firms, no_vacancies, no_employees, no_employees_skill_1, no_employees_skill_2, no_employees_skill_3, no_employees_skill_4, no_employees_skill_5, firm_average_wage, firm_average_wage_skill_1, firm_average_wage_skill_2, firm_average_wage_skill_3, firm_average_wage_skill_4, firm_average_wage_skill_5, firm_average_s_skill, firm_average_s_skill_1, firm_average_s_skill_2, firm_average_s_skill_3, firm_average_s_skill_4, firm_average_s_skill_5, region_firm_data, region_household_data, day_of_month_to_act, range, posx, posy);
								add_Market_Research_agent_internal(current_Market_Research_agent);

								current_Market_Research_agent->posx = xcentre;
								current_Market_Research_agent->posy = ycentre;
								current_Market_Research_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Clearinghouse") == 0)
				{
					posx = current_Clearinghouse_agent->posx;
					posy = current_Clearinghouse_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Clearinghouse_agent(id, trader_id, stock_id, bond_id, gov_bond_id, limit_price, limit_quantity, range, posx, posy);
						add_Clearinghouse_agent_internal(current_Clearinghouse_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Clearinghouse_agent(id, trader_id, stock_id, bond_id, gov_bond_id, limit_price, limit_quantity, range, posx, posy);
								add_Clearinghouse_agent_internal(current_Clearinghouse_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Clearinghouse_agent(id, trader_id, stock_id, bond_id, gov_bond_id, limit_price, limit_quantity, range, posx, posy);
								add_Clearinghouse_agent_internal(current_Clearinghouse_agent);

								current_Clearinghouse_agent->posx = xcentre;
								current_Clearinghouse_agent->posy = ycentre;
								current_Clearinghouse_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Bank") == 0)
				{
					posx = current_Bank_agent->posx;
					posy = current_Bank_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Bank_agent(id, proposed_interest_rate, amount_credit_offer, range, posx, posy);
						add_Bank_agent_internal(current_Bank_agent);
						
						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz ;
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
								p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, proposed_interest_rate, amount_credit_offer, range, posx, posy);
								add_Bank_agent_internal(current_Bank_agent);
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

								p_xmachine = &(current_node->agents);
								//add_Bank_agent(id, proposed_interest_rate, amount_credit_offer, range, posx, posy);
								add_Bank_agent_internal(current_Bank_agent);

								current_Bank_agent->posx = xcentre;
								current_Bank_agent->posy = ycentre;
								current_Bank_agent->range = rrange;

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
//				wage_update_was_made = 0;
//				share_net_investments = 0.0;
//				mean_wage = 0.0;
//				needed_capital_stock = 0.0;
//				actual_cap_price = 0.0;
//				mean_specific_skills = 0.0;
//				planned_production_quantity = 0.0;
//				production_quantity = 0.0;
//				unit_costs = 0.0;
//				planned_production_costs = 0.0;
//				production_costs = 0.0;
//				revenue_per_day = 0.0;
//				technological_frontier = 0.0;
//				cum_revenue = 0.0;
//				out_of_stock_costs = 0.0;
////				quality = 0.0;
//				price = 0.0;
//				price_last_month = 0.0;
////				total_units_capital_stock = 0.0;
//				total_value_capital_stock = 0.0;
//				total_capital_depreciation_value = 0.0;
//				total_capital_depreciation_units = 0.0;
//				employees_needed = 0;
////				total_sold_quantity = 0.0;
//				cum_total_sold_quantity = 0.0;
////////				demand_capital_stock = 0.0;
////				day_of_month_to_act = 0;
//				gov_id = 0;
//				bank_id = 0;
//				ebit = 0.0;
//				payment_account = 0.0;
//				earnings = 0.0;
//				tax_rate_corporate = 0.0;
//				tax_payment = 0.0;
//				net_earnings = 0.0;
//				previous_net_earnings = 0.0;
////				total_interest_payment = 0.0;
//				total_debt_installment_payment = 0.0;
//				total_debt = 0.0;
//				total_dividend_payment = 0.0;
//				total_value_local_inventory = 0.0;
//				total_assets = 0.0;
//				planned_cum_revenue = 0.0;
//				planned_total_interest_payment = 0.0;
//				planned_total_debt_installment_payment = 0.0;
//				planned_total_dividend_payment = 0.0;
//				direct_financial_needs = 0.0;
//				delayed_financial_needs = 0.0;
//				total_financial_needs = 0.0;
//				internal_financial_needs = 0.0;
//				external_financial_needs = 0.0;
//				total_external_financing_obtained = 0.0;
//				direct_financial_needs_require_external_financing = 0;
//				delayed_financial_needs_require_external_financing = 0;
//				current_share_price = 0.0;
//				current_shares_outstanding = 0.0;
//				previous_dividend_per_share = 0.0;
//				current_dividend_per_share = 0.0;
//				previous_dividend_per_earnings = 0.0;
//				current_dividend_per_earnings = 0.0;
//				earnings_per_share_ratio = 0.0;
//				debt_earnings_ratio = 0.0;
//				price_earnings_ratio = 0.0;
//				retained_earnings_ratio = 0.0;
//				earnings_per_share_ratio_growth = 0.0;
//				critical_price_earnings_ratio = 0.0;
//				critical_earnings_per_share_ratio = 0.0;
//				target_loans = 0.0;
//				target_equity = 0.0;
//				bonds_issue_target = 0.0;
//				stocks_issue_target = 0.0;
//				range = 0.0;
//				posx = 0.0;
//				posy = 0.0;
////				wage = 0.0;
//				wage_reservation = 0.0;
//				general_skill = 0;
//				on_the_job_search = 0;
//				number_applications = 0;
//				specific_skill = 0.0;
//				employee_firm_id = 0;
//				employer_region_id = 0;
//				budget = 0.0;
//				week_of_month = 0;
//				weekly_budget = 0.0;
//				expenditures = 0.0;
//				received_dividend_cap = 0.0;
//				received_dividend_cons = 0.0;
//				savings = 0.0;
////				rationed = 0;
//				mall_completely_sold_out = 0;
//////				day_of_week_to_act = 0;
//////				total_supply = 0.0;
//				productivity = 0.0;
//				innovation_probability = 0;
//				productivity_progress = 0.0;
//				capital_good_price = 0.0;
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
//////				trader_id = 0;
//				stock_id = 0;
//				bond_id = 0;
//				gov_bond_id = 0;
//				limit_price = 0.0;
//				limit_quantity = 0.0;
//				proposed_interest_rate = 0.0;
//				amount_credit_offer = 0.0;

	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "region_id") == 0) in_region_id = 1;
			if(strcmp(buffer, "/region_id") == 0) in_region_id = 0;
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
			if(strcmp(buffer, "wage_update_was_made") == 0) in_wage_update_was_made = 1;
			if(strcmp(buffer, "/wage_update_was_made") == 0) in_wage_update_was_made = 0;
			if(strcmp(buffer, "share_net_investments") == 0) in_share_net_investments = 1;
			if(strcmp(buffer, "/share_net_investments") == 0) in_share_net_investments = 0;
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
			if(strcmp(buffer, "unit_costs") == 0) in_unit_costs = 1;
			if(strcmp(buffer, "/unit_costs") == 0) in_unit_costs = 0;
			if(strcmp(buffer, "planned_production_costs") == 0) in_planned_production_costs = 1;
			if(strcmp(buffer, "/planned_production_costs") == 0) in_planned_production_costs = 0;
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
			if(strcmp(buffer, "employees_needed") == 0) in_employees_needed = 1;
			if(strcmp(buffer, "/employees_needed") == 0) in_employees_needed = 0;
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
			if(strcmp(buffer, "demand_capital_stock") == 0) in_demand_capital_stock = 1;
			if(strcmp(buffer, "/demand_capital_stock") == 0) in_demand_capital_stock = 0;
			if(strcmp(buffer, "last_planned_production_quantities") == 0) in_last_planned_production_quantities = 1;
			if(strcmp(buffer, "/last_planned_production_quantities") == 0) in_last_planned_production_quantities = 0;
			if(strcmp(buffer, "day_of_month_to_act") == 0) in_day_of_month_to_act = 1;
			if(strcmp(buffer, "/day_of_month_to_act") == 0) in_day_of_month_to_act = 0;
			if(strcmp(buffer, "gov_id") == 0) in_gov_id = 1;
			if(strcmp(buffer, "/gov_id") == 0) in_gov_id = 0;
			if(strcmp(buffer, "bank_id") == 0) in_bank_id = 1;
			if(strcmp(buffer, "/bank_id") == 0) in_bank_id = 0;
			if(strcmp(buffer, "ebit") == 0) in_ebit = 1;
			if(strcmp(buffer, "/ebit") == 0) in_ebit = 0;
			if(strcmp(buffer, "payment_account") == 0) in_payment_account = 1;
			if(strcmp(buffer, "/payment_account") == 0) in_payment_account = 0;
			if(strcmp(buffer, "earnings") == 0) in_earnings = 1;
			if(strcmp(buffer, "/earnings") == 0) in_earnings = 0;
			if(strcmp(buffer, "tax_rate_corporate") == 0) in_tax_rate_corporate = 1;
			if(strcmp(buffer, "/tax_rate_corporate") == 0) in_tax_rate_corporate = 0;
			if(strcmp(buffer, "tax_payment") == 0) in_tax_payment = 1;
			if(strcmp(buffer, "/tax_payment") == 0) in_tax_payment = 0;
			if(strcmp(buffer, "net_earnings") == 0) in_net_earnings = 1;
			if(strcmp(buffer, "/net_earnings") == 0) in_net_earnings = 0;
			if(strcmp(buffer, "previous_net_earnings") == 0) in_previous_net_earnings = 1;
			if(strcmp(buffer, "/previous_net_earnings") == 0) in_previous_net_earnings = 0;
			if(strcmp(buffer, "loans") == 0) in_loans = 1;
			if(strcmp(buffer, "/loans") == 0) in_loans = 0;
			if(strcmp(buffer, "total_interest_payment") == 0) in_total_interest_payment = 1;
			if(strcmp(buffer, "/total_interest_payment") == 0) in_total_interest_payment = 0;
			if(strcmp(buffer, "total_debt_installment_payment") == 0) in_total_debt_installment_payment = 1;
			if(strcmp(buffer, "/total_debt_installment_payment") == 0) in_total_debt_installment_payment = 0;
			if(strcmp(buffer, "total_debt") == 0) in_total_debt = 1;
			if(strcmp(buffer, "/total_debt") == 0) in_total_debt = 0;
			if(strcmp(buffer, "total_dividend_payment") == 0) in_total_dividend_payment = 1;
			if(strcmp(buffer, "/total_dividend_payment") == 0) in_total_dividend_payment = 0;
			if(strcmp(buffer, "total_value_local_inventory") == 0) in_total_value_local_inventory = 1;
			if(strcmp(buffer, "/total_value_local_inventory") == 0) in_total_value_local_inventory = 0;
			if(strcmp(buffer, "total_assets") == 0) in_total_assets = 1;
			if(strcmp(buffer, "/total_assets") == 0) in_total_assets = 0;
			if(strcmp(buffer, "planned_cum_revenue") == 0) in_planned_cum_revenue = 1;
			if(strcmp(buffer, "/planned_cum_revenue") == 0) in_planned_cum_revenue = 0;
			if(strcmp(buffer, "planned_total_interest_payment") == 0) in_planned_total_interest_payment = 1;
			if(strcmp(buffer, "/planned_total_interest_payment") == 0) in_planned_total_interest_payment = 0;
			if(strcmp(buffer, "planned_total_debt_installment_payment") == 0) in_planned_total_debt_installment_payment = 1;
			if(strcmp(buffer, "/planned_total_debt_installment_payment") == 0) in_planned_total_debt_installment_payment = 0;
			if(strcmp(buffer, "planned_total_dividend_payment") == 0) in_planned_total_dividend_payment = 1;
			if(strcmp(buffer, "/planned_total_dividend_payment") == 0) in_planned_total_dividend_payment = 0;
			if(strcmp(buffer, "direct_financial_needs") == 0) in_direct_financial_needs = 1;
			if(strcmp(buffer, "/direct_financial_needs") == 0) in_direct_financial_needs = 0;
			if(strcmp(buffer, "delayed_financial_needs") == 0) in_delayed_financial_needs = 1;
			if(strcmp(buffer, "/delayed_financial_needs") == 0) in_delayed_financial_needs = 0;
			if(strcmp(buffer, "total_financial_needs") == 0) in_total_financial_needs = 1;
			if(strcmp(buffer, "/total_financial_needs") == 0) in_total_financial_needs = 0;
			if(strcmp(buffer, "internal_financial_needs") == 0) in_internal_financial_needs = 1;
			if(strcmp(buffer, "/internal_financial_needs") == 0) in_internal_financial_needs = 0;
			if(strcmp(buffer, "external_financial_needs") == 0) in_external_financial_needs = 1;
			if(strcmp(buffer, "/external_financial_needs") == 0) in_external_financial_needs = 0;
			if(strcmp(buffer, "total_external_financing_obtained") == 0) in_total_external_financing_obtained = 1;
			if(strcmp(buffer, "/total_external_financing_obtained") == 0) in_total_external_financing_obtained = 0;
			if(strcmp(buffer, "direct_financial_needs_require_external_financing") == 0) in_direct_financial_needs_require_external_financing = 1;
			if(strcmp(buffer, "/direct_financial_needs_require_external_financing") == 0) in_direct_financial_needs_require_external_financing = 0;
			if(strcmp(buffer, "delayed_financial_needs_require_external_financing") == 0) in_delayed_financial_needs_require_external_financing = 1;
			if(strcmp(buffer, "/delayed_financial_needs_require_external_financing") == 0) in_delayed_financial_needs_require_external_financing = 0;
			if(strcmp(buffer, "current_share_price") == 0) in_current_share_price = 1;
			if(strcmp(buffer, "/current_share_price") == 0) in_current_share_price = 0;
			if(strcmp(buffer, "current_shares_outstanding") == 0) in_current_shares_outstanding = 1;
			if(strcmp(buffer, "/current_shares_outstanding") == 0) in_current_shares_outstanding = 0;
			if(strcmp(buffer, "previous_dividend_per_share") == 0) in_previous_dividend_per_share = 1;
			if(strcmp(buffer, "/previous_dividend_per_share") == 0) in_previous_dividend_per_share = 0;
			if(strcmp(buffer, "current_dividend_per_share") == 0) in_current_dividend_per_share = 1;
			if(strcmp(buffer, "/current_dividend_per_share") == 0) in_current_dividend_per_share = 0;
			if(strcmp(buffer, "previous_dividend_per_earnings") == 0) in_previous_dividend_per_earnings = 1;
			if(strcmp(buffer, "/previous_dividend_per_earnings") == 0) in_previous_dividend_per_earnings = 0;
			if(strcmp(buffer, "current_dividend_per_earnings") == 0) in_current_dividend_per_earnings = 1;
			if(strcmp(buffer, "/current_dividend_per_earnings") == 0) in_current_dividend_per_earnings = 0;
			if(strcmp(buffer, "earnings_per_share_ratio") == 0) in_earnings_per_share_ratio = 1;
			if(strcmp(buffer, "/earnings_per_share_ratio") == 0) in_earnings_per_share_ratio = 0;
			if(strcmp(buffer, "debt_earnings_ratio") == 0) in_debt_earnings_ratio = 1;
			if(strcmp(buffer, "/debt_earnings_ratio") == 0) in_debt_earnings_ratio = 0;
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
			if(strcmp(buffer, "target_loans") == 0) in_target_loans = 1;
			if(strcmp(buffer, "/target_loans") == 0) in_target_loans = 0;
			if(strcmp(buffer, "target_equity") == 0) in_target_equity = 1;
			if(strcmp(buffer, "/target_equity") == 0) in_target_equity = 0;
			if(strcmp(buffer, "bonds_issue_target") == 0) in_bonds_issue_target = 1;
			if(strcmp(buffer, "/bonds_issue_target") == 0) in_bonds_issue_target = 0;
			if(strcmp(buffer, "stocks_issue_target") == 0) in_stocks_issue_target = 1;
			if(strcmp(buffer, "/stocks_issue_target") == 0) in_stocks_issue_target = 0;
			if(strcmp(buffer, "range") == 0) in_range = 1;
			if(strcmp(buffer, "/range") == 0) in_range = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "neighboring_region_ids") == 0) in_neighboring_region_ids = 1;
			if(strcmp(buffer, "/neighboring_region_ids") == 0) in_neighboring_region_ids = 0;
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
			if(strcmp(buffer, "budget") == 0) in_budget = 1;
			if(strcmp(buffer, "/budget") == 0) in_budget = 0;
			if(strcmp(buffer, "week_of_month") == 0) in_week_of_month = 1;
			if(strcmp(buffer, "/week_of_month") == 0) in_week_of_month = 0;
			if(strcmp(buffer, "weekly_budget") == 0) in_weekly_budget = 1;
			if(strcmp(buffer, "/weekly_budget") == 0) in_weekly_budget = 0;
			if(strcmp(buffer, "expenditures") == 0) in_expenditures = 1;
			if(strcmp(buffer, "/expenditures") == 0) in_expenditures = 0;
			if(strcmp(buffer, "received_dividend_cap") == 0) in_received_dividend_cap = 1;
			if(strcmp(buffer, "/received_dividend_cap") == 0) in_received_dividend_cap = 0;
			if(strcmp(buffer, "received_dividend_cons") == 0) in_received_dividend_cons = 1;
			if(strcmp(buffer, "/received_dividend_cons") == 0) in_received_dividend_cons = 0;
			if(strcmp(buffer, "savings") == 0) in_savings = 1;
			if(strcmp(buffer, "/savings") == 0) in_savings = 0;
			if(strcmp(buffer, "last_income") == 0) in_last_income = 1;
			if(strcmp(buffer, "/last_income") == 0) in_last_income = 0;
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
			if(strcmp(buffer, "trader_id") == 0) in_trader_id = 1;
			if(strcmp(buffer, "/trader_id") == 0) in_trader_id = 0;
			if(strcmp(buffer, "stock_id") == 0) in_stock_id = 1;
			if(strcmp(buffer, "/stock_id") == 0) in_stock_id = 0;
			if(strcmp(buffer, "bond_id") == 0) in_bond_id = 1;
			if(strcmp(buffer, "/bond_id") == 0) in_bond_id = 0;
			if(strcmp(buffer, "gov_bond_id") == 0) in_gov_bond_id = 1;
			if(strcmp(buffer, "/gov_bond_id") == 0) in_gov_bond_id = 0;
			if(strcmp(buffer, "limit_price") == 0) in_limit_price = 1;
			if(strcmp(buffer, "/limit_price") == 0) in_limit_price = 0;
			if(strcmp(buffer, "limit_quantity") == 0) in_limit_quantity = 1;
			if(strcmp(buffer, "/limit_quantity") == 0) in_limit_quantity = 0;
			if(strcmp(buffer, "proposed_interest_rate") == 0) in_proposed_interest_rate = 1;
			if(strcmp(buffer, "/proposed_interest_rate") == 0) in_proposed_interest_rate = 0;
			if(strcmp(buffer, "amount_credit_offer") == 0) in_amount_credit_offer = 1;
			if(strcmp(buffer, "/amount_credit_offer") == 0) in_amount_credit_offer = 0;


			
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
			if(in_name) strcpy(agentname, buffer);
			if(in_environment)
			{
			}
			else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_region_id) current_Firm_agent->region_id = atoi(buffer);
				if(in_employees)
				{
					j = 0;
					read_employee_dynamic_array(buffer, &j, &current_Firm_agent->employees);
				}
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
				if(in_wage_update_was_made) current_Firm_agent->wage_update_was_made = atoi(buffer);
				if(in_share_net_investments) current_Firm_agent->share_net_investments = atof(buffer);
				if(in_mean_wage) current_Firm_agent->mean_wage = atof(buffer);
				if(in_needed_capital_stock) current_Firm_agent->needed_capital_stock = atof(buffer);
				if(in_actual_cap_price) current_Firm_agent->actual_cap_price = atof(buffer);
				if(in_mean_specific_skills) current_Firm_agent->mean_specific_skills = atof(buffer);
				if(in_planned_production_quantity) current_Firm_agent->planned_production_quantity = atof(buffer);
				if(in_production_quantity) current_Firm_agent->production_quantity = atof(buffer);
				if(in_unit_costs) current_Firm_agent->unit_costs = atof(buffer);
				if(in_planned_production_costs) current_Firm_agent->planned_production_costs = atof(buffer);
				if(in_production_costs) current_Firm_agent->production_costs = atof(buffer);
				if(in_revenue_per_day) current_Firm_agent->revenue_per_day = atof(buffer);
				if(in_technological_frontier) current_Firm_agent->technological_frontier = atof(buffer);
				if(in_cum_revenue) current_Firm_agent->cum_revenue = atof(buffer);
				if(in_out_of_stock_costs) current_Firm_agent->out_of_stock_costs = atof(buffer);
				if(in_malls_sales_statistics)
				{
					j = 0;
					read_sales_statistics_dynamic_array(buffer, &j, &current_Firm_agent->malls_sales_statistics);
				}
				if(in_quality) current_Firm_agent->quality = atof(buffer);
				if(in_price) current_Firm_agent->price = atof(buffer);
				if(in_price_last_month) current_Firm_agent->price_last_month = atof(buffer);
				if(in_capital_stock)
				{
					j = 0;
					read_capital_stock_item_dynamic_array(buffer, &j, &current_Firm_agent->capital_stock);
				}
				if(in_total_units_capital_stock) current_Firm_agent->total_units_capital_stock = atof(buffer);
				if(in_total_value_capital_stock) current_Firm_agent->total_value_capital_stock = atof(buffer);
				if(in_total_capital_depreciation_value) current_Firm_agent->total_capital_depreciation_value = atof(buffer);
				if(in_total_capital_depreciation_units) current_Firm_agent->total_capital_depreciation_units = atof(buffer);
				if(in_employees_needed) current_Firm_agent->employees_needed = atoi(buffer);
				if(in_sold_quantities)
				{
					j = 0;
					read_sold_quantities_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->sold_quantities);
				}
				if(in_total_sold_quantity) current_Firm_agent->total_sold_quantity = atof(buffer);
				if(in_cum_total_sold_quantity) current_Firm_agent->cum_total_sold_quantity = atof(buffer);
				if(in_delivery_volume)
				{
					j = 0;
					read_delivery_volume_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->delivery_volume);
				}
				if(in_planned_delivery_volume)
				{
					j = 0;
					read_delivery_volume_per_mall_dynamic_array(buffer, &j, &current_Firm_agent->planned_delivery_volume);
				}
				if(in_current_mall_stocks)
				{
					j = 0;
					read_mall_info_dynamic_array(buffer, &j, &current_Firm_agent->current_mall_stocks);
				}
				if(in_demand_capital_stock) current_Firm_agent->demand_capital_stock = atof(buffer);
				if(in_last_planned_production_quantities)
				{
					j = 0;
					read_double_dynamic_array(buffer, &j, &current_Firm_agent->last_planned_production_quantities);
				}
				if(in_day_of_month_to_act) current_Firm_agent->day_of_month_to_act = atoi(buffer);
				if(in_gov_id) current_Firm_agent->gov_id = atoi(buffer);
				if(in_bank_id) current_Firm_agent->bank_id = atoi(buffer);
				if(in_ebit) current_Firm_agent->ebit = atof(buffer);
				if(in_payment_account) current_Firm_agent->payment_account = atof(buffer);
				if(in_earnings) current_Firm_agent->earnings = atof(buffer);
				if(in_tax_rate_corporate) current_Firm_agent->tax_rate_corporate = atof(buffer);
				if(in_tax_payment) current_Firm_agent->tax_payment = atof(buffer);
				if(in_net_earnings) current_Firm_agent->net_earnings = atof(buffer);
				if(in_previous_net_earnings) current_Firm_agent->previous_net_earnings = atof(buffer);
				if(in_loans)
				{
					j = 0;
					read_debt_item_dynamic_array(buffer, &j, &current_Firm_agent->loans);
				}
				if(in_total_interest_payment) current_Firm_agent->total_interest_payment = atof(buffer);
				if(in_total_debt_installment_payment) current_Firm_agent->total_debt_installment_payment = atof(buffer);
				if(in_total_debt) current_Firm_agent->total_debt = atof(buffer);
				if(in_total_dividend_payment) current_Firm_agent->total_dividend_payment = atof(buffer);
				if(in_total_value_local_inventory) current_Firm_agent->total_value_local_inventory = atof(buffer);
				if(in_total_assets) current_Firm_agent->total_assets = atof(buffer);
				if(in_planned_cum_revenue) current_Firm_agent->planned_cum_revenue = atof(buffer);
				if(in_planned_total_interest_payment) current_Firm_agent->planned_total_interest_payment = atof(buffer);
				if(in_planned_total_debt_installment_payment) current_Firm_agent->planned_total_debt_installment_payment = atof(buffer);
				if(in_planned_total_dividend_payment) current_Firm_agent->planned_total_dividend_payment = atof(buffer);
				if(in_direct_financial_needs) current_Firm_agent->direct_financial_needs = atof(buffer);
				if(in_delayed_financial_needs) current_Firm_agent->delayed_financial_needs = atof(buffer);
				if(in_total_financial_needs) current_Firm_agent->total_financial_needs = atof(buffer);
				if(in_internal_financial_needs) current_Firm_agent->internal_financial_needs = atof(buffer);
				if(in_external_financial_needs) current_Firm_agent->external_financial_needs = atof(buffer);
				if(in_total_external_financing_obtained) current_Firm_agent->total_external_financing_obtained = atof(buffer);
				if(in_direct_financial_needs_require_external_financing) current_Firm_agent->direct_financial_needs_require_external_financing = atoi(buffer);
				if(in_delayed_financial_needs_require_external_financing) current_Firm_agent->delayed_financial_needs_require_external_financing = atoi(buffer);
				if(in_current_share_price) current_Firm_agent->current_share_price = atof(buffer);
				if(in_current_shares_outstanding) current_Firm_agent->current_shares_outstanding = atof(buffer);
				if(in_previous_dividend_per_share) current_Firm_agent->previous_dividend_per_share = atof(buffer);
				if(in_current_dividend_per_share) current_Firm_agent->current_dividend_per_share = atof(buffer);
				if(in_previous_dividend_per_earnings) current_Firm_agent->previous_dividend_per_earnings = atof(buffer);
				if(in_current_dividend_per_earnings) current_Firm_agent->current_dividend_per_earnings = atof(buffer);
				if(in_earnings_per_share_ratio) current_Firm_agent->earnings_per_share_ratio = atof(buffer);
				if(in_debt_earnings_ratio) current_Firm_agent->debt_earnings_ratio = atof(buffer);
				if(in_price_earnings_ratio) current_Firm_agent->price_earnings_ratio = atof(buffer);
				if(in_retained_earnings_ratio) current_Firm_agent->retained_earnings_ratio = atof(buffer);
				if(in_earnings_per_share_ratio_growth) current_Firm_agent->earnings_per_share_ratio_growth = atof(buffer);
				if(in_critical_price_earnings_ratio) current_Firm_agent->critical_price_earnings_ratio = atof(buffer);
				if(in_critical_earnings_per_share_ratio) current_Firm_agent->critical_earnings_per_share_ratio = atof(buffer);
				if(in_target_loans) current_Firm_agent->target_loans = atof(buffer);
				if(in_target_equity) current_Firm_agent->target_equity = atof(buffer);
				if(in_bonds_issue_target) current_Firm_agent->bonds_issue_target = atof(buffer);
				if(in_stocks_issue_target) current_Firm_agent->stocks_issue_target = atof(buffer);
				if(in_range) current_Firm_agent->range = atof(buffer);
				if(in_posx) current_Firm_agent->posx = atof(buffer);
				if(in_posy) current_Firm_agent->posy = atof(buffer);
			}else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_region_id) current_Household_agent->region_id = atoi(buffer);
				if(in_neighboring_region_ids)
				{
					j = 0;
					read_int_dynamic_array(buffer, &j, &current_Household_agent->neighboring_region_ids);
				}
				if(in_wage) current_Household_agent->wage = atof(buffer);
				if(in_wage_reservation) current_Household_agent->wage_reservation = atof(buffer);
				if(in_general_skill) current_Household_agent->general_skill = atoi(buffer);
				if(in_on_the_job_search) current_Household_agent->on_the_job_search = atoi(buffer);
				if(in_number_applications) current_Household_agent->number_applications = atoi(buffer);
				if(in_specific_skill) current_Household_agent->specific_skill = atof(buffer);
				if(in_employee_firm_id) current_Household_agent->employee_firm_id = atoi(buffer);
				if(in_employer_region_id) current_Household_agent->employer_region_id = atoi(buffer);
				if(in_budget) current_Household_agent->budget = atof(buffer);
				if(in_week_of_month) current_Household_agent->week_of_month = atoi(buffer);
				if(in_weekly_budget) current_Household_agent->weekly_budget = atof(buffer);
				if(in_expenditures) current_Household_agent->expenditures = atof(buffer);
				if(in_received_dividend_cap) current_Household_agent->received_dividend_cap = atof(buffer);
				if(in_received_dividend_cons) current_Household_agent->received_dividend_cons = atof(buffer);
				if(in_savings) current_Household_agent->savings = atof(buffer);
				if(in_last_income)
				{
					j = 0;
					read_double_dynamic_array(buffer, &j, &current_Household_agent->last_income);
				}
				if(in_rationed) current_Household_agent->rationed = atoi(buffer);
				if(in_mall_completely_sold_out) current_Household_agent->mall_completely_sold_out = atoi(buffer);
				if(in_order_quantity)
				{
					j = 0;
					read_ordered_quantity_static_array(buffer, &j, current_Household_agent->order_quantity, 2);
				}
				if(in_received_quantity)
				{
					j = 0;
					read_received_quantities_static_array(buffer, &j, current_Household_agent->received_quantity, 2);
				}
				if(in_day_of_month_to_act) current_Household_agent->day_of_month_to_act = atoi(buffer);
				if(in_day_of_week_to_act) current_Household_agent->day_of_week_to_act = atoi(buffer);
				if(in_range) current_Household_agent->range = atof(buffer);
				if(in_posx) current_Household_agent->posx = atof(buffer);
				if(in_posy) current_Household_agent->posy = atof(buffer);
			}else if(in_Mall_agent == 1)
			{
				if(in_id) current_Mall_agent->id = atoi(buffer);
				if(in_region_id) current_Mall_agent->region_id = atoi(buffer);
				if(in_current_stock)
				{
					j = 0;
					read_mall_stock_dynamic_array(buffer, &j, &current_Mall_agent->current_stock);
				}
				if(in_firm_revenues)
				{
					j = 0;
					read_sales_in_mall_dynamic_array(buffer, &j, &current_Mall_agent->firm_revenues);
				}
				if(in_total_supply) current_Mall_agent->total_supply = atof(buffer);
				if(in_range) current_Mall_agent->range = atof(buffer);
				if(in_posx) current_Mall_agent->posx = atof(buffer);
				if(in_posy) current_Mall_agent->posy = atof(buffer);
			}else if(in_IGFirm_agent == 1)
			{
				if(in_id) current_IGFirm_agent->id = atoi(buffer);
				if(in_region_id) current_IGFirm_agent->region_id = atoi(buffer);
				if(in_productivity) current_IGFirm_agent->productivity = atof(buffer);
				if(in_innovation_probability) current_IGFirm_agent->innovation_probability = atoi(buffer);
				if(in_productivity_progress) current_IGFirm_agent->productivity_progress = atof(buffer);
				if(in_capital_good_price) current_IGFirm_agent->capital_good_price = atof(buffer);
				if(in_revenue_per_day) current_IGFirm_agent->revenue_per_day = atof(buffer);
				if(in_day_of_month_to_act) current_IGFirm_agent->day_of_month_to_act = atoi(buffer);
				if(in_range) current_IGFirm_agent->range = atof(buffer);
				if(in_posx) current_IGFirm_agent->posx = atof(buffer);
				if(in_posy) current_IGFirm_agent->posy = atof(buffer);
			}else if(in_Market_Research_agent == 1)
			{
				if(in_id) current_Market_Research_agent->id = atoi(buffer);
				if(in_region_id) current_Market_Research_agent->region_id = atoi(buffer);
				if(in_no_regions) current_Market_Research_agent->no_regions = atoi(buffer);
				if(in_num_households) current_Market_Research_agent->num_households = atoi(buffer);
				if(in_no_households_skill_1) current_Market_Research_agent->no_households_skill_1 = atoi(buffer);
				if(in_no_households_skill_2) current_Market_Research_agent->no_households_skill_2 = atoi(buffer);
				if(in_no_households_skill_3) current_Market_Research_agent->no_households_skill_3 = atoi(buffer);
				if(in_no_households_skill_4) current_Market_Research_agent->no_households_skill_4 = atoi(buffer);
				if(in_no_households_skill_5) current_Market_Research_agent->no_households_skill_5 = atoi(buffer);
				if(in_employed) current_Market_Research_agent->employed = atoi(buffer);
				if(in_employed_skill_1) current_Market_Research_agent->employed_skill_1 = atoi(buffer);
				if(in_employed_skill_2) current_Market_Research_agent->employed_skill_2 = atoi(buffer);
				if(in_employed_skill_3) current_Market_Research_agent->employed_skill_3 = atoi(buffer);
				if(in_employed_skill_4) current_Market_Research_agent->employed_skill_4 = atoi(buffer);
				if(in_employed_skill_5) current_Market_Research_agent->employed_skill_5 = atoi(buffer);
				if(in_unemployed) current_Market_Research_agent->unemployed = atoi(buffer);
				if(in_unemployment_rate) current_Market_Research_agent->unemployment_rate = atof(buffer);
				if(in_unemployment_rate_skill_1) current_Market_Research_agent->unemployment_rate_skill_1 = atof(buffer);
				if(in_unemployment_rate_skill_2) current_Market_Research_agent->unemployment_rate_skill_2 = atof(buffer);
				if(in_unemployment_rate_skill_3) current_Market_Research_agent->unemployment_rate_skill_3 = atof(buffer);
				if(in_unemployment_rate_skill_4) current_Market_Research_agent->unemployment_rate_skill_4 = atof(buffer);
				if(in_unemployment_rate_skill_5) current_Market_Research_agent->unemployment_rate_skill_5 = atof(buffer);
				if(in_average_wage) current_Market_Research_agent->average_wage = atof(buffer);
				if(in_average_wage_skill_1) current_Market_Research_agent->average_wage_skill_1 = atof(buffer);
				if(in_average_wage_skill_2) current_Market_Research_agent->average_wage_skill_2 = atof(buffer);
				if(in_average_wage_skill_3) current_Market_Research_agent->average_wage_skill_3 = atof(buffer);
				if(in_average_wage_skill_4) current_Market_Research_agent->average_wage_skill_4 = atof(buffer);
				if(in_average_wage_skill_5) current_Market_Research_agent->average_wage_skill_5 = atof(buffer);
				if(in_average_s_skill) current_Market_Research_agent->average_s_skill = atof(buffer);
				if(in_average_s_skill_1) current_Market_Research_agent->average_s_skill_1 = atof(buffer);
				if(in_average_s_skill_2) current_Market_Research_agent->average_s_skill_2 = atof(buffer);
				if(in_average_s_skill_3) current_Market_Research_agent->average_s_skill_3 = atof(buffer);
				if(in_average_s_skill_4) current_Market_Research_agent->average_s_skill_4 = atof(buffer);
				if(in_average_s_skill_5) current_Market_Research_agent->average_s_skill_5 = atof(buffer);
				if(in_no_firms) current_Market_Research_agent->no_firms = atoi(buffer);
				if(in_no_vacancies) current_Market_Research_agent->no_vacancies = atoi(buffer);
				if(in_no_employees) current_Market_Research_agent->no_employees = atoi(buffer);
				if(in_no_employees_skill_1) current_Market_Research_agent->no_employees_skill_1 = atoi(buffer);
				if(in_no_employees_skill_2) current_Market_Research_agent->no_employees_skill_2 = atoi(buffer);
				if(in_no_employees_skill_3) current_Market_Research_agent->no_employees_skill_3 = atoi(buffer);
				if(in_no_employees_skill_4) current_Market_Research_agent->no_employees_skill_4 = atoi(buffer);
				if(in_no_employees_skill_5) current_Market_Research_agent->no_employees_skill_5 = atoi(buffer);
				if(in_firm_average_wage) current_Market_Research_agent->firm_average_wage = atof(buffer);
				if(in_firm_average_wage_skill_1) current_Market_Research_agent->firm_average_wage_skill_1 = atof(buffer);
				if(in_firm_average_wage_skill_2) current_Market_Research_agent->firm_average_wage_skill_2 = atof(buffer);
				if(in_firm_average_wage_skill_3) current_Market_Research_agent->firm_average_wage_skill_3 = atof(buffer);
				if(in_firm_average_wage_skill_4) current_Market_Research_agent->firm_average_wage_skill_4 = atof(buffer);
				if(in_firm_average_wage_skill_5) current_Market_Research_agent->firm_average_wage_skill_5 = atof(buffer);
				if(in_firm_average_s_skill) current_Market_Research_agent->firm_average_s_skill = atof(buffer);
				if(in_firm_average_s_skill_1) current_Market_Research_agent->firm_average_s_skill_1 = atof(buffer);
				if(in_firm_average_s_skill_2) current_Market_Research_agent->firm_average_s_skill_2 = atof(buffer);
				if(in_firm_average_s_skill_3) current_Market_Research_agent->firm_average_s_skill_3 = atof(buffer);
				if(in_firm_average_s_skill_4) current_Market_Research_agent->firm_average_s_skill_4 = atof(buffer);
				if(in_firm_average_s_skill_5) current_Market_Research_agent->firm_average_s_skill_5 = atof(buffer);
				if(in_region_firm_data)
				{
					j = 0;
					read_firm_data_dynamic_array(buffer, &j, &current_Market_Research_agent->region_firm_data);
				}
				if(in_region_household_data)
				{
					j = 0;
					read_household_data_dynamic_array(buffer, &j, &current_Market_Research_agent->region_household_data);
				}
				if(in_day_of_month_to_act) current_Market_Research_agent->day_of_month_to_act = atoi(buffer);
				if(in_range) current_Market_Research_agent->range = atof(buffer);
				if(in_posx) current_Market_Research_agent->posx = atof(buffer);
				if(in_posy) current_Market_Research_agent->posy = atof(buffer);
			}else if(in_Clearinghouse_agent == 1)
			{
				if(in_id) current_Clearinghouse_agent->id = atoi(buffer);
				if(in_trader_id) current_Clearinghouse_agent->trader_id = atoi(buffer);
				if(in_stock_id) current_Clearinghouse_agent->stock_id = atoi(buffer);
				if(in_bond_id) current_Clearinghouse_agent->bond_id = atoi(buffer);
				if(in_gov_bond_id) current_Clearinghouse_agent->gov_bond_id = atoi(buffer);
				if(in_limit_price) current_Clearinghouse_agent->limit_price = atof(buffer);
				if(in_limit_quantity) current_Clearinghouse_agent->limit_quantity = atof(buffer);
				if(in_range) current_Clearinghouse_agent->range = atof(buffer);
				if(in_posx) current_Clearinghouse_agent->posx = atof(buffer);
				if(in_posy) current_Clearinghouse_agent->posy = atof(buffer);
			}else if(in_Bank_agent == 1)
			{
				if(in_id) current_Bank_agent->id = atoi(buffer);
				if(in_proposed_interest_rate) current_Bank_agent->proposed_interest_rate = atof(buffer);
				if(in_amount_credit_offer) current_Bank_agent->amount_credit_offer = atof(buffer);
				if(in_range) current_Bank_agent->range = atof(buffer);
				if(in_posx) current_Bank_agent->posx = atof(buffer);
				if(in_posy) current_Bank_agent->posy = atof(buffer);
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
//////	free_employee_array(employees);
////////////////////////////////////////////////////////////////////////	free_sales_statistics_array(malls_sales_statistics);
////////	free_capital_stock_item_array(capital_stock);
////////////	free_sold_quantities_per_mall_array(sold_quantities);
//////	free_delivery_volume_per_mall_array(delivery_volume);
//	free_delivery_volume_per_mall_array(planned_delivery_volume);
//	free_mall_info_array(current_mall_stocks);
////	free_double_array(last_planned_production_quantities);
//////////////////////	free_debt_item_array(loans);
//////////////////////////////////////////////////////////////////////////////	free_int_array(neighboring_region_ids);
////////////////////////////////	free_double_array(last_income);
//////	free_ordered_quantity_static_array(order_quantity, 2);
//	free_received_quantities_static_array(received_quantity, 2);
////	free_mall_stock_array(current_stock);
//	free_sales_in_mall_array(firm_revenues);
////////////////////////////////////////////////////////////////////////////////////////////////////////	free_firm_data_array(region_firm_data);
//	free_household_data_array(region_household_data);
////////////////
}

/** \fn void saveiterationdata_binary(int iteration_number)
 * \brief Save X-machine memory to a binary file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata_binary(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	int i;
	int agentcount = 0;
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Household * current_Household;
	xmachine_memory_Mall * current_Mall;
	xmachine_memory_IGFirm * current_IGFirm;
	xmachine_memory_Market_Research * current_Market_Research;
	xmachine_memory_Clearinghouse * current_Clearinghouse;
	xmachine_memory_Bank * current_Bank;
	/*ordered_quantity * order_quantity;*/
	/*received_quantities * received_quantity;*/

	sprintf(data, "%s%i.binary", outputpath, iteration_number);
	file = fopen(data, "wb");
	/* iteration number*/
	fwrite(&iteration_number ,sizeof(int), 1, file);
	/* number of xagent memories written (update at end)*/
	fwrite(&i ,sizeof(int), 1, file);
	
	current_node = *p_node_info;
	while(current_node)
	{
	p_xmachine = &current_node->agents;
	current_xmachine = *p_xmachine;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Mall != NULL)
		{
			current_Mall = current_xmachine->xmachine_Mall;
			agentcount++;
		}
		else if(current_xmachine->xmachine_IGFirm != NULL)
		{
			current_IGFirm = current_xmachine->xmachine_IGFirm;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Market_Research != NULL)
		{
			current_Market_Research = current_xmachine->xmachine_Market_Research;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Clearinghouse != NULL)
		{
			current_Clearinghouse = current_xmachine->xmachine_Clearinghouse;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			agentcount++;
		}
		
		current_xmachine = current_xmachine->next;
	}
		current_node = current_node->next;
	}
	
	/* update agent count\n", file);*/
	fseek(file,sizeof(int)*1,SEEK_SET);
	fwrite(&agentcount,sizeof(int),1,file);
	
	/* Close the file */
	fclose(file);
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
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).interest_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).debt_installment_payment);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_periods_before_maturity);
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



/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Household * current_Household;
	xmachine_memory_Mall * current_Mall;
	xmachine_memory_IGFirm * current_IGFirm;
	xmachine_memory_Market_Research * current_Market_Research;
	xmachine_memory_Clearinghouse * current_Clearinghouse;
	xmachine_memory_Bank * current_Bank;
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


	current_node = *p_node_info;
	while(current_node)
	{
		p_xmachine = &current_node->agents;
		current_xmachine = *p_xmachine;
	while(current_xmachine)
	{
		fputs("<xagent>\n" , file);
		if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			fputs("<name>Firm</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Firm->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<region_id>", file);
			sprintf(data, "%i", current_Firm->region_id);
			fputs(data, file);
			fputs("</region_id>\n", file);
			fputs("<employees>", file);
			write_employee_dynamic_array(file, &current_Firm->employees);
			fputs("</employees>\n", file);
			fputs("<wage_offer>", file);
			sprintf(data, "%f", current_Firm->wage_offer);
			fputs(data, file);
			fputs("</wage_offer>\n", file);
			fputs("<technology>", file);
			sprintf(data, "%f", current_Firm->technology);
			fputs(data, file);
			fputs("</technology>\n", file);
			fputs("<no_employees>", file);
			sprintf(data, "%i", current_Firm->no_employees);
			fputs(data, file);
			fputs("</no_employees>\n", file);
			fputs("<no_employees_skill_1>", file);
			sprintf(data, "%i", current_Firm->no_employees_skill_1);
			fputs(data, file);
			fputs("</no_employees_skill_1>\n", file);
			fputs("<no_employees_skill_2>", file);
			sprintf(data, "%i", current_Firm->no_employees_skill_2);
			fputs(data, file);
			fputs("</no_employees_skill_2>\n", file);
			fputs("<no_employees_skill_3>", file);
			sprintf(data, "%i", current_Firm->no_employees_skill_3);
			fputs(data, file);
			fputs("</no_employees_skill_3>\n", file);
			fputs("<no_employees_skill_4>", file);
			sprintf(data, "%i", current_Firm->no_employees_skill_4);
			fputs(data, file);
			fputs("</no_employees_skill_4>\n", file);
			fputs("<no_employees_skill_5>", file);
			sprintf(data, "%i", current_Firm->no_employees_skill_5);
			fputs(data, file);
			fputs("</no_employees_skill_5>\n", file);
			fputs("<vacancies>", file);
			sprintf(data, "%i", current_Firm->vacancies);
			fputs(data, file);
			fputs("</vacancies>\n", file);
			fputs("<average_g_skill>", file);
			sprintf(data, "%f", current_Firm->average_g_skill);
			fputs(data, file);
			fputs("</average_g_skill>\n", file);
			fputs("<average_s_skill_of_1>", file);
			sprintf(data, "%f", current_Firm->average_s_skill_of_1);
			fputs(data, file);
			fputs("</average_s_skill_of_1>\n", file);
			fputs("<average_s_skill_of_2>", file);
			sprintf(data, "%f", current_Firm->average_s_skill_of_2);
			fputs(data, file);
			fputs("</average_s_skill_of_2>\n", file);
			fputs("<average_s_skill_of_3>", file);
			sprintf(data, "%f", current_Firm->average_s_skill_of_3);
			fputs(data, file);
			fputs("</average_s_skill_of_3>\n", file);
			fputs("<average_s_skill_of_4>", file);
			sprintf(data, "%f", current_Firm->average_s_skill_of_4);
			fputs(data, file);
			fputs("</average_s_skill_of_4>\n", file);
			fputs("<average_s_skill_of_5>", file);
			sprintf(data, "%f", current_Firm->average_s_skill_of_5);
			fputs(data, file);
			fputs("</average_s_skill_of_5>\n", file);
			fputs("<wage_offer_for_skill_1>", file);
			sprintf(data, "%f", current_Firm->wage_offer_for_skill_1);
			fputs(data, file);
			fputs("</wage_offer_for_skill_1>\n", file);
			fputs("<wage_offer_for_skill_2>", file);
			sprintf(data, "%f", current_Firm->wage_offer_for_skill_2);
			fputs(data, file);
			fputs("</wage_offer_for_skill_2>\n", file);
			fputs("<wage_offer_for_skill_3>", file);
			sprintf(data, "%f", current_Firm->wage_offer_for_skill_3);
			fputs(data, file);
			fputs("</wage_offer_for_skill_3>\n", file);
			fputs("<wage_offer_for_skill_4>", file);
			sprintf(data, "%f", current_Firm->wage_offer_for_skill_4);
			fputs(data, file);
			fputs("</wage_offer_for_skill_4>\n", file);
			fputs("<wage_offer_for_skill_5>", file);
			sprintf(data, "%f", current_Firm->wage_offer_for_skill_5);
			fputs(data, file);
			fputs("</wage_offer_for_skill_5>\n", file);
			fputs("<wage_update_was_made>", file);
			sprintf(data, "%i", current_Firm->wage_update_was_made);
			fputs(data, file);
			fputs("</wage_update_was_made>\n", file);
			fputs("<share_net_investments>", file);
			sprintf(data, "%f", current_Firm->share_net_investments);
			fputs(data, file);
			fputs("</share_net_investments>\n", file);
			fputs("<mean_wage>", file);
			sprintf(data, "%f", current_Firm->mean_wage);
			fputs(data, file);
			fputs("</mean_wage>\n", file);
			fputs("<needed_capital_stock>", file);
			sprintf(data, "%f", current_Firm->needed_capital_stock);
			fputs(data, file);
			fputs("</needed_capital_stock>\n", file);
			fputs("<actual_cap_price>", file);
			sprintf(data, "%f", current_Firm->actual_cap_price);
			fputs(data, file);
			fputs("</actual_cap_price>\n", file);
			fputs("<mean_specific_skills>", file);
			sprintf(data, "%f", current_Firm->mean_specific_skills);
			fputs(data, file);
			fputs("</mean_specific_skills>\n", file);
			fputs("<planned_production_quantity>", file);
			sprintf(data, "%f", current_Firm->planned_production_quantity);
			fputs(data, file);
			fputs("</planned_production_quantity>\n", file);
			fputs("<production_quantity>", file);
			sprintf(data, "%f", current_Firm->production_quantity);
			fputs(data, file);
			fputs("</production_quantity>\n", file);
			fputs("<unit_costs>", file);
			sprintf(data, "%f", current_Firm->unit_costs);
			fputs(data, file);
			fputs("</unit_costs>\n", file);
			fputs("<planned_production_costs>", file);
			sprintf(data, "%f", current_Firm->planned_production_costs);
			fputs(data, file);
			fputs("</planned_production_costs>\n", file);
			fputs("<production_costs>", file);
			sprintf(data, "%f", current_Firm->production_costs);
			fputs(data, file);
			fputs("</production_costs>\n", file);
			fputs("<revenue_per_day>", file);
			sprintf(data, "%f", current_Firm->revenue_per_day);
			fputs(data, file);
			fputs("</revenue_per_day>\n", file);
			fputs("<technological_frontier>", file);
			sprintf(data, "%f", current_Firm->technological_frontier);
			fputs(data, file);
			fputs("</technological_frontier>\n", file);
			fputs("<cum_revenue>", file);
			sprintf(data, "%f", current_Firm->cum_revenue);
			fputs(data, file);
			fputs("</cum_revenue>\n", file);
			fputs("<out_of_stock_costs>", file);
			sprintf(data, "%f", current_Firm->out_of_stock_costs);
			fputs(data, file);
			fputs("</out_of_stock_costs>\n", file);
			fputs("<malls_sales_statistics>", file);
			write_sales_statistics_dynamic_array(file, &current_Firm->malls_sales_statistics);
			fputs("</malls_sales_statistics>\n", file);
			fputs("<quality>", file);
			sprintf(data, "%f", current_Firm->quality);
			fputs(data, file);
			fputs("</quality>\n", file);
			fputs("<price>", file);
			sprintf(data, "%f", current_Firm->price);
			fputs(data, file);
			fputs("</price>\n", file);
			fputs("<price_last_month>", file);
			sprintf(data, "%f", current_Firm->price_last_month);
			fputs(data, file);
			fputs("</price_last_month>\n", file);
			fputs("<capital_stock>", file);
			write_capital_stock_item_dynamic_array(file, &current_Firm->capital_stock);
			fputs("</capital_stock>\n", file);
			fputs("<total_units_capital_stock>", file);
			sprintf(data, "%f", current_Firm->total_units_capital_stock);
			fputs(data, file);
			fputs("</total_units_capital_stock>\n", file);
			fputs("<total_value_capital_stock>", file);
			sprintf(data, "%f", current_Firm->total_value_capital_stock);
			fputs(data, file);
			fputs("</total_value_capital_stock>\n", file);
			fputs("<total_capital_depreciation_value>", file);
			sprintf(data, "%f", current_Firm->total_capital_depreciation_value);
			fputs(data, file);
			fputs("</total_capital_depreciation_value>\n", file);
			fputs("<total_capital_depreciation_units>", file);
			sprintf(data, "%f", current_Firm->total_capital_depreciation_units);
			fputs(data, file);
			fputs("</total_capital_depreciation_units>\n", file);
			fputs("<employees_needed>", file);
			sprintf(data, "%i", current_Firm->employees_needed);
			fputs(data, file);
			fputs("</employees_needed>\n", file);
			fputs("<sold_quantities>", file);
			write_sold_quantities_per_mall_dynamic_array(file, &current_Firm->sold_quantities);
			fputs("</sold_quantities>\n", file);
			fputs("<total_sold_quantity>", file);
			sprintf(data, "%f", current_Firm->total_sold_quantity);
			fputs(data, file);
			fputs("</total_sold_quantity>\n", file);
			fputs("<cum_total_sold_quantity>", file);
			sprintf(data, "%f", current_Firm->cum_total_sold_quantity);
			fputs(data, file);
			fputs("</cum_total_sold_quantity>\n", file);
			fputs("<delivery_volume>", file);
			write_delivery_volume_per_mall_dynamic_array(file, &current_Firm->delivery_volume);
			fputs("</delivery_volume>\n", file);
			fputs("<planned_delivery_volume>", file);
			write_delivery_volume_per_mall_dynamic_array(file, &current_Firm->planned_delivery_volume);
			fputs("</planned_delivery_volume>\n", file);
			fputs("<current_mall_stocks>", file);
			write_mall_info_dynamic_array(file, &current_Firm->current_mall_stocks);
			fputs("</current_mall_stocks>\n", file);
			fputs("<demand_capital_stock>", file);
			sprintf(data, "%f", current_Firm->demand_capital_stock);
			fputs(data, file);
			fputs("</demand_capital_stock>\n", file);
			fputs("<last_planned_production_quantities>", file);
			write_double_dynamic_array(file, &current_Firm->last_planned_production_quantities);
			fputs("</last_planned_production_quantities>\n", file);
			fputs("<day_of_month_to_act>", file);
			sprintf(data, "%i", current_Firm->day_of_month_to_act);
			fputs(data, file);
			fputs("</day_of_month_to_act>\n", file);
			fputs("<gov_id>", file);
			sprintf(data, "%i", current_Firm->gov_id);
			fputs(data, file);
			fputs("</gov_id>\n", file);
			fputs("<bank_id>", file);
			sprintf(data, "%i", current_Firm->bank_id);
			fputs(data, file);
			fputs("</bank_id>\n", file);
			fputs("<ebit>", file);
			sprintf(data, "%f", current_Firm->ebit);
			fputs(data, file);
			fputs("</ebit>\n", file);
			fputs("<payment_account>", file);
			sprintf(data, "%f", current_Firm->payment_account);
			fputs(data, file);
			fputs("</payment_account>\n", file);
			fputs("<earnings>", file);
			sprintf(data, "%f", current_Firm->earnings);
			fputs(data, file);
			fputs("</earnings>\n", file);
			fputs("<tax_rate_corporate>", file);
			sprintf(data, "%f", current_Firm->tax_rate_corporate);
			fputs(data, file);
			fputs("</tax_rate_corporate>\n", file);
			fputs("<tax_payment>", file);
			sprintf(data, "%f", current_Firm->tax_payment);
			fputs(data, file);
			fputs("</tax_payment>\n", file);
			fputs("<net_earnings>", file);
			sprintf(data, "%f", current_Firm->net_earnings);
			fputs(data, file);
			fputs("</net_earnings>\n", file);
			fputs("<previous_net_earnings>", file);
			sprintf(data, "%f", current_Firm->previous_net_earnings);
			fputs(data, file);
			fputs("</previous_net_earnings>\n", file);
			fputs("<loans>", file);
			write_debt_item_dynamic_array(file, &current_Firm->loans);
			fputs("</loans>\n", file);
			fputs("<total_interest_payment>", file);
			sprintf(data, "%f", current_Firm->total_interest_payment);
			fputs(data, file);
			fputs("</total_interest_payment>\n", file);
			fputs("<total_debt_installment_payment>", file);
			sprintf(data, "%f", current_Firm->total_debt_installment_payment);
			fputs(data, file);
			fputs("</total_debt_installment_payment>\n", file);
			fputs("<total_debt>", file);
			sprintf(data, "%f", current_Firm->total_debt);
			fputs(data, file);
			fputs("</total_debt>\n", file);
			fputs("<total_dividend_payment>", file);
			sprintf(data, "%f", current_Firm->total_dividend_payment);
			fputs(data, file);
			fputs("</total_dividend_payment>\n", file);
			fputs("<total_value_local_inventory>", file);
			sprintf(data, "%f", current_Firm->total_value_local_inventory);
			fputs(data, file);
			fputs("</total_value_local_inventory>\n", file);
			fputs("<total_assets>", file);
			sprintf(data, "%f", current_Firm->total_assets);
			fputs(data, file);
			fputs("</total_assets>\n", file);
			fputs("<planned_cum_revenue>", file);
			sprintf(data, "%f", current_Firm->planned_cum_revenue);
			fputs(data, file);
			fputs("</planned_cum_revenue>\n", file);
			fputs("<planned_total_interest_payment>", file);
			sprintf(data, "%f", current_Firm->planned_total_interest_payment);
			fputs(data, file);
			fputs("</planned_total_interest_payment>\n", file);
			fputs("<planned_total_debt_installment_payment>", file);
			sprintf(data, "%f", current_Firm->planned_total_debt_installment_payment);
			fputs(data, file);
			fputs("</planned_total_debt_installment_payment>\n", file);
			fputs("<planned_total_dividend_payment>", file);
			sprintf(data, "%f", current_Firm->planned_total_dividend_payment);
			fputs(data, file);
			fputs("</planned_total_dividend_payment>\n", file);
			fputs("<direct_financial_needs>", file);
			sprintf(data, "%f", current_Firm->direct_financial_needs);
			fputs(data, file);
			fputs("</direct_financial_needs>\n", file);
			fputs("<delayed_financial_needs>", file);
			sprintf(data, "%f", current_Firm->delayed_financial_needs);
			fputs(data, file);
			fputs("</delayed_financial_needs>\n", file);
			fputs("<total_financial_needs>", file);
			sprintf(data, "%f", current_Firm->total_financial_needs);
			fputs(data, file);
			fputs("</total_financial_needs>\n", file);
			fputs("<internal_financial_needs>", file);
			sprintf(data, "%f", current_Firm->internal_financial_needs);
			fputs(data, file);
			fputs("</internal_financial_needs>\n", file);
			fputs("<external_financial_needs>", file);
			sprintf(data, "%f", current_Firm->external_financial_needs);
			fputs(data, file);
			fputs("</external_financial_needs>\n", file);
			fputs("<total_external_financing_obtained>", file);
			sprintf(data, "%f", current_Firm->total_external_financing_obtained);
			fputs(data, file);
			fputs("</total_external_financing_obtained>\n", file);
			fputs("<direct_financial_needs_require_external_financing>", file);
			sprintf(data, "%i", current_Firm->direct_financial_needs_require_external_financing);
			fputs(data, file);
			fputs("</direct_financial_needs_require_external_financing>\n", file);
			fputs("<delayed_financial_needs_require_external_financing>", file);
			sprintf(data, "%i", current_Firm->delayed_financial_needs_require_external_financing);
			fputs(data, file);
			fputs("</delayed_financial_needs_require_external_financing>\n", file);
			fputs("<current_share_price>", file);
			sprintf(data, "%f", current_Firm->current_share_price);
			fputs(data, file);
			fputs("</current_share_price>\n", file);
			fputs("<current_shares_outstanding>", file);
			sprintf(data, "%f", current_Firm->current_shares_outstanding);
			fputs(data, file);
			fputs("</current_shares_outstanding>\n", file);
			fputs("<previous_dividend_per_share>", file);
			sprintf(data, "%f", current_Firm->previous_dividend_per_share);
			fputs(data, file);
			fputs("</previous_dividend_per_share>\n", file);
			fputs("<current_dividend_per_share>", file);
			sprintf(data, "%f", current_Firm->current_dividend_per_share);
			fputs(data, file);
			fputs("</current_dividend_per_share>\n", file);
			fputs("<previous_dividend_per_earnings>", file);
			sprintf(data, "%f", current_Firm->previous_dividend_per_earnings);
			fputs(data, file);
			fputs("</previous_dividend_per_earnings>\n", file);
			fputs("<current_dividend_per_earnings>", file);
			sprintf(data, "%f", current_Firm->current_dividend_per_earnings);
			fputs(data, file);
			fputs("</current_dividend_per_earnings>\n", file);
			fputs("<earnings_per_share_ratio>", file);
			sprintf(data, "%f", current_Firm->earnings_per_share_ratio);
			fputs(data, file);
			fputs("</earnings_per_share_ratio>\n", file);
			fputs("<debt_earnings_ratio>", file);
			sprintf(data, "%f", current_Firm->debt_earnings_ratio);
			fputs(data, file);
			fputs("</debt_earnings_ratio>\n", file);
			fputs("<price_earnings_ratio>", file);
			sprintf(data, "%f", current_Firm->price_earnings_ratio);
			fputs(data, file);
			fputs("</price_earnings_ratio>\n", file);
			fputs("<retained_earnings_ratio>", file);
			sprintf(data, "%f", current_Firm->retained_earnings_ratio);
			fputs(data, file);
			fputs("</retained_earnings_ratio>\n", file);
			fputs("<earnings_per_share_ratio_growth>", file);
			sprintf(data, "%f", current_Firm->earnings_per_share_ratio_growth);
			fputs(data, file);
			fputs("</earnings_per_share_ratio_growth>\n", file);
			fputs("<critical_price_earnings_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_price_earnings_ratio);
			fputs(data, file);
			fputs("</critical_price_earnings_ratio>\n", file);
			fputs("<critical_earnings_per_share_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_earnings_per_share_ratio);
			fputs(data, file);
			fputs("</critical_earnings_per_share_ratio>\n", file);
			fputs("<target_loans>", file);
			sprintf(data, "%f", current_Firm->target_loans);
			fputs(data, file);
			fputs("</target_loans>\n", file);
			fputs("<target_equity>", file);
			sprintf(data, "%f", current_Firm->target_equity);
			fputs(data, file);
			fputs("</target_equity>\n", file);
			fputs("<bonds_issue_target>", file);
			sprintf(data, "%f", current_Firm->bonds_issue_target);
			fputs(data, file);
			fputs("</bonds_issue_target>\n", file);
			fputs("<stocks_issue_target>", file);
			sprintf(data, "%f", current_Firm->stocks_issue_target);
			fputs(data, file);
			fputs("</stocks_issue_target>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Firm->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Firm->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Firm->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			fputs("<name>Household</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Household->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<region_id>", file);
			sprintf(data, "%i", current_Household->region_id);
			fputs(data, file);
			fputs("</region_id>\n", file);
			fputs("<neighboring_region_ids>", file);
			write_int_dynamic_array(file, &current_Household->neighboring_region_ids);
			fputs("</neighboring_region_ids>\n", file);
			fputs("<wage>", file);
			sprintf(data, "%f", current_Household->wage);
			fputs(data, file);
			fputs("</wage>\n", file);
			fputs("<wage_reservation>", file);
			sprintf(data, "%f", current_Household->wage_reservation);
			fputs(data, file);
			fputs("</wage_reservation>\n", file);
			fputs("<general_skill>", file);
			sprintf(data, "%i", current_Household->general_skill);
			fputs(data, file);
			fputs("</general_skill>\n", file);
			fputs("<on_the_job_search>", file);
			sprintf(data, "%i", current_Household->on_the_job_search);
			fputs(data, file);
			fputs("</on_the_job_search>\n", file);
			fputs("<number_applications>", file);
			sprintf(data, "%i", current_Household->number_applications);
			fputs(data, file);
			fputs("</number_applications>\n", file);
			fputs("<specific_skill>", file);
			sprintf(data, "%f", current_Household->specific_skill);
			fputs(data, file);
			fputs("</specific_skill>\n", file);
			fputs("<employee_firm_id>", file);
			sprintf(data, "%i", current_Household->employee_firm_id);
			fputs(data, file);
			fputs("</employee_firm_id>\n", file);
			fputs("<employer_region_id>", file);
			sprintf(data, "%i", current_Household->employer_region_id);
			fputs(data, file);
			fputs("</employer_region_id>\n", file);
			fputs("<budget>", file);
			sprintf(data, "%f", current_Household->budget);
			fputs(data, file);
			fputs("</budget>\n", file);
			fputs("<week_of_month>", file);
			sprintf(data, "%i", current_Household->week_of_month);
			fputs(data, file);
			fputs("</week_of_month>\n", file);
			fputs("<weekly_budget>", file);
			sprintf(data, "%f", current_Household->weekly_budget);
			fputs(data, file);
			fputs("</weekly_budget>\n", file);
			fputs("<expenditures>", file);
			sprintf(data, "%f", current_Household->expenditures);
			fputs(data, file);
			fputs("</expenditures>\n", file);
			fputs("<received_dividend_cap>", file);
			sprintf(data, "%f", current_Household->received_dividend_cap);
			fputs(data, file);
			fputs("</received_dividend_cap>\n", file);
			fputs("<received_dividend_cons>", file);
			sprintf(data, "%f", current_Household->received_dividend_cons);
			fputs(data, file);
			fputs("</received_dividend_cons>\n", file);
			fputs("<savings>", file);
			sprintf(data, "%f", current_Household->savings);
			fputs(data, file);
			fputs("</savings>\n", file);
			fputs("<last_income>", file);
			write_double_dynamic_array(file, &current_Household->last_income);
			fputs("</last_income>\n", file);
			fputs("<rationed>", file);
			sprintf(data, "%i", current_Household->rationed);
			fputs(data, file);
			fputs("</rationed>\n", file);
			fputs("<mall_completely_sold_out>", file);
			sprintf(data, "%i", current_Household->mall_completely_sold_out);
			fputs(data, file);
			fputs("</mall_completely_sold_out>\n", file);
			fputs("<order_quantity>", file);
			write_ordered_quantity_static_array(file, current_Household->order_quantity, 2);
			fputs("</order_quantity>\n", file);
			fputs("<received_quantity>", file);
			write_received_quantities_static_array(file, current_Household->received_quantity, 2);
			fputs("</received_quantity>\n", file);
			fputs("<day_of_month_to_act>", file);
			sprintf(data, "%i", current_Household->day_of_month_to_act);
			fputs(data, file);
			fputs("</day_of_month_to_act>\n", file);
			fputs("<day_of_week_to_act>", file);
			sprintf(data, "%i", current_Household->day_of_week_to_act);
			fputs(data, file);
			fputs("</day_of_week_to_act>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Household->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Household->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Household->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Mall != NULL)
		{
			current_Mall = current_xmachine->xmachine_Mall;
			fputs("<name>Mall</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Mall->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<region_id>", file);
			sprintf(data, "%i", current_Mall->region_id);
			fputs(data, file);
			fputs("</region_id>\n", file);
			fputs("<current_stock>", file);
			write_mall_stock_dynamic_array(file, &current_Mall->current_stock);
			fputs("</current_stock>\n", file);
			fputs("<firm_revenues>", file);
			write_sales_in_mall_dynamic_array(file, &current_Mall->firm_revenues);
			fputs("</firm_revenues>\n", file);
			fputs("<total_supply>", file);
			sprintf(data, "%f", current_Mall->total_supply);
			fputs(data, file);
			fputs("</total_supply>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Mall->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Mall->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Mall->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_IGFirm != NULL)
		{
			current_IGFirm = current_xmachine->xmachine_IGFirm;
			fputs("<name>IGFirm</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_IGFirm->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<region_id>", file);
			sprintf(data, "%i", current_IGFirm->region_id);
			fputs(data, file);
			fputs("</region_id>\n", file);
			fputs("<productivity>", file);
			sprintf(data, "%f", current_IGFirm->productivity);
			fputs(data, file);
			fputs("</productivity>\n", file);
			fputs("<innovation_probability>", file);
			sprintf(data, "%i", current_IGFirm->innovation_probability);
			fputs(data, file);
			fputs("</innovation_probability>\n", file);
			fputs("<productivity_progress>", file);
			sprintf(data, "%f", current_IGFirm->productivity_progress);
			fputs(data, file);
			fputs("</productivity_progress>\n", file);
			fputs("<capital_good_price>", file);
			sprintf(data, "%f", current_IGFirm->capital_good_price);
			fputs(data, file);
			fputs("</capital_good_price>\n", file);
			fputs("<revenue_per_day>", file);
			sprintf(data, "%f", current_IGFirm->revenue_per_day);
			fputs(data, file);
			fputs("</revenue_per_day>\n", file);
			fputs("<day_of_month_to_act>", file);
			sprintf(data, "%i", current_IGFirm->day_of_month_to_act);
			fputs(data, file);
			fputs("</day_of_month_to_act>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_IGFirm->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_IGFirm->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_IGFirm->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Market_Research != NULL)
		{
			current_Market_Research = current_xmachine->xmachine_Market_Research;
			fputs("<name>Market_Research</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Market_Research->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<region_id>", file);
			sprintf(data, "%i", current_Market_Research->region_id);
			fputs(data, file);
			fputs("</region_id>\n", file);
			fputs("<no_regions>", file);
			sprintf(data, "%i", current_Market_Research->no_regions);
			fputs(data, file);
			fputs("</no_regions>\n", file);
			fputs("<num_households>", file);
			sprintf(data, "%i", current_Market_Research->num_households);
			fputs(data, file);
			fputs("</num_households>\n", file);
			fputs("<no_households_skill_1>", file);
			sprintf(data, "%i", current_Market_Research->no_households_skill_1);
			fputs(data, file);
			fputs("</no_households_skill_1>\n", file);
			fputs("<no_households_skill_2>", file);
			sprintf(data, "%i", current_Market_Research->no_households_skill_2);
			fputs(data, file);
			fputs("</no_households_skill_2>\n", file);
			fputs("<no_households_skill_3>", file);
			sprintf(data, "%i", current_Market_Research->no_households_skill_3);
			fputs(data, file);
			fputs("</no_households_skill_3>\n", file);
			fputs("<no_households_skill_4>", file);
			sprintf(data, "%i", current_Market_Research->no_households_skill_4);
			fputs(data, file);
			fputs("</no_households_skill_4>\n", file);
			fputs("<no_households_skill_5>", file);
			sprintf(data, "%i", current_Market_Research->no_households_skill_5);
			fputs(data, file);
			fputs("</no_households_skill_5>\n", file);
			fputs("<employed>", file);
			sprintf(data, "%i", current_Market_Research->employed);
			fputs(data, file);
			fputs("</employed>\n", file);
			fputs("<employed_skill_1>", file);
			sprintf(data, "%i", current_Market_Research->employed_skill_1);
			fputs(data, file);
			fputs("</employed_skill_1>\n", file);
			fputs("<employed_skill_2>", file);
			sprintf(data, "%i", current_Market_Research->employed_skill_2);
			fputs(data, file);
			fputs("</employed_skill_2>\n", file);
			fputs("<employed_skill_3>", file);
			sprintf(data, "%i", current_Market_Research->employed_skill_3);
			fputs(data, file);
			fputs("</employed_skill_3>\n", file);
			fputs("<employed_skill_4>", file);
			sprintf(data, "%i", current_Market_Research->employed_skill_4);
			fputs(data, file);
			fputs("</employed_skill_4>\n", file);
			fputs("<employed_skill_5>", file);
			sprintf(data, "%i", current_Market_Research->employed_skill_5);
			fputs(data, file);
			fputs("</employed_skill_5>\n", file);
			fputs("<unemployed>", file);
			sprintf(data, "%i", current_Market_Research->unemployed);
			fputs(data, file);
			fputs("</unemployed>\n", file);
			fputs("<unemployment_rate>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate);
			fputs(data, file);
			fputs("</unemployment_rate>\n", file);
			fputs("<unemployment_rate_skill_1>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate_skill_1);
			fputs(data, file);
			fputs("</unemployment_rate_skill_1>\n", file);
			fputs("<unemployment_rate_skill_2>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate_skill_2);
			fputs(data, file);
			fputs("</unemployment_rate_skill_2>\n", file);
			fputs("<unemployment_rate_skill_3>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate_skill_3);
			fputs(data, file);
			fputs("</unemployment_rate_skill_3>\n", file);
			fputs("<unemployment_rate_skill_4>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate_skill_4);
			fputs(data, file);
			fputs("</unemployment_rate_skill_4>\n", file);
			fputs("<unemployment_rate_skill_5>", file);
			sprintf(data, "%f", current_Market_Research->unemployment_rate_skill_5);
			fputs(data, file);
			fputs("</unemployment_rate_skill_5>\n", file);
			fputs("<average_wage>", file);
			sprintf(data, "%f", current_Market_Research->average_wage);
			fputs(data, file);
			fputs("</average_wage>\n", file);
			fputs("<average_wage_skill_1>", file);
			sprintf(data, "%f", current_Market_Research->average_wage_skill_1);
			fputs(data, file);
			fputs("</average_wage_skill_1>\n", file);
			fputs("<average_wage_skill_2>", file);
			sprintf(data, "%f", current_Market_Research->average_wage_skill_2);
			fputs(data, file);
			fputs("</average_wage_skill_2>\n", file);
			fputs("<average_wage_skill_3>", file);
			sprintf(data, "%f", current_Market_Research->average_wage_skill_3);
			fputs(data, file);
			fputs("</average_wage_skill_3>\n", file);
			fputs("<average_wage_skill_4>", file);
			sprintf(data, "%f", current_Market_Research->average_wage_skill_4);
			fputs(data, file);
			fputs("</average_wage_skill_4>\n", file);
			fputs("<average_wage_skill_5>", file);
			sprintf(data, "%f", current_Market_Research->average_wage_skill_5);
			fputs(data, file);
			fputs("</average_wage_skill_5>\n", file);
			fputs("<average_s_skill>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill);
			fputs(data, file);
			fputs("</average_s_skill>\n", file);
			fputs("<average_s_skill_1>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill_1);
			fputs(data, file);
			fputs("</average_s_skill_1>\n", file);
			fputs("<average_s_skill_2>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill_2);
			fputs(data, file);
			fputs("</average_s_skill_2>\n", file);
			fputs("<average_s_skill_3>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill_3);
			fputs(data, file);
			fputs("</average_s_skill_3>\n", file);
			fputs("<average_s_skill_4>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill_4);
			fputs(data, file);
			fputs("</average_s_skill_4>\n", file);
			fputs("<average_s_skill_5>", file);
			sprintf(data, "%f", current_Market_Research->average_s_skill_5);
			fputs(data, file);
			fputs("</average_s_skill_5>\n", file);
			fputs("<no_firms>", file);
			sprintf(data, "%i", current_Market_Research->no_firms);
			fputs(data, file);
			fputs("</no_firms>\n", file);
			fputs("<no_vacancies>", file);
			sprintf(data, "%i", current_Market_Research->no_vacancies);
			fputs(data, file);
			fputs("</no_vacancies>\n", file);
			fputs("<no_employees>", file);
			sprintf(data, "%i", current_Market_Research->no_employees);
			fputs(data, file);
			fputs("</no_employees>\n", file);
			fputs("<no_employees_skill_1>", file);
			sprintf(data, "%i", current_Market_Research->no_employees_skill_1);
			fputs(data, file);
			fputs("</no_employees_skill_1>\n", file);
			fputs("<no_employees_skill_2>", file);
			sprintf(data, "%i", current_Market_Research->no_employees_skill_2);
			fputs(data, file);
			fputs("</no_employees_skill_2>\n", file);
			fputs("<no_employees_skill_3>", file);
			sprintf(data, "%i", current_Market_Research->no_employees_skill_3);
			fputs(data, file);
			fputs("</no_employees_skill_3>\n", file);
			fputs("<no_employees_skill_4>", file);
			sprintf(data, "%i", current_Market_Research->no_employees_skill_4);
			fputs(data, file);
			fputs("</no_employees_skill_4>\n", file);
			fputs("<no_employees_skill_5>", file);
			sprintf(data, "%i", current_Market_Research->no_employees_skill_5);
			fputs(data, file);
			fputs("</no_employees_skill_5>\n", file);
			fputs("<firm_average_wage>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage);
			fputs(data, file);
			fputs("</firm_average_wage>\n", file);
			fputs("<firm_average_wage_skill_1>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage_skill_1);
			fputs(data, file);
			fputs("</firm_average_wage_skill_1>\n", file);
			fputs("<firm_average_wage_skill_2>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage_skill_2);
			fputs(data, file);
			fputs("</firm_average_wage_skill_2>\n", file);
			fputs("<firm_average_wage_skill_3>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage_skill_3);
			fputs(data, file);
			fputs("</firm_average_wage_skill_3>\n", file);
			fputs("<firm_average_wage_skill_4>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage_skill_4);
			fputs(data, file);
			fputs("</firm_average_wage_skill_4>\n", file);
			fputs("<firm_average_wage_skill_5>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_wage_skill_5);
			fputs(data, file);
			fputs("</firm_average_wage_skill_5>\n", file);
			fputs("<firm_average_s_skill>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill);
			fputs(data, file);
			fputs("</firm_average_s_skill>\n", file);
			fputs("<firm_average_s_skill_1>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill_1);
			fputs(data, file);
			fputs("</firm_average_s_skill_1>\n", file);
			fputs("<firm_average_s_skill_2>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill_2);
			fputs(data, file);
			fputs("</firm_average_s_skill_2>\n", file);
			fputs("<firm_average_s_skill_3>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill_3);
			fputs(data, file);
			fputs("</firm_average_s_skill_3>\n", file);
			fputs("<firm_average_s_skill_4>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill_4);
			fputs(data, file);
			fputs("</firm_average_s_skill_4>\n", file);
			fputs("<firm_average_s_skill_5>", file);
			sprintf(data, "%f", current_Market_Research->firm_average_s_skill_5);
			fputs(data, file);
			fputs("</firm_average_s_skill_5>\n", file);
			fputs("<region_firm_data>", file);
			write_firm_data_dynamic_array(file, &current_Market_Research->region_firm_data);
			fputs("</region_firm_data>\n", file);
			fputs("<region_household_data>", file);
			write_household_data_dynamic_array(file, &current_Market_Research->region_household_data);
			fputs("</region_household_data>\n", file);
			fputs("<day_of_month_to_act>", file);
			sprintf(data, "%i", current_Market_Research->day_of_month_to_act);
			fputs(data, file);
			fputs("</day_of_month_to_act>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Market_Research->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Market_Research->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Market_Research->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Clearinghouse != NULL)
		{
			current_Clearinghouse = current_xmachine->xmachine_Clearinghouse;
			fputs("<name>Clearinghouse</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Clearinghouse->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<trader_id>", file);
			sprintf(data, "%i", current_Clearinghouse->trader_id);
			fputs(data, file);
			fputs("</trader_id>\n", file);
			fputs("<stock_id>", file);
			sprintf(data, "%i", current_Clearinghouse->stock_id);
			fputs(data, file);
			fputs("</stock_id>\n", file);
			fputs("<bond_id>", file);
			sprintf(data, "%i", current_Clearinghouse->bond_id);
			fputs(data, file);
			fputs("</bond_id>\n", file);
			fputs("<gov_bond_id>", file);
			sprintf(data, "%i", current_Clearinghouse->gov_bond_id);
			fputs(data, file);
			fputs("</gov_bond_id>\n", file);
			fputs("<limit_price>", file);
			sprintf(data, "%f", current_Clearinghouse->limit_price);
			fputs(data, file);
			fputs("</limit_price>\n", file);
			fputs("<limit_quantity>", file);
			sprintf(data, "%f", current_Clearinghouse->limit_quantity);
			fputs(data, file);
			fputs("</limit_quantity>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Clearinghouse->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Clearinghouse->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Clearinghouse->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			fputs("<name>Bank</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Bank->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<proposed_interest_rate>", file);
			sprintf(data, "%f", current_Bank->proposed_interest_rate);
			fputs(data, file);
			fputs("</proposed_interest_rate>\n", file);
			fputs("<amount_credit_offer>", file);
			sprintf(data, "%f", current_Bank->amount_credit_offer);
			fputs(data, file);
			fputs("</amount_credit_offer>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Bank->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Bank->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Bank->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
	
		fputs("</xagent>\n", file);
		
		current_xmachine = current_xmachine->next;
	}
			current_node = current_node->next;
	}
fputs("</states>\n" , file);
	
	/* Close the file */
	fclose(file);
	
	next_avaliable_id++;
}
