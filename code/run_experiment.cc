#include "utils.h"
#include "BayesianClassifier.h"
#include "Domain.h"

using namespace std;

int main(int argc, char *argv[]) {

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

    // argv[1] is the training data file
    BayesianClassifier classifier(argv[1], domains);
    
    // argv[2] is the testing data file
    ifstream inputFile(argv[2]);

    vector<float> input;
    vector<string> tokens;
    string line;
    float class_label = -1;
	while(!inputFile.eof()) {
        getline(inputFile, line);
        if(line.empty()) {
            continue;
        }

        tokens = split(line, ' ');

		for(unsigned int i = 0; i < tokens.size() - 1; i++) {
            input.push_back(string_to_float(tokens[i]));
		}
        class_label = string_to_float(tokens[tokens.size() - 1]);

        cout << "Input: ";
        for(unsigned int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << "Class label: " << class_label << endl;

        // Reset the variables.
        input.clear();
        class_label = -1;
	}
	inputFile.close();

    exit(1);



    // class: yes
    input.push_back(0.0);
    input.push_back(3.0);
    input.push_back(0.0);
    input.push_back(5.0);
    input.push_back(0.0);
    input.push_back(0.0);
    input.push_back(0.0);
    input.push_back(1.0);
    input.push_back(2.5);
    input.push_back(3.5);
    input.push_back(0.0);
    input.push_back(0.0);
    input.push_back(2.0);

    cout << "The probability of the output 1.0 given the input: " 
         << classifier.calculateProbabilityOfOutput(input, 1.0) << endl;
    cout << "The probability of the output 0.0 given the input: " 
         << classifier.calculateProbabilityOfOutput(input, 0.0) << endl;    

    return 1;
}

