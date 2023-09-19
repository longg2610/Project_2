#include "MinQueue.h"
#include <string.h>
template <typename T>
MinQueue<T>::MinQueue()
{

}

template <typename T>
MinQueue<T>::MinQueue(T* A, int n)
{
    heapArr = new T[n];
    memset(heapArr, '\0', n);
    int arr[10] = {70,50,3,46,49,42,36,45,69,94};
    for (int i{}; i < 10;i++)
        heapArr[i] = arr[i];
}

template <typename T>
void MinQueue<T>::max_heapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest{i};
    if (l <= heap_size && heapArr[l] > heapArr[i])
        largest = l;
    if (r <= heap_size && heapArr[r] > heapArr[i])
        largest = r;
    if(largest != i)
    {
        T temp = heapArr[largest];
        heapArr[largest] = heapArr[i];
        heapArr[i] = temp;
        max_heapify(largest);
    }
}
template <typename T>
void MinQueue<T>::build_heap()
{

}
template <typename T>
void MinQueue<T>::sort(T* A)
{

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
{
    int i{};
    T elem = heapArr[i];
    stringstream mqString;
    while(elem != '\0')
    {
        mqString << elem << ' ';
        elem = heapArr[++i];
    }
    return mqString.str();
}
