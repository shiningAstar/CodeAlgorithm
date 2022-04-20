#ifndef TESTHELPER_H_INCLUDED
#define TESTHELPER_H_INCLUDED

//生成有n个值[min, max)元素随机数组
vector<int> generateRandomArray(int n, int min, int max)
{
    vector<int> array(n);
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        array[i] = min + rand() % (max - min);
    }
    return array;
}

bool isOrdered(vector<int> &nums)
{
    for(int i = 0; i < nums.size() - 1; i++)
        if(nums[i] > nums[i + 1])
            return false;
    return true;
}

void printHeap(vector<int> &heap)
{
    int lg2 = log(heap.size() - 1) / log(2);
    for(int i = 0, k = 0; i <= lg2; i++)
    {
        if(i < lg2)
            cout<<setw((lg2 - i) * 5)<<" ";
        for(int j = k; j < k * 2 + 1; j++)

            count<<"     ";

    }
}

#endif // TESTHELPER_H_INCLUDED
