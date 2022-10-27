# 数组类型题目分类总结

## 子序列类
- **最长递增（非递减）子序列**  
  如果只求子序列长度，桶式统计方法，对每个长度的子序列的最小结尾元素的下标记录  
  对每个元素判断能否放在最长子序列结尾元素下一个，如果可以增长最长子序列长度并记录，  
  如果不能增长最长长度，判断能否更新每个长度的结尾元素为更小，  
  即从大到小比较每个长度结尾元素能放在结尾元素后，能放则可更新大一个长度结尾元素为更小  
  示例题目 [leetcode 300](https://leetcode.cn/problems/longest-increasing-subsequence/)  
  **最长递增（非递减）连续子序列**  
  遍历数组记录递增起始位置和当前位置计算递增连续子序列长度，出现递减元素在递减位置起始继续记录  
  示例题目 [leetcode 674](https://leetcode.cn/problems/longest-continuous-increasing-subsequence/)
  
- **最小递增（非递减）子序列**
  求字典序最小的递增子序列，单调栈（最小栈），最后栈中元素是每个位置都是最小的递增子序列，但不保证最长
  示例题目 [leetcode 1081](https://leetcode.cn/problems/smallest-subsequence-of-distinct-characters/)

- **最大连续子段和**  
  整数数组遍历数组，整数计入和，负数计入后小于等于0不计入，因为在负数后位置开始记录比当前包含负数子段大，  
  大于0计入负数继续，因为后面可能有正数使和更大，过程中记录最大和  
  示例题目 [leetcode 53](https://leetcode.cn/problems/maximum-subarray/)  
- 