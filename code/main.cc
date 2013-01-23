#include "preprocessing.h"

using namespace std;

int main(int argc, char *argv[]) {
    
    Preprocessing *p = new Preprocessing();
    p->read_training_data("../data/input/training");
    p->print_training_data(true);

    p->fill_best_guess_value();

//    vector< vector<string> > data = p->get_data();
//    cout << "Data size: " << data.size() << endl;
//    for(unsigned int i = 0; i < data.size(); i++) {
//        cout << p->get_corresponding_class(i) << endl;
//    }

    delete p;

    return 1;
}

