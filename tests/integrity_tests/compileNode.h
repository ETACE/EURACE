#ifndef NODEH
#define NODEH
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include "tags.h"


int compile(char *filename, Rules *rules);
void readModel( IntegrityTest *test, char *path);
void compile_states(xmlNode * a_node,Rules *rules);
 void compile_xagent(xmlNode * a_node,Rules *rules);

char *compile_name(xmlNode * a_node);
float compile_var(xmlNode * a_node);
#endif
