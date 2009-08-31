#set terminal postscript eps "Helvetica" 30
#set output "capital-labor--region.eps"

#set terminal png
#set output "capital-labor--region.png"

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


plot 'data-capital-labor-region.csv' using 1:6 title "capital-labor-ratio-region1",'data-capital-labor-region.csv' using 1:10 title "capital-labor-ratio-region2",'data-capital-labor-region.csv' using 1:7 title "technology-skills-ratio-region1",'data-capital-labor-region.csv' using 1:11 title "technology-skills-ratio-region2",'data-capital-labor-region.csv' using 1:4 title "stocks-capital-goods-demand-ratio-global",'data-capital-labor-region.csv' using 1:9 title "stocks-coutput-ratio-region1",'data-capital-labor-region.csv' using 1:13 title "stocks-coutput-ratio-region2"

pause -1
