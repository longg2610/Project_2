#include "MinQueue.h"
#include <string.h>
#include <vector>
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
/////////////////////////////////////////
template <typename T>
MinQueue<T>::MinQueue_version2(int length) : heap_size(0), length(length) {
    /*
    Thomas
Constructor of Minqueue that initializes a new Minqueue
Input: integer length
Output: a new min queue
    */
    heapArr = new T[length];
    position = new int[length];
}
/////////////////////////////////////////
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
//////////////////////////////////////////////////

template <typename T>
void MinQueue<T>::min_heapify_version2(int i) {
/*
Thomas
Compare every node in the heap and change position if neccesary to place the minimum value above other nodes
Input: integer i
Output: void (a min heap)
*/
    int minimum = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap_size && heapArr[left] < heapArr[minimum])
        minimum = left;

    if (right < heap_size && heapArr[right] < heapArr[minimum])
        minimum = right;

    if (minimum != i) {
        swap(heapArr[i], heapArr[minimum]);
        swap(position[i], position[minimum]);
        min_heapify_version2(minimum);
    }
}
//////////////////////////////////////////////////////



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
void MinQueue<T>::void insert_version2(T x, int positionIndex) {
    /*
    Thomas
        Insert the value type T x in the heap and compare with the other nodes then swap if neccesary
        Input: x type T and integer positionIndex
        Output: void
    */
    if (heap_size == length) {
        cout << "Full queue" << endl;
    }

    int i = heap_size;
    heapArr[heap_size] = x;
    position[heap_size] = positionIndex;
    heap_size++;

    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heapArr[i] < heapArr[parent]) {
            swap(heapArr[i], heapArr[parent]);
            swap(position[i], position[parent]);
            i = parent;
        }
        else {
            break;
        }
    }
}
template <typename T>
T MinQueue<T>::min(){
    /*
    Thomas
        Find the minimum value of queue
        Input: none
        Output: the minimum value at position 0
    */
        if (heap_size == 0) {
            cout<<"Empty queue"<<endl;
        }
        return heapArr[0];
    }
template <typename T>
T MinQueue<T>::extract_min() {
    /*
    Thomas
        Extract the min value in the queue
        Input: none
        Output: the T value
    */
        if (heap_size == 0) {
            cout<<"Empty queue"<<endl;;
        }

        T root = heapArr[0];

        heapArr[0] = heapArr[heap_size - 1];
        position[0] = position[heap_size - 1];
        heap_size--;

        min_heapify_version2(0);

        return root;
    }

template <typename T>
void MinQueue<T>::remove(int positionIndex) {
    /*
    Thomas
    remove value at integer positionIndex in the queue
    input: int positionIndex
    output: void
    */
    for (int i = 0; i < heap_size; ++i) {
        if (position[i] == positionIndex) {
            heapArr[i] = heapArr[heap_size - 1];
            position[i] = position[heap_size - 1];
            heap_size--;

            min_heapify_version2(i);
            break;
        }
    }
}



template <typename T>
void MinQueue<T>::decrease_key(int i, T k)
{
    /*    // Decreases the value of the element at index i to k while preserving the min-heap property.
     Preconditions:
     - The index i is valid (0 <= i < heap_size).
     - The new value k is smaller than the current value at index i.
     Postconditions: The element at index i is updated to the new value k, and the min-heap property is preserved.
     Parameters:
     - i: The index of the element to be updated.
     - k: The new value to which the element at index i should be decreased.
     Return value: void*/
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

void MinQueue<T>::insert(T x) {
    /* Inserts element x into the MinQueue while maintaining the min-heap property.
     Preconditions: The MinQueue is not full (heap_size < length).
     Parameters:
     - x: The element to be inserted into the MinQueue.
     Postconditions: Element x is inserted into the MinQueue, and the min-heap property is preserved.
     Return value: void
    */
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
