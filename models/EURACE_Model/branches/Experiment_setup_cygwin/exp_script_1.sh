#!/bin/sh

######### CREATION OF EXPERIMENT FOLDERS ###############################################
# Script to create the folder hierarchy
# - Create folders ./duration_x/intensity_y/frequency_z
# - Create folders for multiple batch runs: its_"batch"
# - Copy output.xml and run.sh from top-level to these run folders
########################################################################################
BASE=$PWD

F1="duration_40 duration_120 duration_240 duration_560"
F2="intensity_1 intensity_5 intensity_10 intensity_20"
F3="frequency_0 frequency_20 frequency_40 frequency_60"

#Construct the RUNS list:
TOTAL_RUNS=4;
RUNS=''
i=0
for ((j=0; j<TOTAL_RUNS; j++)); do
    RUNS=$RUNS' '$j
done

echo '  Creating folder hierarchy...'

rm -f STATUS
for folder1 in $F1; do
    mkdir -p $folder1
    echo '    Created folder:' $folder1
    cd $folder1
    for folder2 in $F2; do
        mkdir -p $folder2
        echo '      Created folder:' $folder1/$folder2
        cd $folder2
        for folder3 in $F3; do
            mkdir -p $folder3
            echo '        Created folder:' $folder1/$folder2/$folder3
            #echo $PWD
            cd $folder3
            for run in $RUNS; do
                mkdir -p 'its_'$run
                echo '          Created folder:' $folder1/$folder2/$folder3/'its_'$run
                echo $folder1'/'$folder2'/'$folder3'/run_'$run':CREATED'>> $BASE/STATUS
                cp $BASE/output.xml $BASE/run.sh ./'its_'$run
            done
            cd ..
        done
        cd ..
    done
    cd ..
done

echo '  Finished creation of folder hierarchy.'
