#include "utils.h"

// credit: uvts_cvs's reply at
// http://stackoverflow.com/questions/392981/how-can-i-convert-string-to-double-in-c
float string_to_float(string str) {
    istringstream i(str);
    float val;
    
    if(!(i >> val)) {
        return 0;
    }

    return val;
}

float string_to_int(string str) {
    istringstream i(str);
    int val;
    
    if(!(i >> val)) {
        return 0;
    }

    return val;
}

// beautiful split function by 
// credit: http://stackoverflow.com/a/236803/511707
vector<string> &split(const string &str, 
                      char delimiter, 
                      vector<string> &elems) {
    stringstream ss(str);
    string item;
    while(getline(ss, item, delimiter)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &str, char delimiter) {
    vector<string> elems;
    split(str, delimiter, elems);
    return elems;
}

