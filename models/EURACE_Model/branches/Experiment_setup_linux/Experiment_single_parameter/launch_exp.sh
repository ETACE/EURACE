#!/bin/bash

######### RUNNING ALL EXPERIMENTS ##################################################################
# Script to run a set of experiments exp1...expN
###################################################################################################

echo '  Launching all experiments in:'$BASE
export NUM_EXP=1
#for ((count=1; count<=NUM_EXP; count++)); do
#11 12 13
for count in 10; do
	echo $count
	#echo $count
	cd exp$count
	bash run_exp.sh
	cd -
done
echo '  Done.'

