#set terminal postscript eps "Helvetica" 30
#set output "commuter-region.eps"

#set terminal png
#set output "commuter-region.png"

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


plot 'data-commuter-region.csv' using 1:2 title "commuters",'data-commuter-region.csv' using 1:5 title "employees",'data-commuter-region.csv' using 1:3 title "commuters-from-1-to-2",'data-commuter-region.csv' using 1:6 title "employees-of-region-1",'data-commuter-region.csv' using 1:4 title "commuters-from-2-to-1",'data-commuter-region.csv' using 1:7 title "employees-of-region-2"



pause -1
