# Makefile for cloning code
#

CC=gcc
M_CC=mpicc
CFLAGS=-g -std=c99 -Wall -pedantic
LDFLAGS=

serial: clone_serial.o clone.o
	$(CC) -o clone_serial $(LDFLAGS) clone_serial.o clone.o

parallel: clone_parallel.o clone.o
	$(M_CC) -o clone_parallel $(LDFLAGS) clone_parallel.o clone.o

clone_serial.o: clone_serial.c
	$(CC) -c $(CFLAGS) clone_serial.c

clone_parallel.o: clone_parallel.c
	$(M_CC) -c $(CFLAGS) clone_parallel.c

clone.o: clone.c
	$(CC) -c $(CFLAGS) clone.c

clean:
	rm -f clone_serial clone_parallel *.o
