#include "xmachine_reader.h"

void trim_blanks(char *string)
{ int i;
 char aux[MAXCHAR];
 i=0;
while(string[i]!='\0')
{
 if(string[i]!=' ') 
 aux[i]=string[i];
 i++;
} 
aux[i]='\0';
 strcpy(string,aux);

 
}
void initialize_variable(Variable *variable)
    {
      variable->name[0]='\0';
      variable->type[0]='\0';
      variable->dim=0;
    }
void initialize_module(Module *module)
    {
      module->path[0]='\0';
      module->flag=0;
    
    }
void initialize_variables(Variables *variables)
   { int i;
    
     variables->index=-1;
     variables->list=(Variable *)malloc(sizeof(Variable)*BLOCK);
     variables->real_size=BLOCK;
     for(i=0;i<variables->real_size;i++)
         initialize_variable(&variables->list[i]);
   }
void reset_variables(Variables *variables)
   { int i;
    
     variables->index=-1;
     for(i=0;i<variables->real_size;i++)
         initialize_variable(&variables->list[i]);
   }
void copy_variables(Variables *dest,Variables *source)
   { int i;
        
     for(i=0;i<=source->index;i++)
         add_variable(dest,&source->list[i]);
   }
void free_variables(Variables *variables)
   { 
     free(variables->list);
   }
void initialize_modules(Modules *modules)
   { int i;
     modules->index=-1;
     modules->real_size=MAXMOD;
     for(i=0;i<modules->real_size;i++)
         initialize_module(&modules->list[i]);
   }

void initialize_message(Message *message)
  {
    message->name[0]='\0';
    initialize_variables(&message->variables);
  }
void reset_message(Message *message)
  {
    message->name[0]='\0';
    reset_variables(&message->variables);
  }
void copy_message(Message *dest,Message *source)
  {
    strcpy(dest->name,source->name);
    copy_variables(&dest->variables,&source->variables);
  }
void free_message(Message *message)
  {
   
    free_variables(&message->variables);
  }

void initialize_xmachine(XMachine *xmachine)
     {
        xmachine->name[0]='\0';
         
        initialize_variables(&xmachine->variables);
        initialize_functions(&xmachine->functions);
     }
void reset_xmachine(XMachine *xmachine)
     {
        xmachine->name[0]='\0';    
        reset_variables(&xmachine->variables);
        reset_functions(&xmachine->functions);
     }
void copy_xmachine(XMachine *dest,XMachine *source )
     {
        strcpy(dest->name,source->name);   
        copy_variables(&dest->variables,&source->variables);
        dest->functions=source->functions;
     }
void free_xmachine(XMachine *xmachine)
     {
        
        free_variables(&xmachine->variables);
     }
void initialize_xmachines(XMachines *xmachines)
     { int i;
       xmachines->index=-1;
     
       for(i=0;i<MAXM;i++)
         initialize_xmachine(&xmachines->list[i]);
     }
void free_xmachines(XMachines *xmachines)
     { int i;
       xmachines->index=-1;
       for(i=0;i<MAXM;i++)
         free_xmachine(&xmachines->list[i]);
     }
void initialize_messages(Messages *messages)
      { 
       int i;
       messages->index=-1;
       for(i=0;i<DIM;i++)
         initialize_message(&messages->list[i]);
     }
void reset_messages(Messages *messages)
      { 
       int i;
       messages->index=-1;
       for(i=0;i<DIM;i++)
         reset_message(&messages->list[i]);
     }
void copy_messages(Messages *dest,Messages *source)
      { 
       int i;
       dest->index=source->index;
       for(i=0;i<DIM;i++)
         copy_message(&dest->list[i],&source->list[i]);
     }
void free_messages(Messages *messages)
      { 
       int i;
       messages->index=-1;
       for(i=0;i<DIM;i++)
         free_message(&messages->list[i]);
     }
void initialize_function(Function *function)
     {
        function->name[0]='\0';
        function->currentState[0]='\0';
        function->nextState[0]='\0';
     }

