/**
 *   @file: priorityq-struct.cc
 * @author: Nasseef Abukamail
 *   @date: October 31, 2022
 *  @brief: Priority Queue examples using the C++ built-in priority_queue.
 *          Examples:
 *              -- Max heap using int 
 *              -- Min heap using int
 *              -- Min/Max heap using user defined object Node. Where the comparison operator < is overloaded
 *                 to organize the entries in the queue.
 * 
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;
struct Node{
    Node(int id, string name){
        this->id = id;
        this->name = name;
    }
    bool operator <(const Node &other)const{
        return id > other.id;
    };
    int id;
    string name;
};




///Constants and function prototypes

int main(int argc, char const *argv[]) {

    //Max Heap using priority queue
    // priority_queue <int> q;
    // q.push(10);
    // q.push(10);
    // q.push(4);
    // q.push(9);

    // while (!q.empty())
    // {
    //     cout << q.top() << " ";
    //     q.pop();
    // }
    // cout << endl;
    
    //min heap using priority queue
    // priority_queue<int , vector<int>, greater<int>> q2;
    // q2.push(4);
    // q2.push(9);
    // q2.push(10);

    // while (!q2.empty())
    // {
    //     cout << q2.top() << " ";
    //     q2.pop();
    // }
    // cout << endl;

    // return 0;
    //Using priority queues with other objects (Node)
    priority_queue <Node> q3;

    q3.push(Node(9, "B"));
    q3.push(Node(4, "A"));
    q3.push(Node(2, "C"));
    q3.push(Node(8, "E"));
    q3.push(Node(7, "F"));
    q3.push(Node(1, "D"));
  
    

    while (!q3.empty())
    {
        cout << q3.top().id << " " << q3.top().name << " ";
        q3.pop();
    }
    cout << endl;
    /*add code*/
    return 0;
} /// main

