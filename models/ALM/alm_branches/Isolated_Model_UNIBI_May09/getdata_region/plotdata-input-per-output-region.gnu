#set terminal postscript eps "Helvetica" 30
#set output "input-per-output-region.eps"

#set terminal png
#set output "input-per-output-region.png"

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


plot 'data-input-per-output-region.csv' using 1:6 title "Labor_per_output_reg1",'data-input-per-output-region.csv' using 1:9 title "Labor_per_output_reg2",'data-input-per-output-region.csv' using 1:7 title "capital_per_output-reg1",'data-input-per-output-region.csv' using 1:10 title "capital_per_output-reg2",'data-input-per-output-region.csv' using 1:8 title "Labor_per_capital-reg1",'data-input-per-output-region.csv' using 1:8 title "Labor_per_capital-reg2"

pause -1
