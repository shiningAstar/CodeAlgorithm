#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/* 堆（优先队列） */

#define lessHeap(t1, t2) (t1 < t2)
#define lessEqualHeap(t1, t2) (t1 <= t2)
#define greaterHeap(t1, t2) (t1 > t2)
#define greaterEqualHeap(t1, t2) (t1 >= t2)
#define equalHeap(t1, t2) (t1 == t2)

//实现最大堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

template<typename T>
bool __shiftUp1(vector<T> &heap, int k)
{
    int p = (k - 1) / 2;
    T kv = heap[k];
    if(greaterEqualHeap(heap[p], kv))
        return false;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && lessHeap(heap[p], kv))
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
    return true;
}

template<typename T>
bool __shiftDown1(vector<T> &heap, int k)
{
    int c = k * 2 + 1;
    T kv = heap[k];
    if(c >= heap.size())
        return false;
    if(c + 1 < heap.size() && greaterHeap(heap[c + 1], heap[c]))
        c++;
    if(lessEqualHeap(heap[c], kv))
        return false;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && greaterHeap(heap[c + 1], heap[c]))
            c++;
        if(lessEqualHeap(heap[c], kv))
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
    return true;
}

template<typename T>
//堆最后元素放在头部位置调用shiftDown
void lastTop1(vector<T> &heap)
{
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}

template<typename T>
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast1(vector<T> &heap, T i)
{
    heap.push_back(i);
    if(heap.size() > 1)
        __shiftUp1(heap, heap.size() - 1);
}

template<typename T>
//堆插入元素，在头位置调用shiftDown
void insertHeapTop1(vector<T> &heap, T i)
{
    if(heap.size() > 0)
        heap[0] = i;
    else
        heap.push_back(i);
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}

template<typename T>
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify1(vector <T> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown1(heap, i);
}

template<typename T>
//取出最大元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最大堆性质
bool extractMaxLast1(vector <T> &heap, T &max)
{
    if(heap.size() == 0)
        return false;
    max = heap[0];
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return true;
}

template<typename T>
//取出最大元素，元素i放在根调用shiftDown保持最大堆性质
bool extractMaxItem1(vector <T> &heap, T &max, T i)
{
    if(heap.size() == 0)
        return false;
    max = heap[0];
    heap[0] = i;
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return true;
}

template<typename T>
//堆排序，利用堆顶点最大性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort1(vector <T> &heap)
{
    heapify1(heap);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown1(heap, 0);
    }
}

/*********************************/


//实现最小堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

template<typename T>
bool __shiftUp2(vector<T> &heap, int k)
{
    int p = (k - 1) / 2;
    T kv = heap[k];
    if(lessEqualHeap(heap[p], kv))
        return false;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && greaterHeap(heap[p], kv))
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
    return true;
}

template<typename T>
bool __shiftDown2(vector<T> &heap, int k)
{
    int c = k * 2 + 1;
    T kv = heap[k];
    if(c >= heap.size())
        return false;
    if(c + 1 < heap.size() && lessHeap(heap[c + 1], heap[c]))
        c++;
    if(greaterEqualHeap(heap[c], kv))
        return false;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && lessHeap(heap[c + 1], heap[c]))
            c++;
        if(greaterEqualHeap(heap[c], kv))
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
    return true;
}

template<typename T>
//堆最后元素放在头部位置调用shiftDown
void lastTop2(vector<T> &heap)
{
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
}

template<typename T>
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast2(vector<T> &heap, T i)
{
    heap.push_back(i);
    if(heap.size() > 1)
        __shiftUp2(heap, heap.size() - 1);
}

template<typename T>
//堆插入元素，在头位置调用shiftDown
void insertHeapTop2(vector<T> &heap, T i)
{
    if(heap.size() > 0)
        heap[0] = i;
    else
        heap.push_back(i);
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
}

template<typename T>
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify2(vector <T> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown2(heap, i);
}

template<typename T>
//取出最小元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最小堆性质
bool extractMinLast2(vector <T> &heap, T &min)
{
    if(heap.size() == 0)
        return false;
    min = heap[0];
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return true;
}

template<typename T>
//取出最小元素，元素i放在根调用shiftDown保持最小堆性质
bool extractMinItem2(vector <T> &heap, T &min, T i)
{
    if(heap.size() == 0)
        return false;
    min = heap[0];
    heap[0] = i;
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return true;
}

template<typename T>
//堆排序，利用堆顶点最小性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort2(vector <T> &heap)
{
    heapify2(heap);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown2(heap, 0);
    }
}

/*********************************/


//实现索引最大堆
/*********************************/
/* 堆用索引表示数组存储，根节点在下标0开始 */

template<typename T>
bool __shiftUp3(vector<T> &array, vector<int> &heap, vector<int> &heappos, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(greaterEqualHeap(array[heap[p]], array[kv]))
        return false;
    heap[k] = heap[p];
    heappos[heap[k]] = k;
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && lessHeap(array[heap[p]], array[kv]))
    {
        heap[k] = heap[p];
        heappos[heap[k]] = k;
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
    heappos[kv] = k;
    return true;
}

