#include "tags.h"


void initialize_integrity(IntegrityTest *test)
    {
      test->start=0;
      test->stop=0;
      strcpy(test->directory,DEFAULTDIRECTORY);
      initialize_rules(&test->rules);
    }

void initialize_rules(Rules *rules)
     { int i;
       empty_rules(rules);
       for(i=0;i<DIM;i++)
         initialize_tagarray(&rules->array[i]);
      }

void initialize_tagarray(TagArray *tagarray)
     { int i;
       empty_tagarray(tagarray);
       for(i=0;i<DIM;i++)
         initialize_tag(&tagarray->array[i]);
     }
void initialize_tag(Tag *tag)
   {
    tag->type[0]='\0';
    tag->name[0]='\0';
    tag->sign=1;
    tag->sum_values=0;
  }
void print_tag(FILE *file, Tag *tag)
     {
      //fprintf(file,"%d ",tag->sign);
      fprintf(file,"%s ",tag->name);
      fprintf(file,"%s ",tag->type);
      fprintf(file,"%f ",tag->sum_values);
     }

void reset_integrity(IntegrityTest *test)
     { int i,k;
       Rules *rules;
       TagArray *tagarray;
       Tag *tag;
       rules=&test->rules;
       for(i=0;i<=rules->index;i++)
         {
           tagarray=&rules->array[i];
           for(k=0;k<=tagarray->index;k++)
           {
            tag=&tagarray->array[k];
            tag->sum_values=0;
           }
         }
}
void empty_tagarray(TagArray *tag_array)
     {
       
        tag_array->index=-1;
     }

void add_tag(TagArray *tag_array, Tag *untag)
     {  
        tag_array->index++;
        tag_array->array[tag_array->index]=*untag;
     }


void print_tagarray(FILE *file, TagArray *tagarray)
     { int i;
       for(i=0;i<=tagarray->index;i++)
         print_tag(file,&tagarray->array[i]);
     }


void print_rules(FILE *file, Rules *rules)
     {
     int i;
       for(i=0;i<=rules->index;i++)
         {
         //print_tagarray(file,&rules->array[i]);          
         print_rule(file,&rules->array[i]);
         fprintf(file,"    ");
         print_assertion_rule(&rules->array[i],file);
         fprintf(file,"\n");
         }
     }

void print_rule(FILE *file,TagArray *tagarray)
     {
       int i;
       Tag *tag;
       char sign;
       for(i=0;i<=tagarray->index;i++)
          {
           tag=&tagarray->array[i];
           if(tag->sign==-1) sign='-'; else sign='+';
           fprintf(file,"%c %s %s =%f\n",sign,tag->name,tag->type,tag->sum_values);
          }
    }

void print_integrity_test(IntegrityTest *test, FILE *file)
     {
      
      print_rules(file,&test->rules);

     }
      
/*delete all blan_ks from a string*/
void stream_blank(char *string)
    { 
      char aux[DIM];
      int i,k;
      i=0;
      k=0;
      while(string[i]!=';')
        {
          if(string[i]!=' ') 
           {
            aux[k]=string[i];
            k++;
           }
          i++;
        }
     aux[i]='\0';      
     strcpy(string,aux);
    }

void print_assertion_rule(TagArray *rule,FILE *file)
     {
      int i;
      Tag *tag;
      double sum;
      sum=0;
      for(i=0;i<=rule->index; i++)
        {
         tag=&rule->array[i];
         sum+=tag->sum_values*(tag->sign);
        }
  if(abs(sum)>PRECISION) fprintf(file,"THE RULE FAILED");
                 else    fprintf(file,"THE RULE IS VERIFIED");

     }

void parse_expression(TagArray *tag_array, char *expr)
    { 
      int i,k,found,sign;
      Tag current_tag;
      char tag[MAXCHAR];
      found=1;
       i=0;
      while(expr[i]!='\0')
       {// printf("%c",expr[i]);
          k=0; 
          sign=1;
          found=1;
          while((expr[i]!='\0')&&found)
            { 
              if((expr[i]=='+')||(expr[i]=='=')) found=0;
               else
                { tag[k]=expr[i];
                  k++;
                } 
              i++;
              if(expr[i]=='=') sign=-1;
            }
        tag[k]='\0';
	get_condition(tag,current_tag.type);
        strcpy(current_tag.name,tag);
        current_tag.sign=sign;
        add_tag(tag_array,&current_tag);
       }
     }



void get_condition(char *tag, char *type ) 
     { int open,close,end; 
       int i,k;
       open=0;
       close=0; k=0;
       i=0;
       end=-1;
      while(tag[i]!='\0')
        {
	 if(tag[i]=='(') {open=1; end=i; type[i]='\0';}
	 if(tag[i]==')') {type[k]=')'; close=1;k++;}
	 if(open&&(!close)) {type[k]=tag[i]; k++;}
	 i++;
	 }
      if(end>0) tag[end]='\0';
      type[k]='\0';
      }
                         
