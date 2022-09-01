/**
 *   @file: dec2bin.cc
 * @author: Nasseef Abukamail
 *   @date: August 31, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

///Constants and function prototypes

string decToBase(int num, int base);
int countEven(int numbers[], int size);
int main(int argc, char const *argv[]) {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << n << " in binary: " << decToBase(n, 8) << endl;
    int numbers[] = {2, 5, 6, 6, 7, 9, 1, 2, 4};
    cout << "Even numbers: " << countEven(numbers, 9) << endl;
    return 0;
} /// main

string decToBase(int num, int base){
    if (num < base)
    {
        return to_string(num);
    }
    return decToBase(num / base, base) + to_string(num % base);
}

int countEven(int numbers[], int size){
    if (size == 0)
    {
        return 0;
    }
    else if(numbers[size - 1] % 2 == 0){
        return 1 + countEven(numbers, size - 1);
    }
    return countEven(numbers, size - 1);
}