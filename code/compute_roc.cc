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
    
    vector<string> tokens;
    string line;

    vector<float> thresholds;
    vector<int> order;
    ifstream thresholdFile( "threshold" );
	while(!thresholdFile.eof()) {
        getline(thresholdFile, line);
        if(line.empty()) {
            continue;
        }

        tokens = split(line, '\t');

        thresholds.push_back( string_to_float( tokens[0] ) );
        order.push_back( string_to_int( tokens[1] ) );
    }
	thresholdFile.close();

    vector< vector<float> > vInput;
    vector<float> class_label;
    int numberOfTestingInputs = 0;
        
    int TP = 0;
    int FP = 0;
    int TN = 0;
    int FN = 0;
    
    int count = 0;
	while(!inputFile.eof()) {
        vector<float> input;

        getline(inputFile, line);
        if(line.empty()) {
            continue;
        }

        tokens = split(line, ' ');

		for(unsigned int i = 0; i < tokens.size() - 1; i++) {
            input.push_back(string_to_float(tokens[i]));
		}
        vInput.push_back( input );
        class_label.push_back(string_to_float(tokens[tokens.size() - 1]));
    }
	inputFile.close();

    for(unsigned int thresholdIndex = 0; thresholdIndex < thresholds.size(); thresholdIndex++ ) {
        for(unsigned int i = 0; i < order.size(); i++ ) {

            float prob_class_yes = classifier.calculateProbabilityOfOutput(vInput[ order[i] ], 1.0);
            float prob_class_no = classifier.calculateProbabilityOfOutput(vInput[ order[i] ], 0.0);
        
            //cout << "The probability of the output 1.0 given the input: " 
            //     << prob_class_yes << endl;
            //cout << "The probability of the output 0.0 given the input: " 
            //     << prob_class_no << endl << endl; 
            //cout << prob_class_yes << "\t" << count << endl;
            count++;

            if(prob_class_yes >= thresholds[ thresholdIndex ]) {
                if(class_label[ order[i] ] == 1.0) {
                    TP++;
                }
                else {
                    FP++;
                }
            }
            else {
                if(class_label[ order[i] ] == 1.0) {
                    FN++;
                }
                else {
                    TN++;
                }
            }

            numberOfTestingInputs++;
        }

/*
        float precision = (float) TP / (float) (TP + FP);
        float recall = (float) TP / (float) (TP + FN);
        float accuracy = (float) (TP + TN) / (float) (numberOfTestingInputs);

        cout << "Precision: " << precision << endl;
        cout << "Recall: " << recall << endl;
        cout << "Accuracy: " << accuracy << endl;
*/
        float TPR = (float) TP / ( float ) ( TP + FN );
        float FPR = (float) FP / ( float ) ( FP + TN );

        cout << TPR << "\t" << FPR << endl;
    }

    return 1;
}


