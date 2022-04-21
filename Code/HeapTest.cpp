#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

#include "TestHelper.h"
#include "../heap.h"

int main()
{
    int n = 10;
    vector<int> array1 = generateRandomArray(n, 0, 100);
    vector<int> array2(array1), heap;

    heapify1(array1);

    printHeap(array1);

    heap.reserve(n);

    for(int i = 0; i < n; i++)
    {
        heap.push_back(i);
    }

    heapifyIndex1(array2, heap);

    for(int i = 0; i < array2.size(); i++)
    {
        cout<<array2[i]<<" ";
    }

    cout<<endl;

    printHeap(heap);

}

