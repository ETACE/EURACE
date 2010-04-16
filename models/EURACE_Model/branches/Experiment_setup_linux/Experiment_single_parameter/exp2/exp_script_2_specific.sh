#!/bin/bash
# Script to create the file specific.xml that contains the specific parameter settings
# - Enter folder ./value_x
# - Write xml tags and parameter settings to the file specific.xml

echo '  Creating specific.xml files in folder hierarchy...'

mkdir -p 'its'
cd ./its

echo 'In exp_script_2_specific.sh these values are used:'
echo '[' $F1_values ']'

mkdir -p $EXPERIMENT_NAME
cd ./$EXPERIMENT_NAME

for f1 in $F1_values; do
                cd $f1
                rm -f specific.xml
                echo '<environment>'>>specific.xml

                #Variable:
                echo -n '<'$EXPERIMENT_NAME'>'>>specific.xml
                echo -n $f1>>specific.xml
                echo '</'$EXPERIMENT_NAME'>'>>specific.xml

                echo -n '<'income_tax_rate'>'>>specific.xml
                echo "scale=2;$f1/10"|bc -l>>specific.xml			#use bc to do division, 2 decimals
                echo '</income_tax_rate>'>>specific.xml
                echo '</environment>'>>specific.xml
                
                cd -
done
cd ..

echo '  Finished creation of specific.xml files.'
