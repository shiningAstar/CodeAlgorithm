#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

//实现最大堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

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

//堆插入元素，在最后位置调用shiftUp
void insertHeap(vector<int> &heap, int i)
{
    heap.push_back(i);
    __shiftUp(heap, heap.size() - 1);
}

//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify(vector <int> &heap)
{
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; i--)
        __shiftDown(heap, i);
}

//取出最大元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最大堆性质
int extractMax(vector <int> &heap)
{
    int ret = heap.front();
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    __shiftDown(heap, 0);
    return ret;
}


//堆排序，利用堆顶点最大性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
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
