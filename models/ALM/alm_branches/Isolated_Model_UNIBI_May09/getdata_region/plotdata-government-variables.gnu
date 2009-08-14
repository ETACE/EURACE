#set terminal postscript eps "Helvetica" 30
#set output "government-variables-region.eps"

#set terminal png
#set output "government-variables-region.png"

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


plot 'data-government-tax-revenues-region.csv' using 1:3 title "tax-revenue-region1",'data-government-tax-revenues-region.csv' using 1:4 title "tax-revenue-region2",'data-government-benefit-payment-region.csv' using 1:3 title "benefit-payment-region1",'data-government-benefit-payment-region.csv' using 1:4 title "benefit-payment-region2"

pause -1
