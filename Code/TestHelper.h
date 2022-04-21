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

int pof2(int n)
{
    int ret = 2;
    if(n == 0) return 1;
    for(int i = 1; i < n; i++)
    {
        ret += ret;
    }
    return ret;
}

void printHeap(vector<int> &heap)
{
    int lg2 = log(heap.size() - 1) / log(2);
    for(int i = 0, k = 0; i <= lg2; i++, k = k * 2 + 1)
    {
        for(int j = k; j < k * 2 + 1; j+=2)
        {
            if(j >= heap.size())
                break;
            cout<<setw((pof2(lg2 - i) - 1) * 5)<<"";
            cout<<setw(5)<<heap[j];
            if(j + 1 >= k * 2 + 1 || j + 1 >= heap.size())
                break;
            cout<<setw((pof2(lg2 - i) - 1) * 5 * 2 + 1)<<"";
            cout<<setw(5)<<heap[j + 1];
            if(j + 1 == k * 2 || j + 1 == heap.size() - 1)
                break;
            cout<<setw((pof2(lg2 - i) - 1) * 5 + 1)<<"";
        }
        cout<<endl;
    }
}

#endif // TESTHELPER_H_INCLUDED
