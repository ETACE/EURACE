#set terminal postscript eps "Helvetica" 30
#set output "graph-employees-region.eps"

#set terminal png
#set output "graph-employees-region.png"

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


plot 'data-employees-vacancies-region.csv' using 1:2 title "employees",'data-employees-vacancies-region.csv' using 1:4 title "employees-reg-1",'data-employees-vacancies-region.csv' using 1:6 title "employees-reg-2",'data-employees-vacancies-region.csv' using 1:8 title "employees-reg-3",'data-employees-vacancies-region.csv' using 1:10 title "employees-reg-4",'data-employees-vacancies-region.csv' using 1:12 title "employees-reg-5",'data-employees-vacancies-region.csv' using 1:14 title "employees-reg-6",'data-employees-vacancies-region.csv' using 1:16 title "employees-reg-7",'data-employees-vacancies-region.csv' using 1:18 title "employees-reg-8",'data-employees-vacancies-region.csv' using 1:20 title "employees-reg-9"

pause -1
