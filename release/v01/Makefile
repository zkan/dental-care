#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = g++ $(CFLAGS)
PROG = prog 
all: $(PROG)

Domain.o: Domain.cc Domain.h
	$(CC) -c Domain.cc

BayesianClassifier.o: BayesianClassifier.cc BayesianClassifier.h Domain.h
	$(CC) -c BayesianClassifier.cc

main.o: main.cc Domain.h BayesianClassifier.h
	$(CC) -c main.cc

prog: main.o Domain.o BayesianClassifier.o
	$(CC) main.o Domain.o BayesianClassifier.o -o prog

clean:
	rm *.o $(PROG)







