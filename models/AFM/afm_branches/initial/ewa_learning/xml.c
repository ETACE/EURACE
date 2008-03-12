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


/** \fn void read_EWAParameterStruct(char * buffer, int * j, EWAParameterStruct * temp_datatype)
 * \brief Reads EWAParameterStruct datatype.
 */
void read_EWAParameterStruct(char * buffer, int * j, EWAParameterStruct * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).EWA_rho = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).EWA_rho = atof(arraydata);
	(*j)++;
	(*temp_datatype).EWA_phi = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).EWA_phi = atof(arraydata);
	(*j)++;
	(*temp_datatype).EWA_delta = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).EWA_delta = atof(arraydata);
	(*j)++;
	(*temp_datatype).EWA_beta = 0.0;
	array_k = 0;
	while(buffer[*j] != '}')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).EWA_beta = atof(arraydata);
	(*j)++;
}

void read_EWAParameterStruct_dynamic_array(char * buffer, int * j, EWAParameterStruct_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_EWAParameterStruct(temp_datatype_array, 0.0, 0.0, 0.0, 0.0);
			read_EWAParameterStruct(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_EWAParameterStruct_static_array(char * buffer, int * j, EWAParameterStruct * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_EWAParameterStruct(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_GAParameterStruct(char * buffer, int * j, GAParameterStruct * temp_datatype)
 * \brief Reads GAParameterStruct datatype.
 */
void read_GAParameterStruct(char * buffer, int * j, GAParameterStruct * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).prob_cross = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).prob_cross = atof(arraydata);
	(*j)++;
	(*temp_datatype).prob_mut = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).prob_mut = atof(arraydata);
	(*j)++;
	(*temp_datatype).size = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).size = atoi(arraydata);
	(*j)++;
	(*temp_datatype).pop_size = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).pop_size = atoi(arraydata);
	(*j)++;
	(*temp_datatype).reproduction_proportion = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).reproduction_proportion = atof(arraydata);
	(*j)++;
	(*temp_datatype).single_point_cross_over = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).single_point_cross_over = atoi(arraydata);
	(*j)++;
	(*temp_datatype).election = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).election = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).stepsize, 10);
	}
	
	(*j)++;
}

void read_GAParameterStruct_dynamic_array(char * buffer, int * j, GAParameterStruct_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_GAParameterStruct(temp_datatype_array, 0.0, 0.0, 0, 0, 0.0, 0, 0, NULL);
			read_GAParameterStruct(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_GAParameterStruct_static_array(char * buffer, int * j, GAParameterStruct * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_GAParameterStruct(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_PublicClassifierRule(char * buffer, int * j, PublicClassifierRule * temp_datatype)
 * \brief Reads PublicClassifierRule datatype.
 */
void read_PublicClassifierRule(char * buffer, int * j, PublicClassifierRule * temp_datatype)
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
	(*temp_datatype).counter = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).counter = atoi(arraydata);
	(*j)++;
	(*temp_datatype).performance = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).performance = atof(arraydata);
	(*j)++;
	(*temp_datatype).avg_performance = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).avg_performance = atof(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).parameters, 10);
	}
	
	(*j)++;
}

void read_PublicClassifierRule_dynamic_array(char * buffer, int * j, PublicClassifierRule_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_PublicClassifierRule(temp_datatype_array, 0, 0, 0.0, 0.0, NULL);
			read_PublicClassifierRule(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_PublicClassifierRule_static_array(char * buffer, int * j, PublicClassifierRule * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_PublicClassifierRule(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_PrivateClassifierRule(char * buffer, int * j, PrivateClassifierRule * temp_datatype)
 * \brief Reads PrivateClassifierRule datatype.
 */
void read_PrivateClassifierRule(char * buffer, int * j, PrivateClassifierRule * temp_datatype)
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
	(*temp_datatype).my_performance = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).my_performance = atof(arraydata);
	(*j)++;
	(*temp_datatype).avg_performance = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).avg_performance = atof(arraydata);
	(*j)++;
	(*temp_datatype).attraction = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).attraction = atof(arraydata);
	(*j)++;
	(*temp_datatype).choiceprob = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).choiceprob = atof(arraydata);
	(*j)++;

	while(buffer[*j] != '}')
	{
		while(buffer[*j] != '{') (*j)++;
		read_double_static_array(buffer, j, (*temp_datatype).parameters, 10);
	}
	
	(*j)++;
}

