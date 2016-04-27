//  tools.cpp

#include "tools.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

namespace tools_namespace
{
    string getString(string prompt)
    {
        cout << prompt;
        string answer;
        cin >> answer;
        return answer;
    }
    
    bool getBool(string prompt)
    {
        cout << prompt;
        char input;
        cin >> input;
        
        if(input == 'y' || input == 'Y') return true;
        else if(input == 'n' || input == 'N') return false;
        else
        {
            cout << "bad input. try again." << endl << endl;
            return getBool(prompt);
        }
    }
    
    void new_line_problem_solver(string &str)
    {
        while(str[0] != 'z' && str[0] != 'x' && str[0] != 'c' && str[0] != 'v' && str[0] != 'b' && str[0] != 'n' && str[0] != 'm' && str[0] != 'a' && str[0] != 's' && str[0] != 'd' && str[0] != 'f' && str[0] != 'g' && str[0] != 'h' && str[0] != 'j' && str[0] != 'k' && str[0] != 'l' && str[0] != 'q' && str[0] != 'w' && str[0] != 'e' && str[0] != 'r' && str[0] != 't' && str[0] != 'y' && str[0] != 'u' && str[0] != 'i' && str[0] != 'o' && str[0] != 'p' && str[0] != '1' && str[0] != '2' && str[0] != '3' && str[0] != '4' && str[0] != '5' && str[0] != '6' && str[0] != '7' && str[0] != '8' && str[0] != '9' && str[0] != '0' && str[0] != 'Z' && str[0] != 'X' && str[0] != 'C' && str[0] != 'V' && str[0] != 'B' && str[0] != 'N' && str[0] != 'M' && str[0] != 'A' && str[0] != 'S' && str[0] != 'D' && str[0] != 'F' && str[0] != 'G' && str[0] != 'H' && str[0] != 'J' && str[0] != 'K' && str[0] != 'L' && str[0] != 'Q' && str[0] != 'W' && str[0] != 'E' && str[0] != 'R' && str[0] != 'T' && str[0] != 'Y' && str[0] != 'U' && str[0] != 'I' && str[0] != 'O' && str[0] != 'P')
        {
            str = str.substr(1, str.length());
        }
    }
    
    void pull_vec_into_temp_vec(vector<string>&org_vec, vector<string>&temp_vec)
    {
        for(int x = 0; x < org_vec.size(); ++x)
        {
            temp_vec.push_back(org_vec[x]);
        }
        org_vec.clear();
    }
    
    void output_vec(vector<string> vec)
    {
        for(int x = 0; x < vec.size(); ++x)
        {
            cout << x << ": " << vec[x] << endl;
        }
    }
}













