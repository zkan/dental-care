#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = g++ $(CFLAGS)
PROG = prog 
all: $(PROG)

preprocessing.o: preprocessing.cc preprocessing.h
	$(CC) -c preprocessing.cc

Domain.o: Domain.cc Domain.h
	$(CC) -c Domain.cc

BayesianClassifier.o: BayesianClassifier.cc BayesianClassifier.h Domain.h
	$(CC) -c BayesianClassifier.cc

main.o: main.cc preprocessing.h Domain.h BayesianClassifier.h
	$(CC) -c main.cc

prog: main.o preprocessing.o Domain.o BayesianClassifier.o
	$(CC) main.o preprocessing.o Domain.o BayesianClassifier.o -o prog

clean:
	rm *.o $(PROG)







