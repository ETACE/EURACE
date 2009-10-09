#!/bin/bash
#Clean up of xml files after DB creation

echo '  Starting cleanup for benchmark in: '$BASE

cd ./its
cd ./bench
echo 'RUN: ' $RUNS
for run in $RUNS; do
    cd 'run_'$run

	rm *.xml

    cd ..
done
cd $BASE
echo 'Returning to: ' $PWD

#Single parameter experiment
echo '  Starting cleanup for experiment in:'$BASE
cd ./its
for folder1 in $F1; do
	cd $folder1
        for run in $RUNS; do
            cd 'its_'$run
			echo 'Entered: '$PWD
			
			#Compress the xml files and remove them
			#echo '+ Compressing and removing the xml files'
			#tar -cvj --remove-files --file=xmlfiles.tar.bz *

			#Just remove the xml files
			#echo '+ Removing the xml files'
			#rm *.xml

			#Compress the databases without removing originals
			#echo '+ Compressing iters.db, keeping the original'
			#tar -cjv --file=iters.tar.gz iters.db

			#Compress the databases and remove the originals
			#echo '+ Compressing iters.db  and removing the original'
			#tar -cjv --remove-files --file=iters.tar.gz iters.db

			#Just remove the database files
			#echo '+ Removing the .db files'
			#rm *.db

			cd ..
        done
    cd ..
	echo 'Returning to: ' $PWD
done
cd $BASE
echo 'Returning to: ' $PWD
echo '  Finished cleanup of xml files.'