void initialize_functions(Functions *functions)
      { 
       int i;
       functions->index=-1;
       for(i=0;i<MAXFUN;i++)
        initialize_function(&functions->list[i]);
     }
void reset_functions(Functions *functions)
      { 
       
       functions->index=-1;
      
     }
void initialize_unitarytest(UnitaryTest *unitarytest)
{
  unitarytest->name[0]='\0';
  unitarytest->function_name[0]='\0';
   unitarytest->xagent_name[0]='\0';
  initialize_variables(&unitarytest->variables);
  initialize_messages(&unitarytest->messages);
}
void reset_unitarytest(UnitaryTest *unitarytest)
{
  unitarytest->name[0]='\0';
  unitarytest->function_name[0]='\0';
   unitarytest->xagent_name[0]='\0';
  reset_variables(&unitarytest->variables);
  reset_messages(&unitarytest->messages);
}

void copy_unitarytest(UnitaryTest *dest,UnitaryTest *source)
{
  strcpy(dest->name,source->name);
  strcpy(dest->function_name,source->function_name);
  strcpy(dest->xagent_name,source->xagent_name);
  copy_variables(&dest->variables,&source->variables);
  copy_messages(&dest->messages,&source->messages);
}

void free_unitarytest(UnitaryTest *unitarytest)
{
 
  free_variables(&unitarytest->variables);
  free_messages(&unitarytest->messages);
  
}
void initialize_suite(Suite *suite)
    {
       int i;
        suite->index=-1;
      suite->name[0]='\0';
      suite->path[0]='\0';
      suite->list=(UnitaryTest *)malloc(sizeof(UnitaryTest)*MAXUNITTESTS);
       for(i=0;i<MAXUNITTESTS;i++)
        
          initialize_unitarytest(&suite->list[i]);
   
     }
void reset_suite(Suite *suite)
    {
       int i;
        suite->index=-1;
      suite->name[0]='\0';
      suite->path[0]='\0';
       for(i=0;i<MAXUNITTESTS;i++)
        
          reset_unitarytest(&suite->list[i]);
   
     }
void copy_suite(Suite *dest,Suite *source)
{ int i;
  dest->index=source->index;
  strcpy(dest->name,source->name);
  strcpy(dest->path,source->path);
  for(i=0;i<=source->index;i++)
      copy_unitarytest(&dest->list[i],&source->list[i]);
}
void free_suite(Suite *suite)
    {
       int i;
        suite->index=-1;
      
       for(i=0;i<MAXUNITTESTS;i++)
        
          free_unitarytest(&suite->list[i]);
          free(suite->list);
   
     }
void initialize_suites(Suites *suites)
 {
       int i;
       suites->index=-1;
       suites->model_path[0]='\0';
       suites->list=(Suite *) malloc(sizeof(Suite)*MAXSUITES);
       for(i=0;i<MAXSUITES;i++)
        initialize_suite(&suites->list[i]);
     }

void free_suites(Suites *suites)
 {
       int i;
       suites->index=-1;
       for(i=0;i<MAXSUITES;i++)
        free_suite(&suites->list[i]);
        free(suites->list);
     }
void initialize_model(Model *model)
    {
          model->name[0]='\0';
         initialize_functions(&model->functions);
         initialize_modules(&model->modules); 
         initialize_messages(&model->datatypes);
         initialize_xmachines(&model->xmachines);
         initialize_messages(&model->messages);
         initialize_variables(&model->constants);
         initialize_variables(&model->variables);
    }

void add_unitarytest(Suite *suite, UnitaryTest *unitarytest)
     {
        suite->index++;
        copy_unitarytest(&suite->list[suite->index],unitarytest);
     }
void add_suite(Suites *suites, Suite *suite)
     {
        
        suites->index++;
        copy_suite(&suites->list[suites->index],suite);
     }
void add_newpath_suite(Suites *suites, char *path)
     {
        Suite *suite;
        suites->index++;
        suite=&suites->list[suites->index];
        strcpy(suite->path,path);
     }
