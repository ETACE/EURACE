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
export ITS=5000

#Set number of nodes to use (only valid for parallel)
export NR_NODES=1

#Set number of job processes to use (nr of job lists: job_list_$n.sh)
export NUM_PROCS=2

#Set number of batch runs
export TOTAL_RUNS=10
RUNS=''
for ((j=1; j<=TOTAL_RUNS; j++)); do
    export RUNS=$RUNS' '$j
done
echo 'Batch runs:[' $RUNS ']'

#Parameters
#1. Tax experiment
export EXPERIMENT_NAME="const_income_tax_rate"
export F1_values=$(seq 0.04 0.02 0.14)
#export F1_values=$(seq 0.05 0.05 0.05)

#2. Unemployment benefit experiment:
#export EXPERIMENT_NAME="gov_policy_unemployment_benefit_pct"
#export F1_values=$(seq 0.60 0.10 1.00)

#3. Technological progress experiment:
#export EXPERIMENT_NAME="productivity_progress"
#export F1_values=$(seq 0.00 0.0125 0.05)

#4. Debt installment period
#export EXPERIMENT_NAME="const_installment_periods"
#export F1_values=$(seq 6 3 24)
#export F1_values=$(seq 6 1 6)

#5. Debt rescaling factor
#export EXPERIMENT_NAME="debt_rescaling_factor"
#export F1_values=$(seq 0.0 0.2 0.8)

#6. Dividend earnings ratio
#export EXPERIMENT_NAME="const_dividend_earnings_ratio"
#export F1_values=$(seq 0.1 0.1 0.7)

#7. Bank leverage ratio: value-at-risk <= alfa * equity
#export EXPERIMENT_NAME="alfa"
#export F1_values=$(seq 4 0.5 10)

#8. ECB base interest rate
#export EXPERIMENT_NAME="ecb_interest_rate"
#export F1_values=$(seq 0.01 0.01 0.05)

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
export MAIN_S='/home/svdhoog/EURACE/SVN/geole/branches/UNIBI_Branched_Model_2010/main_sd'
#export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_sd'
#export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_pd'

#For production version
export MAIN_S='/home/svdhoog/EURACE/SVN/geole/branches/UNIBI_Branched_Model_2010/main_sp'
#export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_sp'
#export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_pp'

#Location of the SQL database creation script (not actually used currently):
#export SQL_DB_DIR='/home/svdhoog/EURACE/SVN/xagents/sim_validation'

#Location of the model XML (used to generate the SQL)
#export MODEL_XML_DIR='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0'


##Ubuntu Laptop settings:

#For debug version
#export MAIN_S='/media/DataStorageLinux/SVN/geole/branches/UNIBI_Branched_Model_2010/main_sd'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_sd'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_pd'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/tags/exported/main_sd'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/branches/UNIBI_Branched_Model/main_sd'

#For production version
#export MAIN_S='/media/DataStorageLinux/SVN/geole/branches/UNIBI_Branched_Model_2010/main_sp'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_sp'
#export MAIN_S='/media/DataStorageLinux/SVN/eurace/tags/Integrated_Model_1.0beta/main_sp'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0/main_pp'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/tags/exported/main_sp'
#export MAIN_P='/media/DataStorageLinux/SVN/eurace/branches/UNIBI_Branched_Model/main_sp'

#Location of the SQL database creation script gendb.py (used after XML output to generate the SQL):
##Note: better to place gendb.py in the root simulation folder
#export SQL_DB_DIR='/media/DataStorageLinux/SVN/xagents/sim_validation'

#Location of the model XML (used to generate the SQL DB)
#export MODEL_XML_DIR='/media/DataStorageLinux/SVN/eurace/trunk/Integrated_Model_1.0'
#export MODEL_XML_DIR='/media/DataStorageLinux/SVN/geole/branches/UNIBI_Branched_Model_2010'
export MODEL_XML_FILE='eurace_model.xml'

######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY 
bash ./exp_script_1_setup.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE 
bash ./exp_script_2_specific.sh

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
