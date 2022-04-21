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
void __shiftUp1(vector<T> &heap, int k)
{
    int p = (k - 1) / 2;
    T kv = heap[k];
    if(greaterEqualHeap(heap[p], kv))
        return;
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
}

template<typename T>
void __shiftDown1(vector<T> &heap, int k)
{
    int c = k * 2 + 1;
    T kv = heap[k];
    if(c >= heap.size())
        return;
    if(c + 1 < heap.size() && greaterHeap(heap[c + 1], heap[c]))
        c++;
    if(lessEqualHeap(heap[c], kv))
        return;
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
void __shiftUp2(vector<T> &heap, int k)
{
    int p = (k - 1) / 2;
    T kv = heap[k];
    if(lessEqualHeap(heap[p], kv))
        return;
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
}

template<typename T>
void __shiftDown2(vector<T> &heap, int k)
{
    int c = k * 2 + 1;
    T kv = heap[k];
    if(c >= heap.size())
        return;
    if(c + 1 < heap.size() && lessHeap(heap[c + 1], heap[c]))
        c++;
    if(greaterEqualHeap(heap[c], kv))
        return;
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
void __shiftUpIndex1(vector<T> &array, vector<int> &heap, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(greaterEqualHeap(array[heap[p]], array[kv]))
        return;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && lessHeap(array[heap[p]], array[kv]))
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
}

template<typename T>
void __shiftDownIndex1(vector<T> &array, vector<int> &heap, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size())
        return;
    if(c + 1 < heap.size() && greaterHeap(array[heap[c + 1]], array[heap[c]]))
        c++;
    if(lessEqualHeap(array[heap[c]], array[kv]))
        return;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && greaterHeap(array[heap[c + 1]], array[heap[c]]))
            c++;
        if(lessEqualHeap(array[heap[c]], array[kv]))
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
}

template<typename T>
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertIndexHeap1(vector<T> &array, vector<int> &heap, T i)
{
    array.push_back(i);
    heap.push_back(array.size() - 1);
    __shiftUpIndex1(array, heap, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapifyIndex1(vector<T> &array, vector<int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDownIndex1(array, heap, i);
}

template<typename T>
//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMaxIndex1(vector<T> &array, vector<int> &heap)
{
    T ret = array[heap[0]];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDownIndex1(array, heap, 0);
    return ret;
}

template<typename T>
//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSortIndex1(vector<T> &array, vector<int> &heap)
{
    heapifyIndex1(array, heap);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDownIndex1(array, heap, 0);
    }
}

/*********************************/


//ʵ��������С��
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

template<typename T>
void __shiftUpIndex2(vector<T> &array, vector<int> &heap, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(lessEqualHeap(array[heap[p]], array[kv]))
        return;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && greaterHeap(array[heap[p]], array[kv]))
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
}

template<typename T>
void __shiftDownIndex2(vector<T> &array, vector<int> &heap, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size())
        return;
    if(c + 1 < heap.size() && lessHeap(array[heap[c + 1]], array[heap[c]]))
        c++;
    if(greaterEqualHeap(array[heap[c]], array[kv]))
        return;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && lessHeap(array[heap[c + 1]], array[heap[c]]))
            c++;
        if(greaterEqualHeap(array[heap[c]], array[kv]))
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
}

template<typename T>
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeapIndex2(vector<T> &array, vector<int> &heap, T i)
{
    heap.push_back(i);
    __shiftUpIndex2(array, heap, heap.size() - 1);
}

template<typename T>
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapifyIndex2(vector<T> &array, vector<int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDownIndex2(array, heap, i);
}

template<typename T>
//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
T extractMinIndex2(vector<T> &array, vector<int> &heap)
{
    T ret = array[heap[0]];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDownIndex2(array, heap, 0);
    return ret;
}

template<typename T>
//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSortIndex2(vector<T> &array, vector<int> &heap)
{
    heapifyIndex2(array, heap);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDownIndex2(array, heap, 0);
    }
}


/*********************************/

#endif // HEAP_H_INCLUDED
