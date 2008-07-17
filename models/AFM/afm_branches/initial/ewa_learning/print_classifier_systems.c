/*********************************
 * print_classifier_systems.c
 * Script to print out the classifier systems per household as a table to an output file.
 * Version 1.0 of July 2008
 * For any comments, please contact Sander van der Hoog (svdhoog@gmail.com) 
 * *********************************
 * History:
 * 16/07/08 Sander 
 *********************************/

void FinancialAgent_print_public_classifiersystem(int itno);
void Household_print_private_classifiersystem(int itno);


void FinancialAgent_print_public_classifiersystem(itno)
{	
	char file[100];
	int i, rule_id, counter;
	double performance, avg_performance, my_performance, attraction, choiceprob;
	
	//Set the output file:
	ERR = sscanf("../log/CS_%d.txt", itno, file);
	
	if (ERR)
	{
		printf("sscanff returns: %d\n\n", ERR);
		printf("Error writing fileneame the char array");
	}
	else printf("File to write data to: %s", file);
	
	
	//Open a file pointer: FILE *Fp 
	printf("\n Appending data to file %s, starting to write...\n", file);
	FILE = fopen(file,"w");


	//Print comments/notes:
    fprintf(FILE,"Logfile: Print-out of all classifier systems. \n");
    fprintf(FILE,"Note 1: The performance and counter columns for the households are copied from the FinancialAdvisors CS. \n");
    fprintf(FILE,"Note 2: The avgperformance column can contain different values for two households, since it contains the copy from the FinancialAdvisors CS at the moment of the households most recent portfolio update. \n\n");

    //Print FinancialAdvisor classifier system:
    fprintf(FILE,"=============================================================================================\n");
    fprintf(FILE,"FinancialAdvisor:\n");
    fprintf(FILE,"rule\t performance\t counter\t avgperformance\t choice prob\n");
    fprintf(FILE,"=============================================================================================\n"); 

    for (i=0;i<PUBLIC_CLASSIFIERSYSTEM.nr_rules;i++)
    {
         rule_id 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].id;
		 counter 		= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].counter;
         performance 	= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].performance;
         avgperformance = PUBLIC_CLASSIFIERSYSTEM.ruletable[i].avg_performance;
         choiceprob 	= PUBLIC_CLASSIFIERSYSTEM.ruletable[i].choiceprob;

         fprintf(FILE,"%d\t %f\t %7d\t\t %f\t\t %f\n", rule_id, performance, counter, avgperformance, choiceprob);
    }
     fprintf(FILE,"=============================================================================================\n");

    fprintf(FILE,"\n");
	fclose(file);
}

void Household_print_private_classifiersystem(itno)
{
	char file[100];
	int i, rule_id, counter;
	double performance, avg_performance, my_performance, attraction, choiceprob;

	//Set the output file:
	file = sprintf(file, "../log/CS_%d.txt", itno);
	printf("%s", file);

	printf("\n Appending data to file %s, starting to write...\n", file);
	FILE = fopen(file,"w");


	//Print per household classifier system:
	 fprintf(FILE,"=============================================================================================\n");
	 fprintf(FILE,"Household: %d Current rule: %d\n", ID, PRIVATE_CLASSIFIERSYSTEM.current_rule);
	 fprintf(FILE,"rule\t performance\t counter\t avgperformance\t my_performance\t attraction\t choice prob\n");
	 fprintf(FILE,"=============================================================================================\n"); 
	
	for (i=0;i<PRIVATE_CLASSIFIERSYSTEM.nr_rules;i++)
	{
		rule_id 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].id;
		performance 	= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].performance;
		counter 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].counter;
		avgperformance 	= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].avg_performance;
		my_performance 	= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].my_performance;
	    attraction 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].attraction;
	    choiceprob 		= PRIVATE_CLASSIFIERSYSTEM.ruletable[i].choiceprob;
	    fprintf(FILE,"%d\t %f\t %7d\t\t %f\t\t %f\t\t %f\t %f\n", rule_id, performance, counter, avgperformance, my_performance, attraction, choiceprob);
	}
	fprintf(FILE,"=============================================================================================\n");

	fprintf(FILE,"\n");
	fclose(file);
}
