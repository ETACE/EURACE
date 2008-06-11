#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*************************************
* Struct Type Definitions            *
*************************************/


struct Eurostat
{
	int id;
	double gdp;
	double total_earnings;
	double total_debt;
	double total_assets;
	double total_equity;
	double average_debt_earnings_ratio;
	double average_debt_equity_ratio;
	double labour_share_ratio;
	
	struct Eurostat * next;

};

typedef struct Eurostat Eurostat;

/*****************************************************************
* FUNCTIONS: linked list functions                               *
* PURPOSE: to allocate and free memory in linked lists           *
*****************************************************************/

void freeEurostats(Eurostat * head)
{
	/* Tempory element needed for loop */
	Eurostat * tmp;

	/* Loop while head is not NULL */
	while(head)
	{
		/* Make next in list tmp */
		tmp = head->next;
		/* Free memory of head */
		free(head);
		/* Make head the next in the list */
		head = tmp;
	}
}

Eurostat * addEurostat(Eurostat ** pointer_to_Eurostats, Eurostat * current)
{
	/* The new tail of the linked list */
	Eurostat * tail;

	/* Allocate memory for new neighbour data */

	tail = (Eurostat *)malloc(sizeof(Eurostat));

	/* Check if current is not NULL */
	if(current)
	{
		/* Current exists therefore make its next point to tail */
		current->next = tail;
	}
	else
	{
		/* Current is NULL therefore make the cell neighbour_head point to tail */
		*pointer_to_Eurostats = tail;
	}
	/* Point next to NULL */
	tail->next = NULL;
	/* Return new neighbour data */
	return tail;
}

/* Print all cell data */
/*void printagentdata(xmachine ** pointer_to_cells)
{
	xmachine * current;
	
	current = *pointer_to_cells;

	printf("Cell Data\n");
	while(current)
	{
		printf("cell:%d\txp:%f\ty:%f\tz:%f\n", current->id, current->x, current->y, current->z);
		current = current->next;
	}

	printf("\n");
}*/

