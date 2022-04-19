#ifndef TESTHELPER_H_INCLUDED
#define TESTHELPER_H_INCLUDED

//������n��ֵ[min, max)Ԫ���������
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

#endif // TESTHELPER_H_INCLUDED
