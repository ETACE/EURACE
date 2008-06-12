#set terminal postscript eps "Helvetica" 30
#set output "graph-revenue-region.eps"

#set terminal png
#set output "graph-revenue-region.png"

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


plot 'data-revenues-region.csv' using 1:2 title "revenue",'data-revenues-region.csv' using 1:3 title "revenue-reg-1",'data-revenues-region.csv' using 1:4 title "revenue-reg-2",'data-revenues-region.csv' using 1:5 title "revenue-reg-3",'data-revenues-region.csv' using 1:6 title "revenue-reg-4",'data-revenues-region.csv' using 1:7 title "revenue-reg-5",'data-revenues-region.csv' using 1:8 title "revenue-reg-6",'data-revenues-region.csv' using 1:9 title "revenue-reg-7",'data-revenues-region.csv' using 1:10 title "revenue-reg-8",'data-revenues-region.csv' using 1:11 title "revenue-reg-9" 

pause -1
