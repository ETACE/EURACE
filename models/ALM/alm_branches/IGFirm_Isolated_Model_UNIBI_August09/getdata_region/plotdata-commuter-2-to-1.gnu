#set terminal postscript eps "Helvetica" 30
#set output "commuter-2-to-1.eps"

#set terminal png
#set output "commuter-2-to-1.png"

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

plot 'data-commuter-region-2.csv' using 1:2 title "emigrants",'data-commuter-region-2.csv' using 1:6 title "emigrants-skill-1",'data-commuter-region-2.csv' using 1:10 title "emigrants-skill-2",'data-commuter-region-2.csv' using 1:14 title "emigrants-skill-3",'data-commuter-region-2.csv' using 1:18 title "emigrants-skill-4",'data-commuter-region-2.csv' using 1:22 title "emigrants-skill-5"

pause -1
