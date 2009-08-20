#set terminal postscript eps "Helvetica" 30
#set output "unemployment-skill-region-2.eps"

set terminal png
set output "unemployment-skill-region-2.png"

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


plot 'data-unemployment-region.csv' using 1:16 title "unemployment-rate", 'data-unemployment-region.csv' using 1:17 title "unemployment-rate-skill-group-1", 'data-unemployment-region.csv' using 1:18 title "unemployment-rate-skill-group-2", 'data-unemployment-region.csv' using 1:19 title "unemployment-rate-skill-group-3", 'data-unemployment-region.csv' using 1:20 title "unemployment-rate-skill-group-4", 'data-unemployment-region.csv' using 1:21 title "unemployment-rate-skill-group-5", 'data-unemployment-region.csv' using 1:22 title "unemployment-rate-skill-group-6"

#pause -1
