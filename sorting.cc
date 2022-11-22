/**
 *   @file: sorting.cc
 * @author: Nasseef Abukamail
 *   @date: November 21, 2022
 *  @brief: Several sorting functions
 */

#include <chrono>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
/// Constants and function prototypes
void print(vector<int> data);
void selectSort(vector<int> &data);

// heap sort functions
void heapSort(vector<int> &data);
void buildHeap(vector<int> &data);
void percolateDown(vector<int> &data, int size, int parentIndex);

//merge sort
void merge(vector<int> &data, int first, int middle, int last);
void mergeSortRecursive(vector<int> &data, int first, int last);
void mergeSort(vector<int> &data) {
    mergeSortRecursive(data, 0, data.size() - 1);
}

//quick sort
void quickSortRecursive(vector<int> &data, int first, int last);
void partition(vector<int> &data, int first, int last, int &pivIndex);
void quickSort(vector<int> &data){quickSortRecursive(data, 0, data.size() - 1);};

int main(int argc, char const *argv[]) {
    if (argc != 2)
    {
        cout << "Error: enter the number of array elements" << endl;
        exit(0);
    }
    int dataSize = atoi(argv[1]);
    srand(time(nullptr));
    vector<int> original(dataSize);
    cout << fixed << setprecision(9);

    for (size_t i = 0; i < original.size(); i++) {
        original.at(i) = rand() % 1000;
    }

    vector<int> data = original;
     //print(data);

    auto begin = chrono::high_resolution_clock::now();
    selectSort(data);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "Selection sort: " << elapsed.count() / 1.0e9 << " seconds" << endl;
    
    data = original;
    begin = chrono::high_resolution_clock::now();
    heapSort(data);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "Heap Sort: " << elapsed.count() / 1.0e9 << " seconds" << endl;

    data = original;
    // print(data);
    begin = chrono::high_resolution_clock::now();
    mergeSort(data);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "Merge Sort: " << elapsed.count() / 1.0e9 << " seconds" << endl;

    data = original;
    //print(data);
    begin = chrono::high_resolution_clock::now();
    quickSort(data);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cout << "Quick Sort: " << elapsed.count() / 1.0e9 << " seconds" << endl;

    //print(data);
    return 0;
}  /// main

void print(vector<int> data) {
    for (size_t i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
void selectSort(vector<int> &data) {
    int iom;  // Index of min
    for (int i = 0; i < data.size() - 1; i++) {
        iom = i;
        for (int j = i; j < data.size(); j++)
            if (data[j] < data[iom]) iom = j;
        if (iom != i) swap(data[i], data[iom]);
    }
}  // selectSort

void buildHeap(vector<int> &data) {
    int i;
    for (i = data.size() / 2; i > 0; i--) {
        percolateDown(data, data.size(), i);
    }
}  // buildHeap

void percolateDown(vector<int> &data, int size, int parentIndex) {
    int childIndex = parentIndex * 2;
    while (childIndex <= size) {  // As long as parent has children
        if (childIndex < size)    // is there a right child?
        {  // Find the index of the largest of the 2 Children
            if (data[childIndex + 1] > data[childIndex]) {
                childIndex++;
            }
        }
        if (data[parentIndex] < data[childIndex]) {  // not heap
            swap(data[parentIndex], data[childIndex]);
        } else {
            break;
        }  // yes it is a heap
        parentIndex = childIndex;
        childIndex = parentIndex * 2;
    }  // while
}  // PercolateDown

void heapSort(vector<int> &data) {
    int i;
    buildHeap(data);
    i = data.size();
    while (i > 1) {
        swap(data[1], data[i]);
        i--;
        percolateDown(data, i, 1);
    }
}  // heapSort

void mergeSortRecursive(vector<int> &data, int first, int last) {
    int middle;
    if (first < last) {
        middle = (first + last) / 2;
        mergeSortRecursive(data, first, middle);
        mergeSortRecursive(data, middle + 1, last);
        merge(data, first, middle, last);
    }
}  // mergeSortRecursive

void merge(vector<int> &data, int first, int middle, int last) {
    vector<int> temp(last - first + 1);
    int nextLeft = first, nextRight = middle + 1, index = 0;
    while ((nextLeft <= middle) && (nextRight <= last)) {
        if (data[nextLeft] < data[nextRight]) {
            temp[index++] = data[nextLeft++];
        } else {
            temp[index++] = data[nextRight++];
        }
    }
    while (nextLeft <= middle) {
        temp[index++] = data[nextLeft++];
    }
    while (nextRight <= last) {
        temp[index++] = data[nextRight++];
    }
    index = 0;
    for (size_t i = first; i <= last; i++) {
        data[i] = temp[index++];
    }

}  // merge

void quickSortRecursive(vector<int> &data, int first, int last) {
    int pivIndex;
    if (first < last) {
        partition(data, first, last, pivIndex);
        quickSortRecursive(data, first, pivIndex - 1);
        quickSortRecursive(data, pivIndex + 1, last);
    }
}  // quickSortRecursive

void partition(vector<int> &data, int first, int last, int &pivIndex) {
    int pivot, up = first, down = last;
    pivot = data[first];  // can be chosen randomly
    do {
        while (data[up] <= pivot && up < last) {
            up++;
        }
        while (data[down] > pivot){
            down--;
        }
        if (up < down){
            swap(data[up], data[down]);
        }
    } while (up < down);
    swap(data[first], data[down]);
    pivIndex = down;
}  // partition
