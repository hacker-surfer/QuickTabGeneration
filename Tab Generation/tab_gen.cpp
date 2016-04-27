//  tab_gen.cpp

#include "tab_gen.hpp"
#include "cpp_template.h"
#include "tools.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace tab_gen_namespace
{
    void interface(void)
    {
        vector<string> tabs_vec;
        vector<string> file_locs;
        string template_str = template_namespace::template_str();
        
        cout << ">> USER INPUT COLLECTION" << endl << endl;
        cout << "\t1.) Enter file name" << endl;
        cout << "\t2.) Enter \'m\' to manually input tab names into this console," << endl;
        cout << "\t3.) Enter \'f\' to insert first ten DSPG default tabs" << endl << endl << endl;
        string file_name = tools_namespace::getString(">> Input file name here: ");
        cout << endl;
        
        if (file_name == "f" || file_name == "F") enter_first_ten(tabs_vec, file_name);
        if (file_name == "m" || file_name == "M") manul_user_entry(tabs_vec);
        else pull_tab_names(tabs_vec, file_name);
        
        general_format(tabs_vec);
        insert_blank_tabs_till_div_by_5(tabs_vec);
        format_out_bad_XML_chars_and_upper_all(tabs_vec);
        slot_in_data(tabs_vec, template_str, file_locs);
        
        open_files(file_locs);
    }
    
    void enter_first_ten(vector<string>&vec, string &file_name)
    {
        vec.push_back("DRIVERSPG PROPOSAL");
        vec.push_back("DRIVERSPG ESTIMATE");
        vec.push_back("DRIVERSPG SCHEDULE");
        vec.push_back("DRIVERSPG RFP");
        vec.push_back("DRIVERSPG ADDENDA");
        
        vec.push_back("DRIVERSPG RFI");
        vec.push_back("DRIVERSPG JOBWALK NOTES/PHOTOS");
        vec.push_back("DRIVERSPG BIDLIST");
        vec.push_back("DRIVERSPG CORRESPONDENCE");
        vec.push_back("DRIVERSPG MISC. FILES/NOTES");
        
        cout << "\t-----First ten tabs added!-----" << endl << endl;
        
        cout << ">> USER INPUT COLLECTION CONTINUED" << endl << endl;
        cout << "\t1.) Enter file name" << endl;
        cout << "\t2.) enter \'m\' to manually input tab names into this console" << endl << endl << endl;
        file_name = tools_namespace::getString(">> Input file name here: ");
        cout << endl;
    }
    
    void manul_user_entry(vector<string> &vec)
    {
        string user_input;
        cout << "Enter a tab name - enter \'d\' when done: ";
        cin >> user_input;
        if(user_input != "d" && user_input != "D")
        {
            vec.push_back(user_input);
            manul_user_entry(vec);
        }
    }
    
    void pull_tab_names(vector<string> &vec, string file_name)  // pull tab names from txt
    {
        // should be universal for SBN and manual entry...
        file_name = "/users/nnelson/Documents/Work/Templates/Binder/Tab_Generation_Automatic/" + file_name;
        ifstream file1(file_name);
        char iter = '$$$';
        
        for(string token; getline(file1, token, iter); vec.push_back(token));
        
        file1.close();
        
        if(vec.size() < 1)
        {
            cout << "File didn't work. relaunching..." << endl << endl << endl;
            interface();
        }
        
        
        bool SBN_OR_NOT = tools_namespace::getBool("Is this file from SmartBidNet? ");
        if(SBN_OR_NOT == true) format_out_SBN_misc(vec);
    }
    
    void general_format(vector<string> &vec)    // new line problem and empty token solver
    {
        vector<string>temp_vec;
        tools_namespace::pull_vec_into_temp_vec(vec, temp_vec);
        
        for(int x = 0; x < temp_vec.size(); ++x)
        {
            string cur = temp_vec[x];
            if(cur.length() > 0)
            {
                tools_namespace::new_line_problem_solver(cur);
                vec.push_back(cur);
            }
        }
    }
    
    void insert_blank_tabs_till_div_by_5(vector<string>&vec)    //  make sure we hit %5 tabs
    {
        // enter blanks so that all 5 tabs can be deleted
        int num_tabs = vec.size();
        
        while(num_tabs % 5 != 0)
        {
            vec.push_back("   ");
            ++num_tabs;
        }
        
        float num_tab_sets = vec.size() / 5;
        cout << endl << endl << "\t-----Number of tab sets to throw in the printer: ";
        cout << num_tab_sets << " -----" << endl << endl;
    }
    
    void format_out_SBN_misc(vector<string> &vec)     // format out normal SBN stuff so names fit
    {
        vector<string> temp_vec;
        tools_namespace::pull_vec_into_temp_vec(vec, temp_vec);
        
        for(int iter_word = 0; iter_word < temp_vec.size(); ++iter_word)
        {
            string cur = temp_vec[iter_word];
            
            if(cur.find(" - ") != std::string::npos)
            {
                size_t loc = cur.find(" - ");
                cur = cur.substr(loc+3, cur.length());
            }
            
            if(cur.find("(") != std::string::npos)
            {
                size_t loc2 = cur.find("(");
                cur = cur.substr(0, loc2);
            }
            
            vec.push_back(cur);
        }
    }
    
    void format_out_bad_XML_chars_and_upper_all(vector<string>&vec) // safety precaution for XML
    {
        vector<string>temp_vec;
        tools_namespace::pull_vec_into_temp_vec(vec, temp_vec);
        
        for(int word_token = 0;  word_token < temp_vec.size(); ++word_token)
        {
            string cur_word = temp_vec[word_token];
            string new_str;
            for(int char_token = 0; char_token < cur_word.length(); ++char_token)
            {
                if(cur_word[char_token] == '&') new_str += "AND";
                else if(cur_word[char_token] == '<') new_str += "";
                else if(cur_word[char_token] == '>') new_str += "";
                else if(cur_word[char_token] == '\"') new_str += "";
                else if(cur_word[char_token] == '\'') new_str += "";
                else if(cur_word[char_token] == ')') new_str += "";
                else if(cur_word[char_token] == ',') new_str += "";
                else if(cur_word[char_token] == ':') new_str += "";
                else if(cur_word[char_token] == ';') new_str += "";
                else if(cur_word[char_token] == '-') new_str += " ";
                else if(cur_word[char_token] == '\t') new_str += "";
                else new_str += toupper(cur_word[char_token]);
            }
            vec.push_back(new_str);
        }
    }
    
    void slot_in_data(vector<string>vec, string str, vector<string> &file_locs)
    {
        int num_tab_sets = 1;
        int cur_tab = 1;
        string blank_template = str;
        ofstream file_output;
        
        string iter1 = "$$$T1";
        string iter2 = "$$$T2";
        string iter3 = "$$$T3";
        string iter4 = "$$$T4";
        string iter5 = "$$$T5";
        
        for(int x = 0; x < vec.size(); ++x)
        {
            string current_tab_name = vec[x];
            
            if(cur_tab == 1)slot_in_individual_tab(str, current_tab_name, iter1);
            else if(cur_tab == 2)slot_in_individual_tab(str, current_tab_name, iter2);
            else if(cur_tab == 3)slot_in_individual_tab(str, current_tab_name, iter3);
            else if(cur_tab == 4)slot_in_individual_tab(str, current_tab_name, iter4);
            else if(cur_tab == 5)
            {
                slot_in_individual_tab(str, current_tab_name, iter5);
                
                string filename = "/users/nnelson/Documents/Work/Templates/Binder/Tab_Generation_Automatic/tab_" + to_string(num_tab_sets) + ".doc";
                
                file_output.open(filename);
                file_output << str;
                file_output.close();
                
                file_locs.push_back(filename);
                
                str = blank_template;
                
                ++num_tab_sets;
                
                cur_tab = 0;
            }
            ++cur_tab;
        }
    }
    
    void slot_in_individual_tab(string &template_str, string tab, string iter)
    {
        // it is known that there are 2 of each iter.
        
        size_t loc = template_str.find(iter);
        template_str = template_str.substr(0, loc) + tab + template_str.substr(loc+iter.length(), template_str.length());
        
        if(template_str.find(iter) != std::string::npos) slot_in_individual_tab(template_str, tab, iter);
    }
    
    void open_files(vector<string> &vec)
    {
        for(int x = 0; x < vec.size(); ++x)
        {
            string command = "open " + vec[x];
            system(command.c_str());
        }
    }
}