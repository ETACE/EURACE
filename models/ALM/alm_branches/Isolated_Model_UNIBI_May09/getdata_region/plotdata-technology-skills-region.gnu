#set terminal postscript eps "Helvetica" 30
#set output "graph-technology-skill-region.eps"

#set terminal png
#set output "graph-technology-skill-region.png"

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



plot 'data-specific-skill-firm-region.csv' using 1:4 title "specific-skills-reg-1",'data-specific-skill-firm-region.csv' using 1:5 title "technology-reg-1",'data-specific-skill-firm-region.csv' using 1:6 title "specific-skills-reg-2",'data-specific-skill-firm-region.csv' using 1:7 title "technology-reg-1",'data-technological-frontier.csv' using 1:2 title "technology-frontier"

pause -1
#'data-specific-skill-firm-region.csv' using 1:2 title "specific-skills",'data-specific-skill-firm-region.csv' using 1:3 title #"technology",
