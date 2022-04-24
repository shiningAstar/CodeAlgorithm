#include <vector>
#include <stack>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

#include "TestHelper.h"
#include "../mergesort.h"
#include "../quicksort.h"

int main()
{
    int n = 1111111;
    vector<int> array1 = generateRandomArray(n, 0, 10000);
    vector<int> array2(array1), array3(array1);
    vector<int> array4(array1), array5(array1), array6(array1);

    //cout<<"before sort: "<<endl;

    /*for(int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
        if(i % 10 == 9)
            cout<<endl;
    }*/
    clock_t begin = clock();
    mergeSort1(array1);
    clock_t end = clock();

    if(isOrdered(array1))
        cout<<"merge sort 1 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    begin = clock();
    mergeSort2(array2);
    end = clock();

    if(isOrdered(array2))
        cout<<"merge sort 2 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    begin = clock();
    mergeSort3(array3);
    end = clock();

    if(isOrdered(array3))
        cout<<"merge sort 3 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    begin = clock();
    quickSort1(array4);
    end = clock();

    if(isOrdered(array4))
        cout<<"quick sort 1 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    begin = clock();
    quickSort2(array5);
    end = clock();

    if(isOrdered(array5))
        cout<<"quick sort 2 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    begin = clock();
    quickSort3(array6);
    end = clock();

    if(isOrdered(array6))
        cout<<"quick sort 3 "<<n<<" time: "<<(double)(end-begin)/CLOCKS_PER_SEC<<endl;

    //cout<<"after sort: "<<endl;

    /*for(int i = 0; i < n; i++)
    {
        cout<<array[i]<<" ";
        if(i % 10 == 9)
            cout<<endl;
    }*/

}
