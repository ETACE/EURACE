#!/bin/bash

######### CREATION OF EXPERIMENT FOLDERS ###############################################
# Script to create the folder hierarchy
# - Create folders ./duration_x/intensity_y/frequency_z
# - Create folders for multiple batch runs: its_"batch"
# - Copy output.xml and run.sh from top-level to these run folders
########################################################################################
BASE=$PWD

F0="png"
#F1="duration_40 duration_120 duration_240 duration_560"
#F2="intensity_0.01 intensity_0.05 intensity_0.10 intensity_0.20"
#F3="frequency_0 frequency_20 frequency_40 frequency_60"

F1="duration_40 duration_240"
F2="intensity_0.01 intensity_0.05 intensity_0.10"
F3="frequency_0 frequency_20 frequency_60"

#F1="duration_40"
#F1="duration_560"
#F2="intensity_0.20"
#F3="frequency_0"

echo '  Creating folder hierarchy in ./plots...'

rm -f STATUS

for folder0 in $F0; do
    mkdir -p $folder0
    echo '    Created folder:' $folder
    cd $folder0
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

		done
		cd ..
	    done
	    cd ..
	done
    cd ..
done

echo '  Finished creation of folder hierarchy.'

echo '  Starting copying plots into folder hierarchy.'

for folder0 in $F0; do
for folder1 in $F1; do
    for folder2 in $F2; do
	echo '      Entering folder:' $folder0/$folder1/$folder2
        for folder3 in $F3; do
			echo '      Entering folder:' $folder0/$folder1/$folder2/$folder3
			cp ../$folder0/$folder1/$folder2/$folder3/*.png ./$folder0/$folder1/$folder2/$folder3
        done
    done
done
done

echo '  Finished copying plots into folder hierarchy.'

