#set terminal postscript eps "Helvetica" 30
#set output "commuter.eps"

set terminal png
set output "commuter.png"

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


plot 'data-commuter-region-1.csv' using 1:3 title "emigrants-from-1-to-2",'data-employed-region.csv' using 1:3 title "employees-of-region-1",'data-commuter-region-2.csv' using 1:2 title "emigrants-from-2-to-1",'data-employed-region.csv' using 1:4 title "employees-of-region-2"



#pause -1
