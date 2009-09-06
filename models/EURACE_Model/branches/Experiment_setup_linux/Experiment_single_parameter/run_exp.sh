#!/bin/bash

################################################################################################################
# This script is for exportting up and running the experiment:
# Steps:
# - 1 : experiment exporttings
# - 2 : creation of experiment folder hierarchy
# - 3 : creation of the specific exporttings xml file
# - 4 : running the initial transient phase; stores a snapshot of the last iteration in transient.xml
# - 5 : running the experiment
################################################################################################################

echo 'Starting top-level experiment script...'

######### STEP 1: EXPERIMENT exportTINGS ##################################################################
env -u NR_NODES
env -u ITS_PRE
env -u ITS
env -u TOTAL_RUNS
env -u RUNS
env -u F1
env -u F1_values
env -u MAIN_P
env -u MAIN_S
env -u BASE

#Set the base folder
export BASE=$PWD

#Iterations
export NR_NODES=4
export ITS_PRE=540
export ITS=1000

#Runs
export TOTAL_RUNS=1
RUNS=''
for ((j=0; j<TOTAL_RUNS; j++)); do
    export RUNS=$RUNS' '$j
done
echo $RUNS

#Parameters
export F1="tax_0.01 tax_0.05 tax_0.10"
export F1_values="0.20 0.30 0.50"

#Executable
#export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_p'
#export MAIN_S='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_s'
export MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/GREQAM/Integrated_Model_1.0/main_p'
#export MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Integrated_Model_1.0_energy_shock/main'


######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY #####################################################
#bash ./exp_script_1.sh

######### STEP 3: CREATION OF THE SPECIFIC exportTINGS XML FILE ##################################################
#bash ./exp_script_2.sh

######### STEP 4: RUNNING THE INITIAL PHASE ###################################################################
#bash ./run_first_stage.sh

######### STEP 4b: RUNNING BENCHMARK SCENARIO ###################################################################
bash ./run_benchmark.sh

######### STEP 5: RUNNING THE EXPERIMENT ######################################################################
#bash ./run_experiment.sh

echo 'Finished top-level experiment script.'
