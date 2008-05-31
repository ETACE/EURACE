cd ..
cd xparser
./xparser ../model/model.xml
cd ..
cd model
make
./main 3000 ./its/0.xml
cd getdata
./getdata ../its/0.xml
gnuplot plotdata-monthly-output.gnu 
