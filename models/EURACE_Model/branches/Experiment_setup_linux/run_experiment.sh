#!/bin/bash

######### RUNNING THE EXPERIMENT ##################################################################
# Script to run the second stage of the experiment:
# - Level 1 : duration  of energy shock, measured as a time period
# - Level 2 : intensity of energy shock, measured as a percentage price increase
# - Level 3 : frequency of energy shock, measured in days
###################################################################################################
BASE=$PWD
F1="duration_40 duration_120 duration_240 duration_560"
F2="intensity_1 intensity_5 intensity_10 intensity_20"
F3="frequency_0 frequency_20 frequency_40 frequency_60"

#Construct the RUNS list:
TOTAL_RUNS=4
RUNS=''
#for ((j=0; j<TOTAL_RUNS; j++)); do
#    RUNS=$RUNS' '$j
#done
while [ $j -lt $TOTAL_RUNS ]; do
   RUNS=$RUNS' '$j
   let j="j + 1"
done

echo '  Starting second stage of experiment: running all cases...'

rm -f STATUS
for folder1 in $F1; do
    for folder2 in $F2; do
        for folder3 in $F3; do
        cd $folder1/$folder2/$folder3
        for run in $RUNS; do
            cd 'its_'$run
            bash run.sh
            echo '              '$folder1'/'$folder2'/'$folder3'/its_'$run --DONE
            echo $folder1/$folder2/$folder3/'its_'$run':OK'>> $BASE/STATUS 
            cd ..
        done
        cd $BASE
        done
    done
done
echo '  Finished second stage of experiment: all cases are done.'
