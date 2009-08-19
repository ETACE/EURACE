#set terminal postscript eps "Helvetica" 30
#set output "IGvariables.eps"

#set terminal png
#set output "IGvariables.png"

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


plot 'data-IGfirm-capital-good-demand-region.csv' using 1:2 title "capital-good-demand",'data-IGfirm-output-region.csv' using 1:2 title "output",'data-IGfirm-output-region.csv' using 1:3 title "planned-output",'data-IGfirm-sales-region.csv' using 1:2 title "sales",'data-IGfirm-capital-good-store-region.csv' using 1:2 title "store-before-production",'data-IGfirm-capital-good-store-region.csv' using 1:3 title "store-after-production",'data-IGfirm-employees-region.csv' using 1:2 title "production-employees",'data-IGfirm-employees-region.csv' using 1:3 title "research-employees"

pause -1
