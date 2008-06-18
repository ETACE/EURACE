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
set output 'graph-growthrate-output-4-region.eps'
#plot 'data-eurostat.csv' using 1:14 title "growth rate: output, monthly (direct)"
#plot 'data-eurostat.csv' using 1:15 title "growth rate: output, monthly (2)"
#plot 'data-eurostat.csv' using 1:15 title "growth rate: output, quarterly"
#plot 'data-eurostat.csv' using 1:16 title "growth rate: output, annual monthly"
#plot 'data-eurostat.csv' using 1:17 title "growth rate: output, annual quarterly"
plot 'data-growthrate-output-region.csv' using 1:2 title "growth rate output", 'data-growthrate-output-region.csv' using 1:3 title "growth rate output reg1", 'data-growthrate-output-region.csv' using 1:4 title "growth rate output reg2", 'data-growthrate-output-region.csv' using 1:5 title "growth rate output reg3", 'data-growthrate-output-region.csv' using 1:6 title "growth rate output reg4"
set output

set terminal png
set output 'graph-growthrate-output-4-region.png'
#plot 'data-eurostat.csv' using 1:14 title "growth rate: output, monthly (direct)"
#plot 'data-eurostat.csv' using 1:15 title "growth rate: output, monthly (2)"
#plot 'data-eurostat.csv' using 1:15 title "growth rate: output, quarterly"
#plot 'data-eurostat.csv' using 1:16 title "growth rate: output, annual monthly"
#plot 'data-eurostat.csv' using 1:17 title "growth rate: output, annual quarterly"
plot 'data-growthrate-output-region.csv' using 1:2 title "growth rate output", 'data-growthrate-output-region.csv' using 1:3 title "growth rate output reg1", 'data-growthrate-output-region.csv' using 1:4 title "growth rate output reg2", 'data-growthrate-output-region.csv' using 1:5 title "growth rate output reg3", 'data-growthrate-output-region.csv' using 1:6 title "growth rate output reg4"
set output

# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-growthrate-output-4-region.pdf graph-growthrate-output-4-region.eps 
quit 
