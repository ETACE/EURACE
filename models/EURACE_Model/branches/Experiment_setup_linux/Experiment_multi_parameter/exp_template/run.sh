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

	#Decompress the xml files
	echo '+ DeCompressing and removing the xml files'
	bzip2 -d xmlfiles.tar.bz
	tar -xf xmlfiles.tar

	#Create the SQL database
	python $BASE/gendb.py $MODEL_XML_DIR/$MODEL_XML_FILE ./

	#Rename to VisGUI default name
	mv iterdata.db iters.db

	#Compress the xml files and remove them
	echo '+ Compressing and removing the xml files'
	tar -cvj --remove-files --overwrite --file=xmlfiles.tar.bz *.xml
	rm xmlfiles.tar

	#Just remove the xml files
	#echo '+ Removing the xml files'
	#rm *.xml

	#Remove the xml files, except multiples of 240
	#echo '+ Removing xml files, except multiples of 240'
	#for i in *.xml; do
	#   filebase=`basename $i .xml`
	#   if (( filebase % 240 != 0 )); then
	#       echo "Removing $i"
	#       rm $i
	#   fi
	#done

	#Compress the databases without removing originals
	#echo '+ Compressing iters.db, keeping the original'
	#tar -cjv --overwrite --file=iters.tar.gz iters.db

	#Compress the databases and remove the originals
	#echo '+ Compressing iters.db and removing the original'
	#tar -cjv --remove-files --overwrite --file=iters.tar.gz iters.db

echo 'Run '$PWD' --DONE'
echo 'Run '$PWD':DONE' >>$BASE/STATUS 
