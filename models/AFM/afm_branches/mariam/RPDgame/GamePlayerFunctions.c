/****************************************
Start date: 22/02/08
Mariam : Functions file for Game player
Description: 
*****************************************/



#include <math.h>
#include <header.h>
#include "GamePlayer_agent_header.h"
#include "mylibraryheader.h"

int neighbour_location()
{
	//find my neighbours
	//add to my dynamic memory list of nieghbours
	
	return 0;
}

int move_randomly()
{
	set_posx( get_posx() + (agent_jump - (rand()/(double)(RAND_MAX)*(agent_jump*2.0)) ));
	set_posy( get_posy() + (agent_jump - (rand()/(double)(RAND_MAX)*(agent_jump*2.0)) ));
	return 0;
}

int mate_with_neighbour()
{
	//get dynamic array of neighbours
	//sort the array according to payoffs
	//post message of offsprings created
	
	//post my location
	add_player_location_message();
}