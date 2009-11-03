#include "../header.h"
#include "../Firm_agent_header.h"
#include "../my_library_header.h"
#include "Labour_aux_headers.h"


/************************************ Firm agent functions ************************************/

/* Function condition functions */

int same_workers()
{
    if(NO_EMPLOYEES == EMPLOYEES_NEEDED) return 1;
    else return 0;
}

int less_workers_needed()
{
    if(NO_EMPLOYEES > EMPLOYEES_NEEDED) return 1;
    else return 0;
}

int more_workers_needed()
{
    if(NO_EMPLOYEES < EMPLOYEES_NEEDED) return 1;
    else return 0;
}




int Firm_finish_labour_market_first_round()
{
    return 0;
}


int Firm_start_labour_market()
{
    return 0;
}



/*************************************Firm Role: Labour Market*********************************/

/** \fn Firm_calculate_specific_skills_and_wage_offer()
 * \brief Firms calculate the specific skills for each general skill group 
 * and the according wage offer*/
int Firm_calculate_specific_skills_and_wage_offer()
{
    
    /*Sum up the specific skills of each general skill group (1-5): for average*/
    double sum_1 = 0;
    double sum_2 = 0;
    double sum_3 = 0;
    double sum_4 = 0;
    double sum_5 = 0;
    
    /*For every employee*/
    int n;
    for(n = 0; n < EMPLOYEES.size; n++)
    {
        /*general skill levels 1-5*/
        switch(EMPLOYEES.array[n].general_skill)
        {
        case 1:/*If employee has general skill level 1 add specific skill to sum1*/
            sum_1 = sum_1 + EMPLOYEES.array[n].specific_skill;
            break;

        case 2:
            sum_2 = sum_2 + EMPLOYEES.array[n].specific_skill;
            break;

        case 3:
            sum_3 = sum_3 + EMPLOYEES.array[n].specific_skill;
            break;

        case 4:
            sum_4 = sum_4 + EMPLOYEES.array[n].specific_skill;
            break;

        case 5:/*If employee has general skill level 5 add specific skill to sum5*/
            sum_5 = sum_5 + EMPLOYEES.array[n].specific_skill;
            break;
        }
    }

    /*for each general skill group: calculate the average specific skills*/
    int m;
    for(m = 1; m < 6;m++)
    {
        switch(m)
        {
        /*If skill level 1*/
        case 1:
            /*If there are employees with general skill level 1*/
            if(NO_EMPLOYEES_SKILL_1 > 0)
            {   
                /*Calculate average specific skill of skill group 1*/
                AVERAGE_S_SKILL_OF_1 = sum_1/NO_EMPLOYEES_SKILL_1;
            }
            
            /*Skill Group 1 gets the basic wage offer*/
            WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER* min(TECHNOLOGY,AVERAGE_S_SKILL_OF_1);
            break;
        
        case 2:
            if(NO_EMPLOYEES_SKILL_2 > 0)
            {
                AVERAGE_S_SKILL_OF_2 = sum_2/NO_EMPLOYEES_SKILL_2;  
            }
        
            /*The other skill groups get a higher wage offer depending on the                   productivity (specific skill)*/
            WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_2);
            break;

        case 3:
            if(NO_EMPLOYEES_SKILL_3 > 0)
            {
                AVERAGE_S_SKILL_OF_3 = sum_3/NO_EMPLOYEES_SKILL_3;  
            }
            
            WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_3);
            break;

        case 4:
            if(NO_EMPLOYEES_SKILL_4 > 0)
            {
                AVERAGE_S_SKILL_OF_4 = sum_4/NO_EMPLOYEES_SKILL_4;  
            }
            
            WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_4);
            break;

        case 5:/*If there are employees with skill level 5*/
            if(NO_EMPLOYEES_SKILL_5 > 0)
            {
                /*Calculate average specific skill of skill group 5*/
                AVERAGE_S_SKILL_OF_5 = sum_5/NO_EMPLOYEES_SKILL_5;  
            }
            
            WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER*min(TECHNOLOGY,AVERAGE_S_SKILL_OF_5);
            break;      
        }
    }
    
    return 0;
}



