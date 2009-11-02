#set terminal postscript eps "Helvetica" 30
#set output "graph-unemployment-flows.eps"

#set terminal png
#set output "graph-unemployment-flows.png"

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



plot 'data-unemployment-flows.csv' using 1:2 title "inflow", 'data-unemployment-flows.csv' using 1:3 title "outflow", 'data-unemployment-flows.csv' using 1:4 title "inflow_1",'data-unemployment-flows.csv' using 1:5 title "outflow_1",'data-unemployment-flows.csv' using 1:6 title "inflow_2",'data-unemployment-flows.csv' using 1:7 title "outflow_2"

pause -1
