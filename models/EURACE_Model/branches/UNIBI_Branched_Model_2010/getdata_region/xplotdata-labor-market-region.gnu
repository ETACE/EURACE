#set terminal postscript eps "Helvetica" 30
#set output "labor-market-region.eps"

set terminal png
set output "labor-market-region.png"

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


plot 'data-labor-market-region.csv' using 1:5 title "acceptance/(V/U)"#,'data-labor-market-region.csv' using 1:3 title "no-#applications",'data-labor-market-region.csv' using 1:4 title "no-matches"
 
 

#pause -1
