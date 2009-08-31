#set terminal postscript eps "Helvetica" 30
#set output "IGfirm-wage-offer-skill-region-1.eps"

#set terminal png
#set output "IGfirm-wage-offer-skill-region-1.png"

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


plot 'data-IGfirm-wage-offer-region.csv' using 1:8 title "wage-offer-for-skill-1",'data-IGfirm-wage-offer-region.csv' using 1:9 title "wage-offer-for-skill-2",'data-IGfirm-wage-offer-region.csv' using 1:10 title "wage-offer-for-skill-3",'data-IGfirm-wage-offer-region.csv' using 1:11 title "wage-offer-for-skill-4",'data-IGfirm-wage-offer-region.csv' using 1:12 title "wage-offer-for-skill-5",'data-IGfirm-wage-offer-region.csv' using 1:13 title "wage-offer-for-rd"

pause -1
