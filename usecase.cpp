#include <iostream>
#include <vector>
#include "MinQueue.h"
#include "MinQueue.cpp"

using namespace std;

template <typename T>
vector<T> minSlidingWindow(T arr[], int len, int window) {
    vector<T> result;
    MinQueue_version2<T> MinQueue_version2(window);

    for (int i = 0; i < window; ++i) {
        MinQueue_version2.insert_version2(arr[i], i);
    }
    result.push_back(MinQueue_version2.min());

    for (int i = window; i < len; ++i) {
        MinQueue_version2.remove(i - window);
        MinQueue_version2.insert_version2(arr[i], i);
        result.push_back(MinQueue_version2.min());
    }

    return result;
}