void read_PrivateClassifierRule_dynamic_array(char * buffer, int * j, PrivateClassifierRule_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_PrivateClassifierRule(temp_datatype_array, 0, 0.0, 0.0, 0.0, 0.0, NULL);
			read_PrivateClassifierRule(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_PrivateClassifierRule_static_array(char * buffer, int * j, PrivateClassifierRule * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_PrivateClassifierRule(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_SimplePublicClassifierSystem(char * buffer, int * j, SimplePublicClassifierSystem * temp_datatype)
 * \brief Reads SimplePublicClassifierSystem datatype.
 */
void read_SimplePublicClassifierSystem(char * buffer, int * j, SimplePublicClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_rules = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_PublicClassifierRule_static_array(buffer, j, (*temp_datatype).ruletable, 100);
	
	(*j)++;
}

void read_SimplePublicClassifierSystem_dynamic_array(char * buffer, int * j, SimplePublicClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_SimplePublicClassifierSystem(temp_datatype_array, 0, NULL);
			read_SimplePublicClassifierSystem(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_SimplePublicClassifierSystem_static_array(char * buffer, int * j, SimplePublicClassifierSystem * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_SimplePublicClassifierSystem(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_SimplePrivateClassifierSystem(char * buffer, int * j, SimplePrivateClassifierSystem * temp_datatype)
 * \brief Reads SimplePrivateClassifierSystem datatype.
 */
void read_SimplePrivateClassifierSystem(char * buffer, int * j, SimplePrivateClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_rules = atoi(arraydata);
	(*j)++;
	(*temp_datatype).experience = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).experience = atof(arraydata);
	(*j)++;
	(*temp_datatype).current_rule = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_rule = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_PrivateClassifierRule_static_array(buffer, j, (*temp_datatype).ruletable, 100);
	
	(*j)++;
}

void read_SimplePrivateClassifierSystem_dynamic_array(char * buffer, int * j, SimplePrivateClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_SimplePrivateClassifierSystem(temp_datatype_array, 0, 0.0, 0, NULL);
			read_SimplePrivateClassifierSystem(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_SimplePrivateClassifierSystem_static_array(char * buffer, int * j, SimplePrivateClassifierSystem * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_SimplePrivateClassifierSystem(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_ComplexPublicClassifierSystem(char * buffer, int * j, ComplexPublicClassifierSystem * temp_datatype)
 * \brief Reads ComplexPublicClassifierSystem datatype.
 */
void read_ComplexPublicClassifierSystem(char * buffer, int * j, ComplexPublicClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).nr_types = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_types = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, &(*temp_datatype).nr_rules_per_type);
	}
	
	(*j)++;
	(*temp_datatype).nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_rules = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_PublicClassifierRule_static_array(buffer, j, (*temp_datatype).ruletable, 100);
	
	(*j)++;
}

void read_ComplexPublicClassifierSystem_dynamic_array(char * buffer, int * j, ComplexPublicClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ComplexPublicClassifierSystem(temp_datatype_array, 0, NULL, 0, NULL);
			read_ComplexPublicClassifierSystem(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_ComplexPublicClassifierSystem_static_array(char * buffer, int * j, ComplexPublicClassifierSystem * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_ComplexPublicClassifierSystem(buffer, j, &temp_datatype_array[arraycount]);
		if(arraycount < (size-1)) while(buffer[(*j)] != '{') { (*j)++; }
	}
	
	(*j)++;
}

/** \fn void read_ComplexPrivateClassifierSystem(char * buffer, int * j, ComplexPrivateClassifierSystem * temp_datatype)
 * \brief Reads ComplexPrivateClassifierSystem datatype.
 */
void read_ComplexPrivateClassifierSystem(char * buffer, int * j, ComplexPrivateClassifierSystem * temp_datatype)
{
	int array_k;
	char arraydata[10000];
	(*j)++;
	
	(*temp_datatype).nr_types = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_types = atoi(arraydata);
	(*j)++;

	while(buffer[*j] != ',')
	{
		while(buffer[*j] != '{') (*j)++;
		
		read_int_dynamic_array(buffer, j, &(*temp_datatype).nr_rules_per_type);
	}
	
	(*j)++;
	(*temp_datatype).nr_rules = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).nr_rules = atoi(arraydata);
	(*j)++;
	(*temp_datatype).experience = 0.0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).experience = atof(arraydata);
	(*j)++;
	(*temp_datatype).current_rule = 0;
	array_k = 0;
	while(buffer[*j] != ',')
	{
		arraydata[array_k] = buffer[*j];
		array_k++;
		(*j)++;
	}
	arraydata[array_k] = 0;
	(*temp_datatype).current_rule = atoi(arraydata);
	(*j)++;
	while(buffer[*j] != '{') (*j)++;

	read_PrivateClassifierRule_static_array(buffer, j, (*temp_datatype).ruletable, 100);
	
	(*j)++;
}

void read_ComplexPrivateClassifierSystem_dynamic_array(char * buffer, int * j, ComplexPrivateClassifierSystem_array * temp_datatype_array)
{
	int arraycount = 0;
	
	(*j)++;
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != '}')
	{
		if(buffer[(*j)] == '{')
		{
			add_ComplexPrivateClassifierSystem(temp_datatype_array, 0, NULL, 0, 0.0, 0, NULL);
			read_ComplexPrivateClassifierSystem(buffer, j, &(*temp_datatype_array).array[arraycount]);
			arraycount++;
		}
		while(buffer[(*j)] != '{' && buffer[(*j)] != '\0') { (*j)++; }
	}
	
	(*j)++;
}

void read_ComplexPrivateClassifierSystem_static_array(char * buffer, int * j, ComplexPrivateClassifierSystem * temp_datatype_array, int size)
{
	int arraycount;
	
	(*j)++;
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		read_ComplexPrivateClassifierSystem(buffer, j, &temp_datatype_array[arraycount]);
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
	int in_FinancialAgent_agent;

	int in_id;
	int in_EWA_parameters;
	int in_classifiersystem;
	int in_posx;
	int in_posy;
	int in_day_of_month_to_act;
	int in_day;
	int in_month;
	int in_GA_parameters;


	/* Variables for initial state data */
//	int id;
//	EWAParameterStruct * EWA_parameters;
//	SimplePrivateClassifierSystem * classifiersystem;
//	double posx;
//	double posy;
//	int day_of_month_to_act;
//	int day;
//	int month;
//	GAParameterStruct * GA_parameters;


	xmachine_memory_Household * current_Household_agent;
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
	in_FinancialAgent_agent = 0;
	in_id = 0;
	in_EWA_parameters = 0;
	in_classifiersystem = 0;
	in_posx = 0;
	in_posy = 0;
	in_day_of_month_to_act = 0;
	in_day = 0;
	in_month = 0;
	in_GA_parameters = 0;

	/* Default variables for memory */
	/* Not implemented static arrays */
//	id = 0;
//	EWA_parameters = init_EWAParameterStruct();
//	classifiersystem = init_SimplePrivateClassifierSystem();
//	posx = 0.0;
//	posy = 0.0;
//	day_of_month_to_act = 0;
//	day = 0;
//	month = 0;
//	GA_parameters = init_GAParameterStruct();







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
					if(strcmp(agentname, "Household") == 0)
					{
						current_Household_agent = init_Household_agent();
						in_Household_agent = 1;
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
						//add_Household_agent(id, EWA_parameters, classifiersystem, posx, posy);
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
								//add_Household_agent(id, EWA_parameters, classifiersystem, posx, posy);
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
								//add_Household_agent(id, EWA_parameters, classifiersystem, posx, posy);
								add_Household_agent_internal(current_Household_agent);

								current_Household_agent->posx = xcentre;
								current_Household_agent->posy = ycentre;
								current_Household_agent-> = rrange;

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
						//add_FinancialAgent_agent(day_of_month_to_act, day, month, EWA_parameters, classifiersystem, GA_parameters, posx, posy);
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
								//add_FinancialAgent_agent(day_of_month_to_act, day, month, EWA_parameters, classifiersystem, GA_parameters, posx, posy);
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
								//add_FinancialAgent_agent(day_of_month_to_act, day, month, EWA_parameters, classifiersystem, GA_parameters, posx, posy);
								add_FinancialAgent_agent_internal(current_FinancialAgent_agent);

								current_FinancialAgent_agent->posx = xcentre;
								current_FinancialAgent_agent->posy = ycentre;
								current_FinancialAgent_agent-> = rrange;

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
//////				posx = 0.0;
//				posy = 0.0;
//				day_of_month_to_act = 0;
//				day = 0;
//				month = 0;
//
	}
			if(strcmp(buffer, "id") == 0) in_id = 1;
			if(strcmp(buffer, "/id") == 0) in_id = 0;
			if(strcmp(buffer, "EWA_parameters") == 0) in_EWA_parameters = 1;
			if(strcmp(buffer, "/EWA_parameters") == 0) in_EWA_parameters = 0;
			if(strcmp(buffer, "classifiersystem") == 0) in_classifiersystem = 1;
			if(strcmp(buffer, "/classifiersystem") == 0) in_classifiersystem = 0;
			if(strcmp(buffer, "posx") == 0) in_posx = 1;
			if(strcmp(buffer, "/posx") == 0) in_posx = 0;
			if(strcmp(buffer, "posy") == 0) in_posy = 1;
			if(strcmp(buffer, "/posy") == 0) in_posy = 0;
			if(strcmp(buffer, "day_of_month_to_act") == 0) in_day_of_month_to_act = 1;
			if(strcmp(buffer, "/day_of_month_to_act") == 0) in_day_of_month_to_act = 0;
			if(strcmp(buffer, "day") == 0) in_day = 1;
			if(strcmp(buffer, "/day") == 0) in_day = 0;
			if(strcmp(buffer, "month") == 0) in_month = 1;
			if(strcmp(buffer, "/month") == 0) in_month = 0;
			if(strcmp(buffer, "GA_parameters") == 0) in_GA_parameters = 1;
			if(strcmp(buffer, "/GA_parameters") == 0) in_GA_parameters = 0;


			
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
				if(in_EWA_parameters)
				{
					j = 0;
					read_EWAParameterStruct(buffer, &j, &current_Household_agent->EWA_parameters);
				}
				if(in_classifiersystem)
				{
					j = 0;
					read_SimplePrivateClassifierSystem(buffer, &j, &current_Household_agent->classifiersystem);
				}
				if(in_posx) current_Household_agent->posx = atof(buffer);
				if(in_posy) current_Household_agent->posy = atof(buffer);
			}else if(in_FinancialAgent_agent == 1)
			{
				if(in_day_of_month_to_act) current_FinancialAgent_agent->day_of_month_to_act = atoi(buffer);
				if(in_day) current_FinancialAgent_agent->day = atoi(buffer);
				if(in_month) current_FinancialAgent_agent->month = atoi(buffer);
				if(in_EWA_parameters)
				{
					j = 0;
					read_EWAParameterStruct(buffer, &j, &current_FinancialAgent_agent->EWA_parameters);
				}
				if(in_classifiersystem)
				{
					j = 0;
					read_SimplePublicClassifierSystem(buffer, &j, &current_FinancialAgent_agent->classifiersystem);
				}
				if(in_GA_parameters)
				{
					j = 0;
					read_GAParameterStruct(buffer, &j, &current_FinancialAgent_agent->GA_parameters);
				}
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
////	free_EWAParameterStruct_datatype(EWA_parameters);
//	free_SimplePrivateClassifierSystem_datatype(classifiersystem);
////////////	free_GAParameterStruct_datatype(GA_parameters);

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
	xmachine_memory_Household * current_Household;
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

/** \fn void write_EWAParameterStruct(FILE *file, EWAParameterStruct * temp_datatype)
 * \brief Writes EWAParameterStruct datatype.
 */
void write_EWAParameterStruct(FILE *file, EWAParameterStruct * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).EWA_rho);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).EWA_phi);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).EWA_delta);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).EWA_beta);
	fputs(data, file);
	fputs("}", file);
}

