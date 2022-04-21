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

    heapify1(array1);

    printHeap(array1);

}

