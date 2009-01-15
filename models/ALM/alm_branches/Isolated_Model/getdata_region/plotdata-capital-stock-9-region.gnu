#set terminal postscript eps "Helvetica" 30
#set output "graph-capital-stock-region.eps"

#set terminal png
#set output "graph-capital-region.png"

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


plot 'data-capital-stock-region.csv' using 1:2 title "capital-stock",'data-capital-stock-region.csv' using 1:3 title "capital-stock-reg-1",'data-capital-stock-region.csv' using 1:4 title "capital-stock-reg-2",'data-capital-stock-region.csv' using 1:5 title "capital-stock-reg-3",'data-capital-stock-region.csv' using 1:6 title "capital-stock-reg-4",'data-capital-stock-region.csv' using 1:7 title "capital-stock-reg-5",'data-capital-stock-region.csv' using 1:8 title "capital-stock-reg-6",'data-capital-stock-region.csv' using 1:9 title "capital-stock-reg-7",'data-capital-stock-region.csv' using 1:10 title "capital-stock-reg-8",'data-capital-stock-region.csv' using 1:11 title "capital-stock-reg-9"
 

pause -1
