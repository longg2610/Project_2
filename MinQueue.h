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


    void insert(T x);


    T min();
    T extract_min();

    void decrease_key(int i, T k);

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
