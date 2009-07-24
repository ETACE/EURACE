#!/bin/bash

######### RUNNING THE EXPERIMENT ##################################################################
# Script to run the second stage of the experiment:
# - Level 1 : duration  of energy shock, measured as a time period
# - Level 2 : intensity of energy shock, measured as a percentage price increase
# - Level 3 : frequency of energy shock, measured in days
###################################################################################################
BASE=$PWD
JOIN='/home/sander/cloning/scripts/join'
NR_NODES=4

#F1="duration_40 duration_120 duration_240 duration_560"
#F2="intensity_0.01 intensity_0.05 intensity_0.10 intensity_0.20"
#F3="frequency_0 frequency_20 frequency_40 frequency_60"

F1="duration_40 duration_240"
F2="intensity_0.01 intensity_0.05 intensity_0.10"
F3="frequency_0 frequency_20 frequency_60"

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

echo '  Starting second stage of experiment: running all cases...'

rm -f STATUS
cd ./its
for folder1 in $F1; do
    for folder2 in $F2; do
        for folder3 in $F3; do
        cd $folder1/$folder2/$folder3
        for run in $RUNS; do
            cd 'its_'$run
       	    bash run.sh				#Running single run
	    bash $JOIN/join.sh ./ $NR_NODES 	#Concatenating the node files
	    rm node*.xml 			#Removing the node files
            echo '              '$folder1'/'$folder2'/'$folder3'/its_'$run --DONE
            echo $folder1/$folder2/$folder3/'its_'$run':OK'>> $BASE/STATUS 
            cd ..
        done
        cd $BASE
        done
    done
done
cd ..
echo '  Finished second stage of experiment: all cases are done.'

