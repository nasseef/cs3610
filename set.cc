/**
 *   @file: set.cc
 * @author: Nasseef Abukamail
 *   @date: September 12, 2022
 *  @brief: Add Description
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

/// Constants and function prototypes

int main(int argc, char const *argv[]) {
    int data[] = {1, 8, 3, 2};
    set<int> mySet;
    mySet.insert(data, data + 4);
   
    
    for (auto it = mySet.begin(); it != mySet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    int data2 [] = {1,3,9};
    set<int> otherSet;
    otherSet.insert(data2, data2+8);

    for (auto it = otherSet.begin(); it != otherSet.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    cout << (mySet <= otherSet) << endl;

    return 0;
    //find
    auto it = mySet.find(8);
    if (it == mySet.end()) {
        cout << "not found" << endl;
    } else {
        cout << "found" << endl;
    }

    //unordered set

    unordered_set<int> mySet2;
    mySet2.insert(data, data + 4);
    mySet2.insert(9);
    mySet2.insert(9);
    mySet2.insert(10);
    mySet2.insert(5);
    mySet2.insert(6);
    for (auto it = mySet2.begin(); it != mySet2.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    

    unordered_multiset<int> mySet3;
    mySet3.insert(data, data + 4);
    mySet3.insert(9);
    mySet3.insert(9);
    mySet3.insert(10);
    mySet3.insert(5);
    mySet3.insert(6);
    for (auto it = mySet3.begin(); it != mySet3.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}  /// main