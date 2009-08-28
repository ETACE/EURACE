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
ITS=1000

MAIN_P='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_p'
MAIN_S='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/trunk/Integrated_Model_1.0/main_s'
#MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Integrated_Model_1.0_energy_shock/main'

#$MAIN $ITS output.xml
mpiexec -n $NR_NODES $MAIN $ITS output.xml -r

