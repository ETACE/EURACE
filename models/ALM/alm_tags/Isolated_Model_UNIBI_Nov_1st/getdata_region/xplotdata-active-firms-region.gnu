#set terminal postscript eps "Helvetica" 30
#set output "active-firms-region.eps"

set terminal png
set output "active-firms-region.png"

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


plot 'data-active-firms-region.csv' using 1:2 title "active-firms",'data-active-firms-region.csv' using 1:3 title "active-firms-reg-1",'data-active-firms-region.csv' using 1:4 title "active-firms-reg-2"

#pause -1
