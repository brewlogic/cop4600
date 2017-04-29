
CC=gcc

all: ex1

ex1: bar.o main.o
  $(CC) bar.o main.o -o ex1

bar.o: bar.h bar.c
  $(CC) -c bar.c

main.o: main.c bar.h
  $(CC) -c main.c

clean:
  rm -f ex1 *.o
