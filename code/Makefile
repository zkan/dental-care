#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = g++ $(CFLAGS)
PROG = prog 
all: $(PROG)

preprocessing.o: preprocessing.cc preprocessing.h
	$(CC) -c preprocessing.cc

main.o: main.cc preprocessing.h
	$(CC) -c main.cc

prog: main.o preprocessing.o 
	$(CC) main.o preprocessing.o -o prog

clean:
	rm *.o $(PROG)







