#include "header.h"

void output_dgraph(char * filename, char * filepath, model_data * modeldata)
{
	/* File to write to */
	FILE *file;
	/* Buffer for concatenating strings */
	char buffer[1000];
	xmachine * current_xmachine;
	xmachine_function * current_function;
	adj_function * current_adj_function;
	
	/* place in 'data' the file to write to */
	sprintf(buffer, "%s%s", filepath, filename);
	/* print out the location of the source file */
	printf("writing file: %s\n", buffer);
	/* open the file to write to */
	file = fopen(buffer, "w");
	
	fputs("digraph dependency_graph {\n", file);
	fputs("\trankdir=BT;\n", file);
	fputs("\tsize=\"8,5;\"\n", file); /* cg 9/8/07 - bug - ; missing */
	fputs("\tnode [shape = rect];\n", file);
	
	fputs("\t\n\t/* Functions */\n", file);
	/* For every function */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		current_function = current_xmachine->functions;
		while(current_function)
		{
			fputs("\t", file);
			fputs(current_function->name, file);
			fputs("[label = \"", file);
			fputs(current_function->name, file);
			fputs("\"]\n", file);
			
			/* For every dependency */
			current_adj_function = current_function->depends;
			while(current_adj_function)
			{
				fputs("\t", file);
				fputs(current_function->name, file);
				fputs(" -> ", file);
				fputs(current_adj_function->function->name, file);
				fputs(" [ label = \"<depends on ", file);
				fputs(current_adj_function->type, file);
				fputs(">\" ];\n", file);
				
				current_adj_function = current_adj_function->next;
			}
			
			current_function = current_function->next;
		}
		
		current_xmachine = current_xmachine->next;
	}
	fputs("}", file);
	
	/* Close the file */
	fclose(file);
}

