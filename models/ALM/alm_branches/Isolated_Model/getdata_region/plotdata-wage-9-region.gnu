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


plot 'data-wage-region.csv' using 1:2 title "wage",'data-wage-region.csv' using 1:8 title "wage-reg-1",'data-wage-region.csv' using 1:14 title "wage-reg-2",'data-wage-region.csv' using 1:20 title "wage-reg-3",'data-wage-region.csv' using 1:26 title "wage-reg-4",'data-wage-region.csv' using 1:32 title "wage-reg-5",'data-wage-region.csv' using 1:38 title "wage-reg-6",'data-wage-region.csv' using 1:44 title "wage-reg-7",'data-wage-region.csv' using 1:50 title "wage-reg-8",'data-wage-region.csv' using 1:56 title "wage-reg-9"

pause -1