/** \fn Firm_send_vacancies()
 * \brief Firms post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies()
{
    
                                
     /*If more employees needed then send vacancies */
    if(EMPLOYEES_NEEDED > NO_EMPLOYEES)
    {
        /*Number of Vacancies/additional employees wanted*/
        VACANCIES = EMPLOYEES_NEEDED - NO_EMPLOYEES;

        /*For every skill group send vacancy message with the correspondent wage offer*/
        
        add_vacancies_message(ID, REGION_ID, 
        WAGE_OFFER_FOR_SKILL_1, WAGE_OFFER_FOR_SKILL_2, 
        WAGE_OFFER_FOR_SKILL_3, WAGE_OFFER_FOR_SKILL_4, 
        WAGE_OFFER_FOR_SKILL_5);
                                        
    }
    
    return 0;
}



/** \fn Firm_send_redundancies()
 * \brief Firms have to dismiss employees. Therefore the send firing_messages:
 */
int Firm_send_redundancies()
{
    
    /*If less employees needed then send redundencies */
    if(EMPLOYEES_NEEDED < NO_EMPLOYEES)
    {
        VACANCIES = 0;
        
        /*sorting employees: highest specific skills first*/
        /*int a, b;
        employee * first_employee, * second_employee;
        employee * temp_employee = (employee *)malloc(sizeof(employee));*/

        /* Using a bubble sort */
        /*for(a = 0; a<(EMPLOYEES.size-1); a++)
        {
            for(b=0; b<(EMPLOYEES.size-1)-a; b++) 
            {
                first_employee = &EMPLOYEES.array[b+1];
                second_employee = &EMPLOYEES.array[b];*/
        
                /* Comparing the values between neighbours */
                /*if(first_employee.specific_skill > 
                   second_employee.specific_skill)
                {*/
                    /* Swap neighbours */
                    /** temp_employee = * second_employee;
                    * second_employee = * first_employee;
                    * first_employee = * temp_employee;
                }
            }
        }*/

        /*sorting employees: highest specific skills first*/
        qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
            employee_list_rank_specific_skills_function);
        
        /*For the number of redundencies*/
        int j;


        //for(int i = 0; i < (NO_EMPLOYEES - EMPLOYEES_NEEDED); i++)
        int no_redundancies = NO_EMPLOYEES - EMPLOYEES_NEEDED;
        int i;
        for(i = 0; i < no_redundancies; i++)
        {   
            /*Firing: by chance*/
            j = random_int(0,(EMPLOYEES.size-1));
            add_firing_message(ID, EMPLOYEES.array[j].id);

            /*Firing: lowest specific skill*/
            /*j = EMPLOYEES.size-1;
            add_firing_message(ID, EMPLOYEES.array[j].id);*/
        
            switch(EMPLOYEES.array[j].general_skill)
            {
                /*If employee have had skill level 1 reduce the number of                       employees with skill level 1 by 1*/
                case 1:
                    NO_EMPLOYEES_SKILL_1--;
                    break;
                    
                case 2:
                    NO_EMPLOYEES_SKILL_2--;
                    break;

                case 3:
                    NO_EMPLOYEES_SKILL_3--;
                    break;

                case 4:
                    NO_EMPLOYEES_SKILL_4--;
                    break;
                /*If employee have had skill level 5 reduce the number of                       employees with skill level 5 by 1*/
                case 5:
                    NO_EMPLOYEES_SKILL_5--;
                    break;
            }
            
            remove_employee(&EMPLOYEES, j);
            NO_EMPLOYEES--;

            
        }
        
        //NO_EMPLOYEES = EMPLOYEES_NEEDED;
    }
    
    
    return 0;
}


