#set terminal postscript eps "Helvetica" 30
#set output "graph-technology-region.eps"

#set terminal png
#set output "graph-technology-region.png"

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



plot 'data-specific-skill-firm-region.csv' using 1:3 title "technology",'data-specific-skill-firm-region.csv' using 1:5 title "technology-reg-1",'data-specific-skill-firm-region.csv' using 1:7 title "technology-reg-2",'data-specific-skill-firm-region.csv' using 1:9 title "technology-reg-3",'data-specific-skill-firm-region.csv' using 1:11 title "technology-reg-4",'data-specific-skill-firm-region.csv' using 1:13 title "technology-reg-5",'data-specific-skill-firm-region.csv' using 1:15 title "technology-reg-6",'data-specific-skill-firm-region.csv' using 1:17 title "technology-reg-7",'data-specific-skill-firm-region.csv' using 1:19 title "technology-reg-8",'data-specific-skill-firm-region.csv' using 1:21 title "technology-reg-9"
pause -1
