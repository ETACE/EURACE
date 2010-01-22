#set terminal postscript eps "Helvetica" 30
#set output "sales-region.eps"

set terminal png
set output "sales-region.png"

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


plot 'data-sales-region.csv' using 1:5 title "sales-in-reg-1"#,'data-sales-region.csv' using 1:6 title "sales-in-1-from-1",'data-#sales-region.csv' using 1:7 title "sales-of-1-from-2",'data-sales-region.csv' using 1:8 title "sales-in-reg-2",'data-sales-#region.csv' using 1:9 title "sales-in-2-to-2",'data-sales-region.csv' using 1:10 title "sales-in-2-from-1"
 

#pause -1