/** \fn Firm_send_redundancies()
* \brief Firms have to dismiss employees. Therefore the send firing_messages:
*/
int Firm_send_random_redundancies()
{
           int random_num = random_int(LOWER_BOUND_FIRING,UPPER_BOUND_FIRING);
           
       /*sorting employees: highest specific skills first*/
       qsort(EMPLOYEES.array, EMPLOYEES.size, sizeof(employee),
           employee_list_rank_specific_skills_function);
             /*For the number of redundencies*/
       int j;


       //for(int i = 0; i < (NO_EMPLOYEES - EMPLOYEES_NEEDED); i++)
       int no_redundancies = (random_num*NO_EMPLOYEES)/100;

       if(((random_num*NO_EMPLOYEES)%100) < 100 && ((random_num*NO_EMPLOYEES)%100)>0)
       {
           no_redundancies = no_redundancies+1;
       }

//printf("random_num %d; NO_EMPLOYEES %d; no_redundancies %d
//\n",random_num,NO_EMPLOYEES,no_redundancies);
       int i;
       for(i = 0; i < no_redundancies; i++)
       {              /*Firing: by chance*/
           j = random_int(0,(EMPLOYEES.size-1));
           add_firing_message(ID, EMPLOYEES.array[j].id);

           /*Firing: lowest specific skill*/
           /*j = EMPLOYEES.size-1;
           add_firing_message(ID, EMPLOYEES.array[j].id);*/
                 switch(EMPLOYEES.array[j].general_skill)
           {
               /*If employee have had skill level 1 reduce the number of                         employees with skill level 1 by 1*/
               case 1:
                   NO_EMPLOYEES_SKILL_1--;
                   break;
                                 case 2:
                   NO_EMPLOYEES_SKILL_2--;
                   break;

               case 3:
                   NO_EMPLOYEES_SKILL_3--;
                   break;

               case 4:
                   NO_EMPLOYEES_SKILL_4--;
                   break;
               /*If employee have had skill level 5 reduce the number of                         employees with skill level 5 by 1*/
               case 5:
                   NO_EMPLOYEES_SKILL_5--;
                   break;
           }
                     remove_employee(&EMPLOYEES, j);
           NO_EMPLOYEES--;

                 }
             //NO_EMPLOYEES = EMPLOYEES_NEEDED;
         return 0;
} 



/** \fn Firm_read_job_applications_send_offer_or_rejection()
 * \brief Read job applications, rank, and send job offers and rejections
 */
