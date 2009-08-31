#include "xmachine_reader.h"
#include <stdio.h>
void read_intermediate_data(char *filename,char data[][MAXCHAR],int ind)
   { char aux[MAXCHAR];
    
     FILE *file;
     int index,i;
     file=fopen(filename,"r");
     if(!file) printf("could not open the intermediate data input");
     else 
     for(i=0;i<ind;i++) 
        { fscanf(file,"%d %s\n",&index,aux);
          //printf("car%d %s\n",index,aux);
          strcpy(data[index],aux);
        }
    }

Model *model;
Suites *suites;
FILE *file;
XMachines *xmachines;
Datatypes *datatypes;
Messages *messages;
Variables *constants;
Functions *functions;
char capitalized[MAXCHAR];
char new_path[MAXPATH];
char temp_path[MAXPATH];
 char primtype[4][10]={"int","char","float","double"};
 char specifier[4][10]={"%d","%c","%f","%lf"};


int generate_c_main_code()
{
char car[18][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("main.c.tmp",car,18);
file=fopen("main.c","w");
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
fclose(file);
ffind_and_substitute("main.c");
strcpy(path,new_path);
strcat(path,"main.c");
copy_file("main.c",path);
   return 0;
}

int generate_h_header_code()
{
char car[599][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("header.h.tmp",car,599);
file=fopen("header.h","w");
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[46]);
strcpy(capitalized,message->name);
capitalize(capitalized);
fprintf(file,"%s",capitalized);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
strcpy(capitalized,message->name);
capitalize(capitalized);
fprintf(file,"%s",capitalized);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",car[29]);

  }}
fprintf(file,"%s",car[47]);
{
   Variable *variable;
   int j;
   for(j=0;j<=constants->index;j++)
   {
variable=&constants->list[j];
fprintf(file,"%s",car[51]);
strcpy(capitalized,variable->name);
capitalize(capitalized);
fprintf(file,"%s",capitalized);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[48]);

   }
}
{
  int i;
for(i=0;i<4;i++)
  {
 fprintf(file,"%s",car[61]);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[52]);
}
}
{
   Datatype *datatype;
   Variables *variables;
   int k;
   for(k=0;k<=datatypes->index;k++)
   {
datatype=&datatypes->list[k];
variables=&datatype->variables;
fprintf(file,"%s",car[64]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",car[62]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[67]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[66]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[65]);

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[68]);

}

   }
}
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",car[74]);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[70]);

   }
}
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[89]);
fprintf(file,"%s",car[88]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[93]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[92]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[91]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[90]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[96]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[95]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[94]);

}

   }
}
fprintf(file,"%s",car[98]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[97]);

  }
}
fprintf(file,"%s",car[102]);
fprintf(file,"%s",car[101]);
fprintf(file,"%s",car[100]);
fprintf(file,"%s",car[99]);
{
   Variable *variable;
   int j;
   for(j=0;j<=constants->index;j++)
   {
variable=&constants->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[105]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[104]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[103]);

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[107]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[106]);

}

   }
}
fprintf(file,"%s",car[121]);
fprintf(file,"%s",car[120]);
fprintf(file,"%s",car[119]);
fprintf(file,"%s",car[118]);
fprintf(file,"%s",car[117]);
fprintf(file,"%s",car[116]);
fprintf(file,"%s",car[115]);
fprintf(file,"%s",car[114]);
fprintf(file,"%s",car[113]);
fprintf(file,"%s",car[112]);
fprintf(file,"%s",car[111]);
fprintf(file,"%s",car[110]);
fprintf(file,"%s",car[109]);
fprintf(file,"%s",car[108]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[123]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[122]);

  }
}
fprintf(file,"%s",car[135]);
fprintf(file,"%s",car[134]);
fprintf(file,"%s",car[133]);
fprintf(file,"%s",car[132]);
fprintf(file,"%s",car[131]);
fprintf(file,"%s",car[130]);
fprintf(file,"%s",car[129]);
fprintf(file,"%s",car[128]);
fprintf(file,"%s",car[127]);
fprintf(file,"%s",car[126]);
fprintf(file,"%s",car[125]);
fprintf(file,"%s",car[124]);
{
  int i;
for(i=0;i<4;i++)
  {
 fprintf(file,"%s",car[227]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[226]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[225]);
fprintf(file,"%s",car[224]);
fprintf(file,"%s",car[223]);
fprintf(file,"%s",car[222]);
fprintf(file,"%s",car[221]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[220]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[219]);
fprintf(file,"%s",car[218]);
fprintf(file,"%s",car[217]);
fprintf(file,"%s",car[216]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[215]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[214]);
fprintf(file,"%s",car[213]);
fprintf(file,"%s",car[212]);
fprintf(file,"%s",car[211]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[210]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[209]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[208]);
fprintf(file,"%s",car[207]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[206]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[205]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[204]);
fprintf(file,"%s",car[203]);
fprintf(file,"%s",car[202]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[201]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[200]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[199]);
fprintf(file,"%s",car[198]);
fprintf(file,"%s",car[197]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[196]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[195]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[194]);
fprintf(file,"%s",car[193]);
fprintf(file,"%s",car[192]);
fprintf(file,"%s",car[191]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[190]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[189]);
fprintf(file,"%s",car[188]);
fprintf(file,"%s",car[187]);
fprintf(file,"%s",car[186]);
fprintf(file,"%s",car[185]);
fprintf(file,"%s",car[184]);
fprintf(file,"%s",car[183]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[182]);
fprintf(file,"%s",car[181]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[180]);
fprintf(file,"%s",car[179]);
fprintf(file,"%s",car[178]);
fprintf(file,"%s",car[177]);
fprintf(file,"%s",car[176]);
fprintf(file,"%s",car[175]);
fprintf(file,"%s",car[174]);
fprintf(file,"%s",car[173]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[172]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[171]);
fprintf(file,"%s",car[170]);
fprintf(file,"%s",car[169]);
fprintf(file,"%s",car[168]);
fprintf(file,"%s",car[167]);
fprintf(file,"%s",car[166]);
fprintf(file,"%s",car[165]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[164]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[163]);
fprintf(file,"%s",car[162]);
fprintf(file,"%s",car[161]);
fprintf(file,"%s",car[160]);
fprintf(file,"%s",car[159]);
fprintf(file,"%s",car[158]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[157]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[156]);
fprintf(file,"%s",car[155]);
fprintf(file,"%s",car[154]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[153]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[152]);
fprintf(file,"%s",car[151]);
fprintf(file,"%s",car[150]);
fprintf(file,"%s",car[149]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[148]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[147]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[146]);
fprintf(file,"%s",car[145]);
fprintf(file,"%s",car[144]);
fprintf(file,"%s",car[143]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[142]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[141]);
fprintf(file,"%s",car[140]);
fprintf(file,"%s",car[139]);
fprintf(file,"%s",car[138]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[137]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[136]);
}
}
{
   Datatype *datatype;
   Variables *variables;
   int k;
   for(k=0;k<=datatypes->index;k++)
   {
datatype=&datatypes->list[k];
variables=&datatype->variables;
fprintf(file,"%s",car[250]);
fprintf(file,"%s",car[249]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[248]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[247]);
fprintf(file,"%s",car[246]);
fprintf(file,"%s",car[245]);
fprintf(file,"%s",car[244]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[243]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[242]);
fprintf(file,"%s",car[241]);
fprintf(file,"%s",car[240]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[239]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[238]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[237]);
fprintf(file,"%s",car[236]);
fprintf(file,"%s",car[235]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[234]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[233]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[232]);
fprintf(file,"%s",car[231]);
fprintf(file,"%s",car[230]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[229]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[228]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[254]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[253]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[252]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[251]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[257]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[256]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[255]);

}

   }
}
fprintf(file,"%s",car[344]);
fprintf(file,"%s",car[343]);
fprintf(file,"%s",car[342]);
fprintf(file,"%s",car[341]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[340]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[339]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[338]);
fprintf(file,"%s",car[337]);
fprintf(file,"%s",car[336]);
fprintf(file,"%s",car[335]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[334]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[333]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[332]);
fprintf(file,"%s",car[331]);
fprintf(file,"%s",car[330]);
fprintf(file,"%s",car[329]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[328]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[327]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[326]);
fprintf(file,"%s",car[325]);
fprintf(file,"%s",car[324]);
fprintf(file,"%s",car[323]);
fprintf(file,"%s",car[322]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[321]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[320]);
fprintf(file,"%s",car[319]);
fprintf(file,"%s",car[318]);
fprintf(file,"%s",car[317]);
fprintf(file,"%s",car[316]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[315]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[314]);
fprintf(file,"%s",car[313]);
fprintf(file,"%s",car[312]);
fprintf(file,"%s",car[311]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[310]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[309]);
fprintf(file,"%s",car[308]);
fprintf(file,"%s",car[307]);
fprintf(file,"%s",car[306]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[305]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[304]);
fprintf(file,"%s",car[303]);
fprintf(file,"%s",car[302]);
fprintf(file,"%s",car[301]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[300]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[299]);
fprintf(file,"%s",car[298]);
fprintf(file,"%s",car[297]);
fprintf(file,"%s",car[296]);
fprintf(file,"%s",car[295]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[294]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[293]);
fprintf(file,"%s",car[292]);
fprintf(file,"%s",car[291]);
fprintf(file,"%s",car[290]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[289]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[288]);
fprintf(file,"%s",car[287]);
fprintf(file,"%s",car[286]);
fprintf(file,"%s",car[285]);
fprintf(file,"%s",car[284]);
fprintf(file,"%s",car[283]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[282]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[281]);
fprintf(file,"%s",car[280]);
fprintf(file,"%s",car[279]);
fprintf(file,"%s",car[278]);
fprintf(file,"%s",car[277]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[276]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[275]);
fprintf(file,"%s",car[274]);
fprintf(file,"%s",car[273]);
fprintf(file,"%s",car[272]);
fprintf(file,"%s",car[271]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[270]);
fprintf(file,"%s",car[269]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[268]);
fprintf(file,"%s",car[267]);
fprintf(file,"%s",car[266]);
fprintf(file,"%s",car[265]);
fprintf(file,"%s",car[264]);
fprintf(file,"%s",car[263]);
fprintf(file,"%s",car[262]);
fprintf(file,"%s",car[261]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[260]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[259]);
fprintf(file,"%s",car[258]);

   }
}
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[363]);
fprintf(file,"%s",car[362]);
fprintf(file,"%s",car[361]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[360]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[359]);
fprintf(file,"%s",car[358]);
fprintf(file,"%s",car[357]);
fprintf(file,"%s",car[356]);
fprintf(file,"%s",car[355]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[354]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[353]);
fprintf(file,"%s",car[352]);
fprintf(file,"%s",car[351]);
fprintf(file,"%s",car[350]);
fprintf(file,"%s",car[349]);
fprintf(file,"%s",car[348]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[347]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[346]);
fprintf(file,"%s",car[345]);

  }
}
fprintf(file,"%s",car[375]);
fprintf(file,"%s",car[374]);
fprintf(file,"%s",car[373]);
fprintf(file,"%s",car[372]);
fprintf(file,"%s",car[371]);
fprintf(file,"%s",car[370]);
fprintf(file,"%s",car[369]);
fprintf(file,"%s",car[368]);
fprintf(file,"%s",car[367]);
fprintf(file,"%s",car[366]);
fprintf(file,"%s",car[365]);
fprintf(file,"%s",car[364]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[378]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[377]);
fprintf(file,"%s",car[376]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[381]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[380]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[379]);

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[383]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[382]);

}

   }
}
fprintf(file,"%s",car[403]);
fprintf(file,"%s",car[402]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[401]);
fprintf(file,"%s",car[400]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[399]);
fprintf(file,"%s",car[398]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[397]);
fprintf(file,"%s",car[396]);
fprintf(file,"%s",car[395]);
fprintf(file,"%s",car[394]);
fprintf(file,"%s",car[393]);
fprintf(file,"%s",car[392]);
fprintf(file,"%s",car[391]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[390]);
fprintf(file,"%s",car[389]);
fprintf(file,"%s",car[388]);
fprintf(file,"%s",car[387]);
fprintf(file,"%s",car[386]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[385]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[384]);

  }}
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[426]);
fprintf(file,"%s",car[425]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[424]);
fprintf(file,"%s",car[423]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[422]);
fprintf(file,"%s",car[421]);
fprintf(file,"%s",car[420]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[419]);
fprintf(file,"%s",car[418]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[417]);
fprintf(file,"%s",car[416]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[415]);
fprintf(file,"%s",car[414]);
fprintf(file,"%s",car[413]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[412]);
fprintf(file,"%s",car[411]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[410]);
fprintf(file,"%s",car[409]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[408]);
fprintf(file,"%s",car[407]);
fprintf(file,"%s",car[406]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[405]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[404]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[430]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[429]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[428]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[427]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[433]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[432]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[431]);

}

   }
}
fprintf(file,"%s",car[518]);
fprintf(file,"%s",car[517]);
fprintf(file,"%s",car[516]);
fprintf(file,"%s",car[515]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[514]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[513]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[512]);
fprintf(file,"%s",car[511]);
fprintf(file,"%s",car[510]);
fprintf(file,"%s",car[509]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[508]);
fprintf(file,"%s",car[507]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[506]);
fprintf(file,"%s",car[505]);
fprintf(file,"%s",car[504]);
fprintf(file,"%s",car[503]);
fprintf(file,"%s",car[502]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[501]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[500]);
fprintf(file,"%s",car[499]);
fprintf(file,"%s",car[498]);
fprintf(file,"%s",car[497]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[496]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[495]);
fprintf(file,"%s",car[494]);
fprintf(file,"%s",car[493]);
fprintf(file,"%s",car[492]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[491]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[490]);
fprintf(file,"%s",car[489]);
fprintf(file,"%s",car[488]);
fprintf(file,"%s",car[487]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[486]);
fprintf(file,"%s",car[485]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[484]);
fprintf(file,"%s",car[483]);
fprintf(file,"%s",car[482]);
fprintf(file,"%s",car[481]);
fprintf(file,"%s",car[480]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[479]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[478]);
fprintf(file,"%s",car[477]);
fprintf(file,"%s",car[476]);
fprintf(file,"%s",car[475]);
fprintf(file,"%s",car[474]);
fprintf(file,"%s",car[473]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[472]);
fprintf(file,"%s",car[471]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[470]);
fprintf(file,"%s",car[469]);
fprintf(file,"%s",car[468]);
fprintf(file,"%s",car[467]);
fprintf(file,"%s",car[466]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[465]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[464]);
fprintf(file,"%s",car[463]);
fprintf(file,"%s",car[462]);
fprintf(file,"%s",car[461]);
fprintf(file,"%s",car[460]);
fprintf(file,"%s",car[459]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[458]);
fprintf(file,"%s",car[457]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[456]);
fprintf(file,"%s",car[455]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[454]);
fprintf(file,"%s",car[453]);
fprintf(file,"%s",car[452]);
fprintf(file,"%s",car[451]);
fprintf(file,"%s",car[450]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[449]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[448]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[447]);
fprintf(file,"%s",car[446]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[445]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[444]);
fprintf(file,"%s",car[443]);
fprintf(file,"%s",car[442]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[441]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[440]);
fprintf(file,"%s",car[439]);
fprintf(file,"%s",car[438]);
fprintf(file,"%s",car[437]);
fprintf(file,"%s",car[436]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[435]);
fprintf(file,"%s",car[434]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[521]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[520]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[519]);
if((variables->index)>j)
{
fprintf(file,"%s",car[522]);

}

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[524]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[523]);
if((variables->index)>j)
{
fprintf(file,"%s",car[525]);

}

}

   }
}
fprintf(file,"%s",car[526]);

  }}
