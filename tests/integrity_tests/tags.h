#ifndef TAGH
#define TAGH
#define PRECISION 0.0000000001
#define DEFAULTDIRECTORY ""
#include <string.h>
#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define MAXCHAR 200
#define DIM 100

 struct  tag
          {
             char name[MAXCHAR];
             char type[MAXCHAR]; //Bank, Firm, etc,
             double sum_values;
             int sign;
          };
typedef struct tag Tag;
 struct tagarray_s
         { int index;
           Tag array[DIM];
         };
typedef struct tagarray_s TagArray; 

struct rules
      {
        int index;
	TagArray array[DIM];
      };
typedef struct rules Rules;

struct int_test
        { int start;
	  int stop;
          char directory[MAXCHAR];
	  Rules rules;
	 };
typedef struct int_test IntegrityTest;
	
void initialize_integrity(IntegrityTest *test);
void initialize_rules(Rules *rules);
void initialize_tagarray(TagArray *tagarray);
void initialize_tag(Tag *tag);

 	  

void empty_tagarray(TagArray *tag_array);
void add_tag(TagArray *tag_array, Tag *untag);



/*delete all blanks from a string*/
void stream_blank(char *string);
void parse_expression(TagArray *tag_array, char *expr);
void get_condition(char *tag, char *type );
void add_rule(Rules *rules, TagArray *expr);
void empty_rules(Rules *rules);
TagArray *current_rule(Rules *rules);
void compile_rules(xmlNode * a_node, Rules *rules);
void compile_rule(xmlNode * a_node, Rules *rules);
int compile_start(xmlNode * a_node);
int compile_stop(xmlNode * a_node);
void compile_integrity(xmlNode * a_node, IntegrityTest *test);
int compile_test_rules(char *filename, IntegrityTest *test);
void compile_iteration(xmlNode * a_node, IntegrityTest *test);
void print_tagarray(FILE *file, TagArray *tagarray);
void print_rules(FILE *file, Rules *rule);
void print_rule(FILE *file,TagArray *tagarray);
void  compile_directory(xmlNode * a_node, IntegrityTest *test);
void print_integrity_test(IntegrityTest *test, FILE *file);
Tag *in_rule(TagArray *rule,Tag *tag);
void reset_integrity(IntegrityTest *test);
void print_assertion_rule(TagArray *rule,FILE *file);
int in_condition(char *type,char *str);
#endif
