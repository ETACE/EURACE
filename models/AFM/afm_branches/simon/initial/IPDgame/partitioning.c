/**
 * \file  partitioning.c
 * \brief Holds partitioning functions.
 */

#include "header.h"
#include "low_primes.h"

/** \var static int factors[30]
 * \brief Array of factors of number of partitions. 
 */
static int factors[30];

/** \var static int powers[30]
 * \brief Array of powers for factors of number of partitions. 
 */
static int powers[30];

/** \var static int nfactor
 * \brief Number of factors of the number of partitions.
 *
 * Initialised to zero.
 */
static int nfactor=0;

/**
 * \fn static void collect_factors( long fact, long power )
 * \brief Collects given factor and power in appropriate arrays.
 *
 * Variable nfactor is incremented by this function.
 *
 * \param fact  The factor to add to factors array.
 * \param power The power to add to powers array.
 *
 * \author  C Greenough CCLRC
 * \date    2007
 */
static void collect_factors( long fact, long power )
{
	factors[nfactor]=fact;
	powers[nfactor]=power;
	nfactor+=1;
}

/**
 * \fn static int test_fact( long* numP, long fact )
 * \brief Test whether second argument is a factor of the first and how many times.
 *
 * Test by repeated division and multiplication by the factor in integer arithmetic.
 *
 * \param numP  Pointer to number to be tested.
 * \param fact  The factor to test against.
 * \returns     1 if we have to try the next factor or 0 if not.
 *
 * \author  C Greenough CCLRC
 * \date    2007
 */
static int test_fact( long* numP, long fact )
{
    long power, t;

    power = 0;
    while ( ( t = *numP / fact ) * fact == *numP )
        {
        ++power;
        *numP = t;
        }

    if ( power != 0 )
        collect_factors( fact, power );

    if ( t > fact )
        return 1;

    return 0;
}

/**
 * \fn static void factor( long num )
 * \brief Factor the argument into its prime factors.
 *
 * \param num Integer value to factor.
 *
 * \author  C Greenough CCLRC
 * \date    2007
 */
static void factor( long num )
{
    int p;
    long lnum, fact;

    lnum = num;

    if ( lnum == 0 || lnum == 1 ) {
        /* If it's a simple factorisation */
        collect_factors( lnum, 1 );
    }
    else {
        /* Loop over the lower prime numbers till we have the factors.*/
    	for ( p = 0; p < sizeof(low_primes)/sizeof(*low_primes); ++p )
    	    if ( ! test_fact( &lnum, low_primes[p] ) ) goto done;
        /* If we didn't find any factors generate some more on the fly. */
    	fact = ( low_primes[p - 1] + 5 ) / 6 * 6 - 1;
    	for ( ; ; )
    	    {
    	    if ( ! test_fact( &lnum, fact ) )
    		break;
    	    fact += 2;
    	    if ( ! test_fact( &lnum, fact ) )
    		break;
    	    fact += 4;
    	    }
    	done:
            if ( lnum != 1 )
                collect_factors( lnum, 1 );
    }
}


/** \fn void generate_partitions(double cloud_data[6], int partitions)
 * \brief Generate space partitions in x and y by factoring number of partitions.
 *
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partitions The number of partitions required.
 *
 * \author  C Greenough and DJ Worth CCLRC
 * \date    2007
 */
