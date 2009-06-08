#set terminal postscript eps "Helvetica" 30
#set output "graph-reservation-wage-region-2.eps"

#set terminal png
#set output "graph-reservation-wage-region-2.png"

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


plot 'data-reservation-wage.csv' using 1:12 title "reservation-wage-for-skill-1",'data-reservation-wage.csv' using 1:13 title "reservation-wage-for-skill-2",'data-reservation-wage.csv' using 1:14 title "reservation-wage-for-skill-3",'data-reservation-wage.csv' using 1:15 title "reservation-wage-for-skill-4",'data-reservation-wage.csv' using 1:16 title "reservation-wage-for-skill-5"





pause -1