void write_EWAParameterStruct_static_array(FILE *file, EWAParameterStruct * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_EWAParameterStruct(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_EWAParameterStruct_dynamic_array(FILE *file, EWAParameterStruct_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_EWAParameterStruct(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_GAParameterStruct(FILE *file, GAParameterStruct * temp_datatype)
 * \brief Writes GAParameterStruct datatype.
 */
void write_GAParameterStruct(FILE *file, GAParameterStruct * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%f", (*temp_datatype).prob_cross);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).prob_mut);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).size);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).pop_size);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).reproduction_proportion);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).single_point_cross_over);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).election);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).stepsize, 10);
	fputs("}", file);
}

void write_GAParameterStruct_static_array(FILE *file, GAParameterStruct * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_GAParameterStruct(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_GAParameterStruct_dynamic_array(FILE *file, GAParameterStruct_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_GAParameterStruct(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_PublicClassifierRule(FILE *file, PublicClassifierRule * temp_datatype)
 * \brief Writes PublicClassifierRule datatype.
 */
void write_PublicClassifierRule(FILE *file, PublicClassifierRule * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).counter);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).performance);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).avg_performance);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).parameters, 10);
	fputs("}", file);
}

void write_PublicClassifierRule_static_array(FILE *file, PublicClassifierRule * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_PublicClassifierRule(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_PublicClassifierRule_dynamic_array(FILE *file, PublicClassifierRule_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_PublicClassifierRule(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_PrivateClassifierRule(FILE *file, PrivateClassifierRule * temp_datatype)
 * \brief Writes PrivateClassifierRule datatype.
 */
void write_PrivateClassifierRule(FILE *file, PrivateClassifierRule * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).id);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).my_performance);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).avg_performance);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).attraction);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).choiceprob);
	fputs(data, file);
	fputs(", ", file);	write_double_static_array(file, (*temp_datatype).parameters, 10);
	fputs("}", file);
}

