#!/bin/bash

######### RUNNING THE EXPERIMENT ##################################################################
# Script to run the second stage of the experiment:
# - Level 1 : duration  of energy shock, measured as a time period
# - Level 2 : intensity of energy shock, measured as a percentage price increase
# - Level 3 : frequency of energy shock, measured in days
###################################################################################################
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
	    	#bash $BASE/join.sh ./ $NR_NODES 	#Concatenating the node files
	    	#rm node*.xml 			#Removing the node files
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

