#!/bin/bash

######### CREATION OF EXPERIMENT FOLDERS ###############################################
# Script to create the folder hierarchy
# - Create folders ./duration_x/intensity_y/frequency_z
# - Create folders for multiple batch runs: its_"batch"
# - Copy output.xml and run.sh from top-level to these run folders
########################################################################################

echo '  Creating folder hierarchy...'
echo 'In exp_script_1.sh these values are used:'
echo 'Tax: [' $F1 ']'

rm -f STATUS
mkdir -p 'its'
cd ./its

for folder1 in $F1; do
    mkdir -p $folder1
    echo '    Created folder:' $folder1
    cd $folder1
            for run in $RUNS; do
                mkdir -p 'run_'$run
                echo '          Created folder:' $folder1/'run_'$run
                echo $folder1/run_$run:CREATED>> $BASE/STATUS
                cp $BASE/output.xml $BASE/run.sh ./'run_'$run
    done
    cd ..
done
cd ..

echo '  Finished creation of folder hierarchy.'
echo '  Returned to:'$PWD
