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
    domains.push_back(Domain(-5.0, 8.0, 15)); // [-5, 8]
    domains.push_back(Domain(-5.0, 8.0, 15)); // [-5, 8]
    // The ouput domain
    domains.push_back(Domain(0.0, 1.0, 2)); // {0, 1}

    // argv[1] is the training data file
    BayesianClassifier classifier(argv[1], domains);
    
    // argv[2] is the testing data file
    ifstream inputFile(argv[2]);

    vector<float> input;
    float class_label = -1;
    int numberOfTestingInputs = 0;
        
    int TP = 0;
    int FP = 0;
    int TN = 0;
    int FN = 0;
    
    vector<string> tokens;
    string line;
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
    

        float prob_class_yes = classifier.calculateProbabilityOfOutput(input, 1.0);
        float prob_class_no = classifier.calculateProbabilityOfOutput(input, 0.0);
    
        cout << "The probability of the output 1.0 given the input: " 
             << prob_class_yes << endl;
        cout << "The probability of the output 0.0 given the input: " 
             << prob_class_no << endl << endl; 

        if(prob_class_yes >= prob_class_no) {
            if(class_label == 1.0) {
                TP++;
            }
            else {
                FP++;
            }
        }
        else {
            if(class_label == 1.0) {
                FN++;
            }
            else {
                TN++;
            }
        }

        // Reset the variables.
        input.clear();
        class_label = -1;

        numberOfTestingInputs++;
	}
	inputFile.close();

    float precision = (float) TP / (float) (TP + FP);
    float recall = (float) TP / (float) (TP + FN);
    float accuracy = (float) (TP + TN) / (float) (numberOfTestingInputs);

    cout << "Precision: " << precision << endl;
    cout << "Recall: " << recall << endl;
    cout << "Accuracy: " << accuracy << endl;

    return 1;
}


