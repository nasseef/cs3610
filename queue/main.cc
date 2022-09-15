/**
 *   @file: main.cc
 * @author: Nasseef Abukamail
 *   @date: September 12, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "queue.h"
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    Queue <string> myQ;
    myQ.push("Bob");
    myQ.push("Jim");
    myQ.push("Ed");
    myQ.push("John");
    
    for (size_t i = 0; i < 4; i++)
    {
        cout << "front of the queue: " << myQ.pop() << endl;
        cout << "Size of queue: " << myQ.size() << endl;
    }
    
    return 0;
} /// main