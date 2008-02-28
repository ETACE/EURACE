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

//random number between two numbers
int random_unif_dist(int a,int b)
{
	int number;
	number=(rand()%b)+a;
	return number;
}