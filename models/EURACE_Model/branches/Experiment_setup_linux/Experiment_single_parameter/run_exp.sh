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

echo 'Starting top-level experiment script...'

######### STEP 1: EXPERIMENT SETTINGS ##################################################################


######### STEP 2: CREATION OF EXPERIMENT FOLDER HIERARCHY #####################################################
#bash ./exp_script_1.sh

######### STEP 3: CREATION OF THE SPECIFIC SETTINGS XML FILE ##################################################
#bash ./exp_script_2.sh

######### STEP 4: RUNNING THE INITIAL PHASE ###################################################################
#bash ./run_first_stage.sh

######### STEP 4b: RUNNING BENCHMARK SCENARIO ###################################################################
bash ./run_benchmark.sh

######### STEP 5: RUNNING THE EXPERIMENT ######################################################################
#bash ./run_experiment.sh

echo 'Finished top-level experiment script.'