void write_PrivateClassifierRule_static_array(FILE *file, PrivateClassifierRule * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_PrivateClassifierRule(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_PrivateClassifierRule_dynamic_array(FILE *file, PrivateClassifierRule_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_PrivateClassifierRule(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_SimplePublicClassifierSystem(FILE *file, SimplePublicClassifierSystem * temp_datatype)
 * \brief Writes SimplePublicClassifierSystem datatype.
 */
void write_SimplePublicClassifierSystem(FILE *file, SimplePublicClassifierSystem * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).nr_rules);
	fputs(data, file);
	fputs(", ", file);	write_PublicClassifierRule_static_array(file, (*temp_datatype).ruletable, 100);
	fputs("}", file);
}

void write_SimplePublicClassifierSystem_static_array(FILE *file, SimplePublicClassifierSystem * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_SimplePublicClassifierSystem(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_SimplePublicClassifierSystem_dynamic_array(FILE *file, SimplePublicClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_SimplePublicClassifierSystem(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_SimplePrivateClassifierSystem(FILE *file, SimplePrivateClassifierSystem * temp_datatype)
 * \brief Writes SimplePrivateClassifierSystem datatype.
 */
void write_SimplePrivateClassifierSystem(FILE *file, SimplePrivateClassifierSystem * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).nr_rules);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).experience);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).current_rule);
	fputs(data, file);
	fputs(", ", file);	write_PrivateClassifierRule_static_array(file, (*temp_datatype).ruletable, 100);
	fputs("}", file);
}

