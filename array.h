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

void idx_sort(vi nums){
    int n = nums.size();
    vi oidx(n);   /* oidx为nums的排序索引数组 */
    iota(be(oidx),0);
    sort(be(oidx), [&nums](const int &x1, const int &x2){return nums[x1]<nums[x2];});
}

/*******************************/

/*******************************/
/* 类型定义 */
#define p1 first
#define p2 second
#define t1(t) get<0>(t)
#define t2(t) get<1>(t)
#define t3(t) get<2>(t)
#define def_tl(name,type...) using name=tuple<type>
#define def_pair(name,type1,type2) using name=pair<type1,type2>
using pii=pair<int,int>;using tiii=tuple<int,int,int>;using vi=vector<int>;using vvi=vector<vector<int>>;using usi=unordered_set<int>;
using uss=unordered_set<string>;using umii=unordered_map<int, int>;using umsi=unordered_map<string, int>;
using umis=unordered_map<int, string>;using umss=unordered_map<string, string>;using si=set<int>;
using ss=set<string>;using mii=map<int, int>;using msi=map<string, int>;using mis=map<int, string>;using mss=map<string, string>;
#define def_vi(name,n,v) vi name = vi(n, v)
#define def_vvi(name,n,m,v) vvi name = vvi(n, vi(m, v))
/* 打印容器 */
template<typename Iter>void pt(Iter first,Iter last){for(;first!=last;++first)cout<<*first<<" ";cout<<endl;}
template<typename Iter>void ptp(Iter first,Iter last){for(;first!=last;++first)cout<<"("<<first->p1<<","<<first->p2<<")";cout<<endl;}
void ptv(){cout<<endl;}template<typename T, typename ...Ts>void ptv(const T &t, Ts... rest){cout<<t<<" ";ptv(rest...);}
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
#define ptcc(c,it,prt) {auto f=[](decltype(c.begin()) it){prt;cout<<" ";}; for(auto iter=c.begin();iter!=c.end();++iter)f(iter);cout<<endl;}
#define ptc(c) pt(be(c))
#define ptcp(c) ptp(be(c))
#define riter(it) make_reverse_iterator(it)
#define eriter(ct,rit) rit = riter(ct.erase((++rit).base()))
/*******************************/

#endif //ARRAY_H_INCLUDED