/**
 *   @file: fact.cc
 * @author: Nasseef Abukamail
 *   @date: August 29, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes
int fact(int n);
int main(int argc, char const *argv[]) {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int factorial = fact(n);
    cout << "Factorial: " << factorial << endl;
    return 0;
} /// main

int fact(int n){
    if (n == 0) //base case
    {
        return 1;
    }
    else {
        return n * fact(n - 1); //rule
    }
    
}