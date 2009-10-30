#set terminal postscript eps "Helvetica" 30
#set output "costs-per-unit-region.eps"

#set terminal png
#set output "costs-per-unit-region.png"

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


plot 'data-costs-per-unit-region.csv' using 1:6 title "Unit_costs_reg1",'data-costs-per-unit-region.csv' using 1:10 title "Unit_costs_reg2",'data-costs-per-unit-region.csv' using 1:7 title "Labour_costs_reg1",'data-costs-per-unit-region.csv' using 1:11 title "Labour_costs_reg2",'data-costs-per-unit-region.csv' using 1:8 title "capital_costs-reg1",'data-costs-per-unit-region.csv' using 1:12 title "capital_costs-reg2",'data-costs-per-unit-region.csv' using 1:9 title "interest-reg1",'data-costs-per-unit-region.csv' using 1:13 title "interest-reg2"

pause -1
