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
        if(arr[mid] == t)
            break;
        else if(arr[mid] > t))
            r = mid - 1;
        else
            l = mid + 1;
        /* 只有两种情况的判断，找大于(等于)目标值第一个即目标值右边的查找后左指针指向，
           找小于(等于)目标值第一个即目标值左边的查找后右指针指向 */
        /* 
        if(arr[mid] >= t)
            r = mid - 1;
        else
            l = mid + 1; */
    }

    /*两种情况判断*/
    /* return l/r; */

    if(l > r)
        return -1;
    else
        return mid;

}

/*********************************/

#endif // BINARYSEARCH_H_INCLUDED