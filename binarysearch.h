#ifndef BINARYSEARCH_H_INCLUDED
#define BINARYSEARCH_H_INCLUDED

/* 二分查找 */

#define lessBinary(t1, t2) (t1 < t2)
#define lessEqualBinary(t1, t2) (t1 <= t2)
#define greaterBinary(t1, t2) (t1 > t2)
#define greaterEqualBinary(t1, t2) (t1 >= t2)
#define equalBinary(t1, t2) (t1 == t2)

//递推实现二分查找
/*********************************/

template<typename T>
int binarySearch(vector<T> array, T target)
{
    int l = 0, r = array.size() - 1;
    int mid;

    /* 在[l,r]范围内查找target */
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(equalBinary(array[mid], target))
            break;
        else if(greaterBinary(array[mid], target))
            r = mid - 1;
        else
            l = mid + 1;
    }

    if(l > r)
        return -1;
    else
        return mid;

}

/*********************************/

#endif // BINARYSEARCH_H_INCLUDED
