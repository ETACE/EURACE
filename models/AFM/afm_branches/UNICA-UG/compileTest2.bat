cd compiledTests
rm -f *.c
rm -f *.h
cd ..



xcopy   agents\*.h   compiledtests\ 
xcopy   agents\*.c   compiledtests\  

xcopy   Random\*.h   compiledtests\ /y 
xcopy   Random\*.c   compiledtests\ /y 
xcopy   Order\*.h   compiledtests\ /y 
xcopy   Order\*.c   compiledtests\ /y 

xcopy   Double\*.h   compiledtests\ /y 
xcopy   Double\*.c   compiledtests\ /y

xcopy   Asset\*.h   compiledtests\ /y 
xcopy   Asset\*.c   compiledtests\ /y

xcopy   Stream\*.h   compiledtests\ /y 
xcopy   Stream\*.c   compiledtests\ /y

xcopy   Portfolio\*.h   compiledtests\ /y 
xcopy   Portfolio\*.c   compiledtests\ /y

xcopy    *.h   compiledtests\ /y 
xcopy    *.c   compiledtests\ /y

xcopy   Household\*.h   compiledtests\ /y 
xcopy   Household\*.c   compiledtests\ /y


xcopy   ClearingHouse\*.h   compiledtests\ /y 
xcopy   ClearingHouse\*.c   compiledtests\ /y

xcopy    makefile  compiledtests\ /y 

xcopy   COrder\*.h   compiledtests\ /y 
xcopy   COrder\*.c   compiledtests\ /y 

xcopy   CDouble\*.h   compiledtests\ /y 
xcopy   CDouble\*.c   compiledtests\ /y 

xcopy   ClearingMechanism\*.h   compiledtests\ /y 
xcopy   ClearingMechanism\*.c   compiledtests\ /y 

xcopy   CAsset\*.h   compiledtests\ /y 
xcopy   CAsset\*.c   compiledtests\ /y 

xcopy   Belief\*.h   compiledtests\ /y 
xcopy   Belief\*.c   compiledtests\ /y 


xcopy   Int\*.h   compiledtests\ /y 
xcopy   Int\*.c   compiledtests\ /y 



  
xcopy  tests2\*.h   compiledtests\ /y
xcopy  tests2\*.c   compiledtests\ /y

xcopy  tests2\makefile   compiledtests\ /y
cd compiledTests
make
rm -f *.o
rm -f *.h
rm -f *.c