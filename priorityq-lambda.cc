/**
 *   @file: priorityq-lambda.cc
 * @author: Nasseef Abukamail
 *   @date: November 02, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <queue>
using namespace std;

///Constants and function prototypes

int main(int argc, char const *argv[]) {

    //declare a lambda function
    //function<bool (pair<int, string>, pair<int, string>)> f = [&](pair<int, string> a, pair<int, string> b) { return a.first > b.first; };
    auto f = [](pair<int, string> a, pair<int, string> b) ->bool { return a.first > b.first; };
    cout << f(pair<int, string>(4, "bob"), pair<int, string>(5, "B")) << endl;

    
    //using the f function
   
    //cout << f(pair<int, string>(8, "Bob"), pair<int, string>(5, "Jim")) << endl;

    //lambda functions as objects don't have a default constructor. It needs to be passed
    //to the constructor for the priority queue (q(f)) below.
    priority_queue <pair<int, string>, vector<pair<int, string>>, decltype(f)> q(f);

    q.push(pair<int, string>(9, "B"));
    q.push(pair<int, string>(4, "A"));
    q.push(pair<int, string>(2, "C"));
    q.push(pair<int, string>(8, "E"));
    q.push(pair<int, string>(7, "F"));
    q.push(pair<int, string>(1, "D"));
    
    while (!q.empty()) {
        cout << q.top().first << " " << q.top().second << " ";
        q.pop();
    }
    cout << endl;
    return 0;
} /// main