fprintf(file,"%s",car[528]);
fprintf(file,"%s",car[527]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[530]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[529]);

  }}
fprintf(file,"%s",car[549]);
fprintf(file,"%s",car[548]);
fprintf(file,"%s",car[547]);
fprintf(file,"%s",car[546]);
fprintf(file,"%s",car[545]);
fprintf(file,"%s",car[544]);
fprintf(file,"%s",car[543]);
fprintf(file,"%s",car[542]);
fprintf(file,"%s",car[541]);
fprintf(file,"%s",car[540]);
fprintf(file,"%s",car[539]);
fprintf(file,"%s",car[538]);
fprintf(file,"%s",car[537]);
fprintf(file,"%s",car[536]);
fprintf(file,"%s",car[535]);
fprintf(file,"%s",car[534]);
fprintf(file,"%s",car[533]);
fprintf(file,"%s",car[532]);
fprintf(file,"%s",car[531]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[572]);
fprintf(file,"%s",car[571]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[570]);
fprintf(file,"%s",car[569]);
fprintf(file,"%s",car[568]);
fprintf(file,"%s",car[567]);
fprintf(file,"%s",car[566]);
fprintf(file,"%s",car[565]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[564]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[563]);
fprintf(file,"%s",car[562]);
fprintf(file,"%s",car[561]);
fprintf(file,"%s",car[560]);
fprintf(file,"%s",car[559]);
fprintf(file,"%s",car[558]);
fprintf(file,"%s",car[557]);
fprintf(file,"%s",car[556]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[555]);
fprintf(file,"%s",car[554]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[553]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[552]);
fprintf(file,"%s",car[551]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[550]);

  }
}
fprintf(file,"%s",car[573]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[578]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[577]);
fprintf(file,"%s",car[576]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[575]);
fprintf(file,"%s",car[574]);

  }}
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[583]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[582]);
fprintf(file,"%s",car[581]);
fprintf(file,"%s",car[580]);
fprintf(file,"%s",car[579]);

  }}
fprintf(file,"%s",car[586]);
fprintf(file,"%s",car[585]);
fprintf(file,"%s",car[584]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0))
{
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[588]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[587]);

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[595]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[594]);
fprintf(file,"%s",car[593]);
fprintf(file,"%s",car[592]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[591]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[590]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[589]);

}

}
if(!((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0)))
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[597]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[596]);

}

   }
}

  }
}
fprintf(file,"%s",car[598]);
fclose(file);
ffind_and_substitute("header.h");
strcpy(path,new_path);
strcat(path,"header.h");
copy_file("header.h",path);
   return 0;
}

int generate_c_Suite_code()
{
char car[338][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("Suite.c.tmp",car,338);
file=fopen("Suite.c","w");
fprintf(file,"%s",car[63]);
fprintf(file,"%s",car[62]);
fprintf(file,"%s",car[61]);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Suite *suite;
  int l;
for(l=0;l<=suites->index;l++)
  {
suite=&suites->list[l];
fprintf(file,"%s",car[91]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[90]);
fprintf(file,"%s",car[89]);
fprintf(file,"%s",car[88]);
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",suite->path);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",car[74]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",car[70]);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",car[68]);
fprintf(file,"%s",car[67]);
fprintf(file,"%s",car[66]);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",car[64]);

  }
}
fprintf(file,"%s",car[119]);
fprintf(file,"%s",car[118]);
fprintf(file,"%s",car[117]);
fprintf(file,"%s",car[116]);
fprintf(file,"%s",car[115]);
fprintf(file,"%s",car[114]);
fprintf(file,"%s",car[113]);
fprintf(file,"%s",car[112]);
fprintf(file,"%s",car[111]);
fprintf(file,"%s",car[110]);
fprintf(file,"%s",car[109]);
fprintf(file,"%s",car[108]);
fprintf(file,"%s",car[107]);
fprintf(file,"%s",car[106]);
fprintf(file,"%s",car[105]);
fprintf(file,"%s",car[104]);
fprintf(file,"%s",car[103]);
fprintf(file,"%s",car[102]);
fprintf(file,"%s",car[101]);
fprintf(file,"%s",car[100]);
fprintf(file,"%s",car[99]);
fprintf(file,"%s",car[98]);
fprintf(file,"%s",car[97]);
fprintf(file,"%s",car[96]);
fprintf(file,"%s",car[95]);
fprintf(file,"%s",car[94]);
fprintf(file,"%s",car[93]);
fprintf(file,"%s",car[92]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[127]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[126]);
fprintf(file,"%s",car[125]);
fprintf(file,"%s",car[124]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[123]);
fprintf(file,"%s",car[122]);
fprintf(file,"%s",car[121]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[120]);

  }
}
fprintf(file,"%s",car[166]);
fprintf(file,"%s",car[165]);
fprintf(file,"%s",car[164]);
fprintf(file,"%s",car[163]);
fprintf(file,"%s",car[162]);
fprintf(file,"%s",car[161]);
fprintf(file,"%s",car[160]);
fprintf(file,"%s",car[159]);
fprintf(file,"%s",car[158]);
fprintf(file,"%s",car[157]);
fprintf(file,"%s",car[156]);
fprintf(file,"%s",car[155]);
fprintf(file,"%s",car[154]);
fprintf(file,"%s",car[153]);
fprintf(file,"%s",car[152]);
fprintf(file,"%s",car[151]);
fprintf(file,"%s",car[150]);
fprintf(file,"%s",car[149]);
fprintf(file,"%s",car[148]);
fprintf(file,"%s",car[147]);
fprintf(file,"%s",car[146]);
fprintf(file,"%s",car[145]);
fprintf(file,"%s",car[144]);
fprintf(file,"%s",car[143]);
fprintf(file,"%s",car[142]);
fprintf(file,"%s",car[141]);
fprintf(file,"%s",car[140]);
fprintf(file,"%s",car[139]);
fprintf(file,"%s",car[138]);
fprintf(file,"%s",car[137]);
fprintf(file,"%s",car[136]);
fprintf(file,"%s",car[135]);
fprintf(file,"%s",car[134]);
fprintf(file,"%s",car[133]);
fprintf(file,"%s",car[132]);
fprintf(file,"%s",car[131]);
fprintf(file,"%s",car[130]);
fprintf(file,"%s",car[129]);
fprintf(file,"%s",car[128]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[180]);
fprintf(file,"%s",car[179]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[178]);
fprintf(file,"%s",car[177]);
fprintf(file,"%s",car[176]);
fprintf(file,"%s",car[175]);
fprintf(file,"%s",car[174]);
fprintf(file,"%s",car[173]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[172]);
fprintf(file,"%s",car[171]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[170]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[169]);
fprintf(file,"%s",car[168]);
fprintf(file,"%s",car[167]);

  }}
