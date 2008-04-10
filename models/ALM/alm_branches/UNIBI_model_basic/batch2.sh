#!/bin/bash
cd .. 
cd xparser 
./xparser ../model/model.xml
cd ..
cd model
make 	
iterations=4000;
runs=15;
path="its/0.xml";

mkdir batchruns
cd batchruns
mkdir graphs
mkdir datafile_monthly_output
mkdir datafile_region_unemployment
mkdir datafile_technology
mkdir datafile_capital
mkdir datafile_employees
mkdir datafile_monthly_account
mkdir datafile_monthly_savings
mkdir datafile_planned_output
mkdir datafile_price_index
mkdir datafile_region
mkdir datafile_region_monthly_output
mkdir datafile_unemployment
mkdir datafile_region_wage
mkdir datafile_revenue
mkdir datafile_wage
mkdir datafile_wage_offer
mkdir datafile_growthrate_output
mkdir datafile_growthrate_technology
mkdir datafile_mean_specific_skills_region
mkdir datafile_wage_reg1
mkdir datafile_wage_reg2
mkdir datafile_wage_reg_firm
mkdir datafile_region_price
cd ..

for n in $(seq 1 $runs); do
mkdir batchruns/its
cp $path batchruns/its
./main $iterations ./batchruns/its/0.xml
cd getdata_batchruns
gcc getdata.c -o getdata
./getdata ../batchruns/its/0.xml
gnuplot plotdata-employees.gnu
gnuplot plotdata-monthly-output.gnu
gnuplot plotdata-unemployment.gnu
cd ..
cp getdata_batchruns/data-monthly-output.csv batchruns/datafile_monthly_output/data-monthly-output-$n.csv
cp getdata_batchruns/data-region-unemployment.csv  batchruns/datafile_region_unemployment/data-region-unemployment$n.csv
cp getdata_batchruns/data-capital.csv batchruns/datafile_capital/data-capital-$n.csv
cp getdata_batchruns/data-technology.csv  batchruns/datafile_technology/data-region-technology$n.csv

cp getdata_batchruns/data-employees.csv batchruns/datafile_employees/data-employees-$n.csv
cp getdata_batchruns/data-monthly-account.csv  batchruns/datafile_monthly-account/data-monthly-account-$n.csv
cp getdata_batchruns/data-monthly-savings.csv batchruns/datafile_monthly_savings/data-monthly-savings-$n.csv
cp getdata_batchruns/data-planned-output.csv  batchruns/datafile_planned_output/data-planned-output-$n.csv

cp getdata_batchruns/data-price-index.csv batchruns/datafile_price_index/data-price-index-$n.csv
cp getdata_batchruns/data-region.csv  batchruns/datafile_region/data-region-$n.csv
cp getdata_batchruns/data-region-monthly-output.csv batchruns/datafile_region_monthly_output/data-region-monthly-output-$n.csv
cp getdata_batchruns/data-unemployment.csv  batchruns/datafile_unemployment/data-unemployment-$n.csv

cp getdata_batchruns/data-region-wage.csv batchruns/datafile_region_wage/data-region-wage-$n.csv
cp getdata_batchruns/data-revenue.csv  batchruns/datafile_revenue/data-revenue-$n.csv
cp getdata_batchruns/data-wage.csv batchruns/datafile_wage/data-wage-$n.csv
cp getdata_batchruns/data-wage-offer.csv  batchruns/datafile_wage_offer/data-wage-offer-$n.csv
cp getdata_batchruns/data-growthrate-output.csv  batchruns/datafile_growthrate_output/data-growthrate-output-$n.csv
cp getdata_batchruns/data-growthrate-technology.csv  batchruns/datafile_growthrate_technology/data-growthrate-technology-$n.csv
cp getdata_batchruns/mean_specific_skills_region.csv batchruns/datafile_mean_specific_skills_region/data-mean-specific-skills-gegion-$n.csv
cp getdata_batchruns/data-wage-reg1.csv batchruns/datafile_wage_reg1/data-wage-reg1-$n.csv
cp getdata_batchruns/data-wage-reg2.csv batchruns/datafile_wage_reg2/data-wage-reg2-$n.csv

cp getdata_batchruns/data-regional-wage-firm.csv batchruns/datafile_wage_reg_firm/data-regional-wage-firm-$n.csv

cp getdata_batchruns/data-regional-wage-firm.csv batchruns/datafile_wage_reg_firm/data-regional-wage-firm-$n.csv

cp getdata_batchruns/data-regional-price.csv batchruns/datafile_region_price/data-regional-price-$n.csv

cp getdata_batchruns/graph-unemployment.png batchruns/graphs/graph-unemployment-$n.png
cp getdata_batchruns/graph-monthly-output.png batchruns/graphs/graph-monthly-output-$n.png
done
#LANG=de_DE.ISO-8859-1 /usr/lib/R/bin/R

