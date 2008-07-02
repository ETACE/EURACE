#set terminal postscript eps "Helvetica" 30
#set output "graph-region.eps"

#set terminal png
#set output "graph-region.png"

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


plot 'data-region.csv' using 1:2 title "employed", 'data-region.csv' using 1:3 title "employed-region-1", 'data-region.csv' using 1:4 title "employed-region-2", 'data-region.csv' using 1:5 title "employed-region-1-live-region-1", 'data-region.csv' using 1:6 title "employed-region-1-live-region-2", 'data-region.csv' using 1:7 title "employed-region-2-live-region-1", 'data-region.csv' using 1:8 title "employed-region-2-live-region-2"

pause -1
