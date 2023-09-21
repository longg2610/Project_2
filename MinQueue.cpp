#include "MinQueue.h"
#include <string.h>
template <typename T>
MinQueue<T>::MinQueue()
/*
Long
*/
{
    length = 0;
    heap_size = 0;
}

template <typename T>
MinQueue<T>::MinQueue(T *A, int n)
/*
Long
*/
{
    (*this).allocate(n);
    // memset(heapArr, '\0', n);
    for (int i{}; i < n; i++)
        (*this).set(i, A[i]);
    (*this).build_heap();
}

template <typename T>
void MinQueue<T>::min_heapify(int i)
/*
Long
*/
{
    int l = left(i);
    int r = right(i);
    int smallest{};
    if (l < heap_size && heapArr[l] < heapArr[i])
        smallest = l;
    else
        smallest = i;
    if (r < heap_size && heapArr[r] < heapArr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(heapArr[smallest], heapArr[i]);
        min_heapify(smallest);
    }
}
template <typename T>
void MinQueue<T>::build_heap()
/*
Long
*/
{
    heap_size = length;
    for (int i{length / 2 - 1}; i >= 0; i--)
        min_heapify(i);
}
template <typename T>
void MinQueue<T>::sort(T* A) //not sure if sort() sorts MinQueue array or A
/*
Long
*/
{
    //operations on member array, if empty
    if(length == 0)
    {
        return;
    }
    //if heapArr not empty
    (*this).build_heap();
    for (int j{length - 1}; j > 0; j--)
    {
        swap(heapArr[j], heapArr[0]);
        heap_size--;
        min_heapify(0);
    }
    
    //operations on A
    int begin{0};
    int end{length - 1};
    while(begin < end)
    {
        swap(heapArr[begin], heapArr[end]);
        begin++;
        end--;
    }
     for(int i{}; i < length; i++)
        A[i] = heapArr[i];
}
template <typename T>
void MinQueue<T>::insert(T x)
{
}
template <typename T>
T MinQueue<T>::min()
{
}
template <typename T>
T MinQueue<T>::extract_min()
{
}
template <typename T>
void MinQueue<T>::decrease_key(int i, T k)
{
}
template <typename T>
string MinQueue<T>::to_string()
/*
Long
*/
{
    int i{};
    T elem;
    stringstream mqString;
    for (int i{}; i < length; i++)
    {
        elem = heapArr[i];
        if(i != length - 1)
            mqString << elem << ' ';
        else mqString << elem;
    }
    return mqString.str();
}

template <typename T>
MinQueue<T>::~MinQueue()
{
    // delete [] heapArr;
}

template <typename T>
void MinQueue<T>::swap(T &a, T &b)
/*
Long
*/
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void MinQueue<T>::set(int i, T val)
/*
Long
*/
{
    heapArr[i] = val;
}

template <typename T>
void MinQueue<T>::allocate(int n)
/*
Long
*/
{
    heap_size = n;
    length = n;
    heapArr = new T[n];
}
