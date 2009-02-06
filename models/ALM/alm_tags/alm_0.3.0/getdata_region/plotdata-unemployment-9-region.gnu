#set terminal postscript eps "Helvetica" 30
#set output "graph-unemployment-region.eps"

#set terminal png
#set output "graph-unemployment-region.png"

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



plot 'data-unemployment-region.csv' using 1:2 title "unemployment-rate", 'data-unemployment-region.csv' using 1:8 title "unemployment-rate-reg-1",'data-unemployment-region.csv' using 1:14 title "unemployment-rate-reg-2",'data-unemployment-region.csv' using 1:20 title "unemployment-rate-reg-3",'data-unemployment-region.csv' using 1:26 title "unemployment-rate-reg-4",'data-unemployment-region.csv' using 1:32 title "unemployment-rate-reg-5",'data-unemployment-region.csv' using 1:38 title "unemployment-rate-reg-6",'data-unemployment-region.csv' using 1:44 title "unemployment-rate-reg-7",'data-unemployment-region.csv' using 1:50 title "unemployment-rate-reg-8",'data-unemployment-region.csv' using 1:56 title "unemployment-rate-reg-9"


pause -1
