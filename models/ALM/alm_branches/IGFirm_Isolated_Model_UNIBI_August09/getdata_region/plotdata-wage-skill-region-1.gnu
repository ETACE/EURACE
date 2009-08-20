#set terminal postscript eps "Helvetica" 30
#set output "wage-skill-region-1.eps"

#set terminal png
#set output "wage-skill-region-1.png"

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


plot 'data-wage-region.csv' using 1:9 title "wage", 'data-wage-region.csv' using 1:10 title "wage_skill_1",'data-wage-region.csv' using 1:11 title "wage_skill_2",'data-wage-region.csv' using 1:12 title "wage_skill_3",'data-wage-region.csv' using 1:13 title "wage_skill_4",'data-wage-region.csv' using 1:14 title "wage_skill_5",'data-wage-region.csv' using 1:15 title "wage_skill_6"

pause -1
