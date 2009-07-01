#set terminal postscript eps "Helvetica" 30
#set output "wage.eps"

set terminal png
set output "wage.png"

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


plot 'data-wage-region.csv' using 1:2 title "wage", 'data-wage-region.csv' using 1:3 title "wage_skill_1",'data-wage-region.csv' using 1:4 title "wage_skill_2",'data-wage-region.csv' using 1:5 title "wage_skill_3",'data-wage-region.csv' using 1:6 title "wage_skill_4",'data-wage-region.csv' using 1:7 title "wage_skill_5"

#pause -1
