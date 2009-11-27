#!/bin/bash

################################################################################################################
# This script is for setting up and running the experiment:
# Steps:
# - 1 : experiment settings
# - 2 : creation of experiment folder hierarchy
# - 3 : creation of the specific settings xml file
# - 4 : running the initial transient phase; stores a snapshot of the last iteration in transient.xml
# - 5 : running the experiment
################################################################################################################

echo 'Starting top-level experiment script...'

######### STEP 1: EXPERIMENT SETTINGS ##################################################################

#Set the base folder
export BASE=$PWD

#Iterations
export ITS_PRE=1000
export ITS=6000

#Set number of nodes to use
export NR_NODES=1

#Set number of job processes to use
export NUM_PROCS=5


#Set number of batch runs
export TOTAL_RUNS=5
RUNS=''
for ((j=1; j<=TOTAL_RUNS; j++)); do
    export RUNS=$RUNS' '$j
done
echo 'Batch runs:[' $RUNS ']'

#Parameters
#export F1="tax_0.02 tax_0.04 tax_0.06 tax_0.08 tax_0.10"
#export F1_values="0.02 0.04 0.06 0.08 0.10"

#Tax experiment
#export F1="tax_0.10 tax_0.15 tax_0.20 tax_0.25"
#export F1_values="0.10 0.15 0.20 0.25"
export F1="tax_0.08"
export F1_values="0.08"
#export F1="tax_0.05 tax_0.10"
#export F1_values="0.05 0.10"

#Unemployment benefit experiment:
export F1="ub_0.60 ub_0.70 ub_0.80 ub_0.90 ub_1.00 ub_1.10 ub_1.20"
export F1_values="0.60 0.70 0.80 0.90 1.00 1.10 1.20"
#export F1="ub_0.50"
#export F1_values="0.50"


#export F1="bench"
#export F1_values=""

#export F1="sim1 sim2 sim3 sim4 sim5 sim6 sim7"
#export F1_values="0.10 0.10 0.10 0.10 0.10 0.10 0.10"

#Executables

##AIX settings:

#For debug version
#export MAIN_S='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_sd'
#export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_pd'

#For production version
#export MAIN_S='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_sp'
#export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_pp'
#echo 'MAIN_S:'$MAIN_S
#echo 'MAIN_P:'$MAIN_P

#Location of the SQL database creation script (not actually used currently, since gendb.py is now in utils):
#export SQL_DB_DIR='/media/DOCS/Docs/EURACE/X-models/SVN_linux/xagents/sim_validation'

#Location of the model XML (used to generate the SQL)
#export MODEL_XML_DIR='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0'

##UNIBI settings:

#For debug version
#export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_sd'
#export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_pd'

#For production version
#export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_sp'
#export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_pp'

#Location of the SQL database creation script (not actually used currently):
#export SQL_DB_DIR='/home/svdhoog/EURACE/SVN/xagents/sim_validation'

#Location of the model XML (used to generate the SQL)
#export MODEL_XML_DIR='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0'


##Ubuntu Laptop settings:

#For debug version
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_sd'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_pd'

#For production version
export MAIN_S='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_sp'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/tags/Integrated_Model_1.0beta/main_sp'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_pp'

#Location of the SQL database creation script (used after XML output to generate the SQL):
#export SQL_DB_DIR='/media/DataStorageLinux/SVN/xagents/sim_validation'

#Location of the model XML (used to validate the rules after generating the SQL)
export MODEL_XML_DIR='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0'

######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY 
bash ./exp_script_1.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE 
#bash ./exp_script_2_tax.sh
bash ./exp_script_2_unemployment.sh

######### STEP 4: RUNNING THE INITIAL PHASE 
#bash ./run_first_stage.sh

######### STEP 4b: RUNNING BENCHMARK SCENARIO 
#bash ./run_benchmark.sh

######### STEP 5: RUNNING THE EXPERIMENT 
#bash ./run_experiment.sh

######### STEP 6: CREATING  JOB SCRIPTS 
bash ./create_job_list.sh

######### STEP 7: LAUNCHING  JOB SCRIPTS 
bash ./launch_job_list.sh

######### STEP 8: CLEANING OUT THE FOLDERS AFTER VISGUI HAS CREATED DBs 
#bash ./clean_up.sh

echo 'Finished top-level experiment script.'
