#include <iostream>
#include "MinQueue.h"
using namespace std;
int main()
{
    int arr[10] = {70,50,3,46,49,42,36,45,69,94};    
    MinQueue<int> mq(arr, 12);
    mq.max_heapify(4);
    cout << mq.to_string();
    return 0;
}