#set terminal postscript eps "Helvetica" 30
#set output "graph-imigrants-region-1.eps"

#set terminal png
#set output "graph-immigrants-region-1.png"

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


plot 'data-commuter-region-1.csv' using 1:12 title "immigrants-reg-2",'data-commuter-region-1.csv' using 1:13 title "immigrants-reg-3",'data-commuter-region-1.csv' using 1:14 title "immigrants-reg-4",'data-commuter-region-1.csv' using 1:15 title "immigrants-reg-5",'data-commuter-region-1.csv' using 1:16 title "immigrants-reg-6",'data-commuter-region-1.csv' using 1:17 title "immigrants-reg-7",'data-commuter-region-1.csv' using 1:18 title "immigrants-reg-8",'data-commuter-region-1.csv' using 1:19 title "immigrants-reg-9" 

pause -1
