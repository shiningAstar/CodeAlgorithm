#ifndef UNIONFIND_H_INCLUDED
#define UNIONFIND_H_INCLUDED

vector<int> fa, rank;
int n;

void init(int n){
    for (int i = 0; i < n; ++i){
        fa[i] = i;
        rank[i] = 1;
    }
}

int find(int x){
    int k, j, r;
    r = x;
    while(r != parent[r]) r = parent[r];   //���Ҹ��ڵ� //�ҵ����ڵ�,��r��¼��
    k = x;
    while(k != r){   //�ǵݹ�·��ѹ������
        j = parent[k]; //��j�ݴ�parent[k]�ĸ��ڵ�
        parent[k] = r; //parent[x]ָ����ڵ�
        k = j;  //k�Ƶ����ڵ�
    }
    return r;   //���ظ��ڵ��ֵ
}

void merge(int i, int j){
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y]) fa[x] = y;
    else fa[y] = x;
    if (rank[x] == rank[y] && x != y) rank[y]++;
}

#endif // UNIONFIND_H_INCLUDED