void add_module(Modules *modules, Module *module)
     {
        modules->index++;
        modules->list[modules->index]=*module;
     }
void add_variable(Variables *variables, Variable *variable)
     {int i,newdim;
    if(find_variable(variables,variable->name)<0) 
        {
     if(variables->index==(variables->real_size-1)) 
           { 
         newdim=sizeof(Variable)*(variables->real_size+BLOCK);
         
         variables->list=(Variable  *) realloc(variables->list,newdim);
         for(i=variables->real_size;i<variables->real_size+BLOCK;i++) initialize_variable(&variables->list[i]);
         variables->real_size=variables->real_size+BLOCK;
         
           }
        variables->index++; 
        variables->list[variables->index]=*variable; 
        }
     }

void add_xmachine(XMachines *xmachines, XMachine *xmachine)
     {  
        if(find_xmachine(xmachines,xmachine->name)<0)
        {
        xmachines->index++;
        copy_xmachine(&xmachines->list[xmachines->index],xmachine);
        }
     }
void add_message(Messages *messages, Message *message)
     {  
        if(find_message(messages,message->name)<0)
        {
        messages->index++;
        copy_message(&messages->list[messages->index],message);
        }
     }


void add_function(Functions *functions, Function *function)
     {
       functions->index++;
       functions->list[functions->index]=*function;
     }

void compile_type(xmlNode * a_node, char *name)
{
    printf("    %s  ",a_node->content);
    strcpy(name,(char *)a_node->content);
}
void compile_name(xmlNode * a_node, char *name)
{
    printf("    %s \n",a_node->content);
    
    strcpy(name,(char *)a_node->content);
    trim_blanks(name);
}
int  compile_varname(xmlNode * a_node, char *name)
{   int i,start,stop;
    int dim,k;
    char dimension[20];
    printf("    %s \n",a_node->content);
    strcpy(name,(char *)a_node->content);
    i=0;
    start=0;
    stop=0;
    while(name[i]!='\0')
       { 
       if(name[i]=='[') start=i;
       if(name[i]==']') stop=i;
       i++;
       }
   k=0;
   if((start!=0)&&(stop!=0))
    { i=start+1;
      while(i<=stop)
        {
         dimension[k]=name[i];
         i++;
         k++;
        }
     dimension[k]='\0';
     name[start]='\0';
   }
    if(k>0) sscanf(dimension,"%d",&dim);
    else dim=0;
 
    return dim;
        
       
    
}
int find_variable(Variables *variables, char *name)
     { int i,index,found;
       Variable *variable;
       index=-1;
       i=0; found=1;
       while(found&&(i<=variables->index)) 
         {
          variable=&variables->list[i];
          if(strcmp(variable->name,name)==0) found=0;
          else i++;
         }
       if(found) return -1;
       else return i;
     } 
int find_xmachine(XMachines *xmachines, char *name)
     { int i,index,found;
       XMachine *xmachine;
       index=-1;
       i=0; found=1;
       while(found&&(i<=xmachines->index)) 
         {
          xmachine=&xmachines->list[i];
          if(strcmp(xmachine->name,name)==0) found=0;
          else i++;
         }
       if(found) return -1;
       else return i;
     } 
int find_message(Messages *messages, char *name)
     { int i,index,found;
       Message *message;
       index=-1;
       i=0; found=1;
       while(found&&(i<=messages->index)) 
         {
          message=&messages->list[i];
          if(strcmp(message->name,name)==0) found=0;
          else i++;
         }
       if(found) return -1;
       else return i;
     } 
int find_datatype(Datatypes *datatypes, char *name)
     { int i,index,found;
       Datatype *datatype;
       index=-1;
       i=0; found=1;
       while(found&&(i<=datatypes->index)) 
         {
          datatype=&datatypes->list[i];
          if(strcmp(datatype->name,name)==0) found=0;
          else i++;
         }
       if(found) return -1;
       else return i;
     }
