#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

/* �ѣ����ȶ��У� */

//ʵ������
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

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
//�����Ԫ�ط���ͷ��λ�õ���shiftDown
void lastTop1(vector<int> &heap){
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}
//�����λ�ò���Ԫ�أ������λ�õ���shiftUp
void insertHeapLast1(vector<int> &heap, int v){
    heap.push_back(v);
    if(heap.size() > 1)
        __shiftUp1(heap, heap.size() - 1);
}
//��ͷλ�ò���Ԫ�أ���ͷλ�õ���shiftDown
void insertHeapTop1(vector<int> &heap, int v){
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
}
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify1(vector <int> &heap){
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown1(heap, i);
}
//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
int extractMaxLast1(vector <int> &heap){
    int maxi = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return maxi;
}
//ȡ�����Ԫ�أ�Ԫ��v���ڸ�����shiftDown������������
int extractMaxItem1(vector <int> &heap, int v){
    int maxi = heap[0];
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown1(heap, 0);
    return maxi;
}
//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort1(vector <int> &heap){
    heapify1(heap);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown1(heap, 0);
    }
}
/*********************************/


//ʵ����С��
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */

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
//�����Ԫ�ط���ͷ��λ�õ���shiftDown
void lastTop2(vector<int> &heap){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    }
}
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeapLast2(vector<int> &heap, int v){
    heap.push_back(v);
    if(heap.size() > 1)
        __shiftUp2(heap, heap.size() - 1);
}
//�Ѳ���Ԫ�أ���ͷλ�õ���shiftDown
void insertHeapTop2(vector<int> &heap, int v){
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
}
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify2(vector <int> &heap){
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown2(heap, i);
}
//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������С������
int extractMinLast2(vector <int> &heap){
    int mini = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return mini;
}
//ȡ����СԪ�أ�Ԫ��i���ڸ�����shiftDown������С������
int extractMinItem2(vector <int> &heap, int v){
    int mini = heap[0];
    heap[0] = v;
    if(heap.size() > 1)
        __shiftDown2(heap, 0);
    return mini;
}
//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort2(vector <int> &heap){
    heapify2(heap);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        if(i > 1)
            __shiftDown2(heap, 0);
    }
}

/*********************************/


//ʵ����������
/*********************************/
/* ����������ʾ����洢�����ڵ����±�0��ʼ */

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
//�����Ԫ�ط���ͷ��λ�õ���shiftDown
void lastTop3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
        heappos[heap[0]] = 0;
        heap.pop_back();
        if(heap.size() > 1)
            __shiftDown3(arr, heap, heappos, 0);
    }
}
//arriΪԪ����array������
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeapLast3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap.push_back(arri);
    heappos.push_back(heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp3(arr, heap, heappos, heap.size() - 1);
}
//�Ѳ���Ԫ�أ���ͷλ�õ���shiftDown
void insertHeapTop3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
}
//�����ѵ��������������鵽������
void buildHeapIndex(vector<int> &heap, vector<int> &heappos, int n){
    heap.reserve(n), heappos.reserve(n);
    for(int i = 0; i < n; ++i)
        heap.push_back(i), heappos.push_back(i);
}
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    buildHeapIndex(heap, heappos, arr.size());
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown3(arr, heap, heappos, i);
}
//ȡ�����Ԫ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������������
int extractMaxLast3(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    int ret;
    ret = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
    return ret;
}
//arriΪԪ����array������
//ȡ�����Ԫ�أ�Ԫ��i���ڸ�����shiftDown������������
int extractMaxItem3(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    int ret;
    ret = heap[0];
    heap[0] = arri;
    if(heap.size() > 1)
        __shiftDown3(arr, heap, heappos, 0);
    return ret;
}
//���������öѶ���������ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
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


//ʵ��������С��
/*********************************/
/* ��������洢�����ڵ����±�0��ʼ */
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
//�����Ԫ�ط���ͷ��λ�õ���shiftDown
void lastTop4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    if(heap.size() > 0){
        heap[0] = heap[heap.size() - 1];
        heappos[heap[0]] = 0;
        heap.pop_back();
        if(heap.size() > 1)
            __shiftDown4(arr, heap, heappos, 0);
    }
}
//�Ѳ���Ԫ�أ������λ�õ���shiftUp
void insertHeapLast4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap.push_back(arri);
    heappos.push_back(heap.size() - 1);
    if(heap.size() > 1)
        __shiftUp4(array, heap, heappos, heap.size() - 1);
}
//�Ѳ���Ԫ�أ���ͷλ�õ���shiftDown
void insertHeapTop4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown4(array, heap, heappos, 0);
}
//�����ѣ��ڵ�һ����Ҷ�ӽ�㿪ʼ���ε���shiftDown
void heapify4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    buildHeapIndex(heap, heappos, arr.size());
    for(int i = (heap.size() - 1 - 1) / 2; i >= 0; --i)
        __shiftDown4(arr, heap, heappos, i);
}
//ȡ����СԪ�أ�������ȫ���������һ��Ԫ�ط��ڸ�����shiftDown������С������
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
//ȡ����СԪ�أ�Ԫ��i���ڸ�����shiftDown������С������
int extractMinItem4(vector<int> &arr, vector<int> &heap, vector<int> &heappos, int arri){
    int ret;
    ret = heap[0];
    heap[0] = arri;
    heappos[arri] = 0;
    if(heap.size() > 1)
        __shiftDown4(arr, heap, heappos, 0);
    return ret;
}
//���������öѶ�����С���ʣ�����ȡ�����������Ԫ�ؽ�������shiftDown����ԭ�ռ�ʵ������
void heapSort4(vector<int> &arr, vector<int> &heap, vector<int> &heappos){
    heapify4(arr, heap, heappos);
    for(int i = heap.size() - 1; i > 0; --i){
        swap(heap[0], heap[i]);
        heappos[heap[0]] = 0;  //�������⣬�ѳ��Ȳ������ͷλ�õ�Ԫ��shiftDown�ַŵ����������Ԫ�غ���
        if(i > 1)
            __shiftDown4(arr, heap, heappos, 0);
    }
}


/*********************************/

#endif // HEAP_H_INCLUDED
