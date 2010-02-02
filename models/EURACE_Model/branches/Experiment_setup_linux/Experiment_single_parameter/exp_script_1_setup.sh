#!/bin/bash

######### CREATION OF EXPERIMENT FOLDERS ###############################################
# Script to create the folder hierarchy
# - Create folders ./duration_x/intensity_y/frequency_z
# - Create folders for multiple batch runs: its_"batch"
# - Copy output.xml and run.sh from top-level to these run folders
########################################################################################

echo '  Creating folder hierarchy...'
echo 'In exp_script_1_setup.sh these values are used:'
echo '[' $F1_values ']'

rm -f STATUS
mkdir -p 'its'
cd ./its

mkdir -p $EXPERIMENT_NAME
cd ./$EXPERIMENT_NAME

for folder1 in $F1_values; do
    mkdir -p $folder1
    echo '    Created folder:' $folder1
    cd $folder1
            for run in $RUNS; do
                mkdir -p 'run_'$run
                echo '          Created folder:' $folder1/'run_'$run
                echo $folder1/run_$run:CREATED>> $BASE/STATUS
                cp $BASE/output.xml $BASE/run.sh ./'run_'$run
		#cp $BASE/its/0_transient.xml ./'run_'$run/0.xml
    done
    cd ..
done
cd ..

echo '  Finished creation of folder hierarchy.'
echo '  Returned to:'$PWD
