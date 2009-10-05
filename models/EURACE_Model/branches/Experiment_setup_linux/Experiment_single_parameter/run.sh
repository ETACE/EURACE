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

	$MAIN_S $ITS output.xml
	#mpiexec -n $NR_NODES $MAIN_P $ITS output.xml -r
	#bash $BASE/join.sh ./ $NR_NODES
	#rm node*.xml

	#tar -cj --remove-files --overwrite --file=xmlfiles.tar.bz *

	#Create the SQL database
	#python $BASE/gendb.py $MODEL_XML_DIR/eurace_model.xml ./

	#Rename to VisGUI default name
	#mv iterdata.db iters.db

	#Compress the database
	#tar -cj --remove-files --file=iters.tar.gz iters.db

echo 'Run '$PWD' --DONE'
echo 'Run '$PWD':DONE' >>$BASE/STATUS 
