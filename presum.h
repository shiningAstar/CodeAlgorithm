#ifndef PRESUM_H_INCLUDED
#define PRESUM_H_INCLUDED

/*******************************/
/* 一维前缀和实现 */

int n;
vector<int> s;
vector<int> nu;

void init_sum(){
    s.assign(n + 1, 0);
    for(int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + nu[i - 1];
}

void preSumCal(vector<int> &nums){
    nu.swap(nums);
    n = nu.size();
    init_sum();
    //计算i...j之间区间和
    //int sum = s[j + 1] - s[i]
}

/*******************************/


/*******************************/
/* 二维前缀和实现 */

int n;
int m;
vector<vector<int>> s;
vector<vector<int>> nu;

void init_sum(){
    s.assign(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + nu[i - 1][j - 1];        
}

void preSumCal(vector<vector<int>> &nums){
    nu.swap(nums);
    n = nu.size();
    m = nu[0].size();
    init_sum();
    //计算[i1,j1]...[i2,j2]之间二维区间和
    //int sum = s[i2 + 1][j2 + 1] - s[i1][j2 + 1] - s[i2 + 1][j1] + s[i1][j1];
}

/*******************************/

/*******************************/
/* 差分数组，记录数组变化量累计过程，用于数组范围变化多次，过程中不需查询，
   变化后直接整理元素最终值，查询要整理前续全部变化后再得到元素最终值 */

int n;
vector<int> d;
vector<int> nu;

void init_dif() {
    n = nu.size();
    d.assign(n + 1, 0);
}

/* 区间[l,r]元素变化val */
void range_update(int l, int r, int val){
    d[l] += val; d[r + 1] -= val;
}

/* 生效全部变化，计算最终值 */
void effect_update(){
    int dif = 0;
    for(int i = 0; i < n; ++i){
        dif += d[i];
        nu[i] += dif;
    }
}

/*******************************/


/*******************************/
/* 前缀和，元素编号1-n，二分查找前缀和大于等于sum的第一个元素编号0~n-1 */
    template<typename T, typename Ts, Ts zero>
    typedef struct PSum{
        vector<Ts> s;int n;PSum(){} PSum(vector<T> &v){build(v);}
        void build(vector<T> &v){n = v.size();s.assign(n + 1,zero);for(int i=1;i<=n;++i)s[i]=s[i-1]+v[i-1];}
        Ts search(int fst_idx, int lst_idx){return s[lst_idx+1]-s[fst_idx];}
        int binarysearch(Ts sum){int l=1,r=n;int mid;
            while(l <= r){mid=l+(r-l)/2;if(s[mid] >= sum)r = mid - 1;else l = mid + 1;}return l-1;}
    };


/*******************************/

#endif // PRESUM_H_INCLUDED