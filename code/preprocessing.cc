#include "preprocessing.h"

Preprocessing::Preprocessing() {
}

Preprocessing::~Preprocessing() {
}

// credit: uvts_cvs's reply at
// http://stackoverflow.com/questions/392981/how-can-i-convert-string-to-double-in-c
double Preprocessing::string_to_double(string str) {
    istringstream i(str);
    double val;
    
    if(!(i >> val)) {
        return 0;
    }

    return val;
}

// beautiful split function by 
// credit: http://stackoverflow.com/a/236803/511707
vector<string> &Preprocessing::split(const string &str, 
                                     char delimiter, 
                                     vector<string> &elems) {
    stringstream ss(str);
    string item;
    while(getline(ss, item, delimiter)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> Preprocessing::split(const string &str, char delimiter) {
    vector<string> elems;
    split(str, delimiter, elems);
    return elems;
}

/*
void Preprocessing::print_min_max_for_each_column() {
    // for each column
    for(unsigned int j = 0; j < this->_data[0].size(); j++) {
        float min = 10000;
        float max = -10000;
        cout << "Column: " << j << endl;
        for(unsigned int i = 0; i < this->_data.size(); i++) {
            if((float) this->_data[i][j] > max) {
                max = (float) this->_data[i][j];
            }
            if((float) this->_data[i][j] < min) {
                min = (float) this->_data[i][j];
            }
        }
        cout << "Min: " << min << endl;
        cout << "Max: " << max << endl;
    }
}
*/

void Preprocessing::print_training_data(bool ignore_missing_data) {
    for(unsigned int i = 0; i < this->_data.size(); i++) {
        if(ignore_missing_data) {
            bool is_missing_data = false;
            for(unsigned int j = 0; j < this->_data[i].size(); j++) {
                if(this->_data[i][j].compare("?") == 0) {
                    is_missing_data = true;
                    break;
                }
            }
            if(is_missing_data) {
                continue;
            }
        }
        for(unsigned int j = 0; j < this->_data[i].size(); j++) {
            cout << this->_data[i][j]; 
            if(j != this->_data[i].size() - 1) {
                cout << " ";
            }
        }
        cout << " " << this->_class[i] << endl;
    }
}

void Preprocessing::read_training_data(char* file_data) {
    ifstream ifile;
    ifile.open(file_data);

    vector<string> tokens;
    vector<string> val;
    string line;
    while(!ifile.eof()) {
        getline(ifile, line);
        // skip an empty line
        if(line.empty()) {
            continue;
        }
        
        // split the data into tokens
        tokens = split(line, ',');

        // first to second last column are data Xi
        for(unsigned int i = 0; i < tokens.size() - 1; i++) {
            if(tokens[i].compare("") == 0) {
                tokens[i] = "?";
            }
            val.push_back(tokens[i]);
        }
        this->_data.push_back(val);

        // last column is the predicted data y
        //this->_class.push_back(string_to_double(tokens[tokens.size() - 1]));
        this->_class.push_back(tokens[tokens.size() - 1]);

        val.clear();
    }
}
/*
void Preprocessing::normalize() {
    // initialize the mean and std vectors
    for(unsigned int i = 0; i < this->_data[0].size(); i++) {
        this->_mean.push_back(0);
        this->_std.push_back(0);
    }

    // compute mean and std (both have same vector size)
    unsigned int N = this->_data.size();
    for(unsigned int i = 0; i < this->_data.size(); i++) {
        for(unsigned int j = 0; j < this->_data[i].size(); j++) {
            this->_mean[j] += this->_data[i][j];
            this->_std[j] += this->_data[i][j] * this->_data[i][j];
        }
    }
    for(unsigned int i = 0; i < this->_mean.size(); i++) {
        this->_mean[i] = this->_mean[i] / N;
        this->_std[i] = sqrt((this->_std[i] / N) - (this->_mean[i] * this->_mean[i]));
    }

    for(unsigned int i = 0; i < this->_data.size(); i++) {
        // normalize all except the first column (the first column is used for theta_0)
        for(unsigned int j = 1; j < this->_data[i].size(); j++) {
            this->_data[i][j] = (this->_data[i][j] - this->_mean[j]) / this->_std[j];
        }
    }

}
*/
vector< vector<string> > Preprocessing::get_data() {
    return this->_data;
}

string Preprocessing::get_corresponding_class(int index) {
    return this->_class[index];
}

vector<double> Preprocessing::get_mean_vector() {
    return this->_mean;
}

vector<double> Preprocessing::get_std_vector() {
    return this->_std;
}

void Preprocessing::fill_best_guess_value() {
    // store the class name in set
    set<string> data_class_set;
    set<string>::iterator it_set;
    for(unsigned int i = 0; i < this->_class.size(); i++) {
        data_class_set.insert(this->_class[i]);
    }

    // for each class, find the most frequent item
    for(it_set = data_class_set.begin(); 
        it_set != data_class_set.end(); 
        ++it_set) {

//        cout << "Class: " << *it_set << endl;

        // for each attribute, fill the best guess value in
        for(unsigned int col_index = 0; 
                         col_index < this->_data[0].size(); 
                         col_index++) {
            string most_freq_item = get_most_frequent_item(col_index, *it_set);
//            cout << "Most frequent item for attribute " 
//                 << col_index << ": " 
//                 << most_freq_item << endl;

            replace_missing_value_with_most_freq_item(col_index, 
                                                      *it_set, 
                                                      most_freq_item);
        }
    }
}

void Preprocessing::replace_missing_value_with_most_freq_item(int index, 
                                                              string data_class, 
                                                              string most_freq_item) {
    for(unsigned int i = 0; i < this->_data.size(); i++) {
        if(this->_class[i].compare(data_class) == 0) {
            // find the missing value
            if(this->_data[i][index].compare("?") == 0) {
                this->_data[i][index] = most_freq_item;
            }
        }
    }
}

string Preprocessing::get_most_frequent_item(int index, string data_class) {
    map<string, int> data_freq_map;
    map<string, int>::iterator it;
    for(unsigned int i = 0; i < this->_data.size(); i++) {
        if(this->_class[i].compare(data_class) == 0) {
            // skip the missing value
            if(this->_data[i][index].compare("?") != 0) {
                it = data_freq_map.find(this->_data[i][index]);
                if(it == data_freq_map.end()) {
                    data_freq_map[this->_data[i][index]] = 1;
                }
                else {
                    data_freq_map[this->_data[i][index]] += 1; 
                }
            }
        }
    }

    string most_freq_item;
    int max = -1;

    for(it = data_freq_map.begin(); it != data_freq_map.end(); ++it) {
//        cout << it->first << " => " << it->second << endl;
        if(it->second > max) {
            max = it->second;
            most_freq_item = it->first;
        }
    }

    return most_freq_item;
}

/*
void Preprocessing::write_preprocessed_training_data() {
    for(unsigned int i = 0; i < this->_data.size(); i++) {
    }
}
*/





