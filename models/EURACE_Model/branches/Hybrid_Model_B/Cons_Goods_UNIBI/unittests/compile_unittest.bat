gcc -g -I../../libmboard/include -L../../libmboard/lib unittest.c ../../memory.c ../../messageboards.c ../Mall_Functions.c ../Mall_aux_functions.c Mall_unittests.c -lm -lcunit -lmboard_s 