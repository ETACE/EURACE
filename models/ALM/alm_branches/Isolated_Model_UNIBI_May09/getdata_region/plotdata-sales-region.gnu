#set terminal postscript eps "Helvetica" 30
#set output "graph-sales.eps"

#set terminal png
#set output "graph-sales.png"

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


plot 'data-sales-region.csv' using 1:5 title "sales_in_region_1", 'data-sales-region.csv' using 1:6 title "sales_in_1_from_1", 'data-sales-region.csv' using 1:7 title "sales_in_1_from_2",'data-sales-region.csv' using 1:8 title "sales_in_region_2", 'data-sales-region.csv' using 1:9 title "sales_in_2_from_2", 'data-sales-region.csv' using 1:10 title "sales_in_2_from_2"


pause -1
