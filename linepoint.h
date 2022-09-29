#ifndef LINEPOINT_H_INCLUDED
#define LINEPOINT_H_INCLUDED

/***************************/
/* 直线、点相关 */

vector<int> prime;

/* 分解质因数 */
void trial_divisio_fac(int n){
    int a=2;
    while(a*a<=n){
        while(n%a==0){
            prime.emplace_back(a); n=n/a;
        }
        a++;
    }
    if(n > 1) prime.emplace_back(n);//n没有因数
}

//a、b的最大公约数
/* stl 标准库algorithm算法提供最大公约数gcd和最小公倍数lcm */
int gcd(int a, int b);
int lcm(int a, int b);
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

/*计算点p1和p2之间直线的斜率,用x、y数对表示不失精度，一正一负统一x负，
  不考虑p1、p2相同x、y同为0，如x=0或y=0即纵轴平行或横轴平行特判y=1或x=1*/
void slopek(vector<int> &p1, vector<int> &p2, int &x, int &y){
    x = p2[0] - p1[0];
    y = p2[1] - p1[1];
    if(y == 0) x = 1;
    else if(x == 0) y = 1;
    else{
        if(y < 0){
            x = -x;
            y = -y;
        }
        int gcdxy = gcd(abs(x), abs(y));
        x /= gcdxy, y /= gcdxy;
    }
}

/***************************/

/***************************/

/* 区间相关 */

/* 比较区间inter1、inter2
返回inter1完全在左侧4
   inter1右端与inter2左端可合并3
   inter1左端小于不含inter2左端，右端包含大于inter2右端2
   inter1左端等于inter2左端，右端小于不含inter2右端1
   inter1左右端等于inter2左右端0
   inter1大于-1 */
int compInterval(const vector<int> &inter1, const vector<int> &inter2){
    if(inter1[0] < inter2[0]){
        //相邻端点区间是否合并，如[1,2][3,4]合并[1,4]，启用+1
        if(inter1[1] /*+ 1*/ < inter2[0]) return 4;
        else if(inter1[1] < inter2[1]) return 3;
        else return 2;
    }
    else if(inter1[0] == inter2[0]){
        if(inter1[1] < inter2[1]) return 1;
        else if(inter1[1] == inter2[1]) return 0;
    }
    return -1;
}

/*合并inter左区间到mergeInter右区间，存在inter<mergeInter，
  返回合并1不能合并0区间非法-1*/
int mergeIntervalr(const vector<int> &inter, vector<int> &mergeInter){
    int ret = compInterval(inter, mergeInter);
    if(ret == 4) return 0;
    if(ret == 1) return 1;
    if(ret == 3) {
        mergeInter[0] = inter[0];
        return 1;
    }
    if(ret == 2) return -2;
    return -1;
}
/*合并inter右区间到mergeInter左区间，存在mergeInter<inter，
  返回合并1不能合并0区间非法-1，合并后还能合并即mergeInter[1] > inter[1]返回2*/
int mergeIntervall(vector<int> &mergeInter, const vector<int> &inter){
    int ret = compInterval(mergeInter, inter);
    if(ret == 4) return 0;
    if(ret == 3 || ret == 1){
        mergeInter[1] = inter[1];
        return 1;
    }
    if(ret == 2) return 2;
    return -1;
}

/* 区间由set结构存储，数据实现为平衡二分搜索树红黑树，区间的插入、查找均为logn
   区间互不重叠，每个区间范围[interval[0],interval[1]] */
void insertInterval(set<vector<int>> &intervals, vector<int> interval){
    set<vector<int>>::iterator ceil = intervals.lower_bound(interval);
    set<vector<int>>::iterator ceill = ceil;
    int ret;
    if(ceil == intervals.end()){
        //没有ceil，看左侧是否需合并，ceil为begin元素不需合并
        if(ceil == intervals.begin()) intervals.insert(interval);
        else {
            --ceill; 
            if((ret = mergeIntervalr(*ceill, interval)) >= 0){
                if(ret > 0) intervals.erase(ceill);
                intervals.insert(interval);
            }
        }
    } else {
        //合并左侧--ceill和右侧ceil

        //左侧只看一个区间，ceil不为begin元素需合并
        if(ceil != intervals.begin()){
            --ceill;
            if((ret = mergeIntervalr(*ceill, interval)) > 0)
                intervals.erase(ceill);
            else if(ret == -2) return;
        }

        //右侧到不覆盖全部的第一个区间，即interval[1] < *ceil[1]
        while(ceil != intervals.end() && (ret = mergeIntervall(interval, *ceil)) > 0)
            ceil = intervals.erase(ceil);

        //合并了左区间和右区间的interval放入集合
        if(ret == 0)
            intervals.insert(interval);
    }
}

/* num是否在区间集合中 */
bool inIntervals(set<vector<int>> &intervals, int num){
    set<vector<int>>::iterator ceil = intervals.lower_bound({num, num});
    set<vector<int>>::iterator ceill = ceil;
    set<vector<int>>::iterator bbegin = --intervals.begin();
    --ceill;
    if(ceil == intervals.end()){
        if(ceill == bbegin) return false;
        else if(*ceill[1] >= num) return true;
        else return false;
    }
    else{
        if(*ceil[0] == num) return true;
        else if(ceill == bbegin) return false;
        else if(*ceill[1] >= num) return true;
        else return false;
    }
}

/* 区间interval同区间集合intervals重合部分，重合区间存储在dups */
void inIntervals(set<vector<int>> &intervals, vector<int> interval,
                    vector<vector<int>> &dups){
    set<vector<int>>::iterator ceil = intervals.lower_bound(interval);
    set<vector<int>>::iterator ceill = ceil, bbegin = --intervals.begin();
    --ceill;
    if(ceil == intervals.end()){
        //没有ceil，看左侧是否需合并
        if(ceill == bbegin) return;
        else if((ret = compInterval(*ceill, interval)) != -1){
            if(ret == 1) dups.push_back(*ceill);
            else if(ret == 3 && *ceill[1] >= interval[0])
                dups.push_back({*ceill[1], interval[0]});
            else if(ret == 2) dups.push_back(interval);
            return;
        }
    }
    else{
        while(ceil != intervals.end() && (ret = compInterval(interval, *ceil)) == 2){
            dups.push_back(*ceil);
            ++ceil;
        }

        if(ret != -1){
            if(ret == 3 && interval[1] >= *ceil[0])
                dups.push_back({interval[1], *ceil[0]});
            else if(ret == 2) return;
            else if(ret == 1 || ret == 0) dups.push_back(interval);
        }

        if(ceill != bbegin){
            if((ret = compInterval(*ceill, interval)) != -1){
                if(ret == 1) dups.push_back(*ceill);
                else if(ret == 2) dups.push_back(interval);
                else if(ret == 3 && *ceill[1] >= interval[0])
                    dups.push_back({*ceill[1], interval[0]});
                return;
            }
        }
    }
}

/***************************/

#endif // LINEPOINT_H_INCLUDED