void output_stategraph(char * filename, char * filepath, model_data * modeldata, int flag)
{
	/* File to write to */
	FILE *file;
	/* Buffer for concatenating strings */
	char buffer[1000];
	int i;
	
	xmachine * current_xmachine;
	xmachine_function * current_function;
	xmachine_state * current_state;
	flame_communication * current_communication;
	
	/* place in 'data' the file to write to */
	sprintf(buffer, "%s%s", filepath, filename);
	/* print out the location of the source file */
	printf("writing file: %s\n", buffer);
	/* open the file to write to */
	file = fopen(buffer, "w");
	
	fputs("digraph state_graph {\n", file);
	fputs("\trankdir=TB;\n", file);
	fputs("\tsize=\"8,5;\"\n", file);
	//fputs("\tnode [shape = rect];\n", file);
	
	/* Invisible level nodes */
	for(i = 0; i <= modeldata->layer_total; i++)
	{
		fputs("\tlayer_", file);
		sprintf(buffer, "%d", i);
		fputs(buffer, file);
		//fputs(" [style=invis, shape=point];\n", file);
		fputs(" [shape=plaintext, label=\"layer ", file);
		sprintf(buffer, "%d", i);
		fputs(buffer, file);
		fputs("\"];\n", file);
		//fputs(";\n", file);
		
		if(i != 0)
		{
			fputs("\tlayer_", file);
			sprintf(buffer, "%d", i-1);
			fputs(buffer, file);
			fputs(" -> layer_", file);
			sprintf(buffer, "%d", i);
			fputs(buffer, file);
			fputs(" [style=invis];\n", file);
		}
	}
	
	fputs("\t\n\t/* States */\n", file);
	/* For every state */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		current_state = current_xmachine->states;
		while(current_state)
		{
			fputs("\t", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_state->name, file);
			fputs(" [label = \"", file);
			fputs(current_state->name, file);
			fputs("\"]\n", file);
			
			current_state = current_state->next;
		}
		
		current_xmachine = current_xmachine->next;
	}
	/* For every function */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		current_function = current_xmachine->functions;
		while(current_function)
		{
			fputs("\t", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_function->name, file);
			fputs("_", file);
			fputs(current_function->current_state, file);
			fputs("_", file);
			fputs(current_function->next_state, file);
			fputs(" [label = \"", file);
			fputs(current_function->name, file);
			fputs("\", shape = rect]\n", file);
			
			current_function = current_function->next;
		}
		
		current_xmachine = current_xmachine->next;
	}
	fputs("\t\n\t/* Transitions */\n", file);
	/* For every transition */
	/* For each agent */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		if(flag == 0)
		{
			fputs("subgraph cluster_", file);
			fputs(current_xmachine->name, file);
			fputs(" {\n", file);
			fputs("\tlabel = \"Agent ", file);
			fputs(current_xmachine->name, file);
			fputs("\";\n", file);
		}
		
		/* For each function */
		current_function = current_xmachine->functions;
		while(current_function)
		{
			fputs("\t", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_function->current_state, file);
			fputs(" -> ", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_function->name, file);
			fputs("_", file);
			fputs(current_function->current_state, file);
			fputs("_", file);
			fputs(current_function->next_state, file);
			if(current_function->condition_function == NULL)
			{
				fputs(";\n", file);
			}
			else
			{
				fputs(" [ label = \"", file);
				// TODO
				//fputs(current_function->condition, file);
				fputs("\"];\n", file);
			}
			
			
			fputs("\t", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_function->name, file);
			fputs("_", file);
			fputs(current_function->current_state, file);
			fputs("_", file);
			fputs(current_function->next_state, file);
			fputs(" -> ", file);
			fputs(current_xmachine->name, file);
			fputs("_", file);
			fputs(current_function->next_state, file);
			fputs(";\n", file);
			
			current_function = current_function->next;
		}
		
		if(flag == 0)
		{
			fputs("}\n", file);
		}
		
		current_xmachine = current_xmachine->next;
	}
	fputs("\t\n\t/* Communications */\n", file);
	/* For every communication */
	current_communication = * modeldata->p_communications;
	while(current_communication)
	{
		fputs("\t", file);
		fputs(current_communication->output_function->agent_name, file);
		fputs("_", file);
		fputs(current_communication->output_function->name, file);
		fputs("_", file);
		fputs(current_communication->output_function->current_state, file);
		fputs("_", file);
		fputs(current_communication->output_function->next_state, file);
		fputs(" -> ", file);
		fputs(current_communication->input_function->agent_name, file);
		fputs("_", file);
		fputs(current_communication->input_function->name, file);
		fputs("_", file);
		fputs(current_communication->input_function->current_state, file);
		fputs("_", file);
		fputs(current_communication->input_function->next_state, file);
		fputs(" [ label = \"", file);
		fputs(current_communication->messagetype, file);
		fputs("\" color=\"#00ff00\" constraint=false];\n", file);
		
		current_communication = current_communication->next;
	}
	
	for(i = 0; i <= modeldata->layer_total; i++)
	{
		fputs("\t{ rank=same; layer_", file);
		sprintf(buffer, "%d", i);
		fputs(buffer, file);
		fputs("; ", file);
		
		current_xmachine = * modeldata->p_xmachines;
		while(current_xmachine)
		{
			// For each function
			current_function = current_xmachine->functions;
			while(current_function)
			{
				if(current_function->rank_in == i)
				{
					fputs(" ", file);
					fputs(current_xmachine->name, file);
					fputs("_", file);
					fputs(current_function->name, file);
					fputs("_", file);
					fputs(current_function->current_state, file);
					fputs("_", file);
					fputs(current_function->next_state, file);
					fputs("; ", file);
				}
				
				current_function = current_function->next;
			}
			
			current_xmachine = current_xmachine->next;
		}
		
		fputs("}\n", file);
	}
	fputs("}", file);
	
	/* Close the file */
	fclose(file);
}

void find_loop(xmachine_function * current, xmachine_function * depends)
{
	adj_function * current_adj_function;
	int flag = 0;
	
	//printf("FUNCTION: %s\n", current->name);
	
	//add_adj_function_simple(current, depends);
	
	current_adj_function = current->alldepends;
	while(current_adj_function)
	{
		//printf("\t%s\n", current_adj_function->function->name);
		
		if(strcmp(depends->name, current_adj_function->function->name) == 0)
		{
			flag = 1;
			current_adj_function = NULL;
		}
		else current_adj_function = current_adj_function->next;
	}
	
	if(flag == 1)
	{
		printf("*** ERROR: Function %s has loop with %s\n", current->name, depends->name);
		//exit(1);
	}
	else
	{
		add_adj_function_simple(current, depends);
		
		current_adj_function = depends->dependson;
		while(current_adj_function)
		{
			find_loop(current, current_adj_function->function);
			remove_adj_function_simple(current);
			
			current_adj_function = current_adj_function->next;
		}
	}
}

/** \fn void create_dependency_graph(char * filepath, model_data * modeldata)
 * \brief Calculate agent functions dependency graph and produce a dot graph description output.
 * \param filepath Pointer to the file path and name.
 * \param modeldata Data from the model.
 */