/*****************************************************************
* FUNCTION: getIteration                                         *
* PURPOSE: read iteration xml file                               *
*****************************************************************/
int getiteration(char * filepath, int itno, Eurostat ** pointer_to_Eurostats)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = ' ';
	char buffer[100000];
	/* Variable to keep reading file */
	int reading = 1;

	/* Variables for checking tags */
	int i, instate, intag, initeration, inagent, inid, inregion_id, inname;

	/*Eurostat*/
	int	ingdp, intotal_earnings, intotal_debt, intotal_assets, intotal_equity;
	int inaverage_debt_earnings_ratio, inaverage_debt_equity_ratio, inlabour_share_ratio;
	
	/* Variables for model data */
	int state, id, region_id;

	/*Eurostat*/
	double gdp, total_earnings, total_debt, total_assets, total_equity;
	double average_debt_earnings_ratio, average_debt_equity_ratio, labour_share_ratio;

	
	char name[100];

	Eurostat * current_Eurostat, * tail_Eurostat;
	tail_Eurostat = *pointer_to_Eurostats;
	current_Eurostat = NULL;

	/* Open config file to read-only */
	char data[200];
	sprintf(data, "%s%i%s", filepath, itno, ".xml");
	printf("%s", data);
	if((file = fopen(data, "r"))==NULL)
	{
		printf(" Getdata.c reached last xml file in sequence \n");
		return 0;
		/*exit(0);*/
	}
	else
	{

	printf("\n");
	/* Initialise variables */
	i = 0;
	instate = 0;
	intag = 0;
	initeration = 0;
	inagent = 0;
	inname = 0;
	inid = 0;
	inregion_id = 0;

	/*Eurostat*/
	ingdp =0;
	intotal_earnings =0;
	intotal_debt =0;
	intotal_assets =0;
	intotal_equity =0;
	inaverage_debt_earnings_ratio =0;
	inaverage_debt_equity_ratio =0;
	inlabour_share_ratio =0;

	state = 0;
	id = 0;
	region_id = 0;
		
	/*Eurostat*/
    gdp =0.0;
    total_earnings =0.0;
    total_debt =0.0;
    total_assets =0.0;
    total_equity =0.0;
    average_debt_earnings_ratio =0.0;
    average_debt_equity_ratio =0.0;
    labour_share_ratio =0.0;

	
	/* Read characters until the end of the file */
	/*while(c != EOF)*/
	/* Read characters until end of xml found */
	while(reading == 1)
	{
		/* Get the next char from the file */
		c = fgetc(file);
		
		//printf("%c", c);
		
		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;
			if(strcmp(buffer, "states") == 0) { initeration = 1; }
			if(strcmp(buffer, "/states") == 0) { initeration = 0; reading = 0; }
			if(strcmp(buffer, "xagent") == 0) { inagent = 1; }
			if(strcmp(buffer, "/xagent") == 0)
			{
				inagent = 0;
				
				//printf("Found agent ... ");
				
				if(strcmp(name, "Eurostat") == 0)
				{
					//printf("Adding agent\n");
					
					/* check if tail is NULL */
					if(tail_Eurostat == NULL)
					{
						//printf("tail is null allocate more memory\n");
						/* Allocate memory */
						tail_Eurostat = addEurostat(pointer_to_Eurostats, current_Eurostat);
					}
					//else printf("tail exisits\n");
					
					/* Make tail the current element to add to */
					current_Eurostat = tail_Eurostat;
					
					current_Eurostat->id                         = id;
				    current_Eurostat->gdp                        = gdp;
				    current_Eurostat->total_earnings             = total_earnings;
				    current_Eurostat->total_debt                 = total_debt;
				    current_Eurostat->total_assets               = total_assets;
				    current_Eurostat->total_equity               = total_equity;
				    current_Eurostat->average_debt_earnings_ratio= average_debt_earnings_ratio;
				    current_Eurostat->average_debt_equity_ratio  = average_debt_equity_ratio;
				    current_Eurostat->labour_share_ratio          = labour_share_ratio;

					
					//printf("Eurostat %d, ", id);
					
					/* Make tail the next element in the linked list */
					tail_Eurostat = current_Eurostat->next;
				}
			//else printf("Not adding agent\n");
			}
			if(strcmp(buffer, "name") == 0) { inname = 1; }
			if(strcmp(buffer, "/name") == 0) { inname = 0; }
			if(strcmp(buffer, "id") == 0) { inid = 1; }
			if(strcmp(buffer, "/id") == 0) { inid = 0; }
			if(strcmp(buffer, "region_id") == 0) { inregion_id = 1; }
			if(strcmp(buffer, "/region_id") == 0) { inregion_id = 0; }
			
			if(strcmp(buffer, "gdp") == 0) { ingdp = 1; }
		       if(strcmp(buffer, "/gdp") == 0) { ingdp= 0; }	
			if(strcmp(buffer, "total_earnings") == 0) { intotal_earnings = 1; }
		       if(strcmp(buffer, "/total_earnings") == 0) { intotal_earnings= 0; }	
			if(strcmp(buffer, "total_debt") == 0) { intotal_debt = 1; }
		       if(strcmp(buffer, "/total_debt") == 0) { intotal_debt= 0; }	
			if(strcmp(buffer, "total_assets") == 0) { intotal_assets = 1; }
		       if(strcmp(buffer, "/total_assets") == 0) { intotal_assets= 0; }	
			if(strcmp(buffer, "total_equity") == 0) { intotal_equity = 1; }
		       if(strcmp(buffer, "/total_equity") == 0) { intotal_equity= 0; }	
			if(strcmp(buffer, "average_debt_earnings_ratio") == 0) { inaverage_debt_earnings_ratio = 1; }
		       if(strcmp(buffer, "/average_debt_earnings_ratio") == 0) { inaverage_debt_earnings_ratio= 0; }	
			if(strcmp(buffer, "average_debt_equity_ratio") == 0) { inaverage_debt_equity_ratio = 1; }
		       if(strcmp(buffer, "/average_debt_equity_ratio") == 0) { inaverage_debt_equity_ratio= 0; }	
			if(strcmp(buffer, "labour_share_ratio") == 0) { inlabour_share_ratio = 1; }
		       if(strcmp(buffer, "/labour_share_ratio") == 0) { inlabour_share_ratio= 0; }	
		       
			/* End of tag and reset buffer */
			intag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			intag = 1;
			/* If just read data into buffer retrieve it */
			if(inagent && inname)  { strcpy(name, buffer); }
			if(inagent && inid) { id = atoi(buffer); }
			if(inagent && inregion_id) { region_id = atoi(buffer); }
			
			if(inagent && ingdp)  { gdp  = atof(buffer); }
			if(inagent && intotal_earnings)  { total_earnings  = atof(buffer); }
			if(inagent && intotal_debt)  { total_debt  = atof(buffer); }
			if(inagent && intotal_assets)  { total_assets  = atof(buffer); }
			if(inagent && intotal_equity)  { total_equity  = atof(buffer); }
			if(inagent && inaverage_debt_earnings_ratio)  { average_debt_earnings_ratio  = atof(buffer); }
			if(inagent && inaverage_debt_equity_ratio)  { average_debt_equity_ratio  = atof(buffer); }
			if(inagent && inlabour_share_ratio)  { labour_share_ratio  = atof(buffer); }
			
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(intag)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else// if(inname || inid || ina || inproductivity || inprice || insold || inproduction || inwage || insavings || infirmid || inworkers)
		{
			buffer[i] = c;
			i++;
		}
	}
	
	/* Free memory for unused linked list elements */
	if(tail_Eurostat)
	{
		freeEurostats(tail_Eurostat);
		/* Make pointer to tail equal NULL */
		if(current_Eurostat) { current_Eurostat->next = NULL; }
	}

	/* Close the file */
	fclose(file);
	
	/*printagentdata(pointer_to_cells);*/
	
	return 1;
	}
}

