#!/bin/bash
# Script to create the file specific.xml that contains the specific parameter settings
# - Enter folder ./value_x
# - Write xml tags and parameter settings to the file specific.xml

echo '  Creating specific.xml files in folder hierarchy...'

mkdir -p 'its'
cd ./its

echo 'In exp_script_2.sh these values are used:'
echo 'Unemployment benefit: [' $F1_values ']'

for f1 in $F1_values; do
    folder1='ub_'$f1

                cd 'ub_'$f1
                rm -f specific.xml
                echo '<environment>'>>specific.xml

                #Tax rate:
                echo -n '<gov_policy_unemployment_benefit_pct>'>>specific.xml
                echo -n $f1>>specific.xml
                echo '</gov_policy_unemployment_benefit_pct>'>>specific.xml

                echo '</environment>'>>specific.xml
                
                cd -
        done
cd ..

echo '  Finished creation of specific.xml files.'
