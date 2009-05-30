#!/bin/bash

######### CREATION OF THE SPECIFIC SETTINGS #########################################################
# Script to create the file specific.xml that contains the specific parameter settings for the cases
# - Enter folder ./duration_x/intensity_y/frequency_z
# - Write xml tags and parameter settings to the file specific.xml
#####################################################################################################
BASE=$PWD

#F1="40 120 240 560"     #duration: 240+"40 120 240 560"=280 360 480 801
#F2="0.01 0.05 0.10 0.20" #intensity
#F3="0 20 40 60"         #frequency


F1="40 240"
#F1="560"     		#duration: 240+"40 120 240 560"=280 360 480 801
F2="0.01 0.10" 		#intensity
F3="0 20 40"         #frequency

#Create main latex document
echo '  Creating main latex document...'
rm -f main.tex
echo '\documentclass{article}'>>main.tex
echo '\usepackage{epsfig,graphicx,verbatim, boxedminipage}'>>main.tex
echo '\begin{document}'>>main.tex

echo '  Creating latex figures in folder hierarchy...'

for f1 in $F1; do
    folder1=duration_$f1
    for f2 in $F2; do
        folder2=intensity_$f2
        for f3 in $F3; do
            folder3=frequency_$f3
                #echo $PWD
                cd ./$folder1/$folder2/$folder3
                rm -f plot.tex

		echo '\begin{figure}[ht!]'>>plot.tex
		echo '\centering\leavevmode'>>plot.tex
		echo '\begin{minipage}{14cm}'>>plot.tex
		echo '\centering\leavevmode'>>plot.tex
		echo '{$d='$f1', i='$f2', f='$f3'$}\\'>>plot.tex
		echo '\includegraphics[width=4cm]{'./$folder1/$folder2/$folder3/'IGFirm-capital_good_price.png}'>>plot.tex
		echo '\includegraphics[width=4cm]{'./$folder1/$folder2/$folder3/'Eurostat-gdp.png}'>>plot.tex
		echo '\includegraphics[width=4cm]{'./$folder1/$folder2/$folder3/'Eurostat-unemployment_rate.png}'>>plot.tex
		echo '\end{minipage}'>>plot.tex
		echo '%\caption{$d='$f1', i='$f2', f='$f3'$}'>>plot.tex
		echo '%\label{Figure: IGFirm-capital_good_price}'>>plot.tex
		echo '\end{figure}'>>plot.tex
           	echo ''>>plot.tex

                cd $BASE
		#In main document: add an input line
		echo '\input{'./$folder1/$folder2/$folder3'/plot}'>>main.tex
        done
    done
done
#Close latex document
echo '\end{document}'>>main.tex

echo '  Finished creation of latex figures files.'
