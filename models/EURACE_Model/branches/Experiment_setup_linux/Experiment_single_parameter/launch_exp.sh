#!/bin/bash

######### RUNNING ALL EXPERIMENTS ##################################################################
# Script to run a set of experiments exp1...expN
###################################################################################################

echo '  Launching all experiments in:'$BASE
export NUM_EXP=1
for ((count=1; count<=NUM_EXP; count++)); do
export NUM_EXP=1
#for ((count=1; count<=NUM_EXP; count++)); do
#for count in 2 3 5 7; do
	#echo $count
	cd exp$count
	bash run_exp.sh
	cd -
done
echo '  Done.'