template<typename T>
bool __shiftDown3(vector<T> &array, vector<int> &heap, vector<int> &heappos, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size())
        return false;
    if(c + 1 < heap.size() && greaterHeap(array[heap[c + 1]], array[heap[c]]))
        c++;
    if(lessEqualHeap(array[heap[c]], array[kv]))
        return false;
    heap[k] = heap[c];
    heappos[heap[k]] = k;
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && greaterHeap(array[heap[c + 1]], array[heap[c]]))
            c++;
        if(lessEqualHeap(array[heap[c]], array[kv]))
            break;
        heap[k] = heap[c];
        heappos[heap[k]] = k;
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
    heappos[kv] = k;
    return true;
}

/*
//T i为元素值
template<typename T>
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast3(vector<T> &array, vector<int> &heap, vector<int> &heappos, T i)
{
    array.push_back(i);
    heap.push_back(array.size() - 1);
    heappos.push_back(heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp3(array, heap, heappos, heap.size() - 1);
}

template<typename T>
//堆插入元素，在头位置调用shiftDown
void insertHeapTop3(vector<T> &array, vector<int> &heap, vector<int> &heappos, T i)
{
    if(heap.size() > 0)
    {
        array[heap[0]] = i;
    }
    else
    {
        array.push_back(i);
        heap.push_back(array.size() - 1);
        heappos.push_back(0);
    }

    if(heap.size() > 1)
        __shiftDown3(array, heap, heappos, 0);
}*/

template<typename T>
//堆最后元素放在头部位置调用shiftDown
void lastTop3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown3(array, heap, heappos, 0);
}

//int i为元素在array中索引
template<typename T>
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast3(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    heap.push_back(i);
    heappos[i](heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp3(array, heap, heappos, heap.size() - 1);
}

template<typename T>
//堆插入元素，在头位置调用shiftDown
void insertHeapTop3(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    if(heap.size() > 0)
    {
        heap[0] = i;
        heappos[i] = 0;
    }
    else
    {
        heap.push_back(i);
        heappos[i] = heap.size() - 1;
    }

    if(heap.size() > 1)
        __shiftDown3(array, heap, heappos, 0);
}

template<typename T>
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown3(array, heap, heappos, i);
}

template<typename T>
//取出最大元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最大堆性质
int extractMaxLast3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    int ret;
    if(heap.size() == 0)
        return -1;
    ret = heap[0];
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown3(array, heap, heappos, 0);
    return ret;
}

template<typename T>
//取出最大元素，元素i放在根调用shiftDown保持最大堆性质
int extractMaxItem3(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    int ret;
    if(heap.size() == 0)
        return -1;
    ret = heap[0];
    heap[0] = i;
    if(heap.size() > 1)
        __shiftDown3(array, heap, heappos, 0);
    return ret;
}

template<typename T>
//堆排序，利用堆顶点最大性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    heapify3(array, heap, heappos);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heappos[heap[0]] = 0;
        if(i > 1)
            __shiftDownIndex1(array, heap, heappos, 0);
    }
}

/*********************************/


//实现索引最小堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

template<typename T>
bool __shiftUp4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(lessEqualHeap(array[heap[p]], array[kv]))
        return false;
    heap[k] = heap[p];
    heappos[heap[k]] = k;
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && greaterHeap(array[heap[p]], array[kv]))
    {
        heap[k] = heap[p];
        heappos[heap[k]] = k;
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
    heappos[kv] = k;
    return true;
}

template<typename T>
bool __shiftDown4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size())
        return false;
    if(c + 1 < heap.size() && lessHeap(array[heap[c + 1]], array[heap[c]]))
        c++;
    if(greaterEqualHeap(array[heap[c]], array[kv]))
        return false;
    heap[k] = heap[c];
    heappos[heap[k]] = k;
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && lessHeap(array[heap[c + 1]], array[heap[c]]))
            c++;
        if(greaterEqualHeap(array[heap[c]], array[kv]))
            break;
        heap[k] = heap[c];
        heappos[heap[k]] = k;
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
    heappos[kv] = k;
    return true;
}

template<typename T>
//堆最后元素放在头部位置调用shiftDown
void lastTop4(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    if(heap.size() > 1)
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown4(array, heap, heappos, 0);
}

template<typename T>
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    heap.push_back(i);
    heappos[i] = heap.size() - 1;
    if(heap.size() > 1)
        __shiftUp4(array, heap, heappos, heap.size() - 1);
}

template<typename T>
//堆插入元素，在头位置调用shiftDown
void insertHeapTop4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    if(heap.size() > 0)
    {
        heap[0] = i;
        heappos[i] = 0;
    }
    else
    {
        heap.push_back(i);
        heappos[i] = heap.size() - 1;
    }

    if(heap.size() > 1)
        __shiftDown4(array, heap, heappos, 0);
}

template<typename T>
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify4(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown4(array, heap, heappos, i);
}

template<typename T>
//取出最小元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最小堆性质
int extractMinLast4(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    int ret;
    if(heap.size() == 0)
        return -1;
    ret = heap[0];
    lastTop4(array, heap, heappos);
    return ret;
}

template<typename T>
//取出最小元素，元素i放在根调用shiftDown保持最小堆性质
int extractMinItem4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int i)
{
    int ret;
    if(heap.size() == 0)
        return -1;
    ret = heap[0];
    heap[0] = i;
    if(heap.size() > 1)
        __shiftDown4(array, heap, heappos, 0);
    return ret;
}

template<typename T>
//堆排序，利用堆顶点最小性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort4(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    heapify4(array, heap, heappos);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        heappos[heap[0]] = 0;
        if(i > 1)
            __shiftDown4(array, heap, heappos, 0);
    }
}


/*********************************/

#endif // HEAP_H_INCLUDED