int Firm_read_job_applications_send_job_offer_or_rejection()
{
    int no_applications;
            
        /* Create a job application dynamic array */
        job_application_array job_application_list; 
        init_job_application_array(&job_application_list);
        
        /* If day of month to act... */

        START_JOB_APPLICATION_MESSAGE_LOOP
            
            /* Read job application messages for this Firm */
            if(job_application_message->firm_id == ID)
            {
                /*Add application to a list (array)*/
                add_job_application(&job_application_list, 
                job_application_message->worker_id,
                job_application_message->region_id,
                job_application_message->general_skill, 
                job_application_message->specific_skill);
            }

        FINISH_JOB_APPLICATION_MESSAGE_LOOP



        no_applications = job_application_list.size;
        
        qsort(job_application_list.array, job_application_list.size, 
        sizeof(job_application), job_application_list_rank_general_skill_function);


        //printf("ID: %d no_applications %d, VACANCIES %d \n",ID,no_applications, VACANCIES);
        
        /*Case 1: Number of Vacancies is equal or bigger than number of applications:
        each applicant gets a job offer*/   
        if(no_applications <= VACANCIES)
        {


            
        	int i;
            for(i = 0; i < (job_application_list.size); i++)
            {
            /*A firm cannot send more job offers than it has vacancies to fill*/
            
                /*For the different skill levels */
                switch(job_application_list.array[i].general_skill)
                {
                /*If general skill level is 1 send job offer with wage offer for                    general skill level 1*/
                case 1:
                    add_job_offer_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1);
                    break;
                case 2:
                    add_job_offer_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2);
                    break;
                case 3:
                    add_job_offer_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3);
                    break;
                case 4:
                    add_job_offer_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4);
                    break;
                /*If general skill level is 5 send job offer with wage offer for                    general skill level 5*/
                case 5:
                    add_job_offer_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5);
                    break;
                }

            }

        }else
        {
        /*Case 2: Number of Vacancies is smaller  than number of applications:
        firm choose workers using a logit model*/
        int i;
        for(i = 0; i< VACANCIES; i++)
            {

            logit_array  logit_applications_list;
            init_logit_array(&logit_applications_list);
            
            
            /*Computing the dominator of the logit*/
            double denominator_logit = 0;
            double logit = 0.0;
            double sum_of_logits;
            double random_number;
            
            int j;
            for(j = 0; j< job_application_list.size;j++)
                {
                denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill);   

                //denominator_logit+= exp(0.5*job_application_list.array[j].general_skill + 0*job_application_list.array[j].specific_skill);
                }
            
            /*This computes the logits and stores them at the temorary array            logit_applications_list*/

           
            if(denominator_logit>0)
            {
            for(j = 0; j< job_application_list.size;j++)
                {
                //logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill)/ denominator_logit;


         
            logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill)/ denominator_logit;
            

            
            add_logit(&logit_applications_list, 100*logit,job_application_list.array[j].worker_id,job_application_list.array[j].general_skill);
                
                }
            }
            /*This draws a random number*/
            //random_number =  random_double(0.0,100.0);
            random_number =  (double)random_int(0,100);
            
            sum_of_logits = 0;
            for(j = 0; j< logit_applications_list.size;j++)
                {
        
            sum_of_logits += logit_applications_list.array[j].logit_value;
        
            if(random_number<sum_of_logits)
                    {

                    
                
                /*If condition is true, the firm chooses that worker and send a job offer               with the corresponding wage offer   */ 
                    switch(logit_applications_list.array[j].general_skill)
                        {
                /*If general skill level is 1 send job offer with wage offer for                    general skill level 1*/
                        case 1:
                            add_job_offer_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1);
                            break;
                        case 2:
                            add_job_offer_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2);
                            break;
                        case 3:
                            add_job_offer_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3);
                            break;
                        case 4:
                            add_job_offer_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4);
                            break;
                        /*If general skill level is 5 send job offer with wage offer for general skill level 5*/
                        case 5:
                            add_job_offer_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5);
                                break;
                        }

                /*The chosen worker has to be removed from the application list*/

                    	int k;
                        for(k = 0; k< job_application_list.size;k++)
                        {
                        if(job_application_list.array[k]
                    .worker_id == logit_applications_list.array[j]
                    .worker_id)
                            {
                            remove_job_application(&job_application_list,k);
                            break;
                            }
                    

                        }

                    break;  
                    }

                    
                }

                /* Free the job application dynamic array */
                free_logit_array(&logit_applications_list);
            }
        
        
        //The remaining applicants receive a rejection notification
        	
            for(i=0; i < job_application_list.size;i++)
            {
        //add_application_rejection_message(ID, 
          //      job_application_list.array[i].worker_id);
            }
        }

        /* Free the job application dynamic array */
        free_job_application_array(&job_application_list);
        
            
        return 0;
}



/** \fn Firm_read_job_responses()
 * \brief Read job responses and add employees
 */
