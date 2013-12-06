#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <math.h>

using namespace std;

float string_to_float(string str);
float string_to_int(string str);
       
// beautiful split function
// credit: http://stackoverflow.com/a/236803/511707
vector<string> &split(const string &str, 
                      char delimiter, 
                      vector<string> &elems);
vector<string> split(const string &str, char delimiter);

#endif
