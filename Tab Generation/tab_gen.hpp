//  tab_gen.hpp

#ifndef tab_gen_hpp
#define tab_gen_hpp

#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace tab_gen_namespace
{
    void interface(void);
    
    void enter_first_ten(vector<string>&vec,
                         string &file_name);
    
    void manul_user_entry(vector<string> &vec);
    
    void pull_tab_names(vector<string> &vec,
                        string file_name);
    
    void general_format(vector<string> &vec);
    
    void insert_blank_tabs_till_div_by_5(vector<string>&vec);
    
    void format_out_SBN_misc(vector<string> &vec);
    
    void format_out_bad_XML_chars_and_upper_all(vector<string>&vec);
    
    void slot_in_data(vector<string>vec,
                      string str,
                      vector<string>&file_locs);
    
    void slot_in_individual_tab(string &template_str,
                                string tab,
                                string iter);
    
    void open_files(vector<string> &vec);
}

#endif

