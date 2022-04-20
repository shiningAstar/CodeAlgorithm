#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

//ʵ������
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

void __shiftUp(vector<int> &heap, int k)
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

void __shiftDown(vector<int> &heap, int k)
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
}

//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeap(vector<int> &heap, int i)
{
    heap.push_back(i);
    __shiftUp(heap, heap.size() - 1);
}

//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify(vector <int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown(heap, i);
}

//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
int extractMax(vector <int> &heap)
{
    int ret = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown(heap, 0);
    return ret;
}


//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort(vector <int> &heap)
{
    heapify(heap);
    for(int i = heap.size() - 1; i > 0; i--)
    {
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown(heap, 0);
    }
}


/*********************************/

#endif // HEAP_H_INCLUDED