void write_SimplePrivateClassifierSystem_static_array(FILE *file, SimplePrivateClassifierSystem * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_SimplePrivateClassifierSystem(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_SimplePrivateClassifierSystem_dynamic_array(FILE *file, SimplePrivateClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_SimplePrivateClassifierSystem(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ComplexPublicClassifierSystem(FILE *file, ComplexPublicClassifierSystem * temp_datatype)
 * \brief Writes ComplexPublicClassifierSystem datatype.
 */
void write_ComplexPublicClassifierSystem(FILE *file, ComplexPublicClassifierSystem * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).nr_types);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, &(*temp_datatype).nr_rules_per_type);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_rules);
	fputs(data, file);
	fputs(", ", file);	write_PublicClassifierRule_static_array(file, (*temp_datatype).ruletable, 100);
	fputs("}", file);
}

void write_ComplexPublicClassifierSystem_static_array(FILE *file, ComplexPublicClassifierSystem * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ComplexPublicClassifierSystem(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ComplexPublicClassifierSystem_dynamic_array(FILE *file, ComplexPublicClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ComplexPublicClassifierSystem(file, &(*temp_datatype).array[i]);
		
		if(i < (*temp_datatype).size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_ComplexPrivateClassifierSystem(FILE *file, ComplexPrivateClassifierSystem * temp_datatype)
 * \brief Writes ComplexPrivateClassifierSystem datatype.
 */
void write_ComplexPrivateClassifierSystem(FILE *file, ComplexPrivateClassifierSystem * temp_datatype)
{
	char data[1000];
	
	fputs("{", file);
	sprintf(data, "%i", (*temp_datatype).nr_types);
	fputs(data, file);
	fputs(", ", file);	write_int_dynamic_array(file, &(*temp_datatype).nr_rules_per_type);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).nr_rules);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%f", (*temp_datatype).experience);
	fputs(data, file);
	fputs(", ", file);	sprintf(data, "%i", (*temp_datatype).current_rule);
	fputs(data, file);
	fputs(", ", file);	write_PrivateClassifierRule_static_array(file, (*temp_datatype).ruletable, 100);
	fputs("}", file);
}

void write_ComplexPrivateClassifierSystem_static_array(FILE *file, ComplexPrivateClassifierSystem * temp_datatype, int size)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < size; i++)
	{
		write_ComplexPrivateClassifierSystem(file, &temp_datatype[i]);
		
		if(i < size - 1) fputs(", ", file);
	}
	fputs("}", file);
}

