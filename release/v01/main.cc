#include "BayesianClassifier.h"
#include "Domain.h"

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

    BayesianClassifier classifier("data/preprocessed_training", domains);

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
}

int main(int argc, char *argv[]) {

    testBayesianClassifier();

    return 1;
}

