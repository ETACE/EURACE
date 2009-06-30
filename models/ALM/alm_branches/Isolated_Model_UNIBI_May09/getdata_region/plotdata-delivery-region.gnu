#set terminal postscript eps "Helvetica" 30
#set output "graph-relative-delivery.eps"

#set terminal png
#set output "graph-relative-delivery.png"

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


plot 'data-delivery-region.csv' using 1:5 title "delivery-of-reg-1",'data-delivery-region.csv' using 1:6 title "delivery-of-1-to-1",'data-delivery-region.csv' using 1:7 title "delivery-of-1-to-2",'data-delivery-region.csv' using 1:8 title "delivery-of-reg-2",'data-delivery-region.csv' using 1:9 title "delivery-of-2-to-2",'data-delivery-region.csv' using 1:10 title "-delivery-of-2-to-1"
 

pause -1
