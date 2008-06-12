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

set terminal postscript eps color "Helvetica" 16
#set terminal postscript eps monochrome "Helvetica" 16
set output 'graph-unemployment-skills.eps'
plot 'data-unemployment.csv' using 1:2 title "unemployment-rate", 'data-unemployment.csv' using 1:3 title "unemployment-rate-skill-group-1", 'data-unemployment.csv' using 1:4 title "unemployment-rate-skill-group-2", 'data-unemployment.csv' using 1:5 title "unemployment-rate-skill-group-3", 'data-unemployment.csv' using 1:6 title "unemployment-rate-skill-group-4", 'data-unemployment.csv' using 1:7 title "unemployment-rate-skill-group-5"
set output

set terminal png
set output 'graph-unemployment-skills.png'
plot 'data-unemployment.csv' using 1:2 title "unemployment-rate", 'data-unemployment.csv' using 1:3 title "unemployment-rate-skill-group-1", 'data-unemployment.csv' using 1:4 title "unemployment-rate-skill-group-2", 'data-unemployment.csv' using 1:5 title "unemployment-rate-skill-group-3", 'data-unemployment.csv' using 1:6 title "unemployment-rate-skill-group-4", 'data-unemployment.csv' using 1:7 title "unemployment-rate-skill-group-5"
set output


# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-unemployment-skills.pdf graph-unemployment-skills.eps 
quit 
