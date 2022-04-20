#include <vector>

#include <stack>

#include <iostream>

#include <cstdlib>

#include <ctime>

using namespace std;

#include "TestHelper.h"

#include "../heap.h"

int main()
{
    int n = 30;
    vector<int> array1 = generateRandomArray(n, 0, 100);

    heapify(array1);


}

