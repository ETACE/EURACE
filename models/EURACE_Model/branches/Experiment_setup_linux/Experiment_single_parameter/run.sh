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

	#Create the SQL database
	python $BASE/gendb.py $MODEL_XML_DIR/eurace_model.xml ./

	#Rename to VisGUI default name
	mv iterdata.db iters.db

	#Compress the xml files and remove them
	#echo '+ Compressing and removing the xml files'
	#tar -cvj --remove-files --overwrite --file=xmlfiles.tar.bz *.xml

	#Just remove the xml files
	#echo '+ Removing the xml files'
	rm *.xml

	#Compress the databases without removing originals
	#echo '+ Compressing iters.db, keeping the original'
	#tar -cjv --overwrite --file=iters.tar.gz iters.db

	#Compress the databases and remove the originals
	#echo '+ Compressing iters.db and removing the original'
	#tar -cjv --remove-files --overwrite --file=iters.tar.gz iters.db

echo 'Run '$PWD' --DONE'
echo 'Run '$PWD':DONE' >>$BASE/STATUS 