fprintf(file,"%s",car[337]);
fprintf(file,"%s",car[336]);
fprintf(file,"%s",car[335]);
fprintf(file,"%s",car[334]);
fprintf(file,"%s",car[333]);
fprintf(file,"%s",car[332]);
fprintf(file,"%s",car[331]);
fprintf(file,"%s",car[330]);
fprintf(file,"%s",car[329]);
fprintf(file,"%s",car[328]);
fprintf(file,"%s",car[327]);
fprintf(file,"%s",car[326]);
fprintf(file,"%s",car[325]);
fprintf(file,"%s",car[324]);
fprintf(file,"%s",car[323]);
fprintf(file,"%s",car[322]);
fprintf(file,"%s",car[321]);
fprintf(file,"%s",car[320]);
fprintf(file,"%s",car[319]);
fprintf(file,"%s",car[318]);
fprintf(file,"%s",car[317]);
fprintf(file,"%s",car[316]);
fprintf(file,"%s",car[315]);
fprintf(file,"%s",car[314]);
fprintf(file,"%s",car[313]);
fprintf(file,"%s",car[312]);
fprintf(file,"%s",car[311]);
fprintf(file,"%s",car[310]);
fprintf(file,"%s",car[309]);
fprintf(file,"%s",car[308]);
fprintf(file,"%s",car[307]);
fprintf(file,"%s",car[306]);
fprintf(file,"%s",car[305]);
fprintf(file,"%s",car[304]);
fprintf(file,"%s",car[303]);
fprintf(file,"%s",car[302]);
fprintf(file,"%s",car[301]);
fprintf(file,"%s",car[300]);
fprintf(file,"%s",car[299]);
fprintf(file,"%s",car[298]);
fprintf(file,"%s",car[297]);
fprintf(file,"%s",car[296]);
fprintf(file,"%s",car[295]);
fprintf(file,"%s",car[294]);
fprintf(file,"%s",car[293]);
fprintf(file,"%s",car[292]);
fprintf(file,"%s",car[291]);
fprintf(file,"%s",car[290]);
fprintf(file,"%s",car[289]);
fprintf(file,"%s",car[288]);
fprintf(file,"%s",car[287]);
fprintf(file,"%s",car[286]);
fprintf(file,"%s",car[285]);
fprintf(file,"%s",car[284]);
fprintf(file,"%s",car[283]);
fprintf(file,"%s",car[282]);
fprintf(file,"%s",car[281]);
fprintf(file,"%s",car[280]);
fprintf(file,"%s",car[279]);
fprintf(file,"%s",car[278]);
fprintf(file,"%s",car[277]);
fprintf(file,"%s",car[276]);
fprintf(file,"%s",car[275]);
fprintf(file,"%s",car[274]);
fprintf(file,"%s",car[273]);
fprintf(file,"%s",car[272]);
fprintf(file,"%s",car[271]);
fprintf(file,"%s",car[270]);
fprintf(file,"%s",car[269]);
fprintf(file,"%s",car[268]);
fprintf(file,"%s",car[267]);
fprintf(file,"%s",car[266]);
fprintf(file,"%s",car[265]);
fprintf(file,"%s",car[264]);
fprintf(file,"%s",car[263]);
fprintf(file,"%s",car[262]);
fprintf(file,"%s",car[261]);
fprintf(file,"%s",car[260]);
fprintf(file,"%s",car[259]);
fprintf(file,"%s",car[258]);
fprintf(file,"%s",car[257]);
fprintf(file,"%s",car[256]);
fprintf(file,"%s",car[255]);
fprintf(file,"%s",car[254]);
fprintf(file,"%s",car[253]);
fprintf(file,"%s",car[252]);
fprintf(file,"%s",car[251]);
fprintf(file,"%s",car[250]);
fprintf(file,"%s",car[249]);
fprintf(file,"%s",car[248]);
fprintf(file,"%s",car[247]);
fprintf(file,"%s",car[246]);
fprintf(file,"%s",car[245]);
fprintf(file,"%s",car[244]);
fprintf(file,"%s",car[243]);
fprintf(file,"%s",car[242]);
fprintf(file,"%s",car[241]);
fprintf(file,"%s",car[240]);
fprintf(file,"%s",car[239]);
fprintf(file,"%s",car[238]);
fprintf(file,"%s",car[237]);
fprintf(file,"%s",car[236]);
fprintf(file,"%s",car[235]);
fprintf(file,"%s",car[234]);
fprintf(file,"%s",car[233]);
fprintf(file,"%s",car[232]);
fprintf(file,"%s",car[231]);
fprintf(file,"%s",car[230]);
fprintf(file,"%s",car[229]);
fprintf(file,"%s",car[228]);
fprintf(file,"%s",car[227]);
fprintf(file,"%s",car[226]);
fprintf(file,"%s",car[225]);
fprintf(file,"%s",car[224]);
fprintf(file,"%s",car[223]);
fprintf(file,"%s",car[222]);
fprintf(file,"%s",car[221]);
fprintf(file,"%s",car[220]);
fprintf(file,"%s",car[219]);
fprintf(file,"%s",car[218]);
fprintf(file,"%s",car[217]);
fprintf(file,"%s",car[216]);
fprintf(file,"%s",car[215]);
fprintf(file,"%s",car[214]);
fprintf(file,"%s",car[213]);
fprintf(file,"%s",car[212]);
fprintf(file,"%s",car[211]);
fprintf(file,"%s",car[210]);
fprintf(file,"%s",car[209]);
fprintf(file,"%s",car[208]);
fprintf(file,"%s",car[207]);
fprintf(file,"%s",car[206]);
fprintf(file,"%s",car[205]);
fprintf(file,"%s",car[204]);
fprintf(file,"%s",car[203]);
fprintf(file,"%s",car[202]);
fprintf(file,"%s",car[201]);
fprintf(file,"%s",car[200]);
fprintf(file,"%s",car[199]);
fprintf(file,"%s",car[198]);
fprintf(file,"%s",car[197]);
fprintf(file,"%s",car[196]);
fprintf(file,"%s",car[195]);
fprintf(file,"%s",car[194]);
fprintf(file,"%s",car[193]);
fprintf(file,"%s",car[192]);
fprintf(file,"%s",car[191]);
fprintf(file,"%s",car[190]);
fprintf(file,"%s",car[189]);
fprintf(file,"%s",car[188]);
fprintf(file,"%s",car[187]);
fprintf(file,"%s",car[186]);
fprintf(file,"%s",car[185]);
fprintf(file,"%s",car[184]);
fprintf(file,"%s",car[183]);
fprintf(file,"%s",car[182]);
fprintf(file,"%s",car[181]);
fclose(file);
ffind_and_substitute("Suite.c");
strcpy(path,new_path);
strcat(path,"Suite.c");
copy_file("Suite.c",path);
   return 0;
}

int generate_h__agent_header_code()
{
char car[5][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("_agent_header.h.tmp",car,5);
file=fopen("_agent_header.h","w");
{
  XMachine *xmachine;
  Variables *variables;
  int i;
  FILE  *file;
  char local_path[100];
char aux[]="_agent_header.h";
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
strcpy(local_path,xmachine->name);
strcat(local_path,aux);
file=fopen(local_path,"w");
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[4]);
strcpy(capitalized,variable->name);
capitalize(capitalized);
fprintf(file,"%s",capitalized);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[0]);

   }
}
fclose(file);
ffind_and_substitute(local_path);
strcpy(path,new_path);
 strcat(path,local_path);
copy_file(local_path,path);

  }
}
fclose(file);
ffind_and_substitute("_agent_header.h");
strcpy(path,new_path);
strcat(path,"_agent_header.h");
copy_file("_agent_header.h",path);
   return 0;
}

int generate_c_LauncherTest_code()
{
char car[49][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("LauncherTest.c.tmp",car,49);
file=fopen("LauncherTest.c","w");
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
fclose(file);
ffind_and_substitute("LauncherTest.c");
strcpy(path,new_path);
strcat(path,"LauncherTest.c");
copy_file("LauncherTest.c",path);
   return 0;
}

int generate__MakefiletestWin32_code()
{
char car[21][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("MakefiletestWin32.tmp",car,21);
file=fopen("MakefiletestWin32","w");
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Function *variable;
  int l;
for(l=0;l<=functions->index;l++)
  {
variable=&functions->list[l];
fprintf(file,"%s",car[7]);
fprintf(file,"%s",variable->name);

  }
}
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[13]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[12]);

  }
}
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fclose(file);
ffind_and_substitute("MakefiletestWin32");
strcpy(path,new_path);
strcat(path,"MakefiletestWin32");
copy_file("MakefiletestWin32",path);
   return 0;
}

int generate__Makefiletest_code()
{
char car[21][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("Makefiletest.tmp",car,21);
file=fopen("Makefiletest","w");
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Function *variable;
  int l;
for(l=0;l<=functions->index;l++)
  {
variable=&functions->list[l];
fprintf(file,"%s",car[7]);
fprintf(file,"%s",variable->name);

  }
}
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[13]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[12]);

  }
}
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fclose(file);
ffind_and_substitute("Makefiletest");
strcpy(path,new_path);
strcat(path,"Makefiletest");
copy_file("Makefiletest",path);
   return 0;
}

int generate_h_Suite_code()
{
char car[91][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("Suite.h.tmp",car,91);
file=fopen("Suite.h","w");
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Suite *suite;
  int l;
for(l=0;l<=suites->index;l++)
  {
suite=&suites->list[l];
fprintf(file,"%s",car[9]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[6]);
{
  UnitaryTest *utest;
  Variables *variables;
  Messages *messages;
  int i;
for(i=0;i<=suite->index;i++)
  {
utest=&suite->list[i];
variables=&utest->variables;
messages=&utest->messages;
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",utest->function_name);
fprintf(file,"%s",car[10]);

  }
}
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
{
  UnitaryTest *utest;
  Variables *variables;
  Messages *messages;
  int i;
for(i=0;i<=suite->index;i++)
  {
utest=&suite->list[i];
variables=&utest->variables;
messages=&utest->messages;
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[21]);

  }
}
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);

  }
}
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
{
  Suite *suite;
  int l;
for(l=0;l<=suites->index;l++)
  {
suite=&suites->list[l];
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",suite->name);
fprintf(file,"%s",car[30]);

  }
}
fprintf(file,"%s",car[90]);
fprintf(file,"%s",car[89]);
fprintf(file,"%s",car[88]);
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",car[74]);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",car[70]);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",car[68]);
fprintf(file,"%s",car[67]);
fprintf(file,"%s",car[66]);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",car[64]);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",car[62]);
fprintf(file,"%s",car[61]);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fclose(file);
ffind_and_substitute("Suite.h");
strcpy(path,new_path);
strcat(path,"Suite.h");
copy_file("Suite.h",path);
   return 0;
}

