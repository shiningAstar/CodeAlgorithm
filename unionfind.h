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
    while(r != fa[r]) r = fa[r];   //查找跟节点 //找到跟节点,用r记录下
    k = x;
    while(k != r){   //非递归路径压缩操作
        j = fa[k]; //用j暂存parent[k]的父节点
        fa[k] = r; //parent[x]指向跟节点
        k = j;  //k移到父节点
    }
    return r;   //返回根节点的值
}

void merge(int i, int j){
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y]) fa[x] = y;
    else fa[y] = x;
    if (rank[x] == rank[y] && x != y) rank[y]++;
}



#endif // UNIONFIND_H_INCLUDED
