/**
 *   @file: nullptr.cc
 * @author: Nasseef Abukamail
 *   @date: August 24, 2022
 *  @brief: Add Description
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

/// Constants and function prototypes

class Node {
   public:
    Node(int newData, Node * newNext = nullptr){
        data = newData;
        next = newNext;
    };
    int getData(){return data;}
    Node *getNext(){return next;}
    void setData(int newData){data = newData;}
    void setNext(Node *newNext){next = newNext;}
   private:
    int data;
    Node *next;
};

void insert(Node *&head, int data);
void print(Node *head);

int main(int argc, char const *argv[]) {
    
    vector<string> v = {"Bob"};
    ///vector<string>::iterator it = v.begin();
    // auto it = v.begin();
    Node * head = new Node(10, nullptr);
    // auto current = head;
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);
   
    print(head);

    cout << head->getData() << endl;
    // int numbers[] = {10, 20, 30, 40, 50}; //static
    // int *p = numbers;
    // int *p2 = &numbers[3];
    // cout << p2[3] << endl;
    // cout << (p - p2) << endl;
    // cout << *(p+1) << endl;

    // char *c = nullptr;
    // c = new char[4];  //dynamic
    // c[0] = c[2] = c[3] = 0;
    // c[1] = 'A';
    // p = (int *) c;
    // cout << *p << endl;

    return 0;
}  /// main

void insert(Node *&head, int data){
    auto temp = new Node(data, head);
    head = temp;
}

void print(Node *head){
    while(head != nullptr){
        cout << head->getData() << " ";
        head = head->getNext();
    }
    cout << endl;
}