#set terminal postscript eps "Helvetica" 30
#set output "graph-price-region.eps"

#set terminal png
#set output "graph-price-region.png"

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


plot 'data-price-region.csv' using 1:2 title "price",'data-price-region.csv' using 1:3 title "price-reg-1",'data-price-region.csv' using 1:4 title "price-reg-2",'data-price-region.csv' using 1:5 title "price-reg-3",'data-price-region.csv' using 1:6 title "price-reg-4",'data-price-region.csv' using 1:7 title "price-reg-5",'data-price-region.csv' using 1:8 title "price-reg-6",'data-price-region.csv' using 1:9 title "price-reg-7",'data-price-region.csv' using 1:10 title "price-reg-8",'data-price-region.csv' using 1:11 title "price-reg-9" 
 

pause -1
