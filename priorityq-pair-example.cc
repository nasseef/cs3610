/**
 *   @file: priorityq-pair.cc
 * @author: Nasseef Abukamail
 *   @date: October 31, 2022
 *  @brief: Priority Queue examples using the C++ built-in priority_queue with other built-in objects(pair)
 *          Examples:
 *              -- Min/Max heap using a pair object. Where the comparison operator is provided as a function
 *                 object (functor)
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
class Compare{
public:
    bool operator() (pair<int, string> a, pair<int, string> b)
    {
        return a.first > b.first;
    }
};
///Constants and function prototypes

int main(int argc, char const *argv[]) {
    //using Compare as an object of type function
    Compare f;
    cout << f(pair<int, string>(7, "B"), pair<int, string>(5, "C")) << endl;


    priority_queue <pair<int, string>, vector<pair<int, string>>, Compare> q;

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