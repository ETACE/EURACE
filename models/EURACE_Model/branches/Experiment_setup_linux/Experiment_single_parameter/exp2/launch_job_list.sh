#!/bin/bash

######### RUNNING THE EXPERIMENT ##################################################################
# Script to 
###################################################################################################

echo '  Launching all job scripts in:'$BASE

for ((count=0; count<NUM_PROCS; count++)); do
	bash job_list_$count.sh &
	#Wait 1 second before launching next job (prevents identical random seeds)
    sleep 1
done
echo '  Done.'

