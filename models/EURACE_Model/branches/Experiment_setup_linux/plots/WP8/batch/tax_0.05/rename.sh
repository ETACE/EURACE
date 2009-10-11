#!/bin/bash
#Script to rename files

#Batch
mv Eurostat.gdp\(double\)-$PLOTNR.png Eurostat-gdp-runbatch.png
mv Eurostat.unemployment_rate\(double\)-$PLOTNR.png Eurostat-unemployment_rate-runbatch.png
mv Eurostat.annual_growth_rates_monthly.cpi\(double\)-$PLOTNR.png Eurostat-cpi-runbatch.png
mv Eurostat.investment_gdp_ratio\(double\)-$PLOTNR.png Eurostat-investment_gdp_ratio-runbatch.png
mv Eurostat.monthly_investment_value\(double\)-$PLOTNR.png Eurostat-monthly_investment_value-runbatch.png

#Time
mv Eurostat-gdp\(double\).png Eurostat-gdp-timebatch.png
mv Eurostat-unemployment_rate\(double\).png Eurostat-unemployment_rate-timebatch.png
mv Eurostat-annual_growth_rates_monthly.png Eurostat-cpi-timebatch.png
mv Eurostat-investment_gdp_ratio\(double\).png Eurostat-investment_gdp_ratio-timebatch.png
mv Eurostat-monthly_investment_value\(double\).png Eurostat-monthly_investment_value-timebatch.png



