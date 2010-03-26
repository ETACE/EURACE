#!/bin/bash

######### RUNNING ALL EXPERIMENTS ##################################################################
# Script to run a set of experiments exp1...expN
###################################################################################################

echo '  Launching all experiments in:'$BASE
export NUM_EXP=8
for ((count=1; count<=NUM_EXP; count++)); do
	#echo $count
	cd exp$count
	bash run_exp.sh
	cd -
done
echo '  Done.'

