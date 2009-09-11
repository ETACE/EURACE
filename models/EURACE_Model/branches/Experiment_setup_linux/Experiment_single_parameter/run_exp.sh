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
#env -u NR_NODES
#env -u ITS_PRE
#env -u ITS
#env -u TOTAL_RUNS
#env -u RUNS
#env -u F1
#env -u F1_values
#env -u MAIN_P
#env -u MAIN_S
#env -u BASE

#Set the base folder
export BASE=$PWD

#Iterations
export ITS_PRE=540
export ITS=1000

#Set number of nodes to use
export NR_NODES=4

#Set number of job processes to use
export NUM_PROCS=4


#Set number of batch runs
export TOTAL_RUNS=4
RUNS=''
for ((j=0; j<TOTAL_RUNS; j++)); do
    export RUNS=$RUNS' '$j
done
echo 'Batch runs:[' $RUNS ']'

#Parameters
export F1="tax_0.01 tax_0.05 tax_0.10"
export F1_values="0.01 0.05 0.10"

#Executables

##AIX settings:
#export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_p'
#export MAIN_S='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_s'
#export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/GREQAM/Integrated_Model_1.0/main_p'
#export MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Integrated_Model_1.0_energy_shock/main'

##UNIBI settings:
export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/branches/GREQAM/Integrated_Model_1.0/main_s'
export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/branches/GREQAM/Integrated_Model_1.0/main_p'
#export MAIN_S='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_s'
#export MAIN_P='/home/svdhoog/EURACE/SVN/eurace/trunk/Integrated_Model_1.0/main_p'


######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY 
bash ./exp_script_1.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE 
bash ./exp_script_2.sh

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


echo 'Finished top-level experiment script.'
