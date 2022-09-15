/**
 *   @file: m-backup.cc
 * @author: Nasseef Abukamail
 *   @date: September 12, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
//#include <utility>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {
    map<string, int> dictionary;

    dictionary.insert(make_pair("number", 50));
    dictionary.insert(make_pair("rate", 15));
    dictionary.insert(make_pair("age", 22));
    dictionary.insert(make_pair("age", 24));
    //dictionary.erase("number");
    cout << dictionary["rate"] << endl;
    dictionary["x"] = 9;

    for (auto it = dictionary.begin(); it != dictionary.end(); it++)
    {
        cout << "(" << it->first << ", " << it->second << ")" << endl;
    }
   
    
    auto it = dictionary.begin();
    pair<string, int> p = *it;

    cout << p.second << endl;
    return 0;
} /// main