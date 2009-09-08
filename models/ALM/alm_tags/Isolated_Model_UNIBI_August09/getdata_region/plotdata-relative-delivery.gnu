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


plot 'data-relative-delivery-region.csv' using 1:2 title "relative-delivery-ORIGIN-reg1/reg2",'data-relative-delivery-region.csv' using 1:3 title "relative-delivery-reg1/reg2-ORIGIN-reg-1",'data-relative-delivery-region.csv' using 1:4 title "relative-delivery-reg1/reg2-ORIGIN-reg2",'data-relative-delivery-region.csv' using 1:5 title "relative-delivery-RECEIVER-reg1/reg2",'data-relative-delivery-region.csv' using 1:6 title "relative-delivery-reg1/reg2-RECEIVER-reg-1",'data-relative-delivery-region.csv' using 1:7 title "relative-delivery-reg1/reg2-RECEIVER-reg2"
 

pause -1
