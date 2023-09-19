#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#ifndef MINQUEUE_H
#define MINQUEUE_H

template <typename T>
class MinQueue
{
private:
    T* heapArr;
    int size{};
    int heap_size{};
    int parent(int i){return i/2;}
    int left(int i){return 2*i;}
    int right(int i){return 2*i + 1;}

public:
    MinQueue();
    MinQueue(T* A, int n);
    void max_heapify(int i);
    void build_heap();
    void sort(T* A);
    void insert(T x);
    T min();
    T extract_min();
    void decrease_key(int i, T k);
    string to_string();

};

#include "MinQueue.cpp"
#endif