int generate_c_messages_code()
{
char car[485][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("messages.c.tmp",car,485);
file=fopen("messages.c","w");
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[13]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[10]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[18]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[15]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[14]);

}

   }
}
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[55]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[50]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[49]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[61]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[56]);

}

   }
}
fprintf(file,"%s",car[66]);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",car[64]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[62]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[70]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[68]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[67]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[73]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[71]);

}

   }
}
fprintf(file,"%s",car[94]);
fprintf(file,"%s",car[93]);
fprintf(file,"%s",car[92]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[91]);
fprintf(file,"%s",car[90]);
fprintf(file,"%s",car[89]);
fprintf(file,"%s",car[88]);
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",car[74]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[96]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[95]);
if(variable->dim>0)
{
fprintf(file,"%s",car[99]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[98]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[97]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[103]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[102]);
fprintf(file,"%s",car[101]);
fprintf(file,"%s",car[100]);
fprintf(file,"%s",variable->name);

}
fprintf(file,"%s",car[104]);

   }
}
fprintf(file,"%s",car[134]);
fprintf(file,"%s",car[133]);
fprintf(file,"%s",car[132]);
fprintf(file,"%s",car[131]);
fprintf(file,"%s",car[130]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[129]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[128]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[127]);
fprintf(file,"%s",car[126]);
fprintf(file,"%s",car[125]);
fprintf(file,"%s",car[124]);
fprintf(file,"%s",car[123]);
fprintf(file,"%s",car[122]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[121]);
fprintf(file,"%s",car[120]);
fprintf(file,"%s",car[119]);
fprintf(file,"%s",car[118]);
fprintf(file,"%s",car[117]);
fprintf(file,"%s",car[116]);
fprintf(file,"%s",car[115]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[114]);
fprintf(file,"%s",car[113]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[112]);
fprintf(file,"%s",car[111]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[110]);
fprintf(file,"%s",car[109]);
fprintf(file,"%s",car[108]);
fprintf(file,"%s",car[107]);
fprintf(file,"%s",car[106]);
fprintf(file,"%s",car[105]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[141]);
fprintf(file,"%s",car[140]);
fprintf(file,"%s",car[139]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[138]);
fprintf(file,"%s",car[137]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[136]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[135]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[150]);
fprintf(file,"%s",car[149]);
fprintf(file,"%s",car[148]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[147]);
fprintf(file,"%s",car[146]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[145]);
fprintf(file,"%s",car[144]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[143]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[142]);

}

   }
}
fprintf(file,"%s",car[244]);
fprintf(file,"%s",car[243]);
fprintf(file,"%s",car[242]);
fprintf(file,"%s",car[241]);
fprintf(file,"%s",car[240]);
fprintf(file,"%s",car[239]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[238]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[237]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[236]);
fprintf(file,"%s",car[235]);
fprintf(file,"%s",car[234]);
fprintf(file,"%s",car[233]);
fprintf(file,"%s",car[232]);
fprintf(file,"%s",car[231]);
fprintf(file,"%s",car[230]);
fprintf(file,"%s",car[229]);
fprintf(file,"%s",car[228]);
fprintf(file,"%s",car[227]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[226]);
fprintf(file,"%s",car[225]);
fprintf(file,"%s",car[224]);
fprintf(file,"%s",car[223]);
fprintf(file,"%s",car[222]);
fprintf(file,"%s",car[221]);
fprintf(file,"%s",car[220]);
fprintf(file,"%s",car[219]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[218]);
fprintf(file,"%s",car[217]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[216]);
fprintf(file,"%s",car[215]);
fprintf(file,"%s",car[214]);
fprintf(file,"%s",car[213]);
fprintf(file,"%s",car[212]);
fprintf(file,"%s",car[211]);
fprintf(file,"%s",car[210]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[209]);
fprintf(file,"%s",car[208]);
fprintf(file,"%s",car[207]);
fprintf(file,"%s",car[206]);
fprintf(file,"%s",car[205]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[204]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[203]);
fprintf(file,"%s",car[202]);
fprintf(file,"%s",car[201]);
fprintf(file,"%s",car[200]);
fprintf(file,"%s",car[199]);
fprintf(file,"%s",car[198]);
fprintf(file,"%s",car[197]);
fprintf(file,"%s",car[196]);
fprintf(file,"%s",car[195]);
fprintf(file,"%s",car[194]);
fprintf(file,"%s",car[193]);
fprintf(file,"%s",car[192]);
fprintf(file,"%s",car[191]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[190]);
fprintf(file,"%s",car[189]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[188]);
fprintf(file,"%s",car[187]);
fprintf(file,"%s",car[186]);
fprintf(file,"%s",car[185]);
fprintf(file,"%s",car[184]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[183]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[182]);
fprintf(file,"%s",car[181]);
fprintf(file,"%s",car[180]);
fprintf(file,"%s",car[179]);
fprintf(file,"%s",car[178]);
fprintf(file,"%s",car[177]);
fprintf(file,"%s",car[176]);
fprintf(file,"%s",car[175]);
fprintf(file,"%s",car[174]);
fprintf(file,"%s",car[173]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[172]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[171]);
fprintf(file,"%s",car[170]);
fprintf(file,"%s",car[169]);
fprintf(file,"%s",car[168]);
fprintf(file,"%s",car[167]);
fprintf(file,"%s",car[166]);
fprintf(file,"%s",car[165]);
fprintf(file,"%s",car[164]);
fprintf(file,"%s",car[163]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[162]);
fprintf(file,"%s",car[161]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[160]);
fprintf(file,"%s",car[159]);
fprintf(file,"%s",car[158]);
fprintf(file,"%s",car[157]);
fprintf(file,"%s",car[156]);
fprintf(file,"%s",car[155]);
fprintf(file,"%s",car[154]);
fprintf(file,"%s",car[153]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[152]);
fprintf(file,"%s",car[151]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[245]);
if(variable->dim>0)
{
fprintf(file,"%s",car[251]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[250]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[249]);
fprintf(file,"%s",car[248]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[247]);
fprintf(file,"%s",car[246]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[256]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[255]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[254]);
fprintf(file,"%s",car[253]);
fprintf(file,"%s",car[252]);

}

   }
}
fprintf(file,"%s",car[288]);
fprintf(file,"%s",car[287]);
fprintf(file,"%s",car[286]);
fprintf(file,"%s",car[285]);
fprintf(file,"%s",car[284]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[283]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[282]);
fprintf(file,"%s",car[281]);
fprintf(file,"%s",car[280]);
fprintf(file,"%s",car[279]);
fprintf(file,"%s",car[278]);
fprintf(file,"%s",car[277]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[276]);
fprintf(file,"%s",car[275]);
fprintf(file,"%s",car[274]);
fprintf(file,"%s",car[273]);
fprintf(file,"%s",car[272]);
fprintf(file,"%s",car[271]);
fprintf(file,"%s",car[270]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[269]);
fprintf(file,"%s",car[268]);
fprintf(file,"%s",car[267]);
fprintf(file,"%s",car[266]);
fprintf(file,"%s",car[265]);
fprintf(file,"%s",car[264]);
fprintf(file,"%s",car[263]);
fprintf(file,"%s",car[262]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[261]);
fprintf(file,"%s",car[260]);
fprintf(file,"%s",car[259]);
fprintf(file,"%s",car[258]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[257]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[290]);
fprintf(file,"%s",car[289]);
fprintf(file,"%s",variable->name);

   }
}
fprintf(file,"%s",car[311]);
fprintf(file,"%s",car[310]);
fprintf(file,"%s",car[309]);
fprintf(file,"%s",car[308]);
fprintf(file,"%s",car[307]);
fprintf(file,"%s",car[306]);
fprintf(file,"%s",car[305]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[304]);
fprintf(file,"%s",car[303]);
fprintf(file,"%s",car[302]);
fprintf(file,"%s",car[301]);
fprintf(file,"%s",car[300]);
fprintf(file,"%s",car[299]);
fprintf(file,"%s",car[298]);
fprintf(file,"%s",car[297]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[296]);
fprintf(file,"%s",car[295]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[294]);
fprintf(file,"%s",car[293]);
fprintf(file,"%s",car[292]);
fprintf(file,"%s",car[291]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[316]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[315]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[314]);
fprintf(file,"%s",car[313]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[312]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[320]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[319]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[318]);
fprintf(file,"%s",car[317]);

}
if((variables->index)>j)
{
fprintf(file,"%s",car[321]);

}

   }
}
fprintf(file,"%s",car[388]);
fprintf(file,"%s",car[387]);
fprintf(file,"%s",car[386]);
fprintf(file,"%s",car[385]);
fprintf(file,"%s",car[384]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[383]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[382]);
fprintf(file,"%s",car[381]);
fprintf(file,"%s",car[380]);
fprintf(file,"%s",car[379]);
fprintf(file,"%s",car[378]);
fprintf(file,"%s",car[377]);
fprintf(file,"%s",car[376]);
fprintf(file,"%s",car[375]);
fprintf(file,"%s",car[374]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[373]);
fprintf(file,"%s",car[372]);
fprintf(file,"%s",car[371]);
fprintf(file,"%s",car[370]);
fprintf(file,"%s",car[369]);
fprintf(file,"%s",car[368]);
fprintf(file,"%s",car[367]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[366]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[365]);
fprintf(file,"%s",car[364]);
fprintf(file,"%s",car[363]);
fprintf(file,"%s",car[362]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[361]);
fprintf(file,"%s",car[360]);
fprintf(file,"%s",car[359]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[358]);
fprintf(file,"%s",car[357]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[356]);
fprintf(file,"%s",car[355]);
fprintf(file,"%s",car[354]);
fprintf(file,"%s",car[353]);
fprintf(file,"%s",car[352]);
fprintf(file,"%s",car[351]);
fprintf(file,"%s",car[350]);
fprintf(file,"%s",car[349]);
fprintf(file,"%s",car[348]);
fprintf(file,"%s",car[347]);
fprintf(file,"%s",car[346]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[345]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[344]);
fprintf(file,"%s",car[343]);
fprintf(file,"%s",car[342]);
fprintf(file,"%s",car[341]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[340]);
fprintf(file,"%s",car[339]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[338]);
fprintf(file,"%s",car[337]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[336]);
fprintf(file,"%s",car[335]);
fprintf(file,"%s",car[334]);
fprintf(file,"%s",car[333]);
fprintf(file,"%s",car[332]);
fprintf(file,"%s",car[331]);
fprintf(file,"%s",car[330]);
fprintf(file,"%s",car[329]);
fprintf(file,"%s",car[328]);
fprintf(file,"%s",car[327]);
fprintf(file,"%s",car[326]);
fprintf(file,"%s",car[325]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[324]);
fprintf(file,"%s",car[323]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[322]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[391]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[390]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[389]);
if((variables->index)>j)
{
fprintf(file,"%s",car[392]);

}

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[394]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[393]);
if((variables->index)>j)
{
fprintf(file,"%s",car[395]);

}

}

   }
}
fprintf(file,"%s",car[416]);
fprintf(file,"%s",car[415]);
fprintf(file,"%s",car[414]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[413]);
fprintf(file,"%s",car[412]);
fprintf(file,"%s",car[411]);
fprintf(file,"%s",car[410]);
fprintf(file,"%s",car[409]);
fprintf(file,"%s",car[408]);
fprintf(file,"%s",car[407]);
fprintf(file,"%s",car[406]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[405]);
fprintf(file,"%s",car[404]);
fprintf(file,"%s",car[403]);
fprintf(file,"%s",car[402]);
fprintf(file,"%s",car[401]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[400]);
fprintf(file,"%s",car[399]);
fprintf(file,"%s",car[398]);
fprintf(file,"%s",car[397]);
fprintf(file,"%s",car[396]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[421]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[420]);
fprintf(file,"%s",car[419]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[418]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[417]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[426]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[425]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[424]);
fprintf(file,"%s",car[423]);
fprintf(file,"%s",car[422]);
fprintf(file,"%s",variable->name);

}
fprintf(file,"%s",car[427]);

   }
}
fprintf(file,"%s",car[434]);
fprintf(file,"%s",car[433]);
fprintf(file,"%s",car[432]);
fprintf(file,"%s",car[431]);
fprintf(file,"%s",car[430]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[429]);
fprintf(file,"%s",car[428]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[437]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[436]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[435]);
if((variables->index)>j)
{
fprintf(file,"%s",car[438]);

}

}
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[440]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[439]);
if((variables->index)>j)
{
fprintf(file,"%s",car[441]);

}

}

   }
}
fprintf(file,"%s",car[449]);
fprintf(file,"%s",car[448]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[447]);
fprintf(file,"%s",car[446]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[445]);
fprintf(file,"%s",car[444]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[443]);
fprintf(file,"%s",car[442]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",variable->name);
if((variables->index)>j)
{
fprintf(file,"%s",car[450]);

}

   }
}
fprintf(file,"%s",car[452]);
fprintf(file,"%s",car[451]);

  }}