void compile_variable(xmlNode * a_node, Variable *variable)
{
    xmlNode *cur_node;
      for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
        if (cur_node->type == XML_ELEMENT_NODE) 
           {
          if(strcmp((char *)cur_node->name,"name")==0) variable->dim=compile_varname(cur_node->children,variable->name );
          if(strcmp((char *)cur_node->name,"type")==0) compile_type(cur_node->children,variable->type );
           }
       }
}

void compile_memory(xmlNode * a_node,Variables *variables)
{
    xmlNode *cur_node;
    printf("compile x machine memory \n");
    Variable variable;
    initialize_variable(&variable);
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"variable")==0) 
           {  
              compile_variable(cur_node->children,&variable );
              add_variable(variables,&variable);
           }
    
         }
       }

}
 

void compile_datatypes(xmlNode * a_node,Datatypes *datatypes)
{
    xmlNode *cur_node;
   
    Datatype datatype;
    initialize_message(&datatype);
 
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"dataType")==0) 
           {  
              reset_message(&datatype);
              compile_datatype(cur_node->children,&datatype );
              add_message(datatypes,&datatype);
           }
    
         }
       }
free_message(&datatype);
}
 
void compile_datatype(xmlNode * a_node,Datatype *datatype)
{
    xmlNode *cur_node;
    printf("compiling  datatype  "); 

     for (cur_node = a_node; cur_node; cur_node = cur_node->next)  
           {
           if (cur_node->type == XML_ELEMENT_NODE) 
            {
             if(strcmp((char *)cur_node->name,"name")==0)       compile_name(cur_node->children,datatype->name );
             if(strcmp((char *)cur_node->name,"variables")==0)  compile_variables(cur_node->children,&datatype->variables);
            }
    }
}

 void compile_envfunction(xmlNode * a_node,Functions *functions)
{
    xmlNode *cur_node;
    Function function;
    initialize_function(&function);
    char current_path[MAXPATH];
    printf("compiling env function \n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
        if (cur_node->type == XML_ELEMENT_NODE) 
          {
          if(strcmp((char *)cur_node->name,"file")==0)  
            { 
             compile_name(cur_node->children,function.name);
             strcpy(current_path,relative_path); 
             strcat(current_path,function.name);
             strcpy(function.name,current_path);
             printf("%s\n",function.name);
             add_function(functions,&function);
            }
           }
       }
}


 void compile_environment(xmlNode * a_node, Model  *model)
{
    xmlNode *cur_node;
     printf("compiling environment\n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next)
       {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"functionFiles")==0) compile_envfunction(cur_node->children,&model->functions);
          if(strcmp((char *)cur_node->name,"dataTypes")==0) compile_datatypes(cur_node->children,&model->datatypes);
           if(strcmp((char *)cur_node->name,"constants")==0) compile_constants(cur_node->children,&model->constants);
        
           }
    }
}

void compile_function(xmlNode * a_node, Function *function)
{
    xmlNode *cur_node;
   
    printf("compiling function ");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"name")==0) compile_name(cur_node->children, function->name );
         
           }
    }
}
     


void compile_functions(xmlNode * a_node,Functions *functions)
{
    xmlNode *cur_node;
    cur_node=a_node;
    Function function;
    //initialize_functions(functions);
     printf("compiling functions\n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
        if (cur_node->type == XML_ELEMENT_NODE) 
         {
           if(strcmp((char *)cur_node->name,"function")==0) compile_function(cur_node->children,&function);
           add_function(functions,&function);
         }
    }
}



