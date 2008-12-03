/****************************************************************
 * test_GA.c
 * 04/12/07  Sander van der Hoog (svdhoog@gmail.com)
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mylibraryheader.h"
#include "test_crossover.h"

#define LENGTH 148

int main()
{
	
	//test_selection();
	test_crossover();
	//test_mutation();
	
	return 0;
}


int test_crossover()
{
	int n,i,k,c,ell,start,end,temp_a,temp_b;
	int string_a[LENGTH], string_b[LENGTH];
	
	//Set fixture: initialize bitstring values
	for (i=0;i<LENGTH;i++)
	{
		string_a[i]=0; //all 0s
		string_b[i]=1; //all 1s
	}

	//Print before cross-over
	printf("String a:\n");
	for (k=0;k<LENGTH;k++)
	{
		printf("%d", string_a[k]);
	}
	printf("\n");
	printf("String b:\n");
	for (k=0;k<LENGTH;k++)
	{
		printf("%d", string_b[k]);
	}
	printf("\n");
	
	//Random cross-over point
	n = (int)(16*random_unif());
	c = 4+n*9;
	//c = 4+8*9; //half-way
	//c = 4+15*9; //at end
	
	//Random cross-over length
	n = (int)(16*random_unif());
	ell= n*9;
	//ell= 2*9; //cross only 2 blocks

    //Set start and end bits
    if (c+ell<=LENGTH)
    {
    	start=c;
    	end=c+ell;
    }
    
    //Prevent overrun on right-hand side and cut to length
/*
    if (c+ell>LENGTH)
    {
        start=c;
        end=LENGTH;            	
    }
*/
    
    //Prevent overrun on right-hand side and make strings circular
    if (c+ell>LENGTH)
    {
    	start=(c+ell)%LENGTH;
    	end=c;
    }
	
	//Crossover the bitstrings
	for (k=start;k<end;k++)
	{
		temp_a = string_a[k];
		temp_b = string_b[k];
		string_a[k] = temp_b;
		string_b[k] = temp_a;
	}

	printf("Crossover point: c=%d\n", c);
	printf("Crossover length: l=%d\n", ell);
	//Print after cross-over
	printf("String a:\n");
	for (k=0;k<LENGTH;k++)
	{
		printf("%d", string_a[k]);
	}
	printf("\n");
	printf("String b:\n");
	for (k=0;k<LENGTH;k++)
	{
		printf("%d", string_b[k]);
	}
	printf("\n");

	
	return 0;
}

