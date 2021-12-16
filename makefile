CC = gcc
CFLAGS = -Wall
TARGET = main.o string_prog.o string_prog.h

mains: main.o libprogstring.a
	$(CC) $(CFLAGS) -g -o stringProg main.o ./libprogstring.a -lm
all: mains

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -lm

my_math.o: string_prog.c string_prog.h
	$(CC) $(CFLAGS) string_prog.c -lm

libprogstring.a: $(TARGET)
	ar -rcs libprogstring.a string_prog.o

clean: 
	rm -f *.o *.a stringProgram
