#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

//实现最大堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

void shiftUp(vector<int> heap, int k)
{
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(heap[p] >= kv)
        return;
    while(k > 0 && heap[p] < kv)
    {
        heap[k] = heap[p];
        k = p;
        p = (k - 1) / 2;
    }
    heap[k] = kv;
}

/*********************************/

#endif // HEAP_H_INCLUDED
