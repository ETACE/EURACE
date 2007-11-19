int Household_reset_private_classifiersystem()
{
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->NR_TYPES;

	//dynamic array with number of rules in each type (size of subpopulations)
	int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM->NRRULES_PER_TYPE;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->NRRULES;

	//Resetting and storing values to memory:
	CLASSIFIERSYSTEM->experience=0;
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

int FinancialAgent_reset_public_classifiersystem()
{
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->nr_types;

	//dynamic array with number of rules in each type (size of subpopulations)
	int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM->nr_rules_per_type;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->nr_rules;
    
	//Resetting and storing values to memory:
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
//rule_type: type identifier for each rule
//nr_params_per_type: number of parameters for each rule type
//nr_params: no. of parameters for each rule
//parameters: parameter setting for each rule 
//rule_execution:  function name to execute the rule
//my_function_names: the names of the functions to call to execute a rule
//my_function_name[1]='Markowitz';
//my_function_name[2]='ProspectTheory';
//my_function_name[3]='RandomRule';

int initialize_ruledetailsystem()
{
 	//Getting the size of the system:
	int NR_TYPES=CLASSIFIERSYSTEM->nr_types;

	//dynamic array with number of rules in each type (size of subpopulations)
	int* NRRULES_PER_TYPE=CLASSIFIERSYSTEM->nr_rules_per_type;

	//total number of rules:
	int NRRULES=CLASSIFIERSYSTEM->nr_rules;
	
	//dynamic array with number of parameters in each type
	int* nr_params_per_type=CLASSIFIERSYSTEM->nr_params_per_type;
	
	//Local vars:
	int[NRRULES] 		ids;
	
	//Here: nr_params is the number of parameters for a rule of certain type
	//For each type we should have a prototype and then fill the dynamic array
	int[NRRULES]		rule_type;
	int[NR_TYPES]		nr_params;
	double**			parameters;			//parameter[NRRULES][MAX_PARAMS];
	
	char**				rule_execution;	    //rule_execution[NRRULES]
	int[NRRULES]		rule_type;			//rule_type[NRRULES]
	
	word_array * 		my_function_names = get_my_function_names(); //list of function names
	
	double				param_value;
	int					i,j,k,m, count;
	
	//First we set the field 'rule_type':
	count = 0;
	for (i=0;i<NR_TYPES;i++)
	{
		//Set nr_rules in the current type
		jmax = CLASSIFIERSYSTEM->array[i]->nr_rules_per_type;
		
		//For type i, traverse the rule ids from 0+count to jmax+count
		for (j=count;j<count+jmax;j++)
		{
			//We are now in rule id j
			CLASSIFIERSYSTEM->array[j]->rule_type = i;
			CLASSIFIERSYSTEM->array[j]->nr_params = CLASSIFIERSYSTEM->array[i]->nr_params_per_type;
			
		}
		//Set counter to current rule id
		count=count+jmax;
	}
	
	//Filling in random parameter settings
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

		//We set the field 'rule_execution':
		//First possibility: we test which function name the rule has
		j=CLASSIFIERSYSTEM->array[i]->rule_type;
		CLASSIFIERSYSTEM->array[i]->rule_execution[i]=sprintf('my_function_names[%d]',j);
	}

	//ALTERNATIVE CODE for rule_execution
	//we loop over the different rule types
	//this avoids the rule_type[i]	
	count = 0;
	for (i=0;i<NR_TYPES;i++)
	{
		//Set nr_rules in the current type
		jmax = CLASSIFIERSYSTEM->array[i]->nr_rules_per_type;
		
		//For type i, traverse the rule ids from 0+count to jmax+count
		for (j=count;j<count+jmax;j++)
		{
			//We are now in rule id j
			//Set the function call for rule j, which is just my_function_names[i]
			CLASSIFIERSYSTEM->array[j]->rule_execution=sprintf('my_function_names[%d]', i);
		}
		//Set counter to current rule id
		count=count+jmax;
	}
	
    return 0;
}




