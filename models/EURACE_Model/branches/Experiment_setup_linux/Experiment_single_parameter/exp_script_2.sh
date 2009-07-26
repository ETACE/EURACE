#!/bin/bash

######### CREATION OF THE SPECIFIC SETTINGS #########################################################
# Script to create the file specific.xml that contains the specific parameter settings for the cases
# - Enter folder ./duration_x/intensity_y/frequency_z
# - Write xml tags and parameter settings to the file specific.xml
#####################################################################################################
BASE=$PWD

F1="0.01 0.05 0.10"
echo '  Creating specific.xml files in folder hierarchy...'

mkdir -p 'its'
cd ./its

for f1 in $F1; do
    folder1=tax_$f1
                #echo $PWD
                cd ./$folder1/
                rm -f specific.xml
                echo '<environment>'>>specific.xml

                #Tax rate:
                echo -n '<const_income_tax_rate>'>>specific.xml
                echo -n $f1>>specific.xml
                echo '</const_income_tax_rate>'>>specific.xml

                echo '</environment>'>>specific.xml
                
                cd $BASE
        done
cd ..

echo '  Finished creation of specific.xml files.'
