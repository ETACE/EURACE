#set terminal postscript eps "Helvetica" 30
#set output "graph-wage-region.eps"

#set terminal png
#set output "graph-wage-region.png"

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


plot 'data-wage-region.csv' using 1:3 title "wage",'data-wage-region.csv' using 1:5 title "wage-reg-1",'data-wage-region.csv' using 1:7 title "wage-reg-2",'data-wage-region.csv' using 1:9 title "wage-reg-3",'data-wage-region.csv' using 1:11 title "wage-reg-4",'data-wage-region.csv' using 1:13 title "wage-reg-5",'data-wage-region.csv' using 1:15 title "wage-reg-6",'data-wage-region.csv' using 1:17 title "wage-reg-7",'data-wage-region.csv' using 1:19 title "wage-reg-8",'data-wage-region.csv' using 1:21 title "wage-reg-9"

pause -1
