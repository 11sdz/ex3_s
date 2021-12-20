CC = gcc
CFLAGS = -Wall
TARGET = main.o string_prog.o string_prog.h

all: stringProg

stringProg: string_prog.o main.o
	gcc -g -Wall -o stringProg string_prog.o main.o

string_prog.o: string_prog.c string_prog.h
	gcc -c -g -Wall string_prog.c string_prog.h

main.o: main.c string_prog.h
	gcc -c -g -Wall main.c string_prog.h

PHONY: clean all

clean:
	rm -f *.o stringProg 