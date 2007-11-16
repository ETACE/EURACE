int reset_private_classifiersystem()
{
 	//Getting the size of the system:
	NRRULES=CLASSIFIERSYSTEM->double_ids_dynamic_array->size;
	NRRULES=CLASSIFIERSYSTEM->array[]->ids->size;

	//First declare local vars:
    int_array[NRRULES] 		ids;
    double					experience;
    int						current_rule;
    double					my_performance;
    double_array[NRRULES] 	avgperformance;
    double_array[NRRULES] 	attraction;
    double_array[NRRULES] 	choiceprob;
    
	//Resetting:
	CLASSIFIERSYSTEM->experience =0;
	CLASSIFIERSYSTEM->current_rule=0;
	CLASSIFIERSYSTEM->my_performance=0;

	for (i=0; i<NRRULES; i++)
	{
	
		CLASSIFIERSYSTEM->array[i]->avgperformance=0;
		CLASSIFIERSYSTEM->array[i]->attraction=0;
		CLASSIFIERSYSTEM->array[i]->choiceprob=0;
	}

	//Resetting and storing values to memory:
	//Using the capitalisation method to access memory values directly
	CLASSIFIERSYSTEM->experience =0;
	CLASSIFIERSYSTEM->current_rule=0;
	CLASSIFIERSYSTEM->my_performance=0;

	for (i=0; i<NRRULES; i++)
	{
		CLASSIFIERSYSTEM->array[i]->avgperformance=0;
		CLASSIFIERSYSTEM->array[i]->attraction=0;
		CLASSIFIERSYSTEM->array[i]->choiceprob=0;
	}

    return 0;
}

int reset_public_classifiersystem()
{
	//Not needed? then remove
    //PublicClassifierSystem classifiersystem;

	//Getting the size of the system:
	NRRULES=CLASSIFIERSYSTEM->double_ids_dynamic_array->size;
	NRRULES=CLASSIFIERSYSTEM->array[]->ids->size;

	//First declare local vars:
    int_array[NRRULES] 	ids;
    double_array[NRRULES]	performance;
    double_array[NRRULES] 	avgperformance;
    
	//Resetting:
	for (i=0; i<NRRULES; i++)
	{
		CLASSIFIERSYSTEM->array[i]->performance=0;
		CLASSIFIERSYSTEM->array[i]->avgperformance=0;
	}

	//Resetting and storing values to memory:
	//Using the capitalisation method to access memory values directly
	for (i=0; i<NRRULES; i++)
	{
		CLASSIFIERSYSTEM->array[i]->performance=0;	
		CLASSIFIERSYSTEM->array[i]->avgperformance=0;
	}

    return 0;
}

//HERE: function to initialize the rule_detail_system.
//Contains arrays for:
//NR_TYPES: number of different types of rules (typically NR_TYPES=3)
//NRRULES_PER_TYPE[NR_TYPES]: number of rules per type (typically the same, equal to 10)
//NRRULES_PER_TYPE=[10,10,10];
//ids: rule ids
//nr_params: no. of parameters for each rule
//parameter: parameter setting for each rule 
//rule_execution:  function names to execute the rule
//rule_type: type for each rule
//my_function_names: the names of the functions
//my_function_name[1]='Markowitz';
//my_function_name[2]='ProspectTheory';
//my_function_name[3]='RandomRule';

