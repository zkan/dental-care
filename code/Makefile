#
#   Author: Kan Ouivirach
# 
CFLAGS = -g -Wall
CC = g++ $(CFLAGS)
PROG = prog run_experiment compute_roc
all: $(PROG)

preprocessing.o: preprocessing.cc preprocessing.h
	$(CC) -c preprocessing.cc

utils.o: utils.cc utils.h
	$(CC) -c utils.cc

Domain.o: Domain.cc Domain.h
	$(CC) -c Domain.cc

BayesianClassifier.o: BayesianClassifier.cc BayesianClassifier.h utils.h
	$(CC) -c BayesianClassifier.cc

main.o: main.cc preprocessing.h Domain.h BayesianClassifier.h
	$(CC) -c main.cc

prog: main.o preprocessing.o Domain.o BayesianClassifier.o utils.o
	$(CC) main.o preprocessing.o Domain.o BayesianClassifier.o utils.o -o prog

run_experiment.o: run_experiment.cc utils.h Domain.h BayesianClassifier.h
	$(CC) -c run_experiment.cc

run_experiment: run_experiment.o utils.o Domain.o BayesianClassifier.o
	$(CC) run_experiment.o utils.o Domain.o BayesianClassifier.o -o run_experiment

compute_roc: compute_roc.o utils.o Domain.o BayesianClassifier.o
	$(CC) compute_roc.o utils.o Domain.o BayesianClassifier.o -o compute_roc

clean:
	rm *.o $(PROG)







