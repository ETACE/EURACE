#set terminal postscript eps "Helvetica" 30
#set output "graph-output-2-region.eps"

#set terminal png
#set output "graph-output-2-region.png"

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


plot 'data-output-region.csv' using 1:3 title "output-reg-1",'data-output-region.csv' using 1:4 title "output-reg-2",'data-output-region.csv' using 1:5 title "output-reg-3",'data-output-region.csv' using 1:6 title "output-reg-4"

 
 

pause -1
