#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

#ifndef MINQUEUE_H
#define MINQUEUE_H

template <typename T>
class MinQueue
{
private:
    T* heapArr;
    int length{};
    int heap_size{};
    int* position; // Array to store position
    //int parent(int i){return i/2;} //+1?
    int left(int i){return 2*i + 1;}
    int right(int i){return 2*i + 2;}
    void swap(T &a,T &b);
   
public:
    //constructors
    MinQueue();
    MinQueue(T* A, int n);
     ~MinQueue();

    //heap methods
    void min_heapify(int i);
    void build_heap();
    void sort(T* A);

    //MinQueue operations
    //Inserts element x into the MinQueue while maintaining the min-heap property.
    //Preconditions: The MinQueue is not full (heap_size < length).
    //Postconditions: Element x is inserted into the MinQueue, and the min-heap property is preserved.
    // Parameters:
    // - x: The element to be inserted into the MinQueue.
    //Return value: void
    void insert(T x){
        if (heap_size == length) {
        cout << "MinQueue is full. Cannot insert." << endl;
        return;
    }

    int i = heap_size;
    heapArr[heap_size] = x;
    heap_size++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[i] < heapArr[parent]) {
            swap(heapArr[i], heapArr[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

    }
    T min();
    T extract_min();
    // Decreases the value of the element at index i to k while preserving the min-heap property.
    // Preconditions:
    // - The index i is valid (0 <= i < heap_size).
    // - The new value k is smaller than the current value at index i.
    // Postconditions: The element at index i is updated to the new value k, and the min-heap property is preserved.
    // Parameters:
    // - i: The index of the element to be updated.
    // - k: The new value to which the element at index i should be decreased.
    // Return value: void
    void decrease_key(int i, T k){
    
            if (i < 0 || i >= heap_size) {
        cout << "Invalid index for decrease_key." << endl;
        return;
    }

    if (k >= heapArr[i]) {
        cout << "New value is not smaller than the current value." << endl;
        return;
    }

    heapArr[i] = k;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[i] < heapArr[parent]) {
            swap(heapArr[i], heapArr[parent]);
            i = parent;
        } else {
            break;
        }
    }
    }

    //testing
    string to_string();
    void set(int i, T val);
    void allocate(int n);

    //Additional function
    void remove(int index);
    void insert_version2(T x, int index);
    MinQueue_version2(int length) : heap_size(0), length(length);
    void min_heapify_version2(int i);
};

#include "MinQueue.cpp"
#endif
