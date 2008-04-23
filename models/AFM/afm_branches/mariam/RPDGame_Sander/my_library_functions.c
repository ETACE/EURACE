//global functions used by the player and solver

//coverts the state represented as a 4 array  into a unique identifier
//useful for comparison


int state_unique_value(int * state_array)
{
	int value=0;
	int i;
	for(i=3;i>=0;i--)
	{
		value+=pow(2,state_array[i]);
	}
	return value;
	
}

//function for array copy
void array_element_copy(int * arrayFrom, int * arrayTo)
{
	int i,size;
	size=arrayFrom.size;
	for(i=0;i<size;i++)
	{
		arrayTo[i]=arrayFrom[i];
	}
}

//random number between two numbers
int random_unif_dist(int a,int b)
{
	int number;
	number=(rand()%b)+a;
	return number;
}

//function for sorting strategy performance
int sort_array()
{
	//return array
}