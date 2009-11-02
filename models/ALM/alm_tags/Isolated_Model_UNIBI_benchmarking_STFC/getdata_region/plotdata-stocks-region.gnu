#set terminal postscript eps "Helvetica" 30
#set output "stocks-region.eps"

#set terminal png
#set output "stocks-region.png"

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


plot 'data-stocks-region.csv' using 1:5 title "stocks-of-reg-1",'data-stocks-region.csv' using 1:6 title "stocks-of-1-in-1",'data-stocks-region.csv' using 1:7 title "stocks-of-1-in-2",'data-stocks-region.csv' using 1:8 title "stocks-of-reg-2",'data-stocks-region.csv' using 1:9 title "stocks-of-2-in-2",'data-stocks-region.csv' using 1:10 title "-stocks-of-2-in-1"
 

pause -1
