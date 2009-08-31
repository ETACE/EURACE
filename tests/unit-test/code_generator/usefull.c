

void extract_name_ext(char *complete_name, char *name, char *extension)
  {
    int i,j,k,found;
    i=0;
    k=0;j=0;
    found=0;
    while(complete_name[i]!='\0')
      {
        
        if(!found) { name[k]=complete_name[i]; k++;}
                   else {extension[j]==complete_name[i]; j++;}
        i++;
        if(complete_name[i]=='.') {found=1;i++}
      }
   name[k]='\0';
   extension[j]='\0';
 }