void compile_xagent(xmlNode * a_node,XMachine *xmachine)
{
    xmlNode *cur_node;
    cur_node=a_node;
    printf("compile x machine \n");
    
      for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
          if (cur_node->type == XML_ELEMENT_NODE) 
           {
            if(strcmp((char *)cur_node->name,"name")==0)  compile_name(cur_node->children, xmachine->name );
            if(strcmp((char *)cur_node->name,"memory")==0) compile_memory(cur_node->children,&xmachine->variables);
            if(strcmp((char *)cur_node->name,"functions")==0) compile_functions(cur_node->children,&xmachine->functions);
           }  
       }
}
 void compile_xagents(xmlNode * a_node,XMachines *xmachines)
{   int index;
    xmlNode *cur_node;
    cur_node=a_node;
    XMachine xmachine;
    initialize_xmachine(&xmachine);
    printf("compile xmachines list  \n");
    
      for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
       {
          if (cur_node->type == XML_ELEMENT_NODE) 
            if(strcmp((char *)cur_node->name,"xagent")==0)  
               {reset_xmachine(&xmachine);
                compile_xagent(cur_node->children, &xmachine);
                index=find_xmachine(xmachines,xmachine.name);
                if(index>-1) compile_xagent(cur_node->children, &xmachines->list[index] );
                else { 
                       
                       add_xmachine(xmachines,&xmachine);
                       //free_xmachine(&xmachine);
                     }
                     
               }
          
       }
  
}

void compile_message(xmlNode * a_node,Message *message)
{
    xmlNode *cur_node;
    printf("compiling  message  "); 

     for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"name")==0)       compile_name(cur_node->children,message->name );
          if(strcmp((char *)cur_node->name,"variables")==0)  compile_variables(cur_node->children,&message->variables);
        
           }
    }
}

void compile_variables(xmlNode * a_node,Variables *variables)
{
    xmlNode *cur_node;
    Variable variable;
    printf("compiling  variables \n"); 
    initialize_variable(&variable);
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
     {
        if (cur_node->type == XML_ELEMENT_NODE)
          {
          if(strcmp((char *)cur_node->name,"variable")==0)  
              {
               compile_variable(cur_node->children,&variable);
               add_variable(variables,&variable);
              }
           }
     }
}
void compile_constants(xmlNode * a_node,Variables *variables)
{
    xmlNode *cur_node;
    Variable variable;
    printf("compiling  constants \n"); 
    initialize_variable(&variable);
    if(variables->index<0)
     { 
       strcpy(variable.name,"current_day");
       strcpy(variable.type,"int");
       add_variable(variables,&variable);
       initialize_variable(&variable);
       strcpy(variable.name,"seed");
       strcpy(variable.type,"int");
       add_variable(variables,&variable);
       initialize_variable(&variable);
      }
       
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
     {
        if (cur_node->type == XML_ELEMENT_NODE)
          {
          if(strcmp((char *)cur_node->name,"variable")==0)  
              {
               compile_variable(cur_node->children,&variable);
               add_variable(variables,&variable);
              }
           }
     }
}

void compile_messages(xmlNode * a_node,Messages *messages)
{
    xmlNode *cur_node; 
    cur_node=a_node;
    Message message;
    printf("compiling  messages \n");
    initialize_message(&message);
    
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
      {
        if (cur_node->type == XML_ELEMENT_NODE) 
         {
          if(strcmp((char *)cur_node->name,"message")==0) 
             {
              reset_message(&message);
              compile_message(cur_node->children,&message);
              add_message(messages,&message);
             }
         }
      }
 free_message(&message);
}  
void compile_model(xmlNode * a_node,Model *model)
{
    xmlNode *cur_node = NULL;
    printf("compile x-agent model \n");
    for (cur_node = a_node; cur_node; cur_node = cur_node->next) {
      if (cur_node->type == XML_ELEMENT_NODE) {
    
          if(strcmp((char *)cur_node->name,"name")==0)  compile_name(cur_node->children,model->name );
          if(strcmp((char *)cur_node->name,"agents")==0) 
            compile_xagents(cur_node->children,&model->xmachines );                         
          if(strcmp((char *)cur_node->name,"messages")==0)      
            compile_messages(cur_node->children,&model->messages );
          if(strcmp((char *)cur_node->name,"environment")==0) 
            compile_environment(cur_node->children,model);
             if(strcmp((char *)cur_node->name,"models")==0) compile_modules(cur_node->children,&model->modules);
       }  
} 

}
void compile(char *filename, Model *model)
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
    
    compile_model(root_element->children,model);
    xmlFreeDoc(doc);
    xmlCleanupParser();
}
int read_suite(char *filename, Suite *suite)
{
    int readed;
    readed=0;
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    LIBXML_TEST_VERSION
    /*parse the file and get the DOM */
    doc = xmlReadFile(filename, NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", filename);
    }
    else{
    root_element = xmlDocGetRootElement(doc);
    
    compile_suite(root_element->children,suite);
    xmlFreeDoc(doc);
    readed=1;
    }
    xmlCleanupParser();
    return readed;
}

