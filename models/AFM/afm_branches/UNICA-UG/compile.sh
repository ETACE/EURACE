cd project
rm -f *.c
rm -f *.h
cd ..


cp -R   Agents/*.h   project/ 
cp -R   Agents/*.c   project/  
cp -R   CDouble/*.h   project/  
cp -R   CDouble/*.c   project/  
cp -R   Random/*.h   project/  
cp -R   Random/*.c   project/  
cp -R   Order/*.h   project/  
cp -R   Order/*.c   project/  

cp -R   Double/*.h   project/  
cp -R   Double/*.c   project/   

cp -R   Asset/*.h   project/  
cp -R   Asset/*.c   project/   

cp -R   Stream/*.h   project/  
cp -R   Stream/*.c   project/   

cp -R   Portfolio/*.h   project/  
cp -R   Portfolio/*.c   project/   

cp -R    /*.h   project/  
cp -R    /*.c   project/   

cp -R   Household/*.h   project/  
cp -R   Household/*.c   project/   


cp -R   ClearingHouse/*.h   project/  
cp -R   ClearingHouse/*.c   project/   

cp -R    Makefile  project/  

cp -R   COrder/*.h   project/  
cp -R   COrder/*.c   project/  

cp -R   CDouble/*.h   project/  
cp -R   CDouble/*.c   project/  

cp -R   ClearingMechanism/*.h   project/  
cp -R   ClearingMechanism/*.c   project/  

cp -R   CAsset/*.h   project/  
cp -R   CAsset/*.c   project/  

cp -R   Belief/*.h   project/  
cp -R   Belief/*.c   project/  


cp -R   Int/*.h   project/  
cp -R   Int/*.c   project/  

cp -R   Eurostat/*.h   project/ 
cp -R   Eurostat/*.c   project/ 
cp -R   Stock/*.h   project/  
cp -R   Stock/*.c   project/  
cp -R   Histogram/*.h   project/  
cp -R   Histogram/*.c   project/  
cd project
make
rm -f *.o

cd ..
