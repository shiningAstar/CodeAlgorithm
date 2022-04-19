#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

/* 快速排序 */

//递归实现一路快速排序
/***********************************************/

//按标定点左右分界，近乎有序数组随机标定点避免分界不平衡
int __partition1(vector<int> &nums, int l, int r)
{
    //随机选标定点
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int i, j;

    for(i = l + 1, j = l + 1; i <= r; i++)
    {
        if(nums[i] < v)
        {
            swap(nums[j], nums[i]);
            j++;
        }
    }

    swap(nums[l], nums[j - 1]);

    return j - 1;

}

//对范围[l,r]的数组快速排序
void __quickSort1(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    int q = __partition1(nums, l, r);
    __quickSort1(nums, l, q - 1);
    __quickSort1(nums, q + 1, r);

}

void quickSort1(vector<int> &nums)
{
    //随机标定点
    //srand(time(NULL));
    __quickSort1(nums, 0, nums.size() - 1);
}

/***********************************************/



//递归实现两路快速排序，重复元素分散到两边，尽可能平衡
/***********************************************/

int __partition2(vector<int> &nums, int l, int r)
{
    //随机选标定点
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int i = l + 1, j = r;



    while(true)
    {
        while(i <= r && nums[i] < v) i++;
        while(j > l && nums[j] > v) j--;
        if(i > j) break;
        swap(nums[i], nums[j]);
        i++;
        j--;
    }

    swap(nums[l], nums[j]);

    return j;

}

void __quickSort2(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    int q = __partition2(nums, l, r);
    __quickSort2(nums, l, q - 1);
    __quickSort2(nums, q + 1, r);
}


void quickSort2(vector<int> &nums)
{
    __quickSort2(nums, 0, nums.size() - 1);
}

/***********************************************/



//递归实现三路快速排序，标定点大小分两边，标定点重复元素中间，只处理左右两边
/***********************************************/

void __quickSort3(vector<int> &nums, int l, int r)
{
    if(l >= r)
        return;

    //partition
    //随机选标定点
    //swap(nums[l], nums[l + rand() % (r - l)]);
    int v = nums[l];
    int lt = l, gt = r + 1;

    for(int i = l + 1; i < gt;)
    {
        if(nums[i] < v)
        {
            lt++;
            swap(nums[lt], nums[i]);
            i++;
        }
        else if(nums[i] > v)
        {
            gt--;
            swap(nums[i], nums[gt]);
        }
        else
            i++;
    }

    swap(nums[l], nums[lt]);


    __quickSort3(nums, l, lt - 1);
    __quickSort3(nums, gt, r);
}


void quickSort3(vector<int> &nums)
{
    __quickSort3(nums, 0, nums.size() - 1);
}

/***********************************************/

#endif // QUICKSORT_H_INCLUDED
