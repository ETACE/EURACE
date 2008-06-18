#Set title:
#set title "Labour Market Model"

#Set style:
#set data style linespoints
set data style lines
set pointsize 1.0
set grid
set line 5.0

set style line 6 lc rgb "black"

#Set labels:
set xlabel "Days" 
#set ylabel ""
#set y2label ""

#Set legenda:
#set nokey
set key top left

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
#set terminal postscript eps "Helvetica" 16
set output "graph-unemployment-2-region.eps"
plot 'data-unemployment-region.csv' using 1:2 title "unemployment-rate", 'data-unemployment-region.csv' using 1:8 title "unemployment-rate-reg-1",'data-unemployment-region.csv' using 1:14 title "unemployment-rate-reg-2" with lines ls 6
set output

set terminal png
set output "graph-unemployment-2-region.png"
plot 'data-unemployment-region.csv' using 1:2 title "unemployment-rate", 'data-unemployment-region.csv' using 1:8 title "unemployment-rate-reg-1",'data-unemployment-region.csv' using 1:14 title "unemployment-rate-reg-2" with lines ls 6
set output

# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-unemployment-2-region.pdf graph-unemployment-2-region.eps 
quit 
