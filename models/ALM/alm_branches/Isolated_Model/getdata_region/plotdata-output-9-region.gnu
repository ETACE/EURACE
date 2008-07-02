#set terminal postscript eps "Helvetica" 30
#set output "graph-output-region.eps"

#set terminal png
#set output "graph-output-region.png"

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


plot 'data-output-region.csv' using 1:2 title "output",'data-output-region.csv' using 1:3 title "output-reg-1",'data-output-region.csv' using 1:4 title "output-reg-2",'data-output-region.csv' using 1:5 title "output-reg-3",'data-output-region.csv' using 1:6 title "output-reg-4",'data-output-region.csv' using 1:7 title "output-reg-5",'data-output-region.csv' using 1:8 title "output-reg-6",'data-output-region.csv' using 1:9 title "output-reg-7",'data-output-region.csv' using 1:10 title "output-reg-8",'data-output-region.csv' using 1:10 title "output-reg-9"

 
 

pause -1
