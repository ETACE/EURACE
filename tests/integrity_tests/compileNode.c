#include "compileNode.h"

int compile(char *filename, Rules *rules)
{
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    
    LIBXML_TEST_VERSION
    /*parse the file and get the DOM */
    doc = xmlReadFile(filename, NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", filename);
    }
    root_element = xmlDocGetRootElement(doc);
    compile_states(root_element->children,rules);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}


void readModel( IntegrityTest *test, char *path)
{    char name[MAXCHAR];
     char filename[MAXCHAR];
     FILE *file;
     printf(" read states \n");
     int i;
     file=fopen(path,"w");
     for(i=test->start;i<=test->stop;i++)
      {fprintf(file,"ITERATION %d\n",i);
       reset_integrity(test);
       strcpy(filename,test->directory);
       sprintf(name,"%d",i);
       strcat(filename,name);
       strcat(filename,".xml");
       printf("%s",filename);
       compile(filename,&(test->rules));
       print_integrity_test(test,file);   
      }
      fclose(file);
     printf("end read states \n");
 }
 
 
    
void compile_states(xmlNode * a_node,Rules *rules)
{
    xmlNode *cur_node = NULL;
    printf("read x-agent states \n");
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
      if (cur_node->type == XML_ELEMENT_NODE) 
        if(strcmp(cur_node->name,"xagent")==0) compile_xagent(cur_node->children,rules);
    } 
}

  void compile_xagent(xmlNode * a_node,Rules *rules)
{
    xmlNode *cur_node;
    cur_node=a_node;
    Tag current_tag;
    char *x_agent_name;
    double value;
    TagArray *tagarray;
    Tag *tag;
    int i;
    //printf("compile x machine \n");
    
      for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
        {
        if (cur_node->type == XML_ELEMENT_NODE) 
	   {
          if(strcmp(cur_node->name,"name")==0) 
            {
             x_agent_name=compile_name(cur_node->children);
             strcpy(current_tag.type,x_agent_name);
             
            }
           strcpy(current_tag.name,cur_node->name);
          for(i=0;i<=rules->index;i++)
          {
           
            tagarray=&rules->array[i];
          tag=in_rule(tagarray,&current_tag);
          if(tag!=NULL) 
                { 
                  value=compile_var(cur_node->children);
                  tag->sum_values+=value;
                 // printf("value =%f\n",value);
                                    
                }
           }  
        }
}
}
char *compile_name(xmlNode * a_node)
{
    
   
    //printf("compile name %s \n",a_node->content);
  
    return (char *)a_node->content;
}

double compile_var(xmlNode * a_node)
{
    double num;
     // printf("compile variable %s \n",a_node->content);
     if(strlen(a_node->content)>0)  
                                    sscanf((char *)a_node->content,"%lf",&num);			    
     else printf("errore");
     return num;

}
