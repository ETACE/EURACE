gcc -D_DEBUG_MODE -g -I../../libmboard/include -L../../libmboard/lib unittest.c ../../memory.c ../../messageboards.c ../../my_library_functions.c ../Firm_Financial_Management_Functions.c Firm_Financial_Management_unittests.c -lm -lcunit -lmboard_s