void generate_partitions(double cloud_data[6], int partitions, int partition_method)
{
    int geometric = 1;
        int other = 2;

    int xdiv=1,ydiv=1;
    int i,j,id;
    double xmax=0,xmin=0,ymax=0,ymin=0;
    double dx,dy,px,py;
    /* Limits in x and y of partition to be created */
    double xlo, xhi, ylo, yhi;
    double margin=0.25; /* small extension of region */

    /* factor number of partitions */
	factor((long) partitions);

    /* build divisions for x and y axes */

    for ( i=nfactor-1; i >= 0; --i){
        /* printf("%d : %d \n",factors[i],powers[i]);*/
        for( j=1; j <=powers[i] ; ++j){
            if(xdiv<=ydiv) {
                xdiv=xdiv*factors[i];
            }
            else {
                ydiv=ydiv*factors[i];
            }
        }
    }

    printf("xdiv=%d ydiv=%d\n",xdiv,ydiv);



/* Geometric partitioning */

    if(partition_method==geometric){

        xmax=cloud_data[1]; /*+SPINF;*/
        xmin=cloud_data[0]; /*-SPINF;*/
        ymax=cloud_data[3]; /*+SPINF;*/
        ymin=cloud_data[2]; /*-SPINF;*/
    }
    else if(partition_method==other){
    
        dx=1.0;
        dy=1.0;
        xmax=dx;
        xmin=0.0;
        ymax=dy;
        ymin=0.0;
        margin=0.0;
    }

    /* defined agent cloud with small margin */ 
    xmax+=fabs(xmax)*margin;
    xmin-=fabs(xmin)*margin;
    ymax+=fabs(ymax)*margin;
    ymin-=fabs(ymin)*margin;

    /* calculate increments */

    dx=(xmax-xmin)/(xdiv);
    dy=(ymax-ymin)/(ydiv);
    /* generate partitions */

    /* current = *node_list; */
    id=0;
    px=xmin;
    for (i=0; i < xdiv; ++i){
        py=ymin;
        for (j=0; j < ydiv; ++j){
            xlo = px;
            xhi = px+dx;
            ylo = py;
            yhi = py+dy;
            if(partition_method==geometric){
                if (xlo <= xmin+0.01) xlo = -SPINF;
                if (xhi >= xmax-0.01) xhi = SPINF;
                if (ylo <= ymin+0.01) ylo = -SPINF;
                if (yhi >= ymax-0.01) yhi = SPINF;
            }
            else {
                /*    
                if (xlo <= xmin) xlo = -domain_size;
                if (xhi >= xmax) xhi = domain_size;
                if (ylo <= ymin) ylo = -domain_size;
                if (yhi >= ymax) yhi = domain_size;
            */
            }

            printf("Partition %d: %f, %f, %f, %f\n",
                            id,xlo,xhi,ylo,yhi); 


            add_node(id++,xlo,xhi,ylo,yhi,-SPINF,SPINF);
            py=py+dy;
        }
        px=px+dx;
    }
/*  } */
/*  else if(partition_method == other){*/
/* Round robin partitions */
/*  id=0;
    xlo=0.0;
    xhi=0.0;
    ylo=0.0;
    yhi=0.0;
    for(i=0;i<partitions;++i){
        add_node(id++,xlo,xhi,ylo,yhi,-SPINF,SPINF);
      }
    }*/
}


