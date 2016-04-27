// main.cpp

#include "tools.hpp"
#include "tab_gen.hpp"
#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    cout << "\t------------ TAB GENERATION ------------" << endl << endl;
    
    cout << ">> BEGIN INSTRUCTIONS" << endl << endl;
    cout << "\t- Open Excel Sheet." << endl;
    cout << "\t- Row A must be desired tab names." << endl;
    cout << "\t- Row B must be \"$$$\" next to EVERY tab name" << endl;
    cout << "\t- Save as tab_delim txt." << endl;
    cout << "\t- Make sure txt file is in same location as this exe" << endl << endl << endl;
    
    tab_gen_namespace::interface();
    
    bool all_done_or_not = tools_namespace::getBool("All done? ");
    if(all_done_or_not == true)  return 0;
    else tab_gen_namespace::interface();
}