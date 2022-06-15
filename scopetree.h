#ifndef SCOPETREE_H_INCLUDED
#define SCOPETREE_H_INCLUDED

/***************************/
/* 线段树 */

/* 修改区间，在以node为根范围为[l,r]的区间内，对区间[sl,sr]每个元素的值加value*/
void updateScopeTree(int sl, int sr, int value, int l, int r, int node){
    if(l == r){  //区间叶子节点，单个元素修改，肯定在区间[sl,sr]中
        tree[node] += value;
        return;
    }

    //中点[l,r]分两部分
    int mid = l + ((r - l) >> 1);

    if(sl <= mid) {  //修改区间在左半区有一部分，修改左半区对应细分部分
        updateScopeTree(sl, sr, value, l, mid, 2 * node);
    }
    if(mid < sr) { //修改区间在右半区有一部分，修改右半区对应细分部分
        updateScopeTree(sl, sr, value, mid + 1, 2 * n + 1);
    }
    //线段树记录区间和
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    //线段树记录区间最大最小值
    //tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    //tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}


/* 查询线段树，在以node为根范围为[l,r]的区间内，查询区间[sl,sr]的值 */
int searchScopeTree(int sl, int sr, int l, int r, int node){
    if(sl <= l && r <= sr){  //全部[l,r]区间在查询区间中，node节点值全部返回
        return tree[node];
    }

    //中点[l,r]分两部分
    int mid = l + ((r - l) >> 1);

    //线段树存储区间和
    int res = 0;
    //线段树存储区间最大值最小值
    //int res = nums[sl];
    if(sl <= mid){  //查询区间在左半区有一部分，查询左半区对应细分部分
        //线段树存储区间和
        res += searchScopeTree(sl, sr, l, mid, 2 * node);
        //线段树存储区间最大值最小值
        //res = max(res, searchScopeTree(sl, sr, l, mid, 2 * node));
        //res = min(res, searchScopeTree(sl, sr, l, mid, 2 * node));
    }
    if(mid < sr){  //查询区间在右半区有一部分，查询右半区对应细分部分
        //线段树存储区间和
        res += searchScopeTree(sl, sr, mid + 1, r, 2 * node + 1);
        //线段树存储区间最大值最小值
        //res = max(res, searchScopeTree(sl, sr, mid + 1, r, 2 * node + 1));
        //res = min(res, searchScopeTree(sl, sr, mid + 1, r, 2 * node + 1));
    }
    return res;
}

/* 数组存储线段树，根节点下标编号1，节点n左孩子2n，右孩子2n-1 */

vector<int> nums;
//线段树数组，元素最多4n
vector<int> tree(4 * nums.size());

/* 在下标范围[l,r]内建立线段树，线段树根节点node */
void buildScopeTree(int l, int r, int node){
    if(l == r){
        tree[node] = nums[l];
        return;
    }

    //中点分两部分区间
    int mid = l + ((r - l) >> 1);

    buildScopeTree(l, mid, 2 * node);
    buildScopeTree(mid + 1, r, 2 * node + 1);

    //线段树记录区间和
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    //线段树记录区间最大最小值
    //tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    //tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

/***************************/

#endif // SCOPETREE_H_INCLUDED