int read_suites(char *filename, Suites *suites)
{
    int readed;
    readed=0;
    xmlDoc *doc = NULL;
    xmlNode *root_element = NULL;
    LIBXML_TEST_VERSION
    /*parse the file and get the DOM */
    doc = xmlReadFile(filename, NULL, 0);

    if (doc == NULL) {
        printf("error: could not parse file %s\n", filename);
    }
    else{
    root_element = xmlDocGetRootElement(doc);
    
    compile_suites(root_element->children,suites);
    xmlFreeDoc(doc);
    readed=1;
    }
    xmlCleanupParser();
    return readed;
}
                      

void readModel(char * filename,Model *model)
{  printf("compile read model \n");
     compile(filename, model);
     printf("end compile \n");
 }
int main_read_model(int argc, char * argv[],Model *model,Suites *suites)
{   
  char module_path[250];
  char directory[250];
  char path[250];
  if(argc < 1)
	{

		printf("Usage: %s  [<path model>]/<name of the main model> \n",argv[0]);
		exit(0);
	}
  if(argc < 2)
	{
		printf("Need the path of the model\n");
		exit(0);
	}
 
  strcpy(path, argv[1]);
  extract_directory(path, directory);
 
  //strcpy(suite_path,module_path);
  read_suites(path,suites);
  if(strlen(suites->model_path)>0) 
   { strcpy(module_path,directory);
     strcat(module_path,suites->model_path);
     readModel(module_path,model);
  read_sub_modules(directory,model);
  read_all_suites(directory,suites);
  }
  else printf("Error 1 : the %s file doesn't contain the model path\n",path);
  //strcat(suite_path,"suite.xml");
  //read_suite(suite_path,suite);
  return 0;
 }

void put_and_shift(char *str,char car)
    { int i,len;
      i=0;
      len=strlen(str);
      str[len]=car;
      str[len+1]='\0';
      while(str[i]!='\0') 
      {str[i]=str[i+1]; i++;}
        
    }
          
 
/*int find_and_substitute(char *text, char *variable, char *value )
   { char buffer[20];
     char aux[10000]; 
     int i,k,j,last;
     i=0;k=0;
     strcpy(buffer,variable);
     i=0; while(buffer[i]!='\0') {buffer[i]=text[i];i++;} 
     i--;
     last=1;
     while((strlen(buffer)==strlen(variable)))
       {
        if(strcmp(buffer,variable)!=0) 
          { 
            aux[k]=buffer[0]; 
            k++;
          }
        else
          { for(j=0;j<strlen(value);j++)
              {
                aux[k]=value[j];
                k++; 
              }
          j=0; while((buffer[j]!='\0')) {if(text[i]!='\0') {buffer[j]=text[i];j++;i++;} else {buffer[j]='\0';j++;i++;}}
          i--;
          }
        if(text[i]!='\0') i++;
      put_and_shift(buffer,text[i]); 
      }
     aux[k]='\0';
     k=0;
     while(aux[k]!='\0') 
     {
      text[k]=aux[k];
      k++;
     }
    text[k]='\0';
  return 0;
   } */
int find_and_substitute(char *text, char *variable, char *value )
    { int i;
      char prec,current;
      i=1;
      if(strlen(text)>1)
       {
      prec=text[0];
      current=text[1];
    while(text[i]!='\0')
      {
       if((prec==variable[0])&&(current==variable[1])) 
       {
       text[i-1]=value[0];
       text[i]=value[1];
       }
       prec=current;
       i++;
       current=text[i];
      }
      }
return 0;
     }
