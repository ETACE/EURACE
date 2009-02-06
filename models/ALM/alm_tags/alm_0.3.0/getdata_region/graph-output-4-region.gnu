#set title "Labour Market Model"

#Set style:
#set data style linespoints
set data style lines
set pointsize 1.0
set grid
set line 5.0

#Set labels:
set xlabel "Days" 
set ylabel "actual output"
#set y2label ""

#Set legenda:
#set nokey
set key top right

#Set ranges:
#set xrange [1:8]
#set yrange [-1:5]
#set y2range [-1:5]

#Set a tick marks:
#set xtics (1, 4, 9, 16)
#set ytics (0, 200, 400, 600, 800, 1000)
#set xtics nomirror
#set ytics nomirror
#set y2tics nomirror

#Plotting

set terminal postscript eps color solid rounded "Helvetica" 16
#set terminal postscript eps monochrome "Helvetica" 16
set output 'graph-output-4-region.eps'
#plot 'data-eurostat.csv' using 1:11 title "actual output", 'data-eurostat.csv' using 1:10 title "actual sales"
#plot 'data-monthly-output.csv' using 1:4 title "output"
#plot 'data-output-region.csv' using 1:2 title "output",'data-sold-quantity-region.csv' using 1:2 title "sold-quantity",'data-supply-region.csv' using 1:2 title "total stock"
#plot 'data-output-region.csv' using 1:2 title "output"
plot 'data-output-region.csv' using 1:3 title "output-reg-1",'data-output-region.csv' using 1:4 title "output-reg-2",'data-output-region.csv' using 1:5 title "output-reg-3",'data-output-region.csv' using 1:6 title "output-reg-4"
set output

set terminal png
set output 'graph-output-4-region.png'
#plot 'data-eurostat.csv' using 1:11 title "actual output" , 'data-eurostat.csv' using 1:10 title "actual sales"
#plot 'data-monthly-output.csv' using 1:4 title "output"
#plot 'data-output-region.csv' using 1:2 title "output",'data-sold-quantity-region.csv' using 1:2 title "sold-quantity",'data-supply-region.csv' using 1:2 title "total stock"
#plot 'data-output-region.csv' using 1:2 title "output"
plot 'data-output-region.csv' using 1:3 title "output-reg-1",'data-output-region.csv' using 1:4 title "output-reg-2",'data-output-region.csv' using 1:5 title "output-reg-3",'data-output-region.csv' using 1:6 title "output-reg-4"
set output

# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-output-4-region.pdf graph-output-4-region.eps 
quit 
