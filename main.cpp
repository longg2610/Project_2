#include <iostream>
#include <vector>
#include "MinQueue.h"
#include "usecase.cpp"
using namespace std;
void test_minqueue() {

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if(mq_str != "1 2 4 3 6 5 8 10 7 9") {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
       

    } catch (exception& e) {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}
void test_heapify() {
    
    int* empty_data = new int[0];

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if(mq_str != "") {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);
        
        mq_str = mq.to_string();
        
        if(mq_str != "1 3 4 7 6 5 8 10 11 9") {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }

    } catch (exception &e) {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_build_min_heap(){

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> mq;
        mq.allocate(10);
        for(int i = 0; i < 10; i++) {
            mq.set(i, int_data[i]);
        }
        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if(mq_str != "1 2 4 3 6 5 8 10 7 9") {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }
    } catch (exception &e) {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapsort() {

    int* empty_data = new int[0];

    int* int_data = new int[10];
    for(int i = 0; i < 10; i++){
        int_data[i] = 10-i;
    }

    try {

        MinQueue<int> empty;
        empty.sort(empty_data);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for(int i = 1; i < 10; i++) {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if(sorted_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }

    } catch (exception& e) {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_slidingWindow(){
int nums1[] = { 1, 3, -1, -3, 5, 3, 6, 7 };
int k1 = 3;

vector<int> result1 = minSlidingWindow(nums1, 8, k1);
cout << "[";
for (int i = 0; i < result1.size(); ++i) {
    if (i > 0) cout << ",";
    cout << result1[i];
}
cout << "]" << endl; 

int nums2[] = { 1, 2, 6, 8, 9, -7, -2, 7 };
int k2 = 3;

vector<int> result2 = minSlidingWindow(nums2, 8, k2);
cout << "[";
for (int i = 0; i < result2.size(); ++i) {
    if (i > 0) cout << ",";
    cout << result2[i];
}
cout << "]" << endl;
}
int main()
{
    // int arr[10] = {70,50,3,46,49,42,36,45,69,94};    
    // MinQueue<int> mq(arr, 10);
    // //mq.build_heap();
    // cout << mq.to_string()<<endl;

    // mq.sort();
    // cout << mq.to_string() << endl;

    // mq.min_heapify(4);
    // cout << mq.to_string()<<endl;
    // mq.min_heapify(3);
    // cout << mq.to_string()<<endl;
    // mq.min_heapify(2);
    // cout << mq.to_string()<<endl;
    // mq.min_heapify(1);
    // cout << mq.to_string()<<endl;
    // mq.min_heapify(0);
    // cout << mq.to_string()<<endl;


    test_minqueue();
    test_heapify();
    test_build_min_heap();
    test_heapsort();
    test_slidingWindow();
    cout << "testing complete\n";

    return 0;
}