int ffind_and_substitute(char *nome_file )
   { char *text;
     text=(char *)malloc(sizeof(char)*MAXTEXT );
     int i; 
     char current;
     char tab[3];
     char space[3];
     char newline[3];
     tab[0]='\t';
     tab[1]='\t';
     tab[2]='\0';
     newline[0]=' ';
     newline[1]='\n';
     newline[2]='\0';
     space[0]=' ';
     space[1]=' ';
     space[2]='\0';
   
     FILE *file;
     file=fopen(nome_file,"r"); i=0;
     while(fscanf(file,"%c",&current)!=EOF)
         { text[i]=current;i++;}
      text[i]='\0';
     fclose(file);
    
     find_and_substitute(text,"\\\\",newline);
     find_and_substitute(text,"!!",space);
     find_and_substitute(text,"^^",tab);
     file=fopen(nome_file,"w"); 
     i=0;
     while(text[i]!='\0') {fprintf(file,"%c",text[i]);i++;}
      fclose(file);
      free(text);
return 0;
}

         

void capitalize(char *simple_word)
    { char *result;
      int i;
      i=0;
     while(simple_word[i]!='\0') 
       {
          if(('a'<=simple_word[i])&&('z'>=simple_word[i])) simple_word[i]=('A'-'a')+simple_word[i];
          i++;
       }
   }



void compile_unittest(xmlNode * a_node, UnitaryTest  *unitarytest)
{
    xmlNode *cur_node;
     printf("compiling unittest\n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next)
       {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"name")==0) compile_name(cur_node->children,unitarytest->name);
          if(strcmp((char *)cur_node->name,"function")==0) compile_name(cur_node->children,unitarytest->function_name);
           if(strcmp((char *)cur_node->name,"xagent")==0) compile_name(cur_node->children,unitarytest->xagent_name);
           if((strcmp((char *)cur_node->name,"assertions")==0 )||(strcmp((char *)cur_node->name,"declaration")==0)) compile_declaration(cur_node->children,unitarytest);
          
           }
    }
}