fprintf(file,"%s",car[455]);
fprintf(file,"%s",car[454]);
fprintf(file,"%s",car[453]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[467]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[466]);
fprintf(file,"%s",car[465]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[464]);
fprintf(file,"%s",car[463]);
fprintf(file,"%s",car[462]);
fprintf(file,"%s",car[461]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[460]);
fprintf(file,"%s",car[459]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[458]);
fprintf(file,"%s",car[457]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[456]);

  }}
fprintf(file,"%s",car[471]);
fprintf(file,"%s",car[470]);
fprintf(file,"%s",car[469]);
fprintf(file,"%s",car[468]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[475]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[474]);
fprintf(file,"%s",car[473]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[472]);

  }}
fprintf(file,"%s",car[479]);
fprintf(file,"%s",car[478]);
fprintf(file,"%s",car[477]);
fprintf(file,"%s",car[476]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[483]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[482]);
fprintf(file,"%s",car[481]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[480]);

  }}
fprintf(file,"%s",car[484]);
fclose(file);
ffind_and_substitute("messages.c");
strcpy(path,new_path);
strcat(path,"messages.c");
copy_file("messages.c",path);
   return 0;
}

int generate_c_xmachine_code()
{
char car[422][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("xmachine.c.tmp",car,422);
file=fopen("xmachine.c","w");
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[12]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[10]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[9]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[15]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[13]);

}

   }
}
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(!((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0)))
{
if(variable->dim==0)
{
fprintf(file,"%s",car[43]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[40]);

}

}

   }
}
fprintf(file,"%s",car[69]);
fprintf(file,"%s",car[68]);
fprintf(file,"%s",car[67]);
fprintf(file,"%s",car[66]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[64]);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",car[62]);
fprintf(file,"%s",car[61]);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[90]);
fprintf(file,"%s",car[89]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[88]);
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",car[74]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",car[70]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[112]);
fprintf(file,"%s",car[111]);
fprintf(file,"%s",car[110]);
fprintf(file,"%s",car[109]);
fprintf(file,"%s",car[108]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[107]);
fprintf(file,"%s",car[106]);
fprintf(file,"%s",car[105]);
fprintf(file,"%s",car[104]);
fprintf(file,"%s",car[103]);
fprintf(file,"%s",car[102]);
fprintf(file,"%s",car[101]);
fprintf(file,"%s",car[100]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[99]);
fprintf(file,"%s",car[98]);
fprintf(file,"%s",car[97]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[96]);
fprintf(file,"%s",car[95]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[94]);
fprintf(file,"%s",car[93]);
fprintf(file,"%s",car[92]);
fprintf(file,"%s",car[91]);

}

   }
}
fprintf(file,"%s",car[125]);
fprintf(file,"%s",car[124]);
fprintf(file,"%s",car[123]);
fprintf(file,"%s",car[122]);
fprintf(file,"%s",car[121]);
fprintf(file,"%s",car[120]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[119]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[118]);
fprintf(file,"%s",car[117]);
fprintf(file,"%s",car[116]);
fprintf(file,"%s",car[115]);
fprintf(file,"%s",car[114]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[113]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[140]);
fprintf(file,"%s",car[139]);
fprintf(file,"%s",car[138]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[137]);
fprintf(file,"%s",car[136]);
fprintf(file,"%s",car[135]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[134]);
fprintf(file,"%s",car[133]);
fprintf(file,"%s",car[132]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[131]);
fprintf(file,"%s",car[130]);
fprintf(file,"%s",car[129]);
fprintf(file,"%s",car[128]);
fprintf(file,"%s",car[127]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[126]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[154]);
fprintf(file,"%s",car[153]);
fprintf(file,"%s",car[152]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[151]);
fprintf(file,"%s",car[150]);
fprintf(file,"%s",car[149]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[148]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[147]);
fprintf(file,"%s",car[146]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[145]);
fprintf(file,"%s",car[144]);
fprintf(file,"%s",car[143]);
fprintf(file,"%s",car[142]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[141]);

}

   }
}
fprintf(file,"%s",car[157]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[156]);
fprintf(file,"%s",car[155]);

  }
}
fprintf(file,"%s",car[184]);
fprintf(file,"%s",car[183]);
fprintf(file,"%s",car[182]);
fprintf(file,"%s",car[181]);
fprintf(file,"%s",car[180]);
fprintf(file,"%s",car[179]);
fprintf(file,"%s",car[178]);
fprintf(file,"%s",car[177]);
fprintf(file,"%s",car[176]);
fprintf(file,"%s",car[175]);
fprintf(file,"%s",car[174]);
fprintf(file,"%s",car[173]);
fprintf(file,"%s",car[172]);
fprintf(file,"%s",car[171]);
fprintf(file,"%s",car[170]);
fprintf(file,"%s",car[169]);
fprintf(file,"%s",car[168]);
fprintf(file,"%s",car[167]);
fprintf(file,"%s",car[166]);
fprintf(file,"%s",car[165]);
fprintf(file,"%s",car[164]);
fprintf(file,"%s",car[163]);
fprintf(file,"%s",car[162]);
fprintf(file,"%s",car[161]);
fprintf(file,"%s",car[160]);
fprintf(file,"%s",car[159]);
fprintf(file,"%s",car[158]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[202]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[201]);
fprintf(file,"%s",car[200]);
fprintf(file,"%s",car[199]);
fprintf(file,"%s",car[198]);
fprintf(file,"%s",car[197]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[196]);
fprintf(file,"%s",car[195]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[194]);
fprintf(file,"%s",car[193]);
fprintf(file,"%s",car[192]);
fprintf(file,"%s",car[191]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[190]);
fprintf(file,"%s",car[189]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[188]);
fprintf(file,"%s",car[187]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[186]);
fprintf(file,"%s",car[185]);

  }
}
fprintf(file,"%s",car[213]);
fprintf(file,"%s",car[212]);
fprintf(file,"%s",car[211]);
fprintf(file,"%s",car[210]);
fprintf(file,"%s",car[209]);
fprintf(file,"%s",car[208]);
fprintf(file,"%s",car[207]);
fprintf(file,"%s",car[206]);
fprintf(file,"%s",car[205]);
fprintf(file,"%s",car[204]);
fprintf(file,"%s",car[203]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[218]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[217]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[216]);
fprintf(file,"%s",car[215]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[214]);

  }
}
fprintf(file,"%s",car[289]);
fprintf(file,"%s",car[288]);
fprintf(file,"%s",car[287]);
fprintf(file,"%s",car[286]);
fprintf(file,"%s",car[285]);
fprintf(file,"%s",car[284]);
fprintf(file,"%s",car[283]);
fprintf(file,"%s",car[282]);
fprintf(file,"%s",car[281]);
fprintf(file,"%s",car[280]);
fprintf(file,"%s",car[279]);
fprintf(file,"%s",car[278]);
fprintf(file,"%s",car[277]);
fprintf(file,"%s",car[276]);
fprintf(file,"%s",car[275]);
fprintf(file,"%s",car[274]);
fprintf(file,"%s",car[273]);
fprintf(file,"%s",car[272]);
fprintf(file,"%s",car[271]);
fprintf(file,"%s",car[270]);
fprintf(file,"%s",car[269]);
fprintf(file,"%s",car[268]);
fprintf(file,"%s",car[267]);
fprintf(file,"%s",car[266]);
fprintf(file,"%s",car[265]);
fprintf(file,"%s",car[264]);
fprintf(file,"%s",car[263]);
fprintf(file,"%s",car[262]);
fprintf(file,"%s",car[261]);
fprintf(file,"%s",car[260]);
fprintf(file,"%s",car[259]);
fprintf(file,"%s",car[258]);
fprintf(file,"%s",car[257]);
fprintf(file,"%s",car[256]);
fprintf(file,"%s",car[255]);
fprintf(file,"%s",car[254]);
fprintf(file,"%s",car[253]);
fprintf(file,"%s",car[252]);
fprintf(file,"%s",car[251]);
fprintf(file,"%s",car[250]);
fprintf(file,"%s",car[249]);
fprintf(file,"%s",car[248]);
fprintf(file,"%s",car[247]);
fprintf(file,"%s",car[246]);
fprintf(file,"%s",car[245]);
fprintf(file,"%s",car[244]);
fprintf(file,"%s",car[243]);
fprintf(file,"%s",car[242]);
fprintf(file,"%s",car[241]);
fprintf(file,"%s",car[240]);
fprintf(file,"%s",car[239]);
fprintf(file,"%s",car[238]);
fprintf(file,"%s",car[237]);
fprintf(file,"%s",car[236]);
fprintf(file,"%s",car[235]);
fprintf(file,"%s",car[234]);
fprintf(file,"%s",car[233]);
fprintf(file,"%s",car[232]);
fprintf(file,"%s",car[231]);
fprintf(file,"%s",car[230]);
fprintf(file,"%s",car[229]);
fprintf(file,"%s",car[228]);
fprintf(file,"%s",car[227]);
fprintf(file,"%s",car[226]);
fprintf(file,"%s",car[225]);
fprintf(file,"%s",car[224]);
fprintf(file,"%s",car[223]);
fprintf(file,"%s",car[222]);
fprintf(file,"%s",car[221]);
fprintf(file,"%s",car[220]);
fprintf(file,"%s",car[219]);
{
   Variable *variable;
   int j;
   for(j=0;j<=constants->index;j++)
   {
variable=&constants->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[310]);
fprintf(file,"%s",car[309]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[308]);
fprintf(file,"%s",car[307]);
fprintf(file,"%s",car[306]);
fprintf(file,"%s",car[305]);
fprintf(file,"%s",car[304]);
fprintf(file,"%s",car[303]);
fprintf(file,"%s",car[302]);
fprintf(file,"%s",car[301]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[300]);
fprintf(file,"%s",car[299]);
fprintf(file,"%s",car[298]);
fprintf(file,"%s",car[297]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[296]);
fprintf(file,"%s",car[295]);
fprintf(file,"%s",car[294]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[293]);
fprintf(file,"%s",car[292]);
fprintf(file,"%s",car[291]);
fprintf(file,"%s",car[290]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[332]);
fprintf(file,"%s",car[331]);
fprintf(file,"%s",car[330]);
fprintf(file,"%s",car[329]);
fprintf(file,"%s",car[328]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[327]);
fprintf(file,"%s",car[326]);
fprintf(file,"%s",car[325]);
fprintf(file,"%s",car[324]);
fprintf(file,"%s",car[323]);
fprintf(file,"%s",car[322]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[321]);
fprintf(file,"%s",car[320]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[319]);
fprintf(file,"%s",car[318]);
fprintf(file,"%s",car[317]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[316]);
fprintf(file,"%s",car[315]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[314]);
fprintf(file,"%s",car[313]);
fprintf(file,"%s",car[312]);
fprintf(file,"%s",car[311]);

}

   }
}
fprintf(file,"%s",car[338]);
fprintf(file,"%s",car[337]);
fprintf(file,"%s",car[336]);
fprintf(file,"%s",car[335]);
fprintf(file,"%s",car[334]);
fprintf(file,"%s",car[333]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[340]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[339]);

  }
}
fprintf(file,"%s",car[341]);
{
   Variable *variable;
   Variable *xvariable;
   int j;
   Variables *variables;
 variables=&model->variables;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
      xvariable=variable;
if((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0))
{
if(variable->dim==0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[343]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[342]);

}
if(variable->dim>0)
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[345]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[344]);

}
fprintf(file,"%s",car[346]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
if(find_variable(variables,xvariable->name)>=0) 
{
fprintf(file,"%s",car[356]);
fprintf(file,"%s",car[355]);
fprintf(file,"%s",car[354]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[353]);
fprintf(file,"%s",car[352]);
fprintf(file,"%s",car[351]);
fprintf(file,"%s",car[350]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[349]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[348]);
fprintf(file,"%s",car[347]);

}

  }
}
if(variable->dim==0)
{
fprintf(file,"%s",car[360]);
fprintf(file,"%s",car[359]);
fprintf(file,"%s",car[358]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[357]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[363]);
fprintf(file,"%s",car[362]);
fprintf(file,"%s",car[361]);

}
fprintf(file,"%s",car[364]);
if(variable->dim==0)
{
fprintf(file,"%s",car[370]);
fprintf(file,"%s",car[369]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[368]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[367]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[366]);
fprintf(file,"%s",car[365]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
if(find_variable(variables,xvariable->name)>=0) 
{
fprintf(file,"%s",car[378]);
fprintf(file,"%s",car[377]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[376]);
fprintf(file,"%s",car[375]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[374]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[373]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[372]);
fprintf(file,"%s",car[371]);

}

  }
}
fprintf(file,"%s",car[379]);

}

}
if(!((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0)))
{
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[382]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[381]);
fprintf(file,"%s",car[380]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
if(find_variable(variables,xvariable->name)>=0) 
{
if(variable->dim>0)
{
fprintf(file,"%s",car[390]);
fprintf(file,"%s",car[389]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[388]);
fprintf(file,"%s",car[387]);
fprintf(file,"%s",car[386]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[385]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[384]);
fprintf(file,"%s",car[383]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[399]);
fprintf(file,"%s",car[398]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[397]);
fprintf(file,"%s",car[396]);
fprintf(file,"%s",car[395]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[394]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[393]);
fprintf(file,"%s",car[392]);
fprintf(file,"%s",car[391]);

}

}

  }
}
fprintf(file,"%s",car[402]);
fprintf(file,"%s",car[401]);
fprintf(file,"%s",car[400]);

}

   }
}
fprintf(file,"%s",car[408]);
fprintf(file,"%s",car[407]);
fprintf(file,"%s",car[406]);
fprintf(file,"%s",car[405]);
fprintf(file,"%s",car[404]);
fprintf(file,"%s",car[403]);
{
  XMachine *xmachine;
  Variables *variables;
  int i;
for(i=0;i<=xmachines->index;i++)
  {
xmachine=&xmachines->list[i];
variables=&xmachine->variables;
fprintf(file,"%s",car[420]);
fprintf(file,"%s",car[419]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[418]);
fprintf(file,"%s",car[417]);
fprintf(file,"%s",car[416]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[415]);
fprintf(file,"%s",car[414]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[413]);
fprintf(file,"%s",car[412]);
fprintf(file,"%s",car[411]);
fprintf(file,"%s",xmachine->name);
fprintf(file,"%s",car[410]);
fprintf(file,"%s",car[409]);

  }
}
fprintf(file,"%s",car[421]);
fclose(file);
ffind_and_substitute("xmachine.c");
strcpy(path,new_path);
strcat(path,"xmachine.c");
copy_file("xmachine.c",path);
   return 0;
}

