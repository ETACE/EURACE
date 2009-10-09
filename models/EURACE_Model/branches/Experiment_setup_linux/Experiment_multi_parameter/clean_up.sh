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

#Multi parameter experiment
echo '  Starting cleanup for experiment in:'$BASE
cd ./its

for folder1 in $F1; do
    for folder2 in $F2; do
        for folder3 in $F3; do
        cd ./its/$folder1/$folder2/$folder3

        for run in $RUNS; do
            cd 'run_'$run

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
			echo '+ Compressing iters.db and removing the original'
			tar -cjv --remove-files --file=iters.tar.gz iters.db

			cd ..
        done
        cd $BASE
        done
    done
done
echo '  Returning to: ' $PWD
echo '  Finished cleanup of xml files.'