int Firm_read_job_responses()
{           
    /* If day of month to act... */
    
    START_JOB_ACCEPTANCE_MESSAGE_LOOP
        
        /* Read job acceptance messages for this Firm */
        if(job_acceptance_message->firm_id == ID)
        {
            
            /*Add employee to employee list */
            VACANCIES--;
            NO_EMPLOYEES++;

            switch(job_acceptance_message->general_skill)
            {
                /*If new employee has general skill level 1*/
                case 1:
                    add_employee(&EMPLOYEES, 
                    job_acceptance_message->worker_id,
                    job_acceptance_message->region_id,                          WAGE_OFFER_FOR_SKILL_1, 
                    job_acceptance_message->general_skill, 
                    job_acceptance_message->specific_skill);

                    NO_EMPLOYEES_SKILL_1++;
                    break;
            
                case 2:
                    add_employee(&EMPLOYEES, 
                    job_acceptance_message->worker_id,
                    job_acceptance_message->region_id,                          WAGE_OFFER_FOR_SKILL_2, 
                    job_acceptance_message->general_skill, 
                    job_acceptance_message->specific_skill);

                    NO_EMPLOYEES_SKILL_2++;
                    break;
            
                case 3:
                    add_employee(&EMPLOYEES, 
                    job_acceptance_message->worker_id,
                    job_acceptance_message->region_id,                          WAGE_OFFER_FOR_SKILL_3, 
                    job_acceptance_message->general_skill, 
                    job_acceptance_message->specific_skill);

                    NO_EMPLOYEES_SKILL_3++;
                    break;
            
                case 4:
                    add_employee(&EMPLOYEES, 
                    job_acceptance_message->worker_id,
                    job_acceptance_message->region_id,                          WAGE_OFFER_FOR_SKILL_4, 
                    job_acceptance_message->general_skill, 
                    job_acceptance_message->specific_skill);
                    
                    NO_EMPLOYEES_SKILL_4++;
                    break;
                /*If new employee has general skill level 5*/
                case 5:
                    add_employee(&EMPLOYEES, 
                    job_acceptance_message->worker_id,
                    job_acceptance_message->region_id,                          WAGE_OFFER_FOR_SKILL_5, 
                    job_acceptance_message->general_skill, 
                    job_acceptance_message->specific_skill);
                    
                    NO_EMPLOYEES_SKILL_5++;
                    break;
            }           
        }

    FINISH_JOB_ACCEPTANCE_MESSAGE_LOOP

    
            
    return 0;
}

int Firm_read_job_quitting()
{
    /*Firms have to read quitting messages every day*/
    START_QUITTING_MESSAGE_LOOP
        /*Read quittings for this firm*/
        if(quitting_message->firm_id == ID)
        {
            int i;
            /*Control employees if one of them wants to quit*/
            for(i=0; i < (EMPLOYEES.size);i++)
            {
                if(quitting_message->worker_id == EMPLOYEES.array[i].id)
                {   
                    int temp_skill = 0;
                    temp_skill = EMPLOYEES.array[i].general_skill;
                    /*remove that employee from the list*/
                    remove_employee(&EMPLOYEES,i);
                            
                    VACANCIES++;
                    NO_EMPLOYEES--;

                    switch(temp_skill)
                    {
                        /*If the former employee have had general skill                         level 1 */
                        case 1:
                            NO_EMPLOYEES_SKILL_1--;
                            break;
                        
                        case 2:
                            NO_EMPLOYEES_SKILL_2--;
                            break;

                        case 3:
                            NO_EMPLOYEES_SKILL_3--;
                            break;

                        case 4:
                            NO_EMPLOYEES_SKILL_4--;
                            break;
                        /*If the former employee have had general skill                         level 5 */
                        case 5:
                            NO_EMPLOYEES_SKILL_5--;
                            break;
                    }
                }
            }       
        }

    FINISH_QUITTING_MESSAGE_LOOP
    
    return 0;
}


/** \fn Firm_update_wage_offer()
 * \brief Firms update wage_offer to get more applications
 */
int Firm_update_wage_offer()
{
        
    /*If there are "a lot" of vacancies still open...*/ 
    if(VACANCIES > MIN_VACANCY)  
    {
        WAGE_OFFER = WAGE_OFFER*(1+WAGE_UPDATE);

        WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+WAGE_UPDATE);
        WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+WAGE_UPDATE);
        WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+WAGE_UPDATE);
        WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+WAGE_UPDATE);
        WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+WAGE_UPDATE);    
    }
    
    return 0;
}



/** \fn Firm_send_vacancies_2()
 * \brief Firms which  did not fill all vacancies post vacancies and wage offer and send vacancies message
 */
