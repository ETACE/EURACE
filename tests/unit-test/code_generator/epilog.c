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

