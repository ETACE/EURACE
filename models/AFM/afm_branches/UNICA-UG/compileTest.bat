
xcopy  Int\*.h  tests\ /y
xcopy  Int\*.c  tests\ /y  
xcopy  Double\*.h  tests\ /y
xcopy  Double\*.c  tests\ /y  
xcopy  Stream\*.h   tests\ /y
xcopy  Stream\*.c   tests\ /y
xcopy  CollectionDouble\*.h   tests\ /y
xcopy  CollectionDouble\*.c   tests\ /y

xcopy  tests\makefile   tests\ /y
cd tests
make
rm -f *.o
