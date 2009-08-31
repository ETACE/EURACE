/* code_generator.y  MF Locci
   Input file to 'bison' (or 'yacc').  Specification for the 
   code generator '.
*/
%{
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#define MAXDIM 120000
#define MAXCHAR 300
extern int  yylexlinenum;                   /* these are in YYlex      */
extern char *yytext;                        /* current token           */
extern FILE *yyin;
char *guard;
int ind;
FILE *file;
FILE *file_code;
char file_def[MAXCHAR];
char file_name_data[MAXCHAR];
char file_name[MAXCHAR];
  char sub_ext[10];
void read_and_write_external(FILE *file_code,char *name)
 { FILE *file; char c;
   file=fopen(name,"r");
   while(fscanf(file,"%c",&c)!=EOF)
    fprintf(file_code,"%c",c);
   fclose(file);
  
 }

void extract_name_ext(char *complete_name, char *name, char *extension)
  {
    int i,j,k,found;
    i=0;
    k=0;j=0;
    found=0;
    while(complete_name[i]!='\0')
      {
        
        if(!found) { name[k]=complete_name[i]; k++;}
                   else {extension[j]=complete_name[i]; j++; }
         
        i++;
        if((complete_name[i]=='.')&&(!found)) {found=1;i++;}
       
      }
   name[k]='\0';
   extension[j]='\0';
 }
void open_input_file(char *file_name)
{
  yyin      = NULL; 
  while(yyin == NULL){
    if(file_name){
      yyin = fopen(file_name,"r");
      if(yyin == NULL){
        printf("Unable to open \"%s\"\n",file_name);
      }
    } else {
      printf("stdin\n");
      yyin = stdin;
      break;
    }
  }
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


%}

%union{                                     /* this is the data union  */
    char name[41500];                       /* names                   */
}

%token CAPMESSAGENAME
%token MESSAGENAME
%token REPEAT
%token XAGENTS
%token XAGENTNAME
%token XAGENTSVAR
%token VARIABLES
%token ALLVARIABLES
%token MESSAGES
%token DATATYPES
%token IDENT
%token BEG
%token END
%token CONSTANT
%token CONSTANTS
%token TYPE
%token DTYPE
%token NAME
%token CAPNAME
%token DIM
%token EOL
%token DATATYPENAME
%token SUITENAME
%token FUNCTIONS
%token UTESTNAME
%token FUNCTIONNAME
%token IFSTATIC
%token IFNOTLAST
%token IFNOTSTATIC
%token IFPRIMTYPE
%token IFINAGENT
%token IFNOTPRIMTYPE 
%token PRIMITIVETYPES
%token PRIMTYPE
%token SPECIFIER
%token UNITTESTS
%token SUITES
%token UAGENTNAME 
%token SUITEPATH
%token XAGENTHEADERS
%start input

%type  <name>  c_code 
%type  <name>  block
%type  <name>  input
%type  <name>  forexp
%type  <name>  ifexpr  
%type  <name>  identifier
%type  <name>  iteration_expr
%type  <name>  expression
%type  <name>  CONSTANT  NAME DIM TYPE DTYPE XAGENTS MESSAGES VARIABLES FUNCTIONS DATATYPES PRIMITIVETYPES PRIMTYPE SPECIFIER CONSTANTS UNITTESTS SUITES  UAGENTNAME  FUNCTIONNAME UTESTNAME SUITEPATH XAGENTHEADERS CAPNAME IFPRIMTYPE IFNOTPRIMTYPE  ALLVARIABLES 

%%
input   : 

 expression  {     char aux[400];
            
                   sprintf(aux,"\nint generate_%s_%s_code()\n{\n",sub_ext,file_name);
                   strcpy($$,aux);
                   sprintf(aux,"char car[%d][MAXCHAR];\n char path[MAXPATH];\n read_intermediate_data(\"%s\",car,%d);\n",ind,file_name_data,ind);
                   strcat($$,aux);
                  sprintf(aux,"file=fopen(\"%s\",\"w\");\n",file_def);
                   strcat($$,aux);
           
                   strcat($$,$1); 
                   sprintf(aux,"fclose(file);\nffind_and_substitute(\"%s\");\n",file_def);
                   strcat($$,aux);
                   sprintf(aux,"strcpy(path,new_path);\nstrcat(path,\"%s\");\n",file_def);
                   strcat($$,aux);
                   sprintf(aux,"copy_file(\"%s\",path);\n",file_def);
                   strcat($$,aux);
                   strcat($$,"   return 0;\n}\n");fprintf(file_code,"%s",$$);} 
;

expression: ifexpr {strcpy($$,$1);}|forexp {strcpy($$,$1);}|c_code {strcpy($$,$1);}|c_code expression {strcpy($$,$1);strcat($$,$2);}|  expression c_code {strcpy($$,$1);strcat($$,$2);}|expression expression {strcpy($$,$1);strcat($$,$2);}| {strcpy($$," ");} 
;

block   : 
 BEG expression END { strcpy($$,$2); }
;
ifexpr  : IFSTATIC EOL block EOL {strcpy($$,"if(variable->dim>0)\n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          }; | 
IFNOTSTATIC EOL block EOL {strcpy($$,"if(variable->dim==0)\n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          };|
IFNOTLAST EOL block EOL {strcpy($$,"if((variables->index)>j)\n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          };|
IFINAGENT EOL block EOL {strcpy($$,"if(find_variable(variables,xvariable->name)>=0) \n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          };|
IFPRIMTYPE EOL block EOL {strcpy($$,"if((strcmp(variable->type,\"int\")==0)||(strcmp(variable->type,\"double\")==0)||(strcmp(variable->type,\"float\")==0)||(strcmp(variable->type,\"char\")==0))\n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          };|
IFNOTPRIMTYPE EOL block EOL {strcpy($$,"if(!((strcmp(variable->type,\"int\")==0)||(strcmp(variable->type,\"double\")==0)||(strcmp(variable->type,\"float\")==0)||(strcmp(variable->type,\"char\")==0)))\n{\n");
                          strcat($$,$3);
                          strcat($$,"\n}\n");
                          }; 

forexp  : REPEAT iteration_expr EOL block EOL 
                                       {  char aux[300];
                                          strcpy(guard,"");
                                        
                                        if(strcmp($2,"xagents")==0) 
                                          {strcpy(guard,"{\n  XMachine *xmachine;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<=xmachines->index;i++)\n");
                                           strcat(guard,"  {\nxmachine=&xmachines->list[i];\n");
                                           strcat(guard,"variables=&xmachine->variables;\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy($$,guard);
                                      
                                          }
                                          if(strcmp($2,"xagentheaders")==0) 
                                          {strcpy(guard,"{\n  XMachine *xmachine;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"  FILE  *file;\n");
                                           strcat(guard,"  char local_path[100];\n");
                                           sprintf(aux,"char aux[]=\"%s\";\n",file_def);
                                           strcat(guard,aux);
                                           strcat(guard,"for(i=0;i<=xmachines->index;i++)\n");
                                           strcat(guard,"  {\nxmachine=&xmachines->list[i];\n");
                                           strcat(guard,"variables=&xmachine->variables;\n");
                                           strcat(guard,"strcpy(local_path,xmachine->name);\n");
                                           strcat(guard,"strcat(local_path,aux);\n");
                                           strcat(guard,"file=fopen(local_path,\"w\");\n");
                                           strcat(guard,$4);
                                           strcat(guard,"fclose(file);\n");
                                           strcat(guard,"ffind_and_substitute(local_path);\n");
                                           strcat(guard,"strcpy(path,new_path);\n strcat(path,local_path);\n");
                                           strcat(guard,"copy_file(local_path,path);\n");
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy($$,guard);
                                      
                                          }
                                         if(strcmp($2,"utests")==0) 
                                          {strcpy(guard,"{\n  UnitaryTest *utest;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  Messages *messages;\n");
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<=suite->index;i++)\n");
                                           strcat(guard,"  {\nutest=&suite->list[i];\n");
                                           strcat(guard,"variables=&utest->variables;\n");
                                           strcat(guard,"messages=&utest->messages;\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy($$,guard);
                                      
                                          }
                                      if(strcmp($2,"suites")==0) 
                                          {strcpy(guard,"{\n  Suite *suite;\n");
                                        
                                           strcat(guard,"  int l;\n");
                                           strcat(guard,"for(l=0;l<=suites->index;l++)\n");
                                           strcat(guard,"  {\nsuite=&suites->list[l];\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy($$,guard);
                                      
                                          }

                                         if(strcmp($2,"variables")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   for(j=0;j<=variables->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&variables->list[j];\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy($$,guard);
                                      
                                          }
                                           if(strcmp($2,"allvariables")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   Variable *xvariable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   Variables *variables;\n variables=&model->variables;\n");
                                           strcat(guard,"   for(j=0;j<=variables->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&variables->list[j];\n");
                                           strcat(guard,"      xvariable=variable;\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy($$,guard);
                                      
                                          }
                                          if(strcmp($2,"datatypes")==0) 
                                          {strcpy(guard,"{\n   Datatype *datatype;\n");
                                           strcat(guard,"   Variables *variables;\n");
                                           strcat(guard,"   int k;\n");
                                           strcat(guard,"   for(k=0;k<=datatypes->index;k++)\n");
                                           strcat(guard,"   {\ndatatype=&datatypes->list[k];\n");
                                           strcat(guard,"variables=&datatype->variables;\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n   }\n}\n");
                                          
                                           strcpy($$,guard);
                                      
                                          }
                                           if(strcmp($2,"messages")==0) 
                                          {strcpy(guard,"{\n  Message *message;\n");
                                           strcat(guard,"  Variables *variables;\n");
                                           strcat(guard,"  int w;\n");
                                           strcat(guard,"for(w=0;w<=messages->index;w++)\n");
                                           strcat(guard,"  {\n   message=&messages->list[w];\n");
                                           strcat(guard,"   variables=&message->variables;\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n  }}\n");
                                      
                                           strcpy($$,guard);
                                      
                                          }
                                     if(strcmp($2,"primitivetypes")==0) 
                                          {strcpy(guard,"{\n");
                                         
                                           strcat(guard,"  int i;\n");
                                           strcat(guard,"for(i=0;i<4;i++)\n");
                                           strcat(guard,"  {\n "); 
                                           strcat(guard,$4);
                                           strcat(guard,"}\n}\n");
                                      
                                           strcpy($$,guard);
                                      
                                          }
                                      if(strcmp($2,"consts")==0) 
                                          {strcpy(guard,"{\n   Variable *variable;\n");
                                           strcat(guard,"   int j;\n");
                                           strcat(guard,"   for(j=0;j<=constants->index;j++)\n");
                                           strcat(guard,"   {\nvariable=&constants->list[j];\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n   }\n}\n");
                                           
                                           strcpy($$,guard);
                                      
                                          }
                                      if(strcmp($2,"functions")==0) 
                                          {strcpy(guard,"{\n  Function *variable;\n");
                                        
                                           strcat(guard,"  int l;\n");
                                           strcat(guard,"for(l=0;l<=functions->index;l++)\n");
                                           strcat(guard,"  {\nvariable=&functions->list[l];\n");
                                           strcat(guard,$4);
                                           strcat(guard,"\n  }\n}\n");
                                         
                                           strcpy($$,guard);
                                      
                                          }

                                         }
;
iteration_expr    : 
XAGENTS { strcpy($$,$1); }  |  
MESSAGES { strcpy($$,$1); }  | 
VARIABLES { strcpy($$,$1); } | 
PRIMITIVETYPES { strcpy($$,$1); } | 
CONSTANTS { strcpy($$,$1); } |
UNITTESTS { strcpy($$,$1); } |  
SUITES { strcpy($$,$1); } | 
FUNCTIONS { strcpy($$,$1); } |
XAGENTHEADERS { strcpy($$,$1); } |
ALLVARIABLES { strcpy($$,$1); } |
DATATYPES { strcpy($$,$1); }
;

 
c_code  : 
c_code CONSTANT {
                 char car[20];
                 sprintf(car,"car[%d]",ind);
                 strcpy($$,$1);
                 strcat($$,"fprintf(file,\"\%s\",");
                 strcat($$,car);
                 strcat($$,");\n");
                 fprintf(file,"%d %s\n",ind,$2); 
                 ind++;
                } | 
CONSTANT c_code {
                 char car[20]; 
                 sprintf(car,"car[%d]",ind);
                 strcpy($$,"fprintf(file,\"\%s\",");
                 strcat($$,car);
                 strcat($$,");\n");
                 strcat($$,$2);
                 fprintf(file,"%d %s\n",ind,$1); 
                 ind++;
                } |
CONSTANT       { 
                 char car[20]; 
                 sprintf(car,"car[%d]);\n",ind);
                 strcpy($$,"fprintf(file,\"\%s\",");
                 strcat($$,car);
                 strcat($$,");\n");
                 fprintf(file,"%d %s\n",ind,$1); 
                 ind++;
               } |
identifier c_code {strcpy($$,$1);strcat($$,$2);} | 
c_code identifier {strcpy($$,$1); strcat($$,$1);}| 
c_code EOL { strcpy ($$,$1) ;strcat($$,"");} |
EOL c_code { strcpy($$,"") ;strcat($$,$2);} |
EOL { strcpy($$,"") ;} 
 ;

identifier: NAME {strcpy($$,"fprintf(file,\"\%s\",variable->name);\n");}|
TYPE {strcpy($$,"fprintf(file,\"\%s\",variable->type);\n");}|
PRIMTYPE {strcpy($$,"fprintf(file,\"\%s\",primtype[i]);\n");}|
SPECIFIER {strcpy($$,"fprintf(file,\"\%s\",specifier[i]);\n");}|
 DTYPE  {strcpy($$,"if(variable->dim>0)\n{char aux[30];\n strcpy(aux,variable->type);\nstrcat(aux,\"_static\");\nfprintf(file,\"\%s\",aux);\n}\n else fprintf(file,\"\%s\",variable->type);\n");} |
 DIM  {strcpy($$,"if(variable->dim>0)\n fprintf(file,\"\%d\",variable->dim);\n");} |
 XAGENTNAME  {strcpy($$,"fprintf(file,\"\%s\",xmachine->name);\n");} |
 DATATYPENAME  {strcpy($$,"fprintf(file,\"\%s\",datatype->name);\n");} |
 UTESTNAME  {strcpy($$,"fprintf(file,\"\%s\",utest->name);\n");} |
 UAGENTNAME  {strcpy($$,"fprintf(file,\"\%s\",utest->xagent_name);\n");} |
 FUNCTIONNAME  {strcpy($$,"fprintf(file,\"\%s\",utest->function_name);\n");} |
 MESSAGENAME  {strcpy($$,"fprintf(file,\"\%s\",message->name);\n");} |
 SUITENAME  {strcpy($$,"fprintf(file,\"\%s\",suite->name);\n");} |
 SUITEPATH  {strcpy($$,"fprintf(file,\"\%s\",suite->path);\n");} |
 CAPMESSAGENAME { 
                   strcpy($$,"strcpy(capitalized,message->name);\n");
                   strcat($$,"capitalize(capitalized);\n");
                   strcat($$,"fprintf(file,\"\%s\",capitalized);\n");} |
 CAPNAME { 
                   strcpy($$,"strcpy(capitalized,variable->name);\n");
                   strcat($$,"capitalize(capitalized);\n");
                   strcat($$,"fprintf(file,\"\%s\",capitalized);\n");}

;
%%


yyerror(char *message)
{
  printf("%s\n",message);
}

int main(int argc, char *argv[])
{ 
  
 guard=(char *) malloc(sizeof(char)*MAXDIM );
  char file_name_code[MAXCHAR];
  char file_name_input[MAXCHAR];
  char current_name[MAXCHAR];
  char real_ext[10];

  char current_ext[10];
  char directory[MAXCHAR];
  char tempdir[MAXCHAR];
  struct dirent * Dirent;
  DIR * dir;
  file_code=NULL;
if( argc<2) printf("Error - input directory must be specified");
    else
     {
     strcpy(directory,argv[1]);
     
    if(!file_code) 
        {strcpy(file_name_code,directory);
         strcat(file_name_code,"main_code.c");
         file_code=fopen(file_name_code,"w");
         printf("writing file %s\n",file_name_code); 
         read_and_write_external(file_code,"prolog.c");
     
  
  

 dir = opendir(directory);
  while((Dirent = readdir(dir)) != NULL)	
  {
    extract_name_ext(Dirent->d_name, file_name, current_ext);
    extract_name_ext(current_ext, sub_ext, real_ext);
    //printf("%s %s\n",sub_ext,real_ext);
    if((strcmp(real_ext,"lkp")==0)||((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0)))
    {  
      ind=0;
      if(strlen(sub_ext)==0) strcpy(sub_ext,"x");
      if((strcmp(sub_ext,"lkp")==0)) {strcpy(real_ext,sub_ext); strcpy(sub_ext,"");}
      strcpy(current_name,directory);
      strcat(current_name,file_name);
      strcpy(file_name_data,file_name);
       if(strlen(sub_ext)!=0)  strcat(file_name_data,".");
      strcat(file_name_data,sub_ext);
      strcat(file_name_data,".tmp");
      strcpy(file_name_input,current_name);
      strcat(file_name_input,".");
      strcat(file_name_input,current_ext);
      strcpy(file_def,file_name); 
      if(strlen(sub_ext)!=0) strcat(file_def,".");
      strcat(file_def,sub_ext); 
      printf("opening like-pascal code file %s\n",file_name_data);
      open_input_file(file_name_input);
      strcpy(tempdir,directory);
      strcat(tempdir,file_name_data);
      file=fopen(tempdir,"w");
      printf("writing file %s\n",file_name_data);
      yyparse();
      fclose(file);
    }
  }
read_and_write_external(file_code,"epilog.c");
   dir = opendir(directory);
while((Dirent = readdir(dir)) != NULL)	
  {
    extract_name_ext(Dirent->d_name, file_name, current_ext);
    extract_name_ext(current_ext, sub_ext, real_ext);
    if((strcmp(real_ext,"lkp")==0)||((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0)))
    { 
      if(((strcmp(sub_ext,"lkp")==0)&&(strcmp(real_ext,"")==0))) fprintf(file_code,"   generate_%s_%s_code();\n","",file_name);
    else fprintf(file_code,"   generate_%s_%s_code();\n",sub_ext,file_name);
    }
  }
  fprintf(file_code,"return 0;\n}");

fclose(file_code);
 } }
strcpy(tempdir,directory);
strcat(tempdir,"xmachine_reader.c");
copy_file("xmachine_reader.c",tempdir);
strcpy(tempdir,directory);
strcat(tempdir,"xmachine_reader.h");
copy_file("xmachine_reader.h",tempdir);
strcpy(tempdir,directory);
strcat(tempdir,"Makefile");
copy_file("Makefile2",tempdir);
free(guard);
  return(0);
}

 
     
      