int generate_c_unittest_code()
{
char car[80][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("unittest.c.tmp",car,80);
file=fopen("unittest.c","w");
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  Suite *suite;
  int l;
for(l=0;l<=suites->index;l++)
  {
suite=&suites->list[l];
{
  UnitaryTest *utest;
  Variables *variables;
  Messages *messages;
  int i;
for(i=0;i<=suite->index;i++)
  {
utest=&suite->list[i];
variables=&utest->variables;
messages=&utest->messages;
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[2]);
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[25]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[22]);

  }}
fprintf(file,"%s",car[47]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",utest->function_name);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",utest->name);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[48]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[67]);
fprintf(file,"%s",car[66]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",car[64]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[62]);
fprintf(file,"%s",car[61]);
fprintf(file,"%s",utest->xagent_name);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[59]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[58]);

}

   }
}
{
  Message *message;
  Variables *variables;
  int w;
for(w=0;w<=messages->index;w++)
  {
   message=&messages->list[w];
   variables=&message->variables;
fprintf(file,"%s",car[74]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[70]);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",message->name);
fprintf(file,"%s",car[68]);

  }}
fprintf(file,"%s",car[79]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);

  }
}

  }
}
fclose(file);
ffind_and_substitute("unittest.c");
strcpy(path,new_path);
strcat(path,"unittest.c");
copy_file("unittest.c",path);
   return 0;
}