int initialize_ruledetailsystem()
{
	//Global vars:
	int 		  		NR_TYPES;			//nr. of types of rules
	int[NR_TYPES] 		NRRULES_PER_TYPE; 	//nr. of rules per type
	int			  		MAX_PARAMS;
	
	//Local vars:
	int[NRRULES] 		id;
	int[NRRULES]		nr_params;
	double**			parameters;			//parameter[NRRULES][MAX_PARAMS];
	
	char**				rule_execution;	    //rule_execution[NRRULES]
	int[NRRULES]		rule_type;			//rule_type[NRRULES]
	
	word_array * 		my_function_names = get_my_function_names(); //list of function names
	
	double				param_value;
	int					i,j,k,m;
	
	
	//Examples:
	//Adding an int to an int dynamic array:
	//add_int(int_var_dynamic_array, 987);
	//Adding a model data type to a data type dynamic array
	//add_my_datatype(my_datatype_var_dynamic_array, 4, 3.3, 2.2, 'u');
	//Length:
	//int_var_dynamic_array->size;
	//Accessing: 
	//my_datatype_var_dynamic_array->array[i]->int_datatype_var;
	//To create a local var:
	//int_array * my_int_list = init_int_array();
	//Free the local var:
	//free_int_array(my_int_list);
	
	for (i=0; i<NRRULES; i++)
	{
		//I want to add an empty double_array to the double2D_array parameter
		add_double_array(double2D_parameter_dynamic_array->array[i], []);
		
		//Filling the just added double_array parameter[i] with the parameter values of rule i
		for (j=0; j<nr_params[i]; j++)
		{
			//Filling the parameters[i][j]
			//A random value is chosen from the parameter resolution given by:
			//[p0:dp:p1] where dp is the step size.
				
			par_res = (p1[i]-p0[i])/dp[i]; //total possibilities
			k=rand_unif();
			m=floor(k*par_res); //random uniform in [0,par_res]	
	
			//Can we add a double directly inside the function add_double?
			add_double(parameters[i][j], p0[i] + m*dp[i]);		

			//param_value = p0[i] + m*dp[i];
			//add_double(parameters[i][j], param_value);

		}		

		//rule_execution
		//First possibility: we test which function name the rule has
		rule_execution[i]=sprintf('my_function_names[%d]', rule_type[i]);
	}

	//ALTERNATIVE CODE: rule_execution
	//we loop over the different rule types
	//this avoids the rule_type[i]	
	for (h=0; h<NR_TYPES; h++)
	{
		for (i=0; i<NRRULES_PER_TYPE[h]; i++)
		{
			rule_execution[i]=sprintf('my_function_names[%d]', h);
		}
	}

    return 0;
}

//FinancialAgent_send_ruledetailsystem_message()
//Function to send ruledetailsystem updates.
int FinancialAgent_send_ruledetailsystem_message()
{
	//Send a message containing the entire ruledetailsystem:
	add_ruledetailsystem_message(ruledetailsystem, range, x, y, z);

	//Alternative: we only need to send the double2D_array 
	//ruledetailsystem->parameters
	//double** parameters = ruledetailsystem->parameters;
	//add_ruledetailsystem_message(parameters, range, x, y, z);
		
    return 0;
}

//Household_read_ruledetailsystem_message()
//Function to download a new rule_detail_system.
//Used by agents to refresh their rule detail system
//We allow for changes in:
//parameters: changes occur due to crossover, mutation
int Household_read_ruledetailsystem_message()
{
	//Global vars:
	int 		  		NR_TYPES;			//nr. of types of rules
	int[NR_TYPES] 		NRRULES_PER_TYPE; 	//nr. of rules per type
	int			  		MAX_PARAMS;
	
	//Local vars:
	int[NRRULES] 		id;
	int[NRRULES]		nr_params;
	double**			parameters;			//parameter[NRRULES][MAX_PARAMS];
	
	char**				rule_execution;	    //rule_execution[NRRULES]
	int[NRRULES]		rule_type;			//rule_type[NRRULES]
	
	word_array * 		my_function_names = get_my_function_names(); //list of function names
	
	double				param_value;
	int					i,j,k,m,jmax=0;

	//HERE: As exception, we need a local copy of ruledetailsystem
	//because we need to copy it from the message
	//and then copy the values that are inside using a for loop.
	//So we need to temporarily store the contents of the message.
	//Do we need to free memory space afterward if we make a local copy?
	
	RuleDetailSystem *	ruledetailsystem;
	
	//Reading from new_ruledetailsystem_message
	new_ruledetailsystem_message = get_first_new_ruledetailsystem_message();
	while(new_ruledetailsystem_message)
	{
		ruledetailsystem = new_ruledetailsystem_message->ruledetailsystem;
				
		//Proceed to next message
		new_ruledetailsystem_message = get_next_new_ruledetailsystem_message(new_ruledetailsystem_message);
	}
	
	for (i=0; i<NRRULES; i++)
	{
		//Filling the double_array parameter[i] with the parameter values of rule i
		jmax=nr_params[i];
		for (j=0; j<jmax; j++)
		{
			//Filling the field parameters[i][j]
			//Problem: in xml we cannot add a name for the array[j]->(double param_value);
			//parameters[i] is a double_array, so to access its elements we need:
			  parameters[i][j] = ruledetailsystem->array[i]->parameters->array[j]->(double param_value);
		}

	}
	
    return 0;
}
