#!/bin/bash

######### CREATION OF THE SPECIFIC SETTINGS #########################################################
# Script to create the file specific.xml that contains the specific parameter settings for the cases
# - Enter folder ./duration_x/intensity_y/frequency_z
# - Write xml tags and parameter settings to the file specific.xml
#####################################################################################################
BASE=$PWD

echo '  Creating specific.xml files in folder hierarchy...'
echo 'In exp_script_2.sh these values are used:'
echo 'Duration: [' $F1_values ']'
echo 'Intensity: [' $F2_values ']'
echo 'Frequency: [' $F3_values ']'

for f1 in $F1_values; do
    folder1='duration_'$f1
    for f2 in $F2_values; do
        folder2='intensity_'$f2
        for f3 in $F3_values; do
            folder3='frequency_'$f3
                #echo $PWD
                cd ./its/$folder1/$folder2/$folder3
                rm -f specific.xml
                echo '<environment>'>>specific.xml

                #Symmetric shock:
                echo -n '<symmetric_shock>'>>specific.xml
                echo -n '1'>>specific.xml
                echo '</symmetric_shock>'>>specific.xml
        
                #Duration:
                echo -n '<energy_shock_start>'>>specific.xml
                echo -n '240'>>specific.xml
                echo '</energy_shock_start>'>>specific.xml
        
                echo -n '<energy_shock_end>'>>specific.xml
                echo -n $[240+$f1]>>specific.xml
                echo '</energy_shock_end>'>>specific.xml
        
                #Intensity:
                echo -n '<const_energy_shock_intensity>'>>specific.xml
                echo -n $f2>>specific.xml
                echo '</const_energy_shock_intensity>'>>specific.xml
                
                #Frequency:
                echo -n '<energy_shock_frequency>'>>specific.xml
                echo -n $f3>>specific.xml
                echo '</energy_shock_frequency>'>>specific.xml
                
                echo '</environment>'>>specific.xml
                
                cd $BASE
        done
    done
done

echo '  Finished creation of specific.xml files.'
