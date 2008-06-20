#set terminal postscript eps "Helvetica" 30
#set output "graph-planned-output.eps"

#set terminal png
#set output "graph-planned-output.png"

set data style linespoints
#set pointsize 4.0
#set key below
#set grid
#set line 4.0

#set xrange [1:8]
#set yrange [0:60]
#set xtics (1, 4, 9, 16)
#set ytics (0, 200, 400, 600, 800, 1000)

#set title "Labour Market Model"
set xlabel "Days"
#set ylabel "value of a"


plot 'data-planned-output.csv' using 1:2 title "monthly-output",'data-planned-output.csv' using 1:3 title "planned-monthly-quantity", 'data-planned-output.csv' using 1:4 title "monthly-output-region-1",'data-planned-output.csv' using 1:5 title "planned-monthly-quantity-region-1",'data-planned-output.csv' using 1:6 title "monthly-output-region-1",'data-planned-output.csv' using 1:7 title "planned-monthly-quantity-region-1"
 
 

pause -1