void create_dependency_graph(char * filepath, model_data * modeldata)
{
	/* pointers to model datatypes */
	xmachine * current_xmachine;
	xmachine * current_xmachine2;
	xmachine_function * current_function;
	xmachine_function * current_function2;
	xmachine_ioput * current_input;
	xmachine_ioput * current_output;
	flame_communication * current_communication;
	adj_function * current_adj_function;
	layer * current_layer;
	xmachine_state * current_state;
	function_pointer * current_function_pointer;
	xmachine_message * current_message;
	xmachine_ioput * current_ioput;
	
	int k, m;
	
	/* Find start state of agents, find error if more than one? */
	/* For each agent */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		current_state = current_xmachine->states;
		while(current_state)
		{
			k = 0;
			m = 0;
			current_function = current_xmachine->functions;
			while(current_function)
			{
				if(strcmp(current_function->next_state, current_state->name) == 0)
					k = 1;
				
				if(strcmp(current_function->current_state, current_state->name) == 0)
					m++;
				
				current_function = current_function->next;
			}
			
			if(k == 0)
			{
				/*printf("%s - %s\n", current_xmachine->name, current_state->name);*/
				current_xmachine->start_state = current_state;
			}
			
			if(m == 0)
			{
				/*printf("END STATE: %s - %s\n", current_xmachine->name, current_state->name);*/
				addstateholder(current_state, &current_xmachine->end_states);
			}
			
			if(m > 1)
			{
				/*printf("More than one outgoing edge: %s - %s\n", current_xmachine->name, current_state->name);*/
			}
			
			current_state = current_state->next;
		}
		
		/* if no start state then error */
		if(current_xmachine->start_state == NULL)
		{
			printf("ERROR: no start state found in '%s' agent\n", current_xmachine->name);
			exit(0);
		}
		
		current_xmachine = current_xmachine->next;
	}
	
	/* For each agent */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		/* For each function */
		current_function = current_xmachine->functions;
		while(current_function)
		{
			current_input = current_function->inputs;
			while(current_input)
			{
				current_xmachine2 = * modeldata->p_xmachines;
				while(current_xmachine2)
				{
					current_function2 = current_xmachine2->functions;
					while(current_function2)
					{
						current_output = current_function2->outputs;
						while(current_output)
						{
							if(strcmp(current_input->messagetype, current_output->messagetype) == 0)
							{
								add_flame_communication(current_input->messagetype, current_function, current_function2, modeldata->p_communications);
							}
							
							current_output = current_output->next;
						}
						
						current_function2 = current_function2->next;
					}
					
					current_xmachine2 = current_xmachine2->next;
				}
				
				current_input = current_input->next;
			}
			
			current_function = current_function->next;
		}
		
		current_xmachine = current_xmachine->next;
	}
	
	printf("Creating dependency graph\n");
	/* Gather information */
	
	/* Look for internal dependencies */
	/* For each agent */
	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		/* For each function */
		current_function = current_xmachine->functions;
		while(current_function)
		{
			current_function2 = current_xmachine->functions;
			while(current_function2)
			{
				if(strcmp(current_function->current_state, current_function2->next_state) == 0)
				{
					add_adj_function(current_function2, current_function, "internal");
				}
				
				current_function2 = current_function2->next;
			}
			
			current_function = current_function->next;
		}
		
		current_xmachine = current_xmachine->next;
	}
	
	/* Look for communication dependencies */
	/* For each communication */
	current_communication = * modeldata->p_communications;
	while(current_communication)
	{
		add_adj_function(current_communication->output_function, current_communication->input_function, current_communication->messagetype);
		
		current_communication = current_communication->next;
	}
	
	/* Calculate layers of dgraph */
	/* This is achieved by finding functions with no dependencies */
	/* giving them a layer no, taking those functions away and do the operation again */
	
	//check loops in dependencies
	/* For each agent */