int Firm_send_vacancies_2()
{
    /* If day of month to act... */
    
    /* If vacancies left */
    if(VACANCIES > 0)
    {
        /*For every general skill level (1-5)*/
    	
        add_vacancies2_message(ID, REGION_ID, 
        WAGE_OFFER_FOR_SKILL_1, WAGE_OFFER_FOR_SKILL_2, WAGE_OFFER_FOR_SKILL_3, WAGE_OFFER_FOR_SKILL_4, WAGE_OFFER_FOR_SKILL_5);
                         
    }   
    
    return 0;
}




/** \fn Firm_read_job_applications_send_offer_or_rejection()_2
 * \brief Read job applications, rank, and send job offers and rejections
 */
int Firm_read_job_applications_send_job_offer_or_rejection_2()
{
    int no_applications;
            
        /* Create a job application dynamic array */
        job_application_array job_application_list; 
        init_job_application_array(&job_application_list);
        
        /* If day of month to act... */

        START_JOB_APPLICATION2_MESSAGE_LOOP
            
            /* Read job application messages for this Firm */
            if(job_application2_message->firm_id == ID)
            {
                /*Add application to a list (array)*/
                add_job_application(&job_application_list, 
                job_application2_message->worker_id,
                job_application2_message->region_id,
                job_application2_message->general_skill, 
                job_application2_message->specific_skill);
            }

        FINISH_JOB_APPLICATION2_MESSAGE_LOOP



        no_applications = job_application_list.size;

        qsort(job_application_list.array, job_application_list.size, 
        sizeof(job_application), job_application_list_rank_general_skill_function);

        /*Case 1: Number of Vacancies is equal or bigger than number of applications:
        each applicant gets a job offer*/   
        if(no_applications <= VACANCIES)
        {
        	
        	int i;
            for(i = 0; i < (job_application_list.size); i++)
            {
            /*A firm cannot send more job offers than it has vacancies to fill*/
            
                /*For the different skill levels */
                switch(job_application_list.array[i].general_skill)
                {
                /*If general skill level is 1 send job offer with wage offer for                    general skill level 1*/
                case 1:
                    add_job_offer2_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1);
                    break;
                case 2:
                    add_job_offer2_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2);
                    break;
                case 3:
                    add_job_offer2_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3);
                    break;
                case 4:
                    add_job_offer2_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4);
                    break;
                /*If general skill level is 5 send job offer with wage offer for                    general skill level 5*/
                case 5:
                    add_job_offer2_message(ID, job_application_list.array[i]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5);
                    break;
                }

            }

        }else
        {
        /*Case 2: Number of Vacancies is smaller  than number of applications:
        firm choose workers using a logit model*/
        int i;
        for(i = 0; i< VACANCIES; i++)
            {

            logit_array  logit_applications_list;
            init_logit_array(&logit_applications_list);
            
            
            /*Computing the dominator of the logit*/
            double denominator_logit = 0;
            double logit =0.0;
            double sum_of_logits;
            double random_number;
            
            int j;
            for(j = 0; j< job_application_list.size;j++)
                {
                denominator_logit+= exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill);   

                //denominator_logit+= exp(0.5*job_application_list.array[j].general_skill + 0*job_application_list.array[j].specific_skill);
                }
            
            /*This computes the logits and stores them at the temorary array            logit_applications_list*/

         if(denominator_logit>0)
         {
            
            for(j = 0; j< job_application_list.size;j++)
                {
                logit = exp(LOGIT_PARAMETER_GENERAL_SKILLS*job_application_list.array[j].general_skill + LOGIT_PARAMETER_SPECIFIC_SKILLS*job_application_list.array[j].specific_skill)/ denominator_logit;

            //logit = exp(0.5*job_application_list.array[j].general_skill + 0*job_application_list.array[j].specific_skill)/ denominator_logit;
                
            
            add_logit(&logit_applications_list, 100*logit,job_application_list.array[j].worker_id,job_application_list.array[j].general_skill);
                
                }
         }
            /*This draws a random number*/
            //random_number =  random_double(0,100);
            random_number =  (double)random_int(0,100);
            
            sum_of_logits = 0;
            for(j = 0; j< logit_applications_list.size;j++)
                {

            sum_of_logits += logit_applications_list.array[j].logit_value;
        
            if(random_number<sum_of_logits)
                    {
                        
                /*If condition is true, the firm chooses that worker and send a job offer               with the corresponding wage offer   */ 
                    switch(logit_applications_list.array[j].general_skill)
                        {
                /*If general skill level is 1 send job offer with wage offer for                    general skill level 1*/
                        case 1:
                            add_job_offer2_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_1);
                            break;
                        case 2:
                            add_job_offer2_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_2);
                            break;
                        case 3:
                            add_job_offer2_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_3);
                            break;
                        case 4:
                            add_job_offer2_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_4);
                            break;
                        /*If general skill level is 5 send job offer with wage offer for general skill level 5*/
                        case 5:
                            add_job_offer2_message(ID, logit_applications_list.array[j]
                    .worker_id,REGION_ID, WAGE_OFFER_FOR_SKILL_5);
                                break;
                        }

                /*The chosen worker has to be removed from the application list*/
                    
                    	int k;
                        for(k = 0; k< job_application_list.size;k++)
                        {
                        if(job_application_list.array[k]
                    .worker_id == logit_applications_list.array[j]
                    .worker_id)
                            {
                            remove_job_application(&job_application_list,k);
                            break;
                            }
                    

                        }
                        break;
                        
                    }

                    

                }

                /* Free the job application dynamic array */
                free_logit_array(&logit_applications_list);
            }
        
        
        //The remaining applicants receive a rejection notification

            for(i=0; i < job_application_list.size;i++)
            {
        //add_application_rejection2_message(ID, 
          //      job_application_list.array[i].worker_id);
            }
        }

        /* Free the job application dynamic array */
        free_job_application_array(&job_application_list);
        
            
        return 0;
}



