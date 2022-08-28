#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

/* 数组相关 */

/*******************************/
/* 枚举子序列，子序列为数组的顺序无关的子集，
   即在长度为n的数组中取1~n个数及全部组合 */

int n;
vector<int> nu;
vector<vector<int>> seq;

void enum_seq(){
    n = nu.size();
    /* 第一个元素为一个组合，依次枚举以后一个元素为结尾的组合，
    枚举方法为对每一个上一个为结尾的组合
    枚举两个组合
    1.最后一个替换成后一个 
    2.后面加上后一个 */
    seq.emplace_back(vector<int>{nu[0]});
    vector<int> v;
    int l = 0, r = 0;
    for(int i = 1; i < n; ++i){
        for(int j = l; j <= r; ++j){
            v = seq[j]; v[v.size() - 1] = nu[i];
            seq.emplace_back(move(v));
            v = seq[i]; v.emplace_back(nu[i]);
            seq.emplace_back(move(v));
        }
        l = r + 1; r = seq.size() - 1;
    }
}


/*******************************/

#endif //ARRAY_H_INCLUDED