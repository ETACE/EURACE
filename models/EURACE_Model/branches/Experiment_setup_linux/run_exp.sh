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

BASE=$PWD
F1="duration_40 duration_120 duration_240 duration_560"
F2="intensity_1 intensity_5 intensity_10 intensity_20"
F3="frequency_0 frequency_20 frequency_40 frequency_60"

echo 'Starting top-level experiment script...'

######### STEP 1: EXPERIMENT SETTINGS #########################################################################

#Construct the RUNS list:
TOTAL_RUNS=4
RUNS=''
for ((j=0; j<TOTAL_RUNS; j++)); do
    RUNS=$RUNS' '$j
done

#while [ $j -lt $TOTAL_RUNS ]; do
#   RUNS=$RUNS' '$j
#   let j="j + 1"
#done

echo '  Number of batch runs:' $TOTAL_RUNS
echo $RUNS
######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY #####################################################
bash ./exp_script_1.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE ##################################################
bash ./exp_script_2.sh

######### STEP 4: RUNNING THE INITIAL PHASE ###################################################################
bash ./run_first_stage.sh

######### STEP 5: RUNNING THE EXPERIMENT ######################################################################
bash ./run_experiment.sh

echo 'Finished top-level experiment script.'
