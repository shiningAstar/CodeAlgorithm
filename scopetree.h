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
        updateScopeTree(sl, sr, value, mid + 1, r, 2 * node + 1);
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


/***************************/
/* 线段树，记录查询区间最大最小值、区间和，更新单点，查询更新复杂度均为logn */

    template<typename T, T zero, T minv, T maxv, int Rt = 1>  //N个元素的区间，Rt记录类型 1区间和 2最大值 3最小值
    class STree{
        public:
            vector<T> t;int l, r;
            template<typename Tp>STree(vector<Tp> &v, int fst_idx, int lst_idx){
                l = fst_idx; r = lst_idx;
                t.assign(4 * (r - l + 1), zero);
                build(v, l, r, 1);
            }
            void build(vector<T> &v, int l, int r, int node){
                if(l == r){t[node] = v[l];return;}
                int mid = l + ((r - l) >> 1);build(v, l, mid, 2 * node);build(v, mid + 1, r, 2 * node + 1);
                if constexpr (Rt == 1)t[node] = t[2 * node] + t[2 * node + 1];
                else if constexpr (Rt == 2)t[node] = max(t[2 * node], t[2 * node + 1]);
                else if constexpr (Rt == 3)t[node] = min(t[2 * node], t[2 * node + 1]);
            }
            T search(int sl, int sr){return search(sl, sr, l, r, 1);}
            T search(int sl, int sr, int l, int r, int node){
                if(sl <= l && r <= sr){return t[node];}int mid = l + ((r - l) >> 1);T res;
                if constexpr (Rt == 1) res = zero;else if constexpr (Rt == 2) res = minv; else if constexpr (Rt == 3) res = maxv;
                if(sl <= mid){if constexpr (Rt == 1)res += search(sl, sr, l, mid, 2 * node);
                    else if constexpr (Rt == 2)res = max(res, search(sl, sr, l, mid, 2 * node));
                    else if constexpr (Rt == 3)res = min(res, search(sl, sr, l, mid, 2 * node));}
                if(mid < sr){if constexpr (Rt == 1)res += search(sl, sr, mid + 1, r, 2 * node + 1);
                    else if constexpr (Rt == 2)res = max(res, search(sl, sr, mid + 1, r, 2 * node + 1));
                    else if constexpr (Rt == 3)res = min(res, search(sl, sr, mid + 1, r, 2 * node + 1));}return res;
            }
            void update_add(int sl, int sr, T value){return update<1>(sl,sr,value,l,r,1);}
            void update_ass(int sl, int sr, T value){return update<0>(sl,sr,value,l,r,1);}
            void update_add(int node, T value){return update<1>(node,node,value,l,r,1);}
            void update_ass(int node, T value){return update<0>(node,node,value,l,r,1);}
            template<int add = 1>  void update(int sl, int sr, T value, int l, int r, int node){ //add 1修改增加value 0修改赋值value
                if(l == r){if constexpr (add == 1) t[node] += value;else if constexpr (add == 0) t[node] = value;return;}
                int mid = l + ((r - l) >> 1);if(sl <= mid) update<add>(sl, sr, value, l, mid, 2 * node);
                if(mid < sr) update<add>(sl, sr, value, mid + 1, r, 2 * node + 1);
                if constexpr (Rt == 1)t[node] = t[2 * node] + t[2 * node + 1];
                else if constexpr (Rt == 2)t[node] = max(t[2 * node], t[2 * node + 1]);
                else if constexpr (Rt == 3)t[node] = min(t[2 * node], t[2 * node + 1]);
            }
    };


/***************************/
#endif // SCOPETREE_H_INCLUDED
