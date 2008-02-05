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
	(*j)++;
	
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
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
	
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
	
	(*j)++;
}


/** \fn void read_string(char * buffer, int * j, string * temp_datatype)
 * \brief Reads string datatype.
 */
void read_string(char * buffer, int * j, string * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_char_dynamic_array(buffer, j, temp_datatype->stringname);
	}
	
	(*j)++;
}

void read_string_dynamic_array(char * buffer, int * j, string_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_string(temp_datatype_array, NULL);
		read_string(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_string_static_array(char * buffer, int * j, string ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_string(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_stringlist(char * buffer, int * j, stringlist * temp_datatype)
 * \brief Reads stringlist datatype.
 */
void read_stringlist(char * buffer, int * j, stringlist * temp_datatype)
{
	
	(*j)++;
	
	while(buffer[*j] != '{') (*j)++;

	read_string_dynamic_array(buffer, j, temp_datatype->stringlistname);
	
	(*j)++;
}

void read_stringlist_dynamic_array(char * buffer, int * j, stringlist_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_stringlist(temp_datatype_array, NULL);
		read_stringlist(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_stringlist_static_array(char * buffer, int * j, stringlist ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_stringlist(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_word(char * buffer, int * j, word * temp_datatype)
 * \brief Reads word datatype.
 */
void read_word(char * buffer, int * j, word * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_char_dynamic_array(buffer, j, temp_datatype->wordname);
	}
	
	(*j)++;
}

void read_word_dynamic_array(char * buffer, int * j, word_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_word(temp_datatype_array, NULL);
		read_word(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_word_static_array(char * buffer, int * j, word ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_word(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_wordlist(char * buffer, int * j, wordlist * temp_datatype)
 * \brief Reads wordlist datatype.
 */
void read_wordlist(char * buffer, int * j, wordlist * temp_datatype)
{
	
	(*j)++;
	
	while(buffer[*j] != '{') (*j)++;

	read_word_dynamic_array(buffer, j, temp_datatype->wordlistname);
	
	(*j)++;
}

void read_wordlist_dynamic_array(char * buffer, int * j, wordlist_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_wordlist(temp_datatype_array, NULL);
		read_wordlist(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_wordlist_static_array(char * buffer, int * j, wordlist ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_wordlist(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_int2D(char * buffer, int * j, int2D * temp_datatype)
 * \brief Reads int2D datatype.
 */
void read_int2D(char * buffer, int * j, int2D * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->int2Dname);
	}
	
	(*j)++;
}

void read_int2D_dynamic_array(char * buffer, int * j, int2D_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_int2D(temp_datatype_array, NULL);
		read_int2D(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_int2D_static_array(char * buffer, int * j, int2D ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_int2D(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_double2D(char * buffer, int * j, double2D * temp_datatype)
 * \brief Reads double2D datatype.
 */
void read_double2D(char * buffer, int * j, double2D * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->double2Dname);
	}
	
	(*j)++;
}

void read_double2D_dynamic_array(char * buffer, int * j, double2D_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_double2D(temp_datatype_array, NULL);
		read_double2D(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_double2D_static_array(char * buffer, int * j, double2D ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_double2D(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_RuleDetailSystem(char * buffer, int * j, RuleDetailSystem * temp_datatype)
 * \brief Reads RuleDetailSystem datatype.
 */
void read_RuleDetailSystem(char * buffer, int * j, RuleDetailSystem * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->nr_params_per_type);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->nr_params);
	}
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_double2D_dynamic_array(buffer, j, temp_datatype->parameters);
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_wordlist(buffer, j, temp_datatype->myfunctionnames);
	(*j)++;
}

void read_RuleDetailSystem_dynamic_array(char * buffer, int * j, RuleDetailSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_RuleDetailSystem(temp_datatype_array, NULL, NULL, NULL, NULL);
		read_RuleDetailSystem(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_RuleDetailSystem_static_array(char * buffer, int * j, RuleDetailSystem ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_RuleDetailSystem(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_PublicClassifierSystem(char * buffer, int * j, PublicClassifierSystem * temp_datatype)
 * \brief Reads PublicClassifierSystem datatype.
 */
void read_PublicClassifierSystem(char * buffer, int * j, PublicClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	temp_datatype->nr_types = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->nr_types = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->nr_rules_per_type);
	}
	
	(*j)++;
	temp_datatype->nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->nr_rules = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->ids);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->rule_type);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->counter);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->performance);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->avgperformance);
	}
	
	(*j)++;
}

void read_PublicClassifierSystem_dynamic_array(char * buffer, int * j, PublicClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_PublicClassifierSystem(temp_datatype_array, 0, NULL, 0, NULL, NULL, NULL, NULL, NULL);
		read_PublicClassifierSystem(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_PublicClassifierSystem_static_array(char * buffer, int * j, PublicClassifierSystem ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_PublicClassifierSystem(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_PrivateClassifierSystem(char * buffer, int * j, PrivateClassifierSystem * temp_datatype)
 * \brief Reads PrivateClassifierSystem datatype.
 */
void read_PrivateClassifierSystem(char * buffer, int * j, PrivateClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	temp_datatype->nr_types = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->nr_types = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->nr_rules_per_type);
	}
	
	(*j)++;
	temp_datatype->nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->nr_rules = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->ids);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->rule_type);
	}
	
	(*j)++;
	temp_datatype->EWA_rho = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->EWA_rho = atof(arraydata);
	(*j)++;
	temp_datatype->EWA_phi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->EWA_phi = atof(arraydata);
	(*j)++;
	temp_datatype->EWA_delta = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->EWA_delta = atof(arraydata);
	(*j)++;
	temp_datatype->EWA_beta = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->EWA_beta = atof(arraydata);
	(*j)++;
	temp_datatype->experience = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->experience = atoi(arraydata);
	(*j)++;
	temp_datatype->current_rule = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->current_rule = atoi(arraydata);
	(*j)++;
	temp_datatype->my_performance = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->my_performance = atof(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->avgperformance);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->attraction);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->choiceprob);
	}
	
	(*j)++;
}

void read_PrivateClassifierSystem_dynamic_array(char * buffer, int * j, PrivateClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_PrivateClassifierSystem(temp_datatype_array, 0, NULL, 0, NULL, NULL, 0.0, 0.0, 0.0, 0.0, 0, 0, 0.0, NULL, NULL, NULL);
		read_PrivateClassifierSystem(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_PrivateClassifierSystem_static_array(char * buffer, int * j, PrivateClassifierSystem ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_PrivateClassifierSystem(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_StockDataType(char * buffer, int * j, StockDataType * temp_datatype)
 * \brief Reads StockDataType datatype.
 */
void read_StockDataType(char * buffer, int * j, StockDataType * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_char_static_array(buffer, j, temp_datatype->class, 5);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, temp_datatype->id, 5);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->NrOutStandingShares);
	}
	
	(*j)++;
	temp_datatype->price = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->price = atof(arraydata);
	(*j)++;
	temp_datatype->Book_intraday_transaction = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	temp_datatype->Book_intraday_transaction = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->dividends);
	}
	
	(*j)++;
}

void read_StockDataType_dynamic_array(char * buffer, int * j, StockDataType_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_StockDataType(temp_datatype_array, NULL, NULL, NULL, 0.0, 0, NULL);
		read_StockDataType(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_StockDataType_static_array(char * buffer, int * j, StockDataType ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_StockDataType(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_BondDataType(char * buffer, int * j, BondDataType * temp_datatype)
 * \brief Reads BondDataType datatype.
 */
void read_BondDataType(char * buffer, int * j, BondDataType * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		read_char_static_array(buffer, j, temp_datatype->class, 5);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_int_static_array(buffer, j, temp_datatype->id, 5);
	}
	
	(*j)++;
}

void read_BondDataType_dynamic_array(char * buffer, int * j, BondDataType_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_BondDataType(temp_datatype_array, NULL, NULL);
		read_BondDataType(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_BondDataType_static_array(char * buffer, int * j, BondDataType ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_BondDataType(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_DBFinancialAssets(char * buffer, int * j, DBFinancialAssets * temp_datatype)
 * \brief Reads DBFinancialAssets datatype.
 */
void read_DBFinancialAssets(char * buffer, int * j, DBFinancialAssets * temp_datatype)
{
	
	(*j)++;
	
}

void read_DBFinancialAssets_dynamic_array(char * buffer, int * j, DBFinancialAssets_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_DBFinancialAssets(temp_datatype_array);
		read_DBFinancialAssets(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_DBFinancialAssets_static_array(char * buffer, int * j, DBFinancialAssets ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_DBFinancialAssets(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_Asset(char * buffer, int * j, Asset * temp_datatype)
 * \brief Reads Asset datatype.
 */
void read_Asset(char * buffer, int * j, Asset * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->ids);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, temp_datatype->nr_units);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->current_price);
	}
	
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->best_ask_price);
	}
	
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->best_bid_price);
	}
	
	(*j)++;
}

void read_Asset_dynamic_array(char * buffer, int * j, Asset_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_Asset(temp_datatype_array, NULL, NULL, NULL, NULL, NULL);
		read_Asset(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_Asset_static_array(char * buffer, int * j, Asset ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_Asset(buffer, j, temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_AssetPortfolio(char * buffer, int * j, AssetPortfolio * temp_datatype)
 * \brief Reads AssetPortfolio datatype.
 */
void read_AssetPortfolio(char * buffer, int * j, AssetPortfolio * temp_datatype)
{
	
	(*j)++;
	

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_double_dynamic_array(buffer, j, temp_datatype->performance_history);
	}
	
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_Asset(buffer, j, temp_datatype->firm_stocks);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_Asset(buffer, j, temp_datatype->firm_bonds);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;
	read_Asset(buffer, j, temp_datatype->gov_bonds);
	(*j)++;
}

void read_AssetPortfolio_dynamic_array(char * buffer, int * j, AssetPortfolio_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0')
	{
		add_AssetPortfolio(temp_datatype_array, NULL, NULL, NULL, NULL);
		read_AssetPortfolio(buffer, j, temp_datatype_array->array[arraycount]);
		arraycount++;
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_AssetPortfolio_static_array(char * buffer, int * j, AssetPortfolio ** temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_AssetPortfolio(buffer, j, temp_datatype_array[arraycount]);
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
	int in_Household_agent;
	int in_Firm_agent;
	int in_Bank_agent;
	int in_ClearingHouse_agent;
	int in_LimitOrderBook_agent;
	int in_Government_agent;
	int in_FinancialAgent_agent;

	int in_id;
	int in_privateclassifiersystem;
	int in_current_assetportfolio;
	int in_prescribed_assetportfolio;
	int in_asset_budget;
	int in_range;
	int in_posx;
	int in_posy;
	int in_revenues;
	int in_sales_costs;
	int in_total_revenue;
	int in_net_revenue;
	int in_operational_cost;
	int in_total_wage_payments;
	int in_total_input_payments;
	int in_interest_payments;
	int in_total_earnings;
	int in_tax_rate_profits;
	int in_pretax_profit;
	int in_tax_provision;
	int in_net_earnings;
	int in_div_payments;
	int in_retained_earnings;
	int in_current_debt;
	int in_debt_interest_rate;
	int in_debt_repayments;
	int in_share_repurchase_value;
	int in_share_repurchase_units;
	int in_target_total_shares;
	int in_current_total_shares;
	int in_total_financial_needs;
	int in_financial_needs;
	int in_add_financial_needs;
	int in_financial_reserves;
	int in_target_loans;
	int in_target_equity;
	int in_bonds_issue_target;
	int in_stocks_issue_target;
	int in_price;
	int in_max_debt;
	int in_div_earn_ratio;
	int in_debt_earn_ratio;
	int in_div_pshare_ratio;
	int in_earn_pshare_ratio;
	int in_price_earn_ratio;
	int in_retained_earn_ratio;
	int in_earn_pshare_ratio_growth;
	int in_critical_price_earn_ratio;
	int in_critical_earn_pshare_ratio;
	int in_ra;
	int in_rg;
	int in_re;
	int in_rj;
	int in_publicclassifiersystem;


	/* Variables for initial state data */
//	int id;
//	PrivateClassifierSystem * privateclassifiersystem;
//	AssetPortfolio * current_assetportfolio;
//	AssetPortfolio * prescribed_assetportfolio;
//	double asset_budget;
//	double range;
//	double posx;
//	double posy;
//	double_array * revenues;
//	double_array * sales_costs;
//	double total_revenue;
//	double net_revenue;
//	double operational_cost;
//	double total_wage_payments;
//	double total_input_payments;
//	double interest_payments;
//	double total_earnings;
//	double tax_rate_profits;
//	double pretax_profit;
//	double tax_provision;
//	double net_earnings;
//	double div_payments;
//	double retained_earnings;
//	double current_debt;
//	double debt_interest_rate;
//	double debt_repayments;
//	double share_repurchase_value;
//	int share_repurchase_units;
//	int target_total_shares;
//	int current_total_shares;
//	double total_financial_needs;
//	double financial_needs;
//	double add_financial_needs;
//	double financial_reserves;
//	double target_loans;
//	double target_equity;
//	double bonds_issue_target;
//	double stocks_issue_target;
//	double price;
//	double max_debt;
//	double div_earn_ratio;
//	double debt_earn_ratio;
//	double div_pshare_ratio;
//	double earn_pshare_ratio;
//	double price_earn_ratio;
//	double retained_earn_ratio;
//	double earn_pshare_ratio_growth;
//	double critical_price_earn_ratio;
//	double critical_earn_pshare_ratio;
//	double ra;
//	double rg;
//	double re;
//	double rj;
//	PublicClassifierSystem * publicclassifiersystem;


	xmachine_memory_Household * current_Household_agent;
	xmachine_memory_Firm * current_Firm_agent;
	xmachine_memory_Bank * current_Bank_agent;
	xmachine_memory_ClearingHouse * current_ClearingHouse_agent;
	xmachine_memory_LimitOrderBook * current_LimitOrderBook_agent;
	xmachine_memory_Government * current_Government_agent;
	xmachine_memory_FinancialAgent * current_FinancialAgent_agent;


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
	in_Household_agent = 0;
	in_Firm_agent = 0;
	in_Bank_agent = 0;
	in_ClearingHouse_agent = 0;
	in_LimitOrderBook_agent = 0;
	in_Government_agent = 0;
	in_FinancialAgent_agent = 0;
	in_id = 0;
	in_privateclassifiersystem = 0;
	in_current_assetportfolio = 0;
	in_prescribed_assetportfolio = 0;
	in_asset_budget = 0;
	in_range = 0;
	in_posx = 0;
	in_posy = 0;
	in_revenues = 0;
	in_sales_costs = 0;
	in_total_revenue = 0;
	in_net_revenue = 0;
	in_operational_cost = 0;
	in_total_wage_payments = 0;
	in_total_input_payments = 0;
	in_interest_payments = 0;
	in_total_earnings = 0;
	in_tax_rate_profits = 0;
	in_pretax_profit = 0;
	in_tax_provision = 0;
	in_net_earnings = 0;
	in_div_payments = 0;
	in_retained_earnings = 0;
	in_current_debt = 0;
	in_debt_interest_rate = 0;
	in_debt_repayments = 0;
	in_share_repurchase_value = 0;
	in_share_repurchase_units = 0;
	in_target_total_shares = 0;
	in_current_total_shares = 0;
	in_total_financial_needs = 0;
	in_financial_needs = 0;
	in_add_financial_needs = 0;
	in_financial_reserves = 0;
	in_target_loans = 0;
	in_target_equity = 0;
	in_bonds_issue_target = 0;
	in_stocks_issue_target = 0;
	in_price = 0;
	in_max_debt = 0;
	in_div_earn_ratio = 0;
	in_debt_earn_ratio = 0;
	in_div_pshare_ratio = 0;
	in_earn_pshare_ratio = 0;
	in_price_earn_ratio = 0;
	in_retained_earn_ratio = 0;
	in_earn_pshare_ratio_growth = 0;
	in_critical_price_earn_ratio = 0;
	in_critical_earn_pshare_ratio = 0;
	in_ra = 0;
	in_rg = 0;
	in_re = 0;
	in_rj = 0;
	in_publicclassifiersystem = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	privateclassifiersystem = init_PrivateClassifierSystem();
//	current_assetportfolio = init_AssetPortfolio();
//	prescribed_assetportfolio = init_AssetPortfolio();
//	asset_budget = 0.0;
//	range = 0.0;
//	posx = 0.0;
//	posy = 0.0;
//	revenues = init_double_array();
//	sales_costs = init_double_array();
//	total_revenue = 0.0;
//	net_revenue = 0.0;
//	operational_cost = 0.0;
//	total_wage_payments = 0.0;
//	total_input_payments = 0.0;
//	interest_payments = 0.0;
//	total_earnings = 0.0;
//	tax_rate_profits = 0.0;
//	pretax_profit = 0.0;
//	tax_provision = 0.0;
//	net_earnings = 0.0;
//	div_payments = 0.0;
//	retained_earnings = 0.0;
//	current_debt = 0.0;
//	debt_interest_rate = 0.0;
//	debt_repayments = 0.0;
//	share_repurchase_value = 0.0;
//	share_repurchase_units = 0;
//	target_total_shares = 0;
//	current_total_shares = 0;
//	total_financial_needs = 0.0;
//	financial_needs = 0.0;
//	add_financial_needs = 0.0;
//	financial_reserves = 0.0;
//	target_loans = 0.0;
//	target_equity = 0.0;
//	bonds_issue_target = 0.0;
//	stocks_issue_target = 0.0;
//	price = 0.0;
//	max_debt = 0.0;
//	div_earn_ratio = 0.0;
//	debt_earn_ratio = 0.0;
//	div_pshare_ratio = 0.0;
//	earn_pshare_ratio = 0.0;
//	price_earn_ratio = 0.0;
//	retained_earn_ratio = 0.0;
//	earn_pshare_ratio_growth = 0.0;
//	critical_price_earn_ratio = 0.0;
//	critical_earn_pshare_ratio = 0.0;
//	ra = 0.0;
//	rg = 0.0;
//	re = 0.0;
//	rj = 0.0;
//	publicclassifiersystem = init_PublicClassifierSystem();







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
					printf("in agent: %s\n", agentname);
					if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
					}
					else if(strcmp(agentname, "Firm") == 0)
					{
						current_Firm_agent = init_Firm_agent();
						in_Firm_agent = 1;
					}
					else if(strcmp(agentname, "Bank") == 0)
					{
						current_Bank_agent = init_Bank_agent();
						in_Bank_agent = 1;
					}
					else if(strcmp(agentname, "ClearingHouse") == 0)
					{
						current_ClearingHouse_agent = init_ClearingHouse_agent();
						in_ClearingHouse_agent = 1;
					}
					else if(strcmp(agentname, "LimitOrderBook") == 0)
					{
						current_LimitOrderBook_agent = init_LimitOrderBook_agent();
						in_LimitOrderBook_agent = 1;
					}
					else if(strcmp(agentname, "Government") == 0)
					{
						current_Government_agent = init_Government_agent();
						in_Government_agent = 1;
					}
					else if(strcmp(agentname, "FinancialAgent") == 0)
					{
						current_FinancialAgent_agent = init_FinancialAgent_agent();
						in_FinancialAgent_agent = 1;
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
				in_Household_agent = 0;
in_Firm_agent = 0;
in_Bank_agent = 0;
in_ClearingHouse_agent = 0;
in_LimitOrderBook_agent = 0;
in_Government_agent = 0;
in_FinancialAgent_agent = 0;

				
				if(strcmp(agentname, "Household") == 0)
				{
					posx = current_Household_agent->posx;
					posy = current_Household_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Household_agent(id, privateclassifiersystem, current_assetportfolio, prescribed_assetportfolio, asset_budget, range, posx, posy);
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
								//add_Household_agent(id, privateclassifiersystem, current_assetportfolio, prescribed_assetportfolio, asset_budget, range, posx, posy);
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
								//add_Household_agent(id, privateclassifiersystem, current_assetportfolio, prescribed_assetportfolio, asset_budget, range, posx, posy);
								add_Household_agent_internal(current_Household_agent);

								current_Household_agent->posx = xcentre;
								current_Household_agent->posy = ycentre;
								current_Household_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Firm") == 0)
				{
					posx = current_Firm_agent->posx;
					posy = current_Firm_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Firm_agent(id, revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, range, posx, posy);
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
								//add_Firm_agent(id, revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, range, posx, posy);
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
								//add_Firm_agent(id, revenues, sales_costs, total_revenue, net_revenue, operational_cost, total_wage_payments, total_input_payments, interest_payments, total_earnings, tax_rate_profits, pretax_profit, tax_provision, net_earnings, div_payments, retained_earnings, current_debt, debt_interest_rate, debt_repayments, share_repurchase_value, share_repurchase_units, target_total_shares, current_total_shares, total_financial_needs, financial_needs, add_financial_needs, financial_reserves, target_loans, target_equity, bonds_issue_target, stocks_issue_target, price, max_debt, div_earn_ratio, debt_earn_ratio, div_pshare_ratio, earn_pshare_ratio, price_earn_ratio, retained_earn_ratio, earn_pshare_ratio_growth, critical_price_earn_ratio, critical_earn_pshare_ratio, range, posx, posy);
								add_Firm_agent_internal(current_Firm_agent);

								current_Firm_agent->posx = xcentre;
								current_Firm_agent->posy = ycentre;
								current_Firm_agent->range = rrange;

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
						//add_Bank_agent(id, ra, range, posx, posy);
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
								//add_Bank_agent(id, ra, range, posx, posy);
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
								//add_Bank_agent(id, ra, range, posx, posy);
								add_Bank_agent_internal(current_Bank_agent);

								current_Bank_agent->posx = xcentre;
								current_Bank_agent->posy = ycentre;
								current_Bank_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "ClearingHouse") == 0)
				{
					posx = current_ClearingHouse_agent->posx;
					posy = current_ClearingHouse_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_ClearingHouse_agent(id, rg, range, posx, posy);
						add_ClearingHouse_agent_internal(current_ClearingHouse_agent);
						
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
								//add_ClearingHouse_agent(id, rg, range, posx, posy);
								add_ClearingHouse_agent_internal(current_ClearingHouse_agent);
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
								//add_ClearingHouse_agent(id, rg, range, posx, posy);
								add_ClearingHouse_agent_internal(current_ClearingHouse_agent);

								current_ClearingHouse_agent->posx = xcentre;
								current_ClearingHouse_agent->posy = ycentre;
								current_ClearingHouse_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "LimitOrderBook") == 0)
				{
					posx = current_LimitOrderBook_agent->posx;
					posy = current_LimitOrderBook_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_LimitOrderBook_agent(id, re, range, posx, posy);
						add_LimitOrderBook_agent_internal(current_LimitOrderBook_agent);
						
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
								//add_LimitOrderBook_agent(id, re, range, posx, posy);
								add_LimitOrderBook_agent_internal(current_LimitOrderBook_agent);
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
								//add_LimitOrderBook_agent(id, re, range, posx, posy);
								add_LimitOrderBook_agent_internal(current_LimitOrderBook_agent);

								current_LimitOrderBook_agent->posx = xcentre;
								current_LimitOrderBook_agent->posy = ycentre;
								current_LimitOrderBook_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "Government") == 0)
				{
					posx = current_Government_agent->posx;
					posy = current_Government_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_Government_agent(id, rj, range, posx, posy);
						add_Government_agent_internal(current_Government_agent);
						
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
								//add_Government_agent(id, rj, range, posx, posy);
								add_Government_agent_internal(current_Government_agent);
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
								//add_Government_agent(id, rj, range, posx, posy);
								add_Government_agent_internal(current_Government_agent);

								current_Government_agent->posx = xcentre;
								current_Government_agent->posy = ycentre;
								current_Government_agent->range = rrange;

							}
							++agent_count;
						} /* if partition */

					} /* if flag */

				}
				else if(strcmp(agentname, "FinancialAgent") == 0)
				{
					posx = current_FinancialAgent_agent->posx;
					posy = current_FinancialAgent_agent->posy;
					posz = 0.0;
					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						//add_FinancialAgent_agent(id, publicclassifiersystem, range, posx, posy);
						add_FinancialAgent_agent_internal(current_FinancialAgent_agent);
						
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
								//add_FinancialAgent_agent(id, publicclassifiersystem, range, posx, posy);
								add_FinancialAgent_agent_internal(current_FinancialAgent_agent);
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
								//add_FinancialAgent_agent(id, publicclassifiersystem, range, posx, posy);
								add_FinancialAgent_agent_internal(current_FinancialAgent_agent);

								current_FinancialAgent_agent->posx = xcentre;
								current_FinancialAgent_agent->posy = ycentre;
								current_FinancialAgent_agent->range = rrange;

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
////////				asset_budget = 0.0;
//				range = 0.0;
//				posx = 0.0;
//				posy = 0.0;
//////				total_revenue = 0.0;
//				net_revenue = 0.0;
//				operational_cost = 0.0;
//				total_wage_payments = 0.0;
//				total_input_payments = 0.0;
//				interest_payments = 0.0;
//				total_earnings = 0.0;
//				tax_rate_profits = 0.0;
//				pretax_profit = 0.0;
//				tax_provision = 0.0;
//				net_earnings = 0.0;
//				div_payments = 0.0;
//				retained_earnings = 0.0;
//				current_debt = 0.0;
//				debt_interest_rate = 0.0;
//				debt_repayments = 0.0;
//				share_repurchase_value = 0.0;
//				share_repurchase_units = 0;
//				target_total_shares = 0;
//				current_total_shares = 0;
//				total_financial_needs = 0.0;
//				financial_needs = 0.0;
//				add_financial_needs = 0.0;
//				financial_reserves = 0.0;
//				target_loans = 0.0;
//				target_equity = 0.0;
//				bonds_issue_target = 0.0;
//				stocks_issue_target = 0.0;
//				price = 0.0;
//				max_debt = 0.0;
//				div_earn_ratio = 0.0;
//				debt_earn_ratio = 0.0;
//				div_pshare_ratio = 0.0;
//				earn_pshare_ratio = 0.0;
//				price_earn_ratio = 0.0;
//				retained_earn_ratio = 0.0;
//				earn_pshare_ratio_growth = 0.0;
//				critical_price_earn_ratio = 0.0;
//				critical_earn_pshare_ratio = 0.0;
//				ra = 0.0;
//				rg = 0.0;
//				re = 0.0;
//				rj = 0.0;
//
	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "privateclassifiersystem") == 0) in_privateclassifiersystem = 1;
			if(strcmp(buffer, "/privateclassifiersystem") == 0) in_privateclassifiersystem = 0;
			if(strcmp(buffer, "current_assetportfolio") == 0) in_current_assetportfolio = 1;
			if(strcmp(buffer, "/current_assetportfolio") == 0) in_current_assetportfolio = 0;
			if(strcmp(buffer, "prescribed_assetportfolio") == 0) in_prescribed_assetportfolio = 1;
			if(strcmp(buffer, "/prescribed_assetportfolio") == 0) in_prescribed_assetportfolio = 0;
			if(strcmp(buffer, "asset_budget") == 0) in_asset_budget = 1;
			if(strcmp(buffer, "/asset_budget") == 0) in_asset_budget = 0;
			if(strcmp(buffer, "range") == 0) in_range = 1;
			if(strcmp(buffer, "/range") == 0) in_range = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "revenues") == 0) in_revenues = 1;
			if(strcmp(buffer, "/revenues") == 0) in_revenues = 0;
			if(strcmp(buffer, "sales_costs") == 0) in_sales_costs = 1;
			if(strcmp(buffer, "/sales_costs") == 0) in_sales_costs = 0;
			if(strcmp(buffer, "total_revenue") == 0) in_total_revenue = 1;
			if(strcmp(buffer, "/total_revenue") == 0) in_total_revenue = 0;
			if(strcmp(buffer, "net_revenue") == 0) in_net_revenue = 1;
			if(strcmp(buffer, "/net_revenue") == 0) in_net_revenue = 0;
			if(strcmp(buffer, "operational_cost") == 0) in_operational_cost = 1;
			if(strcmp(buffer, "/operational_cost") == 0) in_operational_cost = 0;
			if(strcmp(buffer, "total_wage_payments") == 0) in_total_wage_payments = 1;
			if(strcmp(buffer, "/total_wage_payments") == 0) in_total_wage_payments = 0;
			if(strcmp(buffer, "total_input_payments") == 0) in_total_input_payments = 1;
			if(strcmp(buffer, "/total_input_payments") == 0) in_total_input_payments = 0;
			if(strcmp(buffer, "interest_payments") == 0) in_interest_payments = 1;
			if(strcmp(buffer, "/interest_payments") == 0) in_interest_payments = 0;
			if(strcmp(buffer, "total_earnings") == 0) in_total_earnings = 1;
			if(strcmp(buffer, "/total_earnings") == 0) in_total_earnings = 0;
			if(strcmp(buffer, "tax_rate_profits") == 0) in_tax_rate_profits = 1;
			if(strcmp(buffer, "/tax_rate_profits") == 0) in_tax_rate_profits = 0;
			if(strcmp(buffer, "pretax_profit") == 0) in_pretax_profit = 1;
			if(strcmp(buffer, "/pretax_profit") == 0) in_pretax_profit = 0;
			if(strcmp(buffer, "tax_provision") == 0) in_tax_provision = 1;
			if(strcmp(buffer, "/tax_provision") == 0) in_tax_provision = 0;
			if(strcmp(buffer, "net_earnings") == 0) in_net_earnings = 1;
			if(strcmp(buffer, "/net_earnings") == 0) in_net_earnings = 0;
			if(strcmp(buffer, "div_payments") == 0) in_div_payments = 1;
			if(strcmp(buffer, "/div_payments") == 0) in_div_payments = 0;
			if(strcmp(buffer, "retained_earnings") == 0) in_retained_earnings = 1;
			if(strcmp(buffer, "/retained_earnings") == 0) in_retained_earnings = 0;
			if(strcmp(buffer, "current_debt") == 0) in_current_debt = 1;
			if(strcmp(buffer, "/current_debt") == 0) in_current_debt = 0;
			if(strcmp(buffer, "debt_interest_rate") == 0) in_debt_interest_rate = 1;
			if(strcmp(buffer, "/debt_interest_rate") == 0) in_debt_interest_rate = 0;
			if(strcmp(buffer, "debt_repayments") == 0) in_debt_repayments = 1;
			if(strcmp(buffer, "/debt_repayments") == 0) in_debt_repayments = 0;
			if(strcmp(buffer, "share_repurchase_value") == 0) in_share_repurchase_value = 1;
			if(strcmp(buffer, "/share_repurchase_value") == 0) in_share_repurchase_value = 0;
			if(strcmp(buffer, "share_repurchase_units") == 0) in_share_repurchase_units = 1;
			if(strcmp(buffer, "/share_repurchase_units") == 0) in_share_repurchase_units = 0;
			if(strcmp(buffer, "target_total_shares") == 0) in_target_total_shares = 1;
			if(strcmp(buffer, "/target_total_shares") == 0) in_target_total_shares = 0;
			if(strcmp(buffer, "current_total_shares") == 0) in_current_total_shares = 1;
			if(strcmp(buffer, "/current_total_shares") == 0) in_current_total_shares = 0;
			if(strcmp(buffer, "total_financial_needs") == 0) in_total_financial_needs = 1;
			if(strcmp(buffer, "/total_financial_needs") == 0) in_total_financial_needs = 0;
			if(strcmp(buffer, "financial_needs") == 0) in_financial_needs = 1;
			if(strcmp(buffer, "/financial_needs") == 0) in_financial_needs = 0;
			if(strcmp(buffer, "add_financial_needs") == 0) in_add_financial_needs = 1;
			if(strcmp(buffer, "/add_financial_needs") == 0) in_add_financial_needs = 0;
			if(strcmp(buffer, "financial_reserves") == 0) in_financial_reserves = 1;
			if(strcmp(buffer, "/financial_reserves") == 0) in_financial_reserves = 0;
			if(strcmp(buffer, "target_loans") == 0) in_target_loans = 1;
			if(strcmp(buffer, "/target_loans") == 0) in_target_loans = 0;
			if(strcmp(buffer, "target_equity") == 0) in_target_equity = 1;
			if(strcmp(buffer, "/target_equity") == 0) in_target_equity = 0;
			if(strcmp(buffer, "bonds_issue_target") == 0) in_bonds_issue_target = 1;
			if(strcmp(buffer, "/bonds_issue_target") == 0) in_bonds_issue_target = 0;
			if(strcmp(buffer, "stocks_issue_target") == 0) in_stocks_issue_target = 1;
			if(strcmp(buffer, "/stocks_issue_target") == 0) in_stocks_issue_target = 0;
			if(strcmp(buffer, "price") == 0) in_price = 1;
			if(strcmp(buffer, "/price") == 0) in_price = 0;
			if(strcmp(buffer, "max_debt") == 0) in_max_debt = 1;
			if(strcmp(buffer, "/max_debt") == 0) in_max_debt = 0;
			if(strcmp(buffer, "div_earn_ratio") == 0) in_div_earn_ratio = 1;
			if(strcmp(buffer, "/div_earn_ratio") == 0) in_div_earn_ratio = 0;
			if(strcmp(buffer, "debt_earn_ratio") == 0) in_debt_earn_ratio = 1;
			if(strcmp(buffer, "/debt_earn_ratio") == 0) in_debt_earn_ratio = 0;
			if(strcmp(buffer, "div_pshare_ratio") == 0) in_div_pshare_ratio = 1;
			if(strcmp(buffer, "/div_pshare_ratio") == 0) in_div_pshare_ratio = 0;
			if(strcmp(buffer, "earn_pshare_ratio") == 0) in_earn_pshare_ratio = 1;
			if(strcmp(buffer, "/earn_pshare_ratio") == 0) in_earn_pshare_ratio = 0;
			if(strcmp(buffer, "price_earn_ratio") == 0) in_price_earn_ratio = 1;
			if(strcmp(buffer, "/price_earn_ratio") == 0) in_price_earn_ratio = 0;
			if(strcmp(buffer, "retained_earn_ratio") == 0) in_retained_earn_ratio = 1;
			if(strcmp(buffer, "/retained_earn_ratio") == 0) in_retained_earn_ratio = 0;
			if(strcmp(buffer, "earn_pshare_ratio_growth") == 0) in_earn_pshare_ratio_growth = 1;
			if(strcmp(buffer, "/earn_pshare_ratio_growth") == 0) in_earn_pshare_ratio_growth = 0;
			if(strcmp(buffer, "critical_price_earn_ratio") == 0) in_critical_price_earn_ratio = 1;
			if(strcmp(buffer, "/critical_price_earn_ratio") == 0) in_critical_price_earn_ratio = 0;
			if(strcmp(buffer, "critical_earn_pshare_ratio") == 0) in_critical_earn_pshare_ratio = 1;
			if(strcmp(buffer, "/critical_earn_pshare_ratio") == 0) in_critical_earn_pshare_ratio = 0;
			if(strcmp(buffer, "ra") == 0) in_ra = 1;
			if(strcmp(buffer, "/ra") == 0) in_ra = 0;
			if(strcmp(buffer, "rg") == 0) in_rg = 1;
			if(strcmp(buffer, "/rg") == 0) in_rg = 0;
			if(strcmp(buffer, "re") == 0) in_re = 1;
			if(strcmp(buffer, "/re") == 0) in_re = 0;
			if(strcmp(buffer, "rj") == 0) in_rj = 1;
			if(strcmp(buffer, "/rj") == 0) in_rj = 0;
			if(strcmp(buffer, "publicclassifiersystem") == 0) in_publicclassifiersystem = 1;
			if(strcmp(buffer, "/publicclassifiersystem") == 0) in_publicclassifiersystem = 0;


			
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
			else if(in_Household_agent == 1)
			{
				if(in_id) current_Household_agent->id = atoi(buffer);
				if(in_privateclassifiersystem)
				{
					j = 0;
					read_PrivateClassifierSystem(buffer, &j, current_Household_agent->privateclassifiersystem);
				}
				if(in_current_assetportfolio)
				{
					j = 0;
					read_AssetPortfolio(buffer, &j, current_Household_agent->current_assetportfolio);
				}
				if(in_prescribed_assetportfolio)
				{
					j = 0;
					read_AssetPortfolio(buffer, &j, current_Household_agent->prescribed_assetportfolio);
				}
				if(in_asset_budget) current_Household_agent->asset_budget = atof(buffer);
				if(in_range) current_Household_agent->range = atof(buffer);
				if(in_posx) current_Household_agent->posx = atof(buffer);
				if(in_posy) current_Household_agent->posy = atof(buffer);
			}else if(in_Firm_agent == 1)
			{
				if(in_id) current_Firm_agent->id = atoi(buffer);
				if(in_revenues)
				{
					j = 0;
					read_double_dynamic_array(buffer, &j, current_Firm_agent->revenues);
				}
				if(in_sales_costs)
				{
					j = 0;
					read_double_dynamic_array(buffer, &j, current_Firm_agent->sales_costs);
				}
				if(in_total_revenue) current_Firm_agent->total_revenue = atof(buffer);
				if(in_net_revenue) current_Firm_agent->net_revenue = atof(buffer);
				if(in_operational_cost) current_Firm_agent->operational_cost = atof(buffer);
				if(in_total_wage_payments) current_Firm_agent->total_wage_payments = atof(buffer);
				if(in_total_input_payments) current_Firm_agent->total_input_payments = atof(buffer);
				if(in_interest_payments) current_Firm_agent->interest_payments = atof(buffer);
				if(in_total_earnings) current_Firm_agent->total_earnings = atof(buffer);
				if(in_tax_rate_profits) current_Firm_agent->tax_rate_profits = atof(buffer);
				if(in_pretax_profit) current_Firm_agent->pretax_profit = atof(buffer);
				if(in_tax_provision) current_Firm_agent->tax_provision = atof(buffer);
				if(in_net_earnings) current_Firm_agent->net_earnings = atof(buffer);
				if(in_div_payments) current_Firm_agent->div_payments = atof(buffer);
				if(in_retained_earnings) current_Firm_agent->retained_earnings = atof(buffer);
				if(in_current_debt) current_Firm_agent->current_debt = atof(buffer);
				if(in_debt_interest_rate) current_Firm_agent->debt_interest_rate = atof(buffer);
				if(in_debt_repayments) current_Firm_agent->debt_repayments = atof(buffer);
				if(in_share_repurchase_value) current_Firm_agent->share_repurchase_value = atof(buffer);
				if(in_share_repurchase_units) current_Firm_agent->share_repurchase_units = atoi(buffer);
				if(in_target_total_shares) current_Firm_agent->target_total_shares = atoi(buffer);
				if(in_current_total_shares) current_Firm_agent->current_total_shares = atoi(buffer);
				if(in_total_financial_needs) current_Firm_agent->total_financial_needs = atof(buffer);
				if(in_financial_needs) current_Firm_agent->financial_needs = atof(buffer);
				if(in_add_financial_needs) current_Firm_agent->add_financial_needs = atof(buffer);
				if(in_financial_reserves) current_Firm_agent->financial_reserves = atof(buffer);
				if(in_target_loans) current_Firm_agent->target_loans = atof(buffer);
				if(in_target_equity) current_Firm_agent->target_equity = atof(buffer);
				if(in_bonds_issue_target) current_Firm_agent->bonds_issue_target = atof(buffer);
				if(in_stocks_issue_target) current_Firm_agent->stocks_issue_target = atof(buffer);
				if(in_price) current_Firm_agent->price = atof(buffer);
				if(in_max_debt) current_Firm_agent->max_debt = atof(buffer);
				if(in_div_earn_ratio) current_Firm_agent->div_earn_ratio = atof(buffer);
				if(in_debt_earn_ratio) current_Firm_agent->debt_earn_ratio = atof(buffer);
				if(in_div_pshare_ratio) current_Firm_agent->div_pshare_ratio = atof(buffer);
				if(in_earn_pshare_ratio) current_Firm_agent->earn_pshare_ratio = atof(buffer);
				if(in_price_earn_ratio) current_Firm_agent->price_earn_ratio = atof(buffer);
				if(in_retained_earn_ratio) current_Firm_agent->retained_earn_ratio = atof(buffer);
				if(in_earn_pshare_ratio_growth) current_Firm_agent->earn_pshare_ratio_growth = atof(buffer);
				if(in_critical_price_earn_ratio) current_Firm_agent->critical_price_earn_ratio = atof(buffer);
				if(in_critical_earn_pshare_ratio) current_Firm_agent->critical_earn_pshare_ratio = atof(buffer);
				if(in_range) current_Firm_agent->range = atof(buffer);
				if(in_posx) current_Firm_agent->posx = atof(buffer);
				if(in_posy) current_Firm_agent->posy = atof(buffer);
			}else if(in_Bank_agent == 1)
			{
				if(in_id) current_Bank_agent->id = atoi(buffer);
				if(in_ra) current_Bank_agent->ra = atof(buffer);
				if(in_range) current_Bank_agent->range = atof(buffer);
				if(in_posx) current_Bank_agent->posx = atof(buffer);
				if(in_posy) current_Bank_agent->posy = atof(buffer);
			}else if(in_ClearingHouse_agent == 1)
			{
				if(in_id) current_ClearingHouse_agent->id = atoi(buffer);
				if(in_rg) current_ClearingHouse_agent->rg = atof(buffer);
				if(in_range) current_ClearingHouse_agent->range = atof(buffer);
				if(in_posx) current_ClearingHouse_agent->posx = atof(buffer);
				if(in_posy) current_ClearingHouse_agent->posy = atof(buffer);
			}else if(in_LimitOrderBook_agent == 1)
			{
				if(in_id) current_LimitOrderBook_agent->id = atoi(buffer);
				if(in_re) current_LimitOrderBook_agent->re = atof(buffer);
				if(in_range) current_LimitOrderBook_agent->range = atof(buffer);
				if(in_posx) current_LimitOrderBook_agent->posx = atof(buffer);
				if(in_posy) current_LimitOrderBook_agent->posy = atof(buffer);
			}else if(in_Government_agent == 1)
			{
				if(in_id) current_Government_agent->id = atoi(buffer);
				if(in_rj) current_Government_agent->rj = atof(buffer);
				if(in_range) current_Government_agent->range = atof(buffer);
				if(in_posx) current_Government_agent->posx = atof(buffer);
				if(in_posy) current_Government_agent->posy = atof(buffer);
			}else if(in_FinancialAgent_agent == 1)
			{
				if(in_id) current_FinancialAgent_agent->id = atoi(buffer);
				if(in_publicclassifiersystem)
				{
					j = 0;
					read_PublicClassifierSystem(buffer, &j, current_FinancialAgent_agent->publicclassifiersystem);
				}
				if(in_range) current_FinancialAgent_agent->range = atof(buffer);
				if(in_posx) current_FinancialAgent_agent->posx = atof(buffer);
				if(in_posy) current_FinancialAgent_agent->posy = atof(buffer);
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
////	free_PrivateClassifierSystem_datatype(privateclassifiersystem);
//	free_AssetPortfolio_datatype(current_assetportfolio);
//	free_AssetPortfolio_datatype(prescribed_assetportfolio);
//////////	free_double_array(revenues);
//	free_double_array(sales_costs);
////////////////////////////////////////////////////////////////////////////////////////	free_PublicClassifierSystem_datatype(publicclassifiersystem);

}

/** \fn void saveiterationdata_binary(int iteration_number)
 * \brief Save X-machine memory to a binary file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata_binary(int iteration_number)
{
	/* Pointer to file */
	FILE *file;
	char data[100];
	int i;
	int agentcount = 0;
	xmachine_memory_Household * current_Household;
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Bank * current_Bank;
	xmachine_memory_ClearingHouse * current_ClearingHouse;
	xmachine_memory_LimitOrderBook * current_LimitOrderBook;
	xmachine_memory_Government * current_Government;
	xmachine_memory_FinancialAgent * current_FinancialAgent;

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
		if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			agentcount++;
		}
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			current_ClearingHouse = current_xmachine->xmachine_ClearingHouse;
			agentcount++;
		}
		else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			current_LimitOrderBook = current_xmachine->xmachine_LimitOrderBook;
			agentcount++;
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			current_Government = current_xmachine->xmachine_Government;
			agentcount++;
		}
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			current_FinancialAgent = current_xmachine->xmachine_FinancialAgent;
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
	char data[100];
	
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
	char data[100];
	
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
	char data[100];
	
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
	char data[100];
	
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
	char data[100];
	
	fputs("{", file);
	for(i=0; i<temp->size; i++)
	{
		sprintf(data, "%i", temp->array[i]);
		fputs(data, file);
		if(i < (temp->size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[100];
	
	fputs("{", file);
	for(i=0; i<temp->size; i++)
	{
		sprintf(data, "%f", temp->array[i]);
		fputs(data, file);
		if(i < (temp->size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[100];
	
	fputs("{", file);
	for(i=0; i<temp->size; i++)
	{
		sprintf(data, "%f", temp->array[i]);
		fputs(data, file);
		if(i < (temp->size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[100];
	
	for(i=0; i<temp->size; i++)
	{
		sprintf(data, "%c", temp->array[i]);
		fputs(data, file);
	}
}

/** \fn void write_string(FILE *file, string * temp_datatype)
 * \brief Writes string datatype.
 */
void write_string(FILE *file, string * temp_datatype)
{
	
	
	fputs("{", file);
	write_char_dynamic_array(file, temp_datatype->stringname);
	fputs("}", file);
}

void write_string_static_array(FILE *file, string ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_string(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_string_dynamic_array(FILE *file, string_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_string(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_stringlist(FILE *file, stringlist * temp_datatype)
 * \brief Writes stringlist datatype.
 */
void write_stringlist(FILE *file, stringlist * temp_datatype)
{
	
	
	fputs("{", file);
	write_string_dynamic_array(file, temp_datatype->stringlistname);
	fputs("}", file);
}

void write_stringlist_static_array(FILE *file, stringlist ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_stringlist(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_stringlist_dynamic_array(FILE *file, stringlist_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_stringlist(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_word(FILE *file, word * temp_datatype)
 * \brief Writes word datatype.
 */
void write_word(FILE *file, word * temp_datatype)
{
	
	
	fputs("{", file);
	write_char_dynamic_array(file, temp_datatype->wordname);
	fputs("}", file);
}

void write_word_static_array(FILE *file, word ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_word(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_word_dynamic_array(FILE *file, word_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_word(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_wordlist(FILE *file, wordlist * temp_datatype)
 * \brief Writes wordlist datatype.
 */
void write_wordlist(FILE *file, wordlist * temp_datatype)
{
	
	
	fputs("{", file);
	write_word_dynamic_array(file, temp_datatype->wordlistname);
	fputs("}", file);
}

void write_wordlist_static_array(FILE *file, wordlist ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_wordlist(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_wordlist_dynamic_array(FILE *file, wordlist_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_wordlist(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_int2D(FILE *file, int2D * temp_datatype)
 * \brief Writes int2D datatype.
 */
void write_int2D(FILE *file, int2D * temp_datatype)
{
	
	
	fputs("{", file);
	write_int_dynamic_array(file, temp_datatype->int2Dname);
	fputs("}", file);
}

void write_int2D_static_array(FILE *file, int2D ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_int2D(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_int2D_dynamic_array(FILE *file, int2D_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_int2D(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double2D(FILE *file, double2D * temp_datatype)
 * \brief Writes double2D datatype.
 */
void write_double2D(FILE *file, double2D * temp_datatype)
{
	
	
	fputs("{", file);
	write_double_dynamic_array(file, temp_datatype->double2Dname);
	fputs("}", file);
}

void write_double2D_static_array(FILE *file, double2D ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_double2D(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_double2D_dynamic_array(FILE *file, double2D_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_double2D(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_RuleDetailSystem(FILE *file, RuleDetailSystem * temp_datatype)
 * \brief Writes RuleDetailSystem datatype.
 */
void write_RuleDetailSystem(FILE *file, RuleDetailSystem * temp_datatype)
{
	
	
	fputs("{", file);
	write_int_dynamic_array(file, temp_datatype->nr_params_per_type);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->nr_params);
	fputs(", ", file);	write_double2D_dynamic_array(file, temp_datatype->parameters);
	fputs(", ", file);	write_wordlist(file, temp_datatype->myfunctionnames);
	fputs("}", file);
}

void write_RuleDetailSystem_static_array(FILE *file, RuleDetailSystem ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_RuleDetailSystem(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_RuleDetailSystem_dynamic_array(FILE *file, RuleDetailSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_RuleDetailSystem(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_PublicClassifierSystem(FILE *file, PublicClassifierSystem * temp_datatype)
 * \brief Writes PublicClassifierSystem datatype.
 */
void write_PublicClassifierSystem(FILE *file, PublicClassifierSystem * temp_datatype)
{
	char data[100];
	
	fputs("{", file);
	sprintf(data, "%i", temp_datatype->nr_types);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->nr_rules_per_type);
	fputs(", ", file);	sprintf(data, "%i", temp_datatype->nr_rules);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->ids);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->rule_type);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->counter);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->performance);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->avgperformance);
	fputs("}", file);
}

void write_PublicClassifierSystem_static_array(FILE *file, PublicClassifierSystem ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_PublicClassifierSystem(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_PublicClassifierSystem_dynamic_array(FILE *file, PublicClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_PublicClassifierSystem(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_PrivateClassifierSystem(FILE *file, PrivateClassifierSystem * temp_datatype)
 * \brief Writes PrivateClassifierSystem datatype.
 */
void write_PrivateClassifierSystem(FILE *file, PrivateClassifierSystem * temp_datatype)
{
	char data[100];
	
	fputs("{", file);
	sprintf(data, "%i", temp_datatype->nr_types);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->nr_rules_per_type);
	fputs(", ", file);	sprintf(data, "%i", temp_datatype->nr_rules);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->ids);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->rule_type);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->EWA_rho);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->EWA_phi);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->EWA_delta);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->EWA_beta);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", temp_datatype->experience);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", temp_datatype->current_rule);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->my_performance);
	fputs(data, file);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->avgperformance);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->attraction);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->choiceprob);
	fputs("}", file);
}

void write_PrivateClassifierSystem_static_array(FILE *file, PrivateClassifierSystem ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_PrivateClassifierSystem(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_PrivateClassifierSystem_dynamic_array(FILE *file, PrivateClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_PrivateClassifierSystem(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_StockDataType(FILE *file, StockDataType * temp_datatype)
 * \brief Writes StockDataType datatype.
 */
void write_StockDataType(FILE *file, StockDataType * temp_datatype)
{
	char data[100];
	
	fputs("{", file);
	write_char_static_array(file, temp_datatype->class, 5);
	fputs(", ", file);	write_int_static_array(file, temp_datatype->id, 5);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->NrOutStandingShares);
	fputs(", ", file);	sprintf(data, "%f", temp_datatype->price);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", temp_datatype->Book_intraday_transaction);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->dividends);
	fputs("}", file);
}

void write_StockDataType_static_array(FILE *file, StockDataType ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_StockDataType(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_StockDataType_dynamic_array(FILE *file, StockDataType_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_StockDataType(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_BondDataType(FILE *file, BondDataType * temp_datatype)
 * \brief Writes BondDataType datatype.
 */
void write_BondDataType(FILE *file, BondDataType * temp_datatype)
{
	
	
	fputs("{", file);
	write_char_static_array(file, temp_datatype->class, 5);
	fputs(", ", file);	write_int_static_array(file, temp_datatype->id, 5);
	fputs("}", file);
}

void write_BondDataType_static_array(FILE *file, BondDataType ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_BondDataType(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_BondDataType_dynamic_array(FILE *file, BondDataType_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_BondDataType(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_DBFinancialAssets(FILE *file, DBFinancialAssets * temp_datatype)
 * \brief Writes DBFinancialAssets datatype.
 */
void write_DBFinancialAssets(FILE *file, DBFinancialAssets * temp_datatype)
{
	
	
	fputs("{", file);

	fputs("}", file);
}

void write_DBFinancialAssets_static_array(FILE *file, DBFinancialAssets ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_DBFinancialAssets(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_DBFinancialAssets_dynamic_array(FILE *file, DBFinancialAssets_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_DBFinancialAssets(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_Asset(FILE *file, Asset * temp_datatype)
 * \brief Writes Asset datatype.
 */
void write_Asset(FILE *file, Asset * temp_datatype)
{
	
	
	fputs("{", file);
	write_int_dynamic_array(file, temp_datatype->ids);
	fputs(", ", file);	write_int_dynamic_array(file, temp_datatype->nr_units);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->current_price);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->best_ask_price);
	fputs(", ", file);	write_double_dynamic_array(file, temp_datatype->best_bid_price);
	fputs("}", file);
}

void write_Asset_static_array(FILE *file, Asset ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_Asset(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_Asset_dynamic_array(FILE *file, Asset_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_Asset(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_AssetPortfolio(FILE *file, AssetPortfolio * temp_datatype)
 * \brief Writes AssetPortfolio datatype.
 */
void write_AssetPortfolio(FILE *file, AssetPortfolio * temp_datatype)
{
	
	
	fputs("{", file);
	write_double_dynamic_array(file, temp_datatype->performance_history);
	fputs(", ", file);	write_Asset(file, temp_datatype->firm_stocks);
	fputs(", ", file);	write_Asset(file, temp_datatype->firm_bonds);
	fputs(", ", file);	write_Asset(file, temp_datatype->gov_bonds);
	fputs("}", file);
}

void write_AssetPortfolio_static_array(FILE *file, AssetPortfolio ** temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_AssetPortfolio(file, temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_AssetPortfolio_dynamic_array(FILE *file, AssetPortfolio_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < temp_datatype->size; i++)
	{
		write_AssetPortfolio(file, temp_datatype->array[i]);
		
		if(i < temp_datatype->size - 1) fputs(", ", file);
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
	char data[100];
	xmachine_memory_Household * current_Household;
	xmachine_memory_Firm * current_Firm;
	xmachine_memory_Bank * current_Bank;
	xmachine_memory_ClearingHouse * current_ClearingHouse;
	xmachine_memory_LimitOrderBook * current_LimitOrderBook;
	xmachine_memory_Government * current_Government;
	xmachine_memory_FinancialAgent * current_FinancialAgent;
	//double_array * revenues;
	//double_array * sales_costs;
	
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
		if(current_xmachine->xmachine_Household != NULL)
		{
			current_Household = current_xmachine->xmachine_Household;
			fputs("<name>Household</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Household->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<privateclassifiersystem>", file);
			write_PrivateClassifierSystem(file, current_Household->privateclassifiersystem);
			fputs("</privateclassifiersystem>\n", file);
			fputs("<current_assetportfolio>", file);
			write_AssetPortfolio(file, current_Household->current_assetportfolio);
			fputs("</current_assetportfolio>\n", file);
			fputs("<prescribed_assetportfolio>", file);
			write_AssetPortfolio(file, current_Household->prescribed_assetportfolio);
			fputs("</prescribed_assetportfolio>\n", file);
			fputs("<asset_budget>", file);
			sprintf(data, "%f", current_Household->asset_budget);
			fputs(data, file);
			fputs("</asset_budget>\n", file);
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
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			current_Firm = current_xmachine->xmachine_Firm;
			fputs("<name>Firm</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Firm->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<revenues>", file);
			write_double_dynamic_array(file, current_Firm->revenues);
			fputs("</revenues>\n", file);
			fputs("<sales_costs>", file);
			write_double_dynamic_array(file, current_Firm->sales_costs);
			fputs("</sales_costs>\n", file);
			fputs("<total_revenue>", file);
			sprintf(data, "%f", current_Firm->total_revenue);
			fputs(data, file);
			fputs("</total_revenue>\n", file);
			fputs("<net_revenue>", file);
			sprintf(data, "%f", current_Firm->net_revenue);
			fputs(data, file);
			fputs("</net_revenue>\n", file);
			fputs("<operational_cost>", file);
			sprintf(data, "%f", current_Firm->operational_cost);
			fputs(data, file);
			fputs("</operational_cost>\n", file);
			fputs("<total_wage_payments>", file);
			sprintf(data, "%f", current_Firm->total_wage_payments);
			fputs(data, file);
			fputs("</total_wage_payments>\n", file);
			fputs("<total_input_payments>", file);
			sprintf(data, "%f", current_Firm->total_input_payments);
			fputs(data, file);
			fputs("</total_input_payments>\n", file);
			fputs("<interest_payments>", file);
			sprintf(data, "%f", current_Firm->interest_payments);
			fputs(data, file);
			fputs("</interest_payments>\n", file);
			fputs("<total_earnings>", file);
			sprintf(data, "%f", current_Firm->total_earnings);
			fputs(data, file);
			fputs("</total_earnings>\n", file);
			fputs("<tax_rate_profits>", file);
			sprintf(data, "%f", current_Firm->tax_rate_profits);
			fputs(data, file);
			fputs("</tax_rate_profits>\n", file);
			fputs("<pretax_profit>", file);
			sprintf(data, "%f", current_Firm->pretax_profit);
			fputs(data, file);
			fputs("</pretax_profit>\n", file);
			fputs("<tax_provision>", file);
			sprintf(data, "%f", current_Firm->tax_provision);
			fputs(data, file);
			fputs("</tax_provision>\n", file);
			fputs("<net_earnings>", file);
			sprintf(data, "%f", current_Firm->net_earnings);
			fputs(data, file);
			fputs("</net_earnings>\n", file);
			fputs("<div_payments>", file);
			sprintf(data, "%f", current_Firm->div_payments);
			fputs(data, file);
			fputs("</div_payments>\n", file);
			fputs("<retained_earnings>", file);
			sprintf(data, "%f", current_Firm->retained_earnings);
			fputs(data, file);
			fputs("</retained_earnings>\n", file);
			fputs("<current_debt>", file);
			sprintf(data, "%f", current_Firm->current_debt);
			fputs(data, file);
			fputs("</current_debt>\n", file);
			fputs("<debt_interest_rate>", file);
			sprintf(data, "%f", current_Firm->debt_interest_rate);
			fputs(data, file);
			fputs("</debt_interest_rate>\n", file);
			fputs("<debt_repayments>", file);
			sprintf(data, "%f", current_Firm->debt_repayments);
			fputs(data, file);
			fputs("</debt_repayments>\n", file);
			fputs("<share_repurchase_value>", file);
			sprintf(data, "%f", current_Firm->share_repurchase_value);
			fputs(data, file);
			fputs("</share_repurchase_value>\n", file);
			fputs("<share_repurchase_units>", file);
			sprintf(data, "%i", current_Firm->share_repurchase_units);
			fputs(data, file);
			fputs("</share_repurchase_units>\n", file);
			fputs("<target_total_shares>", file);
			sprintf(data, "%i", current_Firm->target_total_shares);
			fputs(data, file);
			fputs("</target_total_shares>\n", file);
			fputs("<current_total_shares>", file);
			sprintf(data, "%i", current_Firm->current_total_shares);
			fputs(data, file);
			fputs("</current_total_shares>\n", file);
			fputs("<total_financial_needs>", file);
			sprintf(data, "%f", current_Firm->total_financial_needs);
			fputs(data, file);
			fputs("</total_financial_needs>\n", file);
			fputs("<financial_needs>", file);
			sprintf(data, "%f", current_Firm->financial_needs);
			fputs(data, file);
			fputs("</financial_needs>\n", file);
			fputs("<add_financial_needs>", file);
			sprintf(data, "%f", current_Firm->add_financial_needs);
			fputs(data, file);
			fputs("</add_financial_needs>\n", file);
			fputs("<financial_reserves>", file);
			sprintf(data, "%f", current_Firm->financial_reserves);
			fputs(data, file);
			fputs("</financial_reserves>\n", file);
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
			fputs("<price>", file);
			sprintf(data, "%f", current_Firm->price);
			fputs(data, file);
			fputs("</price>\n", file);
			fputs("<max_debt>", file);
			sprintf(data, "%f", current_Firm->max_debt);
			fputs(data, file);
			fputs("</max_debt>\n", file);
			fputs("<div_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->div_earn_ratio);
			fputs(data, file);
			fputs("</div_earn_ratio>\n", file);
			fputs("<debt_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->debt_earn_ratio);
			fputs(data, file);
			fputs("</debt_earn_ratio>\n", file);
			fputs("<div_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->div_pshare_ratio);
			fputs(data, file);
			fputs("</div_pshare_ratio>\n", file);
			fputs("<earn_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->earn_pshare_ratio);
			fputs(data, file);
			fputs("</earn_pshare_ratio>\n", file);
			fputs("<price_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->price_earn_ratio);
			fputs(data, file);
			fputs("</price_earn_ratio>\n", file);
			fputs("<retained_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->retained_earn_ratio);
			fputs(data, file);
			fputs("</retained_earn_ratio>\n", file);
			fputs("<earn_pshare_ratio_growth>", file);
			sprintf(data, "%f", current_Firm->earn_pshare_ratio_growth);
			fputs(data, file);
			fputs("</earn_pshare_ratio_growth>\n", file);
			fputs("<critical_price_earn_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_price_earn_ratio);
			fputs(data, file);
			fputs("</critical_price_earn_ratio>\n", file);
			fputs("<critical_earn_pshare_ratio>", file);
			sprintf(data, "%f", current_Firm->critical_earn_pshare_ratio);
			fputs(data, file);
			fputs("</critical_earn_pshare_ratio>\n", file);
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
		else if(current_xmachine->xmachine_Bank != NULL)
		{
			current_Bank = current_xmachine->xmachine_Bank;
			fputs("<name>Bank</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Bank->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<ra>", file);
			sprintf(data, "%f", current_Bank->ra);
			fputs(data, file);
			fputs("</ra>\n", file);
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
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			current_ClearingHouse = current_xmachine->xmachine_ClearingHouse;
			fputs("<name>ClearingHouse</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_ClearingHouse->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<rg>", file);
			sprintf(data, "%f", current_ClearingHouse->rg);
			fputs(data, file);
			fputs("</rg>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_ClearingHouse->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_ClearingHouse->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_ClearingHouse->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_LimitOrderBook != NULL)
		{
			current_LimitOrderBook = current_xmachine->xmachine_LimitOrderBook;
			fputs("<name>LimitOrderBook</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_LimitOrderBook->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<re>", file);
			sprintf(data, "%f", current_LimitOrderBook->re);
			fputs(data, file);
			fputs("</re>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_LimitOrderBook->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_LimitOrderBook->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_LimitOrderBook->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_Government != NULL)
		{
			current_Government = current_xmachine->xmachine_Government;
			fputs("<name>Government</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_Government->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<rj>", file);
			sprintf(data, "%f", current_Government->rj);
			fputs(data, file);
			fputs("</rj>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_Government->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Government->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Government->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			current_FinancialAgent = current_xmachine->xmachine_FinancialAgent;
			fputs("<name>FinancialAgent</name>\n", file);
			fputs("<id>", file);
			sprintf(data, "%i", current_FinancialAgent->id);
			fputs(data, file);
			fputs("</id>\n", file);
			fputs("<publicclassifiersystem>", file);
			write_PublicClassifierSystem(file, current_FinancialAgent->publicclassifiersystem);
			fputs("</publicclassifiersystem>\n", file);
			fputs("<range>", file);
			sprintf(data, "%f", current_FinancialAgent->range);
			fputs(data, file);
			fputs("</range>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_FinancialAgent->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_FinancialAgent->posy);
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
