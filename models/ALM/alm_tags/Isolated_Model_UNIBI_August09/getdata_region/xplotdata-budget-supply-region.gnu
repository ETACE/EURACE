#set terminal postscript eps "Helvetica" 30
#set output "budget-supply-region.eps"

set terminal png
set output "budget-supply-region.png"

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


plot 'data-budget-supply-region.csv' using 1:2 title "relative-supply-reg1/reg2",'data-budget-supply-region.csv' using 1:3 title "relative-consumption-budget-reg1/reg2",'data-budget-supply-region.csv' using 1:4 title "relative-stocks-reg1/reg2",'data-budget-supply-region.csv' using 1:5 title "relativ-delivery-reg1/reg2",'data-budget-supply-region.csv' using 1:6 title "relativ-sales-reg1/reg2"
 

#pause -1
