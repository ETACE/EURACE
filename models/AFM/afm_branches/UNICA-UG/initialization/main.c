/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"
#include "init.h"
/** \fn int main(int argc, char ** argv)
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char ** argv)
{
    strcpy(outputpath,"");
	xmachine **agent_list;
	/* Particle cloud data */
	double cloud_data[6];
	/* Don't use binary output as default */
	use_binary_output = 0;
	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Initialise pointers */
	initialise_pointers();
    agent_list = p_xmachine;
    initialstates( agent_list, cloud_data, 0);
    /* Generate partitions */
    generate_partitions(cloud_data,1);
    save_partition_data();
    partition_data(1, agent_list, cloud_data);
     agent_list = p_xmachine;
   saveiterationdata(0);
	clean_up(0);
	return 0;
}
