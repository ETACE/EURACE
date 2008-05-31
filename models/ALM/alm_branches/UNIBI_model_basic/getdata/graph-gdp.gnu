#Set title:
#set title "Labour Market Model"

#Set style:
#set data style linespoints
set data style lines
set pointsize 1.0
set grid
set line 5.0

#Set labels:
set xlabel "Days" 
#set ylabel ""
#set y2label ""

#Set legenda:
#set nokey
set key below

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

#set terminal postscript eps color "Helvetica" 16
set terminal postscript eps monochrome "Helvetica" 16
set output 'graph-gdp.eps'
plot 'data-eurostat.csv' using 1:2 title "gdp"
set output

set terminal png
set output 'graph-gdp.png'
plot 'data-eurostat.csv' using 1:2 title "gdp"
set output

# Call external epstopdf to transform the eps file to pdf.
!epstopdf --outfile=graph-gdp.pdf graph-gdp.eps 
quit 
