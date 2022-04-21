#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

//ʵ������
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

void __shiftUp1(vector<int> &heap, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(heap[p] >= kv)
        return;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && heap[p] < kv)
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
}

void __shiftDown1(vector<int> &heap, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c + 1 < heap.size() && heap[c + 1] > heap[c])
        c++;
    if(heap[c] <= kv)
        return;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && heap[c + 1] > heap[c])
            c++;
        if(heap[c] <= kv)
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
}

//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap1(vector<int> &heap, int i)
{
    heap.push_back(i);
    __shiftUp1(heap, heap.size() - 1);
}

//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify1(vector <int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown1(heap, i);
}

//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
int extractMax1(vector <int> &heap)
{
    int ret = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown1(heap, 0);
    return ret;
}


//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort1(vector <int> &heap)
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

void __shiftUp2(vector<int> &heap, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(heap[p] <= kv)
        return;
    heap[k] = heap[p];
    k = p;
    p = (k - 1) / 2;
    while(k > 0 && heap[p] > kv)
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
}

void __shiftDown2(vector<int> &heap, int k)
{
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c + 1 < heap.size() && heap[c + 1] < heap[c])
        c++;
    if(heap[c] >= kv)
        return;
    heap[k] = heap[c];
    k = c;
    c = k * 2 + 1;
    while(c < heap.size())
    {
        if(c + 1 < heap.size() && heap[c + 1] < heap[c])
            c++;
        if(heap[c] >= kv)
            break;
        heap[k] = heap[c];
        k = c;
        c = k * 2 + 1;
    }
    heap[k] = kv;
}

//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap2(vector<int> &heap, int i)
{
    heap.push_back(i);
    __shiftUp2(heap, heap.size() - 1);
}

//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify2(vector <int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown2(heap, i);
}

//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
int extractMin2(vector <int> &heap)
{
    int ret = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown2(heap, 0);
    return ret;
}


//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort2(vector <int> &heap)
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

#endif // HEAP_H_INCLUDED
