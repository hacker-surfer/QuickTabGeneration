//  tools.hpp

#ifndef tools_hpp
#define tools_hpp

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

namespace tools_namespace
{
    string getString(string prompt);
    bool getBool(string prompt);
    void new_line_problem_solver(string &str);
    void pull_vec_into_temp_vec(vector<string>&org_vec, vector<string>&temp_vec);
    void output_vec(vector<string> vec);
}

#endif