void add_rule(Rules *rules, TagArray *expr)
     {  
        rules->index++;
        rules->array[rules->index]=*expr;
        
     }
     
void empty_rules(Rules *rules)
     {
        
        rules->index=-1;
     }


TagArray *current_rule(Rules *rules)
    {  int index;
       index=rules->index;
       return &rules->array[index];
    }

void compile_rules(xmlNode * a_node, Rules *rules)
   {    
    xmlNode *cur_node = NULL;
    printf("read  rules \n");
    empty_rules(rules);
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {  
      if (cur_node->type == XML_ELEMENT_NODE) 
       {
         if(strcmp(cur_node->name,"rule")==0) compile_rule(cur_node->children,rules);
        
       }
    }
  }

void compile_rule(xmlNode * cur_node, Rules *rules)
{   
    TagArray tag_array;
    empty_tagarray(&tag_array);
    printf("compile  rule %s\n",cur_node->content);
    stream_blank(cur_node->content);
    parse_expression(&tag_array,cur_node->content);
    add_rule(rules,&tag_array);

}
 
int compile_start(xmlNode * a_node)
{ 
    int result;
      printf("compile tag start %s \n",a_node->content);
     if(strlen(a_node->content)>0)  
        sscanf(a_node->content,"%d",&result);
                       
     else printf("errore");
     return result;

}


int compile_stop(xmlNode * a_node)
{
    int result;
    printf("compile tag stop %s \n",a_node->content);
     if(strlen(a_node->content)>0)  
        sscanf(a_node->content,"%d",&result);               
     else printf("errore");
     return result;

}
void  compile_directory(xmlNode * a_node, IntegrityTest *test)
{   int len;
   
    printf("compile tag directory %s \n",a_node->content);
     len=strlen(a_node->content);
     if(len>0)  
        { if((a_node->content[len-1]=='/') ||(a_node->content[len-1]=='\\') ) strcpy(test->directory,(char *)a_node->content);
          else 
            { printf(" it isnt a directory, using default directory %s",DEFAULTDIRECTORY );   
              strcpy(test->directory,DEFAULTDIRECTORY);
            }  
        }
     else strcpy(test->directory,DEFAULTDIRECTORY);
        


}

void compile_iteration(xmlNode * a_node, IntegrityTest *test)
   {    
    xmlNode *cur_node = NULL;
    printf("read  iteration tag \n");
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
     {
      if (cur_node->type == XML_ELEMENT_NODE) 
       { 
        if(strcmp(cur_node->name,"start")==0) test->start=compile_start(cur_node->children);
	if(strcmp(cur_node->name,"stop")==0)  test->stop=compile_stop(cur_node->children);
       }
     } 
  }

void compile_integrity(xmlNode * a_node, IntegrityTest *test)
{  
    xmlNode *cur_node = NULL;
    printf("read  integrity \n");
    empty_rules(&test->rules);
    for (cur_node = a_node; cur_node; cur_node = cur_node->next)
    {
      if (cur_node->type == XML_ELEMENT_NODE) 
        {
	
	if(strcmp(cur_node->name,"iteration")==0) compile_iteration(cur_node->children,test);	
        if(strcmp(cur_node->name,"directory")==0) compile_directory(cur_node->children,test);
        
	if(strcmp(cur_node->name,"rules")==0) compile_rules(cur_node->children,&test->rules);
	}
    } 
}

int compile_test_rules(char *filename, IntegrityTest *test)
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
    compile_integrity(root_element->children,test);
    xmlFreeDoc(doc);
    xmlCleanupParser();
    return 0;
}  

Tag *in_rule(TagArray *tagarray,Tag *tag)
     { 
       int i,found;
       Tag *current_tag,*result;
       result=NULL;
       current_tag=NULL;
       i=0;
       found=1;
       while((i<=tagarray->index)&&found)
         {
          current_tag=&(tagarray->array[i]);
          //printf("%s",current_tag->type);
          //if(strstr(current_tag->type,tag->type)!=NULL) printf("%s\n",strstr(current_tag->type,tag->type));
          if(current_tag->type[0]=='\0')
             {
              if(strcmp(current_tag->name,tag->name)==0) 
                  {found=0; result=current_tag;}
             }
          else
          if((strcmp(current_tag->name,tag->name)==0)&&(strstr(current_tag->type,tag->type)!=NULL)) 
                  {found=0; result=current_tag;}
          i++;
         }
       return result;
      }
  