int generate_c_datatype_code()
{
char car[748][MAXCHAR];
 char path[MAXPATH];
 read_intermediate_data("datatype.c.tmp",car,748);
file=fopen("datatype.c","w");
fprintf(file,"%s",car[37]);
fprintf(file,"%s",car[36]);
fprintf(file,"%s",car[35]);
fprintf(file,"%s",car[34]);
fprintf(file,"%s",car[33]);
fprintf(file,"%s",car[32]);
fprintf(file,"%s",car[31]);
fprintf(file,"%s",car[30]);
fprintf(file,"%s",car[29]);
fprintf(file,"%s",car[28]);
fprintf(file,"%s",car[27]);
fprintf(file,"%s",car[26]);
fprintf(file,"%s",car[25]);
fprintf(file,"%s",car[24]);
fprintf(file,"%s",car[23]);
fprintf(file,"%s",car[22]);
fprintf(file,"%s",car[21]);
fprintf(file,"%s",car[20]);
fprintf(file,"%s",car[19]);
fprintf(file,"%s",car[18]);
fprintf(file,"%s",car[17]);
fprintf(file,"%s",car[16]);
fprintf(file,"%s",car[15]);
fprintf(file,"%s",car[14]);
fprintf(file,"%s",car[13]);
fprintf(file,"%s",car[12]);
fprintf(file,"%s",car[11]);
fprintf(file,"%s",car[10]);
fprintf(file,"%s",car[9]);
fprintf(file,"%s",car[8]);
fprintf(file,"%s",car[7]);
fprintf(file,"%s",car[6]);
fprintf(file,"%s",car[5]);
fprintf(file,"%s",car[4]);
fprintf(file,"%s",car[3]);
fprintf(file,"%s",car[2]);
fprintf(file,"%s",car[1]);
fprintf(file,"%s",car[0]);
{
  int i;
for(i=0;i<4;i++)
  {
 fprintf(file,"%s",car[326]);
fprintf(file,"%s",car[325]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[324]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[323]);
fprintf(file,"%s",car[322]);
fprintf(file,"%s",car[321]);
fprintf(file,"%s",car[320]);
fprintf(file,"%s",car[319]);
fprintf(file,"%s",car[318]);
fprintf(file,"%s",car[317]);
fprintf(file,"%s",car[316]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[315]);
fprintf(file,"%s",car[314]);
fprintf(file,"%s",car[313]);
fprintf(file,"%s",car[312]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[311]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[310]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[309]);
fprintf(file,"%s",car[308]);
fprintf(file,"%s",car[307]);
fprintf(file,"%s",car[306]);
fprintf(file,"%s",car[305]);
fprintf(file,"%s",car[304]);
fprintf(file,"%s",car[303]);
fprintf(file,"%s",car[302]);
fprintf(file,"%s",car[301]);
fprintf(file,"%s",car[300]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[299]);
fprintf(file,"%s",car[298]);
fprintf(file,"%s",car[297]);
fprintf(file,"%s",car[296]);
fprintf(file,"%s",car[295]);
fprintf(file,"%s",car[294]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[293]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[292]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[291]);
fprintf(file,"%s",car[290]);
fprintf(file,"%s",car[289]);
fprintf(file,"%s",car[288]);
fprintf(file,"%s",car[287]);
fprintf(file,"%s",car[286]);
fprintf(file,"%s",car[285]);
fprintf(file,"%s",car[284]);
fprintf(file,"%s",car[283]);
fprintf(file,"%s",car[282]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[281]);
fprintf(file,"%s",car[280]);
fprintf(file,"%s",car[279]);
fprintf(file,"%s",car[278]);
fprintf(file,"%s",car[277]);
fprintf(file,"%s",car[276]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[275]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[274]);
fprintf(file,"%s",car[273]);
fprintf(file,"%s",car[272]);
fprintf(file,"%s",car[271]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[270]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[269]);
fprintf(file,"%s",car[268]);
fprintf(file,"%s",car[267]);
fprintf(file,"%s",car[266]);
fprintf(file,"%s",car[265]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[264]);
fprintf(file,"%s",car[263]);
fprintf(file,"%s",car[262]);
fprintf(file,"%s",car[261]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[260]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[259]);
fprintf(file,"%s",car[258]);
fprintf(file,"%s",car[257]);
fprintf(file,"%s",car[256]);
fprintf(file,"%s",car[255]);
fprintf(file,"%s",car[254]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[253]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[252]);
fprintf(file,"%s",car[251]);
fprintf(file,"%s",car[250]);
fprintf(file,"%s",car[249]);
fprintf(file,"%s",car[248]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[247]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[246]);
fprintf(file,"%s",car[245]);
fprintf(file,"%s",car[244]);
fprintf(file,"%s",car[243]);
fprintf(file,"%s",car[242]);
fprintf(file,"%s",car[241]);
fprintf(file,"%s",car[240]);
fprintf(file,"%s",car[239]);
fprintf(file,"%s",car[238]);
fprintf(file,"%s",car[237]);
fprintf(file,"%s",car[236]);
fprintf(file,"%s",car[235]);
fprintf(file,"%s",car[234]);
fprintf(file,"%s",car[233]);
fprintf(file,"%s",car[232]);
fprintf(file,"%s",car[231]);
fprintf(file,"%s",car[230]);
fprintf(file,"%s",car[229]);
fprintf(file,"%s",specifier[i]);
fprintf(file,"%s",car[228]);
fprintf(file,"%s",car[227]);
fprintf(file,"%s",car[226]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[225]);
fprintf(file,"%s",specifier[i]);
fprintf(file,"%s",car[224]);
fprintf(file,"%s",car[223]);
fprintf(file,"%s",car[222]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[221]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[220]);
fprintf(file,"%s",car[219]);
fprintf(file,"%s",car[218]);
fprintf(file,"%s",car[217]);
fprintf(file,"%s",car[216]);
fprintf(file,"%s",car[215]);
fprintf(file,"%s",car[214]);
fprintf(file,"%s",car[213]);
fprintf(file,"%s",car[212]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[211]);
fprintf(file,"%s",car[210]);
fprintf(file,"%s",car[209]);
fprintf(file,"%s",car[208]);
fprintf(file,"%s",car[207]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[206]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[205]);
fprintf(file,"%s",car[204]);
fprintf(file,"%s",car[203]);
fprintf(file,"%s",car[202]);
fprintf(file,"%s",car[201]);
fprintf(file,"%s",car[200]);
fprintf(file,"%s",car[199]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[198]);
fprintf(file,"%s",car[197]);
fprintf(file,"%s",car[196]);
fprintf(file,"%s",car[195]);
fprintf(file,"%s",car[194]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[193]);
fprintf(file,"%s",car[192]);
fprintf(file,"%s",car[191]);
fprintf(file,"%s",car[190]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[189]);
fprintf(file,"%s",car[188]);
fprintf(file,"%s",car[187]);
fprintf(file,"%s",car[186]);
fprintf(file,"%s",car[185]);
fprintf(file,"%s",car[184]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[183]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[182]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[181]);
fprintf(file,"%s",car[180]);
fprintf(file,"%s",car[179]);
fprintf(file,"%s",car[178]);
fprintf(file,"%s",car[177]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[176]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[175]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[174]);
fprintf(file,"%s",car[173]);
fprintf(file,"%s",car[172]);
fprintf(file,"%s",car[171]);
fprintf(file,"%s",car[170]);
fprintf(file,"%s",car[169]);
fprintf(file,"%s",car[168]);
fprintf(file,"%s",car[167]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[166]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[165]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[164]);
fprintf(file,"%s",car[163]);
fprintf(file,"%s",car[162]);
fprintf(file,"%s",car[161]);
fprintf(file,"%s",car[160]);
fprintf(file,"%s",car[159]);
fprintf(file,"%s",car[158]);
fprintf(file,"%s",car[157]);
fprintf(file,"%s",car[156]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[155]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[154]);
fprintf(file,"%s",car[153]);
fprintf(file,"%s",car[152]);
fprintf(file,"%s",car[151]);
fprintf(file,"%s",car[150]);
fprintf(file,"%s",car[149]);
fprintf(file,"%s",car[148]);
fprintf(file,"%s",specifier[i]);
fprintf(file,"%s",car[147]);
fprintf(file,"%s",car[146]);
fprintf(file,"%s",car[145]);
fprintf(file,"%s",car[144]);
fprintf(file,"%s",car[143]);
fprintf(file,"%s",car[142]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[141]);
fprintf(file,"%s",car[140]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[139]);
fprintf(file,"%s",car[138]);
fprintf(file,"%s",car[137]);
fprintf(file,"%s",car[136]);
fprintf(file,"%s",car[135]);
fprintf(file,"%s",car[134]);
fprintf(file,"%s",car[133]);
fprintf(file,"%s",car[132]);
fprintf(file,"%s",car[131]);
fprintf(file,"%s",car[130]);
fprintf(file,"%s",car[129]);
fprintf(file,"%s",car[128]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[127]);
fprintf(file,"%s",car[126]);
fprintf(file,"%s",car[125]);
fprintf(file,"%s",car[124]);
fprintf(file,"%s",car[123]);
fprintf(file,"%s",car[122]);
fprintf(file,"%s",car[121]);
fprintf(file,"%s",car[120]);
fprintf(file,"%s",car[119]);
fprintf(file,"%s",car[118]);
fprintf(file,"%s",car[117]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[116]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[115]);
fprintf(file,"%s",car[114]);
fprintf(file,"%s",car[113]);
fprintf(file,"%s",car[112]);
fprintf(file,"%s",car[111]);
fprintf(file,"%s",car[110]);
fprintf(file,"%s",car[109]);
fprintf(file,"%s",car[108]);
fprintf(file,"%s",car[107]);
fprintf(file,"%s",car[106]);
fprintf(file,"%s",car[105]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[104]);
fprintf(file,"%s",car[103]);
fprintf(file,"%s",car[102]);
fprintf(file,"%s",car[101]);
fprintf(file,"%s",car[100]);
fprintf(file,"%s",car[99]);
fprintf(file,"%s",car[98]);
fprintf(file,"%s",car[97]);
fprintf(file,"%s",car[96]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[95]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[94]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[93]);
fprintf(file,"%s",car[92]);
fprintf(file,"%s",car[91]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[90]);
fprintf(file,"%s",car[89]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[88]);
fprintf(file,"%s",car[87]);
fprintf(file,"%s",car[86]);
fprintf(file,"%s",car[85]);
fprintf(file,"%s",car[84]);
fprintf(file,"%s",car[83]);
fprintf(file,"%s",car[82]);
fprintf(file,"%s",car[81]);
fprintf(file,"%s",car[80]);
fprintf(file,"%s",car[79]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[78]);
fprintf(file,"%s",car[77]);
fprintf(file,"%s",car[76]);
fprintf(file,"%s",car[75]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[74]);
fprintf(file,"%s",car[73]);
fprintf(file,"%s",car[72]);
fprintf(file,"%s",car[71]);
fprintf(file,"%s",car[70]);
fprintf(file,"%s",car[69]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[68]);
fprintf(file,"%s",car[67]);
fprintf(file,"%s",car[66]);
fprintf(file,"%s",car[65]);
fprintf(file,"%s",car[64]);
fprintf(file,"%s",car[63]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[62]);
fprintf(file,"%s",primtype[i]);
fprintf(file,"%s",car[61]);
fprintf(file,"%s",car[60]);
fprintf(file,"%s",car[59]);
fprintf(file,"%s",car[58]);
fprintf(file,"%s",car[57]);
fprintf(file,"%s",car[56]);
fprintf(file,"%s",car[55]);
fprintf(file,"%s",car[54]);
fprintf(file,"%s",car[53]);
fprintf(file,"%s",car[52]);
fprintf(file,"%s",car[51]);
fprintf(file,"%s",car[50]);
fprintf(file,"%s",car[49]);
fprintf(file,"%s",car[48]);
fprintf(file,"%s",car[47]);
fprintf(file,"%s",car[46]);
fprintf(file,"%s",car[45]);
fprintf(file,"%s",car[44]);
fprintf(file,"%s",car[43]);
fprintf(file,"%s",car[42]);
fprintf(file,"%s",car[41]);
fprintf(file,"%s",car[40]);
fprintf(file,"%s",car[39]);
fprintf(file,"%s",car[38]);
}
}
{
   Datatype *datatype;
   Variables *variables;
   int k;
   for(k=0;k<=datatypes->index;k++)
   {
datatype=&datatypes->list[k];
variables=&datatype->variables;
fprintf(file,"%s",car[332]);
fprintf(file,"%s",car[331]);
fprintf(file,"%s",car[330]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[329]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[328]);
fprintf(file,"%s",car[327]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[336]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[335]);
fprintf(file,"%s",car[334]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[333]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[341]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[340]);
fprintf(file,"%s",car[339]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[338]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[337]);

}

   }
}
fprintf(file,"%s",car[348]);
fprintf(file,"%s",car[347]);
fprintf(file,"%s",car[346]);
fprintf(file,"%s",car[345]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[344]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[343]);
fprintf(file,"%s",car[342]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(!((strcmp(variable->type,"int")==0)||(strcmp(variable->type,"double")==0)||(strcmp(variable->type,"float")==0)||(strcmp(variable->type,"char")==0)))
{
fprintf(file,"%s",car[352]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[351]);
fprintf(file,"%s",car[350]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[349]);

}

   }
}
fprintf(file,"%s",car[364]);
fprintf(file,"%s",car[363]);
fprintf(file,"%s",car[362]);
fprintf(file,"%s",car[361]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[360]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[359]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[358]);
fprintf(file,"%s",car[357]);
fprintf(file,"%s",car[356]);
fprintf(file,"%s",car[355]);
fprintf(file,"%s",car[354]);
fprintf(file,"%s",car[353]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim==0)
{
fprintf(file,"%s",car[371]);
fprintf(file,"%s",car[370]);
fprintf(file,"%s",car[369]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[368]);
fprintf(file,"%s",car[367]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[366]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[365]);

}
if(variable->dim>0)
{
fprintf(file,"%s",car[380]);
fprintf(file,"%s",car[379]);
fprintf(file,"%s",car[378]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[377]);
fprintf(file,"%s",car[376]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[375]);
fprintf(file,"%s",car[374]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[373]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[372]);

}

   }
}
fprintf(file,"%s",car[390]);
fprintf(file,"%s",car[389]);
fprintf(file,"%s",car[388]);
fprintf(file,"%s",car[387]);
fprintf(file,"%s",car[386]);
fprintf(file,"%s",car[385]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[384]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[383]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[382]);
fprintf(file,"%s",car[381]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[397]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[396]);
fprintf(file,"%s",car[395]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[394]);
fprintf(file,"%s",car[393]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[392]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[391]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[403]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[402]);
fprintf(file,"%s",car[401]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[400]);
fprintf(file,"%s",car[399]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[398]);

}

   }
}
fprintf(file,"%s",car[407]);
fprintf(file,"%s",car[406]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[405]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[404]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[411]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[410]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[409]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[408]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[414]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[413]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[412]);

}

   }
}
fprintf(file,"%s",car[438]);
fprintf(file,"%s",car[437]);
fprintf(file,"%s",car[436]);
fprintf(file,"%s",car[435]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[434]);
fprintf(file,"%s",car[433]);
fprintf(file,"%s",car[432]);
fprintf(file,"%s",car[431]);
fprintf(file,"%s",car[430]);
fprintf(file,"%s",car[429]);
fprintf(file,"%s",car[428]);
fprintf(file,"%s",car[427]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[426]);
fprintf(file,"%s",car[425]);
fprintf(file,"%s",car[424]);
fprintf(file,"%s",car[423]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[422]);
fprintf(file,"%s",car[421]);
fprintf(file,"%s",car[420]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[419]);
fprintf(file,"%s",car[418]);
fprintf(file,"%s",car[417]);
fprintf(file,"%s",car[416]);
fprintf(file,"%s",car[415]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[443]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[442]);
fprintf(file,"%s",car[441]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[440]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[439]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[454]);
fprintf(file,"%s",car[453]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[452]);
fprintf(file,"%s",car[451]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[450]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[449]);
fprintf(file,"%s",car[448]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[447]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[446]);
fprintf(file,"%s",car[445]);
fprintf(file,"%s",car[444]);
fprintf(file,"%s",variable->name);

}
fprintf(file,"%s",car[455]);

   }
}
fprintf(file,"%s",car[474]);
fprintf(file,"%s",car[473]);
fprintf(file,"%s",car[472]);
fprintf(file,"%s",car[471]);
fprintf(file,"%s",car[470]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[469]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[468]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[467]);
fprintf(file,"%s",car[466]);
fprintf(file,"%s",car[465]);
fprintf(file,"%s",car[464]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[463]);
fprintf(file,"%s",car[462]);
fprintf(file,"%s",car[461]);
fprintf(file,"%s",car[460]);
fprintf(file,"%s",car[459]);
fprintf(file,"%s",car[458]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[457]);
fprintf(file,"%s",car[456]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[475]);
fprintf(file,"%s",variable->name);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[477]);
fprintf(file,"%s",car[476]);
fprintf(file,"%s",variable->name);

}

   }
}
fprintf(file,"%s",car[585]);
fprintf(file,"%s",car[584]);
fprintf(file,"%s",car[583]);
fprintf(file,"%s",car[582]);
fprintf(file,"%s",car[581]);
fprintf(file,"%s",car[580]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[579]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[578]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[577]);
fprintf(file,"%s",car[576]);
fprintf(file,"%s",car[575]);
fprintf(file,"%s",car[574]);
fprintf(file,"%s",car[573]);
fprintf(file,"%s",car[572]);
fprintf(file,"%s",car[571]);
fprintf(file,"%s",car[570]);
fprintf(file,"%s",car[569]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[568]);
fprintf(file,"%s",car[567]);
fprintf(file,"%s",car[566]);
fprintf(file,"%s",car[565]);
fprintf(file,"%s",car[564]);
fprintf(file,"%s",car[563]);
fprintf(file,"%s",car[562]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[561]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[560]);
fprintf(file,"%s",car[559]);
fprintf(file,"%s",car[558]);
fprintf(file,"%s",car[557]);
fprintf(file,"%s",car[556]);
fprintf(file,"%s",car[555]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[554]);
fprintf(file,"%s",car[553]);
fprintf(file,"%s",car[552]);
fprintf(file,"%s",car[551]);
fprintf(file,"%s",car[550]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[549]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[548]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[547]);
fprintf(file,"%s",car[546]);
fprintf(file,"%s",car[545]);
fprintf(file,"%s",car[544]);
fprintf(file,"%s",car[543]);
fprintf(file,"%s",car[542]);
fprintf(file,"%s",car[541]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[540]);
fprintf(file,"%s",car[539]);
fprintf(file,"%s",car[538]);
fprintf(file,"%s",car[537]);
fprintf(file,"%s",car[536]);
fprintf(file,"%s",car[535]);
fprintf(file,"%s",car[534]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[533]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[532]);
fprintf(file,"%s",car[531]);
fprintf(file,"%s",car[530]);
fprintf(file,"%s",car[529]);
fprintf(file,"%s",car[528]);
fprintf(file,"%s",car[527]);
fprintf(file,"%s",car[526]);
fprintf(file,"%s",car[525]);
fprintf(file,"%s",car[524]);
fprintf(file,"%s",car[523]);
fprintf(file,"%s",car[522]);
fprintf(file,"%s",car[521]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[520]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[519]);
fprintf(file,"%s",car[518]);
fprintf(file,"%s",car[517]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[516]);
fprintf(file,"%s",car[515]);
fprintf(file,"%s",car[514]);
fprintf(file,"%s",car[513]);
fprintf(file,"%s",car[512]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[511]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[510]);
fprintf(file,"%s",car[509]);
fprintf(file,"%s",car[508]);
fprintf(file,"%s",car[507]);
fprintf(file,"%s",car[506]);
fprintf(file,"%s",car[505]);
fprintf(file,"%s",car[504]);
fprintf(file,"%s",car[503]);
fprintf(file,"%s",car[502]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[501]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[500]);
fprintf(file,"%s",car[499]);
fprintf(file,"%s",car[498]);
fprintf(file,"%s",car[497]);
fprintf(file,"%s",car[496]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[495]);
fprintf(file,"%s",car[494]);
fprintf(file,"%s",car[493]);
fprintf(file,"%s",car[492]);
fprintf(file,"%s",car[491]);
fprintf(file,"%s",car[490]);
fprintf(file,"%s",car[489]);
fprintf(file,"%s",car[488]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[487]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[486]);
fprintf(file,"%s",car[485]);
fprintf(file,"%s",car[484]);
fprintf(file,"%s",car[483]);
fprintf(file,"%s",car[482]);
fprintf(file,"%s",car[481]);
fprintf(file,"%s",car[480]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[479]);
fprintf(file,"%s",car[478]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[586]);
if(variable->dim>0)
{
fprintf(file,"%s",car[592]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[591]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[590]);
fprintf(file,"%s",car[589]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[588]);
fprintf(file,"%s",car[587]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[597]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[596]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[595]);
fprintf(file,"%s",car[594]);
fprintf(file,"%s",car[593]);

}

   }
}
fprintf(file,"%s",car[628]);
fprintf(file,"%s",car[627]);
fprintf(file,"%s",car[626]);
fprintf(file,"%s",car[625]);
fprintf(file,"%s",car[624]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[623]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[622]);
fprintf(file,"%s",car[621]);
fprintf(file,"%s",car[620]);
fprintf(file,"%s",car[619]);
fprintf(file,"%s",car[618]);
fprintf(file,"%s",car[617]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[616]);
fprintf(file,"%s",car[615]);
fprintf(file,"%s",car[614]);
fprintf(file,"%s",car[613]);
fprintf(file,"%s",car[612]);
fprintf(file,"%s",car[611]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[610]);
fprintf(file,"%s",car[609]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[608]);
fprintf(file,"%s",car[607]);
fprintf(file,"%s",car[606]);
fprintf(file,"%s",car[605]);
fprintf(file,"%s",car[604]);
fprintf(file,"%s",car[603]);
fprintf(file,"%s",car[602]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[601]);
fprintf(file,"%s",car[600]);
fprintf(file,"%s",car[599]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[598]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
fprintf(file,"%s",car[630]);
fprintf(file,"%s",car[629]);
fprintf(file,"%s",variable->name);

   }
}
fprintf(file,"%s",car[661]);
fprintf(file,"%s",car[660]);
fprintf(file,"%s",car[659]);
fprintf(file,"%s",car[658]);
fprintf(file,"%s",car[657]);
fprintf(file,"%s",car[656]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[655]);
fprintf(file,"%s",car[654]);
fprintf(file,"%s",car[653]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[652]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[651]);
fprintf(file,"%s",car[650]);
fprintf(file,"%s",car[649]);
fprintf(file,"%s",car[648]);
fprintf(file,"%s",car[647]);
fprintf(file,"%s",car[646]);
fprintf(file,"%s",car[645]);
fprintf(file,"%s",car[644]);
fprintf(file,"%s",car[643]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[642]);
fprintf(file,"%s",car[641]);
fprintf(file,"%s",car[640]);
fprintf(file,"%s",car[639]);
fprintf(file,"%s",car[638]);
fprintf(file,"%s",car[637]);
fprintf(file,"%s",car[636]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[635]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[634]);
fprintf(file,"%s",car[633]);
fprintf(file,"%s",car[632]);
fprintf(file,"%s",car[631]);
{
   Variable *variable;
   int j;
   for(j=0;j<=variables->index;j++)
   {
variable=&variables->list[j];
if(variable->dim>0)
{
fprintf(file,"%s",car[666]);
if(variable->dim>0)
{char aux[30];
 strcpy(aux,variable->type);
strcat(aux,"_static");
fprintf(file,"%s",aux);
}
 else fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[665]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[664]);
fprintf(file,"%s",car[663]);
if(variable->dim>0)
 fprintf(file,"%d",variable->dim);
fprintf(file,"%s",car[662]);

}
if(variable->dim==0)
{
fprintf(file,"%s",car[670]);
fprintf(file,"%s",variable->type);
fprintf(file,"%s",car[669]);
fprintf(file,"%s",variable->name);
fprintf(file,"%s",car[668]);
fprintf(file,"%s",car[667]);

}
if((variables->index)>j)
{
fprintf(file,"%s",car[671]);

}

   }
}
fprintf(file,"%s",car[747]);
fprintf(file,"%s",car[746]);
fprintf(file,"%s",car[745]);
fprintf(file,"%s",car[744]);
fprintf(file,"%s",car[743]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[742]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[741]);
fprintf(file,"%s",car[740]);
fprintf(file,"%s",car[739]);
fprintf(file,"%s",car[738]);
fprintf(file,"%s",car[737]);
fprintf(file,"%s",car[736]);
fprintf(file,"%s",car[735]);
fprintf(file,"%s",car[734]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[733]);
fprintf(file,"%s",car[732]);
fprintf(file,"%s",car[731]);
fprintf(file,"%s",car[730]);
fprintf(file,"%s",car[729]);
fprintf(file,"%s",car[728]);
fprintf(file,"%s",car[727]);
fprintf(file,"%s",car[726]);
fprintf(file,"%s",car[725]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[724]);
fprintf(file,"%s",car[723]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[722]);
fprintf(file,"%s",car[721]);
fprintf(file,"%s",car[720]);
fprintf(file,"%s",car[719]);
fprintf(file,"%s",car[718]);
fprintf(file,"%s",car[717]);
fprintf(file,"%s",car[716]);
fprintf(file,"%s",car[715]);
fprintf(file,"%s",car[714]);
fprintf(file,"%s",car[713]);
fprintf(file,"%s",car[712]);
fprintf(file,"%s",car[711]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[710]);
fprintf(file,"%s",car[709]);
fprintf(file,"%s",car[708]);
fprintf(file,"%s",car[707]);
fprintf(file,"%s",car[706]);
fprintf(file,"%s",car[705]);
fprintf(file,"%s",car[704]);
fprintf(file,"%s",car[703]);
fprintf(file,"%s",car[702]);
fprintf(file,"%s",car[701]);
fprintf(file,"%s",car[700]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[699]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[698]);
fprintf(file,"%s",car[697]);
fprintf(file,"%s",car[696]);
fprintf(file,"%s",car[695]);
fprintf(file,"%s",car[694]);
fprintf(file,"%s",car[693]);
fprintf(file,"%s",car[692]);
fprintf(file,"%s",car[691]);
fprintf(file,"%s",car[690]);
fprintf(file,"%s",car[689]);
fprintf(file,"%s",car[688]);
fprintf(file,"%s",car[687]);
fprintf(file,"%s",car[686]);
fprintf(file,"%s",car[685]);
fprintf(file,"%s",car[684]);
fprintf(file,"%s",car[683]);
fprintf(file,"%s",car[682]);
fprintf(file,"%s",car[681]);
fprintf(file,"%s",car[680]);
fprintf(file,"%s",datatype->name);
fprintf(file,"%s",car[679]);
fprintf(file,"%s",car[678]);
fprintf(file,"%s",car[677]);
fprintf(file,"%s",car[676]);
fprintf(file,"%s",car[675]);
fprintf(file,"%s",car[674]);
fprintf(file,"%s",car[673]);
fprintf(file,"%s",car[672]);

   }
}
fclose(file);
ffind_and_substitute("datatype.c");
strcpy(path,new_path);
strcat(path,"datatype.c");
copy_file("datatype.c",path);
   return 0;
}
int main(int argc, char * argv[])
 { 
   model=(Model *)malloc(sizeof(Model));
   initialize_model(model);
   suites=(Suites *)malloc(sizeof(Suites));
   initialize_suites(suites);
   strcpy(temp_path, argv[1]);
   extract_directory(temp_path,new_path);
   printf("opening project file from %s\n",new_path);
   main_read_model(argc,argv,model,suites);
  
   //add_suite(suites,&suite);
   xmachines=&model->xmachines;
   datatypes=&model->datatypes;
   messages=&model->messages;
   constants=&model->constants;
   functions=&model->functions;

   generate_c_main_code();
   generate_h_header_code();
   generate_c_Suite_code();
   generate_h__agent_header_code();
   generate_c_LauncherTest_code();
   generate__MakefiletestWin32_code();
   generate__Makefiletest_code();
   generate_h_Suite_code();
   generate_c_messages_code();
   generate_c_xmachine_code();
   generate_c_unittest_code();
   generate_c_datatype_code();
return 0;
}