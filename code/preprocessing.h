/*
    Preprocessing class
    Author: Kan Ouivirach
*/
#ifndef _PREPROCESSING_H_
#define _PREPROCESSING_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <set>

using namespace std;

class Preprocessing {
    private:
        vector< vector<string> > _data;
        vector<string> _class;
        vector<double> _mean;
        vector<double> _std;
        
        double string_to_double(string str);
       
        // beautiful split function
        // credit: http://stackoverflow.com/a/236803/511707
        vector<string> &split(const string &str, 
                              char delimiter, 
                              vector<string> &elems);
        vector<string> split(const string &str, char delimiter);
        
        string get_most_frequent_item(int index, string data_class);
        void replace_missing_value_with_most_freq_item(int index, 
                                                       string data_class, 
                                                       string most_freq_item);

    public:
        Preprocessing();
        ~Preprocessing();

        void read_training_data(char* file_data);
        void print_training_data(bool ignore_missing_data);

        vector< vector<string> > get_data();
        string get_corresponding_class(int index);
        vector<double> get_mean_vector();
        vector<double> get_std_vector();

        void fill_best_guess_value();

//        void print_min_max_for_each_column();
//        void write_preprocessed_training_data();
        
//        void normalize();
};

#endif

