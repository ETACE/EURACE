#set terminal postscript eps "Helvetica" 30
#set output "graph-emigrants-region-5.eps"

#set terminal png
#set output "graph-emigrants-region-5.png"

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


plot 'data-commuter-region-5.csv' using 1:2 title "emigrants-reg-1",'data-commuter-region-5.csv' using 1:3 title "emigrants-reg-2",'data-commuter-region-5.csv' using 1:4 title "emigrants-reg-3",'data-commuter-region-5.csv' using 1:5 title "emigrants-reg-4",'data-commuter-region-5.csv' using 1:7 title "emigrants-reg-6",'data-commuter-region-5.csv' using 1:8 title "emigrants-reg-7",'data-commuter-region-5.csv' using 1:9 title "emigrants-reg-8",'data-commuter-region-5.csv' using 1:10 title "emigrants-reg-9"


pause -1
