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


// *********** BEGIN AUXILIARY FUNCTIONS ****************************

//double sum(double * p)
//Sum of a elements of a vector p.
double sum(double * p)
{
	int imax=p->size;
	double sum=0.0;
	
	for (i=0;i<imax;i++)
	{
		sum+=p[i];
	}	
	
    return sum;
}

//double * cumsum(double * p)
//Cumulative sum of elements of a vector p.
double * cumsum(double * p)
{
	int imax=p->size;
	double[imax] cumsum;
	
	//Cummulative sum
	cumsum[0]=p[0];
	for (i=0;i<imax-2;i++)
	{
		cumsum[i+1]=cumsum[i]+p[i+1];
	}
	cumsum[imax-1]=cumsum[imax-2]+p[imax-1];
	
    return cumsum;
}

//double * cumpdf(double * p)
//Cummulative probability density function.
//Given a vector of probabilities p, the cumulative pdf is given by:
//  cpdf = cumsum(p)/sum(p);
double * cumpdf(double * p)
{
	int imax=p->size;
	double sum_p = sum(p);
	double[imax] cumsum_p = cumsum(p);	
	double[imax] cpdf;

    //The cumulative pdf is:
	for (i=0;i<imax;i++)
	{    	
     	cpdf[i] = cumsum[i]/sum_p;
	}
	
    return cpdf;
}

//int draw(double * cpdf)
//Drawing a random number from the cummulative probability density function cpdf.
//Returns the bin number of a randomly chosen number u.
//Given a cummulative pdf F(.), the random number u belongs to bin j
//if and only if F(j-1)<= u < F(j).
int draw(double * cpdf)
{	
	int imax = cpdf->size;

    //Random number generator:
    u=rand_unif();
    
    nr_selected_bin=0;
    
    //Case 1: u<F(1)
        if (0<=u && u<cpdf[0])  
            nr_selected_bin=1;
        end;
    
    //Case 2: Travers the cpdf until u >= F(j-1)
	    for j=2:imax
	        if (cpdf[j-1]<=u && u<cpdf[j])
	            nr_selected_bin=j;
	            break;
	        end;
	    end;
	    
    //Case 3: u>=F(J)
        if (cpdf[imax]<=u)
            nr_selected_bin=imax;
        end;

    return nr_selected_bin;
}

//int ismember(int i, int * x, int n)
//Check if i is a member of the array x, with size n.
//Returns 1 if i is a member, 0 else.
int ismember(int i, int * x, int n)
{
	int k, ans=0;
	for (k=0;k<n;k++)
	{
		if(i==x[k])
		{
			ans=1;
			break;
		}
	}

	return ans;
}


//int * draw_without_replacement(int N, double * cpdf)
//Drawing N random numbers (integers) without replacement from the cummulative probability density function cpdf.
int * draw_without_replacement(int N, double * cpdf)
{
	double[N] draws;
	int i,k,count=0;
	
	for (k=0;k<N;k++)
	{
		draws[k]=-1;
	}
	
	//Continue drawing until N different numbers have been drawn
	while(count!=N)
	{
		i = draw(cpdf);
		
		//Check membership, only add if not yet a member
		if (ismember(i,draws,N)==0)
		{
			draws[count]=i;
			count += 1;
		}
	}
	
    return draws;
}

//int * draw_with_replacement(int N, double * cpdf)
//Drawing N random numbers (integers) with replacement from the cummulative probability density function cpdf.
int * draw_with_replacement(int N, double * cpdf)
{
	double[N] draws;
	int k=0;

	for (k=0;k<N;k++)
	{
		draws[k]=draw(cpdf);
	}
	
    return draws;
}

// *********** END AUXILIARY FUNCTIONS ****************************
