#set terminal postscript eps "Helvetica" 30
#set output "graph-wage.eps"

#set terminal png
#set output "graph-wage-reg1.png"

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


plot 'data-wage-reg1.csv' using 1:2 title "ave-wage reg1", 'data-wage-reg1.csv' using 1:3 title "wage-skill-1", 'data-wage-reg1.csv' using 1:4 title "ave-skill-2", 'data-wage-reg1.csv' using 1:5 title "ave-skill-3", 'data-wage-reg1.csv' using 1:6 title "wage-skill-4", 'data-wage-reg1.csv' using 1:7 title "ave-skill-5"

pause -1
