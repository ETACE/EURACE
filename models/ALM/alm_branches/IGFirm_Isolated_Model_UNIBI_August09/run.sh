make
./main 100 ./its/0.xml -f 20
cd getdata_region
gcc getdata_region.c -o getdata_region
./getdata_region ../its/0.xml
gnuplot plotdata-output.gnu
