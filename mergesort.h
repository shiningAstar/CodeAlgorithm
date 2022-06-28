#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

/* 归并排序 */

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

//归并两个数组，范围[l,mid][mid+1,r]
template<typename T>
void __merge(vector<T> &nums, int l, int mid, int r, vector<T> &numsSort)
{
    //临时存储的两部分有序数组归并为一个有序数组
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

//递归实现归并排序
/***********************************************/
//数组下标从0开始
/* 排序[l,r]范围内数组 */
template<typename T>
void __mergeSort1(vector<T> &nums, int l, int r, vector<T> &numsSort)
{
    //单个不用排序
    if(l >= r)
        return;

    //在中位数位置二分，偶数个元素数组取中间偏右位置
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

/* 递推实现归并排序 */
/***********************************************/

template<typename T>
void mergeSort2(vector<T> &nums)
{
    stack<pair<int, int>> Sort;
    pair<int, int> sort, last;
    int l, r;
    int mid;

    vector<T> numsSort;

    numsSort.reserve(nums.size());

    sort = pair<int, int>{0, nums.size() - 1};
    l = 0;
    r = nums.size() - 1;
    last = sort;

    while(!Sort.empty() || l < r)
    {
        l = sort.first;
        r = sort.second;
        if(l >= r)
        {
            sort = Sort.top();
            l = sort.first;
            r = sort.second;
            mid = l + (r - l) / 2;
            pair<int, int> sortr{mid + 1, r};
            if(mid + 1 < r && last != sortr)
            {
                sort = sortr;
            }
            else
            {
                if(greaterMerge(nums[mid], nums[mid + 1]))
                    __merge(nums, l, mid, r, numsSort);
                Sort.pop();
                last = sort;
                sort.first = sort.second = 0;
                l = r = 0;
            }
        }
        else
        {
            Sort.push(sort);
            mid = l + (r - l) / 2;
            sort.second = mid;
            r = mid;
        }
    }

}
/***********************************************/

//自底向上实现归并排序
/***********************************************/

template<typename T>
void mergeSort3(vector<T> &nums)
{
    int n = nums.size();
    vector<T> numsSort;
    int l, r;
    int mid;
    numsSort.reserve(n);

    //以s为区间两两合并逐渐增倍s
    for(int s = 1; s < n; s += s)
    {
        //依次归并[l,mid],[mid,r]两个区间，结尾边界前区间不足mid>=n-1不归并，后区间不足r>=n取[mid,n]
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