/**
 * Distribute the agents to their partition based on agent positions. 
 *
 * This serial version moves agents from agent_list to the agent list on each node.
 *
 * \param totalnodes    Number of partitions to create.
 * \param agent_list    List of agents in the model.
 * \param cloud_data    Limits of agent positions: {xmin, xmax, ymin, ymax}
 *
 * \author  DJ Worth CCLRC
 * \date    2007
 */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method)
{
    /* Data to loop through agents and copy data into nodes*/
    xmachine * current_xmemory, *next_agent;
    /* Data to loop through nodes*/
    node_information* current_partition;
    /* Limits of this space partition*/
    double xmin,xmax,ymin,ymax;
    double x_centre,y_centre;
    
    int geometric = 1;
    int other = 2;


    if(partition_method == geometric){

        printf("Geometric partitioning\n");

        current_xmachine = *agent_list;
        while(current_xmachine)
        {
            /* Loop through nodes */
            current_partition = *p_node_info;
            while (current_partition)
            {
                /* Check if agent in this space partition. If so add it to agent list */
                xmin=current_partition->partition_data[0];
                xmax=current_partition->partition_data[1];
                ymin=current_partition->partition_data[2];
                ymax=current_partition->partition_data[3];
                /* Use get_ methods since current_agent global variable is set*/
                if((agent_get_x() >= xmin) && (agent_get_x() < xmax) &&
                   (agent_get_y() >= ymin) && (agent_get_y() < ymax))
                {
                    current_xmemory = current_partition->agents;
                    current_partition->agents = current_xmachine;
                    next_agent = current_xmachine->next;
                     current_xmachine->next = current_xmemory;
                    current_partition->agent_total++;
                     /* Stop the loop over nodes*/
                     current_partition = NULL;
                }
                else {
                    current_partition = current_partition->next;
                }
            } /* end of partition while */
            current_xmachine = next_agent;
        } /* end of xmachine while */
    }
    else if(partition_method == other){/* Round Robin allocation */

        printf("Round robin partitioning\n");

        /* Loop through agents */
        current_xmachine = *agent_list;
        while(current_xmachine){
            /* Loop through nodes */
            current_partition = *p_node_info;
            while(current_partition && current_xmachine){
            
                /* Compute centre of partition */
                xmin=current_partition->partition_data[0];
                xmax=current_partition->partition_data[1];
                ymin=current_partition->partition_data[2];
                ymax=current_partition->partition_data[3];
                x_centre=xmin+(xmax-xmin)/2.0;
                y_centre=ymin+(ymax-ymin)/2.0;
                /*_centre=zmin+(zmax-zmin)/2.0;*/

                /* Allocation current agent to current node */
                current_xmemory = current_partition->agents;

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                /* Change agent position to centre */
                set_(1.5);
                set_posx(x_centre);
                set_posy(y_centre);

                current_partition->agents = current_xmachine;
                next_agent = current_xmachine->next;
                current_xmachine->next = current_xmemory;
                current_partition->agent_total++;

                /* Select next agent and next node */
                current_xmachine = next_agent;
                current_partition = current_partition->next;
            } /* End of node loop */
            current_xmachine = next_agent;
        } /* End of agent loop */
    }

}




/** \fn void save_partition_data()
 * \brief Save the partition data to a file. 
 *
 * The file is space_partitions.xml and is used by the visualisation application.
 */
void save_partition_data()
{
    FILE *file;
    char data[100];
    node_information *node_info;

    sprintf(data, "%sspace_partitions.xml", outputpath);
	file = fopen(data, "w");
	fputs("<spacepartitions>\n" , file);
	fputs("<partitions>\n" , file);
	fputs("<number>" , file);
	sprintf(data, "%d", totalnodes);
	fputs(data, file);
	fputs("</number>\n" , file);
	node_info = *p_node_info;
	while(node_info) {
		fputs("<node>\n" , file);
		fputs("<nodeid>" , file);
		sprintf(data, "%i", node_info->node_id);
		fputs(data, file);
		fputs("</nodeid>\n" , file);
		fputs("<xmin>" , file);
		if(node_info->partition_data[0] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[0] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[0]); fputs(data, file); }
		fputs("</xmin>\n" , file);
		fputs("<xmax>" , file);
		if(node_info->partition_data[1] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[1] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[1]); fputs(data, file); }
		fputs("</xmax>\n" , file);
		fputs("<ymin>" , file);
		if(node_info->partition_data[2] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[2] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[2]); fputs(data, file); }
		fputs("</ymin>\n" , file);
		fputs("<ymax>" , file);
		if(node_info->partition_data[3] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[3] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[3]); fputs(data, file); }
		fputs("</ymax>\n" , file);
		fputs("<zmin>" , file);
		if(node_info->partition_data[4] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[4] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[4]); fputs(data, file); }
		fputs("</zmin>\n" , file);
		fputs("<zmax>" , file);
		if(node_info->partition_data[5] == SPINF) fputs("SPINF" , file);
		else if(node_info->partition_data[5] == -SPINF) fputs("-SPINF" , file);
		else{ sprintf(data, "%f", node_info->partition_data[5]); fputs(data, file); }
		fputs("</zmax>\n" , file);
		fputs("</node>\n" , file);
		
		node_info = node_info->next;
	}
	fputs("</partitions>\n" , file);
	fputs("</spacepartitions>" , file);
	fclose(file);

}



