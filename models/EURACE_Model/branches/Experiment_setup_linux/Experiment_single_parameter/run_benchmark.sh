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

echo '  Starting benchmark experiment...'

mkdir -p 'its'
cd ./its
mkdir -p 'bench'
cd ./bench

for run in $RUNS; do
    mkdir -p 'run_'$run
    cd 'run_'$run

    echo '      Starting run for benchmark experiment...'

	#Empty the folder	
	rm *

	#Run serial with no output:
	#cp $BASE/output_benchmark_none.xml ./
	#echo '      Copied output file from' $BASE'/output_none.xml to folder: run_'$run
	#$MAIN_S $ITS 'output_benchmark_none.xml'

	#Run serial with snapshot:
	#cp $BASE/output_benchmark_snapshot.xml ./
	#echo '      Copied output file from' $BASE'/output_benchmark_snapshot.xml to folder: run_'$run
	#$MAIN_S $ITS 'output_benchmark_snapshot.xml'
	
	#Run serial with all but household output:
	#cp $BASE/output_benchmark_no_hh.xml ./
	#echo '      Copied output file from' $BASE'/output_benchmark_no_hh.xml to folder: run_'$run
	#$MAIN_S $ITS 'output_benchmark_no_hh.xml' 

	#Run serial with small output:
	cp $BASE/output_benchmark.xml ./
	echo '      Copied output file from' $BASE'/output_benchmark.xml to folder: run_'$run
	$MAIN_S $ITS 'output_benchmark.xml' 


	#Run parallel:
	#mpiexec -n $NR_NODES $MAIN_P $ITS 'output_benchmark_snapshot.xml' -r
	#mpiexec -n $NR_NODES $MAIN_P $ITS 'output_benchmark.xml' -r
	#mpiexec -n $NR_NODES $MAIN_P $ITS 'output_none.xml' -r

#	If the program exits:
#	if [ $? -ne 0 ]; then
#		echo $MAIN_S $ITS output_benchmark_snapshot.xml 
#		bash
#	fi 

	#Concatenating the node files
	#echo '      Starting concatenation of the node output files'
	#bash $BASE/join.sh ./ $NR_NODES
	#echo '      Finished concatenation'

	#Removing the node files
	#rm -f node*.xml
	#echo '      Removed node output files'

	#tar -cj --remove-files --file=xmlfiles.tar.bz *
	#rm *.xml

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

    cd ..
done
cd ../..

echo '  Finished benchmark experiment.'
