#include "preprocessing.h"
#include "BayesianClassifier.h"
#include "Domain.h"

//#define PREPROCESSING

using namespace std;

void testBayesianClassifier() {
    int errors = 0;

    vector<Domain> domains;

    // The input domains
    domains.push_back(Domain(0.0, 3.0, 4)); // [0, 3]
    domains.push_back(Domain(0.0, 6.0, 7)); // [0, 6]
    domains.push_back(Domain(0.0, 4.0, 5)); // [0, 4]
    domains.push_back(Domain(0.0, 5.0, 6)); // [0, 5]
    domains.push_back(Domain(0.0, 2.0, 3)); // [0, 2]
    domains.push_back(Domain(0.0, 3.0, 4)); // [0, 3]
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}
    domains.push_back(Domain(0.0, 7.0, 8)); // [0, 7]
    domains.push_back(Domain(0.0, 4.0, 5)); // [0, 4]
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}
    domains.push_back(Domain(0.0, 2.0, 3)); // {0, 1, 2}
    // The ouput domain
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}

    BayesianClassifier classifier("../data/input/preprocessed_training", domains);

    // It is possible to not give any data and add it later
    // BayesianClassifier classifier(domains);

    vector<float> input1;

/*
    // class: yes
    input1.push_back(0.0);
    input1.push_back(3.0);
    input1.push_back(0.0);
    input1.push_back(5.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(1.0);
    input1.push_back(2.5);
    input1.push_back(3.5);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(2.0);
//*/

//*
    // class: yes
    input1.push_back(1.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(1.0);
    input1.push_back(0.0);
    input1.push_back(3.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(3.5);
    input1.push_back(3.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
//*/

/*
    // class: no
    input1.push_back(0.0);
    input1.push_back(1.5);
    input1.push_back(2.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
    input1.push_back(0.0);
//*/

    cout << "The probability of the output 1.0 given the input: " 
         << classifier.calculateProbabilityOfOutput(input1, 1.0) << endl;
    cout << "The probability of the output 0.0 given the input: " 
         << classifier.calculateProbabilityOfOutput(input1, 0.0) << endl;
    
/*
	// Calculates the probability of obtaining the output 0.0 given the input (1.0, 2.0)
	if(classifier.calculateProbabilityOfOutput(input1, 0.0) != 0.5) {
		cout << "The probability should be 0.5" << endl;
		errors++;
	}
*/
	
/*
	// Updates the classifier with new values (1.0, 2.0, 0.0)
	classifier.addRawTrainingData("data/newBayesianClassifierValues.txt");
	
	if(classifier.calculateProbabilityOfOutput(input1, 0.0) <= 0.727272 || classifier.calculateProbabilityOfOutput(input1, 0.0) >= 0.727274) {
		cout << "The probability should be 0.727273" << endl;
		errors++;
	}
	
	// The most probable output should be 0.0 given the input (1.0, 2.0)
	if (classifier.calculateOutput(input1) != 0.0) {
		cout << "The output should be 0.0" << endl;
		errors++;
	}
*/

/*
	vector<float> newRawTrainingData;
	
	newRawTrainingData.push_back(1.0);
	newRawTrainingData.push_back(2.0);
	newRawTrainingData.push_back(1.0);
	
	classifier.addRawTrainingData(newRawTrainingData);

	if(classifier.calculateProbabilityOfOutput(input1, 0.0) <= 0.49 || classifier.calculateProbabilityOfOutput(input1, 0.0) >= 0.51) {
		cout << "The probability should be 0.5" << endl;
		errors++;
	}
	
	if (errors == 0) {
		cout << "TestBayesianClassifier passed" << endl;
	}
*/
}

int main(int argc, char *argv[]) {

#ifdef PREPROCESSING
    Preprocessing *p = new Preprocessing();
    p->read_training_data("../data/input/training");
    p->fill_best_guess_value();
    p->print_training_data(false);
    delete p;
#endif

    testBayesianClassifier();

    return 1;
}