void compile_suite(xmlNode * a_node,Suite *suite)
{
    xmlNode *cur_node; 
    UnitaryTest unitarytest;
    initialize_unitarytest(&unitarytest);
    printf("compiling  suite \n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
      {
        if (cur_node->type == XML_ELEMENT_NODE) 
         {
          if(strcmp((char *)cur_node->name,"name")==0) compile_name(cur_node->children,suite->name);
          if(strcmp((char *)cur_node->name,"unittest")==0) 
             {reset_unitarytest(&unitarytest);
              compile_unittest(cur_node->children,&unitarytest);
              add_unitarytest(suite,&unitarytest);
             }
         }
      }
     //free_unitarytest(&unitarytest);

}
void compile_suites(xmlNode * a_node,Suites *suites)
{
    xmlNode *cur_node; 
    char path[MAXPATH];
    printf("compiling  suites \n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next) 
      {
        if (cur_node->type == XML_ELEMENT_NODE) 
         {
          if(strcmp((char *)cur_node->name,"suitePath")==0) 
           {
            
            compile_name(cur_node->children,path);
            trim_blanks(suites->model_path);
            add_newpath_suite(suites,path);
          }
          if(strcmp((char *)cur_node->name,"modelPath")==0) {compile_name(cur_node->children,suites->model_path); }
         }
      }

}
 void compile_declaration(xmlNode * a_node, UnitaryTest *unitarytest)
{
    xmlNode *cur_node;
     printf("compiling declaration\n");
     for (cur_node = a_node; cur_node; cur_node = cur_node->next)
       {
        if (cur_node->type == XML_ELEMENT_NODE) {
          if(strcmp((char *)cur_node->name,"variables")==0) compile_variables(cur_node->children,&unitarytest->variables);
          if(strcmp((char *)cur_node->name,"messages")==0) compile_messages(cur_node->children,&unitarytest->messages);
           
           }
    }
}

void compile_modules(xmlNode * a_node, Modules *modules)
{
     xmlNode *cur_node;
     printf("compiling modules\n");
     Module module;
     for (cur_node = a_node; cur_node; cur_node = cur_node->next)
       {
        if (cur_node->type == XML_ELEMENT_NODE) 
          {
          if(strcmp((char *)cur_node->name,"model")==0) compile_module(cur_node->children,&module);
          add_module(modules,&module);
          }
    }
}
void compile_module(xmlNode * a_node, Module *module)
{    char result[MAXCHAR];
     xmlNode *cur_node;
     printf("compiling module\n");;
     for (cur_node = a_node; cur_node; cur_node = cur_node->next)
       {
        if (cur_node->type == XML_ELEMENT_NODE) 
          {
          if(strcmp((char *)cur_node->name,"file")==0) compile_name(cur_node->children,module->path);
          if(strcmp((char *)cur_node->name,"enabled")==0) { compile_name(cur_node->children,result);
                                                   if(strcmp(result,"true")==0) module->flag=1;
                                                   if(strcmp(result,"false")==0) module->flag=0;
                                                  }
          }
    }
}
void read_sub_modules(char *path, Model *model)
 { Modules *modules;
   Module *module;
   char relative[MAXPATH];
   char complete_path[MAXPATH ];
   int i,readed;
   modules=&model->modules;
   for(i=0;i<=modules->index;i++)
     { 
       module=&modules->list[i];
       if(module->flag) 
         { 
           strcpy(complete_path,path);
           strcat(complete_path,module->path);
           extract_directory(module->path,relative);
           strcpy(relative_path,relative);
           readModel(complete_path,model);
          }
                         

     }
 collect_all_variables(model);
}

void read_all_suites(char *directory,Suites *suites)
 { 
   char suite_path[MAXPATH];
   
   int i,readed;
   Suite *suite;
   for(i=0;i<=suites->index;i++)
     { 
       suite=&suites->list[i];
       strcpy(suite_path,directory);
       strcat(suite_path,suite->path);
       printf("%s\n",suite_path);
       readed=read_suite(suite_path,suite);
       printf("end reading suites\n");  

     }
}

void extract_directory(char *inputfile, char *directory)
 {    
      int i,lastd;
        i = 0;
	lastd = 0;
	while(inputfile[i] != '\0')
	{
	/* For windows directories */
		if(inputfile[i] == '\\') lastd=i;
	/* For unix directories */
		if(inputfile[i] == '/') lastd=i;
		i++;
	}
	/* If a directory is in the path */
	if(lastd != 0)
	{
		strcpy(directory, inputfile);
		directory[lastd+1] = '\0';
	}
	else directory[0] = '\0';
}
   
int copy_file(char *from_name,char *to_name )
 {FILE *from, *to;
  char ch;


  /* open source file */
  if((from = fopen(from_name, "rb"))==NULL) {
    printf("Cannot open source file.\n");
    return 1;
  }

  /* open destination file */
  if((to = fopen(to_name, "wb"))==NULL) {
    printf("Cannot open destination file%s.\n",to_name);
    return 1;
  }
  /* copy the file */
  while(!feof(from)) {
    ch = fgetc(from);
    if(ferror(from)) {
      printf("Error reading source file.\n");
      return 1;
    }
    if(!feof(from)) fputc(ch, to);
    if(ferror(to)) {
      printf("Error writing destination file.\n");
      return 1;
    }
  }

  if(fclose(from)==EOF) {
    printf("Error closing source file.\n");
    return 1;
  }

  if(fclose(to)==EOF) {
    printf("Error closing destination file.\n");
    return 1;
  }

  return 0;
}
     

void collect_all_variables(Model *model)
 {XMachines *xmachines;
  XMachine *xmachine;
  Variables *variables;
  int i,k;
  xmachines=&model->xmachines;
 
  for(i=0;i<=xmachines->index;i++)
   {
    xmachine=&xmachines->list[i];
    variables=&xmachine->variables;
    for(k=0;k<=variables->index;k++)
    add_variable(&model->variables,&variables->list[k]);
   }
 }
   
