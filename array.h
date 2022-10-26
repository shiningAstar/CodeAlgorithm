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


/*******************************/
/* 索引排序 */

vector<int> nus;
vector<int> oidx;
int n;

bool cmp(const int &x1, const int &x2){
    return nus[x1] < nus[x2];
}

void idx_sort(vector<int> nums){
    nus.swap(nums);
    n = nus.size();
    oidx.assign(n);
    for(int i = 0; i < n; ++i) oidx[i] = i;
    sort(oidx.begin(), oidx.end(), cmp);
}

/*******************************/

/*******************************/
/* 打印容器 */
template<typename Iter>void pt(Iter first,Iter last){for(;first!=last;++first)cout<<*first<<" ";cout<<endl;}
template<typename Iter>void ptp(Iter first,Iter last){for(;first!=last;++first)cout<<"("<<first->first<<","<<first->second<<")";cout<<endl;}
template<typename T>void ptv(T &t){cout<<t<<endl;}
template<typename T, typename ...Ts>void ptv(T &t, Ts... rest){cout<<t<<" ";ptv(rest...);}
/* 循环宏 */
#define rep(i,a,b) for(int i = a, __ = b; i < __; ++i)
#define repe(i,a,b) for(int i = a, __ = b; i <= __; ++i)
#define rrep(i,b,a) for(int i = b - 1; i >= a; --i)
#define rrepe(i,b,a) for(int i = b; i >= a; --i)
#define repc(it,ct) for(auto it = ct.begin(); it != ct.end(); ++it)
/* 函数短称 */
#define eb emplace_back
#define em emplace
#define pb push_back
#define be(c) c.begin(),c.end()
#define ptc(c) pt(be(c))
#define ptcp(c) ptp(be(c))
/* 类型定义 */
#define p1 first
#define p2 second
typedef pair<int,int> pii;typedef vector<int> vi;typedef vector<vector<int>> vvi;typedef unordered_set<int> usi;
typedef unordered_set<string> uss;typedef unordered_map<int, int> umii;typedef unordered_map<string, int> umsi;
typedef unordered_map<int, string> umis;typedef unordered_map<string, string> umss;typedef set<int> si;
typedef set<string> ss;typedef map<int, int> mii;typedef map<string, int> msi;typedef map<int, string> mis;typedef map<string, string> mss;
#define def_vi(name,n,v) vi name = vi(n, v)
#define def_vvi(name,n,m,v) vvi name = vvi(n, vi(m, v))
/*******************************/

#endif //ARRAY_H_INCLUDED