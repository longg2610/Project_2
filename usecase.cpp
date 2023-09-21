#include <iostream>
#include <vector>
#include <sstream>
#include "MinQueue.h"
#include "MinQueue.cpp"

using namespace std;

template <typename T>
string minSlidingWindow(T arr[], int len, int window) {
    vector<T> result;
    MinQueue_version2<T> MinQueue_version2(window);
    stringstream ss;

    for (int i = 0; i < window; ++i) {
        MinQueue_version2.insert_version2(arr[i], i);
    }
    result.push_back(MinQueue_version2.min());

    for (int i = window; i < len; ++i) {
        MinQueue_version2.remove(i - window);
        MinQueue_version2.insert_version2(arr[i], i);
        result.push_back(MinQueue_version2.min());
    }

    ss << "[";
    for (int i = 0; i < result.size(); ++i) {
        if (i > 0) {
            ss << ",";
        }
        ss << result[i];
    }

    ss << "]";
    return ss.str();
   
}
