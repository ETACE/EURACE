cd project
rm -f *.c
rm -f *.h
cd ..



xcopy   agents\*.h   project\ 
xcopy   agents\*.c   project\  

xcopy   Random\*.h   project\ /y 
xcopy   Random\*.c   project\ /y 
xcopy   Order\*.h   project\ /y 
xcopy   Order\*.c   project\ /y 

xcopy   Double\*.h   project\ /y 
xcopy   Double\*.c   project\ /y

xcopy   Asset\*.h   project\ /y 
xcopy   Asset\*.c   project\ /y

xcopy   Stream\*.h   project\ /y 
xcopy   Stream\*.c   project\ /y

xcopy   Portfolio\*.h   project\ /y 
xcopy   Portfolio\*.c   project\ /y

xcopy    *.h   project\ /y 
xcopy    *.c   project\ /y

xcopy   Household\*.h   project\ /y 
xcopy   Household\*.c   project\ /y


xcopy   ClearingHouse\*.h   project\ /y 
xcopy   ClearingHouse\*.c   project\ /y

xcopy    makefile  project\ /y 

xcopy   COrder\*.h   project\ /y 
xcopy   COrder\*.c   project\ /y 

xcopy   CDouble\*.h   project\ /y 
xcopy   CDouble\*.c   project\ /y 

xcopy   ClearingMechanism\*.h   project\ /y 
xcopy   ClearingMechanism\*.c   project\ /y 

xcopy   CAsset\*.h   project\ /y 
xcopy   CAsset\*.c   project\ /y 

xcopy   Belief\*.h   project\ /y 
xcopy   Belief\*.c   project\ /y 


xcopy   Eurostat\*.h   project\ /y 
xcopy   Eurostat\*.c   project\ /y

xcopy   Int\*.h   project\ /y 
xcopy   Int\*.c   project\ /y 



cd project
make
rm -f *.o
rm -f *.h
rm -f *.c