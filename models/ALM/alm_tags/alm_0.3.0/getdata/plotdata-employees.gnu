#set terminal postscript eps "Helvetica" 30
#set output "graph-employees.eps"

#set terminal png
set output "graph-employees.png"

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


plot 'data-employees.csv' using 1:2 title "ave-vacancies", 'data-employees.csv' using 1:3 title "ave-employees",'data-employees.csv' using 1:4 title "ave-vacancies-region-1", 'data-employees.csv' using 1:5 title "ave-employees-region-1",'data-employees.csv' using 1:6 title "ave-vacancies-region-2", 'data-employees.csv' using 1:7 title "ave-employees-region-2" 
 

#pause -1
