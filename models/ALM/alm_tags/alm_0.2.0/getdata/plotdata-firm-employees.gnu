#set terminal postscript eps "Helvetica" 30
#set output "graph-firm-output.eps"

#set terminal png
#set output "graph-firm-output.png"

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


plot 'data-firm-employees.csv' using 1:2 title "firm1", 'data-firm-employees.csv' using 1:3 title "firm2", 'data-firm-employees.csv' using 1:4 title "firm3", 'data-firm-employees.csv' using 1:5 title "firm4",'data-firm-employees.csv' using 1:6 title "firm5", 'data-firm-employees.csv' using 1:7 title "firm6", 'data-firm-employees.csv' using 1:8 title "firm7", 'data-firm-employees.csv' using 1:9 title "firm8",'data-firm-employees.csv' using 1:10 title "firm9", 'data-firm-employees.csv' using 1:11 title "firm10"
 

pause -1
