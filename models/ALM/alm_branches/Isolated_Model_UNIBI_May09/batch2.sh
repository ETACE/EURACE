#!/bin/bash


iterations=5000;
runs=10;
path="./its/0.xml";

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
mkdir datafile_government_debt
cd ..

for n in $(seq 1 $runs); do
mkdir batchruns/its
cp $path batchruns/its
./main $iterations ./batchruns/its/0.xml -f 20
cd getdata
gcc getdata.c -o getdata
./getdata ../batchruns/its/0.xml

gnuplot plotdata-file-monthly-output.gnu
gnuplot plotdata-file-unemployment.gnu
cd ..
cp getdata/data-monthly-output.csv batchruns/datafile_monthly_output/data-monthly-output-$n.csv
cp getdata/data-region-unemployment.csv  batchruns/datafile_region_unemployment/data-region-unemployment$n.csv
cp getdata/data-capital.csv batchruns/datafile_capital/data-capital-$n.csv
cp getdata/data-technology.csv  batchruns/datafile_technology/data-region-technology$n.csv

cp getdata/data-employees.csv batchruns/datafile_employees/data-employees-$n.csv
cp getdata/data-monthly-account.csv  batchruns/datafile_monthly-account/data-monthly-account-$n.csv
cp getdata/data-monthly-savings.csv batchruns/datafile_monthly_savings/data-monthly-savings-$n.csv
cp getdata/data-planned-output.csv  batchruns/datafile_planned_output/data-planned-output-$n.csv

cp getdata/data-price-index.csv batchruns/datafile_price_index/data-price-index-$n.csv
cp getdata/data-region.csv  batchruns/datafile_region/data-region-$n.csv
cp getdata/data-region-monthly-output.csv batchruns/datafile_region_monthly_output/data-region-monthly-output-$n.csv
cp getdata/data-unemployment.csv  batchruns/datafile_unemployment/data-unemployment-$n.csv

cp getdata/data-government.csv batchruns/datafile_government_debt/data-government-debt-$n.csv
cp getdata/data-region-wage.csv batchruns/datafile_region_wage/data-region-wage-$n.csv
cp getdata/data-revenue.csv  batchruns/datafile_revenue/data-revenue-$n.csv
cp getdata/data-wage.csv batchruns/datafile_wage/data-wage-$n.csv
cp getdata/data-wage-offer.csv  batchruns/datafile_wage_offer/data-wage-offer-$n.csv
cp getdata/data-growthrate-output.csv  batchruns/datafile_growthrate_output/data-growthrate-output-$n.csv
cp getdata/data-growthrate-technology.csv  batchruns/datafile_growthrate_technology/data-growthrate-technology-$n.csv
cp getdata/mean_specific_skills_region.csv batchruns/datafile_mean_specific_skills_region/data-mean-specific-skills-gegion-$n.csv
cp getdata/data-wage-reg1.csv batchruns/datafile_wage_reg1/data-wage-reg1-$n.csv
cp getdata/data-wage-reg2.csv batchruns/datafile_wage_reg2/data-wage-reg2-$n.csv

cp getdata/data-regional-wage-firm.csv batchruns/datafile_wage_reg_firm/data-regional-wage-firm-$n.csv

cp getdata/data-regional-wage-firm.csv batchruns/datafile_wage_reg_firm/data-regional-wage-firm-$n.csv

cp getdata/data-regional-price.csv batchruns/datafile_region_price/data-regional-price-$n.csv

cp getdata/graph-unemployment.png batchruns/graphs/graph-unemployment-$n.png
cp getdata/graph-monthly-output.png batchruns/graphs/graph-monthly-output-$n.png
done
#LANG=de_DE.ISO-8859-1 /usr/lib/R/bin/R

