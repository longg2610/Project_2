#include <iostream>
#include <vector>
#include "MinQueue.h"
#include "MinQueue.cpp"

using namespace std;

template <typename T>
vector<T> MinQueue<T>::minSlidingWindow(T arr[], int len, int k) {
    vector<T> result;
    MinQueue_version2<T> MinQueue_version2(k);

    for (int i = 0; i < k; ++i) {
        MinQueue_version2.insert_version2(arr[i], i);
    }
    result.push_back(MinQueue_version2.min());

    for (int i = k; i < len; ++i) {
        MinQueue_version2.remove(i - k);
        MinQueue_version2.insert_version2(arr[i], i);
        result.push_back(MinQueue_version2.min());
    }

    return result;
}
