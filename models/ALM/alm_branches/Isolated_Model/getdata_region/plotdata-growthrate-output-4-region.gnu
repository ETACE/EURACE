#set terminal postscript eps "Helvetica" 30
#set output "graph-monthly-savings.eps"

#set terminal png
#set output "graph-growthrate-output.png"

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


plot 'data-growthrate-output-region.csv' using 1:2 title "growth rate output", 'data-growthrate-output-region.csv' using 1:3 title "growth rate output reg1", 'data-growthrate-output-region.csv' using 1:4 title "growth rate output reg2", 'data-growthrate-output-region.csv' using 1:5 title "growth rate output reg3", 'data-growthrate-output-region.csv' using 1:6 title "growth rate output reg4"
 
 
pause -1
