#set terminal postscript eps "Helvetica" 30
#set output "graph-stocks.eps"

#set terminal png
#set output "graph-stocks.png"

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


plot 'data-stocks-region.csv' using 1:2 title "stocks", 'data-stocks-region.csv' using 1:3 title "stocks_in_home_region", 'data-stocks-region.csv' using 1:4 title "stocks_in_foreign_region", 'data-stocks-region.csv' using 1:5 title "stocks_in_region_1", 'data-stocks-region.csv' using 1:6 title "stocks_in_1_from_1", 'data-stocks-region.csv' using 1:7 title "stocks_in_2_from_1",'data-stocks-region.csv' using 1:8 title "stocks_in_region_2", 'data-stocks-region.csv' using 1:9 title "stocks_in_2_from_2", 'data-stocks-region.csv' using 1:10 title "stocks_in_1_from_2"


pause -1
