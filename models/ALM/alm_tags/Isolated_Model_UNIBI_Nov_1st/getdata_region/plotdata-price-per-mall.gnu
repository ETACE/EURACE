#set terminal postscript eps "Helvetica" 30
#set output "price-mall.eps"

#set terminal png
#set output "price-mall.png"

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


plot 'data-price-index-mall-region.csv' using 1:2 title "price",'data-price-index-mall-region.csv' using 1:3 title "price-reg-1",'data-price-index-mall-region.csv' using 1:4 title "price-reg-2"
 

pause -1
