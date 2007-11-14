int reset_private_classifiersystem()
{
    PrivateClassifierSystem classifiersystem=get_classifiersystem();

//Getting the size of the system:
	NrTotalRules=classifiersystem->double_ids_dynamic_array->size;

//Or is it:
//	NrTotalRules=double_(classifiersystem->ids)_dynamic_array->size;

//First declare local vars:
    int_array[NrTotalRules] 	ids;
    double						experience;
    int							current_rule;
    double						my_performance;
    double_array[NrTotalRules] 	avgperformance;
    double_array[NrTotalRules] 	attraction;
    double_array[NrTotalRules] 	choiceprob;
    
//Resetting:
	classifiersystem->experience =0;
	classifiersystem->current_rule=0;
	classifiersystem->my_performance=0;

	for (i=0; i<NrRules; i++)
	{
	
		classifiersystem->array[i]->avgperformance=0;
		classifiersystem->array[i]->attraction=0;
		classifiersystem->array[i]->choiceprob=0;
	}

//Setting values to memory:


//Using the capitalisation method to access memory values directly
//Resetting and storing in memory in one go:
	CLASSIFIERSYSTEM->experience =0;
	CLASSIFIERSYSTEM->current_rule=0;
	CLASSIFIERSYSTEM->my_performance=0;

	for (i=0; i<NrRules; i++)
	{
	
		CLASSIFIERSYSTEM->array[i]->avgperformance=0;
		CLASSIFIERSYSTEM->array[i]->attraction=0;
		CLASSIFIERSYSTEM->array[i]->choiceprob=0;
	}

    return 0;
}

