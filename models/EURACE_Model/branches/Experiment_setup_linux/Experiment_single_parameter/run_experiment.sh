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

F1="tax_0.01 tax_0.05 tax_0.10"

#Construct the RUNS list:
TOTAL_RUNS=4
RUNS=''
for ((j=0; j<TOTAL_RUNS; j++)); do
    RUNS=$RUNS' '$j
done

echo '  Starting second stage of experiment: running all cases...'

rm -f STATUS
cd ./its
for folder1 in $F1; do
		cd $folder1
        for run in $RUNS; do
            cd 'its_'$run
       	    bash run.sh				#Running single run
	    	bash $JOIN/join.sh ./ $NR_NODES 	#Concatenating the node files
	    	rm node*.xml 			#Removing the node files
            echo '              '$folder1'/its_'$run --DONE
            echo $folder1/'its_'$run':OK'>> $BASE/STATUS  
            cd ..
        done
        cd $BASE
done
cd ..
echo '  Finished second stage of experiment: all cases are done.'

