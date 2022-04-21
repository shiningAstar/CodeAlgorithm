#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

/* �鲢���� */

#define lessMerge(t1, t2) (t1 < t2)
#define lessEqualMerge(t1, t2) (t1 <= t2)
#define greaterMerge(t1, t2) (t1 > t2)
#define greaterEqualMerge(t1, t2) (t1 >= t2)
#define equalMerge(t1, t2) (t1 == t2)

/*template<typename T>
int compareMerge(T t1, T t2)
{
    if(t1 < t2)
        return -1;
    else
        return t1 > t2;
}*/

//�鲢�������飬��Χ[l,mid][mid+1,r]
template<typename T>
void __merge(vector<T> &nums, int l, int mid, int r, vector<T> &numsSort)
{
    //��ʱ�洢����������������鲢Ϊһ����������
    numsSort.assign(nums.begin() + l, nums.begin() + r + 1);

    mid = mid + 1 - l;
    for(int i = 0, j = mid, p = l; p <= r; p++)
    {
        if(i >= mid)
            nums[p] = numsSort[j++];
        else if(j > r - l)
            nums[p] = numsSort[i++];
        else if(lessEqualMerge(numsSort[i], numsSort[j]))
            nums[p] = numsSort[i++];
        else
            nums[p] = numsSort[j++];
    }
}

//�ݹ�ʵ�ֹ鲢����
/***********************************************/
//�����±��0��ʼ
/* ����[l,r]��Χ������ */
template<typename T>
void __mergeSort1(vector<T> &nums, int l, int r, vector<T> &numsSort)
{
    //������������
    if(l >= r)
        return;

    //����λ��λ�ö��֣�ż����Ԫ������ȡ�м�ƫ��λ��
    int mid = l + (r - l) / 2;

    __mergeSort1(nums, l, mid, numsSort);
    __mergeSort1(nums, mid + 1, r, numsSort);

    if(greaterMerge(nums[mid], nums[mid + 1]))
        __merge(nums, l, mid, r, numsSort);

}

template<typename T>
void mergeSort1(vector<T> &nums)
{
    vector<T> numsSort;
    numsSort.reserve(nums.size());
    __mergeSort1(nums, 0, nums.size() - 1, numsSort);
}
/***********************************************/

/* ����ʵ�ֹ鲢���� */
/***********************************************/

template<typename T>
void mergeSort2(vector<T> &nums)
{
    stack<pair<pair<int, int>, int>> Sort;
    pair<pair<int, int>, int> sort;
    int l, r;
    int mid;

    vector<T> numsSort;

    numsSort.reserve(nums.size());

    Sort.push(pair<pair<int, int>, int>(pair<int, int>(0, nums.size() - 1), -1));

    while(!Sort.empty())
    {
        sort = Sort.top();
        l = sort.first.first;
        r = sort.first.second;
        if(l >= r)
        {
            Sort.pop();
            continue;
        }
        mid = sort.second;
        if(mid == -1)
        {
            mid = l + (r - l) / 2;
            Sort.top().second = mid;
            Sort.push(pair<pair<int, int>, int>(pair<int, int>(l, mid), -1));
            Sort.push(pair<pair<int, int>, int>(pair<int, int>(mid + 1, r), -1));
            continue;
        }

        if(greaterMerge(nums[mid], nums[mid + 1]))
            __merge(nums, l, mid, r, numsSort);
        Sort.pop();
    }

}
/***********************************************/

//�Ե�����ʵ�ֹ鲢����
/***********************************************/

template<typename T>
void mergeSort3(vector<T> &nums)
{
    int n = nums.size();
    vector<T> numsSort;
    int l, r;
    int mid;
    numsSort.reserve(n);

    //��sΪ���������ϲ�������s
    for(int s = 1; s < n; s += s)
    {
        //���ι鲢[l,mid],[mid,r]�������䣬��β�߽�ǰ���䲻��mid>=n-1���鲢�������䲻��r>=nȡ[mid,n]
        for(int l = 0; l < n; l += s + s)
        {
            mid = l + s - 1;
            r = mid + s;
            if(mid >= n - 1)
                break;
            if(r >= n)
                r = n - 1;
            if(greaterMerge(nums[mid], nums[mid + 1]))
                __merge(nums, l, mid, r, numsSort);
        }
    }
}

/***********************************************/

#endif // MERGE_H_INCLUDED
