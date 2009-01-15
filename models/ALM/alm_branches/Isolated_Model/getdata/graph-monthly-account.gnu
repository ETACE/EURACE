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
set output 'graph-monthly-account.eps'
plot 'data-monthly-account.csv' using 1:2 title "monthly-account",'data-monthly-account.csv' using 1:3 title "monthly-account-region-1",'data-monthly-account.csv' using 1:4 title "monthly-account-region-2"
set output

set terminal png
set output 'graph-monthly-account.png'
plot 'data-monthly-account.csv' using 1:2 title "monthly-account",'data-monthly-account.csv' using 1:3 title "monthly-account-region-1",'data-monthly-account.csv' using 1:4 title "monthly-account-region-2"
set output

# Call external epstopdf to transform the eps file to pdf.
# !epstopdf --outfile=graph-monthly-account.pdf graph-monthly-account.eps 
quit 