/*	current_xmachine = * modeldata->p_xmachines;
	while(current_xmachine)
	{
		current_function = current_xmachine->functions;
		while(current_function)
		{
			current_adj_function = current_function->dependson;
			while(current_adj_function)
			{
				find_loop(current_function, current_adj_function->function);
				
				current_adj_function = current_adj_function->next;
			}
			
			current_function = current_function->next;
		}
		
		current_xmachine = current_xmachine->next;
	}*/
	
	/* For a set amount of times for each layer (cannot be more layers than functions?) */
	/* WARNING: there is no check for depencency loops that can cause an infinite loop */	
	current_layer = addlayer(modeldata->p_layers);
	int newlayer = 0;
	m = 0;
	while(m == 0)
	{
		/* For each agent */
		current_xmachine = * modeldata->p_xmachines;
		while(current_xmachine)
		{
			/* For each function */
			current_function = current_xmachine->functions;
			while(current_function)
			{
				/* If rank_in is unknown */
				if(current_function->rank_in == -1)
				{
					//printf("%s rank = %d\n", current_function->name, current_function->rank_in);
					
					k = 0;
					/* Search dependencies on the current function */
					current_adj_function = current_function->dependson;
					while(current_adj_function)
					{
						//printf("\tdependson %s\n", current_adj_function->function->name);
						/* Check if the function has a dependency on it (and not from itself) */
						/* Check to see if the dependency is a function and not be assigned a layer in last layers */
						if(current_adj_function->function->rank_in == -1 || current_adj_function->function->rank_in == newlayer)
						{
							/* Change flag to say there is a dependency */
							k = 1;
						}
						
						current_adj_function = current_adj_function->next;
					}
					if(k == 0)
					{
						//printf("%s-%s rank = %d\n", current_function->agent_name, current_function->name, current_function->rank_in);
						current_function->rank_in = newlayer;
						
						addfunction_pointer(&current_layer->functions, current_function);
						
						//printf("layer %d: %s  %s->%s\n", newlayer, current_function->name,
						//current_function->current_state, current_function->next_state);
						
						//current_function2 = addxfunction(&current_layer->functions);
						//current_function2->name = copystr(current_function->name);
						//current_function2->note = copystr(current_function->agent_name);
					}
				}
				
				current_function = current_function->next;
			}
			
			current_xmachine = current_xmachine->next;
		}
		/* Increment layer */
		newlayer++;
		/* If all the functions have layers then stop */
		/* Set flag to all functions have a layer */
		k = 0;
		current_xmachine = * modeldata->p_xmachines;
		while(current_xmachine)
		{
			/* For each function */
			current_function = current_xmachine->functions;
			while(current_function)
			{
				/* If a function does not have a layer yet */
				if(current_function->rank_in == -1) k = 1;
				
				current_function = current_function->next;
			}
			
			current_xmachine = current_xmachine->next;
		}
		/* If flag is still zero then stop */
		if(k == 0) m = 1;
		else
		{
			current_layer = addlayer(modeldata->p_layers);
		}
	}
	/* Make the layer value equal to the number of layers */
	newlayer--;
	
	modeldata->layer_total = newlayer;
	
	if(modeldata->depends_style == 0) output_stategraph("stategraph.dot", filepath, modeldata, 1);
	if(modeldata->depends_style == 1) output_dgraph("dgraph.dot", filepath, modeldata);
	
	/* Calculate points to start sync and end sync communication */
	/* and points where states have more than one leading edge */
	
	current_message = * modeldata->p_xmessages;
	while(current_message)
	{
		/* Points to the last function that outs a message type */
		current_function2 = NULL;
		
		current_layer = * modeldata->p_layers;
		while(current_layer)
		{
			current_function_pointer = current_layer->functions;
			while(current_function_pointer)
			{
				current_function = current_function_pointer->function;
				
				/* Find first input of a messagetype */
				current_input = current_function->inputs;
				while(current_input)
				{
					if(current_message->first == 0)
					{
						if( strcmp(current_message->name, current_input->messagetype) == 0 )
						{
							current_ioput = addioput(&current_function->first_inputs);
							current_ioput->messagetype = copystr(current_message->name);
							
							current_message->first = 1;
						}
					}
					
					current_input = current_input->next;
				}
				
				/* Find last output of a messagetype */
				current_output = current_function->outputs;
				while(current_output)
				{
						if( strcmp(current_message->name, current_output->messagetype) == 0 )
						{
							current_function2 = current_function;
						}
					
					current_output = current_output->next;
				}
				
				current_function_pointer = current_function_pointer->next;
			}
		
			current_layer = current_layer->next;
		}
		
		if(current_function2 != NULL)
		{
			current_ioput = addioput(&current_function2->last_outputs);
			current_ioput->messagetype = copystr(current_message->name);
		}
		
		current_message = current_message->next;
	}
	
	/* Test finding last output and first input of messages */
/*	current_layer = * modeldata->p_layers;
	while(current_layer)
	{
		current_function_pointer = current_layer->functions;
		while(current_function_pointer)
		{
			current_function = current_function_pointer->function;
			
			current_input = current_function->first_inputs;
			while(current_input)
			{
				printf("FIRST: %s\n", current_input->messagetype);
				
				current_input = current_input->next;
			}
			
			printf("FUNCTION: %s\n", current_function->name);
			
			current_input = current_function->last_outputs;
			while(current_input)
			{
				printf("LAST: %s\n", current_input->messagetype);
				
				current_input = current_input->next;
			}
			
			current_function_pointer = current_function_pointer->next;
		}
	
		current_layer = current_layer->next;
	}*/
}
