#set terminal postscript eps "Helvetica" 30
#set output "graph-earnings-region.eps"

#set terminal png
#set output "graph-earnings-region.png"

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


plot 'data-earnings-region.csv' using 1:2 title "earnings",'data-earnings-region.csv' using 1:3 title "earnings-reg-1",'data-earnings-region.csv' using 1:4 title "earnings-reg-2",'data-earnings-region.csv' using 1:5 title "earnings-reg-3",'data-earnings-region.csv' using 1:6 title "earnings-reg-4",'data-earnings-region.csv' using 1:7 title "earnings-reg-5",'data-earnings-region.csv' using 1:8 title "earnings-reg-6",'data-earnings-region.csv' using 1:9 title "earnings-reg-7",'data-earnings-region.csv' using 1:10 title "earnings-reg-8",'data-earnings-region.csv' using 1:11 title "earnings-reg-9" 

pause -1
