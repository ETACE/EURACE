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

#set terminal postscript eps color "Helvetica" 16
set terminal postscript eps monochrome "Helvetica" 16
set output 'graph-firm-employees.eps'
plot 'data-firm-employees.csv' using 1:2 title "firm1", 'data-firm-employees.csv' using 1:3 title "firm2", 'data-firm-employees.csv' using 1:4 title "firm3", 'data-firm-employees.csv' using 1:5 title "firm4",'data-firm-employees.csv' using 1:6 title "firm5", 'data-firm-employees.csv' using 1:7 title "firm6", 'data-firm-employees.csv' using 1:8 title "firm7", 'data-firm-employees.csv' using 1:9 title "firm8",'data-firm-employees.csv' using 1:10 title "firm9", 'data-firm-employees.csv' using 1:11 title "firm10"
set output

set terminal png
set output 'graph-firm-employees.png'
plot 'data-firm-employees.csv' using 1:2 title "firm1", 'data-firm-employees.csv' using 1:3 title "firm2", 'data-firm-employees.csv' using 1:4 title "firm3", 'data-firm-employees.csv' using 1:5 title "firm4",'data-firm-employees.csv' using 1:6 title "firm5", 'data-firm-employees.csv' using 1:7 title "firm6", 'data-firm-employees.csv' using 1:8 title "firm7", 'data-firm-employees.csv' using 1:9 title "firm8",'data-firm-employees.csv' using 1:10 title "firm9", 'data-firm-employees.csv' using 1:11 title "firm10"
set output

# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-firm-employees.pdf graph-firm-employees.eps 
quit 
