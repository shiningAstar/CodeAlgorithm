#ifndef SLIDERWINDOW_H_INCLUDED
#define SLIDERWINDOW_H_INCLUDED

void sw(){
    /* 左右指针都从左向右的滑动窗口 */
    vector<int> nums;
    int n = nums.size();
    int l = 0, r = 0;      //l指左元素，r指右元素下一个，窗口元素数r - l
    while(l < n){          //左右都到数组末尾位置，如果只右到末尾位置（如窗口长度固定时）r <= n
        if(r < n && nums...) ++r;  //窗口元素不满足条件右移r
        else if(l < r) ++l;     //窗口元素条件满足右移l
    }           

    /* 左指针从左向右，右指针从右向左的滑动窗口 */
    vector<int> nums;
    int n = nums.size();
    int l = 0, r = n;      //l指左元素，r指右元素下一个，，窗口元素数r - l
    while(l < r){        //l == r串口空
        if(nums[r]...) --r;   //右条件不满足，右指针左移
        else if(nums[l]...)   //左条件不满足，左指针右移
    }
    
}

#endif // SLIDERWINDOW_H_INCLUDED