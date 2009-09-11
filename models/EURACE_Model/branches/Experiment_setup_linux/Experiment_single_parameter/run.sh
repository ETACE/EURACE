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

#$MAIN_S $ITS output.xml
#mpiexec -n $NR_NODES $MAIN_P $ITS output.xml -r
#bash $BASE/join.sh ./ $NR_NODES
#rm node*.xml

echo 'Run '$PWD' --DONE'
echo 'Run '$PWD':DONE' >>$BASE/STATUS 
