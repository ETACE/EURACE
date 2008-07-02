#set terminal postscript eps "Helvetica" 30
#set output "graph-r-wage.eps"

#set terminal png
#set output "graph-r-wage.png"

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

#plot 'data-r-wage.csv' using 1:2 title "ave-r-wage", 'data-r-wage.csv' using 1:3 title "ave-r-wage-skill-group-1", 'data-r-wage.csv' using 1:4 title "ave-r-wage-skill-group-2", 'data-r-wage.csv' using 1:5 title "ave-r-wage-skill-group-3", 'data-r-wage.csv' using 1:6 title "ave-r-wage-skill-group-4", 'data-r-wage.csv' using 1:7 title "ave-r-wage-skill-group-5"
plot 'data-r-wage.csv' using 1:2 title "ave-r-wage", 'data-r-wage.csv' using 1:3 title "ave-r-wage-skill-group-1", 'data-r-wage.csv' using 1:4 title "ave-r-wage-skill-group-2", 'data-r-wage.csv' using 1:5 title "ave-r-wage-skill-group-3", 'data-r-wage.csv' using 1:6 title "ave-r-wage-skill-group-4", 'data-r-wage.csv' using 1:7 title "ave-r-wage-skill-group-5"

pause -1
