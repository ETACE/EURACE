#!/bin/bash

######### CREATION OF THE SPECIFIC SETTINGS #########################################################
# Script to create the file specific.xml that contains the specific parameter settings for the cases
# - Enter folder ./duration_x/intensity_y/frequency_z
# - Write xml tags and parameter settings to the file specific.xml
#####################################################################################################
BASE=$PWD

F0="png"
#F1="40 120 240 560"     #duration: 240+"40 120 240 560"=280 360 480 801
#F2="0.01 0.05 0.10 0.20" #intensity
#F3="0 20 40 60"         #frequency

F1="40 240"
#F1="560"     		#duration: 240+"40 120 240 560"=280 360 480 801
F2="0.01 0.05 0.10" 		#intensity
F3="0 20 60"         #frequency

#Create main latex document
echo '  Creating main latex document...'
rm -f main.tex
echo '\documentclass{article}'>>main.tex
echo '\usepackage{epsfig,graphicx,verbatim, boxedminipage}'>>main.tex
echo '\begin{document}'>>main.tex

echo '  Creating latex figures in folder hierarchy...'
for folder0 in $F0; do
  for f1 in $F1; do
    folder1=duration_$f1
    for f2 in $F2; do
        folder2=intensity_$f2
        for f3 in $F3; do
            folder3=frequency_$f3
                #echo $PWD
                cd ./$folder0/$folder1/$folder2/$folder3
				echo 'Entering folder: '$PWD
                rm -f plot.tex

				#mv IGFirm-capital_good_price\(double\).png IGFirm-capital_good_price.png &
				#mv Eurostat-unemployment_rate\(double\).png Eurostat-unemployment_rate.png &
				#mv Eurostat-gdp\(double\).png Eurostat-gdp.png &
				#mv IGFirm-energy_costs_per_day\(double\).png IGFirm-energy_costs_per_day.png &

				echo '\begin{figure}[ht!]'>>plot.tex
				echo '\centering\leavevmode'>>plot.tex
				echo '\begin{minipage}{17cm}'>>plot.tex
				echo '\centering\leavevmode'>>plot.tex
				echo '{$d='$f1', \pi='$f2', \Pi='$f3'$}\\'>>plot.tex
				echo '\includegraphics[width=8cm]{./energy_shock/'$folder0/$folder1/$folder2/$folder3/'IGFirm-capital_good_price.png}'>>plot.tex
				echo '\includegraphics[width=8cm]{./energy_shock/'$folder0/$folder1/$folder2/$folder3/'IGFirm-energy_costs_per_day.png}'>>plot.tex
				echo '\includegraphics[width=8cm]{./energy_shock/'$folder0/$folder1/$folder2/$folder3/'Eurostat-gdp.png}'>>plot.tex
				echo '\includegraphics[width=8cm]{./energy_shock/'$folder0/$folder1/$folder2/$folder3/'Eurostat-unemployment_rate.png}'>>plot.tex
				echo '\end{minipage}'>>plot.tex
				echo '%\caption{Energy shock parameters: duration $d='$f1'$, intensity $\pi='$f2', periodicity $\Pi='$f3'$.}'>>plot.tex
				echo '%\label{Figure: IGFirm-capital_good_price}'>>plot.tex
				echo '\end{figure}'>>plot.tex
		       	echo ''>>plot.tex

                cd $BASE
		#In main document: add an input line
		echo '\input{'./$folder0/$folder1/$folder2/$folder3'/plot}'>>main.tex
        done
    done
  done
done


#Close latex document
echo '\end{document}'>>main.tex

echo '  Finished creation of latex figures files.'
