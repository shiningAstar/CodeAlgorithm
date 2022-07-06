#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/* 堆（优先队列） */

//实现最大堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

bool __shiftUp1(vector<int> &heap, int k){
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(heap[p] >= kv) return false;
    while(k > 0 && heap[p] < kv){
        heap[k] = heap[p];
        k = p, p = (k - 1) / 2;
    }
    heap[k] = kv;
    return true;
}
bool __shiftDown1(vector<int> &heap, int k){
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size()) return false;
    if(c + 1 < heap.size() && heap[c + 1] > heap[c]) ++c;
    if(heap[c] <= kv) return false;
    while(c < heap.size()){
        if(c + 1 < heap.size() && heap[c + 1] > heap[c]) ++c;
        if(heap[c] <= kv) break;
        heap[k] = heap[c];
        k = c, c = k * 2 + 1;
    }
    heap[k] = kv;
    return true;
}
//堆最后元素放在头部位置调用shiftDown
void lastTop1(vector<int> &heap){
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}
//堆最后位置插入元素，在最后位置调用shiftUp
void insertHeapLast1(vector<int> &heap, int v){
    heap.push_back(v);
    if(heap.size() > 1)
        __shiftUp1(heap, heap.size() - 1);
}
//堆头位置插入元素，在头位置调用shiftDown
void insertHeapTop1(vector<int> &heap, int v){
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify1(vector <int> &heap){
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown1(heap, i);
}
//取出最大元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最大堆性质
int extractMaxLast1(vector <int> &heap){
    int maxi = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return maxi;
}
//取出最大元素，元素v放在根调用shiftDown保持最大堆性质
int extractMaxItem1(vector <int> &heap, int v){
    int maxi = heap[0];
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return maxi;
}
//堆排序，利用堆顶点最大性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort1(vector <int> &heap){
    heapify1(heap);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown1(heap, 0);
    }
}
/*********************************/


//实现最小堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */

bool __shiftUp2(vector<int> &heap, int k){
    int p = (k - 1) / 2;
    int kv = heap[k];
    if(heap[p] <= kv) return false;
    while(k > 0 && heap[p] > kv){
        heap[k] = heap[p];
        k = p, p = (k - 1) / 2;
    }
    heap[k] = kv;
    return true;
}
bool __shiftDown2(vector<int> &heap, int k){
    int c = k * 2 + 1;
    int kv = heap[k];
    if(c >= heap.size()) return false;
    if(c + 1 < heap.size() && heap[c + 1] < heap[c]) ++c;
    if(heap[c] >= kv) return false;
    while(c < heap.size()){
        if(c + 1 < heap.size() && heap[c + 1] < heap[c]) ++c;
        if(heap[c] >= kv) break;
        heap[k] = heap[c];
        k = c, c = k * 2 + 1;
    }
    heap[k] = kv;
    return true;
}
//堆最后元素放在头部位置调用shiftDown
void lastTop2(vector<int> &heap){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    }
}
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast2(vector<int> &heap, int v){
    heap.push_back(v);
    if(heap.size() > 1)
        __shiftUp2(heap, heap.size() - 1);
}
//堆插入元素，在头位置调用shiftDown
void insertHeapTop2(vector<int> &heap, int v){
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
}
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify2(vector <int> &heap){
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown2(heap, i);
}
//取出最小元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最小堆性质
int extractMinLast2(vector <int> &heap){
    int mini = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return mini;
}
//取出最小元素，元素i放在根调用shiftDown保持最小堆性质
int extractMinItem2(vector <int> &heap, int v){
    int mini = heap[0];
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return mini;
}
//堆排序，利用堆顶点最小性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort2(vector <int> &heap){
    heapify2(heap);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown2(heap, 0);
    }
}

/*********************************/


//实现索引最大堆
/*********************************/
/* 堆用索引表示数组存储，根节点在下标0开始 */

