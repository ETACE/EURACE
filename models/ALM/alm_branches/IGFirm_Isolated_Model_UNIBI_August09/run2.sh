cd create2
gcc -std=c99 create.c -o create
./create
cp 0.xml ../its
cd ..
make
./main 1500 ./its/0.xml -f 20
cd getdata_region
gcc getdata_region.c -o getdata_region
./getdata_region ../its/0.xml

gnuplot xplotdata-output-region.gnu
mv output-region.png ./Graph

gnuplot xplotdata-unemployment-region.gnu
mv unemployment-region.png ./Graph

gnuplot xplotdata-unemployment-skill-region-1.gnu
mv unemployment-skill-region-1.png ./Graph

gnuplot xplotdata-unemployment-skill-region-2.gnu
mv unemployment-skill-region-2.png ./Graph

gnuplot xplotdata-unemployment.gnu
mv unemployment.png ./Graph

gnuplot xplotdata-wage-region.gnu
mv wage-region.png ./Graph

gnuplot xplotdata-wage-firm-region.gnu
mv wage-firm-region.png ./Graph

gnuplot xplotdata-wage.gnu
mv wage.png ./Graph

gnuplot xplotdata-wage-skill-region-1.gnu
mv wage-skill-region-1.png ./Graph

gnuplot xplotdata-wage-skill-region-2.gnu
mv wage-skill-region-2.png ./Graph

gnuplot xplotdata-technology-region.gnu
mv technology-region.png ./Graph

gnuplot xplotdata-price-region.gnu
mv price-region.png ./Graph

gnuplot xplotdata-delivery-region.gnu
mv delivery-region.png ./Graph

gnuplot xplotdata-sales-region.gnu
mv sales-region.png ./Graph

gnuplot xplotdata-capital-stock-region.gnu
mv capital-stock-region.png ./Graph

gnuplot xplotdata-specific-skills-firm-region.gnu
mv specific-skills-firm-region.png ./Graph

gnuplot xplotdata-specific-skills-household-region.gnu
mv specific-skills-household-region.png ./Graph

gnuplot xplotdata-commuter-region.gnu
mv commuter-region.png ./Graph

gnuplot xplotdata-commuter-1-to-2.gnu
mv commuter-1-to-2.png ./Graph

gnuplot xplotdata-commuter-2-to-1.gnu
mv commuter-2-to-1.png ./Graph

gnuplot xplotdata-wage-offer-region.gnu
mv wage-offer-region.png ./Graph

gnuplot xplotdata-wage-offer-skill-region-1.gnu
mv wage-offer-skill-region-1.png ./Graph

gnuplot xplotdata-wage-offer-skill-region-2.gnu
mv wage-offer-skill-region-2.png ./Graph

gnuplot xplotdata-wage-offer.gnu
mv wage-offer.png ./Graph

gnuplot xplotdata-vacancies-region.gnu
mv vacancies-region.png ./Graph

gnuplot xplotdata-stocks-region.gnu
mv stocks-region.png ./Graph

gnuplot xplotdata-active-firms-region.gnu
mv active-firms-region.png ./Graph

gnuplot xplotdata-revenues-IG.gnu
mv revenues-IG.png ./Graph

gnuplot xplotdata-dividend-payment-IG.gnu
mv dividend-payment-IG.png ./Graph

gnuplot xplotdata-budget-supply-region.gnu
mv budget-supply-region.png ./Graph

gnuplot xplotdata-consumption-budget-region.gnu
mv consumption-budget-region.png ./Graph

gnuplot xplotdata-IG-variables.gnu
mv IG-variables.png ./Graph

gnuplot xplotdata-capital-good-price-region.gnu
mv capital-good-price-region.png ./Graph
