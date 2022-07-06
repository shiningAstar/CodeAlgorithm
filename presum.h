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
    s.assign(n, vector<int>(m, 0));
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


#endif // PRESUM_H_INCLUDED