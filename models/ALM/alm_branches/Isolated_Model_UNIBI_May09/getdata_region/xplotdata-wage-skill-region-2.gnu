#set terminal postscript eps "Helvetica" 30
#set output "wage-skill-region-2.eps"

set terminal png
set output "wage-skill-region-2.png"

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


plot 'data-wage-region.csv' using 1:14 title "wage", 'data-wage-region.csv' using 1:15 title "wage_skill_1",'data-wage-region.csv' using 1:16 title "wage_skill_2",'data-wage-region.csv' using 1:17 title "wage_skill_3",'data-wage-region.csv' using 1:18 title "wage_skill_4",'data-wage-region.csv' using 1:19 title "wage_skill_5"

#pause -1
