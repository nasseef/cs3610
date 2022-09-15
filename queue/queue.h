/**
 *   @file: queue.h
 * @author: Nasseef Abukamail
 *   @date: September 12, 2022
 *  @brief: Add Description
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <deque>
using namespace std;

template <typename DataType>
class Queue{
    public:
        Queue(){}
        void push(DataType data);
        DataType pop();
        DataType peek();
        size_t size(){return q.size();}
    private:
        deque<DataType> q;

};

template <typename DataType>
void Queue<DataType>::push(DataType data){
    q.push_back(data);
}

template <typename DataType>
DataType Queue<DataType>::pop(){
    DataType value = q.at(0);
    q.pop_front();
    return value;
}

template <typename DataType>
DataType Queue<DataType>::peek(){
    DataType value = q.at(0);
    return value;
}