void savedatatofile(int itno, Eurostat ** pointer_to_Eurostats)
{
	FILE *file;
	char data[100];

	Eurostat* current_Eurostat;
	
	current_Eurostat = *pointer_to_Eurostats;
	
	double gdp;
	double total_earnings;
	double total_debt;
	double total_assets;
	double total_equity;
	double average_debt_earnings_ratio;
	double average_debt_equity_ratio;
	double labour_share_ratio;



	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
	/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
	/*----------------------------EUROSTAT MONTHLY AND REGIONAL DATA---------------------------------------*/

	current_Eurostat = *pointer_to_Eurostats;

	while(current_Eurostat)
	{
		//Set local variables
	    gdp = current_Eurostat->gdp;
	    total_earnings = current_Eurostat->total_earnings;
	    total_debt =  current_Eurostat->total_debt;
	    total_assets = current_Eurostat->total_assets;
	    total_equity = current_Eurostat->total_equity;
	    average_debt_earnings_ratio = current_Eurostat->average_debt_earnings_ratio;
	    average_debt_equity_ratio = current_Eurostat->average_debt_equity_ratio;
	    labour_share_ratio = current_Eurostat->labour_share_ratio;
		
		//Go to the next in linked list
		current_Eurostat = current_Eurostat->next;
		
	}
	//Write data to file
		if(itno%20 == 1)
		{

			file = fopen("data-eurostat.csv", "a");

			sprintf(data, "%i", itno);
			fputs(data, file);
			fputs("\t", file);
			
			sprintf(data, "%f", gdp);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", total_earnings);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", total_debt);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", total_assets);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", total_equity);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", average_debt_earnings_ratio);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", average_debt_equity_ratio);
			fputs(data, file);

			fputs("\t", file);
			sprintf(data, "%f", labour_share_ratio);
			fputs(data, file);

			fputs("\n", file);
			fclose(file);
		}
			
}

int main( int argc, char **argv )
{
	int position = 0;
	int lastd = 0;
	int i;
	char * filepath;

	Eurostat * Eurostats, * current_Eurostat;
	

	Eurostat ** p_Eurostats;
	
	int iteration_number = 0;
	int stilldata = 1;
	int lastread = 0; //added to allow for jumps in reading n.xml files
	 
	FILE *file;	

	file = fopen("data-eurostat.csv", "w");
	fclose(file);

	/* Read initial states of x-machines */
	/* advance argument pointer to next argument */
	*argv++;
	if(*argv == NULL)
	{
		printf("No intial states defined\n");
		exit(0);
	}
	printf("Initial states: %s\n", *argv);
	/*readinitialstates(*argv, p_iteration_number, p_xmemory);*/
	while(**argv != 0)
	{
		/* For windows directories */
		if(**argv == '\\') lastd=position;
		/* For windows directories */
		if(**argv == '/') lastd=position;
		(*argv)++;
		position++;
	}
	for(i=position; i>0; i--)
	{
		if(i==lastd+1) **argv = 0;
		(*argv)--;
	}
	filepath = *argv;
	printf("Ouput dir: %s\n", filepath);
	
	/* Initialise pointers */	
	Eurostats = NULL;
	p_Eurostats = &Eurostats;

	while(iteration_number - lastread < 241) //RHS: frequency+1
	{
		stilldata = getiteration(filepath, iteration_number, p_Eurostats);
		
		if(stilldata)
		{
				savedatatofile(iteration_number, p_Eurostats);
				lastread = iteration_number;
		}
		
		iteration_number++;
		
		/*
		 current = *p_agents;
		
		printf("Cell Data\n");
		while(current)
		{
			printf("cell:%d\ts:%d\tt:%d\n", current->id, current->state, current->type);
			current = current->next;
		}
		
		printf("\n");
		*/
	}
	
	/* Should never get here */
	return( 0 );
}