void write_ComplexPrivateClassifierSystem_dynamic_array(FILE *file, ComplexPrivateClassifierSystem_array * temp_datatype)
{
	int i;
	
	fputs("{", file);
	for(i = 0; i < (*temp_datatype).size; i++)
	{
		write_ComplexPrivateClassifierSystem(file, &(*temp_datatype).array[i]);
		
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
	xmachine_memory_Household * current_Household;
	xmachine_memory_FinancialAgent * current_FinancialAgent;
	
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
			fputs("<EWA_parameters>", file);
			write_EWAParameterStruct(file, &current_Household->EWA_parameters);
			fputs("</EWA_parameters>\n", file);
			fputs("<classifiersystem>", file);
			write_SimplePrivateClassifierSystem(file, &current_Household->classifiersystem);
			fputs("</classifiersystem>\n", file);
			fputs("<posx>", file);
			sprintf(data, "%f", current_Household->posx);
			fputs(data, file);
			fputs("</posx>\n", file);
			fputs("<posy>", file);
			sprintf(data, "%f", current_Household->posy);
			fputs(data, file);
			fputs("</posy>\n", file);
		}
		else if(current_xmachine->xmachine_FinancialAgent != NULL)
		{
			current_FinancialAgent = current_xmachine->xmachine_FinancialAgent;
			fputs("<name>FinancialAgent</name>\n", file);
			fputs("<day_of_month_to_act>", file);
			sprintf(data, "%i", current_FinancialAgent->day_of_month_to_act);
			fputs(data, file);
			fputs("</day_of_month_to_act>\n", file);
			fputs("<day>", file);
			sprintf(data, "%i", current_FinancialAgent->day);
			fputs(data, file);
			fputs("</day>\n", file);
			fputs("<month>", file);
			sprintf(data, "%i", current_FinancialAgent->month);
			fputs(data, file);
			fputs("</month>\n", file);
			fputs("<EWA_parameters>", file);
			write_EWAParameterStruct(file, &current_FinancialAgent->EWA_parameters);
			fputs("</EWA_parameters>\n", file);
			fputs("<classifiersystem>", file);
			write_SimplePublicClassifierSystem(file, &current_FinancialAgent->classifiersystem);
			fputs("</classifiersystem>\n", file);
			fputs("<GA_parameters>", file);
			write_GAParameterStruct(file, &current_FinancialAgent->GA_parameters);
			fputs("</GA_parameters>\n", file);
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