/** \fn Firm_read_job_responses_2()
 * \brief Read job responses and add employees
 */
int Firm_read_job_responses_2()
{
    /* If day of month to act... */
    
    START_JOB_ACCEPTANCE2_MESSAGE_LOOP

        /* Read job acceptance messages for this Firm */
        if(job_acceptance2_message->firm_id == ID)
        {
            /*Add employee to employee list*/ 
            
            VACANCIES--;
            NO_EMPLOYEES++;

            switch(job_acceptance2_message->general_skill)
            {
                /*If new employees has general skill level 1*/
                case 1:
                    add_employee(&EMPLOYEES, 
                    job_acceptance2_message->worker_id,
                    job_acceptance2_message->region_id,                             WAGE_OFFER_FOR_SKILL_1, 
                    job_acceptance2_message->general_skill,                         job_acceptance2_message->specific_skill);
                    
                    NO_EMPLOYEES_SKILL_1++;
                    break;
            
                case 2:
                    add_employee(&EMPLOYEES, 
                    job_acceptance2_message->worker_id,
                    job_acceptance2_message->region_id,                             WAGE_OFFER_FOR_SKILL_2, 
                    job_acceptance2_message->general_skill,                         job_acceptance2_message->specific_skill);

                    NO_EMPLOYEES_SKILL_2++;
                    break;
            
                case 3:
                    add_employee(&EMPLOYEES, 
                    job_acceptance2_message->worker_id,
                    job_acceptance2_message->region_id,                             WAGE_OFFER_FOR_SKILL_3, 
                    job_acceptance2_message->general_skill,                         job_acceptance2_message->specific_skill);

                    NO_EMPLOYEES_SKILL_3++;
                    break;
            
                case 4:
                    add_employee(&EMPLOYEES, 
                    job_acceptance2_message->worker_id,
                    job_acceptance2_message->region_id,                             WAGE_OFFER_FOR_SKILL_4, 
                    job_acceptance2_message->general_skill,                         job_acceptance2_message->specific_skill);

                    NO_EMPLOYEES_SKILL_4++;
                    break;
                /*If new employees has general skill level 5*/
                case 5:
                    add_employee(&EMPLOYEES, 
                    job_acceptance2_message->worker_id,
                    job_acceptance2_message->region_id,                             WAGE_OFFER_FOR_SKILL_5, 
                    job_acceptance2_message->general_skill,                         job_acceptance2_message->specific_skill);

                    NO_EMPLOYEES_SKILL_5++;
                    break;
            }
        }

    FINISH_JOB_ACCEPTANCE2_MESSAGE_LOOP
    
        
    return 0;
}

