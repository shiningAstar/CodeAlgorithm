#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

/* 归并排序 */


//归并两个数组，范围[l,mid][mid+1,r]
void __merge(vector<int> &nums, int l, int mid, int r, vector<int> &numsSort)
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
        else if(numsSort[i] <= numsSort[j])
            nums[p] = numsSort[i++];
        else
            nums[p] = numsSort[j++];
    }
}

//递归实现归并排序
/***********************************************/
//数组下标从0开始
/* 排序[l,r]范围内数组 */
void __mergeSort1(vector<int> &nums, int l, int r, vector<int> &numsSort)
{
    //单个不用排序
    if(l >= r)
        return;

    //在中位数位置二分，偶数个元素数组取中间偏右位置
    int mid = l + (r - l) / 2;

    __mergeSort1(nums, l, mid, numsSort);
    __mergeSort1(nums, mid + 1, r, numsSort);

    if(nums[mid] > nums[mid + 1])
        __merge(nums, l, mid, r, numsSort);

}

void mergeSort1(vector<int> &nums)
{
    vector<int> numsSort;
    numsSort.reserve(nums.size());
    __mergeSort1(nums, 0, nums.size() - 1, numsSort);
}
/***********************************************/

/* 递推实现归并排序 */
/***********************************************/

void mergeSort2(vector<int> &nums)
{
    stack<pair<pair<int, int>, int>> Sort;
    pair<pair<int, int>, int> sort;
    int l, r;
    int mid;

    vector<int> numsSort;

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

        if(nums[mid] > nums[mid + 1])
            __merge(nums, l, mid, r, numsSort);
        Sort.pop();
    }

}
/***********************************************/

//自底向上实现归并排序
/***********************************************/

void mergeSort3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> numsSort;
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
            if(nums[mid] > nums[mid + 1])
                __merge(nums, l, mid, r, numsSort);
        }
    }
}

/***********************************************/

#endif // MERGE_H_INCLUDED
