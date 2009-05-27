#!/bin/bash

######### BASE RUN ################################################################
# Script for a base run:
# Usage:
# - NR_NODES: number of nodes to use
# - ITS: number of iterations
# - MAIN: location of executable file
# Steps:
# - run
# - join the node-*.xml files to single xml files
# - remove the node-*.xml files
###################################################################################

NR_NODES=4
ITS=800
MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Hybrid_Model_A_energy_shock/main'
JOIN='/home/sander/cloning/scripts/join/join.sh'

#$MAIN $ITS output.xml
mpiexec -n $NR_NODES $MAIN $ITS output.xml

#Concatenating the node files
bash $JOIN ./ $NR_NODES

#Removing the node files
rm node*.xml
