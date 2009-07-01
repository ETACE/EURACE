#set terminal postscript eps "Helvetica" 30
#set output "vacancies-region.eps"

#set terminal png
#set output "vacancies-region.png"

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


plot 'data-employees-vacancies-region.csv' using 1:3 title "vacancies",'data-employees-vacancies-region.csv' using 1:5 title "vacancies-reg-1",'data-employees-vacancies-region.csv' using 1:7 title "vacancies-reg-2"
pause -1
