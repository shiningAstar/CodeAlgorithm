#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED

//递推实现二分查找
/*********************************/

int binarySearch(vector<int> arr, int t)
{
    int l = 0, r = arr.size() - 1;
    int mid;

    /* 在[l,r]范围内查找target */
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        /* 三种情况查找相等 */
        /*if(arr[mid] == t)
            break;
        else if(arr[mid] > t))
            r = mid - 1;
        else
            l = mid + 1;*/
        /* 只有两种情况的判断，找大于(等于)目标值第一个即目标值右边的查找后左指针指向，
           找小于(等于)目标值第一个即目标值左边的查找后右指针指向 */ 
        if(arr[mid] >= t)   /* 右侧左移，右侧大于等于 */
            r = mid - 1;
        else                /* 左侧右移，左侧小于 */
            l = mid + 1;
    }

    /*两种情况判断，左侧最后一个r指向，右侧第一个l指向 */
    /* return l/r; */

    /* 三种情况判断相等 */
    if(l > r)
        return -1;
    else
        return mid;

}

/*********************************/

#endif // BINARYSEARCH_H_INCLUDED