bool __shiftUp3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int k){
    int p = (k - 1) / 2;
    int ki = heap[k];
    if(arr[heap[p]] >= arr[ki]) return false;
    while(k > 0 && arr[heap[p]] < arr[ki])){
        heap[k] = heap[p], heappos[heap[k]] = k;
        k = p, p = (k - 1) / 2;
    }
    heap[k] = ki, heappos[ki] = k;
    return true;
}
bool __shiftDown3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int k){
    int c = k * 2 + 1;
    int ki = heap[k];
    if(c >= heap.size()) return false;
    if(c + 1 < heap.size() && arr[heap[c + 1]] > arr[heap[c]]) ++c;
    if(arr[heap[c]] <= arr[ki]) return false;
    while(c < heap.size()){
        if(c + 1 < heap.size() && arr[heap[c + 1]] > arr[heap[c]]) ++c;
        if(arr[heap[c]] <= arr[ki]) break;
        heap[k] = heap[c], heappos[heap[k]] = k;
        k = c, c = k * 2 + 1;
    }
    heap[k] = ki, heappos[ki] = k;
    return true;
}
//堆最后元素放在头部位置调用shiftDown
void lastTop3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
        heappos[heap[0]] = 0;
        heap.pop_back();
        if(heap.size() > 1)
            __shiftDown3(arr, heap, heappos, 0);
    }
}
//arri为元素在array中索引
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap.push_back(arri);
    heappos.push_back(heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp3(arr, heap, heappos, heap.size() - 1);
}
//堆插入元素，在头位置调用shiftDown
void insertHeapTop3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
}
//建立堆到数组索引、数组到堆索引
void buildHeapIndex(vector<int> &heap, vector<int> &heappos, int n){
    heap.reserve(n), heappos.reserve(n);
    for(int i = 0; i < n; ++i)
        heap.push_back(i), heappos.push_back(i);
}
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    buildHeapIndex(heap, heappos, arr.size());
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown3(arr, heap, heappos, i);
}
//取出最大元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最大堆性质
int extractMaxLast3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    int ret;
    ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
    return ret;
}
//arri为元素在array中索引
//取出最大元素，元素i放在根调用shiftDown保持最大堆性质
int extractMaxItem3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    int ret;
    ret = heap[0];
    heap[0] = arri;
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
    return ret;
}
//堆排序，利用堆顶点最大性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort3(vector<int> &arr, vector<int> &heap, vector<int> &heappos)
{
    heapify3(arr, heap, heappos);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        heappos[heap[0]] = 0;
        if(i > 1)
            __shiftDownIndex1(arr, heap, heappos, 0);
    }
}

/*********************************/


//实现索引最小堆
/*********************************/
/* 堆用数组存储，根节点在下标0开始 */
bool __shiftUp4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int k){
    int p = (k - 1) / 2;
    int ki = heap[k];
    if(arr[heap[p]] <= arr[kv]) return false;
    while(k > 0 && arr[heap[p]] > arr[ki]){
        heap[k] = heap[p], heappos[heap[k]] = k;
        k = p, p = (k - 1) / 2;
    }
    heap[k] = ki, heappos[ki] = k;
    return true;
}
bool __shiftDown4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int k){
    int c = k * 2 + 1;
    int ki = heap[k];
    if(c >= heap.size()) return false;
    if(c + 1 < heap.size() && arr[heap[c + 1]] < arr[heap[c]]) ++c;
    if(arr[heap[c]] >= arr[ki]) return false;
    while(c < heap.size()){
        if(c + 1 < heap.size() && arr[heap[c + 1]] < arr[heap[c]]) ++c;
        if(arr[heap[c]] >= arr[ki]) break;
        heap[k] = heap[c], heappos[heap[k]] = k;
        k = c, c = k * 2 + 1;
    }
    heap[k] = ki, heappos[ki] = k;
    return true;
}
//堆最后元素放在头部位置调用shiftDown
void lastTop4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
        heappos[heap[0]] = 0;
        heap.pop_back();
        if(heap.size() > 1)
            __shiftDown4(arr, heap, heappos, 0);
    }
}
//堆插入元素，在最后位置调用shiftUp
void insertHeapLast4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap.push_back(arri);
    heappos.push_back(heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp4(arr, heap, heappos, heap.size() - 1);
}
//堆插入元素，在头位置调用shiftDown
void insertHeapTop4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown4(arr, heap, heappos, 0);
}
//建立堆，在第一个非叶子结点开始依次调用shiftDown
void heapify4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    buildHeapIndex(heap, heappos, arr.size());
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown4(arr, heap, heappos, i);
}
//取出最小元素，保持完全二叉树最后一个元素放在根调用shiftDown保持最小堆性质
int extractMinLast4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    int ret;
    ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heappos[heap[0]] = 0;
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown4(arr, heap, heappos, 0);
    return ret;
}
//取出最小元素，元素i放在根调用shiftDown保持最小堆性质
int extractMinItem4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    int ret;
    ret = heap[0];
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown4(arr, heap, heappos, 0);
    return ret;
}
//堆排序，利用堆顶点最小性质，依次取出顶点与最后元素交换调用shiftDown，在原空间实现排序
void heapSort4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    heapify4(arr, heap, heappos);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        heappos[heap[0]] = 0;  //存在问题，堆长度不变放在头位置的元素shiftDown又放到交换到最后元素后面
        if(i > 1)
            __shiftDown4(arr, heap, heappos, 0);
    }
}


/*********************************/

#endif // HEAP_H_INCLUDED
