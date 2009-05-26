#!/bin/sh

######### CREATION OF THE SPECIFIC SETTINGS #########################################################
# Script to create the file specific.xml that contains the specific parameter settings for the cases
# - Enter folder ./duration_x/intensity_y/frequency_z
# - Write xml tags and parameter settings to the file specific.xml
#####################################################################################################
BASE=$PWD
OLDPWD=$PWD

F1="40 120 240 560"     #duration: 240+"40 120 240 560"=280 360 480 801
F2="1 5 10 20"          #intensity
F3="0 20 40 60"         #frequency

echo '  Creating specific.xml files in folder hierarchy...'

for f1 in $F1; do
    folder1=duration_$f1
    for f2 in $F2; do
        folder2=intensity_$f2
        for f3 in $F3; do
            folder3=frequency_$f3
                #echo $PWD
                cd ./$folder1/$folder2/$folder3
                rm -f specific.xml
                echo '<environment>'>>specific.xml
        
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
