#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/* �ѣ����ȶ��У� */

#define lessHeap(t1, t2) (t1 < t2)
#define lessEqualHeap(t1, t2) (t1 <= t2)
#define greaterHeap(t1, t2) (t1 > t2)
#define greaterEqualHeap(t1, t2) (t1 >= t2)
#define equalHeap(t1, t2) (t1 == t2)

//ʵ������
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

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
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap1(vector<T> &heap, T i)
{
    heap.push_back(i);
    __shiftUp1(heap, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify1(vector <T> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown1(heap, i);
}

template<typename T>
//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMax1(vector <T> &heap)
{
    T ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown1(heap, 0);
    return ret;
}

template<typename T>
//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
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


//ʵ����С��
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

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
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap2(vector<T> &heap, T i)
{
    heap.push_back(i);
    __shiftUp2(heap, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify2(vector <T> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown2(heap, i);
}

template<typename T>
//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMin2(vector <T> &heap)
{
    T ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown2(heap, 0);
    return ret;
}

template<typename T>
//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
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


//ʵ����������
/*********************************/
/* ����������ʾ����洢�����ڵ����±�0��ʼ */

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

template<typename T>
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap3(vector<T> &array, vector<int> &heap, vector<int> &heappos, T i)
{
    array.push_back(i);
    heap.push_back(array.size() - 1);
    __shiftUp3(array, heap, heappos, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown3(array, heap, heappos, i);
}

template<typename T>
//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMax3(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    T ret = array[heap[0]];
    heap[0] = heap[heap.size() - 1];
    heappos[heap[0]] = 0;
    heap.pop_back();
    __shiftDown3(array, heap, heappos, 0);
    return ret;
}

template<typename T>
//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
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


//ʵ��������С��
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

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
void __shiftDown4(vector<T> &array, vector<int> &heap, vector<int> &heappos, int k)
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
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap4(vector<T> &array, vector<int> &heap, vector<int> &heappos, T i)
{
    heap.push_back(i);
    __shiftUp4(array, heap, heappos, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify4(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown4(array, heap, heappos, i);
}

template<typename T>
//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMinIndex2(vector<T> &array, vector<int> &heap, vector<int> &heappos)
{
    T ret = array[heap[0]];
    heap[0] = heap[heap.size() - 1];
    heappos[heap[0]] = 0;
    heap.pop_back();
    __shiftDown4(array, heap, heappos, 0);
    return ret;
}

template<typename T>
//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
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
