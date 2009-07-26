#!/bin/bash

######### CREATION OF EXPERIMENT FOLDERS ###############################################
# Script to create the folder hierarchy
# - Create folders ./duration_x/intensity_y/frequency_z
# - Create folders for multiple batch runs: its_"batch"
# - Copy output.xml and run.sh from top-level to these run folders
########################################################################################
BASE=$PWD

F1="tax_0.01 tax_0.05 tax_0.10"


#Construct the RUNS list:
TOTAL_RUNS=4
RUNS=''
for ((j=0; j<TOTAL_RUNS; j++)); do
    RUNS=$RUNS' '$j
done
echo $RUNS

echo '  Creating folder hierarchy...'
echo $F1

rm -f STATUS
mkdir -p 'its'
cd ./its

for folder1 in $F1; do
    mkdir -p $folder1
    echo '    Created folder:' $folder1
    cd $folder1
            echo '        Created folder:' $folder1
            for run in $RUNS; do
                mkdir -p 'its_'$run
                echo '          Created folder:' $folder1/'its_'$run
                echo $folder1'/''run_'$run':CREATED'>> $BASE/STATUS
                cp $BASE/output.xml $BASE/run.sh ./'its_'$run
    done
    cd ..
done
cd ..

echo '  Finished creation of folder hierarchy.'