int Firm_read_job_quitting_2()
{
    /*Firms have to read quitting messages every day*/
    START_QUITTING2_MESSAGE_LOOP
        /*Read quittings for this firm*/
        if(quitting2_message->firm_id == ID)
        {
            int i;
            /*Control every employee if he wants to quit*/
       
            for(i=0; i < (EMPLOYEES.size);i++)
            {
                if(quitting2_message->worker_id == EMPLOYEES.array[i].id)
                {   
                    int temp_skill = 0;
                    temp_skill = EMPLOYEES.array[i].general_skill;
                    /*remove this former employee from the list*/
                    remove_employee(&EMPLOYEES,i);
                        
                    VACANCIES++;
                    NO_EMPLOYEES--;

                    switch(temp_skill)
                    {
                        /*If the former employee have had general skill                         level 1*/
                        case 1:
                            NO_EMPLOYEES_SKILL_1--;
                            break;
                        
                        case 2:
                            NO_EMPLOYEES_SKILL_2--;
                            break;

                        case 3:
                            NO_EMPLOYEES_SKILL_3--;
                            break;

                        case 4:
                            NO_EMPLOYEES_SKILL_4--;
                            break;
                        /*If the former employee have had general skill                         level 5*/
                        case 5:
                            NO_EMPLOYEES_SKILL_5--;
                            break;
                    }
                }
            }
            
        }

    FINISH_QUITTING2_MESSAGE_LOOP
    
    return 0;
}


/** \fn Firm_update_wage_offer_2()
 * \brief Firms update wage_offer to get more applications in next iteration
 */
int Firm_update_wage_offer_2()
{
    int i;
    int j = 0;

    /*Average  general skill at the end of one day*/
    
    for(i = 0; i < (EMPLOYEES.size); i++)
    {
        j += EMPLOYEES.array[i].general_skill;  
    }
    
    if(NO_EMPLOYEES > 0)
    {
        AVERAGE_G_SKILL = (double)((double)j/(double)NO_EMPLOYEES);
    }
    

    if(VACANCIES > MIN_VACANCY)  
    {
            /*WAGE_OFFER = WAGE_OFFER*(1+WAGE_UPDATE);

            WAGE_OFFER_FOR_SKILL_1 = WAGE_OFFER_FOR_SKILL_1*(1+WAGE_UPDATE);
            WAGE_OFFER_FOR_SKILL_2 = WAGE_OFFER_FOR_SKILL_2*(1+WAGE_UPDATE);
            WAGE_OFFER_FOR_SKILL_3 = WAGE_OFFER_FOR_SKILL_3*(1+WAGE_UPDATE);
            WAGE_OFFER_FOR_SKILL_4 = WAGE_OFFER_FOR_SKILL_4*(1+WAGE_UPDATE);
            WAGE_OFFER_FOR_SKILL_5 = WAGE_OFFER_FOR_SKILL_5*(1+WAGE_UPDATE);  */  
     }

    

    return 0;
}

int Firm_compute_mean_wage_specific_skills()
{
    double ave_wage =0.0;
    double ave_spec_skills =0.0;
    
    int i;
    for(i=0;i<EMPLOYEES.size;i++)
    {
        ave_wage+=EMPLOYEES.array[i].wage;
        ave_spec_skills += EMPLOYEES.array[i].specific_skill;
    }
    
    double no_employees = (double) NO_EMPLOYEES;
    if(no_employees==0)
    {
        MEAN_WAGE = WAGE_OFFER;
        MEAN_SPECIFIC_SKILLS = AVERAGE_S_SKILL_OF_1;
    }
    else
    {
        MEAN_WAGE = ave_wage /( no_employees);
        MEAN_SPECIFIC_SKILLS =ave_spec_skills/no_employees;
    }
return 0;
}
