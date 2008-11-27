#set terminal postscript eps "Helvetica" 30
#set output "graph-commuter-region.eps"

#set terminal png
#set output "graph-commuter-region.png"

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


plot 'data-commuter-region.csv' using 1:2 title "commuter", 'data-commuter-region.csv' using 1:3 title "commuter-reg-1",'data-commuter-region.csv' using 1:6 title "commuter-reg-2",'data-commuter-region.csv' using 1:9 title "commuter-reg-3",'data-commuter-region.csv' using 1:12 title "commuter-reg-4",'data-commuter-region.csv' using 1:15 title "commuter-reg-5",'data-commuter-region.csv' using 1:18 title "commuter-reg-6",'data-commuter-region.csv' using 1:21 title "commuter-reg-7",'data-commuter-region.csv' using 1:24 title "commuter-reg-8",'data-commuter-region.csv' using 1:27 title "commuter-reg-9"

pause -1
