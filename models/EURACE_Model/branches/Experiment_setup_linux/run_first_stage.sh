#!/bin/bash

######### RUNNING THE INITIAL PHASE ###############################################################
# Script to run the first stage simulation:
# Runs the transient phase, and then saves the final iteration as transient.xml in the top folder
# Steps:
# - run in the top-level folder: ./its/0.xml (see output_last.xml)
# - save a full snapshot in the last iteration only (see output_last.xml)
# - join the node-*.xml files to a single file
# - the final xml is renamed to transient.xml
###################################################################################################
# Usage:
# - NR_NODES: number of nodes to use
# - ITS: number of iterations
# - MAIN: location of executable file
# - run
# - remove

echo '  Starting first stage of experiment...'
BASE=$PWD
NR_NODES='4'
ITS=540
MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Integrated_Model_rev2295/main'
#MAIN='/media/DOCS/Docs/EURACE/X-models/SVN_linux/models/EURACE_Model/branches/Hybrid_Model_A_energy_shock/main'
#JOIN='/home/sander/cloning/scripts/join/join.sh'

echo '      Starting run for initial transient...'
#$MAIN $ITS output_last.xml
mpiexec -n $NR_NODES $MAIN $ITS output_last.xml -r
echo '      Finished run for initial transient.'

#Concatenating the node files
echo '      Starting concatenation of the node output files'
bash ./join.sh ./ $NR_NODES
echo '      Finished concatenation'

#Removing the node files
rm -f node*.xml
echo '      Removed node output files'

#Rename the $ITS.xml to 0_transient.xml
mv $ITS.xml 0_transient.xml
echo '      Renamed last iteration xml file to transient.xml'

echo '  Finished first stage of experiment.'
