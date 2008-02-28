/**
 * \file  my_library_functions.c
 * \brief Holds user created library functions.
 */

#include "header.h"
#include "my_library_header.h"

/** \fn sort_vacancy_list(vacancy_array * vacancy_list)
 * \brief Sorts an array of vacancies highest wage first
 * \param vacancy_list The array of vacancies.
 */
void sort_vacancy_list(vacancy_array * vacancy_list)
{
	int i, j;
	vacancy * first_vacancy, * second_vacancy;
	vacancy * temp_vacancy = (vacancy *)malloc(sizeof(vacancy));
	
	/* Using a bubble sort */
	for(i=0; i<(vacancy_list->size-1); i++)
	{
		for(j=0; j<(vacancy_list->size-1)-i; j++) 
		{
			first_vacancy = vacancy_list->array[j+1];
			second_vacancy = vacancy_list->array[j];
			
			/* Comparing the values between neighbours */
			if(first_vacancy->wage_offer > second_vacancy->wage_offer)
			{
				/* Swap neighbours */
				* temp_vacancy = * second_vacancy;
				* second_vacancy = * first_vacancy;
				* first_vacancy = * temp_vacancy;
			}
		}
	}
	
	free(temp_vacancy);
}

/** \fn sort_job_offer_list(job_offer_array * job_offer_list)
 * \brief Sorts an array of job offers highest wage first
 * \param job_offer_list The array of job offers.
 */
void sort_job_offer_list(job_offer_array * job_offer_list)
{
	int i, j;
	job_offer * first_job_offer, * second_job_offer;
	job_offer * temp_job_offer = (job_offer *)malloc(sizeof(job_offer));
	
	/* Using a bubble sort */
	for(i=0; i<(job_offer_list->size-1); i++)
	{
		for(j=0; j<(job_offer_list->size-1)-i; j++) 
		{
			first_job_offer = job_offer_list->array[j+1];
			second_job_offer = job_offer_list->array[j];
			
			/* Comparing the values between neighbours */
			if(first_job_offer->wage_offer > second_job_offer->wage_offer)
			{
				/* Swap neighbours */
				* temp_job_offer = * second_job_offer;
				* second_job_offer = * first_job_offer;
				* first_job_offer = * temp_job_offer;
			}
		}
	}
	
	free(temp_job_offer);
}

/** \fn int random_int(int min,int max)
 * \brief Returns an integer between and including min and max
 * \param min The minimum integer.
 * \param max The maximum integer.
 * \return The random integer.
 */
int random_int(int min,int max)
{
	return min + rand() % (max - min + 1);
}

/** \fn sort_job_application_list(job_application_array * job_application_list)
 * \brief Sorts an array of job applications lowest wage first
 * \param job_application_list The array of job applications.
 */
void sort_job_application_list(job_application_array * job_application_list)
{
	int i, j;
	job_application * first_job_application, * second_job_application;
	job_application * temp_job_application = (job_application *)malloc(sizeof(job_application));
	
	/* Using a bubble sort */
	for(i=0; i<(job_application_list->size-1); i++)
	{
		for(j=0; j<(job_application_list->size-1)-i; j++) 
		{
			first_job_application = job_application_list->array[j+1];
			second_job_application = job_application_list->array[j];
			
			/* Comparing the values between neighbours */
			if(first_job_application->general_skill > second_job_application->general_skill)
			{
				/* Swap neighbours */
				* temp_job_application = * second_job_application;
				* second_job_application = * first_job_application;
				* first_job_application = * temp_job_application;
			}
			
			if(first_job_application->general_skill == second_job_application->general_skill && first_job_application->specific_skill > second_job_application->specific_skill)
			{
				/* Swap neighbours */
				* temp_job_application = * second_job_application;
				* second_job_application = * first_job_application;
				* first_job_application = * temp_job_application;
			}

		}
	}
	
	free(temp_job_application);
}

void sort_mall_sales_list(sales_statistics_array * sales_mall_list )
{


		int i, j;
	sales_statistics * first_sales_statistics, * second_sales_statistics;
	sales_statistics * temp_sales_statistics = (sales_statistics *)malloc(sizeof(sales_statistics));
	
	/* Using a bubble sort */
	for(i=0; i<sales_mall_list->size -1; i++)
	{
		for(j=0; j<(sales_mall_list->size-1)-i; j++) 
		{
			first_sales_statistics = sales_mall_list->array[j+1];
			second_sales_statistics = sales_mall_list->array[j];
			
			/* Comparing the values between neighbours */
			if(first_sales_statistics->sales < second_sales_statistics->sales)
			{
				/* Swap neighbours */
				* temp_sales_statistics = * second_sales_statistics;
				* second_sales_statistics = * first_sales_statistics;
				* first_sales_statistics = * temp_sales_statistics;

			}
		}
	}free(temp_sales_statistics);

}
