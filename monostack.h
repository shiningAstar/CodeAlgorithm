#ifndef PRESUM_H_INCLUDED
#define PRESUM_H_INCLUDED

/*******************************/
/* 单调栈实现 */

void monostack()
{
    stack<int> st;

    /* 最小栈 */
    int num;
    for(int i = 0; i < n; ++i){
        num = nums[i];
        while(!st.empty() && st.top()>num){   
        /* 栈中弹出条件，弹出大于当前元素，到第一个小于元素为止，
            也可加判断栈中存在相同当前元素不入栈，数组中最后剩余不满栈元素最少个数不弹出等条件 */
            st.pop();
        }
        st.emplace(num);
    }

}

/*******************************/

#endif // PRESUM_H_INCLUDED