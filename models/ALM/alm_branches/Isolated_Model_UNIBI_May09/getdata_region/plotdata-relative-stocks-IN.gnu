#set terminal postscript eps "Helvetica" 30
#set output "graph-relative-stocks-IN.eps"

#set terminal png
#set output "graph-relative-stocks-IN.png"

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


plot 'data-relative-stocks-region.csv' using 1:5 title "relative-stocks-IN-reg1/reg2",'data-relative-stocks-region.csv' using 1:6 title "relative-stocks-reg1/reg2-IN-reg-1",'data-relative-stocks-region.csv' using 1:7 title "relative-stocks-reg1/reg2-IN-reg2"
 

pause -1
