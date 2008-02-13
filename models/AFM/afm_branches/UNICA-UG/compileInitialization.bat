cd compiledInitialization
rm -f *.c
rm -f *.h
cd ..



xcopy   agents\*.h   compiledInitialization\ 
xcopy   agents\*.c   compiledInitialization\  

xcopy   Random\*.h   compiledInitialization\ /y 
xcopy   Random\*.c   compiledInitialization\ /y 
xcopy   Order\*.h   compiledInitialization\ /y 
xcopy   Order\*.c   compiledInitialization\ /y 

xcopy   Double\*.h   compiledInitialization\ /y 
xcopy   Double\*.c   compiledInitialization\ /y

xcopy   Asset\*.h   compiledInitialization\ /y 
xcopy   Asset\*.c   compiledInitialization\ /y

xcopy   Stream\*.h   compiledInitialization\ /y 
xcopy   Stream\*.c   compiledInitialization\ /y

xcopy   Portfolio\*.h   compiledInitialization\ /y 
xcopy   Portfolio\*.c   compiledInitialization\ /y

xcopy    *.h   compiledInitialization\ /y 
xcopy    *.c   compiledInitialization\ /y

xcopy   Household\*.h   compiledInitialization\ /y 
xcopy   Household\*.c   compiledInitialization\ /y


xcopy   ClearingHouse\*.h   compiledInitialization\ /y 
xcopy   ClearingHouse\*.c   compiledInitialization\ /y

xcopy    makefile  compiledInitialization\ /y 

xcopy   COrder\*.h   compiledInitialization\ /y 
xcopy   COrder\*.c   compiledInitialization\ /y 

xcopy   CDouble\*.h   compiledInitialization\ /y 
xcopy   CDouble\*.c   compiledInitialization\ /y 

xcopy   ClearingMechanism\*.h   compiledInitialization\ /y 
xcopy   ClearingMechanism\*.c   compiledInitialization\ /y 

xcopy   CAsset\*.h   compiledInitialization\ /y 
xcopy   CAsset\*.c   compiledInitialization\ /y 

xcopy   Belief\*.h   compiledInitialization\ /y 
xcopy   Belief\*.c   compiledInitialization\ /y 


xcopy   Int\*.h   compiledInitialization\ /y 
xcopy   Int\*.c   compiledInitialization\ /y 



  
xcopy  initialization\*.h   compiledInitialization\ /y
xcopy  initialization\*.c   compiledInitialization\ /y

xcopy  initialization\makefile   compiledInitialization\ /y
cd compiledInitialization
make
rm -f *.o
rm -f *.h
rm -f *.c