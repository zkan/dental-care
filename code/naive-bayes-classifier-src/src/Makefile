CFLAGS = -g -Wall
CC = g++ $(CFLAGS)
PROG = naive
all: $(PROG)

Domain.o: Domain.cpp Domain.h
	$(CC) -c Domain.cpp

BayesianClassifier.o: BayesianClassifier.cpp BayesianClassifier.h Domain.h
	$(CC) -c BayesianClassifier.cpp

Main.o: Main.cpp BayesianClassifier.h Domain.h
	$(CC) -c Main.cpp

naive: BayesianClassifier.o Domain.o Main.o 
	$(CC) BayesianClassifier.o Domain.o Main.o -o naive

clean:
	rm *.o $(PROG)







