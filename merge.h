#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

/* �鲢���� */


//�鲢�������飬��Χ[l,mid][mid+1,r]
void __merge(vector<int> &nums, int l, int mid, int r, vector<int> &numsSort)
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
        else if(numsSort[i] <= numsSort[j])
            nums[p] = numsSort[i++];
        else
            nums[p] = numsSort[j++];
    }
}

//�ݹ�ʵ�ֹ鲢����
/***********************************************/
//�����±��0��ʼ
/* ����[l,r]��Χ������ */
void __mergeSort1(vector<int> &nums, int l, int r, vector<int> &numsSort)
{
    //������������
    if(l >= r)
        return;

    //����λ��λ�ö��֣�ż����Ԫ������ȡ�м�ƫ��λ��
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

/* ����ʵ�ֹ鲢���� */
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

//�Ե�����ʵ�ֹ鲢����
/***********************************************/

void mergeSort3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> numsSort;
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
            if(nums[mid] > nums[mid + 1])
                __merge(nums, l, mid, r, numsSort);
        }
    }
}

/***********************************************/

#endif // MERGE_H_INCLUDED
