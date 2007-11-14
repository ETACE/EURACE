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
		classifiersystem->avgperformance[i]=0;
		classifiersystem->attraction[i]=0;
		classifiersystem->choiceprob[i]=0;
	}

//Setting values to memory:


    return 0;
}